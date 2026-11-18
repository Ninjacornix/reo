# Actor response score, timer samples, yaw windows and authority dispatch

Static File #1 US research, 2026-11-04. Eight complete original bodies reviewed. Addresses/offsets/masks hexadecimal; distances, counts and explicitly stated arithmetic constants decimal. No execution, attachment, build, replay or engine changes. Literal signed conversions, wrap branches and scope of local guards are retained.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x640190](../recomp/config/output_ovl/o2/o2_00640190_0x640190.cpp) | `accumulate_actor_contact_response_score_from_damage_word_and_difficulty_candidate` | High mechanics; subsystem role probable | Signedword138<decimal41returns0. Elsecategory3==2BandBBA!=0 ->signedhalfC2E+=decimal200;other +=signedhalf72B210+10*(4BAE8A&3)+2*unsignedC28. Storeswrappedhalf,returns1. Readsfullworddamage138unlike6407D0signedhalfsubtract. No scoreclamp/indexadmission. |
| [o2 0x666D00](../recomp/config/output_ovl/o2/o2_00666D00_0x666d00.cpp) | `increment_class_zero_actor_d30_counter_with_ffff_saturation_candidate` | High mechanics; subsystem role probable | Nullactorignored;classbyte2must0. UnsignedhalfD30<FFFFincrements,elseunchanged. Doesnotchangehealth/sourceownership;deathcreditrolecomesfrom6407D0caller. |
| [o2 0x666D40](../recomp/config/output_ovl/o2/o2_00666D40_0x666d40.cpp) | `clear_class_zero_actor_d2c_word_candidate` | High mechanics; subsystem role probable | Nullactorignored;classbyte2must0. WriteswordD2C=0only. D2Cmeaningdiffersacrossactorclasses;notrenamedagenericheightreset. |
| [o2 0x634880](../recomp/config/output_ovl/o2/o2_00634880_0x634880.cpp) | `sample_difficulty_selector_timer_scale_by_actor_parameter_and_global_factor_candidate` | High mechanics; subsystem role probable | a0actor,a1selectorlow8. t=unsigned72BA80+40*(4BAE8A&3)+8*selector+(randomlow16&7). f=(float(t)*decimal60)*(float(unsigned72BD20[actor142])/decimal100). Guestintconversionthen signed16truncation,divideunsigned74F200,truncateagain signed16. Zeroresultbecomes1;negativeresultnotclamped. No selector/142span/u!=0admission. |
| [o2 0x634AB0](../recomp/config/output_ovl/o2/o2_00634AB0_0x634ab0.cpp) | `sample_eight_entry_signed_timer_divide_global_factor_and_avoid_zero_candidate` | High mechanics; subsystem role probable | Ignoresincomingargs; r=low16random&7,signedhalfT=72BC10[2*r]. Q=signed16(T/unsigned74F200);returnsQunless0then1. Noguardforu0andnolowerboundclampfornegatives;ownedeightTpositive. |
| [o2 0x636CF0](../recomp/config/output_ovl/o2/o2_00636CF0_0x636cf0.cpp) | `test_actor_target_yaw_window_with_literal_wrap_side_branch_candidate` | High mechanics; subsystem role probable | a0actor,a1targetXYZ,a2unsignedwindow. Window10000returns1withoutpositionquery. Else376EF0(actor38,target)yawT,actorunsignedyawY;literalpiecewisedifferenceDbelow,return D<=window>>1. Somewrapbranchesuse10000-max(Y,T)withoutaddingmin;do notsilentlyreplacewithshortestarcmath. No targetnullguardonqueriedpath. |
| [o2 0x6A9490](../recomp/config/output_ovl/o2/o2_006A9490_0x6a9490.cpp) | `route_actor_authority_to_category_control_handler_or_local_default_state_candidate` | High mechanics; subsystem role probable | 640640false saves8/9->BE8/BE9,clearsA/B,category4=6 ->2/7,9 ->1/19,other1/0;calls6AA530. Authoritytrue invokesowned719880[category4],passingactor,nocategorybounds/nullhandlercheck. No C36publicationinlocaldefaultbranch. |
| [o2 0x6355D0](../recomp/config/output_ovl/o2/o2_006355D0_0x6355d0.cpp) | `emit_type_one_visual_effect_from_world_position_and_euler_halves_candidate` | High mechanics; subsystem role probable | a0XYZ,a1threeEulerhalves. Initialize64bytesbasis18FDF0,overwriteorientation370320(signedhalves0/2/4),then5DCD70(nullowner,basis,originalXYZ,1). Pointeradmissiondelegated;noactorskeletonneeded. |

636CF0 precise branch arithmetic for unsigned16 actorYawY and targetYawT, afterthefull-window10000earlyreturn:

| Condition | D used for comparison |
| --- | --- |
| Y<T andT-Y<=8000 | T-Y |
| Y<T andT-Y>8000 | 10000-T |
| Y>=T andY-T<=8000 | Y-T |
| Y>=T andY-T>8000 | 10000-Y |

Returns1iffD<=(unsignedwindow>>1). The two wrap cases omit the smaller yaw component. That is observed static arithmetic, not a demonstrated player-facing targeting defect. Valid caller angles/window distribution and a controlled replay would be needed before proposing a behavioral correction. Full-window10000 callers bypass this arithmetic entirely.

634880/634AB0 supplythecounterinitializer6AA530reviewedin [state initialization](SYMBOLS_ACTOR_ACTION_STATE_INITIALIZATION.md). They use guest floating conversion and signed16 wrap before/afterdivision;notarbitraryprecisionmathematicalformulas. Theglobalfactor74F200isreadonlyherenotmodified,enablingnoexperimentalpath. Zero-divisorandselectoradmissionremainunproveninputcontracts.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Full data spans consumed for fixed masked dimensions:

| Owned span | Decoded values / interpretation |
| --- | --- |
| 72B210..72B24F | Fourphysicalrows*8signedhalfwords,shownbelow.64-byteSHA256 `0d33df9629b9324bb4263a1d3eacf73730552b77f820d0b48e5d190549b918ec`. C28mustselectvalidcolumn;no<8checkin640190. |
| 72BC10..72BC1F | Signedhalfwordsdecimal2,2,3,3,4,4,5,6;16-byteSHA256 `88a9f3795c826ad3438aa5c98096df090638ec36e7270ffa3b0ac777a4065ff2`. Fixedrandom&7admissioncoversall8. |
| 72BA80..72BB7F | Fourphysical64-bytegroups;each8selectorrows*8randomcolumns,allbyteslistedbelow.256-byteSHA256 `ec8f36f8ab80dfb06be05cbc9634ec0b69263daca710496aa7ab32db11eb2c1a`. Nofunction-local selector<8guard. |
| 72BD20..72BD2F | Explicitlyinspected16-byteprefix:decimal100,110,thenfourteen100. SHA256 `2fe6982dcb7ac1120f64bffa2c4612290d27f47b4edfd1fe8bfd1a2a3f5f5ae4`. Fullmodifierarraylengthandvalidactor142rangearenotestablishedbythisprefix. |

| Score row | Eight signed entries, decimal |
| --- | --- |
| 0 | 142, 160, 184, 218, 270, 355, 526, 1023 |
| 1 | 127, 142, 160, 184, 218, 270, 355, 526 |
| 2 | 78, 87, 99, 116, 142, 184, 270, 355 |
| 3 | 24, 24, 82, 92, 99, 116, 142, 218 |

| Difficulty row | Selector row0..7 (decimal); eight random bytes each |
| --- | --- |
| 0, selector0 | 0, 0, 0, 0, 0, 0, 0, 0 |
| 0, selector1 | 2, 2, 3, 3, 3, 4, 4, 4 |
| 0, selector2 | 5, 5, 5, 6, 6, 6, 7, 7 |
| 0, selector3 | 8, 8, 8, 9, 9, 9, 10, 10 |
| 0, selector4 | 10, 10, 10, 11, 11, 11, 12, 12 |
| 0, selector5 | 60, 65, 70, 80, 90, 100, 110, 120 |
| 0, selector6 | 120, 130, 140, 145, 150, 160, 170, 180 |
| 0, selector7 | 180, 190, 200, 205, 210, 220, 230, 240 |
| 1, selector0 | 0, 0, 0, 0, 0, 0, 0, 0 |
| 1, selector1 | 1, 1, 1, 2, 2, 2, 3, 3 |
| 1, selector2 | 4, 4, 4, 5, 5, 5, 6, 6 |
| 1, selector3 | 6, 6, 6, 7, 7, 7, 8, 8 |
| 1, selector4 | 8, 8, 8, 9, 9, 9, 10, 10 |
| 1, selector5 | 60, 65, 70, 80, 90, 100, 110, 120 |
| 1, selector6 | 120, 130, 140, 145, 150, 160, 170, 180 |
| 1, selector7 | 180, 190, 200, 205, 210, 220, 230, 240 |
| 2, selector0 | 0, 0, 0, 0, 0, 0, 0, 0 |
| 2, selector1 | 1, 1, 1, 1, 2, 2, 2, 2 |
| 2, selector2 | 2, 2, 3, 3, 4, 4, 5, 5 |
| 2, selector3 | 5, 5, 6, 6, 6, 7, 7, 8 |
| 2, selector4 | 8, 8, 8, 9, 9, 9, 10, 10 |
| 2, selector5 | 60, 65, 70, 80, 90, 100, 110, 120 |
| 2, selector6 | 120, 130, 140, 145, 150, 160, 170, 180 |
| 2, selector7 | 180, 190, 200, 205, 210, 220, 230, 240 |
| 3, selector0 | 0, 0, 0, 0, 0, 0, 0, 0 |
| 3, selector1 | 0, 0, 1, 1, 1, 1, 1, 1 |
| 3, selector2 | 1, 1, 2, 2, 3, 3, 4, 4 |
| 3, selector3 | 4, 4, 4, 4, 5, 5, 5, 5 |
| 3, selector4 | 6, 6, 6, 7, 7, 8, 9, 10 |
| 3, selector5 | 60, 65, 70, 80, 90, 100, 110, 120 |
| 3, selector6 | 120, 130, 140, 145, 150, 160, 170, 180 |
| 3, selector7 | 180, 190, 200, 205, 210, 220, 230, 240 |

Authoritydispatch719880..7198AFcontains12physicalwords: 6A9550,6A9780,6A9AB0,6A8F40,6A9C80,6A9DC0,6A9EE0,6A9F80,6A9550,6AA130,6A9550,0. SHA256 `f2d9d34b89cb5896d9a8bb8e62f715f7d2c8662f0e7ec0ea2524d1d2ca540960`. Slots0/8/Ashare6A9550,slotB=0;thereisnoexplicitcategory<Bandnonnullcheck.0isapointervalue,notfunctioncoverage. Connected6A9F80and6AA130arein [target/region routing](SYMBOLS_ACTOR_TARGET_REGIONS_CONTACT_ROUTING.md);othercategoryhandlersremainindependentbodiestoreview.

[Contact/damage admission](SYMBOLS_ACTOR_CONTACT_DAMAGE_ADMISSION.md)uses640190,666D00/40and636CF0; [effect emission](SYMBOLS_ACTOR_CONTACT_EFFECT_EMISSION.md)uses6355D0adapter. No runtime timing, trigger frequency or original visual/AI state enums are established by these helpers.

Full-body owned-word audit: 8 rows, 253 verified instruction words, zero conflicts, 13 omitted zero/NOP words, zero omitted nonzero words.
