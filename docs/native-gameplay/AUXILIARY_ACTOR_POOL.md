# Canonical auxiliary actor pool

Status: qualified on LLVM and GCC; uninstalled. Stage4 remains incomplete.
InstalledV39 is unchanged and no game was launched.

World now owns one ten-actor AuxiliaryActorPool for the682C60/682D10/682E30
domain. It is separate from the existing fifty-model LinkedModelPool. Both use
the same canonical Actor/entity store, while retaining independent capacities,
list membership and physical allocation order. Generic World retirement refuses
auxiliary members so their pool metadata cannot become detached from storage.

Allocation preserves the source head/tail choice, LIFO free order, mutable slot
byte and independent physical identity. Reset also clears the four attachment
reservations; claiming a reservation does not allocate an actor or a model.
Identifier lookup supplies both the unfiltered666640 and active-only682F80
policies, including first match and full-width input comparison.

Native retirement invalidates the entity capability permanently. A retained
invocation lease keeps the old Actor value, while physical reuse creates a new
object and identity. Free-slot metadata preserves only the source slot-byte
reuse contract; it is not another active Actor record. Cleared scalar/contact/
gauge fields have native initialization, while unresolved model/scene and
phase-qualified alignment capabilities wait for their actual producers.

Both compilers execute the six complete original bodies, with256 allocation/
release/reset epochs,2,560 reuses,267,776 identifier lookups and5,378 explicit
refusal checks. The matrix covers both list ends, all slot-byte values, first
match/activity filtering, high-word inputs, attachment exhaustion, protected
retirement, stale/foreign capabilities and entity generation/capacity exhaustion.
Four lifetime compositions include50-model coexistence, reset, destruction
reentry and World shutdown. The combined89,918,019 checks are identical.

Fresh World comparisons pass4,096 cases and81 lifetime checks; behavior
comparisons pass32,768 cases. Parent builds and all eight integration checks pass
per compiler. Eleven comparison drivers add only the newly required link unit;
their dependency changes are verified against the preceding commit. Evidence:
`native_auxiliary_actor_pool_qualification_v1.json`.

Actual auxiliary template/model/resource construction, child attachment release,
callback/AI/movement passes, peer-message binding, semantic saves and installed
game acceptance remain open. This establishes the actor lifetime/lookup owner,
not a complete auxiliary actor implementation or slowdown fix.
