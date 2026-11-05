# Actor category four: 4x4 XOR-mask puzzle controller

Static File #1 US research, 2026-11-04. One complete original body reviewed,
including all fourteen phase arms and three bounded16-cell scans. Addresses
and offsets hex unless marked decimal. Puzzle identity and original UI name
remain unknown. No execution, build, attachment or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6FBA20](../recomp/config/output_ovl/o2/o2_006FBA20_0x6fba20.cpp) | `tick_actor_category_four_4x4_xor_mask_puzzle_candidate` | High mechanics; probable gameplay role | Signed phase record4 uses owned742F90 fourteen-arm dispatch. Data=record60. A sixteen-bit board at data42 changes by XOR with one of16 move masks chosen by clamped row/column recordA/9 and permutationdata30..3F. BoardFFFF is success. Model slots3..18decimal display each bit through5D8350; selector model is mapped fromdata4C, bound torecord20 pose. Entry may forcephase7 fromselectedplayerBA0bit20000,thenphaseC from4B9C08bit40000000. Full original phase contracts below; no captured incident or measured hotspot identified. |

| Phase | Observed work |
| --- | --- |
|0|Setphase1,byte3=D; initialize eight starting masks indata0..F, sixteen move masks10..2F and identity permutation30..3F;5D8390;setslot1white,slot2gray88888888.|
|1|Setphase2 and slots3..18gray.|
|2|Wait4B9A80bit20000000;thenphase3,counter8=0.|
|3|Choose starting boarddata[2*4BAE8A+(random(0)&1)],storedata42;increment signedcounter8. Beforecounter15,loop16bits and shade setbits by11111111 pluscounter*11111111 through10FAA0;clearbitsgray. Atcounter>=15 enter4.|
|4|Enter5,clear40/42/44;derive selectedmove46/48 frompermutation andmove masks;choose another startingboard bysame two-choice scheme;timerdata54=900 decimal. Paint16boardbitswhite/gray. Mapdata4C via581830,copy64-byte modelpose torecord20,bindslot5D8280.|
|5|Unsigned-half timer54 predecrements;postzero ->phaseB,audioCE,message5A5050(17,28),timer60. OtherwiseboardFFFF ->phase8,slot1gray/slot2white,timer60,audio9E. Otherwise324210 directionbits1/2/4/8 move row/column one direction per invocation,clamp0..3,recalculate move46,soundB onlyadmittedmovement.4BAE90bit20 storesoldboard44,XORsboard42withmove46,phase9,counter8=0,audio9D. Bit10 thenmayoverridephase6/5A5320. Selector outputtranslation=originalslotXYZ +(0,-8*row,-12*column),Wpreserved.|
|6|5A5380(record,7,5),5A5060(46,1). Original phase result/side effects come fromcallee.|
|7|Clearphase4/counter8/row9/columnA;when4B9A80bit20000000,signals1Dclear/1Eset. Remapsdata4C,copy64/bindagain;doesnotunbindinthisbody.|
|8|Predecrementunsigned timer54;postzero ->phaseA and5703E0(5E,1).|
|9|Incrementcounter8;firstseven ticks crossfade each of16bits fromold44 tonew42 withcounter*11111111 and88888888/FFFFFFFF bases;atcounter>=8 phase5.|
|A|5B93B0 clearsrecord110bytes plusmatchingcallbackregistration;thisbodycontainsno5D8300 unbind call.|
|B|Predecrementunsignedtimer54;postzero phase7.|
|C|EnterphaseA,5D8390,slot1gray/slot2white,all16boardcellswhite.|
|D|Setphase7.|

Initial masks are33CC,F99F,9009,4422,300C,0E22,0000,0810.
Move masks are0021,0052,00A4,0048,0212,0525,0A4A,0484,2120,5250,
A4A0,4840,1200,2500,4A00,8400. They are literal sixteen-bit toggles;
calling this a candidate4x4 mask puzzle does not assign an original puzzle name.

Owned742F90 targets6FBAD0,6FBC38,6FBC80,6FBCA4,6FBDC0,6FBF20,
6FC248,6FC26C,6FC310,6FC344,6FC4B8,6FC4C8,6FC4E8,6FC54C.
The guest timer uses unsigned-half wrapping; onlypostzero expires. Input,
model-slot admission and external flag transitions remain separate evidence.
Related[category dispatch](SYMBOLS_ACTOR_AUDIO_CATEGORY_DISPATCH.md) and
[model-slot state](SYMBOLS_MODEL_SLOT_STATE.md).
