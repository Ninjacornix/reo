# ActorD90 getter and600000..680000 stub audit

Static File #1 US owned o2 review, 2026-11-05. All32previouslylistedresidualeight-bytebodiesreadinfull,includingreturndelayslots,andtheirrawownedbyteschecked. [Identity](FUNCTION_INDEX.md). No runtimework,buildorprocessaccess. Catalogueentryownershipisfunctionstart>=600000and<680000.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x663980](../recomp/config/output_ovl/o2/o2_00663980_0x663980.cpp) | `get_actor_d90_unsigned_halfword` | Confirmed complete specific field accessor; D90 domain meaning unknown | JRRAwithdelayslotLHUv0,D90(a0). Returnszero-extended16-bitfield,doesnotmodifyactororvalidatepointer. Thisisnotagenericconstantreturnstub;earlierresidualclassificationwastoobroad. Exactoriginalfieldname/typeownershiprequirescallercontracts. |

663980[8] ownedrawbytes=`0800e003900d8294`,SHA-256 `4dd25df4046010e1db00479e74b33c906c083c151c00b43c5c9507ff202d2d25`. Twononzeroinstructionsfullyverified.

## Honestgenericresidualinventory

Theother**31**bodiesaremechanicallycompletebuttheiroriginalcallback/APIpurposeisunknown. Theyreceive**nonewsemanticmappingrows**here;renamingallofthese`return_zero`wouldinflatecoveragewithoutrecoveringpurpose. Immediatefullbodycontractsare:

| Body class | Count | Exact functionstarts |
| --- | --- | --- |
| Returnonly,untouchedv0 |10|606BC0,606BD0,613D10,615BD0,633780,635630,63F590,6408E0,6409C0,6409D0|
| Returnconstantzero |21|626AD0,626AE0,626B70,626B80,626B90,626BA0,626BB0,6272A0,6272B0,6272C0,627310,627590,6275F0,627650,627660,627670,627760,628D20,628D30,629320,6408D0|

Everyreturn-onlybodyisexactbytes`0800e00300000000`(JRRA,NOP),oneoriginalnonzerowordplusonedelay-slotzero. Everyreturn-zerobodyis`0800e0032d100000`(JRRA,DADDUv0,zero,zero),twononzerowords. Allbodyintervalsare8bytes;nosideeffect,looporindirecttargetexistsinsideanyoftheseintervals. ThisdoesnotestablishcallerABI,observability,unusedstatusorremovalpermission.

Concatenatingeight-bytebodiesinthelistedaddressorder:10return-onlybodiesSHA-256 `f1812e76c444a16b9e140f6311fefb157322e0cd165fbca8162b346bf22d498a`;21return-zerobodiesSHA-256 `65821e73dbfad541ebca9c7858c0f4ce0e9fa6a8b6ebf9b35bd9dbb791a780df`. Totalgenericresidual52nonzerowords+10NOPwords=62words/248bytes.

Theboundedprefix72B820[0]references635630asadefaultcallback,asrecordedin[contactreview](SYMBOLS_ACTOR_65A_CONTACT_REACTION_ROOT_MOTION_AND_SURFACE_ADMISSION.md). Thatoneuseconfirmsonecallbackrolebutdoesnotrecoverallcallersororiginalpurpose;theentryremainsagenericno-opincoverageaccounting. Remainingsemanticrecoveryrequirescaller/table/protocolcontext,notmorebodydecompilation. No performancecost,deadcodeorfullynative-equivalenceclaimfollowsfromthisinventory.
