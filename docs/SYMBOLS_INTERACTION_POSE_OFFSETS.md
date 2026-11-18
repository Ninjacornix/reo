# Interaction pose offset and dispatch data

Owned File #1 o2, base570000, SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Static decode, 2026-11-04. These are physical file-backed blocks consumed by [pose bank handlers](SYMBOLS_INTERACTION_POSE_BANKS.md), not independently mapped function bodies or proven authored table counts. XYZ values below are rounded decimal renderings of original little-endian float32; hashes preserve exact bytes. Vector indexing is 12 decimal bytes; actor B99 and descriptor indices are not locally bounded.

| Physical half-open span | XYZ triples in order | SHA256 |
| --- | --- | --- |
| 70B070..70B0A0 | (64.7, 0, 60); (-70.7, 0, 55); (70.7, 0, -55); (-64.7, 0, -60) | `f233777248200552c12ea2736ef8cc6b05d25e66ed118493cf7f8e6d3d65b9f2` |
| 70B0A0..70B0D0 | (50.7, 0, 60); (-50.7, 0, 60); (50.7, 0, -60); (-50.7, 0, -60) | `94478ee4cc1727f38c2c9d0d11f3c93ed2dcb70f52710e48a8f4be2fc8c8fb2b` |
| 70B0D0..70B130 | (42.7, 0, 93); (-42.7, 0, 93); (42.7, 0, -93); (-42.7, 0, -93); (42.7, 0, 93); (-42.7, 0, 93); (42.7, 0, -93); (-42.7, 0, -93) | `ec392c3eb6d09c8fa44648e02e7393a6c8384f0a3315b4668488e2376b429879` |
| 70B130..70B160 | (62, 0, 60); (-42.7, 0, 93); (52.7, 0, -93); (-42.7, 0, -93) | `1da2ae5e8e43d19a9688d089f96b841ed86e55413a88a57602dc1a7bd7bd36e0` |
| 70B160..70B190 | (72.7, 0, 93); (-42.7, 0, 93); (42.7, 0, -93); (-42.7, 0, -93) | `3070402542e1ae689b7956a41f1548acf557359bac6fbcaf484339261bc46753` |
| 70B1A0..70B200 | (0, 0, 109.467); (0, 0, 118.56); (0, 0, 0); (0, -50, 0); (0, -50, 0); (0, 0, 0); (-50, 0, 0); (-50, 0, 0) | `f460cf4b69735db01b1f02226deb74bf0032ebfde8279afe1306c91690770aed` |
| 70B200..70B260 | (0, 0, -50); (0, 0, -50); (0, 0, 0); (0, -40, 0); (0, 40, 0); (0, -50, 0); (0, 50, 0); (0, -100, 0) | `6b6a40668bfeaddf5f43db5183b52a472770f436cb40c399eae5247ed5843574` |
| 70B270..70B2D0 | (0, 0, -43.46); (0, 0, -43.46); (0, 0, 0); (0, -72.5, 0); (0, -72.5, 0); (0, -100, 0); (0, 0, -45); (0, -50, -45) | `d6f7b5232f3c9512a1c75074e06e8608872b5c6d317853d14ca6df33d19dcc3d` |

The16-byte gap70B260..70B26F is not interpreted as a pose vector table. Adjacencies above delimit reviewed physical blocks, rather than a claimed runtime bounds contract.

| Physical span | Exact decoded values / SHA256 |
| --- | --- |
| 73DF10..73DF2F | words hexadecimal: 580AF4,580B68,580BEC,580C94,580BEC,580C94,580D3C,580AF4; `2c77363ac51df62ecd37e3a68960a995d0cce2c6c0715459eec748a673427d16` |
| 70A750..70A757 | bytes hexadecimal: 7,8,14,17,1B,1C,7,2D; `2ab5f661d0e3f9bc473aadcdc3e814f9b567d73cd6681aec5a213096077bc710` |
| 70B190..70B19F | bytes hexadecimal: 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0; `bdc8351e1b616bd11a7dcf146623b721921745822b1974ceeaaae80018dd9617` |

70A750 is the eight-byte case prefix;580A10 reads it before selector<8, so this decode does not prove all out-of-range accesses invalid or valid.70B190 is a16-byte physical block; descriptor50 range admission remains unknown. The eight jump words agree with all selector cases reviewed in580A10. No dynamic table contents, observed incident or confirmed root cause is claimed.
