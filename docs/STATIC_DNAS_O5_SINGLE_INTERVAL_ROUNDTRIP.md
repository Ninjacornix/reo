# One DNAS interval reconstructed by offline byte arithmetic

Static File #1 US investigation, 2026-11-05. **The clear routines and owned metadata are sufficient to reconstruct this one 68-byte interval and restore its exact original bytes.** This proves the selected byte transformation and paired restore schedule. It assigns no additional function meaning or mapping credit.

Only new private copied byte buffers were changed. No recovered instructions were executed, emulated, built, installed into the runtime, or written into the owned input/generated source. No game, process, live memory or network was accessed.

## Input and bounded selection

The input is the existing owned `o5.bin`, runtime ID7, base `0x6E0000`, embedded name `insdnas.bin`, SHA-256 `97174f5d367cd90bedd5ba397c6492e9fb4bbd0ec7d6021c2be524c49925d38e`. The [reviewed transform routines](SYMBOLS_DNAS_TRANSFORM_COPIES.md) and [protected entry](SYMBOLS_DNAS_PROTECTED_ENTRIES.md) were read again with their original owned words.

The selected protected payload is `[0x702F74,0x702FB8)`: `0x44` bytes, 17 little-endian words, inside entry `0x702EF0`. Its descriptor at `0x702F60` contains five words:

```text
00000000 3CAE8DA9 00000000 3CAE8DED 00000000
```

The clear call at `0x702F38` passes payload anchor `0x702F74`, span operand `3CAE8DED`, selector `3CAE8DA9`, packed key/direction `0`, to `0x700B18`. Thus span is `3CAE8DED XOR 3CAE8DA9 = 44` hex. Direction0 selects the interval beginning at the anchor and inverse table `0x70B7D0`. Exception key is `packed>>1 = 0`; lookup `0x700BF0` returns three zeros and predicate `0x700CA8` admits every word without reading an exception list.

## Actual schedules, including restore

Normalizer `0x700CE8` masks each of seven low nibbles to three bits. The upper nibble's low three bits set the pass count, with zero replaced by five. Both dispatchers consume low nibbles in increasing order. They do **not** automatically reverse the schedule.

| Route | Owned selector | Normalized selector | Consumed indices | Original primitive addresses |
| --- | --- | --- | --- | --- |
| Decode | `3CAE8DA9` | `34260521` | `1,2,5` | `7015F0,701690,7018E8` |
| Restore | `3CAE89AD` | `34260125` | `5,2,1` | `7011A0,700F68,700EC8` |

Let `A=09F8ED17`, `B=A95128C3`; all arithmetic retains 32 bits. The three decode passes are `w XOR B`, rotate-right13, then `rotate-right13(w XOR A)`. The separate forward primitives implement rotate-left13 then XOR A, rotate-left13, then XOR B. Their actual restore selector supplies the reverse index order.

That restore selector is owned metadata, not an assumed mathematical inverse. Clear setup at `0x702FE8..0x703008` loads metadata pointer `0x702FD8`, anchor `0x702FB8`, then calls `0x700B18` at `0x703000`. Metadata words are:

```text
3CAE89AD 00000001 3CAE89E9
```

Packed direction1 selects `[anchor-span,anchor)`, again the exact selected payload. Its exception key is also zero. The direction0 descriptor self-pointer mark and direction1 clear were reproduced on the copied descriptor word only. Kernel cache-flush calls were neither invoked nor needed for byte arithmetic.

## Evidence and result

[The reproducible script](../tools/function_index/recover_dnas_o5_byte_compare.py) contains only the three individually reviewed operations needed here. It reads the actual tables/descriptors, checks the clear restore-call words, uses a new guarded bytearray, and writes [identity/schedule/results JSON](../build-function-index/dnas-offline-o5-702f74/artifacts/proof.json). It refuses to overwrite an existing output directory. For another run, supply a fresh directory with `--output`.

| Artifact | SHA-256 |
| --- | --- |
| [Original encoded payload](../build-function-index/dnas-offline-o5-702f74/artifacts/encoded.bin) | `b70c789cbc9d6787941e81fd57f197608880aa6016e8c1110250ea7d17da33de` |
| [Transformed candidate](../build-function-index/dnas-offline-o5-702f74/artifacts/candidate.bin) | `e507066b82b2fdcae2e125652cd50fee53febe455dcd130cdb380c25b1544da9` |
| [Restored encoded payload](../build-function-index/dnas-offline-o5-702f74/artifacts/restored.bin) | `b70c789cbc9d6787941e81fd57f197608880aa6016e8c1110250ea7d17da33de` |

All 17 payload words changed. Applying the original paired restore schedule returns **all 68 bytes exactly**, not merely matching a checksum. A second equality check covers the complete 120-byte copied frame `[0x702F50,0x702FC8)`, including the descriptor mark/clear and 16 guard bytes before and after the descriptor/payload region. Its original and restored SHA-256 is `be0a7c67120285029ef9d758f73b3b3eadcd5ef1eb93d271fc20ccfd56aab843`. Only the payload and descriptor's first word change in the candidate frame; all other copied bytes remain identical.

The forward arithmetic follows its own original shifts/mask/XOR order rather than calling a generated inverse of the Python decode function. Forty additional control words, including zero, all ones, sign boundaries, XOR constants and each single-bit word, pass both directions for each selected primitive. This supplements the actual owned-payload equality check; it is not a CPU execution test.

The script also checks 13 connected catalogue intervals against owned bytes: **550 instruction-comment words, four omitted zero/NOP words, zero conflicts and zero omitted nonzero words**. Every dependency interval/hash is recorded in `proof.json`. The input file is read again afterward and still has its original whole-image hash.

The complete reconstructed payload words, in address order, are retained here so the evidence survives scratch-artifact cleanup:

```text
702F74 1220000F
702F78 0000282D
702F7C 02651821
702F80 02452021
702F84 90620000
702F88 24A50001
702F8C 90830000
702F90 00B1302B
702F94 0062202B
702F98 0043102B
702F9C 14400006
702FA0 2410FFFF
702FA4 14800004
702FA8 24100001
702FAC 14C0FFF4
702FB0 02651821
702FB4 0000802D
```

The repository helper locates the repository from its own path and defaults to the original repository-owned image and a private `build-function-index` output folder. Reproduce into a fresh directory:

```powershell
python tools/function_index/recover_dnas_o5_byte_compare.py --output build-function-index/dnas-o5-roundtrip-new
```

The result is one reproducible transformed candidate with a validated paired byte restore. It does not validate other selector families, nonzero exception metadata, runtime callability, successful DNAS activity, or the complete connected function's semantics. At the end of this byte-only proof, independent instruction-boundary/control-flow and full-body review were still required. The subsequent [complete-owner comparison review](SYMBOLS_DNAS_RECOVERED_UNSIGNED_BYTE_COMPARISON.md) now supplies that evidence and refines the existing owner annotation, without adding a fragment identity. The [earlier residual admission inventory](STATIC_O5_DNAS_RESIDUAL_ADMISSION_REFRESH.md) remains correct for its earlier no-transformation scope; this later experiment changes the evidence available for this single interval only.
