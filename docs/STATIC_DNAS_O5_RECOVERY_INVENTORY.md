# O5 DNAS copied-data recovery inventory

**73 spans / 5,596 words / 460 preserved exception words.** All 73 clear entry setups bind their descriptor and start anchor; 50 adjacent canonical clear restore setups bind the paired end anchor. Every metadata-paired schedule restores the exact original bytes. **This inventory admits zero function mappings.**

Owned o5 (`insdnas.bin`, runtime overlay 7), base `6E0000`, SHA-256 `97174f5d367cd90bedd5ba397c6492e9fb4bbd0ec7d6021c2be524c49925d38e`. No target instructions, game, build, replay, network operation or process attachment ran. Original and generated inputs remain unchanged.

All 18/19/30 keyed records of the three tables are accounted for, plus six zero-key spans. The entry direction selects the inverse word table, while the paired restore selects the forward table. Selectors are read independently from both descriptors; exception membership uses `relative_base + 4 * word_index`, modulo 32 bits. Unsigned offset lists are not sorted or reinterpreted.

Reproduce with `python tools/function_index/recover_dnas_o5_family_inventory.py`. The private JSON receipt `build-function-index/dnas-o5-family-recovery-inventory.json` retains every original/candidate hash, candidate word, descriptor, schedule, key and exception list. Noncanonical restore bindings stay pending until complete connected paths are reviewed. Nested spans and generated catalogue cuts remain parts of their logical owners.

| Span, end exclusive | Dispatcher | Words | Exceptions | Canonical clear restore | Candidate SHA-256 |
| --- | --- | ---: | ---: | --- | --- |
| `6E0794..6E07CC` | `0x6e2828` | 14 | 3 | Pending individual binding | `2765a382ce91733c758df6fdafd0d02f2fe05e14a95e92f80026fac37891d5eb` |
| `6E0918..6E09E0` | `0x6e2828` | 50 | 7 | Pending individual binding | `272649b7cc511c9e74edaa523cac8710ade93b2fab9741bad838bc3e4d7d308f` |
| `6E0AAC..6E0AEC` | `0x6e2828` | 16 | 3 | Pending individual binding | `535e4530fad30aecfd734a5c97253b1d8a53962c26444895b3f86fe581153ea1` |
| `6E0C1C..6E0C5C` | `0x6e2828` | 16 | 3 | Pending individual binding | `323a528eef8573f74d7d305c224f29aaa5b3569c8258c545777850816b5e573f` |
| `6E0D30..6E0D6C` | `0x6e2828` | 15 | 3 | Pending individual binding | `5f656045b4c2f8172f89241838bf68de05c8d022f8be29218278c58da1299efd` |
| `6E0E40..6E0E7C` | `0x6e2828` | 15 | 3 | Pending individual binding | `c7516affd24a5ec4282e9bff39c1c7b7433480a3dbe56bce0a1c551763e7475c` |
| `6E0FC8..6E1170` | `0x6e2828` | 106 | 21 | Pending individual binding | `22b4192911b9ab075905a9e027608bd7f5372edd96fd9e4741537469bcb02d88` |
| `6E1230..6E126C` | `0x6e2828` | 15 | 3 | Pending individual binding | `9a0eaf223240bdf6900ed020922c30926762ea9d483bd51ddc14b86c5fc91dec` |
| `6E1314..6E1354` | `0x6e2828` | 16 | 3 | Pending individual binding | `5898ea44ce3a02eeb68737013827ca73e164f141d79a6dab2fe594b91c432db2` |
| `6E1400..6E1444` | `0x6e2828` | 17 | 3 | Pending individual binding | `1a39e78f5f72000c454269ba5732bb7e8c0d774e4d46dc12ea4a09cc3d4544ec` |
| `6E1728..6E1764` | `0x6e2828` | 15 | 3 | Pending individual binding | `040795d4161406818e28e2d64302487ad5b8cfa19600ec68e8ed4a5a12eacc17` |
| `6E1848..6E188C` | `0x6e2828` | 17 | 3 | Pending individual binding | `80420116fe5ca3affbd93f5ed7ee53120c3abb26f595073cc6ce92d9eb0d0d3b` |
| `6E1954..6E1994` | `0x6e2828` | 16 | 3 | Pending individual binding | `28c3ce7b87943ae463d4f978a098e0901b78b4bb860b042b8d84023059f3f5d6` |
| `6E1F50..6E2070` | `0x6e2828` | 72 | 19 | Pending individual binding | `ce4f65ee7df3884af3e7d66ab97854731ad8d39cc282fe6bfbcb29793413e90f` |
| `6E2168..6E219C` | `0x6e2828` | 13 | 3 | Pending individual binding | `ac8ed4faf28985fd1594480896c0d26f86d94ae16f34e2b407d826ee42b47115` |
| `6E2280..6E2354` | `0x6e2828` | 53 | 15 | Pending individual binding | `c5faeb0608b3663d6148e72fff88fc0e324601a0a2c6699302b46a14d986d448` |
| `6E2430..6E25B8` | `0x6e2828` | 98 | 24 | Pending individual binding | `8721850c11f83480fd62699ee05ba62bb2959d62b138e2b241cbdcfaa8b2863c` |
| `6E26D8..6E270C` | `0x6e2828` | 13 | 3 | Pending individual binding | `e85b930849f6a687f22b31a7c8f9d156ec54ff807ddd71226643e10d93e3f5f7` |
| `6FA60C..6FA6EC` | `0x708e18` | 56 | 4 | Verified | `c68b05856048cd47a7cf81d0c3135c45a3757cd5634f24562b9b456c5015249b` |
| `6FA79C..6FA89C` | `0x708e18` | 64 | 4 | Verified | `0b472e2ecc5eed4d6eb0502619328788f35f04ab241f9724ac5ce42cb06a8103` |
| `6FA94C..6FAC44` | `0x708e18` | 190 | 10 | Pending individual binding | `c4cb3abb61db831f4fda3f998bb1c7a5bd24f8a3d1de2919462b0906bd4edffe` |
| `6FACF8..6FAE08` | `0x708e18` | 68 | 5 | Verified | `bf01c46427a5d1e91dcc6f6596e0af9f72f0a66ff448f44c067985e1967efbc5` |
| `6FAF78..6FB080` | `0x708e18` | 66 | 5 | Verified | `3a4a2bc8eb80780732ef2af57788aab91e6c59e226504850c3c404f68c92100c` |
| `6FB130..6FB240` | `0x708e18` | 68 | 5 | Verified | `432de0678bf500a39dd8600a4120063b89e933c201bdf7a7c5eeffefb10cb45b` |
| `6FB2F0..6FB414` | `0x708e18` | 73 | 5 | Verified | `ff6623a2deb99f2239aa3abcb97b99d302e8558d04e64f98746b4fb87d68436e` |
| `6FB4C4..6FB75C` | `0x708e18` | 166 | 9 | Verified | `f39b90f2a66cd17afeb0b64c7d63321238032bb4db366d8e9f190165d5ca1e40` |
| `6FB80C..6FB86C` | `0x708e18` | 24 | 0 | Verified | `1847b1d1f34c2bd5914cae7454c2e3921465c0d744e1618b82914e8531ac7038` |
| `6FB91C..6FBCB4` | `0x708e18` | 230 | 15 | Verified | `484b194e456261c50329e6049ad06a541f6f2320127b98611fb6f95fb88ff5e0` |
| `6FBD64..6FBE30` | `0x708e18` | 51 | 5 | Verified | `0bc31a0f78730c6e3e3246f10d856e32f4e4aa5d9b37d01b2047270d40aa480c` |
| `6FBEE0..6FC02C` | `0x708e18` | 83 | 6 | Verified | `54dbab4e88e9970658d5b57e793e4c8bbf54f4ac1acae49961928a42c00b290d` |
| `6FC0DC..6FC220` | `0x708e18` | 81 | 3 | Verified | `100a71dd36e9eae35691a949cc12aa362029720a91716ea38cb40fab58e63742` |
| `6FC2D0..6FC308` | `0x708e18` | 14 | 0 | Verified | `4579c09a5d115b81232bcba3be2160f4f77cb59ff94242555fa3d2d49831d3a0` |
| `6FC3B8..6FC44C` | `0x708e18` | 37 | 2 | Verified | `9171ea38ad2fd0c6dcd8b63f881bbe0dc494e1c69a602aa410585e9c88dafac8` |
| `6FC4FC..6FC530` | `0x708e18` | 13 | 3 | Pending individual binding | `ef8712444253212f6e76fc520b58918a8c184d6bd977b418f9b707813ad4e49c` |
| `6FC5FC..6FCD88` | `0x708e18` | 483 | 19 | Verified | `58e14a651a3e5421a433d13b11127be09a2a3051447fdbcf8331b82c06562efa` |
| `6FD344..6FD488` | `0x708e18` | 81 | 7 | Pending individual binding | `1f90f5d7901f811c1a3d1efd49bbc5730a63b427bf32e55238ee02e3fa80f7d0` |
| `6FD5B4..6FD810` | `0x708e18` | 151 | 6 | Pending individual binding | `5265f3552cba662aa95e591b17ce966dc1f3d3995909bbd8585db3b9965b7668` |
| `6FD988..6FD9E4` | `0x708e18` | 23 | 0 | Pending individual binding | `ccdb3d03558fc39a0ebd5d5bffcc5f517c660adad1ffc70505aa239a47307f9f` |
| `6FDA90..6FDB8C` | `0x708e18` | 63 | 2 | Verified | `d5b9f01967a25bd41d4b6a83efd695942be0e7b5fbe103ed9ac565e80e07f1ca` |
| `6FDCD8..6FDD0C` | `0x708e18` | 13 | 4 | Verified | `5ebed8d0836d0a43e2d8214d5ea9b060429f9fed17dcf3a5939eb75da402d439` |
| `6FDDC8..6FDF54` | `0x708e18` | 99 | 1 | Verified | `f30be50517466a9fa4bac155824fb2fdf6ce81c772c47c7b2d78f14d93699711` |
| `6FE004..6FE12C` | `0x708e18` | 74 | 5 | Verified | `5930ce285ea2259fb59c90485bde2e57e4cfcfb815df7f5f9f43838a8a549db0` |
| `6FE1DC..6FE564` | `0x708e18` | 226 | 8 | Verified | `6d5560d2335e40f5807f736ad8a9dda0dbc3e738ffb692b01bf8b48abf6a1d45` |
| `6FE614..6FE704` | `0x708e18` | 60 | 5 | Verified | `fa476f99663a82b642809da00b66b9de9365d3eb78dfda8cb8d529d1836d870a` |
| `6FE7B4..6FE9C8` | `0x708e18` | 133 | 10 | Verified | `a7eac2a89383fc51ce0a61a97b1888c732574c726f08140edcfd67ba8a995a13` |
| `6FEA78..6FEAC8` | `0x708e18` | 20 | 0 | Verified | `98bff2ab77367d0327cded184718ca949f0236595e05d969defd2fc10ac7577f` |
| `6FEB78..6FED84` | `0x708e18` | 131 | 7 | Verified | `609b7dbb0da0c3759490990dbdb94aaf1e244bcc3055add56516cb201a139b1a` |
| `6FEE34..6FF150` | `0x708e18` | 199 | 6 | Verified | `4afaf2f15f0968108e872efcd3ccf8f543ab4f8414492b8b6b0714a13610ddf6` |
| `6FF318..6FF508` | `0x708e18` | 124 | 10 | Verified | `72559350b9216e04026dedb30bb2b21cf90e735947c485a31ae5732389b8560d` |
| `6FF76C..6FF868` | `0x708e18` | 63 | 2 | Verified | `b671242268448d6b41820cc4d51028b36ad1b6f24ec89f5d3312e60a286dfac0` |
| `6FFF80..6FFFA4` | `0x708e18` | 9 | 3 | Verified | `3d0b239899e7b3135432f07d538ae7e25e470a0aeeebf49eaf2a5c2fe5055f1d` |
| `700424..700454` | `0x708e18` | 12 | 3 | Verified | `7ff301da2485699a5aaa14b38ea69fcfab8c3178294662a68d0eadf292b1397f` |
| `701C90..701CA8` | `0x700b18` | 6 | 1 | Verified | `034d8117fc8de8c4408f3a0646e6ef713d64c412b9a313a9c82a5883e95ce007` |
| `701DA0..701E6C` | `0x700b18` | 51 | 2 | Verified | `d57189279c0b316a9692b65ba6e250841e5d27267592559ef3e0af4e51a44dee` |
| `701F70..70203C` | `0x700b18` | 51 | 2 | Verified | `36b16a63bff31452a7b633fc37a965591c814e5f09446de45e66e7c813648faa` |
| `702144..7022CC` | `0x700b18` | 98 | 4 | Verified | `c27f479f1f1ee76ebbe4a43f86454ea0695a59c56ed156d5099c603fe431db91` |
| `7023F0..7024F4` | `0x700b18` | 65 | 7 | Verified | `b163ab2ea1633ac54faae12974d83e56414f2a4884554e5edafe44b8b298ebe7` |
| `7025EC..702630` | `0x700b18` | 17 | 5 | Verified | `3a96f3667a342e15042dcc1b2ee0b27f30c6b846c2fa546d3d684c67cce99dfb` |
| `70270C..702740` | `0x700b18` | 13 | 4 | Verified | `9d6e5aaf28ef6d028fe47c5431b464202da53ba82629dd158e38626da7f126d9` |
| `7028C4..702E60` | `0x700b18` | 359 | 14 | Verified | `315deeac46ca395f472cc685afcb29d57584341c6e34638499f3d4eb571831ee` |
| `702F74..702FB8` | `0x700b18` | 17 | 0 | Verified | `e507066b82b2fdcae2e125652cd50fee53febe455dcd130cdb380c25b1544da9` |
| `7030A0..70312C` | `0x700b18` | 35 | 0 | Verified | `1e3cc730042815eba63f666ec8d1b8dfbbc772cfed5cdcdee3cb51605baf292e` |
| `703220..7032D0` | `0x700b18` | 44 | 10 | Verified | `df982d625ad84361ae72dc5e16b802a909e82426a834144db613f6ee78136f0c` |
| `7033CC..70353C` | `0x700b18` | 92 | 19 | Verified | `a0794adcb3e8a83acfb7a6e848f0f3384b06beb497a8133ae113fb3b8f184b2c` |
| `703624..703664` | `0x700b18` | 16 | 3 | Verified | `20446055b53680f537c4afce47be71b46d734b5e5ff2a747299b48d9de5611a6` |
| `703750..703854` | `0x700b18` | 65 | 4 | Verified | `f53fc396d3e77ffe85de40e3d9b95af5738c9db3f7520d6da6046ad9e33edf95` |
| `703E14..70420C` | `0x700b18` | 254 | 29 | Verified | `e9f800bad9f4ca475de05ad59294fc2e4b7629c350338d3401e7a33646867901` |
| `704314..70438C` | `0x700b18` | 30 | 7 | Verified | `f822ef465ccd7d59216ab00e858bf57940a5ed371b7972a630aa16a442742a51` |
| `7078CC..707928` | `0x700b18` | 23 | 4 | Verified | `518ceeb37d515a30960c91cc3ba282e5388fb80dee6f687df4521593cd56d4be` |
| `707A34..707CE4` | `0x700b18` | 172 | 9 | Verified | `dafb3eaf601905750257c10f38c1d55f5f65db63bd683825e2dbda68ef53a951` |
| `707DFC..707EBC` | `0x700b18` | 48 | 7 | Verified | `57f4b4f02033aeaaa1e95114afa770df39ef412d2d57a0bf26bef5726ac34313` |
| `707FCC..708078` | `0x700b18` | 43 | 8 | Verified | `532e0bed9eff02e18e943ae2c7b18bdf3397e566358a9a9aec24d0d6d712dd7a` |
| `708194..7085D4` | `0x700b18` | 272 | 17 | Verified | `db767eebb23b9d3adb28d1b004bdf82500e301eef2ad624f131f9b4b2e5eca99` |
