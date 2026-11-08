# Media retirement audit

2026-11-08, File #1 US only. This distinguishes replaced workers from the
temporary interfaces used by game callers that still run through the translated
engine. It does not declare Step 3 complete or remove the PS2 runtime.

| Boundary | Current native replacement | Remaining dependency |
| --- | --- | --- |
| Ordinary SFD movies | Imported H.264 assets, Windows Media Engine clock/decoder, native playlist/session worker, immutable frame leases. | The guarded 25-entry public adapter and game cue workspace remain. Existing game tests sample all eight original MWSFD slots as inactive; sampling does not prove every unobserved path is retired. |
| Movie image display | Native BGRA frames reach the existing game renderer through `native_host_movie/render_bridge.h`. | CPU readback, legacy pixel tiling/conversion and game texture/render submission remain explicit renderer interfaces. The native rendering stage must replace these consumers rather than call them fully native presentation. |
| Ordinary ADX sources | Canonical native source owner, native workers and complete native PCM/bank/RAM output composition. | Original game-side metadata and the guarded 18-entry control/service interface remain. LSC/external SJ producer and nonzero before-PCM callback routes are explicitly unsupported by the current ordinary runtime adapter; passing the opening does not validate those routes. |
| Resource payloads | Verified native imported mount and synchronous exact reads; ordinary audio retains this same mount. | Existing game ABI/RPC entry and layout checks remain. Native package selection now enables the mount even when the user's source selection is an ISO. |
| Numbered effect movies | No native consumer installed. | `1CC2D0` loads `data\\rom\\eff_mov\\eff_%03d.mov`; `1CC5B0` still contains actual IPU/DMA work. Absence of named files in an inventory is insufficient proof that this path can be removed. |
| Shared movie initialization | Ordinary movie instances are replaced. | `1CC260 -> 15E6A0` remains a distinct initializer path with global reference state and delegated subsystem initialization/callback registration. Do not replace the whole initializer with a no-op merely because ordinary SFD instance slots stay zero. |

The effect loader's original descriptor reads signed width/height halfwords at
file offsets `8/A`, frame count at `C`, and derives payload bytes from word `4`
minus eight. Its payload begins at `10` hex. These facts provide a bounded
inventory search profile, not a validated container signature or codec identity.
A candidate asset must be checked against its actual consumer and decoded output
before conversion. No new effect asset, runtime invocation or slowdown was
established by this audit.

Existing complete original-body findings are
[effect playback](../SYMBOLS_ENGINE_EFFECT_MOVIE_IPU_PLAYBACK.md),
[global initialization](../SYMBOLS_MWSFD_GLOBAL_INITIALIZATION_AND_CONFIGURATION.md)
and [startup orchestration](../SYMBOLS_VBLANK_GETTER_AND_DVD_BOOT.md). The generated
V27 original bodies were cross-checked for the effect descriptor and initializer
call sequence. This is source analysis, not a new live original-call capture.

Next retirement evidence must account for required producer profiles and the
effect consumer, and exercise resource/room and media controls in the coherent
game candidate. Stages 4/5 migrate the remaining game/renderer callers; stage 6
removes their obsolete execution and build dependencies. Renaming a bridge or
deleting checks cannot supply that evidence. Subjective A/V synchronization
remains unconfirmed while the user is away.

A bounded member-header search checks the first 16 bytes of 17,989 sufficiently
large members from the 18,732-member inventory. It reads 287,824 bytes and finds
no `.mov`/`eff_mov` names or headers matching the searched positive, block-aligned
geometry and contained length profile. This excludes only that profile at those
member starts. Embedded/unnamed/compressed payloads, other layouts and actual
call reachability remain unresolved; this is not permission to delete IPU
support. The report is `build-native-sjuni/effect-member-header-search-v1.json`.

## Queued audio consumer boundary

The ordinary adapter's five producer refusals are not all unreferenced codec
internals. Existing complete source findings identify actual engine wrappers:
`1AE9F0` resolves a sound name and calls `12A6B8` to enqueue an AFS member;
`1AEA70` calls the queue-count query, repeat control and `12A780` start.
The special E3 movie setup in o1 also uses the enqueue/restart route. These are
static caller facts from [stream channels](../SYMBOLS_STREAM_CHANNELS.md),
[queued source APIs](../SYMBOLS_ADXT_SEAMLESS_LSC_SOURCE_CONTROLS.md) and
[o1 movie options](../SYMBOLS_O1_OPTIONS_MOVIE.md). They establish that a required
consumer audit cannot simply classify the whole interface as unused. They do
not establish that an E3/debug route is a required retail scenario, or that one
of these functions executed in V28-V31.

The existing native `adxt_lsc_input::Input` already owns prepared assets,
enqueue/repeat/start/stop, bounded journals and source retirement. The next
integration should resolve game cues into retained native resource extents and
use that native owner, with original game-visible status/return behavior only at
the temporary caller interface. It should not execute the original queue/file
producer behind a native label. Required cue profiles must be checked against
`adx_sequence::Clip` admission, which currently refuses inline-loop metadata
and incompatible output/attenuation. Ordinary finite-file success does not
remove those separate admission limits.

Game/renderer interfaces remain staged migrations. The first-room captures show
allocated original LSC children staying idle, not proof that all later scenarios
avoid queued audio. This boundary remains open independently of the measured
finite-file read-ahead improvement.

The [native preparation/handoff implementation](NATIVE_AUDIO_QUEUE_PREPARATION.md)
now keeps cue header reads off the game thread and prevents premature decoder
EOF while an accepted next clip is still preparing. Both compilers pass 79 native
suites; two private fault removals fail the intended checks. This supplies the
next binding's preparation and playback boundary, not the engine command
integration or a real-cue admission audit. Those remain required.

The subsequent [cue-controller binding](NATIVE_AUDIO_CUE_CONTROLLER.md) replaces
finite enqueue/start/count/repeat/reset/stop consumers and passes 80 native
suites plus six real-asset adapter cases on both compilers. The table's 18-entry
refusal profile describes V31; the new 22-entry implementation is awaiting its
coherent game retest. The independent catalogue audit and its 89 inline-loop
refusals remain explicit. This does not retire arbitrary SJ callbacks or prove
the effect consumer unreachable.
