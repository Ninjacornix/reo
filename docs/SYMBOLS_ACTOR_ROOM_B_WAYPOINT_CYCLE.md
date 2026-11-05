# Actor roomB waypoint cycle

Static File #1 US research, 2026-11-04. One complete original body reviewed.
Addresses/offsets/selectors hexadecimal; distances/timers decimal. No execution,
attachment, build, replay or engine changes. Original waypoint meaning unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C4F30](../recomp/config/output_ovl/o2/o2_006C4F30_0x6c4f30.cpp) | `cycle_three_room_b_waypoints_with_endpoint_turns_and_wait_counter_candidate` | High mechanics | FD2states0..4,FC4signedwaypoint,FC8direction,FC6wait.0FC4=0,idleunless80000,FD2++,falls1;1copies7304E0[FC4]XYZto1124,FD2++,returns.2route6BD270,selectmotion1unless80000,unless30<=distance choosesendpointturnorindexadvance.3waitsFCC0,FD2++,idlesunless80000.4predecrementsFC6,post<0 advances/clamps/togglesindexdirection,FD2=1. Fullendpointdetailsbelow. DoesnotinitializeFC8locally;previous64Aphaseclearsit. |

At reachedwaypoint inFD2=2, nonzero730510[FC4]setsFC6=90,FD2=3,
FF4=half730508[FC4],FCC1,selectmotionDunless80000. Zeroentry advances
index immediately andFD2=1. Direction0 incrementsindex;newindex>=3togglesFC8
withoutclamping inthis zeroentrypath. Directionnonzero decrementsindex;
newindex<0togglesFC8withoutclamping. Bycontrastafter90-stepwait, direction0
incrementsandclamps>=3to2/toggles;directionnonzerodecrementsandclamps<0to0/toggles.
All branches and initial fallthrough reviewed.

Owned three-waypoint data has endpointflags[1,0,1]; therefore with admitted
indices0..2 and direction0/1, endpoints use the clamped wait path. No invalid
asset or counter state is assumed, and arbitrary FC4/FC8 values are not locally
validated. The [caller sequence](SYMBOLS_ACTOR_6C45D0_DEMO_ROOM_COMMANDS.md)
clearsFC8 before relocating to the roomB slot record.

| Owned span | Values / SHA256 |
| --- | --- |
| 7304E0 length24 | XYZ(decimal)[(5801,800,2829),(5790,800,2508),(5931,800,2428)]. `ca392f3d85d56443e069bb8ffa096cbd79b379ef8536f4ffb27caef1abcae5fc` |
| 730508 length6 | Unsignedyawhalves[4000,0,4000]. `845f557f7cf5f592b094888abf09ba6b26b327d7c556cfac6d6c1ba523c58572` |
| 730510 length4 | bytes[1,0,1,0];firstthreeusedforadmittedwaypoints. `507503b51960cceda8d924904fb85377fe7d177fb8dfcf56b24e4557644ed486` |

Owned image`build-function-index/owned-overlays/o2.bin`,base570000,SHA256
`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Full-body owned-word audit: 1 rows, 205 verified instruction words,
zero conflicts, 13 omitted zero/NOP words, zero omitted nonzero words.
