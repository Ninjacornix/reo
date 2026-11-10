# Native AI control registrations and request producers

2026-11-10. The registration/request producer path is qualified as a native
component. Its service/network consumers and full AI initialization remain open.
Stage4 is incomplete and installed gameplay remains V39.

One `ControlRequests` instance on the canonical Session owns64 registrations and
64 pending four-byte requests. It replaces the original addressed tables with
logical native values. Actor Owner calls resolve the real actor and use its slot;
the slot is not assumed to be the primary entity's physical index.

Complete681240 membership and6812B0 registration narrow kind to a byte and target
to a signed halfword. Duplicate registration changes nothing. New registration
uses the first inactive slot, assigns owner tagFF and clears the four counters,
while retaining previous phase/payload values. Complete681330 removes only the
first matching registration and preserves fields the original does not clear.

Complete681710 request lookup compares full kind/target arguments against stored
values. Selector-1 chooses owner tagFF; other selectors use low-byte+1 with byte
wrap. Complete681790 looks up before checking capacity, copies four bytes and
appends without overwriting a full queue. Missing-registration and full outcomes
remain distinct. Complete815DF0 publishes type0 for the actor slot, narrowing its
parameter to one byte followed by three zero bytes.

Both compilers pass30579888 identical checks, including the previous goal/action
suite and64 membership,152 registration,44 removal,18432 lookup,18432 request and
66 actor publisher original comparisons. Full tables/queues, narrow duplicate
keys, full versus missing admission, signed targets, selector wrap and unchanged
fields compare against complete original bodies without new surroundings ports.

Both parent builds and twelve integration tests pass. Actual Owner tests verify
the same Session queue, slot5 on primary index0, copied payload and rejection of
foreign/retired identities. Evidence is sealed by
`native_gameplay_ai_controls_qualification_v1.json` (SHA256
`dfcc3f6594531bbc89802c94282123b4af00ed77b370378b756704be3a69cf2c`).

Pending requests are available to the future service consumer. No automatic
delivery, successful network send or full AI update is claimed. Service/reset,
owner acknowledgements, initialization/observations/goal/action dispatch, real
input/network/save ownership and coherent native gameplay acceptance remain
open. No game was launched or performance change measured for this work.
