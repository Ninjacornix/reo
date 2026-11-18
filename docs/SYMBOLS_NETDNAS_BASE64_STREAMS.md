# Network DNAS: Base64 block and streaming codecs

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. No game, build, replay, attachment, network request, live-memory read or target encode/decode occurred.

Ten complete clear bodies were independently read, including every streaming-state exit, wholechunkentry,statelessinitialinputread,quadrupletcheck,returnandpaddingbranch. Alphabet identity below confirms Base64; full RFC/PEMconformance,allchunkboundaries,arbitraryaliasing andruntimeusage remainunproved. The0x60-byte sharedstreamobject haspending0,chunk/lastsize4,buffer8,line58,boundary5C. Encodermode48-byte lines anddecoderstate have distinct initialization. Proposedlabelsarenotoriginalsymbols; no gameplaytimingorslowdowncause isestablished.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x702F48](../recomp/config/output_ovl/o4/o4_00702F48_0x702f48.cpp) | `allocate_zeroed_base64_stream_context_60_hex_bytes` | Confirmed complete byte/table/control flow; format/admission limits retained | Allocates60hexbytes7109F0; failure reports(6,72hex,21hex),NULL. Zeroeswholeallocation107C68,returnspointer. Doesnotselectencode/decodemodeuntilinitializer. |
| [o4 0x702FA8](../recomp/config/output_ovl/o4/o4_00702FA8_0x702fa8.cpp) | `release_base64_stream_context_without_local_wipe` | Confirmed complete byte/table/control flow; format/admission limits retained | Tail710A40(originalpointer); no additionalwipe,fieldread or normalizedreturn. Zero delaywordreviewed. |
| [o4 0x702FB0](../recomp/config/output_ovl/o4/o4_00702FB0_0x702fb0.cpp) | `initialize_base64_encoder_pending_count_and_48_byte_chunk` | Confirmed complete byte/table/control flow; format/admission limits retained | Sets count0=0,chunk4=30hex(48),line58=0. Doesnotclearbuffer8orflag5C; novalidation/returnnormalization. |
| [o4 0x702FC8](../recomp/config/output_ovl/o4/o4_00702FC8_0x702fc8.cpp) | `encode_base64_stream_in_48_byte_lines_with_pending_tail` | Confirmed complete byte/table/control flow; format/admission limits retained | Setscallerproduced=0. Inputcount0returns; otherwise ifpending+input<chunk4,copiesall tocontext8+pending,updatescount. Elsefillspriorpendingtochunk,7031B0encodes,appendsLF/NUL,thenloopsthroughwholechunks withLF/NUL,bufferstail,storesproducedincludingLF. Initialremaining>=chunk testbeforewholechunkbody; ordinaryinitializerchunk48. No calleroutputcapacity,negativecount,mutatedchunk0/overfloworpartialaliasadmission. |
| [o4 0x703138](../recomp/config/output_ovl/o4/o4_00703138_0x703138.cpp) | `flush_pending_base64_encoded_tail_as_one_line` | Confirmed complete byte/table/control flow; format/admission limits retained | Pendingcount0 ->produced0,noop. Otherwise7031B0(output,context8,count),appendLF/NUL,clearcount,produced=encodedbytes+1. No capacitycheck or normalizedreturncontract. |
| [o4 0x7031B0](../recomp/config/output_ovl/o4/o4_007031B0_0x7031b0.cpp) | `encode_bytes_to_canonical_base64_alphabet_with_equals_padding` | Confirmed complete byte/table/control flow; format/admission limits retained | Count<=0writesoutputNUL/returns0withoutinputread. Repeatedpositivegroups3bytes emit4chars viaownedalphabet762E90;final1/2bytegroupsproduce==/=padding,terminatesNUL,returns4*ceil(count/3). No outputcapacityorintegeroverflowguard; canonicalalphabet/paddinglocalshapeconfirmed,arbitraryoverlapunproved. |
| [o4 0x703318](../recomp/config/output_ovl/o4/o4_00703318_0x703318.cpp) | `initialize_base64_decoder_pending_line_and_boundary_state` | Confirmed complete byte/table/control flow; format/admission limits retained | Clearscount0,line58,boundary5C;setsword4=1Ehex(30). No bufferwipe,mode objecttag or returnnormalization. |
| [o4 0x703330](../recomp/config/output_ovl/o4/o4_00703330_0x703330.cpp) | `decode_base64_stream_with_line_boundary_padding_and_pending_state` | Confirmed complete byte/table/control flow; format/admission limits retained | Inputs context,out,producedcell,input,count. Reads/savespending0,line58,boundary5C;zero input orfreshchunkfirstclassF2(-)returns0. Loopslow7bittable;line>=80orinvalidFFreturns-1. FiltersE0/F0/F1/F2classes usingliteral class|13hex==F3hex;validalphabet/equalsbufferedat8. Trackslocalpaddingcount/firstpaddingposition,flusheson64bufferedchars,boundaryorendwithadmittedgroup;703558resultminuspaddingcountaddedtoproduced. Negativeinnerdecode maps0 ratherthan-1;someboundary/paddingconditionsreturn0,ordinarymoreprogress1. Savespending/line/boundaryandproducedonallterminalpaths. Paddingstateispartlycall-local;no allsplits/canonical/highbit/lineconformanceproof or outputcapacityadmission. |
| [o4 0x703558](../recomp/config/output_ovl/o4/o4_00703558_0x703558.cpp) | `decode_trimmed_base64_groups_returning_three_bytes_per_quartet` | Confirmed complete byte/table/control flow; format/admission limits retained | Unconditionallyreadsfirstinputbytebeforecountadmission. TrimsleadingclassE0whilelengthpositive andtrailingclasseswhosevalue|13hex==F3hexwhilelength>=4;requiresremainingmultiple4else-1. Nonpositivecount0afterinitialread;positivequadlookups maskeverybyte&7Fhex,rejectanymappingbit80set,combinefour6bitvalues->3bytes,return3perquad. Equalsmaps0 andisnotlocallyremovedfromproducedcount;streamwrapperhandlespadding. Leadingwhitespaceexhaustioncanreadnextbytebeforetest;directcallerbuffer/lengthcontractremainsrequired,notareproducedfault. |
| [o4 0x7036E0](../recomp/config/output_ovl/o4/o4_007036E0_0x7036e0.cpp) | `flush_pending_base64_decode_groups_and_clear_only_on_success` | Confirmed complete byte/table/control flow; format/admission limits retained | Initialproduced0;pending0returns1. Otherwise703558(output,context8,count);negative returns-1withoutclearingpending,nonnegativeclearscount,storesrawdecodedcount,returns1. No localpaddingdiscount or outputcapacitycheck;successfulflushdoesnotcertifycanonicalinput. |

## Complete owned alphabet and classifications

762E90..762ED1,65bytesincludingNUL,SHA-256 `b549d027496b9c80494809966f74ebf09c8a21512d7f2152230a26ac65016653`:

```text
ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/
```

762ED8..762F58,128bytes,SHA-256 `7c59021dd61df4d884d549501022d6f78e9cd831454eeffbaf73459fdfc7756e`. All128valuesinASCIIindexorder:

```text
00: ff ff ff ff ff ff ff ff ff e0 f0 ff ff f1 ff ff
10: ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff
20: e0 ff ff ff ff ff ff ff ff ff ff 3e ff f2 ff 3f
30: 34 35 36 37 38 39 3a 3b 3c 3d ff ff ff 00 ff ff
40: ff 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e
50: 0f 10 11 12 13 14 15 16 17 18 19 ff ff ff ff ff
60: ff 1a 1b 1c 1d 1e 1f 20 21 22 23 24 25 26 27 28
70: 29 2a 2b 2c 2d 2e 2f 30 31 32 33 ff ff ff ff ff
```

Alphabet characters map0..63;equalsASCII3D maps0. Specialclasses:E0=HT09/space20,F0=LF0A,F1=CR0D,F2=hyphen2D;allothernonalphabet bytesmapFF. Everylookup masksinputto7bits,so high-bitbytesaliasASCII; no strictASCII admissionisclaimed. Thedirectblockdecoderretains3bytesperquartetincludingpadding-derivedzeros,whilestreamingcodecounts/subtractsitsobservedequalscharactersunderitsownbranchrules. A0/1/-1 return fromthesewrappers haslocaldocumentedmeaning,not a blanketinvalid/validclaim.

No host replacement codec,testsorenginebehaviorchange wasmade. Static malformed-input observations are bounded call-contract questions, not reproduced incidents.
