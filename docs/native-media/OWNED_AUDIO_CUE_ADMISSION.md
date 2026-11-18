# Owned audio cue admission audit

The native asynchronous preparation worker has now checked all 8,910 structurally
recognized ADX members from the pinned owned File #1 inventory. It admits 8,821
and explicitly refuses 89. Every refused asset has inline-loop metadata; the
current queued `Clip` profile rejects that metadata. No guard was removed and no
original producer was used to turn a refusal into apparent native success.

All extents are sector-aligned inside `NETBIO01.DAT`. The probe uses the actual
verified native resource mount and retained bounded views, not extracted audio
copies or an emulated file service. It checks the independent inventory's
container identity and offsets against the pinned import. The native worker's
channels, sample rate and total samples match the independent inventory for
every admitted member. Admitted rates are 24 kHz for 8,317 assets and 48 kHz for
504 assets. All preparation tickets release and the worker joins with matching
accounting. Imported file length, timestamp, file identity and manifest hash stay
unchanged. No game or audio device is opened.

| Cue | Native queued-clip result |
| --- | --- |
| `adxsnd.afs/s010100a.adx` (`NETBIO01.DAT/0/10`) | Admitted: stereo, 48 kHz, 4,633,715 samples. |
| `adxsnd.afs/E3-Bio_Mix.adx` (`NETBIO01.DAT/0/410`) | Admitted: stereo, 48 kHz, 9,849,840 samples. |
| `adxsnd.afs/bgm00.adx` (`NETBIO01.DAT/0/0`) | Refused by the queued clip profile; inline-loop metadata is present. |

This is header admission, not a PCM comparison, A/V check, engine command test
or proof that every inventoried asset is used through the queued consumer. The
ordinary native player already has a separately qualified regular-loop path;
this audit does not disable it or require converting every looped asset. Required
queued use of looped content needs explicit native loop/playlist semantics or
appropriate import-time preparation, with samples, controls and retirement
verified. Simply clearing a header flag or deleting a check would not establish
that behavior.

Engine cue binding remains next: resolve AFS/name requests to native resource
identities, use the preparation worker and pending-header fence, then bind
enqueue/start/count/repeat/reset/stop and validate game transitions. Unknown or
unsupported content must remain explicit. Opaque members and six unconfirmed
ADX magic candidates are outside this structural-ADX audit. Step 3 remains open.

Tools are `tools/native_reconstruction/probe_audio_cue_assets.{py,cpp}`. Counts,
selected cues, source/evidence hashes and limits are recorded in
`tools/native_reconstruction/owned_cue_admission_qualification_v1.json`.
The private plan, per-member results, executable and complete receipt are in
`build-native-sjuni/queued-audio-checks/owned-assets-llvm-v1`.
