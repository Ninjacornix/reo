# Interface-provider and Ethernet connection controllers

Static File #1 US research, 2026-11-04. Two complete original main-ELF catalogue intervals, including every failure/retry branch, and the complete ten-target provider-status table. Identity in the [central index](FUNCTION_INDEX.md). No connection, game, timeout, device service or native replacement was run.

The [three-way connection router](SYMBOLS_NETWORK_GAME_RESOLVER_CACHE_AND_CONNECTION_ROUTER.md) passes eight state pointers. For readability: M=*a0 is controller mode, P=*a1 phase, S=*a2 subphase, T=*a3 signed16 timer, R=*t0 signed16 guard counter, A=*t1 and B=*t2 signed16 budgets, E=*t3 signed error byte. Hexadecimal phase/status/error codes below; decimal durations are explicitly call counts. Progress bytes33C6EC/ED/EE are target/current/ceiling, advanced separately from transport work.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1C9950](../recomp/config/output/sub_001C9950_0x1c9950.cpp) | `advance_interface_provider_connection_configuration_status_and_bounded_retry_controller` | Confirmed complete phase/branch mechanics; provider enum partial | Preflights1C96B0; failure E=-51,M=2 and clears P/S/T/R/A/B. Advances displayed progress by at most1, dispatches P0..7,A,63,64. Builds nested interface settings, initializes TCP/provider, submits configuration, polls normalized interface status through ten-target table, handles gate/option/budget retries via staged disconnect, initializes resolver and completes only once displayed progress reaches100. Ordinary0, complete2,restart-after-disconnect5. Full phase and error contracts below. |
| [0x1CA3F0](../recomp/config/output/sub_001CA3F0_0x1ca3f0.cpp) | `advance_ethernet_static_or_dynamic_address_connection_and_retry_controller` | Confirmed complete phases and child status gates; link enum partial | Same preflight/error clearing/progress mechanics. Initializes TCP then Ethernet link1D72C0, selects static or dynamic address path from33CC48, polls link/configuration, initializes resolver/name service, requires nonzero final link indicator1D7400, then waits for displayed progress100. Retry63/64 delegates staged disconnect with retained attempt budget. Ordinary0,complete2,restart5; no native process or renderer action. |

Common failure records E, switches M=2 and clears seven remaining phase/counter slots P/S/T/R/A/B. The preflight1C96B0 dereferences configuration33D158 before P0's later explicit null check; the later check is not a general protection for that earlier child. Progress is UI state, not an observed connection percentage or amount of completed network work.

## Interface-provider phases

| P | Complete original effect |
| --- | --- |
| 0 | Requires configuration pointer or writes E=-51. Sets ceiling10/current0/target0, S/T/R=0,A=3,B=2. Configuration mode1/submode0 or1 switches M=1 for the Ethernet controller. Mode1/submode2 or other configuration modes selects P=A. Unknown submode leaves current stage. |
| A |1D6EB0 publishes two pointers to owned empty string2369A0; builds nested settings bank33D9B0/33D9D0 with pointers to option records33D9A0/998/9E0 and three string banks33CB50/C930/C830, fixed selectors0/1/4, saved option bytes and default empty252E28 when needed. Clears16-byte selector record33D9E0 and seeds its first half from33C818. Selects P1. No borrowed strings are deep-copied. |
| 1 | Decrements positive old T and waits; otherwise T=0, target2,1D68B0(config0,config4). Negative common E=-52; success P2. |
| 2 | Target2,1D6DD0 provider init; negative E=-52. Supplies wordA to1D6E00, advances P3,T0 regardless that setter's return. |
| 3 | Target6. Configuration modes2/3 first1D6ED0 into config10; negative E=-51. Calls1D6F10(settings33D9D0),negative E=-52. Clears20-byte interface snapshot33B670, advances P5,T59 decimal. |
| 4 | R>=31 decimal ->E=-56. Otherwise advances P5,T29 decimal. R is not incremented inside this function; its producer contract remains separate. |
| 5 | R>=31 ->E=-56. Each T divisible by30 raises target toward ceiling by at most1. Decrements positive old T and waits. At T<=0, queries1D7050 snapshot33B670; negative E=-52. Dispatches normalized state half33B67C via table252E30; details below. Resets T29 after a completed status branch, including its late error paths. |
| 6 | Target/ceiling100 decimal; advances P7, commits option gate1C97D0, initializes resolver1C9530, publishes phase3/clears failure1D7000, copies snapshot word0 into33C810. Returns0. These side effects do not prove backend readiness independently. |
| 7 | Only displayed current33C6ED==100 returns2 and clears M/P/T/R/A/B. S is not explicitly cleared in this success arm. Otherwise0. |
| 63 | Advances64, clears S/T, returns0. |
| 64 |1CB180(&S,&T) staged disconnect. Pending0. Complete resets target0/ceiling10, selects P1,S0,T90,R0, retains A/B budgets and returns5. |

Provider status half33B67C:1 sets ceiling12/current minimum11;2 ceiling60/current minimum12;3 ceiling70/current minimum60;4 ceiling80/current minimum70 and advances P6. Each comparison is a static integer operation, not an assertion about real completion fractions. States0 and5..9 use reason half33B680; out-of-range/negative status uses E=-52.

| Provider reason | Retry/error branch |
| --- | --- |
| 2 |1C9770 gate success selects retry63; failure E=-3. |
| C | Decrements signed16 B; exactly0 ->E=-2, any other result retries63. A negative budget is not rejected by this equality test. |
| 1 | Same decrement/equality behavior for A; zero E=-52, otherwise63. |
| 5 |1C97F0 option cycle result0 retries63; nonzero E=-52. |
| 3 /6 /D | E=-5 /-55 /-2 respectively. |
| Other | E=-52. |

Owned ten-target table252E30: `1CA090,1C9FD0,1CA000,1CA02C,1CA058,1CA090,1CA090,1CA090,1CA090,1CA090`;40-byte SHA-256 `56d01600ebc8a27e82df69220b65fd2d9ce16c6aed77262f30c18821dc16721d`. Every target and the bounds/default were checked. Owned2369A0 and252E28 both begin with NUL; no credential contents were inspected.

## Ethernet phases

| P | Complete original effect |
| --- | --- |
| 0 | Advances1, clears S/T/R/A/B, ordinary0. |
| 1 | Waits positive old T, then clears T, ceiling10/target0 and advances2. |
| 2 | Target2; TCP init1D68B0(config0,config4), negative E=-52; otherwise3. |
| 3 | Target6; Ethernet link init1D72C0, negative E=-52. Submode33CC48==0 selectsA;==1 selects14; other submodes do not advance. |
| A | Ceiling20/current minimum10, builds address pair33B660 from33C810/808,1D72F0; negative E=-52,otherwiseB. The child's literal all-ones third-word formula remains its documented contract. |
| B | Starts Ethernet1D7330(byte33C820); negative E=-52,otherwise C,T0. |
| C | R>=31 ->E=-56. Every T divisible by30 raises progress target toward ceiling; increments T, calls1D7360. ANY nonzero result advancesD,T150,A0 and sets ceiling70/current minimum20. Zero result waits until T>=451; then A>=3 errors E=-52, otherwise retry63 and increments A. |
| D | Same R>=31 guard/progress cadence, counts T down using old-value gate. On expiry ceiling100/current minimum70, resolver1C9530,1D74B0(0,33C800); negative E=-52,otherwise1E. |
| 14 | Ceiling20/current minimum11,1D7330(byte33C820), negative E=-52; success15,T0. |
| 15 | Same R guard/progress/T increment/link1D7360 as C. Any nonzero advances16,T0,ceiling60/current minimum20. Zero with T>=451 uses A>=3 failure or increments A/retry63. Negative indicator is nonzero and follows readiness arm literally. |
| 16 |1D7540 then1D75A0(0,5); either negative E=-52. Otherwise17,T0. |
| 17 | R>=31 first calls1D7570 then E=-56. Every T divisible by30 raises progress target; increments T, polls1D75D0. Negative status calls1D7570 and either E=-54 when A>=3 or increments A/retries63. Exact status3 queries1D7600 pair into33B660, caches33C810/808, calls1D72F0 without checking result, advances18,T90,ceiling70/current minimum60. Other nonnegative statuses wait without a local overall timer limit. |
| 18 | Updates progress cadence and decrements T; continues once new signed16 T<=0. Initializes resolver1C9530,1D7660 into33B660 (negative E=-52), saves returned address33C800,1D74B0(0,address) (negative E=-52),otherwise1E;ceiling100/current minimum70. |
| 1E | Publishes Ethernet phase3/clears latch1D7390, zeros33B668 then1D7400(&33B668). Negative result or zero indicator ->E=-53. Otherwise target/ceiling100, advances1F,S/T/R/A/B0,returns0. |
| 1F | Waits displayed current==100; then clears M/P/T/R/A/B,returns2. S is not explicitly cleared in this arm. |
| 63 /64 |63 clears S/T and advances64.64 runs1CB180; completion resets progress,selects P1,S0,T90,R0,retains A/B and returns5. |

Unknown phases return0 unchanged beyond common preflight/progress. Poll counters are signed halfwords and can wrap; retry-budget equality and exact status tests are retained rather than replaced with inferred conventional behavior. Counts30/59/90/150/451 describe original calls and state, not measured seconds. Child RPCs may have their own blocking contracts. No global deadline, successful live connection or slowdown diagnosis is claimed.
