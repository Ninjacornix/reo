# Overlay o3 browser command menus, focus scrolling and exit gate

Static File #1 US research,2026-11-04. [Owned provenance/audit](SYMBOLS_O3_MENU_INPUT.md),
[document completion/input](SYMBOLS_O3_DOCUMENT_COMPLETION_INPUT.md),[document objects](SYMBOLS_O3_DOCUMENT_OBJECTS.md).
No game,build,replay,network traffic or attachment. These7source-backed bodies have direct control/data-flow review.
No originalsymbols, handwritten translations, measured costs or reproducedslowdowncause are claimed.
The current shared notebook and annotationsJSON were checked before adding these identities.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o3 0x591C40](../recomp/config/output_ovl/o3/o3_00591C40_0x591c40.cpp) | `process_two_or_three_choice_browser_command_menu` | Confirmed/static mechanics; product semantics partial | Root68E85==4 allows3choices,otherstates2. Clears commandbyte68E7A. Confirm routes state4 selections1/2 to command2/1 plus10*context35,selection3cancel;state5 selection1command61,selection2command60/back;state6 selection1command82andnestedmodalstate4,selection2command80. Controller/keyboard repeat uses owned60C8E0 step table and8-call gate;clampsselection1..max ratherthanwrapping. Shared reset591BF0 returnsinputtoidle. Product labels remain unresolved. |
| [o3 0x5922C0](../recomp/config/output_ovl/o3/o3_005922C0_0x5922c0.cpp) | `return_without_nested_browser_menu_work` | Confirmed/static mechanics; product semantics partial | Owned JRRA+NOP only. No sideeffects or establishedreturnvalue. Distinct catalogueentry. |
| [o3 0x5922D0](../recomp/config/output_ovl/o3/o3_005922D0_0x5922d0.cpp) | `focus_browser_object_and_scroll_its_top_left_into_view` | Confirmed/static mechanics; product semantics partial | Lowhalf a0 selects objectpointer withoutlocalbound/nullcheck. Lowbyte a1==0 rejects top-leftY>412-context1C orX>624-context20,clearsselected68E78/returns0. Else cursor modal10/12 =objectXY-pageScroll+10;clampsupper584/380 andadjusts pagescroll. Loweredgesuse literalcontext1A forbothfirsttests,thencontext1E in finalXcorrection; exact offsetsretained. Storesselectedindex68E78,returns1. Float/intconversion andviewport arithmetic reviewed, no externalwait. |
| [o3 0x592720](../recomp/config/output_ovl/o3/o3_00592720_0x592720.cpp) | `handle_profile_save_confirmation_and_copy_local_snapshot` | Confirmed/static mechanics; product semantics partial | 599430(2),confirmroot4F8A4bit10 orkeyboard28. Choice1copies1D0bytes profile67C2D0 toresident8A6BF0;loadingmode2E8opensmodal11,elsefeedback+599110 with67DA98=1. Choice2orcancelbit20/keyboard29calls5993C0(0). No diskpersistcallinside;local snapshotcommitrole confirmed. |
| [o3 0x592850](../recomp/config/output_ovl/o3/o3_00592850_0x592850.cpp) | `handle_boolean_browser_modal_confirmation` | Confirmed/static mechanics; product semantics partial | Confirmbit10/keyboard28calls5993C0(1);cancelbit20/keyboard29calls5993C0(0). No selectioninspectionorcopy. Resident keyboard/controller fields used, not globalhook. |
| [o3 0x5928F0](../recomp/config/output_ovl/o3/o3_005928F0_0x5928f0.cpp) | `confirm_browser_exit_with_loading_mode_guest_loop` | Confirmed/static mechanics; product semantics partial | Setsroot68E85=11,thenrequiresconfirmbit10/keyboard28. Resident38CD80 modes0/2setroot60DCA=2;mode67DBA0==0 counts max500pending type13/state5==1 resources:nonzero setscontext2E8/modal11,else599110 with67DA98=-1. Resident38CD80==1 andcontext2E==8 enters unconditional NOP loop592A6C..592A84;othercontextcalls599110(0). Loop has no reload/callee/exit. Static hazard; no execution or link to player incident established. |
| [o3 0x592AA0](../recomp/config/output_ovl/o3/o3_00592AA0_0x592aa0.cpp) | `return_without_browser_modal_terminal_work` | Confirmed/static mechanics; product semantics partial | Owned JRRA+NOP only. No sideeffects or establishedreturnvalue. |

The exit handler contains an unconditional guest-code loop, not an external-progress poll:

```text
592A6C..592A7C: five NOP words (00000000)
592A80:        1000FFFA  beq zero,zero,592A6C
592A84:        00000000  delay-slot NOP
```

All seven words were checked directly against the owned o3 image. The preceding branch at592A64 jumps to592A88
only when context2E differs from8; equal8 falls through into the loop. The surrounding gates are confirmation
(root4F8A4bit10 or keyboard byte28hex), then resident38CD80==1.
The callback has no inline loop reload that could notice a later mode or keyboard change. The generated function
checks runtime preemption on the backward branch; this can yield host execution while leaving guest PC in the loop.
Thus a guest nonprogress hazard is established statically, but a permanent native-thread hang is not established.

Context2E8 is independently used by590470/5905B0 for pending embedded resources. The semantic purpose of resident
38CD80 value1, normal reachability from player inputs, and whether callers suppress this menu while loading remain
unknown. The specific instruction sequence can be investigated after the mapping milestone; no fix was applied and
this notebook does not attribute the player's Outbreak room/cutscene slowdown to this browser branch.
