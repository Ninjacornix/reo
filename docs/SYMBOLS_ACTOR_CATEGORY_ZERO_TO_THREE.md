# Actor category zero through three controllers and cleanup primitives

Static File #1 US research, 2026-11-04. Eight complete original bodies
reviewed. Addresses/offsets hex unless marked decimal. These are guest
callback/actor records. No game, build, attachment, replay or engine changes.
Original scene flag and category names are unknown; semantic labels are
candidates from the full bodies and owned dispatch data.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5B93B0](../recomp/config/output_ovl/o2/o2_005B93B0_0x5b93b0.cpp) | `clear_guest_actor_callback_record_and_matching_render_registration_candidate` | High mechanics; probable role | a0record. If3B64B4==record,5BAE30(0);else if3B64C0==record,5BAE30(1). Then107C68(record,0,110) zeros exactly110 bytes. No heap-free call in this body; clearing a guest record must not be described as host task/thread termination. |
| [o2 0x5BAE30](../recomp/config/output_ovl/o2/o2_005BAE30_0x5bae30.cpp) | `remove_callback_registration_and_clear_twelve_byte_registration_slot` | High mechanics | a0index addresses3B64B0+12*index. Nonzero pointer atslot8 passedto1AFA70 toremove callback,then107C68(slot,0,C). No independent index bound check; record0..1 callers observed in5B93B0. |
| [o2 0x5DCB60](../recomp/config/output_ovl/o2/o2_005DCB60_0x5dcb60.cpp) | `clear_indexed_upper_scene_render_mask_bit_candidate` | High bit mechanics; role tentative | 3C2748 &= ~(1000 << ((a0+10)&1F)) using guest32-bit variable-shift semantics. Since seed isbit12, many shift counts yieldzero; do not rewrite as1<<(index+28) with modulo after the whole sum. No bounds check or other side effect. |
| [o2 0x5DCB90](../recomp/config/output_ovl/o2/o2_005DCB90_0x5dcb90.cpp) | `set_indexed_upper_scene_render_mask_bit_candidate` | High bit mechanics; role tentative | 3C2748 |= 1000 << ((a0+10)&1F), guest32-bit variable shift. Exact pair of5DCB60; original index and render-mask semantics require caller evidence. |
| [o2 0x6FAC80](../recomp/config/output_ovl/o2/o2_006FAC80_0x6fac80.cpp) | `tick_actor_category_zero_paired_model_curve_sequence_candidate` | High mechanics; probable role | Signedrecord4 phase0..6 dispatch742F30. Phase0 sets1,clears60+1C/1D (created/completed counters),pretestedtwo allocations573890(parent,6F96D0);success maps modelslot581830((word68+i)&FF),setschild12=120 if3243CCnonzero else240,storeschild74/78,countscreated;failurestoresnull. Signals5705F0(word64,1,byte100),byte3=6. Phase1 whencompleted==created enters2,sets mask5DCB90(word6C),incrementscompleted fornullchildslots. Phase2 requirescompleted==2*created,enters3,clearsmask5DCB60,againcountsnullslots. Phase3 completed>=3*created enters4,storeslowbyte600 or1200 intobyte9. Phase4 tests old signedbyte9==0 toenter5,then decrementsbyte9 modulo256. Phase5 signalsclear and5B93B0;phase6 firstclearsmask then samecleanup. Common cancellation tests4B9A80 bitword70;setclearsmask/event,setsnon-nullchildphase8=63,clearschildslots,clearsrecord. Allocation failures and timer truncation retained as literal contracts, without claiming a reproduced defect. |
| [o2 0x6FAFE0](../recomp/config/output_ovl/o2/o2_006FAFE0_0x6fafe0.cpp) | `tick_actor_category_one_unlocked_room_destination_menu_candidate` | High mechanics; probable role | Everycall4BAE89=7;selectedplayer4A5C30+10E0*4BADED. Nonzero signedphase4 withstoredroom10!=3243DC clearsrecord. Nine-phase742F60:0 searches7 roomrows73CA00 (index7 stillusedifnone),closesgameplayUI6E1430,gets581AF0(rowbyte2),alignsplayer669700(record4C),570CC0(player,29),5BF0F0(73C9F8[word60],FFFE),phase1/returnphase5=3,C/E0,savesroom,byte3=8,5D8390;scansunlockbits10..16,storesunlockednoncurrentrowIDs in74+E,grayslocked slots5D8350;thenfalls into phase1prompt. Phase1 rendersmessageE andincrementsC;released inputlowF orC>=1F entersphase3,C0. Phase3 adjusts/clampsselectionC in0..E using324228bits4/8,soundB onchange;4BAE90bit20 selectsphase4 or5(lastcancelchoice),bit10 phase5. Builds local text from<p1>,73CA30 messageIDs plusfinalcancel,marks selectedbyte2 withASCII1,5A5180 display. Phase4 rewritescurrent scene record44/48 to chosenroom/spawn,34=player,3E=31,signalsword68,5C1710,audio87,phase7. Phase5 restoresplayer sceneXYZ/yaw/ACC,570CC0(1D),AEA0,669F10,3DDDB6=0,570370(word64),phase6. Phase6 waits onlywhileplayer8/9=1/61,elseclears. Phase7returns. Phase8setsphase2,byte3=8;phase2restoresreturnphase,refreshesgrayingwhen3,and570CC0(29)unlessreturnphase6. Original label text and gameplay meaning beyond room destination selection remain unconfirmed. |
| [o2 0x6FB7A0](../recomp/config/output_ovl/o2/o2_006FB7A0_0x6fb7a0.cpp) | `clear_actor_category_two_record_adapter` | High routing | Tailjumps5B93B0 with originala0; no independent work or added lifetime semantics. |
| [o2 0x6FB7B0](../recomp/config/output_ovl/o2/o2_006FB7B0_0x6fb7b0.cpp) | `tick_actor_category_three_paired_model_slot_visibility_blink_candidate` | High mechanics; probable role | a0record,datarecord60. Signedphase4=0 checks4B9C00bit8000. Clearbit: forcountword68 maps two IDs(word6C+2*i and+1) through581830,ORs49F790[mapped]bit80,returnsphase0unchanged. Setbit:clearbit80 onbothmappedslots,seeds signedhalfdata70+6*i=randomlow3,setsphase1. Phase1 mapssecondofeachpair;counter0resets8,1..4clearsvisibilitybit80anddecrements,5..8setsbit80anddecrements,>=9returnswithoutdecrement forthatslot (negativecounterfollows<5branch). Counts pretested usingunsignedword68;caller bounds unknown. Otherphasesreturn. |

Owned742F30 phase targets are6FACD0,6FAD9C,6FAE08,6FAE78,6FAEB4,
6FAED4,6FAEF4. Owned742F60 phase targets are6FB084,6FB218,6FB6B0,
6FB280,6FB470,6FB570,6FB668,6FB784,6FB69C. These are internal arm
addresses and are not separately counted as original function entries.

Seven73CA00 rows `(room,spawn,baseSlot)` are (24,0,2),(24,0,2),
(4C,0,3),(24,0,2),(4E,0,7),(24,0,2),(5E,0,2). The duplicate room24
rows and failed-search use ofindex7 are retained as source/asset admission
questions. Owned73C9F8 bytes7,7,4,7,A,7,2,0 select sequence IDs;
73CA30 bytes1B,1C,F,10,11,12,13,15 select localized labels.
The destination menu builds text in its local buffer without independently
checking each appended label length; no overflowing player asset is claimed.

Paired child tasks and original counter phases are detailed in
[bound model curves](SYMBOLS_BOUND_MODEL_CURVE_TASKS.md); category-table
selection is in[audio/category dispatch](SYMBOLS_ACTOR_AUDIO_CATEGORY_DISPATCH.md).
No measured root cause or engine optimization follows from static coverage.
