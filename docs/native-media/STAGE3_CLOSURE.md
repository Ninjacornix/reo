# Stage 3 closure checklist

Status: active work, starting at local commit `959d2198`. This is a gate checklist,
not a weighted percentage. Passing more isolated tests does not substitute for
consumer integration or game transition evidence.

The reconstruction plan requires matching resource loading/completion behavior,
audio/movie output and lifecycle transitions. Its first selected edition is
File #1 US. File #2 admission requires its own address/behavior validation.
Stages 4-6 remain separate; no runtime dependency is removed by this checklist.

| Required boundary | Existing evidence | Remaining closure work |
| --- | --- | --- |
| Native resource/PAK reads | Verified imported files/ranges, native mount/reader, bounded read owner, guarded synchronous game payload tests. | Include those same sources and selections in the final coherent candidate; retest loading, cancel/reopen, room/resource transitions and shutdown. |
| Compressed audio ownership | Native ADX codecs, header/window/refill, real source workers, ADXT Session, service clocks, regular loops and bounded LSC owners have separate comparisons. | Bind admitted consumers to the canonical native Session and actual service ordering; validate live loop/LSC, pause, replacement and source/output retirement. |
| PCM/bank/RAM output | V11/V12 prove complete-backend selection and joined retirement. V12 identifies the unsupported request as SID 1 / RPC 0x10; its candidate reply matches frozen full-memory results and both compilers' SDK object checks. | Link and retest that reply; validate combined native player/output routes across representative rooms and packet/bank domains. |
| Movie timing and video | Native clocks, controls, frames, lifecycle and timestamps have comparisons. All 201 File #1 movies decode/present 216,998 independently counted pictures on the GPU after rebuild. Pending service matches 515 original cases on both compilers. | Bind the logical/physical movie owner and service providers to game scheduling and source controls; qualify skip/recovery and error profiles. |
| Whole movie/audio behavior | Existing original/native historical opening runs; new owners have standalone and offscreen evidence. | Full-stream I/P/B, decode/reorder/skip, pause/resume/frame step, repeat/stop/rebuild, error/EOF and audible A/V validation through the selected native graph. |
| Coherent game integration | Separate earlier candidates validate narrower cuts; new media cores are not linked by those old binaries. | Build a fresh source/compiler/dependency-identified candidate, verify actual native handshakes/body execution, and run matched original/native media and resource transitions. |

Completion requires an evidence reference for every admitted boundary and an
explicit list of unsupported profiles. Unsupported required consumers cannot be
made successful by falling back after native effects, dropping frames/audio or
inventing completion. Existing controls must preserve original game speed;
diagnostics must not silently select experimental rendering or VU paths.

The timestamp and complete short-video gates have advanced beyond the earlier
first-frame boundary. All 201 hash-verified File #1 SFD members (2.26 GB) contain
no C0-DF or BD audio packets, so this edition's audio gate is its separate ADX
game-consumer route. Native embedded-audio demux is not substituted for that
actual integration requirement. The next work is broader video coverage and
logical/physical game scheduling, alongside separate ADX/output integration.
