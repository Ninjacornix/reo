# Native scenario ownership publication

`ScenarioPublication` reconstructs the admitted67DBD0 ownership path over the
actual World and FlagState. The update Owner binds it behind scenario flag writes
and timer expiration, so the ownership bytes read by automatic completion are
written through the same native owner. No guest pointer or ownership-byte mirror
is used. Native512-entry admission remains explicit.

The selected primary's status mask5C0 suppresses publication without undoing the
earlier scenario bit write. Message phase is the separate signed Session byte
original3243FB; only values1/2 enable the1B0310 branch. Other values write the
replacement owner directly, including overFF. In the message branch, gameplay
mode0 selects the original o9 route and mode1 the o8 route; other modes skip
dispatch exactly as1AFDD0 does. A reached current ownerFF is protected only in
this branch. The byte is read again after the message consumer returns, allowing
the same synchronous mutation order as the original.

The explicit `ScenarioMessageSink` consumes initialized typed fields: flag index
low16 and value low8, with channel5/type0/length8/options0/dispatch-mode4. Original
uninitialized stack padding is not treated as a native wire format. A required
but missing/failing message consumer reports `message_unavailable`, before later
ownership replacement. Overlay queue admission, sender/framing and actual
transport delivery remain required work; this class does not claim those sends
have happened. Unknown selected-primary identities and reached indices outside
the native owner return unavailable. Original full indices are retained until
the actual ownership access; the message request may precede that refusal.

FlagNotifications now return a result. A failed notification propagates through
FlagState instead of pretending the command succeeded; earlier flag and ownership
writes remain visible. Within the update Owner, scenario callbacks observe the
completed native publication; strided notification effects remain a separate
required consumer. Closed owners refuse publication. No game caller currently
constructs this reconstructed core, so no legacy transport is invoked twice.

Both compilers pass34,031,528 combined assertions each, including71,680 direct
publication cases,3,075 actual declared message-port observations and eight new
refusal groups. Complete owned67DBD0,1B0310 and1AFDD0 bodies execute. Only the
final o8/o9 message consumers are declared typed oracle ports; no socket or game
is started. Coverage includes every phase/mode byte combination, all owner-tag
values, high argument bits, source status gating, FF behavior and post-dispatch
tag changes. Missing/failing message consumers and unavailable identities retain
their declared failure ordering.

Current worker/phase comparisons pass2,048/4,096 cases per compiler. They now
register actual inactive canonical primaries for the flag publisher's status
reads, without substituting an absent actor's status. The first ordering fixture
also registered these actors in the audio fixture and collided with its own
actor construction; its failed logs are retained, and the fixtures now initialize
only their required owners. Both current script comparisons pass14,080,853
assertions each. Both parent builds and eight integration tests pass, including
flag-to-owner-tag-to-automatic-completion and missing-message prefix behavior.

Identities are sealed in `native_scenario_publication_qualification_v1.json`.
Other ownership writers, message receivers/queue/transport, strided effects,
remaining gameplay consumers and actual game installation/acceptance remain
open. Installed V39 is unchanged. Stage4 is still incomplete.
