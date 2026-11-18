# Shared secondary resource retirement

`SceneRecordAttachment` retains a genuine ID in the existing shared128 scene/
control/collision owner. It allocates no second record and carries no primary
model flag capability. The base attachment now represents lifetime only;
`SceneFlagAttachment` supplies the separate primary flag interface. Applying a
primary-only flag operation to a different capability fails explicitly.

`ResourceFrames::release` implements5B1850 and the5B1A90 attachment-flag wrapper.
Inactive descriptors retain their pointers and flags. Active descriptors retire
the actual64-owner primary model first, then their actual shared128 secondary
record, clear those capabilities and optionally clear descriptor flag20000.
The descriptor itself keeps its identity. A required secondary must belong to
the explicitly bound shared owner and still be current. Foreign/stale/unknown
capabilities fail before retiring a valid primary; unsupported raw-pointer
profiles are not claimed equivalent.

Both compilers pass52,708,394 checks,134 release cases and seven model passes.
The release cases cover128 direct combinations plus six real weapon/common
callback chains that self-retire during the64-model update. Original complete
5B1850/5B1A90/590D80/5C12A0 bodies run with both original pools. Native scene
controls and collision proxies observe the same secondary retirement; retained
IDs never retarget its reused slot. The same cohorts compare214,272 WMD frames,
262,144 pose cases and eighteen native safety/refusal cases. Actor status200
permits static-base copying; it is not included in the5E0 retirement mask.

Current pulse/visual composition passes4,060,214 checks on each compiler.
The scene-resource regression passes10,610 checks and2,589 original calls.
Full current unpinned scenario dispatch passes14,067,135 checks and30,185 original
dispatches per compiler, preserving327/432 ordinary and300/432 offline algorithm
bindings, including no-ops. These counts are not whole-game coverage. Parent
libraries and four existing World/contact tests also pass. Exact immutable
sources and outputs are bound in `native_resource_secondary_qualification_v1.json`.

The next592770 branch needs a naming correction to older checkpoint notes:
following591BE0 shows descriptor deactivation and active-count decrement, not
resource construction. It first releases the instances, then conditionally
deactivates through the template40000 flag and signed parameter gate. That
branch, extended actors, actual asset/resource construction, installation and
representative gameplay acceptance remain open. No game was launched.
