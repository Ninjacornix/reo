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
