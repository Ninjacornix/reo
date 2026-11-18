# Instance-owned model topology

Status: bounded native core qualified on both compilers. Not installed; Step4 is
incomplete. The installed game remains V39. No game or performance test was run.

Original61B1A0 patches parent/child/sibling links. The Yoko P07_00/HP07 assets
actually need this: ordinary restoration detaches nodes36/37, while the high
model detaches nodes73/74. Later owned recipes reconnect them. The other five
extra nodes remain separate authored branches. Treating every model traversal as
the immutable imported hierarchy cannot reproduce this contract.

`Instance` now owns typed links and current root traversal alongside its mutable
node/track state. The shared Skeleton remains immutable. Patches validate a
complete private candidate before publishing it: node/target bounds, child/sibling
cycles, shared paths and reachable parent consistency. Detached nodes retain
their storage, curves, poses and old parent metadata. Invalid changes preserve
the current links, traversal and immutable joint publication. Copies have their
own links and traversal; new sibling models start from authored topology.

Binding, clearing, sampling, whole-model admission, blending and recursive matrix
publication consume the instance topology. Constraint callbacks also read current
parents and child/sibling links. A whole-model clip is matched to the reachable
subtree count rather than all allocated nodes.

The coupled test exposed an earlier blender assumption: native code indexed the
source bank by the destination node's ordinal. Complete192710 instead walks both
banks' links together. The native implementation now follows both paths and finds
each bank's selected root independently. A missing required paired branch refuses
before blend mutation. It also preserves the original unmatched ancestor-sibling
subtree skip, which differs from the ordinary direct leaf-sibling path. This is
a native correctness fix before installation,
not evidence of an original-game defect or a measured slowdown cause.

The focused fixture uses real43/80-node models and actual restore/reconnect
recipes, complete owned61B1A0, binding, sampling, blending and recursive matrix
bodies. Additional curve containers are explicitly controlled prefixes of owned
curves, sized to the current41/43/78/80-node traversal. A controlled isomorphic
source-bank permutation forces paired nodes to have different physical ordinals;
it is not a stock authored layout. The fixture does not call the original on a
missing paired branch, cyclic topology or invalid identity.

The first topology V1 comparison failed; V2 located the mismatch in blending.
V3 completed the coupled comparisons but exposed an invalid negative fixture:
its supposedly wrong parent already matched HP07's real parent. The fixture now
uses an unequivocally inconsistent root parent. Those failed outputs are retained.
Constraint comparisons additionally detach the actual node7 child branch for
half their cases and compare complete original
callback traversal, copied owners, contexts and retained publication. This checks
that the new links reach the real constraint consumer.

Final playback cohorts are `instance-topology-{llvm,gcc}-v6`:5,308,826 checks,
16 main topology cycles,32 sample/blend comparisons,16 mixed-track skip cases,
16 copy cases,16 missing-pair refusals and14 invalid topology refusals. Eight
additional clear/reconnect cycles preserve detached bindings. Each invokes
14,623,650 original calls, retaining the previous full playback/routing coverage.
`instance-topology-constraints-{llvm,gcc}-v2` pass720,728 checks and512 callback
cases,256 with a detached branch. Current World regressions pass10,454,734 checks;
actual model-lifetime regressions pass150,804, and all five dependent parents
pass per compiler. Their sources, outputs and compiler identities are sealed in
`tools/native_reconstruction/native_instance_topology_qualification_v1.json`.

Actual61A6A0/61A820 selector and secondary-chain ownership, cinematic traversal,
all remaining scene actors/objects and installed gameplay/save/co-op/shutdown
acceptance remain separate work. This core supplies the required topology owner;
it does not declare those consumers migrated.
