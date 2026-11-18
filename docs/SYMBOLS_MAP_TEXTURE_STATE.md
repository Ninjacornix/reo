# Map texture, view state and icon upload adapters

Static File #1 US research, 2026-11-04. Eleven complete original bodies reviewed.
Addresses/offsets are hexadecimal; counts decimal when explicitly stated. No
game/build/replay/attachment/live-memory inspection. Map role follows owned
map%03de.dat resources and the linked UI cache loader; original type names unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6D9110](../recomp/config/output_ovl/o2/o2_006D9110_0x6d9110.cpp) | `initialize_map_texture_three_palettes_and_double_upload_buffers_candidate` | Probable role; full body reviewed | a1scratchpalette,a2VRAMbase,a3mapwork. Publisheswork35/34counts,38tiletable,3Cviewtable;dimensionhalves40/42times256to755D84/88. Mapsdimension100/200/300/400toTEXlog8/9/A/A,othersto8. Pixelbase=work44,CLUTbase=a1,CLUTcount3,workcount80. Writes3*16RGBAcolorsfrom733C40;palette1/2entry1special(0,21,0,7)/(21,0,0,7). VRAM38=a2,3C=a2+600. Twobufferswith40byteprefix,6DBD10paletteuploads,6DBD90mapupload;stride(90*3+E0+90*80+3F)&~3F. Resetsindex/currentpointer,drawcounts,color80808080,depth-2;size40=end-work30. Noactualsubmission. |
| [o2 0x6D9480](../recomp/config/output_ovl/o2/o2_006D9480_0x6d9480.cpp) | `initialize_map_view_scale_origin_and_player_center_candidate` | Probable role; full body reviewed | Null755DF8returns. View=table+5C*unsignedwork14;6DB180scale->work20,signedview48->floatwork1C. If4A/4C/4Eall-1,zeroswork24..2Aandcenter16/18=(320,224). Elseorigin24/26=round(view4A/4E/100*work1C*scale),zeros28/2A,center16/18=round((localactorX/Z-view4A/4E)/100*work1C*scale). View40ID->wordwork68. No viewport/frame-pacingchanges. |
| [o2 0x6D9680](../recomp/config/output_ovl/o2/o2_006D9680_0x6d9680.cpp) | `project_actor_xz_to_selected_map_coordinates_candidate` | Probable role; full body reviewed | a0mapwork,a1signedactorindex,a2floatXYout. Nullviewtableorselectedvieworigin4A/4C/4Eall-1 returns0withoutoutput. Otherwiseupdateswork1Cfromsignedview48,projectsactor4A5C30+10E0*a1 X/Z via((coord-origin)/100)*work1C*work20;returns1. Noactorindexboundcheck. |
| [o2 0x6D97A0](../recomp/config/output_ovl/o2/o2_006D97A0_0x6d97a0.cpp) | `project_integer_world_xz_to_selected_map_coordinates_candidate` | Probable role; full body reviewed | a0work,a1integerworldX,a2integerworldZ,a3floatXYout. Sameviewtable/allsentinelgateandwork1Cupdateas9680; integerargumentstoconvertfloat,subtractview4A/4E,divide100,multiplywork1C*work20. Success1/failure0; nooutputonsentinel. |
| [o2 0x6D9890](../recomp/config/output_ovl/o2/o2_006D9890_0x6d9890.cpp) | `set_item_message_packet_draw_origin_candidate` | High mechanics; candidate role | Storesa0/a1intoglobal755DD8/DDC (=state58/5C). Nootherwritesorcallees. |
| [o2 0x6D98B0](../recomp/config/output_ovl/o2/o2_006D98B0_0x6d98b0.cpp) | `set_item_message_packet_palette_selection_candidate` | High mechanics; candidate role | Storesa0to755DE4 (=state64),whichspritepacketbuildersuseforCLUTselection. Noindexclamp. |
| [o2 0x6D98C0](../recomp/config/output_ovl/o2/o2_006D98C0_0x6d98c0.cpp) | `set_item_message_packet_rgba_word_candidate` | High mechanics; candidate role | Storesa0to755DE8 (=state68),laterpackedintospriteRGBA. Nochannelconversionormask. |
| [o2 0x6D98D0](../recomp/config/output_ovl/o2/o2_006D98D0_0x6d98d0.cpp) | `address_item_icon_pixels_by_texture_stride` | High; full body reviewed | Returnswordstate18+wordstate10*a1withoriginal32bitmultiply;notabsolutebounds/nonnullcheck. Nomemorycopy. |
| [o2 0x6D98F0](../recomp/config/output_ovl/o2/o2_006D98F0_0x6d98f0.cpp) | `append_consecutive_item_icon_uploads_and_sprites_candidate` | Probable role; full body reviewed | a0firsticon,a1palette,a2signedcount,a3X,t0Y,t1tintmode. Requires755D98and324405==1;setsdrawpalette/origin/color(t1==1?80808080:40808080). Pretestedcountloopgetsiconpixels98D0,6DB760(state,currentpacket,pixels,0),incrementsdrawcount48,originXbywidth50,iconID,andpacket34. No localmaxicon/count/packetcapacityguard;negativecountdoesnoappend. |
| [o2 0x6D99F0](../recomp/config/output_ovl/o2/o2_006D99F0_0x6d99f0.cpp) | `address_file_icon_pixels_by_texture_stride` | High; full body reviewed | ReturnsstateA4+state9C*a1withoriginal32bitmultiply. Independentsecondtexturebank;noindexcheck. |
| [o2 0x6D9A10](../recomp/config/output_ovl/o2/o2_006D9A10_0x6d9a10.cpp) | `append_file_icon_upload_and_sprite_candidate` | Probable role; full body reviewed | a0icon,a3receivesoriginaliconforpixeladdress;require755E24and324405==1. 99F0resolvespixels,6DBA60(state,packetC0,pixels,inheriteda3),storesreturnedC0,D0=1. Calleeusesa3forCLUTindex,soactualpassediconIDretainedratherthanassuminga separatepaletteparameter. |

Original projection converts and rounds through COP1 cvt.w.s; it does not imply
host-default truncation. Index and packet-capacity contracts belong to callers.
The initialization creates reusable guest upload buffers; later flush behavior
is mapped separately and cannot be inferred from constructors alone.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
