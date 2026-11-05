# Resident movie conversion: second tiled fourth-channel lookup variant

Static File #1 US research, 2026-11-04. Owned ELF `game_data/SLUS_207.65`, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**. Complete53-word original body read, including both initial dimension gates and all byte loops. No game/build, replay, attachment, live-memory or conversion test.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x150110](../recomp/config/output/sub_00150110_0x150110.cpp) | `write_lookup_mapped_fourth_channel_from_16_by_32_tiled_source_variant_candidate` | Confirmed complete address/count formulas; visual channel meaning partial | Inputs source descriptor{base0,dimension4,dimension8},destination descriptor{base0},256byteLUTa2. A=trunc0(dim4/16),B=trunc0(dim8/32). Fori0..A-1,j0..B-1,k0..255:dst[1024*B*i+1024*j+4*k+3]=LUT[src[768*B*i+384*B+384*j+k]]. Outer/inner<=0skipwrites. No outputdimension/stridefieldread,extentcheckoractualRGBA/alphaconventionproved. |

Sourceadvances256bytesforeachtilethen128bytesgap;destinationadvancesfourbyteseachsample. The firstsourceplaneoffset384*Bisdifferentfromastreamofcontiguous16x16tiles;preservethisliteralformulaalongside[existingconversionmethods](SYMBOLS_MOVIE_CONVERSION_METHODS_AND_TABLES.md). Indexedcaller17B960hasasite17B9F8;itdoesnotbyitselfproveframefrequencyorwhichvisualchannelthebytecontrols. All53instructioncommentsmatchownedELFwords;omittedalignedwordsarezero. No bandwidthmeasurement,linearimageparityor slowdowndiagnosis.
