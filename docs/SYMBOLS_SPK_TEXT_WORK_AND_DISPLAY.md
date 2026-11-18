# SPK text work scheduling, byte classification and display state machine

Static File #1 US research, 2026-11-04. Six complete original bodies reviewed.
Addresses/offsets/phaseshex; counts/positionsdecimalwherestated. Originaltext
encodingandUIinteractionnamesunknown. Noexecution,renderbenchmarkorfixes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6B9590](../recomp/config/output_ovl/o2/o2_006B9590_0x6b9590.cpp) | `tick_sixteen_spk_text_records_sort_two_banks_retire_nonleaders_and_render_candidate` | High mechanics; probable role | Global4BADF8/4BAE8D/4BAE89bit4gateentireupdate. Clears2halfcounts74DD30/32,two16wordbanks74DCB0/DCF0. For16records74DD40+98*i,activehalf0nonzeroincrementsagehalf8,9E90(record,signedbyteD)sorts. Freespointedrecordsinbothbankspositions1..15byhalf0=0andzerosbankpointer. Bank0leader97D0(record,0),publishesrecord60/5Cto74E768/774;bank1leader97D0(record,1),publishes74E76A/778. Publishes0whenleaderabsent. No rendercallforretirednonleaders. |
| [o2 0x6B9750](../recomp/config/output_ovl/o2/o2_006B9750_0x6b9750.cpp) | `advance_text_pointer_after_requested_newline_count_or_nul_candidate` | High mechanics; probable role | a0text,a1newlinecount;scansbytesuntilcount==a1orNUL. Newline0Aincrementscount,otherbytesonlyadvancepointer. NULpathreturnspointerafterterminatorbecauseincrementisinbranchdelay. Negativea1cannotmatchnonnegativecountunderordinaryshortstrings;no lengthcap. |
| [o2 0x6B9790](../recomp/config/output_ovl/o2/o2_006B9790_0x6b9790.cpp) | `count_text_bytes_until_nul_cr_or_lf_candidate` | High mechanics; probable role | Countsbytesbefore00/0A/0D,returns32-bitcount. Itdoesnotdecodecharactersoradvancecallerpointer. |
| [o2 0x6B97D0](../recomp/config/output_ovl/o2/o2_006B97D0_0x6b97d0.cpp) | `advance_spk_text_work_fade_reveal_page_hold_and_render_candidate` | High mechanics; probable role | a0record,a1displaybank. Signedhalf2phases0..4,fullmechanicsbelow. Buildsformattedtextinrecord18,uses1B49B0cleanupand1B48E0drawatY140or15A;6DEE20nonzerosuppressesdraw. Originalencoding,bufferlimitsandengine/nativefontboundarynotassumed. No measuredrendercost. |
| [o2 0x6B9E40](../recomp/config/output_ovl/o2/o2_006B9E40_0x6b9e40.cpp) | `classify_text_byte_as_single_unit_outside_multibyte_lead_ranges_candidate` | High mechanics; probable role | Masksbyte;returns0for80..9ForE0..FF,1for00..7ForA0..DF. Numericrangesonly;doesnotvalidatefollowingbyteorassertfullencoding. |
| [o2 0x6B9E90](../recomp/config/output_ovl/o2/o2_006B9E90_0x6b9e90.cpp) | `insert_active_spk_text_record_into_age_sorted_display_bank_candidate` | High mechanics; probable role | a0record,a1bank. Requiresrecordhalf0nonzeroandcount74DD30+2*bank<16decimal. Appendsbank74DCB0+40*bank,theninsertionsortdescending signedagehalf8,stableties. Countsignedhalf,bankboundsunchecked. No renderingorcopyingtextpayload. |

97D0recordW,ownerA=W5C,bankB:

- Phase0setsphase1,countsliteralLFbytesinNULterminatedW14into69,68=0,
  A.1075=W92;fallsphase1.
- Phase1setsA=8,C/B/E0,phase2,hold4=6,clears18size40. Uses9750(W14,68),
  9790toobtainlinebytelength10;X5A=decimal320-5*length. Optional1BA250(A,0,W58)
  accordingtobankandotheractiveactorvoicefield. Clearsmask72size20/62half.
  Itslooprepeatedlyclassifies**thefirstbyteofW14**,incrementingtemporary
  width1or2and62untilwidth>=length;pointerdoesnotadvanceinthatloop.
- If62>=3andA.DB8nonzero,desiredmaskedpositions=rounded(.3000000119*62)
  plusRNG&1unlessW67specialprefix(whichforces0). Rejection-samplesRNG%62,
  skippingindex0andusedpositions,setsmask72[index]=1untildesiredzero.
  Originalreselectionloophasnolocaliterationcap;no observedruntimeclaim.
- Phase2signedbyteApredec;negative->phase3,A0,C80;elseC+=10clamped80.
- Phase3waitsuntilE>=length,thenpredec signedhold4;negative->phase4,A8.
- Phase4predecA;negativeincrements68;if68<69->phase1,elseactivehalf0=0,
  A.10750. ClearsA/C,1B49B0(W18),returns. NonnegativeC-=10withbytewrap
  followedbyC>80->0.
- SharedtailpredecB,negativeclamp0andrequestsrebuild. Always1B49B0(W18).
  Rebuildzeros18size40,copies4bytesW6Aformatprefix. Existingrevealedbytes
  come**fromW14**,not9750'sreturnedlinepointer;W67rawcopyelse1/2byteunits,
  flaggeddoubleunitsreplacedwithowned8163. RevealsonenextunitandadvancesE
  by1/2,66++. DoesnotreplaceW14withline-offsetpointerhere.
- Drawunless6DEE20:1B48E0(X5A,Y=320whenB0else346,1,20,W18,C).
  Ifhold4<30andbankcount>=2andsecondpointeractive,sethold4=0.

Pageoffsetonlyusedforlengthandthefixedfirst-byteclassificationareliteral
sourcecontracts,notcorrectedbehaviororprovenfaults. Buffer18size40andmask72
size20retaincaller/assetbounds. Owned740CD8=.3000000119;723A98->740CC8,
replacementbytes8163. [Fontoverrideboundary](SYMBOLS_FONT_OVERRIDE_BOUNDARY.md)
distinguishesoriginalfontbodiesfromnativebindings;thisnotebookdoesnotclaim
whichparticularplayerbinaryexecuteswhathostimplementation.

Related[sequenceconstruction](SYMBOLS_SPK_SEQUENCE_CONSTRUCTION_AND_DISPATCH.md),
[workpools](SYMBOLS_SCENE_AUXILIARY_WORK_POOLS.md),[textbankadapters](SYMBOLS_SPK_TEXT_BANK_ADAPTERS.md).
