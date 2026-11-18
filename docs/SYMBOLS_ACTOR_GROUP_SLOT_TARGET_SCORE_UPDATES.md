# Group/slot target-score updates

Static File #1 US, 2026-11-05. Five complete original o2 bodies reviewed, including cached-query admission, all scoring/decay branches, soft-double modifiers, conversion order and delay slots. Addresses, masks and offsets are hexadecimal; float/constants and stated score formulas are decimal. No execution, build, attachment, live memory, input or timing. Target-score role is candidate, supported by indexed preference writes and separate target-health ranking; no damage application is claimed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x636410](../recomp/config/output_ovl/o2/o2_00636410_0x636410.cpp) | `update_group_slot_target_score_from_cached_distance_facing_and_state_candidate` | High mechanics; candidate role | a0source,a1target,a2unsignedwindow,t0group,t1slot,f12maxdistance,f13nearoutsidewindowdistance. Cached distance5A9950;within800 firstaddsD10-weight*runtime sourcecategorycoefficient to signedscoreBF8+14hex*low8group+2*low8slot, uppercaps1FFF after narrowing. Then cachedaux/maxdistance/targetstate/BA020000000 can decay. Angularwindow admission calls636830(scale1) and mayupdatehealth extrema; outsidewindow butwithin f13 calls636830(scale2); othercases636BB0. Initial baselinewrite precedes all laterrejections. |
| [o2 0x636830](../recomp/config/output_ovl/o2/o2_00636830_0x636830.cpp) | `apply_distance_category_and_flag_scaled_target_score_delta_candidate` | High mechanics; candidate role | a0source,a1target,a2integerdistance,a3gainindex,t0group,t1slot,f12scale. Base400-signedDIV(word(2*distance),72F7E0[low8gainindex]);onlynegativebase->1. Targetclass0 uses specialcategory2 factor0.1,elsemaskpredicate factor1.5/1 plus sourceC20/10;otherclass sourceC21/10. Zero coefficient paths skipwrites. C23 targetB99 flags modify sign/soft-double1.5; finalguestCVT(delta*f12) storedglobal744610/group/slot andaddedtosignedhalfsourceBF8. Sign-dependent clamps preserve original narrow/wrap order. |
| [o2 0x636B80](../recomp/config/output_ovl/o2/o2_00636B80_0x636b80.cpp) | `test_category_bit_against_byte_mask_from_eight_bit_table_candidate` | High mechanics; candidate role | a0categorylow8,a1masklow8. Returnsbool(710630[category]&mask). Owned firsteightbytes1,2,4,8,10,20,40,80. No localcategorybound;636830 uses targetB98 and sourceC22. Not an actoractivity check. |
| [o2 0x636BB0](../recomp/config/output_ovl/o2/o2_00636BB0_0x636bb0.cpp) | `decay_group_slot_score_by_divisor_selected_step_candidate` | High mechanics; candidate role | a0source,a1ignored,a2decayindex,a3group,t0slot. Overridesa1=decimal2500. Step=signed16(unsignedDIV(2500,72F800[low8decayindex])+1), subtractsfromsignedhalfBF8+14hex*low8group+2*low8slot, stores/reloadssignedhalf. Result<0 OR>=2000 clears0; otherwise retained. Upperout-of-range alsozeros,notcaps1FFF. No own selection or targetpointer. |
| [o2 0x636C40](../recomp/config/output_ovl/o2/o2_00636C40_0x636c40.cpp) | `derive_positive_signed16_counter_from_half_input_and_clamped_float_modifier_candidate` | High mechanics; candidate role | a0signedhalfinput,f12value,f13modifier. c=f12/10;orderedc<1 sets1,thenfailedc<=100 sets100(includingunordered). term=signed16(guestCVT(-2*c*f13));halfinput=signeddivisionby2towardzero. Returns signed16(term+halfinput), replacing<=0 with1. Arithmeticnarrowing precedes positivity check; no actor/global writes. |

## Baseline write before admission

636410 preserves source/target/window/group/slot and both distance limits. Cached distance5A9950(source,signedtargetbyte3) is read once. Ifdistance<=800 and signedweight710620[targetD10]!=0, it multiplies weight by unsigned runtime byte74F2AC+60hex*sourceB98, narrows the product signed16, adds to existing indexedscore, narrows again and upper-caps>=2000 to1FFF. There is no lower clamp on this baseline path. Later denial still leaves that write in place.

It then rejects nonzero low8cachedaux5A9C50, distance>incomingf12, target6689B0 nonzero, or targetBA0 mask20000000 into decay. These cached metrics are not relabeled as geometry/line-of-sight. Otherwise634530 computes relative bearing; it admits when unsignedwindow >= unsigned16(bearing+unsigned16(window>>1)). Window0 therefore admits an exactalignedbearing here; no separate zero-window rejection is added. Angular admission converts distance through the original guest unsigned-style float-to-word sequence and calls636830(scale1,gainindexsourceC89).

After that call it tests `(low8(group)+1) & sourceC23`, not `1 << group`. If nonzero, target signedhealth544 updates global maximum744600 withgroup/slot bytes7445F0/7445E8 when larger, and minimum7445F8 with7445E0/7445D8 when smaller. This happens even if636830 skipped score writes because a coefficient waszero. Outside the angle window, distance<=incomingf13 calls the same gain helper withscale2; otherwise decay uses sourceC8A.

## Gain arithmetic and flags

Let B=400-signedDIV(word(2*distance),gainDivisor). Negative B becomes1; exactzero remains0. For targetcategorybyte2=0, categoryB98==2 selects float0.10000000149011612; othercategories select1.5 when710630[B98]&sourceC22,else1. With V=sourceC20/10, eitherexactfactor0 or V0 skipswrites; otherwise integergain=guestCVT(B*(factor+V)/2). Nonzero targetcategory uses V=sourceC21/10; V0 skips, elsegain=guestCVT(B*(1+V)/2).

Then sourceC23 bit1: targetB99==0 multipliesgain by software-double1.5 with truncating/saturatingint conversion; anotherB99 withbit4 negatesgain. Bit2 independently follows: targetB99==1 multiplies1.5, anotherB99 withbit4 negatesgain. Both flags may act in sequence, including repeated sign changes. [Software-float contracts](SYMBOLS_SOFTWARE_FLOAT_ARITHMETIC.md) establish1122E8/111DB0/1123A0; do not replace this with a guessed integer percentage rounding rule.

Final signedintegerdelta=guestCVT(float(gain)*incomingf12). Low16delta goes to global744610+14hex*group+2*slot; its signedlow16 is added to sourceBF8 at the same index. Based on the full delta register sign, a nonnegative delta caps a reloaded signedscore>=2000 to1FFF; a negative delta clears reloaded negative score0. Other wrapping cases are retained. No direct target health544 store occurs in either gain or decay helper.

## Complete owned windows

| Address span | Content | SHA256 |
| --- | --- | --- |
|710620..71062F|eight signedhalfweights0,0,10,0,1000,3000,0,0|`0fa1773f20926a46047948ded1d2d364685f2640408a576ce9f6889ff8b56092`|
|710630..710637|eightmaskbytes1,2,4,8,10,20,40,80hex|`5ac9831b2e30eb285ef34f8501620f878432d5c04331ad1ae47f977a83ba41a5`|
|72F7E0..72F7FF|eight signedgain-divisorwords532,266,176,132,88,76,66,60|`018210ca7b31909aa667d547878236314967910357c168e004a3be686815b17f`|
|72F800..72F81F|eight unsigneddecay-divisorwords2,20,40,60,66,88,132,2500|`909e367d46cd665a5b843248ac81564e9d6ea5fd26864850ead8a3dcd62e203f`|
|740170..740173|float0.10000000149011612|`fb360f7241a770dc32cade9a1d1273c92b13bd4959b1c130931312b7fe95e63f`|

These complete windows establish bytes, not local index bounds: targetD10/B98 and gain/decay indexes are unsignedbytes without bounds checks. Runtimecoefficient74F2AC and global score/extrema arrays lie beyond owned file-backed o2; none was read live. All-writer invariants, initialized extrema, group/slot limits and actual frequency remain unknown.

636C40 is a separate pure numeric counter helper, included because it neighbors this score family. Its incomingfloat division/clamps and signed16half rounding are explicit; original counter purpose is unresolved. The [cached metric contracts](SYMBOLS_CACHED_TARGET_METRICS.md), [bearing helper](SYMBOLS_ACTOR_BEARING_TRANSFORMS_AND_AUTHORITY_ADAPTERS.md), and [target-state admission](SYMBOLS_ACTOR_CONTACT_DAMAGE_ADMISSION.md) retain their own limits. No measured bottleneck or candidate fix is asserted. Owned o2 base570000 SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Full owned-body audit: 505 original words verified; 28 omitted words all zero/NOP. Zero conflicts or omitted nonzero words.
