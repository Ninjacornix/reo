# Native source runtime factory checkpoint

`sound_ram::install_native_sources` is an explicit alternative to the existing
complete PCM/bank/RAM factory. It creates one device-free ADXT control owner,
retains its render lease in Aggregate3, and uses the existing actual
`RuntimeMemory::prepare` authority for bank/packet capture. The synchronous
CaptureProviderV3 shim forwards the same scoped capture source and result; it
does not mint RAM authority or copy a guest token into a new lifetime.

The source owner is registered before the SDK binding. Stop closes controller
admission without joining. Runtime teardown joins actual source workers before
the device/RAM binding; the root also independently joins sources before RAM
retirement. Guest, I/O and native controller contexts refuse a join before outer
device effects. A failed device fence retains RAM and can be retried. Publication
failure explicitly drains the unpublished composition; an already registered
inert source worker remains owned by Runtime, without an unregister claim.

One actual outer callback remains responsible for polling settings, combining
native streams with banks and applying master gain. Native stream route factors
use the existing opaque RNA UID lookup. The final diagnostic reads the child's
synchronized report and the canonical source owner's fenced output statistics;
it does not misreport the empty legacy PCM bridge as successful native playback.

Both compilers pass 74 native suites with the added outer-join eligibility query.
Both compile the complete factory against audited 130-patch SDK headers. Twelve
protocol scenarios pass on both compilers: actual native workers through the
combined callback, blocked source shutdown, scoped join refusal, retry after a
failed device fence, the existing PCM route, and seven preparation/publication
refusal profiles. The live fixture reports 64 signal frames, zero underruns,
one callback, clean source/device/RAM retirement, and no hard failures.

These factory fixtures use the retained public facade bodies with declared
Runtime, RAM-acquisition and device ports. They do not exercise actual GS/CD RAM
authority acquisition or an audio device. The separate production-header object
checks use real declarations. Earlier RuntimeMemory acquisition/copy evidence
remains separately identified; this checkpoint does not upgrade a model port to
an actual runtime test.

The final factory cohort is V4. Native archive inputs are identical to passing
V2; only two factory fixture files differ, checked explicitly by the verifier.
V1's fixture compile failed because two synthetic audio declarations collided;
V2's blocked-read fixture omitted the required first source-service visit; V3's
added legacy fixture used model IDs outside the production IOP UID domain.
Those failed receipts and exact source snapshots remain retained. V4 corrects
the fixture expectations, without changing V2 production code or native archives.

`tools/native_reconstruction/native_audio_media_factory_qualification.json`
records the source manifests, SDK/compiler identities and receipts. The candidate
preparer includes the complete canonical audio dependency set, sharing resource
view bodies once with the file-payload path.

The existing bootstrap still selects the prior factory. This alternative must
be called by a complete guest adapter before run: original PCM production and
post-source reset remain refused by Aggregate3. Guest source/control/clock/reset
bindings, actual scheduler ordering, movie providers and coherent game/A/V tests
remain Step 3 closure requirements. No game was launched for this checkpoint.
