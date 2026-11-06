# Complete PCM/bank owner dispatch (dependency0124)

Status: dependency implementation and isolated qualification, 2026-11-06.
No game, device or full runtime/game build is performed here. The patch installs
no backend by default and changes no game clock, rendering or VU configuration.
The production aggregate owner, qualified capture factory and bootstrap activation
remain separate integration work.

## Reproducible source

Public patch:
[0124-complete-audio-bank-owner-dispatch.patch](../../third_party/patches/ps2recomp/0124-complete-audio-bank-owner-dispatch.patch),
SHA-256 `1c08f9667edee15dbeeb0e332b12473d0ae77433519dde22c32e1c329f7fa377`.
It extends actual full124 at pinned revision
`c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f`. The active submodule, full124 baseline,
sealed SDKs, root bootstrap and CMake are untouched.

[prepare_patch.py](../../tools/native_reconstruction/audio_bank_dispatch/prepare_patch.py)
verifies the immutable124 receipt, creates a fresh small touched-source copy and
exports the focused normalized diff. Entire public series125 reapplication passed
in `build-native-sjuni/dependency-bank-reapply-v3`; its receipt SHA-256 is
`3019662f2fd62dbe4a9b3c7b99528bd631338424597ad78d2a4a04bcebeb3d6a`.
Reauthoring independently as `dependency-bank-author-v7` produced the identical
patch hash. Intermediate source/check receipts remain retained and are superseded
by this qualification.

| Actual125 source | SHA-256 |
| --- | --- |
| `Helpers/CriAudioBackend.h` | `631db6363db9a8945711f5c305ed8bfb0628ca50b3625cc2492e2afb3987f126` |
| `Helpers/CriAudio.cpp` | `be320a54a8064723c4af23a5c7c1e0e5340ae555796abcbf569ae5606b0e40ec` |
| `Helpers/CriAudioDispatch.h` | `d0c04ecf67babed202b66bff800b6941d661f1718eb21b8db1f98146875230de` |
| `Helpers/ReoSoundBanks.cpp` | `d691d6f6ab60b26f8fe8ebc0a87bfedc168a37ee4c7a6ea8ca3e641bb31fef6f` |
| `RPC.cpp` | `51f17d2c361c7208264fe774095b0911f44b58a05555c52dbbe677ea3f07c88f` |
| `Kernel/Stubs/SIF.cpp` | `d52d89ea4922a48662a2df0121fa3692452459f329f5ada2394b9d8a9cb67cbb` |
| `ps2_runtime.cpp` | `c800ae703c4ffb973991654593314d53330aabf4062722a5f9ef4ee4f1bf278d` |

Helper paths are below `ps2xRuntime/src/lib/Kernel/Syscalls`; runtime/SIF paths are
relative to `ps2xRuntime/src/lib` as indicated. All source identities, prior patch
identities and consumed project includes are retained by the verification receipt.

## One publication and one outer admission

`BackendApiV1` and `BackendRegistrationV1` retain their layout and PCM-only
behavior. V1 bank operations deliberately retain legacy compatibility, including
its existing ownership limits. This is explicitly not the complete V2 contract.

V2 supplies `BackendApiV2 { pcm, banks, render_admitted }` and one shared owner.
The complete PCM table, all eight bank callbacks, ABI/structure/capability fields
and the admitted-render callback must validate before worker registration. One
existing registry decision publishes the complete owner; no bank-only registration,
per-operation legacy retry or second output owner is introduced. First ordinary
PCM or bank use selects legacy if no backend was published. Publication loss and
registration-time stop keep an inert worker and expose no candidate callbacks.

`SoundCall` strongly retains the selected Binding and its whole-call count.
Its explicit methods return `BankStatusV2` or `BankQueryV2`; compatibility wrappers
retain old public signatures, while internal RPC callers inspect typed results.
Table callbacks are nonthrowing. Wrapper methods permit the original allocating
legacy paths to propagate exceptions instead of turning them into termination.
Pure Bank/Sequence utilities do not select playback.

V2 render transfers its existing facade lease into the SoundCall passed to
`render_admitted`. Its bank stage calls **that same token's** `mix`, even after stop
closed new admission. It does not reacquire a fresh public bank operation.
Likewise a producer admitted before stop may enter its bank table callback after
stop; it remains admitted. A future owner must keep PacketAdapter producer and
inner BankSession admission open until all these outer calls drain.

Stop closes outer admission and signals the owner once. Shutdown waits existing
calls, then invokes the owner shutdown; join is serialized and retryable. Own
operation/lifecycle self-join is refused through explicit SoundCallScope/dispatch
scopes. No registry lock is held across owner methods or destruction. The owner
must separately prove actual provider detach/fence, keep failed-fence resources
alive, then close/join inner state on control side. The dependency cannot turn an
incorrect implementation of those callbacks into a real device lifetime proof.

## Caller closure and control provenance

| Actual path | Guard and retained lifetime |
| --- | --- |
| Public bank submit/packet/query/reset/mix/report | Selected SoundCall before source effects; source legacy methods are private named implementations. |
| Recognized sound RPC | Primitive SID/RPC classification first; exact runtime admission before adoption, status mutation, payload read/log/capture/provider ensure, table operation and response publication. |
| Outer SifCallRpc | Admission before transport payload copy; retained through generic result copying, completion semaphore/end callback and final client completion. Direct IOP entry obtains its own equivalent scope. |
| Sound-driver runtime reset | Actual `run()` passes `this` to the qualified overload. Foreign runtime refuses before bank/cookie/arena reset. The retained no-arg symbol refuses unknown V2 provenance. |
| SifInitRpc first/re-init | V2 runtime and actual RDRAM association checked before IOP init, PCM reset, DTX metadata clear or sound `initialized` mutation. First init uses the existing admitted token for PCM reset; no newly closed inner facade gate. |
| Set/clear DTX layout | Entire eligible unselected setup operation uses runtime PreRunSetupLease plus shared boot reservation before layout assignment/reset/metadata writes. Published V2 requires exact runtime; unknown/foreign control is inert. |
| Sound compatibility layout setters | Nonselecting metadata reservation prevents publication during an unselected write. V2 unqualified setters refuse; current callers are pre-publication override setup. |
| GetOtherData status backfill/copy | One qualified control token spans backfill, IOP pointer borrow, source copy, guest descriptor writes and completion. Preparation reuses it; retained old unqualified preparation symbol refuses V2. |

Every V2 RPC/transfer path above also checks supplied RDRAM against
`runtime.memory().getRDRAM()` before payload/status access. This proves address
association, not a coherent snapshot against arbitrary guest/DMA writers. Runtime
identity must remain live through the token and real runtime teardown must retain
RAM until its registered workers and guest threads finish.

The nonselecting metadata reservation uses a count, not a held registry lock.
Install/setup returns busy while it exists. Ordinary first use may still select
legacy; it never waits for that count. This avoids a registry/RPC lock cycle.
That unselected metadata token cannot invoke PCM/bank methods. Actual reset
operations use ordinary first-use admission or the explicit pre-run setup
capability instead. Pre-run callbacks receive a borrowed const capability and
must not retain it or reenter public dispatch.

## Wire outcomes and source semantics

- Unrecognized sound SID/RPC remains not-covered before audio selection or reads.
- Closed/foreign V2 recognized RPC is owned terminal cancellation, never service
  fallback. Direct helper returns handled, `resultPtr=0` and nowait-completion
  true, without payload/query response writes. Outer SIF entry clears transport
  busy, signals completion and returns `-1` before payload copy or guest end
  callback. No successful zero query is invented.
- Admitted malformed/unsupported/budget-refused command retains the original
  command RPC's handled behavior: the original wrapper ignores parser false.
  Typed refusal/diagnostics and already committed prefix effects remain owned;
  no retry against legacy banks occurs. The packet adapter preserves conditional
  `0x4E` loaded-bank skip before any unused asset capture/allocation.
- Admitted query failure cancels without writing a success word. Successful
  pending-load value zero remains distinct from closed/unsupported.
- Original legacy parser, DSP, gain order, clock, conditional load, prefix and
  mix/reset/query bodies are unchanged apart from their private namespace.
  Ordinary PCM reset retains banks; bank-only reset does not reset PCM/output.

The packet adapter, budgeted core, owner lifecycle and qualified capture factory
must preserve these contracts together. Identity equality alone is not a runtime
or capture qualification, and a typed refusal cannot silently reopen legacy.

## Verification and remaining limits

[verify.py](../../tools/native_reconstruction/audio_bank_dispatch/verify.py) uses
the freshly reapplied source, complete source PCM/bank facades, exact extracted
runtime phase/setup and sound/SIF helper bodies, and declared fake worker/RAM/
provider surroundings. It also compiles production RPC, CRI, banks, SIF and runtime
objects against one coherent actual125 header/source cohort. Depfiles reject
older runtime headers from sealed geometry inputs. Synthetic status-backfill
surroundings test its admission boundary, not the unchanged checksum algorithm.

Both GCC15.2 and bundled Clang21.1.8 passed all 73 recorded checks each:

- 34 joint selection/admission/control/wire scenarios, including accepted render
  and pre-table producer continuation after stop, foreign init followed by owned
  query/command, unknown/foreign reset/layout controls, wrong RAM, metadata
  publication arbitration and paused status-copy completion versus join.
- All 18 previous V1 dispatch and 9 previous runtime/setup scenarios, compiled
  against the same new source.
- Frozen original PCM: 22 cases, 46 state snapshots, 16,656 float observations.
  Frozen original banks: 18 cases, 252 actions, 13,004 float words, 12,768 ordered
  gain calls. Both comparisons retain identical observations.
- Five complete production objects against actual125 headers: RPC, CRI, banks,
  SIF and runtime. Each compiler's depfile proof qualifies 93 project inputs;
  existing SSSE3/SSE4.1 runtime target flags are explicit. No library or executable
  game is linked by that object check.

Final receipts under `build-native-sjuni/audio-bank-dispatch`:

| Receipt | SHA-256 |
| --- | --- |
| `gcc-qualified-final/receipt.json` | `c3cb28727ac44eed9141bc0981b2baaa2d50031dbe39a28b5eadc6fa0d22c398` |
| `llvm-qualified-final/receipt.json` | `cc237daa5a93e268834c572270ced3ee6862286fb9d77118bf7145b979eca043` |

Authored tool/source identity checks remain unchanged after both runs. Test output
directories use NTFS compression to preserve every byte/receipt while reducing
storage; logical hashes and test coverage are unaffected.

The isolated tests do not link a complete runtime library or prove actual audio
device behavior, aggregate activation, real guest capture coherence, every generic
SIF/DMA/DTX protocol, native ownership of guest queues or a performance improvement.
The existing [packet adapter](NATIVE_BANK_PACKET_ADAPTER.md),
[bank budget review](BANK_BUDGET_V2_REVIEW.md) and
[integration contract](BANK_BACKEND_INTEGRATION_REVIEW.md) identify those remaining
factory/ownership gates. A matching rebuilt runtime and coherent candidate are
required before actual game validation; an old sealed library cannot satisfy V2.
