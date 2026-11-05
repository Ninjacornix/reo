# Function mapping pass 3: neighbors of known systems

Static investigation, 2026-11-03. This pass adds 33 entry mappings selected
from [the central index](FUNCTION_INDEX.md) and nearby helpers. The previous
84 entries remain in [pass 1](SYMBOLS.md) and [pass 2](SYMBOLS_GAMEPLAY.md).

Target: Outbreak File #1 US, `SLUS-20765`, main ELF SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
Image labels such as `o2` identify source/map partitions, not automatically
runtime overlay IDs. All labels below are proposed research names.

No game, game build, replay, GPU test, debugger attachment, live memory read,
or new recording was performed. Existing generated instructions, index evidence
and historical notes were inspected. Game/runtime source code was not changed.
The offline index tool gained an annotation-only refresh operation and synthetic
checks so further mapping does not require scanning all generated sources again.

`Confirmed/static` establishes the stated mechanics, not the original symbol
name or a complete replacement contract. `Probable` retains uncertainty about
the subsystem/API interpretation. Indirect dispatch, recompiler continuations,
PS2 arithmetic and guest-visible side effects require further validation.

## 1. Mode checks used by actors and scenario services

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1B0300](../recomp/config/output/sub_001B0300_0x1b0300.cpp) | `get_session_mode_byte` | Confirmed/static getter; mode meaning probable | Returns unsigned byte `0x3243F2` in the return delay slot. Several unrelated adjacent helpers share this generated file. Historical offline-menu notes distinguish mode value 1, but not every other value is identified. |
| [0x1B02D0](../recomp/config/output/sub_001B02D0_0x1b02d0.cpp) | `is_session_mode_zero` | Confirmed/static | Calls `0x1B0300` and returns unsigned result <1, equivalent to mode==0. It does not mean mode!=1 for arbitrary byte values. This distinction matters when giving it an offline/online name. |
| [0x1B0310](../recomp/config/output/sub_001B0310_0x1b0310.cpp) | `is_session_submode_1_or_2` | Confirmed/static predicate; submode meaning unknown | Reads signed byte `0x3243FB`; returns 1 only for values 1 or 2, otherwise zero. Its callers include actor processing and UI entry. A stronger gameplay-mode name needs the writers of this byte. |
| [0x1B0340](../recomp/config/output/sub_001B0340_0x1b0340.cpp) | `is_locally_controlled_actor_candidate` | Probable | Rejects actors with nonzero byte +2. When mode==0, accepts actor id +3 equal to zero; in other modes compares id to selected byte `0x4BADED`. Exact meaning of the +2 exclusion flag and all remote-mode behavior remain unknown. |
| [0x1B03C0](../recomp/config/output/sub_001B03C0_0x1b03c0.cpp) | `is_secondary_actor_in_mode_zero` | Confirmed/static predicate; companion role probable | Rejects nonzero actor +2; then accepts only mode==0 and actor id +3 !=0. Fits an offline companion/secondary actor distinction, but it is not proven to identify every AI-controlled actor. |

The historical [menu-return investigation](M2_MENU_RETURN_INVESTIGATION.md)
uses mode-dependent pause/UI guards. That historical context is not a new
measurement of the active playtest.

## 2. Critical-section adapters and original I/O waiting

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1416D0](../recomp/config/output/sub_001416D0_0x1416d0.cpp) | `cri_enter_tag1` | Confirmed/static | Sets argument 1 and tail-calls the already mapped tagged critical-section entry `0x1415E0`. This exposes the tag used by the higher-level `0x1264E0` lock adapter. |
| [0x1416E8](../recomp/config/output/sub_001416E8_0x1416e8.cpp) | `cri_leave_tag1` | Confirmed/static | Sets argument 1 and tail-calls `0x141640`; paired with `0x1416D0`, preserving its callback, nesting and owner checks. |
| [0x1382F0](../recomp/config/output/sub_001382F0_0x1382f0.cpp) | `cri_enter_file_lock_if_configured` | Confirmed/static | Tests word `0x21BBFC==1`; only that value tail-calls tag-4 entry `0x141730`. Otherwise returns. Not an unconditional host mutex lock. |
| [0x138328](../recomp/config/output/sub_00138328_0x138328.cpp) | `cri_leave_file_lock_if_configured` | Confirmed/static | Same configuration test; tail-calls tag-4 leave `0x1417A8` when enabled. The generated file also contains a later disc API beginning `0x138360`. |
| [0x137610](../recomp/config/output/sub_00137610_0x137610.cpp) | `cri_fixed_busy_delay` | Confirmed/static | Initializes a counter to 0x3FFF, repeatedly subtracts 0x20 around a NOP loop, and returns. No syscall, file read, callback, or memory-poll predicate occurs in this body. The branch-likely delay slot participates in the counter update. It consumes guest instruction work rather than requesting a timed OS sleep. |
| [0x137668](../recomp/config/output/sub_00137668_0x137668.cpp) | `cri_wait_file_completion_with_retry_limit` | Probable completion meaning; polling explicit | Initializes a stack status word to 1; calls `0x1384A0(context.+0x30,1,&status)` until it changes. Between busy results calls `0x137610`; retry counter is bounded against 0x9000, then a diagnostic is emitted. Negative poll results are stored at context +0x34 and state byte +2 becomes 9. Timeout and error branches need preserving. |
| [0x1378D0](../recomp/config/output/sub_001378D0_0x1378d0.cpp) | `cri_check_disc_request_error` | Probable API meaning; narrow status test explicit | When the global gate and request state 2 permit, calls `0x101AE8`, optionally under tag-4 lock, with breadcrumbs 0x1400/0x1401 or 0x1500/0x1501. Results -1 and 0 return no reported error; other values are written to context +0x34 and reported. Exact SDK status meanings remain unverified. |

### Potential performance relevance, not a diagnosis

`0x137668 -> 0x137610` is a concrete CPU-polling/delay path. It is distinct from
the known frame-completion wait and from host ISO-read time. A repeatedly busy
backend can make it expensive, but no new observation establishes that this
path ran during the recorded slowdowns. Later evidence should identify whether
phase-3 marker 0x1100/0x1101 repeats, the returned status, and the time spent
between those markers. Skipping the delay or forcing completion would change
original behavior; no such change was made or proposed as a proven fix.

## 3. Common memory and formatted-output helpers

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x107C68](../recomp/config/output/sub_00107C68_0x107c68.cpp) | `memset` | Confirmed/static operation | Uses destination/value/count, repeats the low fill byte through PCPYH/PCPYLD, writes aligned blocks and remaining bytes, and returns the original destination. Historical generator correction for PCPYH is documented elsewhere; this mapping does not authorize replacing guest memory access with unchecked host `memset`. |
| [0x107AB0](../recomp/config/output/sub_00107AB0_0x107ab0.cpp) | `memcpy_forward` | Confirmed/static copying; original library name probable | Copies source to destination forward using aligned 128/64-bit operations or byte fallback, returns destination. It does not implement the general overlap-safe contract of `memmove`. Guest aliases, MMIO and fault behavior still need checking before a host replacement. |
| [0x10A830](../recomp/config/output/sub_0010A830_0x10a830.cpp) | `sprintf_candidate` | Probable | Saves variadic integer and floating-point arguments, creates output state pointing to caller buffer, sets large capacity values, calls `0x10D168`, and writes a terminating zero at the final output cursor. Room loader supplies a filename format string. Exact formatting/return/error rules are not fully recovered. |
| [0x116848](../recomp/config/output/sub_00116848_0x116848.cpp) | `printf_candidate` | Probable debug printf; complete formatter/backend reviewed | Saves variadic arguments in eight-byte slots, temporarily replaces shared callback209D44 with DECI2 line-buffer output115F30, calls116218(format,&saved_args), and restores callback. Owned default callback is serial CRLF115FE0. Complete restricted parser and output waits are documented in [debug formatter](SYMBOLS_DEBUG_FORMATTER_AND_SERIAL_OUTPUT.md); no standard printf return-count or full format compatibility claim. Used for errors in multiple CRI file paths; no proof of emission during normal gameplay. |

These high-fan-in helpers are useful naming anchors. Their original ABI, guest
address behavior, exceptions and resumes need validation before replacing them;
recognizing a standard operation is not itself a compile-time or runtime gain.

## 4. Matrix and vector operations

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x18FDF0](../recomp/config/output/sub_0018FDF0_0x18fdf0.cpp) | `copy_shared_matrix_to_output` | Confirmed/static copy; matrix interpretation probable | Copies four 16-byte vectors from `0x294E00` to argument 1 using VU0 transfers. The routine does not synthesize an identity matrix. Identity-like use at a caller does not prove that shared data always contains identity. |
| [0x18FE60](../recomp/config/output/sub_0018FE60_0x18fe60.cpp) | `copy_shared_matrix_with_diagonal_values` | Confirmed/static | Loads the same shared four-vector data, replaces row0.x/row1.y/row2.z using float arguments f12/f13/f14, then writes output. Off-diagonal and fourth-vector contents come from shared data; a pure scale-matrix label would require proving that template's contents. |
| [0x191300](../recomp/config/output/sub_00191300_0x191300.cpp) | `multiply_matrix4_in_place` | Confirmed/static products; matrix convention unresolved | Loads all four vectors of both arguments, computes four weighted four-vector combinations through VU0 ACC, then stores to argument 1. Source loads precede stores. Row/column convention and composition order must be derived from engine callers, not host math-library naming. Initial entry returns before neighboring routine `0x191380`. |
| [0x191380](../recomp/config/output/sub_00191380_0x191380.cpp) | `multiply_matrix3_components_preserve_w` | Confirmed/static | Loads three vectors from each source and three destination vectors, writes weighted XYZ combinations with VU component masks, preserving destination W lanes. No affine translation term is added by this entry. |
| [0x1919D0](../recomp/config/output/sub_001919D0_0x1919d0.cpp) | `transform_vector3_without_translation` | Confirmed/static | Computes output XYZ from input XYZ and the first three matrix vectors; uses no fourth matrix vector/translation. Three floats are stored to output, so do not label it a generic point transform with implicit W=1. |
| [0x191A40](../recomp/config/output/sub_00191A40_0x191a40.cpp) | `transform_vector3_in_place_without_translation` | Confirmed/static | Same three-vector combination, with argument 1 as both input and output and argument 2 as matrix. Temporary storage avoids overwriting input components during calculation. |

These operations connect camera-local offsets and animation displacement to
the previously mapped `0x65E3A0` route. VU0 register/ACC side effects and exact
operation order remain relevant even when the mathematical formula is clear.

## 5. Resource, frame and movie orchestration

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1AA4C0](../recomp/config/output/sub_001AA4C0_0x1aa4c0.cpp) | `load_room_nbd_resource_set` | Probable | Formats verified main-ELF string `R%03d%02d%02d.NBD` at `0x24D010`, reads via `0x1AA3E0`, copies a 0x50-byte header, walks resource tables, switches bank byte `0x5697B8`, initializes manager state and publishes render parameters. This is more specific than an unnamed room helper; all NBD sections and relocation/lifetime rules remain unknown. |
| [0x12A1E8](../recomp/config/output/sub_0012A1E8_0x12a1e8.cpp) | `initialize_cri_services_reference_counted` | Probable subsystem; initialization mechanics explicit | Word `0x20F3B0` gates first-time setup; initialization clears the 16-handle area at `0x20F3C8`, initializes dependent subsystems and registers group-2/group-4/group-5 callbacks. Every call increments the reference count. Exact library API name and failure propagation need recovery. |
| [0x1BAAF0](../recomp/config/output/sub_001BAAF0_0x1baaf0.cpp) | `service_n_frame_boundaries_and_record_clock` | Confirmed/static control flow; clock meaning probable | Calls `0x19F6C0(0)` up to requested signed iteration count, conditionally clears `0x294178`, then calls `0x1AC630` and writes result to `0x3243F4`. This is not simply a host sleep, and the returned clock's units are not established here. |
| [0x1B5FB0](../recomp/config/output/sub_001B5FB0_0x1b5fb0.cpp) | `service_font_packet_buffers_with_conditional_dma_submission_candidate` | Probable font packet servicing; full original body reviewed | Defaultfont2BAAF0 state0!=0 reloads remainingbytes+50 from+9C then switchesbuffer. State0zero/type+4==7 delegates1B7B00. Otherpathsconfigure selectors5F/60/6C,gate3243D6/EA, anddependingcounter+88/EA/mode3243C3 canwait18D650,drawstatus1B5A50, setDMAcontextbits40/80,call1148A0(0),pollread32(1000A000)&100hex, then103390(context29FD7C,selectedpacketstart+38/+3C). Non-EApathwithglyphcount emitsENDtagandqueues18CEF0 instead. Buffer48 toggles,packetend4C reloads from40/44,priorglyphcount68 records64 then64clears, with1AF770 on some paths. Three literal DMA polls have no local timeout. Current File1 override source replaces this entry with ret0 under net_accept label; see [dispatch audit](SYMBOLS_FONT_OVERRIDE_BOUNDARY.md). Original wait cannot be attributed to player execution without installed-handler evidence. |
| [0x148170](../recomp/config/output/sub_00148170_0x148170.cpp) | `mpeg_decode_picture_state_driver` | Confirmed full driver, table and connected processing; header parser partial | Resolves owner40 context, clears completion0 and requires F0 destination64-byte alignment.10A0 is an ABORT flag, not a busy flag; set prints/returns-1. Clears838 then loops145C40 unless prior child result==-1; negative header status-1. Complete23E100 table:status0 finalflush148608/completion1;1 resets three picture-class counters and148448(thresholdAC),2 usesBC/B0,3/4 useC0/B4; each class counter increments. Aborts checked after dispatch; loop ends on838publication orcompletion0nonzero,returns1. Full frame/field, output and timestamp contracts in [reference/publication pass](SYMBOLS_MOVIE_REFERENCES_AND_OUTPUT_PUBLICATION.md). No UI event loop, watchdog or game-clock tick. |

The verified filename string was obtained through the existing hash-checked ELF
reference index. Other labels here use control flow and state accesses, not
filename proximity or a presumed match with Code Veronica.

## 6. Actor dispatch, camera mode selection and UI entry

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x66B500](../recomp/config/output_ovl/o2/o2_0066B500_0x66b500.cpp) | `service_actor_actions_and_dispatch_state` | Probable | Runs actor pre-services, copies history fields, processes camera-relative input through `0x6621F0`, checks local-control/UI gates, then calls table `0x712BD0[actor.+8]`. Tracks previous action state in bytes near `0x744648/0x744640`. Dynamic state handlers still require mapping; this is a useful parent of the previously inspected pickup state. |
| [o2 0x5BED30](../recomp/config/output_ovl/o2/o2_005BED30_0x5bed30.cpp) | `dispatch_camera_mode_and_publish_view` | Probable | Reads camera state near `0x3DDDB0`, camera/actor-related records, selects helpers including `0x5BF1F0`, `0x5BF7B0` and `0x5BF300`, then publishes through `0x375920`. Exact mode names and triggers remain unknown; do not assume this covers every cinematic camera. |
| [o2 0x6E0ED0](../recomp/config/output_ovl/o2/o2_006E0ED0_0x6e0ed0.cpp) | `open_or_switch_gameplay_ui_mode` | Probable | Accepts a type-like argument and actor selector, resolves actor storage, handles preexisting UI state, initializes fields rooted at `0x755EC0`, and sets actor/UI gate `0x4BADEE`. Existing pause/pickup investigations exercise different UI types. Every type's meaning is not established, so this is broader than an inventory-only label. |

## 7. File probes and handle wrappers

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x13C240](../recomp/config/output/sub_0013C240_0x13c240.cpp) | `read_bounded_file_prefix_probe` | Probable | Builds a path in a zeroed 256-byte local buffer, opens it, seeks to end then start, requests up to 0x1000 bytes into caller buffer and closes. Markers 0x6000..0x6501 bracket stages. Returns success/failure rather than necessarily a byte count; exact file-format purpose and short-read handling need audit. |
| [0x138518](../recomp/config/output/sub_00138518_0x138518.cpp) | `cri_open_file_wrapper` | Probable | Brackets underlying two-argument `0x118A70` with conditional file lock/unlock, logs negative results with diagnostic string at `0x23C760`, returns underlying result. Exact open flags/device semantics are below this wrapper. |
| [0x138580](../recomp/config/output/sub_00138580_0x138580.cpp) | `cri_close_file_wrapper` | Probable | Same bracket/error pattern, one argument to `0x118CF8`, diagnostic string at `0x23C780`. Pending asynchronous operations and handle ownership remain contracts to recover. |

## Review queue after this pass

1. Recover the actual values/writers of mode bytes `0x3243F2/0x3243FB` before
   renaming predicates to online/offline or expanding local/remote actor rules.
2. Resolve actor table `0x712BD0` and camera mode branches, with overlay identity
   and exact handler boundaries, to grow the gameplay map beyond wrappers.
3. Audit the completion-poll status and host RPC implementation before drawing
   conclusions about the fixed-delay path's contribution to a slowdown.
4. Establish NBD section types, manager layout and resource lifetimes using the
   now-named loader and its helpers; cached resources cannot be reused blindly.
5. Use existing CPU/build profiles to choose reconstruction targets. A compact
   matrix or memory operation is not automatically the largest cost.

All 33 mappings retain source links, confidence qualifiers and unresolved
contracts. No function was rewritten or enabled as a native replacement.
