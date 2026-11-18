# ADXB decode window admission and PCM wrap accounting

Static File #1 US research, 2026-11-04. Original **SLUS_207.65**, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**. Both complete original bodies reviewed with the output reservation callback, lower predictor count, mono/stereo request adapters and wrap-copy callees. No vectors, decoding, audio, game or build executed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x125370](../recomp/config/output/sub_00125370_0x125370.cpp) | `admit_ADXB_predictor_block_count_against_input_output_and_sample_budgets_candidate` | Confirmed complete signed arithmetic and mono/stereo dispatch | Uses channels50, input blocks4C, samples/block58, capacity60, offset68, available6C and remaining70. Computes the four block bounds below with literal signed truncating division and adjustment; minimum selects request count. Channels==2 tails125318 stereo, otherwise1252D0 mono. Zero channels and zero samples/block execute compiler division BREAK paths; no general positivity or overflow admission. This is request geometry, not actual sample decoding or game timing. |
| [0x125518](../recomp/config/output/sub_00125518_0x125518.cpp) | `collect_ADX_predictor_result_and_copy_PCM_wrap_overflow_candidate` | Confirmed complete count conversion and copy routes | Lower completed count135060 is k. Encoded bytes94=blockbytes54*k. Initial sample count=floor_signed(samples/block58*k/channels50), reduced by the partial-budget gap below when k>=ceil_budget_blocks*channels. Stores produced samples90. If offset68+produced>=capacity40, calls stereo125488 whenchannels==2, elsemono1254F8, copying overflow from wrap extension back to channel base(s). Uses original borrowed base3C,totalhalfwords44 and capacity40. No loop for multiple full wraps, no clamp of negative produced values and no capacity check on copies. Does not advance outer stream counters or publish SJ spans here. |

For125370, define `N=word50`, `K=word4C`, `B=word58`, `C=word60`, `O=word68`, `A=word6C`, and `R=word70`. All divisions below mean the original signed integer division, not mathematical floor for negative values; additions and products retain original32-bit behavior.

```text
input_bound = K / N
window_bound = (C - O + B - 1) / B
budget_bound = (R + B - 1) / B
gap = B - ((R + B - 1) % B) - 1
if budget_bound < window_bound:
    window_bound += (O + window_bound * B - gap < C)
available_bound = (A + (R < A) * gap) / B
request_blocks = min(input_bound, available_bound, budget_bound, window_bound)
```

For125518, `gap` and `budget_bound` use the same B/R arithmetic. After reading k, its sample count is `(B*k)/N`; if `k >= budget_bound*N`, it subtracts `gap`. The literal wrap test uses decoder's original capacity40/base3C, whereas request admission uses the copied working fields60/5C; header setup initializes those copies but their identity must be preserved by later changes. The copy overflow is `O+produced-original_capacity`, not a modulo reduction. Lower key/history state and outer SJ ownership are independent.

The [pinned CVX comparison](recvx-crosscheck/AUDIO_SECOND_PASS.md) supports `ADXB_EvokeDecode`/`ADXB_EndDecode` as comparative roles, but finds a material result-threshold difference: CVX `ADXB_EndDecode` compares completed blocks directly with the budget block count, while Outbreak12559C multiplies that bound by the channel count before1255B8 tests it. Outbreak's existing formula above is authoritative. Do not replace it with the older source's stereo edge arithmetic merely because the surrounding flow matches.

Addresses and structure offsets are hexadecimal; formula variables and arithmetic constants are ordinary integer notation. This is a static reconstruction of control arithmetic, not a tested native implementation. Related: [predictor request adapters and copy kernels](SYMBOLS_ADX_PREDICTOR_CONTEXT_AND_WORK_DISPATCH.md), [outer reservation and publication](SYMBOLS_ADXB_HEADER_INPUT_AND_OUTPUT_SERVICE.md), [central index](FUNCTION_INDEX.md).
