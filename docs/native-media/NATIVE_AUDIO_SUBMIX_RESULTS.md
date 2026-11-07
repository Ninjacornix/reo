# Native streams through the complete output callback

Current extension: cold wire reset is now admitted before the first native
producer is published. A read-only, mutex-protected source-epoch observation
latches permanently at publication; source retirement never reopens startup
admission. The serialized game controller may reset the existing raw-ID bridge
while no migrated source exists. Post-source reset remains an explicit refusal.
The startup test checks actual bridge reset and retained bank state, then starts
real native sources and checks that a later reset refuses before effects.
All 72 suites and the 14 aggregate scenarios pass with both compilers for
`native_audio_submix_manifest_v3.json`. Null-profile replay still produces the
same 21 original-input cases and 14 declared terminal differences. Exact new
receipts extend `native_audio_submix_qualification.json`; the initial evidence
below remains the earlier V2 cohort.

The device-free native submix and aggregate-three composition pass isolated
checks with GCC and LLVM. All 72 standalone native suites pass in fresh V2
builds. Four instance workflows exercise actual mono/stereo source workers,
stable handles, replacement, private stop/join and continued peer rendering;
four deliberately broken ownership variants are detected by each compiler.

The new aggregate retains its parent's one actual model provider/callback and
grouped bank/RAM capability route. Two real native source workers feed that
callback through the private submix. Checks observe PCM consumption in both
players, continued peer consumption after individual stop, private join while
the outer bank callback remains active, and exactly one provider attachment,
detachment, stop and unload. Callback allocation/free counters remain zero.
Banks advance once per callback, including after the private streams have
joined. The private join never claims that the outer provider has joined.

The initial native-stream profile explicitly refuses original PCM queue
publication, playing-voice configuration and PCM reset before their effects. It cannot
arbitrarily add two independently clipped PCM voice domains while preserving
the original mixing order. A game binding must migrate the actual stream
consumers and implement their reset/control behavior before enabling this
profile. These explicit unsupported operations are remaining work, not covered
consumers or successful silent fallbacks.

With no native submix supplied, replay of the 21 frozen original-input cases
produces exactly the qualified parent's observations: 287 actions, 9,316 float
words and 10,052 ordered hooks. All 14 previously declared terminal-policy
differences from the original reference remain raw and unchanged. No expected
observation is normalized. The native-stream extension has ownership/model
evidence; this null-profile comparison does not establish original ADXT game
ABI parity or new waveform equivalence.

Both compilers also compile the actual aggregate object against the audited
129-patch SDK headers. The callback fixtures use the retained 126 facade mock
surroundings, whose public capability headers match the actual current headers;
they do not execute the full 129-patch runtime, a real capture factory or a real
audio device. V14's timed game test contains the older complete backend, not
these newly composed source owners.

Two initial fixture failures are retained. LLVM's first native build failed a
clock-player startup assertion under concurrent compilation: its model device
advanced while a peer's real source worker was still starting, so a common
playing state was scheduling-sensitive. V2 coordinates both starts before
model rendering and uses bounded wall-clock waits; production DSP is unchanged.
The first combined-aggregate fixture read a final, fenced report as live bank
state. V2 uses the existing live read-only bank observation until final join,
then verifies the actual fenced report. Assertions were not replaced with
invented report values.

An incremental draft check briefly rebuilt three archives in a historical
two-slot build folder. Its modified outputs were retained separately, and all
recorded archive bytes were restored from independently hash-identical prior
copies. Every library hash again matches the original receipt. The repair
record is `build-native-sjuni/submix/draft-incremental-v1/repair.json`. Later
submix qualification uses separate fresh folders only.

Exact sources, compiler identities and all receipts are recorded in
`tools/native_reconstruction/native_audio_submix_qualification.json` and
`recomp/overrides/native_audio/v3/identity.json`. The successful aggregate
receipts below `build-native-sjuni` are:

| Receipt | SHA-256 |
| --- | --- |
| `native-audio-aggregate-v3/qualified-llvm-v2/receipt.json` | `764a7d434c5e604f3fc051b072d19b9b0b089a19eab9a39ea94aed1bea92018a` |
| `native-audio-aggregate-v3/qualified-gcc-v2/receipt.json` | `954fcd03846b50b2eb6e93d2d291a9084f4803b5b991c64837ead09c4dfaa276` |

Game source/control binding, remaining PCM/reset consumers, correct gain/mix
ordering, real callback handshakes, native stream statistics and audible A/V
validation remain stage-three gates. The aggregate's old PCM counters describe
its raw-ID bridge; they must not be presented as the new native streams' counters.
Those come from the canonical native control/output owner. No player default,
game speed, rendering or VU selection changes with these isolated APIs.
