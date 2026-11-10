# Resource content replacement and instance rebinding

`ResourceContents` implements5B4C90/5B4BF0/5B3C70 through the canonical
World, SceneResources, ResourceTemplates, ResourceUse and ResourceFactory.
`ResourceFactory::rebind` supplies complete admitted591510. Native descriptor
and model capabilities replace arbitrary original record/model pointers.

Direct replacement publishes content and its signed-content selector before
touching a model. It has no activity/owner gate and does not change quantity.
Owned replacement requires activity, a nonzero owner and unequal unsigned old
content versus signed low16 new content. This deliberately admits negative new
content even when its bit pattern equals the old unsigned content. It then
replaces and resets quantity through the actual initial-quantity query. The
0/1/B remap uses direct replacement to1C5/1C8/1C6 without quantity reset.

Rebinding changes the existing model's content, selects its update work from
the descriptor named by that model's own resource slot, resolves actual immutable
NBD poses and copies the new parts. It preserves unused trailing poses/masks,
timers, flags, transforms and other untouched fields. Known missing geometry
sets visibility false. Rebinding creates no model and no companion effects.
Common/weapon/delayed work uses the same already qualified owners and scheduler
ordering. Weapon elapsed time and pulse time are distinct fields; neither is
reset here. Both weapon playback and delayed work use the same elapsed field.

Both compilers pass20,586,083 combined assertions each. New coverage includes
469,596 content operations,5,376 direct model rebind/update sequences and672
ownership/closure refusals. All16 owned NBD banks and five owned ITEM banks run,
alongside a controlled callback-class bank. The full signed-content domain is
also compared without an instance. Tests vary activity/owner, same-content
gates, signed narrowing, missing geometry, retained trailing parts and model
resource slots different from the calling descriptor. Existing construction,
placement, delayed work, release, visuals and inventory regressions also pass.
Both parent builds and five integration tests pass. Evidence is sealed in
`native_resource_content_qualification_v1.json`.

This comparison exposed a shared fixture defect: it initialized the original
selector table to zero while native selectors correctly began atFF. The fixture
now executes actual5919F0 before import; the current regression covers that
initialization. Failed cohorts are retained. Production selector semantics were
not changed to match the incorrect fixture.

Callback classes outside0..3 and the two known greater-than-six-part primary
roots remain explicit unavailable profiles. Foreign/stale models refuse after
the measured descriptor publication prefix; they cannot mutate a recycled model.
Recipe/transfer dispatch, higher gameplay consumers and actual game installation
remain open. No game or audio device was launched; installed V39 is unchanged.
This component does not close Stage4 or its acceptance requirements.
