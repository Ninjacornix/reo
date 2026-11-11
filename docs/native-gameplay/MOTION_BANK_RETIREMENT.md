# Native motion-bank retirement and character release

`MotionBank::clear` now supplies complete admitted 1B1BC0 retirement: clear all
2,000 token slots and all logical rows, zero the first-track/count bytes and
preserve the bank type. `cleared_bank` separately supplies an explicitly known
initial bank, with type zero by default, matching 1B2130's whole-object clear.
The two operations are deliberately distinct.

An ordinary default-constructed bank still has no admitted header profile.
An explicitly cleared bank instead has known absent tokens. Bounded lookups
return absence through the actual sparse/strided formulas, allowing existing
missing-token playback policies to run. Strided lookups outside the 2,000-slot
native domain still refuse rather than reading adjacent row-map storage as
resource tokens. A failed reload preserves the old clear state; a successful
load publishes its real kind/header and exits the cleared state.

This corrects the newly added primary bank's initial type. The generic native
default was sparse, whereas the original primary 4EA8C0 initial clear has type
zero. The primary publication now uses the explicit initial-clear factory.
This was caught before native game installation; it is not an attribution for
any historical slowdown.

`HumanoidMotionAssets::release_character` prepares an immutable child snapshot
for complete 5EC0E0/1B1BC0 character-bank release. It preserves the shared bank's
type, unaffected bank identities, default-loaded flag and previous snapshot
leases. An explicitly released never-loaded character obtains the known
initial zero type. Invalid character indices refuse before any change.

The live publication test clears character 3 in two actual NPC bindings while
preserving character 5, actor model/channel timing and old snapshot leases.
Reload updates the same semantic bindings. Across the focused case there are
six publications and 45 rebound resources, with existing stale-load, closure,
busy and guarded retirement checks retained. It does not claim a successful
animation from a missing clip.

Both compilers pass 255,057 basic bank checks: 25 bank cases, 20,000 explicit
cleared-token queries, four clear cases and nine lifetime cases. Complete owned
clear, release-loop and construction bodies execute; heap packing/release and
bounded memset remain the declared fixture ports. Actual token release calls
and subsequent zero slots are checked. Native retained snapshots/blocks remain
readable independently of the original heap observation.

The paired shared-bank cohort passes 317,889 native checks plus 13,432,451
original checks, including 932 bank cases, eight character releases and 50,000
released-character queries. It uses the actual owned PC, character and demo
assets and executes the complete o2 release route. Current primary initialization
passes 39,664,817 checks with all fifteen parents passing. Current World and
behavior regressions also pass on both compilers.

Reproduce with `animation/verify_motion_banks.py`, then
`verify_humanoid_motion_assets.py --publication`, and the existing World,
behavior and primary-initialization verifiers with fresh output directories.
Evidence is `motion-bank-retirement-{llvm,gcc}-v1`,
`humanoid-character-retirement-{llvm,gcc}-v1`, and
`motion-retirement-{world,behavior,primary}-{llvm,gcc}-v1`.
The combined seal is `native_motion_bank_retirement_qualification_v1.json`.

Actual primary model-cache loading/reuse, model-instance replacement, scene/
resume callers and coherent native game acceptance remain open. The installed
game is V39. No game was launched and Step 4 remains incomplete.
