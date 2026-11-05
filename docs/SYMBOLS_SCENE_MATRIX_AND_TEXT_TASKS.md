# Scene matrix motion and bounded text task lifecycles

Static File #1 US research, 2026-11-04. Five complete original bodies reviewed.
Addresses/offsets/selectors hexadecimal; explicit loop countsdecimal. Original
object subtype names unresolved. No execution, attachment, build, replay or engine
changes. Task registration and valid argument ranges remain separate evidence.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6B6120](../recomp/config/output_ovl/o2/o2_006B6120_0x6b6120.cpp) | `tick_actor_variant_yaw_curve_matrix_task_with_owner_and_binding_cleanup_candidate` | High mechanics | a0taskT,ownerT28. T4=1andownerBA0bit20000 forcesT8=2. States0/1initialize/evaluate,2commit/unbind/delete,3waitforreplacementbindingthenonlydelete;detailbelow. Nullownerandselectoradmissionnotcheckedlocally. No task invocation frequency inferred. |
| [o2 0x6B6530](../recomp/config/output_ovl/o2/o2_006B6530_0x6b6530.cpp) | `tick_actor_variant_local_z_curve_matrix_task_and_cleanup_candidate` | High mechanics | T8=0clearsC/E/10,copiesbase4A3C20+40*T6toT30,sets8=1,falls1.1evaluatescurve7232B0[2*T4+ownerB99],copiesbaseeachstep,rotateslocalZcurvevalueandaddsX/Z,processesonebank2event,advancestime/segment;sentinel->8=2.2mode4=0copiesT30tobase49FA10+40*T6,thenunconditionally5D8300(slot),573740(T). Othersreturn. |
| [o2 0x6B6880](../recomp/config/output_ovl/o2/o2_006B6880_0x6b6880.cpp) | `tick_delayed_spk_text_display_then_cancel_or_delete_task_candidate` | High mechanics; SPK relation verified | Unless4BAE0Anonzeroand4BADEEqual0,6B9FA0(0,T12),clear4BAE0A,T8=2thenimmeddelete.0nonzeroT10predecrementsandreturns;zero6B9F30(T.E,T12,convertfloat70/74toint,T.C,byte5),T8++,falls1.1predecrementsC,post<=0T8++,clears4BAE0A,returns.2deletes573740. NegativeT10isnotnormalizedtounsignedduration. Displayhelperfailureisself-owned. |
| [o2 0x6B6990](../recomp/config/output_ovl/o2/o2_006B6990_0x6b6990.cpp) | `tick_four_mode_axis_rotation_curve_task_with_packed_sound_and_commit_candidate` | High mechanics | T8=0clearsC/E,copiesbase49FA10+40*T6toT30,8=1;curve723320[T4]firsttimehighbits7FFF0000requestbank2event(high16)ifnonzero.1one/twocurveinnersteps;mode4=0/3yaw,othermodepitch,composewithbase,restorebasetranslation,advanceC/E,requestnexttimehigh16soundatsuccessfulboundary. Endsentinel->8=2.2commitT30tobaseonlyif723330[T4]nonzero,thenunbindslot/delete. Fullwordtimesstillusedinarithmetic/comparison;notmaskedbythisbody. |
| [o2 0x6B6CC0](../recomp/config/output_ovl/o2/o2_006B6CC0_0x6b6cc0.cpp) | `tick_delayed_ten_channel_matrix_curve_task_and_conditional_commit_candidate` | High mechanics | T8=0predecrements10;post>=0returns. ExpiredclearsC/E/10,copiesbase49FA10+40*T6toT30,8=1,falls1.1evaluatestenchannelrecordsfromT24 stride8,appliesrotationchannels0..2andXYZoffset3..5,channel9exacttimebank2sound,C++,alltencomplete->8=2.2[T24]+4nonzero commitsT30tobase,thenunbindslot/delete. Six..eightchannelsareevaluatedbutnotusedinsubsequentmatrixcalls. Keysearchisassetbounded,notlocallycountbounded. |

Allmatrixcopyloopsusecount8pairsandperform64bytes. Evaluatingstates of6120,
6530and6990runoneinnerstepwhen3243CC=0andtwowhennonzero;earlyendexitsbefore
thesecondstep. Theseareoriginalgameclocksemantics,notnewdiagnosticchanges.
BaseA=4A3C20+40*slot,baseB=49FA10+40*slot. Matrixbindingtable4A1B70[slot]
andownerpointeraremutableguestwork,notownedstaticassets.

6B6120completephases:

- T8=0:C/E/10=0,copybaseAtoT30,8=1,falls1.
- T8=1:linearanglecurve722FD0[2*T4+ownerB99],segmentE,timeC;convertthrough
  191EF0,buildyawbasis370320,compose191380withbaseA,restorefourtranslation
  floatsfrombaseA. C++ thencheckonebank2eventfrom
  word723118[byte4A1D70[slot]][2*T4+ownerB99],time<newC.
  Eventcursor10!=-1andnonnullrequired;nexttime=-1marks10=-1,else10++.
  AdvancesequenceEwhenkeynexttime<newC. Onnextnexttime=-1,T4=1sets8=3,
  othertypesincrement8(1->2).
- T8=2:modesT4=0/6copyT30tobaseB;unbindonlywhen4A1B70[slot]==T30;
  alwaysdelete573740(T).
- T8=3:whilebindingstillT30return;oncebindingdiffersdeletewithoutunbind.
- Otherstatesreturn. Ownerflag20000preemptionrunsbeforethisdispatch.

6B6530translationtaskusestheanalogoussoundpointerroot723308 indexedby
byte4A1D70[slot],then2*T4+ownerB99. Its eventcheckoccursbeforeC++,whereas6120
checksafterC++;thisone-tickorderingdifferenceisretained. Bothrequest1B8930
withpositionT60,neverclaimactualplayback. No zero-denominator guard is added;
owned reviewed curves and runtime index contracts are distinct.

6B6CC0per-channelwalk: nullpointercountscompleteandkeepsoutput0. Fornonnull
pointerP,whileP.nexttime!=-1andT.C>=nexttime,advancePby8. Finalnexttime=-1
returnsP.valueandcountscomplete;otherwiselinearlyinterpolateP/currentandnext.
Channel9additionallyrequiresT.C==P.timebefore1B8930(T60,int(output9)). Every
callclearsalltenoutputfloatsto0;metadataafterchannel0pointercontrolscommit.
Angles0..2feed190670,thetemporarybasiscomposeswithbaseBthrough191380,
translationXYZ=baseXYZ+channels3..5,translationW=baseW. No scale application
fromchannels6..8isinthisbody.

ConnectedSPKtextadapters6B9F30/6B9FA0arein
[textbankadapters](SYMBOLS_SPK_TEXT_BANK_ADAPTERS.md); earlier
[ten-channelruntime](SYMBOLS_SCENE_TEN_CHANNEL_MATRIX_CURVES.md) providesa
relatedconsumerwithitsowninputcontract. Sharedslotprogramsarein
[matrixevaluation](SYMBOLS_SCENE_MATRIX_PROGRAM_EVALUATION.md).

Full-body owned-word audit: 5 rows, 894 verified instruction words,
zero conflicts, 51 omitted zero/NOP words, zero omitted nonzero words.
