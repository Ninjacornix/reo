# Retained Windows imported-data mount

`MountedResources::open_file1_windows(dataRoot, optionalPlanPath)` builds a
private, read-only File #1 extracted-data/PAK mount. It returns either an admitted
`shared_ptr<const MountedResources>` or a typed failure with no partial mount.
There are no guest addresses, environment switches, global active overlay,
automatic threads, ResourceSession singleton, new archive reader or launcher
changes. This factory has not been connected to game consumers.

The factory reads `parent(dataRoot)/import.json` once from a retained read-only
handle, bounded to the existing 8 MiB limit. It hashes those exact bytes and calls
the existing Windows.Data.Json `parse_import_manifest` V1/V2 File #1 admission.
Every imported file is opened by `PinnedFile::open_verified` using its manifest
length and digest. A nonfollowing regular-file gate rejects a reparse leaf and
compares its file ID against that of the retained PinnedFile. Directory component
handles reject reparse ancestors and retain namespace objects against ordinary
rename/delete while this mount lives. File bytes and hashes use the same retained
PinnedFile handle. No provider reopens a pathname after admission.

Only local fixed/removable drive paths are admitted; UNC/device namespaces and
raw volumes are unsupported. Imported **file** names must be ASCII because the
current PAK facade uppercases narrow names. The existing manifest parser still
owns path grammar and case-collision admission. Actual regular files are
enumerated with the same relative-name/backslash/uppercase key semantics as
CDVD, with explicit rejection of reparse/nonregular entries and case collisions.
The actual key set must equal the manifest; a second check catches namespace
changes observed during admission. Empty ordinary directories are harmless.
This is not a filesystem transaction against hostile concurrent changes.
The mount also bounds retained directory guards to 65,536 and its internally
encoded identity description to 32 MiB; unsupported larger inputs fail explicitly.

`routes()` is immutable metadata plus retained native ByteViews. Original routes
sort by uppercase ASCII/backslash key, independently of manifest row order, start
at LBA `0x01000000`, and advance by `ceil(bytes/2048)+0x4000`, preserving the
current facade's bounds and zero-filled read-ahead regions. Zero-byte imported
files are supported. `find_file` requires an already-canonical key; it does not
invent another PS2 URI parser.

An optional overlay plan is read once from a retained handle, bounded to the
existing 16 MiB limit. The existing Overlay/PlanReader parses it exactly once.
Its two-argument `VerifiedSourceResolver` supplies original/ELF sources from the
already admitted import and verifies any provided expectation against that row.
Replacement requests must carry both length and SHA-256, which feed PinnedFile
directly. The existing 256 MiB replacement hash limit is checked before pinning.
Overlay still performs every existing game/ELF, base-leaf/replacement hash,
path/AFS/extent/size/layout check. Its generated memory and retained source
segments are frozen through VirtualFileView. No-op replacement handles remain
retained by the mount, even though they create no virtual archive.

File lookup selects overlay routes when present; original PAK LBAs still select
the original imported bytes. Overlay LBAs/layout/padding come from the existing
Overlay implementation, including its one-sector gaps. `resolve_sectors` performs
no I/O: it returns a retained view, byte offset, total output size and in-file
prefix length. A caller zero-fills private staging and reads only a positive prefix
through ResourceSession; publish the completed output only after exact success.
A zero prefix means no provider call, since the offset may be
beyond EOF. Crossing a route or violating `1..0x4000` sector counts fails before
I/O. ResourceSession's separate maximum-read policy remains the caller's concern.

`identity()` contains manifest version, exact manifest/plan byte hashes, actual
volume/file IDs, captured lengths/content digests and a computed route digest.
That digest includes ordered route/LBA/capacity metadata and segment descriptions
with retained source identities or generated-memory hashes. It is computed
internally; no caller-supplied `verified` flag or provenance string admits bytes.
The local manifest is unsigned: matching it does not authenticate every file as
a canonical retail disc. The supported ELF hash pins the executable revision.

PinnedFile's ordinary read-only sharing excludes write/delete opens, including
through hard links. It does not revoke a writable mapping established earlier.
This mount adds no private content snapshot or stronger filesystem guarantee;
the provider's content-immutability precondition still excludes such mutation.
Returned views retain their referenced file providers after facade destruction;
retain the whole mount as the request owner when its complete identity, directory,
manifest/plan and unused/no-op source lifetimes must also cover completion.
All ownership cleanup runs without registry/queue locks in this factory.

Raw ISO LBAs are deliberately absent: import.json does not record ISO file
extents or a whole-image digest. Do not use these PAK LBAs as original disc LBAs.
An eventual adapter must explicitly admit the PAK/virtual-route mode and preserve
its completion/error/stop ownership; this class does not redirect CDVD or FIO.

## Standalone validation

```text
python tools/native_reconstruction/verify_mounted_resources.py --cxx C:/msys64/mingw64/bin/g++.exe
```

CTest can pass `--executable <built mounted_resources_tests.exe>` to skip compilation
and record its SHA-256. `--cxx` is optional in that mode; supply the correct LLVM
runtime DLL PATH when using its executable. `--output` can select separate GCC/LLVM
receipt directories named `mounted-resources-checks` under either repository
ignored build root (`build-native-sjuni` or `build-function-index`). Prebuilt
receipts describe the current source snapshot without asserting that the binary
was compiled from it; retain the accompanying CMake/build evidence separately.

The driver builds with C++20 and `-Wall -Wextra -Wpedantic -Werror`. Synthetic
archives/manifests/plans check V1/V2, raw BOM identity, unsorted/mixed-case rows,
hard-link sharing, empty sources/replacements, PAK ordering/LBAs, overlay file
precedence, original-sector retention, exact prefix/EOF/read-ahead padding against
the existing CDVD facade, concurrent reads, last-view handle release, frozen
routes, content/length/manifest/file-set failures, overlay checks and native-created
NTFS junction rejection in both import and replacement paths. The owned ELF is
copied only into the ignored private fixture tree for unchanged identity checks;
none of its instructions execute and user assets are not written.

The source/compiler-bound receipt is
`build-native-sjuni/mounted-resources-checks/receipt.json`. No game, PS2 runtime
library, original ISO/archive, decoder, live callback or gameplay is executed.
