# Native movie priming checkpoint

The live V12 configuration read observed two logical movie frame slots and a
ready threshold of four capped to that count. The prepared native graph used
three logical slots, coupled to its three physical decoder/output slots.

The first priming checkpoint permits bounded decoding while playback remains
in state two. It publishes pictures in timestamp order and requires every
earlier publication to be ready in the pool before exposing a later one.
The readiness query observes the pool's committed state without polling a
producer fence. The frontend cannot borrow a frame during preparation.

The complete 316-picture title stream passed the real D3D11/Vulkan check,
including two ready pictures before each of two playback incarnations,
ordered presentation, matching first-frame pixels after rebuild, and an
unsignaled renderer fence preventing replacement. This checkpoint still uses
three logical slots. It does not prove the live two-slot configuration, game
scheduling, paced playback, audio synchronization or a speedup.

Evidence: `build-native-sjuni/movie-priming/title-v1/receipt.json`, SHA-256
`69c95d30d52e4879c70a77db3e19b19f799667fe4f38f8c3b93973ed8756bc96`.
Its exact native cohort is `game/native/adxt_instances/manifest.json`; all
72 standalone suites passed with GCC and LLVM. Stable ADXT ownership has its
own qualification record beside that manifest.

The next graph cut must separate bounded physical decoder/reorder resources
from the actual two-slot logical frame pool, then repeat priming and complete
catalogue checks. Historical catalogue evidence applies to its recorded source
cohort only. Stage 3 remains open.
