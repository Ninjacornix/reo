# Cinematic primary character choice

Status: native choice preparation qualified on LLVM and GCC. Uninstalled;
temporary actor construction/model transfer and Step4 remain incomplete.

`select_cutscene_primaries` prepares the full5F0DC0 character-choice policy using
typed headers, the actual scene roster list, its one-based preference and current
temporary-slot occupancy. It preserves explicit kind0 requests, kind3 required
and optional fallback ordering, reserved characters, class-bit conversion and
first-inactive physical slots. With no relevant group, prior reservations remain
unchanged. A full pool returns a bounded selected prefix and the failed group;
no live Actor or model changes. Invalid roster preferences/counts refuse explicitly.
The scene preference must not be guessed from `World.selected_actor`.

The input captures all eight physical roster entries plus their population.
Construction searches all eight, even beyond that population. A matched class1
choice requests retirement of the corresponding main model and removes that
character from the subsequent scene roster. Choice preparation predicts the
matched slot and updated roster; it does not perform the model retirement.
Unused roster bytes must be captured, not silently inferred from population.

The current `cutscene-primary-selection-{llvm,gcc}-v6` cohorts pass869,033 checks
and31,494 complete original choice/construction comparisons. Coverage includes20,480 generated
cases and10,960 cases using all548 owned0950 descriptors, four roster profiles
and five preferences. Forty native full-pool cases refuse without executing the
original null-target path. Three invalid-preference cases also refuse explicitly.
Raw owned headers independently feed the original; the fixture does not rebuild
them from the native decoded values. Signed list-byte behavior is retained,
including repeated128 selections from unsigned roster queries when class1
retirement does not first remove that character. Targeted cases distinguish that
retirement, duplicate roster entries and a match beyond the active population.
Every population0..8 also runs against both empty and partially occupied pools.

Full5F0DC0/5F0C60/5F0CF0/5F0D90/5F1330/5F1400 bodies match owned words and execute.
The original construction copies bounded canonical actor records, applies actual
stores and updates the roster. Its5EC270 model-retirement request is observed;
actual native retirement has separate qualification and is not performed by this
selector. Per-group construction metadata arguments use a nonoverlapping fixture
arena, corresponding to native typed output. Original overlapping output arrays
above16 groups are not admitted as a live storage contract. These checks establish
choice preparation with constructor effects on selection, not complete native
Actor value cloning or model ownership. Fill/copy are bounded fixture ports.

The comparison compiles the real native descriptor parser and the exact three
immutable stream import methods extracted from their production translation unit.
The unrelated live World scheduler is not stubbed or executed. V1 retains a
comparison-build dependency failure. V2 included those production methods but
used a construction trace port; V3 expanded complete construction and corrected
the class1 roster-mutation omission before installation. Native CMake targets
also use normal library linkage.

The retained qualification seal is
`native_cutscene_primary_selection_qualification_v1.json`.

The [lifetime follow-up](PRIMARY_SCENE_LIFETIME_AUDIT.md) supersedes that cohort's
preference<=eligible-count admission. The current input names `eligible_count`
explicitly and accepts any preference within all eight captured character bytes.
Both physical-preference cohorts pass56,686 original comparisons and19,728 cases
from all548 owned descriptors, with72 explicit full-pool refusals. The constructor
regressions remain current; no temporary model-cache admission was opened.

Typed cloning, model-slot ownership across entry/exit, primary sparse cinematic
motion, sixteen category10 objects and full scene/game acceptance remain open.
No game was run or installed and no performance improvement is claimed.
