# Paired response with five-descriptor bank and partner signals

Static File #1 US, 2026-11-05. One complete original o2 body reviewed across6421D0..6427B3, including delay-slot values used at phases5/A and the common partner-offset tail. No execution, build, attachment, live memory, input or networking. States, fields, addresses and descriptor IDs are hexadecimal; explicit counters are decimal. Original action names remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6421D0](../recomp/config/output_ovl/o2/o2_006421D0_0x6421d0.cpp) | `update_paired_response_wait62_active63_and_release4_sequence_candidate` | High mechanics; candidate role | a0actor. Sets54AbitsC/32FF,6673C0idle reset,partnerresolveviaB1D/R1,phasechangepublication. Phase0linksactorsandsetsB20=2;1waitsB1E62;2/3/4/5stepdescriptors/animation/actor-effects;5waits63thenA signalspartner4;BcompletionFF. Usesfive-entrybank711220+40*B99;commoncopiesCF4..CFCtopartnerB28..B30. TimersetCbutnotconsumedlocally. Original subtype/animationmeaningunresolved. |

Prelude matches the paired family in [640B00](SYMBOLS_ACTOR_PAIRED_CONTACT_RESPONSE_640B.md): savephaseA,OR54AbitsC,32FF. Positive6673C0 immediatelyresets54F/548bit1,action1/0/1/0,snapshot,2050start0/blend10,activatebankandreturn. ForA!=0 deriveE=42EB00+D90*byte(74F251+60*B1D);fixedpooladdition'snulltestdoesnotboundtheindex. False63EF30(E)orownB1E6setsAFFexceptcurrentphaseB. Sourceclass0partnerC26!=source3setsAFFwithoutthephaseBexception. ChangedAisserialized67E230(actor,1)BEFOREprocessingthenewphase.

Let `D[i]` denote 8-byte descriptor711220+8*(5*B99+i). Animationticksuse58C300(actor,1);completiontestsbelowareliteral signedlow8comparisons. No B99/indexbound is checkedlocally.

| PhaseA | Concrete work |
| --- | --- |
| 0 | A1,54FB0,D101,snapshot;zeroB22/B1E/B9F;663350(148,149)->E. Null->idle2050blend10. OtherwiseownB24=E/B1D=E.B98;E.B1C/B1E1,E.B1D=source3,E.B24=source,E.B28/2C/30zero. B=bool65F410(source,E,0),yaw=heading(sourceXYZ,E.XYZ)withoutorientationhalfturn;E.B1F=B,E.B20=2. C=60if3243CCzeroelse30;clearrootXYZ,58C7F0,2051start0/blend10,activatebank. |
| 1 | Recomputeheading. B1E==62clearsB1E,incrementsA2,selectsD0start0/blend0,activatebank. OtherwiseanimationtickandrootXYZzero. C is NOTdecrementedortestedhere,unlike6412B0'swaitphase. |
| 2 | Recomputeheading,animationtick;positivecompletionincrementsA3. |
| 3 | A4,D1start0/blend0,activatebank. No phase4fallthroughthiscall. |
| 4 | A5,6681C0(actor,8),thenticksanimationinthesamecall. DoesnotcheckcompletionorB1E63untilnextphase5call. |
| 5 | B1E63clearsB1E,setsAAusinglivea0=Afrominitialdispatch;thenSTILLticksanimation. Signedlow8result2calls6681C0(actor,9);noanimationcompletionphaseoverride. Otherresultsnoadditionalsignal. |
| A | ABusinglivev1=A+1fromdispatchdelayslot;writespartnerB1E4;D3start0/blend0. ThisbodyneverselectsD2/D4. NoactivationcallinphaseA. |
| B | Animationtick;positivecompletionAFF. |
| FF | Byte32=60/30by3243CC;idle2050start0/blend15,skippingpartneroffsettail. Otherresetsuseblend10. |
| Other | No ownphaseoperation,thenpartneroffsettail. |

Commonexit64277C copies sourceCF4/CF8/CFCfloatstoE.B28/B2C/B30whenE!=null. Earlyreset,phase0nullfallbackandFFexitskipit. Thephase0timerCassignmentisobservedstorage,notaneffectivewaittimeoutinthisbody;externalcounterwriterswere notinspectedhere. Phase5actor-effectselector9istriggeredbyspecifictickreturn2,notbygenericpositivecompletion. 6681C0'sindependentcontractanddescriptoractivationremaininthe[animation](SYMBOLS_ANIMATION.md)/[dispatch](SYMBOLS_DISPATCH.md)notes.

Owned711220..71126Fwindow80bytes,twofive-entrybanks,SHA256`ca9262208d821bd52dad5d7b85c4504c4fc3632f917b4e11ab97073c19e7787d`. Everyentryhalf0=60,half2=4. Bank0half4/6pairsE,1A,11,10,F;bank1pairs40,4C,43,42,41. Theseareliteralpackedhalves,notdecodedmodel/start/endfields. Thephysicaltwo-bankwindowdoesnotproveallB99admission.

No runtimewait,partnerlifetime,soundplayback,performancecost,slowdownorrootcausewasmeasured. Original o2base570000SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Full owned-body audit: 349 original words verified; 28 omitted words all zero/NOP; zero conflicts and zero omitted nonzero words.

Correction from complete child review:6681C0 applies difficulty/RNG-indexed health and BAC changes with optional secondary actor effect;it is not a sound request. Numeric selectors above are actor-effect selectors. No audio playback is established by this child.
