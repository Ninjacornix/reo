# Actor CDD contact flag, input reduction and category sampling

Static File #1 US research, 2026-11-04. Four complete original bodies reviewed. Hexadecimal addresses/fields/masks; explicit decimal percentages/counts. Local mechanics high confidence, gameplay meaning probable. No target execution, attachment, build, replay or slowdown inference.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x662890](../recomp/config/output_ovl/o2/o2_00662890_0x662890.cpp) | `promote_actor_cdd_high_flag_from_action_five_resource_contact_candidate` | High mechanics; role probable | Requires action8==5 and BA4 bit800000. Class0,1B02D0()==1,FF0 nonzero additionally ORs F80 mask440. Requires F80&440,C7C nonzero,metadata719A60+44*CA8 word0 bit800,then signed resource half3C5654+3C*C7C!=0. On admission OR CDD80,return1;else0. Nonzero signed quantity, not strictly positive; flag never cleared here. |
| [o2 0x6629C0](../recomp/config/output_ovl/o2/o2_006629C0_0x6629c0.cpp) | `calculate_actor_cdd_reduction_from_input_edges_or_owned_actor_gate_candidate` | High mechanics; role probable | Class0+1B02D0()==1+FF0 nonzero delegates662B10(actor). Other paths return Boolean(F78&F)+2*Boolean(F78&230), range0..3. Incoming a1 low7 passed by662A60 is not read locally. |
| [o2 0x662B10](../recomp/config/output_ovl/o2/o2_00662B10_0x662b10.cpp) | `sample_actor_category_cdd_reduction_at_global_byte_cadence_candidate` | High mechanics; role probable | Return0 unless unsigned byte4BAE03 modulo5 when3243CC nonzero or10 when zero is0. Then low16 RNG1AEC80(1)%100 converted float compared strictly to71AD60[A.B98]; successful sample returns A hexadecimal (decimal10),else0. No actor-class/ownership guard inside; caller6629C0 supplies it. |
| [o2 0x662BC0](../recomp/config/output_ovl/o2/o2_00662BC0_0x662bc0.cpp) | `choose_actor_ba4_flag800000_from_category_probability_or_default_candidate` | High mechanics; role probable | Class0,1B02D0()==1,FF0 nonzero ->low16 RNG1AEC80(1)%100<71AD80[A.B98] sets BA4 bit800000; failed ordered comparison clears it. Other actors/default paths always set bit. No cadence gate or normalized return; separate table from662B10. |

These close the two immediate callees of662A60 in [numeric actor entries](SYMBOLS_ACTOR_NUMERIC_D7_DF_ENTRIES.md).662890 can mutate F80 and CDD before662A60 reads its magnitude/high flag. The reducer6629C0 does not use incoming a1, and category sampling returns either0 or decimal10. Combined with high80 multiplier2 in662A60, low7 narrowing remains part of the exact original arithmetic.

Global byte4BAE03 is a sampled counter, not measured FPS or elapsed time. Modulo cadence observes only that byte; its producer/wrap behavior is not inferred. Category byteB98 indexes both float arrays without a local bound; the physically adjacent8-float blocks below are not a valid actor-category proof. Strict random<threshold means equality and NaN reject. The RNG low16 modulo100 distribution is original, not replaced by a host probability function.

662890 tests actorCA8 metadata word and separate resource ID C7C quantity field; neither field is treated as a host pointer. Any nonzero signed half admits.662BC0 sets BA4 flag unconditionally outside its particular owned-actor gate; flag names retain numeric800000, rather than an unverified game status enum.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Physical span | Float32 values decimal | SHA256 |
| --- | --- | --- |
| 71AD60..71AD7F | 60,50,50,40,40,40,30,30 | `f2e6ba1d999f912f7454720986b3abd958299f1fb80cdaca98a52fdda0a76ca7` |
| 71AD80..71AD9F | 50,50,40,50,30,20,20,50 | `2964c854cb00b557b92ce455d9bf9add220c417e2dee5f61e6eba3c30bab5ac6` |

No original character IDs, effective per-second rate, runtime ownership state or slowdown responsibility is claimed. These are original guest-body mappings; native override/executable provenance remains separate.

Owned-word audit:4 rows,189 distinct instruction words verified,16 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited.
