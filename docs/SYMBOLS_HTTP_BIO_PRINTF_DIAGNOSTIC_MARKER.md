# HTTP overlay BIO formatted output and diagnostic address marker

Static owned File #1 o6 `nethttp.bin`, runtime ID6/base6E0000, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Two complete catalogue bodies reviewed. No formatted output was executed and no target memory was sampled. The marker callback initially resembled a formatter by its arguments; its full body proves only conditional global stores.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x6F1C40](../recomp/config/output_ovl/o6/o6_006F1C40_0x6f1c40.cpp) | `format_variadic_text_to_stack_buffer_then_write_bio_string` | Confirmed full varargs/save/write mechanics | Increments owned counter735170. Calls710648(stack+400,owned source path73B1A8,26,counter). Then variadic formatter10F880 writes main stack buffer from original format arg and saved variadic-register area, computes strlen, writes through6F3BD0(BIO,buffer,length). Does not output source marker separately or use710648 as formatter. No capacity passed to10F880 here; exact formatter truncation contract delegated. |
| [o6 0x710648](../recomp/config/output_ovl/o6/o6_00710648_0x710648.cpp) | `record_lower_candidate_address_and_its_source_location_metadata` | Confirmed complete unsigned compare/store path and connected reporting | If unsigned candidate a0<global7384B0, stores candidate there and records a1 at740530,a2 at740528,a3 at74052C. Address7384B0 is LUI74 plus signed displacement-7B50; the earlier7404B0 transcription was incorrect. Otherwise no stores. Always returns0. No indirect callback, text formatting, memory dereference at candidate, or allocation occurs. Initial baseline7384B4 and complete stack-usage reporting consumers are reviewed in [stack candidate report](SYMBOLS_HTTP_STACK_CANDIDATE_REPORT.md); this records candidate stack addresses rather than measured per-function stack depth or runtime time. |

Owned73B1A8 string is `./bio/../bio/b_print.c`. It corroborates source provenance for the BIO formatter but does not establish a line-for-line upstream version or safe arbitrary-format capacity. This library text output is separate from the player's incident recorder.

Audit: 51 verified instruction words, zero conflicts, zero omitted zero words, zero omitted nonzero words.
