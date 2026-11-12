# Native script scenario audio

Status: implemented native component, not installed in the game. Stage 4 is
incomplete. No game or audio device was started for these checks.

`ScriptAudio` reconstructs script command `0x73` (`68F640`) and its scenario
sound frontend `1B8930`. It borrows the canonical World, native audio bank Owner
and camera SpatialContext. Scenario identity, the remembered sound and random
state remain in the existing Session. It uses the existing scenario cue tables,
bank 2, native request routing, positional attenuation and bank mixer.

The command preserves the original modes:

| Mode | Behavior |
|---|---|
| 0 | Play the remapped cue without a position. |
| 1 | Use the selected primary actor's current position; selector 4 resolves the canonical selected actor, selectors 0–3 name that slot directly. |
| 2 | Convert three signed 32-bit coordinates independently to float and use that position. |
| Other full-word values | No sound request and no remembered-cue update. |

Mapped cue 255 makes no request and preserves the previous remembered cue.
Every other mapped cue writes its low halfword after requesting sound, including
requests ignored for distance, pending loading, unavailable banks or invalid
event numbers in an otherwise admitted bank. Those actual native outcomes remain
available through `last_result`; they do not fabricate audible playback or rewind
script progress. The existing `1B8870` profile rejects events outside the 208-entry
tables for the five mapped scenarios. Other scenario values preserve the full
32-bit incoming event before bank routing.

The interpreter imports mode-specific payload extents: at least 8 bytes,
12 for actor positions, and 20 for explicit coordinates. Whole-program admission
checks every sound request against the concrete audio owner and World before any
instruction mutates state. Missing or foreign owners, unavailable scenario
identity, out-of-profile remap events and absent primary slots remain explicit
provider failures. An unknown-mode-only program needs no audio owner. Offline
dispatch retains its original category/relation filters.

## Independent source comparison

`verify_gameplay_audio.py --script-frontends` freezes production/test sources,
audits the original function words against the owned executable and overlay, and
executes complete original `68F640`, `1B8930`, `1B8870`, the positional/nonpositional
wrappers and lower bank request bodies. Only the existing declared command/SDK
boundaries are ports. Captured original bank commands feed a separate real native
bank Session. Tests compare request state, RNG, remembered cue and mixed samples
with the production frontend and its real bank Session.

The paired LLVM/GCC `script-scenario-audio-*-v2` cohorts each pass:

- 516,085 checks and 19,982 complete command cases;
- all 208 events in each of the five scenario tables plus identity-scenario cases;
- all five actor selectors, all four selected slots, positioned distance cases,
  signed coordinate limits and values crossing exact float integer precision;
- unknown modes including high-bit and all-ones values;
- 4,150 emitted commands and 639,424 mixed frames, with 24,896 nonzero samples;
- pending/unavailable banks and ten native owner/content/lifetime refusals;
- 143,819 original boundary invocations.

The first draft test retained the source bank's loaded phase while asking the
native bank to enter pending loading. That fixture mismatch failed the RNG check;
the corrected fixture supplies the actual pending phase. The failed `llvm-v1`
receipt remains available. No production behavior was changed to match the
incorrect fixture.

The full ordinary/offline interpreter comparison passes 492,589,059 checks per
compiler, including 9,072 script-audio dispatches. These compare actual bank
requests, remembered cues, random state and 290,304 mixed frames through the
declared frontend port. Twelve current-source CMake parent tests pass on each
compiler, including actual constructor/pool lifetimes, archive/script import,
World, actor assets, collision, cooperation and AI ownership.

The complete audio and interpreter receipts retain their exact immutable
source snapshots. Later full-clear history adoption and the explicit scripted
actor head-point zero default are recorded separately by the seal and current
parent regressions; the old snapshots are not relabelled as newer source.

## Remaining integration

The full interpreter comparison is a separate composition check: its explicitly
declared `1B8930` port composes the already qualified native audio frontend with
the original dispatcher, while the independent comparison above executes that
complete original body. Neither test proves actual scenario bank assignment,
camera publication, device listening or a complete native session. A production
session still must bind the real audio Owner, bank assets and camera context and
pass controlled gameplay acceptance before Stage 4 can close.
