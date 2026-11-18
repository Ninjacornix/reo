# Native delayed resource construction and callbacks

`ResourceFactory::create_delayed` supplies591400 through the existing native
64-model owner. It records actual signed cache lookup results but never copies
static part poses or emits companion visuals. It starts invisible, with identity
pose and unit scale. The canonical session clock_mode controls signed delay
halving toward zero; it does not change game speed or create another clock.

Callback class2 now uses concrete DelayedResourceWork. Complete593550 policy
always hides the model, wraps its signed16 timer down by one and proceeds only
at exactly zero. An inactive descriptor leaves the model allocated. An active
matching unowned descriptor uses the real primary placement and shared collision
constructors. Other rooms/owners only clear the specified descriptor flag.
The callback saves descriptor identity before any self-retirement and rereads
the canonical descriptor after construction. Natural model/collision exhaustion
preserves the measured prefix effects. A weak factory token rejects callbacks
after their factory is destroyed, without a reference cycle or dangling call.

The combined suite caught an error in the earlier primary factory: source
590C70(1) corresponds to the native front insertion. The factory had used back
insertion. Isolated one-model state comparisons did not distinguish these ends.
Both normal and delayed factories now use front insertion, and tests compare
head/tail plus every reached node's links. This supersedes the earlier factory/
placement checkpoints' incomplete multi-model ordering coverage. No game was
running with those uninstalled components; no historical slowdown cause is
claimed by this correction.

Both compilers pass14,283,910 assertions in the current combined suite.262,435
delayed constructions include all65,536 signed delays under clock modes0/1/2/255.
65,826 callback/pass cases cover the full signed timer transition domain,
288 room/owner/attachment combinations,24 successful reconstruction cases and
three actual capacity cases. Self/other/absent primary relationships execute
inside the original590EA0 and actual native model pass, including new models
visited during that same pass. The existing factory/placement/static/visual
suite remains enabled. Parent libraries and World/collision checks pass; exact
sources and outputs are sealed in `native_resource_delayed_qualification_v1.json`.

Class2 is supported; six5DF450 companion contents, larger primary roots and
unknown metadata profiles remain unavailable when reached. Binding these real
consumers into scenario commands, asset-loading callers and game installation
remain open. The installed game remains V39. No game was launched and Stage4
remains incomplete.
