# Actor 6C contact reaction selection and motion switching

Static File #1 US research, 2026-11-04. Five complete original bodies reviewed.
Addresses/offsets/states hex; explicitly named scalar blend lengths decimal.
Original actor, reaction and action names unresolved. No target execution or fixes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6CA230](../recomp/config/output_ovl/o2/o2_006CA230_0x6ca230.cpp) | `dispatch_actor_6c_contact_and_alignment_reaction_with_record_flags_candidate` | High mechanics; probable role | Stores637490 resultpeer11C;B1E==1 clearsownandsetspeerB1E6. Invokes72B820[unsigned141](actor,6);if138>0 calls666D40(peer). Calls6407D0(actor,peer,64),narrowsreturntosignedbyte;2normalizesto0. Saves8/9,sets1A8=owned7306F8pointer7306C0. Dispatchesstate-specificreactionbelow. Ifnormalizedresult1,5A8140(actor,2 whenrecordbyte74F294+60*B98==1 else0),setsrecordbyte74F295+60*B98=1. Returns1throughalllistedpaths. Nullpeer/index validity remainscaller/calleecontract. |
| [o2 0x6CA450](../recomp/config/output_ovl/o2/o2_006CA450_0x6ca450.cpp) | `select_actor_6c_primary_three_special_alignment_reaction_candidate` | High mechanics; probable role | Sets8=3,A/B=0. BA3=0->9=9,1->7,2->A,3->A. Mode2 firststores8to9 thenfallsdirectlythroughstoreA at4A8/4AC;noinventedbranch. OtherBA3leaves9unchanged. Noanimationselection. |
| [o2 0x6CA4C0](../recomp/config/output_ovl/o2/o2_006CA4C0_0x6ca4c0.cpp) | `select_actor_6c_primary_three_reaction_by_alignment_and_class_candidate` | High mechanics; probable role | Sets8=3,A/B=0;ignoresincominga1,rereadsbyte140. For140=0/1/2:BA3=0 chooses9=0/1/2;BA3=1 chooses7/7/7;BA3=2 chooses8/8/8;BA3=3 chooses2/4/5. Otherclassormodeleaves9unchanged. Noactoridentityinferredfromclass. |
| [o2 0x6CA610](../recomp/config/output_ovl/o2/o2_006CA610_0x6ca610.cpp) | `select_actor_6c_motion_with_state_dependent_blend_or_advance_existing_candidate` | High mechanics; probable role | a0actor,a1requestedmotion. Sameassigned520 onlyadvances58C300step1. Changedmotion5A85F0(requestsigned16,f13defaultdecimal10),withoutadvancehere. Blend0whenprimary8=0;orprimary1and(oldmotion9/A/5 orrequested3). Otherstatekeeps10. f12fornewselectionisnotlocallyinitialized;callee5A85F0contractretained. |
| [o2 0x6CA6C0](../recomp/config/output_ovl/o2/o2_006CA6C0_0x6ca6c0.cpp) | `ensure_actor_6c_motion_without_blend_then_advance_one_step_candidate` | High mechanics; probable role | Comparesrequestedmotionto520;ifdifferent5A85F0(signed16request,f13=0). Always58C300(actor,f12=1)afterward,includingnewselection. No global update/fps semantics. |

6CA230 state-specific dispatch aftersavingstate and installingdescriptor:

- Primary8=2:optionalB24peerB1E=6,667060(actor),115|=1;nonzeronormalized
  contactcode->A450,zero->A4C0(actor,140).
- Primary8=3:nonzerocode->A450;zero->5A7C40(owned7305C8,actorCD8);
  returns1immediately,skippingcontactcode1recordflagsblock.
- Primary8=4:sets8=3,9=0,thensharedcontactcode1recordflagsblock.
- Otherprimary:nonzerocode->A450,zero->A4C0(actor,140),thenflagsblock.

The indirectcallback table72B820 andpeer/contacthelpers are existing mappings;
this notebookdoesnotassignarbitrarynewroles totheircatalogentries.
Reactionselector branch targets anddelay slots werereadthrough,especiallythe
BA3=2fallthroughinA450. Descriptordataandtableaddressareownedfilebytes;
record74F294/295isoutsideowneddataandwasnotreadfromaliveprocess.

Related [alignment/collision](SYMBOLS_ACTOR_6C_ALIGNMENT_COLLISION.md) and
[motionevents](SYMBOLS_ACTOR_6C_MOTION_EVENTS.md). These are staticmechanics,
notconfirmedslowdowncauses.
