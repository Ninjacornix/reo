# Shared scene lighting, color and fog publication modes

Static File #1 US research, 2026-11-04. Four complete original bodies reviewed against owned o2 words. Hexadecimal offsets/addresses; quantities below explicitly decimal. No execution, attachment, build, replay or renderer changes. Parameter publication denotes the original1AF780 call, not a measured GPU submission or confirmed hardware effect.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6B10A0](../recomp/config/output_ovl/o2/o2_006B10A0_0x6b10a0.cpp) | `initialize_shared_scene_light_fog_and_render_parameter_work_candidate` | High mechanics; rendering role probable | Initializes323DA0..3240D3 light/color/fog/flag work. Unit scales at3DA4/8/C,3F44/48/4C,3FAC/B0/B4; directionalZ defaults-1 at3E44/3EAC/3F14/3F7C/3FE4. Scalar100 at3DF0/4010, float1785/132/340 at3F80/84/88, float4300 at4014; baseRGBA4018=[7,10,20,80]. Copies740C80 to equal RGB at3DC4 and three light-color groups,740C78 to other light colors plus3F90/3FF8,740C70 to3F64/68/6C. Publishes1AF780(E,FF808080). Clears light pools748350/E00,747540/E00 and7474B0/80, counts/flags; details below. No runtime reuse/frequency inferred. |
| [o2 0x6B1660](../recomp/config/output_ovl/o2/o2_006B1660_0x6b1660.cpp) | `publish_primary_scene_light_directions_fog_and_color_parameters_candidate` | High mechanics; rendering role probable | For i0..2, flag324080+2*i==1 builds direction from angle words32401C+10*i and owned720218, stores323DD4+68*i. Flag324086+2*i==1 analogous32404C; when3240BF mask1 and4BADF8==0 instead normalize(324144-324138), stores323F0C+68*i. Packs clamped base4018RGBA plus signed-byte40D0 adjustments ->paramF; publishes4010 raw float bits param10,4014 param11 with+1 when numerically equal4010; param67=-1; param14=FF000000|RGB407C..7E. All through1AF780; not a GPU flush. |
| [o2 0x6B1A00](../recomp/config/output_ovl/o2/o2_006B1A00_0x6b1a00.cpp) | `publish_scene_primary_color_adjustment_and_light_block_candidate` | High mechanics; rendering role probable | Four unsigned bytes32408C..8F plus signedhalf324090..96; each sum truncates signed16 before clamp0..255. PackAARRGGBB ->1AF780(E,value). Nonzero half324080 publishes param5A pointer323DA0. Does not recalculate directions or publish fog scalars. |
| [o2 0x6B1BA0](../recomp/config/output_ovl/o2/o2_006B1BA0_0x6b1ba0.cpp) | `publish_scene_secondary_color_adjusted_light_and_fog_blocks_candidate` | High mechanics; rendering role probable | Four unsigned bytes324098..9B plus signedhalf32409C..A2, signed16 wrap then clamp and pack ->paramE. Nonzero half324086 copies68 bytes323ED8 tostack; adds/clamps RGB from3240A4 through6B36D0 to local colors at+4 and+24, publishes local pointerparam5A. Nonzero324088/8A publish323F40/323FA8 pointers via5B/5C. No retained stack pointer lifetime is proven by this call boundary. |

The shared cached mode selector6B15D0 was previously reviewed in [overlay math](SYMBOLS_OVERLAY_MATH.md): changed modes0/1/2 select6B1660/6B1A00/6B1BA0, then update the cached byte3240BC. Equal mode returns without these publications. Unknown mode values invoke no mode body. Main draw traversal selecting a mode is separate from individual primitive submission.

6B10A0 additional initialization contracts, all offsets relative to320000:

- Clears word3DA0,3DB4/3DB8/3DBC,3DE0/3DE4/3DE8/3DEC/3DF4,3E08,3E1C/3E20/3E24,3E3C/3E40,3E54/3E5C,3E70,3E84/3E88/3E8C,3EA4/3EA8,3ED8,3EEC/3EF0/3EF4,3F0C/3F10,3F40,3F54/3F58/3F5C,3F74/3F78,3FA8,3FBC/3FC0/3FC4,3FCC/3FD0/3FD4/3FDC/3FE0,3FE8/3FEC/3FF0/3FF4/3FFC.
- Half flags4080=2,4082=1,4084=1,4086=1,4088=2,408A=2. The direction update tests equal1, whereas publication gates test nonzero; those conditions are intentionally different.
- Clears bytes407C/7D/7E; sets40BD=-1,408C/8D/8E/8F=FF,409B=FF,4098/99/9A=80. Clears4090..97 and409C..A3 (8 bytes each),40A4..AF and40B0..BB (12 each),40D0..D3 (4).
- Clears count bytes748340/747538 and word747530; clears3240C8/40C4/40C0 and byte40BF; sets40BE/40BC=-1 and half40CC=1. No generic whole-context memset is inferred from this selective field initialization.

6B1660 packs color after signed16 conversion and0..255 clamping, preserving original wrapping and channel order. Its fog near/far equality test uses floats, then adds1 only to the submitted far value;324014 itself is not changed by that branch. Normalization in the special direction path uses191D80; zero-vector handling belongs to that helper, not an added guard here.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Source720218 is a three-float basis vector; source740C70/78/80 are owned initialized scalar values. Pool destinations747xxx/748xxx are beyond the owned file end743100 and remain runtime work. Related per-room LIG/FOG loading and light record mutation are in [LIG/FOG consumers](SYMBOLS_LIG_FOG_CONSUMERS_AND_WORK.md), track interpolation in [cutscene light tracks](SYMBOLS_CUTSCENE_LIGHT_TRACK_INTERPOLATION.md). No shader or VU pathway is selected or changed by these notes.

Owned 720218..720223: float values (0.0, 0.0, -1.0), SHA256 `02f50cc13892e5a15486c38f5fcaa7dd69c7fb56b5b8d0e874feb3699835898f`.

Owned 740C70..740C83: float values (0.10000000149011612, 0.0, 0.009999999776482582, 0.0, 0.20000000298023224), SHA256 `f54c4d2e67d596c7a6ab419a3332b85ed6c77713c59756eed456efa4a6308dd2`.

Full-body owned-word audit: 4 rows, 780 verified instruction words, zero conflicts, 17 omitted zero/NOP words, zero omitted nonzero words.
