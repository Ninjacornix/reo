# Resource model continuation after slot reuse

This supersedes the `unadmitted_reuse` limit in the first
[resource-owner checkpoint](RESOURCE_MODELS.md). Complete590EA0 reads the current
physical row's previous link after its callback. A delayed callback can retire
its model and create a replacement in that row, so treating this as an automatic
failure prevents a valid construction path.

The native owner now reads its current slot occupant solely to choose the next
continuation. The old callback invocation lease, model object and generation ID
remain retired; none can retarget the new object. If the row stays empty, the
cleared old continuation ends the pass as before. Replacement at either list
end and an additional same-callback allocation follow the original ordering.
The existing traversal budget still bounds pathological repeated mutations.

Both compilers pass758,618 checks,5,487 allocation/retirement operations and160
passes against complete original owner bodies. Twenty-five native reuse cases
include the paired mutation passes and an additional lifetime contract. Existing
neighbor removal, insertion, refresh, pause, capacity and4,096-operation churn
cases remain included. Five other native safety cases check stale/foreign IDs,
missing work, traversal limits and close. Parent libraries compile.

`native_resource_models_qualification_v2.json` binds the exact code, source
comparisons and immutable outputs. The v1 source/receipt remains historical;
its refusal is no longer current behavior. This is a scheduler prerequisite for
actual delayed resource construction, which remains open. No game was launched.
