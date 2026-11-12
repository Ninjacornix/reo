# Canonical launch difficulty and EE predicates

`World::Session::difficulty` now owns source byte `4BAE8A`. It is optional:
generic Session construction does not establish a launch choice. This is
separate from gameplay mode `3243F2`, UI inventory ownership and saved display
options. `NativeSession::import_launch_difficulty` imports an explicit selected
byte while the application is open and idle.

Actual frontend producer `37F330` reads the selection at `318B65` and stores
its byte unchanged to `4BAE8A`. The independent prefix comparison executes its
entry through the first `107AB0` copy call, then explicitly interrupts. It
compares all 256 possible selected bytes with the real NativeSession method,
checks unknown initial state and verifies refusal during real actor retirement
and after close. Both compilers passed 1,542 checks. Later launch copies,
roster, room selection and platform entry are outside this subproducer; the
import method does not impersonate those side effects. Two other producer
sites, `o8:81028C` and `o9:810C9C`, belong to their respective UI flows.

Opcode EE executes the complete `691AE0` predicate policy over that canonical
byte. Both operands and the comparison selector narrow to their low byte.

| Selector | Predicate |
|---|---|
| 0 | current equals authored value |
| 1 | current differs from authored value |
| 2 | current is at least authored value |
| 3 | current is at most authored value |
| 4 | current exceeds authored value |
| 5 | current is below authored value |
| 6 through 255 | false branch without reading difficulty |

The condition counter increments before either path. Failed tests use the
actual native nested-if scan, including else and end-if behavior. Program
admission requires a known difficulty for selectors 0 through 5 before any
script prefix executes. Invalid selectors require no World/difficulty
capability, while the existing offline dispatcher still requires its canonical
flag bank. NativeSession checks difficulty availability before installing a
room program that needs it.

The current 28-parent suite passed on both compilers with no source drift,
including all application import byte values and the final speech/pose schema.
The full original dispatcher matrix covers every pair of current/authored byte
values in the ordinary profile, all six comparisons and invalid selectors,
representative complete byte edges in the offline profile, nested conditions,
missing-difficulty refusal and high-word narrowing.
The final pair passed 577,009,894 checks each, including 605,958 new full
ordinary/offline programs and 13 refusal cases. The earlier ordinary matrix
passed before its first offline test exposed a missing canonical flag provider
in the fixture; that fixture was corrected without changing native semantics.

The actual five-EVB admission pair advances ordinary `r001.evb` from EE at
block 2+3600 to opcode 64 at block 2+4700. Other ordinary frontiers remain D0
and 108; all offline EVBs still stop at 1A8. Across 4,837 authored role0 records,
69 ordinary instructions using 12 distinct opcodes remain unsupported. No
complete EVB becomes admitted: the 171-bank totals remain 34 ordinary and 27
offline. These are static authored counts and actual parser/install results,
not observed dynamic reachability or a claim of complete providers.

The installed game remains the historical gameV39 candidate. Native launch
selection, complete frame terminal services, input/transport/media ownership,
semantic saves and installed acceptance remain Stage4 work.
