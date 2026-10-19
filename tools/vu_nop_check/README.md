Isolated reached-NOP interpreter experiment. The coordinator owns compilation and
execution; run `tools\vu_nop_check\run.bat 11 validation1` from the workspace root.
Use a fresh suffix for later comparisons: output directories must be empty.

The candidate is the copied interpreter at
`build-ninja/m2-vu-nop/ps2_vu1.cpp`; its frozen baseline is
`ps2_vu1.baseline.cpp`. Baseline SHA256:
`B41A1283BDE2CC7F7F68A42A29285F74F3974F277A0908D06E18A959F2070A55`.
Production and headers are untouched. The sole behavioral optimization skips
`execUpper` for actual secondary row 11/column 3 NOP and `execLower` for the exact
canonical word `0x8000033C`. Instruction flags, literal assignment, capture,
branch/E delay pairs, cycle accounting and zero-register invariants remain in
the existing loop. No program cache is introduced, so MPG-like code mutation is
observed directly on every pair.

The fixture compiles the same harness against baseline and candidate copies with
existing isolated packet sinks. It independently checks NOP invariants, upper
unused fields and E/I flags, old-I arithmetic order, branches, E delay/resume,
and code mutation at the same pointer. Thirteen assertions and eight synthetic
artifacts are expected in each run. It loads all 256 weighted captures from
`20261011-185621-m2-weighted-room-baseline/vu1-kevin` and all 64 static captures
from `20261011-181645-m2-depth-wake-original-room-check/vu1-room`.

For each capture it restores the complete input state and VU data, runs the full
original branch loop at captured maxCycles, and saves the complete final native
`VU1State`, all 16KiB resulting VU data, and ordered GIF packet counts, lengths,
and bytes. Comparison reads actual bytes, not just hashes. Exactly 328 binary
artifact pairs must match. These include both memory-submitted and direct GS
packet sinks. The existing GIF manifest's state/data hashes describe inputs;
this fixture instead checks the final outputs needed for CPU optimizations.

After input loading and output writing, one warm pass and repeated in-memory
passes measure the same 320-input set. No file I/O or capture diagnostics occur
inside the benchmark. Input restoration and packet-sink allocations remain part
of both measurements. Runtime sources compile with the same `/O2` flags. Timing
ratios from this isolated fixture cannot establish a native FPS improvement or
the cumulative VU share of room stalls.
