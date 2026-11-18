# Native inventory consumption callers and item messages

The direct consumption owner now implements the actual5B4460/5B45E0/5B47F0
inventory callers. They scan canonical actor inventory and descriptors and use
the existing completion, quantity, content, model and inventory owners. The
admitted5B58C0 message frontend uses the update Owner's same `StatePublication`
and `GameplayMessageSink` as scenario publication; neither facade owns a second
queue, actor table or session. These names supersede ScenarioPublication and
ScenarioMessageSink from the preceding checkpoint.

5B4460 scans four carried slots, skips zero IDs, requires matching low16 content
and template flag200, and records eligible local completion before the40000
decrement flag. A usable matching record without40000 still ends the search.
When decrement is requested, its message precedes the direct helper. The record's
self index is reread after message dispatch before decrementing. Decrement
preserves that earlier completion evidence through its shared core.

5B45E0 calls consume/transform on each matching carried ID. A zero result continues
the search, even though completion may already have been recorded. A nonzero
result publishes operation1 after the consumption/content/inventory effects,
using the saved carried ID.5B47F0 searches carried items first; only character6
then searches storage indices1..31. It publishes operation2 before destruction,
using the descriptor self index and rereading that index afterward. Storage0 is
not searched by that fallback. These rules remain distinct from inventory
compaction's character7 grouping.

The typed resource message contains the low16 resource, low8 actor and operation,
with original channel5/type9/length8/options0/dispatch-mode4. All message phase
and raw-mode dispatch gates are preserved through actual1B0310/1AFDD0 comparison.
Unknown padding is not a native wire format. A sink's true result means its
dispatch operation completed, including an intentional queue drop policy; it
does not prove packet storage or delivery. False means the required consumer is
unavailable. Callers refuse at that point and preserve earlier effects. Actual
queue/admission/framing/transport still require migration and validation.

Both compilers pass193,602,856 combined assertions each, including1,216,512 caller
cases and196,608 direct frontend cases.139,178 typed message observations include
inventory, quantity, score and event-capacity snapshots at dispatch, proving the
before/after differences. Complete original callers,5B58C0 and1B0310/1AFDD0
execute; final o8/o9 message consumers are declared ports. Coverage includes all
five owned ITEM banks, controlled templates, all raw phase/mode byte pairs, the
full resource/actor/operation argument domains, duplicate carried contents,
inactive/null cases, self indices, character-specific storage and synchronous
self-index mutation. Prior direct consumption/recipe/model suites remain included.

Both production builds and eight integration tests pass. Production composition
consumes a real live model and inventory item before its operation1 message;
failure checks distinguish the operation0/2 prefix from operation1's later
message. Current completion/publication regressions pass34,031,528 assertions per
compiler, and current worker/phase comparisons pass2,048/4,096 cases. Initial
cohorts retained an ambiguous overloaded message initializer, an ambiguous fixture
helper and GCC indentation errors; warnings remain enabled in the corrected runs.
Exact identities are in `native_resource_wrappers_qualification_v1.json`.

Item health/status effects, other ownership/transfer paths, inventory UI,
network queue/receivers/transport and actual game caller installation remain open.
No game/audio device was launched or foreground input used. Installed V39 remains
unchanged; the full Stage4 and native gameplay acceptance are incomplete.
