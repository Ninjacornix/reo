# HTTP overlay SSL parent control dispatcher

Static owned o6 `nethttp.bin`, runtime ID6/base `6E0000`, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Entire original interval and all 36 jump-table words reviewed, including stores in branch delay slots and the external method fallback. No target execution or networking. Values are hexadecimal. [Parent lifetime](SYMBOLS_HTTP_SSL_PARENT_CONTEXT_AND_GLOBAL_POLICY.md) defines this 120-byte object; [session capacity enforcement](SYMBOLS_HTTP_SSL_CACHED_SESSION_LIFETIME.md) calls controls14/2B.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x71D468](../recomp/config/output_ovl/o6/o6_0071D468_0x71d468.cpp) | `dispatch_ssl_parent_cache_statistics_limits_options_and_method_controls` | Confirmed complete 36-way table and fallback | Args(parent,selector,value,subselector). Selectors14..37 use table73DDE0; table defaults and outside selectors invoke parent method0->34(parent,originalselector,value,subselector). Local getter/exchange/OR/limit behavior fully listed below; no generic pointer, concurrency, range or callback validation. Exchange returns old field, OR returns new field. Cache-control names are corroborated by insertion/eviction callers, while remaining counters stay field identities. |

| Selector | Local behavior |
| --- | --- |
| 14 | Return u64 parent1C hash count30; requires nonnull hash. |
| 15,16,17,18,19,1A,1B,1C,1D,1E,1F | Return signed parent word4C,54,50,58,60,5C,70,74,64,68,6C respectively. |
| 20 | OR supplied value into u64 options8, return new mask. |
| 28 /29 | Get /exchange signed wordA4. Exchange stores low32 value. |
| 2A /2B | Exchange /get u64 cache capacity20. Insertion treats positive capacity as bounded-cache mode. |
| 2C /2D | Exchange /get signed cache mode word30. |
| 2E | Subselector64 writes both u64 E8/F0;65 writesE8;66 writesF0; supported route returns1, other0. |
| 2F | Subselector65 getsE8,66 getsF0; zero field returns default19000. Other subselector0. |
| 32 /33 | Exchange /get signed word114. |
| 35 /36 | Exchange /get signed word118. |
| 37 | Get signed reference count78. |
| 21..27,30,31,34 and outside14..37 | Delegate method slot34 with original selector/value/subselector. |

Owned table `73DDE0..73DE70`, 36 words, SHA-256 `66a9b7c8788cbe47c67b585760da4d33b05447f7cb51661da9e9d08f81adfcbd`. Every destination lies inside the reviewed interval. Statistics getters report stored values only; no runtime counter sampling was performed. Neither parent controls nor the HTTP library were changed.

Audit: 111 verified instruction words, zero conflicts, 1 omitted zero words (NOP padding), zero omitted nonzero words.
