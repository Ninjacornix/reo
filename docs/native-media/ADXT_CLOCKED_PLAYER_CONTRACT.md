# Live native player clock boundary

This revision connects the separately qualified estimated/integer clock to the
actual decoder/PCM/shared-output player. It consumes real prepared queue
observations: original outer decoded count, channel0 PCM bytes and shared-output
occupied samples, plus header total/frequency. The initial tag0 profile has
16-bit depth, no seamless A4 offset and an explicit modulo32 time-base word.
No service-call count, device timestamp or host clock substitutes for a supplied
original tick. Shared mode/ratio/rebase/service state is strongly retained and
externally serialized across all players and clock calls.

Per-stream paused/RNA-play bytes and estimate/tick origins are canonical clock
state. Startup and natural completion synchronize actual output play and those
origins; getter-induced rebase and pause/resume synchronize the playback
controller's corresponding fields. Retired pre-clear queue evidence is marked
invalid as a live clock observation. A closed shared output is not a valid
clock endpoint.

The pure prepared clock core is unchanged. It admits nearest rounding, masked
exceptions and no FTZ/DAZ, preserves caller FP state and retains the original
signed/wrapping arithmetic and asymmetric drift comparison. A math preflight
refusal does not mute output. The discard/rebase branch requiring unowned global
workers remains an explicit refusal; the caller may use the already-busy branch
only when that condition actually holds. This is not full scheduler recovery.

Pause compares the full signed argument with the sign-extended previous byte.
Only argument1 pauses audio; every other changed argument resumes, while the
stored byte remains its low8 bits. Thus argument2 plays audio with byte2 retained.
An unchanged signed argument performs no output call or tick/baseline update.

Before actual pause effects, a private scratch copy of the pure clock state
performs its normal preflight. It has no hooks, allocation, I/O or canonical
effects and preserves FP state. After admission, the canonical paused byte is
stored, then actual output play changes. The raw queue observation used by the
canonical clock calculation is captured **after** that play operation. Audio
callbacks may progress between resume and that observation. A single control
owner and immutable active header make both prepared snapshots valid; no other
control/clock caller may interleave. The duplicated scratch calculation is not
an original-instruction-count claim. Unexpected post-effect failure retains
state and faults only this stream, with no fallback.

Each actual clock transaction still uses the unchanged pure core with no mutable
control callback. Canonical calculation and FP environment restoration finish
before returning; copied bytes and output consumption remain separate. Gain,
source retirement and shared-provider lifetime follow the prior shared-player
contract. No game, device or runtime selection is implied.

Differential qualification captures native live queues and literal results,
freezes those measured inputs before original replay, and executes the already
audited original clock instructions with the separately qualified FP worker.
These are measurement-derived inputs, not newly independent authored originals.
Only typed clock fields/results are compared; original guest ABI/FPR scratch
and global scheduler equivalence are not claimed.

A separate scheduling fixture invokes the existing model callback at the
permitted boundary after actual resume and before raw observation. It supplies
no sample-position/math result. Original replay uses separately observed
post-command queues (no later callback in that fixture), so a mutation that uses
the pre-resume observation is detected. This scheduling glue is generated test
code, never a production hook. Plain and scheduled client results need not be
equal: they deliberately have different external callback progress.
