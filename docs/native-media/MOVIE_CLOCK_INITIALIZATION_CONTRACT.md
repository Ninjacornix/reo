# Movie clock construction contract

Next typed cut: complete `175A50` with actual callback registration `1769B0`,
record initialization `175C50` and seven-word clear `175C98`, for the normal
main/context relation. The complete 0x2A0-byte clock block is initialized, while
the rest of the main object remains unchanged. Freeze original execution before
implementing native state, including stale nonzero blocks and unrelated state.

Callbacks 0–5 become unavailable, counter, empty, contextual, empty, external;
the late-picture callback is cleared. Six owned ten-word rational/history records
are reset, with physical-order default numerators MAX, -1, -1, 0, -1, MAX and
denominators 1. Both 32-entry prediction windows are cleared. Preserve remaining
prefix/metadata, raw sentinels, selected/latest pairs, counters, increment 1000,
hysteresis count 100, external callback/history and -1.0 query bits literally.
Some tracker payload roles remain unresolved: keep their bounded typed storage
explicit and do not invent a valid clock interpretation from their sentinels.

The original constructor performs only FP register/memory bit moves. Reuse the
existing raw-bit worker, auditing emitted statements from the public generated
source against the owned ELF. Qualify those actual words with raw-bit vectors
before constructor execution; no Python float or arithmetic-result hook. Record
compiler/runtime identity and distinguish current-runtime emission compatibility
from original PS2 hardware FPU equivalence.

Native state uses named fields, owned fixed arrays, callback kinds and nullable
owned provider references. It must not become a guest-offset array, simulated
register file or second RAM image. Any mechanical mapping from original offsets
belongs only in the verification fixture. This initializes a clock block, not
the whole movie object, its properties, source, decoder, frame owners or audio
filter. Complete `173C70` stop/rebuild and callback lifetimes remain separate.

The resulting constructor must still be joined with selected/audio/pause state
under one owned movie context before replacing real callers. Stage 3 remains
open, followed by gameplay, graphics/platform migration and runtime removal.
