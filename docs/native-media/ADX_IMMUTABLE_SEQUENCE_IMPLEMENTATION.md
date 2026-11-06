# Prepared seamless audio sequences

The private native player now admits a prepared sequence of two to sixteen
immutable sector-backed audio views. Preparation checks each actual header,
output format, end record, real trailing bytes and cumulative counter bounds.
It retains the views and freezes their offsets without copying audio payloads,
reopening paths or constructing padding. Arbitrary seamless views and mismatched
prepared-view identities remain refused. This is a bounded known-sequence path;
live LSC insertion/replacement remains separate work.

Across **421 sequences**, both compilers copy all **6,706 distinct finite audio
payloads** from the verified installed File1 import. Every complete clip's
accepted PCM count and hash matches the earlier finite decoder baseline:
**1,198,405,644 channel samples /2,396,811,288 PCM bytes**. Complete clip rows
and group observations match across compilers. Session service counts differ
and remain recorded separately. No ISO or real audio device was opened.

Source polling remains explicit. Before a clip transition, the decoder waits
until the actual published source counter covers the entire next header. It
then executes the existing owned seamless search, selective reset and header
parse against the actual shared ring. A controlled blocked-provider case proves
that an unfinished read does not clear seamless mode or end playback early.
The same output producer remains active through the clips. Raw clocks include
the decoder's real seamless-sample accumulation; terminal time equals the full
prepared sample total. Evidence-prefix accounting uses the full sequence limit
so a shorter later clip cannot cause unsigned subtraction underflow.

The independent preparation suite passes **922 checks** per compiler. The actual
control-owner matrix includes eighteen three-clip profiles spanning mono/stereo,
24/44.1/48kHz, partial ADPCM blocks and shorter subsequent clips. Separate
negative controls detect removal of the next-header wait, accumulated clock
offset, sequence-wide prefix limit and exact prepared-view identity. The identity
case uses a different valid prepared view with the same size and content, so a
mere range-size failure cannot satisfy it.

The original finite and regular-loop corpora also pass again with both compilers:
8,910 references /6,706 finite payloads and 89 references /80 looping payloads.
All complete payload observations match their prior baselines. One finite
case has differing copied/consumed padding observations across compilers; these
declared post-payload fields are retained, not presented as equal waveforms or
performance evidence. The sixty-operation canonical serviced-clock comparison
and existing player/control negative controls pass again. All **52 standalone
native suites** pass in both complete Release builds.

Thirteen inherited player bodies remain identical to the earlier clocked player.
Two explicit native additions are reviewed separately: clock observation reads
the actual seamless accumulation, and the copied-prefix bound selects the
prepared sequence total. Their legacy finite/loop domains normalize to the old
bodies, while the new actual-asset and negative checks cover the additions.
The qualified decoder, codec, original clock arithmetic and source credit rules
were not changed for this profile.

The [qualification](../../game/native/adx_sequence/qualification.json) pins the
source manifest, derived-observer identity, full native/negative transcripts,
ancestor source snapshot, parent checks and regression receipts. Principal
receipts:

| Evidence | SHA-256 |
| --- | --- |
| Full imported sequences GCC | `d64f481d8d02721c63f897165c90bb8f57812b0600fa0296cc2e51f399db9b01` |
| Full imported sequences LLVM | `072ea38f1cba3b34bbb32b9627e71fb0639de4c4bae612e2288d10a4b1fff25b` |
| Sequence comparison | `945010db5d7a60f6a189acafe93bc13a85f78581691e802b0d2adee7d65523ab` |
| Preparation/owner negatives GCC | `3570d210823de185f88188891bfce6f487387954f2b760d158256c9bea534a91` |
| Preparation/owner negatives LLVM | `37199d31be26a2ae533d073c37a39593b57d2c8724c43183a7633eb2f3750811` |

The accepted-copy observer exists only in derived verification sources. Model
rendering and native decoder baseline agreement do not establish actual audible
playback, complete original scheduler parity or a speed improvement. Dynamic
LSC source ownership, shared bank/packet output, movie consumers, game adapters
and controlled media transitions remain stage 3 requirements. Gameplay,
graphics/platform reconstruction and final runtime removal remain stages 4–6.
No player executable was changed or launched by these checks.
