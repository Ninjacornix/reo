# Synchronous exact mounted reader

`MountedReader::open_file1_windows(dataRoot, optionalOverlayPlan, maxReadBytes)`
returns `{MountStatus, shared_ptr<MountedReader>, detail, system_error}`. The
default positive read budget is 8 MiB. It owns the verified MountedResources,
one ResourceSession and opened generation handles for every immutable route.
Handle capacity is the route count, rather than the session's generic default.
Construction failure publishes no partial reader. Destruction closes handles,
shuts down/drains the session and releases the mount afterward. Keep the reader
alive until all method calls finish; concurrent caller destinations must be
disjoint or synchronized.

`read_sectors(lba,count,span<byte>) noexcept` is synchronous and returns
`{ReaderDisposition, resource_status, bytes}`. The dispositions mean:

- `not_covered`: before provider I/O or destination changes, the count is outside
  `1..0x4000`, output size differs from `count*2048`, the configured budget is
  exceeded, the LBA route is unknown/crossed, or any requested byte would require
  EOF/read-ahead padding. Only this result permits an external legacy fallback.
- `ok`: ResourceSession read and staged exactly all requested in-file bytes, then
  copied them to the destination. `resource_status` is `Status::ok` and `bytes`
  equals the complete requested byte count.
- `failed`: an admitted native read failed. Output is unchanged, `bytes` is zero,
  and the resource status distinguishes allocation/source/handle failures.
  Never restart a failed read through an unchecked pathname or legacy fallback.

For coverage rejection, `resource_status` is `invalid_range` or `read_limit`;
these describe the excluded domain rather than an attempted source read. Empty
reads, partial final sectors and ordinary PAK prefetch remain outside this first
native domain. Overlay-generated headers/payload sectors wholly in-file and
original PAK sectors are supported through their existing retained ByteViews.
The reader neither pads nor opens paths while reading.

`identity()` exposes the actual retained mount identity. `mount()` exposes a
const reference for route validation against an already initialized compatibility
facade. Both references require the reader's lifetime. The caller must admit the
actual PAK/virtual-route configuration and matching facade ordering before game
integration; an environment flag alone is not proof. No ISO layout is inferred.

There are no game/PS2 headers, guest addresses, environment switches, workers,
pending target leases, callbacks or global services. Calls finish their reads
before returning. All MountedResources/PinnedFile limits remain: local unsigned
manifest matching does not authenticate an entire retail disc; namespace checks
are not a hostile-change filesystem transaction; previously writable mappings
are not revoked by read-only handle sharing.

Standalone validation:

```text
python tools/native_reconstruction/verify_mounted_reader.py --cxx C:/msys64/mingw64/bin/g++.exe
```

The driver reuses the existing synthetic fixture writer and copies the owned ELF
only as identity data. It builds with C++20 warnings treated as errors. Coverage,
overlay, limit/EOF/padding, concurrency, blocked-read ownership and construction
cases use private new files. The test executable alone substitutes its ReadFile
import pointer to inject short completions, failures after a written prefix and
a blocked read; real reads delegate to the actual OS function. An allocation
fault verifies transactional staging failure. These hooks are absent from the
reader/library and any game target.

CTest may use `--executable <mounted_reader_tests.exe>` without recompilation,
with an appropriate toolchain DLL PATH. `--output` supports separate directories
named `mounted-reader-checks` under the repository's ignored build roots. Each
receipt records binary/source hashes and distinguishes prebuilt provenance from
a source build. No game, original instruction, original archive/ISO, runtime
library, original RPC flow or live guest destination is executed in these checks.
