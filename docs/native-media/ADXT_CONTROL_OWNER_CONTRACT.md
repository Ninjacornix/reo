# Native ADXT control admission and shutdown

The runtime-independent `adxt_control_owner::Owner` owns one canonical
device-free `adxt_instances::Instances`, and exposes its render-only submix.
Its synchronous `Operation` borrows the controller under a mutex. No mutable
controller alias may escape. An operation must be bounded, must not wait for
guest work or provider I/O, and must not reenter another control owner. The
instance API retains its original caller-supplied tick and pending-retirement
semantics. This guard adds no scheduler ticks or source producer.

`request_stop` sets an atomic admission flag and returns. It does not mutate
the single-controller instance state from a shutdown thread. New operations
refuse immediately. Operations waiting behind an accepted borrow recheck the
flag after taking the mutex, before any effects. The accepted borrow may finish
using its existing source state. Rendering only touches the separately owned
private output state and never takes the controller mutex.

`join` refuses from any controller operation before waiting or closing
admission. That includes cross-owner nesting, which could otherwise create an
A-to-B-to-A lock cycle. Outside a controller scope, join closes admission,
waits for the accepted borrow, then actually joins the instance/source/private
output owners. Pending cancellation stays pending internally until the source
worker acknowledges it; elapsed time never grants reuse or completion. Source
providers must obey the existing file-only native source contract and cannot
wait on a controller/guest callback. An explicit fault retains state. Destruction
requires successful join, preserving ownership if a fence cannot be proven.

The final canonical snapshot is written once after source/private-output join,
then published with release/acquire synchronization. It never claims that an
outer audio device joined. Reports and the render-only lease can be observed
without borrowing the controller; report counters are point observations, not
an atomic cross-field event trace. A retained closed lease preserves prior
outer audio and can safely outlive the controller.

This guard is required by the selected runtime's actual shutdown paths. The
audited 130-patch `ps2_runtime.cpp` destructor calls
`joinExternalWorkersOrTerminate` before the later guest-host-thread joins.
The normal `run` exit joins guest threads first. A new external owner therefore
cannot assume that both paths supply controller quiescence in the same order.
The root adapter must signal this owner and invoke its blocking join outside
guest/RPC/controller scopes, before destroying the game binding. It must also
keep the actual runtime alive through accepted calls. This class does not
implement that runtime registration or a guest audio-function binding.

Qualification requires serialized callers; self/cross-owner refusal before
effects; a caller already waiting when stop arrives; join waiting for the
accepted borrow before closing native output; actual blocked-source completion;
an independently rendering peer; final private/device fence separation; and a
render lease retained after controller destruction. Fault-injected checks must
detect removing the post-lock admission check, bypassing the controller fence,
and treating pending source cancellation as completed.
