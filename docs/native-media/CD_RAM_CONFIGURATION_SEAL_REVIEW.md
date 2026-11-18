# Independent native CD configuration seal review

Status: source-only review, 2026-11-06. No confirmed defect found in the reviewed
receipt/seal contract. This review does not qualify actual bank RAM capture or
run a compiler, game, disc device or audio device.

The review covers the lifecycle-sentinel correction in `b8045f0`, current
[ram_configuration.h](../../recomp/overrides/native_cd_owner/ram_configuration.h)
and [runtime_adapter.cpp](../../recomp/overrides/native_cd_owner/runtime_adapter.cpp),
its actual final125 Runtime surroundings, and the existing GCC/LLVM v6 receipts.
The current bytes match both receipts:

| Input | SHA-256 |
| --- | --- |
| `ram_configuration.h` | `f8774e85e56938ff116425d13025c4647924392a5af883171bd1a58f95978649` |
| `runtime_adapter.cpp` | `ceb169ef93e6952fc73626c97f04ea06690c6f07be045420d60feb82e42ccd07` |
| `runtime_adapter.h` | `c9b25869715018d94ecb04b20788b44aba53a10345dca8ea63e7742282f9cc86` |
| `tests/harness.cpp` | `6fe40a3e841ccbc7bc3d2d1900fe5ea9b6029f407d0332d421c1adaa48b67b08` |

## Contract checked in source

`configureWithReceipt` and `ConfigurationReceipt::try_seal` obtain a short actual
`PreRunSetupLease`, then use the same configuration mutex. The actual final125
`PS2Runtime::acquirePreRunSetup` serializes registration/run publication, increments
a bounded setup count and refuses stopped/sealed runtimes. The persistent seal
keeps only a configuration-state reference/count; it releases that phase lease
before returning. Consequently a seal does not hold the run-start gate closed.

A successful configuration observation requires actual Runtime RAM equality,
32MiB geometry, the admitted File1 serial/code hashes and callback registration.
Only the actual selected native-CD branch issues the private receipt. An active
asynchronous session remains asynchronous despite changed environment settings;
a foreign active session refuses. There is no stop-and-relabel route to mint a
synchronous seal.

Unsealed configuration observations are invalidated before route setup and
replacement allocation. Configuration generations do not wrap. A failed
allocation or failed sentinel registration issues no usable receipt. The
process-sticky `asynchronous_worker_attempted` is set before Session construction
and is never reset by later receipts, worker drain, a different Runtime or
allocation failure. Thus a failed worker-registration attempt conservatively
excludes future seals, even when the retained route is synchronous.

`try_seal` requires the exact current state, matching Runtime/RAM/extent, a live
registered sentinel, synchronous mode, no asynchronous-attempt history, no active
Session and a bounded count. Configuration holds the same mutex before testing
that count: either sealing wins and all subsequent configure attempts conflict,
or replacement wins and the old receipt is stale. Identical reconfiguration is
also refused while sealed. Atomic release decrements once, move replacement
releases the old count, and moved-from destruction does not release twice.

The registered `RamConfigurationState` is a real Runtime external worker. Its
nonblocking stop marks `runtime_alive=false`; actual Runtime stop/destruction
signals registered external workers. An old unsealed receipt therefore cannot
be revived by constructing a new Runtime/RAM at recycled addresses. Registration
failure refuses issuance instead of relying on pointer equality alone. Existing
seals intentionally retain configuration exclusion after stop, until the accepted
audio owner drains and releases them. `matches` is an identity comparison on an
existing seal, not an alive/read-authority query; its documented post-stop result
is not proof that memory remains accessible.

No reviewed lock cycle was found: the short setup lease holds a count rather than
a Runtime mutex; configuration may briefly acquire the active-session and Runtime
registration mutexes, while stop snapshots/releases Runtime registration before
calling sentinel stop. Active-session exchange releases its registry mutex before
join/destruction. No configuration lock is acquired by sentinel stop or seal
release. This is a source lock-order observation, not timing or scheduler proof.

## Existing evidence and remaining limits

Receipts below `build-native-sjuni/cd-owner-ram-configuration` both have status
`passed`, 23 checks (one mock build, 21 fresh-process scenarios and one actual125
header object), and empty authored-source postchecks:

| Receipt | SHA-256 |
| --- | --- |
| `gcc-v6/receipt.json` | `5e8fdae5cd691d3a97e04dbeffaf7e57140096804409d979280ca3004940c207` |
| `llvm-v6/receipt.json` | `5545156a944866a1be90f97612a4c33a44cb508d43440894082a1df8c0841f30` |

Their actual-source reapply receipt is
`3019662f2fd62dbe4a9b3c7b99528bd631338424597ad78d2a4a04bcebeb3d6a`.
The harness checks move/replacement counts, stale/foreign/phase refusal, lifecycle
invalidation, active asynchronous retention, settings, allocation/registration
failure and 32 configure-versus-seal races. I checked the relevant source paths
rather than inferring correctness solely from those passing checks. I did not
rerun the tests or treat the mock phase token as an implementation proof of the
actual Runtime lease.

The seal certifies this native-CD configuration exclusion only. It neither owns
Runtime/RAM/parent storage, grants a read lease, identifies all writers, reserves
GPU publication nor provides a coherent multi-span snapshot. Other mutation paths
and resource lifetimes still require the explicit capabilities in the
[capture design](NATIVE_BANK_CAPTURE_CAPABILITY_DESIGN.md). The enclosing admitted
owner must retain actual lifetime/read authority and the seal through every
accepted producer and render call. A factory must not replace those capabilities
with a matching pointer, a code hash, a seal or an asserted guest depth.

The detached legacy-CD build is outside this interface's qualification. Existing
false-read callback behavior, unresolved completion-state error publication and
other original CD semantics are outside this configuration-only review. A leaked
seal conservatively blocks later reconfiguration; it does not silently relax the
profile. No whole-game/native-audio completion or performance claim follows.
