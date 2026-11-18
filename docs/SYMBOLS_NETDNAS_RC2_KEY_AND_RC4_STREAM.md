# Network DNAS: RC2 key expansion and RC4 permutation/stream primitives

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. Only original owned bytes and generated source were read; no cipher operation, game, build, replay, network request, attachment or live-memory inspection occurred.

Four complete bodies connect to the [named cipher-method adapters](SYMBOLS_NETDNAS_CIPHER_METHOD_ADAPTERS.md). RC2 key expansion and RC4 state/byte flow are independently supported by their full bodies and owned data. RC2 block arithmetic, cryptographic correctness/security, original names and active gameplay/session use remain outside this note. No slowdown attribution is established.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x715C10](../recomp/config/output_ovl/o4/o4_00715C10_0x715c10.cpp) | `expand_rc2_family_key_into_sixty_four_u16_words` | Confirmed complete local expansion and effective-bit mixing; malformed arguments and standard equivalence partial | a0 destination128 bytes,a1 signed key-byte length,a2 key,a3 effective-bit value. Negative length substitutes length1 and address7F1DC0; nonnegative length caps at128. Copies length bytes to128-byte stack workspace; expands each remaining byte through owned256-byte permutation77E860 indexed by previous-byte plus byte-keylength-behind modulo256. Zero effective value substitutes1024. Derives ceil(bits/8) with signed rounding, masks a selected tail byte, substitutes through same table, then works backward with XOR/substitution. Packs every adjacent pair little-endian into64 u16 outputs. No effective-bit admission, destination capacity check, key erasure or normalized return. Negative-length fallback address is outside this owned overlay; its contents are unresolved here. |
| [o4 0x715DB8](../recomp/config/output_ovl/o4/o4_00715DB8_0x715db8.cpp) | `xor_rc4_stream_bytes_and_commit_permutation_indices` | Confirmed complete RC4-shaped permutation/XOR loop; vectors/security partial | a0 state,a1 byte count,a2 input,a3 output. Zero count returns before state/input/output reads. Otherwise loads i/j from state+0/+4 and256 u32 permutation entries from+8. For each byte increments i modulo256, adds S[i] to j modulo256, swaps S[i]/S[j], XORs input with low byte at S[(old S[i]+old S[j])&255], writes output and decrements count. Commits last used i/j after final iteration. Reads current input before current output store, supporting ordinary exact in-place use. No initial negative-count rejection or state/capacity validation; arbitrary overlap and malformed state remain unproven. |
| [o4 0x715E78](../recomp/config/output_ovl/o4/o4_00715E78_0x715e78.cpp) | `initialize_rc4_identity_permutation_and_mix_repeating_key` | Confirmed complete256-step state/key loop; argument validity and cipher proof partial | a0 state needs408hex bytes,a1 key-byte count,a2 key. Zeros state i/j, initializes all256 u32 entries to0..255 via backward255..0 store loop, then performs256 forward swaps: j=(j+S[i]+key[keyindex])&255; keyindex resets only when increment equals a1. No empty-key/null/negative-length admission. For a1=0, it still reads successive key bytes rather than treating an empty key as a safe no-op. Initial entry and post-body decrement establish exactly256 iterations in each loop. |
| [o4 0x715F10](../recomp/config/output_ovl/o4/o4_00715F10_0x715f10.cpp) | `get_owned_rc4_implementation_label` | Confirmed complete literal-pointer return | Returns77E988; owned NUL-terminated text is `rc4(i f)`. Does not select a cipher, run a transform or validate a key. No direct incoming edge in current catalogue, which does not prove unused. |

## Loop and malformed-input limits

715DB8 begins by testing the full byte count for zero. It increments i once before entering the byte loop, preloads the next S[i] during each iteration and saves `(next_i-1)&255` at completion. Those prefetch/index details do not imply an extra output byte. The count decrement is64-bit and the exit tests nonzero, with no positive-range admission; the ordinary finite byte-count interpretation assumes a nonnegative valid count and adequate buffers.

715C10's ordinary expansion assumes1..128 key bytes and an effective-bit range for which its selected stack indices remain valid. Key length0 is not rejected: expansion starts at byte0 and loads the preceding stack byte. Effective bits beyond the ordinary1..1024 domain are not clamped before derived indices and variable shifts. These static missing checks are not a reproduced fault or proof that callers pass malformed arguments. Adapter702D70 supplies key length and an optional effective-bit value; its own application-field admission is documented separately. The128-byte key workspace is not explicitly scrubbed at return.

715E78 writes state+8 through+404hex inclusive; the complete state footprint is408hex bytes. Adapter702E98 places this after its10hex-byte cached-key prefix, matching its418hex private workspace. The primitive's408hex footprint should not be confused with the adapter's full workspace or its allowed key lengths.

## Complete owned RC2 expansion permutation

77E860..77E960 contains256 bytes, each value0..255 exactly once, SHA-256 `ef39c5a882f9477b2a250ba257247825ceb07fc53c3c984385f2c2e5f8222431`. All bytes were read in original order. This data is not256 additional functions and permutation completeness is not a standard-equivalence proof.

```text
D9 78 F9 C4 19 DD B5 ED 28 E9 FD 79 4A A0 D8 9D
C6 7E 37 83 2B 76 53 8E 62 4C 64 88 44 8B FB A2
17 9A 59 F5 87 B3 4F 13 61 45 6D 8D 09 81 7D 32
BD 8F 40 EB 86 B7 7B 0B F0 95 21 22 5C 6B 4E 82
54 D6 65 93 CE 60 B2 1C 73 56 C0 14 A7 8C F1 DC
12 75 CA 1F 3B BE E4 D1 42 3D D4 30 A3 3C B6 26
6F BF 0E DA 46 69 07 57 27 F2 1D 9B BC 94 43 03
F8 11 C7 F6 90 EF 3E E7 06 C3 D5 2F C8 66 1E D7
08 E8 EA DE 80 52 EE F7 84 AA 72 AC 35 4D 6A 2A
96 1A D2 71 5A 15 49 74 4B 9F D0 5E 04 18 A4 EC
C2 E0 41 6E 0F 51 CB CC 24 91 AF 50 A1 F4 70 39
99 7C 3A 85 23 B8 B4 7A FC 02 36 5B 25 55 97 31
2D 5D FA 98 E3 8A 92 AE 05 DF 29 10 67 6C BA C9
D3 00 E6 CF E1 9E A8 2C 63 16 01 3F 58 E2 89 A9
0D 38 34 1B AB 33 FF B0 BB 48 0C 5F B9 B1 CD 2E
C5 F3 DB 47 E5 A5 9C 77 0A A6 20 68 FE 7F C1 AD
```

The separate nine-byte77E988..77E991 string including NUL has SHA-256 `a38f02e79ad1aa8950d158ee0e62621bda05b544d833a7c44ff0d85d6eb89fe5`. Adjacent RSA path/OID bytes have not been assigned to this getter.

## Validation

Four independent rows,189 original instruction comments, complete aligned catalogue intervals checked against owned bytes; no conflicting or omitted nonzero words. Local links resolve. This is static role documentation, not a cipher test or a change to runtime behavior.
