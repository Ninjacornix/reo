# HTTP overlay ASN1 UTC-time display adapter

Static owned o6 `nethttp.bin`, runtime ID 6/base `6E0000`, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Full original254-byte catalogue interval reviewed, including optional seconds, timezone, initial digit-loop test and BIO failure returns. Values are hexadecimal. No target execution or parser testing.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x72A928](../recomp/config/output_ovl/o6/o6_0072A928_0x72a928.cpp) | `display_asn1_two_digit_year_utc_time_with_optional_seconds_and_timezone_on_bio` | Confirmed complete formatting mechanics; malformed-input reachability untested | Args output BIO, ASN1 string with length0/data8. Declared length<A fails. Checks only first A bytes are decimal digits; last declared byte Z selects GMT form. Parses YY/MM/DD/hh/mm; requires month1..C, maps YY00..49 to2000..2049 and50..99 to1950..1999. Optional digit pair at positionsA/B supplies seconds; otherwise seconds=-1 until a non-Z offset path replaces it with0. Non-Z chooses offset positionC when seconds present orA when absent, reads sign and four digits without separate digit/range admission. Prints `%s %2d %02d:%02d:%02d %d GMT` with owned month name, day/time/year; for non-Z also prints `%c%02d:%02d`. Positive formatted BIO returns yield1, failures0. Invalid length/digits/month writes exactly E bytes `Bad time value` then returns0, ignoring write status. |

Owned month-pointer table `739880..7398B0`,30 bytes, SHA-256 `7182cdede376954e5c47b53c41f73dc911bbc0be55b032801ef627866df802ad`. Formatting strings are at `73F630` and `73F650`, error bytes at `73F660`; combined `73F630..73F670` SHA-256 `c63d5703d541b4e6be1f5fd87b2c3d43e0c189453b2c594631d90f3fc53e8ce4`.

The declared minimum length A does not cover the unconditional byte-A read, optional byte-B read, or non-Z offset suffix. Day/time ranges, timezone sign and suffix extent are not validated here. This is a display adapter, not a certificate acceptance decision; upstream ownership, input admission and malformed-input reachability remain separate questions.

Audit: 149 verified instruction words, zero conflicts, 0 omitted zero words, zero omitted nonzero words.
