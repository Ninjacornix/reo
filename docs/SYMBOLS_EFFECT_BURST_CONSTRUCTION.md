# Effect bursts, scalar variants and actor-node emitters

Static File #1 US research, 2026-11-04. This continues the neighboring
[resource effect constructors](SYMBOLS_RESOURCE_EFFECT_CONSTRUCTORS.md).
Original identities are recorded in [the central index](FUNCTION_INDEX.md).
Only static instruction comments and owned file-backed bytes were inspected;
no game, build, replay, attachment, live-memory inspection or implementation
change was performed. Numeric effect IDs, callbacks and flag masks are retained
without invented visual names or original enum claims.

## Burst selection and count contracts

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5DD9D0](../recomp/config/output_ovl/o2/o2_005DD9D0_0x5dd9d0.cpp) | `spawn_table_selected_actor_effect_and_position_notification_candidate` | Probable role; full body reviewed | a0 actor,a1 optional matrix,a2 mutable XYZ,a3 full selector. Signed upper-bound selector<44 only;negative not rejected. Signed byte70B680+2*selector selects effect,palette7123A0[effect] loaded before effect-1 rejection.2F jitters input X/Z by random low6-32,spawns callback653E80 and sets uniform scale1+(random low5-16)/100,half23E=4.30 first spawns37 and5EAD70(success),then spawns30;others spawn selected ID,including2E. Common successful selected effect calls5EAD70. Builds notification XYZ=matrix translation or0,plus optional XYZ,then1B8D40(actor byte3,XYZ,13). Rejected selector/effect-1 skips notification;allocation failure usually does not. Input XYZ is mutated on2F path. |
| [o2 0x5DDDD0](../recomp/config/output_ovl/o2/o2_005DDDD0_0x5dddd0.cpp) | `spawn_actor_effect82_with_mode_selected_multiplicity_candidate` | Probable role; full body reviewed | a0 actor,a1 full mode. Spawns82/callback653E80 at actorXYZ,palette0,t0=(mode>=2 signed). Success half23E=100,A8=.5 when mode>=2,otherwise1. Exactly mode2 adds two more82 attempts at same XZ,Y+random low5,eachA8=.5/half23E100. Other modes attempt only first. Extra attempts continue despite earlier allocation failure. No actor activity/null admission or mode lower bound. |
| [o2 0x5DDF50](../recomp/config/output_ovl/o2/o2_005DDF50_0x5ddf50.cpp) | `spawn_actor_effect_c6_with_random_mode_count_candidate` | Probable role; full body and original loop words reviewed | a0 actor,a1 mode0/1/2 only,otherwise return. Selects count N:mode0=random low16%3+2;mode1=random lowbit;mode2=random lowbit+1. Tests initial count before emission:zero exits,positive N emits exactly N attempts as detailed below. Each attempt randomizes three local coordinates low10/10 minus owned51.4/51.2/51.2,spawnsC6 using actor matrix50,callback6536D0,paletteFFFF. Success byte4=mode,byte5=current remaining count low8 before decrement. Mode0 initializes velocity from actorD0C trig and random speed1..4,decay(-X/15,-Y/10,-Z/15),byteB=F;other modes zero velocity/decay,byteB=1. Allocation failure still decrements and retries;no failure break. |
| [o2 0x5DE230](../recomp/config/output_ovl/o2/o2_005DE230_0x5de230.cpp) | `tick_signed_byte_counter_and_emit_actor_node_effect69_candidate` | Probable role; full body reviewed | a0 actor,a1 signed-byte counter pointer. Nonnegative counter decrements and returns;negative emits only actor byte3=0/2/16. Those classes choose variant random0..3/4..7/8..B,node11/12/18,lifetime10/12/E respectively. Spawns69 with local vector70B710+12*variant,paletteFFFE,flags1A593,callback577B40. Success byte1=0,variant4,node pointer24=model->820[node],actor28,node index5,yaw92 from70B7A0[variant],half12=lifetime. Both allocation success/failure reset counter to5+(random low16%55),range5..89 decimal. Unsupported class with negative counter leaves it negative. No node bounds or actor activity checks. |
| [o2 0x5DE820](../recomp/config/output_ovl/o2/o2_005DE820_0x5de820.cpp) | `spawn_table_counted_directional_type19_effect_burst_candidate` | Probable role; full body and six records reviewed | a0 XYZ,a1 signed low16 yaw,a2 full table selector,unbounded. Eleven-byte record70B7D0+11*selector supplies effect ID,countBase,countMask,eight parameter bytes. Count=countBase+(random&mask);do-at-least-once loop decrements after each attempt,without failure break. For each success652390/652E20:active1,byte1=0,type3=19,update58F8B0,render371EF0,flags200=8193,1F4=392670,baseXYZ D8,selector32,yaw234. Global scenario3243DA==1 chooses Z jitter and table parameter into4/30;other scenarios choose X jitter,4/30=0 and uniform scale=parameter/10. Selector5 additionally randomized velocities rotated by yaw. Selector4 emits final2D after burst. Owned selectors0..5 counts are positive;table evidence below. |

The initial branch in `0x5DDF50` goes through5DE1F8/5DE1FC to
5DE1E8,skipping the decrement at5DE1E4 on its first test. The delay slot
at5DE200 initializes a stack pointer;it does not decrement the count.

```text
N = mode-selected nonnegative random count
while N != 0:
    emit_attempt()
    N = signed32(N - 1)
```

Mode0 attempts2..4,mode1 attempts0..1,mode2 attempts1..2. Failed allocation
still consumes one bounded attempt. The earlier pre-decrement/underflow
interpretation was incorrect and is withdrawn;these owned paths do not show
a count-underflow stall.

Original callsites5E374C and5E3854,both owned by5E3600,explicitly pass mode1
in their JAL delay slots. Sites5E1E2C/5E2840 pass2;5E4E08 passes0. These
are inspected callsite cross-references,not additional full-function mappings.
The five caller windows contain58 original instruction words,independently
checked against the owned o2 bytes with zero conflicts. Caller execution and
correspondence to a captured incident remain unproven. No runtime timing or
controlled fix/retest was performed. The separate5DE820 loop has no zero-count
admission,but its six owned reviewed records all choose positive counts:

| Selector | Effect ID | Base / random mask | Attempt count |
| --- | --- | --- | --- |
| 0 | C1 | 3 /1 | 3..4 |
| 1 | C1 | 5 /3 | 5..8 |
| 2 | C1 | 7 /3 | 7..10 decimal |
| 3 | 63 | 3 /1 | 3..4 |
| 4 | 63 | 5 /3 | 5..8 |
| 5 | 63 | 12 /0 | Exactly12 decimal |

## Single emitters and actor composites

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5DE3E0](../recomp/config/output_ovl/o2/o2_005DE3E0_0x5de3e0.cpp) | `spawn_scaled_effect_from_signed_halfword_pair_table_candidate` | Probable role; mechanics verified | a0 XYZ,a1 full table index,f12 scale. Reads signed effect/notification halves70B7B8+4*index,70B7BA+4*index;palette7123A0[effect]. Spawns callback653E80. Success ordered scale!=1 (including NaN) writes uniform B4/B8/BC and half23E=4. Signed notification!=-1 calls1B8930(XYZ,notification),regardless allocation success. No table,negative-effect or null-XYZ admission. |
| [o2 0x5DE4C0](../recomp/config/output_ovl/o2/o2_005DE4C0_0x5de4c0.cpp) | `spawn_effect41_at_actor_node_xz_and_actor_height_candidate` | Probable role; mechanics verified | a0 actor without null/node guard. Position X/Z from actor model->848 node translation30/38,Y from actorY3C. Spawns41/palette-1/callback653E80;success half23E=100,A8=owned0.333333403 at73EC08. No owner/resource mutation. |
| [o2 0x5DE540](../recomp/config/output_ovl/o2/o2_005DE540_0x5de540.cpp) | `spawn_actor_node_composite72_73_74_and_type13_parts_candidate` | Probable role; full body reviewed | a0 actor. Node index2 ordinarily;actor byte3=1 uses definition387E90[category]+16*BBA byte5 to chooseE or14. Spawns72/73 on selected node with zero localXYZ;success variants0/1 and652F90(.3,0,0). Builds random-yaw quarter-turn matrix,spawns74 at actorY+3;success variant2,half12=12C,F0=.01,652F90(owned73EBF0,0,0). Then8..11 attempts652390(75),stop first failure;each type3=13,callback578020,render371EF0,source nodeXYZ copied44..4C,random low2 intohalfC andbyte30,flags200=8193,1F4=392670. Finally1B9310(actor,A,0),including partial allocation failure. |
| [o2 0x5DEBF0](../recomp/config/output_ovl/o2/o2_005DEBF0_0x5debf0.cpp) | `spawn_effect62_at_position_with_flag80_candidate` | Confirmed/static mechanics | a0 XYZ ->6525D0(NULL,XYZ,C,62,0,1A193,653E80). Success half23E=80. No profile,room or actor admission. |
| [o2 0x5DEC40](../recomp/config/output_ovl/o2/o2_005DEC40_0x5dec40.cpp) | `spawn_yaw_effect5c_then_selector5_directional_burst_candidate` | Probable role; mechanics verified | a0 XYZ,a1 yaw. Initializes matrix then370220(0,signed low16 yaw,0),spawns5C via6525C0 with palette byte7123FC,flags1A193. Calls5DE820(XYZ,original yaw,5) regardless single-spawn result. No return-success aggregation. Selector5's owned count is12. |
| [o2 0x5DECC0](../recomp/config/output_ovl/o2/o2_005DECC0_0x5decc0.cpp) | `spawn_yaw_effect5c_and_three_pairs_at_rotated_offsets_candidate` | Probable role; full body reviewed | a0 XYZ,a1 yaw,a2 optional full notification ID. Copies three owned vectors70B820,builds yaw matrix370320. Spawns5C/palette7123FC/callback653E80;success half23E=100,A8=.5. Each of3 vectors transforms through1919D0 and adds XYZ,then attempts3C and3D via6525C0 with palette-1,t0=1. Allocation failures do not skip pairs or terminate loop. If notification!=-1 calls1B8930(original XYZ,id). |
| [o2 0x5DEE20](../recomp/config/output_ovl/o2/o2_005DEE20_0x5dee20.cpp) | `spawn_yaw_pair_and_surface_adjusted_effect3e_candidate` | Probable role; full body reviewed | a0 XYZ,a1 yaw,a2 notification. Builds yaw matrix,spawns3C/3D at input withpalette-1. Rotates owned vector70B848,adds X/Z to input while replacingY with inputY,queries616F20(maskFF),setsY=query+1,spawns3E/callback653FA0. Success C=A,half12=384,F0=.01. Notification!=-1 calls1B8930(inputXYZ,id),even if effect allocation failed. No returned surface-type admission. |
| [o2 0x5DEF90](../recomp/config/output_ovl/o2/o2_005DEF90_0x5def90.cpp) | `construct_type1a_effect_copying_parent_matrix_candidate` | Probable role; mechanics verified | a0 parent.652390(12),success active1,category2=6,byte1=0,byte30=0,half204=12,type3=1A,update653CC0,render371EF0,variant4=0,parent24=input. Copies64-byte parent50 matrix tochild50,sets1F0=&matrix50,word200=8193,1F4=392670. Does not call652E20 and no parent-null admission. |
| [o2 0x5DF050](../recomp/config/output_ovl/o2/o2_005DF050_0x5df050.cpp) | `spawn_actor_yaw_effect72_73_and_quarter_turn74_candidate` | Probable role; mechanics verified | a0 actorXYZ+(0,2,0),yaw signed92. Builds370320(0,yaw,0),spawns72/73 withpalette0. Rebuilds370320(4000,yaw,0),spawns74/paletteFF/callback653FA0. Success half12=12C,F0=.01. No per-child variant or652F90 scalar adjustments of5DF150. Failures do not suppress later attempts. |
| [o2 0x5DF150](../recomp/config/output_ovl/o2/o2_005DF150_0x5df150.cpp) | `spawn_actor_linked_effect74_and_scalar_variants72_73_candidate` | Probable role; mechanics verified | a0 actorXYZ+(0,5,0),quarter-turn/yaw matrix. Spawns74/paletteFF/callback653960;success variant4=0,parent24=actor,652F90(owned73EBF0,0,0). Then72/73 at sameXYZ with null matrix,palette0;success variants1/2 and same scalar call. No lifetime reset orF0 write here;separate contracts from5DF050. |

All15 named entries were reviewed within indexed ownership boundaries and their
instruction words checked against the owned o2 blob. Counts describe attempted
allocations,not measured visible objects or frame cost. Table constants/records
were read from owned file-backed data; no original symbol or root-cause proof
is claimed.
