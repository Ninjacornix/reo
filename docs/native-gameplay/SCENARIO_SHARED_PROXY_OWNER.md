# Canonical native scenario controls and collision proxies

Status, 2026-11-09: the two native consumers share one qualified owner. The [native room initializer profile](SCENARIO_ROOM_SCENE_IMPORT.md) now imports its admitted typed state and helpers; full stock coverage and actual gameplay installation remain open. Stage4 is incomplete; no game was launched for this work. The counts below preserve the first shared-owner checkpoint; the later initializer cohort refreshes shared views to41,984 checks and clears the optional P48 fallback when typed metadata owns that field.

`gameplay_scene::Records` owns at most128 records, one free stack, one linked order and one domain/generation identity. `SceneControlId` and collision `ownership::Handle` are aliases of that identity. Construct `SceneControls` and `Proxies` with the same `shared_ptr<Records>`; their default constructors remain independent standalone fixtures and must not be mistaken for an installed shared room.

The original `5C1120`, `5C11B0` and `5C12A0` bodies establish the128 capacity, allocation order and retirement behavior. Allocator argument0 appends at `3B5160`; argument1 prepends at `3B5158`. Collision ordered views traverse from the oldest end; script commands traverse the same records in reverse. The historical `SceneControls.append` preserves its established standalone traversal order using oldest placement. The new room importer must explicitly request newest placement, as `5C1390` does.

The canonical record stores authored identity, raw activation byte, priority/counter and typed body once. Collision geometry and entity ownership occupy separate fields; collision `Proxy` and `Door` values are derived views. A type-zero destination edge and type-two descriptor supply the collision `+48` value directly. Type-zero door selector and matrix resource class share their `+60` value, while the full `+58` word supplies heading and collision admission. Type-two `+58` is also one full word: collision checks complete-word equality with2, while the matrix selector reads its low byte. Missing typed fields remain missing.

A script activation or priority change invalidates the collision selection snapshot through the shared revision. Geometry replacement preserves script parameters and retains raw nonzero activation unless the collision edit actually changes its boolean state. A collision edit cannot silently change a typed control into another kind. Direct canonical edits are simulation-owner operations and must call `touch`; no worker-thread mutation or guest-memory access is introduced.

`Proxies.acquire` returns a checked strong invocation lease. Retirement immediately invalidates both future views, and reusing the physical slot creates a different node and generation. An existing lease retains the old record rather than following the replacement occupant. Script traversal retains its reverse continuation across callback retirement; retiring another live node updates the same live link. The raw pointer returned by `Proxies.get` is only a synchronous derived projection; retain a lease across callbacks.

Both compilers pass the following independent cohorts:

| Cohort | Evidence per compiler |
| --- | --- |
| Complete original allocator comparison |24,432,024 checks;65,568 original calls; allocation/ordering/reuse/retirement |
| Actual shared script/collision composition |41,216 checks;256 cases; shared capacity, query changes, alias widths, retired leases |
| Existing collision ownership/original geometry oracle |344,728 checks;1,500 pool sequences;1,200 poses;200 wall callers; maximum observed error0 under its declared support ports |
| Full interpreter and real periodic-effects owner |14,001,146 checks;29,753 original dispatch calls; ordinary326/offline299 qualified bindings; no new opcode admission |

The full VM rerun includes the actual opcode131 work from checkpoint `3004bfb5`, with only its `SceneControls::start_periodic` traversal adapted to the shared leases. Its admission, canonical flags/RNG checks, reset-before-start ordering, counter wrap and natural scheduler-full result remain unchanged. Earlier source snapshots remain historical evidence. An initial new test incorrectly converted `EntityCreated` to bool; the failed fixture remains retained and was corrected to check its explicit status.

The separately hash-verified asset audit finds166 RDTs,2,144 base records and a maximum39 base records per room. Those totals exclude helper-created and runtime proxies. All actual type-zero/type-two authored indices in that inventory fit the16 matrix channels. Five initial table-zero references contain `FF`. The immediate `68C570` setup copies the data and relocates references without rewriting those bytes; `5C1390` then calls model-space helpers whose unbounded original index can alias adjacent matrix work. This is an explicit importer frontier. It is not evidence that an FF slot is a valid native model, that substituting model0 is correct, or that a particular gameplay incident exercised the alias.

Next: implement the complete bounded importer and type helpers against the actual owned records, preserving canonical channel/model sound-map writes and handling unsupported aliases explicitly. Only then qualify installed shared-room behavior. The older [installation gate](SCENARIO_SHARED_PROXY_POOL.md) and [matrix selection qualification](SCENARIO_MATRIX_PROGRAM_SELECTION.md) retain their separate scope. Exact source closures and immutable receipt hashes are recorded in `native_gameplay_shared_scene_records_qualification_v1.json`.
