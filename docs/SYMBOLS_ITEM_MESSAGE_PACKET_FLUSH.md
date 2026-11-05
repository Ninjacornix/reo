# Item/message sprite packets, queue flush and double buffers

Static File #1 US research, 2026-11-04. Ten full original bodies reviewed,
including packet fields, queue rejection and both buffer-selection paths.
Addresses/offsets are hexadecimal. No game/build/replay/attachment/live-memory
inspection. Guest packet construction, software enqueue and eventual hardware
execution are separate; this note reaches the software queue only.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6DB1C0](../recomp/config/output_ovl/o2/o2_006DB1C0_0x6db1c0.cpp) | `write_item_message_background_uv_scroll_pair_candidate` | Probable role; full body reviewed | a0state,a1output. Usesstate78scroll; writespackedUV64wordsatoutput0and10:(scroll,0),(scroll+200,200). Ifglobal29F9B4==0halvesYextentto100,notXscroll. NoaddressadvanceorDMAcall. |
| [o2 0x6DB220](../recomp/config/output_ovl/o2/o2_006DB220_0x6db220.cpp) | `advance_item_message_background_uv_scroll` | High; full body reviewed | Adds10tostate78,ifresult>200subtracts200once. Exact200retained;negative/out-of-rangeinheritedvaluesnotfullymodulo-normalized. |
| [o2 0x6DB250](../recomp/config/output_ovl/o2/o2_006DB250_0x6db250.cpp) | `tick_item_message_background_and_enqueue_selected_packet_candidate` | Probable role; full body reviewed | Null755D78returns. Invalid324405clears755D80thencommonbufferswap. When755D80nonzeroandmodea0==1returnsearly. Mode1calls6DD650;othermodesdecrementstate68by2with+800underflowwrap,6DC5E0four24bytes733E60records,andpatchselectedstate50pointerUVusingviewportheightmode. If755EC4==1,optionally6DC9F0/6DD650by759C9Estate,always6DC8D0andB220. Ifstate84nonzero,6DC5E0(734140),writesDMAEND F0000000atcurrent34,enqueue18CEF0(low28bitsselectedbuffer20,29F6F0). Commonpathflipsstate30,restores34from28[newindex],clears84. Enqueuereturnisnotchecked;no successorhardwarecompletionclaim. |
| [o2 0x6DB450](../recomp/config/output_ovl/o2/o2_006DB450_0x6db450.cpp) | `enqueue_item_icon_map_packets_then_swap_draw_buffers_candidate` | Probable role; full body reviewed | State755D80. Invalid324405clearsstate0;requiresstate0anddrawcount48nonzerotoemit. Setsrenderparameters63=10000,5F=5,60=0,6C=0,appendsENDtagat34,18CEF0(low28bitsbuffer20[state30],29F6F0),thenparameter6C=1. Alwaysflipsstate30,restorescurrent34from28[newindex],copies48to4C,clears48. Noqueue-resultcheck,waitorpresentationcall. |
| [o2 0x6DB550](../recomp/config/output_ovl/o2/o2_006DB550_0x6db550.cpp) | `enqueue_file_icon_packet_then_swap_second_buffers_candidate` | Probable role; full body reviewed | Invalid324405clears755D80. IfstateD0nonzero,samerenderparameterprefixasB450,ENDatC0,enqueue18CEF0(low28bitsbufferAC[stateBC],29F6F0),6C=1. AlwaysclearsD0,flipsBC,andsetsC0fromB4[newindex]. Doesnotcheckstate0,differentfromB450. |
| [o2 0x6DB760](../recomp/config/output_ovl/o2/o2_006DB760_0x6db760.cpp) | `append_item_icon_texture_upload_and_textured_sprite_packet_candidate` | High packet mechanics; probable role | a0state,a1packet,a2pixelbase,a3UVshift. First1B6FD0uploadsstate4-squarePSM13texturetoVRAMstate38,TBW1. Thenappends90bytesofGSsprite/GIF/DMAfieldsincludingTEX0/UV/XYZ/RGBA,state3CCLUTadvanced4*max(state64,0),scaledviewportorigin58/5C,width50/depth60/color68. Honorsglobal29F9B4verticalhalfmodeandlogicalUVshift. Returnsafterupload+sprite(120byteshexinordinarycase). Nopixelcopy,capacityguardorenqueuehere. |
| [o2 0x6DBA60](../recomp/config/output_ovl/o2/o2_006DBA60_0x6dba60.cpp) | `append_file_icon_128_texture_upload_and_sprite_packet_candidate` | High packet mechanics; probable role | a0state,a1packet,a2pixels,a3CLUTindex. Uploads128x128PSM13toC4,TBW2via1B6FD0;appends90bytespritewithC8+4*max(index,0)CLUT,originalfixedscreenpositions/UV/color80404040anddepthnegative. ScalesXbyviewportwidth/640,halvesYif29F9B4zero. Returnsafterupload+sprite;noactualsubmission. |
| [o2 0x6DBD90](../recomp/config/output_ovl/o2/o2_006DBD90_0x6dbd90.cpp) | `append_map_psm4_texture_upload_reference_candidate` | High packet mechanics; probable role | a0state,a1packet. 1B6FD0(packet,state18pixels,state38VRAM,state4>>6TBW,PSM14,x0,y0,widthstate4,heightstate8). Propagatesendcursor. Noimageformatconversionorallocation. |
| [o2 0x6DBDE0](../recomp/config/output_ovl/o2/o2_006DBDE0_0x6dbde0.cpp) | `append_map_tile_sprite_packet_from_cached_uv_and_draw_state_candidate` | High packet mechanics; probable role | a0state,a1packet;writes90byteswithoutcallsoruploads. UsesUVorigin7C/80,size8C/90,draworigin58/5C,size50/54,depth60,color68;viewportwidth/640Xscaleand29F9B4verticalhalfmode. Applieshalftexel8adjustmentswithunsignedadmission,selectsCLUT=3C+64,buildsTEX0from38,width4>>6,logs84/88,PSM14,andGSspriteUV/XYZ/RGBA. Returnsa1+90. No16-bytecapacitycheck/fencehere. |
| [0x18CEF0](../recomp/config/output/sub_0018CEF0_0x18cef0.cpp) | `enqueue_packet_reference_into_selected_double_bank_queue_candidate` | High queue mechanics; probable role | a0reference,a1queue. Bank=global29FDB4;unsignedpending14[bank]must<=capacity4-1,elsereject-1withnomutation. Success18DCA0(queueC[bank])returnsstoragepointer;increments pending14[bank],writesreferenceatstorage[writeindex1C[bank]],incrementsindexandwrapsatcapacity;clearsqueue34/38,returns0. DoesnotwalkGS/DMAchainorwaitforGPU; bank/capacity/storagevalidityiscallercontract. Capacity0unsignedunderflowbehaviorpreservedwithoutdefectclaim. |

Packet source pixel/CLUT lifetime must cover later consumption of DMA references.
The UI flushers ignore software-queue rejection and continue their original
buffer rotation, but queue saturation or a visible fault is unmeasured. No fix
is made here. The main enqueue body contains no hardware submission, GPU fence
or display pacing observation; those require the queue consumer chain.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Main ELF SHA-256:06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46.
Original words and omitted-NOP gaps verified against owned file-backed images.

Native registration boundary: the original1B6FD0 packet body above does not prove
that it executes in the current native build. The File #1 override table binds
that address to a net_connect replacement; see the
[font/packet override audit](SYMBOLS_FONT_OVERRIDE_BOUNDARY.md). Player-executable
registration identity and actual dispatch still require artifact evidence.
