# Native enemy spawn records and initialized route metadata

The Session now owns the256-entry enemy spawn table, expiry values, room counts
and starts, class/room route-bank assignments and the final1B2D80 reset state.
`Owner::load_scenario_enemies` uses the canonical scenario, launch choice row and
raw mode to read the matching file through the native scenario archive.
The record importer supplies the bounded successful-load6BAA40 expansion.

Raw mode0 selects `sgl_e%03u.emd`, uses the choice row's low two bits for group
selection and selects the offline health table. Other raw modes select
`e%03u.emd` and the observed shared RNG group. The earlier static notebook's
mode wording confused1B02D0's boolean return with the raw mode. Its affected
entries have been corrected after following complete1B02D0/1B0300 and executing
the original importer.

The importer preserves integer-to-float-to-integer coordinate rounding,
positive saturation, mask filtering, signed/unsigned narrowing, linked-ID byte
wrap, room-run start updates, room-count wrap and the rotating RNG seed.
Tracked records register kind2 on the actual shared AI owner. Two health tables
and the initialized selector window are reproduced from hash-verified owned
bytes by the two profile scripts. Malformed, oversized and unavailable profiles
preserve the previous descriptors, RNG and registrations through a staged commit.

`EnemyRoutes` supplies bounded complete5A7BC0/6D45A0/6D4650/6BC210 selection and
position lookup. The four initialized route trees for scenarios1,6,35 and41
become native constant sequences. Missing classes, FFFF banks and authored
null entries complete with position-1. Reached unknown roots, banks or selectors
return unavailable. Runtime-initialized data outside the file-backed image
remains an open producer dependency.

LLVM and GCC each pass101,844,008 identical scenario checks. The enemy part
compares24,800 complete original route queries and1,163 successful imports.
The imports include160 cases across all ten hash-verified owned EMD files,
four choice rows and four observed group values. There are7,968 explicit route
profile refusals and26 atomic import refusals. File formatting/acquisition and
memory library functions remain declared fixture ports. No game runs in these
comparisons.

The direct archive cohorts pass14,206 checks each over186 exact member payloads,
including all ten enemy loads through the actual Update owner. Three native
boundary regressions cover256 records with byte-sized count publication,
a257th record and a truncated terminator. The latter two preserve prior state.
Seven parent integration tests pass with each compiler. The archive probe's
initial filename assumption covered `r` prefixes. It now validates the EMD
filename forms separately. Evidence is sealed in
`native_enemy_descriptors_qualification_v1.json`.

Actual class/room assignment producers, missing-character command84, enemy
actor/model construction, behavior and room orchestration, save integration
and coherent native gameplay acceptance remain open. Installed gameplay remains
V39 and Step4 remains incomplete. These results establish component behavior.
No measured live slowdown fix is claimed.
