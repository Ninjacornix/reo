# Resource-attached effects and nearby effect constructors

Static File #1 US research, 2026-11-04. Original identities are recorded in
[the central index](FUNCTION_INDEX.md). This follows the effect calls in
[instance pooling](SYMBOLS_RESOURCE_INSTANCE_POOL.md) and
[resource consumption](SYMBOLS_INVENTORY_CONSUMPTION_QUERIES.md). Only owned
static files were inspected; no game, build, replay, attachment, live-memory
inspection or implementation change was performed.

Numeric effect IDs and callback addresses describe observed construction.
Smoke/fire/splash or item names are not assigned from visual intuition. Shared
effect allocator/setup helpers are cross-references, not remapped here.

## Content-specific effects and resource instances

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5DDC70](../recomp/config/output_ovl/o2/o2_005DDC70_0x5ddc70.cpp) | `spawn_random_resource_periodic_effect_and_update_packed_cycle_candidate` | Probable role; full body reviewed | a0 XYZ,a1 packed signed halfword state pointer. Random1AEC80(1) low16%3 selects effect24..26,6525D0(NULL,XYZ,0,id,0,1A193,6535C0). On success copies XYZ38..40,C=0,F0=30. Packed phase=arithmetic signed state>>12;phase2 wraps0,other phase increments. Replaces packed state with phase<<12,then ORs max(0,signed16(E/2 toward0 + offset -4));offset0 when new phase0,otherwise30*(phase+1). Allocation failure leaves packed state unchanged. Does not preserve prior low12 bits. No phase-range admission. |
| [o2 0x5DF2A0](../recomp/config/output_ovl/o2/o2_005DF2A0_0x5df2a0.cpp) | `spawn_resource_content_selected_effect_parts_candidate` | Probable role; mechanics verified | Instance content36:6E calls5DF340(instance,0,BF);6A/6F calls(instance,1,C0);74 calls(instance,2,5A) then(instance,3,5B). Other content no work. No instance null/activity or allocation aggregation;does not release/transform source resource. |
| [o2 0x5DF340](../recomp/config/output_ovl/o2/o2_005DF340_0x5df340.cpp) | `construct_resource_effect_part_from_instance_transform_candidate` | Probable role; full body reviewed | a0 source instance,a1 full part index,a2 effect ID.652390(signed low16 ID),failure skips.652E20(new,low16 ID,0);sets active1,byte1=0,update14=58FBC0,render18=o0:371EF0,type3=1B,variant4=part,byte30=0. Initializes matrix50,composes source1C0 through191530,extracts matrix translation toD8 through1900E0;transforms local XYZ70B860+12*part through1919D0 and adds toD8. Sets1F0=&matrix50,word200=8193,word1F4=392670. No part bounds or source admission and no explicit pointer return contract. |
| [o2 0x5DF450](../recomp/config/output_ovl/o2/o2_005DF450_0x5df450.cpp) | `attach_content_specific_effect_children_to_resource_instance_candidate` | Probable role; full body and constants reviewed | Null source ignored;starts identity stack matrix composed with source1C0,zero local XYZ. Content72/3200/1C/1D/135/75 spawn through6525D0 with callback654720;table below records parameters. Common successful final child gets type3=1C,parent24=source,subtype1FF,content234=source content,half23C metadata. Content1D also creates a first independently guarded child type4/content/metadata15 before final child. Content3200 with signed low8 a1==0 accesses returned child before common null guard (caveat below). Other content no child. |

| Source content | Spawn effect / palette argument | Local position | Final child subtype / half23C |
| --- | --- | --- | --- |
| 72 | 27 /0 | (0,18.7000008,0) | 0 /1 |
| 3200 | 7F /FFFF | (0,-1,0) | 6 /1 |
| 1C | 44 /0 | (0,10.1000004,5.6999998) | 3 /E |
| 1D first | 40 /0 | (0,10.1999998,3.5) | 4 /15; separate successful-child block |
| 1D final | 3F /20 | (0,10.1000004,5.6999998) | 3 /4E |
| 135 | 43 /0 | (0,10.1000004,5.6999998) | 3 /E |
| 75 | 91 /0 | (-54.1500015,-2.3800001,0) | 5 /A5; successful childEC=10 |

For content3200 and caller switch0, `0x5DF594` loads the allocated child's
halfwordE and writes it to10, then setsE=2. The allocator result has no null
admission before those accesses; the common guard is later at5DF744. This is an
untested allocation-failure candidate defect. It does not show that the player's
crash or slowdown took this path, and no code was changed.

## Position and actor-context effects

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5DF790](../recomp/config/output_ovl/o2/o2_005DF790_0x5df790.cpp) | `construct_context_attached_type15_effect_with_random_counter_candidate` | Probable role; mechanics verified | a0 parent/context. Allocates652390(7),sets up652E20(new,7,-1);successful child active1,byte1=0,update6545F0,render371EF0,type3=15,variant4=0,parent24=input. Random1AEC80(1)&F into halfC. No parent null/activity guard;no allocation return contract asserted. |
| [o2 0x5DF820](../recomp/config/output_ovl/o2/o2_005DF820_0x5df820.cpp) | `spawn_effect89_on_surface_type81_candidate` | Probable role; mechanics verified | a0 XYZ copied,Y+300,616F20(position,&byteType,81) gives replacementY. Only returned type81 addsY+2 and spawns6525D0(NULL,position,FF,89,0,1A193,653E80). Successful child half23E=80 then5EAD70(child). No success value or surface interpretation beyond numeric81 assumed. |
| [o2 0x5DF8F0](../recomp/config/output_ovl/o2/o2_005DF8F0_0x5df8f0.cpp) | `spawn_effect1e_on_surface_type81_with_fixed_parameters_candidate` | Probable role; mechanics verified | Original a0 unused;a1 XYZ copied,Y+200,616F20 type81 required. AddsY+3,spawns callback653FA0/effect1E/paletteFF. Success652F90(child,owned0.300000012,0,0),A8=owned0.699999988,half23E OR100,C=0,half12=12C,F0=owned0.00999999978. Constants decoded at73EC00/73EBB8/73EBF8. No splash/water name inferred from surface type or effect ID. |
| [o2 0x5DF9F0](../recomp/config/output_ovl/o2/o2_005DF9F0_0x5df9f0.cpp) | `construct_actor_attached_type32_effect_unless_definition_excludes_candidate` | Probable role; mechanics verified | a0 actor,a1 variant. If actor byte3==1,looks up387E98+16*unsigned BBA and skips when entry byte5==1. Otherwise651A30(0,0,1),success child active1,byte1=0,update5EA4C0,render371EF0,type3=32,variant4=input,parent24=actor. No actor null/activity or definition-index bounds check. |
| [o2 0x5DFA90](../recomp/config/output_ovl/o2/o2_005DFA90_0x5dfa90.cpp) | `construct_type17_effect_for_each_fixed_actor_candidate` | Probable role; mechanics verified | Loops unsigned actor index against global word4BAEA0. For each651A30(0,0,1),successful child active1,byte1=0,update5EA970,render371EF0,type3=17,variant4=index,parent24=4A5C30+10E0*index. Allocation failure skips current actor but continues. No actor activity admission or hardcoded four-actor bound. |
| [o2 0x5DFB30](../recomp/config/output_ovl/o2/o2_005DFB30_0x5dfb30.cpp) | `spawn_actor_effect7d_and_up_to_eight_randomized_type24_parts_candidate` | Probable role; full body reviewed | a0 actor. Spawns7D/paletteC/callback6535C0 at actorXYZ+(0,100,0),success C=0,F0=80. Then up to8 allocations652390(7E),each652E20(...,7E,0),type3=24,byte1=0,update6543E0,render371EF0,1F0=0,word200=8193,1F4=392670. Random1 values set X/Z=actor+(low6-32),Y=actorY+120+(low6-32),C4=3+low2,C8=low6/10,C=30+low3,half12=3;D0/F0 use owned73EBB0/73EBA8. First failed part allocation stops further parts;main7D failure does not stop them. |
| [o2 0x5DFD80](../recomp/config/output_ovl/o2/o2_005DFD80_0x5dfd80.cpp) | `spawn_matrix_index_effect54_52_and_ten_randomized_53_parts_candidate` | Probable role; full body reviewed | Low8 a0 selects matrix49FA10+40*index without bound. Transforms owned vector70B890,spawns54/callback655240,then Yoffset=100 spawns52. Adds matrix translation to local position for main1B8930(position,BC). Exactly10 iterations choose random local X0..99,Y0..199,Z-30..69,transform by matrix,spawn53 via6525C0;successful child C=random&F. Continues attempts after allocation failures. No actor/resource lookup from index. |
| [o2 0x5DFF90](../recomp/config/output_ovl/o2/o2_005DFF90_0x5dff90.cpp) | `spawn_effect51_at_resolved_matrix_and_notify_c3_candidate` | Probable role; mechanics verified | a0 passed5817F0,low8 return selects matrix49FA10+40*index. Transforms owned vector70B8A0,spawns51/palette-1/callback655450. On success child1FF=0,half12=original a1;adds matrix translation to local XYZ,main1B8930(position,C3). No success path callback if allocation fails. Original selector/notification semantics unresolved. |

All12 named entries were reviewed and instruction words checked against the
owned o2 blob. Raw constant addresses are retained where not decoded rather
than inventing values. No measured effect count, performance cost, incident
reproduction or verified fix is claimed.
