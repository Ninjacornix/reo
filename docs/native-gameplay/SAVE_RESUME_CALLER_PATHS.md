# Temporary-save and resume caller paths

Static File #1 source/data evidence, 2026-11-09. No game, input, live attachment, build or save-file mutation was used. This narrows earlier unresolved source bindings; it does not prove an actual temporary save or resume worked.

Overlay o0 contains the two directional lookups over the owned byte-pair table at `3898C8`: `37B910` maps runtime scenario IDs to selection indices, and `37B950` maps those indices back to runtime IDs. The complete table is `(0,1), (1,35), (2,28), (3,2), (4,41), (FF,FF)`. Both return -1 when no admitted key is found. The o0 decoded image is SHA-256 `bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2`.

`register_o0.cpp` registers `37B950` with base `370000`, magic `336F574D`, id offset4 and id1. This is an image-qualified binding outside the shared `570000` overlay window. A controlled live case must still verify the actual loaded tag/body; merely finding this source file does not prove which code executed in a past run. The older card UI notes correctly left that runtime observation open.

The special gameplay save-and-main-menu handler `o2:6ED6D0` reads the current runtime scenario at `6ED830`, calls `37B910` at `6ED838`, sets the second-section/temporary flag at `6ED83C`, writes lookup-index+1 to `32448D` at `6ED858`, then calls `1C2600(3,1)` at `6ED85C`. Thus the saved resume selector is not itself the runtime scenario ID. The native snapshot core retains it as an uninterpreted byte; a later native world integration must preserve the same selection policy or explicitly convert it.

The frontend single-play controller `o1:582230` calls `1C2600(3,2)` at `5823C8`, which selects resident resume-read handler `1C3950`. Its successful restore subtracts one from the saved selector and resolves through `37B950`; invalid/nonpositive results lead to the original fallback. This path can read ordinary profile data with no temporary flag; that would establish entry execution, not successful gameplay resume.

The same frontend calls `1C2600(3,4)` at `5824E8` after the temporary-data prompt, selecting `1C3590`. That handler restores, clears the two resume flags, recaptures and rewrites through the original card backend when required. Owned prompt wording about temporary data being deleted does not justify calling the measured operation host file deletion. An end-to-end claim needs the successful rewrite and later ordinary menu/gameplay state, not just acknowledgement input.

Event callback `o2:5BAD70` sets gate `4BAE97` in phase1 and waits for it to clear in phase2. Existing source connects this gate to the special UI5 save route. The stock script/event/content record and ordinary room interaction that schedules that callback remain unlocated in this investigation; the scenario-content agent also has no admitted retail binding yet. Setting a live guest flag or fabricating a temporary world snapshot would not establish the requested ordinary gameplay save/reload/resume path.

The source-verified title OPTIONS save/load/policy/automatic paths remain separate from these temporary gameplay paths. Future cases should first preserve an actual successful private card, then distinguish valid autoload, explicit load, temporary rewrite, and actual resumed gameplay. No arbitrary test-only profile is presented as a retail gameplay save.

The complete function/table/registration evidence is in `build-native-sjuni/native-gameplay/save-resume-caller-paths-v1.json`, SHA-256 `4ec7ef717ecf2bc8b84918a863fd22beabb0561d2aeb90fa50d2dea6ed9aab24`, reproducible with `tools/native_reconstruction/save_resume_caller_paths.py`. Earlier historical mappings are preserved. Stage 4 and real gameplay resume remain open.
