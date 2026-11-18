# Actor speech messages and inventory-map presence

The native sender implements original67E230 selector11. The incoming67ED50
branch11 applies the same state and calls an actual native inventory-map cache
owner corresponding to6DFEE0. These are component changes; the installed game
is still V39 and Stage4 remains incomplete.

`Actor::speech` owns SPK selection, target/context, response/pending state, the
DA9 variant and DB8 gauge notice. Selection, variant and gauge notice are
independently unknown until their real producer, import or receipt supplies
them. A receipt that updates only the variant does not invent the other fields.
The role follows the separately reviewed
[SPK construction and dispatch consumers](../SYMBOLS_SPK_SEQUENCE_CONSTRUCTION_AND_DISPATCH.md);
those higher speech/text consumers are not migrated by message transport.

The sender captures its selection and signed fields, measures the selected
primary actor's actual gauge, stores notice0/1 before dispatch, then uses the
shared authority, suppression and room-routing rules. Lookup callbacks may
change live state or mode without changing the captured payload. It does not
perform the status-classification write used by selectors1/2.

The receiver first applies shared admission and notice clearing. It refreshes
the inventory-map cache before storing the variant. A zero variant for an actor
outside the current room preserves the old selection and gauge notice, then
continues shared pose/equipment cleanup. An accepted payload narrows the context
halfword and response word to signed bytes, and sign-extends the gauge byte to
the canonical word, matching the original operations.

`InventoryPresence` borrows the same World and stores four optional peer samples.
An inactive view or local actor skips refresh; an active remote sample receives
the room's low byte, raw XYZ and lifetime90. The value90 remains a source update
count; no wall-clock conversion or guessed decrement is added. Active indices
outside the four actual UI slots refuse. A missing view owner is unknown and
refuses after shared admission instead of silently assuming a closed UI. Cache
activation does not create the rest of the inventory UI. World closure revokes
its access, and a receiver rejects a cache borrowed from another World.

Both compiler sender comparisons include589825 speech cases,258290 messages
and131074 room lookups. Focused reception includes131072 speech cases,65536
independent complete6DFEE0 comparisons, partial unknown-state preservation,
missing/foreign/closed owner refusals and actual UpdateOwner-to-queue-to-receiver
delivery across separate Worlds. The full resource/recovery/equipment regression
and parent checks are retained in the qualification receipt.

Only outgoing selector3 remains unimplemented. Other incoming branches, actual
speech selection/target/sequence producers and text/audio consumers, inventory
UI lifetime/rendering, external transport/authentication/encoding, semantic
saves and game installation/acceptance remain open. These tests launched no
game and establish no measured slowdown cause or fix.
