# Native resource boundary

2026-11-05. Status: inventory reviewed; independent read-only core implemented
and checked with synthetic providers. Existing game consumers have not migrated.

The [source inventory](RESOURCE_BOUNDARY_INVENTORY.md) identifies the existing
PAK import, cached-file/virtual AFS byte providers, ISO/sector facade, FIO/RPC
adapters and CRI completion dependencies. It also records a discrepancy between
the accessible dirty dependency source and the public virtual-asset patch;
that discrepancy is not a diagnosis of the player's executable.
The [fresh dependency audit](DEPENDENCY_INPUT_AUDIT.md) successfully reconstructs
all 120 public patches on the recorded base; matching compiled resource-route
inputs and libraries remain a separate gate.

The [native library](../../game/native/resources/README.md) reuses existing
`Source`/`VirtualFile` reads through immutable views. Native session handles have
owner identity, generation retirement, bounded exact reads, typed errors and
explicit close/shutdown/drain. Reads retain a provider lease outside the registry
mutex; failed reads leave the destination unchanged. There are no guest addresses,
automatic threads, runtime headers or new archive parsers.

Nine focused synthetic groups pass, including owned nested subranges near the
64-bit boundary without copying payloads. The combined standalone `game/native`
CMake project builds four core/bridge/resource/worker suites, and all
four pass CTest. These checks cover synthetic file/memory/gap reads, frozen
metadata, malformed and 64-bit extents, failures, stale handles and provider
lifetime while close/shutdown races an accepted read. The files backing mounted
views must remain externally immutable; file identity/content is not continuously
verified by the core.

The source/compiler-bound `tools/native_reconstruction/verify_resources.py`
also passes 256 native/Source/host-file range comparisons and 36 existing PAK
sector-prefix/padding comparisons over a synthetic 65,539-byte file. The native
exact reader rejects EOF overrun and preserves output; the existing sector facade
still supplies explicit zero padding. This checks the existing facade as an
oracle, without redirecting it or launching a game. Its receipt is
`build-native-sjuni/resource-verification/receipt.json`.

Remaining work is concrete: pin verified edition/content/mount identity at the
owning service; extend byte comparisons to replacement-aware mounted views and
owned import identities; then migrate one caller with its original completion, EOF/padding and
stop ownership. Positioned reads alone do not replace CRI reservations, decoder
control, guest callbacks, cancellation or shutdown synchronization. No dependency
removal, original-game I/O parity or performance improvement is claimed.

The [cvFs request review](CVFS_REQUEST_BOUNDARY.md) checks 33 original bodies and
defines the next safe cut: a wholly in-range payload read beneath the existing
request owner. Original admission, service-driven completion, borrowed SJ span
publication and stop/close stay explicit until their contracts migrate.

The [request-owner implementation](REQUEST_OWNER_IMPLEMENTATION.md) adds the
opt-in joinable worker and runtime stop/join boundary. Isolated checks pass;
matching linked-candidate validation and mid-game reservation ownership remain
pending before the new resource byte provider is connected.
