# Native transfer group scheduling contract

This extends the original-qualified audio dispatch envelope through all32 DTR
and8 DTX slot visits. It reconstructs dispatch and owned membership; individual
DMA/RPC/credit operations remain separate child contracts. It must not count
scans as audio frames, game updates or device completion.

Original `1389D8` visits32 independent DTR slots in ascending order, admitting
only signed active byte1, then tail-calls the8-slot DTX group at `139568`.
The latter enters/leaves chunk tag1 around its live ascending8-slot traversal.
The facade `141268` invokes the same DTX group again. Consequently one complete
outer audio group services DTR32 once and DTX8 twice, after RNA16 service and
RNA guard leave, while outer CRI service phase3 remains published.

The same native DTX owner is retained by DTR and supplied to the outer group's
DTX boundary. No duplicate DTX state or second device clock exists. Strong local
child references survive current-slot removal; later-slot replacement and
activity changes are observed live. Changes to earlier DTX slots in the first
scan are visible in the second. DTX changes to DTR slots wait until the next
DTR traversal. Traversal performs no allocation, source join or device callback.

The original RNA guard is a plain nesting counter, not itself a mutex. CRI,
RNA and chunk guard boundaries are separate native ports; their model depths
prove ordering only. One externally serialized control owner governs all five
slot tables and shared clock state. Guards themselves cannot call user code.
Individual child errors/pending state belong to their retained owners and do
not invent an early exit from the original void dispatch sequence.

This envelope does not implement original DMA/SJRMT/IOP or enable a replacement
in the game. Native PCM copying may replace hardware transport only after its
publication and source-credit binding is qualified for the actual consumers.
The existing native synchronous stereo-copy fence is useful evidence for that
future binding, not proof that opaque per-slot protocols have disappeared.
