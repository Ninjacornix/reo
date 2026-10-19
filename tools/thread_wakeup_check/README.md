# Original CRI WakeupThread handshake regression

Run only when the coordinator permits compilation and the game is closed:

```powershell
cmd /c tools\thread_wakeup_check\run.bat
```

An optional first argument selects an existing PS2Recomp CMake build directory.
The tool links the already-built Release runtime and compiles only its own
fixture and five existing generated guest functions. It does not rebuild or
launch the native game, initialize a graphics window, or open an audio device.
Output stays in ignored `build-ninja/thread_wakeup_check`.

The core regression calls the existing generated `sub_0012BF98_0x12bf98`,
including the original `0x114520` ReferThreadStatus and `0x114550` WakeupThread
syscall wrappers. It puts a target in the real production SleepThread wait,
sets the original service request at `0x21049C`, and checks that the original
guest function clears it after waking the target selected by `0x2104E8`.
An additional original-function case covers a suspended sleeping target;
controls cover a ready target and absence of a service request.

Both normal and interrupt wake entrypoints also exercise zero, self, unknown
and dormant errors; queued wakes consumed by the next real SleepThread;
and actual blocked targets released within a two-second deadline. Thread-map
fixtures avoid booting the game or introducing unrelated scheduler behavior.

Coordinator validation on 2026-10-11 reproduced the old-library baseline:
28/34 assertions passed. The six failures were four successful
normal/interrupt wake return values and the original blocked/suspended
handshake's two service-request clears. All wake releases and error controls
passed. After rebuilding the runtime with the narrow return correction,
the same original-function regression passed 34/34. Recorded logs:

- `build-ninja/m2-wakeup-original-handshake-baseline.log`
- `build-ninja/m2-wakeup-original-handshake-corrected.log`

The coordinator first corrected two fixture macro argument parentheses;
the same resulting harness was used for both library comparisons.

Original assembly was read through Ghidra's `/ps2/SLUS_207.65` program:
`0x12BFEC` calls WakeupThread, `0x12BFF4` reloads the target id, and
`0x12BFF8` compares it with the returned value; only the branch-likely delay
slot at `0x12BFFC` clears the pending request. The primary
[Play! EE kernel implementation](https://github.com/jpd002/Play-/blob/master/Source/ee/PS2OS.cpp)
also returns the target id from successful WakeupThread/iWakeupThread.

This regression establishes the handshake's kernel return contract. Native
gameplay and audio acceptance after this correction remain pending. It does
not establish that this discrepancy caused the long graphics/audio pauses.
