# Resident primary model resources

Status: native ownership foundation, not full scene handoff or installed gameplay.
Step4 remains incomplete. No game was run; installed game remains V39.

Each `PrimaryActorModels` physical row now owns its asset and both mutable model
instances independently of its Actor identity. `resident(slot)` returns a retained
read-only lease. Actor channels, root history and constraint state remain with the
Actor. A successful cache reuse keeps the same resident instances; replacement
and explicit retirement update the resident row within the existing guarded
operation. Even an initializer failure retains the committed allocated model
prefix while leaving the cache key uncommitted.

Retiring an Actor generation therefore does not discard its resident resource.
An unrelated replacement Actor still cannot adopt that row implicitly. Capture
also rejects inconsistent Actor/resource associations. Owner closure first seals
the cache and clears every visible row, then destroys its old resource references
under the World guard. External retained leases remain independently valid.

Both `primary-resident-resources-{llvm,gcc}-v1` cohorts pass124598 checks, all
existing original cache/scene/roster comparisons and the native-only parent test. New lifetime
cases cover all eight slots with and without an external lease, seventeen stale
binding refusals, eight real-clip destructor guard observations, eight surviving
leases and one actual initializer-refusal prefix. Real assets and native model
instances execute; these lifetime assertions do not pretend that a guest pointer
is a native ownership object. The source/evidence seal is
`tools/native_reconstruction/native_primary_resident_resources_qualification_v1.json`.

The source lifetime audit established why this is needed:5ED770 invokes5ED340,
which resets temporary Actor records before descriptor resource retirement.
Explicit scene authority, temporary model binding, return to main bindings and
post-reset retirement remain separate required work. No public stale-ID bypass,
automatic temporary admission or update-readiness claim is introduced here.
