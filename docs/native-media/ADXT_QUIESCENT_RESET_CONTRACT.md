# Canonical native source reset admission

The native source controller may perform a bounded PCM reset only inside
`Owner::when_empty`. Ordinary source admission and reset use the same lock,
recheck stop after waiting and prohibit nested control owners or source joins.
The check must find no constructed instances, pending source requests, retiring
sources, active session records, service operation, guard fault or occupied
private output. Ordinary instance destruction must already have completed its
actual source join and private output fence. Output emptiness alone is
insufficient: a source may still have a blocked file read after its output fence.

The controller mints a noncopyable `Quiescent` proof for the callback's lifetime.
It authorizes only that controller's exact render submix and the calling thread.
The callback may perform bounded reset/control; it must not retain the proof,
join sources/devices, access providers, call guest/SDK services or reenter a
controller. New source creation remains excluded until the callback returns.
This does not close the canonical session or its shared device.

The distinct Aggregate4 ABI mechanically preserves frozen Aggregate3's behavior
and common capture/device ports. Its new `reset_native` checks the scoped proof
before calling the existing raw bridge reset. Null, foreign or wrong-thread
proofs refuse. The raw bridge acquires its own data lock; the adapter must not
hold the private submix lock while resetting because rendering acquires those
locks in the opposite direction. The original unqualified reset entry retains
the prior post-source refusal.

The complete factory's native-source route invokes that new entry only through
the canonical controller. An occupied, stopping or nested owner leaves mappings
unchanged and records the existing reset refusal. The legacy original-source
route still dispatches its existing reset. A valid later reset is permitted only
after every stable game/native handle was destroyed and its sources joined; a
mere Stop with a retained idle instance is insufficient.

This contract is a native ownership boundary. It does not claim that original
game reset/destruction callers have been bound or that live return-to-title and
restart behavior is validated. Those remain Step 3 integration gates.
