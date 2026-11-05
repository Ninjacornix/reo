# Recovered container digest and bounded record extraction

Static File #1 US, 2026-11-05. Owned o4/runtime5/base6E0000, image SHA-256
`8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16`.
Five complete logical bodies were reviewed through clear entrances,614 recovered
payload words and clear restore/return paths. The [copied-data inventory](STATIC_DNAS_UPPER_RECOVERY_INVENTORY.md)
retains every actual selector, exception offset and exact original-byte restore.
No recovered code was executed. No game, network, build, attachment, live memory,
owned-input change or generated/runtime-code modification occurred.

| Guest entry / original source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x74DB58](../recomp/config/output_ovl/o4/o4_0074DB58_0x74db58.cpp) | `derive_thirty_two_bytes_from_digest_of_256_byte_input_and_236_byte_suffix` | Confirmed complete reconstructed byte/control flow; exact digest identity inherited | Calls74C6C8(input,256,SP0), then74C6C8(input+20,236,SP20). Publishes32 bytes: all20 bytes of the second digest, followed by first12 bytes of the first digest. Overwrites each20-byte scratch with scaled-LCG bytes, executes actual protected-span restore, returns0. No NULL/size/overlap admission or normalized digest status check. |
| [o4 0x74DDC8](../recomp/config/output_ovl/o4/o4_0074DDC8_0x74ddc8.cpp) | `decode_shared_64k_container_and_extract_bounded_record_then_overwrite_workspace` | Confirmed complete reconstructed lifecycle/data flow; provider/container identity partial | Copies65536 input bytes into global7F22A8. Derives162-byte parameters via74D760, invokes74CCB0(global+FC00,128,parameters,162,SP0,128,&length), requires nonnegative status and length112. Copies SP20[80] over global prefix, transforms64512 bytes in place through74C1F0 using four8-byte regions atSP0. Calls74EF18(output,1024,produced*,global+F800,1024,originala1,76BDA0), returns0 for its nonnegative result, else-1. All normal paths overwrite global65536 plus scratch128/162 bytes before code restore. Global workspace is not read from the game; its offsets come from instructions. |
| [o4 0x74E830](../recomp/config/output_ovl/o4/o4_0074E830_0x74e830.cpp) | `decode_private_1024_byte_container_prefix_and_publish_forty_and_thirty_two_byte_slices` | Confirmed complete reconstructed lifecycle/data flow; record purpose unresolved | Copies input[0:1024] toSP80;74D760 derives162 bytes atSP480. Provider74CCB0 reads128 bytes from original input+FC00, requires produced112, then copies SP20[80] over private prefix.74C1F0 transforms1024 private bytes in place. On success copies40 bytes from decoded prefix+128 to originala2 and32 from decoded prefix+168 to originala1; result0, otherwise-1 without those publications. Always overwrites scratch128/private1024/parameters162 through1314 LCG calls, then restores code. Original input extent is larger than the copied1024-byte prefix. |
| [o4 0x74EF18](../recomp/config/output_ovl/o4/o4_0074EF18_0x74ef18.cpp) | `decode_two_stage_block_record_extract_big_endian_length_and_shift_payload_to_output_start` | Confirmed complete reconstructed data/control flow; arbitrary-input admission partial | Args output,capacity,produced*,cipherInput,inputLength,key32Input,keyParameter. Requires unsigned capacity>=inputLength; derives32 bytes via74BCE0(key32Input,keyParameter,SP0,4blocks).74C1F0 decodes inputLength>>3 blocks to output using scratch parameters. Second in-place call operates atoutput+32 for((inputLength-32)>>3) blocks using four8-byte output prefixes.74EEE8 stores BE32(output+32) through produced*. Requires capacity>=produced+40, then shifts produced bytes from output+40 to output0; zero produced skips copy. Success0, errors-1. Always overwrites32 scratch bytes and restores code; produced/output may already be modified on failure. No local minimum input32, alignment or parsed-length-versus-input check. |

Additional complete logical owner:

| Guest entry / original source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x74EBC8](../recomp/config/output_ovl/o4/o4_0074EBC8_0x74ebc8.cpp) | `decode_11264_byte_prefix_shift_10240_byte_record_and_extract_in_place` | Confirmed complete reconstructed lifecycle/data flow; container purpose unresolved | Args input,workspace,produced*. First copies11264 bytes to workspace before any provider-status gate.74D760 derives162 bytes;74CCB0 reads input+FC00[128], requires produced112, copies SP20[80] over workspace prefix.74C1F0 transforms11264 bytes in place using provider output slices as parameters. Forward-copies10240 bytes from workspace+200 down to workspace0. Then74EF18(workspace,10240,produced*,workspace,10240,76BDA8,76BDA0) extracts in place. Nonnegative child status maps0, else-1. Always overwrites128/162 scratch bytes and restores code; workspace and produced pointer can already be modified on failure. |

Decimal sizes are stated as numbers; addresses and offsets with alphabetic
digits or `SP` notation are hexadecimal. In particular FC00=64512 and
F800=63488. The source catalogue cuts some bodies inside their payloads;
the rows credit normal logical entrances, not the skipped data or interior cuts.
Underlying [digest/padded-provider contracts](SYMBOLS_NETDNAS_UPPER_DIGEST_AND_PADDED_OPERATION.md),
[fixed162-byte parameter derivation](SYMBOLS_NETDNAS_RECOVERED_SLICE_DIGEST_AND_FIXED_RECORDS.md)
and [block-session adapters](SYMBOLS_NETDNAS_OPAQUE_BLOCK_SESSIONS.md) retain
their own limitations. No standard hash, cipher, signature format or security
guarantee is inferred from byte sizes alone.

## Exact publication and cleanup boundaries

74DB58 reverses the order of its two digest products when assembling output:
suffix digest first, whole-input digest second. The12-byte tail is a truncation
of the whole-input digest, not a third hash. It ignores the digest helper's
unnormalized return register. The two input extents end at the same input+256.
The two scratch overwrites each perform20 stores; the returned integer0 is
assigned only after the actual code restore.

74DDC8 copies its entire64KiB input before testing the parameter-provider
result. Its provider input at global+FC00 is801EA8. The80 copied decoded bytes
come from SP20, while SP0..SP1F supply block-session parameter slices. The
three-parameter update count1F80hex means64512 bytes after the child multiplies
by8. It subsequently gives the record decoder the1024 bytes beginning at
global+F800. Any negative child status or produced-length mismatch joins the
same three cleanup loops. There are65826 local-LCG calls on normal paths,
including failure paths. This is a static count, not measured timing or a
slowdown attribution; execution frequency and surrounding serialization are unknown.

74E830 copies the container prefix to private stack storage rather than the
shared64KiB global. Its provider still reads original input+FC00. Successful
publication occurs only after the1024-byte block operation succeeds. It writes
the40-byte originala2 output before the32-byte originala1 output; aliasing can
therefore affect the final arrangement. On failure, local cleanup does not
transactionally clear caller outputs. Pointer capacities and aliases are not
validated locally.

All overwrite loops use the same reviewed74AA20 local LCG, float division by
bits4EFFFFFF, multiplication by256, guest CVT.W.S and explicit2^31 correction,
then low-byte stores. Calling this secure erasure or a cryptographic random
generator would exceed the evidence. Frame/register restoration and code
restoration were read in each clear epilogue; neither was invoked here.

## Record decoder length and width details

74EF18 preserves original output capacity and input length in guest registers.
The first provider count is a logical right shift of input length by3. The
second count uses the original32-bit ADDIU(inputLength,-32) then logical shift3;
short or unaligned values are not repaired by this mapping.32-bit address
formation and register-width unsigned comparisons remain original contracts.

Its clear support helper74EEE8..74EF18 is absent from this catalogue, so it
receives no additional mapping row. All12 original words were read directly:

```text
90A60001 90A20000 90A30002 00063400 90A70003 00021600
00031A00 00471025 00661825 00431025 03E00008 AC820000
```

They load four unsigned bytes from argumenta1, assemble big-endian32 bits and
store the result through argumenta0 in the return delay slot. The helper does
not decode an eight-byte length or validate its input. The decoder calls it
with output+32 and the caller's produced pointer before checking capacity
against the resulting length+40. That final addition is also the original
32-bit operation; no overflow rejection is added. The check uses capacity,
not decrypted input length. Shifting payload bytes toward lower addresses is
forward byte copying with input at+40, not a general memmove contract.

On earlier errors the produced pointer may remain unchanged; on a later error
it can contain the decoded length. No failure-path zeroing is present. The
32-byte key scratch is overwritten on every normal path even when the first
capacity check rejects the request. A recovered shape is not unrestricted
host-library equivalence or proof of safe arbitrary inputs.

## Reconstructed payload fingerprints

| Payload, end exclusive | Words | SHA-256 |
| --- | ---: | --- |
| 74DBE4..74DD4C | 90 | `7fdc92b79dbbc5a005de1e8941e1c95d2d2d8418924a2ca2e85bc0ec3ec4a696` |
| 74DE68..74E0DC | 157 | `13d5e784ca9ad452635d9eb766fd1d03857d3a50d24bf1114fc4c20e1435e31c` |
| 74E8C8..74EB44 | 159 | `269069cfc68526966f7eccd48a606ac7dce7741f279d49d4fdc1fe256b5e823b` |
| 74EFD4..74F10C | 78 | `8e24c12db13dc2f563e77a3be07df0ef0d7fa486c2c4dc6e98d1c630800ed3a8` |
| 74EC5C..74EE64 | 130 | `d9cb0af075402e41026549b548ecd7d97aa5d23501eea5da081104c3a3489a92` |

All actual forward schedules reproduce their original encoded words, preserving
the original exception lists. Reproduce with
`python tools/function_index/recover_dnas_upper_inventory.py`. The original
generated-source graph remains unchanged; apparent edges from encoded/skipped
bytes are not caller evidence. Runtime admission, frequency and outcomes remain
unknown, and no native replacement or fix/retest is claimed.

The [portable connected-word checker](../tools/function_index/review_dnas_upper_root.py) rebuilds the full admitted word listing, original joined-interval hashes and bounded branch targets; inline data is excluded from instruction decoding. Its private receipt is data evidence, not a guest execution or semantic-equivalence test.
