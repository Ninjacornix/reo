# Resident bootstrap and recurring frame callback

Static File #1 US owned ELF,2026-11-05. Complete original body plus connected reviewed callees. [Identity](FUNCTION_INDEX.md). No frame or runtime callback executed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1BAA00](../recomp/config/output/sub_001BAA00_0x1baa00.cpp) | `bootstrap_graphics_session_once_then_service_frame_and_resident_callbacks` | Confirmed full two-state route | State316598==0 retries19F380(640,448) until nonzero, initializes session arenas1BAEC0, audio/UI/fade1BB1D0, installs callback1BC6A0 through1B7EE0 and increments state. State1 calls1BAAF0 frame service, snapshots half3244D0 to3244C8 and increments3244C0, converts1A9180 result to float316590, tests1AF5C0 before optional1AF4D0 teardown, then1B7CB0 callback/fade service. Other state skips work. Returns0. Both1A9180 and1AF5C0 are literal return-zero leaves; no clock measurement or reachable teardown inferred from this original path. |

One body /51 words. [Session initialization](SYMBOLS_RESIDENT_SESSION_BOOT_AND_SETTINGS.md), [render state](SYMBOLS_RENDER_STATE_CONTROLLER.md), [resident slots](SYMBOLS_RESIDENT_CALLBACK_SLOTS.md). The graphics admission loop has no local backoff/deadline; actual override behavior and playtest reachability are separate evidence.
