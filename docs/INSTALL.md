# Install

PokoCraft is a code mod: a single `.pkmod` file. It needs Recompia with
Modtopia, and nothing else. It does not patch game files and does not need a
RomFS mod.

## Requirements

- **Windows x64 or Linux x64**, including Steam Deck. One package holds both
  builds. **The Linux build has not been tested yet.**
- **Recompia 0.16.0 or later**, with the **Modtopia** mod loader.
- **Pokopia 2.0.1**, build `76a489f3bd3642fa5e18bd83d32c98ba`. This is the only
  game version covered; a game update needs a new PokoCraft release.
- Your own legally obtained copy of the game. No game files are included.

## Install from the app

Once PokoCraft is listed on Pokopia Native:

1. Open the app's **Browse mods**.
2. Find **PokoCraft** and install it.
3. Start the game.

The app puts the `.pkmod` in the right place for you.

## Install by hand

1. Download `pokocraft-1.0.1.pkmod` from the **Releases** page.
2. Check the download (optional but recommended). In PowerShell, in the folder
   where you saved the file:

   ```powershell
   Get-FileHash .\pokocraft-1.0.1.pkmod -Algorithm SHA256
   ```

   On Linux or Steam Deck, run `sha256sum pokocraft-1.0.1.pkmod` instead.

   The hash must match the SHA-256 in the release notes.

3. Copy `pokocraft-1.0.1.pkmod` into the `mods` folder of your Recompia install
   (the folder next to `pkp.ini`).
4. Start the game. If Modtopia asks whether to allow PokoCraft, allow it.

## Check that it loaded

- The app's mod list shows **PokoCraft 1.0.1**.
- `pkp.log`, in the Recompia folder, contains the line:

  ```
  pokocraft 1.0.1 ready
  ```

If the line is missing, the mod was not loaded: check the `mods` folder, and
that Modtopia is installed and enabled.

## Use it

Open the mod's settings and look for **Bypass Requirements**:

| Setting | What happens |
|---|---|
| **On** (default) | Crafting ignores whether you have the materials. With an empty bag you can still craft, and the quantity selector offers 1 to 99. |
| **Off** | The game checks your bag before crafting, as it normally would. Materials are still never consumed. |

In both modes, crafting never uses up materials, and nothing is added to your
bag. Recipe screens look unchanged because recipes keep their usual
ingredients.

To check it works: with **Bypass Requirements** on, craft something you have no
materials for. It should complete, and your bag should not change.

## Uninstall

Delete `pokocraft-1.0.1.pkmod` from the `mods` folder (or uninstall it from the
app). No game files were changed, so nothing else needs undoing.

If your install keeps per-mod settings, you can also delete PokoCraft's settings
file to remove the saved toggle.

## Troubleshooting

**PokoCraft is not in the mod list.**
The file is not in Recompia's `mods` folder, or Modtopia is not installed.

**The game still says you don't have enough materials.**
Turn **Bypass Requirements** on in the mod settings. If it is already on, check
that the game is version 2.0.1 and that the loaded version is 1.0.1.

**Nothing changes at all.**
Check `pkp.log` for `pokocraft 1.0.1 ready`. If it is missing, the mod is not
loaded. A game update also breaks the hook addresses; install a PokoCraft
release for your game version.

**Shared achievements are off.**
Expected: PokoCraft is a cheat (`tags = ["cheat"]`), and Modtopia keeps shared
achievements off while a cheat mod is enabled.

[Back to the README](../README.md)
