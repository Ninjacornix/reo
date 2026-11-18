# Cutscene light track interpolation and point-light parameter selection

Static File #1 US research, 2026-11-04. Eight complete original bodies reviewed.
Addresses/offsets/selectors hexadecimal; channel counts, ratios and scalar values
decimal. No execution, attachment, build, replay or rendering changes. Light
roles are supported by connected LIG consumers, color fields and render parameter
publication; original record type names remain provisional.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6B31B0](../recomp/config/output_ovl/o2/o2_006B31B0_0x6b31b0.cpp) | `evaluate_cosine_radial_light_weight_times_max_rgb_candidate` | High mechanics; light role supported | a0core,a1position;nullreturns-1,radiuscore30=0returns0. Distance191D10(core+20,position)<=radius givescosine1921A0(ownedpi/2*distance/radius)*max(coreRGB);outsideorderedradiusreturns0. No normalization ofnegative/NaNfields inferred. |
| [o2 0x6B3280](../recomp/config/output_ovl/o2/o2_006B3280_0x6b3280.cpp) | `select_top_two_eligible_lights_for_position_and_publish_parameters_candidate` | High mechanics; type labels unresolved | a0position,a1sector,nonnullpositiononly. Scans64records747540 stride38,activebyte0,positivefloat30,optionalmatchingsectorbyte1(kind0globalallowed),excludestypebyte2=2. Type4weight1;type0radialweightmayoverride0.5 whencore2C>owned.02 andweightpositive;othernonzero typesradialweight. Retainsstrictbesttwoweights,thenpublishesrankedcolors/positionbelow. Allloopentriesandcomparisonpathsreviewed. |
| [o2 0x6B36D0](../recomp/config/output_ovl/o2/o2_006B36D0_0x6b36d0.cpp) | `add_rgb_vectors_and_saturate_each_component_zero_one` | High mechanics | a0out,a1/a2inputs;sumXYZthenclampnegative0,above1to1. Originalorderedcomparesalsochoose1forNaNcomponent. NoWwrite. |
| [o2 0x6B38D0](../recomp/config/output_ovl/o2/o2_006B38D0_0x6b38d0.cpp) | `clear_thirty_two_cutscene_light_start_end_record_pairs` | High mechanics | Clears32eight-bytepairsat38EB20. No allocation or live light data clear. |
| [o2 0x6B3900](../recomp/config/output_ovl/o2/o2_006B3900_0x6b3900.cpp) | `bind_cutscene_light_key_record_and_initialize_normalized_color_core_candidate` | High mechanics | Readsrecordhalf6beforenullguard. Half6=0storesstartpointer38EB20+8*signedlow8group,normalizesRGBbytes24..26/28..2A by255,zeroW,XYZ8..10,core30=R20,core2C=R2C;616F60 determinessector. Copies34bytesto[747430+(group&1F)*4]+4,setsbyte1sector/byte2=2+(Rhalf4&1). Half6nonzeroonlystoresendpointerpair+4. Workpointerarraynotfilebacked. |
| [o2 0x6B3BB0](../recomp/config/output_ovl/o2/o2_006B3BB0_0x6b3bb0.cpp) | `interpolate_cutscene_light_position_colors_radius_and_mirror_kind_two_candidate` | High mechanics | Signedlow8grouprequiresboth38EB20start/endptrsandnonnull747430[group&1F]. Halfstart32=FFFFcopiesstaticposition/colors/radius/extra. Otherwisepositionquadraticcurve371600(P0=start8,P1=start14,P2=start38,t) witht=(38ECA8-starttime2)/(nexttime32-starttime2),zero-durationt1. Updatecolors/radiuspercallusingduration,halvedwhen3243CCnonzero;duration<=1skipincrements. Detailbelow. No wallclockduration or measuredcost. |
| [o2 0x6B4320](../recomp/config/output_ovl/o2/o2_006B4320_0x6b4320.cpp) | `sample_position_sector_then_select_two_light_parameters_candidate` | High mechanics | 616F60(originala0,&sector,FF),then6B3280(position,sector). |
| [o2 0x6B4360](../recomp/config/output_ovl/o2/o2_006B4360_0x6b4360.cpp) | `publish_global_light_parameter_blocks_with_rgb_offsets_candidate` | High mechanics | Half324086nonzerocopies68bytes323ED8 tostack,adds/clampsRGB at+4/+24 against3240A4 via6B36D0,publishes1AF780(5A,stack). Othergates324082/84 publish5B/5C from323E08/323E70. Finally3240BC=FF. No game-clock advancement. |

6B3280 initializes two weights0 and two signedindicesFF fromowned720378.
For each admittedrank, type0/3/4 copiescorecolor0/10 (16byteseach),XYZ20
(12bytes),extra2C directly toparameterrecord323DA0+68*(rank+1) at13C/15C/178
and extra2C into[323DA0+68*rank]+1F0. OtheradmittedtypesdivideweightbymaxRGB,scale
bothRGBs,add/clampagainst3240B0 using6B36D0,copyXYZ/extra. Missingrankclears
parameterrecord+138 length68. Flags324088/8Apublish1AF780 slots5B/5C from
323F40/323FA8;finally3240BC=FF. ThereisnolocalmaxRGBzero guard.

6B3BB0 color/radiusincrementdetails: R=startrecord; nextkeyfieldsatR+30.
DurationD=unsignedhalfR32-unsignedhalfR2;afterpositioncurve,D/=2if3243CCnonzero.
ForD>1,core30+=(R50-R20)/D;coreRGB+=(R54..56-R24..26)/(255*D),
secondaryRGB+=(R58..5A-R28..2A)/(255*D),core2C+=(R5C-R2C)/D.
Theupdatesaccumulateontheexistingcore,notrecomputedlinearcolorsfromt.
Forbyte2=2,copysectorbyte1andcore34bytesintoglobal[747420]first;afterward,
if endrecordsignedbyte1=0,clearonlylocalcore2C. Thatorderispreserved.

Callerproof:[cutscene effect stream](SYMBOLS_CUTSCENE_TRACK_CONSUMERS.md)
5EF640->6B3900 and[playbackorchestrator](SYMBOLS_CUTSCENE_PLAYBACK_ORCHESTRATION.md)
5EE260->6B3BB0foreachgroup. Groupcapacity/streamorderingremaincallercontracts;
pairaddressingusesunmaskedsignedgroupwhilelightworkusesgroup&1F.
See[LIG/FOG](SYMBOLS_LIG_FOG_CONSUMERS_AND_WORK.md) forresourcecontext.

Ownedconstants:720378length2=FFFF,SHA256
`ca2fd00fa001190744c15c317643ab092e7048ce086a243e2be9437c898de1bb`;
740C58float.019999999552965164,SHA256
`8b35fe1a9b331dc0217e0419be35288af59676e9c57022a334110ab0e4799df4`;
740C60float1.5707963705062866,SHA256
`ffe8a9dbe92ed9fa0338c87ae9707c16511c68059475793054e2d246bddead75`.
747420/430/540 areoutsidefile-backedo2bytesandnotdecodedasstaticdata.

Full-body owned-word audit: eight rows, 1073 verified instruction words,
zero conflicts, 34 omitted zero/NOP words, zero omitted nonzero words.
