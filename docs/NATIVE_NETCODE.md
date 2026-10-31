# RC2 native networking

RC2 adds a room-negotiated extension beside the original SN@P gameplay channel.
This is experimental multiplayer work. A successful build or socket fixture
does not establish complete scenario synchronization.

## Compatibility and transport

`REO_NETCODE=auto` is the native launch default. `legacy` suppresses negotiation.
The native transport probes only after a real KICS login; an unsupported server
gets at most three probes per attempt. All original authentication and service
selection still run. Extensions use the same game UDP socket and selected server
endpoint, with no additional port or separate account system.

The server accepts an extension only when both its SID and source endpoint match
an admitted Outbreak session. Capabilities have five-second leases. In a waiting
room, every member must acknowledge the same roster epoch. When the original host
closes the room for scenario start, the server freezes enhanced or legacy mode.
A legacy member, expired lease or missing acknowledgement chooses legacy for the
whole room. New members cannot enable features in a running scenario.

A negotiated instance nonce permits UDP port rebinding on the same host while
preserving the original reliable queues. A new logical login fences old native
packets with a new epoch and switches that running scenario to legacy mode.

Features are intersected independently: 1 = faster batches, 2 = motion,
4 = typed reliable events, 8 = world checks/refresh. Client health expires after
2.5 seconds without valid server status. Existing original replication remains
available when a motion stream becomes stale. Offline launches retain the
original intervals; legacy native File #1 retains RC1's 500 ms interval.

The transport retains the original SDK's 16-entry reliable window, ACKs and
retries. It does not tunnel that reliable stream through a second reliable
protocol. A future GameNetworkingSockets integration would require separate
evaluation; RC2 does not depend on Steam or its relay service.

## Motion and critical events

Enhanced rooms use 100 ms opportunities to drain the original reliable batch
queue. This is not a 10 Hz world simulation. Player position/yaw samples are
independent, replaceable UDP updates capped at 20 Hz. The receiver rejects old
sequences, duplicates, invalid positions, other epochs and conflicting actor
ownership. Buffers are bounded to 32 samples per actor. Interpolation uses sender
time relative to arrival, with a 50–150 ms buffer adapted to observed jitter;
remote PCs do not need synchronized clocks. Stale samples stop after 300 ms.
Pause/loading and room changes invalidate samples. The original scripted-movement
exceptions remain in the guest correction handler.

The guest owner feeds the original actor correction record and retains its
animation/collision gates. Original full actor packets keep their non-motion
actions; only verified position/yaw fields are temporarily adapted to the fresh
motion stream. File #2's packed X/Z fields are handled separately from File #1.
No transport thread reads or writes guest RAM.

Original world/item/door group 5 and verified enemy HP/behavior/transition/death
records in group 8 can use original reliable mode 4. Destination fields and player
group 1–4 coalescing stay under original code. The typed enemy set is
`08,09,32,33,36,59`, plus File #1 `54,55`. Other enemy subtypes retain their
original delivery mode. This is bounded coverage, not a claim that every original
event subtype has been classified.

## World consistency and repair

The original game's per-room actor authority supplies the digest; it is not
necessarily the launcher host. A canonical checksum covers initialized, room-owned
spawn records' stable identity, family/variant, HP/max HP, room and lifecycle.
Renderer slots, pointers, positions, clocks and transient AI flags are excluded.
Three successive mismatches can request a refresh, limited to once per five
seconds. The request is routed only to the authenticated native owner; original
guest authority and room checks are repeated before any original helper runs.

Repair generates fresh original packets for existing living same-room actors:
an absolute state subtype already observed for that entity, followed by absolute
HP subtype 8. Packets enter the original reliable queue, preserving ordering with
its events. Cached damage/pickup packets and the dormant subtype 0 are never
replayed. Refresh work is bounded, leaves queue headroom and restores the guest
context/stack. Unsupported helpers disable optional refresh with a diagnostic.

**Missing actor construction, death/revival reconstruction, inventories and full
script/room baselines are not implemented.** A matching digest does not prove
that renderer actors or all scenario state match. Refresh cannot reconstruct an
enemy whose allocation/model lifecycle has not been verified. Those cases retain
the original game behavior and require further investigation.

## Measurements and checks

Online launcher sessions write `network-metrics.jsonl`: RTT, arrival jitter,
interpolation delay, motion counts/rejections, reliable pending age/retries,
event promotions and world-refresh counters. Hosted servers write the same
filename in their state folder, reporting transport queue depth and RTT estimates.
These files contain metadata, not authentication payloads. Render FPS is separate
from these networking measurements.

`tools/native_netcode_check/run.bat` checks wire framing, compatibility, ownership,
freshness, canonical digests and deterministic three-peer impairment scenarios.
The latter exercise 50–200 ms RTT, ±15 ms one-way jitter, 1–5% loss and 5%
duplication, with separate sequence/reordering checks; their results measure the fixture's motion age, not an
Internet gameplay guarantee. `tools/netcode_lab/udp_impairment.py` supplies a
loopback-only real-client gameplay proxy with dynamically adjustable profiles.
Keep bootstrap direct: its login protocol advertises its actual service port.

The mixed fallback run preceded the lifetime-only ownership fix; all final
enhanced runs use the fixed binaries.

Local acceptance uses real original logins, lobby entry, scenario start, guest
position reads and ordinary window-close requests. Final builds retain clean RC1
SDK headers/libraries; the unrelated dirty SDK checkout is excluded.

| Edition | Clients | Mode | Movement, impairment and shutdown |
| --- | ---: | --- | --- |
| File #1 | 2 | Enhanced | Passed; both exit codes zero |
| File #1 | 4 | Enhanced | Passed; all four exit codes zero |
| File #2 | 2 | Enhanced | Passed; both exit codes zero |
| File #2 | 4 | Enhanced | Passed; all four exit codes zero |
| File #1 | 2 | Mixed native/legacy | Passed; whole room legacy, both exit codes zero |

The real proxy profile is 100 ms RTT, 15 ms jitter, 3% loss, 2% duplication and
5% reordering. Both editions matched settled positions on every peer after
controlled reciprocal movement. Enhanced rooms used 100 ms batch intervals;
the mixed room retained 500 ms intervals and sent no native motion.

Existing-actor HP repair was tested separately in four-player rooms. File #1's
non-authority persistent HP fault, 620 to 619, returned to 620 on all four clients.
File #2's fault, 480 to 479, returned to 480 in both persistent records and live
actors, with matching canonical digests. Each case requested a refresh from the
original room authority (player 3 in these runs), which emitted two fresh original
reliable packets. Purely kinematic enemy datagrams were selectively dropped while
ACKs, reliable traffic and mixed records remained available. These tests establish
the bounded existing-actor path, not missing-actor or complete world reconstruction.

The File #2 run exposed a shutdown lifetime bug. Crash dumps placed the invalid
sample-deque operation in `State::reset`, called by transport teardown after the
function-local state was destroyed. The transport now retains shared ownership.
An isolated regression with identical test code and the game compiler crashes
with `0xc0000374` using the old ownership and exits zero with the fix. The socket
checker populates the mailbox after local transports are destroyed, then checks
process teardown through a longer-lived global transport. Final game runs above
use that ownership fix.

Local automated checks pass: 21,667 native assertions, 510 real TCP/UDP/APP
transport checks (498 without a separate APP service), 24 native server tests,
100 relevant upstream Outbreak/reliability/runtime tests, 104 local-build tool
tests (11 skips), 63 co-op harness tests (one skip), nine impairment-fixture tests,
and 1,226 launcher checks. The full upstream suite is not claimed to pass.

These are bounded loopback and synthetic checks. Complete scenarios, critical
interactions, room/script transitions, missing-actor recovery, long sessions and
real Internet conditions still require broader validation before release.
