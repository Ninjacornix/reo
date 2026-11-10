# Native actor resource operations and shared action notices

Status: qualified on both compilers. Not installed;
Stage4 remains incomplete. The installed game remains V39.

`ActorResourceOperations` supplies5F4FE0 quantity transfer,5F5C50 instance release
and5F6A80 content remapping using the existing canonical recipes, inventory,
content, model and shared-secondary owners. Category1 bypasses locality;
otherwise mode0 requires the actor's slot to equal the session's selected actor,
mode1 requires a different slot and other low-byte modes bypass the test.
Rejection returns-1 before resource mutations or action-notice writes.

Quantity transfer executes the real owned-pair operation. Result0 returns before
journaling. Results2/3 remove the corresponding actor inventory reference and
compact through the real inventory owner; current qualified lower operations
produce0/1/3, so the result2 branch is retained without claiming an observed
result2 producer. Other nonzero results still reach the journal with result0.
Except mode1, the caller ORs1000 and narrows first/second/amount into the three
shared notice payload bytes. Full-width arguments still reach their original
low-byte/low-halfword consumers before that journal narrowing.

Instance release uses the actual primary/shared-secondary lifecycle and returns1,
including an inactive record's intentional no-op. It preserves owner, quantity,
selected/inventory references and descriptor flag20000. Except mode1, it ORs800
and writes the first payload byte, preserving the other two bytes.

Content remapping uses the actual0/1/B to1C5/1C8/1C6 mutation/rebinding consumer.
Only successful remapping of the actor's currently selected resource detaches
instances, clears20000 and clears the selected resource/action. It preserves
other inventory references. Except mode1,8000 and the first payload byte are
published even when remapping returned0.

## Canonical notice correction

The earlier native equipment producer wrote `equipment_notice_flags`, while
the World frame independently reset/tested `pending_notice`. Both represented
original actor halfwordD92. The isolated primitive and frame comparisons each
passed against their own field, leaving their actual composition disconnected.
This was a native integration defect in the uninstalled components, not a
reproduced installed-game slowdown or a new measurement of the player's session.

All producers now write the World-owned `pending_notice` field. The duplicate
field is removed. The three payload bytes remain independent and survive frame
flag clearing. Equipment's complete65E710 producer is in a small separate
translation unit so its actual composition can be checked without loading
unrelated animation/audio/contact consumers. Its public entry remains unchanged.

The integrated cases invoke real equipment and instance-release producers
during `World::update_primary`. Both masks arrive at its publication stage and
are cleared only after the declared observer returns. A throwing observer
retains flags and earlier model retirement. No-writer cases also verify that a
prior flag value is reset without clearing payload bytes. Other frame services
and final notice delivery remain declared test seams; this does not close actual
network/UI delivery. The separate complete original frame/direct-input and
animation/weapon comparisons are refreshed against the same canonical field.

Both final main cohorts pass372,678,288 combined assertions with identical
observations:1,179,648 actor-operation cases across five owned ITEM sections and
a controlled compatibility bank,393,216 independent locality/category gate
cases,1,728 actual primary/proxy/inventory lifecycle cases, five refusal groups
and12 publication observations across16 native frame-composition cases. The
transfer-result mask records0/1/3/-1; it does not claim result2 execution.

Both parent builds and eight integration tests per compiler pass. Current
animation/weapon comparisons pass11,671,463 assertions per compiler, including
the complete original65E710 producer. Refreshed complete669F30/1B0B80 frame/input
comparisons pass4,096 cases and291,127 ordered calls, plus78 native lifetime
checks, per compiler. The old frame driver lacked current linked-model objects;
its new revision freezes all transitive native headers and links the actual
current model/body dependencies. Failed link receipts are retained. None of
these comparison programs constructs a game window or output device.

Final source/cohort identities are sealed in
`native_actor_resource_operations_qualification_v1.json`, SHA256
bc9b64de1e434d2db2f8190c9c2bf9759b791bfce2797d9fcfa2a0f2874a3044.

Higher-level acquisition/transfer/peer cleanup, action/AI dispatch, authority
statistics, actual final notice/message/UI consumers and game installation
remain open. Borrowed owners outlive calls. Stale/foreign/null actor identities,
closed owners and missing reached metadata refuse without a successful fallback.
No game, physical audio device or window/input action was used.
