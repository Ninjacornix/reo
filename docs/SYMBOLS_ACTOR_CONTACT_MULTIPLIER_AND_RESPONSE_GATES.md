# Contact double multiplier and actor response gates

Static File #1 US, 2026-11-04. Six complete original o2 bodies, hexadecimal addresses/fields/masks; probability bounds100 and float1/2 decimal. Mechanics high confidence; numeric-state roles remain candidates. No execution, builds, attachment, runtime measurements or engine edits.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6683E0](../recomp/config/output_ovl/o2/o2_006683E0_0x6683e0.cpp) | `roll_actor_contact_double_multiplier_from_packet_probability_and_forced_status_candidate` | High mechanics; role probable | a0actor,a1packet. Unsigned packetD<100 indexesfloat719A6C+44*D;otherwisebase0. Exactbase0 immediately returns1,evenforcedBA4bit800. Nonzero base addsactorBB0,orderedclamps0..100. BA4bit800 forces double;otherwiselow16RNG%100<threshold. Success optional authority1B0340==1 requests controller vibration pattern8,returnsfloat2;failure1. No accumulator/health mutation. |
| [o2 0x668520](../recomp/config/output_ovl/o2/o2_00668520_0x668520.cpp) | `select_actor_directional_response_or_zero_health_motion_and_notify_candidate` | High mechanics; role probable | Bearing fromactor38 towardword(actor34+874).translation,relativeyaw+4000 low16<8000 selects side. Nonzerohealth544 orBA0bit80 ->action3/substate11or10,phases0,667370. Zerohealthwithout80 ->class1special5F6800/54F=A0/action4/phaseA,other65FBA0(actor,A);thenmotion1043/1044 restart or select byside. Always67E230(actor,1). No directhealth decrement. |
| [o2 0x6686C0](../recomp/config/output_ovl/o2/o2_006686C0_0x6686c0.cpp) | `request_off_room_actor_numeric_channel_mode_zero_or_action_two_pair_candidate` | High mechanics; role provisional | Ifactorroom1E2==current3243DC returns. Low8mode0 ->1B90C0(actor,0);mode1 ->1B90C0(actor,1) onlywhenactor8/9==2/2. Othermodes skip. Resident channel helper's precise audio role remains separate evidence;no global process callback. |
| [o2 0x668870](../recomp/config/output_ovl/o2/o2_00668870_0x668870.cpp) | `classify_substate_eighty_bcd_modes_into_one_two_three_candidate` | High mechanics; role provisional | Requiresunsigned54F==80;thenBCD0->1,1->2,2->3,other0. Other54Freturns0. Pure classifier;response labels beyond numeric values unknown. |
| [o2 0x6688D0](../recomp/config/output_ovl/o2/o2_006688D0_0x6688d0.cpp) | `test_actor_inactive_flagged_or_selected_action_one_response_states_candidate` | High mechanics; role provisional | Signedbyte1==0 orBA0&178 ->1. Elseaction8!=1 ->0. Action1 returns1 only54F in8,A,B,D,1A,21,22,23,24,27,2B,30,31;others0. No mutation or inferred original disabled/dead enum. |
| [o2 0x6689B0](../recomp/config/output_ovl/o2/o2_006689B0_0x6689b0.cpp) | `test_actor_category_two_substate_forty_one_candidate` | High mechanics; role provisional | Returns Boolean(B98==2 and54F==41). No class/activity guard. Pure predicate,not animation completion test. |

6683E0 caller is [contact packet scanners](SYMBOLS_ACTOR_CONTACT_PACKET_SCANNERS.md),wherefloat2 scales later numeric response values and can change responsecode3->9. This supports double-contact multiplier;it does not independently recover an original critical-hit name. Baseprobability exactzero bypasses actorBB0 and forcedstatus entirely. Nonzero probability can be negative/tiny/unordered;ordered upper clamp branch sets100 when value is not less than100,then lower clamp floorsnegative0. Random modulo100 comparison remains strict. Forcebit800 bypasses RNG only after nonzero-base admission. Authority gate controls vibration only,not multiplier2 return. [Resident vibration](SYMBOLS_CONTROLLER_VIBRATION_PATTERNS.md) adds saved-option/connection gates.

668520 relative side uses raw low16 bearing difference plus4000,not signed shortest-yaw subtraction. Zerohealth,class1 first calls5F6800(actor,0),sets54F=A0,8=4,9=0,A=A,B=0,667370. Otherclasses65FBA0(actor,A). Motion520==1043 or1044 calls58C300(actor,1) regardless current side;otherwise58C7F0 then5D4CF0(actor,side?1043:1044,f12=0,f13=10 decimal). Surviving/BA080 path sets8=3,9=side?11:10,A/B=0,667370. All exits67E230(actor,1);the helper does not itself install an authority callback or changehealth. Existing [motion response helpers](SYMBOLS_ACTOR_MOTION_RESPONSE_INCLINE.md) and [animation](SYMBOLS_ANIMATION.md) describe the reused animation operations.

Owned data access:719A6C+44*unsignedpacketD for D0..63 hexadecimal admitted by the literal100 decimal bound. These are strided fields,not proof that the entire intervening bytes are a hundred coherent probability records. High indices decode varied/tiny/signed data,so original valid packetID admission remains open. The exact accessed400-byte concatenation is listed below;this is a physical read record,not claimed gameplay probability configuration. Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Strided field concatenation SHA256 `704d75fe870e7e9b10f14bd958e9ee3cba53c935631dade91a7693c05784a37c`. Words are IEEE754 bits, hexadecimal;ordinal is unsigned packetD.

| Ordinal range | Exact words |
| --- | --- |
|0..F|00000000,40400000,40400000,40400000,40000000,40000000,00000000,40000000,40400000,40400000,00000000,00000000,40400000,00000000,40400000,3F800000|
|10..1F|00000000,00000000,00000000,3F800000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,40400000|
|20..2F|40400000,40400000,40400000,40400000,40400000,40400000,40400000,40400000,40400000,00000000,00000000,00000000,40A00000,00000000,00000000,00000000|
|30..3F|00000000,00000000,00000000,40A00000,00000000,40A00000,40400000,00000000,40A00000,00000000,00000000,00000000,00000000,00000000,00000000,00000000|
|40..4F|00000000,41C00000,00000000,10000C00,C1900000,40400000,3F800000,0FA00E10,42480000,0000001E,3F8CCCCD,3F8147AE,00000000,C1F00000,00000000,00000000|
|50..5F|C1F00000,41200000,41C80000,00000000,00E000E0,00000000,80058005,00000000,00000000,00400040,00000000,00800080,00000000,00000000,80038000,01B4016C|
|60..63|00B600B6,0071B040,016C016C,00000000|

Owned-word audit:6 rows,266 distinct instruction words verified,34 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited.
