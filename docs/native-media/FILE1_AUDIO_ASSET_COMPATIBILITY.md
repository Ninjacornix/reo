# Owned File1 audio asset compatibility inventory

Status: completed metadata inventory; source authority and read plan were recorded
before the full scan. This audit
reads owned container bytes and writes new metadata only. It neither extracts
payloads nor launches the game, and it does not measure performance or identify
assets used in an earlier recording.

## Source authority and read plan

The selected source is the local owned File1 v2.00 ISO. The repository's
`game_data` directory holds only the ELF. Before inspecting asset headers, the
inventory validates the ISO9660 index and requires the embedded `SLUS_207.65`
SHA-256 to equal
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
This establishes the executable revision; it does not authenticate a full retail
disc image. The audit records the full ISO hash separately.

The index reader follows the checked extents, dual-endian values, supported
directory-record flags, and sector geometry in `launcher/DiscImage.cs`. Nested
AFS tables are read by the existing bounded
`tools/assets/extract_assets.py::table`; its extraction function is never called.
AFS index paths identify entries, because names may be missing or duplicated.
Names are labels only. The audit hashes every regular ISO file, every nested AFS
container, and every leaf member, and records their exact byte extents.

`read_plan.json` is written before scanning. It records SHA-256 for the actual
parser and current native profile sources, the ISO path/length/write time,
metadata schema, allowed reads, and limitations. The scan refuses source-plan
drift and rechecks source metadata and authority hashes afterward. These local
checks assume no hostile concurrent modification; they do not revoke existing
writable mappings.

Recognized ADX headers require the binary marker, bounded header extent, and
`(c)CRI` marker. Magic-only candidates remain separate. The metadata contains
frequency, signed filter, encoding, bits, channels, version/control, block bytes,
sample total, and available loop fields. Compatibility means only that those
fields fit the current `game/native/adx_header` finite header profile: encoding 3,
18-byte blocks, bits 0/4, mono/stereo, version 3/4, filter 500 and
24/44.1/48kHz, with required readable header/history extents. It does not establish
complete ADX playback or runtime FP-environment admission.

HSYN HD recognition uses the actual reversed `SCEI`/`Vers`/`Head` and four chunk
signatures checked by `game/native/audio_banks/v2/algorithms.cpp`. The individual
2MiB part limit comes from both `Session::capture` and `Bank::load`. BD/TQ have no
established independent identification/pairing rule in this audit. An opaque
member's size or filename cannot establish a bank-part violation. Neither file
lengths nor offline metadata prove simultaneous 64MiB asset-budget sufficiency,
128 live-asset capacity, packet-size coverage, or real DSP/control support.

MPEG program streams/SFD remain undemuxed. The repository's lightweight
`media/sofdec/sofdec_decoder.cpp` has TODO audio-demux paths, so it supplies no
completed authoritative ADX stream enumeration. No decompression, random embedded
signature carving, or inferred room-bank pairing is performed. Opaque packed
members are explicitly uninspected.

## Reproduction

The tool and synthetic tests are under
[`audio_asset_inventory`](../../tools/native_reconstruction/audio_asset_inventory).
First create a fresh metadata plan, then execute that exact plan:

```powershell
python -m unittest discover -s tools/native_reconstruction/audio_asset_inventory -p test_inventory.py -v
python tools/native_reconstruction/audio_asset_inventory/inventory.py --iso "iso/Resident Evil - Outbreak (v2.00).iso" --output build-native-sjuni/audio-asset-inventory/<fresh-output>
python tools/native_reconstruction/audio_asset_inventory/inventory.py --iso "iso/Resident Evil - Outbreak (v2.00).iso" --output build-native-sjuni/audio-asset-inventory/<fresh-output> --scan
```

## Measured inventory

The owned image is 4,698,767,360 bytes, with SHA-256
`69ae2c48e6f01e2605659feabb54eb9b82c63a809bdc8a78ad2d160b3c59a4a1`.
The checked index contains 85 regular ISO files, 35 AFS containers, and 18,732
leaf references. All 8,910 structurally identified ADX leaves are in
`NETBIO01.DAT`; they represent 6,786 distinct full-payload hashes. Duplicate
references remain counted, rather than being silently deduplicated.

| Recognition | Leaf references | Interpretation |
| --- | ---: | --- |
| Structural ADX header | 8,910 | All fit the finite native header field profile; zero identified headers outside it. |
| MPEG program-stream magic | 201 | Undemuxed; audio streams and formats remain unknown. |
| Structural HSYN HD header | 1 | Individual HD length fits 2MiB; no complete bank tuple proved. |
| ADX magic-only candidate | 6 | All have inconsistent header fields/extent and no CRI marker; excluded from identified audio totals. |
| Empty | 680 | No format classification. |
| Opaque/unparsed | 8,934 | Audio membership and compatibility remain unknown. |

The six magic-only candidates occur in room/event/weapon-labeled entries, but
their exclusion follows their binary structure, not their names. Likewise, the
opaque count is not a count of unsupported audio files.

All identified ADX headers use encoding 3, 4 bits, 18-byte blocks, filter 500, and
version-control byte 0. Their observed combinations are:

| Frequency | Channels | Version | References |
| --- | ---: | ---: | ---: |
| 24,000 Hz | 1 | 3 | 4,171 |
| 24,000 Hz | 1 | 4 | 4,146 |
| 48,000 Hz | 1 | 3 | 176 |
| 48,000 Hz | 2 | 3 | 377 |
| 48,000 Hz | 2 | 4 | 40 |

No 44.1kHz header was observed in this identified set; that native-supported rate
is not needed to explain these particular assets. Header lengths range from 36
to 2,048 bytes. Loop fields are present/readable with enabled flag 1 in 89 headers;
8,821 have headers too short for the optional loop structure. The latter means
the fields are absent, not that a loop flag of 0 was read. Raw loop count/index
and four positions are retained without guessing their gameplay meaning.

Identified ADX leaf references total 1,050,288,272 container bytes and
1,013,472,419 declared per-channel samples. These totals include duplicate
references and do not measure samples actually decoded or played.

The 422-entry `adxsnd.afs` table is not 422 decoded audio files: entries 401–408
are eight nested 1,000-entry voice AFS archives, and entry 409 is another 88-entry
voice AFS. The scan follows these bounded nested tables. This explains the
larger leaf inventory relative to the historical two-level summary in
`ASSET_PAKS.md`; it is not evidence of source corruption. Identified ADX counts
by first nested archive are: `adxsnd.afs` 8,386, `bgm.afs` 80, `pl00_vo.afs` 317,
`voice.afs` 88, and the five environment archives 5/7/6/10/11. These names are
location labels after structural identification.

## Bank-part evidence and remaining gap

`NTGUI2/BIN/EFF.HD` is the only leaf beginning with the complete recognized HSYN
header/chunk structure. Its length is 1,408 bytes; SHA-256 is
`e712dd7f966ad9f7579b5f00191c9517bbbced3dc538c1b4a12efecf06daec2c`.
Its four chunk offsets are 1,072/912/240/80, with matching source signatures.
This individual HD fits the current 2MiB part limit.

The ISO also has a sibling named `NTGUI2/BIN/EFF.BD`, length 32,656, SHA-256
`379be985bf5fdd4802aba74d6b28e164f35917a1cd95d376d8d970e5e4d3aec4`.
That is an exact indexed-file observation, not proof that the native bank facade
receives it with this HD or a particular TQ. No TQ member or complete HD/BD/TQ
association was authoritatively established. Packed room resources were not
decoded. Consequently this audit finds no *proved* part-limit violation, but
cannot clear the gameplay bank domain or its decoded-allocation budget.

The useful next evidence is a source-qualified bank-resource loader map that
locates actual packed HD/BD/TQ spans and ties them to real facade submissions,
plus an independent bounded program-stream audio enumeration. Increasing the
native part limit or widening ADX header math is not justified by this scan.
The current observed ADX header fields do not expose a missing frequency/filter
profile. Neither conclusion attributes the previously measured starvation or
movie gaps to an asset.

## Verification and receipts

Eleven synthetic tests pass: finite/outside-profile ADX, magic-only refusal,
short/oversized header extents, AHX rejection, version 4 loop offsets, HSYN chunk
and part limits, ISO nested indexing, dual-endian disagreement, multi-extent
refusal, and bounded reads. No owned payload is used as a test fixture. The
inventory performed one completed read-only scan, with source authority and
source length/write-time checks unchanged afterward.

Private metadata is under `build-native-sjuni/audio-asset-inventory/file1-v1`:

| Artifact | SHA-256 |
| --- | --- |
| `read_plan.json` | `0558a2a30b023563228d8fc21566a7650510a150f399f8ccc4a6d210250d6d47` |
| `receipt.json` | `765b03bca36fa7a3c78f57f8bf73bb72f0790d504dd14054e304dff29d570d23` |
| `summary.json` | `ffc9c0c07d5a00f1773d66c4247189f74ae8358b33fc9dc3ba259926c7148a8d` |
| `members.json` | `276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2` |

`verified_index.json`, `containers.json`, and `archives.json` retain every
directory/index path and checked extent, including full container hashes.
`members.json` retains each leaf hash and parsed metadata, with its container
identity. The committed tool cohort/qualification files pin the reader, tests,
actual source authority, report, scan receipt and synthetic-test receipt.
Owned payloads remain outside tracked files. No runtime, SDK, bootstrap, game
state, or player data was changed.
