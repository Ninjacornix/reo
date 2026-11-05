# Actor numeric substate admission and periodic state-message gates

Static File #1 US research, 2026-11-04. Three complete original bodies reviewed. Hexadecimal IDs/fields/masks. High mechanics confidence, semantic gate labels probable; original action taxonomy remains unknown. No target execution, builds, attachment or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x664D00](../recomp/config/output_ovl/o2/o2_00664D00_0x664d00.cpp) | `test_actor_action_one_substate_admission_set_candidate` | High mechanics; role probable | Returns1 iffactor8==1 andsubstate9 inexactnumericsetSbelow;else0. Purebyteclassification,notoriginalactionnames. |
| [o2 0x664F60](../recomp/config/output_ovl/o2/o2_00664F60_0x664f60.cpp) | `periodically_serialize_selected_actor_substate_set_candidate` | High mechanics; role probable | Requires signed4BADF8==0,byte4BAE03%1E==0,actor3==byte4BADED,action8==1. SubstatesinsetTbelow call67E230(actor,2),othersno call. No timer/FPSnormalization ordeliverysuccess guarantee. |
| [o2 0x6651F0](../recomp/config/output_ovl/o2/o2_006651F0_0x6651f0.cpp) | `test_actor_action_one_or_two_substate_context_admission_candidate` | High mechanics; role probable | Action1setUbelow->1;action2branchesonlow8a1/a2contextandC7Cresourcequantity;otheraction0. Fullaction2tablebelow. Read-onlyclassification,noresourceconsumption. |

Allsetsbelowareinclusivehexadecimalrangesverifiedfromeachphysicalcomparisonchain,notinferredthroughoneotherfunction:

| Set | Exact admittedaction1substates |
| --- | --- |
| S,664D00 |0..E,24,31,32,4A..55,74..7C,81..83,98..A0,CD,D0,D1. |
| T,664F60 |0..E,24,4A..55,74..7C,81..83,99..A0,CD,D0,D1. Excludes98/31/32fromS. |
| U,6651F0 |1..E,31,32,4A..55,74..7C,81..83,98..A0,A3..AB,CD,D0,D1. Excludes0/24fromS,addsA3..AB. |

6651F0action2letsub=actor9,Q=signedhalf(3C5654+3C*actor.byteC7C):

| Context | Early acceptance / thenfallback |
| --- | --- |
| low8a1==2,low8a2==1 |sub2andQ==0 returns1;othercasesfallback. |
| low8a1==2,low8a2in5/6 |sub9returns1;sub2andQ==0returns1;othercasesfallback. |
| Othercontext |Noearlyacceptance. |

Fallbackacceptssub0/1/5/6/7/A,orsub2withQ==0;other0. Noteearlya2==1sub2Q==0returnsregisterv0whichstillcontains1fromtheprecedingcomparisonsetup,notresourcequantity0. Earlya2in5/6sub9explicit1. Quantity0gatesremainnonpositive-onlyagnostic:negativeQcountsnonzeroandisrejectedforthesub2acceptance. Noactorpool,resourcepointerorquantityboundschecks.

664F60samplingusesglobalbyte4BAE03andmodulo1E(decimal30)withoutclockfrequencyorwall-timeconversion.67E230iscandidate [actor state serialization](SYMBOLS_DISPATCH.md),withitsownauthority/duplicate suppression. Passingthisgateisnotproofthatarecordwassent,accepted,orusedbytheplayerexecutable. No measurednetworkcostorslowdownclaim.

Owned-word audit:3 rows,451 distinct instruction words verified,114 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited.
