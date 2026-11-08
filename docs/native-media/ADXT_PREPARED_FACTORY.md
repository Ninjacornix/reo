# Prepare the source binding before backend selection

`install_prepared_native_sources` accepts the canonical source owner already
prepared by a complete guest adapter. The adapter can allocate its handle map,
retained immutable mount/table and inert worker before selecting the SDK audio
backend. The factory returns the same owner and its selected aggregate's
read-only order capability. It creates no second source session or device.

The caller owns exclusive control of the supplied device-free owner and must
configure its actual host gain hooks. The entry acquires the real pre-run lease,
then checks that the owner is open with no constructed instances, pending starts,
retiring sources, session records, service/guard fault or occupied output. Null,
late, nested and occupied admission refuses before RAM/device preparation or
worker registration. These validation refusals leave the supplied owner usable.
After a publication attempt, the existing failure cleanup may have stopped or
joined it; the caller retains cleanup responsibility on failure.

The older explicit `install_native_sources` still creates its own canonical
owner with the actual host gain hook, then uses this same entry and joins its
owned preparation on failure. The legacy original-source installer is unchanged.

Both compilers pass 19 complete factory protocol scenarios, including all prior
14 scenarios and five prepared-owner cases: same-owner selection and source
start/join, null owner, closed runtime phase, idle occupied owner and nested
controller admission. Acquisition and device ports remain declared fixtures;
production SDK130 object checks separately compile the factory. No guest hooks
or new game route are installed by this checkpoint. Step 3 remains open.

See [qualification](../../tools/native_reconstruction/adxt_prepared_factory_qualification.json)
for exact source and receipt identities.
