# Joined movie audio controls

This scope connects movie pause/resume and frame-step policy to the existing
native ADXT Session and to the same filter owner used by movie clock queries.
It is a prepared, serialized audio graph. It does not implement video frame
presentation or full movie creation/destruction.

An optional `Config.audio_commands` admits channel-7/decoder-3 presence and
initial requested-pause/residual state. It requires buffering facts and a
`ControlledSource` capability on the exact source object retained by the clock.
The factory refuses a separate or query-only source. Property 6 comes from that
same buffering owner. No control capability is enabled by default.

`audio_requested` stores the raw request before suppressing unpause when the
movie's user-pause word is exactly 1. `audio_temporary` suppresses unpause when
the saved requested pause is exactly 1. Neither gate treats every nonzero word
as 1. The existing pause controller's channel-7 command now follows channel/
decoder presence and nonzero property 6 before applying these controls.

Mode 0 clears residual before temporary unpause. Mode 1 applies pause. Mode 2
checks readiness, obtains sample frequency, converts the original frame ratio
with signed product/division and low-word wrapping, carries the previous
residual, performs the qualified Session discard/service/rebase, stores the
returned difference and applies the same filter's baseline operation. The
original File #1 discard result is zero; the quantity is not a seek request.
The existing controller publishes its clock increment before this command.

`SessionSource` retains the Session, opaque stream key and original service-tick
owner. It validates identity/lifetime before reading a tick. Pause calls the
actual Session operation; discard may service the existing group and refresh
its clock according to the already qualified SDK policy. No extra source poll,
fixed display-rate tick, decoder replacement or device teardown is invented.
The filter pause word changes after device control completes. Context reentry
and detach are refused while control is active, and the Context retains itself
and its providers through callbacks.

Failures preserve already applied user-pause/nesting/counter/request effects;
they do not publish a successful filter update after failed device control.
Discard effects and residual publication remain if a later filter baseline
refuses. The copied audio-control stage/provider fields identify the failure.
There is no fallback to an original object after native side effects.

Requested/temporary pause and the called SDK pause/filter setters are void.
Their incidental guest return register is retained in original evidence but
excluded from the native value-return contract, including suppressed unpause.
Frame-step mode 2, unsupported modes and absent/disabled component routes retain
their explicitly defined zero result. Full guest ABI reconstruction is outside
this typed native interface.

`detach_queries` fences new Context operations; it is not source/device/frame
retirement. The owning movie must explicitly retire its Session stream and join
its shared output when appropriate. Provider refusal during join retains the
resources needed for retry. Outstanding peers must not be destroyed by a movie
control operation.

Qualification compares original movie dispatch/policy/filter bodies with SDK
pause/discard/frequency ports. Those SDK internals retain their separate prior
qualifications. Native owner checks use actual source workers, decoding, PCM,
Session controls, mixer and callback fences with an explicit device model.
They do not establish audible output or complete game/movie integration.

The requested three-item scope ends at connected audio controls, original frame
arithmetic/filter reconciliation, and buffering/repeated-pause/failure/shutdown
validation. Actual video frames, full movie start/stop/rebuild and representative
in-game transitions remain in the rest of stage 3.
