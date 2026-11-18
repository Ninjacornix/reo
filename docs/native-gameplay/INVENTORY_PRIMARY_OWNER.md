# Canonical actor inventory and primary resource detachment

Each native Actor now owns one InventorySlots value with four carried handles
and32 storage handles. WorldInventory operates on that actor through its actual
World identity; it does not maintain a second mutable inventory. C7D's secondary
equipped handle is a separate typed field from the earlier secondary audio/model
selector. CA8 uses the existing resource_action field.

The complete admitted5F22C0/5F2120/5F2180/5F2330/5F27B0 consumers are supplied:
find the first matching handle, remove that occurrence, release selected/
secondary equipped instances through actual ResourceFrames, compact inventories
and insert a descriptor's real self-index before refreshing. Zero remains an
ordinary lookup value. Insertion also refreshes a full inventory, preserving the
source's order rather than retrying insertion after duplicate removal.

Carried handles are stably ordered by active template flag20000, deduplicated
and compacted. Other characters preserve storage slot0 and stably partition
slots1..31 without deduplication. Character7 instead groups slots1..28 by content
12C/12D/12E into three nine-entry groups and retains the last other item. Slot0
and slots29..31 remain unchanged. A group over nine remains explicitly
unavailable after the carried-prefix effects; native code does not reproduce
source stack/bucket aliases or invent overflow gameplay semantics.

WorldInventory also supplies primary SceneOwners resolution and actual detach/
refresh effects. SceneOwners now returns status, allowing missing capabilities
or refresh refusal to stop the scenario operation before later retirement.
Four canonical primary actor indices are supported without an invented activity
gate. Extended actor resolution remains unavailable.

Both compilers pass15,400,003 combined assertions. The inventory portion includes
393,216 lookups,24,576 removals,24,576 insertions,30,576 compactions and192 complete
592CA0 detach cases with real primary actors, resource release and descriptor
deactivation. All five owned template banks plus a separate controlled flag bank
run through the original helper bodies. Carried patterns, the full byte lookup
domain, ordinary storage, bounded character7 group counts, existing/absent items,
all primary actors and all instance/selection combinations are covered. Twelve
refusal cases include overflow admission, stale/foreign owners and closure.
The refresh-refusal case also checks that scenario detachment preserves earlier
inventory effects and does not deactivate the resource afterward. The optimized
GCC parent build required explicit collection bounds and a fixed four-entry
duplicate scan; current comparisons and parent builds pass with those guards.
The29-byte character7 source copy is a declared bounded oracle port.

Both current unpinned scenario regressions and focused descriptor regressions
pass. Parent libraries and four World/collision tests also pass. Exact evidence
is sealed in `native_inventory_primary_owner_qualification_v1.json`.

This closes these inventory primitives and the admitted primary detach consumer,
not the full equipment/use/recipe/transfer system, extended actors, room asset
installation or native gameplay acceptance. The installed game remains V39;
no game was launched and Stage4 remains incomplete.
