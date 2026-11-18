# Network DNAS: default backend callback installation

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. No game, build, replay, attachment, network request or live-memory read occurred.

Three complete clear bodies were independently read and all55 literal registration pairs checked against owned instruction words. This connects the independently reviewed [backend callback registry](SYMBOLS_NETDNAS_BACKEND_CALLBACKS.md), [certificate bridges](SYMBOLS_NETDNAS_CERTIFICATE_BACKEND_BRIDGES.md) and [certificate lookup](SYMBOLS_NETDNAS_CERTIFICATE_LOOKUP_FILES.md). Initializer success does not prove every callback was admitted: return values from individual registrations are discarded. Proposed labels are not original symbols, and current runtime slots are unknown. No timing or gameplay slowdown finding follows.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x6FBFB8](../recomp/config/output_ovl/o4/o4_006FBFB8_0x6fbfb8.cpp) | `clear_backend_enable_words_and_callback_region` | Confirmed static address/byte span | Tail107C68(7F1AB8,0,E8hex) clears two enable words plus callbackregion through7F1BA0 exclusive. Does not release callback-owned objects or preserve prior registrations; no runtime mutation performed. |
| [o4 0x6FBFD0](../recomp/config/output_ovl/o4/o4_006FBFD0_0x6fbfd0.cpp) | `set_one_of_two_backend_enable_words_by_selector_zero_or_one` | Confirmed literal selector/store flow | Selector0 writes7F1AB8,selector1 writes7F1ABC,returns1; allotherselectors0 withoutstore. No Boolean normalization of incomingvalue or callback invocation. |
| [o4 0x6FBC10](../recomp/config/output_ovl/o4/o4_006FBC10_0x6fbc10.cpp) | `install_default_certificate_and_key_backend_callbacks_after_region_clear` | Confirmed complete immediate/call sequence; admission completeness partial | Calls6FBFB8 clear,6FBFD0(0,1)/(1,1),then55 calls6FC000(selector,callback) listedbelow. Discards everyresult,returns1unconditionally. Literal selector38hex=56 requests72C838 but setter rejects56; slot-registration completeness and runtimeuse therefore not implied byreturn1. No automatic registration of each supported selector is inferred. |

## Complete immediate registration requests

Each row is a constant pair from the clear16-byte LUI/ADDIU/JAL/ADDIU pattern at6FBC38..6FBFA8. These are instruction-immediate evidence, not an additional function mapping or independent implementation of the requested callback. Identifiers are hexadecimal; source-owned callback availability and behavior retain the existing notebooks' limits.

| Selector | Callback | Literal pair instruction address |
| --- | --- | --- |
| `1` | `732080` | `6FBC38` |
| `2` | `732138` | `6FBC48` |
| `3` | `72D4D0` | `6FBC58` |
| `4` | `72D5C8` | `6FBC68` |
| `5` | `731D80` | `6FBC78` |
| `6` | `731E60` | `6FBC88` |
| `7` | `732118` | `6FBC98` |
| `8` | `72C878` | `6FBCA8` |
| `9` | `72C518` | `6FBCB8` |
| `A` | `72C540` | `6FBCC8` |
| `B` | `72C550` | `6FBCD8` |
| `C` | `72C800` | `6FBCE8` |
| `D` | `6FB848` | `6FBCF8` |
| `E` | `6FB9B8` | `6FBD08` |
| `F` | `6FBA20` | `6FBD18` |
| `10` | `6F08D8` | `6FBD28` |
| `11` | `6F0970` | `6FBD38` |
| `12` | `72D568` | `6FBD48` |
| `13` | `72C6B0` | `6FBD58` |
| `15` | `72C570` | `6FBD68` |
| `16` | `6F0620` | `6FBD78` |
| `1F` | `6F03D8` | `6FBD88` |
| `17` | `6FBA88` | `6FBD98` |
| `18` | `72E680` | `6FBDA8` |
| `19` | `72E798` | `6FBDB8` |
| `1A` | `6FBB08` | `6FBDC8` |
| `1B` | `72CD70` | `6FBDD8` |
| `1D` | `6FB8B0` | `6FBDE8` |
| `1E` | `6FB8E0` | `6FBDF8` |
| `20` | `72D340` | `6FBE08` |
| `21` | `70AB80` | `6FBE18` |
| `22` | `72D508` | `6FBE28` |
| `23` | `72CAC0` | `6FBE38` |
| `24` | `72CBA8` | `6FBE48` |
| `25` | `72D798` | `6FBE58` |
| `26` | `72D708` | `6FBE68` |
| `27` | `6FBB70` | `6FBE78` |
| `28` | `72D1A8` | `6FBE88` |
| `29` | `72D1F8` | `6FBE98` |
| `2A` | `72D278` | `6FBEA8` |
| `2B` | `72D2B0` | `6FBEB8` |
| `2C` | `72D0D0` | `6FBEC8` |
| `2D` | `72D120` | `6FBED8` |
| `2E` | `72D168` | `6FBEE8` |
| `2F` | `72D188` | `6FBEF8` |
| `30` | `72D320` | `6FBF08` |
| `31` | `72D328` | `6FBF18` |
| `32` | `72D330` | `6FBF28` |
| `3B` | `72D338` | `6FBF38` |
| `33` | `6FEBF8` | `6FBF48` |
| `34` | `729438` | `6FBF58` |
| `35` | `7294A0` | `6FBF68` |
| `36` | `6FBB80` | `6FBF78` |
| `37` | `729458` | `6FBF88` |
| `38` | `72C838` | `6FBF98` |

No built callback array was generated or installed. Selector38hex rejection is a static mismatch between this caller and the separately reviewed switch, not a reproduced initialization failure or a proposed engine fix.
