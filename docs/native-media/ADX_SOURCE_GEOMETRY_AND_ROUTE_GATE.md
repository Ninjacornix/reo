# ADX source geometry and route gate

Status: read-only metadata derivation and owned-word source audit, 2026-11-06.
This is new evidence for the remaining stage-3 source boundary, not native
source admission, an actual playback observation or a slowdown diagnosis.

The [audit tool](../../tools/native_reconstruction/audio_source_geometry.py)
reads the pinned [asset inventory](FILE1_AUDIO_ASSET_COMPATIBILITY.md) metadata
and checks six selected source intervals against the owned File1 ELF. It does
not reread/extract payloads, launch a game, open a device or change a reader.

## Logical payload geometry

Of **8,910 structurally identified ADX references** / **6,786 distinct payload
hashes**, only **91** logical member lengths are multiples of2,048 bytes.
**8,819** have partial-sector tails, including **1,905** shorter than one sector.
All8,910 logical extents can hold the header and the minimum18-byte blocks
implied by their declared total/channels. That arithmetic check does not prove
the compressed contents decode or establish their live source route.

| First archive label | Whole-sector references | Partial-sector references |
| --- | ---: | ---: |
| `adxsnd.afs` | 6 | 8,380 |
| `bgm.afs` | 46 | 34 |
| `pl00_vo.afs` | 0 | 317 |
| `voice.afs` | 0 | 88 |
| Five environment archives combined | 39 | 0 |

These are reference counts with duplicates. The six rejected magic-only
candidates are excluded, as are opaque members and undemuxed program streams.
Archive labels do not identify runtime routing. Physical AFS alignment does
not prove trailing bytes belong to a bounded logical member view.

The qualified Source2 still requires whole-sector ranges in its actual view.
Its Window2 qualification therefore does not admit all these logical payloads.
It is also incorrect to conclude that every partial member requires file-backed
tail padding: memory/SJMEM and LSC paths have different contracts.

## Original source distinctions

The six complete audited intervals match398 owned instruction comments plus10
omitted zero words, with no missing nonzero word. Static matching is not replay.

- `133490..133580` StartAfs resolves partition/member through129E18 and retains
  its path/parent/start/length in the ADXT record before selecting deferred
  file-start state. It does not eagerly copy an ADX payload into SJMEM.
- `133618..133630` StartMem forwards a declared capacity`0x40000000` to
  `133630..133708` StartMem2. That routine creates the SJMEM view, initializes
  decoder input and selects mode2. The large declared capacity is not proof of
  physically owned backing length and cannot become a native bounds check.
- `131C50..131D18` configures the file range and delegates file open/start plus
  decoder initialization. This deferred path and its actual backend length must
  be connected to the resolver before drawing conclusions from member length.
- `1307A8..1307E8` derives the default target using signed division and a positive
  remainder increment: for positive lengths, a ceiling sector count.
- `130800..130B78` bounds requested whole sectors with signed floor division of
  the stored file byte length. Existing2049-byte reference evidence reaches a
  zero-sector tail request and stays reading; it does not prove padded success.

The previously mapped engine start sites1ADA20/1ADB30 and the archive selection
branches in1AE7D0 call StartAfs. Their existence is evidence against assuming
that all small/voice-named assets use StartMem. This audit does not connect all
8,910 indexed references to these sites or prove which branch ran in play.
Generated companion files can contain neighboring bodies; caller discovery by
filename alone is not a count of distinct original call sites.

## Implementation gate

The next source contract must establish actual resolver length/start units,
deferred open result, logical versus retained backing extents, read/seek/poll
semantics at the last sector, and EOF/target/loop ordering for each admitted
AFS/file, memory and LSC route. Replay boundary lengths0/1/2047/2048/2049 and
wrapped final grants through those real helpers. Preserve actual accepted work,
partial results, stop/close and backing lifetime.

Keep Source2 and its proof unchanged. A wider source/owner must have an explicit
version and new original inputs. Any deliberate native byte-reader policy must
separately demonstrate equivalent decode/progress, rather than claim raw sector
ABI parity. Do not invent bytes, round a member view into its neighbor, assume
EOF is success, or infer a device-consumption fence from copied data.

Local report: `build-native-sjuni/audio-source-geometry/file1-v1/report.json`,
SHA-256 `3a33d06bbe9bfa6b188b9efc81ba7690ccbb949b97d9e2bd909e83817caa61af`.
It records inventory/ELF/tool identities, grouped counts and full audited body
identities. The inventory input hash is
`276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2`.
