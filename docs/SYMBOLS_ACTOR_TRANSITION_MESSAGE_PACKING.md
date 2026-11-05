# Actor transition message packing and local mirror updates

Static File #1 US research, 2026-11-04. One complete large original body reviewed.
Addresses/offsets/lengths hex. Original protocol/type identities and delivery
unresolved. No network operation, target execution or engine change.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x684810](../recomp/config/output_ovl/o2/o2_00684810_0x684810.cpp) | `pack_actor_transition_selector_message_and_update_local_record_mirror_candidate` | High packing mechanics; probable message role | Requiresactorbyte2==1and681970(1,FB5)nonzero. a1lowbyte<8dispatchowned740840. P=stack30;P0selector,P1initial2C,P2/P30;R=390210+78*FB5. EachcaseoverwritesP1length,packsselectedfieldsandcalls1AFDD0(9,P,0,4),exceptselector7lastarg2. Mirrormutationsandpayloadbelow. Doesnotwaitforacknowledgementorproveremotedelivery. |

ActorA, payloadP, mirrorR notation. `b/h/w/f` names byte/half/word/float writes;
XYZ copies threefloatwords. All cases writeP4h=A.BB4 and retainP0selector,
P2/P3zero. Payload is not otherwise fully zero-initialized in this body.

| Selector / internal PC | Declared length and additional payload | Local mirror writes |
| --- | --- | --- |
| 0 /6848A0 | len14;P6b=lowA.1E2,P7b=B9B,P8w=signedFCF,PCw=1150,P10h=544 | R30w=FCF,R1b=low1E2,R16h=544,R20b=B9B,R28w=1150,R1Eb=0;theseoccurafterroutingcall |
| 1 /68491C | len20;P6b=1020,P7b=101F,P8w=FCF,PC..14XYZ,P18w=1150,P1Ch=92 | R30w=FCF,R8..10XYZ,R14h=92,R24b=1020,R25b=101F,R28w=1150,R1Eb=0;beforerouting |
| 2 /6849CC | len1C;P6b=low1E2,P7b=1154,P8w=FCF,PC..14XYZ,P18w=1150 | R30w=FCF,R8..10XYZ,R1b=low1E2,R21b=1154,R28w=1150,R1Eb=2;beforerouting |
| 3 /684A70 | lenC;P6b=1020,P7b=101F,P8w=FCF | R30w=FCF,R1b=low1E2,R24b=1020,R25b=101F,R1Eb=0;afterrouting |
| 4 /684AD4 | len1C;P6b=low1E2,P7b=1154,P8w=FCF,PC..14XYZ | R30w=FCF,R8..10XYZ,R1b=low1E2,R21b=1154,R1Eb=1;beforerouting;R28unchanged |
| 5 /684B68 | len20;P6b=1020,P7b=101F,P8w=FCF,PC..14XYZ,P18w=1150 | R30w=FCF,R8..10XYZ,R24b=1020,R25b=101F,R28w=1150,R1Eb=0;beforerouting;no yawwrite |
| 6 /684C08 | len24;P6b=low1E2,P7b=B9B,P8w=FCF,PC..14XYZ,P18h=92,P1Ah=544,P1Cw=1150,P20w=unsignedbyte113C | R30w=FCF,R8..10XYZ,R1b=low1E2,R14h=92,R16h=544,R20b=B9B,R28w=1150,R1Eb=0;afterrouting |
| 7 /684CCC | len18;P8..10XYZ,P14h=92 | R8..10XYZ,R14h=92;afterrouting;othermirrorfieldsunchanged |

Owned740840eightPCs6848A0/491C/49CC/4A70/4AD4/4B68/4C08/4CCC checked
againstallbranches. Headerlengthdoesnotprovethateverybyteuptothatlengthis
writtenhere;unknownpadding/consumersemanticsretained. R78hexstride isdecimal120.
681970admissionandFB5boundsremaincallee/callercontracts,notoriginalenumguesses.

[1AFDD0mode routing](SYMBOLS_DISPATCH.md) may forward accordingtosessionmode
orreturnwithoutforwarding. Localmirrorwritescanthereforehappenwithoutproven
externaldelivery. Theactor6Cwrapperusesselector0,see
[commandadmission](SYMBOLS_ACTOR_6C_COMMAND_ADMISSION.md).
