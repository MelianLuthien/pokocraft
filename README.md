<div align="center">

# PokoCraft

**Craft anything in Pokopia without spending materials,<br>and, if you want, without having them at all.**

[![Latest release](https://img.shields.io/github/v/release/MelianLuthien/pokocraft?style=flat-square&color=f2a30f)](https://github.com/MelianLuthien/pokocraft/releases/latest)
[![Downloads](https://img.shields.io/github/downloads/MelianLuthien/pokocraft/total?style=flat-square&color=3a3fb5)](https://github.com/MelianLuthien/pokocraft/releases)
![Pokopia 2.0.1](https://img.shields.io/badge/Pokopia-2.0.1-5aa02c?style=flat-square)
![Windows and Linux x64](https://img.shields.io/badge/Windows%20%7C%20Linux-x64-555555?style=flat-square)
[![MIT licence](https://img.shields.io/badge/licence-MIT-777777?style=flat-square)](LICENSE)

[**Download**](https://github.com/MelianLuthien/pokocraft/releases/latest) ·
[Install guide](docs/INSTALL.md) ·
[Changelog](CHANGELOG.md) ·
[Build from source](docs/BUILD.md)

</div>

## What it changes

With PokoCraft, a craft **never uses up materials**. One setting decides whether
you need to own them:

| Bypass Requirements | What happens |
|---|---|
| **On** (default) | Crafting ignores whether you have the materials. The quantity selector goes up to 99 per craft. |
| **Off** | The game checks your bag before crafting, as it normally would. |

PokoCraft changes crafting only. It does not add items to your bag, touch your
storage or edit recipe data, so recipes still list their usual ingredients.

## Install

You need **Recompia 0.16.0 or later** with **Modtopia**, and **Pokopia 2.0.1**
(build `76a489f3bd3642fa5e18bd83d32c98ba`). Windows x64 and Linux x64,
including Steam Deck.

1. Download `pokocraft-1.0.1.pkmod` from the [latest release](https://github.com/MelianLuthien/pokocraft/releases/latest).
2. Copy it into Recompia's `mods` folder.
3. Start the game and set **Bypass Requirements** in the mod's settings.

No RomFS patch and no `pkp.ini` change are needed. The
[full guide](docs/INSTALL.md) covers checking the download's SHA-256,
uninstalling and troubleshooting.

## Good to know

> [!IMPORTANT]
> **PokoCraft is a cheat**, and says so (`tags = ["cheat"]` in `mod.toml`).
> Modtopia keeps shared achievements off while it is enabled.

- **Single-player only.** It runs on your machine, does not connect to the
  internet and does not touch online or shared features.
- **Game build 2.0.1 only.** A game update moves the hook addresses and needs a
  new release.
- **Construction and building costs** are not covered yet.
- **The Expansion Pass (DLC)** is not modified.
- **No game files** are included, copied or patched by the mod.

## Licence

The code and documentation are under the [MIT licence](LICENSE).

This is an unofficial fan project, not affiliated with or endorsed by Nintendo
or The Pokémon Company.
