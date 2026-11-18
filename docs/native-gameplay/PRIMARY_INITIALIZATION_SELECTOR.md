# Native primary initialization branch selector

`initialize_primary_actor` now reads the actual native outer-update State and
the canonical signed World pause byte, then invokes exactly one admitted
initialization branch. Nonzero notification pending with pause zero selects
restoration; every other pair selects fresh default/custom/saved initialization.
It does not cache the choice, mutate the notification byte, advance a clock or
construct a launcher window.

Both compilers compare every notification/pause byte pair against complete
owned 66A750: 65,536 cases with exactly 255 restore selections. Tests include
canonical exit-request bypass, retained saved-action pose, health/class/flags,
equipment, visibility and motion state. The original oracle receives the actual
raw notification byte, including full-initialization cases with nonzero pause.
Restore preserves a pre-existing constraint owner when the exit request bypasses
reinitialization; the comparison now accounts for that retained owner too.

The combined cohort passes 39,664,817 initialization checks, retaining all
32,768 defaults, 4,384 real custom constructions, 4,096 direct restore cases,
65,536 setters, 65,536 saved initializations, full signed action-byte checks and
the shared-bank publication. The separate 468,289 custom-statistic comparisons
and all fifteen parent tests also pass on both compilers.

Reproduce with `verify_primary_actor_initialization.py --custom --saved` and
fresh output folders. Evidence is `primary-initialization-selector-{llvm,gcc}-v1`.
The exact unchanged production closures of the recent World and behavior
cohorts are checked by `native_primary_initialization_selector_qualification_v1.json`.
Historical receipts remain bound to their captured sources.

The API accepts the real Update State; actual primary model loading/reuse and
scene/resume callers still need to adopt it. Model retirement, character-bank
release, complete semantic save ownership and installed native gameplay remain
open. This is a component checkpoint. The installed game is still V39 and no
game was launched.
