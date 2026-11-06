# Explicit native sound RAM capture companion

Status: isolated SDK dispatch infrastructure. No production RAM capture provider
is supplied, installed, or admitted by this work. No game/device was started and
no runtime library was linked. The ordinary no-companion path remains enabled.

## Inputs and reproducibility

The authoring tool is
`tools/native_reconstruction/audio_ram_capture_dispatch/prepare_patch.py`.
It checks the complete prior125 receipt, every recorded prior source file and
every public patch before copying a small set of files to a new ignored author
directory. It never edits the active `third_party/PS2Recomp` checkout. All new
text is UTF-8 with LF endings.

Prior source is `build-native-sjuni/dependency-bank-reapply-v3`, based on
`c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f` plus125 public patches. Its receipt
SHA256 is `3019662f2fd62dbe4a9b3c7b99528bd631338424597ad78d2a4a04bcebeb3d6a`.
Public0124 SHA256 is
`1c08f9667edee15dbeeb0e332b12473d0ae77433519dde22c32e1c329f7fa377`.
The prior actual `CriAudioBackend.h` SHA256 is
`631db6363db9a8945711f5c305ed8bfb0628ca50b3625cc2492e2afb3987f126`.

The new public patch is
`third_party/patches/ps2recomp/0125-explicit-native-sound-ram-capture-companion.patch`.
Its fresh full series contains126 patches. Apply/reverse checks and object
compilation are source/ABI evidence; matching rebuilt runtime libraries remain
mandatory before any application uses this interface. See
[dependency patch workflow](../../third_party/patches/README.md).

## Atomic selection and lifetime

`CriAudioRamCapture.h` declares a separate versioned `NativeSoundRamApiV1`.
Published V1/V2 table, registration and `SoundCall` layouts are unchanged. The
only change in `CriAudioBackend.h` is a non-layout friend declaration; the
verifier compares the entire old header after removing exactly that line.

`installBackendWithNativeSoundRamBeforeRunV1(runtime,registration,capture)`
validates the complete V2 PCM/bank/render table and all companion callbacks,
version, size, capabilities, owner and finite packet limit. There is one shared
registration owner and one private Binding/worker; no independent RAM owner or
late per-operation companion installation exists. An invalid partial API does
not register a worker or select a backend.

The NEW install API holds a real allocation-free `PreRunSetupLease` across
worker registration **and** Binding/companion publication. Actual runtime
`beginExternalWorkerRun` waits that lease. Old V1/V2 APIs retain their prior
behavior. Stop remains nonblocking and can defeat publication; an unpublished
worker is inert and never invokes backend lifecycle callbacks. Publication loss
does not replay operations or choose a replacement backend.

The fast companion flag is sticky after publication. The supported caller
profile requires actual runtime guest execution, whose run seal cannot overtake
this new install lease. Directly calling guest RPC entry points concurrently
with pre-run installation is outside this profile; a flag read alone would not
serialize such synthetic callers.

`NativeSoundRamCallV1` borrows an already accepted `SoundCall`. The outer token
must outlive it and remain accepted, unmoved and unreleased; mutable and const
rvalue constructor overloads are deleted. No operation reacquires admission or consults a later
stop flag. Each callback runs under `SoundCallScope`. The capture scope retains
the Binding/owner and invokes `end` after every invoked `begin`, including a
refused begin, so finite provider storage can be returned. New outer calls are
refused after stop; already accepted calls retain mapping/provider lifetime
through final response/completion and then release before worker join.

## Provider contract

There is deliberately no default `memcpy` provider. Runtime/executable/RAM
identity equality is insufficient to supply one. The injected interface has:

| Operation | Required contract |
| --- | --- |
| `begin/end` | Bounded caller context and prebudgeted storage; no range or graphics lock retained over the entire RPC or a guest callback. |
| `read_batch` | EE/IOP tagged spans; reserve the real writer protocol for the complete group, validate all extents before reads, then bounded copy to owned host destinations. |
| `control_batch` | Typed write/zero roles; preflight every destination and source extent before any mutation; refuse a batch without partial writes. |
| `copy_forward` | Reserve source AND destination; validate before mutation; exact evolving-source bytewise forward semantics. |
| `snapshot_packet` | Return finite owner-storage loan with exact requested byte count, valid until `end`; no guest pointer can escape. |
| `log_owned_packet` | Observe only the admitted owned packet loan; no implicit guest reads or HD/BD/TQ dumping. |
| `report` | Typed failure stage/status; no recursive facade call, retained token, or exception. |

Callbacks are synchronous and noexcept. They must obey the actual runtime
capture protocol and lock order. Some read/control callbacks run under
`g_rpc_mutex`, matching original sound ownership; they must not acquire that
mutex again or wait for guest/source/protocol work in an inverted order. Arbitrary
provider reentry, blocking I/O, or latency is not made safe by this SDK wrapper.

The provider must distinguish 32MiB EE backing from actual 2MiB IOP backing,
qualify aliases and arithmetic extents, and refuse unsupported scratch/MMIO,
wrapping or foreign-incarnation ranges. Read/control/copy reservations end
after the bounded group copy, before bank decode/install or guest callback.
Complete asset HD/BD/TQ group capture is a separate versioned packet-adapter
prerequisite described in
[capture capability design](NATIVE_BANK_CAPTURE_CAPABILITY_DESIGN.md).

Packet snapshot storage is separate from the bank v2 aggregate asset budget
and the adapter's packet/control staging budget. The SDK maximum is nonzero and
at most1MiB; an installed owner must also honor its actual smaller parser/staging
limits. There is no new unbounded transport vector: original `rpcCopyToRdram`
already copies bytes directly.

## Actual RPC sequence

The selected native path classifies from existing host SID metadata before
unqualified guest reads. It acquires one runtime-qualified outer `SoundCall`,
then capture scope, before ABI stack words or client/server descriptors.
All traffic on owned SID0/1 is intercepted. An unknown RPC is terminal typed
unsupported before ABI/client/payload access, with no generic service fallback
or guessed completion; it is not reported as a processed legacy command.
Production admission must source-qualify use of supported owned commands.
The default125 `SifCallRpc` function body is text-identical except for one
companion-only entry guard; the verifier checks this.

Supported native input requires fully readable bounded ABI stack/client/server
extents. The original extended-register versus O32 plausibility choice is
preserved for builtin sound services, including register preference. The DTX
Create34 exception belongs to another service and is not migrated here.

The native profile refuses a nonzero EE-local server function before effects;
it does not skip such a function and claim success. It also refuses overlapping
client/server descriptors or payload transport destinations overlapping either
descriptor, before metadata writes. Those original sequential pointer reads can
be self-mutating; freezing a host descriptor would change them. Ordinary
payload source/destination overlap is supported exactly.

After qualified metadata updates, server transport uses the original forward
copy and1MiB clamp. In particular, source `ABCDEFGH`, destination offset2,
length6 becomes **`ABABABAB`**. A staging copy or `memmove` produces different
bytes. Transport can change the send buffer; the actual packet snapshot occurs
after transport and original runtime adoption/reset, before logging/output/
bank submission. The owned logger precedes `ensure_output`, matching125.

The parser's returned bool/status remains deliberately ignored for the source
command RPC acknowledgment. A native parser prefix is never replayed through
legacy. Query failure does not fabricate a query word; original nowait
completion behavior remains. Query/status reply writes and zero tails use
typed control batches. Completion semaphores are refreshed through admitted
reads after writes/guest callbacks that can alias client metadata.

An early begin/ABI/profile refusal returns V0=-1 and a typed diagnostic/status.
It performs no unqualified client RAM read/write, callback or guessed semaphore
signal. This is **not** claimed to complete or cancel the RPC. A production
profile must qualify the caller ABI/control arena or supply safe bounded
completion before it can be enabled. Later failures can use only already safe
completion metadata; a failed refresh makes that metadata unknown.

Direct builtin IOP service entry also creates an explicit capture scope around
its accepted token. The outer SIF path calls the captured implementation
directly, so it does not reacquire a newly closed admission gate.

## IOP status and caller control

Sound arena initialization uses real IOP-tagged zero/write batches for status,
address table and storage, preserving host adoption/addresses/order. Status
checksum backfill reads the primary/fallback EE arrays and existing IOP slots
through bounded batches. It retains primary selection, fallback selection and
the zero-only16-bit slot fill rule. Reading a complete small table instead of
the old byte short-circuit requires the full table extent to be admitted.

`sceSifGetOtherData` classifies sound IOP ownership using host state without
exporting an IOP pointer. An overlapping incomplete range is refused rather
than treated as EE. Sound transfers use the same accepted control token,
captured backfill, IOP→EE forward copy and typed EE receive-descriptor writes.
Their original full transfer size is preserved; the RPC1MiB clamp is not applied
to this path. Other generic SIF transfers remain a valid caller-context domain,
not a claim of generic SIF/IOP arena migration.

## Isolated evidence and remaining admission

`verify.py` runs actual126 source against finite fake RAM/provider/worker
surroundings. It retains an explicitly identified private adaptation of the
immutable0124 verifier to include the new header/functions. It preincludes
`<span>` outside the original PCM oracle's test-only `std` macro shim; no DSP,
actions or expected observations are changed.

The new cases cover partial API refusal, absent/foreign/busy/unavailable
capabilities, accepted-after-stop and paused read/join lifetime, strong owner
retention, alias negative control, exact clamp, post-transport/adoption packet
capture, owned-only logging/failure, malformed snapshot, read/control/transport
refusals, descriptor/profile rejection, register/O32 ABI, callback metadata
refresh, query replies, IOP transfer extent and original-source backfill parity.
Real extracted runtime lease/run methods test paused registration/publication
against run, already-run refusal and stop defeating publication.

Unchanged regressions include34 joint cases,18 V1 cases,9 boot cases,22 original
PCM cases/46 snapshots/16,656 float values and18 original bank cases/252 actions/
13,004 float words/12,768 gain calls. Actual RPC/SIF/CRI/bank/runtime objects are
compiled against the fresh126 headers and sealed unrelated V6 include cohort,
with every consumed include qualified. This does not link or exercise a real
device, guest process, graphics reservation or CD writer protocol.

Production admission still requires the actual CD configuration seal,
CPU/graphics ownership reservation and complete RAM-writer coverage, real
caller ABI/control provenance, coherent HD/BD/TQ batch capture, whole outer-call
mapping incarnation retention, finite aggregate storage, and matching rebuilt
SDK libraries. Until those contracts are supplied, injected capture may return
unsupported and the experimental bank backend must remain uninstalled.

## Superseded first frozen cohort

`tools/native_reconstruction/audio_ram_capture_dispatch/cohort_identity.json`
SHA256: `6b03e642deef568a0eba054c09cbeaa237a55cbf52061da8805fd6bd785ab4a3`.
This is an explicitly identified post-expectation implementation cohort; it
does not claim a blind freeze before the historical source expectations were
seen. All authored input hashes remained unchanged during final checks.

Public0125 SHA256:
`bd9d1cbcc2de72a478d649d399bc7cdef18ba9461ece15286520b55987e1d7ff`.
Fresh126 tree: `build-native-sjuni/dependency-ram-reapply-v4`.
Fresh reapply receipt SHA256:
`45ee38e3076d5898dfad6fd0a44a0a8f7c753b0f2742aef0f7fbe6d10cf85ece`.
Actual new `CriAudioRamCapture.h` SHA256:
`a9c5e85d222f6fa9dfecb96be5818795f6f7f3bb19973875caea5dc3184d1d73`.

Historical first-cohort receipts are below
`build-native-sjuni/audio-ram-capture-dispatch/`:

| Receipt | SHA256 | Result |
| --- | --- | --- |
| `gcc-qualified-final/receipt.json` | `898679d15399b92db8a2004dc91c7e1585c2e98c8788286847ef3fe84d83632c` |31 companion cases plus all prior suites/original observations PASS |
| `llvm-qualified-final/receipt.json` | `f542ac18a8d19872083f57280d36e14afec6eb313d61964dccc468f152b1b43d` | Same PASS |
| `gcc-objects-final/receipt.json` | `76fc0a85e7f9ee157891a1430f1d940bc23f1c42cca78c25ee8f1be20fc22580` | Five actual-header objects PASS |
| `llvm-objects-final/receipt.json` | `90d061ec0a5b46ed15a17ae000fc1247c688e9bf5daf9f81b02dafdc21998e69` | Five actual-header objects PASS |

Earlier draft author trees, reapply trees, failed test receipts and preserved
patches remain in the ignored build outputs. They are superseded, not rewritten
as successful final evidence. The initial stop-before-publication test expected
a backend stop callback; the corrected assertion follows the existing inert
unpublished-worker contract. The LLVM oracle wrapper required `<span>` to be
included before its test-only `std` macro shim; production headers compiled
without that shim in the actual object cohorts.

## Final reviewed cohort v2

Independent root review and self-review found two source-order gaps in the
first cohort. A rejected forward copy is guaranteed to have no effects, so
already captured completion metadata must remain valid on that refusal. A
successful copy invalidates it until the admitted refresh. Also, the compat
busy word can alias `client.hdr.sema_id`; the original unresolved-callback
fallback rereads that field after clearing busy. The new helper now does so.
The supported borrow contract is explicit and rvalue tokens are compile-time
rejected. Neither change alters a published V1/V2 layout.

The final verifier proves the actual `ps2_iop::init` body remains solely
`m_rdram = rdram;`, with no RAM dereference/reset. The final host client registry
mutation uses the original `operator[]` busy=false behavior, including
reinsertion if a guest callback cleared the map. The tests compare safe
transport-refusal completion to semaphore7 and busy-alias completion to
semaphore7 followed by captured endParam23. Private negative controls restore
the superseded source order and fail both assertions on both compilers.

Frozen authored identity SHA256:
`980d08960c22c4cef1504bd380ed1ee257583b7c5bda6fb60254a70e033ec5c8`.
The old raw authored files, documentation, patch and identity are preserved at
`build-native-sjuni/audio-ram-capture-dispatch/preserved-cohort-v4`;
earlier reapply trees/receipts remain unchanged.

Final public0125 SHA256:
`d7c6fad418f00d3d4c3f2e2bfa336307590f96b8933251b1e35595fc0978ff42`.
Fresh full126 source: `build-native-sjuni/dependency-ram-reapply-v5`.
Reapply receipt SHA256:
`2de11297c268e453888341b7f3ed44012ae51bdd10c9baa39a168e5cade97ec0`.
Actual `CriAudioRamCapture.h` SHA256:
`2505ea1838df71edd5bf6c87f88934cf303d2c533e8bd3e24dee3a2c7fea3147`.

Final receipts below `build-native-sjuni/audio-ram-capture-dispatch/`:

| Receipt | SHA256 | Result |
| --- | --- | --- |
| `gcc-qualified-v2-final/receipt.json` | `80126f5d7e4fbfa353ac6197ba71855c3aa9ec08c72726749e2fdc1d21301483` |32 cases, two expected negative-control failures, all prior suites/original observations PASS |
| `llvm-qualified-v2-final/receipt.json` | `3fc3621a3b6d036ce125ce08a4963f06aec7731f281a123d8dc786e9d41fa270` | Same PASS |
| `gcc-objects-v2-final/receipt.json` | `9da47c09a3de275073c2c86c65d87151ae03f77c1b94eb4457ab1a55975b6657` | Five actual-header objects PASS |
| `llvm-objects-v2-final/receipt.json` | `93254621c33e3b7345eda9266afbd15985bd529490c6181833902b2e2d05f994` | Five actual-header objects PASS |

All authored inputs and complete reapply source hashes remained unchanged
during these checks. This superseding cohort retains the same injected-only
production admission limits; no capture factory was added.
