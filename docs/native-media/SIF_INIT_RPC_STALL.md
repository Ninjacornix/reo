# Movie hitch narrowed to SifInitRpc

The V14 private File #1 retest completes the cinematic route, observes gameplay
without skip inputs, and exits normally after WM_CLOSE. Native audio and RAM
owners retire cleanly with zero hard failures, queue rejections or non-log RAM
refusals. No compilation or offscreen GPU check runs during this pass.

Its largest CPU presentation-return gap is **1452.1292 ms**, at frame CSV line
5005. CRI group-four dispatch at stderr line 3508 lasts 1451.970 ms wall time;
its file-service step three accounts for 1451.248 ms after scheduler-acquire
wait subtraction. Three `SifInitRpc` calls total **1451.025 ms**, while three
`SifCallRpc` calls total only 0.169 ms. A second 132.6342 ms presentation gap
at CSV line 5146 has a 132.707 ms dispatch, with 131.846 ms in `SifInitRpc`.
Both are in approximate movie sample windows. None of the native reader calls
emits a >=20 ms read record. This locates the measured bottleneck in this run's
initializer path; it does not identify its internal cause or prove the same
cause for V13's late player-reported hitch.

The dispatch-to-frame join scales the observer's raw QPC values using this
machine's current 10 MHz frequency. Analysis records that frequency was read
after the run and assumes the same Windows boot. It preserves raw QPC values,
rounded dispatch durations and frame-clock endpoints. Under that declared join,
the long dispatch overlaps 1451.7888 ms of the largest return interval.

The inspected matching SDK initializer acquires the sound-call lease and two
RPC mutexes. Its IOP `init` only assigns the retained RAM pointer. Warm init
clears a driver lazy-initialization flag and emits the repeated `std::cerr`
re-init message while holding those locks. Lease acquisition, lock contention,
logging and host descheduling remain hypotheses; the outer timing cannot
separate them. No speculative lock release or state reset has been applied.

V14 reports 53,440 underrun frames out of 18,861,120 output frames. They have
no incident timestamps and cannot be aligned causally to either gap. Frame
records drop zero entries; return timings do not establish physical scanout or
original-update FPS. The quiet run is an incident investigation, not an accepted
performance comparison with a different run/order/cache state.

## Next probe

Public patch `0129-time-sif-init-rpc-stages.patch` adds opt-in timing to the
same SDK initializer, with a maximum of 64 slow records. It distinguishes sound
lease acquisition, RPC lock acquisition, state work, existing logging, and
release. The report executes only after the original locks and sound lease
unwind. Existing warm logging, initialization, returns and lock policy remain
unchanged. `REO_CRI_SERVER_SLOW_MS` controls the threshold; no new public header
or ABI is introduced.

Both compilers compare 630 calls through the complete frozen prior/current
initializer bodies using declared host ports. Their state/return/counter traces
match. Controlled audio-acquire, lock-acquire and logging delays appear in the
correct stage; stage intervals partition total elapsed, disabled timing emits
nothing, and every diagnostic runs after the modeled locks/lease release.
These are host SDK instrumentation checks, not original PS2 IOP execution.
Reference execution occurred after probe authoring and is identified as such.
All five actual matching SDK objects compile with both compilers. All 130
public patches apply to a fresh independent checkout at the recorded pin.
The active dependency checkout is preserved.

| Receipt below `build-native-sjuni` | SHA-256 |
| --- | --- |
| `candidate-work-v14/candidate-build-result.json` | `56790113f92480b350fb6198ed2af31206563e1778a5c77e4be013049922e660` |
| `cri-timer/playtest-v14/observations.json` | `55f413ec4381d67234a986e902b0048b20a24f2ac498a33d2207e7ae17e039a1` |
| `dependency-sif-init-timing-reapply-v1-receipt.json` | `473ad00c8fcae9966455fc8f47047f2dccd619d747077fc1ffaec2c2e3444df6` |
| `sif-init-timing/qualified-llvm-v2/receipt.json` | `b7b4b77de81af86a0d99f8ee0e5417ad90d82acf5922ff0764a4a7e89417ac82` |
| `sif-init-timing/qualified-gcc-v2/receipt.json` | `1bc33d5db0e9edac775622c6abd110f1890bc609ea1010b2048bbbfdb944744e` |

`tools/native_reconstruction/sif_init_timing_qualification.json` also identifies
the exact patch and SDK object receipts. A matching linked probe and live retest
remain required. Stage 3 is open; the new native source/movie owners are not
bound by this diagnostic candidate.
