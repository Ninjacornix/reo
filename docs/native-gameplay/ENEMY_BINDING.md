# Native expanded enemy record binding

The bounded6BBDA0 binder now operates on an actual Actor leased from the
World's fifty-node LinkedModelPool. It requires the linked enemy category2
used by6BB040. Health, position, orientation, model scale, descriptor identity,
collision priority and numeric policy fields use their canonical native owners.
The source's definition scale and nonzero R57..59 percentage overrides retain
FP32 operation order. Two timer selections consume the existing Session RNG
in source order.

BA1/BA3 writes use masks over the canonical status word. BA4/BA6/BA7 writes
use masks over the canonical auxiliary status word. The model motion-style
selector occupies B99. The ten R2F..38 bytes supply existing BAC, BB0 and BB4
state through bit-preserving typed writes. Priority initialization remains the
parent's subsequent6BB9F0 operation and uses the existing BB6/BB8 halfwords.

Linked-family C84..C90 policy values and the float at BD0 belong to the typed
EnemyState component. Primary inventory and primary pending-hit semantics
have their own family-qualified owners. Numeric parameter names retain the
source locations where their gameplay meaning remains unconfirmed.

The source's final target becomes a portable primary ActorReference with
the selected actor byte. Its earlier C25/C26 hints remain independent values.
The transient encoded target is overwritten before the original returns.
Its intervening children read category, slot, character and AI-control state.
The self reference from1DC to the actor's own AEC state is represented through
direct canonical Actor ownership.

Complete6EFAF0 also supplies the body-priority query. Mode0 selects the offline
table. Other raw modes select the ordinary table. Controlled primary actors,
category1 and other categories retain their source branches. Admission covers
the62 owned model classes and eight controlled-primary character entries.
The binder additionally requires four policy indices and one timer profile
within their reviewed eight-entry extents. Failed admission preserves Actor
and RNG state.

The comparison executes complete owned6BBDA0,6EFAF0 and main RNG children.
It checks4,096 record bindings, all defined output fields, every other original
actor byte, integer-to-float boundaries, partial status writes, two-stream RNG
state, full-byte target selectors and preserved pool capacity. Separate body
priority checks cover four raw modes, category branches, both AI-control states
and every byte-sized slot/character input. Refusals cover invalid policy data,
metadata, ownership, stale IDs and closed Worlds.

LLVM and GCC each pass425,065,503 identical checks in the current full
scenario cohort. The binder accounts for4,096 successful calls and14 refusal
cases. The body-priority query accounts for7,696 complete original calls and
2,545 admission/closed-owner refusals. Seven parent integration tests pass
with each compiler. The direct archive regression passes14,206 checks across
186 members, including all ten owned EMD files. The scenario opcode ledger
remainsv25. `native_enemy_binding_qualification_v1.json` seals this evidence.

Model/resource construction and texture/audio acquisition remain surrounding
6BB040/6BA790 work. Enemy behavior, room orchestration, real game installation
and Step4 acceptance remain open. These comparisons provide component evidence.
