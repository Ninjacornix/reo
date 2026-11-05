# Resource boundary inventory

2026-11-05. Static source inspection only; no game, build, import, I/O replay or
live process was run. This is a bounded dependency inventory for the
[resources/media stage](../NATIVE_RECONSTRUCTION_PLAN.md), not a claim that the
resource subsystem has been reconstructed or newly validated.

Subsequent implementation is tracked in the [current status](README.md) and
[native core](../../game/native/resources/README.md); the observations and
proposed boundary below retain this inventory's original static-only scope.

**A native positioned range reader already exists.** Reuse
`reo::assets::Source` and `VirtualFile` instead of introducing a second AFS parser,
ZIP reader or file-offset engine. The next useful boundary is an immutable,
session-owned read-only archive handle with explicit extent, lifetime and error
semantics, backed by those existing providers. Sector emulation and CRI request
completion should remain separate adapters until their consumers are migrated.

## Current path and status

| Layer | Source evidence | State and remaining boundary |
| --- | --- | --- |
| ISO import | [DiscImage constructor/index/copy](../../launcher/DiscImage.cs:13), [DiscImport.Ensure/Extract](../../launcher/DiscImport.cs:85) | Native managed import: validates ISO9660 file extents and supported executable, copies/hashes imported files into private staging, publishes completed import. This reads the ISO during import; it is not a gameplay file service. |
| Complete game PAK import | [GamePaks.Read](../../launcher/GamePaks.cs:69), [Transfer](../../launcher/GamePaks.cs:103), [Import](../../launcher/GamePaks.cs:139) | Native managed ZIP/range reconstruction, not direct runtime ZIP streaming. Reconstructs complete cached files, including archive headers/padding and boot files; hashes each file on fresh transfer. Ordinary native readers subsequently use cache paths. |
| Replacement preparation | [AssetPaks.Index](../../launcher/AssetPaks.cs:219), [Resolve](../../launcher/AssetPaks.cs:261), [Prepare](../../launcher/AssetPaks.cs:313) | Native managed numeric/unique-name resolution, original/replacement hashes, cache validation and bounded session plan. Installable replacement packs and complete game-source PAKs are distinct formats/roles. |
| Range bytes and virtual archives | [Source](../../runtime/assets/virtual_afs.h:29), [VirtualFile](../../runtime/assets/virtual_afs.h:59), [table/original/build](../../runtime/assets/virtual_afs.h:86) | Implemented native C++ without guest-register/RAM dependencies. Provides file-offset reads, AFS extent parsing and replacement composition. General mount-handle ownership and typed failure/completion contracts are not yet a standalone reconstructed service. |
| Replacement mount | [Overlay constructor](../../runtime/assets/overlay.h:45), [find/sector](../../runtime/assets/overlay.h:118), [hostRead](../../runtime/assets/overlay.h:147) | Native provider, currently owned by process-global `assets::active`. Its lookup pointers and provider lifetime are coupled to CDVD construction/reset and existing adapters. |
| Cached-file/ISO sector facade | [CDVD](../../runtime/cdvd/cdvd.cpp:23), [open_image](../../runtime/cdvd/cdvd.cpp:51), [read_sectors](../../runtime/cdvd/cdvd.cpp:205) | Native implementation of a compatibility facade. PAK mode synthesizes sector extents over cache files; ISO mode still opens ISO or a mounted raw volume. This layer retains console path/LBA semantics. |
| FIO/CDVD RPC bridge | [ReoHwBridge::onSifRpc](../../recomp/overrides/reo_hw_bridge.cpp:2581), [FILEIO branch](../../recomp/overrides/reo_hw_bridge.cpp:2731), [CD branches](../../recomp/overrides/reo_hw_bridge.cpp:2938) | Implemented adapters still take guest addresses, SIF RPC IDs, result buffers, semaphores and runtime objects. Serving bytes natively does not remove these dependencies. |
| Async File #1 disc completion | [reo_cd_async](../../recomp/overrides/reo_cd_async.h:48), [bootstrap configuration](../../recomp/reo_bootstrap.cpp:1305), [override registration](../../recomp/overrides/reo_override.cpp:1721) | Host worker handles one verified File #1 SifCallRpc shape, then runs the original callback with guest execution scope/context/stack. It is not an independent native resource request service. |
| Original CRI stream lifecycle | [file stream service](../SYMBOLS_CRI_FILE_STREAM_SECTOR_READ_SERVICE.md), [cvFs dispatch](../SYMBOLS_CRI.md), [engine archive starts](../SYMBOLS_ENGINE_STREAM_CREATION_AND_AFS_START.md) | Mapped original logic, still distinct from a native implementation. Accepted request counts, completion status, SJ reservation publication, close/stop and decoder consumption remain separate transitions. |

The existing [asset implementation report](../ASSET_PAKS_IMPLEMENTATION.md)
records earlier synthetic and owned-data/gameplay checks. Those are historical
evidence with their stated scope, not tests rerun for this inventory. The current
source checkout and newly proposed resource handle have not been assigned fresh
runtime or real-consumer validation here.

## Import, ownership and publication

`GamePaks.Read` bounds member/file counts, validates safe names, edition/executable
identity, per-file contiguous ranges and complete coverage. `Transfer` consumes
each ZIP member sequentially, rejects truncated/oversized slices and compares the
reconstructed whole-file SHA-256. There is no C++ gameplay dependency on Python
or on a live ZipArchive object.

`GamePaks.Import` hashes the PAK for cache identity, takes `import.lock`, stages
new content privately and publishes it by moving the completed directory. On
same-volume NTFS it may reuse matching existing imports via verified hard links;
it still verifies the PAK payload before creating those links. Completed-cache
reuse instead checks all file sizes and the executable hash; it does not rehash
every cached payload on every reuse. Hard links retain filesystem aliasing to the
old import. A new read-only mount must explicitly require unchanged cached data
for its lifetime or establish stronger content/handle identity; this inventory
does not assume that a cached path is an immutable byte object.

The launcher [prepares the source and checks capability markers](../../launcher/GameSession.cs:87),
including `[GAME-PAK-1]` before PAK play. It sets
[`REO_GAME_PAK=1` or `REO_ISO`](../../launcher/GameSession.cs:245) and normal play
sets [`REO_NATURAL=1`](../../launcher/GameSession.cs:262).
These are source-selection/capability inputs, not proof of which exact I/O route
ran in a particular session.

## Existing range and AFS contract

- `Source` owns a filesystem path, captured size, `ifstream` and mutex. `read(off,n,dst)`
  requires `off<=size` and `n<=size-off`, serializes seek+read, and throws if the
  stream is not good afterward. It has no externally visible cursor: offset is
  supplied for every call. Originals remain open; replacement sources marked
  `transient` reopen on demand and close after a successful read.
- `VirtualFile` owns segment descriptors. Each segment retains a `shared_ptr`
  to a `Source` or in-memory header/name bytes. Copying a completed view therefore
  retains its underlying sources; it does not duplicate payloads. Reads require
  an in-range extent, zero the destination, then fill overlaps from sorted
  segments. Unrepresented alignment gaps become zero bytes.
- `VirtualFile::read` returns immediately for a valid zero-length range. A
  nonzero caller must supply valid writable storage. An I/O exception after
  earlier segments were copied can leave a partially modified destination;
  all-or-nothing output is not supplied by this implementation.
- `table(Source,base,size)` validates AFS magic, count, table/name extents, entry
  alignment and header-size limits. `build` retains entry order/indices, recurses
  to a bounded depth, aligns children to 2048 bytes, rebuilds table offsets and
  selected name-size fields, and caps virtual size below 4 GiB. No changes means
  `original` returns an identity range, preserving original padding.
- Replacement admission excludes whole nested archives and room `_h.bin` name
  tables. `Overlay` rechecks the executable and targeted original/replacement
  hashes before mounting changed archives. Exact-identity replacements do not
  require virtual repacking.
- `VirtualFile`/segments are public mutable structures; a generic service cannot
  accept arbitrary caller-built segments and infer the sorted/nonoverlapping
  builder invariant. Freeze builder-produced views or validate imported views.
- The current `table` parser accepts `Source`, not an arbitrary `VirtualFile`.
  A future native leaf resolver must not apply original offsets to rebuilt
  virtual bytes. Generalize the existing parser's reader boundary if needed;
  do not add a second parser that silently disagrees about replacement offsets.

`Overlay::find` returns a pointer into its owned map. `assets::active` is an inline
global `unique_ptr`; each CDVD constructor resets/replaces it. Existing FIO
descriptors retain keys/positions, not shared ownership of that mount. A new
session-owned handle should retain its view explicitly instead of assuming that
the global mount cannot change during asynchronous work.

## PAK versus live ISO/CD routes

`CDVD::open_image` gives PAK mode priority. It sorts cached paths, maps them from
LBA `0x01000000` and leaves a `0x4000`-sector read-ahead area after each file.
PAK mode returns before opening `REO_ISO` or a raw volume. `has_image()` is true
for PAK mode too; its name is not proof that an ISO file is open.

In ISO mode, `open_image` opens `REO_ISO` read-only and determines its length. On
Windows a drive-root data path can instead open `\\.\X:` for raw-volume reads.
`read_sectors` holds a mutex around its shared image cursor and seek+read.
`search_file` parses ISO9660 directories through that same sector route when no
virtual archive/PAK map handles the name. Removing the ISO requirement therefore
requires migrating those remaining raw-LBA/lookup consumers, not changing the
launcher picker alone.

The exact current policies differ:

| Route | Extents / EOF / error behavior |
| --- | --- |
| `Source::read`, `VirtualFile::read` | Strict byte extent, positioned read. Out-of-range throws; mid-read failure can leave output partly modified. |
| `Overlay::sector` | Virtual LBAs start at `0x20000000`; count is 1..16384. Reads cannot cross the selected archive's rounded sector extent; the final partial sector is zero-padded. The allocation gap is not a generally readable extension. |
| `Overlay::hostRead` | Reports whether the path names a mounted archive, zeros the requested output and copies only bytes before virtual EOF. A mounted path can return true for a read entirely beyond EOF; true means provider handled it, not exact bytes read. |
| PAK-mode `CDVD::read_sectors` | Count is 1..`0x4000`; cached-file payload plus bounded `0x4000`-sector read-ahead is supported. It opens the cached file per read, zero-fills requested output, reads the available prefix and requires that prefix's exact `gcount`. No adjacent mapped file data is exposed. |
| ISO/raw-volume `CDVD::read_sectors` | Nonzero count, maximum 32 MiB and known-image bound; seek/read must deliver the full requested sector bytes. Raw volume size is left unknown locally. |
| CDVD whole `read_file` | Copies a whole host or virtual archive into an owned vector. The plain-host branch does not check final `gcount`/stream status before returning true. It is not the strict range-reader result contract. |
| HW FILEIO read | Per-descriptor position; returns actual bytes up to EOF and advances by those bytes. Mounted archives use their own virtual position; ordinary files use `fread`. Acceptance and result/semaphore publication are separate fields. |

Do not merge strict reads, short EOF reads and zero-padded sector reads into one
boolean API before recording which policy each consumer needs. Paths also differ:
CDVD normalization, overlay `pathKey`, and SDK loose/numeric lookup are not the
same name resolver or ambiguity policy.

## Completion, seek and retained runtime dependencies

The [HW FILEIO server](../../recomp/overrides/reo_hw_bridge.cpp:2731)
handles service `0x80000001`. Open/read/close/lseek writes the operation result to
the request's result address, sets receive word to accepted, then signals the
specified semaphore through `hleSignalSema`. Reads currently perform host I/O in
that handler. Virtual seeks support SET/CUR/END and restrict the resulting byte
position to `0..0x7FFFFFFF`; underlying ordinary-file seeks use the existing
64-bit [host_file helpers](../../runtime/core/host_file.h:14) before narrowing.
Close releases the host file and archive key. IOP reboot closes all these FDs
and clears keys. The native byte provider does not own that protocol lifecycle.

The CD N-command RPC `0x80000595` read remains synchronous in the fallback handler;
it cannot freely release guest execution while the SIF call mutex is held. Its
returned control fields are not a byte-count result. Search service `0x80000597`
returns LBA/size metadata, using different packet path offsets for the recognized
packet sizes. DVD readiness/status/tray replies are compatibility responses.

`reo_cd_async` intercepts only the verified File #1 call to SifCallRpc at
`0x1179E8`: client `0x208AD0`, operation/mode 1, send `0x207A00`, size `0x18`,
return address `0x101908`, callback `0x1004D8`. Other requests delegate. A host
worker reads through `ReoHwBridge::readCdSectors`, then creates an original guest
callback context, reserves an async stack and invokes that callback under
`PS2Runtime::GuestExecutionScope`. The read-success flag is logged here; it does
not locally gate callback invocation or publish a separate failure status. Stop
and callback availability gate dispatch. The worker is detached with a global
queue and no shutdown/join path in this header. Raw RAM/runtime lifetime and
pending-request drain/cancel belong to a future request-owner contract.

Original mapped consumers reinforce why bytes alone are insufficient:
`cvFsSeek 0x135D60`/`ReqRd 0x135DC8`/`GetStat 0x135F50` dispatch through a backend;
`0x130800` reserves SJ buffers, submits sector counts, waits for later status,
publishes the accepted count to pool 1 and returns unused suffixes to pool 0.
`0x130B78` handles deferred stop/close/open only when no read is in flight.
Engine `0x1ADA20`/`0x1ADB30` initiating an archive member is not a playback or
resource-ready completion. Those mapped contracts remain pending native service
and real-consumer parity; this pass adds no original function-name credit.

The separate `runtime/iop/IopHLE::hle_cdvd` implementation is also guest-memory
coupled. Its sector branch calls `CDVD::read_sectors` but reports success without
propagating that boolean. Its filename branch heuristically interprets packets
and copies a whole vector. Existence of this alternate path does not establish
that it serves the selected native executable; dispatch/build selection needs
its own evidence.

## Dependency source and patch reconciliation

The recorded and accessible dependency HEAD is
`c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f`, with many local source modifications.
The working sources are under `third_party/PS2Recomp/ps2xRuntime`, not an older
PS2Runtime header layout. `git submodule status` printed a `-` prefix in this
workspace, but the source checkout and its own Git HEAD are accessible; that
status alone must not be interpreted as absent source.

There is a concrete current source/patch discrepancy:

- Actual [Support.h](../../third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Stubs/Helpers/Support.h:8)
  uses pseudo LBAs from `0x00100000`. Its `registerCdFile`, `readHostRange` and
  `readCdSectors` have no `reo::assets` branches. Host ranges zero output and
  perform a read without checking final `gcount`, then report success after
  opening/seeking. Unmapped LBAs can fall back to `PS2Runtime::IoPaths::cdImage`.
- Actual [Syscalls/FileIO.cpp](../../third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/FileIO.cpp:76)
  uses plain `fopen`/`fread`/`fseek`/`ftell`, with no overlay include or `g_assetFds`.
  Its seek width/error behavior is therefore not the root HW bridge's virtual
  archive policy. It still uses guest buffers/registers and global FD locks.
- Actual [SDK CD stubs](../../third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Stubs/CD.cpp:6)
  use those helpers, include alternate argument-layout recovery, clamp read
  bytes to RAM backing and return immediate nonbusy from `sceCdSync`.
- Reproducible [patch 0109](../../third_party/patches/ps2recomp/0109-virtual-asset-archives.patch)
  adds overlay-aware SDK and syscall paths and moves pseudo LBAs to `0x40000000`.
  Those additions are absent from the actual dependency files above, while the
  root CDVD/HW bridge source already contains overlay routing.

This is an unresolved build-input integration difference, not evidence that the
player's current PAK session failed. A selected executable may have linked a
different patched library. Reconcile the required patch series and matching
compiled objects before making route-coverage claims or editing dependencies.
No private old build folder is needed to establish the discrepancy above.

`AfsArchive` in `game/formats` and `NetbioReader` in `recomp/overrides` are other
readers, not the replacement-aware mounted provider. The former loads an entire
archive and its parser has weaker truncation/extent admission than `table`;
the latter owns a mutable `FILE*` cursor, returns actual short `fread` counts and
has guest-RAM helper methods. Its two found call sites are snapshot-injection
paths: one explicitly disabled, one disabled by normal `REO_NATURAL` launch.
Neither is a reason to duplicate the current virtual AFS implementation.

## Bounded next contract

Implement or extract a **read-only mounted file/view handle** around the existing
`Source`/`VirtualFile`, independently of `PS2Runtime`, ISO LBAs, guest addresses,
SIF packets and CRI scheduling. This is a proposed next deliverable, not code
added by this inventory.

1. Mount a verified imported-file view or builder-produced virtual archive;
   retain its sources with shared ownership and pin edition/content/mount identity.
   Opening a handle must not depend on the mutable global `assets::active`.
2. Expose length and `read_at(offset, destination)` with checked 64-bit bounds,
   explicit exact/short/failure results and a documented partial-output rule.
   Reuse existing segment reads. Do not add a second decompressor, AFS parser or
   source-position implementation. Runtime ZIP streaming is unnecessary for
   this milestone because PAK import already produces verified cached files.
3. Add a bounded subview only if it retains the parent and validates base/length
   once. If member-index resolution is needed, adapt the existing table reader to
   the effective virtual bytes. Preserve index/order and replacement layout.
4. Keep optional cursor/SET-CUR-END behavior outside the positioned provider.
   Its adapter must preserve original signed widths and EOF behavior. Keep
   padded sector reads as explicit compatibility policy rather than pretending
   they are exact archive bytes.
5. The first comparison target is byte/range parity across existing Source,
   VirtualFile, host-file and PAK-sector routes using synthetic files and owned
   import identities. Cover identity padding, changed nested sizes, gaps, final
   sector, read-ahead, EOF, overflow, invalid views, concurrent independent reads,
   failed/truncated sources and handle lifetime after owner release.
6. Only afterward connect one proved consumer and its completion owner. A pure
   range source alone does not replace `0x130800`, SJ reservation handoff,
   decoder ownership, stop/close, cancellation or async shutdown. Do not remove
   syscall/IOP/RPC code before its remaining users migrate.

Existing [virtual AFS tests](../../tools/assets/test_virtual_afs.py),
[native probe](../../tools/assets/virtual_afs_check.cpp) and
[PAK sector probe](../../tools/assets/game_pak_routes_check.cpp) are useful starting
oracles for those existing byte policies. They were inspected, not executed in
this pass. New handle/error/lifetime checks and source/build identity must be
recorded before calling the next contract validated.

## Source identity snapshot

Hashes below identify inspected source inputs, including dirty dependency files;
they do not identify a linked executable. Only this Markdown file was added by
the resource inventory task.

| Input | SHA-256 |
| --- | --- |
| `launcher/GamePaks.cs` | `83a37f75379c6bd44346a003790b22d29980dcd315fbb05e7f08a0c35392a669` |
| `launcher/DiscImport.cs` | `10b4d1710dc6fbbce5ecb1dea1846f8c2763df104f3d51858bbfa5084b24319c` |
| `launcher/DiscImage.cs` | `a4c80d522997e0deb93594968351f55514f7c44e58d8c8dba44f1a68a5c646ec` |
| `launcher/AssetPaks.cs` | `ad96927cd268946dbe7c8faaf5831deb2edaf6cb8678ac920e18609f370a6efa` |
| `launcher/GameSession.cs` | `d27e7a086d7344a1d957d669753872774a13040620f7a8fcabb3fff4cf695518` |
| `runtime/assets/virtual_afs.h` | `b43dd6d0b76204cd5a8ea22c67282c08da911ff14e7548ad590da6aaf8eef196` |
| `runtime/assets/overlay.h` | `79728d0658015938046284a15fcad264138b42b91fbbcc83bfe52396e3560f8c` |
| `runtime/cdvd/cdvd.cpp` | `440cfd85512be78f715c6caca485f23fb5c2683415d89fdec00f985dc89e08d2` |
| `runtime/core/host_file.h` | `4b50318f357371735cddf5ebb2e89cd66e4dcef73d50971569eba4cc5a7a8416` |
| `recomp/overrides/reo_cd_async.h` | `f0a2be2a318e8fadb9bf1776c07f6b416207207646a46864e0c62433396f1381` |
| `recomp/overrides/reo_hw_bridge.cpp` | `adc667f73cf2d0ca34a3a2da407f1b47e54997abada752110c1f46a094acdb63` |
| `recomp/overrides/reo_netbio.cpp` | `e0d7a6427e77805df62f9da653567da422e194d5b2353e5bdec1e4268b7f1821` |
| `game/formats/afs_archive.cpp` | `9b393c568123397515e3ad8daf2e5a27c91a9e82b43d8592bf28cfef764cd4bb` |
| `third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Stubs/Helpers/Support.h` | `e52884fc5fc1ee5d05b21dcddff41dc7dcd5e4a8e30af15089db3a18f876ceae` |
| `third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Stubs/CD.cpp` | `40dcc336889e157372f969e648f1f7adeef1619944336906b2cffb4114c2b363` |
| `third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/FileIO.cpp` | `109ec25f69f1fffe11d93a32d639937ea89ee121a0b2f6155b7f30d9ce307d98` |
| `third_party/patches/ps2recomp/0109-virtual-asset-archives.patch` | `ec11fb9742cae82e91e3ee947f68f3cff5d374392a2e39e76a811b46de7e72e3` |
