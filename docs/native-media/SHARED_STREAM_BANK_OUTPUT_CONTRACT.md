# Shared native stream and bank output

Status: next implementation contract. The existing qualified bank session and
stream output owner remain independent until this composition is tested. This
document does not claim a device test or original whole-game parity.

One callback owner renders all compressed-stream PCM, then adds bank/sequence
audio, then obtains the master gain and clamps the result. Preserve the existing
PCM core's own clamp and exact stream summation order. Preserve all 224 bank gain
reads in their qualified order; do not replace them with a guessed single gain.
Master gain admission remains finite [0,8]. This order comes from the existing
qualified PCM bridge/complete-audio aggregate; it is not inferred from a desired
sound result. The old source-qualified bank DSP expressions remain unchanged.

The bank tail owns its bank session and strongly retains pure, nonreentrant
bank/master gain providers. It exposes control-side preparation, installation,
commands and copied observations, without exposing a mutable renderer or bank
session alias. Gain callbacks cannot read guest state, perform I/O, allocate,
join, access output/provider APIs or reenter the graph; any eventual game binding
must independently establish those properties. No new device is opened by bank
construction, preparation or installation.

A tail binds once to one output lifetime. Reject reuse by a second output owner
before attaching its provider. Stream retirement changes only that producer:
banks, peer streams and the shared device keep running. Source failures mute the
affected stream without resetting the bank session. Ordinary whole-output stop
closes callback and bank-operation admission. Provider detach/fence precedes bank
join, storage clear and successful final output retirement. A failed provider
fence retains the whole graph. Control callers release their bank Submission
leases before joining, as required by the existing bank-session contract.

Rendering takes the stream data lock before the bank data lock; bank control
operations never acquire the stream lock. No provider lifecycle call or join may
occur with either data lock held. Rendering uses bounded preallocated bank/core
storage. Failure after PCM consumption is explicit and silences the current
buffer; it must not claim a transaction rollback or recover by resetting peers.

Required evidence: bit-exact stream→bank→master results against separately driven
qualified cores, output with only banks active, bank survival after stream
retirement, actual blocked callback/provider-fence failure and retry, duplicate
tail refusal, gain-failure behavior, no render-side asset allocation/free and
whole-lease bank shutdown. Run all prior stream/LSC/loop tests with no tail and
both compilers. Guest packet capture, the original global scheduler, movies,
actual game transitions and stages 4–6 remain separate obligations.
