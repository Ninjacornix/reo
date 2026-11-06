# Owned LSC queue validation

The native LSC queue/control core is implemented independently of guest memory,
registers, generated functions and the compatibility runtime. It retains sealed
filename copies and range metadata, sixteen records, sequence allocation,
source-control state and shared notification/error/lower-file ports. This is
the queue/control boundary; actual segment I/O and consumer integration remain.

Before native implementation, the original-word oracle froze **53 cases /339
operations**. All returned with **33,211 original instructions**, including
notification callbacks that execute the original enqueue/start/stop bodies.
Both compiler builds reproduce every admitted return, slot, flag, progress
value, stale-slot query and ordered lower-file request. The complete native
projection transcript SHA-256 is
`ac5f12e1d448413d10fd2b423207c26a88e372991711bea3716d17d36e35adb2`.

The original corpus covers full queues, stopped versus active start/stop,
threshold rejection, ring and INT_MAX sequence wrap, exact-one pause and repeat
bytes, lower states0â€“5/255, empty and unsigned-byte filenames, missing handles,
and notifications that enqueue, stop/start, pause, clear repeat or withdraw the
lower handle. Service reloads the head between poll, retire and start. It does
not repeat whole admission or drain arbitrary numbers of entries in one visit.
Native filenames are copied into private immutable storage; borrowed-name
mutation and corrupt queue structures remain outside admission.

Four counterfactual native variants are detected with both compilers:

| Deliberate change | Different operation projections |
| --- | --- |
| Use stale head after retirement | 31 |
| Treat every nonzero repeat byte as enabled | 10 |
| Set waiting state before empty notification | 2 |
| Erase stale records while clearing indices | 5 |

The separate ownership suite passes **111 checks** per compiler with zero
allocations after setup. It checks sealed-name backing independence, bounds,
retention through retirement and stale queries, overwrite release, queue-full
refusal, notification enqueue and nested-service refusal. Callback-safe control
mutations remain admitted. The new suite also builds and passes in both parent
Release projects, which now register 51 suites. The prior 50-suite complete runs
are retained with the regular-loop milestone; only the new independent target
needed another parent check here.

The first original execution stopped at an unsupported BLTZL instruction in the
older shared instruction engine. The scoped oracle adds the two REGIMM likely
forms locally, preserving scheduling/annulment in the existing word runner.
Forty signed64 and immediate-boundary vectors pass. The first frozen inputs and
failed execution remain preserved; the second freeze has identical case bytes
and still records that no native implementation existed. Its actual returned
original corpus, rather than a native-derived expectation, is the comparison
authority.

The [qualification](../../game/native/lsc_queue/qualification.json) retains the
source manifest, original input/word/source identities, native and negative
transcripts, engine vectors and parent build/test identities. Principal receipts:

| Evidence | SHA-256 |
| --- | --- |
| Original returned corpus | `7c4dd9e2532a90a4b2948a29c610d23beb97d59f4171652dfbbd56578d31fb20` |
| Native GCC | `770f2e9cec97f47542ba7c553e90e66a490e176b1358f7e1b92c6402a5a63c19` |
| Native LLVM | `58ffad034c7e897d8f50485b3a7d53aa79a0f18facf9ab3eb347b37ad6e2bcff` |

Lower file calls, diagnostics, strlen and notification dispatch remain explicit
external boundaries in the original execution. The native queue's retained
ports are not proof of actual worker retirement or read completion. Module pool
construction/destruction, actual retained segment publication, seamless decoder
transitions, shared media output, movie controls and game integration remain
required. No game or real audio device was opened. Stage3 and stages4â€“6 remain
unfinished; this work is not a measured stutter fix.
