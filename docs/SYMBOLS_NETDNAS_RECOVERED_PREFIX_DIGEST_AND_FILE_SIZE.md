# Recovered fixed-prefix, digest/provider comparison and file-size routes

Static File #1 US review, 2026-11-05. Owned o4/runtime5/base6E0000,
SHA-256 `8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16`.
Three connected logical bodies were read from their original clear envelopes
and reconstructed copied-data spans. All172 reconstructed words have exact
actual-selector restores in the [upper recovery inventory](STATIC_DNAS_UPPER_RECOVERY_INVENTORY.md).
The original generated source, catalogue intervals and inputs are unchanged.
No guest execution, network, game, build, attachment or runtime changes occurred.

| Guest entry / original source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x74E2E0](../recomp/config/output_ovl/o4/o4_0074E2E0_0x74e2e0.cpp) | `compare_context_digest_to_decoded_provider_output_then_overwrite_three_scratch_regions` | Confirmed complete reconstructed data/control mechanics; mathematical provider identity partial | Copies162 owned bytes76BEA0 into stackA0, calls74BCE0(stackA0,76BE98,stackA0,6). Negative result selects-1 and cleanup. Otherwise74C6C8(context,FCC0,stack0) computes20-byte candidate digest;74CCB0(context+FCC0,80,stackA0,A2,stack20,80,&stack150) invokes the reviewed128-byte provider route. Negative status or produced length!=14 selects-1. Produced length14 compares20 bytes atstack0/20 using74E1A8; equality returns1, mismatch0. All normal paths overwrite stack0[14],stack20[80],stackA0[A2] through310 scaled-LCG calls, then restore protected code and return saved result. Bounds, provider mathematics, exact digest standard and secure-erasure guarantees remain unproved. Sizes/offsets in this row are hexadecimal. |
| [o4 0x74E618](../recomp/config/output_ovl/o4/o4_0074E618_0x74e618.cpp) | `check_context_fc80_fixed_prefix_then_delegate_digest_provider_comparison` | Confirmed complete reconstructed comparison/delegate flow | Saved result starts0. Compares context+FC80 against32 owned bytes76BE78 through74E1A8. Nonzero comparison leaves result0; exact equality calls74E2E0(context) and preserves its-1/0/1 result through the actual code restore. No local NULL/extent check, proof that the32 bytes are a hash, or original API/field enum. |
| [o4 0x74F818](../recomp/config/output_ovl/o4/o4_0074F818_0x74f818.cpp) | `query_file_size_by_read_only_open_seek_end_and_close_with_error_retry` | Confirmed complete reconstructed file-RPC flow; device/provider semantics inherited | Calls118A70(path,1); negative fd returns-1 through code restore. Otherwise118E78(fd,0,2); negative seek takes close cleanup and keeps-1. Nonnegative seek is saved, then118CF8(fd). Nonnegative close commits saved seek as result and changes local fd to-1 so cleanup skips. Negative close leaves fd>=0 and cleanup calls118CF8 a second time, ignores its result, returns-1. No async flags are requested locally. File/device state and remote completion behavior remain inherited from the separately reviewed RPC adapters. |

The source catalogue splits the first two logical bodies at74E378 and74E6A0,
inside their reconstructed operations. The roles above cover the connected
normal entrances through their actual shared epilogues, rather than inventing
functions for every subsequent cut. Original source-interval audits and the
reconstructed-word proofs are separate evidence checks. Skipped metadata and
interior fragments receive no new role credit. The static graph still includes
encoded-source artifacts; those apparent call edges are not validated here.

## Digest/provider comparison, including all cleanup paths

The clear entrance saves the original context in S0, saves registers/F20..F22
and reserves1B0 stack bytes. A descriptor gate enters reconstructed74E370..74E594.
It copies exactlyA2 (162decimal) owned bytes before calling the fixed block
session adapter. The negative adapter-result branch explicitly initializes
S4=stack20 before joining cleanup. Its nonnegative branch computes the digest
atstack0 and selects the same scratch base before the provider call. Thus both
routes have all three cleanup-region pointers initialized; an error does not
skip the observed overwrite loops.

The digest uses the [reviewed20-byte block/padding contract](SYMBOLS_NETDNAS_UPPER_DIGEST_AND_PADDED_OPERATION.md),
including its unusual48-byte padding threshold. This caller does not prove
standard SHA-1 parity. The [fixed block session](SYMBOLS_NETDNAS_OPAQUE_BLOCK_SESSIONS.md)
and padded two-number provider remain their recorded mathematical candidates.
The block-session argument6 requests six eight-byte blocks (48bytes) of the
162-byte copied blob, not a mode number or a transformation of all162 bytes.
Neither that count nor the blob alone proves an RSA mode or signature format.

For a nonnegative provider result with output length exactly14hex/20decimal,
the bounded unsigned-byte comparison sets result1 iff equal, else0. Other
provider results select-1. No caller-output pointer is published by this body.

Each of the three overwrite loops calls74AA20, converts its returned word to
float, divides by float bits4EFFFFFF, multiplies by float bits43800000 (256),
then uses the original CVT.W.S sequence. Comparison against float bits4F000000
(2^31) selects the original subtract/convert/OR80000000 correction. Only the
low byte is stored. The loops overwrite20,128 and162 bytes respectively, even
on early provider failure. This is deterministic local-LCG-derived overwrite,
not a proven security primitive or an observed bottleneck. FP rounding and
endpoint behavior are retained as guest contracts.

The clear branch at74E594 skips metadata to74E5C4. The actual paired restore
is called at74E5DC; saved S5 supplies the return value after the call. The
epilogue restores F20..F22 and saved integer registers before returning at74E610.
The complete joined original interval74E2E0..74E618, including skipped data,
has SHA-256 `c5c20a67b5d7817cdc48c62ff3890341bcd4d13c78bec482e6d728435259a159`.

## Prefix and file-size details

The prefix wrapper's reconstructed12 words call the
[bounded comparison](SYMBOLS_NETDNAS_THREE_ZERO_KEY_RECOVERED_LOCAL_ROLES.md)
with length20hex/32decimal. Its S1 result starts0 and changes only if the prefix
matches and the child runs. The full joined interval74E618..74E728 has original
SHA-256 `2880f377cb1fcabb1a89a9580c475aff9a4dfccf54b2582525a90abfa82bcc90`.

The file-size route uses [resident file RPC](SYMBOLS_FILE_RPC.md), not a memory
length field or a platform-independent filesystem call. Its duplicate close
on the first close's negative result is literal control flow; it is not repaired
or diagnosed as a live bug here. A negative seek closes once and preserves-1.
Successful seek/close preserves the seek's original response value, without
converting it to a wider host size type. Code restoration occurs on every normal
return path in this local body. The joined74F818..74F95C interval, ending after
the return delay slot and before padding, has original SHA-256
`5319cc4ed71e1bf1dbe14ca2ee2546c1fe106ed21d8a7b2591fdd7a6ad71e258`.

## Owned data and reconstructed fingerprints

| Evidence extent | SHA-256 |
| --- | --- |
| Fixed prefix76BE78[32] | `06bf9183a358812b36e6380f19ef94eb92545ba7e92df780dd19672d04af6e87` |
| Fixed session bytes76BE98[6] | `7631f5c6931ad1b530425d1f22c3b53c852f6128665ead2804492607455b2d52` |
| Copied blob76BEA0[162] | `548ca312f2531b93ec80259d4062e7cbefd47c1648ab040dd7480992d6f7fbee` |
| Reconstructed74E370..74E594,137words | `68d70dda4811d44893bb4603549afa2d00c4cf9d9d57a1b1139870e162d1c38e` |
| Reconstructed74E68C..74E6BC,12words | `fd00abef117f4d4f2cbc546342d35de1ef15f9baadcc9d84c47e622e2b7beea9` |
| Reconstructed74F894..74F8F0,23words | `518ceeb37d515a30960c91cc3ba282e5388fb80dee6f687df4521593cd56d4be` |

Reproduce all copied-word arrays, original fingerprints, actual selector schedules
and preserved exception offsets with
`python tools/function_index/recover_dnas_upper_inventory.py`. Pointer admission,
aliasing, concurrent code/descriptor modification, remote I/O outcomes and
runtime reachability remain unknown. These mappings demonstrate no native
replacement, performance improvement or controlled fix/retest.

The [portable connected-word checker](../tools/function_index/review_dnas_upper_root.py) rebuilds the full admitted word listing, original joined-interval hashes and bounded branch targets; inline data is excluded from instruction decoding. Its private receipt is data evidence, not a guest execution or semantic-equivalence test.
