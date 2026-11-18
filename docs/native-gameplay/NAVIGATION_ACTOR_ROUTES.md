# Canonical actor route and action state

2026-11-10. Bounded component qualification. Stage4 is incomplete; installed
gameplay remains V39. No game was launched or slowdown measured.

Complete8173D0 and816EF0 now use one optional `ActorRouteState` on the real World
Actor. An absent component is unavailable; construction, import or a real
producer must establish it. The UpdateOwner resolves its existing actor identity
and passes the same canonical room, status, slot, AI-control, flags and Bank.
There is no guest RAM, register context or mirrored actor record in production.

Refresh chooses local policy0 or the qualified cross-room dispatcher. It writes
the last-current node after a completed call, including completed no-path. A
successful action update publishes the actor occupancy bit to the actual Bank,
preserving32-bit shift masking followed by byte truncation. It selects the first
direct edge action and, at the applicable link node, the last matching reverse
edge action across the traversed neighbors. Full16-bit actions are preserved.
Reaching the local destination substitutes the requested final XYZ in both
positions; this function does not also rewrite the route node IDs.

Current/destination node, first/second route nodes and positions, final XYZ,
previous/current action, destination room, completion/refresh, last-current node
and selected link remain distinct. These functions leave previous action and
completion/refresh untouched. They do not establish missing current-node or
destination producers merely by being callable.

Both compilers pass35,106,105 checks, including8,205 route refreshes and8,211
action updates.13,336 actor calls use the five retail navigation inputs. Of the
16,416 completed actor comparisons,14,112 use the strict profile and2,304 select
the separately declared collector initialization correction (including early
denials without collection). The correction retains its prior qualification
limits; it is not presented as unmodified source behavior or game acceptance.

One controlled no-writer cost case stays unavailable. The first fixture had
expected unknown in a context where an earlier source route supplied a known
cost. Both failed v1 receipts are retained; v2 clears visits and places the actor
on the source link to test the intended unknown input. This corrected the test
setup without changing the production route policy.

Both parent builds and all ten integration tests pass. Owner tests exercise
absent capability, actual actor mutation and shared occupancy, along with the
existing foreign/retired identity and closed-World checks. Evidence lives in
`build-native-sjuni/navigation-actor-{llvm,gcc}-v2/receipt.json`, the matching
`navigation-actor-parent-*`/`navigation-actor-tests-*` logs and
`tools/native_reconstruction/native_actor_navigation_qualification_v1.json`.

Initial/current-node producers, full destination setup816890, movement and
transition actions, remaining AI/VM owners, broader cost/content admission,
real loading, semantic saves and coherent native gameplay installation and
acceptance remain open. This qualification does not close Stage4.
