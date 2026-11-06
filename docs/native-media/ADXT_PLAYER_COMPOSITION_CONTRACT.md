# Single-resource native ADXT player composition

Status: bounded composition contract. This is not full-game, device, movie,
LSC or final-runtime-removal qualification. All initial experiments are offline.

One control owner contains the real async Source2, the corrected keyed decoder,
the phased PCM store, the startup/drain control and one private native PCM
session. Rendering alone may run concurrently. Neither the native PCM session
nor its channel/voice handles escape. A single outer mutex covers a stereo
acceptance and each render callback, so one channel cannot become visible to
the renderer before the other. The inner PCM mutex always follows this mutex;
no provider, source I/O or guest call runs under either output lock.

The first profile has one or two channels, tag0 ADX at24/44.1/48kHz, explicit
neutral mono or hard-left/right stereo routing and zero pitch. Seamless/LSC
replacement and downmix are refused. Configured pan and AINF metadata must
produce the admitted routing; no ignored pitch/pan approximation is allowed.
Source2 supplies the existing finite whole-sector bounded backing profile.
Native loop policy is supported by the decoder; a single looping resource
requires an explicit stop. No automatic end is inferred from loop count.

The playback-R2 Window2 revision retains the actual Source2 friend class and
changes its header/layout. Every translation unit in an executable must select
this R2 header and exactly one v2 owner implementation. Never mix frozen, R1
or R2 class definitions/libraries in one executable. The inherited test source
is an exact copy for local header selection. Decoder/header/source methods are
otherwise mechanically identical to R1 apart from initializing the new PCM
bridge and suppressing codec-only PCM observers for the added silence path.

The new PCM interface remains the Window owner itself. No independent mutable
store alias escapes. Silence is admitted only after the decoder ended and ready
configuration completed. Window reentry/stopped/fault gates remain active.
Phased-store faults fault the containing graph and retain actual credit tokens.
The controller uses the same guarded PCM port as its original-word comparison.

The output queue has8192 samples per channel, copied in64-byte quanta. The
player acquires a real PCM read lease, copies the bounded bytes into fixed
private staging, admits the complete channel batch under the output mutex,
and only then returns the decoder's PCM credit. Any post-effect failure retains
the real lease and faults the graph; there is no fallback. Copied input and
output consumption are separate observations. Core consumed-byte counts may
include deliberately skipped input after an underrun; they do not prove audible
presentation. Statistics, voice skipped/late state and pre-clear observations
remain available.

Service ordering in this native composition is source service, decoder service,
one-time ready/output preparation, bounded output pump, then one playback-state
service. Supplied original tick values do not count service calls or audio
frames. Full original worker scheduling and estimated/pause clock composition
remain separate qualification work.

The supplied provider must implement the existing source-pinned audio-output
Owner contract. Its callback renderer holds only the output PCM owner, with no
reference to Window/player/control state. Synchronous callback during attach
is valid. Transfer-stop completion fences synchronous accepted copies under the
output mutex; it is distinct from callback/provider detach/stop/unload.

Retirement first closes callback admission and joins that actual provider owner
outside every PCM/source lock. A failed detach/stop/unload retains both PCM
queues and decoder admission for retry. After a successful provider join, an
explicit cut returns held decoder credits, drains queued PCM, and stops/joins
the actual encoded source. Natural completion leaves padding; manual stop cuts
remaining audio. No drain-to-device claim is inferred. Separate joined flags
identify the provider and the actual file worker.

The renderer retains the callback slot. A published slot retains the existing
audio Owner, which retains the renderer. A failed emergency provider join thus
retains the callback graph rather than freeing registered callback storage.
Successful ordinary join breaks that retention. Explicit retirement/retry is
required for reclamation; destruction does not report a failed fence as joined.

The offline model provider executes callbacks and implements detach under the
same mutex as dispatch, with explicit retry failures. It opens no audio device
and cannot qualify a production provider by returning the source-hash constant.
Actual asset prefix-digest comparison proves copied PCM against the separately
qualified native decoder, not original whole-player scheduling or audible PCM
parity. A buffered deterministic test consumer is not a performance benchmark.
