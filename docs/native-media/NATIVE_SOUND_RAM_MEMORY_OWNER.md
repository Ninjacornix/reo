# RuntimeMemory: actual source acquisition and bounded capture owner

Status: implemented provider and isolated checks; not yet a validated game
configuration. This document does not claim a game/device test or complete SIF
migration. The production entry remains private to the complete composite owner.

The final source cohort uses LF bytes: `runtime_memory.h` SHA256
`6b6dea2942cf7c417da6ab5e55fec1067b771693bd8a20e22fa4521415290502`;
`runtime_memory.cpp`
`cb30c0446ad665140c27c87904033f6cf80453b265311314119f7cda72628d67`;
fixture `runtime_memory_tests.cpp`
`68605f8e3c93fc99aeef649c7c930750f694c62aae6a02d401baf84a37a4ebee`;
verifier `383ee308297852af7ce120e4b8b48df9d6ff040ab570fbe9f4a452affe047798`.

`recomp/overrides/native_sound_ram/runtime_memory.{h,cpp}` implements
`audio_aggregate::v2::QualifiedCaptureProvider` and the explicit SDK sound-RAM
companion delegates. It adds no bootstrap call, dependency patch, rendering-mode
toggle, or device ownership. The root composite owns publication and shutdown.

## Inputs that grant authority

The private `RuntimeMemory::prepare` is accessible only to the actual
`CompositeBackend`. Its caller must hold a real outer `PreRunSetupLease` across
preparation, child construction, SDK registration/publication, and explicit
failure cleanup. The inner preparation lease alone does not register a runtime
worker or preserve Runtime lifetime after returning.

Preparation performs these operations in order:

1. Reject a current guest-execution or IO-register-lock context; acquire the
   actual Runtime pre-run lease.
2. Obtain the actual Runtime EE and IOP backing pointers. Require the SDK's
   32MiB EE geometry and the strict, disjoint 32MiB/2MiB `AddressDomain`.
3. Seal the actual observed synchronous CD configuration using
   `ConfigurationReceipt::try_seal`. An environment string is insufficient.
4. Acquire the actual SDK127 `SoundRamSelectionLeaseV1` through its pre-run/GS
   gateway. This pins actual backend/factory selection and the observed disabled
   advanced-parent configuration. It supplies no general RAM read authority.
5. Require the actual live `ReoHwBridge` writer witness, the actual linked
   parallel-backend Service witness, and the app's process Coordinator2 to be
   the same object. Require no actual source owner and no first-entry enrollment.
6. Allocate the fixed owner state; under a real `GuestExecutionScope` and one
   actual fair CPU copy group, copy File1 code guards into stack arrays. Release
   the group and guest scope before hashing the owned arrays.

The guards are `[0x1392f8,+0x40)` SHA256
`48af9491776a966a35a3dd46ed6122d2aa237c85f2a1967c38f204a488517be8`
and `[0x135078,+0xf8)` SHA256
`a6ac3b23bfac0c9862d0facae8e02be99f08a69e6e20cb2dda05a10ffd3813bd`.
No unqualified pre-read is used to choose this profile.

The supplied `MemoryIdentity` is report metadata. Preparation replaces its
`runtime_incarnation` with the actual GS selection incarnation,
`ram_incarnation` with the nonwrapping process-issued Memory nonce, and
`ram_bytes` with actual 32MiB geometry. A matching caller hash, number or boolean
never grants copy permission. Actual backing and configuration checks remain
independent of these tags.

This uses the conditional writer coverage in
[NATIVE_SOUND_RAM_WRITER_CATALOGUE.md](NATIVE_SOUND_RAM_WRITER_CATALOGUE.md) and
[PAD_RAM_CAPTURE_COORDINATION.md](PAD_RAM_CAPTURE_COORDINATION.md). In
particular, an inactive advanced parent alone is insufficient: the real CD seal,
actual guest ownership, instrumented Pad writer, sticky Service exclusion, and
conservative VU aperture exclusions all remain necessary.

## Every operation takes a short copy group

`begin` retains bounded context/storage only. It does not hold a CPU group,
graphics lock, source reservation, or guest lock across an RPC, decoder, output
provider, or callback. It verifies actual Runtime and EE backing, actual current
guest depth, retained CD/GS leases and zero-owner/enrollment conditions.

Each payload operation first validates **all** descriptors, enums, checked
extents, host-buffer provenance and nonalias rules. A fixed local plan captures
the descriptors before effects, so writes to descriptor-adjacent buffers cannot
change a later interpretation. Only then does it call actual Coordinator2
`wait_cpu_group(EE backing)`. Qualification is rechecked after the wait, before
any copy. The group covers only synchronous byte copies and is destroyed before
returning to the caller or invoking a typed operation.

Waiting while guest/RPC ownership is held relies on the specific retained
config-off/no-Service/zero-source-owner/no-enrollment profile: the actual Pad
body has at most 64 socket records and its source wrappers take the reviewed
atomic/direct-copy paths without acquiring guest/RPC/source/protocol ownership.
The generic coordinator does not prove that dependency property for arbitrary
writers. Tickets are fair; metadata, graphics withdrawal and self-wait refusals
are explicit. OS scheduling prevents a hard wall-time latency guarantee.

`AddressDomain` admits only exact EE windows `0`, `0x20000000`, `0x80000000`,
`0xa0000000` with checked 32MiB extents, and separately tagged 2MiB IOP offsets.
It excludes physical EE ranges `[0x01000000,0x01001000)`,
`[0x01004000,0x01005000)` and `[0x01008000,0x01010000)` for both source and
destination. These are conservative capture-profile exclusions; this is not a
claim that the SDK async VIF worker writes those EE aliases.

Host spans must not overlap either complete guest backing, owner state/pool,
the RuntimeMemory facade, live token, or borrowed SoundCall. Token and Call
storage are validated before inspecting their values; descriptor tables are
validated before iteration. Read output spans must be disjoint. These checks
establish arithmetic and provenance, **not arbitrary host-pointer readability**.
The actual SDK/adapter must keep its host objects valid for the synchronous call.

No provider-wide 1MiB/2MiB copy clamp was invented. Descriptor counts are limited
to 16; grouped asset parts to 3. EE/IOP geometry and checked extents bound each
copy. RPC's existing 1MiB transport clamp remains at its source call site; IOP
transfers retain their full valid geometry. The existing child bank Session's
explicit 2MiB **per-part** limit and its aggregate 64MiB asset budget remain
unchanged and act before `copy_parts_v1` allocates/fills destinations.

## Tokens, snapshots and staging

The owner preallocates 16 slots of 65,536 bytes (1,048,576 payload bytes), plus
fixed metadata. This storage budget is separate from the bank asset/control
allocator budgets. Packet, direct-bank and PCM operations share the finite slot
pool. Runtime operations do not grow a vector or allocate staging storage.

A native token binds the private State pointer, process nonce, nonwrapping slot
generation, issuing thread, exact borrowed SoundCall, **and exact token object
address**. Copying the opaque words into another host token does not transfer
admission or return the original slot's credit. A live token cannot be reused
for another begin. Its SDK Call must remain accepted, unmoved and unreleased
until end. These are SDK-owner obligations, not independent authentication of a
fabricated SoundCall. All provider delegates must belong to that same complete
SDK registration.

One immutable packet snapshot loan can be issued per NativeScope. It is at most
65,536 bytes, copied under a group into the reserved slot and retained until
end. A second snapshot is refused without changing the existing loan or output
metadata. Stale, sliced, foreign, guest-backed, cross-thread or subsequently
released loans cannot enter `with_packet`. End refuses a slot currently borrowed
by a typed packet operation; no group is held for the whole operation.

`with_packet` accepts only the exact live loan and actual EE view. Its Source3
copies the owned packet to the adapter's already-budgeted storage and performs
all HD/BD/TQ copies under **one** group. It does not inspect asset descriptors in
advance, preserving the original loaded-`0x4E` skip before unused descriptor
validation/capture/allocation. Decode/install begins after that group ends.

`with_bank` accepts only actual EE-backed pointer extents. Arbitrary immutable
host assets or IOP borrows need a separately qualified future lease and are
currently unsupported. The complete synchronous operation retains a slot; its
Source maps checked part offsets into the real EE backing and uses the same
grouped-copy protocol. No raw guest pointer is retained by the bank core.

`with_pcm` admits the actual public facade's nonempty even queue domain up to
`0x4000` bytes and an EE-backed source. It copies to owner staging under a group,
releases the group, then invokes `PcmOperation::run` exactly once with owned
bytes. It returns the operation's exact boolean, including a valid downstream
false. Output ensure, callback acquisition and PCM core operations occur after
the copy group ends. Host or IOP PCM borrows are not silently treated as EE.

`copy_forward` reserves both complete regions and uses increasing-byte evolving
source semantics. For `ABCDEFGH`, copying six bytes two bytes forward produces
`ABABABAB`. Staging or `memmove` would change the original behavior. Control
write/zero batches preserve their specified sequence, including overlapping
guest destinations, after full preflight. A refused batch has no payload effects.

## Stop, retirement and diagnostics

The real SDK Binding retains the actual runtime/backing/bridge lifetime through
every accepted call and drain. Existing accepted work is not rejected merely
because Runtime.stop was signaled: retained seal matches do not reacquire a
configuration or test the stop flag. No new dispatch admission is invented here.

After actual outer drain and the child's provider/callback fence/join, the root
composite calls `retire_after_outer_drain`. It refuses active scopes, typed
staging/loans, copy operations, guest ownership, IO ownership, or another active
retirement. It releases GS/CD leases outside the metadata mutex and marks
retirement complete afterwards. A completed repeated retirement returns before
dereferencing the Runtime. The method does **not** itself prove outer drain,
stop devices, join guest threads, or make arbitrary racing direct calls safe.

Failed unpublished SDK installation also requires explicit child join and
Memory retirement while the real outer pre-run lease remains held. The SDK may
retain an inert unpublished worker without calling backend shutdown/join; a
destructor-only failure path would retain or release configuration incorrectly.
Do not destroy a nonretired owner on an arbitrary callback/guest thread.

Diagnostics use fixed saturating atomic attempt/refusal/report counters and a
first-failure word. Payload logging is deliberately absent: a validated owned
loan returns typed `unsupported`. The SDK reports that diagnostic separately
and continues handling the captured packet. No guest-byte logging, filesystem
write, or claim of a saved export occurs. Refused native work never falls back
to legacy or replays an applied prefix.

## Qualification evidence and limits

The verifier admits only final full127-v4 reapply receipt SHA256
`909917fc2f766c8a43a10abbc0b94189fa24254ecfaa7f710e4eb24dc941b58a`
and GS header `d99bf2fa5724b6c152725eaa2ca9d95e87527cdf812add82f92e18a9a724be9b`.
It verifies all reapply source/patch identities and uses a project-qualified copy
of that SDK before root includes. Graphics headers come from sealed V8 manifest
`435ae2791088c3061ffd2caa3617924daa9d1b8815eb441512f4c9f50e5b4ea0`,
matching compile plan and the owned generated catalogue receipt. Active SDK
headers, old sealed SDK headers and unidentified private build inputs are refused.

Protocol fixtures compile exact production token/copy/source/retirement methods
with **substituted fake** Runtime/CD/GS/SoundCall contexts. The private fixture
friend explicitly bypasses production preparation. Tests exercise pool/generation
exhaustion, token address/thread/Call/nonce checks, stale loans, complete batch
preflight, host/internal aliases, full-size forward spans, snapshot immutability,
owned PCM forwarding, real cooperating-writer waits, and retirement refusal.
They also run the real frozen PacketAdapter3 and BankSession2 through the owned
snapshot Source, including loaded-`0x4E` unused-descriptor skip and malformed
packet prefix effects. Private `memmove` and missing-token-address variants must
fail those same checks. No expected DSP values were newly inferred from this
provider; original source parity remains the separately frozen bank/adapter work.

The complete unmodified production TU is separately compiled against actual127
headers with consumed project-input hashes and pre/post drift checks. This
proves actual signatures/coherent source compilation, not successful live CD/GS
capability acquisition. A matching rebuilt dependency/runtime/game and controlled
actual qualified-game test remain required. No release/default backend change is
claimed by these isolated checks.

Final isolated results, each 130 assertions, both private negatives detected,
and a complete actual production object with 42 qualified project inputs:

| Compiler | Receipt under `build-native-sjuni/runtime-memory` | SHA256 |
| --- | --- | --- |
| GCC15.2 | `gcc-v6/receipt.json` | `10b8dd85995a1cb592a10de4cd51baf34888c4cb1d1cacb550eec169a05ad53f` |
| Clang21.1.8 | `llvm-v6/receipt.json` | `6b359ea3e08d09d98cdb94fa2790b09fd276d1501266f4f91450a82d14c330c0` |

Authored, frozen fixture prerequisite, SDK and consumed-include postchecks are
empty in both receipts. Earlier `v1`–`v5` private outputs remain as development
history; the receipts above identify the completed cohort. Neither receipt says
that real production preparation or a live game/device was exercised.
