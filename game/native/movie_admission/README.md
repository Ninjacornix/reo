# Native picture admission arithmetic

Implements the complete arithmetic/state cut in the
[contract](../../../docs/native-media/MOVIE_ADMISSION_ARITHMETIC_CONTRACT.md):
current-clock ratio/slack comparison, auxiliary rational fallback and the actual
tolerance/duplicate/hysteresis state machine. The core owns ordinary fields and
value inputs; it has no runtime, guest memory, registers, device or frame owner.

Both original compiler cohorts give identical results for 330 cases / 336
operations: 18,449 original instructions. Their scoped compiled workers qualify
the actual emitted ordered comparisons, branches and arithmetic in 638 raw-bit
cases per compiler. Statements are audited from public generated source against
the owned ELF. This is current-runtime emission compatibility, not measured
original PS2 FPU equivalence. Three zero-frequency exclusions preserve partial
architectural DIV refusals; they do not claim returned original failure parity.

The first 324 cases / 330 operations were frozen before native implementation.
The initial native comparison matched but failed qualification because a
full-product slack counterfactual escaped detection. Six original cases were
then added for wrapped margins and equal rounded ratios, recording the existing
candidate's hashes and retaining every earlier original input/result unchanged.
The original expectations were not changed to match native code. The successful
qualification records the detected faults and host-FP/refusal boundary checks.

The native profile preserves signed low-word products, truncated division,
individual binary32 rounding, exact-one selector, signed hysteresis counts,
59940/rate/increment special threshold, duplicate float equality and raw cached
decisions. Integer bypass/fallback remains available independently of host FP
rounding. Floating paths reject unsupported rounding, exception masks or flush
modes before state effects and restore the host environment afterward.

The cached-clock query is an explicit sample boundary. The fixture supplies only
authored reply words, masks, prior scratch and post-query facts, never expected
arithmetic/state. It does not qualify a real provider, callback lifetime or a
complete guest ABI. Incidental original FP register/FCR effects are recorded but
are not this typed API. Public admission bypass policies, skip paths, full
buffering predicates, frame returns and one coherent movie owner remain required.

Run `python game/native/movie_admission/verify.py --cxx <compiler> --output
build-native-sjuni/movie-admission/<fresh-scope>` for the frozen comparison and
negative controls. No game was launched, real device opened or production path
selected. Stage 3 and subsequent gameplay, graphics/platform and compatibility
removal stages remain open.
