# Complete SDK-facing sound adapter applicability review

Static review, 2026-11-05. CVX pin `657b0c0c9489943116c71f151804ad7304fca975`; owned Outbreak File #1 US ELF SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. **57/57 actual implemented reference definitions** are individually dispositioned:55 in `sdc.c` and2 in `sdcwrap.c`. These SDK-facing sound utilities are explicitly included in the shared-purpose screen. Their file names or inclusion in a game are not grounds for exclusion.

All57 have scoped **no-demonstrated-counterpart** findings after reading every available complete source body and comparing the concrete Outbreak transfer, request, gain, pan, status, stop and ramp contracts. This means no same whole adapter/owner was established in the inspected candidates; it does not claim the binary lacks equivalent arithmetic or the same broad audio features. There are no invented sd/MIDI/shot aliases, new annotation rows or mapping credit.

## Evidence and reproduction

The [offline helper](../../tools/function_index/review_recvx_sound_adapter_complete_scope.py) regenerates `build-function-index/recvx-sound-adapter-complete-scope.json` using the pinned source copy and shared complete-source manifest. Run `python tools/function_index/review_recvx_sound_adapter_complete_scope.py`; optional `--reference`/`--output` change source-copy/private-output locations. It verifies raw file hashes, all57 exact definition identities/bounds/body hashes and22 complete owned candidate intervals, retaining SDK calls, source signatures, exact global-state witness lines, authoritative annotation rows and source-project progress comments.

Owned comparison evidence totals **1,127 verified original instruction-comment words**, zero conflicts and53 omitted words independently verified zero. Original instructions and complete return/delay-slot paths for the central SDR initialization/transfer callback, effect gain, request/change queue and ADXT ramp candidates were read directly; remaining neighboring wrappers use their existing complete-body reviews plus fresh owned-byte audits. No game, target instructions, emulation, audio/device/RPC call, build, process attachment, live memory or input was used. Shared review/index/annotations, original inputs and native/runtime code were not changed.

The reference supplies complete C implementations, but some progress comments report less than100% byte matching (including86.67% pan requests and87.69% fade requests). Those comments are preserved as source provenance, not independently reproduced CVX parity. A complete source-body disposition is distinct from proof that all reference retail instruction details are recovered.

| Reference file | Definitions | Raw SHA-256 |
| --- | ---: | --- |
| `src/ps2/veronica/prog/sdc.c` | 55 | `7491247a010e5708ce96efe8723ee3aa6d3199c4624000310217a71969ceca3f` |
| `src/ps2/veronica/prog/sdcwrap.c` | 2 | `74eaa6a277aca49c8ab5e32e2495511aca0469e92fbfb8c7290683cd83d8a975` |

## Material ownership and arithmetic boundaries

CVX owns8 MIDI and20 shot handles, each with a48-byte `SDS_INFO` record: registration flag0, fade mode4/count8/current volumeC/speed10/target14/limit18, pan mode1C/count20/current24/speed28/target2C. Calls operate on `sdMidi*`/`sdShot*` ports and shared `SDS_MEMBLK` downloads. None of these port counts, record offsets, enum values or memory-block lifetimes is transferred to Outbreak.

Outbreak's inspected sound-effects layer instead enqueues32 twelve-byte SDR command records, with packed identity/parameter-presence flags and asynchronous RPC conversion. Its stream layer has **three**24-byte control records and CRI ADXT handles. These represent separate effect and streamed-audio owners, so matching a CVX shot slot to a request-queue slot or an ADXT channel would be unjustified. See [resident SDR requests](../SYMBOLS_ANIMATION_SOUND.md), [bank installation](../SYMBOLS_SOUND_BANK_INSTALL_AND_SYNC.md), [stream controls](../SYMBOLS_STREAM_CHANNELS.md) and [PS2RNA controls](../SYMBOLS_PS2RNA_AUDIO_CONTROLS_AND_UNSUPPORTED_API.md).

Transfer completion differs concretely: CVX `TransWaitCallBackFunction` destroys the shared memory block and clears a flag; Outbreak1A7FA0 merely signals the supplied semaphore. CVX `CheckTransComplete` reads the flag, while1A7F50 acquires/polls and re-signals a semaphore. Outbreak1AC730 also performs bank conversion, command/RPC completion polling and vertical-event synchronization; it is not CVX `SetSoundData`'s `sdBankDownload` memory-block facade. Neither observation implies audible playback completion.

Gain and pan units are not interchangeable. CVX passes float-converted char controls plus short delay parameters through its ports. Outbreak effects use signed-byte parameter-presence gates and packed SDR gain/pan/pitch fields; ADXT levels are maximum-scaled and gain-table quantized; lower PS2RNA stores attenuation clamped-999..0 and pan clamped-15..15. No full matching default-volume, stereo/GDDA pan, persistent mode or effect-program set/clear wrapper was shown by the inspected bodies. Numeric SDR control operations remain opaque where their provider behavior is not demonstrated.

CVX fade requests store a counter and `(current-target)/counter`; timer-based requests use the literal `((Timer/100)*30 + ((Timer%100)*6)/10)/2` conversion and fix exact-zero counts to1. Explicit Frame0 requests retain the previous speed rather than recomputing it. The manager subtracts speed, predecrements the counter and snaps only when it becomes **negative**; int-converted volume-127 stops a port. Outbreak1AE3F0 always divides by its supplied duration, caps target above its channel maximum and stores a float step. Its1AE4B0 worker completes by quantized target crossing without CVX's fade counter or-127 stop sentinel. No reference timer unit is converted into wall-clock seconds, FPS or original game updates.

Two easily missed literal source details are preserved: `ExPlayMidi` resets volume from **SdcSeDefaultVolume**, and `SetPanMidi2` admits updates when registered AND `(PanFunc!=0 OR FadeFunc!=2)`. The shot pan setter has no such extra condition. `CheckFadeEndSe` returns1 while a fade is pending and0 when its mode is clear. These are source contracts, not Outbreak bugs or invitations to copy state fields.

## Every reference definition

All rows below retain a precise searched boundary; no row is admitted by shared naming alone. Families contain6 transfer/lifecycle,3 mode,4 volume configuration,15 MIDI,14 shot,2 effect-program,8 fade,3 pan-ramp and2 bootstrap definitions.

### sdc.c

| Reference function / lines | Family | Complete-body comparison and remaining boundary |
| --- | --- | --- |
| `TransWaitCallBackFunction` 21..26 | driver-transfer-lifecycle | Destroys global SdMemBlk and clears TransCompleteFlag; Outbreak RPC completion1A7FA0 signals a supplied semaphore only. No same shared memory-block lifetime/flag callback. |
| `CheckTransComplete` 29..32 | driver-transfer-lifecycle | Returns global TransCompleteFlag directly. Outbreak1A7F50 polls/waits then restores a semaphore and returns0/1; it is not this plain flag accessor or proof of payload/audio completion. |
| `SetupSoundDriver` 35..58 | driver-transfer-lifecycle | sdLibInit, create/set driver memory block using prior callback, sdDrvInit, destroy block, DMA transfer mode, install callback and slot maxima36/20/8. Outbreak initializes two SDR RPC clients/queue/semaphores and separate named-bank state; no same sd library/memory-block/port setup. |
| `ExitSoundDriver` 61..68 | driver-transfer-lifecycle | Stops tracked FX, sdSndStopAll and sdSysFinish. No matching complete sd MIDI/shot port shutdown facade established in SDR/CRI owners. |
| `SetMultiUnit` 71..82 | driver-transfer-lifecycle | Creates block, sets transfer flag, configures callback-1, downloads multi-unit and destroys block. Outbreak three-span bank-transfer admission/packing has different metadata, callback and ownership protocol. |
| `SetSoundData` 85..94 | driver-transfer-lifecycle | Creates shared block, sets flag, binds caller payload and current callback, invokes sdBankDownload(DataType,BankNo); no local destroy, leaving callback lifetime. Outbreak1AC730/1A7900 use converted bank sections and RPC/queue acknowledgement; not the same complete transfer API. |
| `SetSoundModeEx` 97..118 | sound-mode-configuration | Mode0 selects stereo and GDDA pan127/-127; other modes mono and0/0; caches original mode and optionally calls syCfgSetSoundMode. No identical SDR/CRI mode field, port-pan law or persistence wrapper demonstrated. |
| `SetSoundMode` 121..124 | sound-mode-configuration | Calls SetSoundModeEx with persistence flag1. No Outbreak full stereo/GDDA/cache/config wrapper pair established from generic control RPC. |
| `GetSoundMode` 127..139 | sound-mode-configuration | Lazy caches syCfgGetSoundMode only while local cache-1. Outbreak inspected audio initialization/control has no demonstrated matching lazy OSD-cache owner; no cross-game cache-field identity. |
| `SetMasterVolume` 142..147 | volume-configuration | sdSndSetMasterVol(charVolume) then caches byte. Outbreak1ACEB0 uses zero-gain gate and queued slot/global SDR commands; CRI attenuation13F038 clamps-999..0. No identical complete master-volume facade or units. |
| `SetGdDaVolume` 150..153 | volume-configuration | Stores byte SdcGdDaVolume only, without SDK call. No connected Outbreak GDDA field/consumer identified; a generic byte store is insufficient identity. |
| `InitMidiInfo` 156..178 | midi-port-adapters | Visits8 SDS_INFO slots; first initialization clears flags, later initialization frees registered ports; zeros volume/limit/fade/pan modes. Outbreak SDR request queue and three ADXT records have different storage/lifetime. |
| `RegistMidiSlot` 181..193 | midi-port-adapters | Already registered returns1; otherwise sdMidiOpenPort into MidiHandle[slot], sets flag1, returns0, ignoring child status. No local slot bound; no matching Outbreak8-port allocation facade. |
| `FreeMidiSlot` 196..204 | midi-port-adapters | If registered calls sdMidiClosePort then clears flag. Outbreak cancellation/stream stop does not close an equivalent per-slot MIDI port. |
| `CheckPlayMidi` 207..214 | midi-port-adapters | sdMidiGetStat into local status then returns m_Flg&1; no registration guard. Outbreak query1AE2E0 multiplexes ADXT state/control fields, not the same status bit/port object. |
| `PlayMidi` 217..223 | midi-port-adapters | Registered slot and ListNo!=-1 gate sdMidiPlay(handle,bank,list,priority). Outbreak descriptor request links/randomization/queue identity differ; no same port ownership or signed request sentinel. |
| `ExPlayMidi` 226..285 | midi-port-adapters | SND_REQ per-field delay-2 resets,-1 preserves,others update; volume reset uses SdcSeDefaultVolume even for MIDI, not Midi default. Pitch/speed/effect controls precede PlayMidi; no same Outbreak descriptor/request ABI demonstrated. |
| `StopMidi` 288..294 | midi-port-adapters | Registered flag gates sdMidiStop(handle), preserving open slot. Outbreak cancel coalescing or ADXT stop uses distinct handles/state and is not a matching full MIDI wrapper. |
| `SetPanMidi2` 297..305 | midi-port-adapters | Registered AND (PanFunc!=0 OR FadeFunc!=2) gates sdMidiSetPan(float,shortDelay), then caches float pan. This surprising FadeFunc predicate is literal source; no Outbreak corresponding guard or delayed float-pan port API. |
| `SetPanMidi` 308..311 | midi-port-adapters | Converts char pan to float and delegates SetPanMidi2. Outbreak signed-byte SDR presence flags and CRI-15..15 pan clamp are different units/ownership. |
| `SetVolumeMidiEx` 314..337 | midi-port-adapters | Active FadeFunc0 sends/stores caller volume; FadeFunc1 may retarget fade when Flag0 and new volume<VolLast, stores volume then falls through2 to send cached volume with delay0. No same Outbreak setter/fade-state fallthrough contract. |
| `SetVolumeMidi` 340..343 | midi-port-adapters | Char volume adapter to SetVolumeMidiEx with Flag0. Outbreak quantized level/attenuation setters are another representation and cancellation policy. |
| `SetVolumeMidi2` 346..349 | midi-port-adapters | Float volume adapter to SetVolumeMidiEx with Flag0. No identical Outbreak8-port volume/fade-state facade established. |
| `SetPitchMidi` 352..358 | midi-port-adapters | Registered slot gates sdMidiSetPitch(shortPitch,shortDelay). Outbreak SDR pitch payload does not establish MIDI port or delay semantics. |
| `SetSpeedMidi` 361..367 | midi-port-adapters | Registered slot gates sdMidiSetSpeed(shortSpeed,shortDelay). No matching complete MIDI tempo/speed owner shown in SDR effect requests or ADXT streams. |
| `SetFxLevelMidi` 370..376 | midi-port-adapters | Registered slot gates sdMidiSetFxLev(charFxLevel). No identical Outbreak port-specific effect-send facade or parameter units established. |
| `SetMidiDefaultVolume` 379..382 | volume-configuration | Stores SdcMidiDefaultVolume byte only; no whole corresponding Outbreak8-MIDI-port default field/consumer identified. Do not infer effect from storage spelling alone. |
| `InitSeInfo` 385..407 | shot-port-adapters | Visits20 SDS_INFO slots, initial flag clear or later FreeSeSlot, zeroes volume/limit/fade/pan modes. Distinct from32 queued SDR command slots or three ADXT channels. |
| `RegistSeSlot` 410..422 | shot-port-adapters | Existing registration returns1; otherwise sdShotOpenPort, flag1, return0 without checking status. No same Outbreak20-shot-port allocation interface. |
| `FreeSeSlot` 425..433 | shot-port-adapters | Conditionally sdShotClosePort then clears registration flag; not equivalent to SDR queued cancellation or retained ADXT stop. |
| `CheckPlaySe` 436..443 | shot-port-adapters | sdShotGetStat and lowbit query without local registration guard. No same Outbreak status bit/shot-port record established. |
| `PlaySe` 446..452 | shot-port-adapters | Registered and ListNo!=-1 gates sdShotPlay(handle,bank,list,priority). Outbreak SdrSeReq exposes packed identity and parameter presence, not this registered shot handle/request tuple. |
| `ExPlaySe` 455..509 | shot-port-adapters | SND_REQ delay-2 resets,-1 preserves,others update pan/volume/pitch; FX switch-2 explicitly sends0,-1 skips. No MIDI speed path here and no same Outbreak whole request ABI. |
| `StopSe` 512..518 | shot-port-adapters | Registered slot gates sdShotStop on retained port. SDR cancellation edits pending commands/coalesces before enqueue; no equivalent full registered-shot stop facade. |
| `SetPanSe2` 521..529 | shot-port-adapters | Registered slot sends float pan/short delay then caches pan; unlike MIDI variant it has no FadeFunc/PanFunc admission condition. Outbreak pan fields and deferred queue controls differ. |
| `SetPanSe` 532..535 | shot-port-adapters | Char-to-float wrapper to SetPanSe2. No same typed slot/port/float-delay wrapper in the inspected Outbreak consumers. |
| `SetVolumeSeEx` 538..561 | shot-port-adapters | Shot counterpart of FadeFunc0 direct setter and FadeFunc1 retarget/store/fallthrough2 cached immediate update. Outbreak channel level setter cancels a different ramp representation, not this protocol. |
| `SetVolumeSe` 564..567 | shot-port-adapters | Char volume and Flag0 adapter to SetVolumeSeEx. No same shot-port registration/fade-state ABI demonstrated. |
| `SetVolumeSe2` 570..573 | shot-port-adapters | Float volume and Flag0 adapter to SetVolumeSeEx. Not identical to Outbreak signed integer level plus gain-table conversion. |
| `SetPitchSe` 576..582 | shot-port-adapters | Registered shot port gates short pitch/delay SDK call. Outbreak queue pitch halfword alone cannot establish same delay or ownership contract. |
| `SetFxLevelSe` 585..591 | shot-port-adapters | Registered shot port gates sdShotSetFxLev. No same complete Outbreak slot-specific effect-send facade established. |
| `SetSeDefaultVolume` 594..597 | volume-configuration | Stores SdcSeDefaultVolume byte, which both extended request bodies can select. No same Outbreak default byte/request structure demonstrated. |
| `SetFxProgram` 600..605 | effect-program-adapters | sdSndSetFxPrg(charProgram,charOutput) then sets ExecFxFlag1. Inspected SDR numeric control RPC is not decoded to this program/output API; no enum or ownership identity inferred. |
| `StopFxProgram` 608..616 | effect-program-adapters | Calls sdSndClearFxPrg only if ExecFxFlag nonzero, always clears flag. No same connected Outbreak effect-program flag/set/clear pair demonstrated. |
| `RequestMidiFadeFunction` 619..649 | volume-fade-state | Sets start-127/targetLimit forFunc1 or target-127 forFunc2; count=((Timer/100)*30+((Timer%100)*6)/10)/2, exact0=>1; speed=(Volume-target)/count. Different from Outbreak maximum-capped target/duration step with no timer conversion/countdown. |
| `RequestMidiFadeFunctionEx` 652..684 | volume-fade-state | Start-1 uses integer conversion of current float volume, stores target/count; Frame0 leaves old VolSpeed, then speed<0 choosesFunc1 else2. Outbreak1AE3F0 always divides by supplied duration and has no matching stale-speed or sentinel branch. |
| `StopFadeMidi` 687..690 | volume-fade-state | Clears MidiInfo.FadeFunc only; no SDK stop. Outbreak1ADFD0 clears its ramp as part of volume publication, not this isolated8-port state operation. |
| `RequestSeFadeFunction` 693..723 | volume-fade-state | 20-slot shot counterpart of timer formula, Func1 start-127/targetLimit,Func2 target-127 and exact-zero count fixup. No same Outbreak ramp/count/units or stop sentinel established. |
| `RequestSeFadeFunctionEx` 726..758 | volume-fade-state | Shot start-1/current-to-int, explicit target/count and Frame0 stale speed preserved. No identical Outbreak whole request or state transition. |
| `StopFadeSe` 761..764 | volume-fade-state | Clears SeInfo.FadeFunc only; no port stop or volume change. No same connected Outbreak20-port isolated fade-mode clear. |
| `CheckFadeEndSe` 767..775 | volume-fade-state | Returns0 when FadeFunc0,otherwise1, i.e. outstanding fade flag despite End name. Outbreak1AE470 tests float ramp!=0 (including NaN), different representation/ownership. |
| `ExecSoundFadeManager` 778..842 | volume-fade-state | Scans8 MIDI+20 shot SDS_INFO records; modes1/2 subtract speed and predecrement count, snaps only when count<0, stops port at intVolume==-127, then sends through forced setter. Outbreak three-channel worker uses maximum/gain-table quantization and target crossing with no such countdown or MIDI/shot stop sentinel. |
| `RequestMidiPanFunctionEx` 845..867 | pan-ramp-state | StartPan-1 uses int conversion of current float, sets last/count, updates speed only if Frame!=0 using128+pan operands, always sets PanFunc1. No identical Outbreak pan-ramp/count/slot protocol. |
| `RequestSePanFunctionEx` 870..892 | pan-ramp-state | 20-slot shot counterpart retaining old PanSpeed for Frame0; explicit128-offset arithmetic and signed sentinel are reference-specific. No same Outbreak complete pan-ramp constructor shown. |
| `ExecSoundPanManager` 895..938 | pan-ramp-state | Scans8+20 slots; active pan subtracts speed/decrements count, snaps/clears only below0, calls per-port float pan setter every active invocation. Outbreak ramp worker is volume-only and CRI pan setter is a clamped stored integer, not this complete pan manager. |

### sdcwrap.c

| Reference function / lines | Family | Complete-body comparison and remaining boundary |
| --- | --- | --- |
| `InitSdcParameter` 11..24 | sound-bootstrap-facade | Reads/applies cached config mode, sets master15/GDDA127/default MIDI0/default shot0, initializes8/20 slot tables, then sets first flag1. No same Outbreak defaults, local tables or sd port lifecycle established. |
| `InitSoundDriver` 27..68 | sound-bootstrap-facade | Queries/allocates/reads driver file with tray check and ExitApplication on read failure, calls SetupSoundDriver and frees buffer; optional multi-unit repeats flow, then parameter init/return0. No same complete Outbreak filename-driven sd driver/multi-unit loader facade demonstrated. |

## Owned interval audit receipt

These22 complete intervals are comparison evidence, not new function credit. The machine receipt retains their existing authoritative note paths and rows.

| Owned entry | End exclusive | Original interval SHA-256 | Verified words / omitted zero words |
| --- | --- | --- | ---: |
| `main:13F038` | `13F054` | `fc6404608f0e787ca4750e45ad4adece393f8d5406a7b491cb6894ce9b5ff2b2` | 7 / 0 |
| `main:13F058` | `13F080` | `020d99269d3b36b0ebf6b02b13a1e947b381bbcbc6701ecb96d2e05731a6c49a` | 10 / 0 |
| `main:1A71E0` | `1A7304` | `4b76269c5e3d4a3b7056152ace304b0cff54b76c7332fd9b88030f759bf0ef6f` | 71 / 2 |
| `main:1A7310` | `1A7430` | `1c340c1659a5237e498795955e72eeb0589bdc1152fd3e90bee0d1bf4dfd9566` | 71 / 1 |
| `main:1A7430` | `1A7544` | `c23bda1d6d3e4df36313a630dd69a09e75f13c7fee045713665f06397a1ebf80` | 66 / 3 |
| `main:1A7550` | `1A7688` | `373bd99b267a281746e61ce18fc9038d5b0e3f8da4b0ee1eb53ff98c79ff8076` | 76 / 2 |
| `main:1A7900` | `1A7A7C` | `db0004ef8d07ca3b02ce710ed1ea626fd6e28699fa5e548d8d5fbcc0d3666601` | 92 / 3 |
| `main:1A7F50` | `1A7FA0` | `abb21455e20daa0a3f40e267f0fbbac68bfe681f5eeed81796f7a76a8c50f315` | 19 / 1 |
| `main:1A7FA0` | `1A7FA8` | `4a3912394769135d5148ef7027492b06244b0c3a4a8cc9361160752bfc1b2441` | 1 / 1 |
| `main:1A7FB0` | `1A8054` | `3bd9eec35188f804268c69e890323838f1df30fea15bd0aac78607bb1a5db821` | 41 / 0 |
| `main:1A8060` | `1A80C0` | `830a4cc13efd5064afb4a4d9f596c3965b90154da6efe9577f1dd6c70659c011` | 23 / 1 |
| `main:1AC6D0` | `1AC708` | `02b1b8bd3de7cf30e4251d7fd6e33198a1a5b737dd3821c739217e58daf9fc57` | 13 / 1 |
| `main:1AC730` | `1AC7E8` | `4e838d66ca10e273350eeb34938766c00e268846d5d7e90f2132926e320a1988` | 41 / 5 |
| `main:1AC7F0` | `1ACB5C` | `a9abc0c1f2d2fbaf914d5ee2dae38da15b478bcbc47af91fd41c737dc0dc58eb` | 207 / 12 |
| `main:1ACEB0` | `1ACF58` | `b52584f508b262caf6bc6199382c01260d8125bcf8b0630f6cac5f20a005d386` | 40 / 2 |
| `main:1ADFD0` | `1AE0BC` | `3713bc4dfaffef0ebe01848a256daa992a7baf73f28e74bcec8fa64548c2274b` | 58 / 1 |
| `main:1AE0C0` | `1AE190` | `b36bc3593f61c3ea15b4563f1b2cc62ab99437e915540ddf4264fd16391a991f` | 51 / 1 |
| `main:1AE190` | `1AE1DC` | `18293606ad2df04ec5cb647690a11989183cc221be42f223821f018d59041d26` | 19 / 0 |
| `main:1AE2E0` | `1AE3CC` | `9cd6ae87b4085a17d55039d378427dbe30ae7329f2015debef2e49e1640df41c` | 54 / 5 |
| `main:1AE3F0` | `1AE46C` | `f015e7876ac7f057659b502aa24514c9183d7b596dd8773043ae01990fe58905` | 30 / 1 |
| `main:1AE470` | `1AE4AC` | `33e09f2a243fd6a9d120717f1d53d5341a03223235e5a9cf3a5cd6de2057323d` | 14 / 1 |
| `main:1AE4B0` | `1AE6C4` | `1e22a2b3ec125a6cf8f37bfb119297e8e37a451b22f453cab64d12fd9d583fee` | 123 / 10 |

No material error in the existing Outbreak sound annotations was proven here. Reusable audio-framework purpose is acknowledged, while identical API bodies, parameter scales, slot ownership and serialized formats remain unproven. This closes the57-definition applicability screen with explicit evidence rather than a filename-based game-sound exclusion.
