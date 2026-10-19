Coordinator-only isolated SSE2 broadcast VU experiment:
`tools\vu_packed_check\run.bat 11 validation1`.
Use a fresh output suffix for later runs. No native/full-runtime build is needed.
Production source and headers remain unchanged. Frozen baseline SHA256:
`6BC400311D600F5522D2177F7077BA156B4E2563BD1885477F3ED160F77AEB47`.
Source copies live in `build-ninja/m2-vu-packed`.

Actual Release object disassembly shows four scalar MULSS/ADDSS operations and
four TEST/JE scalar masked-store pairs. There are no MULPS/ADDPS instructions
inside execUpper, and applyDest/broadcast are already inlined. Reached weighted
trace prefixes contain MADDA-bc 44032, MULA-bc 22350, MADDbc 22172 operations;
static prefixes contain 3517, 3473, 2337 respectively. Those prefixes are bounded
at 1024 instruction pairs per call and do not establish whole-game CPU share.

Only these three broadcast families are intercepted. Four lane multiplications
use SSE2 packed MULPS, followed by a separate ADDPS for MADD variants. Loads are
unaligned-safe; all inputs are loaded before any destination write. Full-mask
stores avoid scalar branches; other masks select raw bits with an integer mask
table and preserve all unwritten lanes. VF0/VI0 restoration, I/E flags, branch
and E delays, lower execution, captures and timing remain in the original loop.
Every nonfinite source/scalar/used accumulator stays on the existing scalar
path, preserving its NaN operand-selection behavior. Finite multiplication
preserves bits even for MULA.x's opposite scalar operand order. Non-x86 targets
retain the complete existing scalar handler through compile-time guards. No
other opcode, decoded cache, JIT, or header/API is changed.

The same complete 320 original weighted/static input snapshots and eight
instruction-control fixtures used by the NOP oracle are replayed. Full resulting
VU1State, all 16KiB VU data, and ordered packet lengths/bytes must match across
baseline/candidate. The additional packed matrix has 13440 cases: all 16 masks,
four broadcast selectors, three instruction families, five alias/VF0 layouts,
seven bit-pattern sets, and denormal handling both enabled and disabled.
Independent scalar SSE lane arithmetic checks exact numeric bits and MXCSR
exception flags; complete state comparison also checks unwritten lanes, source
registers, VF0, ACC and control state. Its data remains zero and emits no packets.
Inputs include a nonfused-rounding counterexample, tiny/largest subnormals,
signed zero, large finite/overflow, infinities, distinct QNaN/SNaN payloads,
nonfinite accumulators, and old destination NaNs during finite packed writes.

Expected outputs: 13453 assertions and 329 binary artifacts on each side (320
captured + 8 controls + 1 packed-matrix aggregate). The comparator reads complete
actual bytes and validates all matrix records. The in-memory 320-input benchmark
has 11 repeated rounds, with input/output file I/O and numeric fixtures outside
measurement. It includes input restoration and packet-sink costs on both sides;
it does not include GS admission waits or measure native game FPS.
