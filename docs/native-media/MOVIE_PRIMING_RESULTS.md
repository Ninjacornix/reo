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

## Two-slot graph qualification

That capacity cut now passes. Future MPEG anchors retain physical surface
leases without reserving logical frame slots. Only an eligible picture entering
the display pool reserves one of its two slots; real pending producer fences
and prior-publication ordering remain explicit. Stop/rebuild retire unpublished
physical leases and published logical frames before replacing either owner.

All **201** owned File #1 movies pass two-slot priming before each of two
incarnations, real renderer-fence rebuild refusal, matching first-frame pixels
and complete ordered presentation. **216,998** decoded/presented pictures match
independent elementary-stream counts: 12,471 I, 60,729 P and 143,798 B. Every
result explicitly reports two logical slots and two ready primed pictures.
Both compilers again pass all 72 standalone suites for this exact source cohort.

| Receipt below `build-native-sjuni` | SHA-256 |
| --- | --- |
| `movie-priming/title-two-slot-v1/receipt.json` | `67c0a1789e1f5f94ab8ea0f4b61bb3816d4dd71d4c81292277850b8516ad66ab` |
| `movie-matrix/catalog-two-slot-v1/receipt.json` | `b162cae0e82f14a4ea18f6c2065324a89362afb316c1def94ba587fc306f63a0` |

The complete source/build/count identities are recorded in
`tools/native_reconstruction/movie_two_slot_qualification.json`. These checks
remain unpaced and offscreen; they do not execute the game's media binding,
establish audible A/V synchronization, reproduce the late CRI stall or close
stage 3. The earlier three-slot checkpoint remains a historical cohort.
