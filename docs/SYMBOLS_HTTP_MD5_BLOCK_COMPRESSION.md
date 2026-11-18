# HTTP overlay MD5-style 64-byte block compression

Static owned File #1 o6 `nethttp.bin`, runtime ID6/base6E0000, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Full original6E9508..6EA518 catalogue interval read in two consecutive chunks split6E9D00;all64rotate steps counted fromsource. No hashing tests, target execution, game/build/network operations. This is a static compression map, not formal equivalence or an implemented replacement.

Companion: [Digest authentication, initialization/update/finalization and little-endian buffer helpers](SYMBOLS_HTTP_AUTH_DIGEST_HELPERS.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x6E9508](../recomp/config/output_ovl/o6/o6_006E9508_0x6e9508.cpp) | `compress_one_md5_style_64byte_block_into_four_word_state` | Confirmed full static structure; complete standard equivalence untested | a0four-wordstate,a1block64. LoadsstateintoFP/S7/S6/T9,decodes64inputbytesas16little-endianwordstostackvia6EA568. Executes64unrolled32bitadd/Boolean/rotatesteps,updatesregistersinFP,T9,S6,S7order. First16use(x AND y)OR(NOTx ANDz)androtations7/12/17/22;next16use(x ANDz)OR(y ANDNOTz),5/9/14/20;next16XORthree,4/11/16/23;last16yXOR(x OR NOTz),6/10/15/21. UsesMD5characteristicroundconstantsincludingD76AA478,E8C7B756,242070DB,C1BDCEEE,F57C0FAFandfinalEB86D391. FinalfeedforwardaddsworkingFP/S7/S6/T9totheinitialfourstatewordsandstores+0/4/8/C;zeroesdecoded64stackbytesvia6EA600. Originalstate/bitcountbuffer+10onwardnotmodifiedhere;doesnotpadorreturndigestbytes. |

Reviewed Boolean groups are visible at6E9560(first),6E99B4(second),6E9E24(third),6EA1B8(fourth). Input-indexschedulesare0..15;then1,6,B,0,5,A,F,4,9,E,3,8,D,2,7,C;then5,8,B,E,1,4,7,A,D,0,3,6,9,C,F,2;then0,7,E,5,C,3,A,1,8,F,6,D,4,B,2,9. Indicesarehex. Fullsourceincludesinterleavedconstantconstructionandstackspills;thesearepartoftheownedinstructionaudit,notextraalgorithmrounds.

All64left-rotationinstructions (PC: working register: shift) retain an independent step count:

```
6E95A0: fp 7
6E95E0: t9 12
6E9620: s6 17
6E9660: s7 22
6E96B0: fp 7
6E96F0: t9 12
6E9740: s6 17
6E9788: s7 22
6E97C0: fp 7
6E97F4: t9 12
6E9838: s6 17
6E9870: s7 22
6E98B8: fp 7
6E98F8: t9 12
6E9954: s6 17
6E9994: s7 22
6E99E4: fp 5
6E9A24: t9 9
6E9A64: s6 14
6E9AA4: s7 20
6E9ADC: fp 5
6E9B40: t9 9
6E9B8C: s6 14
6E9BD4: s7 20
6E9C1C: fp 5
6E9C5C: t9 9
6E9C94: s6 14
6E9CDC: s7 20
6E9D24: fp 5
6E9D64: t9 9
6E9D9C: s6 14
6E9E00: s7 20
6E9E4C: fp 4
6E9EA4: t9 11
6E9EF0: s6 16
6E9F5C: s7 23
6E9FC4: fp 4
6E9FF0: t9 11
6EA01C: s6 16
6EA04C: s7 23
6EA074: fp 4
6EA0A0: t9 11
6EA0CC: s6 16
6EA0F4: s7 23
6EA120: fp 4
6EA148: t9 11
6EA17C: s6 16
6EA1AC: s7 23
6EA1D8: fp 6
6EA210: t9 10
6EA240: s6 15
6EA270: s7 21
6EA2A4: fp 6
6EA2D4: t9 10
6EA304: s6 15
6EA330: s7 21
6EA360: fp 6
6EA394: t9 10
6EA3C4: s6 15
6EA3F4: s7 21
6EA428: fp 6
6EA460: t9 10
6EA498: s6 15
6EA4CC: s7 21
```

No data-dependent loop or allocation occurs inside this body: 16 decoded input words,64fixedrounds,fourfeedforwardstores,64-byteclear. This identifiesfixedper-blockwork,notitshosttimingoraconfirmedslowdownbottleneck. Unalignedsourcehandlingcomesfrom6EA568byteassembly;statepointerandcapacityadmissionremaincallercontracts.

Audit: 1028 verified instruction words, zero conflicts, zero omitted zero words and zero omitted nonzero words.
