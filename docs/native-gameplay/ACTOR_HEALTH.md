# Native health and status actions

The independent actor core now implements signed health adjustment and authority
gates, periodic status admission/expiry, status clearing, zero-health action
selection, and the exact hit-response overrides. These functions use typed native
state and the shared session RNG. Production contains no translated instruction
execution, guest memory, register file, or original function address.

Health addition/subtraction wraps to a signed 16-bit result before its original
limits are applied. Additive mode has an upper limit only and always returns
zero. Subtractive mode rejects its invulnerability status, clamps nonpositive
results to zero, and returns one for that path. Authority rejection also returns
zero. Callers must not interpret zero as a general failure or success Boolean.

Status timer invocation always draws from the primary shared RNG, before pause
and invulnerability gates. Counters count admitted invocations, not wall time.
Intervals preserve both original clock modes; this work does not change speed.
The one-unit timer and five-unit timer have different reload, health-floor and
expiration behavior. Later gates reread values after synchronous service calls.

Clearing a status publishes the original notification even for an unknown
selector. Zero-health selection retains its distinct actor-class and status
branches. Only the explicitly supported motion classes override hit responses;
motion 0x28 clears health without changing or snapshotting the action.

Both compiler cohorts pass 3,145,728 arithmetic cases covering every signed
health bit pattern, 65,536 authority cases, and 163,840 status/action cases with
189,996 ordered trace words and 32,768 shared RNG requests. Seven complete owned
original bodies execute inside the isolated status oracle. The
[qualification](../../tools/native_reconstruction/native_gameplay_actor_health_qualification_v1.json)
records the exact compiled sources, executables, original-body word audits and
receipts. Two earlier failed status runs retained a fixture tail-return error;
the original publication tail call now returns through its declared fixture ABI.

Health-class refresh, feedback, actor-state publication, resource cleanup,
recovery and action snapshots remain explicit provider ports. Pending-hit damage,
inventory and full actor behavior still require migration. These comparisons
are not actual gameplay integration or completion of Stage 4.

Native `EntityStore` separately owns typed actor payload lifetimes. Domain and
generation identities reject stale or foreign actors. Retiring an actor
unpublishes it before destruction; a strong invocation lease can retain its
payload until the current call finishes. Exhausted generations retire their
slots. Shutdown closes lookup/creation before releasing payloads. This is new
native ownership policy, not a claim that legacy allocation internals were
reproduced or that every actor component already uses this store.
