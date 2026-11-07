# Sound state RPC 0x10: identified refusal and candidate reply

The V12 diagnostic game run identifies the earlier V11 `read/unsupported`
diagnostic: SID 1, RPC `10` hex, client `2B0C00`, send `2B0C80`, mode 1. This
is measured request identity, not a measured stutter cause. V12 reached the
cinematic and gameplay without skip input, then exited 0 after ordinary window
close. Its complete audio/memory owners report joined retirement and zero
active memory slots/operations. It still reports the unsupported request,
19,680 underrun frames and two startup thread-manager warning lines. No timing
or general audio equivalence is accepted from this run.

## Existing behavior and selected replacement

Owned File #1 code `1AC6D0` calls `1A7FB0(0x10,0)` during startup. The latter
submits 16 bytes from/to the same `2B0C80` buffer, on client `2B0C00`, NOWAIT
mode, end callback `1A7FA0`, and a semaphore argument. A failed submission takes
its explicit -9 path. Ghidra was unavailable; the complete generated source
instruction comments and owned source mapping were inspected locally.

The existing host SDK does not implement an IOP query for this request. Its
generic SIF reply clears a self-aliased receive buffer, copies a distinct send
prefix without clearing the tail, or clears when the send is absent/empty.
Both copy and clear clamp at 1 MiB; overlapping copies proceed forward byte by
byte. The normal end callback handles completion, with no early NOWAIT signal.
This describes existing host behavior, not the original PS2 IOP implementation.

Public patch `0128-native-sound-rpc10-reply.patch` admits exactly SID 1 / RPC
`0x10` and reproduces those reply operations through the retained native RAM
capability. It leaves RPC `0x110` unsupported, preserves the other query routes,
and uses existing metadata/callback/retirement handling. It does not retry
through a legacy backend after native effects or initialize an invented IOP
driver state. The ordinary backend's generic reply remains unchanged.

## Offline qualification and pending game retest

Before the new route existed, both compilers executed extracted original SDK
reply/copy/clear bodies for 13 vectors. Their complete 4 MiB memory outputs
match. Native reply tests compare those entire memory images, including the
actual self-aliased address, partial tails, overlap directions, absent/empty
buffers and transfer clamps. Three deliberate faults are detected: omitted
self-alias clearing, reversed copy arguments, and an extra NOWAIT signal.
The unchanged previous wire/bank/PCM and 32 companion scenarios also pass.
All five actual matching SDK objects compile with GCC and LLVM. All 129 public
patches apply to a fresh independent checkout; the active submodule is untouched.

V1's additional reply fixture failed because it attempted to rename two nested
test entry points with one macro. V2 retains the unchanged old harness and
renames only its outer entry in a separate support header. Failed inputs/logs
remain retained; expected memory and wire results were not altered.

| Receipt below `build-native-sjuni` | SHA-256 |
| --- | --- |
| `audio-diagnostic-v12/observations.json` | `b12f1214d6723c228b0b7cdfc88077a70396b5b2c544ae6760c7230988d6ee37` |
| `dependency-sound-rpc10-reapply-v1-receipt.json` | `692d86d3e19c51039e58749cedf86597810fcff672e95b62a451d3b14605514b` |
| `sound-rpc10/original-llvm-v1/receipt.json` | `207c06175f62819921fa83430b51af0d187b68a8368846e29fa1170b4010b721` |
| `sound-rpc10/original-gcc-v1/receipt.json` | `2a3a901383074c01705d8d6903af93c5e52cd58b541a03dbb163cb19300321fe` |
| `sound-rpc10/qualified-llvm-v2/rpc10-receipt.json` | `a556fae8e4ec9aea4cf24a8f1771e82f18e525fb154fdb555cb642b523814842` |
| `sound-rpc10/qualified-gcc-v2/rpc10-receipt.json` | `1cf89669d95f9aea2e552405b4e9339340fd9b14a0a2a877991131539cf39810` |
| `sound-rpc10/objects-llvm-v2/rpc10-receipt.json` | `05d09614cdccacab0c4c99aab4e17b19b34028989124a6d0499b90839fe91504` |
| `sound-rpc10/objects-gcc-v2/rpc10-receipt.json` | `17cfac418aa9ca90ff0e2909c29dba328a48a187bf20ed7b7174f55c3f73bd69` |

The live observer retained 1,578 non-atomic records: at most three constructed
ADXT instances and one registered movie in this route; observed movie shared
objects were null. Twenty-six control rereads changed and remain marked
unstable. A separate bounded configuration read observed two movie frame slots,
ready threshold 4 capped to that slot count, selector 1, video 1/audio 0, and
property 47 zero. These observations guide the next priming/control binding;
they do not prove other rooms, editions or concurrent-media profiles.

A matching linked candidate and controlled fix/retest remain required before
calling the refusal resolved in the game. Stage 3 is still open.
