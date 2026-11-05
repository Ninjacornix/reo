# Resident model debug axes and binding delegate

Static owned resident executable SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. Three complete original intervals reviewed. No target execution, debug drawing or binding mutation.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1B33A0](../recomp/config/output/sub_001B33A0_0x1b33a0.cpp) | `delegate_nonzero_render_resource_binding_to_two_slot_arrays` | Confirmed complete static delegate/axis/table flow | Exacttail18C570,a0/a1/a2unchanged;calleeadmitsresourcehandle1..640,index0..31,nonzerobindingandwritespairedarrays. No independentactivegate. |
| [0x1B33B0](../recomp/config/output/sub_001B33B0_0x1b33b0.cpp) | `draw_three_colored_unit_axes_under_supplied_transform_and_scale` | Confirmed complete static delegate/axis/table flow | Setsrenderparam6C=1,backsupscratchmatrixslot0via192000,setsparam1Afroma0transform. Ownedthree24-byteendpointrows234430areunitX/Y/Ztoorigin;scalesfirstXYZonlybyf12,colorsaxisred/green/bluewithalpha80andsecondcolorOR007F7F7F;194FD0each. Restoresparam1Awithbackup,butdoesnotrestore6C. Childdrawstatusesignored. |
| [0x1B3540](../recomp/config/output/sub_001B3540_0x1b3540.cpp) | `draw_twenty_unit_debug_axes_for_every_model_node_of_actor` | Confirmed complete static delegate/axis/table flow | Readsactor34modelroot,nodecountunsignedhalf816;pretestedloopoverpointerarray820calls1B33B0(nodepointer,20.0f). No model/nodepointeradmission oractiverostercheck. |

Owned234430..23447818floats formthree6-floatrows[(1,0,0,0,0,0),(0,1,0,0,0,0),(0,0,1,0,0,0)],SHA-256 `6389194f1651bdb93e6b0033001b19caffb7b1053b3a21965f6365f23b9cbfa5`. [Gouraud line projection](SYMBOLS_IMMEDIATE_PRIMITIVE_VARIANTS.md) owns194FD0admission/perspectivedivision; [render relocation/binding](SYMBOLS_RESOURCE_RELOCATION.md) owns18C570. Debug geometry role does not establish runtime reachability or measured cost.

Audit: 3 rows, 125 verified owned instruction words; 2 omitted interval words are zero/NOP; 0 omitted nonzero words.
