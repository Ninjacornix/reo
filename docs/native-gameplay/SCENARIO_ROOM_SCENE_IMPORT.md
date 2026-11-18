# Native room control and collision initialization

Status, 2026-11-09: a bounded native `5C1390` initializer profile now populates the shared128-record owner and the canonical model/channel side state. It is independently qualified offline. Actual room loading/model construction, remaining proxy callbacks and game installation are still required; Stage4 is incomplete.

`RoomSceneInput` imports sectionA's offset directory and0xB0-byte authored records, with complete bounds checks. It reads two declared32-byte mapping objects from the room script section. All166 owned inputs prove that table1 immediately follows table0. The source's `table0[id+0x20]` accesses therefore use that second object explicitly. The importer refuses unknown object relationships instead of treating an arbitrary adjacent extent as a64-byte mapping table.

The parser preserves the14 initial type branches into immutable typed definitions. Known runtime control fields, geometry, priority, raw activation, model selection and deferred side writes are explicit values. Type-one initial angle state and ordinal metadata remain available through the immutable definition. A definition is not a second mutable runtime record and does not advertise an unported type callback.

`RoomSceneOwner.install` requires `SceneControls` and `Proxies` to share the same canonical pool, and matrix programs to reference the exact controls/models. It admits an empty pool only. It prepares native depth-extension84, depth-sixty85 and type-six middle-corner reprojection using retained native model poses; helper records retain the same typed parent identity. Base/helper order follows the real allocator. Resource, numeric and total-capacity checks precede publication. An allocation failure during publication retires newly admitted IDs before returning, and no model/channel/global side write has occurred at that point.

Model sound-resource bytes are written through `SceneModels.sound_resource`; type-zero/type-two tags are written through `SceneMatrixPrograms.source_type`. These are the canonical owners, not extra arrays. Only a type-ten input changes `RoomSceneGlobals.height`; an absent input preserves prior state. Teardown retires this owner's identities and rejects stale/reused lookups, while external models/programs/globals retain their separately owned lifecycle.

The optional `P48` fallback was tightened during this work. Type-zero destinations and type-two model descriptors own that value once. Removing typed metadata cannot revive an earlier collision copy: the fallback is cleared and the derived collision view becomes unavailable/inactive. The full `P58`/`P60` values still back their narrower source consumers, including complete-word collision equality versus low-byte matrix class selection.

Both LLVM and GCC pass the final exact-source cohorts:

| Qualification | Result per compiler |
| --- | --- |
| Native initializer and complete original chains |256,346 checks;58,566 top-level original calls |
| Owned content |166 rooms and2,144 base records parsed;163 admitted with explicitly controlled external poses;3 refused before effects |
| Imported reverse queries |All256 request bytes for each admitted controlled/owned room, using the actual original `5819C0` |
| Actual original helper calls |342 depth84 entries,96 depth85 entries including its legitimate no-op branch,127 reprojection entries,517 complete inverse-matrix calls |
| Refreshed shared-view ownership |41,984 checks across256 cases, including removal of typed metadata without stale fallback |
| Refreshed full VM and real opcode131 consumer |14,001,146 checks;29,753 original dispatch calls;326 ordinary/299 offline qualified bindings; no new opcode admission |

The initializer oracle executes the actual `5C1120`, `5C11B0`, `5C12A0`, `5C1390`, `5C45C0`, `5C5D30`, `5C6100`, `5C66C0` and `5819C0` bodies, plus the actual `1900E0`, `191430`, `1919D0`, `1920A0` and two original vector helpers. Matrix/inverse/vector operations are not successful doubles. Bounded memory copy/clear remain declared surroundings. The identity cache at `294E00` is explicitly seeded from its verified `195E50` static authority; its whole bootstrap is not dynamically executed.

All room sections come from a581,688-byte package validated against the owned archive/member hashes. Test poses are deliberately constructed valid external states; they are not proof that full room model construction is native. The first new parser comparison detected incorrect type-six/type-seven selector offsets. The parser was corrected to original fields `P54`/`P70` (input44/input60), and all failed fixtures remain retained. No existing original algorithm or test expectation was weakened to hide that error.

## Explicit stock gap

`r0010100.rdt`, `r0012200.rdt` and `r0417300.rdt` contain the five known table-zero `FF` references. The native owner refuses the applicable out-of-range model/sound operation before changing the pool or other owners. It does not create a Model255.

The original alias matters: sound byte `4A1D70+FF` is `4A1E6F`, inside the canonical room-contact counters at `4A1DF0`, specifically room2/counter15's high byte. Expanding the native sound map to256 entries would create a shadow of that counter state. Original pose slotFF resolves to `4A39D0`, spanning matrix-channel9 translation and channel10 work. Those source aliases require a separate ownership/behavior investigation; their presence does not prove a recorded slowdown or justify substituting model0.

Other refusal tests cover wrong/closed owner, nonempty pool, capacity exhaustion with rollback, invalid channel, degenerate pose and malformed record/directory/remap extents. A type-seven `FF` mapping whose branch performs no model/sound access remains a valid immutable byte; admission is based on the operation actually required, not an arbitrary blanket range check.

## Remaining integration

The full VM rerun pins World/SceneResources to `d6f2df32` and the already qualified periodic visual/geometry/track core to `89e073ff`. The shared owner and its new fallback behavior use current sources. This avoids confusing concurrent general-effect and attachment work with qualified VM behavior. Exact pin and private-snapshot hashes are recorded in `native_gameplay_room_scene_import_qualification_v1.json`.

Complete room reset/loading and real model/resource construction must supply admitted native state. Resolve the three-room alias gap, port the remaining normal proxy/event consumers, and qualify actual game callers before installing this profile as a stock-wide room path. The broader [shared ownership requirement](SCENARIO_SHARED_PROXY_POOL.md) and [Stage4 plan](STAGE4_PLAN.md) remain active. No game, input, process attachment, window, performance measurement or PC sleep was used for this work.
