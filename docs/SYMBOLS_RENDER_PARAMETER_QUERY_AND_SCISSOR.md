# Resident render parameter queries, scissor and depth-buffer state

Static File #1 US research, 2026-11-04. Main **SLUS_207.65**, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**. Five complete original bodies reviewed. No game, GPU work, build or timing measurement executed. Parameter IDs are retained numerically; an exact getter does not prove the original enumeration names.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x196F00](../recomp/config/output/sub_00196F00_0x196f00.cpp) | `query_render_parameter_by_low_byte_id_candidate` | Confirmed complete selector behavior | Uses original a0&FFhex;defaults return0. Selectors return cached words,unshifted masks,booleans or pointers as detailed below. Selector14 calls197480. No queueing,state mutation,hardware readback or allocation. Returning0 does not distinguish unsupported IDs from a valid zero parameter. |
| [0x197470](../recomp/config/output/sub_00197470_0x197470.cpp) | `store_render_parameter_slot_fourteen_word_candidate` | Confirmed setter | Stores full a0 to29FD50. No return assignment or side effect beyond store; scope/name derives from196F00 ID14 getter. |
| [0x197480](../recomp/config/output/sub_00197480_0x197480.cpp) | `load_render_parameter_slot_fourteen_word_candidate` | Confirmed getter | Returns full word29FD50. Does not test or clear state. |
| [0x197490](../recomp/config/output/sub_00197490_0x197490.cpp) | `clamp_scissor_endpoints_and_queue_selected_gs_context_registers_candidate` | Confirmed rectangle/register mechanics | Inputs x,y,width,height,contextt0. Negative x/y become0 without reducing requested widths. If x+width or y+height exceeds globals29FED8/29FED0,shortens dimension;inclusive endpoints are x+width-1,y+height-1. No negative-size,origin-beyond-screen or overflow rejection. Allocates30hex except context2 uses40hex,emits SCISSOR_1/2 register40/41 for contexts0/1/2. Packs x0,x1,y0,y1 in16-bit-spaced64-bit fields without masking inputs;stores context rectangle/cache at29FDF8/29FE08 and29FDF0/29FE00. Queues18CFB0 and returns1 irrespective queue result. Invalid context leaves register payload slots uninitialized locally. |
| [0x197780](../recomp/config/output/sub_00197780_0x197780.cpp) | `queue_depth_buffer_base_format_and_write_mask_for_gs_contexts_candidate` | Confirmed ZBUF register mechanics | Payload=(word29F9F0>>5) OR(word29F9E4<<24) OR((input flags8000hex clear?1:0)<<32). Allocates30hex or40hex for contexta1==2. Context0/1/2 emits ZBUF_1/2(4E/4F),caches64-bit payload at29FDE0/29FDE8. Queue18CFB0 then return1. No depth clear,allocation of a new depth surface or completion wait. Invalid context leaves payload uninitialized locally. |

All IDs/masks/addresses below are hexadecimal. Let **F**=word29FE70 and **G**=word29FE68. Raw masks are intentionally distinct from booleans.

| ID | Returned value |
| --- | --- |
| 01 | F & F00 |
| 02 | F & 1C |
| 04..07 | word294E60+4*(ID-4) |
| 0C | (F & 80)!=0 as0/1 |
| 0D | G & C00 |
| 0E | word29FE30 |
| 0F | word29FE38 |
| 12 | (F & 18000)==8000 as0/1 |
| 14 | word29FD50 through197480 |
| 15 | F & 3 |
| 5A..5C | pointer294200+104decimal*(ID-5A) |
| 5D | F & FF000000 |
| 5E | unsigned byte29FE68 |
| 5F | (G & 380000)>>19decimal,ordinal0..7 |
| 60 | word29FE20 |
| 61 | (G & 01000000)!=0 as0/1 |
| 62 | (F & 4000)!=0 as0/1 |
| 63 | G & 10000 |
| 64 | G & 60000 |
| 66 | (F & 20000)!=0 as0/1 |
| 69 | word294E70 |
| 6A | word294E68 |
| 6B | G & C00000 |
| 6C | (G & 8000)!=0 as0/1 |
| 6D | (G & 7000)>>12decimal,ordinal0..7 |
| All others | 0;includes explicitly admitted no-value IDs as well as default |

The getters observe cached render state. [GS test/blend/texture builders](SYMBOLS_RENDER_GS_TEXTURE_STATE.md) and [immediate primitive setup](SYMBOLS_IMMEDIATE_PRIMITIVE_VARIANTS.md) consume these values. A future native state cache must preserve raw-bit versus boolean contracts,context-specific payloads,and failed/unsupported admissions. No batching benefit or slowdown cause is established by these static mappings.
