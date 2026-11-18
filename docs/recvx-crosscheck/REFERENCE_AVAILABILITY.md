# Reference availability and platform startup boundary

Static review, 2026-11-05. The original Code Veronica source checkout remains
clean at `657b0c0c9489943116c71f151804ad7304fca975`; Outbreak is owned File #1
US ELF SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
No reference executable was supplied or built. No game, module, SDK service,
target process, cache instruction or runtime operation was executed.

## Unavailable implementations are explicitly retained

The comment/literal-aware full inventory finds definitions missed by the earlier
lexical screen, including multiline/no-return-type debug skeletons. A nonempty
brace body is not sufficient evidence of an implemented algorithm. In particular:

- Five top-level IOP sound files contain 46 empty debug-metadata definitions.
  Original address/size comments are reference metadata, not Outbreak addresses
  or reconstructed instructions. Some size comments describe large routines;
  their empty braces do not establish that the originals were no-ops.
- `src/users/oshimi/adx/sjr.093/sjr_svr.c` contains 13 SJRMT server definitions
  with empty bodies or local declarations only. They supply names/signatures,
  not the missing queue-operation implementations. The separately owned
  Outbreak IOP module remains the actual behavioral evidence for its server.
- `src/ps2/veronica/prog/ps2_cri_adxt.c` contains an empty alternate
  `ADXT_Pause`. A same-named implemented function exists in the other CRI tree;
  source selection and version identity must remain explicit. This empty
  alternative does not override the complete audio comparison.
- All 223 `INCLUDE_ASM` entries are recorded individually, including their
  declaring source hash, line, requested assembly directory and same-named C
  definitions elsewhere. Their expected assembly bodies are absent. An older
  named C counterpart does not prove that these alternate binaries match it.

Together the first three categories have 60 individually bounded definitions;
the 223 assembly placeholders are separate entries, not additional implemented
C functions. They are availability results and receive no mapping credit.

Two graphics helpers inside `sub1.c` were carved out of the otherwise
game-specific inventory UI. `Ps2ZbuffOffI` builds a GS TEST_1 packet in the CVX
WORKBASE scratch path; `Ps2DrawOTagI` performs two 4096-bucket OT passes with CVX
depth/texture globals. Their complete source bodies were read and recorded as
CVX ownership boundaries, without assigning an Outbreak counterpart. The
availability receipt therefore contains 62 definition records in total.

## SDK and libc callsites do not supply SDK and libc bodies

The entire pinned source inventory was queried for 35 exact external identifiers,
including memcpy/memset/malloc/free, standard formatting and math, GCC numeric
primitives, sceMc file operations, scePadRead, sceMpeg decoding, SIF RPC, disc
clock reading and thread/alarm/semaphore operations. None has an implementing
definition in this checkout. The receipt lists every query.

This is a bounded source-availability result, not proof that Code Veronica does
not use the libraries or that an implementation cannot exist under another
spelling or in an external binary. Its callers and GCC adapter source are useful
for ABI and workflow comparison; they cannot establish Outbreak's actual kernel,
software-floating-point, C library, MPEG decoder or controller backend bodies.
The [platform ledger](PLATFORM_COMPLETE_SCOPE.md) preserves those distinctions.

Outbreak's SN@P/SNIOP, HTTP/security/DNAS, libmc2/libdbc/libpad2 and substantial
private Sofdec/MPEG implementation also require independently identified bodies
before a function-to-function CVX comparison can be claimed. The actual shared
CRI and movie-buffer subcomponents have their own separate complete ledgers.

## The available assembly startup source was compared

`src/sce/ee/lib/crt0.s` is the only assembly source under the reference `src`
tree. The complete file was inspected against Outbreak100008/100218 and the
thread-root entry at100220:

| Contract | Supported correspondence and difference |
| --- | --- |
| Main-thread and heap initialization | Both startup paths use selectors0x3C and0x3D and install GP/SP before entering application code. Game-specific addresses, stack/argument storage and called init functions remain separate. |
| Register/BSS setup | Outbreak explicitly zeroes integer/FPU state and handles byte edges around aligned BSS stores. The reference shows a simpler quadword BSS loop. No equality of zero-length/end-pointer behavior is asserted from linker symbol names. |
| Exit adapter | The reference `_exit` sets a0=0 before Exit. Outbreak100218 preserves the incoming argument before its own exit target. The existing descriptive tail label correctly avoids asserting the zero-argument contract. |
| Thread root | Both use selector0x23. The Outbreak catalogue interval starting100220 additionally contains a distinct adjacent CDVD callback-registration entry at100230; the startup match does not merge their purposes. |

No new original public symbol or standalone function boundary is promoted by
this comparison. The current startup and embedded-entry annotations remain
qualified by their own complete instructions.

Reproduce with
`python tools/function_index/review_recvx_reference_availability.py --reference PATH`.
The [helper](../../tools/function_index/review_recvx_reference_availability.py)
and [receipt](../../build-function-index/recvx-reference-availability.json)
retain all 62 definition dispositions, 223 placeholder records, 35 external-body
queries, source identities and the three complete owned startup interval audits.
