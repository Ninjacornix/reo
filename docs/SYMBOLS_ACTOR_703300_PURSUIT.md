# Actor 703300 cached-peer pursuit states

Static File #1 US research, 2026-11-04. Six complete original bodies reviewed.
Addresses and offsets are hex unless marked decimal. Actor identity, original
state names and timer units remain unknown. No target execution or engine
changes; these are source contracts, not measured performance findings.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x7057B0](../recomp/config/output_ovl/o2/o2_007057B0_0x7057b0.cpp) | `dispatch_actor_703300_primary_six_cached_peer_pursuit_candidate` | High routing | Caches actor24 at75A4F8. Null calls707110 and returns. Otherwise copies peer XYZ38..40 to actorC44..C4C, then73D9A0[byte9](actor). Two owned slots are705830/705CA0. Copying target position occurs before the secondary handler can substitute a route point. |
| [o2 0x705830](../recomp/config/output_ovl/o2/o2_00705830_0x705830.cpp) | `advance_actor_703300_primary_six_default_pursuit_candidate` | High mechanics; probable role | ORs115bit1. Phase0/FF enters1 and orients C44 withAAA0; failed orientation starts descriptorA/blend decimal10 and2,58C780,returns. Accepted orientation selects descriptor3 unless motion73DCC6; FF C36=40. Phase1 unless D65 may706260: nonzero sets secondary1 and starts descriptor4 at returned frame/blend10, early-return. Otherwise advances; D48==0 permits703E90, then634C00 cached peer distance500/angle4718/argument0 followed7075A0, each successful selection exits. Phase2 completion starts3,phase3,C=4/factor; phase3 expiry XORs yaw8000 and reenters1. Common tail uses707840 auxiliary byte to choose route detour: D68-gated E expiry or first detour sets BD4=0; XZdistance<=100 renews634040 route point and E=600/factor; sets D68. Zero auxiliary clears D68 and copies peer X/Z. Selected peer BF8 metric0 selects5/0/AFF/B0. Otherwise turns toward C44 using BDC/E38 when C83, BDA/6AA4 and signed C84 otherwise. |
| [o2 0x705CA0](../recomp/config/output_ovl/o2/o2_00705CA0_0x705ca0.cpp) | `advance_actor_703300_primary_six_alternate_colored_pursuit_candidate` | High mechanics; probable role | Copies shared72905C->word8 color into C70/1AC/1BC each call. Phase0/FF seeds E=decimal240/factor and1; failedAAA0 orientation selects3/descriptorA with115bit1 and58C780; success starts descriptor4 unless motion211, then5DA2C0(actor,70,1) with115 cleared. FF C36=40. Phase1 advances with32FF, first decrements E: expiry selects2/3/AFF/B0 immediately. Otherwise decrements/clamps C; expired C uses706350, positive C uses BD4<=150, either admitted result starts descriptor5/blend5,phase2,58C780 and115bit1. Rejected transition plus peer BF8metric0 selects phase5. Phase2 completion selects1/0/0/0; phase3 completion starts descriptor4,phase4,timer12=4/factor; phase4 expiry XORs yaw8000,phase1,5DA2C0(70,1),1150. Phase5 completion selects5/0/AFF/B0. Common707840 route detour resembles705830, but turns with four times BDC or BDA and t0=1 on the non-C83 path; no default BF8 fallback in this tail. |
| [o2 0x706350](../recomp/config/output_ovl/o2/o2_00706350_0x706350.cpp) | `test_actor_703300_near_transition_distance_with_peer_mode_candidate` | High mechanics; probable role | Returns1 for BD4<=decimal150. Also accepts up to200 if cached peer B9B is2/3 or actor D6B nonzero. NaN fails both ordered comparisons. Reads cached peer without a new null check; caller performs binding. |
| [o2 0x7075A0](../recomp/config/output_ovl/o2/o2_007075A0_0x7075a0.cpp) | `try_actor_703300_distance_variant_weighted_primary_two_candidate` | High mechanics; probable role |707BA0 fallback returns0 even though it may change state. Otherwise random-low4 selects73DB90 +80*byte4 +40*(BD4>decimal120). Row byte0 FF rejects, seeds D48=180/factor and returns0. Accepted row clears D48 and copies bytes0..2 to8..A, then A=FF while B is preserved. Selected2/3 with D50 nonzero changes secondary to0. Second random-low2 seeds E from73DA80/factor; returns1. Four owned sixteen-row distributions documented below; row byte3 is not consumed by this body. |
| [o2 0x707840](../recomp/config/output_ovl/o2/o2_00707840_0x707840.cpp) | `read_actor_703300_signed_cached_target_auxiliary_byte_candidate` | High mechanics; probable role | Signed-low8 argument a1 passes to5A9BF0(actor,index), then returns signed-low8 of its result. Existing cached-target mapping shows5A9BF0 returns the unsigned auxiliary byte3B41C6+190*(signed index&3)+8*actor6, or0 for null actor. This adapter can therefore return negative values; it does not normalize to boolean. |

Owned73DB90 four sixteen-row banks, counts in decimal:

| Bank address | Four-byte row counts |
| --- | --- |
| 73DB90 | 9x(2,0,0,0),6x(2,1,0,0),1x(2,3,0,0) |
| 73DBD0 | 8x(2,0,0,0),3x(2,3,0,0),5x(255,0,0,1) |
| 73DC10 | 9x(2,0,0,0),4x(2,1,0,0),1x(2,3,0,0),2x(2,2,0,0) |
| 73DC50 | 7x(2,0,0,0),4x(2,3,0,0),3x(2,2,0,0),2x(255,0,0,1) |

The body derives the first bank selector directly from actor byte4; no new
range guard or assumption that every byte4 value is valid is introduced.
Timer factor is byte74F200, not a newly measured frame rate. Route/animation
callback counts are not treated as original global game updates.

Related [bootstrap](SYMBOLS_ACTOR_703300_BOOTSTRAP.md),
[primary two](SYMBOLS_ACTOR_703300_PRIMARY_TWO.md), and
[shared controls](SYMBOLS_ACTOR_703300_SHARED_CONTROLS.md).
