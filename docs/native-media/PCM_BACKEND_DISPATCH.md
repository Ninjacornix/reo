# Versioned complete PCM facade dispatch

Status: dependency dispatch infrastructure implemented and isolated checks,
2026-11-05. This installs **no real native PCM backend**. No game, audio device,
asset or runtime library was run/built by these checks. The
[installation review](PCM_BACKEND_INSTALLATION.md) still governs the real owner's
domain, provider fence, clocks, raw IDs and bank composition.

Public [patch 0121](../../third_party/patches/ps2recomp/0121-cri-audio-session-backend-dispatch.patch)
keeps all eleven `ps2_cri_audio` facade signatures and their legacy implementations.
It adds one versioned session selection and routes every public call through it.
No bootstrap/preparer/CMake option installs a candidate behind this interface.
Source changes require a matching rebuilt runtime before any eventual use.

## Interface and one publication point

The patch adds `CriAudioBackend.h` and private `CriAudioDispatch.h` beside the
existing facade. The latter is included only by `CriAudio.cpp`; there is no new
runtime compilation unit. `BackendApiV1` is a copied nonthrowing function table:
all eleven exports plus `request_stop`/`join`, exact ABI version and structure
size, and the required twelve-bit interface coverage mask. A registration owns
an opaque context through `shared_ptr<void>`. Null owner, missing callback,
wrong version/size or incomplete capabilities refuse before publication.
Capabilities declare interface coverage, not actual provider/device correctness.

This is a versioned C++ static-library interface compiled with matching sources
and toolchain, not a portable DLL/plugin ABI. The retained table cannot be changed
by mutating the caller's registration object afterward.

`installBackendBeforeRunV1(PS2Runtime&, registration)` reserves an untouched
selection, allocates the binding and registers an owning `ExternalWorker` through
the **actual runtime's pre-run gate** before publication. It runs no candidate
callback while holding the registry mutex. First public facade use can win a
race and seal legacy selection; publication then fails explicitly.

The registry state is process-global to match this facade: unselected, sealed
legacy or one sealed native owner. This first infrastructure cut does not permit
late backend replacement, even after a native owner expires. An invalid queue
call also counts as first facade use, while retaining its previous no-output/
no-clock validation behavior. Status inspection alone does not seal selection.
One matching runtime/session per process is the native installation domain.

A registered but never-published worker stays genuinely inert. It retains the
context until runtime cleanup, but does not call candidate stop/shutdown/join
functions that could touch legacy routes or banks. A runtime stop racing between
registration and publication prevents activation. No fake rollback/unregister is
used; the real worker API deliberately has no unregister method.

## Calls, admission and lifetime

The registry contains a weak binding. The runtime worker and each admitted facade
call hold strong binding/context ownership. A short registry lock obtains a strong
snapshot; a separate admission gate counts calls. Registry locks are released
before backend invocation or a potentially last context/lease destruction. This
does not use unsupported `atomic<shared_ptr>` operations from the pinned libc++.

Each selected facade method calls exactly one backend table entry. Its rejected
operation is never retried against legacy queues. Native queue calls retain the
existing zero key/pointer/length, odd length and `>0x4000` rejection checks. A
temporary end-byte value ensures a false backend return cannot overwrite the
caller's `endByte`; this does not roll back an incorrectly implemented backend's
private state. Correct native enqueue/refusal remains the backend's contract.

The selected `render` entry owns the **whole** public render operation, including
the agreed CRI/bank/master composition. Dispatch does not additionally run legacy
bank mixing after native rendering. The selected `ensureHostOutput` must cover
bank-only startup too. Native real-time/clock/gain rules are not implemented or
certified merely by having these table entries.

Runtime `requestStop` closes admission immediately and signals the candidate once
outside internal locks. Already admitted calls keep the context alive and finish;
new calls do not enter it. Closed/expired native selection returns stopped neutral
results (false/zero/no-op and silent render output), never legacy fallback. These
are terminal teardown rules, not claimed ordinary active-playback error parity.

The first stop signal is also marked in flight before releasing the admission
gate. Non-self shutdown/join waits until that outside-lock callback has returned
before entering candidate shutdown or join. A repeated stop request does not wait
for another signal or lifecycle operation. Thus the signal callback cannot still
be accessing owner state while another lifecycle call resets it; callbacks still
run outside internal mutexes, and TLS self checks prevent waiting for oneself.

Public shutdown closes admission and waits admitted calls before invoking the
candidate shutdown entry once. A callback/producer cannot wait for its own lease:
self-shutdown closes admission but defers completion to a non-callback owner.
Self-join refuses. Worker join serializes lifecycle work, completes deferred
shutdown and invokes the candidate's explicit join; only true marks native joined.
A false join retains the owner and does not claim a completed fence. Repeated
successful join/shutdown is idempotent; neither callback nor context destruction
occurs under the registry lock.

The actual candidate must remain inert before publication, make request-stop a
nonblocking signal, and make join prove real provider/producer quiescence. The
infrastructure cannot certify a dishonest join return or replace the actual
raylib detach/unload fence. It also cannot authorize unsupported shared channels,
invent void-configure errors, qualify guest ring generations or migrate queues
after a domain refusal. Those remain gates before a real owner is installed.

## Fresh patch reconstruction and source identities

The predecessor is the exact public 121-patch tree at base
`c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f`; the original complete facade hash is
`39dce6882e561ad69a0112a330ecc4023a98c21365ac2fe8709f838fce4c9a06`.
The patch was authored against a separate audited clone, with all prior changes
staged as its private baseline. No active dependency checkout was edited.

Patch SHA-256:
`3c354e6519d60d530ff8e1cdb1e4c23ddff65f6f8ac0a3b6ddcfc39fd214e79d`.
The final independent worktree reapplies **all 122 public patches** successfully:
`build-native-sjuni/dependency-pcm-dispatch-stop-fence-v2`. Its full receipt SHA-256 is
`807a1740889dbd4ffccede3074f59d90bfae7088032753f4b805a2dfaa1af475`.
The final receipt contains source files rather than clone `.git` administration.

| Final reapplied source | Raw SHA-256 |
| --- | --- |
| `CriAudio.cpp` | `aa90abf0fb6e461b3296ee03831ec4dec9680ebdcd5d679665f56590ff5af877` |
| `CriAudioBackend.h` | `b2e6cc5101ebd34fca4194c0987cd872f7fb740218a20602b1dec07227094560` |
| `CriAudioDispatch.h` | `020f452e4c139ef89ceef5d62cc3e022fd35e35edf736fc4e40d48643372fe6a` |

The Windows reconstruction uses the same `core.autocrlf=true` configuration as
the established predecessor audit. An initial fresh clone explicitly configured
false failed prior patch 0028, before this change; its failed tree/receipt remains
preserved and is not a valid baseline. No patch was forced or changed to bypass
that failure. Final reapplied raw hashes differ from the authored LF working
copies only in line endings; all final checks below use the fresh final worktree.

## Isolated execution evidence

[verify_pcm_backend_dispatch.py](../../tools/native_reconstruction/verify_pcm_backend_dispatch.py)
verifies every prior public patch and every unchanged predecessor source, checks
reverse applicability of 0121, then copies the exact patched facade/headers into
ignored output. Device readiness is mocked false. Backend and runtime-registration
surroundings are explicit fakes; no real native PCM owner is substituted.

GCC and bundled LLVM/MinGW each pass **18 fresh-process scenarios**:

- All eleven selected facade methods; untouched legacy sealing and invalid first
  queue behavior; every missing table callback and wrong ABI/size/capability/owner.
- Runtime-late refusal, first-use publication loss, stop during registration,
  another installer in progress and construction allocation failure.
- Reentrant facade/status calls with no registry lock held; native rejection
  preserves `endByte` without entering legacy state.
- Reset, stop and idempotent shutdown/join; simultaneous blocked producer/render
  calls hold strong ownership while shutdown waits; self-join refuses.
- A failed join does not become joined. A separate strong-snapshot test drops its
  **mock** worker list while an admitted call is blocked and proves context survival;
  this is a reference-lifetime test, not permission for real runtime destruction
  without joining. Expired native selection still does not fall back.
- A deliberately paused request-stop callback blocks non-self shutdown/join,
  while a repeated stop request returns and the context remains strongly held.
  Releasing the signal callback permits exactly one shutdown and join.

A separate negative control compiles only an ignored copied dispatcher with the
stop-signal wait removed. The same paused-signal scenario must fail normally
with exit code 1, demonstrating the reviewed overlap rather than accepting a
vacuous pass. The public patch/source checkout is unchanged by this control;
its expected nonzero result is recorded separately from passing primary checks.

The complete unchanged **22-case / 46-snapshot / 16,656-float** legacy corpus also
matches the prior frozen observations with each compiler. Importantly, its
unchanged harness uses `namespace a=ps2_cri_audio` and calls the **public patched
facade**, thereby testing default selection/dispatch. Internal legacy maps are
read only for observations; calls are not redirected to an internal legacy alias.
Its expected fixture remains SHA-256
`819470f5433c09a5549fefae5f726012ba9ab34f3cc2e4ed3545007d89bea909`.

Each compiler additionally compiles the exact patched facade to an object against
the **actual reconstructed122 `ps2_runtime.h` and new backend headers** from the
final worktree. Only provider functions remain mocked in that object check. This
checks source/header integration; it neither links a matching runtime library
nor runs real runtime registration or a callback/device fence.

Receipts live at `build-native-sjuni/pcm-backend-dispatch-stop-fence-checks/{gcc,llvm}/receipt.json`
and identify sources, patch, compiler, commands, executables, legacy fixture and
actual-header object. The verifier also checks source stability across execution.

```text
python tools/native_reconstruction/verify_pcm_backend_dispatch.py --checkout build-native-sjuni/dependency-pcm-dispatch-stop-fence-v2 --cxx C:/msys64/mingw64/bin/g++.exe --output build-native-sjuni/pcm-backend-dispatch-stop-fence-checks/gcc
```

Before usage, the next stage must implement a complete admitted native facade,
register it through the real pre-run adapter, rebuild/seal matching runtime and
game inputs, and validate real media/output/stop transitions. No native backend
installation, real lifetime fence, audible parity or completed PCM migration is
claimed by this infrastructure patch.
