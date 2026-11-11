# Native actor model assets

ActorAssets reads the actual File #1 common archive and resolves ordinary and
alternate enemy/cutscene model definitions into immutable native assets.
Their skeleton sections use the existing native Skeleton importer. Each
make_instance call creates independent mutable model state. The asset retains
its bundle bytes and immutable skeleton through native shared ownership.

The common archive is indexed once. Successful model reads are cached by
directory entry. Concurrent misses publish one retained asset. File I/O and
skeleton decoding occur outside the cache mutex. Failed reads leave the cache
available for retry. The fixture checks cache reuse, concurrent publication,
independent instances, retained snapshots and a failed read followed by recovery.

Both initialized definition banks now include the construction-mode byte.
The alternate bank's class22 declares two rows and overlaps the following
definition group. Its second row remains admitted from the owned initialized
data. Classes60/61 have null alternate definitions. Ordinary zero-count aliases
retain their reviewed shared definitions. The generator validates the extent
of every admitted row against its owned bank.

The original name tables contain153 ordinary names, three null ordinary
entries and30 alternate names. Some ordinary entries select NPC bundles such
asN200.NBD. They use the same actual archive reader. Source1D1F40 is a complete
no-op on the selected edition. Full model/resource construction remains the
surrounding caller's responsibility.

LLVM and GCC each pass3,010 asset checks over410 definition combinations.
There are406 successful loads covering180 distinct owned NBD files, three
explicit FF model selectors and one missing model. Every loaded byte matches
an independently indexed source range. Skeleton node counts match an independent
raw-tree walk, and all406 native instances publish their initial joint poses.
The current full scenario comparison also passes425,083,581 checks per compiler,
including32,768 definition queries across both banks.

E03_01.NBD is named by ordinary class3 variant1 and is absent from the owned
common archive. A search of the top-level nested AFS directories also found no
member with that name. Reads report the missing asset. The qualification records
that limitation explicitly. This observation does not establish a runtime cause
for a historical slowdown.

Bundle data for meshes and textures remains retained for its rendering consumer.
GPU conversion/submission belongs to Step5. Actual actor construction and motion
bank acquisition, enemy behavior, sound ownership, real room transitions and
native game acceptance remain open in Step4. The installed game remains V39.
`native_actor_model_assets_qualification_v1.json` seals the component evidence.
