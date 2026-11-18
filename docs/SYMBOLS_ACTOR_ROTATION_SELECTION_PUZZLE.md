# Actor category twelve: two-stage twelve-position rotation selection

Static File #1 US research, 2026-11-04. One complete original body reviewed,
including all fifteen dispatch arms and every pose copy/binding transition.
Addresses/offsets hex unless marked decimal. Selection/puzzle role is a
candidate; the original puzzle, object and scenario names are unknown. No
execution, attachment, build or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6FDE00](../recomp/config/output_ovl/o2/o2_006FDE00_0x6fde00.cpp) | `tick_actor_category_twelve_two_stage_twelve_position_rotation_puzzle_candidate` | High mechanics; probable gameplay role | Signedrecord4 uses743020 fifteen-phase dispatch. Data=record60. Cursorbyte48 wraps0..B androtatesboundmodelbasis by30decimaldegrees*cursor usingguestconversionand370320(angle,0,0),191380. Expectedtwo cursorpositionsaredata40/42;acceptedcount49 andstepindex46determinecompletion. Includes timedinputwindowworddata4=18000decimal,45/60/18/80-call phases,playeraction/resourceflags,andtwofollowupmodelcurvetasks. Fullphasecontractsbelow;no measuredhotspot ordefectclaimed. |

Before dispatch, selectedplayerBA0bit20000 or5BA210nonzero forcesphaseE
ifoldphase<4else7. Separately4B9C10bit80 with4B9A88bit80clear forcesE
ifoldphase<4elseD. The second force can overwrite the first.

| Phase | Observed work |
| --- | --- |
|0|Enter1,selectedplayeraction28,playerAD4=2,5BF0F0(3,FFFF). Seedseight6-byteexpectedpairrecords atdata10: (3,5),(3,5),(A,1),(A,1),(7,8),(7,8),(2,A),(2,A);thirdhalfwordeachretainspriorcontents. Clearcursor48,modeword0,successword8.|
|1|Enter3.4B9C10bit10set ->basemodelIDwordC=4,modeword0=1;clear ->baseID6,mode0.|
|2|Return.|
|3|Enter4;choosepairindex2*4BAE8A+(random(0)&1),copyfirsttwohalvestodata40/42,cursor0,timewindowword4=4650. Resetrecord20identity,copyoriginaltranslationofmappedbaseID+1intorecord50..5C,writeidentity+translation64bytesbacktothatslot. RepeatforbaseIDitself,bindbaseIDtotask20. MessageE5for28,timer4A=45.|
|4|Unsignedhalftimerpostzero enters5.|
|5|Predecrementwordtimewindow;postzero phase7. Elseifstepindex46==2,successonlywhenmodeword0==1 andcorrectcount49==2 ->phase8,signals85/8Fandownerflag47,timer60;otherwisephase7. Ordinaryinput324210bits4/8 decrements/incrementscursorwrapping0..B,audioA9.4BAE90bit20 enters9,comparescurrentexpectedpair[stepindex]withcursor andincrementscorrectcountonequality,thenstepindex++;soundC. Bit10mayoverride7. Buildsrotationfrom30*cursor degreeswithguest65536/360conversion;191380 composesoriginalslotbasisandcopiesslottranslation/W.|
|6|5A5380(record,7,5),5A5060(0,1).|
|7|SetsphaseC. If4B9A84bit100000,ownerflag34clear/35set.|
|8|Timerpostzero entersA,timer18,successword8=1,5BF0F0(4,FFFF).|
|9|Enter4. Ifstepindex==2,timer1andreturn;elsecursor0,commit64-bytetaskposeintooldslot,unbindoldslot,baseID++,copynewslotposeintotask20,bindnewslot,message92for28,timer45.|
|A|Timerpostzero entersB,timer80,allocates6FA0E0 childmappedID0and6FA360 childmappedID2. Allocationfailuredoesnotsuppresssubsequentallocationorparenttimer.|
|B|Timerpostzero entersC,signals23.|
|C|Clearphase/stepindex/correctcount;commit64bytestoslotthenunbind. Ifsuccessword8==1signal87. Selectedresource3/4closes5BF140;playeraction0;clearrecord5B93B0.|
|D|Clearphase/stepindex/correctcount,commit/unbind,closecurrentresource3/4,playeraction0,clearrecord;nosuccess87signal.|
|E|Optionalownerflag34clear/35setwhen4B9A84bit100000,closecurrentresource3/4,playeraction0,clearrecord. Thisarmdoesnotcommit/unbindmodelpose.|

Owned743020 targets6FDEFC,6FDFDC,6FE8C0,6FE014,6FE1EC,6FE20C,
6FE484,6FE4A8,6FE4F0,6FE534,6FE610,6FE680,6FE6B4,6FE77C,6FE82C.
Originalstateadmissionmustexplaininitialstepindex/correctcountandthe
thirdhalfwordofthe6-bytepairs;thisnotebookdoesnotclaimtheyareinvalid.

Related[bound model curves](SYMBOLS_BOUND_MODEL_CURVE_TASKS.md) define
thefollowupmodeltasks;[model-slot binding](SYMBOLS_MODEL_SLOT_STATE.md)
definescopy/bind/unbindbehavior. PosecompositionpreservesWandmustnotbe
replacedusinganassumedhostmatrixconvention.
