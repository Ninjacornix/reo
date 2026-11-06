# Native CD request worker ownership pilot

Status: independent worker and temporary File #1 adapter pass isolated checks;
matching linked-game validation is pending. The native resource byte provider is
not connected here. This pilot still calls the existing `readCdSectors` route.

Build with `REO_BUILD_NATIVE_RESOURCE_OWNER=ON` and public runtime patch 0120.
The option defaults OFF. Opt in with `REO_NATIVE_CD_OWNER=1`;
`REO_CD_ASYNC=0` still disables async admission. In this candidate build,
opt-out uses original synchronous HLE. Builds without the option retain their
existing implementation.

The independent [SerialWorker](../../../game/native/tasks/README.md) supplies
eight pending slots plus one active task. It admits a prebuilt task and publishes
RPC client fields before execution. Full/stopping/allocation rejection delegates
original HLE once before those fields are changed.

## Identity and admission

One session retains one runtime/RAM identity. Configure follows final ELF load;
a registered external worker prevents runtime reinitialization, another ELF load
or a second run. File #2 is excluded at compile time. Loaded ranges are checked:

| Range | SHA-256 |
| --- | --- |
| `101788..101967` | `c520c3c1af9405a9b73a60c397b7ed6196d34ad5d54559371b74aed5be6d1baa` |
| `1004D8..10058F` | `6126b560a34e355058f3b6426a7ef310855bb5aef6cd5922a852bc9628b75e47` |
| `100298..100337` | `b1a65fc9ecc2500db7dc938d41b512ab3eb727b2a06748e71d8edee262455fcf` |

Admission requires the established SifCallRpc return/client/send/callback shape,
zero receive arguments, `end_parameter=208A00`, readable aligned caller stack,
and positive whole-sector destination fully inside normal 32 MiB RAM. Callback
admission is limited to data-pattern byte zero (2048-byte sectors), matching
packet pointers and zero head/tail edge-copy counts. The payload must not overlap
the shared 0x90-byte callback metadata block. Other patterns use original HLE;
this does not reconstruct its non-2048-byte behavior. Edge-copy counts are
checked again under guest execution after the read, before callback dispatch.
An unexpected change is diagnosed without replay; its busy state remains unresolved.
Callback
binding must exist and match the captured binding. Unknown calls remain original
HLE responsibilities. A private callback stack is reserved before any admission;
failure refuses the prototype instead of borrowing the main stack. No worker TLS
stack survives into another runtime.

## Lifetime and completion

Runtime owns registered workers strongly. Stop signals reject new work without
joining. Queued tasks observe stop before I/O/callbacks; active I/O finishes while
runtime/RAM remain alive. Runtime joins external workers before VIF/GS and kernel
registry teardown. Bootstrap cleanup also joins before diagnostic exports and
covers early exits. Joins hold no guest-execution, RPC, CDVD or queue lock.

After payload read, completion takes guest execution and rechecks stop. The
captured callback receives saved GP/end parameter/private stack and RA 0.
Registered continuation PCs preserve the context until return/stop, bounded at
256 dispatches. Unchanged entry PC follows the generated host-callee convention.
Missing continuations/limit exhaustion are diagnosed and never replayed as a new
request. Bounded completion proof counts contexts reaching PC 0; it does not
independently prove later SRD/DVCI or SJ publication.

False reads still invoke original completion, matching the existing adapter.
Throwing reads/callbacks are diagnosed and never retried after publication or
partial callback effects. Such requests can remain busy: exception tests prove
later worker survival, not recovery. Native error-to-original-status publication
is still part of the [cvFs contract](../../../docs/native-resources/CVFS_REQUEST_BOUNDARY.md).

This addresses runtime-destruction ownership. Mid-game stream stop/close/reuse
and guest-buffer/SJ-reservation lifetime remain unproved. An active host read
cannot be forcibly interrupted; join waits for it to finish.

## Verification

```powershell
python recomp/overrides/native_cd_owner/tests/run_checks.py `
  --cxx C:/msys64/mingw64/bin/g++.exe `
  --runtime-headers build-native-sjuni/dependency-workers-reapply-v2
```

Fourteen fresh-process scenarios pass with GCC 15.2 and pinned LLVM-MinGW 20251216:
identity/admission refusal,
publication-before-read, callback arguments/scope, false-read callback, bounded
overflow, shutdown during blocked I/O, callback/registry overlap, allocation
failure, stack/registration refusal, throwing reads/callbacks, two-dispatch
continuation and missing/changed bindings. Actual adapter compilation against
real patched runtime headers is also checked. The bundled LLVM libc++ lacks
`atomic<shared_ptr<T>>`; the active owner uses a short registry mutex. No I/O,
guest execution, worker join or final provider destruction occurs under it.
Receipt:
`build-native-sjuni/cd-owner-checks/receipt.json`.

Mocks use synthetic RAM/device/dispatch services. Owned original text supplies
identity gates only; no original instructions are executed. The runtime patch has
its own exact-method/race/unwind checks. Neither result is linked-game,
original-device, audio/movie or performance validation.

The actual configuration branches now also issue optional synchronous RAM-writer
receipts and retained configuration seals. The expanded 21-scenario dual-compiler
checks and remaining memory-authority limits are documented in
[CD_RAM_CONFIGURATION_SEAL.md](../../../docs/native-media/CD_RAM_CONFIGURATION_SEAL.md).
Bootstrap capture integration remains pending.
