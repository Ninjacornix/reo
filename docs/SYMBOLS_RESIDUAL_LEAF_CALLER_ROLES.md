# Caller-supported roles for resident identity and diagnostic leaves

Static File #1 US review, 2026-11-05. Owned ELF SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
No game was launched, built, attached to, sampled or modified. These are purpose
annotations from original instructions and their connected callers, not new native
implementations or measurements of a slowdown.

Earlier notebooks withheld these leaves because their instruction shapes alone
did not establish a subsystem. This review admits the six below using their actual
call contracts. The four identity functions remain identity functions: the proposed
names describe their use, without inventing validation, relocation or conversion.
They have independently established JAL entry points, unlike arbitrary cuts inside
a larger function. Original public function/type names remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [main 0x1A1DA0](../recomp/config/output/sub_001A1DA0_0x1a1da0.cpp) | `pass_through_raw_curve_set_header_pointer` | Confirmed identity; caller-supported curve header role | Complete JR/DADDU body returns a0 unchanged in v0. Four original JAL callers: 1A1DB0 uses v0+14 as the variable-track origin; 1A1E00 reads header C and float10; 1A2200 tests header byte0 before curve conversion; 1A2AD0 reads track count at+4. Thus it is the shared raw curve header pointer adapter, not a decoder, validator or relocator. |
| [main 0x1A2C80](../recomp/config/output/sub_001A2C80_0x1a2c80.cpp) | `pass_through_raw_model_chunk_header_pointer` | Confirmed identity; caller-supported chunk header role | Three original JAL callers 1A2AF0/1A2C90/1A2CF0 use its unchanged v0 as the raw header with count+4, high-bit flag word0 and variable chunks beginning+C. Both finders advance by chunk word8. It does not load a pointer through a handle or validate the model. Distinct from the nested full-word resource path through 1A3590. |
| [main 0x1A3590](../recomp/config/output/sub_001A3590_0x1a3590.cpp) | `pass_through_typed_model_resource_header_pointer` | Confirmed identity; caller-supported typed resource role | Six original JAL callers: 1A31B0/3210 pass unchanged v0 to full-word type2 presence/lookup; 1A32B0/3310 do the same for type9; 1A33E0 uses typeA; 1A3D90 constructs a selected mesh import descriptor. The typed section walker is 1A35F0, not this leaf. No type conversion, pointer fixup or error normalization occurs here. |
| [main 0x1D66D0](../recomp/config/output/sub_001D66D0_0x1d66d0.cpp) | `pass_through_tcp_rpc_result_for_game_adapter` | Confirmed identity; caller-supported network result role | Seven original JAL callers 1D68F0/6930/6A60/6A90/6AF0/6B50/6B80 pass the result of their SNIOP TCP operation, after sign-extending its low16 into a0. This leaf preserves that value. 1D6930 tests its sign; 1D6A90 separately substitutes requested length only when the preserved status is0. The signed16 narrowing belongs to callers, not this leaf. It does not translate error numbers or touch the network. |
| [main 0x1A9190](../recomp/config/output/sub_001A9190_0x1a9190.cpp) | `disabled_positioned_debug_text_sink_candidate` | Probable positioned debug-text API; confirmed disabled body | Nine original JAL sites in o2:6955A0, o3:571150 and o3:576030. The simple-component editor supplies (2,2B,NUMBER-format,selection) and (2,2C,POS-format,promoted float arguments). The avatar updater supplies column2F and lines14+4*i through16+4*i, with format pointer621080 and position coordinates promoted via1118B8. The full36-byte body only makes/restores a0x60-byte stack frame, saves a3/t0..t3 and returns1. It emits no text; historical caller descriptions saying prints describe the caller's requested action. Exact original API and coordinate units remain unproved. |
| [main 0x1B3830](../recomp/config/output/sub_001B3830_0x1b3830.cpp) | `disabled_variadic_engine_diagnostic_sink` | Confirmed disabled body; caller-supported diagnostic role | Seven original JAL sites in model-resource, sound and actor callers. At1B2A9C a0 points to owned24FED0 NOT INITIALIZE MODEL_WORK; at1B2AD8/AF8 it points to24FEF0 PULL MODEL_WORK FAIL. Sound overflow path1AD374 passes24FDE8 SND DATA OVER!. Complete40-byte body saves variadic a1..t3 in its0x50-byte stack frame and returns without formatting, writing a log, trapping or changing v0. Calling it does not stop the caller's error path. Original public API name remains unknown. |

Offsets above are hexadecimal. `DADDU v0,a0,zero` is the actual identity delay
instruction; no pointer dereference is implicit in that operation. The same two
words can legitimately have different caller roles without being different
algorithms.

Connected parser evidence is in [raw curves](SYMBOLS_RAW_CURVE_SET_PACKING.md),
[raw model resources](SYMBOLS_RAW_MODEL_CHUNKS_AND_FORESTS.md), and
[game TCP adapters](SYMBOLS_SNIOP_GAME_ADAPTERS.md). The positioned debug-text
caller's arguments are recorded in
[the simple-component editor](SYMBOLS_O2_REPEATED_COMPONENT_ANIMATION_AND_DRAW.md).

The offline audit [review_residual_leaf_roles.py](../tools/function_index/review_residual_leaf_roles.py)
verified all nine original catalogue intervals against the hash-bound ELF:
38 generated instruction-comment words, no conflicts and no omitted nonzero
words. The two diagnostic intervals are36 and40 **decimal bytes**, respectively;
the earlier leaf snapshot's24/28 values were hexadecimal quantities without a
radix marker. The audit's JSON records decimal sizes through start/end addresses,
full original words and per-interval SHA-256 values.

The audit also scans **1,445,184 aligned file-backed words** across main PT_LOAD
segments and all nine hash-bound overlay images for literal pointers and direct
J/JAL encodings. All36 raw direct-transfer candidates to the six admitted entries
match the36 indexed JAL sites, asserted as exact image/site/kind sets. There are
no aligned literal-pointer candidates; the additional every-byte-offset search
for literal pointers and cached/uncached EE aliases also finds none.
Raw scanning alone does not prove execution or exclude computed/relocated
references, BSS registration, or references hidden inside encoded carriers.

Three entries stay unannotated after this review:

| Candidate | Exact finding | Missing evidence |
| --- | --- | --- |
| main:0x11707C | Only JR ra lies inside this four-byte catalogue interval. Its architectural delay word at117080 is **27BDFFC0**, the following SifInitRpc entry's SP-=40 instruction. The preceding cache-writeback function returns at117074 with a zero delay word117078. | No indexed callers, raw direct transfers or aligned literal pointers. An independent callable role/boundary is unproved; do not silently borrow a NOP delay slot or name it a harmless return stub. |
| main:0x132FB0 | Five-word frame/save/restore tail to12C8E8; its actual target only returns. The branch delay restores SP. | No indexed callers, raw direct transfers or aligned literal pointers. Neighbouring ADXT code does not prove this dormant adapter's original public control/API role. |
| main:0x132FC8 | Five-word frame/save/restore tail to12C8F0; target returns0. The branch delay restores SP. | Same negative reference result and unknown original purpose. A numeric constant is not evidence of a particular RNA/ADXT control. |

These negative scans are bounded discovery results, not proof that the entries
cannot ever be called. They do not receive purpose-annotation credit.
