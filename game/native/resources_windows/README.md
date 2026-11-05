# Windows resource admission

This native adapter is independently built; no game resource call is redirected
by it. It uses Windows APIs and the portable resource core, without PS2 runtime
headers, guest addresses or an installed Python requirement for the game.

`PinnedFile::open_verified` accepts an absolute path, expected length and SHA-256.
One retained read handle supplies file ID/volume identity, bounded streaming
BCrypt hashing and every subsequent positioned read. It shares read access only,
so ordinary write/delete opens, including hard-link aliases, fail while retained.
No pathname reopen is used. Hashing uses 256 KiB chunks; reads serialize the
per-handle file position and cap each OS call at 4 MiB. Native sessions retain
the provider through accepted reads and publish only exact successful output.

Read-only sharing is not a private byte snapshot: mutation through a pre-existing
writable mapping is outside this provider's immutability contract. A matching
local manifest digest also does not authenticate a canonical retail asset.
The identity records the retained object, observed digest and resolved path.
The path is provenance; reads continue through the handle.

The [manifest reader](README_IMPORT_MANIFEST.md) admits the launcher's existing
File #1 V1/V2 import metadata through Windows.Data.Json, with bounded strict
integer and relative-path rules. Parsing metadata does not open or verify files.
The [mount](README_MOUNT.md) binds actual files, virtual layout and edition;
the [synchronous reader](README_READER.md) exposes exact in-file sector reads.
`facade_layout.hpp` compares the native mount against the facade's actual
captured PAK mode, route keys/LBAs/lengths/read-ahead and retained file objects.
The first game integration rejects overlays; their isolated mount support does
not establish ownership of the facade's mutable active-overlay state.

Standalone checks are included in `game/native` CMake/CTest. GCC 15.2 and the
pinned LLVM-MinGW 20251216 compiler build the library and pass all ten suites
in the combined native project. LLVM test execution requires its runtime DLL
directory on the test process's PATH (or ordinary deployment beside the tests).
Synthetic pinned-file
checks cover digest/length refusal, Unicode, exact ranges, file IDs, hard-link
sharing, lifetime, concurrent positioned reads and hashing a file larger than
256 MiB while whole-file C++ allocation is forbidden. Manifest checks cover
121 admission/apartment cases. No imported asset, game or process is run.

`tools/native_reconstruction/verify_pinned_file.py --cxx <compiler>` writes a
source/compiler-bound receipt below `build-native-sjuni/pinned-file-checks`.
CTest uses its `--executable` mode to exercise the binary it just built. Python
is only a developer fixture/test tool. The production library links Windows
`bcrypt` and `runtimeobject`; manifest apartment tests also link `ole32`.
