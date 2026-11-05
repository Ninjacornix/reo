# Picture-position publication prototype

Independent bounded integer implementation of the File1 `16F338` publication
slice, including the arithmetic intent of `15BA80` and the two real inner-field
getters. It owns no game clock, decoder, playback thread, source view or guest
memory. It is not connected to the game or included in the parent native suites.

The implementation is frozen before viewing expected results from the separate
original-word investigation. Synthetic unit checks are not original-code parity.
The independent original-word corpus and cross-compiler comparison remain open.

Inputs are value snapshots; adapters must separately qualify descriptor/source
aliasing, indexing into the rate table, ownership and interleaving. The API accepts
the selected table value, not a guest address or a fabricated clock callback.
It preserves the source's wrapped 32-bit arithmetic, signed rational conversion,
zero-divisor saturation and signed conditional latest-position update. The final
value records the observed low `v0` result without asserting a caller contract.

This is a position publication helper, not native movie playback or a stutter fix.
