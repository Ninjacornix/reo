# Native session RNG and options

The independent `gameplay_session` core owns two random streams and typed live
options. It contains no CPU context, guest addresses or runtime dependency.
The original save codec consumes this shared session RNG; its private XOR
recurrence is a different contract and must not replace the shared generator.

Seeding retains zero and resets the observed byte. Requests select secondary
read, primary advance, observed-byte read, or secondary advance. An advance
replaces zero with one before multiplication by 176 modulo 0xff53. Unknown
selectors return zero without advancing either stream.

Option capture preserves saved bytes 8–15. Sanitization retains the original
signed offset limits, volume/profile bounds, brightness range and bit masks.
Restore publishes every live field before invoking screen, audio-mode, effects
volume and music-volume services, in that order. Each argument is read after
the preceding observer, so mutations made by an observer remain observable.

Both LLVM and GCC compare the complete six owned original bodies across
2,007,552 assertions, including 655,360 RNG requests, 256 seeds and 4,096 option
cases. The [qualification](../../tools/native_reconstruction/native_gameplay_session_qualification_v1.json)
records source, compiler, executable and receipt identities. Original bodies are
test evidence only; production uses the independent native implementation.

These are isolated comparisons with declared screen/audio/default service
ports. Actual game hooks and their lifecycle are a separate integration gate.
This component does not establish complete Stage 4 ownership or game acceptance.
