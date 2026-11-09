# Retail effect descriptor audit

File #1 US owned-asset analysis, 2026-11-09. The five retail scenario archives in
the pinned inventory contain 265 room-script members and 74 texture descriptors.
Every descriptor selects the animated-texture branch; none selects the numbered
effect-movie branch. This establishes the contents of those retail descriptor
sets without a game run. It does not establish that every possible producer or
runtime path avoids effect movies.

## Producer and consumer

The actual descriptor array starts at `392630`, with count `3926BC`; `390000` is
not its base. Complete original main function `1D0C80..1D102B` supplies the data:

- `1D0D80` sets `s4=39269C`; `1D0DA0` initially clears its `+20` count.
- `1D0D88..1D0DA4` selects temporary storage `word[32440C]+200000`.
- Normal source mode formats `%sr%03d\e%03d%02d%02d.bin`, from owned main string
  `256260`; alternate source mode uses `e%03d%02d%02d.bin` at `256280`.
  Current scenario/room/variant come from `3243DA/DC/DE`.
- After a nonzero read, `1D0E50` reads the file's little-endian first word as
  count. `1D0E54..1D0E6C` copies `count*8` bytes from file offset `4` to `392630`.
- `1D1004` stores that count at `s4+20`, or `3926BC`.

The consumer is complete owned overlay-2 function `576F90..5770B7`.
`576FBC..576FD0` skips first byte `FF`, selects animated texture setup when bit
`80` is set, and otherwise reaches `577028 -> o0:371A10(1)`. The existing caller
audit follows the deferred effect service to `1CC2D0`; scenario 0 / room 1
overrides the stored effect ID to 128. These are conditional code facts, not
observed effect playback.

The reproducible audit compares every word in the producer and consumer
intervals with owned bytes: 228 and 70 commented instructions respectively,
plus 7 and 4 omitted zero words. It rejects mismatches, conflicting comments,
and omitted nonzero words. Owned main ELF SHA256 is
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`;
owned o2 SHA256 is
`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

## Owned retail payloads

All matching members reside in `NETBIO00.DAT`:

| Nested archive | Matching room-script members |
| --- | ---: |
| `r001.afs` | 79 |
| `r002.afs` | 45 |
| `r028.afs` | 32 |
| `r035.afs` | 35 |
| `r041.afs` | 74 |

The audit reads all 579,504 bytes in these 265 members and verifies each full
payload SHA256 against the pinned inventory. There are 231 zero-count members
and 34 nonempty members; counts range from 0 to 8. All 74 descriptor first bytes
are `80..87`; none is `FF` or an effect-arm value. No `e000NNNN.bin` belongs to
this cohort.

For example, `NETBIO00.DAT/1/1398`, named `r001.afs/e0012700.bin`, occupies ISO
offset 588,546,048, length 2,192, SHA256
`8eebb95fb2d5fed3d0c6c50722838173193713539bf1839a9c2036cfe0bee585`.
Its three descriptor rows at offsets `4`, `C`, `14` are
`8004050800000000`, `8106071000000000`, `8208091000000000`.

## Reproduction and extraction boundary

From the repository root, use a fresh output directory:

```powershell
python tools/native_reconstruction/audit_retail_effect_descriptors.py --output build-native-sjuni/retail-effect-descriptors-v1
```

The script writes only metadata in the new output directory. Its `audit.json`
contains per-member identities, exact offsets, all descriptor rows, summary
counts, source hashes, and every source/owned-word comparison. It refuses an
existing output directory. A different owned ISO location can be supplied with
`--iso`; the pinned member hashes must still match. The prior inventory receipt
records the full ISO hash; this audit does not rehash the entire disc.

To extract a descriptor-bearing member independently, seek to its inventory
`iso_offset`, read exactly `bytes`, verify `sha256`, read count at offset zero,
check `4+8*count <= bytes`, and enumerate eight-byte rows from offset four. The
audit performs this bounded procedure without writing raw assets.

An effect-arm row would establish effect ID 1, or the separate scenario-0/room-1
override 128, rather than taking the effect ID from the descriptor byte.
`1CC2D0` formats `data\rom\eff_mov\eff_%03d.mov`; its direct-disc length query
and scenario-resource read are separate. Therefore a payload investigation must
follow the active resource directory/name lookup to an exact owned extent,
then verify the consumer's header fields and decode. No such row or associated
effect payload was identified in this cohort. A wider signature scan alone
would not replace that producer-to-resource proof.

Indirect writers, runtime mutation, alternate roots, mods, other builds, and
other caller paths remain outside this result. No game or decoder was launched;
no live process or window was accessed. This does not authorize global IPU or
effect-path removal. See [the broader retirement audit](MEDIA_RETIREMENT_AUDIT.md)
and `tools/native_reconstruction/media_effect_caller_audit_v1.json` for the
separate conditional caller evidence.
