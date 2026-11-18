# Cached target distance and bearing adapters

Static File #1 US research, 2026-11-04. All13 original bodies reviewed,
including null/default returns, signed bank arithmetic and fallback coordinates.
No game, build, replay, attachment or live-memory inspection. Addresses, offsets
and angle constants are hexadecimal; explicit counts decimal. Distance/bearing
roles are inferred from recomputation and yaw subtraction; no target identities
or AI intent are claimed.

A cache entry is8 bytes:float+0,bearinghalf+4,auxiliarybyte+6. Primarybanks
start3B41C0 and mask the signed-byte bank with3;secondarybanks3B3220 retain
the signed byte. Both use190-byte bank stride and8-byte unsigned actor6 slot
stride. The code does not locally establish validbank/slotranges.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5A98F0](../recomp/config/output_ovl/o2/o2_005A98F0_0x5a98f0.cpp) | `read_cached_target_distance_from_four_banks_candidate` | Probable role; full body reviewed | Nullactorreturnsfloat0. B=signedlow8(a1)&3,S=unsignedactor6; returnsfloat[3B41C0+190*B+8*S]. Noactoractive,slotrangeorbankreadinesscheck. Arithmeticstride190 is400 decimal,not100hex. |
| [o2 0x5A9950](../recomp/config/output_ovl/o2/o2_005A9950_0x5a9950.cpp) | `read_target_distance_with_xz_recompute_on_height_mismatch_candidate` | Probable role; full body reviewed | Nullreturns0. IfactorC94bit40andactorY!=Yat4A5C6C+10E0*signedlow8(a1),returns371880((targetX-sourceX)^2+(targetZ-sourceZ)^2),usingpositions4A5C68/70+sameoffset. Otherwisecachedfloat3B41C0+190*(signedlow8(a1)&3)+8*actor6. Directtargetindexunmaskedandsignedunlikecachebank. Noverticalcomponentinrecomputedvalue. |
| [o2 0x5A9A40](../recomp/config/output_ovl/o2/o2_005A9A40_0x5a9a40.cpp) | `read_cached_target_bearing_plus_half_turn_candidate` | Probable role; full body reviewed | Nullreturns0. Readsunsignedhalf[3B41C4+190*(signedlow8(a1)&3)+8*actor6],adds8000andreturnsunsignedlow16. No subtractionofactorheading; outputfullturnwrap. |
| [o2 0x5A9AA0](../recomp/config/output_ovl/o2/o2_005A9AA0_0x5a9aa0.cpp) | `read_cached_target_bearing_relative_to_actor_yaw_candidate` | Probable role; full body reviewed | Nullreturns0. (unsignedcachedbearinghalf+8000-signedactorYaw92)&FFFF,cache3B41C4/190maskedbank/8slot. Signednessofreturnedwrappedanglelefttocaller; returnsunsigned16bits. |
| [o2 0x5A9B10](../recomp/config/output_ovl/o2/o2_005A9B10_0x5a9b10.cpp) | `read_relative_target_bearing_or_actor_override_candidate` | Probable role; full body reviewed | Nullreturns0. C94bit80returnsunsignedhalfBD8directly. Elseidenticalrelativecacheformula5A9AA0,independentlyreviewed. Overrideisnotfurtherrotatedormaskedbybank. |
| [o2 0x5A9B90](../recomp/config/output_ovl/o2/o2_005A9B90_0x5a9b90.cpp) | `read_raw_cached_target_bearing_halfword` | Probable role; full body reviewed | Nullreturns0. Returnsunsignedhalf3B41C4+190*(signedlow8(a1)&3)+8*actor6. No8000additionoractorYawsubtraction; distinctentry. |
| [o2 0x5A9BF0](../recomp/config/output_ovl/o2/o2_005A9BF0_0x5a9bf0.cpp) | `read_raw_cached_target_auxiliary_byte_candidate` | Probable role; full body reviewed | Nullreturns0. Returnsunsignedbyte3B41C6+190*(signedlow8(a1)&3)+8*actor6. Semanticmeaningofbyteunresolved; noangleconversion. |
| [o2 0x5A9C50](../recomp/config/output_ovl/o2/o2_005A9C50_0x5a9c50.cpp) | `read_cached_target_auxiliary_byte_unless_actor_flag10_candidate` | Probable role; full body reviewed | NullactororC94bit10returns0;otherwiseunsignedbyteat3B41C6+190*maskedbank+8*slot. Unlike5A9BF0flag10suppressescachedvalue. No boolean-normalizationofnonzerovalue. |
| [o2 0x5A9CC0](../recomp/config/output_ovl/o2/o2_005A9CC0_0x5a9cc0.cpp) | `read_cached_secondary_target_distance_with_signed_bank_candidate` | Probable role; full body reviewed | Nullreturnsfloat0. Readsfloat3B3220+190*signedlow8(a1)+8*unsignedactor6. No&3maskunlike5A98F0; negativebanksnotlocallyrejected. Banktypeandvalidrangearecallercontracts. |
| [o2 0x5A9D20](../recomp/config/output_ovl/o2/o2_005A9D20_0x5a9d20.cpp) | `read_secondary_distance_with_alternate_target_xz_recompute_candidate` | Probable role; full body reviewed | Nullreturns0. C94bit40andactorY!=float[4170CC+1170*signedlow8(a1)] usesXZdistancevia371880,XYZaddresses4170C8/CC/D0+sameoffset. Otherwisecachedfloat3B3220+190*signedbank+8*actor6. Targetstride1170comesfromliteral32x-minusx,times8-plusx,times16; nottheordinary10E0actorstride. No unsignedbankmask. |
| [o2 0x5A9E10](../recomp/config/output_ovl/o2/o2_005A9E10_0x5a9e10.cpp) | `read_secondary_target_relative_bearing_with_signed_bank_candidate` | Probable role; full body reviewed | Nullreturns0. Returns(unsignedhalf[3B3224+190*signedlow8(a1)+8*actor6]+8000-signedyaw92)&FFFF. No&3bankmask. Arithmeticanglewrapretained. |
| [o2 0x5A9E70](../recomp/config/output_ovl/o2/o2_005A9E70_0x5a9e70.cpp) | `read_secondary_relative_bearing_or_actor_override_candidate` | Probable role; full body reviewed | Nullreturns0. C94bit80returnsunsignedBD8;otherwise5A9E10cacheformulaindependentlyreviewed. No read oftargetpositionoractivity. |
| [o2 0x5A9EF0](../recomp/config/output_ovl/o2/o2_005A9EF0_0x5a9ef0.cpp) | `refresh_actor_target_distance_and_bearing_from_related_record_candidate` | Probable role; full body reviewed | a0 actor,a1 relatedrecord. NullrelatedreturnswithoutupdatingC3C. OtherwisecopiesoldactorBD4floattoC3C beforecategorytest. Relatedbyte2==0 reads5A98F0(actor,signedrelated3),storesBD4;5A9AA0storesBD8. Relatedbyte2==1 usessecondary5A9CC0/5A9E10. OthercategoriesonlyperformoldBD4snapshot. Usescache-onlyhelpers,notheightrecomputing9950/9D20oroverrides. |

The direct-coordinate fallback and cache path intentionally retain different
index admission and target strides. These facts are not a reproduced bad lookup
or a slowdown cause. Cache producers and rebuild timing remain to be traced.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
