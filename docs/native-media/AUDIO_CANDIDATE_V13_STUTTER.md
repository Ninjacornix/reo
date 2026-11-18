# V13 sound reply retest and late cinematic hitch

The private File #1 V13 candidate completed its character-selection route,
cinematic sequence and observed gameplay, then exited normally after WM_CLOSE.
Its complete native PCM/bank/RAM backend joined, with no remaining operations,
hard audio failures or queue rejections. The previously measured SID 1 / RPC
0x10 refusal did not recur. All 132 remaining RAM diagnostic reports correspond
to the existing optional packet-log refusals; other operation refusal counters
are zero. This resolves that identified startup request in this bounded route.
It does not close stage 3 or demonstrate a stutter fix.

The player reported a stutter near the end of the cinematics. The frame log
retains a **747.3569 ms** CPU presentation-return interval at CSV lines
19947–19948, and a nearby **222.2318 ms** interval at lines 19899–19900.
Both lie within approximate advancing movie sample windows. The longer gap
has 746.2117 ms between the endpoint capture spans: the endpoints themselves
do not account for most of it. These are CPU return observations, not measured
physical display scanout or a unique-picture FPS result.

Around the longer gap, stderr lines 7480 and 7495 observe movie clocks
5040000/59940 and 5108000/59940, while the latest decoded-position metadata
changes from 2522000/29970 to 2533000/29970. The latter falls behind the clock;
line 7513 then reports 2586000/29970. This is a measured timing discrepancy and
later recovery, not a decoded-picture count or proof of why work stopped.

No retained movie-work event overlaps either of these two large gaps. All work
sections export successfully with valid records, but epoch four retains only
4,160 of 18,469 slow events and explicitly misses 14,309. Its aggregate maxima
are owner control 92.1426 ms, decode 17.5944 ms and batch fence 33.4577 ms.
The bounded evidence does not assign the large gap to a decoder, GPU fence,
resource wait, original scheduler or host descheduling. Neighboring packet/RPC
messages have no incident timestamps and are not causal evidence.

The scheduler heartbeat supplies a narrower lead. Stderr line 7499 reports
guest thread six owning 751 ms and main thread one waiting 773 ms in that
counter interval; line 7489 previously reports 227 ms owned by six and 245 ms
waiting by one. Before and afterward thread six ordinarily records about
6–7 ms. Creation/start records at lines 531 and 534 identify six as entry
`12AD70`, the CRI group-four dispatcher. The matching SDK's `g_ownNs` records
elapsed time between guest execution acquire/release, not host CPU consumption;
its totals publish at release and can cross heartbeat boundaries. These counters
therefore point toward long shared-execution ownership in the file/disc service
route, including possible host blocking/descheduling, without proving which
child/read caused it. No incident-duration step-level timing was enabled.
The earlier CRI disc-read investigation is a relevant hypothesis, not a repeated
measurement of its historical ISO stall: this test uses verified PAK reads.

The native audio report contains **18,208 underrun frames out of 17,786,880
output frames**. It has no per-window timestamps. These totals cannot be aligned
to this hitch. The pacing analyzer previously checked only the older native
PCM selector, incorrectly describing zero legacy starvation windows for this
complete-backend run. Schema two now reports the selected complete backend's
actual counters and preserves unknown/invalid/unjoined evidence. Seven pacing
and six complete-audio analyzer tests pass. The original analysis is retained;
the corrected report has a new filename.

This run included concurrent standalone compilation and a short offscreen GPU
priming check. It is not an accepted performance comparison. The attempted
desktop rectangle capture is occluded by another application and supplies no
game-pixel validation. The guest observation reaches gameplay without skip
inputs; neither it nor the screenshot establishes audible A/V equivalence.

Evidence below `build-native-sjuni`:

| Receipt | SHA-256 |
| --- | --- |
| `candidate-work-v13/candidate-build-result.json` | `75005134ea5059ac7ef416968fefc9a16df1f536221a9565e8d95b9b340c92a3` |
| `sound-rpc10/playtest-v13/observations.json` | `adc1af303c79d5604ef944e6eb3ed5644f7d7a9d35119a329c694c088661e8eb` |

The observation receipt hashes the original frame/work logs, original and
corrected analyses, process identity, bounded control sample, close request and
occluded screenshot. The candidate executable is
`a6bfe3fdaf99e628b1be9f6e4922244a43ef1c142bec2a58001c92917d6476da`.
Its 129 dependency patches come from the previously audited independent source
copy. The new whole-player/movie owners are not linked into this binary.
