# CRI backends: disc/host method tables and handle state

Static research, 2026-11-03. File #1 US SLUS-20765, SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
No game, build, attachment, replay or live memory reading was performed.

Unlike unresolved overlay tables, the disc table at **0x21CBF8** and host table
at **0x21DA88** are file-backed main-ELF data. All 26 little-endian words in each
were read from the identity-checked ELF; nonzero targets were checked against
the main catalogue. Factory returns and CVFS caller method offsets corroborate
the relationships. Original bytes/assets are not included in the notebook.

| Method offset | Disc target | Host target | Reviewed caller role |
| --- | --- | --- | --- |
| +0x00 | 0x139798 | 0x13B1D8 | Service callback |
| +0x04 | 0x139810 | 0x13B250 | Register error callback/userdata |
| +0x08 | 0x139928 | 0x13B308 | Filename size query |
| +0x10 | 0x139A50 | 0x13B608 | Open |
| +0x14 | 0x139BD8 | 0x13B790 | Close |
| +0x18 | 0x139C30 | 0x13B840 | Logical sector seek |
| +0x1C | 0x139CC8 | 0x13B8D8 | Tell |
| +0x20 | 0x139D00 | 0x13B910 | Admit read |
| +0x28 | 0x139EA8 | 0x13BAA0 | Stop transfer |
| +0x2C | 0x139FA8 | 0x13BBA8 | State getter |
| +0x30 | 0x139FE0 | 0x13BBE0 | Sector length |
| +0x38 | 0x139FE8 | 0x13BBE8 | Transferred bytes |
| +0x40 | 0x1398A0 | 0x13B268 | Existence query |
| +0x60 | 0x13A180 | 0x13BCF0 | Optional selector channel |

All other words through +0x64 are zero in these two tables. That does not prove
all operations are absent from every other device implementation. See the
[CVFS/ADXF notes](SYMBOLS_CRI.md) for callers and upper-layer state numbering.

The [pinned Code Veronica comparison](recvx-crosscheck/FILESYSTEM_SECOND_PASS.md)
confirms that common interface names do not make these provider bodies equivalent.
CVX dvCi/htCi GetNumTr returns the Seek/Tell cursor times2048 without a state
guard; owned139FE8/13BBE8 instead expose completed sectors only in state1.
CVX's inspected provider tables also have no optional member60, whereas the
owned tables bind the C8..CD high/low operations below. Do not transplant the
older cursor getter or infer unsupported optional command behavior from it.

## Entries and handle helpers

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1395C8](../recomp/config/output/sub_001395C8_0x1395c8.cpp) | `dvci_get_device_interface_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Calls 0x13AE10(0) with existing config value in v1 then returns interface address 0x21CBF8. Factory is registered by original 0x131088; no I/O is directly performed by returning the table. |
| [0x1395F8](../recomp/config/output/sub_001395F8_0x1395f8.cpp) | `dvci_invoke_error_callback_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Preserves incoming a0 as a2, loads callback/userdata from 0x21CBE4/0x21CBE8 and invokes callback(userdata,incoming a1,incoming a0) when nonnull. Not established as a noreturn function. |
| [0x1396D0](../recomp/config/output/sub_001396D0_0x1396d0.cpp) | `dvci_update_handle_from_request_state` | Confirmed/static stated mechanics; original API naming unresolved | Reads request pointer handle+0x1C, enters through 0x141700, gets state via 0x137608 and dispatches ten-slot table 0x23CA60. Verified state 3 stores admitted count +0x10 to completed +0x14, advances cursor +0xC and sets handle state 1; state 9 sets 3; state 0 sets 0. Those terminal cases release request via 0x1373C8 and clear pointer; other states keep it. Leaves through 0x141778. |
| [0x139798](../recomp/config/output/sub_00139798_0x139798.cpp) | `dvci_service_40_handles_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Admission gate 0x142190 uses word 0x21CBF0; when admitted scans 40 records at 0x21CC60 stride 0x48 and updates active ones through 0x1396D0, then clears gate. Interface slot +0 is a service callback, not necessarily module initialization. |
| [0x139810](../recomp/config/output/sub_00139810_0x139810.cpp) | `dvci_set_error_callback` | Confirmed/static stated mechanics; original API naming unresolved | Stores a0 callback at 0x21CBE4 and a1 userdata at 0x21CBE8. Verified interface slot +4; no callback is invoked here. |
| [0x1398A0](../recomp/config/output/sub_001398A0_0x1398a0.cpp) | `dvCiIsExistFile_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface slot +0x40. Checks file cache through 0x13AA00, otherwise normalizes name, waits for disc sync and searches through 0x139628; returns 1 for successful metadata lookup, zero on miss/null. Cache/sync/search are distinct work. |
| [0x139928](../recomp/config/output/sub_00139928_0x139928.cpp) | `dvCiGetFileSize_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface slot +8. Uses cached file metadata or disc-search fallback; returns metadata +4 byte-size word, zero for miss after diagnostics. Error text explicitly contains dvCiGetFileSize. Verified main-ELF string reference(s): 0x23CA88, 0x23CAE0. |
| [0x1399F8](../recomp/config/output/sub_001399F8_0x1399f8.cpp) | `dvci_find_last_free_handle_slot` | Confirmed/static stated mechanics; original API naming unresolved | Scans all 40 records at 0x21CC60 stride 0x48 and overwrites candidate for each zero first byte, returning the last free record or null. Does not mark reservation; do not implement first-free behavior as an exact equivalent. |
| [0x139A30](../recomp/config/output/sub_00139A30_0x139a30.cpp) | `dvci_clear_handle72` | Confirmed/static stated mechanics; original API naming unresolved | Tail-calls zero fill of 0x48 bytes at input record. Does not issue a disc cancel/close itself. |
| [0x139A50](../recomp/config/output/sub_00139A50_0x139a50.cpp) | `dvCiOpen_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x10. Rejects null filename/nonzero a2, selects free 72-byte record, uses cached metadata or disc-search fallback. Initializes byte size +4, rounded-up sector count +8, cursor/request/completion fields and active flag. Cache mode can use 0x7FFFFFFF sector sentinel. Verified main-ELF string reference(s): 0x23CB10, 0x23CB60, 0x23CB90, 0x23CBB8. |
| [0x139BD8](../recomp/config/output/sub_00139BD8_0x139bd8.cpp) | `dvCiClose_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x14. If handle state >=2 first stops transfer through 0x139EA8; clears active flag and zeroes record through 0x139A30. Null input is ignored. |
| [0x139C30](../recomp/config/output/sub_00139C30_0x139c30.cpp) | `dvCiSeek_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x18. Updates sector cursor +0xC using origin 0/1/2, clamps to 0..sector size +8 and clears completed count +0x14. No underlying host seek is issued in this body. Verified main-ELF string reference(s): 0x23CBE8. |
| [0x139CC8](../recomp/config/output/sub_00139CC8_0x139cc8.cpp) | `dvCiTell_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x1C. Returns sector cursor +0xC or zero after null diagnostic. Distinct from byte-size accessor. Verified main-ELF string reference(s): 0x23CBE8. |
| [0x139D00](../recomp/config/output/sub_00139D00_0x139d00.cpp) | `dvCiReqRd_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x20. Rejects null/negative/missing-buffer and busy state 2, marks zero request as state 1. Otherwise obtains SRD request 0x137340, clamps to remaining sectors, stores read-mode/buffer fields, starts via 0x137468. Configured synchronous mode runs disc sync and server steps, otherwise sets state 2. Return is admitted sector count. Verified main-ELF string reference(s): 0x23CBE8, 0x23CC20. |
| [0x139EA8](../recomp/config/output/sub_00139EA8_0x139ea8.cpp) | `dvCiStopTr_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x28. For state >=2 marks request break through 0x137868, repeatedly pumps 0x137D80/0x139798/status getter with bounded retry counter, then clears completion and sets state 0. It actively drives server work, unlike a pure status-byte getter. Verified main-ELF string reference(s): 0x23CBE8. |
| [0x139FA8](../recomp/config/output/sub_00139FA8_0x139fa8.cpp) | `dvCiGetStat_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x2C. Returns signed handle state byte +2, or zero after null diagnostic; no server pump occurs here. Backend state 1 is completed in the reviewed updater, 3 error, unlike ADXF status numbering. Verified main-ELF string reference(s): 0x23CBE8. |
| [0x139FE0](../recomp/config/output/sub_00139FE0_0x139fe0.cpp) | `dvCiGetSctLen_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x30 returns constant 0x800 (2048). Slot and caller establish sector-length meaning; this narrow function has no handle access. |
| [0x139FE8](../recomp/config/output/sub_00139FE8_0x139fe8.cpp) | `dvCiGetNumTr_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x38. Only for backend state 1 returns handle completed-sector count +0x14 shifted 11 into byte count, otherwise zero. Null input diagnoses and returns zero. Verified main-ELF string reference(s): 0x23CBE8. |
| [0x13A088](../recomp/config/output/sub_0013A088_0x13a088.cpp) | `dvci_query_file_size_by_name_extended_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Uses file cache or search fallback and returns metadata byte size +4 without the public null/error path of 0x139928. Called by optional size-query adapter 0x13A168. Verified main-ELF string reference(s): 0x23CAB8. |
| [0x13A130](../recomp/config/output/sub_0013A130_0x13a130.cpp) | `dvci_transferred_byte_count_high32` | Confirmed/static stated mechanics; original API naming unresolved | Returns signed high 32 bits of sign-extended completed-sector word +0x14 shifted left 11. Optional selector 0xC8 calls this helper. |
| [0x13A140](../recomp/config/output/sub_0013A140_0x13a140.cpp) | `dvci_transferred_byte_count_low32` | Confirmed/static stated mechanics; original API naming unresolved | Same sector-to-byte expression, returns sign-extended low 32 bits after mask/shift. Optional selector 0xC9 uses it; preserve signed return-register convention when composing 64-bit values. |
| [0x13A160](../recomp/config/output/sub_0013A160_0x13a160.cpp) | `dvci_file_size_high32_zero_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Returns zero; optional size-query selectors 0xCA/0xCC route here. Slot context supplies high-word role, not this two-instruction body alone. |
| [0x13A168](../recomp/config/output/sub_0013A168_0x13a168.cpp) | `dvci_file_size_low32_query_adapter_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Tail-calls 0x13A088 with incoming arguments. Optional selectors 0xCB/0xCD use it, so a0 may be a filename rather than a normal open-handle pointer for this selector. |
| [0x13A180](../recomp/config/output/sub_0013A180_0x13a180.cpp) | `dvci_optional_operation_dispatch` | Confirmed/static stated mechanics; original API naming unresolved | Interface +0x60. For nonnull a0 routes 0xC8/0xC9 to transfer high/low, 0xCA or 0xCC to zero high-size helper, 0xCB/0xCD to low file-size query, 0x12B to result 1; unrecognized including 0x12C returns zero. Null a0 returns zero, so path-rewrite capability selector 0x64 is not enabled by this table. |
| [0x13AF60](../recomp/config/output/sub_0013AF60_0x13af60.cpp) | `htci_get_device_interface_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Calls 0x13CA18(0), then 0x13CAA8(0), returns interface 0x21DA88. Original 0x131338 registers this factory; configuration side effects precede the table return. |
| [0x13AFC8](../recomp/config/output/sub_0013AFC8_0x13afc8.cpp) | `htci_invoke_error_callback_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Loads callback/userdata from 0x21DA7C/0x21DA80, preserves input a0 in a2 and invokes callback when present. Different globals from disc backend; not simply printf. |
| [0x13B110](../recomp/config/output/sub_0013B110_0x13b110.cpp) | `htci_update_handle_from_request_state` | Confirmed/static stated mechanics; original API naming unresolved | Reads request +0x2C, enters 0x141700, gets 0x137608 state and dispatches verified table 0x23CE30. State 3 copies admitted sectors +0x24 to completed +0x28, advances cursor +0x1C, sets state 1; state 9 sets 3; state 0 sets 0. Releases terminal request and clears pointer; other states remain pending. Leaves through 0x141778. |
| [0x13B1D8](../recomp/config/output/sub_0013B1D8_0x13b1d8.cpp) | `htci_service_13_handles_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Admission uses word 0x21DA84; scans 13 records at 0x21DAF0 stride 0x30 and calls 0x13B110 for first byte==1, clears gate after scan. Backend service work, not a plain initialization callback. |
| [0x13B250](../recomp/config/output/sub_0013B250_0x13b250.cpp) | `htci_set_error_callback` | Confirmed/static stated mechanics; original API naming unresolved | Stores callback a0 at 0x21DA7C and userdata a1 at 0x21DA80, interface +4. |
| [0x13B268](../recomp/config/output/sub_0013B268_0x13b268.cpp) | `htCiIsExistFile_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x40. Returns true for cached nonzero-size record; otherwise builds path, opens flag 1 then closes and returns 1 if open succeeded. Null/miss returns zero; empty-file/cache semantics remain distinct. |
| [0x13B308](../recomp/config/output/sub_0013B308_0x13b308.cpp) | `htci_get_file_size_signed32_adapter` | Confirmed/static stated mechanics; original API naming unresolved | Interface +8 calls already mapped 0x13B330 size query, then explicitly sign-extends its low 32 bits before return. Not a new independent file-size algorithm. |
| [0x13B5B0](../recomp/config/output/sub_0013B5B0_0x13b5b0.cpp) | `htci_find_last_free_handle_slot` | Confirmed/static stated mechanics; original API naming unresolved | Scans 13 records at 0x21DAF0 stride 0x30; returns the last record with first byte zero or null. Slot is not reserved by this helper. |
| [0x13B5E8](../recomp/config/output/sub_0013B5E8_0x13b5e8.cpp) | `htci_clear_handle48` | Confirmed/static stated mechanics; original API naming unresolved | Tail-calls zero fill for 0x30-byte record. No host close or request stop occurs here. |
| [0x13B608](../recomp/config/output/sub_0013B608_0x13b608.cpp) | `htCiOpen_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x10. Rejects null name/nonzero a2, chooses free record, uses cached descriptor/size or size query plus host open. Stores descriptor +0x18, 64-bit byte size +8, rounded sector count +0x10 and state fields; cached descriptor byte +1 distinguishes ownership for close. Verified main-ELF string reference(s): 0x23CFC8, 0x23D018, 0x23D070. |
| [0x13B790](../recomp/config/output/sub_0013B790_0x13b790.cpp) | `htCiClose_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x14. Stops pending transfer when state >=2, calls host close only when ownership byte +1==0, clears active flag and record. Reusing a cached descriptor must not make it owned by every handle. Verified main-ELF string reference(s): 0x23D098. |
| [0x13B840](../recomp/config/output/sub_0013B840_0x13b840.cpp) | `htCiSeek_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x18. Updates sector cursor +0x1C for origins 0/1/2, clamps to 0..sector count +0x10, clears completed count +0x28. It changes logical request position, not necessarily the host descriptor's current byte offset. Verified main-ELF string reference(s): 0x23D0B0. |
| [0x13B8D8](../recomp/config/output/sub_0013B8D8_0x13b8d8.cpp) | `htCiTell_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x1C returns sector cursor +0x1C or zero after null diagnostic. Backend field layout differs from disc handle. Verified main-ELF string reference(s): 0x23D0B0. |
| [0x13B910](../recomp/config/output/sub_0013B910_0x13b910.cpp) | `htCiReqRd_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x20. Validates handle/count/buffer, checks backend gate and busy state, creates SRD request, clamps sectors to remaining range, prepares byte count/buffer and calls 0x137558 with descriptor/cursor/bytes/destination. Configured synchronous mode pumps server and completes state locally, otherwise records state 2. Return is admitted sectors, not returned bytes. Verified main-ELF string reference(s): 0x23D0B0. |
| [0x13BAA0](../recomp/config/output/sub_0013BAA0_0x13baa0.cpp) | `htCiStopTr_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x28. Requests break if needed, repeatedly calls 0x13AF98/0x137D80/0x13B1D8/status while state remains 2, with retry bound 0x63FFF6, then clears completed count and sets state 0. Stop can perform substantial work; it is not a field-only operation. Verified main-ELF string reference(s): 0x23D110. |
| [0x13BBA8](../recomp/config/output/sub_0013BBA8_0x13bba8.cpp) | `htCiGetStat_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x2C reads signed state byte +2, zero on null diagnostic. It does not pump completion and uses backend 1=completed/3=error context from updater. Verified main-ELF string reference(s): 0x23D0B0. |
| [0x13BBE0](../recomp/config/output/sub_0013BBE0_0x13bbe0.cpp) | `htCiGetSctLen_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x30 returns constant 2048. No host filesystem sector-size query is performed. |
| [0x13BBE8](../recomp/config/output/sub_0013BBE8_0x13bbe8.cpp) | `htCiGetNumTr_candidate` | Probable API/subsystem identity; table and mechanics reviewed | Interface +0x38 returns completed sectors +0x28 shifted 11 only for state 1, otherwise zero. Optional high/low accessors additionally clamp to true byte size; this accessor does not perform that clamp. Verified main-ELF string reference(s): 0x23D0B0. |
| [0x13BC38](../recomp/config/output/sub_0013BC38_0x13bc38.cpp) | `htci_query_file_size_passthrough` | Confirmed/static stated mechanics; original API naming unresolved | Tail-calls 0x13B330 with unchanged arguments. Used by optional size selectors; incoming pointer therefore follows the size-query contract, not universally an open handle. |
| [0x13BC50](../recomp/config/output/sub_0013BC50_0x13bc50.cpp) | `htci_transferred_byte_count_high32` | Confirmed/static stated mechanics; original API naming unresolved | Computes completed sectors +0x28 times 2048 in 64 bits, clamps unsigned against true byte size at +8, returns high 32 bits. Optional selector 0xC8 uses it. |
| [0x13BC70](../recomp/config/output/sub_0013BC70_0x13bc70.cpp) | `htci_transferred_byte_count_low32` | Confirmed/static stated mechanics; original API naming unresolved | Same clamped byte-count calculation; returns sign-extended low 32 bits. Used by optional selector 0xC9. |
| [0x13BCA0](../recomp/config/output/sub_0013BCA0_0x13bca0.cpp) | `htci_file_size_high32_query_adapter` | Confirmed/static stated mechanics; original API naming unresolved | Calls 0x13BC38 and returns arithmetic high 32 bits. Optional selectors 0xCA/0xCC use this adapter. |
| [0x13BCC0](../recomp/config/output/sub_0013BCC0_0x13bcc0.cpp) | `htci_file_size_low32_query_adapter` | Confirmed/static stated mechanics; original API naming unresolved | Calls 0x13BC38, masks/returns sign-extended low 32 bits. Optional selectors 0xCB/0xCD use it. |
| [0x13BCF0](../recomp/config/output/sub_0013BCF0_0x13bcf0.cpp) | `htci_optional_operation_dispatch` | Confirmed/static stated mechanics; original API naming unresolved | Interface +0x60: nonnull a0 with selectors 0xC8/0xC9 -> transfer high/low, 0xCA or 0xCC -> high file-size query, 0xCB/0xCD -> low query, 0x12B ->1. Unsupported selectors including 0x12C and null a0 return zero. Requested operation controls a0's interpretation. |

## Verified completion translations

The ten-entry jump tables at 0x23CA60 (disc) and 0x23CE30 (host) were also read
from the owned ELF. SRD request state 3 advances backend cursor, records completed
count and sets backend state 1. Request state 9 sets backend state 3; state 0
clears backend state to 0. Other admitted state values retain pending request.
Consequently SRD state, CVFS/backend state and ADXF state are separate enums.
The instruction-level getters alone cannot justify assigning one shared enum.

The method-table identities also explain why a generic optional-operation
wrapper cannot type a0 as an open handle for every selector. Some size selectors
ultimately call a filename size query. Unsupported selector 0x12C returns zero
in both dispatchers, while the CVFS size-by-handle API requests it; assess callers
and intended fallback before treating zero as successful file-size evidence.

These are static relationships. Whether a request runs during a recorded hitch,
which thread owns its progress, and how long stop/lookup takes remain runtime
questions. No side effects were removed and no fix was tested by this mapping.

