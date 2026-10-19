The first variant is rejected for integration. All 320 actual capture outputs
matched, but one of 354 complete-output artifacts differed: static nonfinite
control 7 changed three words (VF2.y, VF19.y and data quad 1017.y) from payload
7FC01234 to FFC00000. Its median isolated benchmark also regressed from 18.2099
to 37.5884 ms. PE executable code grew from 86,547 to 3,073,763 bytes. Those original
validation1 files and logs remain unchanged. The complete mismatch inventory is
`build-ninja/m2-vu-block-proposal/mismatches-validation1.json`.

Variant2 is separate under `build-ninja/m2-vu-block-proposal/variant2`. It freezes
the exact earlier live source, SHA256
`CC7D01BD79741388ABB75D8917B2BFC5469AA9107B4E16D30D780F3927C4679B`,
recovered mechanically before the original baseline's private test hooks. It
does not read a newer production version into this comparison.

Root command, after active native work finishes:

```
tools\vu_block_check\run2.bat 11 validation2
```

The updated generator normalizes decoded source to LF and writes UTF-8 bytes,
preventing the CRCRLF doubling. Both generated variant2 files have zero CR bytes.
Standalone block kernels are explicitly noinline; instruction-pair templates
remain force-inline. Copied frozen decoder expressions and their local constants
are made constexpr so specialization does not depend on helper-call inlining
after a large handler expansion. Arithmetic formulas and operand order remain
the frozen source's own expressions. Assembly listings are requested for root's
post-build code-size/folding audit.

Each compiled pair checks only arithmetic operands affecting a written lane or
CLIP. Bit guards accept signed zero and finite magnitudes at most 2^59. This
bounds upper products and sums below float overflow; raw integer conversions
and register/memory bit copies are handled separately. An unsafe pair is stopped
BEFORE upper or lower executes. The kernel returns its completed-pair count and
the original loop executes that pair and remainder with exact original NaN
payload/operand ordering. Cycle accounting, pending branches and delay slots
retain their original values at this boundary. No state/data rollback is used.

Lower arithmetic also checks its selected VF operands. If the same upper pair
can write one of those lanes, the entire pair falls back before any side effect.
The five actual lower-arithmetic pairs in the two frozen blocks have no such
hazard; the explicit inventory is `variant2/pair-hazard-audit.json`. Finite lower
division may produce infinity; its unique original operation is retained and
later arithmetic consumption is guarded. LQ/SQ, MFIR/MFP and integer transfers
remain exact bit copies, so a memory NaN is preserved until its arithmetic
consumer falls back. Unread memory NaNs do not cause blanket data rejection.
Host floating-point status flags are not part of this VU state/GIF oracle;
guest state, data and ordered packets remain fully compared.

Planned oracle: 368 byte-identical artifacts (320 captures, eight original
controls, 40 block controls) and 91 numerical assertions. The original NaN
control is retained. Added controls isolate quiet/signaling NaN and infinity
memory loads, extreme finite inputs, signaling input payloads, unrelated unread
memory NaNs compared with a finite reference's admission/fallback counts, and
an unknown replacement pair with finite upper multiply overflow followed by a
dependent lower Inf/Inf division. The replacement stays wholly generic through
the code identity guard; its expected infinity/NaN is independently checked.

No compilation, execution or benchmark was performed by this agent. A repaired
oracle alone cannot authorize integration: the new whole-capture benchmark and
code-size audit must show a useful result. If templates remain regressive,
this variant should be rejected in favor of a compact kernel approach.
