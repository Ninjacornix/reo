# HTTP overlay X509 name slash display

Static owned o6 `nethttp.bin`, runtime ID 6/base `6E0000`, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Full original3C4-byte catalogue interval reviewed, including both initial count tests, UniversalString byte-lane masks, output sizing and ownership transfer. Values are hexadecimal. No target execution or malformed-input tests.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x72D8B8](../recomp/config/output_ovl/o6/o6_0072D8B8_0x72d8b8.cpp) | `format_x509_name_as_slash_attribute_values_with_hex_escapes_and_optional_allocated_output` | Confirmed complete sizing/byte filtering/ownership flow | Args name,optional output,capacity. Null name returns owned `NO X509_NAME`. Null output creates growable wrapper6FB3E0, growsC8 and clears first byte; otherwise uses caller storage with capacity-1. Loops positive name4 array count: resolves entry4 OID ID/name through709248/7090D0, fallback numeric OID text6EF1C0 into local50-byte buffer. Reads ASN1 value descriptor8 length/type/data. Emits `/label=value`, copying printable20..7E bytes literally and nonprintables as four ASCII bytes `\xHH`. For type1B and length multiple4, if all bytes in lanes0/1/2 are zero, suppresses those lanes, keeping lane3; otherwise all lanes retained. Measures full entry before writing; caller buffer insufficient stops before that entry and returns original output. Dynamic output grows per entry; success frees wrapper alone and returns detached data; failure logsB/E6/21 and frees wrapper+data. |

Each completed entry appends NUL. Caller-buffer path does not preinitialize output, so an empty name or failure to fit the first entry returns unchanged bytes. Printable slash/equal/backslash are not escaped; this display does not provide unambiguous round-trip parsing or canonical name equality. Capacity/count/length arithmetic uses signed32 operations without local overflow admission. The byte-lane suppression is a display rule, not a general Unicode conversion.

Owned null-name string73F830 including NUL, SHA-256 `888832edaeb53369efd4e0ed217b99ed9245e42eda1811abf2d52579cc28fe37`. Uppercase hex alphabet7398C0 = `0123456789ABCDEF`, including NUL SHA-256 `15035c2b8a71a2cf05f146d7e149a0d0399298833e1394702fbaf2aaa822c08e`.

Audit: 240 verified instruction words, zero conflicts, 1 omitted zero word (NOP padding), zero omitted nonzero words.
