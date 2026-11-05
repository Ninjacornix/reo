# Resident MWSFD: product/ratio conversion helpers

Static File #1 US research, 2026-11-04. Owned ELF `game_data/SLUS_207.65`, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**. Three complete bodies /75 original instruction words were read. No numeric execution, game/build, replay, attachment or live-memory read. Complete routing is established; all-input numerical parity and original names remain unproved.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x15BA68](../recomp/config/output/sub_0015BA68_0x15ba68.cpp) | `MWSFD_integer_product_quotient_adapter_candidate` | Confirmed complete tail route | Unchanged a0/a1/a2 tail15BA80. No added range/zero checks. |
| [0x15BA80](../recomp/config/output/sub_0015BA80_0x15ba80.cpp) | `MWSFD_signed_32_product_divide_and_narrow_or_zero_divisor_limit_candidate` | Confirmed complete27-word arithmetic | Signed32a0*a1assembledfromHI/LOto64bits;nonnulla2signed64divide10FB18thenlow32signextension. Divisor0returns80000000hexiff(a0xor a1)<0,else7FFFFFFFhex. This sign rule applies even zero multiplicand;nonzero quotientoverflowisnot saturated. |
| [0x15BAF0](../recomp/config/output/sub_0015BAF0_0x15baf0.cpp) | `MWSFD_product_ratio_via_software_double_add_half_and_floor_conversion_candidate` | Confirmed complete43-word call sequence; rounding parity partial | Divisor0sameXORsignlimit. Else1122E8convert signed32a0/a1→softwaredouble,111DB0multiply,1122E8divisor,112038divide,111CF0addownedliteral3FE0000000000000(.5),121F28floor-likebitroutine,1123A0toint32. No localrangecheckorsaturationfornonnulla2;inheritschildspecial/roundingbehavior. |

The [resident signed64quotient](SYMBOLS_RESIDENT_64BIT_DIVISION.md) and [softwaredouble arithmetic](SYMBOLS_SOFTWARE_FLOAT_ARITHMETIC.md) retain their independent semantics. Direct15BA80 uses widened signedproduct and truncatingintegerquotient;15BAF0usessoftwarefloatingmultiply/divideandfloor-likeoperationafteraddinghalf. They are not assumed interchangeable fornegativevalues,overfloworallmantissas. The complete121F28callee was statically read as context,including exponent/mantissamasks andnegativefractionincrement,but is outside this notebook's assigned150000+scope and receives no mapping row here. No proof of universal standardfloorornearest rounding is imported from its shape.

All75instructioncommentsmatchownedELFwords;omittedalignedwordsarezero. No use frequencyor timingoptimizationclaim.
