# Network DNAS: version-three client method derivation

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. No game, build, replay, attachment, network request or live-memory read occurred.

Two complete clear bodies were independently read. The [base version-three method](SYMBOLS_NETDNAS_VERSION_THREE_METHOD.md) and all23 initial words at765798 were already owned-word reviewed; these entries copy the complete5Chex-byte method and override two callbacks. The handshake implementation7208C8 remains a separate review boundary. Original names, runtime initialization/thread safety and successful client protocol are unknown; no timing or gameplay slowdown attribution.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x720740](../recomp/config/output_ovl/o4/o4_00720740_0x720740.cpp) | `select_version_three_client_method_only_for_version_0300` | Confirmed literal selector/call flow | Input300hex calls720770 and returns method; every other inputNULL. No fallback to version301 or negotiation here. |
| [o4 0x720770](../recomp/config/output_ovl/o4/o4_00720770_0x720770.cpp) | `lazily_copy_version_three_method_and_install_client_handshake_and_selector` | Confirmed complete method-copy/override flow; handshake semantics partial | Initial flag765808=1 ownedword; when nonzero clears it before71C0F0. Copies5Chex bytes base765798 to global7F1F38 in aligned/unaligned arms: two32-byte iterations plus28-byte tail. Overrides slot14=7208C8 client handshake candidate,slot4C=720740 selector. Returns7F1F38, or existing copy when flag0. No synchronization or child-handshake proof, and current runtime contents unknown. |

Owned765808..76580C bytes `01 00 00 00` read directly. No new function/table ownership is inferred from the destination global address. Base initializer and cache remain separate from gameplay update clocks.
