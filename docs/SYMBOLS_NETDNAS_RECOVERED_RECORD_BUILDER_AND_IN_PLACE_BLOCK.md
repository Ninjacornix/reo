# Recovered block-record builder and fixed in-place header operation

Static File #1 US review, 2026-11-05. Owned o4/runtime5/base6E0000,
SHA-256 `8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16`.
Two complete logical bodies were read through their clear entrances,329
reconstructed words and restore/return paths. Their actual metadata restores
the copied words exactly in the [upper inventory](STATIC_DNAS_UPPER_RECOVERY_INVENTORY.md).
No guest code was executed and no game, network, build, attachment or
owned/generated/runtime-input change occurred.

| Guest entry / original source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x74F1D0](../recomp/config/output_ovl/o4/o4_0074F1D0_0x74f1d0.cpp) | `build_aligned_payload_record_through_staged_block_providers_and_overwrite_workspace` | Confirmed complete reconstructed control/byte flow; format and provider algorithms partial | Args output,capacity,produced*,payload,payloadLength,keyInput,input8,keyStructure32,stack0 keyParameter,stack8 low-byte flag. Allocates align16(capacity) stack workspace before capacity admission. For ordinary counts requires capacity>=align8(payloadLength)+24; insufficient capacity writes produced0 and returns-1 after cleanup. Accepted route generates16 header bytes, modifies headerbyte0 by4*byte+flag, runs74F1A0 to produce the next8 bytes, copies payload, derives32-byte parameters, transforms/reorders blocks and applies fixed-derived parameters. All stages must return nonnegative for result0; errors-1 can leave partial output. Always overwrites workspace[capacity] and two32-byte scratch areas, restores protected code and stack frame. |
| [o4 0x74FD38](../recomp/config/output_ovl/o4/o4_0074FD38_0x74fd38.cpp) | `transform_thirty_two_bytes_in_place_using_derived_eight_byte_and_fixed_parameters` | Confirmed complete reconstructed local/provider flow; mathematical operation partial | Derives8 scratch bytes with74BCE0(76BF78,76BF70,SP0,count1). Nonnegative result runs74C168(originala0,SP0,sameoriginala0,76BF70,count4), transforming32 caller bytes in place through the reviewed count-times8 adapter. Nonnegative final status maps0; either negative child status yields-1. Always overwrites8 scratch bytes via scaled localLCG, calls actual code restore, then returns saved result. No caller extent/NULL/alias/rollback guard or algorithm/direction guarantee. |

## Builder arguments and allocation

The builder preserves its fixed frame in FP, allocates a second stack area
using the original32-bit ADDIU/SRL/SLL alignment sequence, and records both
stack pointers before decoding. The ninth argument is read from originalSP+0;
the final flag byte is read from originalSP+8. The required size is computed by
32-bit add7, logical shift3, shift3 and add24. For admitted ordinary nonnegative
counts this is align8(payloadLength)+24. Arithmetic overflow, sign-extended
values and arbitrary64-bit host sizes are not normalized by this mapping.

It writes required size through the produced pointer before comparing capacity.
On insufficient capacity it replaces that word with0, initializes the second
cleanup pointer and joins cleanup with result-1. Even this route has already
performed dynamic stack allocation. No stack/capacity limit is enforced here.

## Accepted construction route

1. Generate8 bytes at workspace0 and8 at workspace8 through74AA20's float-scaled
   low-byte loop. Replace workspace byte0 with the low byte of4*oldByte+flag.
   The flag is not masked to two bits locally.
2. Call74F1A0(workspace+16,input8,keyStructure32). The existing clear adapter
   expands to74BF98(input8,key+0,key+8,key+16,workspace+16,key+24,count1).
   This is an opaque one-block provider operation, not raw metadata packing.
3. Copy payloadLength bytes to workspace+24. No explicit initialization of the
   align8 padding after the payload appears in this body. Zero payload skips
   this copy. Successful count/formula assumptions do not prove padding contents.
4. Derive32 bytes at FP0 with74BC58(keyInput,ninthArgument,FP0,count4).
   Transform workspace+8 in place through74BF98 using FP18/FP8/FP10/FP0 as
   the literal parameter order and count(produced-8)>>3. All mentioned FP
   offsets are hexadecimal.
5. Publish output0..7 from workspace0..7; publish align8(payloadLength)+8
   bytes at output+8 from workspace+16; place8 bytes from workspace+8 at
   output+align8(payloadLength)+16. These operations preserve the original
   block rearrangement rather than assuming a conventional header layout.
6. Call74C108(output+24,output,output+16,output+24,output+8,
   (produced-24)>>3). The clear adapter's repeated arguments and parameter
   remapping remain the [recorded block-session contract](SYMBOLS_NETDNAS_OPAQUE_BLOCK_SESSIONS.md).
7. Derive32 bytes at FP20 from76BF48 using76BF68 through74BC58(count4).
   Transform output+8 in place through74BF98 with FP20/FP30/FP28/FP38
   parameters and count(produced-8)>>3. Nonnegative status selects result0.

Every negative child result selects-1 and joins the same cleanup; there is no
transactional output rollback. The produced word usually retains the required
size after provider failure. The workspace overwrite uses the original capacity,
not just the required size. It is skipped only when capacity is zero. The two
32-byte scratch overwrites run even when their data was never initialized on an
early failure path. These are writes, not reads of uninitialized scratch.

Each overwrite uses74AA20, float divisor bits4EFFFFFF, multiplier256, guest
CVT.W.S and the original2^31 correction before storing a low byte. The builder
then invokes its actual protected-span restore, restores both stack levels and
the saved registers/F20..F22. No native allocation, cache operation or call to
these guest helpers was made for this review.

The required-size calculation matches connected payload wrappers'40/56/32/40
byte outputs for16/32/5/9 byte inputs in
[query/payload adapters](SYMBOLS_NETDNAS_RECOVERED_QUERY_PAYLOAD_AND_FILE_ADAPTERS.md).
That relation corroborates the local data flow without proving an original
cipher mode, protocol name, padding rule or cryptographic property.

## Fixed in-place operation and fingerprints

74FD38 stages exactly8 bytes, then invokes its second provider on32 caller
bytes. It does not just validate a header: the caller's buffer can change.
Early child errors retain any already-written output. Its scratch overwrite
does not undo those writes. This matters to the connected
[file-trailer check](SYMBOLS_NETDNAS_RECOVERED_FILE_TRAILER_CAPTURE_AND_LENGTH_CHECK.md),
which compares trailer bytes only after this operation.

| Reconstructed payload, end exclusive | Words | SHA-256 |
| --- | ---: | --- |
| 74F2B0..74F714 | 281 | `3c8d3d54c3b975a4392e74082fddb5bcc3d9857016d3ea5807ff0d0811d65e17` |
| 74FDC4..74FE84 | 48 | `0fa2b0c49c82b51eadb14e9a8b55939296151d7c32591b324d319943a970c8e1` |

Reproduce the copied-word evidence with
`python tools/function_index/recover_dnas_upper_inventory.py`. Original source
prefix audits do not substitute for joined-body review; internal catalogue cuts
and skipped metadata receive no additional rows. Output/produced/payload/key
aliasing, input capacities, concurrency and runtime admission remain unresolved.
No translated native implementation, security result or performance fix is claimed.

The [portable connected-word checker](../tools/function_index/review_dnas_upper_root.py) rebuilds the full admitted word listing, original joined-interval hashes and bounded branch targets; inline data is excluded from instruction decoding. Its private receipt is data evidence, not a guest execution or semantic-equivalence test.
