# Serviced ADXT discard/rebase boundary

The original `133058` operation reads the paused byte once. Zero returns without
service. Otherwise `12C8B0` reaches the owned diagnostic/no-op `13F158`, then
`132C08` performs its real group attempt, and only afterward does the operation
query raw queues and publish the new estimate/tick origin. A nonzero service
word causes the actual group to return through its guard; it is not a reason
to skip that call or to fabricate a busy word.

The new independent completion core accepts a strongly retained, explicitly
qualified service port and shared clock identity. The port's observation is
pure; its service operation must call the actual matching native group and
return fresh stream/queue state afterward. Matching metadata alone is not proof
of that binding. Production player publication and its canonical state lifetime
remain an additional integration obligation.

Native numeric admission requires supported nearest/masked FP state and valid
raw queue observations before effects; paused calls also require a nonzero raw
denominator both before and after service. Original zero-denominator execution
is retained separately, outside this native profile. An actual failed service
or invalid post-service observation retains its effects and returns an explicit
failure without inventing a completed rebase.

The returned stream state preserves fresh paused/play bytes and changes only
estimate_base/tick_base after successful paused completion. The raw baseline
uses the original signed-word float conversion, divide/multiply order and high
unsigned conversion branch. It does not clamp padding-negative positions or
replace queue position with copied/device frames. FP environment is preserved.
The native shared in_call guard rejects recursive clock operations; admitted
service children cannot make such recursive queries. Source service, output
play/pause, device progress and host time are not synthesized by the core.

The original-word oracle executes the full discard body and all five group
envelopes. Prepared clock state is relocated into the actual first pool slots,
so the serviced target and subsequent raw query refer to the same object.
Individual group children remain external boundaries with independently
authored literal queue effects. That evidence proves dispatch and subsequent
clock calculation, not complete original decoder/DMA/RPC child execution.

This component does not silently enable the currently refused branch in the
existing phased player/control session. Its real canonical-state/service port
must be implemented and validated before that caller is switched.
