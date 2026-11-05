# Resident fixed-block copy and fill variants

Static owned resident executable SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. Nine full original intervals reviewed; loop initialentry, decrement width and all load/store ordering checked. No code execution or memory-copy benchmark.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x189A88](../recomp/config/output/sub_00189A88_0x189a88.cpp) | `copy_positive_count_of_words_forward` | Confirmed complete transfer/iteration contract | a0source,a1destination,a2wordcount. PeriterationLW/SW4bytes,thenadvance;no initialcounttest. |
| [0x189AA8](../recomp/config/output/sub_00189AA8_0x189aa8.cpp) | `copy_positive_count_of_16_byte_blocks_using_four_word_loads` | Confirmed complete transfer/iteration contract | Loadsallfour32-bitwordsbeforestoring16bytes,thenadvances;counta2numberofblocks. |
| [0x189AE0](../recomp/config/output/sub_00189AE0_0x189ae0.cpp) | `copy_positive_count_of_16_byte_blocks_using_two_doubleword_loads` | Confirmed complete transfer/iteration contract | Loadsbothtwo64-bitvaluesbeforestoring16bytes;requiresdoublewordalignmentfrominstructions;counta2blocks. |
| [0x189B28](../recomp/config/output/sub_00189B28_0x189b28.cpp) | `copy_positive_count_of_32_byte_blocks_using_eight_word_loads` | Confirmed complete transfer/iteration contract | Loadseightwordsbeforeanyofeightstores,thenadvances32bytes,counta2blocks. |
| [0x189B80](../recomp/config/output/sub_00189B80_0x189b80.cpp) | `copy_positive_count_of_32_byte_blocks_using_four_doubleword_loads` | Confirmed complete transfer/iteration contract | Loadsallfour64-bitvaluesbeforestores32bytes,counta2blocks;instructionalignmentadmissionexternal. |
| [0x189BB8](../recomp/config/output/sub_00189BB8_0x189bb8.cpp) | `copy_positive_count_of_two_quadword_blocks_forward` | Confirmed complete transfer/iteration contract | Loads2quadwordswithLQthenSQ32bytes,counta2blocks;requiresquadwordalignmentexternally. |
| [0x189C18](../recomp/config/output/sub_00189C18_0x189c18.cpp) | `zero_positive_count_of_words_forward` | Confirmed complete transfer/iteration contract | a0destination,a1wordcount;decrementsbeforeunconditionalSWzero,advances4,repeatswhilecountnonzero. |
| [0x189C48](../recomp/config/output/sub_00189C48_0x189c48.cpp) | `fill_positive_count_of_words_with_supplied_low32_value` | Confirmed complete transfer/iteration contract | a0destination,a1wordcount,a2pattern;decrementsbeforeSWa2,advances4,repeats. |
| [0x189C60](../recomp/config/output/sub_00189C60_0x189c60.cpp) | `fill_positive_count_of_quadwords_with_supplied_full_gpr_pattern` | Confirmed complete transfer/iteration contract | a0destination,a1quadwordcount,a2full128-bitregisterpattern;SQa2each16bytes. Notbytefillorlow32broadcast;callerregisterhighbitsmatter. |

All are unconditional do/while-style loops; they have no zero-count early return. Zero starts one transfer and decrements toFFFFFFFF, requiring2^32 totaliterations if memory access were toremainvalid. Thisis a literal guest32-bitloop property,not an exercisedcrash/hang. Countunits areblocks/words,notbytes. Theyhave no memmove-style direction choice,span validation,capacity checkor explicitreturnvalue contract; source/destination exactaliasretainsbytes,butgeneraloverlapisnotadmitted.

Previously reviewed189B08 usesoneLQ/SQper16-byteblock,189BE0fourquadwordsper64-byteblock,and189C30zerosquadwords. Thoseidentitiesremainintheirexistingnotebooks; no duplicate rows areaddedhere. Thesehelperssitbetween[arena management](FUNCTION_INDEX.md) andrenderresourcecode, buta fixedcopyroledoesnotproveitdominatesruntimecost.

Audit: 9 rows, 87 verified owned instruction words; 9 omitted interval words are zero/NOP; 0 omitted nonzero words.
