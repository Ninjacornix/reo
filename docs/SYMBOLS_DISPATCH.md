# Function mapping pass 4: dispatch, actor messages and scenario archives

Static investigation, 2026-11-03. This pass adds 35 entry mappings to the
previous 117, and corrects the interpretation of one existing matrix helper.
The [central index](FUNCTION_INDEX.md) links all four mapping notebooks.

Target: Outbreak File #1 US, `SLUS-20765`, main ELF SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
Overlay qualifiers such as `o2` refer to source/catalogue partitions, not
automatically to runtime overlay IDs. Proposed names are research annotations;
no guest functions or generated implementations were renamed.

Only existing files and the offline index were inspected. No game, build,
replay, live memory capture, debugger attachment or runtime setting change was
performed. Main instruction words were checked by the earlier index extraction;
this pass refreshes annotations without re-extracting the graph. Overlay jump
table bytes were not independently verified, so possible switch destinations
are distinguished from proven numeric case assignments.

`Confirmed/static` establishes the narrow stated mechanics. `Probable` marks
remaining semantic inference. Neither establishes an original symbol name,
a safe replacement contract, or a measured performance cause.

## 1. Gameplay UI dispatch and state management

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6DEEA0](../recomp/config/output_ovl/o2/o2_006DEEA0_0x6deea0.cpp) | `gameplay_ui_update_dispatch` | Probable UI semantics; dispatch explicit | Gated by byte 0x4BAE33. Selects actor at 0x4A5C30 with stride 0x10E0, using selected id 0x4BADED when 0x1B0310 permits. Reads raw UI byte 0x755EC4 and jumps through six-slot table 0x7429F0 at 0x6DEF54. Possible source destinations include the opening/eligibility path, a three-way subpage path (0x6E1B30/0x6E6400/0x6E60A0), and calls to 0x6E6710, 0x6ECDE0 and 0x6ED6D0. Raw type 4 -> 0x6ECDE0 is supported by the historical menu investigation; this pass has not verified all table slots. |
| [o2 0x6E0EC0](../recomp/config/output_ovl/o2/o2_006E0EC0_0x6e0ec0.cpp) | `get_ui_type_minus_one` | Confirmed/static | Returns unsigned byte 0x755EC4 minus one in the return delay slot. Raw zero therefore produces signed 32-bit -1, not zero. A caller-visible type from this getter must not be confused with the raw dispatcher byte. |
| [o2 0x6E1430](../recomp/config/output_ovl/o2/o2_006E1430_0x6e1430.cpp) | `close_gameplay_ui_candidate` | Probable cleanup semantics | Clears bit 0x8000 of selected actor +0xBA0, performs cleanup that depends on raw UI type, clears type 0x755EC4, gate 0x4BADEE, calls 0x6D8100(0), then 0x6DF230. Type-1 and type-2 branches have extra side effects; this is not merely a type-byte setter. |
| [o2 0x6DF230](../recomp/config/output_ovl/o2/o2_006DF230_0x6df230.cpp) | `reset_ui_aux_flags_and_callback` | Confirmed/static mechanics; callback meaning unknown | Calls 0x1AFA70 with pointer 0x6EA050, then clears bytes 0x4BAE80 and 0x4BAE81. Also called during UI entry and auxiliary processing, so a whole-menu initialization name would be too broad. |
| [o2 0x6DED50](../recomp/config/output_ovl/o2/o2_006DED50_0x6ded50.cpp) | `cycle_ui_subpage_candidate` | Probable UI role; modulo-three operation explicit | Consumes direction byte 0x759CA0. Value 1 advances byte 0x759C9E modulo three; value 2 decrements with 0 -> 2 wrap. Saves old selection to 0x759C9F, calls 0x6DED00 and 0x1B8820, then clears direction 0x759CA0. Root dispatch subsequently selects a subpage using the new byte. |
| [o2 0x6DED00](../recomp/config/output_ovl/o2/o2_006DED00_0x6ded00.cpp) | `reset_ui_state_for_previous_subpage` | Confirmed/static mechanics; subpage interpretation probable | Reads 0x759C9F. For values 0, 1 or 2 clears 0x755EC0..0x755EC3 and 0x759C94. Other values return without those writes. Called after the previous selection is saved by 0x6DED50. |
| [o2 0x5F1D80](../recomp/config/output_ovl/o2/o2_005F1D80_0x5f1d80.cpp) | `actor_ui_open_eligibility_candidate` | Probable role; multi-valued predicate explicit | Returns zero for actor +0xBD0, global 0x4BAE8D or bit 0 of 0x4BAE89, actor +0xBA0 mask 0x160, action +8 !=1, or excluded +9 states. Accepted cases return 1 when mask 0x480 is clear and 2 when set. The root UI path sometimes accepts any nonzero result and sometimes requires exactly 1; do not reduce this to a Boolean. |

The [earlier menu-return investigation](M2_MENU_RETURN_INVESTIGATION.md) supplies
historical raw-type-4 context. This pass adds no live menu measurement. The
raw-byte/getter distinction is explicit in the instructions even without the
overlay's switch-table data.

## 2. Actor messages, saved transforms and a selected-actor statistic

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x67E230](../recomp/config/output_ovl/o2/o2_0067E230_0x67e230.cpp) | `serialize_actor_state_message_candidate` | Probable message semantics; packing explicit | Checks 0x1B0310, global 0x4BADF8 and actor ownership/flags. Uses low byte of argument a1 as a selector into table 0x740710 for values <16. One branch builds a 0x2C-byte record at sp+0x50: selector/length, action bytes +8..+0xB, position +0x38..+0x40, yaw +0x92, flags +0xBA0 and other state. Other branches pack shorter records and some update local actor state. Routes records through 0x1AFDD0 with actor id+1 or translated id. Duplicate-selector suppression via 0x744638 occurs on particular paths; no claim that every message is deduplicated. This is not a pose evaluator or general render dispatcher. |
| [0x1AFDD0](../recomp/config/output/sub_001AFDD0_0x1afdd0.cpp) | `route_state_message_by_session_mode` | Probable message semantics; mode routing explicit | Preserves four arguments around 0x1B0300. Mode 0 forwards to guest target 0x811190; mode 1 forwards to 0x810870; modes 2 and 3, and other unmatched values, return without those calls. Target addresses alone do not establish overlay residency, wire format, delivery, or a socket-send contract. |
| [o2 0x667370](../recomp/config/output_ovl/o2/o2_00667370_0x667370.cpp) | `save_actor_position_and_yaw` | Confirmed/static | Copies actor floats +0x38/+0x3C/+0x40 to +0xD94/+0xD98/+0xD9C and signed halfword +0x92 to +0xDA0. No animation decode or interpolation occurs here. |
| [o2 0x6673A0](../recomp/config/output_ovl/o2/o2_006673A0_0x6673a0.cpp) | `clear_saved_actor_position_and_yaw` | Confirmed/static | Zeros the three words +0xD94/+0xD98/+0xD9C and halfword +0xDA0. Paired storage with 0x667370; the gameplay meaning of clearing this saved transform is not established. |
| [o2 0x6673C0](../recomp/config/output_ovl/o2/o2_006673C0_0x6673c0.cpp) | `consume_actor_flag4_with_substate_result` | Confirmed/static mechanics; flag meaning unknown | If actor +0xBA4 bit 4 is absent returns zero. Otherwise clears that bit and halfword +0x520. Substate byte +0xA==0xFF still returns zero; other cases return 1 or 2 according to +0xBA4 bit 0x80. This consumes state and is not a pure animation-status getter. |
| [o2 0x667F90](../recomp/config/output_ovl/o2/o2_00667F90_0x667f90.cpp) | `selected_actor_stat_percent_candidate` | Probable statistic meaning; arithmetic explicit | Always resolves selected actor from 0x4BADED, not a caller-supplied actor pointer. Converts unsigned actor word +0xBAC and unsigned reference table 0x71ADB0[actor byte +0xB98] to float, returns 100 * value/reference. Health versus another gameplay statistic is not proved, nor are reference-table contents or zero-denominator reachability. |
| [o2 0x668C80](../recomp/config/output_ovl/o2/o2_00668C80_0x668c80.cpp) | `classify_selected_actor_stat_percent` | Confirmed/static thresholds; statistic meaning unknown | Calls 0x667F90. Returns 3 for ordered values >=90, 2 for >=80, 1 for >=50, otherwise 0. The actual branch sequence also sends NaN to 3 because the first less-than comparison fails. It classifies the selected actor's statistic even when its caller is packing a different actor's record; no health/infection name is asserted. |

Important ownership distinction: several actor-state routines accept an actor
pointer, while 0x667F90 reads the selected global actor. Replacing the latter
with a calculation on the incoming pointer would change behavior. Whether the
original cross-actor use is intentional requires caller and runtime evidence.

## 3. File sizes, cached descriptors and path helpers

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x13B330](../recomp/config/output/sub_0013B330_0x13b330.cpp) | `htCiGetFileSize_candidate` | Probable original API name; size query explicit | Error strings at 0x23CE58 and 0x23CF98 explicitly contain htCiGetFileSize. First queries 0x13C7E8 into a two-word stack record and returns its size when nonzero. Otherwise builds a path with 0x13BE80, opens with flag 1, seeks to offset 0 with modes 0 then 2, closes, and returns end offset. Null/open/seek/close errors retain separate paths and diagnostics; zero is not unambiguously a successful empty file. |
| [0x13B528](../recomp/config/output/sub_0013B528_0x13b528.cpp) | `query_descriptor_size_by_seek` | Confirmed/static | Takes an existing descriptor, seeks to zero with mode 0, then mode 2, returns the nonnegative result or zero on failure. Does not close the descriptor and leaves its position at the resulting end; not a pure metadata-only query. |
| [0x13C3A0](../recomp/config/output/sub_0013C3A0_0x13c3a0.cpp) | `open_cache_file_descriptor_table_candidate` | Probable structure meaning; bounded enumeration explicit | Caps positive input count at 13 and visits names in caller data using layout words at 0x21DE98/0x21DE9C. Opens each name with flag 1, stores descriptor and 0x13B528 size in 8-byte entries, closes the initial descriptor then reopens with configured flag 0x21DEA0. Returns number of initial successful opens. Strings at 0x23D158..0x23D1B8 describe cache-file open totals/errors. Reopen failures are not separately subtracted by this loop, so the count is not proof that every retained descriptor is usable. |
| [0x13C7E8](../recomp/config/output/sub_0013C7E8_0x13c7e8.cpp) | `lookup_configured_cache_file_record` | Probable cache interpretation; wrapper explicit | Clears both output words. If configured pointer at 0x21DE90 is nonzero, tail-calls 0x13C6F8(output,name,table,count at 0x21DE94). That callee compares names and copies a matching 8-byte record, or zeros it on a miss. Used before the open/seek fallback in 0x13B330. |
| [0x13BE80](../recomp/config/output/sub_0013BE80_0x13be80.cpp) | `build_configured_host_file_path` | Probable configuration meanings; normalization explicit | Builds destination string from optional device prefix 0x21DFB0 and input. When 0x13BE28 reports host prefix, appends directory 0x21DEA8 and an optional separator before the input. Final byte loop replaces backslashes with forward slashes. No destination capacity argument is enforced by this body. This is path assembly, not a file read. |
| [0x13BDB8](../recomp/config/output/sub_0013BDB8_0x13bdb8.cpp) | `path_has_colon_in_first_16_bytes` | Confirmed/static | Gets full string length, caps scan length at 16, returns 1 if a colon occurs within that prefix and 0 otherwise. A colon outside the prefix is not accepted. No generalized absolute-path or device-validation contract is established. |
| [0x13BE28](../recomp/config/output/sub_0013BE28_0x13be28.cpp) | `path_starts_with_host_prefix` | Confirmed/static narrow prefix | Zeroes six stack bytes, copies the first four input bytes, compares against verified main-ELF string host at 0x23D148 through 0x10AE78, returns comparison==0. Does not require a following colon and reads four input bytes regardless of earlier NUL. |
| [0x10ABB8](../recomp/config/output/sub_0010ABB8_0x10abb8.cpp) | `strcat_candidate` | Probable library identity; concatenation explicit | Finds destination's terminating zero using aligned vector/64-bit or byte scan, then calls 0x10AFC0 at that cursor with the original source; returns original destination. Bounds, guest memory access and packed-instruction behavior still matter to any replacement. |
| [0x10AFC0](../recomp/config/output/sub_0010AFC0_0x10afc0.cpp) | `strcpy_candidate` | Probable library identity; NUL copy explicit | Copies aligned 16/8-byte chunks only while the zero-detection mask permits, then copies remaining bytes including NUL, returns original destination. The generated file also contains a separate helper beginning 0x10B0D8; it is not part of this string copy. |
| [0x10B158](../recomp/config/output/sub_0010B158_0x10b158.cpp) | `strlen_candidate` | Probable library identity; length operation explicit | Scans aligned 16/8-byte chunks for zero with byte fallback; returns terminator pointer minus input in the return delay slot. Wider reads and guest aliases must be preserved or justified before substitution. |
| [0x10AE78](../recomp/config/output/sub_0010AE78_0x10ae78.cpp) | `strcmp_candidate` | Probable library identity; comparison explicit | Skips equal aligned chunks until a zero or difference, then compares bytes. Final subtraction uses unsigned bytes from each string and returns zero for equal NUL-terminated strings. Vector fast-path memory reads still preclude an unreviewed host substitution. |

The original size-query name is supported by owned-ELF strings, unlike the
research names assigned from behavior alone. These helpers expose file-table
and position side effects which an eventual optimized loader must account for.

## 4. Scenario archive setup, lookup and synchronous member reads

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1AA1E0](../recomp/config/output/sub_001AA1E0_0x1aa1e0.cpp) | `ensure_scenario_archive_and_name_index` | Probable archive format semantics; paths and waits explicit | Uses descriptor at 0x2B16A0, cached scenario id +0x1C and buffer +8. Requires global buffer pointer 0x32444C: its null branch enters a NOP loop at 0x1AA228 that does not reload the pointer. On the valid path sets header area to buffer+0x6000. Verified strings select rfff/rfff.afs with RFFF_H.BIN for 0xFFFF, or scenario/r%03d/r%03d.afs with R%03d_H.BIN. Calls archive setup 0x1A9D60, obtains header-member index, retries 0x129240 until nonzero, starts read through 0x1297A0 and polls 0x129D48 until status 3, then closes. Header words populate descriptor +0x18/+0x14 and name-table cursor advances eight bytes. No timeout or timed sleep is visible in these loops. |
| [0x1A9D70](../recomp/config/output/sub_001A9D70_0x1a9d70.cpp) | `find_archive_member_index_by_name` | Probable archive role; search explicit | Descriptor first word chooses between delegated lookup 0x1AB050 and a local name table. Local branch calls 0x10CDA8 on copied input, extracts a final path component with 0x10B7B8, replaces slash/backslash/dot/hyphen with underscore, compares against successive 16-byte names at descriptor +0xC. A match returns table index + descriptor +0x18, no match returns -1. Case normalization and delegated-branch behavior are not fully recovered. |
| [0x1A9F20](../recomp/config/output/sub_001A9F20_0x1a9f20.cpp) | `read_archive_member_blocking_candidate` | Probable read contract; polling explicit | If argument a3==0 resolves a1 by 0x1A9D70; otherwise treats a1 as an index. Returns zero for -1. Repeatedly calls 0x129240(descriptor.+0x20,index) until nonzero, takes 0x129C08 result as transfer count, calls 0x1297A0(handle,count,destination), then polls 0x129D48 until 3. May call 0x1AFCE0 during polling depending on 0x1A9750 result, closes with 0x129350 and clears global handle 0x2B16A8. Returns count<<11, consistent with 2048-byte sector units; not proven exact unpadded file length. |
| [0x1AA3E0](../recomp/config/output/sub_001AA3E0_0x1aa3e0.cpp) | `load_current_scenario_member_by_name` | Probable archive role; adapter explicit | Ensures archive for halfword 0x3243DA, then calls 0x1A9F20(global descriptor, original a0, original a1, 0). Original a0 is name and a1 destination on the inferred contract. A separate adapter at 0x1AA430 is present in the same generated source as well as its own file. |
| [0x1AA430](../recomp/config/output/sub_001AA430_0x1aa430.cpp) | `load_current_scenario_member_by_index` | Probable archive role; adapter distinction explicit | Same setup and argument preservation as 0x1AA3E0, but passes final argument 1 to 0x1A9F20, bypassing the name-to-index lookup. This flag difference is in call delay slot 0x1AA468; the adapters are not identical aliases. |

The resulting static path is:

```text
room/resource loader (for example 0x1AA4C0)
  -> 0x1AA3E0(name, destination)
       -> 0x1AA1E0(current scenario): ensure archive + name index
       -> 0x1A9F20: resolve member, obtain handle, read, wait, close
            -> 0x1A9D70: local/delegated filename lookup
            -> 0x129240 / 0x1297A0 / 0x129D48 / 0x129350
```

The null-buffer branch at 0x1AA228 is a fixed spin on a failed prerequisite,
not a live poll that could observe a later pointer update. The handle/status
loops actually call their APIs again. Those are original guest polling loops, distinct from host ISO-read latency,
the previously mapped fixed delay at 0x137610, and frame-completion waits.
Their existence identifies places to measure handle acquisition, status
progress and lock ownership later. It does not prove that a particular loop
was active during a slowdown. Forcing status 3, skipping the loop, or releasing
a guest lock without proving callback ownership would change behavior and is
not justified by this mapping.

## 5. Transform composition and a correction to pass 2

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x193A00](../recomp/config/output/sub_00193A00_0x193a00.cpp) | `compose_transform_with_external_scale` | Probable transform convention; arithmetic explicit | Reads three scale-like floats at a1+0/+4/+8, multiplies by external f12/f13/f14 and initializes destination through 0x18FE60. Builds a shared-template temporary, calls 0x190A10 with a1+0xC/+0x10/+0x14, then builds another temporary with reciprocal external scales on its diagonal and a1+0x18/+0x1C/+0x20 in its fourth vector. Calls 0x191300 twice on destination, returns 1. No zero-scale guard is visible; matrix convention and template contents remain dependencies. |
| [0x193AF0](../recomp/config/output/sub_00193AF0_0x193af0.cpp) | `compose_transform_with_reciprocal_external_scale` | Probable transform convention; difference explicit | Same rotation/translation temporary construction and reciprocal-scale diagonal as 0x193A00, but initializes destination using a1's first three floats directly, without multiplying them by external f12/f13/f14. Returns 1. Do not collapse the two functions into one identical transform operation. |

The previous `rotate_matrix_x_candidate` annotation for **0x190A10** was too
narrow. The X-axis operation continues straight into Y at 0x190A98 and Z at
0x190B18; the first return is at 0x190B98. A separate entry starts at 0x190BA0.
[Pass 2](SYMBOLS_GAMEPLAY.md) now calls the existing entry
`rotate_matrix_xyz_euler_candidate` and preserves uncertainty about conventions.
This is a corrected annotation, not an additional mapped entry or a source fix.

## 6. Script continuation helpers

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x68CD80](../recomp/config/output_ovl/o2/o2_0068CD80_0x68cd80.cpp) | `script_handler_return_zero` | Confirmed/static; opcode assignment unverified | Only returns zero in the delay slot. Under the 0x68C660 handler protocol a zero result can permit default cursor advancement; the handler itself neither advances the cursor nor establishes a fixed command size. Table 0x717830 contents have not been independently verified for its opcode assignment. |
| [o2 0x68D0B0](../recomp/config/output_ovl/o2/o2_0068D0B0_0x68d0b0.cpp) | `script_restore_saved_continuation` | Probable saved-continuation role; copy explicit | Uses active script-slot byte 0x4BADC1, copies word from 0x4BAD28[slot] to current cursor 0x4BACE0[slot], returns 1. The dispatcher treats opcodes 0xA/0xD specially, but mapping this helper to one numeric opcode requires the original table bytes. |
| [o2 0x68D2A0](../recomp/config/output_ovl/o2/o2_0068D2A0_0x68d2a0.cpp) | `script_advance_to_next_entry` | Probable script-entry semantics; indexing explicit | Uses byte 0x4BADC1, increments per-slot index at 0x4BAD10[slot], loads a pointer from table 0x4BAD40[slot] at that index, stores it to 0x4BACE0[slot], returns 1. No explicit bounds check appears in this helper. Numeric opcode assignment remains unverified. |

The dispatcher indexes handlers using the low 24 bits of a command word and
derives default cursor advance from its high byte. A callback count, handler
return, command byte length and original game update count are distinct values.

## Next useful evidence

- Recover owned overlay data for tables 0x712BD0 (actor actions), 0x740710
  (actor message selectors), 0x7429F0 (UI cases) and 0x717830 (script handlers),
  checking edition, image identity, load base and relocation before assigning
  numeric cases. No live process reads are needed for that static step.
- Follow archive handle/status implementations to distinguish guest work,
  callback progress and backend waiting. Later runtime instrumentation needs
  phase timing and lock ownership; current playtesting was not interrupted.
- Determine writers and units of actor +0xBAC, reference table 0x71ADB0, and
  the globals used by UI eligibility. Keep health/infection and page names
  tentative until those relationships are established.
- Verify shared matrix template 0x294E00 and arithmetic conventions before
  expressing transforms as native math or changing their evaluation order.

No optimization or causal performance improvement is claimed by this pass.
