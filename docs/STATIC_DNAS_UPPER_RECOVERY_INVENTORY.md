# Upper DNAS copied-data recovery inventory

All **53 previously inventoried spans / 3,966 words** restore exactly using their actual opposite-mode metadata. **355 exception words** remain unchanged. **This inventory adds zero function mappings.**

Owned o4/runtime5/base6E0000, image SHA-256 `8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16`. Only Python integer values copied from this file were transformed. No recovered instructions were executed, loaded into the runtime or written to owned/generated inputs.

The49 keyed records were read directly from the complete owned lookup table. Four zero-key spans use the original zero-exception route. For every span, the entry/restore metadata names the same range, relative base and exception offsets; the clear restore setup loads the exact end anchor, actual mode/operands and original dispatcher. All actual restore schedules reverse their entry schedules. Listed exceptions are preserved on every pass. The original encoded payload digest is checked against the earlier boundary inventory.

Full connected-function review has already admitted [three bounded local operations](SYMBOLS_NETDNAS_THREE_ZERO_KEY_RECOVERED_LOCAL_ROLES.md) and [the two-bit query](SYMBOLS_NETDNAS_RECOVERED_TWO_BIT_FIELD_QUERY.md) as a fourth operation. Remaining candidates still require that same instruction, boundary, caller and data-flow review. A catalogue fragment inside recovered code does not become an independent function. Bytes in skipped metadata are not decoded here.

Reproduce with `python tools/function_index/recover_dnas_upper_inventory.py`. The JSON receipt at `build-function-index/dnas-upper-recovery-inventory.json` retains all candidate words, exception offsets, selectors and hashes. The [original protection inventory](SYMBOLS_NETDNAS_PROTECTED_DISPATCH.md) and [residual boundaries](SYMBOLS_NETDNAS_RESIDUAL_BOUNDARIES.md) preserve the source provenance. Static graph edges from encoded/generated source remain unvalidated.

| Span, end exclusive | Words | Preserved exceptions | Candidate SHA-256 |
| --- | ---: | ---: | --- |
| 0x746924..0x74697c | 22 | 6 | `6fe1a290be7a1f7141874285d33601a94cde949e37ed9eabc1a1d3ecfb87baf0` |
| 0x746a64..0x746abc | 22 | 6 | `6fe1a290be7a1f7141874285d33601a94cde949e37ed9eabc1a1d3ecfb87baf0` |
| 0x746b9c..0x746bd0 | 13 | 4 | `78c29b18d3b192f9062acf92144e106cbec23dca8745b551a81449993585b257` |
| 0x746cd8..0x74727c | 361 | 29 | `ba68a864914d167619f5e12c9dad05be85e95543af56bfb7ca8732099f5f0360` |
| 0x7473ac..0x747524 | 94 | 11 | `df7c376ab547ca6846a5c2319b7638e065b9a808ec8ebc2de420d7fbddf27987` |
| 0x747624..0x747660 | 15 | 2 | `b1af44a40c7b25dd0a2656f37519dd2b75b5c034094f933907bd7f6b3c3de49c` |
| 0x74773c..0x747778 | 15 | 2 | `eb1ed999382b394c7f02047d88c9ff88e8350c53eb33169f12c8461555747e38` |
| 0x74784c..0x747864 | 6 | 2 | `6ae4e4956392f31da9a398a267bb9a27f8c62f58b62c18d2dacea00425fa63cc` |
| 0x747934..0x747948 | 5 | 2 | `cbb7f21545746a4dee8e7952fe153417157466fb71d7ed600c7b265e0516d8e6` |
| 0x747a1c..0x747a30 | 5 | 2 | `cbb7f21545746a4dee8e7952fe153417157466fb71d7ed600c7b265e0516d8e6` |
| 0x747b04..0x747b1c | 6 | 2 | `e677d4f6903641b6dc08cacfc746559a7c6c588fa12896065e70c1cdaf5d5d6a` |
| 0x747bec..0x747c04 | 6 | 2 | `5dfbdfc6f37fdbdf4e2a689c80ecd58f18fa2ed19641df3fe8328c8d90527063` |
| 0x747d00..0x747d18 | 6 | 1 | `9bbe8e9183529835abcca04225d2a93be646e317822641c8be5acd40d9059cf1` |
| 0x747e30..0x747e44 | 5 | 1 | `a47d6019e880719464f569c2d252c720dd522090c9ffaee8513b080dada5ede8` |
| 0x747f30..0x747ffc | 51 | 2 | `7545c03485e2b684a981e7dffb84d975fc7d32be95d20ee7f4b44829f85ec91e` |
| 0x748100..0x7481cc | 51 | 2 | `4a4dc0ce0e98588e9d6d3e1dff26fc99ea1c7951559525e7015b263bd17bf423` |
| 0x7482d4..0x748474 | 104 | 6 | `f4183900a5f6fd3a21fc46d0a14f09a37edc296a9d84dfb3df08425b7025238c` |
| 0x748584..0x748694 | 68 | 10 | `55e3dee56d47d9cd8d90824611d90cdc1401730f531e7f4a6a25b362a807a3f7` |
| 0x748784..0x7487c0 | 15 | 2 | `50bac3f28e55e30d8fddaae6a0b1d6b46710f49d43e63cf6933aae4f20333dc6` |
| 0x7488b4..0x7489c4 | 68 | 10 | `05946d32296ee82fabf4ad65bf736b4f82d6368401dc18a855b7f390f2171866` |
| 0x748ac8..0x748b94 | 51 | 2 | `90155f4c39944d66ecb152fe6220cd68259d861683e4702b60d45816b8a27ec8` |
| 0x748c84..0x748cfc | 30 | 3 | `b8b46a5c45548b9aeee52c9346cd6b8dd41ad79a0e6029fc2f981580f4d3a535` |
| 0x748df4..0x748f04 | 68 | 10 | `a13316e47707f2705f44ce9690a308d433a561b72e41c5997c9cdeea2131e20c` |
| 0x74900c..0x749234 | 138 | 13 | `1696d39efc8325314be5b81c0765c95ac481f65a5706fad40c6510342b22f71f` |
| 0x74933c..0x74944c | 68 | 10 | `14b2f470010fcf2d55a57b1294277b2ee9e6dc00f2fbb56f0905e25fa75b5da1` |
| 0x749584..0x7495c8 | 17 | 0 | `e507066b82b2fdcae2e125652cd50fee53febe455dcd130cdb380c25b1544da9` |
| 0x7496b0..0x74973c | 35 | 0 | `1e3cc730042815eba63f666ec8d1b8dfbbc772cfed5cdcdee3cb51605baf292e` |
| 0x749830..0x7498e0 | 44 | 10 | `5faf8594727ea6888bcacc4d86734abecdd21095a7f6ec8753855ccf3f00bd90` |
| 0x7499dc..0x749b4c | 92 | 19 | `dc3c370f77e8195d12a5f5b839f373ee723f8363548c6d311e891cc29a6cf163` |
| 0x749c34..0x749c74 | 16 | 3 | `1d70d5dab1121357e76bd968e6fc8da039b807d34d2862e14c5f1c28b8ac4ad5` |
| 0x749d60..0x749e64 | 65 | 4 | `df69bccb3e56bbe74177e0dc82e8505a4fa923a66496754d6748c97fe0400792` |
| 0x74a424..0x74a81c | 254 | 29 | `ad84a940cd3837771c061c378ff6e33f9e9167052a7aea268a7b011f2b136fd9` |
| 0x74a924..0x74a99c | 30 | 7 | `8ad23dbbd1ccca131386bab53657be4a689f4329a3485284dd503c1f3063a4ce` |
| 0x74cee8..0x74cf08 | 8 | 1 | `cf4a82a21994b6c0d4e51f07dec431dcd895993c79733be22f455df3b659e6ef` |
| 0x74d010..0x74d1c4 | 109 | 4 | `8ede763ab6db7c2fe810a80cc55182f798f7008f5630a018aa3c065e6f714155` |
| 0x74d2fc..0x74d6cc | 244 | 10 | `0d0a20a424269c441cf70b9b71248e30a549af33025a7103301d550d6da58207` |
| 0x74d7d8..0x74d844 | 27 | 6 | `7bd0bf16defcd45096fc8ef5ddc7ff080233ba75666e24e6c10bedb3ba03ad31` |
| 0x74d93c..0x74dae4 | 106 | 4 | `d0622c829c7f7887ab611c27378d67f4ebb827a687bffd31aa95c43c5057111d` |
| 0x74dbe4..0x74dd4c | 90 | 4 | `7fdc92b79dbbc5a005de1e8941e1c95d2d2d8418924a2ca2e85bc0ec3ec4a696` |
| 0x74de68..0x74e0dc | 157 | 16 | `13d5e784ca9ad452635d9eb766fd1d03857d3a50d24bf1114fc4c20e1435e31c` |
| 0x74e22c..0x74e270 | 17 | 0 | `e507066b82b2fdcae2e125652cd50fee53febe455dcd130cdb380c25b1544da9` |
| 0x74e370..0x74e594 | 137 | 11 | `68d70dda4811d44893bb4603549afa2d00c4cf9d9d57a1b1139870e162d1c38e` |
| 0x74e68c..0x74e6bc | 12 | 4 | `fd00abef117f4d4f2cbc546342d35de1ef15f9baadcc9d84c47e622e2b7beea9` |
| 0x74e7a8..0x74e7c4 | 7 | 0 | `f74cfcb674d483ad4ca99b5a1be0dbdfeb79b96303f3bdfd8de4185ab2e57faf` |
| 0x74e8c8..0x74eb44 | 159 | 6 | `269069cfc68526966f7eccd48a606ac7dce7741f279d49d4fdc1fe256b5e823b` |
| 0x74ec5c..0x74ee64 | 130 | 10 | `d9cb0af075402e41026549b548ecd7d97aa5d23501eea5da081104c3a3489a92` |
| 0x74efd4..0x74f10c | 78 | 5 | `8e24c12db13dc2f563e77a3be07df0ef0d7fa486c2c4dc6e98d1c630800ed3a8` |
| 0x74f2b0..0x74f714 | 281 | 15 | `3c8d3d54c3b975a4392e74082fddb5bcc3d9857016d3ea5807ff0d0811d65e17` |
| 0x74f894..0x74f8f0 | 23 | 4 | `518ceeb37d515a30960c91cc3ba282e5388fb80dee6f687df4521593cd56d4be` |
| 0x74f9fc..0x74fcac | 172 | 9 | `e8c1016a434d6bf66ab64ea344197c7e876b6cc25f274bf65d87bff13ed5367c` |
| 0x74fdc4..0x74fe84 | 48 | 7 | `0fa2b0c49c82b51eadb14e9a8b55939296151d7c32591b324d319943a970c8e1` |
| 0x74ff94..0x750040 | 43 | 8 | `f30cc921b99f62f649d3e0cce63a1849c217ba13e6d02c640ce55d4ce63023c7` |
| 0x75015c..0x75059c | 272 | 17 | `95c6b5424ec0679db84c1ad23a9037135ad9f2d2a02e4818cebed7567819e794` |
