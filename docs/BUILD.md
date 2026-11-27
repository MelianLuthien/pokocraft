# Build from source

The mod is a single C file, [`src/pokocraft.c`](../src/pokocraft.c), that uses
the Modtopia SDK header (`<modtopia/modtopia.h>`). The header ships with the
Modtopia SDK and is not part of this repository.

```sh
zig cc -target x86_64-windows-gnu -shared -std=c11 -O2 -Wall -Wextra -Werror \
  -I "path/to/modtopia/include" \
  -o "bin/windows-x64/mod.dll" "src/pokocraft.c"
```

Then package `mod.toml` and `bin/windows-x64/mod.dll` into a `.pkmod`: a zip
with exactly those two paths, using forward slashes.

[Back to the README](../README.md)
