# Outbreak File #1 function mapping notebook

Status: static investigation, 2026-11-03. Proposed names below are descriptive
labels for research, not recovered original symbols or approved replacements.
No game, build, replay, benchmark, debugger attachment, or new capture was run
for this pass. Only this notebook was added; source, settings, generated code,
and Ghidra databases were not changed.

The subsequent [gameplay and graphics mapping pass](SYMBOLS_GAMEPLAY.md) covers
scenario/script dispatch, room loading, animation, camera/input, collision,
inventory, guest rendering submission, and prerecorded movie transport. Its
guessed names use the same confidence rules below.

## Identity and evidence limits

- Target: US Outbreak File #1, `SLUS-20765`, local `game_data/SLUS_207.65`.
- ELF SHA-256, checked in this pass:
  `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
- Checkout: `048ee6a43fb890f49ad7db4b7b8d79033c5dc5f4`, branch
  `fix/launcher-progress-overlay`, with existing uncommitted changes. That commit
  alone does not reproduce all inspected working-tree files.
- Main-ELF addresses are guest EE addresses. Overlay entries explicitly name their
  overlay; these mappings must not be transferred to File #2 or another revision.
- Evidence: instruction comments and emitted operations in existing generated
  sources; handwritten overrides; historical investigation notes; the previously
  completed session `20261103-210201-498`. Existing notes and comments can be wrong;
  their provenance is identified rather than treated as new measurements.
- Generated files can contain several adjacent leaf routines. A file's declared
  range is not proof of one semantic function. Branch delay slots, tail calls,
  recompiler resume entries, and indirect callback ABIs need independent checks.
- Prior Ghidra inspection found a generic-MIPS import with incomplete R5900
  decoding and an EE import whose bytes at `0x12A020` were zero. The generic
  import's bytes there matched the owned ELF. Do not accept either import's
  function boundaries/pseudocode without correcting or checking its mapping and
  decoder. This pass used existing source and did not open or alter those imports.

Confidence describes the stated role, not complete semantic equivalence:

| Label | Meaning |
| --- | --- |
| Confirmed/static | Explicit instructions establish the narrow behavior stated. Original library name and complete contract may remain unknown. |
| Probable | Calls, data layout, existing notes, and/or recorded execution support a subsystem meaning; alternatives remain. |
| Speculative | A useful direction for investigation with insufficient evidence for a semantic name. |

## 1. CRI callback scheduling and file/disc service

The clearest thread-6 route is:

```text
0x12AD70 service thread
  -> 0x141FF0 dispatch group 4
     -> 0x141E20 invoke registered callbacks
        -> 0x12A1C8 callback adapter
           -> 0x12A020 six-phase service pass
              phases 1/5: 0x130D48
              phases 2/4: 0x135EF0
              phase 3:   0x137D80
              phase 6:   0x129A60
  -> 0x12B0D8 -> 0x114540 SleepThread
```

| EE entry | Proposed label | Confidence | Evidence and unresolved part |
| --- | --- | --- | --- |
| [0x141B10](../recomp/config/output/sub_00141B10_0x141b10.cpp) | `cri_register_group_callback` | Confirmed/static | Computes `0x264820 + group*0x30`, searches six 8-byte slots, writes argument at +4 and callback at +0; returns slot index or -1. Registration is bracketed by `0x1416D0/0x1416E8`. Valid group range must be checked at callers. |
| [0x141E20](../recomp/config/output/sub_00141E20_0x141e20.cpp) | `cri_dispatch_group_callbacks` | Confirmed/static | Calls up to six nonnull callbacks with their stored argument; ORs return values; sets/clears a per-group busy word and increments a per-group dispatch counter. Does not itself identify a costly child callback. |
| [0x141FF0](../recomp/config/output/sub_00141FF0_0x141ff0.cpp) | `cri_dispatch_group4` | Confirmed/static | Sets `$a0=4` and tail-calls `0x141E20`. |
| [0x12AD70](../recomp/config/output/sub_0012AD70_0x12ad70.cpp) | `cri_group4_worker_thread` | Confirmed/static | Loops through group-4 dispatch and SleepThread; maintains busy, loop, and exit state. It also has optional GS MMIO writes around dispatch, so a replacement must preserve those side effects. Existing session identifies this as guest thread 6. |
| [0x12A1C8](../recomp/config/output/sub_0012A1C8_0x12a1c8.cpp) | `cri_group4_service_callback` | Confirmed/static | Thin adapter calling `0x12A020`. The observed registration association is also documented in the existing CRI observer. |
| [0x12A020](../recomp/config/output/sub_0012A020_0x12a020.cpp) | `cri_file_services_pass` | Probable subsystem; confirmed phase order | Guard/phase word at `0x20F390`; six calls in the order above. Grouping as file services is supported by the backend pump in phase 3. Exact CRI API name is unverified. The main body returns before adjacent adapters beginning at `0x12A0C0`; do not translate its entire generated file as one function. |
| [0x130D48](../recomp/config/output/sub_00130D48_0x130d48.cpp) | `cri_service_40_objects` | Confirmed complete file stream dispatch | Calls `0x142190` on `0x21A8B0`; if admitted, visits40 file stream descriptors at `0x21A8C0`, stride `0x5C`, calls `0x130B78` foractivebyte0==1 and clears admissionword. Full descriptor construction, lifetime and controls now reviewed in the [file stream pool pass](SYMBOLS_CRI_FILE_STREAM_POOLS_AND_CONFIGURATION.md). No measured scan duration. |
| [0x130B78](../recomp/config/output/sub_00130B78_0x130b78.cpp) | `cri_service_one_file_object_candidate` | Confirmed complete open/close/read handshake | Full [sector read service pass](SYMBOLS_CRI_FILE_STREAM_SECTOR_READ_SERVICE.md): completes deferredstop44,closesownedcvFsfile8onrequest42,opensborrowedfilename4C/openarg50onrequest41,clampsstartsector/bytecountagainstfilelength,resetsprogress,andservices130800onlystate2ANDownedfile45==1. Openfailure setsstate4; pending read reservations delay lifecycle requests. Current native overrides and runtime causality remain separate. |
| [0x135EF0](../recomp/config/output/sub_00135EF0_0x135ef0.cpp) | `cvFsExecServer_candidate` | Confirmed mechanics; probable comparative API identity | Visits32 device slots at262068, stride16; when interface and its method0 are nonnull, invokes that service callback without explicitly setting arguments. Complete scan/guards match pinned CVX cvFsExecServer, refining earlier cri_poll_backend_callbacks. Owned disc/host targets139798/13B1D8 service40/13 handles; other dynamic targets and inherited argument-register contents remain unpromised. See [filesystem comparison](recvx-crosscheck/FILESYSTEM_SECOND_PASS.md). |
| [0x137D80](../recomp/config/output/sub_00137D80_0x137d80.cpp) | `cri_pump_selected_io_backend` | Confirmed/static structure; probable I/O meaning | Admits through `0x142190(0x21BBC4)`. Mode byte `0x21BB89`: 1 calls `0x1379D0`, 2 calls `0x137BA0`, both with context `0x21BB88`. Optional lock wrappers surround each branch. |
| [0x1379D0](../recomp/config/output/sub_001379D0_0x1379d0.cpp) | `cri_disc_request_step` | Probable | State machine calls low-address disc routines with sector/count/destination-style arguments and markers `0x1600..0x1901`. State 1 submits through `0x101788`; state 2 polls `0x100D78(1)`. Exact SDK symbols and cancellation semantics need verification. |
| [0x137BA0](../recomp/config/output/sub_00137BA0_0x137ba0.cpp) | `cri_file_request_step` | Probable | State machine seeks by `context.+0x28 << 11`, submits a read from +0x18/+0x20, then polls completion. Markers `0x2000..0x2202`; state 3 appears completed, state 9 is an error path. Confirm all switch targets before using that interpretation in code. |
| [0x1383E8](../recomp/config/output/sub_001383E8_0x1383e8.cpp) | `cri_file_seek_wrapper` | Probable | Three arguments; called with a sector-derived byte offset and seek origin zero. Chooses `0x11B010` or `0x118E78` using `0x21BBF8`; reports negative results and brackets the operation with `0x1382F0/0x138328`. Exact 32/64-bit offset contracts differ by branch and need checking. |
| [0x1385D8](../recomp/config/output/sub_001385D8_0x1385d8.cpp) | `cri_file_read_wrapper` | Probable | Forwards three arguments to `0x1190B0`, used as handle/destination/byte-count by `0x137BA0`; reports negative results. Actual host blocking behavior lives further down the RPC/HLE path. |
| [0x1384A0](../recomp/config/output/sub_001384A0_0x1384a0.cpp) | `cri_file_completion_poll_wrapper` | Probable | Forwards handle, command 1, and status-output pointer to `0x1195D0`. Caller remains in state 2 until output becomes zero; negative return enters an error path. Exact SDK API identity is unverified. |
| [0x138208](../recomp/config/output/sub_00138208_0x138208.cpp) | `cri_set_io_breadcrumb` | Confirmed/static | Copies `0x21BBF4` to `0x21BBF0`, then writes argument to `0x21BBF4`. Entry body ends at return delay slot `0x138224`; the file also contains separate getters/configuration routines. |
| [0x129A60](../recomp/config/output/sub_00129A60_0x129a60.cpp) | `ADXF_ExecServer_candidate` | Confirmed ADXF pool/service; probable comparative API name | Under CRI guard1264E0/1264F8 visits16 ADXF records20C8C0,stride44,activebyte0==1 calls129998 status/progress/stop service. Pool ownership is established by128F80/1290C8/129350 and matches pinned CVX ADXF_ExecServer, superseding earlier subtype-unknown prose. Complete original body has no file open/read of its own; delegated work remains separate. See [complete stream/filesystem comparison](recvx-crosscheck/STREAM_FS_COMPLETE_SCOPE.md). |
| [0x12B0D8](../recomp/config/output/sub_0012B0D8_0x12b0d8.cpp) | `cri_sleep_current_thread` | Confirmed/static | Tail-call to SleepThread wrapper `0x114540`. A sample at `0x114544` with return address `0x12AE10` indicates the worker's sleep path, not the identity of its earlier expensive operation. |

Sources for registration association and existing diagnostics:
[CRI observer](../recomp/overrides/reo_cri_server_observer.h) and
[override bindings](../recomp/overrides/reo_override.cpp). These files already
existed at the start of this pass; no instrumentation was enabled here.

### Readable sketch of the group dispatcher

This is explanatory pseudocode, not a callable replacement. Callback ABI,
recompiler resumptions, and original integer behavior still need checking.

```cpp
uint32_t dispatch_group(uint32_t group) {
    uint32_t result = 0;
    for (unsigned slot = 0; slot != 6; ++slot) {
        // Read each slot when reached; do not assume callbacks leave the table unchanged.
        auto entry = guest_read_slot(0x264820 + group * 0x30 + slot * 8);
        if (entry.function) {
            guest_write32(0x22A618 + group * 4, 1);
            result |= guest_call(entry.function, entry.argument);
            guest_write32(0x22A618 + group * 4, 0);
        }
    }
    guest_increment32(0x22A5F8 + group * 4);
    return result;
}
```

The six-phase pass uses `0x20F390` as both a reentry guard and progress marker.
It takes the CRI lock, returns after unlocking if already active, otherwise
marks phase 1 and unlocks before the service calls. It writes phases 2 through 6
before subsequent calls, then clears the word. This must not be replaced with a
host mutex spanning the whole pass without proving equivalent scheduling.

## 2. Critical sections and audio service

| EE entry | Proposed label | Confidence | Evidence and unresolved part |
| --- | --- | --- | --- |
| [0x1264E0](../recomp/config/output/sub_001264E0_0x1264e0.cpp), [0x1264F8](../recomp/config/output/sub_001264F8_0x1264f8.cpp) | `cri_lock` / `cri_unlock` adapters | Confirmed/static routing; probable API names | Tail-call `0x1416D0` / `0x1416E8`. Historical scheduler investigation establishes priority-sensitive CRI critical sections; not ordinary independent host-thread locks. |
| [0x1415E0](../recomp/config/output/sub_001415E0_0x1415e0.cpp) | `cri_enter_tagged_critical_section` | Confirmed/static | Optional callback pair at `0x2649E0`; records outermost tag at `0x22A5F4` and increments depth at `0x22A5F0`. |
| [0x141640](../recomp/config/output/sub_00141640_0x141640.cpp) | `cri_leave_tagged_critical_section` | Confirmed/static | Optional callback pair at `0x2649E8`; decrements depth, checks tag on outermost release, reports mismatch and clears tag. Callback and no-callback branches must be preserved. |
| [0x141730](../recomp/config/output/sub_00141730_0x141730.cpp), [0x1417A8](../recomp/config/output/sub_001417A8_0x1417a8.cpp) | `cri_enter_tag4` / `cri_leave_tag4` | Confirmed/static | Set argument 4 and tail-call `0x1415E0/0x141640`. The latter generated file also contains other tags' wrappers. |
| [0x142190](../recomp/config/output/sub_00142190_0x142190.cpp) | `cri_try_enter_service_guard` | Confirmed/static default branch | Uses optional function pointer `0x2649F8`; otherwise atomically with CRI lock reads old word, writes 1, returns whether old value differs from 1. This is an admission/reentry guard, not evidence of a spin loop. Do not normalize its test to old==0 without verifying value domain. |
| [0x12A1A8](../recomp/config/output/sub_0012A1A8_0x12a1a8.cpp) | `cri_group2_audio_callback` | Probable audio meaning; confirmed routing | Calls `0x132C08`; group association is documented in the existing observer. |
| [0x132C08](../recomp/config/output/sub_00132C08_0x132c08.cpp) | `cri_audio_services_pass` | Probable | Reentry/phase word `0x21B754`; phase 1 `0x12D678`, phase 2 visits 16 active handles at `0x20F3C8`, stride `0xC4`, through `0x134C58`; phase 3 `0x12C798`. Unlike the group-4 sketch, this pass reacquires the CRI lock before phase 1 and releases at exit. |
| [0x12D678](../recomp/config/output/sub_0012D678_0x12d678.cpp) | `cri_service_16_decoder_objects_candidate` | Probable | Visits 16 active objects at `0x217D88`, stride `0x9C`, calling `0x12D638`. Decoder interpretation needs child-call comparison; object count/layout is explicit. |
| [0x134C58](../recomp/config/output/sub_00134C58_0x134c58.cpp) | `cri_audio_handle_step` | Probable | Switch-like branch chain on signed byte +1 dispatches states 1..5, then calls `0x134BC0` and `0x134B40`. This fits a playback lifecycle; exact preparation/playing/end-state names are unverified. Main body tail-returns at `0x134D14`; adjacent routines follow. |
| [0x12C798](../recomp/config/output/sub_0012C798_0x12c798.cpp) | `cri_audio_transport_service_adapter` | Confirmed complete service chain, decoder work separate | Tail-calls `0x13EEE8`: sixteen active PS2RNA group admission scans, `0x1389D8` thirty-two DTR stream DMA scans plus a DTX scan, then `0x141268` another DTX scan. Full intervals and ownership now reviewed in the [DTR and PS2RNA service pass](SYMBOLS_CRI_DTR_STREAM_DMA_AND_PS2RNA_SERVICE.md). No ADX decode or runtime bottleneck is proved by this adapter. |

Historical context, not measurements from this pass:
[D16 critical-section scheduler behavior and D44 DTX transport investigation](DIVERGENCES.md).
Keep host wait time, guest CPU ownership, device work, and actual decoding time
separate when attributing a stall.

## 3. Frame completion, vblank, and actor input

| EE entry | Proposed label | Confidence | Evidence and unresolved part |
| --- | --- | --- | --- |
| [0x18D650](../recomp/config/output/sub_0018D650_0x18d650.cpp) | `wait_previous_frame_completion` | Confirmed/static wait; probable full frame role | Spins at `0x18D678` on `0x29F704 + ((read32(0x29FDB4)^1)*4)`, then repeatedly calls `0x103630(read32(0x29FD78),1,0)` until zero. Historical GS/DMAC investigations explain completion dependencies. Hot PC here can identify a waiter, not the producer delaying it. |
| [0x19F6C0](../recomp/config/output/sub_0019F6C0_0x19f6c0.cpp) | `frame_submission_boundary_candidate` | Probable | Calls `0x18D650` at `0x19F6D0`; return address `0x19F6D8` leads into `0x1A90B0`, VIF register writes, and more frame work. Exact begin/end-of-frame API name remains unknown. |
| [0x19F600](../recomp/config/output/sub_0019F600_0x19f600.cpp) | `game_vblank_handler` | Probable; historically identified | Increments counters `0x29FA0C/0x294170`; conditional flip path calls `0x1A0350`, then `0x1A9040`; ends with interrupt enable. Do not count this as one gameplay update: rendering/vblank and game logic have different rates. |
| [0x1A0350](../recomp/config/output/sub_001A0350_0x1a0350.cpp) | `frame_flip_and_completion_service` | Probable | Vblank caller, completion wait, and frame/DMA setup calls; historical display-snapshot investigation associates it with DISPFB flip. Full routine needs a dedicated register-write audit before replacement. |
| [0x1A9040](../recomp/config/output/sub_001A9040_0x1a9040.cpp) | `conditional_cri_vblank_service` | Confirmed/static routing; probable CRI role | If `0x2B0EC0` is nonzero, calls `0x12BEE0(0)`; adapter goes to `0x12BDB8`. That service contains wakeup calls and group dispatch. |
| [0x669F30, overlay 2](../recomp/config/output_ovl/o2/o2_00669F30_0x669f30.cpp) | `update_active_actor_slots` | Confirmed/static loop; probable scope of update | Walks eight entries from `0x4A5C30`, stride `0x10E0`, skips inactive entries, applies room/pause gates, and calls multiple actor helpers. Calls `0x1B0B80` at `0x66A0D0`, returning to `0x66A0D8`. Not established as the entire global game update. |
| [0x1B0B80](../recomp/config/output/sub_001B0B80_0x1b0b80.cpp) | `copy_mapped_input_to_actor` | Probable | Chooses an input source using actor id/mode, reads controller-style data at `0x324248` with 0x30-byte stride, and shifts actor input history around +0xF78..+0xF8C. Exact meanings of all button masks and remote/local branches remain unknown. |

The existing [clock observer](../recomp/overrides/reo_game_clock_observer.h)
samples only the verified call to `0x1B0B80` with return address `0x66A0D8` and
an actor id below four. The enclosing loop has eight slots. This is a coverage
distinction, not proof that a particular unobserved slot represents a missing
game update. Actor callbacks are deduplicated by original clock/counter state.
In-engine cutscenes can require another verified observation boundary.

## 4. A compile-heavy function belongs to packet processing

| EE entry | Proposed label | Confidence | Evidence and unresolved part |
| --- | --- | --- | --- |
| [0x1DCC2C](../recomp/config/output/sub_001DCC2C_0x1dcc2c.cpp) | `snap_drain_received_packets_candidate` | Probable | Gets work from context +0x68 via `0x1F1104/0x1F1264`, passes returned packet to `0x1DFDA8`, then calls `0x1F2810` with context +0x520. Exact queue ownership and return-code meanings need recovery. |
| [0x1DFDA8](../recomp/config/output/sub_001DFDA8_0x1dfda8.cpp) | `snap_dispatch_packet_command` | Probable network meaning; confirmed header dispatch | Reads header at argument 2 +0x2C. Uses low 7 bits of its second halfword, subtracts 3, bounds-checks against 0x76, dispatches through table `0x257D00`. Many branches call handlers through context function pointers and manipulate packet fields. Existing `traceSnapPacket` explicitly treats argument 2 as a SNAP packet. Exact message types and protocol contracts remain unknown. |
| [0x1DD8E0](../recomp/config/output/sub_001DD8E0_0x1dd8e0.cpp) | `swap_packet_u32_at_10` | Confirmed/static | Byte-swaps the 32-bit field at argument +0x10 in place. This is a packet-field helper, not a vertex transform. Other nearby helpers require separate audits. |

The existing [SNAP trace wrapper](../recomp/overrides/reo_missing_entries.cpp)
logs packet header words at +0x2C/+0x30/+0x34/+0x38 and binds `0x1DFDA8`.
The current generated file is 1,061,344 bytes. [Historical build notes](BASELINE.md)
describe earlier pathological indirect-jump expansion; those historical line
counts and build timings are not new measurements of today's file.

This is a reasonable compile-cost reconstruction candidate. No evidence in this
pass ties it to the recorded offline rendering stalls. Recover message layout,
handler table, error paths, and resume behavior before reducing the dispatch.
Do not assume every large generated function belongs to graphics.

## 5. Host rendering pipeline map

These are authored host functions, not unnamed guest functions. Their behavior
can be inspected directly without translating EE instructions.

| Source/function | Established responsibility | Open question |
| --- | --- | --- |
| [GS worker](../third_party/PS2Recomp/ps2xRuntime/src/lib/ps2_gs_gpu.cpp), `gsWorkerMain` / display-capture enqueue | Processes ordered GS work and display markers. Adjacent capture markers can already coalesce when there is no intervening GS command. | How much time is spent waiting in the queue or doing work before backend `capture()`? |
| [Backend](../tools/parallel_gs_backend/parallel_backend.cpp), `completeEvents()` | Flushes pending GS work and calls `device_->wait_idle()` before ordered event delivery; handles second-SIGNAL halt/ack behavior and reentrancy. | Frequency and cost of this full-device wait in affected scenes. A narrower fence requires proven prefix coverage. |
| Same source, `capture()` | Completes events, applies display snapshot, flushes GS work, optionally retires a stale progressive marker, creates scanout, presents and retains image/fence. | Existing timing combines event work, flush, and scanout. It excludes work before reaching capture. |
| [GS interface](../tools/parallel_gs_backend/resident_gs/gs_interface.cpp), `GSInterface::vsync()` | Chooses promoted buffers and field-aware settings, calls renderer scanout, restores FFMD state. | Which substage dominates and when temporal/interlaced history is essential? |
| [GS renderer](../tools/parallel_gs_backend/resident_gs/gs_renderer.cpp), `flush_submit()` | Submits transfer, clear, setup, heuristic, binning and raster work with dependencies; advances frame context and retires resources. | Relative CPU submission, GPU work, resource retirement and frame-context wait costs. Multiple submits alone do not prove overhead is dominant. |
| Same source, `GSRenderer::vsync()` | Produces merged scanout using display state and sampling configuration. | Per-stage GPU timestamps are needed to separate rendering cost from host waiting. |
| [DXGI presenter](../tools/parallel_gs_backend/resident_dxgi_presenter1c.h), `present()` | Acquire/latency handling, optional SMAA, output draw, GPU submit and DXGI presentation. Normal presentation remains GPU-resident. | Host call duration does not measure GPU completion or actual display time. |

### Connection to existing completed recording

The completed local session `20261103-210201-498` contains the following evidence
from the earlier read-only trace analysis. These are historical observations,
not results of any new run for this notebook:

- Record 40622: about 386.381 seconds from trace start, presentation-scope
  completion gap 157.1465 ms, capture work 0.8684 ms. Nearby stderr line 9749:
  `[vblank-slow] 139042 us, lastOwner=6 tick=23105 catchup=1`.
- Record 48638: about 452.352 seconds, gap 226.6374 ms, capture work 0.8282 ms.
  Nearby thread-6 CPU ownership totals were 161 ms and 230 ms per heartbeat
  window, compared with approximately 5-6 ms in ordinary nearby windows.
- Record 118025: about 997.211 seconds, capture 42.8523 ms; preparation/flush/
  scanout 42.3963 ms, presenter call 0.4426 ms.
- Of 832 deliberately retired scanouts, 815 were clustered around 834-1030
  seconds. Several later long gaps included two retired scanout markers.
- Strict continuous recording completed without dropped native records or
  reaching its byte cap. Per-incident coalescing does not count every hitch.

Times here are host instrumentation boundaries, not measured display scanout
times. The data prioritizes a thread-6 service investigation and a separate later
rendering-preparation investigation. It does not prove a specific child callback,
GPU kernel, or `wait_idle()` caused an incident. A large wait in `0x18D650` can
be downstream of delayed service/completion work.

## 6. Next mapping tasks and falsifiable checks

No checks below were run; they are a queue for after the current playtest.

| Priority | Hypothesis | Competing explanation / falsifier | Smallest useful next evidence |
| --- | --- | --- | --- |
| 1 | Group-4 file/disc service delays guest progress during rare long stalls. | Another worker, host descheduling, or a device wait accounts for the time; a quiet group-4 span would weaken this lead. | Align existing/new per-phase ownership logs with QPC incident records; recover actual `0x135EF0` callback targets. |
| 2 | Phase-3 file/disc RPC service contains a costly operation. | Callback phases 1/2/4/5/6 consume the span instead. Even a long RPC wrapper may spend time waiting rather than doing I/O. | Resolve SDK functions below `0x1383E8/0x1385D8/0x1384A0`; compare breadcrumb intervals and host HLE call timing. |
| 3 | Full-device event completion waits reduce rendering overlap. | Raster cost or earlier queue work dominates; event waits may be infrequent or short. | Separate event, flush, scanout, queue and GPU timings before proposing a fence replacement. |
| 4 | Actor-based observation lacks coverage in some in-engine cutscenes. | Pause, loading, or a deliberately stopped clock explains missing observations. | Identify the global gameplay/cutscene state owner and its clock writes, with state-transition evidence. No new hook admitted solely from a guessed function name. |
| 5 | Reconstructing SNAP dispatch can reduce generated compile cost. | Other units dominate build time; protocol/resume complexity prevents a compact equivalent. | Map packet structures, all switch targets and callback signatures; use existing build profiles before choosing a replacement target. |

## 7. Code Veronica comparison: techniques to reuse

Source inspection in the preceding investigation found:

- `recvx-decomp` reconstructs readable C and uses splat/objdiff with its PS2
  compiler, then tests a rebuilt PS2 ELF. See
  [compile.py at inspected revision](https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/compile.py).
- Its CRI sources give useful library vocabulary. For example,
  [ADXPS2 worker](https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/cri/mwlib/ee/lib/libadxe/adx_mps2.c)
  runs audio and file services before sleeping. This is comparative evidence,
  not an exact match of Outbreak's dispatcher, SDK version, or addresses.
- The enhanced port keeps statically translated VU/reference paths while
  specializing selected operations, and adds native geometry and texture paths
  at recovered boundaries. See
  [VU implementation](https://github.com/aikatore/recvx-enhanced-port/blob/68ad6901932f66ac17a2d4a1da86350485a0008e/pc/src/ps2/vu.c),
  [native geometry](https://github.com/aikatore/recvx-enhanced-port/blob/68ad6901932f66ac17a2d4a1da86350485a0008e/pc/glue/native_glue.c),
  and [architecture](https://github.com/aikatore/recvx-enhanced-port/blob/68ad6901932f66ac17a2d4a1da86350485a0008e/docs/ARCHITECTURE.md).

For Outbreak, first recover roles and contracts, then validate compact functions
against the existing execution path. Preserve original timing, callback order,
guest addresses, floating-point behavior, and synchronization side effects.
Naming a function does not establish a speedup or justify enabling experimental
paths. Semantic replacements and Ghidra renames remain future work.

## Central searchable index

The [native reconstruction plan](NATIVE_RECONSTRUCTION_PLAN.md) describes how
to turn reviewed mappings into independent native subsystems, starting with
SJUNI, and eventually remove the PS2 compatibility layer.

The [Code Veronica cross-check](recvx-crosscheck/README.md) compares this work
with pinned `recvx-decomp` source. It records supported API roles, candidate
names, version differences and explicit coverage limits in a separate folder;
it does not change the canonical mapping tables or the index.

[FUNCTION_INDEX.md](FUNCTION_INDEX.md) describes the offline database and tool
that connect these annotations with catalogue entries, calls and references.
The index preserves these proposed names and confidence levels; it does not
automatically rename or translate functions.
