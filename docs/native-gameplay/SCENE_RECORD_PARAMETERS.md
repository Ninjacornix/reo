# Scene-record parameter command and reception

Opcode `166` now executes through the native Interpreter, canonical Session
EnemyDescriptors, Update publication sink, ActorMessageQueue and ActorReception.
Both original dispatch tables select `694470`. Its three payload arguments are
narrowed independently to bytes. Complete `5A8F40` scans only the imported count,
changes the first row whose condition and parameter23 match, and stores the new
expanded-record byte `2E`. The native field is `EnemyDescriptor::parameter2e`;
its wider gameplay meaning is not inferred from this command alone.

Complete `680FB0` permits notification only in session message phase 1 or 2.
Complete `1AFDD0` routes world mode 0 or 1 to a channel 5, type 6, length 6
message with ordinal/value in bytes 4/5, options 0 and dispatch mode 4. Other
phases and modes retain the local write without needing a transport. Routed
programs require an actual ready sink before any script instruction executes.
A present sink rejecting a send preserves the local write and completes the
command, matching the original ignored return; the helper result reports that
rejection separately. Missing capability refuses before mutation.

The actual `67DD40` channel 5 receiver case 6 gates on message phase 1/2 and
writes the addressed row, including rows beyond the imported count. It applies
no actor, ownership, local-echo or status filter. The native typed queue owns
delivery to that real receiver. `Owner::run_script` supplies the exact sink
retained by StatePublication and refuses a foreign provider before script
execution, so callers cannot accidentally publish through a second transport.

Both compiler full-interpreter comparisons pass **564,131,793 checks** each,
including 4,032 actual ordinary/offline `166` dispatches and 160 initialized
notifications. The separate immutable source builds compare complete sender,
adapter, phase, route and receiver bodies through the real native queue:
217,393,135 checks, 1,120 sender cases, 1,120 adapter cases, 8,352 receiver cases
and nine queue boundaries per compiler. Transport endpoints `811190`/`810870`
are declared capture ports; unrelated original receiver branches throw if used.
No socket or framing protocol is exercised. These frozen comparisons precede
the small Update sink getter/adoption edit; the current parent cohort checks
that composition separately, including successful queue delivery and foreign
provider refusal before an earlier counter write.
Both current compiler cohorts pass all 13 parent tests with unchanged recorded
sources, covering actor construction/initialization, world, archive, script
admission, target metrics, cooperative update, collision, AI and the real queue.

The same full VM cohort extends opcode `73` to all eight owned primary slots,
including selector 4 aliasing selected slots 5–7: 11,340 dispatches, 2,340
declared audio-port calls, 362,880 mixed frames and 5,832 nonzero samples.
The independent audio frontend proof executes complete original `1B8930`;
the VM boundary remains explicit as described in [script audio](SCRIPT_SCENARIO_AUDIO.md).

Native full-Program admission checks all 171 hash-verified owned script banks
against baseline `42b792a2`. Ordinary admission improves from 28 to 31 banks;
offline admission improves from 23 to 26. All five EVBs remain incomplete:

| EVB | Ordinary next refusal (block, offset) | Offline next refusal (block, offset) |
|---|---|---|
| r001 | `170` (2, 1748) | `1A1` (1, 3396) |
| r002 | `156` (1, 3480) | `156` (1, 3480) |
| r028 | `150` (2, 224) | `1A1` (1, 2168) |
| r035 | `150` (2, 156) | `1A1` (1, 2620) |
| r041 | `156` (1, 4844) | `156` (1, 4844) |

Offsets are native block-relative positions, not file offsets or runtime
reachability claims. Coverage is 359 ordinary and 331 offline table entries,
including original no-ops. The [qualification record](../../tools/native_reconstruction/native_scene_record_parameters_qualification_v1.json)
identifies exact frozen receipts and current composition checks. This change
does not establish complete scenario execution, semantic save adoption or an
installed native game session; Stage 4 remains incomplete.
