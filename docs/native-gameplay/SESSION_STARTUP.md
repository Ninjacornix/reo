# Canonical application startup

`gameplay_application::SessionStartup` binds the qualified ordinary startup to
an existing `NativeSession`. It borrows that application's World, Update owner,
ScenarioArchive and room owners. It owns the actual actor/motion asset readers,
one exclusive HumanoidMotionOwner and one exclusive PrimaryActorModels cache.
The existing World registration checks reject a second competing owner.

Construction requires an explicit initial bank publication. Cold source
`1B2150` does not write the default-loaded gate, so this adapter has no guessed
gate default. Unknown/null banks refuse before registering owners. Asset reads
use retained native Sources; there is no guest buffer or production register
context. The NativeSession must outlive this borrowed owner.

`initialize_records()` invokes actual qualified `66A730` bootstrap on the same
World. It keeps all eight slot bytes zero. It does not infer population,
character assignments, roster choice, stream-stage state or launch inputs.
`start()` supplies the application's same Update and Archive to the existing
complete bounded `5EB520` startup, together with actual asset/model owners.
Required external consumers remain explicit `PrimaryStartupEffects`; no default
implementation silently reports completion. Reports preserve reached prefixes,
and retries reuse the established live actor identities and model instances.

The adapter exposes its same model/motion owners and asset readers for later
scene lifecycle composition. It does not infer a lifecycle call to `5EB520`
from a cleanup function's name. Final scene teardown and queued continuation
must use their proved source paths before ordinary startup can run.

Busy guards protect both the adapter and canonical application operations during
external resource calls. The paired test providers attempt reentry, record bootstrap,
World/session/update/model closure, room replacement and script/frame stepping.
It observes busy refusal throughout. Closing the adapter releases its capability
registrations; retained actor/model leases remain valid. Closing the session
first is also covered while the borrowed Session object remains alive.

Owned tests execute a controlled roster alongside actual `r0417300.rdt` room
records, proxies, controls, lighting and matrix owners. Roster kind0 is an
explicit fixture input; this comparison does not claim an authored full launch
or actor placement in that room. Both ordinary and offline modes run actual
model startup, scenario NPC/enemy imports, an interrupted resource phase, retry,
and the installed room script. File #1 model/motion inputs and the additional
room/NPC/enemy bytes are checked against the pinned inventory.

Paired `session-startup-{gcc,llvm}-v3` receipts pass the same results: 1,987 owned
application checks, six completed startups after interruption/retry, 26 model
instances, 399 guard observations, six owned-room script steps and 27 retained
lifetimes. The fixture-only CTest also passes 21 checks. Sixteen exact assets
are verified against the pinned inventory.

The verifier reruns the complete original startup-body suite in this current
immutable application closure: 9,876 checks, 58 normal original returns and 31
controlled interruption prefixes per compiler. The native host regression adds
158 checks. Snapshot bytes remain unchanged; three unrelated test/verifier
changes are recorded as live drift.

Historical failed v1 snapshots retain the in-flight Interpreter174 helper
linkage failure. Failed v2 snapshots retain the newly required transitive
ResourceFactory dependency failure. The canonical Scenario PUBLIC dependency
was corrected, and fresh v3 captures pass. No successful stub or special
application workaround was introduced for either failure.

This is a host application composition proof. Renderer/audio consumers and the
remaining frame-worker capabilities are still explicit; no game process,
window, audio device or power action is started by these checks.
