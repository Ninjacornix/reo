# HTTP overlay ASN.1 line-oriented hexadecimal reader

Static owned File #1 o6 `nethttp.bin`, runtime ID6/base6E0000, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Complete catalogue interval706168..7064E8 reviewed with initial line/nibble loops, branch-likely slots, allocation and continuation paths. No target execution, input read, output mutation, network/live attachment or build. Numbers hexadecimal. Companion [hex writer706010](SYMBOLS_HTTP_EXTRA_DATA_AND_METHOD_LOOKUPS.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x706168](../recomp/config/output_ovl/o6/o6_00706168_0x706168.cpp) | `read_asn1_integer_hex_lines_with_optional_leading_zero_and_continuation` | Confirmed complete line, hex, buffer and publish flow; malformed/continuation semantics partial | Args(BIO,destinationString,scratch,scratchCapacity). Setsdestinationtype4=2 BEFOREreading. Getsline6F3D48,stripstrailingLF/CR,detectsrawlastbackslash,scansleadinghexprefixandNUL-terminatesthere. Firstline optional00 prefix skipped. Subtracts continuation flag from already-scannedhexlength,requires even count; accumulates pairs using0-9/a-f/A-F into growingheapbuffer. Growstolength+2*newBytes via70FF58/70FF80 witholdcapacity. Continuationreadsnextline; finalsuccessassignsnewpayload8/length0,returns1. Olddestinationpayloadnotreleasedhere. Allocationfailurefreesexistingtemporary; oddhex/invalidhex/lineerrors return0 withoutsamefreepath. No globalinput/size/linecap beyond caller scratchcapacity. |

The continuation flag is derived before the scan stops at the first non-hex character; the later subtraction is preserved literally. It is not replaced with an assumed equivalent hexadecimal grammar or a proven inverse of the writer. The nibble loop reads and shifts the current output byte twice, with the final stored byte determined by the two admitted hex digits. Runtime input admission, error-path allocations and continuation outcomes were not exercised.

Audit:221 verified instruction words, zero conflicts,3 omitted zero words (NOP padding), zero omitted nonzero words.
