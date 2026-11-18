# Preparing original file starts from the retained mount

The game binding can now prepare an ordinary file source from the same verified,
immutable native mount. It copies no payload, opens no second mount, starts no
worker and performs no source retirement. Preparation occurs outside canonical
controller admission; the eventual source player owns its independent worker.

The first profile admits File #1 import version 1 without an overlay, a bounded
ASCII filename, the opaque original backend argument zero, and a sector-aligned
root within the qualified signed byte domain. Supported path spelling follows
the existing CDVD facade's case/separator/prefix behavior for `cdrom0:`, `cdrom:`
and `host:`; version handling admits the selected `;1` form. Other prefixes,
versions, embedded NUL, empty/dot/traversal components and oversized names are
explicitly refused. The result uses only canonical mount lookup, never an
arbitrary host path or a filename search through unrelated archives.

Range preparation reuses the qualified `afs_source_range::prepare_open`
reconstruction. Finite counts clamp to the backend's remaining sectors. The
default `0xfffff` sentinel retains the whole backend byte length; a nonzero start
with that sentinel is refused instead of silently changing it to remaining
bytes. Empty ranges have a separate result and do not pretend to be a successful
player start. A ready view is bounded to the exact admitted subrange and retains
the pinned provider independently of the mount and route facade.

Both compilers pass **44 checks using the actual imported files**. They compare
an exact 4096-byte subrange through six filename spellings, verify the boundary,
finite clamping, empty/default-sentinel handling and explicit refusals, then
read the retained subrange after every other prepared view, root route and mount
has left scope. Both detect an injected fault that ignores the start sector.
Imported file statistics and the import manifest remain unchanged.

V1 passed but held other prepared views during the final lifetime read. V2
tightens that fixture scope and adds the subrange fault. The production helper
is unchanged. The earlier four authored inputs are retained under
`build-native-sjuni/adxt-binding/file-source-v1-source`; V2 is the current cohort.

`recomp/overrides/native_adxt/source_profile_qualification.json` identifies those
receipts and their unchanged native archive dependencies. These are real file
provider tests, not actual runtime RAM admission, original scheduler execution,
ADX playback or an audio device test. The helper does not infer the semantics of
nonzero backend arguments. Actual pending-start observations must establish the
required game profile before that adapter is activated. It was authored after
the V17 kit was sealed and is outside that build. Step 3 remains open.
