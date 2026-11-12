# Room lighting and fog load

CutsceneLights::load_room implements the reached1D4870 operation at5ECF90+EC.
It borrows the same World/session, Lighting, Fog and actual ScenarioArchive.
There is no second light pool, fog selection, room identity or controller clock.
The existing6B3830 constructor body is shared with initialize through a private
implementation, while the whole operation holds the worker's busy guard.

Nonzero asset-loading modes format the current scenario/room/variant LIG name,
read its actual AFS sectors through the authored scenario_H table, import only
a positive read, then perform the independent FOG read/import. Mode0 instead
selects the default compiled catalogue. None of its1,342 owned keys names a
room LIG/FOG resource, so those gates miss. Both branches still call6B3830.
Missing files preserve the prior banks. Unknown required session inputs and
unsupported scenario archive producers refuse; no successful provider is invented.

A successful version4 LIG import calls6B1DC0, which also invalidates the shared
fog selection at3240BD. The composed loader applies that effect through the
canonical Fog.reset_selection before FOG import. An unsupported LIG version does
not execute that reset. This matters when the old fog selection is already0:
the original cache check otherwise preserves stale selected values. The isolated
Lighting API continues to own its physical-light subset of that larger reset.
Other unconsumed renderer words cleared by6B1DC0 remain a renderer adoption boundary.

Both compilers pass5,589,724 checks in the whole-helper v4 comparison:227 room
keys,4,086 visits,1,752 LIG reads,2,676 FOG reads and1,362 default-catalogue miss
visits. They execute35 complete source bodies with1,927 matched instruction
words and16,177,743 original calls. Cases cover cached fog selections0/1/255,
primary/auxiliary pool pressure0/63 and asset modes1/0/255. Two room keys exercise
the common-scenario formatting miss and maximal16-bit room/variant inputs.

The independent manifest preserves all six actual_H tables in original ordinal
order and hashes real sector bytes. File1 contains380 physical LIG/FOG members:
370 in the regular scenario archives and ten in rfff. Only369 regular names match
this caller's exact room filename grammar; R0011800_OLD_FOG and the ten common
members do not establish additional reachability through this entry. The225
authored room keys plus two boundary cases remain separate from complete room
transition acceptance.

Original1AA1E0's selected descriptor metadata is an explicit fixture built from
those actual_H tables. SDK task allocation, physical-sector transfer/completion/
close and bounded standard string/format primitives are explicit seams. The
namespace selectors, name normalization, sector-size getters, imports, fog math
and light constructor/pool children execute their complete pinned source bodies.
Production has no CPU context, registers or addressed RAM.

The private comparison copies exact SessionRooms v6 archives with their matching
headers and compiles complete current Lighting/Fog/ScenarioArchive and cinematic
light units. It does not mix an old NativeSession archive with a current layout.
Current application adoption is qualified separately through the real CMake target.
The current application pair passes285,448 checks per compiler with the same227
keys and4,086 visits, including unknown-input refusal and real World closing.
It captures the current InventoryUi/DialoguePool application layout. Current
parent28 v2 also passes both compilers without drift. The
[scoped seal](../../tools/native_reconstruction/native_cutscene_room_lighting_qualification_v1.json)
records the exact six receipts and static5ECF90 caller authority.

Development v1 retained a static-discovery failure before compilation. V2 caught
a fixture hex-token spacing error. V3 caught the actual cross-owner fog-selection
omission; v4 includes and proves the correction. Complete5ECF90, its other model/
facial/render/reset children, full scene/movie lifecycle and game installation
remain open. No game, desktop window, audio device or power action is performed.
