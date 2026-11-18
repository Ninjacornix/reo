# Native resource use and content lookup

`ResourceUse` implements the complete admitted5B3AA0/5B3B80/5B4E60
consumers through the canonical World, SceneResources, ResourceModels and ITEM
template owners. `WorldInventory::find_by_content` implements5F2210 over the
same actor's four carried and32 storage slots. These are native values and
capabilities, with no guest address or second mutable inventory.

Inactive use returns0. Ordinary use decrements the signed halfword quantity
with wrapping, even when already zero or negative, before configuring the
instance. Positive remainder returns2; other remainders return1. Mode0 with
session gameplay-flags bit0 configures without decrement and returns2.
Configuration clears descriptor flag20000 even when its instance is absent.
An existing instance clears flags20800, sets180000, clears delayC and copies
the optional twelve/eight-byte payloads, using zero for absent payloads. It
does not allocate, destroy, detach inventory or play sound.

Initial quantity checks activity and selectorFF first. Content3717 returns
1200 for clock-mode0 and600 otherwise; ordinary content reads signed ITEM
halfword8. Content lookup uses unsigned low16, skips zero slot handles and
returns the first matching resource ID, including inactive records. It does
not filter quantity or ownership.

Both compilers pass2,658,237 assertions each:65,536 uses,4,096 additional
configurations,660,480 quantity queries,65,536 content lookups and five
ownership/closure refusals. Coverage includes all mode/flag bytes, the complete
signed quantity domain, optional bit-pattern payloads and all five owned ITEM
sections. Both cleared-table and retained-tail import lifecycles are compared
against the original bodies. An initial fixture incorrectly reset only the
original table; detailed failure evidence is retained and the fixture now
compares equal lifecycles. No production behavior was changed to hide that
failure.

The current full inventory/resource regression passes18,159,345 assertions per
compiler, including actual construction, release, placement, delayed callbacks
and inventory ordering. Both parent builds and five integration tests pass.
Exact identities are sealed in `native_resource_use_qualification_v1.json`.

Arbitrary original pointer-alias payloads are outside this native value API.
Higher-level use/recipe/transfer and gameplay/UI callers remain open, as does
the full movement consumer for configured use payloads. No game or audio device
was launched. This component is not installed in V39 and does not close Stage4.
