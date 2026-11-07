# Native sound RPC refusal identity

Public patch `0127-identify-native-sound-rpc-refusals.patch` adds bounded identity
logging at existing native sound refusal sites. It does not change request
coverage, guest reads/writes, completion or fallback. It is investigation
infrastructure for the unresolved V11 `read/unsupported` diagnostic, not its fix.

The outer RPC path reports reason, SID, RPC, client, send address and mode for
uncovered requests or rejected server/metadata geometry. The direct service
entry reports SID/RPC/send, with zero sentinels for unavailable client/mode.
Each site logs at most eight lines per process, using a saturating atomic
reservation. Existing diagnostic counters and refusal status remain intact.
No device render callback logs are introduced.

The authoring tool verifies all source/patch identities from the complete
127-patch receipt and edits only a new ignored author tree. The active dirty
submodule remains untouched at its recorded upstream base. All 128 patches
then apply to another fresh independent checkout. V1/V2 published API layouts
remain unchanged; an actual matching rebuilt runtime is still required.

Both GCC and LLVM pass unchanged prior wire/PCM/bank expectations and 32 sound
capture scenarios, including the retained two negative ordering controls.
An additional single-owner test performs 40 refused calls and verifies exactly
16 identity logs: eight at each direct/outer uncovered site, no RAM access or
completion effects. The earlier attempt repeated whole test-owner setup; that
harness lifetime assertion failed after its first pair. Its failed output and
source are retained. V2 repeats calls on one installed owner instead.

All five actual matching SDK objects compile under both compilers: RPC,
CriAudio, ReoSoundBanks, runtime and SIF. These are compilation results, not
linked-runtime or game evidence. The exact adapted verifier bytes are retained;
adaptations change patch counts, isolated destinations, reverse-patch checking
and explicit standard headers, without changing old expected wire results.

| Receipt below `build-native-sjuni` | SHA-256 |
| --- | --- |
| `dependency-sound-diagnostic-reapply-v1-receipt.json` | `54fd56882784fba8cdea3e7a35c33ed443298b10565b2a42aa0b7a2eaad4a43b` |
| `sound-rpc-diagnostics/companion-llvm-v2/diagnostic-receipt.json` | `ea5c3c2ee40a2bb8798cc85c6fe75ec3658188f5c405f9a3a15918b9600dfe51` |
| `sound-rpc-diagnostics/companion-gcc-v2/diagnostic-receipt.json` | `bd2280d903d5ec37d0855498951140046f57ed8fb375d0209d8fd224db423e83` |
| `sound-rpc-diagnostics/objects-llvm-v1/diagnostic-receipt.json` | `bc78dd7338c58a33533483ce70f9ad4b7108a1a9deb039274e3e9d72d3abc634` |
| `sound-rpc-diagnostics/objects-gcc-v2/diagnostic-receipt.json` | `e582b7b0357c92546fbbb5e3b893c9c080cf798ed8d05bab5cfa590a80ab368e` |

The LLVM object receipt predates the repeated-call harness correction; its
driver snapshot is `sound-rpc-diagnostics/driver-v1.py`. SDK source/patch bytes
are identical across all these checks. The next game test must identify the
actual refusal before expanding coverage or claiming it harmless. Stage 3
remains open.
