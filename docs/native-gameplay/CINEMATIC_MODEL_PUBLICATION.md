# Cinematic primary model publication

Status: component qualification passed on both compilers; not installed. Stage 4 remains
incomplete and the installed game remains V39. No game session or performance
measurement is claimed here.

`CinematicModelPass` implements the separate5ECB80 pass over the actual eight
fixed temporary actors. Active actors publish even when hidden. Main actors,
auxiliary NPCs and linked models belong to other passes. Absent temporary
storage requires no allocation. The synchronous consumer borrows World and
correction metadata and holds the World traversal guard during publication.

Its376CF0 path scales the root, applies5D6FC0 height correction, then uses
standard376D50 publication. It preserves the actor's current basis translation;
copying Actor.position into that basis would change the source behavior. It
never selects the ordinary primary5D6400 constrained path. Existing ordinary
publication shares the extracted standard publication helper.

Composition exposed a native state duplication: original Actor+B40 controls
both scripted bank/rate selection and paused height correction. The single
canonical Actor.model_correction_skip byte now supplies commands, scripted
playback and model correction. ScriptedActorState no longer holds another copy.
Temporary scene construction explicitly resets the canonical byte after cloning,
as the original constructor clears that control range.

The comparison executes complete original5ECB80,376CF0,5D6FC0,376D50 and recursive
model publication bodies, with owned instruction verification. Initial reference
nodes project the separately qualified native importer and current link state;
this does not newly validate original packing. Actual P07_00, HP07, HN54 and HN88
skeletons supply the model nodes. Controlled local translations, distinct actor
position/basis, restored topology, activity, visibility and signed pause inputs
exercise repeated publication and preserve earlier snapshots. A real motion
command executes on both implementations before publication to check shared B40
ownership. The native joint-two collision view is checked against the resulting
node; the original376D50 does not write Actor+4D4.

Missing later models and metadata exceptions retain the completed publication
prefix and release guards. Reentry, World close and temporary generation reset
are refused while the metadata provider is running. Required failures remain
visible to the enclosing scene owner.

The first comparison exposed an additional metadata gap: the old correction
profile admitted only125 ordinary N-file variants. Its successor also binds the
108 owned HN filenames directly to the correction table, yielding150 nonzero
variant IDs in the union. HN00 still follows the character branch because variant0
is the source sentinel. The constructor and full height-correction body are
verified against owned instructions; these are actual table values, not default
scales. This expands correction metadata admission, not complete asset/behavior
admission for every named NPC.

The first ordinary-pose regression also exposed a stale standalone link recipe:
World now closes the navigation bank, so its concrete implementation is required
in that fixture. The normal CMake owner already supplies this dependency.

Both `cinematic-model-pass-{llvm,gcc}-v3` cohorts pass11,082,240 checks,
including512 passes,2,176 actor publications,279,552 compared joints and192
actual authored command/publication compositions. Two explicit failure cases
check missing models and throwing metadata. V1 retains the strict-warning
fixture failure; V2 retains the missing high-detail metadata finding. Current
ordinary pose regressions pass14,502,515 checks, including65,536 correction cases
and64 complete ordinary publications. Current model-lifetime comparisons pass
150,804 checks and all five dependent parents pass on both compilers. Evidence:
`tools/native_reconstruction/native_cinematic_model_publication_qualification_v1.json`.
 Full scene phase admission, reaction/secondary
pose composition, category10 object lifetimes, complete entry/exit and installed
native gameplay acceptance remain open.
