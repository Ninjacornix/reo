# DVCI lifecycle oracle and staged-read cut

2026-11-05. Isolated owned-instruction execution with synthetic memory and
explicit external services. No game, runtime library, device, process attachment
or payload I/O is executed. Existing native core/owner implementations are not
imported by the oracle.

## Executed boundary

[dvci_lifecycle_oracle.py](../../tools/native_reconstruction/dvci_lifecycle_oracle.py)
inherits the scalar harness and reuses the unchanged SJUNI integer instruction
engine. Its separate bounded dispatch loop admits eleven complete owned bodies:

| Body | Owned behavior exercised |
| --- | --- |
| `139EA8..139FA8` | Stop early exits, break call, server/service/query loop, cap, warning and final fields |
| `139BD8..139C30`, `139A30..139A4C` | Close and 72-byte clear boundary |
| `1399F8..139A2C`, `139A50..139BD4` | Last-free-slot selection and cached-file reopen |
| `139798..139810`, `1396D0..139794` | Real forty-slot service and terminal DVCI update |
| `137868..1378D0` | Real SRD break-flag write and guard calls |
| `139FA8..139FE0`, `139CC8..139D00`, `139FE8..13A034` | State/cursor/completed-byte observations |

Ends are exclusive. File #1 ELF SHA-256:
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
Fresh source/ELF audit verifies **345 comments plus ten omitted zero words**,
with zero conflicts/omitted nonzero words. Fixture identities include every
body hash and the generator/integer-engine hashes. No instruction arrays are
stored in source or fixture output.

External hooks are declared explicitly: guard enter/leave, diagnostics/messages,
server service, service-gate response, SRD status/destroy, positive cached-file
metadata and generic bounded memset. Gate/SRD responses preserve memory.
Cached metadata supplies only the LBA/byte-size output words; original open
instructions perform the remaining stores and sentinel decision. The memset
hook implements the clear's declared 72-byte zero-fill. Uncached opens, real
SRD internals, cache lookup implementation and callback reentry are outside this
admission; unknown fetches/encodings/plans and exhausted instruction budgets abort.

## Results

The fast fixture has **18 cases / 52 calls / 16,023 interpreted steps**. The
full fixture adds both real cap paths: **20 cases / 60 calls / 52,446,214 steps**.
No retry counter is teleported and no DVCI transition is supplied by a hook.
Hook streams are bounded in output using exact counts, a full-stream hash and
the first/last two observations per kind.

| Original cap observation | Verbosity 0 | Verbosity 2 |
| --- | --- | --- |
| Instructions/hooks counted by bounded runner | 26,214,457 | 26,214,454 |
| Executions of counter increment `139F5C` | 655,360 | 655,360 |
| External server calls / real DVCI service-gate calls | 655,360 each | 655,360 each |
| Warning call | 1 | 0 |
| Final state / completed / stored request | 0 / 0 / retained SRD ID | 0 / 0 / retained SRD ID |

The service gate is scripted to refuse progress for these cap inputs. This is
not a claim about elapsed game time or a physical device timeout. Subsequent
**original** close clears the slot; original lookup and cached open then return
the same address. The pointer's prior request identity is absent in the reopened
record. This establishes scalar slot reuse under these inputs, not that a real
host read remained active or that a particular player incident reached the cap.

Other cases cover stopped/ready early exits, pending/error stop, SRD responses
0/3/9, a 1/2/4/3 response sequence, close without a request, null/invalid opens,
full/partially free pools and cached-result-1's sector sentinel. Destroy events
observe terminal fields before request-pointer clearing. Stop subsequently
normalizes state/count; early exits preserve their previous values.

```powershell
python tools/native_reconstruction/dvci_lifecycle_oracle.py
python tools/native_reconstruction/dvci_lifecycle_oracle.py --include-caps --output build-native-sjuni/dvci-lifecycle-cap-fixtures.json
$env:DVCI_LIFECYCLE_CAP_FIXTURE='C:/Users/Ninjacornix/reo/build-native-sjuni/dvci-lifecycle-cap-fixtures.json'
python -m unittest discover -s tools/native_reconstruction -p test_dvci_lifecycle_oracle.py -v
```

**Nine checks pass** with the separately generated full-cap fixture supplied.
Without it, eight fast checks pass and the cap-receipt check is explicitly
skipped. That check validates source identity, per-PC counter execution, exact
hook counts and close/reopen output; it does not rerun the slow loops.

## Chosen immediate cut: original synchronous RPC ownership

The selected next pilot keeps the **original synchronous RPC owner**, with the
native CD worker disabled for that fresh launch. It substitutes the byte source
for exact in-file PAK requests only. It does not enable the asynchronous
generation-token design below.

At the existing N-command read branch in
[ReoHwBridge::onSifRpc](../../recomp/overrides/reo_hw_bridge.cpp), retain the
already-held guest execution and RPC ownership. Resolve a verified native mount
route, require prefix bytes equal total bytes (no EOF padding), stage exact bytes
in native storage, and copy to the validated guest destination before returning
to the unchanged original RPC completion path. Do not release guest execution
around provider I/O or between staging, validation and copy.

In this synchronous admitted domain, the original call's ownership prevents
another guest stop/close/reset/reopen from interleaving before payload commit.
No durable native DVCI shadow or guessed request-generation scan is needed.
This deliberately retains synchronous blocking behavior; it is a resource-source
transition, not a claimed asynchronous/performance improvement.

Unknown mount/route/layout, non-file ranges, unsupported formats, padding,
limits and allocation refusal stay on the existing byte-read route before
native publication. Native staging failure leaves guest bytes untouched, so
the existing sector read can run once within the **same RPC owner**. Do not
replay SifCallRpc or issue an additional completion. Existing false-read/error
and callback behavior stays original. Provider reads must not invoke guest/RPC
callbacks or release/reacquire guest execution. A fresh worker-disabled launch
and the actual held original RPC/guest scope are necessary admission, not a
runtime environment toggle while jobs might already exist.

## Future asynchronous cut, using actual mounted resources

The current [CD pilot](../../recomp/overrides/native_cd_owner/runtime_adapter.cpp)
reads directly into guest RAM before acquiring guest execution. Its narrowed
admission now requires pattern zero, matching packet pointers, zero edge-copy
counts and callback-block disjointness, and rechecks the two counts under guest
execution. These gates preserve its existing original completion path; they do
not correlate a job with a DVCI/SRD/CRI incarnation.

The actual [MountedResources API](../../game/native/resources_windows/mounted_resources.hpp)
is now present. `resolve_sectors` returns a retained view, offset, prefix length
and total padded length without I/O. The
[implementation](../../game/native/resources_windows/mounted_resources.cpp)
admits one route within its capacity; count is positive and at most `4000`.
The retained-file route starts at `01000000` using sorted facade keys; overlay
routes win appropriate lookups. A bridge must bind this exact route/layout
identity to the runtime's effective CDVD map, not infer it from an LBA alone.

If asynchronous payload ownership is pursued later, its transaction is:

1. **Before publication**, resolve the route and reserve bounded native staging
   and an ownership token. Check total/prefix lengths against configured stage
   and ResourceSession read limits; known allocation/limit/owner refusal takes
   the existing path exactly once before publication.
2. On the native worker, zero the owned stage for total bytes. If prefix is
   positive, use ResourceSession::read_exact for precisely that prefix at the
   resolved offset. Prefix zero performs no provider read, even when the offset
   lies beyond EOF. Do not pass a guest pointer to this read. Retain route/view/
   pinned providers and staging through completion.
3. **Only after successful staging**, take GuestExecutionScope. Revalidate stop,
   runtime/RAM/binding identity, immutable request arguments, pattern/packet/
   zero-edge metadata and the real ownership token below. Until this succeeds,
   the transaction has written no guest payload.
4. Commit the staged bytes to the retained guest target and invoke the original
   completion under that same execution scope. Do not release the scope between
   validation, copy and callback. Do not set DVCI ready or publish/free an SJ span
   from the byte provider; existing SRD/DVCI/CRI service retains those transitions.

The resource [session](../../game/native/resources/resource_session.cpp) retains
providers outside its registry lock and preserves destination on failed exact
reads. Windows [PinnedFile](../../game/native/resources_windows/pinned_file.hpp)
hashes and reads through the same retained handle. Those leases own native
sources, **not** guest destinations. Pre-existing writable mappings remain
outside file immutability admission. If read_exact allocates internally after
publication, allocation/I/O failure still needs an explicit post-publication
policy; successful staging cannot be assumed infallible.

## Correlation required before the guest copy

Do not use unchanged numeric addresses as a generation. The lifecycle fixture
demonstrates close/reopen at the same slot. A token must bind native session and
mount identity to a monotonically admitted DVCI-slot incarnation, SRD allocation
incarnation, LBA/count/destination and, for the initial CRI-only domain, the
specific stream and borrowed SJ reservation.

The concrete producer sites are the existing
[`130800`](../../recomp/config/output/sub_00130800_0x130800.cpp) path: SJ Get at
`130A50` supplies the borrowed span; request is called at `130AC8`, and its
reservation/count fields are stored at `130AD8..130AE4`. Original DVCI request
stores its SRD/count/destination before preparation. The physical sceCdRead RPC
return site alone identifies neither producer nor reservation.

An initial bridge can admit only uniquely correlated **asynchronous CRI-owned
requests**, with a published stream reservation and owned-file link back through
cvFs to the expected active DVCI slot. Synchronous DVCI request can pump device
work before `130800` publishes its span fields; it must remain original unless
an earlier explicit borrowed-span token is retained. Uncorrelated/direct callers
also remain original.

The candidate token needs real producer/lifecycle interception, not a guessed
scan: mint on a proven successful open/allocation, invalidate/advance at close
and reuse, associate the actual SRD admission, and retain the target until its
transaction acknowledges completion. At commit, check native epochs and current
guest links/flags/ranges. Exclude payload overlap with DVCI/SRD/CRI control
records, command/callback blocks and code; address bounds alone are insufficient.
The existing four-entry scalar adapter creates no such token.

A stale token may suppress the payload copy, but this alone does not settle
original busy/semaphore/SRD/error completion. Returning a span early and later
dropping the callback is not cancellation. Likewise a source/read failure after
publication cannot replay the original request or invent DVCI error state.
These protocol/error outcomes need their own explicit contract and fixtures.

Next concrete checks are a blocking fake source plus stop/close/reopen before
commit, target reuse, changed copyback metadata, shutdown, stage allocation/
source failure and callback failure. Compare them with these owned lifecycle
states and extend into SRD create/destroy and CRI stop/reservation publication.
The new oracle closes the stop/cap/slot-reuse evidence gap; actual device
acknowledgement, scheduling and SJ payload lifetime remain unproved.
