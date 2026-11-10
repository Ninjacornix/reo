# Native paired actor requests

Status: qualified on LLVM and GCC; uninstalled. Stage4 remains incomplete.
InstalledV39 is unchanged and no game was launched.

Selector8 and incoming branch8 now use the canonical actor and ten-actor
auxiliary owner. ActorReference represents a primary slot or auxiliary identifier
that the receiving World resolves locally. It is distinct from an EntityId
capability, and does not carry a guest pointer or a source-World registration.
The admitted legacy peer domain is primary0..7 or auxiliary0..32767; malformed
values and missing primary capabilities refuse instead of indexing unchecked
storage. The typed value does not establish an external wire encoding.

HitActor.transient_contact owns C64's low byte once. Optional PeerRequest owns
only the high state byte, logical peer reference and two parameters. Actual hit
cleanup clears the lower byte while retaining the rest of the request. The
request remains unknown until a real producer or incoming message establishes
its context.

Offline publication captures the payload, mirrors it into the selected peer and
stores the sender slot as the peer's primary reference before final dispatch.
Missing auxiliary lookup returns without sending. Incoming application first
stores the base request, then resolves/mirrors its peer. A missing auxiliary
returns before shared pose/equipment cleanup, retaining that distinct prefix.
Both paths use the unfiltered auxiliary lookup, including inactive records.

Both compilers execute complete67E230/67ED50 with actual666640 and produce
identical observations. Sender comparisons cover589,826 cases,247,689 messages,
125,613 room lookups,120,151 admitted offline mirror cases and ten refusal groups.
8,192 additional actual World/behavior/pending-hit/gauge compositions verify the
lower-byte alias. Sender/alias/pool regressions total116,373,882 checks.

Receiver comparisons cover655,360 cases, including65,536 auxiliary/missing-target
cases, plus257 actual equipment/asset cases and149 queue compositions. The queue
delivers a captured request from UpdateOwner into a different World's receiver
and resolves its peer there. Full regressions pass965,916,741 checks, with114,671
balanced original allocations/releases per compiler. Parent builds and all eight
integration checks pass. Evidence: `native_actor_peer_message_qualification_v1.json`.

Higher request producers, senders3/11, other receive/action/AI branches, external
transport/authentication/encoding, semantic saves and installed-game acceptance
remain open. This is not an installed gameplay or slowdown fix.
