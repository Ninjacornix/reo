# Scenario actor node pool, model factory and cutscene update adapter

Static File #1 US research, 2026-11-04. Eight complete original bodies reviewed.
Addresses/offsets/sizeshex; capacity50decimal. Numericactorclass/descriptorroles
keptseparatefromoriginalenemynames. Noexecution,build,attachmentorfixes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6BA260](../recomp/config/output_ovl/o2/o2_006BA260_0x6ba260.cpp) | `reset_fifty_d90_actor_nodes_and_free_pointer_stack_candidate` | High mechanics; probable role | Zeros42EB00size2A620,3B58F80,freecount3B58F0=32hex50decimal,3B59000. Fills50pointers3B5910[i]=42EB00+D90*i. Noresourceheapfreeorconstruction. |
| [o2 0x6BA300](../recomp/config/output_ovl/o2/o2_006BA300_0x6ba300.cpp) | `allocate_zeroed_actor_node_and_insert_head_or_tail_candidate` | High mechanics; probable role | Signedfreecount3B58F0==0returns0;otherwisepop--,pointer3B5910[count],zerosD90,nodebyte6=(ptr-42EB00)/D90. Emptylistsetshead3B58F8/tail3B5900,node1C/200. Nonemptyoriginala0zeroappendstail(prev1C, next20);nonzeroinsertshead. No negativefreecountguardorrollback. |
| [o2 0x6BA410](../recomp/config/output_ovl/o2/o2_006BA410_0x6ba410.cpp) | `walk_actor_list_tail_to_head_and_gate_render_callbacks_candidate` | High mechanics; probable role | Walkstail3B5900via1C. Readsdescriptor387E90[byte3].ptr+10*54D,signedbyteC->5C0870(XYZ,selector). Onlynodebytes0/1nonzero,5C0870signedbyte0,andglobal4B9D12zero invokesnode18(node),sets198=1. Others1980. Descriptortablereadoccursbeforeactivitytest;doesnotinvokeupdatecallback14. |
| [o2 0x6BA4C0](../recomp/config/output_ovl/o2/o2_006BA4C0_0x6ba4c0.cpp) | `mirror_actor_list_position_health_and_target_into_mapped_60_byte_records_candidate` | High mechanics; probable role | 1B0310()==1returns. Walkstailvia1C;BA6nonzeroskip. Usesrecord74F250+60*B98,byte27remapstooutputrecord. XYZconvertedfloat->signedwordto10/14/18;rot90/92signextendedword8/C,health544half1C,BA3byte20,B9Ebyte21,C26byte7;C25==1addsbyte7bit80. Nooutboundscheckorlocalactorstateadvance. |
| [o2 0x6BA5C0](../recomp/config/output_ovl/o2/o2_006BA5C0_0x6ba5c0.cpp) | `allocate_actor_model_node_and_initialize_descriptor_selected_resources_candidate` | High mechanics; probable role | Args a0modelslot,a1class,a2variant,a3descriptorindex;A300(1)allocatesnode,bytes0/10,2=2,3=class,31=slot,BBA=variantlowbyte,54D=descriptorindex. Callback14=6BA880,18=371EF0,model34=459120+1468*slot,F0=1. Descriptor387E90[class].ptr+10*indexfloat8->B4/B8/BC. Calls1D1F40(index,slot,class,variant),1D0920(same,t0=0). Modelpartcount812controlsF4+i=1;CCC..CCFFF,CA0/CA1FF,model1460/1464.377560(node,2,class)optional3777B0(node,slot+4);class1Bregisters573890(node,5D0C90). Returnsnodeevenresourcecallfailure;onlyallocationfailure0. |
| [o2 0x6BA790](../recomp/config/output_ovl/o2/o2_006BA790_0x6ba790.cpp) | `load_descriptor_selected_actor_texture_model_and_sound_resources_candidate` | High mechanics; probable role | Args a0descriptorindex,a1slot,a2class,a3variant,t0flags. Descriptor387E90[lowclass].ptr+10*lowindex;byte1!=FFcalls1D1F40(originalargs),byte0!=FFcalls1D0920(originalargs,t0preserved),byte2!=FFcalls1D35D0(slot,class,variant). Reviewed1D1F40 is a complete no-op on File #1 US. Percomponentchecksindependent,nogeneralrollbackorreturnaggregation. |
| [o2 0x6BA880](../recomp/config/output_ovl/o2/o2_006BA880_0x6ba880.cpp) | `tick_cutscene_owned_actor_script_motion_and_action_23_callbacks_candidate` | High mechanics; probable role | Global4BADF8==0returns;otherwiseonlyactor8==6continues. B38=1setsbyte1=1andB38++;B38=2active;0/otherreturns. B3Cbit2sets9=23,clearbit,A/B/B420. B41zero54A|8. B78nonzero:EulerB6C/B6E,rotates(0,0,B70),addsXYZ,yaw+=B74lowhalf,predecwordB78;exact0zerosB74word/B6C/B6E/B70. Only9==23calls67BFF0,65E3A0,65E4A0. No globalclockadjustment. |
| [o2 0x6BB010](../recomp/config/output_ovl/o2/o2_006BB010_0x6bb010.cpp) | `test_current_session_mode_equals_one_candidate` | High mechanics; probable role | 1B02D0()returncomparedexactly1viaXOR/sltiu;returnsboolean for raw session mode0. Noactorargumentreadorfaultdiagnosis. |

Poolsize50*D90=2A620hex. Linkedlisthead3B58F8/tail3B5900,next20/previous1C.
Onlyallocationpopchecksfreecountexact0;callerpoolintegrityunknown.
Factoryresourcecallargumentsandpartialfailurebehaviorarepreserved;noactual
failedloadwasobserved. Descriptor387E90isnotownedo2filedataandwasnotreadlive.

[1D0920modelconstructor](SYMBOLS_ROOM_AND_EFFECT_MODEL_LOADING.md)retains
itsownrollbackcontract;thisfactorydoesnotcheckitsresult.377560/3777B0
[auxiliarygeometry/no-opmechanics](SYMBOLS_OVERLAY_MATH.md)alreadyreviewed,
withseparateoverlayidentities. [Actorrecordinstallation](SYMBOLS_EMD_ACTOR_RECORD_INSTALLATION.md)
connectsthistabletoconcreteupdatecallbackfamilieswithoutoriginalenumguesses.
