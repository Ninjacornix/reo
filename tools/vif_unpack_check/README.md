Coordinator-only isolated contiguous V4-32 UNPACK experiment:
`tools\vif_unpack_check\run.bat 11 validation1`.
Use a fresh output suffix for later comparisons. Production and headers are
untouched. Candidate and frozen baseline are in `build-ninja/m2-vif-unpack`.
Baseline parser SHA256:
`DFA159570208258D561BEF2B8F652550DFDE959954CE9539C6B13C9C25C5DD7C`.

The copied parser replaces the generic per-vector/per-lane loop with one memcpy
only for V4-32, unmasked, mode exactly zero, normalized CL=WL, a complete payload,
and a destination ending at or before vector 1024. Source and destination byte
ranges must be disjoint. The original command CODE/NUM/IRQ, destination FLG/TOPS
calculation, and input-position advancement remain unchanged. All other formats,
modes, wrapping destinations and overlapping payloads keep the original path.
Mode 3 stays on the original path even though synthetic equivalence is checked.

Two executables link identical harnesses and runtime library dependencies, with
either the saved baseline or candidate parser object. They independently check
59 assertions and save 39 synthetic case artifacts. Cases cover NUM 0/1/2/255,
equal cycles including zero normalization, exact end/wrap boundaries, FLG/TOPS,
USN, IRQ, modes 1/2/3 and row state, fill/skip cycles, masks, fragment splits
before the command or in its payload, overlapping source writes in both
directions, and MPG/DIRECT/MSCALF/MSCNT ordering.

Every artifact contains the entire resulting VIFRegisters (including row/col),
all 16KiB VU microcode and data, and ordered GIF packet bytes and MSCAL/MSCNT
callback arguments plus complete VIF/code/data snapshots at each callback.
Callbacks record observed effects; they do not execute VU programs. Internal
fragment carry is tested by serializing the partial call then completing it and
checking its output, since it is deliberately not exposed through a header/API.

Four metadata-complete original buffers from
`20261011-153637-m2-vif-vu-original-baseline` are replayed continuously, with
initial registers/code/data. The large `vif1_0004.bin` has no post-state metadata
and is excluded. Those four complete buffers do not exercise the room UNPACK
workload; the representative reached format is tested independently with full
source-byte and boundary assertions. Cross-variant parity is not proof that an
unfinished native capture completed in the game.

The byte oracle expects 44 artifacts: 39 synthetic, 4 complete captured inputs,
and 1 benchmark final state. Timing uses an in-memory synthetic stream of 512
V4-32 commands, each 256 vectors, totaling 131072 vectors. Loading, saving,
resetting and diagnostic logging are outside the measured work. This isolates
parser throughput for the reached format, without an entire native DMA chain,
original VU execution, GS admission waits, or game FPS.
