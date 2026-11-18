# Three zero-key DNAS spans: recovered local contracts

Static File #1 US research, 2026-11-05. Owned o4/netdnas.bin, base6E0000, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. This review reconstructed **copied data buffers only**. No original image, generated code or runtime was modified; no guest instructions were loaded, emulated or executed; no game, build, live-memory read, network request or attachment occurred.

The three reviewed zero-key spans were previously bounded in [the residual inventory](SYMBOLS_NETDNAS_RESIDUAL_BOUNDARIES.md). This notebook supersedes the unknown local-operation boundary for these **three owning entrances only**. It does not credit protected fragments, skipped metadata or source-less intervals as extra functions. Source catalogue endpoints are retained; independently traced logical continuations are stated explicitly below.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x749500](../recomp/config/output_ovl/o4/o4_00749500_0x749500.cpp) | `compare_bounded_unsigned_byte_sequences_with_zero_key_transform_envelope_candidate` | High complete reconstructed local mechanics and clear continuation; original API name unknown | a0first,a1second,a2count; recovered17words implement lexicographic unsignedbyte comparison returning-1/0/1. Clearprologue, protectedbody, skippedrestoremetadata andepiloguejoinedthrough749638; exactoriginal-byte restoreverified. No source-lessfragmentcredit. |
| [o4 0x749638](../recomp/config/output_ovl/o4/o4_00749638_0x749638.cpp) | `test_0101_mips_elf_like_two_segment_layout_and_inner_0202_marker_candidate` | High complete reconstructed numeric contract; format attribution inferred | Checks fixedheaderhalfwords and onefirst-segmenttype/innerhalfword asdetailedbelow,returns0or-1.35reconstructedwords pluscompleteclearrestore/returnthrough7497A4;paddingends7497A8. No ELFmagic/bufferlength/adversarial-inputvalidationclaim. |
| [o4 0x74E1A8](../recomp/config/output_ovl/o4/o4_0074E1A8_0x74e1a8.cpp) | `compare_bounded_unsigned_byte_sequences_with_second_zero_key_envelope_candidate` | High complete reconstructed local mechanics and clear continuation; original API name unknown | Same17reconstructedwordsas749500,distinctentry/restoremetadataandaddresses. Joinedlogicalbodythrough74E2E0returns-1/0/1. This is payload-byteidentity, notwholewrapperbyteidentityorarelationshipinferredfromnames. |

## Reproducible copied-data evidence

Newisolatedhelper [recover_dnas_zero_upper.py](../tools/function_index/recover_dnas_zero_upper.py) reads the fixed hash-bound owned image, creates private word lists, transcribes the eight independently reviewed upper primitive pairs, and writes [JSON receipt](../build-function-index/dnas-zero-upper-recovery.json) plus [addressed word-field listing](../build-function-index/dnas-zero-upper-recovery.txt). It never writes the owned image or publishes a replacement binary. All **69 recovered words** and **116 clear words**, including10NOPs, were individually read with their paths/branches; all three listings have zero unrecognized decoded fields.

| Owner | Header5words | Protectedinterval | Actual restore4words |
| --- | --- | --- | --- |
|749500|749570:`0 5BB295FD 0 5BB295B9 0`|749584..7495C8 (17words)|7495E8:`5BBDF592 1 5BBDF5D6 0`|
|749638|74969C:`0 B694CABE 0 B694CA32 0`|7496B0..74973C (35words)|74975C:`B694CEBA 1 B694CE36 0`|
|74E1A8|74E218:`0 F2D58590 0 F2D585D4 0`|74E22C..74E270 (17words)|74E290:`F09585D2 1 F0958596 0`|

Ranges are half-open; addresses/words hexadecimal. Everycase's entrycallloads header+8 intoa3(0),header+Cintoa1(tokenA),header+4intoa2(selectorB),literalpayloadstartintoa0. ActualentryJAL7457C8sites749548,749674,74E1F0chooseinverse becausemodebit0isclear. Span=tokenA XORselectorB equals44,8C,44hex respectively. Zeroidlookup7458A0returnszeroexceptioncount/list/base;thereforeallwordstransform. This direction and absenceofexceptionsarederivedfromthereadcallarguments/dispatch,notchosenfortextplausibility.

Every actualrestorecallloads itsindependentmetadata+4intoa3(1),+8intoa1(tokenA),+0intoa2(selectorB),literalpayload**end**intoa0. Sites749610,749784,74E2B8chooseforward overexactlysameinterval. Recordednormalizedschedules:

| Entryinverse slots | Actualrestoreforward slots |
| --- | --- |
|5,7,5,1,2|2,1,5,7,5|
|6,3,2|2,3,6|
|0,1,5,0,5,5,2|2,5,5,0,5,1,0|

The helper obtains both schedules from owned descriptors separately; it does not generate the restore schedule by reversing the entry schedule. Reversal is an observed relationship checked afterward. Normalizer745998 masks seven selector nibbles to0..7 and count to0..7,default5onlywhenzero. Forward table767A40 contains{745AD8,745B78,745C18,745CC8,745D78,745E50,745F10,746010};inverse767A60 contains{746200,7462A0,746340,746400,7464C0,746598,746670,746780}. Both tables and **all16 full primitive bodies** were independently read, alongside7457C8/7458A0/745958/745998/745A00/746128.

LetA=09F8ED17,B=A95128C3,P(byteslittle)=[b1,b3,b0,b2],Q=[b2,b0,b3,b1]. Slots0/1XOR A/B;2ROL13/ROR13;3ROL8/ROR8;4P/Q;5forwardROL13(w)XORA,inverseROR13(wXORA);6forwardP(ROL8(w)XORB),inverseROR8(Q(w)XORB);7forwardROL8(ROL13(P(w)))XORA,inverseQ(ROR13(ROR8(wXORA))). Masks/arithmeticshiftfillwerecheckedagainstthestores. The new helper validates both compositions onzero,allbits,32basisbitsand3mixed-bitwordsforeachslot,plusactualwhole-spanrestores. These are arithmeticdata checks, not guestexecutionorwhole-programtests. [Prior primitive review](SYMBOLS_O4_WORD_TRANSFORMS.md) and [dispatch review](SYMBOLS_NETDNAS_PROTECTED_DISPATCH.md) provide antecedent source contracts.

| Span | Original SHA-256 | Reconstructed SHA-256 | Actual-selector payload restore |
| --- | --- | --- | --- |
|749584..7495C8|`39e0cf0d8484d0e2a86c5218a9d7fefd8701cdbbcd9777aed719c8610a80ffaa`|`e507066b82b2fdcae2e125652cd50fee53febe455dcd130cdb380c25b1544da9`|Exact17/17words|
|7496B0..74973C|`2ea091043f796161377832d83a61cf24094ee370cc91c42add07b4bb3c3543a4`|`1e3cc730042815eba63f666ec8d1b8dfbbc772cfed5cdcdee3cb51605baf292e`|Exact35/35words|
|74E22C..74E270|`f6fec87cbbdecdfcb69b29ead3d5bdc995a6dca78a8ceccb1c05e38d35c8e636`|`e507066b82b2fdcae2e125652cd50fee53febe455dcd130cdb380c25b1544da9`|Exact17/17words|

## Complete joined ownership and envelope

749500clearprelude749500..749558 saves48-byteframe,s0/s1/s2/s3/RA,capturescount/second/firstins1/s2/s3. Itchecksliveheaderword0;zeroJAL7457C8withtheargumentsabove;nonzeroskipsthatcall. Bothbranch749550to749584,delayNOP. Metadata/junk749558..749584isthereforeskipped. Everyrecoveredexitreaches7495C8,whoseclearbranchskips7495D0..7495F8torestoreglue7495F8. Restorecall/epilogue7495F8..749638returnsoriginalresultfroms0throughv0,restoresallcapturedcallee-savedregisters/RA,anddeallocatesframeinJRdelay. Noneofthemetadatawordsthatlooklikeinstructionsaretreatedasexecutedcode.

749638clearprelude749638..749684saves32-byteframe,s0/s1/RA,capturespointerins0,initializess1=-1. Branch74967Cskips749684..7496B0intorecoveredbody7496B0. Allfailure/successpathsjoin74973C,whoseclearbranchskips749744..74976Ctorestoreglue74976C. Call749784,movev0=s1andbalancedepiloguereturnat74979C/delay7497A0;7497A4NOPispadding. Thecatalogue749684fragmentandfourone-byteintervals749698..74969Bareinside**skippeddata**,notnewlyrecoveredfunctions.

74E1A8envelopeissymmetricto749500incontrol/stackcontractbutusesdifferentliteralmetadata/addresses:clearprelude74E1A8..74E200,branch74E1F8->74E22C,skipped74E200..74E22C,recoveredbody..74E270,branch74E270->74E2A0,restore74E2B8,balancedreturn74E2D8/delay74E2DC. Cataloguefragment74E200isinside**skippeddata**andreceivesnorow.

Complete original joinedintervaldigests,includingprotectedbytesandallskippeddata:749500..749638=`44cfaded211e1669b9cae9e4c4326b83b6eb84b2a9c33601eacdb6f955763b0c`;749638..7497A8=`90cbc98a50fc0932f6ac894d67f084ba787066c48990d6f33d7fa5cdb9aa7340`;74E1A8..74E2E0=`1dd0cd1b33de7364a28126355bc734dd57c80b3f00fa97557ffe90348def9c0c`.

These joined contracts concern original static ownership/control flow. Header-self-pointerwrites,cachecalls1148A0(0)/(2),concurrententrysafetyandactualruntimeheaderstatearenotperformedorsimulatedbytheprivatehelper. Exactpayloadrestoredoesnotbyitselfprovewhole-envelopeorconcurrentruntimeequivalence. Inputsaliasedtothecode/headeroroutputcontrolstatecouldobserveenvelopewrites;noaliasinvariantisinventedfrompayloadpurity.

## Unsigned byte comparisons749500/74E1A8

Inputsfirst=a0,second=a1,count=a2. Preserveinpointers/counts3/s2/s1. Cursorstarts0. Countzerojumpsdirectlytoresult0withoutinput-byteaccess,onlyaftertheprotectionenvelopehasperformeditsnormalheader/transformsteps. Otherwise readunsignedfirst[cursor],incrementcursor,readunsignedsecond[oldcursor],computeunsignedcursor<count. If firstbyte<secondbyte,result-1;iffirstbyte>secondbyte,result1;otherwisecontinuewhilecursor<count,else0. BothnonzerocomparisonbranchesuseJR-independentbranchdelayslotsassigningthecorrespondingconstantbeforejoiningrestore. Theloop'snextfirstpointeradditionoccursinitsbranchdelayslot;itdoesnotreadafurtherbytewhenexiting.

No terminator-string semantics,localehandlingorbyte-differencesizedreturn:thelocalresultisnormalized-1/0/1. Countisoriginala2capturedviaDADDU;thecursorADDIUproducesasign-extended32-bitresult,andSLTUcomparesitagainstthatpreservedcount. PointerADDUwraps32bits. Thisisanarrowcontractforadmittedordinarycounts,notunrestrictedhostmemcmp(size_t64)equivalence;validpointerlengthsandcallerABIareunresolved. Thetwo17-wordreconstructedpayloadsarebyteidentical,includingrelativebranches;theirwrappermetadata/absoluteliteralsaredifferent.

## Specific header-layout check749638

InputP=a0;initialresult-1. ItalwaysreadswordP+1C(phoff-likeoffset)andunsignedhalfP+4beforethefirstadmission. ComputesT=P+word1Cinthefirstbranch'sdelayslot. Orderedrequirements:

1. halfP+4==0101.
2. halfP+12==8.
3. halfP+2A==20.
4. halfP+2C==2.
5. wordT+0==70000080.
6. halfP+10iseitherFF80or2;the2valuecomesfromthealreadyverifiedhalf2C.
7. U=P+wordT+4;halfU+18==0202.

Allreadsareunsignedhalf/wordaslisted;offsetadditionsare32-bitADDU. Everyfailedrequirementleaves-1andjoinsrestore;finalmatchinghalfsetsresult0viaMOVZafterXOR0202. Nootherreturnvalue,memorywriteorchildcallinsidetherecovered35words. TheELF-like/MIPSinterpretationisinferredfromthefieldlayoutandliteral8;thisis**not**ageneralELFvalidator:itdoesnotcheckmagic0..3,inputlength,nulls,offsetbounds,segmentextent,alignmentorloadability. Originalmoduleformatnameandcalleradmissionremainunknown.

The original generated-commentaudit checks only the unchangedcatalogue-ownedsourcecommentsagainstencoded/clearownedwords. Itdoesnotvalidatereconstructedwordsagainsttheencodedimage;thehash-boundprivatearithmeticreceiptandfulljoinedlistingprovidethatseparateevidence. No incidentrootcauseorperformanceimprovementisclaimed.
