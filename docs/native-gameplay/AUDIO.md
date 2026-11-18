# Native gameplay audio routing

This is a native gameplay command and descriptor boundary. It uses the existing
`audio_banks::v2::Session` for bank ownership, requests, scheduling and DSP.
It does not install a replacement game runtime, complete Stage4, or establish a
performance diagnosis. No game was launched for this qualification.

## Ownership and integration

`game/native/gameplay_audio/Owner` strongly retains that existing bank session and
borrows the canonical gameplay `Random`. Its sixteen logical descriptor slots
are distinct from the fourteen playable engine ports. Ports14/15 never receive
invented successful installs. The runtime must use this owner for installation
and unloading of its bank ports and preserve the existing canonical gameplay
RNG order. `bound_to(Random&)` checks that binding explicitly.

`begin_bank()` creates an opaque ticket containing a retained owner domain and
slot generation. A later request supersedes earlier work. Capture/prepare take
place outside the metadata gate and use the existing engine's budget admission
before allocating bank buffers. Commit rechecks the ticket under the gate,
installs the actual prepared bank, then publishes its immutable descriptors.
Failed, foreign and superseded installs publish no new metadata. No caller
provider or file read executes under that gate. The independent engine audio
worker can keep mixing while preparation runs.

The pure descriptor import has direct and staged profiles. Direct import reads
the embedded HD/BD/TQ extents and source pitch halfword. Staged import preserves
the original zero pitch: its HD/BD come from the separate named resources, not
from pretending that every embedded direct extent is meaningful. The concrete
`install_parts()` accepts already owned HD/BD/TQ bytes for that producer. The
runtime archive/name request service and its actual scene installer remain
integration work; this module does not report them as installed.

The request path copies no game actor, reads no guest RAM and creates no ADX or
SDR command queue. A concrete native Session consumer applies typed commands.
An absent or pending native bank returns an explicit status; a closed/reset
engine cannot be reported ready solely because metadata still exists. Playback
can still be inaudible or naturally rejected by the engine scheduler; successful
command acceptance is not a claim that a physical device played the cue.

## Source behavior retained

The source families are `1AC7F0/1ACB60` (descriptor routing), `1ACFB0/1AD220`
(descriptor producers), `1B8D40/1B93D0/1B94B0` (positional routing),
`1ACEB0/1ACF60/1B86F0/1B8780` (settings) and actual `1AEC80` (RNG).

- Caller gain and pan are retained and updated across linked descriptors. Pitch
  variation draws sign then magnitude; gain always draws a sign, including a
  zero variation. Start gain `-1` uses the descriptor gain directly; Change
  retains the original unsigned scaling instead. The original high-bit float
  conversion order and signed low-byte parameter presence are preserved.
- Incoming descriptor-call `a2` owner and `t1` pitch are discarded by the actual
  callee. They are not mistaken for the tag. The Start tag is the low byte of
  `t2`, consumed as the existing bank engine's program offset. Change omits it.
- Descriptor byte9 bit0 sets the high group bit, which the actual engine uses
  for group replacement/cancellation policy. It is **not scheduler priority**;
  priority comes from the TQ sequence entry.
- Requested flag0 permits original descriptor processing. Requested flag1 with
  phase other than2 returns `-1`. The concrete native owner additionally refuses
  absent native bank metadata; it does not emulate reads from uninitialized
  global descriptor storage. A producer failure stops the original chain but
  returns0; native `Result.status` reports that failure separately.
- Start terminates a self-link; Change does not. The native bounded repeated-link
  refusal is an explicit repair to potential infinite cycles. None of the103
  admitted authored banks has a multi-row chain or a reachable cycle.

Positional routing takes an explicit listener world position and the canonical
already-composed world-to-logical-screen matrix. The listener is the original
normalized inverse-camera translation, not an assumed raw view translation.
It preserves the100-unit near zone,4800-unit cutoff,300-unit attenuation bands,
the four owned17-entry tables,640-unit pan projection and behind-camera flip.
Near-zone gain0 still admits descriptor processing. Other computed zero gains
reject the cue before RNG. The old temporary PS2 rendering-parameter mutation
is replaced by these explicit native camera inputs. Zero/nonfinite perspective
values, including a subnormal reciprocal producing nonfinite projected X, are
outside the admitted finite profile and return `numeric_domain` before casting.

Settings read the actual borrowed canonical `Options`, apply commands through
`SessionCommands`, and update the actual existing three-channel `StreamChannels`
through `StreamLevelsBinding`. The borrowed stream backend is its existing
decoder/output backend. No second stream owner exists here. Mono mapping is
verified against the production v3 packet consumer (`mode1` means mono), rather
than the stale test-only packet adapter. The source zero-gain gate is distinct
from backend mute: it changes after the mute command succeeds, even if the
following volume command fails. Effects volume still updates stream maxima1/2
when a bank volume command fails. Music uses channel0.

## Qualification and limits

`tools/native_reconstruction/verify_gameplay_audio.py` audits every comment-word
of its complete original generated bodies against the owned File1 executable
SHA256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
Those unchanged bodies execute in test-only surroundings. Full original
`1A7310/1A7430/1A7550` producers independently encode parameter presence and
command arguments; the native expectation is not a mirror of the router.
Queue draining/failure, native-camera input, sqrt/floor, resource loading/cache
operations and low-level settings command/stream output are declared fixture
ports. The final original projection body `191AB0` executes directly.

The paired receipt ledger is
`tools/native_reconstruction/native_gameplay_audio_qualification_v1.json`.
It includes original-word audits, unchanged source closures, compiler identities,
corpus identities and the exact check counts. The native owner also composes
with the real existing bank engine and actual native StreamChannels; device
attenuation remains an explicit fixture seam.

The owned inventory contains104 named SND members.103 have valid bounded control
sections and all their2166 type0 descriptor events are compared through Start
and Change, the real engine request state and exact stereo PCM. The remaining
`adxsnd.afs/test.snd` (SHA256
`cd4b4b0685b9097e02ce8a49ff63bae8787a17702f3083c3b345463fdfcd36ca`)
declares control offset/size0/0. It is explicitly refused, not counted as a
successful bank. The original do-at-least-once importer would underflow the
size-minus16 bound and read bank-header/HD bytes as128 descriptor rows. No stock
consumer reachability or valid control-table interpretation is established for
that file. Likewise a declared control size16 cannot contain the original
unconditional first row: it is an explicit bounded-import refusal, as are sizes
below32. These exceptional assets are separate from the103 positive imports.

The owner race fixture supersedes a request while the existing engine allocator
is paused, then verifies that the older preparation cannot install or publish
metadata. Reset, stale/foreign tickets, unavailable playback, canonical RNG
binding, repeated links and numeric refusals have focused checks. These are
native admission tests, not claims of original behavior on malformed inputs.

Remaining integration includes actual retained runtime bank-resource acquisition,
camera production, actor/surface/resource cue frontends, canonical Options
service installation, and room reload/teardown ordering. A8 modulation/type17
work uses the shared effect owner and is being implemented separately; it must
reuse these actual sound endpoints and canonical RNG rather than a dummy sound
provider or an independent effect pool.
