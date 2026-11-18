# Native scripted actor construction from scene headers

The actual ScriptedActorConstruction owner now prepares and creates5F0610's
kind2 actors from retained native CutsceneDescriptor headers. Preparation reads
assets outside simulation invocation. Creation uses the existing canonical
fifty-node World pool, model/animation ownership and shared material scheduler.
It supplies real IDs that the Update-owned cutscene track dispatcher can bind.

The eighth actor section supplies its first36-byte header. AFFFF timestamp skips
construction. Kind2 splits the signed halfword at6 by decimal100, separately
narrows quotient/remainder to bytes, and uses the low byte of halfwordA XOR1
for the definition selector. The logical resource group increments only for
these scripted actors, including across skipped or other-family headers.
It then sets the actual scene markerBA6, narrows the scale-profile word14,
overrides all three scales with1 only when that byte is zero, and applies the
word18 mask to the actual model's part visibility. Unused original scratch
visibility bytes have no separate native mutable shadow.

Other header kinds remain absent entries requiring their real player/NPC
owners. The factory reports unavailable if asked to create one. Missing headers,
models and unsupported definitions fail preparation before publishing actors.
Creation also refuses while the World is busy, preventing a voice callback from
allocating into an active actor/track traversal. A caller receives any ordinary
allocation/task failure through the existing constructor result contract.

Owned scene tests exposed seven type0 indices beyond its two-row table group:
10,14,48,49,50,51,52. Original6BA5C0/1D0920 indexing reads initialized adjacent
rows at those exact offsets; the named0950 headers witness their use. The native
profile now admits only those seven exact byte-verified rows in the ordinary
bank. It does not infer that arbitrary adjacent data is a valid model row.
Indices2,11 and53 remain refused. The reproducible generator records each owned
member/hash/group witness and original table address in its admission receipt.
This proves the static data and indexed contract, not live scene reachability.

Both compiler construction cohorts pass2,860,479 checks. The complete
source-word-audited5F0610 body is exercised for65,793 restricted configurations,
including all65,536 signed code encodings and0..16 groups. It observes66,308
constructor requests and exact source scale/profile/mask/marker effects. Its
primary setup calls and6BA5C0 constructor are explicitly declared observation
ports; this is not a comparison of the unported primary/NPC lifecycle. Original
constructor behavior has its own earlier qualification.

Actual native asset preparation and construction cover all548 owned0950 scenes,
all729 scripted actors and all17 scenes exceeding16 total actor groups. They
compare actor identities, definitions, scale, actual part masks and metadata,
then bind all729 selected groups into the real Update track owner. The740
other-family/terminal groups are explicitly left to their distinct owners.
A real track-dispatched voice contract attempts reentrant construction/closure
and verifies refusal without pool mutation. This voice provider is a test port;
no audio device is opened and no real facial playback is claimed. All eight
current parent CTest entries pass on both compilers.

Current World regressions also pass2,633,038 checks/7,556,711 original calls per
compiler, including all548 retained descriptor comparisons. See the sealed
qualification for all exact source/build hashes. The full scenario comparison
passes425,306,821 checks per compiler, with355 ordinary/327 offline bindings.
Its earlier bounds-only definition fixture was updated to recognize only the
seven separately witnessed rows and still compare their literal source bytes;
all other indices keep their existing refusal contract.
Reproduce with verify_cutscene_scripted_construction.py, the pinned descriptor
inventory, explicit compiler/CMake/build/data-root paths and fresh output folders.
generate_cutscene_model_admission.py reproduces the seven admitted rows. Failed
and earlier partial receipts remain preserved.

Native kind0/3 player selection/backup/restoration and reconstruction, kind1 NPC
construction, other descriptor stream consumers, real voice/facial providers,
cinematic lifecycle, installed native gameplay and full Step4 acceptance remain
open. No game was launched and no new performance improvement was measured.
