# Original font/UI roles versus native override registrations

Static source and owned-binary review, 2026-11-04. Main **SLUS_207.65**, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**. No player executable, running process, logs, live memory, game input or timing sample was inspected. No override was edited, removed or executed.

The reviewed original bodies contradict several legacy network/audio labels in [reo_override.cpp](../recomp/overrides/reo_override.cpp:1961). This is a concrete source-registration audit finding. It does not establish that these handlers were installed in the executable used for the player's last session.

| Address | Owned original role and evidence | File #1 registration in this checkout |
| --- | --- | --- |
| `1B5670` | [Active font-context selection](SYMBOLS_FONT_DRAW_CONTROLS.md): writes234768 to default/alternate context. | `reo_net_socket`, labelnet_socket;returnsfakefd1 without the pointer write. |
| `1B5FB0` | [Font packet servicing](SYMBOLS_NEIGHBORS.md): conditionally queues/submits font packets, switches buffers and polls original DMA register. | `reo_ret0`,labelnet_accept;returns0 without original work. |
| `1B6E90` | [40-byte font packet builder](SYMBOLS_FONT_STORAGE_PACKETS.md). | `reo_ret0`,labelnet_sif_send. |
| `1B6F10` | [50-byte font packet builder](SYMBOLS_FONT_STORAGE_PACKETS.md). | `reo_ret0`,labelnet_sif_send_2. |
| `1B6FD0` | [90-byte GS/DMA upload-reference builder](SYMBOLS_ITEM_MESSAGE_TEXTURE_CACHES.md). | `reo_net_connect`,labelnet_connect;returns-1 without emitting original packet. |
| `1B71D0` | [Font texture/glyph packet append](SYMBOLS_UI_RECTANGLE_GLYPH_PACKETS.md). | `reo_net_send`,labelnet_send;returns-1 without original append. |
| `1B7CB0` | [Sixteen-slot callback scheduler](SYMBOLS_RESIDENT_CALLBACK_SLOTS.md), including pending mode changes and fade updates. | `reo_ret0`,labelnet_sif_cmd. |
| `1B80D0` | [Pending primary/secondary mode request](SYMBOLS_RESIDENT_CALLBACK_SLOTS.md). | `reo_net_close`,labelnet_close;returns0 without pending-byte writes. |
| `1BCF60` | [DEV9/ATAD/HDD/PFS bootstrap](SYMBOLS_SCREEN_TRANSITIONS.md),corroboratedbyownedmodulepaths. | `reo_ret0`,labelaudio_init_0x1BCF60. Skipping native IOP initialization could be intentional; the label still does not identify the original role. |

Source observations:

- [bind helper](../recomp/overrides/reo_override.cpp:1635) registers both runtime function table and stub override registry. The listed calls are in the `REO_GAME_FILE1` implementation of `applyOutbreakOverrides`, registered forSLUS_207.65 at the end of that section.
- [bootstrap](../recomp/reo_bootstrap.cpp:1312) reapplies matching game overrides after generated main/overlay registration. This gives the source a route to replace those generated handlers; no running registration table was read.
- The currently indexed [generated font renderer](../recomp/config/output/sub_001B56A0_0x1b56a0.cpp) calls through runtime lookup when a registered function exists, with generated fallback otherwise. Original JAL targets therefore do not alone prove the original body executes.
- [CMake handwritten source list](../recomp/CMakeLists.txt:548) includesreo_override.cpp. The old [render-unstub policy](../recomp/config/outbreak_render_unstub.toml:249) also lists these font entries as stubs; the current [local generator](../tools/local_build/generate_game.py:35) choosesoutbreak.toml forFile1,so that older policy is not proof of current generation inputs.

The full original1B5FB0 body was additionally reviewed: branch paths poll `read32(0x1000A000)&0x100` at1B60E0,1B61BC and1B62E4 before103390; another path enqueues18CEF0. Those polls cannot be attributed to a native incident if the original body was replaced or the branch was not taken. Likewise a stubbed packet return could affect pointer flow only if that installed binding and caller path are demonstrated.

Later validation should first tie the session's executable hash/build inputs to its final registration table and generated call dispatch, then compare each installed replacement against the owned contract. Do not restore this entire address range blindly: packet-reference lifetime, buffer ownership and native DMA handling need to remain coherent. This note records candidate implementation work after the agreed mapping milestone, not a confirmed slowdown cause or an implemented fix.
