# Single-player overlay: catalogue header fragments

Static File #1 US research, 2026-11-04. These are **data classifications, not function mappings**. The nine residual records in [ovl9.csv](../recomp/config/overlay_maps/ovl9.csv) are inside the owned MWo3 header and have no generated function body. Assigning guessed function names to these records would inflate code coverage.

Owned decoded o9 image SHA-256: **604126d6edca1b1333948d79d1d2c8d2f2e22f4a233efbdfb769c106dafe7343**. Header magic is `MWo3`, id **9**, load base **0x00810000**, embedded name **single.bin**. The header field conventions for magic/id/base/text/data are documented by the repository's [overlay extractor](../tools/overlay_extract.py:13). This review reads the existing owned decoded image; it does not extract another disc, execute a game, build, attach or sample a process.

All intervals below are half-open guest address intervals, copied directly from the catalogue. Values are little-endian. A one-byte fragment of a word is not an independent symbol merely because the source map contains a start address for it.

| Catalogue start | Catalogue end | Exact bytes | Classification and evidence |
| --- | --- | --- | --- |
| `o9:0x00810000` | `0x00810008` | `4D 57 6F 33 09 00 00 00` | Magic `MWo3` and complete 32-bit overlay id 9. Header data, not an instruction entry. |
| `o9:0x00810008` | `0x00810009` | `00` | First byte of complete load-base word at header +8, whose four bytes decode as 0x00810000. |
| `o9:0x00810009` | `0x0081000A` | `00` | Second byte of the same load-base word. |
| `o9:0x0081000A` | `0x0081000B` | `81` | Third byte of the same load-base word. |
| `o9:0x0081000B` | `0x0081000C` | `00` | Fourth byte of the same load-base word. |
| `o9:0x0081000C` | `0x00810018` | `C0 89 01 00 00 30 00 00 80 7E 06 00` | Three header words: text size 0x189C0 at +C, data size 0x3000 at +10, raw word 0x67E80 at +14. The latter field's meaning is not established here. |
| `o9:0x00810018` | `0x00810019` | `00` | First byte of header +18 word. The complete four-byte word is 0x0082BA00; its semantic meaning remains unresolved in this review. |
| `o9:0x00810019` | `0x0081001A` | `BA` | Second byte of the same header word. |
| `o9:0x0081001A` | `0x0081001B` | `82` | Third byte of the same header word. Catalogue stops before its fourth byte; it is not a complete instruction. |

For context, header +1C also contains raw word **0x0082BA00**, and +20 contains the NUL-terminated ASCII name `single.bin`. No function role is inferred for these values. The decoded image header region is distinct from the code entries beginning at **0x810080**. Source ownership remains the image-plus-address pair; the shared virtual base used by other overlays does not make those other headers or functions interchangeable.

The o9 catalogue therefore comprises **328 generated code entries reviewed across the symbol notebooks and nine verified header-data fragments**, 337 records in total. The goal/update closure is in [the goal notebook](SYMBOLS_SINGLE_GOALS.md); this data classification must remain separate from its proposed function labels. Reviewed entry roles do not mean full high-level source recovery or validated replacement implementations.
