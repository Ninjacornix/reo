# Resource-wait termination regression

Run `tools\thread_terminate_check\run.bat` from the repository root after building
the Release runtime. An optional first argument selects a different existing
PS2Recomp build directory. The script does not rebuild the runtime or start a
game. Build output and test receipts go to `build-ninja/thread_terminate_check`.

The fixture calls the production `WaitSema`, `WaitEventFlag`, and
`TerminateThread` implementations from `ps2_runtime.lib`. It waits until the
target is sleeping on the resource condition variable, terminates it, and checks
that it unwinds and becomes dormant without changing semaphore counts, event
bits, or resource lifetime. Unknown targets and repeated termination preserve
their errors.

The fixture supplies the host thread's exception boundary and dormant-state
publication; it does not exercise generated guest entry dispatch or the full
`StartThread` wrapper. The internal exit exception has translation-unit-local
type identity, so the boundary catches `std::exception` and checks its exit
message. Production `StartThread` also has a `std::exception` fallback.

Each termination has a two-second deadline. Failure cleanup wakes the actual
resource condition variable without signaling the resource; a process watchdog
bounds any remaining failure to twenty seconds. With the old missing resource
notification, the deadline check fails and cleanup releases the waiter.

Validated on the rebuilt runtime on 2026-10-19: **20/20 checks passed**.
