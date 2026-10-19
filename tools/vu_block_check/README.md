Isolated generated C++ VU block experiment. Production VU/runtime sources and
public headers are untouched. The coordinator owns all compilation and execution.

`python tools/vu_block_check/generate.py` freezes the current interpreter into
`build-ninja/m2-vu-block-proposal/ps2_vu1.baseline.cpp` and generates its candidate
copy `ps2_vu1.cpp`. Generation reads owned snapshots and copies the current upper
and lower handler bodies mechanically into instruction-constant C++ templates.
The original scalar/SSE arithmetic, operand order, destination writes and special
operation formulas remain the baseline's own implementation. Generated program
bytes stay in ignored `build-ninja`; this tracked tool contains no game microcode.
An existing frozen baseline requires explicit `--refresh`.

The frozen source includes the coordinator's whole-kick VU timing collector.
`candidate-manifest.json` records its SHA256 and both copied-source hashes.
The harness disables capture/timing and supplies inactive private whole-kick
diagnostic hooks. No public ABI or class-layout changes are required.

Two blocks are generated: weighted PC `0x348..0x598` (75 pairs), static PC
`0x260..0x3E8` (50 pairs). A generator check rejects E flags, XGKICK, earlier
branches, or a terminal branch other than the expected IBEQ followed by its
ordinary delay pair. Every generated pair retains upper-before-lower execution,
old-I semantics, zero-register invariant writes and the interpreter's branch
pending/target update. Each block runs only with no incoming pending branch or
E delay, enough remaining cycle budget, inactive instruction capture, exact
16KiB code-image byte equality, 16KiB data, disjoint code/data spans, and a second
exact comparison of its own instruction bytes at admission. Unknown programs,
interior entries, short budgets and failed guards use the untouched generic loop.
No hash alone authorizes execution and no code generation occurs at runtime.

Coordinator command from the workspace root:

    tools\vu_block_check\run.bat 11 validation1

Use a fresh suffix; output folders must be empty. Both copies compile with
`/O2 /fp:precise` against the same isolated packet sinks. The original oracle
replays all 256 weighted and 64 static captures and its eight synthetic controls.
The new harness adds 26 complete-output controls for exact block completion,
terminal branch/delay PC, remaining cycle budgets, interior entries, code changes
inside/outside a block at the same pointer, E mutation, nonfinite/signed-zero
operands, zero-register pollution, prior branches and overlapping code/data.
It checks actual compiled hits (candidate) versus zero hits (baseline) while
tracking is disabled throughout the warmed benchmark. The modified-code prior
branch control proves conservative fallback and original execution; it does not
independently isolate the pending-branch guard under an unchanged program image.

`compare.py` reuses the existing byte oracle and requires exactly **354** matching
artifacts: full final VU state, all 16KiB data, and every ordered memory/GS GIF
packet count, length and byte. Benchmark work/checksum must match too. Synthetic
checks provide explicit invariant and branch-PC expectations beside parity.
Actual pass/fail and performance are pending coordinator compilation. This is an
isolated interpreter benchmark, not native room FPS or full VIF-DMA throughput.
