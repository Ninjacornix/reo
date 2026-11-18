# Native bank packet adapter: independent cohort2 review

Status: source-only review, 2026-11-06. No confirmed adapter defect found under
the stated single-call, pure-provider and outer-owner contracts. No adapter/core
source was edited and no compiler, executable, game or device was run for this
review. Existing receipts were read and their identities independently checked.
The actual RuntimeCaptureFactory remains unqualified; this review does not make
the adapter eligible for runtime selection.

## Reviewed identity and evidence

Adapter [identity.json](../../recomp/overrides/native_banks/identity.json) SHA-256:
`2d7efe5f594096d8e1083214341451bde5aa4396d1b7b37750c0a594e9f66616`.
Every listed candidate file matches that identity. Important implementation hashes:

| Source | SHA-256 |
| --- | --- |
| [packet_adapter.cpp](../../recomp/overrides/native_banks/packet_adapter.cpp) | `000d5e10d3efb9641e2feb61a0b691d507a30194da029bb1c06ada7e6b6d6c93` |
| [packet_adapter.h](../../recomp/overrides/native_banks/packet_adapter.h) | `f7fe610037b9c58ff52a53f64053e75036f977645bb9288e7afd7a54b1c4e9d7` |
| [backend_status.h](../../recomp/overrides/native_banks/backend_status.h) | `3ebf14a94829b4d5e42e07cddbe0ddd5a6e627069926c4970fa71b812500287e` |

The prerequisite is the allocator-accounted bank v2 LF cohort
`77b6c1bc20f6c1ea261ea19df9bcde3a5fa516c94e7b2c7d8d6503ca0f7aefca`.
This is explicitly a post-original-expectations implementation, not a new blind
DSP reconstruction. Qualified original124 packet code is ReoSoundBanks.cpp
`e164ba72cc002311d4811d803be2e2df9a6228d5abcaa0c4fa419a31ee09b818`.

All four existing final receipts under
`build-native-sjuni/native-bank-packet-adapter` are passed with empty source
postchecks; their hashes match the implementation report:

| Receipt | SHA-256 |
| --- | --- |
| `gcc-unit-v2/receipt.json` | `3bce1cdf65495f0e8cd6ae8d30e914dbb2019a263a686f2adaba50775a0a7cd5` |
| `llvm-unit-v2/receipt.json` | `fd652005b2ec2dfb667753e1d16b3ca7da7e841229c979835fe3023e9ae77558` |
| `gcc-original-v2/receipt.json` | `ef424d0edc970ade9bb9e7724e1946cdc3db0347e01c17f0bcbd3da86f92114b` |
| `llvm-original-v2/receipt.json` | `a50f60a26b7b6f52f155e79d73a5e1970724aad26dcc27d40435121c05a9e69a` |

Both toolchains record 109 assertions and a missing-relock negative variant that
fails assertion104. Both source comparisons retain all 18 cases/252 actions,
13,004 float words, 12,768 ordered gains and observed request/voice/clip/clock
state with zero differences. The status objects use final125 header
`631db6363db9a8945711f5c305ed8bfb0628ca50b3625cc2492e2afb3987f126`
and reapplication receipt
`3019662f2fd62dbe4a9b3c7b99528bd631338424597ad78d2a4a04bcebeb3d6a`.
These are finite synthetic execution and header-contract evidence, not real RAM,
device, aggregate installation or performance evidence.

## Prefix and load ordering

`submit_packet` (cpp line127) captures the packet into an exclusive pool slot
before acquiring the transaction mutex. Before the first prefix effect there is
no partially applied packet state. Once parsing begins, that mutex spans all
ordinary command effects. Adapter queries, reset and positive mix use the same
mutex (lines187–201); a renderer cannot observe the gap between two such prefix
commands. Runtime callers must use these adapter entry points rather than bypass
them through their separately held Session pointer.

For an actual load, descriptor validation and loaded-state admission occur while
the transaction is held. `PacketLoadUnlock` (lines30–33) releases it before raw
capture/decode and is declared before all staged resources in `prepare_install`
(line95). Every return before explicit relock destroys those staged resources,
then the guard reacquires the caller's transaction before the parser returns.
Successful staging explicitly relocks before closed-state check and install;
the guard then observes that it is already owned. No failure exit leaves the
packet parser's lock in a different state.

The cleanup distinction matters: **after** that explicit relock, a stop/stale/
install refusal may destroy PreparedBank while the packet transaction is held.
Ordinary install/apply/reset can also free control-side assets under that outer
transaction. This is permitted by the explicit nonreentrant AllocationSource
contract. There is no claim that every failure free runs unlocked. For direct
submit_bank the local transaction guard is destroyed before the prepared asset;
there is no enclosing packet transaction to restore.

The existing failed-load test establishes preparation and render gates, completes
staging cleanup, then observes 100 ms of nonreturn while render owns the
transaction. Both private variants that remove only destructor relock fail that
same whole-adapter test. The bounded wait is synchronization-test observation;
source lock reasoning, not a scheduler or latency assumption, establishes the
intended invariant.

## Parsing, extents and accepted effects

The opcode lengths, sentinel defaults, optional parameter order, cancel/change
masks, big-endian pitch/port fields, inverted mono, stop/unload combinations,
accepted no-ops and unsupported report counts match the selected original
parser. `0xFF` stops parsing and leaves trailing bytes unused. Unknown/truncated
commands retain their earlier prefix and report once. Invalid port `0x4C` is an
accepted no-op; invalid `0x47`–`0x4A` follows original global reporting.

Load descriptors retain the 25-bit address mask and 16-byte length units
(lines168–170). Bounds use subtraction after checking offset, avoiding an
unchecked offset-plus-length addition. View extent cannot exceed declared full
RAM extent on a load. The inner Session applies its separate per-part and asset
allocation bounds before capture. These checks do not validate a provider's
actual backing pointer or concurrent writers.

For loaded `0x4E`, full 21-byte command length and valid port are checked first,
then unused descriptors, RAM extent validation, payload copying and asset
admission are skipped. Only packet capture and metadata getters have already
occurred. If initially unloaded, eventual install uses force after relock so a
competing load during decode does not change the admitted source decision.
Reset epoch checks deliberately refuse stale resurrection instead.

`PacketResult` separates typed refusal from the original parser bool. Its
commands_applied includes accepted no-ops and loaded skips; it is parser progress,
not proof that a voice played or an asset was installed. The V2 status bridge
keeps failed query values neutral while preserving a distinct status. Full RPC
acknowledgement/cancellation remains the shared facade's obligation; neither a
typed error nor a partially accepted prefix authorizes legacy retry.

## Call, stop and memory lifetime

`begin_call` (line71) reserves a bounded pool slot/count under the gate, obtains a
core Submission outside it and handles stop/failure by releasing both. A racing
join sees the slot count even during that intermediate admission. Each Call
strongly retains State, its fixed packet buffer and the core producer token.
`Call::release` (line58) drops Submission before entering the pool gate; it marks
the slot free/decrements the count there, then releases its last State reference
outside the gate. Move operations transfer these obligations once.

State is allocate_shared through the retained control Budget allocator, and its
slot/container/packet allocations use that same requested-byte domain. Partial
construction refunds actual allocations; control-block allocator ownership keeps
the Budget/source alive through final deallocation. Join intentionally does not
refund pool memory that still exists. The default pool has 16 calls ×64 KiB
packet buffers; those buffers and its State/container/control-block allocations
must fit the 2 MiB control-byte limit. The Session asset budget is separate. None
of those numbers is a process RSS limit or a proved whole-game packet profile.

Reset serializes through transaction and advances the core epoch. Staged
capture/preparation and command/install validation retain their original
Submission, preventing old work from installing after reset. Queries/reset are
current-state control operations; reset does not close the adapter or provider.

Stop is atomic admission/cancellation signaling. A short commit that passed its
check can finish afterward; join waits whole producer Calls. It does not count
mix_add or prove output/provider retirement. The aggregate must first close and
drain its **outer** SoundCalls, including callbacks paused before bank-table
entry and renders paused between PCM and banks. Only then may it stop/join this
adapter and fence/close its inner state as the complete owner contract requires.

## Contracts and unresolved factory gate

- A Call is an exclusive operation token, not a mutex for concurrent reuse of its
  packet slot. Do not share, move or destroy it while an operation uses it. Keep
  PacketAdapter alive for member calls; a retained Call after adapter destruction
  proves retained memory ownership, not permission to call a destroyed object.
- Release caller-owned Calls before join. CaptureSource and allocation/gain hooks
  cannot join/reenter adapter/session operations. Gain runs under transaction
  plus bank data; control allocation/free can run under transaction. Providers
  must remain memory-only/pure and obey the documented lock order.
- A successful CaptureSource copy must fully fill its requested owned span and
  validate real backing/extents/lifetime. Before/after identity comparisons are
  binding checks, not atomic commit validation. The factory must retain a stable
  Runtime/RAM incarnation through the entire outer call or a commit-qualified
  lease, in addition to synchronized coherent reads.
- The [runtime capture review](NATIVE_BANK_RUNTIME_CAPTURE_REVIEW.md) identifies
  asynchronous CD writers outside guest execution ownership. Positive guest
  depth, pointer equality, copied identity fields or actual125 header compilation
  do not resolve that counterexample. The capture factory remains blocked on real
  writer/read-lease and canonical-source qualification.
- The 64 KiB packet cap is narrower than original remaining-RAM admission.
  Installation must qualify that domain and asset/control peaks before selecting
  this candidate. Source fixture parity does not prove arbitrary asset graphs,
  wire completion, real device output or whole-game performance.

No adapter source change is requested by this review. Retain the source-order
correction and its regression evidence while completing the aggregate and actual
capture boundary described in [the implementation](NATIVE_BANK_PACKET_ADAPTER.md)
and [the shared facade](AUDIO_BANK_BACKEND_DISPATCH.md).
