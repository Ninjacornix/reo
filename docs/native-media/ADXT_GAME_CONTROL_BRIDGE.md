# Stable native controls for the guest adapter

The stable instance facade now exposes the existing qualified integer-ratio,
centisecond and paused-discard clock paths, plus loop and time-base controls.
These calls use the canonical source and session, without manufacturing a
second clock or servicing once per output sample. The supplied tick remains the
original game tick; no wall-clock or callback-count substitute is introduced.

`ClockConfiguration` imports only the actual game-owned mode, ratio,
resynchronization count, rebase selector and raw drift bits. It cannot overwrite
native service/reentry guards. Import refuses while service or another clock
operation is active. Values are not repaired or normalized; the existing clock
core retains its explicit unsupported arithmetic/environment results.

Time-base and loop setters are stable instance properties. When unset, they
preserve the prepared source configuration. Once explicitly set, they survive
stop/replacement, including a replacement waiting for a blocked old worker.
Destroying and recreating the instance resets those overrides. A loop request
that conflicts with a prepared seamless/LSC source refuses before retiring the
active source or changing a pending source. It does not silently turn a regular
loop flag into a seamless queue-repeat request.

Clock queries and paused discard return pending for idle/retiring native
instances. That is this facade's status, not an invented original game return
code. The guest adapter must separately preserve the original idle-handle query
semantics, ABI side effects and global publication. It must copy changed shared
clock fields back under the actual guest ownership boundary.

Qualification uses actual source workers and output state: exact pre-header
ratios and centiseconds, a base retained across blocked replacement, fresh-slot
defaults and stale keys, two real regular-loop iterations followed by loop
disable/EOF, and refusal of a conflicting seamless start before old-source
effects. A live queue notification attempts a clock import during service and
must observe busy with every shared field unchanged. These checks supplement
the independent original clock comparisons; they are not a guest ABI test.
