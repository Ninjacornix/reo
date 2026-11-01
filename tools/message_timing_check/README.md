# Mod-controlled timed messages (#25)

`examineMessages.durationMultiplier` in gameplay mod JSON controls original
timed script messages for either supported game. No launcher option is added.
The default remains original timing. See [mod format](../../docs/MODDING.md#examine-message-timing).

| Original service | File #1 | File #2 |
| --- | --- | --- |
| Timed-message task | `6B6880` | `6E43E0` |
| Task configuration wrapper | `6B9F30` | `6E75C0` |
| Script message renderer | `6BA070` | `6E7700` |
| Queue allocator | `1B46E0` | `1400D0` |
| Queue update | `1B3E00` | `13F7F0` |
| Queue records (32, stride `8C`) | `3151D0` | `2F3D10` |

The task's signed halfword at `+0C` and each queue record's signed halfword at
`+6` independently expire. Extending only the queue leaves the original task's
completion time unchanged. The resident allocator hook verifies the complete
task -> wrapper -> renderer -> normal enqueue guest frame chain and its original
JAL/load/store instructions. A successful allocation extends its line and the
task; subsequent lines do not multiply the task again. Failed allocations do
not extend an invisible task. Guest frames retain provenance across yields.
The original cancellation helper still clears lines and frees the task.

This is a shared timed-message path, including examine text and system notices.
It is not a universal classifier for every scenario's text. Spoken producers
and choice/menu paths lack this task chain and retain their original timing.
Directly registering a handler override would be insufficient because the
runtime resolves resident overlay functions before ordinary registrations.

Run portable controlled checks without game data:

```sh
python tools/message_timing_check/run.py --compiler c++
```

With locally generated game sources and original imported data, execute the
original task, wrappers, queue allocator/update and cancellation routines:

```sh
python tools/message_timing_check/run.py --owned-queue --compiler clang++ --data-file1 "<File 1 import>/data" --data-file2 "<File 2 import>/data"
```

The tool verifies the supported ELF hashes and each generated instruction comment
against original ELF segments or gameplay `BIN/2.DAT` before compiling. Its
generated test inputs, original instruction witnesses, logs and receipts stay in
ignored `build-ninja/message-timing-check/`. String-copy/comparison, the system
string lookup and unrelated engine/audio services use controlled callbacks;
coordinates use exactly representable integers. These checks establish task and
queue behavior, not live scenario completion or a GPU-pixel inspection.

Coverage includes defaults, bounded configuration, fractional rounding, saturation,
both string banks, multiline consistency, start delay, guest preemption/resume,
expiry, cancellation, failed allocation, malformed frame pointers, original-code
witness rejection and speech/menu exclusions. The existing subtitle checker
separately covers visibility and IPC. No analysis engine or configuration was
installed; original opcode comments and owned instruction bytes supply the mapping
evidence.
