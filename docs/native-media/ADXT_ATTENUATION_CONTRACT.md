# ADXT attenuation to raw output volume

The original ADXT output-volume setter stores the low signed halfword of its
argument at C4 offset 40. It queries AINF metadata, adds the signed metadata
halfword if the declared presence is positive and decoder state is 2 or 3,
then clamps the sum to decimal [-999,0] in the RNA setter. The actual original
type-5 command producer selects one of 1,000 owned integer table words at
`220498 - 4*attenuation`. It does not compute a floating point gain or change
sample frequency. Physical decibel units are not established by this boundary.

The native `adxt_attenuation::Table` copies an explicitly provided immutable
table during preparation. It admits exactly 1,000 monotonically nonincreasing
words, first 256 and last zero. The adapter remains responsible for the exact
edition/source hash; accepting this native shape does not attest to retail
identity. Control calls allocate nothing and return the stored requested
halfword, clamped RNA attenuation and raw output-volume word. No game pointer,
worker, callback, RPC receiver, scheduler tick or audio device is involved.

The raw volume belongs in the output session's integer volume control, preserving
`min(volume,256)/256.0f/32768.0f * host_gain`. Converting this table into a second
float gain or approximating its curve can change rounding and values. This
module does not replace the game setter's null-handle diagnostic or publish
guest state/remote commands.

Original comparisons execute all owned words in 1327B8/132820, 12D8F8, the two
inner metadata getters, 12C7F8, 13F038 and the complete 13E000 type-5 producer.
Prepared RNA groups keep other command pairs unchanged. Only the null diagnostic
is an observational port; no hook supplies an attenuation, table result or
command. The actual command type is a halfword; its adjacent padding remains
unchanged and is retained in original observations. Native typed results are
compared to stored request, clamped RNA state and the actual command payload.
This is not a DMA/RPC receiver or original hardware playback comparison.

All 1,870 original cases and 507,764 instructions replay before native core
authoring. Native comparison covers the 1,856 non-null cases, including all
1,000 table indices, request truncation, metadata signs/presence, decoder states
and all 16 RNA slots. The 14 original null diagnostic cases remain retained
outside the native typed-handle profile. Injected faults must detect dropping
the request halfword conversion, ignoring AINF readiness, and replacing the
owned table with a linear approximation.

This corrects the semantic interpretation of the older native window field
named `pitch`: it carries this attenuation contribution. The current player
refuses nonzero values there; it has not applied them as a sample-rate change.
Live native player/game binding must apply the correct raw volume before
allowing output, including metadata readiness, later fades and replacement
latches. That integration remains required before admitting those game callers.
