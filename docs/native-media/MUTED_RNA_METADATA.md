# Muted RNA metadata handoff

Status: implementation and isolated qualification passed. No matching game
retest or three-source game success is claimed yet.

V21 reaches actual native playback but stops when its third source lacks a raw
PCM route. The original SDK's `dtxConsumeActivePs2RnaStreamsLocked` first calls
`configurePcmVoice` for every row in `g_dtx_ps2rna_by_handle`, in actual unsorted
container order, including muted rows. Its ordinary replacement omitted this
registration. Sorting RNA handles or weakening the source-order guard would not
recover that traversal.

Dependency patch `0130` adds the explicit versioned operation
`refreshMutedRnaMetadataV1`. It takes the exact runtime's sound-control lease,
requires the native RAM backend, installs the same sound-call scope and holds
the existing RNA metadata mutex. It validates the complete bounded table before
issuing any request. Playing legacy rows, invalid identities/channel metadata,
an unconfigured UID range and more than 2,041 rows are refused. It then calls the
unchanged configuration helper for every actual row, in container order.

It never queues or consumes original PCM, enables an original source or updates
the original progress/consumption clocks. Request counts describe issued facade
calls, not confirmed bridge registration. The ordinary adapter explicitly calls
the refresh outside native controller admission and output callbacks, then uses
the existing read-only `PcmOrder` copy and complete membership validation. The
three-source guard remains authoritative. The lease precedes the RNA mutex,
matching the original RPC control lock order.

The existing pre-run DTX layout/reset operation clears the global RNA/SJ maps
while holding both RPC mutexes and the actual selected owner setup reservation.
The source factory already requires the matching CD/layout receipt and a single
selected runtime. The new operation does not bypass those publication rules or
automatically attach another runtime. Foreign/closed admission is rejected
before metadata requests.

The complete 131-patch series reapplies in a fresh checkout at
`c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f`. The dirty active submodule is untouched.
The isolated comparison uses the actual frozen SDK130 muted branch, unchanged
ring resolution/configuration helper, actual SDK RNA/SJ structs and each
compiler's real unordered containers. Both compilers pass 38 snapshots and five
detected counterfactuals: omitted muted registration, enabled playing rows,
modified clocks, missing complete preflight and reversed traversal. Runtime
admission, configure and device remain explicit ports; this comparison alone
does not prove actual runtime admission, PCM waveform parity or historical
mailbox timing equivalence.

Both compilers compile SDK131 production sound objects and the five root
adapter/factory objects. Each also passes all 21 existing factory protocol
scenarios. These use declared runtime/device ports and the unchanged SDK130
facade declarations; they are distinct from actual SDK131 object compilation.
The native core's 292 qualified inputs remain byte-identical, so the existing
78-suite archive receipts remain applicable without another archive rebuild.
Both compilers pass 23 adapter scenarios and detect ten runtime faults,
including omitted refresh and ignored metadata refusal. The scenarios cover recovery from an
empty order for three actual imported source workers and metadata refusal.
Actual game validation must still demonstrate the native route map and room
transition. All failures remain explicit; there is no original-source fallback.

Exact source and receipt identities are retained in
`tools/native_reconstruction/muted_rna_metadata_qualification.json` and the V6
ordinary-runtime source manifest. Earlier V5/SDK130 manifests remain historical
inputs and are not rewritten to describe this implementation.
