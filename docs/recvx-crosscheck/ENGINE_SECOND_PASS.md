# Engine comparison: second static pass

Research date: 2026-11-05. This pass adds bounded function-contract comparisons to
[ENGINE_BOUNDARIES.md](ENGINE_BOUNDARIES.md). It found useful common mathematics,
but no evidence for importing a CVX engine function name or structure into the
Outbreak catalogue. No demonstrated error in an authoritative Outbreak mapping
was found in the bodies reviewed below. The new detail resolves omissions in
the earlier cross-check, rather than increasing the mapped-function count.

No game, reference executable, build, replay, debugger or live memory was used.
Reference source describes that project's implementation; its documented tests
and performance figures are not tests or measurements performed here.

## Inputs and coverage

The clean original decomp checkout is pinned to
`657b0c0c9489943116c71f151804ad7304fca975`. The clean enhanced-port checkout
actually inspected in this pass is pinned to
`2fa8a14224ebb92d0103a8c828e6a032c338d6d4`. This is a different revision from
`68ad6901932f66ac17a2d4a1da86350485a0008e` cited by the earlier
[SYMBOLS overview](../SYMBOLS.md#7-code-veronica-comparison-techniques-to-reuse).
These revisions must not be silently substituted for each other.

Owned Outbreak evidence is File #1 US `SLUS_207.65`, SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
The compared o0 and o2 source comments were checked against their hash-bound
owned images using [the focused audit](../../tools/function_index/audit_recvx_engine_second_pass.py).
Its local receipt is `build-function-index/recvx-engine-second-pass-audit.json`:
**12 complete catalogue bodies, 377 matching instruction comments, seven omitted
zero words, zero conflicts and zero omitted nonzero words**. The audit validates
source-to-image correspondence; the semantic comparisons below come from reading
the complete relevant bodies, including branch and delay-slot effects.

This is not an all-functions equivalence proof. CVX sources below are selected
complete functions; the enhanced import converter is inspected at the cited
conversion stages, not independently verified end to end. Existing Outbreak
Clay, actor and pose notebooks supply separately qualified context.

## Concrete utility comparisons

| Comparison | Supported common contract | Differences that prevent aliasing or an unchecked replacement |
| --- | --- | --- |
| CVX `njCalcVector` versus Outbreak main `0x1919D0` | Both multiply an input XYZ vector by the first three matrix vectors using `VMULAX.xyz`, `VMADDAY.xyz`, `VMADDZ.xyz`, omit translation and store XYZ. | CVX arguments are matrix/input/output and a null matrix selects the global current matrix; Outbreak arguments are output/input/matrix with no such fallback. Both first capture the input XYZ, but matching this ordinary algebra does not prove arbitrary matrix/output alias behaviour, VU state or exceptional FP equivalence. |
| CVX `njGetTranslation` versus main `0x1900E0` | Both obtain matrix offsets `0x30`, `0x34`, `0x38` and write output XYZ. | CVX accepts matrix/output, falls back to a current matrix and loads all three words before storing. Outbreak accepts output/matrix and alternates each load with its store. For example output at matrix+`0x34` can change a later Outbreak input, whereas CVX captures all three first. |
| CVX `njUnitRotPortion` versus main `0x18FE20` | Both reset three matrix basis vectors. | CVX stores complete unit-vector quadwords, including W, with a null/current-matrix fallback. Outbreak copies only XYZ from shared template `0x294E00`, preserves each destination W and leaves the translation vector alone. The existing Outbreak label correctly says **shared template**, without assuming immutable identity contents. |
| CVX `njUnitVector` versus main `0x17EC98` | Both normalize XYZ without a local zero-length rejection. | CVX operates in place on a 12-byte XYZ vector, uses `VRSQRT`, and returns the original magnitude as squared-length times reciprocal square root. Outbreak accepts separate output/input quadword pointers, uses `VSQRT` then `VDIV`, writes a 16-byte result with W zero, and preserves conditional interrupt state through `0x11D660`/`0x11D6B8`. These instruction and ABI differences matter even before testing unusual floats. |

CVX evidence: complete functions in pinned
[ps2_NaMatrix.c](https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/ps2/veronica/prog/ps2_NaMatrix.c#L1412)
(`njCalcVector` lines 1412–1451; `njUnitVector` 1454–1499;
`njGetTranslation` 159–179; `njUnitRotPortion` 199–220).
Outbreak evidence: [vector transform](../../recomp/config/output/sub_001919D0_0x1919d0.cpp),
[translation extraction](../../recomp/config/output/sub_001900E0_0x1900e0.cpp),
[basis reset](../../recomp/config/output/sub_0018FE20_0x18fe20.cpp),
[normalization](../../recomp/config/output/sub_0017EC98_0x17ec98.cpp),
[render math notes](../SYMBOLS_RENDER_MATH.md) and
[VU0 math notes](../SYMBOLS_RESIDENT_VU0_VECTOR_MATRIX_ARITHMETIC.md).

The transform and extraction roles are supported local matches. They do not
establish a shared library implementation or a recovered Ninja symbol name.
No catalogue aliases were promoted from these comparisons.

## Trigonometry and animation: similar vocabulary, different contracts

CVX `_Make_SinTable` fills 16,384 floats with `sinf(0.0000958738f * i)`.
Its complete `njSin` and `njCos` bodies mask a turn angle to `0x3FFF`, select
quadrants through bits `0x4000`/`0x8000`, and mirror the table with `16383-i`.
Outbreak o0 `0x3700C0`/`0x370100` also mask an input to its low 16 bits, but
convert it to float and multiply by owned constant `0x38C90FDB`
(approximately `2*pi/65536`), then tail-call the corresponding main path.
The fully read main `0x18F340`/`0x18F470` paths perform phase reduction and VU
polynomial evaluation; the sine candidate additionally computes a signed square
root of a polynomial complement. They do not use CVX's quadrant lookup.

Thus the **turn16 angle convention** is a useful shared interpretation, not
evidence of identical numerical output. Neither host `sinf` nor CVX's lookup is
validated as an Outbreak replacement. CVX table endpoint mirroring, Outbreak
range reduction, rounding and PS2 exceptional-float behaviour remain relevant.
See pinned [ps2_NaMath.c](https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/ps2/veronica/prog/ps2_NaMath.c#L7),
[Outbreak wrappers](../SYMBOLS_OVERLAY_MATH.md) and
[main math](../SYMBOLS_RENDER_MATH.md).

CVX `njLinear` interpolates two adjacent XYZ triples as
`(second-first)*frame+first`, writing XYZ. Outbreak main `0x18F1E0` is instead
a scalar key sampler: with sample `x`, times `t0/t1` and values `v0/v1`, its
operation order evaluates
`((v1-v0)/(t1-t0))*x + (t1*v0-t0*v1)/(t1-t0)`.
There is no local equal-time guard. The formulas can describe the same ordinary
line after a change of inputs, but their APIs, data layouts, division and
rounding order are different. Calling both “linear interpolation” is supported;
transferring the original name or assuming bitwise parity is not.

The complete CVX [bhSetMotion](https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/ps2/veronica/prog/Motion.c#L21)
selects normal/fast/slow and interpolation variants, consumes `BH_PWORK` motion
state, indexes attributes with `frm_no >> 16`, and advances/bounds its **16.16
frame field**. Outbreak main
[0x1930F0](../../recomp/config/output/sub_001930F0_0x1930f0.cpp) receives a
floating sample frame, resolves a model track through `0x192D10` and calls
`0x193140`; its own body returns one and has no local missing-track guard.
It is a different layer from CVX's complete actor-motion controller. Existing
[animation mapping](../SYMBOLS_ANIMATION.md) already preserves that boundary.
No common actor-object layout was established by this comparison.

## Script interpretation: directly different dispatch formats

The complete pinned CVX `bhInitEvent` initializes 16 `bhEtask` records and binds
room `scd0`/`scd1`. Complete `bhEventScheduler2` loops those active task records,
sets `bhScePtr` from task data, and dispatches via
`bhScenarioJmpT[*bhScePtr]`: an **unsigned-byte opcode**. It uses the global
condition nesting/stack and saves the updated script pointer back into the task.
These are statements about those functions, not a claim that all CVX script
records have one fixed size. See pinned
[event.c](https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/ps2/veronica/prog/event.c#L13033).

Outbreak o2 [0x68C660](../../recomp/config/output_ovl/o2/o2_0068C660_0x68c660.cpp)
contains a mode-specific alternative call to `0x7003E0`; the compared local path
dispatches the **low 24 bits of a 32-bit record header** through `0x717830`,
passes payload at record+4, and advances by `4*(1 << headerHighByte)` when the
handler result is zero. Guest variable-shift rules apply. A nonzero slot
countdown decrements on a call and returns; complete handler
[0x68CE90](../../recomp/config/output_ovl/o2/o2_0068CE90_0x68ce90.cpp) merely stores
a payload word in that countdown. A handler's numeric return value also controls
continuation/reload/yield, unlike a blanket “zero means script abort” reading.
The existing [VM notebook](../SYMBOLS_SCRIPT_VM.md) is consistent with these
original words. CVX's event table and task structure cannot supply missing
Outbreak opcode names, time units or actor slots.

## What the enhanced native renderer actually provides

At enhanced pin `2fa8a14`, complete
[pc_native_strip](https://github.com/aikatore/recvx-enhanced-port/blob/2fa8a14224ebb92d0103a8c828e6a032c338d6d4/pc/glue/native_glue.c#L109)
consumes CVX `VU1_STRIP_BUF` records, strip index/UV triples and recovered CVX
material/view globals. It computes CVX colour modes, homogeneous positions,
fog, culling and clip distances before emitting a native strip. Its 64-entry
local output, CVX projection constants and GS colour conversion are concrete
contracts, not a generic replacement for every PS2 draw submission.

The inspected complete `vu0_calcpoint_n`, `calcpoint_n_native` and `vu1_callms`
paths retain reference execution and state checks. In check mode, the batched
native CALCPOINT route compares output bytes **and final VU state** against
per-vertex calls; per-vertex/static calls can themselves be checked against the
interpreter. `RECVX_VU_INTERP` selects the interpreter, while normal VU1 calls
select static execution. This is source evidence for an admission and comparison
design, not proof that Outbreak programs match those CVX microprograms. See
pinned [vu.c](https://github.com/aikatore/recvx-enhanced-port/blob/2fa8a14224ebb92d0103a8c828e6a032c338d6d4/pc/src/ps2/vu.c#L899).

The enhanced [architecture](https://github.com/aikatore/recvx-enhanced-port/blob/2fa8a14224ebb92d0103a8c828e6a032c338d6d4/docs/ARCHITECTURE.md#L199)
also explicitly retains GS state/memory, render targets and remaining VIF/DMA.
Its native geometry is inserted into original sorted order using marker packets;
not all primitives bypass the GS path. This supports the earlier overview's
incremental replacement description. It does not support a claim that the port
removed all PS2 machinery, or that copying its renderer would bypass Outbreak's
different Clay/material/palette contracts without new adapters and verification.

## Outbreak import is a conversion boundary, not shared engine proof

This enhanced revision includes an Outbreak importer, an omission in the older
engine comparison worth recording. Its admitted disc is specifically **File #2
US `SLUS_209.84`**, checked by `ob2.c`; it is not our owned File #1 executable.
The converter is therefore useful independent reference material, not an
authoritative decoder for unreviewed File #1 binary layouts.

Inspected `imp_write_cvxm` stages merge discarded skeleton nodes into kept
ancestors, remap weights, reorder nodes, rotate coordinates 180 degrees about Y,
apply a supplied scale (the caller supplies `0.1f`), and emit new Ninja chunk
strips and `0x34`-byte `NJS_CNK_OBJECT` records. The new output also carries
imported per-vertex skin data. The reference documentation explicitly explains
that CVX's own node/parent skinning does not express Outbreak's arbitrary joint
weights, so the enhanced port supplies separate imported-model skinning.
See [converter](https://github.com/aikatore/recvx-enhanced-port/blob/2fa8a14224ebb92d0103a8c828e6a032c338d6d4/pc/src/import/impmodel.c#L399),
[disc gate and caller](https://github.com/aikatore/recvx-enhanced-port/blob/2fa8a14224ebb92d0103a8c828e6a032c338d6d4/pc/src/import/ob2.c#L527),
and [import documentation](https://github.com/aikatore/recvx-enhanced-port/blob/2fa8a14224ebb92d0103a8c828e6a032c338d6d4/docs/IMPORT_OUTBREAK.md#L204).

Those conversion steps are positive evidence of an asset adapter. They do not
establish shared actor structures, animation encodings, callback signatures or
native render-program identity. No importer was run and no visual or performance
claim from its documentation was independently reproduced here.

## Result and remaining work

The strongest additions are two supported local math roles, precise differences
for trig/reset/normalization/interpolation, the byte-versus-24-bit script
dispatch boundary, and the enhanced port's actual CVX-specific native admission
and asset-conversion boundaries. Existing engine boundary statements and the
reviewed authoritative Outbreak labels remain supported; **no original symbol
name, actor layout, opcode identity or rendering equivalence was newly proven**.

Useful next work is to choose an observed Outbreak hot boundary, specify its
actual input/output and retained VU/GS state, and compare a candidate replacement
against that original case. CVX demonstrates how to keep such reference checks.
It cannot decide which Outbreak boundary is responsible for a player's slowdown,
nor whether a candidate changes game timing, without Outbreak-specific evidence.
