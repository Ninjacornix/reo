# Actor categories ten and eleven: scene-model reveal sequences

Static File #1 US research, 2026-11-04. Two complete original bodies
reviewed, including eleven owned phase arms and all literal slot-ID writes.
Addresses/offsets hex unless marked decimal. Reveal/sequence roles are
candidates; original scenario or object identity is unknown. No execution,
attachment, build or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6FD140](../recomp/config/output_ovl/o2/o2_006FD140_0x6fd140.cpp) | `tick_actor_category_ten_three_condition_model_reveal_sequence_candidate` | High mechanics; probable role | Signedrecord4 dispatch742FF0 phases0..A. Model IDs are mapped through581830 andvisibilitybit80 at49F790[slot] is set/cleared; worddata4C is temporary mappedslot storage. Threeconditiongroups use4B9C14bits20/40/80 versus4B9C04bits200/400/800, reveal IDs3/2/1, signalA5/A6/A7 and audioB0 oncurrent-condition paths. Allphase/timer/allocation mechanics are detailed below. No guessed original object names or runtime cost. |
| [o2 0x6FDCE0](../recomp/config/output_ovl/o2/o2_006FDCE0_0x6fdce0.cpp) | `tick_actor_category_eleven_paired_vertical_curve_and_scene_flag_candidate` | High mechanics; probable role | Phase0 waits4B9C14bit2000,setsphase1,allocates two6F9EB0 children withmappedmodelIDsB/D,storespointersdata18/1C,incrementseachsuccessdata28;then overwritesdata28with1E regardlessallocationcounts. Phase1predecrementsunsignedbytedata28;postzero incrementsphase2. Phase2signals5703E0(83,1),5B93B0 clearsrecord. Otherphasesreturn. Allocation failures do notsuppressoriginaltimerstart;childownershipbeyondparentpointerrequirescallercontext. |

For category10, data=record60 and timer=data4A (unsigned half). All
predecrement waits compare the narrowed postvalue with zero. No unit conversion
or assumption that callbacks finish before the timer is inferred.

| Phase | Observed behavior |
| --- | --- |
|0|Initiallysetsbit80formappedID7. If4B9C10bit2set,choosephase6when4B9C04bit2000else3;visibilityset IDs1,2,3,4,6,8,9,A,B,C,clear5,7,D. Otherwisephase1,set1,2,3,5,6,9,B,D,clear4,7,8,A,C.|
|1|Initialize two localcounts to0eachinvocation. For groups(slot3/2/1),4B9C14completionbit20/40/80 incrementsbothcounts andreveals slot. Else4B9C04currentbit200/400/800 reveals slot,audioB0,signalsA5/A6/A7,andcount1increments onlywhen corresponding4B9A88bit40000/80000/100000 ispresent. If4B9C10bit2set,phase2withnofreshtimerassignmentonthispath. Elsecount1==3 enters2,5BF0F0(3,FFFF),timer15,hides1/2/3/4,reveals5. Elsecounts differ enters5,5BF0F0(3,FFFF),timer30. Equalincompletecountsretainphase1.|
|2|Timerpostzero enters3.|
|3|Enter4,timer120. Allocate6F99E0 childmappedID5;successaudioC0. Allocate6F9C80 childmappedIDC,variantbyte4=0. Bothnullresultsare toleratedbythisbody.|
|4|Timerpostzero entersA,signals81.|
|5|Timerpostzero enters1,5BF140.|
|6|Wait4B9C10bit4;thenphase7 andsamevisibilitypatternasphase0'sbit2setpath.|
|7|Enter8,timer300. Allocate6F99E0 childmappedID5,audioC0onsuccess;6F9C80 childmappedIDD,variantbyte4=1.|
|8|Timerpostzero enters9,clearsbit80formappedIDs9/B.|
|9/A|Returnwithoutadditionalwork.|

Owned742FF0 targets6FD19C,6FD5AC,6FD918,6FD938,6FD9A0,6FD9D4,
6FDA00,6FDBF4,6FDC60,6FDCC0,6FDCC0. Counts and branch entry points
were reviewed before assigning the wait transitions.

The category10 allocation sites admit6F9C80 curve selectors0/1 and therefore
connect the two owned pointer entries documented in
[bound model curves](SYMBOLS_BOUND_MODEL_CURVE_TASKS.md). This is static
caller admission; no player execution or incident is claimed.
