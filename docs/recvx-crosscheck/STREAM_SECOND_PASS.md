# Stream and DTX second-pass comparison

Static File #1 US review, 2026-11-05. Reference: clean
`AshfordFamily/recvx-decomp` at `657b0c0c9489943116c71f151804ad7304fca975`;
Outbreak ELF SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
No game, stream operation, compiler, RPC, target process or native replacement
was run. The pinned C source is comparative evidence; its upstream byte-matching
comments were not independently tested against a Code Veronica executable.

## Corrections to our notes

Several byte sizes mixed hexadecimal literals with decimal-looking prose. The
earlier SJRB notebook even said that byte-count prose was decimal while a row
said its destructor cleared a40-byte object. That was misleading. Original
instructions establish these exact sizes:

| Object / operation | Correct decimal size | Original evidence |
| --- | ---: | --- |
| SJUNI object, including destructor1401A8 | 48 bytes (0x30) |1401C4 supplies ADDIU a2,zero,0x30 to the clear routine. Pool64*48=3072 bytes (0xC00). |
| Outbreak SJRB object, including destructor13F998 | 64 bytes (0x40) |13F9B8 supplies ADDIU a2,zero,0x40. Pool256*64=16384 bytes (0x4000). CVX's older ring object is48 bytes under its32-bit PS2 source layout. |
| DTX context, including destructor139110 | 68 bytes (0x44) |139164 supplies ADDIU a2,zero,0x44. This agrees with the context stride, not44 decimal bytes. |
| DTX create RPC request | 16 bytes (0x10) | Four32-bit request words; the earlier send10bytes shorthand was hexadecimal without a radix marker. |
| DTX trailing footer / length reduction | 64 bytes (0x40) | Constructor separates total transfer size from payload length and the final64-byte line. |

The authoritative [SJUNI](../SYMBOLS_CRI_SJUNI_LINKED_CHUNK_POOLS.md),
[SJRB](../SYMBOLS_CRI_SJRB_POOL_AND_CHUNK_OWNERSHIP.md), and
[DTX](../SYMBOLS_CRI_DTX_TRANSFER_CONTEXT_AND_ACKNOWLEDGEMENT.md) rows now use
explicit decimal/hexadecimal forms for these byte quantities. Their proposed
function roles were retained. No generated/native implementation was modified.

## Previously missing exact interface-identifier evidence

The first pass said that binary identity of the UUIDs had not been established.
It can now be established from the source initializer and the owned ELF bytes.
Packing the pinned source fields as the PS2 little-endian UUID layout
`<IHH8B` produces:

| Identifier | Outbreak address | Exact sixteen bytes, hexadecimal | Result |
| --- | --- | --- | --- |
|CVX sjrbf_uuid |23DA58 |`819e9a3bbb0dd211a6bf444553540000` | Identical. |
|CVX sjuni_uuid |23DA78 |`a34f532e97afd211a5270060089448bc` | Identical. |

Both constructor/getter/vtable paths independently bind those bytes to their
Outbreak stream type. This strengthens the shared middleware-interface evidence.
The SJRB record size, pool capacity, transfer counters and error callback offsets
still differ. A shared UUID is not proof that an object can be cast to the older
CVX structure or replaced with its implementation.

Reference source: pinned [SJUNI](https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/cri/mwlib/ee/lib/libadxe/sj_uni.c)
and [ring](https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/cri/mwlib/ee/lib/libadxe/sj_rbf.c).

## Additional supported correspondences

The refreshed curated crosswalk adds thirteen existing Outbreak entries: SJUNI
initialization/release/UUID/error registration; SJRB initialization/release,
destruction, UUID/error registration/backing-pointer access; and DTX Close plus
its two default callbacks. These add comparison coverage, not thirteen newly
recovered Outbreak functions.

In particular, main138EA8's counter matches the pinned `dtx_def_rcvcbf` role
through its installed receive-completion slot. Main138EC0 matches the default
send callback: fill with0xAA, format the owned `Hello from EE (%d)` string,
increment a separate counter. The string formatting has no local output-size
argument. These callbacks are defaults; application-installed callbacks can do
different work. The earlier caller-supported acknowledgement-counter mapping
was supported, rather than contradicted, by this comparison.

Main138F60 matches CVX `DTX_Close`'s clearing of callback/context pairs. It does
not wait for acknowledgement, deactivate the context, destroy its remote peer
or prevent later service from invoking a cleared callback. Outbreak's actual
destruction/wait contract remains the separate139110 operation. Similar names
must not collapse these lifecycle operations.

Pinned [DTX source](https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/cri/mwlib/ee/lib/libadxe/dtx.c)
and [header](https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/include/cri/mwlib/ee/lib/libadxe/dtx.h)
provide the comparative API spellings. They do not prove original Outbreak
public symbol names or host portability.

## Important differences were retained

- Outbreak's signed work-size division in SJUNI_Create differs from CVX's
  unsigned conversion. SJUNI_Reset still initializes the first node even when
  the supplied count is nonpositive; neither comparison admits arbitrary input.
- SJUNI's peek writes the full first-span length; a non-splitting mode requires
  an exact match. GetChunk in that mode accepts a request at least as large as
  the full span. Ring peek instead bounds the grant by request/availability.
- Outbreak's ring adds four acquisition/return totals and moves the error
  callback fields. Its Unget mismatch can report an error and still subtract
  from a total. The CVX ring has no corresponding totals to update.
- Both ring peeks can return1 for an invalid selector when the request is0,
  after a returning error callback, because grant0 equals request0. This is not
  evidence that the selector is valid or that a host implementation should add
  an undocumented admission rule while claiming parity.
- Outbreak DTX gates new submission on both its per-context enabled byte and a
  global gate. Teardown clears enabled and services all contexts until inflight
  clears. The pinned CVX version sends whenever its wait flag is0 and tears
  down immediately. Missing acknowledgements and sequence wrap remain separate
  unresolved runtime questions; no stall was observed in this review.

## Audit boundary

Run [stream_second_pass.py](stream_second_pass.py) with `--reference` pointing to
the clean pinned checkout. Its [receipt](../../build-function-index/recvx-stream-second-pass.json)
hashes eight reference C/header files, checks both UUIDs and the three original
byte-size instructions, and verifies 52 complete Outbreak catalogue intervals:
1430 instruction-comment words,21 omitted zero/NOP words, zero conflicts and
zero omitted nonzero words. This includes the original rows in the three
stream notebooks and the two default DTX callback bodies. The interval count
is an integrity-audit scope, not a claim that every row has a CVX counterpart;
for example, the separate tagged-media writers are not assigned a CVX alias.

No claim of binary equivalence, race freedom, performance cost or native
replacement correctness follows from these static checks.
