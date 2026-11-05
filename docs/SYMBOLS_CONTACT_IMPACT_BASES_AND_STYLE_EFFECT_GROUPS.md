# Contact impact basis dispatch and style effect groups

Static File #1 US owned o2 analysis, 2026-11-05. Two complete original bodies and owned68-entry table. [Identity](FUNCTION_INDEX.md). Offsets/masks hexadecimal. No game/process/visual or measured-cost claims.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5DD580](../recomp/config/output_ovl/o2/o2_005DD580_0x5dd580.cpp) | `dispatch_class_zero_owner_contact_effect_basis_by_scene_event_candidate` | Confirmed full control/data writes; asset names unknown | Requiresrecord2Cnonnull and ownerclassbyte2==0; other owners return. Eventrecord1B==1: buildorthonormalbasis191820(third=gridAnormal a2,auxiliaryY=(0,1,0)),zero matrixXYZ,then5DD6F0(owner,basis,record1C,recordbyteD). Event2: eye=trianglepoint a1+trianglenormal a3;lookAt191070(matrix,eye,trianglepoint,(0,0,1)),zero matrixXYZ. If low8t0&81==81,copytrianglepoint,addY1,call5DD9D0(owner,NULL,mutableXYZ,recordD). Other event2 calls5DD6F0(owner,basis,trianglepoint,recordD). No othereventacts;no degeneracy guard in local basis construction. |
| [o2 0x5DD6F0](../recomp/config/output_ovl/o2/o2_005DD6F0_0x5dd6f0.cpp) | `spawn_contact_style_effect_group_with_special_resources_and_mutable_position_candidate` | Confirmed full control/data writes; asset names unknown | Originala0owner is discarded before use. Signeda3<44hex only;negative is not rejected. Signedhalf70B5E0[selector] givesresource; -1 returns. Branch46/4B spawn6525C0(NULL,XYZ,0,resource,0,9A993).79 spawns79 then2A with1A993.50 spawns6525D0(NULL,XYZ,0,50,0,1A993,653E80),success scalesXYZB4/B8/BC=2 andhalf23E=4.49 spawns49/1A993,then5E0680(1D):exists setsbyte8=A,else651A30(0,0,1) successactive1,byte1=0,type3=1D,update654D90.32 spawns6525D0(basis,XYZ,-1,32,0,1A193,6531D0). Otherresources:transformlocal(0,0,-1)bybasis andADDINPLACEto callerXYZ;spawnselectedresource with callback653E80,mask-1/1A193,success randomhalf94 andhalf23E2;then independently selected+1 withmask-1 andselected+2 withmask0,1A193. No rollback or standardizedreturn. Defaultbranchrequiresbasis; specialNULLbasisbranchesdo not useit. |

Owned70B5E0[136] contains68 signedhalfwords, SHA-256 `14546ddf7f1eae94a301d4e321106c75da5f7c64c78ddf48a902590481515966`. Indexed selectors0..67 decimal; effect IDs below hexadecimal:

| Selector decimal | Selected effect resource |
| --- | --- |
|0,31..39,41..50,52..57,59,62..67| -1 (no effect) |
|1..11,14..17,19,21,27,28,30,51|28|
|12,13|2B|
|18,22,25,61|46|
|20|50|
|23,29,58|4B|
|24,60|79|
|26|49|
|40|32|

Owned70B668[12] localoffset(0,0,-1), SHA-256 `02f50cc13892e5a15486c38f5fcaa7dd69c7fb56b5b8d0e874feb3699835898f`. Bounds and terminal assumptions are not inferred beyond the physical table; negative selectors remain outside proved caller admission. The common5DD580 caller supplies unsignedbyteD, eliminating negative indices locally but not proving the upper bound.

The default branch mutates its XYZ argument before any allocation result, so a caller passing cachedrecord1C or an output point receives a changed point even if allocations fail. Special branches generally leave that point unchanged. The owner argument is unused in5DD6F0; the separate [5DD9D0 notification variant](SYMBOLS_EFFECT_BURST_CONSTRUCTION.md) does use owner information and has different resource/notification rules. They must not be merged as aliases. These are optional scene-contact effects from [shape consumers](SYMBOLS_LINKED_CONTACT_PACKET_SHAPE_CONSUMERS_AND_EVENTS.md), not the collision detection or health-update implementation itself.

[Matrix bases](SYMBOLS_RENDER_MATH.md), [overlay vector math](SYMBOLS_OVERLAY_MATH.md) and [resource constructors](SYMBOLS_CUTSCENE_RESOURCES.md) establish called mechanics. Runtime style names, selection frequency, resource residency and render cost remain unknown.
