# Authored NoModel repair candidate

Status: offline native modernization candidate. It is disabled by default, has not been installed in the game, and does not close Stage4 or prove affected-room gameplay acceptance.

The [original-only probe](SCENARIO_UNBOUND_MODEL_SOURCE_PROBE.md) found five authored FF references across three imported rooms. Original unchecked indexing mixes model poses, matrix channels, counters and guest pointer slots. This candidate replaces that coupling with an explicit authored absence. Its intentional differences from original memory side effects are part of the result, not failed parity hidden behind a larger array.

`ModelReference` distinguishes a real slot0–127, an authored NoModel, and an unavailable value. Constructing raw255 remains unavailable. Only the bounded `RoomSceneInput` parser can mint authored absence with an immutable native provenance identity. A room installation holds the only strong admission lease; `SceneModels` retains it weakly. Foreign input, teardown, or a changed room map refuses later missing-model operations. Restoring a changed map does not silently re-admit an expired installation.

The repair requires the explicit `NoModelRepair::authored_absent` option. It admits only the initialized alias-channel state measured by the source probe: no existing physical model bindings, zero channel9 translation and zero channel10 metadata/first matrix column. The imported route IDs and first-match map must not select channel9/10. These checks are a conservative profile of the initialization and tested consumer path, not a proof that arbitrary later scripts are harmless.

An admitted NoModel has no physical visibility, style, model target, pointer slot or mutable pose storage. Its pose is an immutable zero value; binding copies that value into the caller's matrix without retaining the target or setting a physical binding bit. The importer preserves the authored absent-model sound resource0/1 as separate optional metadata. It does not enlarge the128-entry real model sound map. Four helper proxies retain the measured zero-area geometry, including their original activation/query/height metadata.

| Operation | Candidate behavior | Measured original difference |
| --- | --- | --- |
| FF sound annotation | Store separate authored resource0/1 | Original writes the high byte of room2/counter15. Native counters preserve their prior value. |
| FF binding/unbinding | Copy zero matrix; register no physical slot; cleanup is idempotent after lease expiry | Original changes bit31 of real pointer slot3 and stores/clears a guest pointer in room7/counters22–23. |
| Authored FF visibility | No physical visibility/style mutation | Original map1 FF toggles style31.bit31. Legacy unadmitted visibility tests still retain their independently qualified behavior. |
| FF B4 transform | Checked completed no-op with live authored admission | Full original B4 on the measured zero alias leaves all64 bytes unchanged for all eight presets in all three rooms. This bounded agreement does not justify a raw255 fallback. |
| Matrix select/playback | Preserve authored absence through source-byte narrowing; use typed pose and sound access | No pointer/counter alias is published; selected channel metadata, matrices and sound requests are compared with the original bodies. |

Whole-program preflight uses `admits_adjustment` for B4 and `admits_visibility` for B0/B1, including both direct interpreter execution and the offline coordinator before any party member runs. A missing/expired lease refuses before an earlier script counter mutation can execute. An immutable installation-domain marker survives weak-lease expiry so a previously typed absence cannot fall back to the historical style31 alias. The marker grants no admission. Direct visibility also reports refusal if a lease expires after preflight. Legacy rooms that never installed the repair retain their measured wide-index behavior. Matrix selectors and playback require the specific admitted channel before using absent-model metadata.

The repair-specific corpus covers all166 imported room sections and2,144 base records with controlled external native poses. The affected three rooms cover five FF records, four distinct route IDs, all five selectors (20 cases), and1,352 complete selected first-curve updates. Both compilers pass308,070 checks and60,833 original calls. All eight original B4 presets are measured in each affected room. Target retention, physical binding masks, independent canonical counters, foreign provenance, remap revocation, teardown, dirty-reset refusal and pre-existing real bindings are checked. These are offline controlled-input tests; the RDT importer does not construct the actual room's NBD/model scene by itself.

Fresh final selector and playback regressions pass both compilers:10,959,860 checks/81,908 original selection calls and4,473,214 checks/242,206 original playback calls. SceneModels passes1,051,061 checks/49,792 original calls. Default repair-off import passes256,346 checks with163 admitted/3 refused rooms. The bounded VM passes14,001,297 checks/29,753 original dispatches, including27 live/expired/revoked B0/B1/B4 ordinary/offline/three-actor cases. Its older World/effect sources are explicitly pinned and recorded, not described as the current complete gameplay composition. Exact sources, hashes and immutable copies are in `native_gameplay_authored_no_model_qualification_v1.json`. The original-only probe and failed intermediate fixtures remain immutable history.

The remaining installation gates are explicit:

- Validate the three affected rooms and their interactions in the actual native scene composition, including sound and route lifecycle behavior.
- Port/qualify the remaining outer matrix task/program path, including the ten-channel0x93 writeback; this candidate does not claim that source alias writes are globally unreachable.
- Keep any raw room-object lifetime/model provider that lacks authored provenance unavailable for FF until its actual caller is migrated; the legacy raw interface is not granted NoModel admission by this change.
- Complete the required shared proxy callbacks, real scene model construction and native program/room ownership. The current controlled matrices do not prove those domains are complete.
- Re-run the current fully composed VM/domain cohort when the other Stage4 providers are integrated. A bounded regression using explicitly pinned prior World/effects sources is evidence for that stated snapshot only.

No game-speed, rendering backend, asset content or save/co-op rule is changed by enabling this candidate in the offline fixture.
