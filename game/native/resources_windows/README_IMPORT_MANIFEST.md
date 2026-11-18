# Windows import manifest admission

`parse_import_manifest(span<const uint8_t>)` consumes the bytes of the launcher's
existing `parent(dataRoot)/import.json`. It opens no files. Windows.Data.Json owns
JSON structure and value decoding through raw ABI COM interfaces; there is no
independent JSON or archive parser and no C++/WinRT generated dependency.

Admission returns typed V1/V2 File #1 metadata with a pinned ELF digest and the
matching nonempty `SLUS_207.65` file row. The caller must separately pin actual
files and verify their lengths/digests. `Source` is optional provenance only;
`SourceLength` and `SourceWriteTicks` are not converted or claimed exact. A caller
needing their original spelling should retain/hash the original manifest bytes.

Limits are 8 MiB UTF-8 input, 32 nesting levels, 65,536 file rows, 1,024 UTF-8 bytes
per relative path, 255 UTF-16 units per component and unsigned 32-bit file lengths.
UTF-8 decoding and JSON strings reject invalid Unicode. Paths normalize slash
separators and reject traversal, absolute/drive/namespace paths, empty components,
Win32 device names, trailing-dot/space aliases, control characters, reserved path
characters and `~` short-name spellings. Invariant uppercase keys reject
case-insensitive duplicates and file/directory prefix conflicts. The path subset
is intentionally conservative; it does not admit every possible Windows name.

A small lexical admission filter skips JSON strings and rejects numeric spellings
containing signs, decimals, exponents or more than 20 digits. Existing launcher
manifests serialize integers as decimal digits. This restriction covers unknown
and provenance fields too. It is necessary because Windows.Data.Json exposes
numbers as `double`: a floor/range check alone would admit a near-integer decimal
after rounding. OS parsing still validates all JSON syntax and typed fields.

Each successful `RoInitialize`, including `S_FALSE`, is balanced. An existing STA
is retained by retrying its mode after `RPC_E_CHANGED_MODE`; the failed mode-change
attempt is never uninitialized. COM objects are released before apartment cleanup.

Standalone synthetic tests require no imported user files:

```powershell
& C:/msys64/mingw64/bin/g++.exe -std=c++20 -Wall -Wextra -Wpedantic -Werror `
  game/native/resources_windows/import_manifest.cpp `
  game/native/resources_windows/import_manifest_tests.cpp `
  -lruntimeobject -lole32 -static-libgcc -static-libstdc++ `
  -o build-native-sjuni/import_manifest_tests.exe
& build-native-sjuni/import_manifest_tests.exe
```

The installed LLVM/MinGW 20251216 `x86_64-w64-mingw32-clang++.exe` supports the same
sources and Windows import libraries. Standard toolchain headers are treated as
system headers by both compilers; no project warning suppression is needed.
That LLVM release's `windows.foundation.h` duplicates the unused
`IReference<BYTE>`/`IReference<boolean>` specialization. A local Clang/MinGW-only
guard in this implementation skips the unused Boolean specialization; JSON ABI
interfaces remain intact and installed toolchain files are not changed.

Microsoft references:

- [JsonValue.GetNumber returns Double](https://learn.microsoft.com/en-us/uwp/api/windows.data.json.jsonvalue.getnumber)
- [JsonValue.Parse](https://learn.microsoft.com/en-us/uwp/api/windows.data.json.jsonvalue.parse)
- [RoInitialize balancing and apartment rules](https://learn.microsoft.com/en-us/windows/win32/api/roapi/nf-roapi-roinitialize)
