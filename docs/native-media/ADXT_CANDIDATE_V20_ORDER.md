# V20 missing raw route and bounded source admission

Status: V20 game failure retained; candidate correction qualified on both compilers.
No successful native source playback or confirmed fix is claimed here.

The private session `build-native-sjuni/playtests/adxt-ordinary-v20` runs the
previously linked executable `9fe82de93d40eeed9b81e511d854442fc7d3dc1962558a0511893e9ffe7487d8`.
Its PID is 232060, creation identity `134386012449630146`. It runs for 56.437
seconds, passes the earlier mono-pan guard, displays the Capcom logo and reaches
the character-selection route. At stderr line 2496 it stops with
`active-raw-route-missing` for C4 handle `20F3C8`. The supervisor correctly records
`native-failure` despite process exit zero.

The complete backend reports native-source selection and joined source/output
retirement, 1,666,080 output frames, zero signal frames, zero underrun frames,
zero hard failures and zero queue rejections. These counts demonstrate no source
PCM playback. The movie trace retains 275 records with no drops. The two read-only
samplers retain 79 observations and five broader control observations before the
process exits. They are partial asynchronous evidence, not atomic state or call
counts. Their original receipts and the failed broad-capture receipt are kept.

`PcmOrder::copy` copies the selected aggregate bridge's actual unsorted raw voice
map. A raw voice enters that map through bridge configuration. The ordinary
adapter replaces the decoder/RNA group with private native producers; a pending
native source cannot assume its raw voice is already configured. V20 proves its
expected route was absent, but does not record the full map at that refusal.

The existing [private output contract](ADXT_SHARED_OUTPUT_CONTRACT.md) already
admits one or two source producers without a supplied traversal. Each channel
adds at most two finite source contributions before final clamping. For three or
more sources, float summation order can affect output, and the true traversal is
required. This qualification does not authorize sorting raw IDs or inventing a
larger original map history.

The candidate correction therefore counts current and pending source records,
including ended/retiring records conservatively. If there are at most two,
missing routes may complete the instance permutation. If there are three or
more, every source route must still appear in the actual map; missing idle
instances alone may be appended. This preserves the existing native mixing
profile rather than removing the order guard. Full three-or-more integration
remains an explicit outstanding boundary.

New declared-port cases reproduce an empty raw map with one and two actual
imported native sources, check PCM output and complete per-source payload
digests, and require refusal with three pending sources for both empty and
partially populated raw maps. Counterfactuals restore the overstrict two-source
check and remove the three-source bound. Controlled game retest is still needed
after a matching candidate build. Both compilers now pass all 78 native suites,
21 adapter scenarios, eight detected runtime faults and five actual SDK130 object
compilations. This is not a successful game retest.

The prior V17b original capture contains three nonterminal source states in ten
original-tick groups, including three state-3 sources together. Other groups
include terminal state-5 records alongside two active sources. The bounded
summary preserves those distinctions and makes no invocation-rate or complete
reachability claim. Three-source ordering is therefore required work, not an
optional profile that may be discarded to declare Stage 3 complete.
