/* PokoCraft 1.0.1 — crafting never consumes materials, and can optionally
 * work with an empty bag.
 *
 * Hooks (Modtopia take_over, game build 2.0.1):
 *   ingredient      0x74f380  ingredient count -> 0 (a craft never consumes)
 *   ret_74e1bc      0x74e1bc  cost wrapper result -> 1
 *   avail_74df10    0x74df10  has-materials flag -> 1 when the recipe is valid
 *   force_fill_154  0xeee154  force the recipe fill when materials are missing
 *   force_qty_1a0   0xeee1a0  force the craftable quantity to 99 when it is 0
 *
 * The last two are gated by the "Bypass Requirements" setting (default on):
 * ON  = the bag is ignored and the quantity selector offers 1..99;
 * OFF = the game checks the bag as usual, but nothing is ever consumed.
 *
 * No game data is included. Nothing is added to the player's bag.
 */
#include <modtopia/modtopia.h>
#include <stddef.h>
#include <stdint.h>

MT_DECLARE_MOD()

static const MtHost *H;
static MtMod *M;

static int bypass_req(void) { return H->config_bool(M, "bypass_requirements"); }

/* Never consume: the ingredient count handed to the cost routine becomes 0. */
static int on_ingredient(MtHookCtx *c, void *u) {
    (void)u;
    if (H->reg_get(c, 2) != 0) H->reg_set(c, 2, 0);
    return MT_CONTINUE;
}

/* Never consume: the cost wrapper reports success. */
static int on_ret(MtHookCtx *c, void *u) {
    (void)u;
    if (H->reg_get(c, 0) != 1) H->reg_set(c, 0, 1);
    return MT_CONTINUE;
}

/* Mark a valid recipe as "has materials". */
static int on_avail(MtHookCtx *c, void *u) {
    (void)u;
    uint64_t x0 = H->reg_get(c, 0);
    uint32_t lo = (uint32_t)x0;
    uint32_t hi = (uint32_t)(x0 >> 32);
    if (((lo - 1) & 0xffff) < 0x5db && hi == 0)
        H->reg_set(c, 0, (x0 & 0xffffffffull) | (1ull << 32));
    return MT_CONTINUE;
}

/* Bypass Requirements: fill the recipe even when the bag is empty. */
static int on_force_fill(MtHookCtx *c, void *u) {
    (void)u;
    if (bypass_req() && H->reg_get(c, 0) != 0) H->reg_set(c, 0, 0);
    return MT_CONTINUE;
}

/* Bypass Requirements: give the quantity selector a normal 1..99 range. */
static int on_force_qty(MtHookCtx *c, void *u) {
    (void)u;
    if (bypass_req() && (uint32_t)H->reg_get(c, 0) == 0) H->reg_set(c, 0, 99);
    return MT_CONTINUE;
}

MT_EXPORT int mod_init(const MtHost *host, MtMod *mod) {
    H = host;
    M = mod;
    if (!H->module_base("main")) {
        H->log(M, MT_LOG_ERROR, "no main module");
        return MT_ERR;
    }
    static const struct { const char *point; MtHookFn fn; } hooks[] = {
        {"ingredient", on_ingredient},
        {"ret_74e1bc", on_ret},
        {"avail_74df10", on_avail},
        {"force_fill_154", on_force_fill},
        {"force_qty_1a0", on_force_qty},
    };
    for (size_t i = 0; i < sizeof hooks / sizeof hooks[0]; i++) {
        if (H->hook(M, hooks[i].point, hooks[i].fn, NULL) != MT_OK) {
            H->log(M, MT_LOG_ERROR, "cannot register a hook");
            return MT_ERR;
        }
    }
    H->log(M, MT_LOG_INFO, "pokocraft 1.0.1 ready");
    return MT_OK;
}
