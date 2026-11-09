# Native resource descriptor allocation

`SceneResources::allocate` implements591AE0 in the canonical descriptor owner.
It scans slots1 through255, preserving reserved slot0, and refuses when the
derived active count reaches255. The first inactive row is cleared, assigned
active/kind1, the narrowed room/authored/content values and its real slot index,
then receives the canonical template selector. It creates no model or secondary
instance. Reusing a row invalidates its previous native descriptor ID; retained
capabilities cannot silently refer to the replacement. Raw source pointer reuse
is not a native compatibility promise.

`ResourceTemplates::selector` preserves complete5B42B0's signed16 input,
normalization of content10000..32767 into500..599, zero return for invalid
content and signed byte return from the600-entry selector table. A tableFF
means-1 and is distinct from the invalid-content return0. Allocation stores the
selector's low byte, exactly as the original consumer does.

Both compilers pass53,424,371 checks,327,680 signed-selector cases and1,295
allocations against the original complete bodies. All five owned item-template
sections are independently extracted and hash checked, loaded by both native
and complete5921D0 code, and compared before selection. Tests cover capacity,
reserved slot0, ascending reuse of four holes, narrowed arguments, selector
sign, cleared typed fields, generation invalidation and existing deactivation.
The first comparison caught an implementation error that scanned from0; the
failed cohorts remain preserved and the corrected scan is the qualified result.

The declared original107AB0 operation is a bounded byte copy into the four
template tables. It is not a resource loader or fake model provider. Native
allocation compares the fields currently owned by SceneDescriptor; unprojected
geometry and actual instance construction remain separate work. Count/table
consistency is an admitted source precondition, as in the deactivation cohort.
The standalone scene regression, parent builds and four World/contact tests
also pass. Exact sources, assets and outputs are bound in
`native_resource_descriptors_qualification_v1.json`.

Actual primary/secondary construction, NBD/static pose loading, extended actors,
game callers and Stage4 gameplay acceptance remain open. No game was launched.
