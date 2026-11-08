# Read-only LSC profile checkpoint

The pure `recomp/overrides/native_adxt/lsc_profile.h` reader inspects bounded
File #1 parent/child links, the original 16-entry LSC pool and 256-entry SJRB
pool, active/type words, queue bounds, capacity/minimum and backing geometry.
It reads no filename or source payload. It neither changes guest RAM nor creates
a runtime identity, native source capability, provider or worker.

The actual SJRB vtable is `224C28`, with count method `13FA38` at `224C4C`.
`23DA58` is UUID data and is deliberately refused as a vtable. The reader
separates fresh empty history from parsed nonempty metadata; it does not invent
an adoption or restart history. A nonzero global LSC callback at `21DFD8` is
outside this reader's initial profile.

Both GCC and LLVM pass 158 checks, including 64 parent/channel/edge-child
combinations, the last SJRB slot, stale links, malformed geometry and queue
bounds, unsupported callbacks and unchanged RAM. Private receipts are under
`build-native-sjuni/adxt-binding/lsc-profile/{gcc,llvm}-v1`. The qualification
pins those receipts and the independent frozen parent fixture.

The diagnostic capture now also copies the three global callback words at
`21DFD8..21DFE3` with a final stability read. It never calls or follows them.
Fifteen isolated capture tests pass. No new game capture was run for these
callback fields.

This is retained integration/research work, not a selected game LSC binding.
The [modernization direction](../NATIVE_MODERNIZATION_DIRECTION.md) now favors
replacing complete media consumers and retiring obsolete PS2/CRI paths rather
than requiring reconstruction of every internal profile.
