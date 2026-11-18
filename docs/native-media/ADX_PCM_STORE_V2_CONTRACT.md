# Phased PCM storage for complete decoder ordering

Status: new v2 prototype/contract, before qualification, 2026-11-06.
The frozen [v1 storage core](ADX_PCM_STORE_IMPLEMENTATION.md) and all its evidence
remain unchanged. Final storage parity does not prove inter-system ordering.

The original writes raw PCM, performs corrected-production wrap, updates inner
decoder state, then returns encoded input credit before PCM callbacks and actual
output publication. V1's combined write/publish call cannot expose this middle
boundary. A complete Window2 must not move raw stores past source-credit guards.

V2 keeps the v1 storage/lease/physical ownership design and separates it into
`reserve`, `stage` and `publish`. Stage performs all admitted raw stores and
corrected wrap copies; it publishes no logical data, returns no credit and emits
no publication callback. It retains each full producer descriptor and records
the exact publication prefix internally. The caller can then update native
decoder/predictor state and finish the real Source2 encoded batch. Publish uses
the already-stored PCM and actual per-channel callback/Split/Put/Unget sequence;
it never rereads the caller's scalar workspace.

After staging, all PCM mutations except explicit publish refuse: read acquisition,
consumer finish, restore, stop and retirement cannot change the checked geometry
or roll back raw effects. Existing held read views remain readable and protected.
A lost staged token leaves the owner blocked with retained storage and credit;
destruction does not publish or return anything. If encoded credit fails, Window2
must keep the staged PCM and fault ownership; it cannot retry original decode or
fabricate retirement. The convenience combined call remains only a composition
of these two operations, not an excuse to skip the middle boundary in Window2.

V2 requires all prior storage tests, explicit intermediate-state assertions,
private post-prefix/ID faults and negative controls, plus **new original read-only
capture at the encoded Put boundary** on both compilers. Original decoded PCM
remains supplied input for this storage-only qualification. This still does not
prove the entire Source2/header/loop/workspace/PCM owner or a device fence.
