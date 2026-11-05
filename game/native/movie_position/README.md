# Picture-position publication prototype

Independent bounded integer implementation of the File1 `16F338` publication
slice, including the arithmetic intent of `15BA80` and the two real inner-field
getters. It owns no game clock, decoder, playback thread, source view or guest
memory. It is not connected to the game.

The implementation was frozen before viewing expected results from the separate
[original-word investigation](../../../docs/native-media/MOVIE_POSITION_ORACLE.md).
GCC and LLVM each pass 18 synthetic checks and match all 25 original publisher
cases / 175 numerical fields. Real getters, ratio scaling and the complete
421-word quotient helper execute in the original oracle; no numerical helper
return is fabricated. Its additional 30 helper cases and partial instruction
coverage are recorded separately, not counted as native publisher API tests.

Core/header SHA-256 at the independent freeze:
`4ba067d7c2a7e0e84c2372470d40d815b3dfb57d0dc23dd5fb15bb7ec006fb3f` /
`fa00728b7c6ff9fe294327f0ba667e4d931b04b7984fbeafb76a16daf1256062`.
Original fixture: `232d07ee2991cb07f25bc65247db597aa2a85f6080ef8d1bff47c45b5fa94822`.
Private comparison receipts: `build-native-sjuni/movie-position-native-compare/{gcc,llvm}`.
Run `compare_original.py --cxx <existing compiler> --output <private folder>`.
This comparison checks four descriptor fields, the retained latest pair and
observed final low-v0 bits. It does not reconstruct original stack/ABI memory
or prove intermediate-store, alias or scheduling equivalence for an adapter.

Inputs are value snapshots; adapters must separately qualify descriptor/source
aliasing, indexing into the rate table, ownership and interleaving. The API accepts
the selected table value, not a guest address or a fabricated clock callback.
It preserves the source's wrapped 32-bit arithmetic, signed rational conversion,
zero-divisor saturation and signed conditional latest-position update. The final
value records the observed low `v0` result without asserting a caller contract.

This is a position publication helper, not native movie playback or a stutter fix.
