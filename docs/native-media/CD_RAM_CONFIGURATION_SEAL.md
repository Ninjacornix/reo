# Observed disc RAM-writer configuration

Status: native-CD-build receipt/seal implemented and isolated checks completed
2026-11-06. No game, disc device or audio device run. Bootstrap does not yet
retain the receipt or enable bank capture.

The actual native CD adapter now offers `configureWithReceipt` and
[ConfigurationReceipt / SyncRamWriteSeal](../../recomp/overrides/native_cd_owner/ram_configuration.h).
The existing `configure` entry calls that implementation. Its observation comes
from the actual selected branch and active worker, rather than an audio factory
inferring the mode from environment strings.

Before issuing a receipt the adapter acquires the real short pre-run setup
lease and verifies File #1 code, callback registration, actual Runtime RAM and
geometry. Disabled native-worker/disabled asynchronous settings can yield an
observed synchronous route. A current asynchronous owner remains asynchronous
even if settings subsequently request synchronous behavior; no worker is stopped
or disabled to obtain a seal. A foreign active owner is a conflict.

`try_seal` requires the current issued receipt and matching Runtime/backing,
observed synchronous mode, no active worker and no previously constructed
asynchronous worker attempt in this process. An attempted worker whose
registration fails also conservatively disqualifies later seals. This deliberately
narrow process profile retains history across receipt-allocation failure and
other Runtime configurations; it does not try to recover eligibility after a
worker drains. This is stricter than checking whether its queue is now empty.

The persistent move-only seal increments a bounded count under the same
configuration mutex that protects actual setup. All subsequent configure calls,
including identical requests, refuse with an explicit conflict while sealed.
Moving or destroying seals releases the count exactly once. Reconfiguration
invalidates old unsealed receipts before attempting allocations or changing the
route; a failed replacement cannot leave a stale safe-mode observation usable.
The monotonic generation and actual receipt object identify a configuration
incarnation. The short Runtime pre-run lease is released before returning;
holding a persistent seal does not prevent `Runtime.run` from beginning.

An existing accepted seal is not invalidated merely because stop is signaled.
Its enclosing audio owner must retain it until all accepted calls drain. This
does **not** retain the Runtime or RAM itself, authorize a read/write, serialize
GPU publication, or certify arbitrary host writers. Actual lifetime and parent
read/write reservations are separate required capabilities. The detached legacy
CD build has no equivalent receipt and remains unsupported by the proposed
runtime capture factory.

## Verification

The actual adapter plus real native SerialWorker passes **21 fresh-process
scenarios** with both GCC and pinned LLVM: the previous 14 ownership/admission/
callback cases and seven configuration cases. The new cases record 209 checks
per compiler, including 32 independently started seal-versus-configure races.
Each race permits exactly either a retained seal plus configuration conflict,
or a replacement configuration plus stale-receipt refusal. Other checks cover
move replacement, multiple seals, release/reconfigure, foreign Runtime/RAM,
phase/stop refusal, changed settings, active idle asynchronous workers,
registration failure and receipt-allocation failure. No scenario performs real
disc I/O or original instruction execution.

Actual adapter objects also compile against the qualified final 125-source
dependency cohort. The verifier validates every dependency source and patch
against its full reapply receipt before compilation, checks sources afterward,
and records empty authored-source postchecks. Mock pre-run phases are only
surroundings; the dependency's exact-method/race checks establish its real lease
implementation separately.

| Private receipt | SHA-256 |
| --- | --- |
| `cd-owner-ram-configuration/gcc-v5/receipt.json` | `57c16088daaa1f6c05af4d602298f42eaee34d966ccb619518a40c5251df0232` |
| `cd-owner-ram-configuration/llvm-v5/receipt.json` | `d222f3144e21dfb1cc04fcbd6a10c425be41751d39d1d0bd04b6e6453ccdce36` |

Both are below ignored `build-native-sjuni`. Earlier failed/partial cohorts are
retained. The candidate preparer now includes the new header when packaging a
future committed candidate; no existing sealed kit or player executable changed.

```powershell
python recomp/overrides/native_cd_owner/tests/run_checks.py `
  --cxx C:/msys64/mingw64/bin/g++.exe `
  --output build-native-sjuni/cd-owner-ram-configuration/gcc-v5 `
  --runtime-headers build-native-sjuni/dependency-bank-reapply-v3
```

Next: actual parent binding/storage pins, canonical group read/write reservations,
versioned grouped bank capture, and the earlier SDK transport/ABI/status input
chain described in [the capability design](NATIVE_BANK_CAPTURE_CAPABILITY_DESIGN.md).
