# Native weapon depletion and use cost

`ResourceDepletion` implements5B4AD0 replacement and5B2590 use cost through the
actual recipe/descriptor/model, debris, equipped-resource audio and weapon
resource owners. Construction requires one World/resource/template binding and
the exact same audio owner for the frontend and weapon loader. A second owner
sharing only the RNG does not qualify as the same mixer/descriptor state.

Replacement preserves the active/owned admission, template bits1/80000,
nonpositive quantity and nonnegative signed alternate-content gate. A visible
primary requests debris and equipped-resource cue5 before replacement. The
current primary is rebound through the actual factory, quantity is initialized
from the new content, and the passed actor's selected equipment is refreshed.
There is no inventory detach, extra completion event, model replacement or game
speed change. The admitted native visibility field is boolean (source byte0/1).

Cue5 is the1B8C70 resource route, not the1B8BB0 actor route. It uses the actor's
currently selected resource metadata and identity bank slot+8 before content
changes. Nonprimary-category cue5 and absent selectors preserve their original
no-request behavior. Natural visual capacity or missing effect resources do not
suppress later cue/replacement work; a full named-bank queue does not undo the
committed descriptor, quantity or WMD changes.

Use cost reads metadata before the mode0/use-override bit0 gate. When bit02000000
applies, character1 costs6, character4 costs2, and other character bytes cost4.
The signed quantity narrows before clamping nonpositive results to1. Quantity
below2 with80000 is set to0 and replacement uses the descriptor's self byte,
which can identify a different descriptor. The caller returns3 even when that
replacement logically returned0. Other result1/2 flag selection preserves the
saved pre-call flags. Required unavailable capabilities expose their known
mutation prefix instead of a fabricated successful action.

Both compilers pass272,433,193 combined assertions each. The component adds
786,433 flag/quantity/cost/bypass cases and577 model/audio/WMD cases across five
owned ITEM banks and a controlled bank. The16-bit quantity and character-byte
domains vary; this is not every possible cross product. Existing primaries,
redirected self indices, zero/nonzero selection, category gates, queue/work
capacity and native-only missing/split-owner prefixes are exercised. Four refusal
groups preserve their exact known prefixes.

Complete5B4AD0/5B2590/1B8C70/1D3B00/6B4AE0 bodies execute in the oracle. The final
1B93D0 bank request delegates to the independently qualified native audio owner
and mixer. A real owned weapon33 sound bank is explicitly assigned to identity
bank8 for these cases; this is controlled bank assignment, not a claim about a
recorded room.49 actual commands produce8,548 nonzero samples, with147,712 PCM
frames compared exactly. The catalogue prepares from the actual ROM once; action
calls perform no additional ROM reads. Parent builds and eight integration checks
per compiler pass. Identities are sealed in
`native_resource_depletion_qualification_v1.json`.

This checkpoint admits the current sixteen prepared WMD selectors. **Stock item
selectors with no WMD file still need an explicit absence profile**: the current
native weapon owner refuses them and skips their later sound request. That
[source/asset gap](WEAPON_WMD_ABSENCE.md) is the next fix, so this checkpoint does
not establish complete stock weapon support. Other ownership/transfer/UI/game
callers, real installation and coherent scenario acceptance also remain open.
Installed V39 is unchanged; Stage4 remains incomplete. No game or physical audio
device was launched for these checks.
