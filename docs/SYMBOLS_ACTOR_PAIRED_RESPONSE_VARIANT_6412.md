# Paired response variant with orientation banks and terminal loops

Static File #1 US, 2026-11-05. One complete original o2 body reviewed across6412B0..6421CB, including every phase, cancellation rule, descriptor index and delay slot. No execution, build, attachment, input, networking or live memory. Addresses, states, descriptors and flags are hexadecimal; explicit counts and counters below are decimal. Original action/actor names remain unresolved.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6412B0](../recomp/config/output_ovl/o2/o2_006412B0_0x6412b0.cpp) | `update_paired_actor_response_with_orientation_banks_terminal_loops_and_partner_offsets_candidate` | High mechanics; candidate role | a0actor. Sets54AbitsC/32FF,handles6673C0idle reset,resolvespartnerthroughB1D/R1,appliesphase-sensitiveinvalid-partnerpolicy. Phase0linksactorsandchoosesorientationB;1waitssignal62;2..6loopsdescriptorbankmotionsandsignal63;A/Band14/15release;1E..26terminalcycle;32..34departure;FFcooldown/idleorspecialinputtransition. Common tail copiesownCF4/8/C topartnerB28/2C/30. Full tablebelow;no original semantic enum inferred. |

Compared with [640B00 paired response](SYMBOLS_ACTOR_PAIRED_CONTACT_RESPONSE_640B.md), thisbody uses orientation-dependent six-descriptorbanks, a health-sensitive seven-descriptorbank and several extra release/terminal branches. They are separateoriginalbodies,notaliases.

EverycallORs54AwithC,sets32FF,savesincomingphaseA. Positive6673C0 resets54F/548bit1,action1/0/1/0,snapshot,2050start0/blend10,activatebankandreturns. Otherphases!=0resolve partnerE=`42EB00+D90*byte(74F251+60*B1D)`. It flags invalid when E==null,inactive signedbyte0==0,63EF30(E)==0,ownB1E==6,or(sourceclass0,phase>=2,E.C26!=sourcebyte3). Thepoolarithmetic itself isnot a bound/null validation.

Invalid-partner policy preserves phases B/15/1E/1F/20/23/24/25/26/32/33/34. Phases21/22 with B1E!=2 instead assignaction3/10/0/0,snapshot,publish1andreturn;B1E2leavesthem. Phase1onlychangesAFFwhen1B02D0()==1. Allotherinvalid phases becomeFF. Afterthatpolicy,changedAcauses67E230(actor,1)beforephasedispatch. Areturn canthereforeincludeearliersnapshot/publicationmutations.

Let `F` bebank7110F0 whenB==0,711150 whenB!=0; eachbankindex=`6*B99+i`,entrystride8. Let `T` be7111B0 withindex=`7*B99+i`. Allmotioncallsbelowuse5D50E0,animationticks58C300(actor,1),andcompletionmeans signedlow8return>0. DescriptorbanksareuncheckedbyB99locally. `L` isbytearray711080indexedbysignedhalf10;index0is6. `idle` meansclear54F/548bit1,action1/0/1/0,snapshot,2050activation.

| PhaseA | Concrete work and exact fallthrough |
| --- | --- |
| 0 | A1,54FB0,D101,snapshot;clearB22/B1E/B9F;663350(148,149) resolvesE. Null->idle. OtherwiseownB24=E,B1D=E.B98;E.B1C/B1E=1,E.B1D=source3,E.B24=source,E.B28/2C/30=0. B=bool65F410(source,E,0);yaw=heading(sourceXYZ,E.XYZ)+(B?8000:0);E.B1F=B,E.B20=(B?1:0). C=60if3243CCzeroelse30;clearrootXYZ,58C7F0,2051start0/blend10,activatebank. No phase1fallthrough. |
| 1 | Recomputeheadingwithorientationhalfturn. If C==0setsAFFwithouttick. OtherwisepredecrementsC;B1E==62clearsB1E,incrementsA2,selectsF[i0],start0/blend10,activatebank. Without62ticksanimationandzerosrootXYZ. Counterbecoming0doesnotenduntilnextcall'spretest. |
| 2 | Recomputeheading,thenanimationtick. CompletionA3,Ehalf=L[0]=6,half10=1. |
| 3,5 | IncrementA(to4or6),selectF[i1ifL[10]==0elsei2],start0/blend0,activatebank. |
| 4 | SetsA6,6681C0(actor,B?6:4),thenfallsintophase6samecall. |
| 6 | Health<2setsA1E;B1E==63clearsitandsetsAAforhealth>=2orA1Eotherwise. STILLticksanimationafterthosewrites. CompletionoverridesAwith5,increments10,and6681C0(actor,B?7:5). Thenmode1andfinalAin{A,1E}publishes1;class1temporarilyORsBA0bit10000000aroundserializationandclearsafter. EarlierA1E/AAassignmentisnotguaranteed tosurviveacompletingtick. |
| A | IncrementAB,writepartnerB1E4. OwnB98==1and143bit1selectsfixed7102E0start0/blend10;otherwiseF[i3]start0/blend10. Noownbankactivationcallinthiscase. |
| B | Tick,completionAFF. |
| 14 | IncrementA15,writepartnerB1E5,F[i4]start0/blend10. |
| 15 | Tick,completionAFF. |
| 1E | IncrementA1F;nonnullpartnerB1E3;OR54Abit4;T[i5]start0/blend0. |
| 1F | OR54Abit4,tick;completionA20,E=L0,10=1. |
| 20 | IncrementA21;B!=0subtracts8000fromyaw;fallsintophase21SAMECALL. |
| 21 | IncrementA22,T[i bool(L[10]!=0)]start0/blend0,activatebank. Directentry21doesnotyawflip. |
| 22 | B1E2clearsB1E,health0,A32,skippingtick. Otherwise tick;completionincrements10,predecrementsE;postE==0rearmsE=L0/10=1;setsA21. The earlyA32storeuseslivea1=32frominitialdispatchcomparisons,verifiedalongentrypath. |
| 23 | IncrementA24,nonnullpartnerB1E4,T[i2]start0/blend0. |
| 24 | Tick,completionAFF. |
| 25 | IncrementA26,nonnullpartnerB1E5,T[i3]start0/blend10. |
| 26 | Tick,completionAFF. |
| 32 | IncrementA33,T[i4]start0/blend0. |
| 33 | Tick,completionincrementsA34;phase34bodywaitsnextcall. |
| 34 | ClearsBA0bit00040000. Class1calls5F6800(actor,0),54FA0,action4/0/A/0,snapshot,publish1;otherclasses65FBA0(actor,A). Noownanimationtickhere. |
| FF | Byte32=60or30by3243CC. SpecialB98==1,143bit1,actor3==localplayer,F80bit10ANDany440assignsaction2/15/A/0,snapshotandreturn. Otherpathsidlewith2050start0/blend15 (not10). Skipscommonpartneroffsettail. |
| Other | Nophaseoperation,thencommonpartneroffsettailifE!=null. |

Commonexit642190 copies threefloatsCF4/CF8/CFC fromsource toE.B28/B2C/B30 whenE!=null,evenifaphaseonlyselectedmotionortickedwithoutcompleting. Earlyreset,invalid21/22transition,FFexitandnullresolverfallbackskipthistail. Partnerfields are actual stored offsetvectors; no live transform or world displacement was measured.

Owneddescriptor/timewindows,allfile-backed:

| Owned window | Extent / observed content | SHA256 |
| --- | --- | --- |
|711080..7110BF|64bytes;first8bytesdecimal6,0,1,0,1,0,1,255;otherrepeatedrowsandpaddingverified. ThisisNOTa256-entryvalidatedlist;runtime10isunboundedlocally.|`14a82738652d38810e72c9c66a2d395b321ada06175ca09d9b1b99bc7d96e84a`|
|7110F0..71114F|96bytes,two6-entrybanks. Allhalf0=60. Bank0half2=4forfirstfiveentries,6forlast;half4/6pairs3,13,12,4,5,6. Bank1half2samepattern;half4/6pairs35,45,44,36,37,38. These are packed descriptor halves, not decoded model IDs or start/end ranges.|`bebaf96bf0b8ee29588a41c153624353a8873bc0d5f9fcdb641a704bf0b6ffa6`|
|711150..7111AF|96bytes,two6-entrybanks. Allhalf0=60,half2=5forfirstfiveentriesand6forlast. Bank0half4/6pairsA,15,14,B,C,D;bank1pairs3C,47,46,3D,3E,3F.|`addcd1262cb11655b9ee3e0d374b957ae8e1427ded071f8ca1a393eb1f529650`|
|7111B0..71121F|112bytes,two7-entrybanks,half0=60,half2=6;bank0half4/6pairs17,16,7,8,9,19,18;bank1pairs49,48,39,3A,3B,4B,4A.|`9994de2f0d4dec001baef59c4115bb48f111d11d3744ddf4695a229b8626567f`|
|7102E0..7102E7|8bytes,signedhalves20,0,130,130;specialB98/143branchdescriptor.|`babb7fee9290615d654abe1b0aa47bf1863e676b4fb3951931a0a4b9f8f60939`|

The8-byteformat preserves the [motiondescriptor](SYMBOLS_ANIMATION.md) semantics; no new cliporiginalnames are asserted. Physicaltwo-bankextents above do not supplymissingB99bounds. Partner admission, counterwriters, expected health/signal ordering and any same-tick transition effect need caller/runtime evidence. No reproducedstall,slowdown,performanceclaimorfixisreported. Owned o2base570000SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Full owned-body audit: 892 original words verified; 75 omitted words all zero/NOP; zero conflicts and zero omitted nonzero words.
