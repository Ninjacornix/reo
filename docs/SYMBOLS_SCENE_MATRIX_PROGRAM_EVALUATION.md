# Scene object matrix program curve evaluation

Static File #1 US research, 2026-11-04. Two complete original bodies reviewed.
Addresses/offsets/selectors hexadecimal; loop capacities/counts decimal. Original
object/interaction names unresolved. No execution, attachment, build or replay.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6B4BA0](../recomp/config/output_ovl/o2/o2_006B4BA0_0x6b4ba0.cpp) | `tick_scene_slot_matrix_curve_and_scheduled_position_sound_candidate` | High mechanics | a0lowbyte selectsworkW=4A3620+60*slot. W4=0returns;1clearsC/E/10,copiesbasematrix49FA10+40*W6toW20,sets4=2,falls2. Runsoneinnerstepwhen3243CC=0,otherwisetwo;eachinterpolatescurve721B40[W9],segmentW.E,timeW.C andappliesW.A transformmodebelow. AdvancesC,checksoneoptional sound event,advancessegment/finishesafterfinalkey. W4otherthan0/1/2returns. |
| [o2 0x6B5050](../recomp/config/output_ovl/o2/o2_006B5050_0x6b5050.cpp) | `evaluate_scene_slot_first_curve_segment_into_matrix_without_advancement_candidate` | High mechanics | a0directworkW. Copiesbasematrix49FA10+40*W6toW20,usesfirsttwo721B40[W9]keyrecords(timeW.C),appliesW.A transformmode. No time/segment/state/sound advancement. Usedaftercommitselection6B5E10. No positivecount or denominatorguardhere. |

Curvekey=8bytes(floatvalue,signedwordtime).6B4BA0usescurrentsegmentat
curve+8*W.E,interpolatesvalue=(nextvalue-currentvalue)*(W.C-currenttime)/
(nexttime-currenttime)+currentvalue. 6B5050usessegment0regardlessW.E.
Neitherclampsinterpolationt. Every64-bytecopyloophasinitialcount8andexact8
iterations;zero-count underflow is not applicable.

| W.A | Complete matrix operation |
| --- | --- |
| 0 | Convertcurveanglethrough191EF0,buildyawbasis370320,zeroW20translationvia18FDF0,compose191380(W20,rotation,basematrix). Restorebasetranslationfourfloats50..5C. |
| 1 | Copybasematrix,transformlocal(curvevalue,0,0)through1919D0,addresultX/ZtobaseX/Z;Ypreserved. |
| 2 | Copybasematrix,addcurvevaluetotranslationY54. |
| 3 | Copybasematrix,transformlocal(0,0,curvevalue),addresultX/ZtobaseX/Z. |
| other | Curvearithmeticstilloccursbutmatrixoperationisskipped. |

Aftereach6B4BA0innerstep,C++ thenoptional721FE0[W9] eventlist:
nonnullandW10!=-1,and eventtime<newC invokes6B60E0(&W50,byte4A1D70[W6],
eventlowhalf). Next eventtime=-1 setsW10=-1;otherwiseW10++. Atmostoneeventper
innerstep,nocatchuploop. Ifcurrentcurve nexttime<newC,W.E++;nextnexttime=-1
clearsW4,setsW3=2,andexitsevenifthesecondstepwouldotherwisebeeligible.

Ownedtableandkeyadmissionauditisin
[scene matrix tables](SYMBOLS_SCENE_MATRIX_PROGRAM_TABLES.md). All64uniqueowned
curvesinthatreviewedtablehave2..27realkeyswithstrictlyincreasingtimesbefore
the-1sentinel. ThisdoesnotvalidatearbitraryruntimeW9/W.E/W.Cvalues.
See[programselection](SYMBOLS_SCENE_MATRIX_PROGRAM_SELECTION.md).

Full-body owned-word audit: 2 rows, 473 verified instruction words,
zero conflicts, 16 omitted zero/NOP words, zero omitted nonzero words.
