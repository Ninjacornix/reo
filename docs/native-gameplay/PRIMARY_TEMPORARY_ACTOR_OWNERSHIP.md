# Cinematic temporary actor ownership audit

Static File1 audit. Fourteen complete actor/object initialization, assignment,
traversal and exit bodies match the owned o2/o0 words. Evidence is
`build-native-sjuni/cutscene-primary-lifetime-audit-v2/receipt.json`; this is static
evidence, not a game recording or a completed native implementation.

Observed boundaries:

| Source | Observed ownership/behavior |
| --- | --- |
| 5F1290 | Clears scratch space, publishes a separate temporary actor base from the resource workspace, clears eight10E0-byte actor records and assigns indices0..7. Calls571010 after those eight records. |
| 5F1330 | Searches that temporary base for an inactive record. Returns the first free slot without marking it active; null base/full returns null. |
| 5F1400 | May copy an entire canonical roster actor into the temporary record, preserving the temporary slot index. Then applies active/visibility/action/BB4/character/class stores and clears the authored control region. The copy includes original model pointers. |
| 5F0DC0 | Assigns primary/fallback groups using reservation and roster state. Header6 alone does not determine every selected actor. |
| 5ECAE0 /5ECB80 /5ECBE0 | Traverse the separate temporary set and linked actors under their respective activity/visibility gates. The first pass calls61A6A0 then the already studied66A2E0 callback. |
| o0 375550 | Traverses the supplemental temporary set under pause and another gate. It supplements the ordinary traversal. |
| 571010 /571080 | Separately initialize/service sixteen11A0-byte category10 model-work records. Initialization requires pause!=0. These are not eight ordinary primary actors or the128 room-scene model slots. |
| 5ED770 | Releases selected descriptor-bound model rows, performs shared cleanup, restores scene identity and clears temporary-base pointers. Full transfer/reconstruction ownership still needs replay. |

The existing canonical `World::primary` roster must not be treated as that
temporary pool. Current primary initialization/model-cache adapters validate
canonical roster identity; controlled scene-header tests explicitly do not prove
assignment into the temporary set. A separate native temporary owner must retain
generation-checked EntityIds while preserving the ordinary roster's identity.

An additional model-lifetime question remains: original main and temporary
records can refer to physical model-work slots, while5F1400 copies model pointers
and5F0C00 subsequently retires main resources. Native code must not reproduce a
raw actor-memory copy or silently share a mutable Instance/Playback across retired
entity generations. The precise cache/pose handoff and restoration semantics must
be compared across complete entry/exit sequences before choosing native transfer
or clone behavior. Static pointer-copy observation alone does not prove that a
new native actor may reuse another actor's mutable model.

One relevant distinction is already established by the full initializer evidence:
fresh66A750 explicitly writes the actor's model pointer at66A7CC from its logical
slot (`4AE330 + 1468 * slot`). The restore branch bypasses that store. A copied
model pointer is therefore transient in normal fresh initialization; it is not
proof that the source continues using the copied main actor's model. The eight
physical work slots still need an explicit native ownership/pose handoff across
the distinct actor identities and the complete entry/exit selector conditions.

Next implementation work is the separate eight-slot temporary owner and sixteen
object-work owner, typed actor/control cloning with explicit model/channel rules,
complete0/3 header assignment and its reservation-list policy, temporary traversal,
then entry/exit reconstruction through the existing bank/cache owners. Each must
use actual model/clip inputs and preserve explicit full/unsupported results.
Primary sparse cinematic motion/retargeting and category10 object timelines are
also separate consumers; enabling the linked-only scripted path for every actor
would not establish their behavior.

The complete phase still requires actual scene/content ownership, native input/
audio/network/save consumers and coherent game acceptance. No new slowdown cause,
performance improvement or Step4 completion is inferred from this audit.
