# File #2 volume routing

File #2 now uses the same five live volume controls as File #1: Master, Music,
Sound effects, Voice and Interface. The host mixer applies category gain once,
then Master gain. Muting does not pause streams or alter bank sequencing. Mixed
cinematic soundtracks and unknown stream archives follow Master only.

## Original-game evidence

Routing was traced in the supported NTSC-U `SLUS_209.84` executable, SHA-256
`5c0411a26247ef9974cd94b844ac5aecbcbf4705db543f51814aeed89da0fd8d`.
The original ELF and sound data are not included in the repository.

| Source | File #2 evidence | Host category |
| --- | --- | --- |
| Stream starts | `0x18E090`, ADXT pointer in a0, AFS ID in a1, member in a2 | Classified before forwarding the captured original service |
| BGM | `0x136B90` registers `bgm.afs` as AFS 0; `0x145B70` starts channel 0 from AFS 0 | Music |
| Player voice streams | `0x136B90` registers `pl00_vo.afs` as AFS 1 | Voice |
| Spoken streams | `0x136C20` opens voice archives as AFS 5–8; dialogue commands use channel 1 / AFS 5 | Voice |
| Environment streams | `0x136AC0` registers `s%02denv.afs` as AFS 4 | Sound effects |
| Player banks | `0x144440`, ports 4–7 | Voice |
| Weapon banks | `0x144500`, ports 8–11 | Sound effects |
| NPC bank | Port 13; gun sequences 6, 8 and 9 at `0x1443D0` | Voice except those gun cues |
| Enemy banks | `0x144AD0`, port 12 | Sound effects |
| Selection speech | Port 12 with File #2 `start.snd` header fingerprint `0x2b5c216e4d0bfbd7` | Voice |
| Common/menu bank | Port 0 in retained native bank-load logs | Interface |

The selection fingerprint is FNV-1a 64 over the HD chunk, using the same
calculation as the production sound-bank mixer. File #1's different fingerprint
cannot accidentally classify File #2 port 12 as Voice. The bank files are in
File #2's original `NETBIO00.DAT/0` ROM archive. Retained native logs independently
confirm common/menu port 0, selection port 12, player port 4, weapon port 8 and
NPC port 13.

The stream hook reads the existing ADXT→RNA→host-handle chain with RAM bounds
checks, records its category and forwards the captured original function once.
Frame service `0x1EDCB0` polls the launcher's existing shared-memory protocol.
The host audio callback also polls; no new audio thread or IPC layout is needed.

## Verification and build requirement

- 330 File #2 actual PCM checks passed with owned sound banks, including category
  independence, half volume, mute, Master multiplication and live changes that
  preserve the playback cursor. File #1's 465 PCM/mixer checks also passed.
- Production hook/Windows IPC checks passed for both variants: File #1 58,
  File #2 60. They cover each stream archive route, handle reuse, bad pointers,
  original-function forwarding and invalid IPC snapshots.
- The Release launcher built with no warnings or errors. Its 1,222 self-checks
  and 21 audio WPF interaction checks passed, including actual File #2 slider
  publishing and reset behavior.
- Both games' complete bootstrap translation units passed MSVC syntax checking
  with the real runtime headers and their production compile definitions.

Rebuild File #2 and refresh its local-build kit to ship the native changes.
The updated launcher requires the native marker
`[AUDIO-MIXER-FILE2-1] master,music,sfx,voice,ui` and requests a rebuild for older
executables. Updating only the launcher cannot add native channel routing.
Controlled PCM and UI tests do not replace a fresh full-game build and gameplay
listening check; that final RC1 validation remains pending.

See [test commands](../tools/audio_mixer_check/README.md).
