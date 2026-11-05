# Explicit PCM pre-run reset transaction

Status: implemented public dependency patch0123, independently reapplied as the
full124 series and checked with GCC/libstdc++ and bundled LLVM/libc++. No active
dependency checkout modification, full library build, device or game execution.
Root bootstrap/override integration is a separate change.

## Concrete startup failure addressed

`loadELF()` applies game overrides, and bootstrap applies them again after function
registration. Dependency `applyMatching()` first clears the DTX layout; File #1's
override then sets it. Both layout operations reset the DTX RPC state, including
a public `ps2_cri_audio::reset()`. Under the complete backend dispatch policy,
that public call seals legacy selection. A native installer placed after override
setup therefore always receives `legacy_in_use` before any gameplay.

The fix gives these explicit runtime-owned initialization resets a separate
transaction. It does not permit a late switch after ordinary PCM use and does not
infer safety from empty queues, an environment flag or a saved setting.

## Exact inputs and patch closure

| Input | Identity |
| --- | --- |
| Upstream recorded base | `c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f` |
| Prior full123 receipt | `8f8a001fd50b1bad9c9da8729888b1f682e75c8321bdfd1076da085db52baeb8` |
| New0123 patch SHA-256 | `06e19bf875b015a7119a884811befd08c850d438cfeab38daec791b4762bb145` |
| Fresh full124 receipt | `944b72d4cc977ac01d8e7a4459c601f0a331b06c8adbb5048bec45a2963f91cb` |

Fresh full124 source is
`build-native-sjuni/dependency-pcm-boot-reapply-v3`. Exactly eight existing source
files differ from123; there are no added/removed dependency source files:
`ps2_runtime.h`, `ps2_syscalls.h`, `ps2_runtime.cpp`, `game_overrides.cpp`,
`Kernel/Syscalls/RPC.cpp`, and the three PCM helper files `CriAudio.cpp`,
`CriAudio.h`, `CriAudioDispatch.h`. Prior patch identities and all resulting source
hashes are checked, and the new patch's reverse check passes. Source receipts
exclude `.git` administration. Authoring and full reapplication use separate
private ignored clones; no force application, active checkout reset or local root
commit is involved.

## Runtime-issued setup lease

The real runtime API adds:

```cpp
PS2Runtime::PreRunSetupLease PS2Runtime::acquirePreRunSetup() noexcept;
```

The move-only lease is allocation-free. Acquisition briefly holds the existing
external-worker mutex, rejects a sealed/stopped runtime or count overflow,
increments the setup count and releases the mutex. Moving transfers its one
release obligation. Destruction decrements the count and notifies the setup CV.
The caller must keep the actual runtime alive through the lease and release its
own lease before calling `run()`.

`beginExternalWorkerRun()` waits for zero setup leases with a condition variable
that releases the runtime mutex, then performs the existing sealing logic.
No runtime mutex remains held while reset hooks, registry operations or backend
callbacks execute. `requestStop()` remains a nonblocking signal; a stopped or
sealed runtime refuses new setup leases. `externalWorkerResetAllowed()` also
requires zero setup leases, so an active setup does not admit initialize/loadELF
reset checks.

Existing registered workers alone do **not** refuse a pre-run setup lease. This
matters because a native CD worker may already be registered before post-load
overrides. A setup lease is not itself a worker registration and therefore does
not permanently disable `loadELF()` or imply an installed native owner.

The prior distinction between attached one-shot runtimes and no-worker restart
behavior is retained. This patch does not add a general runtime lifecycle owner,
protect arbitrary concurrent initialization/destruction, or make a raw runtime
reference a strong lifetime token. Existing owner serialization requirements for
initialize/loadELF/run/destruction still apply. In particular, destruction with a
live lease is outside the contract.

## Selection transaction

The PCM helper adds:

```cpp
bool ps2_cri_audio::resetBeforeRuntimeRun(PS2Runtime& runtime) noexcept;
```

It acquires a real runtime setup lease, then reserves `boot_resetting` only while
the PCM registry is unselected and no installation reservation has won. The
actual legacy reset body runs outside both registry and runtime mutexes. An RAII
reservation releases `boot_resetting` and notifies waiting first-use calls after
reset finishes. The setup lease remains live through that release.

The body is the same legacy route/queue/map/clock reset already used by public
reset; it is factored into a private function rather than duplicated. This avoids
turning the helper's own reset into a public first-use operation.

| Concurrent operation | Required outcome |
| --- | --- |
| Ordinary first PCM call during setup | Wait for the setup reservation, then perform its ordinary selection/admission. It still seals legacy if it is the first public call. |
| Installer during reserved setup | Return `installation_busy` before registering any worker. It cannot publish while legacy reset is executing. |
| Runtime `run()` during setup | Wait for setup lease release before sealing the runtime. |
| `requestStop()` during setup | Signal without waiting; refuse new leases and subsequent worker installation. Existing setup can unwind. |
| Installer reservation wins first | Setup helper refuses. Its caller uses ordinary public reset, which seals legacy; the in-progress installer loses publication and retains an inert worker as previously specified. |
| Legacy/native owner already selected | Setup helper refuses; its caller invokes ordinary selected-owner reset. No owner switch or private legacy reset occurs. |

The helper returns true only when it actually performed its initialization reset.
False is not a no-op acknowledgment: the caller must perform ordinary public
reset. Public `reset()` itself is unchanged in meaning and still seals legacy on
first use. Public shutdown also waits a reserved boot reset before making its
normal selection. Queue, render, configure, consumption and every other facade
operation receive no initialization exemption.

Host reset hooks retain their existing no-PCM-reentry contract. The setup helper
may wait for another setup and public first use may wait for reset completion;
this is initialization synchronization, not callback-thread admission.

## Layout caller plumbing

The public syscall declarations become:

```cpp
void setDtxCompatLayout(const PS2DtxCompatLayout&, PS2Runtime* runtime = nullptr);
void clearDtxCompatLayout(PS2Runtime* runtime = nullptr);
```

The existing RPC reset helper accepts the same optional pointer. A nonnull
pointer attempts the explicit setup reset; refusal and null pointers take the
ordinary public reset path. All existing map clears, next-object reset and both
RPC locks remain in place. Assignment and reset semantics are unchanged.

Dependency `applyMatching()` passes `&runtime` to clear; the dependency's RECVX
layout setter likewise passes its actual runtime. Authored File #1/File #2 setters
in root `recomp/overrides/reo_override.cpp` must pass `&runtime` in their separate
integration change. The getter remains the same by-value two-lock snapshot from
0122; it still has no reset or publication effect.

The third reset-helper caller, guest `SifInitRpc`, retains the default-null path.
It is not silently promoted to initialization merely because a runtime pointer
happens to be available in guest code. A setter/clearer called during run also
fails the setup lease check and uses ordinary selected-owner reset.

## Independent checks

[verify.py](../../tools/native_reconstruction/pcm_boot_setup/verify.py) executes
the complete patched `CriAudio.cpp` with provider/gain/bank mocks. Runtime
lease/move/release/reset-admission/run-sealing methods and the DTX layout
set/clear/getter/reset helper are exact extracted source bodies. The isolated
runtime surroundings supply worker registration/stop race hooks and simple RPC
maps; they are not a replacement full runtime implementation.

Both toolchains pass nine fresh-process setup scenarios:

- Actual layout clear/set -> private initialization reset -> native installation;
  later pre-run/in-run resets forward to the already selected native owner.
- Default-null layout setup and explicit public reset each seal legacy normally.
- Move-only lease release, reset refusal during a lease and nonblocking stop.
- A paused real reset hook versus public first use, installer, run sealing and
  stop; no premature selection/publication/reset admission.
- Installation reservation first -> ordinary legacy reset -> publication loss
  with an inert registered worker.

The reset hook deliberately queries backend status and acquires a nested runtime
lease, establishing that neither registry nor runtime mutex is held across it.
Paused races use explicit entry/release events and bounded observation windows.

All 18 prior dispatch scenarios pass unchanged, including concurrent call/stop,
strong ownership, self-join refusal, repeated stop, stop-callback fence,
registration failure and publication loss. The default/no-explicit-runtime path
matches the frozen legacy **22 cases /46 snapshots /16,656 float values** through
the public facade.

The exact new runtime API methods compile against the **actual124 runtime header**.
Complete unchanged124 `RPC.cpp`, `game_overrides.cpp` and `CriAudio.cpp` also
compile to objects using one qualified fresh-source cohort plus sealed V6
SDK/geometry includes. Every consumed non-system header is verified against the
124 receipt or sealed V6 manifest; old kit runtime headers are rejected. The
only local generated includes are the two existing V6 catalogues qualified by
generation receipt
`57449942f568de9c6f579ee58309d2a50ae16f0cdb69a36b43fbc96329c14e01`.
No assets are regenerated or included in this report. No runtime library is linked.

Final receipts are
`build-native-sjuni/pcm-boot-setup-checks/{gcc,llvm}/receipt.json`.
The full rebuild and actual bootstrap/game/provider validation remain required
before using the new dependency interface with a player executable.

```powershell
python tools/native_reconstruction/pcm_boot_setup/verify.py `
  --cxx C:/msys64/mingw64/bin/g++.exe `
  --output build-native-sjuni/pcm-boot-setup-checks/gcc
```
