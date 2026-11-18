# Actor 6C command wrapper and phase admission

Static File #1 US research, 2026-11-04. Three complete original bodies reviewed.
Addresses/offsets/constants hex. Actor and original command identities unresolved.
No execution, attachment, replay or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C5440](../recomp/config/output_ovl/o2/o2_006C5440_0x6c5440.cpp) | `gate_actor_6c_command_adapter_or_run_related_retry_work_candidate` | High mechanics; probable role | 625630(actor)==0->54C0(actor),6257A0(actor,10A4). Result1setsFCF3;othernonzeroFCF4,health5440,6260E0(FB5);both684810(actor,0). Classifierandpublisheralreadymapped;no originalcommandnameclaimed. |
| [o2 0x6C54C0](../recomp/config/output_ovl/o2/o2_006C54C0_0x6c54c0.cpp) | `admit_actor_6c_command_sequence_in_selected_scenario_and_record_ids_candidate` | High mechanics; probable role | Reads16bits3243DA. Scenarios1,2,1Ccall5560. Scenario23onlyBB4in84/26calls5560. Othercasesreturn. No roomcomparisonoractoridentitytest. |
| [o2 0x6C5560](../recomp/config/output_ovl/o2/o2_006C5560_0x6c5560.cpp) | `initialize_actor_6c_command_phase_and_rearm_on_fcc_zero_candidate` | High mechanics; probable role | UnsignedFD2:phase0FD4=64D,1155/FCC1,FB7FF;unlessBA0bit80000sets8/9/A/B/FB8zero,FB7=8,byte1=1;FD2++. Phase1:scenario!=1andBB4=79andword4B9C04bit100setsFD2=2;independentlyFCCsignedbyte0repeatsFD4/1155/FCC/FB7initializationandconditional8/9/A/B/FB8reset,withoutFD2increment. Phase2/otherreturn. FB7isexplicitlysetFFbeforethecheckagainst8,soresetoccurswhenBA0bitclear. No busywait. |

The54C0/5560 command wrapper is distinct from the normal5690actorupdate.
Related [existing command classifier/retry](SYMBOLS_ACTOR_COMMAND_TRANSITIONS.md).
The684810 callee role remains outside this scoped claim;its numeric
arguments and ordering are retained. Nofrequency or performance attribution.
