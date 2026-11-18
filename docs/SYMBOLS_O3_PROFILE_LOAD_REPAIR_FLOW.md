# File #1 o3 profile load, repair and retry controller

Static full-body review of owned `netwk.bin`, runtime ID 4/base 570000, SHA-256 `5d23ef8bf97c107421f4bcf8589cf8941f3305ae5f6715573ed68837b9511dfb`. Entire 5FC930..5FDDE4 original catalogue interval read in three nonoverlapping chunks, including entry tests, branch delay slots and shared return. Addresses, phase numbers and prompt codes below are hexadecimal; status values and delay counts are decimal. No target execution or storage operations.

Companions: [root container and recovery caller](SYMBOLS_O3_ROOT_PROFILE_MENU_CONTAINER.md), [storage adapters](SYMBOLS_O3_PROFILE_BANK_SERVICE_ADAPTERS.md), [resident card/profile requests and manifests](SYMBOLS_CARD_PROFILE_REQUESTS_AND_MANIFESTS.md), [queued card file API](SYMBOLS_LIBMC2_QUEUED_FILE_API.md), [slot write controller](SYMBOLS_O3_STORAGE_SLOT_WRITE_RECOVERY.md). The resident notes establish that 1C1260 can return pending, errors or positive listing counts; unhandled results here must not all be relabeled errors.

| Identity / source | Proposed role | Confidence | Evidence and contract |
| --- | --- | --- | --- |
| [o3 0x5FC930](../recomp/config/output_ovl/o3/o3_005FC930_0x5fc930.cpp) | `poll_profile_load_offer_write_or_repair_and_route_retry_prompts` | Confirmed static control/data mechanics; displayed policy and reachable provider statuses partial | Unsigned nested phase 6DF152 dispatches the cases below; default returns 0. State 0 initializes storage 5F6DA0, clears UI via 5F7C60, saves 1C5820(workspace+33F000) to halfword 6DF1CA, selection 15A=0, starts 607B40(workspace+31F000), then phase 2/timer 20. Phase 2 delays, stores 607B50 status in signed halfword 156: 0 or -251 ->3, -253 ->4 and 607B90(write), -255 ->A, -254 ->28, -252 ->14, -256 ->3C; other values stay pending. Phase 3 checks 607BF0 availability before offering load-dependent prompt 6C(status=0)/69(other), binary selector field4; availability 0 instead routes A. Choice +1 ->4/timer20 and 607B90; -1 ->32/timer20. State 4 polls write completion: 0 ->5/timer60, -254 ->28/timer20, -251/-255/-256 ->1E/timer20; other statuses stay. States5/6 display A/7, count down with accept allowed in last10 calls, then7 returns1. Full recovery transitions below; all other terminal negative states return -1. No independent hard deadline on provider polling. |

Recovery phases use the same signed timer 6DF154 and binary-result helper 5F6BE0. Positive/negative choices are literal helper results, not inferred button names. Enabling a two-choice prompt calls 5F7710(0,2) and usually sets 6DF179=1. Exit paths clear UI masks 80000/100000/200000; the last mask sometimes uses 5F7590 instead of side-effecting 5F7500. Original prompts and transitions remain distinct even when their return values agree.

| Phase / block | Prompt / status | Positive choice or success | Negative choice / retry |
| --- | --- | --- | --- |
| 9,5FD118 | 6C if saved status0 else69 | After decrement<=0 resets nested phase0 | No input test. |
| A/B/C,5FD168 | Saves156=-255, prompt6A plus field4 | +1 ->B, which returns-1 | -1 ->C/timer20; C displays6A then resets0 after delay. |
| 14/15/16,5FD298 | First availability check; if absent ->A; otherwise saves156=-252, prompt6B plus field4 | +1 ->15 ->-1 | -1 ->16/timer20; displays6B then resets0 after delay. |
| 1E/1F/20,5FD428 | Prompt91 if saved status0 else6D, plus field4 | +1 ->1F ->-1 | -1 ->20/timer20; same prompt then resets0 after delay. |
| 28/29/2A,5FD588 | Availability0 ->A; otherwise saves156=-254, prompt6E plus field4 | +1 ->29/timer20 and 607C20 repair; when timer starts at0, polls607B50:0 ->4/timer1 and sets channel1C9=slot15D before 607B90; -256 ->2D/timer60; others wait | -1 ->31/timer20;31 displays6E then enters33/timer20, choice=1/cursor0. |
| 2A,5FD79C | Prompt8C | Waits delay then accept5F6B70 to reset0 | No binary poll. This phase is admitted by dispatch, but 28 branches shown do not select it. |
| 2D/2E/2F,5FD7E8 | 2D delay then2E/timer20/cursor0;2E prompt90 plus field4 | +1 ->2F ->-1 | -1 clears UI and resets0 directly. |
| 32/33/34/35,5FD984 | 32 delay then33/timer20/choice1/cursor0;33 prompt7C plus field4 | +1 ->34/timer20;34 increments35 and falls through to return-1 on the same call when delay expires;35 returns-1 | -1 clears UI and resets0 directly, without loading a new delay. |
| 3C/3D/3E,5FDAF4 | Prompt79 plus field4 | +1 ->3D ->-1 | -1 ->3E/timer20; displays79 then resets0 after delay. |
| 46/47/48/49,5FDC18 | 46 delay then47/timer20/choice1/cursor0;47 prompt92 if saved status0 else8B plus field4 | +1 ->48 ->-1 | -1 ->49/timer20; same prompt then resets0 after delay. No local transition from ordinary polling selects46. |

Phase1 increments2, though normal phase0 directly selects2. Most delay gates accept a timer that starts0 or becomes<=0 after decrement; phase29 specifically decrements any nonzero timer and returns immediately, polling on the next call only after it starts0. Phase34's immediate fallthrough differs from the many transitions returning0 until the next call. States9,2A,46..49 are described as admitted entries without asserting their runtime reachability. Label does not establish an original name or a measured slowdown cause.

Audit: 1162 verified instruction words, zero conflicts, 163 omitted zero words (NOP padding), zero omitted nonzero words.
