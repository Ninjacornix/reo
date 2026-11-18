# ADX magic scanning and copyright identity check

Static File #1 US research, 2026-11-04. Original **SLUS_207.65**, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**. Complete original instruction intervals and owned six-byte239BE0 copyright marker reviewed. No file scan, audio, game or build executed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x126670](../recomp/config/output/sub_00126670_0x126670.cpp) | `find_two_byte_aligned_ADX_magic_offset_candidate` | Confirmed full scan and matching ADX base parser | Scans signed input length minus1, offsets0,2,4... while offset<len-1 for LH==0080 (memory bytes80,00, matching BE8000 ADX magic). Found offset stored as lowhalf througha2,return0; missing writes0,return-1. Does not validate header fields or ensure returned offset fits16bits. Unaligned input pointer is not admitted here. |
| [0x1266F0](../recomp/config/output/sub_001266F0_0x1266f0.cpp) | `validate_ADX_header_magic_and_owned_copyright_with_literal_large_length_gate_candidate` | Confirmed full unusual admission and exact marker | Signedlength<10hex->0; BE16magic!=8000->0. Reads BE16offset2, computes headerlength=offset+4, candidate marker atinput+offset-2. Literal comparison requires signed inputlength>7FFF before comparing six bytes with239BE0 `(c)CRI` using107A18. Matching marker optionally stores lowhalf headerlength,returns1; otherwise0. No offset-within-length check. The unusual length gate is preserved as observed rather than corrected or described as ordinary bounded header validation. Actual caller/format admission and current overrides remain unknown. |

The six-byte identity marker is data evidence, not evidence of executed audio or decoder compatibility. Original constraints can explain a candidate admission issue only after their caller contracts are established.

Offsets, masks, lengths in condition expressions and addresses are hexadecimal except spelled scan steps. Related: [ADX base-header parser](SYMBOLS_ADXB_DECODER_LIFETIME_HEADER_AND_PHASE.md), [unkeyed CPU kernels](SYMBOLS_ADX_UNKEYED_FLOAT_STEREO_DECODERS.md), [central index](FUNCTION_INDEX.md).
