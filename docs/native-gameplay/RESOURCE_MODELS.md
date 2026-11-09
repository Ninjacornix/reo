# Native primary resource model ownership

`ResourceModels` supplies the distinct64-object primary resource model domain
from590BE0/590C70/590D80. It is separate from the128 shared scene-control/
collision-proxy records and the168/256 effect-work domains. Resource descriptors
retain the same native `ResourceModel` instances owned here, rather than a
parallel pose or lifetime record.

Allocation preserves the original free-stack order (first physical slot63),
front/back insertion and physical-slot metadata. Retirement clears the model's
mutable data, unlinks it and returns its slot to the free stack. Native IDs and
retained model capabilities remain invalid after retirement, even if that
physical slot is reused. Resource attachment and WMD selectors now reject a
retired primary capability.

Update follows complete590EA0's tail-to-previous order, reading the previous
link after the callback. A callback may remove another model, prepend work or
request the final refresh. Self-retirement clears the current previous link and
can end that pass; this is not replaced with a snapshot/vector iteration.
The pause input skips before resetting the refresh request. Actual model work
and the final6AEDA0 consumer remain required native callbacks. Missing work
fails explicitly; this checkpoint does not adopt the generated zero-entry skip
as a successful implementation of an unknown callback.

Each compiler passes744874 checks,5103 controlled allocations/retirements and
112 update passes against complete owned allocator/list/update bodies. Tests
cover full capacity, LIFO reuse, mixed insertion,4096 bounded churn operations,
same-pass removal/insertion, self-retirement, pause and final refresh ordering.
The model callbacks and final refresh in this oracle are declared controlled
mutation/observation seams, not actual game visual implementations. The memcpy/
clear port is a declared byte-copy surrounding operation.

Six native safety cases cover stale/foreign identities, retained model
invalidation, missing work, bounded traversal and close. Retiring and reusing
the currently executing physical slot in one callback returns an explicit
`unadmitted_reuse`: the native invocation lease cannot retarget the new model.
The source can re-read the reused raw slot; that exceptional alias behavior is
not claimed equivalent or silently treated as a successful pass.

Both parent libraries compile. Actual resource construction, descriptor release
composition, common5932F0 updates, weapon6B45C0 playback, other callbacks, game
installation and full Stage4 acceptance remain open. No game is launched and no
performance improvement is claimed.
