# Resident scenario sound remapping and optional spatial routing

Static File #1 US research, 2026-11-04. Main **SLUS_207.65**, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**. Full original bodies reviewed, no target execution/audio/input/network request. Reuses independently mapped [spatial sound and command descriptor helpers](SYMBOLS_ANIMATION_SOUND.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1B8870](../recomp/config/output/sub_001B8870_0x1b8870.cpp) | `remap_sound_event_through_scenario_selected_halfword_table_candidate` | Probable scenario role; full body reviewed | Scenariohalfword3243DA values1,2,1C,23,29 selecttables730BA0/730D40/730EE0/731080/731220. Reads signedhalfword table+2*event a0,returnsvalue;other scenarios return originalevent. Tables are outside ownedmainELF,so current overlay binding/content not assumed. No local event boundscheck. |
| [0x1B8930](../recomp/config/output/sub_001B8930_0x1b8930.cpp) | `request_scenario_remapped_bank_two_sound_with_optional_position_candidate` | Probable sound role; full body/callees reviewed | a0 optionalposition,a1event. Remaps event1B8870;exactFF skips. Nullposition calls1B93B0(bank2,event,owner0);nonnull1B93D0(bank2,event,owner0,position,attenuationselector1,mode0,tag0). Stores remappedhalfword at316550 after eitherrequest. Othernegative remapvalues are not rejected locally;not an audible-success indicator. |
| [0x1B89C0](../recomp/config/output/sub_001B89C0_0x1b89c0.cpp) | `request_unremapped_bank_two_sound_with_optional_position_and_tag_candidate` | Probable sound role; full body reviewed | a0 optionalposition,a1event,a2tag. Nullposition requests1B93B0(bank2,event,owner0);nonnullcalls1B93D0(bank2,event,owner0,position,selector1,mode0,originaltag). No remapping,FF rejection or316550 store. |

The remap table's region must be tied to an owned overlay before assigning actual event names. These wrappers issue requests into the mapped descriptor/queue chain; they do not mix audio, advance game time or establish that any sound played during a reported hitch.
