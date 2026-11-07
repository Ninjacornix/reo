# Shared stream/bank/packet output evidence

The optional tail now composes the existing native stream output owner with the
unchanged qualified budgeted bank session and grouped packet adapter. A single
provider callback renders stream PCM, adds bank/sequence sound, obtains master
gain, then clamps. The PCM core's earlier clamp remains in place. All 224 bank
gain reads preserve their original port/request traversal. The tail opens no
device and never replaces the per-stream decoder/source owners.

The bank session is private. The direct profile provides native preparation,
installation and command operations; the packet profile uses the retained
`bank_packets::v3::PacketAdapter` and its existing prefix transaction lock for
both commands and rendering. Direct mutation refuses in the packet profile.
The adapter's location under `recomp/overrides` is retained; it is still a
migration dependency, not a removed compatibility boundary. This standalone
composition includes no PS2 execution, register context or runtime headers.

Both compilers pass 298 deterministic composition assertions, including exact
float32 output against separately driven qualified PCM/bank cores, gain-read
order, only-bank rendering after both PCM producers retire, duplicate-tail
refusal, foreign capture identity, grouped bank/packet submission, gain errors,
blocked callback retirement, provider-fence failure/retry, and packet-lease drain.
No bank asset allocation or free occurs in the tested render path.

An additional actual-owner test runs a blocked live LSC read and a real decoded
peer player alongside a loaded bank. The peer's actual PCM consumption and bank
clock continue through the same callback. Retiring the blocked source remains
pending until its real worker is released; it does not stop the bank or peer.
After both sources retire, bank-only rendering continues. Whole-output join
clears the bank asset budget and fences/unloads the provider once.

Five detected counterfactuals cover master gain before bank addition, omitted bank
mixing, bank reset during individual stream retirement, bank join before the
provider fence and duplicate tail binding. Failures after PCM consumption are
explicit: the buffer is silenced and the owner stops admitting output. Neither
PCM nor bank progress is reported as rolled back.

The pre-composition contract remains frozen with its original status text in
the source manifest. Exact compiler, source, executable, test and regression
identities are retained in `qualification.json`; ancestor qualifications remain
available under `build-native-sjuni/audio-mix-tail/ancestor-v1`.

This evidence uses synthetic bank fixtures and explicit model-provider callbacks.
It is not a real audio-device run, original full-game parity, a packet capture
factory qualification or a measured performance improvement. The gain providers'
purity/lifetime obligations require separate verification in the eventual game
binding. Movie controls/source/frame lifetimes, broader LSC recovery profiles,
original global scheduler parity, coherent game ABI integration and actual media
transitions still gate stage 3. Stages 4–6 remain open.
