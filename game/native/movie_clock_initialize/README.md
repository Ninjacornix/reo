# Fresh native movie clock construction

The independent constructor in the [contract](../../../docs/native-media/MOVIE_CLOCK_INITIALIZATION_CONTRACT.md)
initializes owned callback kinds, six rational/history records, two prediction
windows, cached pairs, counters and external sample history. It contains no guest
offsets, register file or RAM image. Unresolved tracker/admission payload roles
remain explicitly opaque bounded fields; their sentinels are not valid times.

Both original compiler cohorts were frozen before this module existed. Four
distinct stale-memory/FP-state inputs execute all four complete original bodies:
2,944 instructions and 12 FP bit moves per compiler. All 672 bytes of the clock
block are written; the rest of the synthetic main object and callee-save state
remain unchanged. The only FP register change is the constructor's literal
-1.0 bits in f0; FCR31 is unchanged. No floating-point arithmetic is substituted.

The existing compiled raw-bit worker was reused without modifying its source.
The actual constructor's three emitted instruction words were audited from the
public generated source against the owned ELF and qualified in 24 raw-bit cases
per compiler. This establishes current-runtime emission compatibility, not a
PS2 hardware FPU measurement. Both original cohorts give identical complete
results. Native GCC and LLVM then match all 168 normalized constructor words;
eight deliberate faults are detected. The standalone golden vector is copied
from the frozen original output, with callback addresses normalized to native
kinds only. Projection and golden data belong to verification, not the core.

`initialize()` creates fresh state. It does not reset a live context or release
its callbacks, frames, source workers or audio output. The complete movie object
constructor/rebuild, property restoration and one coherent owner joining the
selected/audio/pause controllers remain required. No game was launched, device
opened or production path selected. This remains stage 3 work; stages 4–6 follow.

Run `python game/native/movie_clock_initialize/verify.py --cxx <compiler> --output
build-native-sjuni/movie-clock-initialize/<fresh-scope>` for the frozen comparison
and counterfactuals. The source and qualification records identify the exact
cohort and all 62 standalone suites.
