# Stage 4 LLVM build and fast regression baseline

Observed 2026-11-13 in `build-native-sjuni/gameplay-native-llvm-v1` (Ninja generator). The pinned compiler is `C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe`; Ninja is `C:/PROGRA~1/MICROS~2/2022/COMMUN~1/Common7/IDE/COMMON~1/MICROS~1/CMake/Ninja/ninja.exe`. CMake and CTest are under `C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/`.

Run these from the repository root in PowerShell. They use the existing configured build and do not force a full clean rebuild:

```powershell
$cmake = 'C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe'
$ctest = 'C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/ctest.exe'
$build = 'build-native-sjuni/gameplay-native-llvm-v1'

# Discover current registered tests (do not hard-code a historic test count).
& $ctest --test-dir $build --show-only=json-v1

# Build a focused integration cohort already used by the owned-content receipt.
& $cmake --build $build --target session_rooms_tests session_startup_tests gameplay_contact_world_tests script_resource_activation_tests native_session_tests script_resource_parameter_tests gameplay_ai_tests scene_record_parameter_tests gameplay_script_program_tests gameplay_archive_tests gameplay_world_tests dialogue_workers_tests session_dialogue_tests session_resources_tests cutscene_actor_speech_assets_tests cutscene_room_lighting_assets_tests --parallel 2

# Run matching CTest cases. Owned-content cases require the arguments below;
# CTest registration alone does not supply all of their assets in this build.
& $ctest --test-dir $build --output-on-failure -R '^(native_session_rooms|native_session_startup|native_gameplay_contact_world|native_script_resource_activation|native_gameplay_application|native_script_resource_parameters|native_gameplay_ai|native_scene_record_parameters|native_gameplay_script_program|native_gameplay_archive|native_gameplay_world|native_dialogue_workers|native_session_dialogue)$'

# Owned assets exercised by surface-follower-parents-llvm-v2 receipt:
$archive = "$env:LOCALAPPDATA/OutbreakRecomp/launcher/imports/file1/25e64b631bbaa0cac9a4822cb66174ff14c3531851d1e502c0a06704379bf446/data/NETBIO00.DAT"
& "$build/gameplay_application/session_dialogue_tests.exe" $archive
& "$build/gameplay_application/dialogue_workers_tests.exe" $archive
& "$build/gameplay_application/session_resources_tests.exe" $archive 'build-native-sjuni/gameplay-contact-content-llvm-v2/contact-content-v1.bin' 'build-native-sjuni/resource-flight-owner-llvm-v4/owned_effect_geometry.bin'
& "$build/gameplay_scenario/cutscene_actor_speech_assets_tests.exe" $archive 'build-native-sjuni/cutscene-actor-speech-llvm-v4/assets.txt' 'build-native-sjuni/cutscene-actor-speech-llvm-v4/models.txt'
& "$build/gameplay_scenario/cutscene_room_lighting_assets_tests.exe" $archive 'build-native-sjuni/cutscene-room-lighting-llvm-v4/resources.txt'
```

The `surface-follower-parents-llvm-v2/receipt.json` additionally records the wider cohort's configure command, 36-target incremental build, focused CTest regex, and these owned-asset invocations. Its evidence says `game_run: false`; these are regression/asset checks, not live gameplay acceptance. For each implementation batch, replace the sample target list and regex with the affected targets/tests; retain the final full-suite and real gameplay gates from `STAGE4_COMPLETION_PLAN.md`.

## Current discovery and caching evidence

Planning discovery returned 134 registered tests. Discovery after the current control/inventory integration batch returns 136, including `native_session_control_preparation`, `native_inventory_actor_preparation`, `native_gameplay_ai_owner` and `native_dialogue_workers`. These counts are snapshots, not permanent contracts; retain required test identities as well as discovering the current suite.

The `actor-population-vm-llvm-v2/receipt.json` records 132 production objects and all 132 as `cache_hit: true` for that cohort. This confirms the object cache works for a warm repeat, but does not quantify a cold miss rate or elapsed savings. In `comparison_objects.py`, each object's identity includes a hash over every captured native header, so a change to an unrelated native header changes every production-object cache key. In `gameplay_scenario/verify.py`, the original fixture and `tests.cpp` are compiled for every cohort; caching these expensive oracle inputs or splitting stable test units is a candidate only after timing them. Prefer per-translation-unit transitive dependency identities for production cache invalidation, preserving compiler, flags, target/sysroot, generated inputs and object hashes.

## Registered versus separately invoked owned tests

The CMake/CTest build contains native session/dialogue tests, but the owned asset executables shown above need explicit data arguments and are not safely represented by bare CTest execution. Run them after building their targets. The current dirty tree also includes new standalone dialogue-bank and scene-reset qualification scripts/executables; verify each actual source registration and asset invocation before considering it part of the current CTest suite.

## Current focused integration result

Latest sealed result: [text-object-startup-llvm-v4](../../build-native-sjuni/stage4-orchestration/text-object-startup-llvm-v4/receipt.json) passes fourteen selected CTests (2.61 seconds) and nine owned-content cases with empty source/archive drift. Its build is an explicit no-work seal after incremental fixes, not a cold-build timing. The initial shared-header rebuild took 199.77 seconds and failed at link on the missing `scene_text_bank.cpp` registration; the corrected build took 9.73 seconds. Subsequent six-step fixture rebuild took 6.86 seconds. Failed receipts are retained separately.

The [timed-text original comparison](../../build-native-sjuni/timed-scene-text-llvm-v2/receipt.json) reuses the exact 67 production archives: original compilation 6.06 seconds, fixture compilation 5.55 seconds, link 0.22 seconds, execution 0.33 seconds for 389,467 checks. The [room-object comparison](../../build-native-sjuni/stage4-orchestration/room-objects-missing-shared-llvm-v1/receipt.json) now likewise requires a passing shared receipt and links its production archives, with 2.22 seconds compilation/link and 0.094 seconds execution. Both check all native source/header and archive identities before and after. No GCC or duplicate production build was run. New camera-mode/analog changes require the next coherent cohort; v4 does not qualify those unlinked drafts. The paragraphs below retain older build history.

Execution update: [ordinary-camera-startup-llvm-v3](../../build-native-sjuni/stage4-orchestration/ordinary-camera-startup-llvm-v3/receipt.json) is now the latest fully passing shared cohort. A nineteen-step incremental build took 11.44 seconds; thirteen selected CTests and all nine owned-content invocations passed with empty source/archive drift. The [ordinary-camera comparison](../../build-native-sjuni/room-camera-llvm-v6/receipt.json) links that exact production build and passes all 166 room sections plus boundary/state-order cases. Its original and fixture compile independently; no duplicate production build or GCC run is needed. Later text/object/input changes must wait for their own coherent batch before reusing these archives as current evidence. The review paragraph below records the earlier failed state, now superseded by v3.

Planning review, 2026-11-13: `offline-camera-llvm-v1` below remains the latest fully passing sealed cohort, not a qualification of subsequent source changes. The newer [ordinary-camera-startup-llvm-v1](../../build-native-sjuni/stage4-orchestration/ordinary-camera-startup-llvm-v1/receipt.json) built 304 steps in 193.50 seconds and passed thirteen selected CTests in 3.313 seconds, but failed overall because one of nine owned cases failed. The NativeSession `169` fixture encountered existing authored-room audio/effect provider refusals before command execution. Its controlled-script correction is prepared; the registered test and shared receipt still need rerunning. The other eight owned cases passed, including the 0.969-second cinematic-camera asset case. Do not pass this failed receipt to a comparison that requires a qualified shared build. No builds or tests were run for this documentation review.

[offline-camera-llvm-v1](../../build-native-sjuni/stage4-orchestration/offline-camera-llvm-v1/receipt.json) records the current compiler, native sources, archive identities, inputs, build and test commands. Its 291-step incremental build took 183.80 seconds; twelve selected CTests passed in 3.18 seconds, followed by seven separately invoked owned-content cases. These include fresh application ownership/retry, actual EVB `5A` before SGL loading, retained frame binding with an explicit missing-provider refusal, and room-camera import in NativeSession. The runner discovers all registered tests and checks that every required selected name is present. Source and archive drift lists are empty. Each distinct owned input is hashed once (0.67 seconds total); native source hashing took 0.42 seconds. The prior [script-startup-llvm-v1](../../build-native-sjuni/stage4-orchestration/script-startup-llvm-v1/receipt.json) recorded a 184.09-second build, twelve selected CTests and six owned-content cases. Shared header changes rebuild affected consumers; a failed or interrupted build is never treated as a coherent comparison input.

[ai-offline-application-original-llvm-v3](../../build-native-sjuni/ai-offline-application-original-llvm-v3/receipt.json) compiled its fresh original/fixture against those production libraries in 5.22 seconds and ran 2,048 cases in 0.27 seconds. This demonstrates a useful focused route without a second production build. It does not replace full final acceptance.

The observation verifier exposed another avoidable cost: its hand-maintained 150-unit standalone production list compiled and then failed to link after production dependencies changed. Its new identity-checked shared-library mode passes [4,096 original comparison cases](../../build-native-sjuni/ai-observation-alias-original-llvm-v3/receipt.json). Relinking the already independently compiled production objects with the required immutable archives yields [identical observations](../../build-native-sjuni/ai-observation-alias-standalone-linked-llvm-v1/receipt.json). The fresh original and fixture remain independently compiled; native source/header and archive hashes must match the passing build receipt and remain unchanged through execution.

Use a fresh output directory with this mode, replacing the build receipt after the next coherent integration batch:

```powershell
python tools/native_reconstruction/verify_ai_observation_frame.py --compiler llvm --native-build build-native-sjuni/gameplay-native-llvm-v1 --build-receipt build-native-sjuni/stage4-orchestration/offline-camera-llvm-v1/receipt.json --output build-native-sjuni/ai-observation-current-llvm-v1
```

This avoids a duplicate 150-unit production build. The standalone mode remains useful for independent qualification; its current explicit source list needs the additional dependency archives shown in the standalone-linked receipt and should not be a mandatory rebuild after each application change.

The [current interaction-command comparison](../../build-native-sjuni/actor-interaction-llvm-v1/receipt.json) links those same 67 production archives and checks only the affected original bodies and authored records. The [current admission scan](../../build-native-sjuni/actor-interaction-admission-llvm-v1/receipt.json) also reports entry-1 startup closures separately from configured roots. A proven quotient of the scanner's absolute condition ordinal removes redundant proof states; the 20,000-state and 4,096-record scan bounds remain intact. This improves the admission algorithm without reducing runtime semantics or accepting unsupported branches.

`verify_scene_reset.py` now also requires the current `--native-build` and `--build-receipt`; it no longer mixes new test/header code with a copied historical application closure. [Its current original comparison](../../build-native-sjuni/scene-reset-sequence-original-llvm-v2/receipt.json) passes 256 cases. For the changed offline resource path, `verify_session_resource_import.py --compiler llvm --offline-only --output <fresh-directory>` runs the bounded 360-case matrix; the original complete verifier remains available without `--offline-only` for final acceptance. Routine test selection does not weaken the final required matrix.

[Room-camera import](../../build-native-sjuni/room-camera-records-llvm-v1/receipt.json) uses the current 67 production archives, compiles only its original bodies and fixture (1.41 and 2.06 seconds), links in 0.14 seconds, and runs all 166 owned room sections plus synthetic boundaries in 1.69 seconds. Its 1,048,895 checks pass with empty source/archive drift. [Offline room variants](../../build-native-sjuni/offline-room-variants-llvm-v1/receipt.json) uses the same archive identities and passes 3,674,929 checks. Neither comparison recompiles a private production closure or runs GCC. The legacy whole-VM `5A` coverage expectation was corrected but that large verifier was not rerun here; retain its final acceptance gate.
