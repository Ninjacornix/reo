# Native session application owner

`game/native/gameplay_application/NativeSession` is now a concrete C++ application
owner around the retained `ScenarioArchive`, canonical shared Session and World,
Update, sequence state, Lighting, SceneChannels and an owned room graph. It uses
no CPU interpreter, register context or guest-memory model. It is a native
library target; production game selection/installation remains a separate cut.

The first admitted owned room is `r0417300.rdt`. Installation reads the actual
archive room and script section, proves the full Program, and preflights the
concrete provider profile. It imports the actual section11 LIG into the canonical
Lighting owner. A real `RoomSceneInput`/`RoomSceneOwner` installs section10's five
authored records plus two helper records into one shared Records pool consumed
by SceneControls and Proxies. SceneModels, SceneModelBindings and sixteen matrix
channels belong to the same room lifetime and use Update's canonical flags and
World's canonical room reference.

Both type0 model references in this owned room are authoredFF absence. The
existing qualified opt-in `NoModelRepair::authored_absent` capability provides
that explicit constrained repair profile. This preserves native authored
absence rather than reproducing the original out-of-bounds aliases. A room needing any physical model asset
refuses until its real asset owner is supplied; no fabricated model pose is
installed. The same refusal applies to scripts requiring capabilities outside
the initial concrete composition. Parser admission alone does not bypass it.

The real room script's B5 commands require an actual refresh consumer. RoomState
implements ControlEffects using native `reset_five` and complete
`SceneMatrixPrograms::select(..., terminal)` for6B5E10. This reaches the existing
native binder and terminal evaluator when canonical strided flags permit it.
Child failures are retained and reported at the application boundary. No
successful callback stand-in is used.

`Owner::step_script` is the canonical application script entry. It reuses the
existing Update caller and its flags, timers, action choices, publication sink
and offline coordinator. It rejects foreign World/flag/timer capabilities before
effects and guards reentrancy. It runs no frame workers and commits no simulation
clock. Offline room installation atomically binds channels1/2/3 plus the real
secondary entry on5. Offline stepping requires an active canonical party; actual
actor startup remains a separate producer.

Room replacement prepares a complete new graph before publishing script bindings,
lighting and identity. Old room records and authored-absence leases retire through
their actual owners; stale shared-record identities no longer resolve. Missing
room/provider/program failures preserve the previously installed room. Closing
guards reentrant actor destruction and honors World's existing controller-busy
refusal before retirement.

Full frame `advance` requires real PhaseServices and World Services. Missing
services refuse before script, actor or clock mutation. This application owner
does not claim a completed gameplay frame, input/controller host, actor asset
startup, scenario EVB, semantic save, renderer or installed game.

Paired current CMake/owned-room receipts are
`build-native-sjuni/native-application-session-{llvm,gcc}-v2/receipt.json`:
158 checks each, four actual room compositions, twelve script steps and four
missing-frame-services refusals. They cover ordinary/offline dispatch and both
flag-gated terminal outcomes, real Lighting and all seven shared records,
offline class scheduling, canonical-provider refusal, room replacement and
destructor reentrancy. Each receipt captures the actual605-input CMake source/
header closure and50 native archive identities, with no source drift. The only
v1 failure was a fixture World left in default offline mode while its test
Program was ordinary; fixture mode was corrected without changing production.

Both current eighteen-parent cohorts pass with no source drift across622
captured source/header/CMake inputs. Receipts are
`native-application-session-parents-{llvm,gcc}-v2/receipt.json`; they include
the head agent's current voice/controller registration and both actor worker
adapters. The v1 parent wrapper retained an outdated expected count17 while all18
tests passed; the corrected v2 wrapper reran the unchanged code and sealed18.
The retained seal is `tools/native_reconstruction/native_application_session_qualification_v1.json`.
Stage4 remains incomplete until the
remaining native application producers, full frame consumers and installed
acceptance close.

The subsequent [SessionRooms production adapter](SESSION_ROOM_RESOURCES.md)
retains this same application graph and supplies actual archive wall/floor/region
geometry to native flight/contact consumers. Room generations now retire
explicitly while retained invocations keep their data alive. The separately
qualified SessionStartup application owner also composes actual roster startup
against these same World/Update owners; it does not duplicate the session.
The [object binding owner](SESSION_OBJECT_BINDING.md) now also retains the
canonical scenario placement table in publication and concrete reception.

The [room object Scene](ROOM_OBJECT_SCENE.md) now uses the room's actual
model/proxy graph and a full64-slot object entity store. Its separate room
identity cannot consume an object slot. The admitted room runs the complete
zero-current-object outer caller; initial saved model poses still restrict
rooms that require real instances.
