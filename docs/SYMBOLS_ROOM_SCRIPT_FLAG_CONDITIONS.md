# Room-script contextual flag conditions

Static File #1 US research, 2026-11-04. Three complete original bodies
reviewed. Addresses/offsets hex. No execution, attachment, build or engine
changes. The three entries are condition-group handlers, not flag mutations.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x701D10](../recomp/config/output_ovl/o2/o2_00701D10_0x701d10.cpp) | `script_op_e3_condition_first_context_flag_candidate` | High mechanics; probable condition role | Payloadword0ID,word4desiredtruth. Increment4BAD58[selected4BADC1].7008C0rawmask!=0 comparedwithdesiredwordnonzero;matchreturns0,mismatch68C9E0skipfailedgroupandreturns2. No flagwrite. |
| [o2 0x701DA0](../recomp/config/output_ovl/o2/o2_00701DA0_0x701da0.cpp) | `script_op_ed_condition_first_set_second_clear_context_flag_candidate` | High mechanics; probable condition role | Sameordinalincrement. Predicate7008C0(ID)!=0AND700930(ID)==0;word4nonzeroexpects predicate,true0expectslogicalinverse. Mismatch68C9E0andreturn2,match0. Preservesshortcircuitqueriesandrawnonzerotests. |
| [o2 0x701E60](../recomp/config/output_ovl/o2/o2_00701E60_0x701e60.cpp) | `script_op_ef_condition_second_context_flag_candidate` | High mechanics; probable condition role | Sameordinal/skipcontractbuttests700930(ID)truthagainstword4nonzero. Return0match,2afterfailedgroupskip;no bitnormalizationrequirement. |

Owned73CBE0 opcodesE3/ED/EF point respectively701D10/701DA0/701E60,
eachwithzero filterbytes. Flagbankaddressingisreviewedin
[room-script runtime](SYMBOLS_ROOM_SCRIPT_BANK_RUNTIME.md),condition
ordinalandnestingskipin[script VM](SYMBOLS_SCRIPT_VM.md). Original
streamadmissionandruntimeiterationfrequencyremainunknown.
