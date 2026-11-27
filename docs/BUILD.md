# Build from source

The mod is a single C file, [`src/pokocraft.c`](../src/pokocraft.c), that uses
the Modtopia SDK header (`<modtopia/modtopia.h>`). The header ships with the
Modtopia SDK and is not part of this repository.

Zig builds both platforms from either system.

```sh
# Windows x64
zig cc -target x86_64-windows-gnu -shared -std=c11 -O2 -Wall -Wextra -Werror \
  -I "path/to/modtopia/include" \
  -o "bin/windows-x64/mod.dll" "src/pokocraft.c"

# Linux x64 and Steam Deck (-s keeps local paths out of the library)
zig cc -target x86_64-linux-gnu.2.31 -shared -fPIC -std=c11 -O2 -Wall -Wextra -Werror -s \
  -I "path/to/modtopia/include" \
  -o "bin/linux-x64/mod.so" "src/pokocraft.c"
```

Then package `mod.toml`, `bin/windows-x64/mod.dll` and `bin/linux-x64/mod.so`
into a `.pkmod`: a zip with exactly those three paths, using forward slashes.

[Back to the README](../README.md)
