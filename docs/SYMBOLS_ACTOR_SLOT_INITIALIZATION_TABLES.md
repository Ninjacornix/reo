# Actor slot initialization, custom statistics and fresh-session modifiers

Update, 2026-11-11: the earlier unavailable-table conclusion below inspected
only the main ELF's empty load segment. The retained owned **o0 overlay**
contains the initialized table at 3898E0: 90 distinct 12-byte entries followed
by the 999 terminal. Table SHA-256 is
`2be3e97fb80da715687f72ad8de2af119a987289cad6a5cd6438b4a934c16f1b`;
o0 SHA-256 is
`bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2`.
`generate_primary_custom_statistics.py` reproduces these initialized bytes,
the owned health/fraction/multiplier tables and 149 admitted substitution masks.
The table order is not sorted. Original669860 uses the terminal's values when
an identity is absent; this is an actual fallback, not an inferred default.
This corrects the initial-data availability claim, without proving that every
possible runtime writer or alternate build preserves the initialized table.

Static File #1 US, 2026-11-04. Four complete original o2 bodies; owned default/category tables decoded. Hexadecimal addresses/fields/masks; health/statistical values decimal. High mechanics confidence; original actor roster/custom-record names unrecovered. No execution, builds, attachment, live data or performance claims.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x669860](../recomp/config/output_ovl/o2/o2_00669860_0x669860.cpp) | `initialize_custom_actor_health_and_modifiers_from_id_lookup_and_owned_bands_candidate` | High mechanics; role probable | BB4zero no-op;elseI=BB4-1. Scans runtime3898E0 twelve-byte rows forhalf0==Ior3E7sentinel,thenconsumesthecurrentrowevenifsentinel. byte3/4/6low3choosehealthrange/fraction/BC0tables;RNGpicksinclusivehealth546,544=guestcvt(max*fraction),BBE=row5,BC4=rowfloat8. Additional716450+14*I suppliesB99/B9A/scales/AA8. Nofoundflag/index/validrangerejection. |
| [o2 0x66A750](../recomp/config/output_ovl/o2/o2_0066A750_0x66a750.cpp) | `initialize_or_restore_actor_slot_models_statistics_collision_programs_and_pose_candidate` | High mechanics; role probable | Usuallyfullinit;global4BADFBnonzeroand4BADF8zerochoosesrestore. Fullinitinstalls66B500/371EF0,modelbank4AE330+1468*ID,class0/categoryB98,partvisibility,custom669860ordefaultstats,savedstateoverride,animationbanksandshape/contacttables. RestoremayreloadD94XYZ/DA0yaw. BothBA4|2/clearC000,CEC/CF0zero,CE8=-1. Fullsource/shape/pointercontractsbelow. |
| [o2 0x66AC50](../recomp/config/output_ovl/o2/o2_0066AC50_0x66ac50.cpp) | `reset_active_actor_progression_and_temporary_modifiers_from_runtime_category_table_candidate` | High mechanics; role probable | Signedactivebyte0nonzero:D28/D2C=-1,BB0=float747400[B98],BAC=0,BB6/BB8=0. When1B02D0()==1calls8120C0(actor). Runtime747400outsideownedo2file;noinventeddefaultvalues. |
| [o2 0x66ACD0](../recomp/config/output_ovl/o2/o2_0066ACD0_0x66acd0.cpp) | `reset_actor_progression_modifiers_for_configured_actor_count_candidate` | High mechanics; role probable | Unsignedi<fullword4BAEA0,actor4A5C30+10E0*i,66AC50. No8slotclampinthiswrapper;activegateiscallee. Count0skipsbodyviaentrytest. Nohealthresetorarrayclear. |

66A750 fullinitialization:preservesoldbyte3ID,setsactive0=1,3/6=ID,B98=low8a1,class2=0,callback14=66B500,queue18=371EF0,model34=4AE330+1468*ID,byte30=B98. Loopsmodelhalf812partcountwritingF4+i=1. Unless54D==1,explicitlyF5=0;whenBB4nonzeroalso32bitvisibilitymaskword716450+14*BB4-4clearscorrespondingF4+i. BB4nonzero669860;elseB99=71ADF0[category],B9A=71ADF8[category],544/546=signedhalf71B020[category],B4/B8/BC=threefloat71AE00[category],AA8=71AE60[category],BC0/BC4=1.

Whenbyte3166A0nonzero,savedrecordstride10CindexedbyactorIDoverwrites544fromsignedhalf31A2DA, B9B=byte31A2DD,C7C=byte31A2FE;5F1F70(actor)â†’CA8. Then65FAB0(actor),B9C=B9B,actorA8/AC/B0=0,animation514/D04=4EA8C0;518/D08=B99!=0?4E6A20:4E8970;51C/D0C=4D7000+1F44*B98.524=5,D8/E4vectors0,F0=1.1A8=word71BD80[category];P=word(word71BDA0[category]),copyfourfloatsPto1AC..1B8and1BC..1C8,CB8=P. AB0=word71B988(71B970).1D8=word(word71BDC0[category]),1DC=actorAEC,D90=0;5D6850(actor),199=low8(6EFAF0(actor)). ThisbyteisnotoverinterpretedasatimebudgetorGPUcategory.

Restorebranch:ifbyte3243D8nonzero,skip5D6850andsavedposecopy. Else5D6850(actor);ifanyD94XYZcomponent!=0orDA0yaw!=0copyD94XYZto38andDA0to92. ExactallzeroXYZ/yawdoesnotrestore;nofreshsaved44copyhere. BothbranchesBA4OR2thenANDFFFF3FFF,CEC/CF0=0,CE8=-1. Callerssupplyslot/categoryadmission;noarbitrarycategoryguardadded.

669860 customlookup3898E0isruntime-loaded. OwnedmainELF`game_data/SLUS_207.65`SHA256`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`hasPT_LOADat370000withfilesz0,so3898E0isnotstaticfile-backedmainbytes. Sentinel3E7terminatessearchbutbodycontinuesusingitsselectors;validID/terminatoradmissionremainsunknown. InclusiveRNGmodulusis(high-low+1),thenhealthmaxnarrows16beforefractionmultiply. Nozero/negative-modulusguard. Custommetadata20-byte rowbase716450+14*I:byte2/3â†’B99/B9A,float8â†’B4/B8/BC,floatCâ†’AA8. CustomtablevalidIDrangeandruntimeheadercontentarenotguessed.

Owned o2base570000SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Span | Exact content | SHA256 |
| --- | --- | --- |
|71AD30..71AD4F|Eight signedhalf pairs decimal(500,800),(900,1200),(1300,1600),(2000,2500),(2600,3000),(3100,3500),(3600,4000),(2000,2999)|`af3bebb9b3a4fdbb73c104cc86381acadcd18d704d353fd460e8d4aeeb2ba493`|
|71AD50..71AD6F|Floatmultipliersdecimal1,.24,0,0,60,50,50,40;literalreadsemanticsretained,noassertionallselectorsareused|`97ec10c165efeb2b438f26fd9a9aa411f7e5f742339f8a35156b15a20982bea9`|
|71ACF0..71AD0F|Floatmultipliersdecimal.6,.7,.9,1,1.1,1,1,1|`0f234957de067dafb986de88ebea1ced3a56b98167e11e911cca707769931477`|
|71ADF0..71ADF7|Signedbytes0,0,0,0,0,1,1,1|`5097197192ab300f177d7cccf23a0e784e1b82fb39d0a6f8301ad055f28cfbfa`|
|71ADF8..71ADFF|Bytes0,0,0,0,1,1,1,1|`5b42971585bb06fed7bdf82a54b1cef17f3b1c92a0c80e316cd871969e1f496b`|
|71AE00..71AE5F|EightXYZfloattriples:eachcomponentsame,valuesdecimal1.05,1.10,1.01,1.02,1.06,1.02,.95,1.01(singleprecisionrounding)|`a316864ff7bff36d6ba79dd3d97289138d749b2f076eef3e668fae70855a50ca`|
|71AE60..71AE7F|Floatvaluesdecimal0,-5,0,0,0,0,0,0|`9ab6d352f1b1579425fa1165222443ca3b395939e9675332fabf6971dc7750df`|
|71B020..71B02F|Signedhealthhalfwordsdecimal2300,3000,1800,2100,2200,2000,1300,1500|`d74ef83988e6a9a1c7f9e19f598ecae2c2dc473b6f215c401381ae85527c48d9`|
|71BD80..71BD9F|1A8pointerwords70C300,70A2B0,70A370,70A430,70A4F0,70C510,70A5B0,70A670|`60856d1445e0863332e4006b7de48bc90f8e0755d4a17ddb85b5e1947abf7419`|
|71BDA0..71BDBF|Pointerwords70C2D0 repeated5,70C4E0 repeated3|`abda7e7e260c36144893dda5c7cfd3553842ac74dff544f3bb2082da2ed61c7d`|
|71BDC0..71BDDF|Pointerwords70C1A0,70A2A0,70A360,70A420,70A4E0,70C3B0,70A5A0,70A660|`dbd4b2f9a5966b3fe53c7ac2cfd494a58cb62830936fac02c8dc8d1f49fcf10c`|

Firstwordof70C2D0=70C1B0,70C4E0=70C3C0;bothpointedfourfloatvalues(0,10,0,50)decimal. Firstwordsof71BDC0pointedheadersinorder:70C130,70A230,70A2F0,70A3B0,70A470,70C340,70A530,70A5F0. Physicalpointersconfirmed;fullcollision-descriptorinterpretationbelongs [actor collision solver](SYMBOLS_ACTOR_COLLISION_SOLVER.md) and [contact packet scans](SYMBOLS_ACTOR_CONTACT_PACKET_SCANNERS.md). Runtimeactor/model/savedrecordtablesarenotfabricatedstaticmeasurements.

Owned-word audit:4 new rows,459 distinct instruction words verified,15 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited. Existing669F30contextisnotincludedintheadditioncount.
