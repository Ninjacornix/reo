# Model-node position and angle response

Static File #1 US owned o2 review, 2026-11-05. Entire661110..661153,661160..661303 and661310..661397 read, including all delay slots, saturation branches and returns. [Identity](FUNCTION_INDEX.md). No runtimework/build/measurements. Offsets and anglelimitshexadecimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x661110](../recomp/config/output_ovl/o2/o2_00661110_0x661110.cpp) | `copy_indexed_model_node_translation_or_actor_position_candidate` | High complete mechanics | a0actor,a1low8nodeindex,a2outXYZ. Ifword(actor34+820)==0 copiesactor38XYZ;otherwisecopiesXYZatword(actor34+820+4*index)+30. Onlybase820entryisnullchecked;chosenentry/boundsnotchecked. |
| [o2 0x661160](../recomp/config/output_ovl/o2/o2_00661160_0x661160.cpp) | `step_clamped_two_angle_model_node_response_and_build_bf0_matrix_candidate` | High complete mechanics; node/anatomicalnameunknown | a0actor,a1two signedhalves. Clampfirstto[-17FF,17FF],secondto[-1FFF,1FFF],divideangleerrorbyBD2remainingsteps,advanceBD8/BDA,updatefixednode874matrixfromexistingthirdrotation,andderiveBF0. Fullorderbelow. |
| [o2 0x661310](../recomp/config/output_ovl/o2/o2_00661310_0x661310.cpp) | `initialize_actor_angle_response_from_model_node_874_rotation_candidate` | High complete mechanics; anatomicalnameunknown | Convertsnode874floats110/114radianstoBD8/BDAusing65536/owned2pi,+.5/originalCVT.W.S;clearBD4/BD6/BD1/BD2/C30/BE0. DoesnotresetBDC/BDEorbuildmatrices. |

661160 firstclampssignedhalfinput+2 to1FFFmaximumand-1FFFminimum;input+0to17FF/-17FF. BD2==0 isreplacedwith1;negativeBD2isretained. SigneddivisionproducesBD4=(clampedfirst-BD8)/BD2andBD6=(clampedsecond-BDA)/BD2,lowhalfstores;thenBD2--,BD8+=BD4,BDA+=BD6withhalfwrap. CurrentanglescopytoBDC/BDEbeforemodelcalls. No shortest-arc wrapcorrection, delta-time factor or independent targetcapture.

FixedpointerP=word(actor34+874). ConvertP.float118tointegeranglewith65536/binary32(2pi),+.5andoriginalCVT.W.S,signedlow16. Call370320(BD8,BDA,convertedthird,P+40). LetQ=word(actor34+870);call193260(P,Q.float104,Q.float108,Q.float10C). Finally191500(actorBF0,P+40). Exactchildorderandpointerlevelsarepreserved;thesechildcallsarenotrenamedasbonehierarchyorinversematrixoperationswithouttheircontracts. No null/indexadmissionexistsinthisbody.

661310 uses thesameP,nodefloats110/114 andconversion. ConvertedlowhalvesstoreBD8/BDA,thenhalfBD6=0,BD4=0,byteBD1=0,halfBD2=0,halfC30=0,wordBE0=0. Thirdrotation118isnotcapturedhere. No normalizedBooleanreturn.

Owned740470[4]=`db0fc940`,binary32(6.2831854820251465),SHA-256 `12d85026b5109a3119231704608d5991a63d8d397d2867a9fc522305810ddb76`. This is aspecificmodelangleinterpolationcontract;originalnodename,callerangleconvention,validpointerlifetimeandcostremainunresolved. No claimedrootcauseorframeratefix.
