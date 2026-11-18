# SPK/SPM sequence construction and trigger dispatch

Static File #1 US research, 2026-11-04. Six complete original bodies reviewed.
Addresses/offsets/IDshex; explicitly stated counts/distancesdecimal. Textroleis
supportedbypointers,ownedprefix/formatbytesanddownstreamtextwork;original
command/interactionnamesunknown. No execution,benchmark,replayorfixes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6B7930](../recomp/config/output_ovl/o2/o2_006B7930_0x6b7930.cpp) | `construct_spk_spm_text_sequence_work_record_for_actor_candidate` | High mechanics; probable role | Gatesglobal4BADF8,4BAE8D,4BAE89bit4,actorbyte0;665DC0(actor,selectedXYZ)<=decimal800;different1E2alsoabsY<=200. ResolvesSPKbank1indexDB4-1byB98whenbyte2=0elsecommon8;nullreturns0. Allocates7890record,thenSPMbase324438+5C000+5C00*actor3orcommon73000;usesSPKhalf2nestedSPMoffsets,textpointerandmetadata. Initializesworkdetailsbelow,processeseightflaghalveswithA230;return0iftextbeginsownedbytes8169,else1. No actualtextdrawinthisbody. |
| [o2 0x6B7D40](../recomp/config/output_ovl/o2/o2_006B7D40_0x6b7d40.cpp) | `translate_actor_trigger_input_to_spk_variant_byte_candidate` | High mechanics; probable role | 6DEE20nonzero->0. Word324210bit2000->DA8=1,selector4;elsemaskF00000nonzero->DA8=1,selector((signed32423A+2000)&FFFF)>>14. IfDA8nonzero,word324218bit80chooses723A78else723A70,storesDA9. Normalbankalso1B02D0()==1andsignedDA9==82clearsDA9/return0;comparisonliteralretained. No newtriggerandpreexistingDA8usesselectorS0notlocallyassigned;callercontractunknown. |
| [o2 0x6B7E40](../recomp/config/output_ovl/o2/o2_006B7E40_0x6b7e40.cpp) | `dispatch_spk_actor_triggers_roster_updates_and_text_sequence_pools_candidate` | High mechanics; probable role | 1B02D0mode0processesselectedactor7D40;zeroreturnand4BAE90bit100forcesDA8=1/DA90. Othermodesloopunsigned4BAEA0actorpool:byte3=0inputpath,otherbyte1098maps723A80[request-1],negativeDA9lowbytecancels,clearsrequest. Calls90A0. Mode1allroster8130+8440;othermodesselected8130thenall8440. Linkedlist3B59F0/1Ceach8130+8440. Finally9590,80A0. No loopoffUIthreadguaranteeorcostmeasurement. |
| [o2 0x6B80A0](../recomp/config/output_ovl/o2/o2_006B80A0_0x6b80a0.cpp) | `increment_or_clear_512_auxiliary_bit_hold_counters_candidate` | High mechanics; probable role | For512decimalindices:bitset74E828[index/32]bitindex%32 ->incrementword74E868+4*index;clearbit->counter0. No elapsedtime/frequencyconversion,blockingorinputpoll. |
| [o2 0x6B8130](../recomp/config/output_ovl/o2/o2_006B8130_0x6b8130.cpp) | `evaluate_actor_spk_trigger_candidates_and_pending_categories_candidate` | High mechanics; probable role | Byte2=0selectedactor:4BAE77nonzeroearlyreturn;predecDB0,positiveclearsDA8/DA9andreturns,elseDB0=0. Allbyte2=0buildDAC..DAFFFthenrosterB98exceptown. Activeactor:predecDBC/DBEonlywhennonzero,exactzeroclearassociatedDC0/DAA/DC5orDC1;DC8nonzeroDD0++. Modesgateoffselectedactor. DA8required;6DEE20nonzeroclearsDA8/9. Otherwise88E0,zeroeightpendingwords74E784..7A0,DC00,DC81,DCC=DD0,DD00,8F60. Nonzeroreturnskipsrest. Otherwiseoptionalselected92C0,8BF0;nonzeroskipsrest;thenfixedscanbelow,8650;finallyDA80. |
| [o2 0x6B8440](../recomp/config/output_ovl/o2/o2_006B8440_0x6b8440.cpp) | `consume_actor_spk_pending_trigger_and_emit_optional_state_message_candidate` | High mechanics; probable role | DC0nonzero:if2setsDC11;8640(actor,2)nop,7930(actor). Byte2=0andactor3selectedandconstructorreturnnonzero ->DB0=30if3243CC!=0else60decimal,67E230(actor,B). AllDC0nonzeroDAA=1,DC0=0. DC0zero->8640(actor,1). Constructorreturn0doesnotproveallocationfailed;specialtextprefixalso0. |

7930workW,actorA,SPKrecordS,SPMbaseM:

- A.DBC,W4,W6=S.signedhalf4. FollowM+4+8*S.unsignedhalf2->relativeword,
  thenrecordrelativeword0->textbase;W14=textbase+8.
- A.DA9nonzero->W8=270F,W92=(DA9&7F)+(DA9bit80?9:1);zero->W92=1.
- W60=lowhalfA.DB4,W D=1onlyA.byte2=0andA.byte3selected,else0;
  W5C=A,W58=S.half6,W67=0(initialFFatW58isoverwritten).
- Textfirsttwosignedbytesmatchowned740CB8=`81 69` ->W67=1,returnvalue0;
  otherwise1. Copiesowned740CC0string`<c7>`intoW6A. Changesitsbyte2to
  B99?3C:3B,orselectedactorB99?3A:39. NoUnicodeororiginalspeakeridentityassumed.
- EightSPMhalvesatM+M.word0+10*S.half2:FFFFskip;otherA230(value&7FFF,
  highbit?1:0),whichsets/clearsauxiliaryworkbits. All8visited,noendbreak.

8130fixedcandidatepassindex0..4999foractorbankor0..5999forcommon:
7520(selector,index,bank0)everyiteration;nullrecordsskippedwithoutendingloop.
Requiresrecordhalf0>=0,signedbyte2<3,andcategorypendingword74E784+4*type==0,
then9330(actor,record). Signednegativetypeisnotexplicitlyrejectedhere.
The5000/6000boundsarestaticworklimits,notmeasuredtimeorprovenhotspots.

Ownedinputbanks723A70firstfivebytes[1,4,3,2,7],723A78[81,80,5,82,6];
723A80firsttenhalves[4,1,2,3,-1,-1,-1,-1,5,6],nofullrequestrangeinferred.
DA9signedcomparisonwith82andpreexistingDA8selectorcontractarepreserved
withoutassertingtheyarereproduceddefects. Related[SPKtables](SYMBOLS_SPK_SPM_TABLE_CONSUMERS.md),
[workpool](SYMBOLS_SCENE_AUXILIARY_WORK_POOLS.md),[candidatepolicy](SYMBOLS_SPK_CANDIDATE_POLICY.md).
