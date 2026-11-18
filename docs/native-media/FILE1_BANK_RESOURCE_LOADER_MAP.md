# File1 packed bank loader to native facade

Status: static original-code and owned-container correspondence. The named
loader's HD/BD/TQ pairing is now established for 103 structurally valid packed
banks. This does not prove that they were submitted during a particular session,
that their DSP/control contents are fully supported, or that the simultaneous
asset budget is sufficient. No game, original instructions, bank decoder, or
audio device was executed.

## Evidence and scope

Owned `SLUS_207.65` SHA-256:
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
The tool checked 2,245 unique instruction-comment words across 16 selected
original ranges against the exact file-backed ELF bytes. Every omitted word
inside those ranges is zero; no unrepresented nonzero word remains. It records
the full generated-source hash and original range hash for each selection.
Generated catalogue bodies sometimes contain neighboring entries, so the range
ends are explicit, rather than inferred from the entire generated file.

The existing Ghidra bridge reported no running instance. The REA read-only
diagnostic also reported unavailable configuration/providers; none was installed
or changed. This investigation therefore uses verified original instruction
comments, existing notebooks with the same ELF identity, and direct read-only
container observations. It does not claim new decompiler evidence.

The source container is the prior verified File1 ISO inventory, SHA-256
`69ae2c48e6f01e2605659feabb54eb9b82c63a809bdc8a78ad2d160b3c59a4a1`.
That inventory's metadata hashes are checked before reuse. This pass checks the
ISO length/write time and rehashes every MOMO candidate member against its
previous full hash, then hashes each identified embedded span. No payload is
extracted. These are local source-consistency checks, not hostile-writer
exclusion or authentication of an entire retail disc.

## Named resource to three submitted spans

| Original function | Confirmed static contract |
| --- | --- |
| `1D3DC0` | Copies the requested name, appends `.snd`, calls name lookup `1AB310`, opens CRI partition 3/index through `129240`, requests the reported file size into the buffer at global `32440C`, polls until state 3, closes, then calls `1AC730(buffer,slot)`. |
| `1AB310 → 1AB050` | Resolves the normalized name against 422 complemented string pointers at `2337C0`. Normalization uppercases and replaces the supported path punctuation with underscores. The sound archive's outer partition setup is documented in `SYMBOLS_ARCHIVE_NAMES_IOP_STARTUP.md`. |
| `1AC730` | Calls `1ACFB0`, then waits for transport/control completion. This is transfer completion, not audible playback completion. |
| `1ACFB0` | Admits an unsigned slot below 14; reads three offset/length pairs from the same loaded buffer and calls `1A7900`. Also converts the separate control-row section into the guest slot table. |
| `1A7900` | Requires a selector below `1000`hex, 16-byte-aligned pointers and signed sizes below `1FFFF1`hex; reserves four queue records, emits a `4D` header and passes the three spans to `1A77D0`. It does not itself read an archive or decode a bank. |

The decisive original loads are
[`1AD0C0..1AD0E8`](../../recomp/config/output/sub_001ACFB0_0x1acfb0.cpp):

| Little-endian wrapper words | Argument to `1A7900` | Identified role |
| --- | --- | --- |
| `+08 offset`, `+0C length` | `a1=base+offset`, `a2=length` | HD |
| `+10 offset`, `+14 length` | `a3=base+offset`, `t0=length` | BD |
| `+18 offset`, `+1C length` | `t1=base+offset`, `t2=length` | TQ |
| `+20 offset`, `+24 length` | Separately converted by `1ACFB0` | TSB/control rows; **not** a fourth submitted bank part |

Offsets here and below are hexadecimal unless a decimal size is explicitly
given. HD/BD/TQ names come from correspondence with the actual SDK bank parser,
including the embedded HD's reversed SCEI chunk signatures and TQ's count/table
layout. The original wrapper code itself simply forwards three spans. `MOMO`
and wrapper version 4 are observed structural discriminators in the owned files;
`1ACFB0` does not locally validate those two words.

`1ACFB0` clears `600`hex bytes at `2B3950 + 600*slot`, converts at most 128
16-byte source rows beginning at `base + word20 + 10` into 12-byte controls,
and bounds the ordinary loop by `(word24-10)>>4`. This guest control table is
distinct from the native TQ command stream. The function has no file-length
argument or general malformed-input admission; the offline parser adds bounded
reads without claiming to reproduce arbitrary invalid-input behavior.

The synchronous loader uses the shared scratch buffer. The queued named loader
`1AD7E0` instead stages into its configured scratch and separates install,
transport-ack and control-ack phases; see
[the existing request-service notebook](../SYMBOLS_NAMED_SOUND_BANK_REQUEST_SERVICE.md).
An archive byte view alone does not replace those guest scratch/transfer
lifetimes.

## Queue encoding and current SDK boundary

[`1A77D0`](../../recomp/config/output/sub_001A77D0_0x1a77d0.cpp)
rounds each length upward to 16, queues three `4F` span records, and folds the
upper length bits into the otherwise-zero low address nibble. The serializer
[`1A85A0`](../../recomp/config/output/sub_001A85A0_0x1a85a0.cpp)
handles `4D/4E` at `1A88CC..1A88EC`: it reserves21 bytes while emitting the
three-byte load prefix. Its `4F` arm at `1A88F8..1A8920` emits each following
six-byte span through `1A82B0`. Thus the wire command is:

`4D | port big-endian16 | HD descriptor6 | BD descriptor6 | TQ descriptor6`.

For descriptor bytes `p[0..5]`, the actual SDK decoder uses:

```text
address = ((p0<<24) | (p1<<16) | (p2<<8) | (p3&0xF0)) & 0x01FFFFFF
bytes   = ((p3&0x0F)<<20) | (p4<<12) | (p5<<4)
```

`1A7DE0` serializes the guest queue, then calls `1179E8` using client `2B0C30`,
function 0 and packet buffer `2B0CC0`, with the source's padded send extent.
`recomp/config/outbreak.toml` skips the original libsif transport;
`recomp/overrides/reo_override.cpp` binds `1179E8` to HLE, optionally through
the native-CD/CRI-observer wrapper. Non-CD sound calls delegate to
`ps2_syscalls::sceSifCallRpc`.

The inspected actual SDK is the fully reapplied127 cohort, receipt
`909917fc2f766c8a43a10abbc0b94189fa24254ecfaa7f710e4eb24dc941b58a`.
Its `RPC.cpp` identifies command SID0/function 0. The complete-capture route
acquires an owner-qualified SoundCall and companion, captures the command
packet, ensures output, and calls the **same** `audio.submit_packet`. The
non-companion route also submits through that facade. `SoundCall::submit_packet`
selects the already chosen legacy or native owner; it does not retry legacy
after a native rejection.

The native packet3 decoder preserves the descriptor formula and source order.
For `4E`, an already-loaded port skips all unused asset descriptors. Otherwise
it reserves all three owned capture buffers, performs one coherent grouped
copy, releases that copy group, and only then prepares/installs the bank. The
metadata map establishes where the caller's bytes originate; it does not itself
prove this runtime capture authority or execute the facade.

## Measured packed-bank correspondence

The bounded pass found 134 `MOMO`-prefixed leaves across the full prior inventory:

| Class | Count | Evidence |
| --- | ---: | --- |
| Complete structural HD/BD/TQ bank | 103 | Four bounded wrapper pairs, valid embedded HD/chunk signatures, nonempty BD, and fitting TQ count table. All are adxsnd indices 297–400 except 354. |
| Partial structural HD/BD resource | 28 | ROMDATA indices 1304–1331; matching embedded HD/chunks and nonempty BD, with zero TQ/TSB lengths. |
| Other MOMO container | 3 | `MCICON.BIN`, `CNICON.BIN`, `GCRES.BIN`; do not satisfy the bank structure and are excluded. |

The 103 complete banks' original complemented lookup names match their AFS
labels at the **same indices**. This corroborates the source's named-loader
indexing; the pairing itself follows the original offset fields and embedded
structures. Other non-bank archive labels differ from original lookup aliases
(for example `DEMO_BATTLE_ADX` versus `battle_usa.adx`), so equal table counts or
similar filenames are not a general name/index identity proof.

For the 103 complete structural banks:

| Part | Largest observed declared length, decimal bytes |
| --- | ---: |
| HD | 10,288 |
| BD | 629,280 |
| TQ | 2,576 |
| TSB, separately consumed | 2,064 |

All three submitted spans, including source transfer rounding, fit their own
member extents and the current 2MiB individual-part limit. Every identified TQ
has 128 table entries; each observed Vagi highest index is 0..56, its offset table
fits the HD, and the source's 4095 highest-index limit is satisfied. No VAG
sample decode, TQ instruction execution, decoded-PCM capacity, allocation-cost
or gain/control admission was tested by these metadata checks.

A reproducible example is `NETBIO01.DAT/0/297`, original name `COMMON_SND`, member
SHA-256 `8b69992911b3204aa8df2dd9c1d650138ae2027fdd0054a83a4a0be5d2f7ecc8`:

| Part | Relative offset, decimal | Length, decimal |
| --- | ---: | ---: |
| HD | 64 | 1,408 |
| BD | 1,472 | 32,656 |
| TQ | 34,176 | 2,576 |
| TSB | 36,800 | 2,064 |

Its embedded HD hash is
`e712dd7f966ad9f7579b5f00191c9517bbbced3dc538c1b4a12efecf06daec2c`,
and BD hash is
`379be985bf5fdd4802aba74d6b28e164f35917a1cd95d376d8d970e5e4d3aec4`.
These exactly match the standalone EFF.HD/EFF.BD files from the first inventory.
The TQ hash is
`7e7ba3299c9969fb8621de77b880a7d5765240f6ce9989016cf7e8b9a2c21102`.
This now establishes a complete packed common-bank tuple without inferring
pairing from the standalone filenames. `DOWNLOAD_SND` at index 298 supplies the
largest BD, and `ENEMY0318_SND` at index 299 supplies the largest complete-bank HD.
Every part's absolute ISO offset and full hash is retained privately.

## Separate enemy assembly path

The verified original `1B8380` preparation state machine first reads
`enemy.tq`/`enemy.tsb` and calls `1AD410`. That helper places TQ at wrapper + `40`,
stores its pair at `18/1C`, aligns the following TSB to 64 bytes, and stores its
pair at `20/24`. It then services four optional resource selections from dynamic
filename-pointer regions around `388BE4/388CAC`.

`1AD4B0` selects staging bases; `1AD4E0` copies each selected resource's
`08/0C` metadata part into the first staging buffer and `10/14` sample part into
the second, records the first-part pointer, and accumulates byte totals.
`1AD220` calls the fully mapped `1BE6D0` merger, then supplies **merged HD**,
**concatenated BD**, and the earlier **enemy TQ** to `1A7900`. The merger rebases
Vagi/sample/instrument references; it is not a byte concatenation of HD files.
See [the exact merge notebook](../SYMBOLS_SOUND_INDEXED_BANK_METADATA_MERGE.md).

The 28 partial packed resources have the right two-part structure for this path,
but their actual selection is still an inference: the dynamic filename tables
are not file-backed in this owned ELF, and this pass has not bound their
initialization to those 28 members. Their observed individual maxima are HD 8,832
and BD 400,880 bytes. Four times that observed BD maximum is 1,603,520 bytes, but
that is only a conditional bound if the selectable set is proved to be exactly
this set. It is **not** a proof of all merged-bank sizes. The original merge
workspace/global counters, collision/partial-error behavior, selected resource
set and output extents remain independent obligations. A post-merge size warning
does not supply missing capacity admission.

## Bounded unresolved links

1. The source name table contains 104 `_SND` entries, while only 103 satisfy this
   packed layout. Index354, `TEST_SND`/`test.snd`, length 67,840, SHA-256
   `cd4b4b0685b9097e02ce8a49ff63bae8787a17702f3083c3b345463fdfcd36ca`,
   starts with a different offset-table layout rather than MOMO/version 4. Its
   use and intended loader are unproved. Do not claim an active native failure
   or silently reinterpret it as the current layout.
2. Bind the enemy selection-table initialization to concrete resource indices
   and exact TQ/TSB sources, then qualify complete merged outputs. Static
   format resemblance alone does not clear those dynamic inputs.
3. Run the unchanged original bank parser/decoder against these source-qualified
   tuples in an isolated read-only fixture before claiming the real assets fit
   all parser/DSP bounds. Test native/original parity independently; this pass
   executes neither implementation.
4. Establish real active/retained-bank concurrency and allocation receipts before
   clearing the 64MiB/128-asset budget. Individual file sizes do not establish
   simultaneous retained generations or decoded allocations.

These questions refine the bank-domain boundary. They do not identify a cause
of the previously measured underruns, movie gaps or game slowdowns.

## Reproduction and final receipts

Supporting tool:
[`bank_resource_map`](../../tools/native_reconstruction/bank_resource_map).
It reads only the exact owned ELF/ISO and pinned inventory/SDK sources; outputs
are metadata beneath a fresh ignored directory.

```powershell
python -m unittest discover -s tools/native_reconstruction/bank_resource_map -p test_map_resources.py -v
python tools/native_reconstruction/bank_resource_map/map_resources.py --output build-native-sjuni/bank-resource-map/<fresh-output>
```

Five synthetic field/range/rounding/normalization tests pass. The completed
metadata output is `build-native-sjuni/bank-resource-map/file1-final-v2`:

| Artifact | SHA-256 |
| --- | --- |
| `receipt.json` | `8ed385eb7385b2d59261a7505debed6de6c75da639cebc9e59377f0cc0220d12` |
| `functions.json` | `2c9fe85359d964d06a0119ce2e373574f39b3cad3b687d3afa84d738a11adc30` |
| `packed_banks.json` | `b9a6dc953cafa4e18a7aaace6cdb940ee71f106202b73dcf9a0e429cd50fa3b7` |
| `summary.json` | `18eac4093ba83d011584054a239b3a0e1f3d56aa8409c4fceb166ad6a3acd4d4` |

The receipt pins the actual original source files, ELF code-range hashes,
fully reapplied SDK source hashes, tool, and outputs. The fresh source postcheck
is empty. Earlier bounded metadata trials are retained, including the initial
trial whose deliberately over-wide function ranges exposed neighboring words;
the final selected intervals close those gaps. No production file, SDK,
bootstrap, game state, or player data was changed, and nothing was committed by
this task.
