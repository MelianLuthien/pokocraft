# PokoCraft

Craft anything in Pokopia without spending materials — and, if you want, without
having them in the bag at all.

- **Game:** Pokopia 2.0.1 (build `76a489f3bd3642fa5e18bd83d32c98ba`)
- **Runs on:** Recompia with Modtopia
- **Type:** code mod (`.pkmod`). No game files are included, copied or patched.
- **Licence:** MIT

## What it does

PokoCraft changes crafting only. It does not add items to your bag, does not
touch your storage, and does not edit recipe data. Recipes still list their
usual ingredients, so menus and recipe screens look unchanged.

| Setting | Default | Effect |
|---|---|---|
| **Bypass Requirements** | On | Crafting ignores whether you have the materials. The quantity selector works normally, up to 99 per craft. |
| | Off | The game checks your bag before crafting, exactly as it normally would. |

Either way, a craft never uses up materials.

## Single-player only

PokoCraft is single-player only. It runs entirely on your machine: it does not
connect to the internet and does not touch online or shared features.

## Cheat

PokoCraft is a cheat, and says so: `tags = ["cheat"]` in `mod.toml`. Modtopia
lists it as a cheat and keeps shared achievements off while it is enabled.

## Install

1. Use Recompia 0.16.0 or later with Modtopia, and game version 2.0.1.
2. Install `pokocraft-1.0.0.pkmod` from the app's **Browse mods**, or copy it
   into Recompia's `mods` folder.
3. Start the game and set **Bypass Requirements** in the mod's settings.

No RomFS patch and no `pkp.ini` change are needed. The full guide, including
checking the download hash, uninstall and troubleshooting, is in
[docs/INSTALL.md](docs/INSTALL.md).

## Build from source

The mod is a single C file that links against the Modtopia SDK header
(`<modtopia/modtopia.h>`), which ships with the Modtopia SDK and is not part of
this repository.

```sh
zig cc -target x86_64-windows-gnu -shared -std=c11 -O2 -Wall -Wextra -Werror \
  -I "path/to/modtopia/include" \
  -o "bin/windows-x64/mod.dll" "src/pokocraft.c"
```

Then package `mod.toml` and `bin/windows-x64/mod.dll` into a `.pkmod` (a zip
with those two paths).

## Known limits

- Game build 2.0.1 only. A game update changes the hook addresses and needs a
  new release.
- Construction and building costs are not covered yet.
- The Expansion Pass (DLC) is not modified.

## Licence

MIT. See [LICENSE](LICENSE).
