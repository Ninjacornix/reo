# Script resource quantity and retirement

Opcode170's ordinary and offline bindings both call complete6949A0. Native
`ScriptResourceParameters` now composes the canonical World, SceneResources,
ResourceTemplates, ResourceModels, ResourceFactory and WorldInventory. Its
constructor and Program admission reject missing or foreign ownership. It
does not substitute successful effect or inventory callbacks.

The source consumes an unsigned16 resource and signed16 quantity. The exact
early gate is World mode0, gameplay_flags bit0 and resource31; this path needs
no resource owner. Other paths perform the original first attached-resource
lookup, including signed lookup semantics, active/flag/owner tests. Metadata
is selected through the matched descriptor's instance_index, which may alias
another descriptor. The maximum quantity is signed16 and clamps only above.

Two metadata queries deliberately differ: complete5B4380 uses fallback row128
for inactive or FF-template descriptors, while complete5B43F0 returns zero
flags in those cases. Full original-code comparison caught and corrected an
initial implementation that incorrectly used fallback flags for release.
Flag40000 plus a clamped quantity of0 invokes the existing complete592CA0
native detach sequence; other values write the matched descriptor's parameter.
Detach preserves the parameter and uses actual factory release/deactivation,
inventory removal/equipment cleanup/compaction and model-pool retirement.

The bounded native profile admits all129 metadata slots and the four concrete
primary inventory owners. Required extended-owner retirement, invalid metadata,
missing primary actors and foreign owner bindings refuse explicitly. Nonrelease
quantity updates do not require an inventory-owner lookup. Static resource
assets remain cold during retirement because no source asset selection occurs.

The full VM cohort executes the complete original ordinary/offline dispatchers,
6949A0, metadata/flag lookup, attached lookup/detach, primary inventory find and
remove, equipment detach, inventory compaction, descriptor release/deactivation
and resource model retirement. Only the original secondary attachment retirement
branch is outside this cohort; reaching it throws, rather than reporting success.
Fixtures compare all256 complete descriptor records, all four inventories and
equipment fields, source/native active counts, live model generation/free count,
and cleared original model records. Coverage includes active/self-alias/inactive/
FF metadata, signed quantity/max edges, early gates, both profiles, actor categories
and relations, plus prefix admission failures.

Both final fullVM cohorts pass566,344,866 checks each, including4,098 new
dispatcher cases,32 real warm model retirements and8 prefix refusals. All11,784
owned original instruction comments are checked against the pinned binary.
Receipts are `build-native-sjuni/script-resource-parameters-vm-{llvm,gcc}-v2/receipt.json`.
Current17-parent cohorts pass on both compilers with no source drift at
`script-resource-parameters-parents-{llvm,gcc}-v2/receipt.json`.

Complete native Program admission checks all171 owned banks against baseline
72c77e8e using each version's original matching Program header. Counts remain
31ordinary/26offline; r001's ordinary frontier advances from170 at block2+1748
to174 at block2+2508. Other ordinary frontiers remain D0/108, and all five
offline frontiers remain1A8. No scenario EVB is completely admitted. Receipts
are `script-resource-parameters-admission-{llvm,gcc}-v1/receipt.json`; both
record no current source drift. The retained qualification seal is
`tools/native_reconstruction/native_script_resource_parameters_qualification_v1.json`.

This is a native script/resource ownership cut. Complete scenario EVB admission,
production NativeSession installation and Stage4 acceptance remain separate
requirements.
