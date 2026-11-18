# Scenario resource identity and packaged object loading

Status: qualified on both compilers; uninstalled. Step4 remains incomplete.

Scenario resources have an identity separate from their AFS display names.
Each owned `rNNN_h.bin` contains a starting member ordinal and sixteen-byte
keys. Complete original1A9D70 normalizes a requested basename and returns the
first matching key's ordinal. Complete1AAAD0 derives an object basename from
the authored texture path, appends `.NBD`, and explicitly terminates at16 bytes.
For example, `obj00_06_a_00.nbd` becomes `obj00_06_a_00.NB` before resolution.
No filename extension is guessed or restored for the archive lookup.

`ScenarioArchive::read_resource` now retains these actual index tables and
resolves their member extents independently of display names. Duplicate keys
preserve original first-match order. Invalid table extents refuse; unknown
keys return no content. The bounded normalizer preserves slash precedence,
ASCII case conversion and punctuation substitution. Existing display-name
reads keep their separate duplicate-name checks. Cinematic object loading uses
the indexed reader with the original explicit16-byte termination.

Both final cinematic-object-combined-loader-{llvm,gcc}-v7 comparisons pass
637,125 checks over2,144 projected constructions and2,684 objects. Complete
5ECF90/5F0610/1D13F0/1AAAD0/1CD710/1CF560/1CDFE0 now execute; the actual
scenario filename and model/skeleton section selection are no longer supplied
by the earlier combined-loader port for packaged loads. Complete1A9D70 selects
member bytes independently, matching the native reader on2,013 loads. All five
header payloads match the pinned owned inventory hashes.

The final scenario-resource-index-{llvm,gcc}-v3 checks pass14,265 comparisons:
186 existing script/NPC/enemy reads and owner bindings plus index fixtures.
Fixtures cover first-match duplicates with distinct member contents, display
name independence, case/path/punctuation, long/empty/NUL keys and malformed
header ranges/counts. Both asset regressions pass452 imports and450 canonical
indexed reads. The five parent tests pass on both compilers. Controlled object
playback remains1,296/1,356; the60 too-few-track pairs and12 missing-model
descriptor requests remain unresolved.

Normal-mode1CE110, texture decode/upload and renderer part publication remain
explicit boundaries. Unprojected model-family branches and second node banks
throw if reached. The comparison still derives requests from descriptor names;
actual scene-controller reachability, cadence, activation and actor parents
remain open. It does not establish a game regression or a slowdown cause.

Evidence: `tools/native_reconstruction/native_scenario_resource_index_qualification_v1.json`.
Early failed fixtures, including the discovered `.NB` identity mismatch, the
GCC string-port warning and an unaligned synthetic AFS fixture, remain retained.
No game, audio, renderer, input, device or power action was used. Full Step4
implementation, installation and gameplay acceptance remain open.
