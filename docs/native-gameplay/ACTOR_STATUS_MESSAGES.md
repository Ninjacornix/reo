# Native status clearing and actor health/status messages

The update Owner now exposes `clear_actor_status` and `record_actor_status` over
canonical entity capabilities. Status clearing reuses one extracted native field
operation; the earlier general status-service path calls that same operation.
No actor or session is copied into a message-specific state model.

The publisher supplies the admitted67E230 selector14 path, not the other15
selectors. It preserves the separate1B0310 phase gate, pause, category/authority
admission, status4 suppression and the shared744638 selector-suppression word.
Primary messages require actor slot equal to selected actor. Category1 requires
status10000000 and uses the actual room-owner capability. Other categories return
without sending. Primary slot255 produces integer channel256.

The typed message carries selector14/length12, channel, status word and signed
health halfword. Known source bytes2/3 are zero; unknown trailing padding is not
a wire-format promise. Category1 lookup occurs after payload capture. Its
synchronous consumer can change mode or actor state; dispatch rereads mode while
retaining the earlier payload. Modes outside0/1 perform no final message dispatch.
Missing required lookup or message consumers report unavailable. A sink's true
result means its dispatch operation completed, including intentional drop policy;
it does not prove network delivery.

All256 low-byte6605B0 selectors preserve the original field mutations and then
request selector14, including selectors which mutate nothing. Publication gates
therefore do not undo a preceding heal/status clear. The Owner reports missing
message consumers after those field changes. Stale/foreign actor capabilities
refuse at the required state access. The original early message gates themselves
do not require an actor, matching the source's ordering.

Both compilers pass35,716,097 combined assertions each, including327,680 actor
message/clear cases,23,080 typed message observations,11,690 room-owner lookups and
seven additional refusal groups. Complete original67E230 executes only the
admitted selector14 and early gates; complete6605B0 and1B0240 bodies execute too.
The two switch tables are loaded from owned o2 bytes. Coverage includes every
phase/mode byte pair, all signed health/maximum values, all clear selectors,
authority/category/status gates, suppression, channel overflow and synchronous
lookup mutation. Final message and room-owner consumers are declared ports.
Unentered selector1 float-conversion paths deliberately throw if reached; this
does not claim conversion or other-selector coverage. The initial cohort retained
its missing oracle conversion declaration and indentation compilation failures.

The seven-body actor status/timer/action regression passes163,840 cases and32,768
RNG requests per compiler. Current worker/phase comparisons and both parent
builds/eight integration tests also pass. Production-linked checks use the actual
Owner's heal/clear fields and typed message callback, including suppression,
pause, mapped channels and unavailable-message prefixes. Exact identities are
in `native_actor_status_message_qualification_v1.json`.

Other actor message selectors and suppression writers, actual room authority and
network queue/transport, remaining health/item callers and game installation
remain open. No game/audio device was launched. Installed V39 remains unchanged;
whole Stage4 and coherent native gameplay acceptance are incomplete.
