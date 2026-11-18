# Item/message background sprite assembly helpers

Static File #1 US research, 2026-11-04. Seven full original bodies reviewed,
including six-way blend selector and complete UI composition branches.
Addresses/offsets hexadecimal; explicit counts decimal. No game/build/replay,
attachment or live-memory inspection. Screen UI follows item_msg assets and
bounded template records; exact panel/action names are not inferred.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6DC150](../recomp/config/output_ovl/o2/o2_006DC150_0x6dc150.cpp) | `append_item_message_alpha_mode_state_packet_candidate` | High packet mechanics; probable role | a0cursor,a1blendselector,a2headertransition. a2=0emitsfullprefixinclTEST47andtailPRMODE8;a2=1shortprefix,a2=2TEST3400F,a2=3TEST3000F;othermodesnoprefix. Owned742890sixarmsa1=0..5writeALPHA42values80000000A1,8000000068,58,44,54,54 respectively;out-of-rangewritesthe42registerwithoutprecedingvalue. a2=0alsoappends0/8pair. Returnscursor. NoGPUflushorstatecachevalidation. |
| [o2 0x6DC370](../recomp/config/output_ovl/o2/o2_006DC370_0x6dc370.cpp) | `append_item_message_texture_and_clut_registers_candidate` | High packet mechanics; probable role | a0cursor,a1textureVRAM,a2CLUTVRAM,a3width,t0height,t1prefixmode,t2filterbits. Width>200getsTEXlogA;otherwidthandheightderiveintegerlogbyrightshiftpretests(minlog1). t1==1emitsadditionalTEXFLUSH3Fpair;otherwiseonlyGIFprefix. WritesTEX0register6withPSM14,width/64,logsandCLUT;TEX1register14=(t2<<5)\|(t2<<6). Returnsafterprefix+20bytes. Signedwidthdivisionretained;noboundscheck. |
| [o2 0x6DC4D0](../recomp/config/output_ovl/o2/o2_006DC4D0_0x6dc4d0.cpp) | `append_item_message_sprite_geometry_and_optional_uv_pointer_candidate` | High packet mechanics; probable role | a0cursor,a1packedwork,a2optionalUVpointerout. Writes40bytes:GIFspriteheader,PRIM156,RGBAwork24,UVoriginwork10/14+8,XYZwork0/4+depth20,andUVend18/1C+8/XYZ8/C+depth20. Ifpointeroutnonnullstorescursor+20beforewritingUV. Returnscursor+40. Doesnotreadtexturepixelsorenqueue. |
| [o2 0x6DC5B0](../recomp/config/output_ovl/o2/o2_006DC5B0_0x6dc5b0.cpp) | `patch_guest_dma_and_direct_qword_count_header` | High; full body reviewed | Writes16byteheaderat a0:word0=10000000\|a1,word4/8=0,wordC=51000000\|a1. Preservesinheritedv0ratherthanreturningnewpointer;callersrelyonthis. Noqwordcountmask/rangevalidation. |
| [o2 0x6DC5E0](../recomp/config/output_ovl/o2/o2_006DC5E0_0x6dc5e0.cpp) | `append_background_template_sprite_with_cached_alpha_transition_candidate` | Probable role; full body reviewed | a036bytetemplate;global755D78cache. Signedbyte18selects16bytetexturedescriptor733DC0;19CLUTindex. ChoosesC150headertransitionfromstate84firstdrawandlast1E/1Fvsinput1E/1F;storesnewcachedbytes. C370selectstextureVRAM+descriptorC,CLUTVRAM+index,width4,height8,mode1D. TransformsinputXY/sizeusingviewportXscale/640andGSoffsets;UV8/A/C/Eto16subpixelunits,widthendpointusesC-1. Packsdepth10/color14,optionalXUVflips1A;optionaltemplate20pointerbankedbystate30receivesUVaddressviaC4D0. PatchesDIRECTcountviaC5B0,current34=end,increments84. Nocache-null/descriptorbounds/packetcapacityguardhere. |
| [o2 0x6DC8D0](../recomp/config/output_ovl/o2/o2_006DC8D0_0x6dc8d0.cpp) | `append_three_background_tab_templates_and_selected_scroll_layer_candidate` | Probable role; full body reviewed | Copies36bytetemplate7340A4,emitsthreetabsatX=half733098[i]+7,Y=28. Copies7340C8,selectsXbyslot759C9E,setsUVpointeroutto cache58,emits,thenB1C0patchesUVforselectedbuffer. Noindexclampforselectedslot. |
| [o2 0x6DC9F0](../recomp/config/output_ovl/o2/o2_006DC9F0_0x6dc9f0.cpp) | `compose_background_panels_player_slots_and_selection_layers_candidate` | Probable role; full body reviewed | Local755EAD[4BADED]>=4returns. Advancescache7CXby24,wrapsat640to-48. Emits7templates733EF0withlocalvariantUV/colorchanges;oneupdates15CLUTRGBentriespreservingalpha. Emitsbase733FF0templateplusplayerstatuscolors,threenonFFplayer slotsfrom755770+14,owned733180offsetsandconditionalB98==6extra. Handleslocalstate755E6C/72/78/80/81/82/83viaselectedpositiontables733720/30,scrollUVpointerpatches,andoptionalFFterminatedselectionlist732AF0[755E81]. Finaltemplates7340EC/4110alwaysafteradmission. Allnumericbranchesreviewed;originalpanelnamesandmalformedindexbehaviorunassigned. |

Original word evidence distinguishes packet append from queue submission.
Descriptor arguments and cached transitions remain numeric where exact enum
meaning is unknown. No runtime cost or slowdown attribution is claimed.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
