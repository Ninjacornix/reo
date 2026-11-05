# Resource transition body 5BA270 and interior 5BA380 boundary

Static File #1 US research, 2026-11-04. One complete original catalog interval
reviewed. Addresses/offsets/constantshex. No targetexecution,attachment,replay,
registration changes or enginefixes. Originaltransition/UIidentityunresolved.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5BA270](../recomp/config/output_ovl/o2/o2_005BA270_0x5ba270.cpp) | `tick_resource_transition_wait_restore_and_callback_cleanup_candidate` | High normal-entry mechanics; probable role | NormalentrysavesactorinS0,calls5BA0F0(actor,4,1),dispatchessignedbyte4phases0..4. Fullphasecontractbelow. Cataloginterval5BA270..5BA46Bcontainsownedzero/NOPat5BA380andinternalphase2target5BA384. Noindependentcatalogbody5BA380;entrycontractatthatinterioraddressnotestablished. |

Normalentryphasecontract:

- Phase0:word68!=FF->5BF0F0(lowbyte68,FFFF);setsbyteB=3C,phase4++.
- Phase1:word324300bit20orpredecrementedsignedBexact0->5A5320(actor),
  5A5060(word70,1),phase4++;other->5A5050(word6C). No<=0substitution.
- Phase2:5A5380(actor),5A5060(word70,1);phaseunchangedhere.
- Phase3:5705F0(word64,1,unsignedbyte100);ifbyte3DDDB5==word68,
  half3DDDB6=0 and byte3DDDE4+198*selectedindex0. Then5705F0(word60,0,byte100),
  5B93B0(actor)zerosresource-recordbody.
- Phase4:sameconditionalglobal/indexedclearasphase3;5705F0(word60,1,byte100),
  5B93B0(actor). Otherphasesreturnafterinitial5BA0F0.

[Main1D4A50](SYMBOLS_SCENARIO_AUXILIARY_RESOURCE_LOADING.md) containsaJAL
to5BA380beforelobbytextureloading. Inthisownedo2catalog5BA380isNOPthen
fallsinto5BA384phase2codeusingS0establishedonlybythenormal5BA270prologue.
This is a **static address/context discrepancy**,notproofthatanactualruntime
callfallsintothatbodywithinvalidregisters. Overlayselection,registrationlookup,
possibleoverridesandtheparticularplayerexecutablemustbereconciledbeforeany
runtimeclaim. No aliasrowfor5BA380wascreatedtoinflatecoverage.

Owned5BA380word00000000independentlydecoded;fullcontainingintervalaudited.
5B93B0existingrecordclearandcallbackhelpersretainindependentroles.
Thelobbycallboundaryisrecordedforparentreviewwithoutchangingloadedcode.
