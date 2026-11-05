# Software-double atan and atan2 candidates

Static File #1 US main ELF,2026-11-04. Three complete bodies, argument-reduction and quadrant branches, full owned coefficient/angle banks and connected software-double arithmetic. [Identity](FUNCTION_INDEX.md). No math test, game, build or benchmark was run. API roles are inferred from the complete formulas and constants; exact library symbol/version and all-input numeric equivalence remain unproven.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x11F878](../recomp/config/output/sub_0011F878_0x11f878.cpp) | `software_double_atan2_with_signed_zero_infinity_and_quadrant_corrections_candidate` | Strong complete formula/constant inference; exceptional arithmetic parity partial | a0 y/a1 x as packed double bits. NaN-shaped operands route x+y through111CF0; exact x=1 tails121A28(y). Derives quadrant from sign bits, handles signed y0,x0 and infinities using owned0/pi/halfpi/quarterpi/threequarterpi. Finite ordinary path estimates exponent gap; large positive gap uses halfpi, tiny y/x with negative x uses0, otherwise atan(abs(y/x)). Reconstructs quadrants with sign-bit flip or pi/pilo correction. No host atan2 equivalence or call-frequency claim. |
| [0x121A28](../recomp/config/output/sub_00121A28_0x121a28.cpp) | `software_double_atan_by_four_argument_reductions_and_split_polynomial_candidate` | Strong complete reduction/polynomial inference; numeric validation absent | abs magnitude>=2^66 returns signed split halfpi except NaN-shaped input routed x+x. Small abs<.4375 uses original signed argument; tiny<2^-29 can return input via huge+x comparison. Other magnitudes use abs and four transforms, then two interleaved polynomial chains over t²/t⁴ and split high/low angle correction. Restores sign for reduced paths. All arithmetic through reviewed software-double helpers, including their truncation/denormal behavior. |
| [0x121EF0](../recomp/config/output/sub_00121EF0_0x121ef0.cpp) | `clear_sign_bit_of_packed_software_double_operand` | Confirmed complete bit expression and connected magnitude use | Returns a0 bits with high-word sign bit clear, preserves remaining63bits. Used by atan and atan2 before reduction. Does not unpack, canonicalize NaNs, flush denormals or convert to a host double. |

## atan reduction and reconstruction

For u=abs(input), the four explicitly encoded intervals/transforms are:

| Interval | ID and reduced t |
| --- | --- |
| .4375<=u<.6875 |0: (2*u-1)/(2+u). |
| .6875<=u<1.1875 |1: (u-1)/(u+1). |
|1.1875<=u<2.4375 |2: (u-1.5)/(1+1.5*u). |
| u>=2.4375 below huge gate |3: -1/u. |

Set z=t*t,w=z*z. Coefficients a0..a10 at239238..239288 form s1=z*(a0+w*(a2+w*(a4+w*(a6+w*(a8+w*a10))))) and s2=w*(a1+w*(a3+w*(a5+w*(a7+w*a9)))). Unreduced path returns t-t*(s1+s2). Reduced path returns hi[id]-((t*(s1+s2)-lo[id])-t), then applies original sign through software subtraction. hi2391F8 and lo239218 have4doubles each: angles approximately atan(.5),atan(1),atan(1.5),pi/2, with explicit low residuals. All thresholds use original high-word comparisons, not a host floating comparison substituted here.

Owned2391F8..23929F168-byte SHA-256 `4e68851ef022bbdfdca2d3f1635ea4271120e79a356297ec87e379511157f066`; this includes the8 split-angle constants,11 coefficients, neighboring1.0 and huge~1e300. The separately read huge value2392A0 has eight-byte hash`e790bfdaea1d276f0b68356677597e2229f198cdb33fbbeab4e6d30bf8e72279`. Original tiny-input route uses that latter address.

## atan2 quadrants

Quadrant m=(signX<<1)|signY. For finite ordinary inputs let z be reduced positive angle: m0->z,m1->sign-flipped z,m2->pi-(z-pilo),m3->(z-pilo)-pi. Exponent difference is arithmetic(absYHigh-absXHigh)>>20; >60 uses halfpi, <-60 with negative x uses0. Exact y0 yields original signed zero for nonnegative x, plus/minus pi for negative x. Exact x0 or infinite y yields signed halfpi; both infinite yield signed quarter/threequarterpi. Infinite x with finite y yields signed zero or pi. NaN handling inherits software add, not a claim that IEEE payload propagation matches the host.

Owned238C88..238D0F136-byte SHA-256 `52ee52aee605cbf0e954c1aaad705c64ebf1e70a57a2cbe560325fd428d83283`. It includes signed angle constants/pi residual1.224646799147353e-16 plus the neighboring log constant at238D08, which is not claimed as part of atan2. [Software-double arithmetic](SYMBOLS_SOFTWARE_FLOAT_ARITHMETIC.md) defines add/subtract/multiply/divide behavior used throughout. These static libm roles do not establish a measured hot path, VU execution or permission to substitute host intrinsics before later equivalence validation. All owned instruction comments match; omitted aligned words are zero.
