# Auxiliary actor primary-motion animation sound schedules

Static File #1 US o2/runtime3/base570000, owned SHA-256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`, 2026-11-05. Entire685530..6877C4 original interval read in three contiguous PC windows, including comparison-chain delay slots and every emitting branch. No game, sound, animation, build or target execution.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x685530](../recomp/config/output_ovl/o2/o2_00685530_0x685530.cpp) | `request_auxiliary_actor_animation_sound_schedule_by_primary_motion` | Confirmed complete dispatch/audio role; original motion and sound names unknown | Switch-like comparison chain on actor unsignedhalf1F2 selects finite frame-event schedule. D7D==0 chooses defaultsoundbase0/randomrange2,otherbase9 andhitbase4;D7D!=0 choosesbaseF/range0,other/hitbase10. Preserves originalf12 step for all frame-crossing requests. Uses5A9250 actor-position sound,5A9860 explicit model-position sound,5A96F0/9620/97A0/97F0 channel controls; does not advance animation, mix audio, poll frames or wait. Exact schedules include conditional state8/9,BB2,B9B/mode gates and randomized target-dependent admission. |

[Actor animation sound helpers](SYMBOLS_ANIMATION_SOUND.md) and [position sound crossings](SYMBOLS_ENTITY_CROSSING_EVENTS.md) establish the event APIs. The first argument to5A9250/5A9860 is an **animation frame**, not a sound ID; the audio identifier and random range are later arguments. Full call targets remain linked to their existing ownership.

Motion64/65/66 first calls635640(actor,FA0); this target-selection helper can mutate related24/C25/C26 and scoring fields. Only nonzero result followed byRNGmode1 low16&3==0 requests frame0 soundbase48/range10. Thus this branch does more than passive audio lookup; RNG consumption and target mutation precede frame-crossing admission in the lower sound helper.

Examples retained from the full schedules (all values hexadecimal):
- Motion6E:frames10,7C with defaultbase/range.6F:62,A4.70:C,50,6E.
- Motion74:frames52,A6,base3/no random.75:22,58,B8,EE defaultbase/range.
- Motion7C:frame36 uses alternatebase,frames68/74/A0 usehitbase, allrange0.
- Motion82:state8==1/state9 in{12,1D} givesframe12/base8;state8==5/state9==18 emitsatmodel86C+30 withbase37/range2;state9 in{24,B,1C} andBB2 in{1,2} choosebase37/8D atsame modelposition. Other paths no request.
- Motion83 similarly emitsframe18/5E/82 sets atactor/model86C/model85C depending state, plus5A96F0 channel controls for ordinary branch.
- Motion85 emitsdefaultfootfalls20/48/6E/A2 plusframe4 base48/range10, then channel events16/1C/32/38 whose IDs depend onmode-zero andB9B bit1.
- Motion87 emitsnine defaultfootfalls at1C/40/56/92/BA/D2/10C/124/144 then5A97A0(frame88).
- Motion12C..139 shareframe2/base38/range8.143/144 both useframe22/alternatebase (9 or10), thenframe50/hitbase; the prior comparison delay slot sets the shared a2 argument.
- Motion1F4/1F5/1F6/1F7 requestframes18/28/22/16 withbase30,1FA/1FB frame1A/base31,1FC frameE/base30.

Calls such as channel start/stop are still **frame gated** by their respective helpers. Request count per selected motion is a fixed small schedule; there is no sample-proportional decode loop in this function. Names of sounds, assets, actor species or animation actions are not inferred from numeric IDs. Unknown motion falls directly to epilogue. Current input stepf12 is preserved, not replaced by host elapsed time.

The complete top-level comparison ledger below records each literal motion and its owned branch entry. Shared branch targets are not additional function mappings. All conditional bodies behind these targets were read; representative schedules above do not claim every conditional path is identical.

| Motion code | Branch entry | Comparison PC |
| --- | --- | --- |
| `64` | `685A00` | `6859F0` |
| `65` | `685A00` | `6859E8` |
| `66` | `685A04` | `6859DC` |
| `6E` | `685A48` | `6859D0` |
| `6F` | `685A7C` | `6859C4` |
| `70` | `685AB0` | `6859B8` |
| `71` | `685B00` | `6859B0` |
| `72` | `685B58` | `6859A4` |
| `73` | `685B8C` | `685998` |
| `74` | `685BC0` | `68598C` |
| `75` | `685BF4` | `685980` |
| `76` | `685C58` | `685974` |
| `77` | `685CBC` | `685968` |
| `78` | `685D08` | `68595C` |
| `79` | `685D54` | `685950` |
| `7A` | `685DB8` | `685948` |
| `7B` | `685DF0` | `68593C` |
| `7C` | `685E24` | `685930` |
| `82` | `685E88` | `685924` |
| `83` | `685FE8` | `68591C` |
| `84` | `686310` | `685910` |
| `85` | `686344` | `685904` |
| `86` | `686584` | `6858F8` |
| `87` | `686644` | `6858EC` |
| `88` | `686730` | `6858E0` |
| `8C` | `6867AC` | `6858D4` |
| `8D` | `6867F8` | `6858C8` |
| `8E` | `686844` | `6858BC` |
| `8F` | `686890` | `6858B0` |
| `90` | `6868F4` | `6858A4` |
| `91` | `686940` | `685898` |
| `92` | `686974` | `68588C` |
| `C8` | `6869F0` | `685880` |
| `12C` | `686A20` | `685878` |
| `12D` | `686A20` | `68586C` |
| `12E` | `686A20` | `685864` |
| `12F` | `686A20` | `685858` |
| `130` | `686A20` | `685850` |
| `131` | `686A20` | `685844` |
| `132` | `686A20` | `68583C` |
| `133` | `686A20` | `685830` |
| `134` | `686A20` | `685828` |
| `135` | `686A20` | `68581C` |
| `136` | `686A20` | `685814` |
| `137` | `686A20` | `685808` |
| `138` | `686A20` | `685800` |
| `139` | `686A24` | `6857F4` |
| `13A` | `686A40` | `6857E8` |
| `13B` | `686ABC` | `6857DC` |
| `13C` | `686B24` | `6857D4` |
| `13D` | `686B98` | `6857C8` |
| `13E` | `686BE4` | `6857BC` |
| `13F` | `686C30` | `6857B0` |
| `140` | `686C94` | `6857A4` |
| `141` | `686D28` | `685798` |
| `142` | `686DA4` | `68578C` |
| `143` | `686DF4` | `685780` |
| `144` | `686DF0` | `685774` |
| `14B` | `686E24` | `685768` |
| `14F` | `686E40` | `68575C` |
| `150` | `686E5C` | `685750` |
| `151` | `686EA8` | `685744` |
| `152` | `686EDC` | `685738` |
| `153` | `686F10` | `68572C` |
| `154` | `686F74` | `685720` |
| `155` | `686FA8` | `685714` |
| `156` | `686FC4` | `685708` |
| `157` | `686FF8` | `6856FC` |
| `158` | `687014` | `6856F0` |
| `159` | `687048` | `6856E4` |
| `15A` | `6870AC` | `6856D8` |
| `190` | `687128` | `6856CC` |
| `191` | `68715C` | `6856C0` |
| `193` | `687190` | `6856B4` |
| `194` | `6871DC` | `6856A8` |
| `196` | `687228` | `68569C` |
| `197` | `687244` | `685690` |
| `198` | `6872C0` | `685684` |
| `199` | `687324` | `685678` |
| `19B` | `687340` | `68566C` |
| `19C` | `6873BC` | `685660` |
| `19D` | `6873F0` | `685654` |
| `19F` | `6874C0` | `685648` |
| `1A0` | `68750C` | `68563C` |
| `1A1` | `687558` | `685630` |
| `1A2` | `6875A4` | `685624` |
| `1A3` | `6875DC` | `68561C` |
| `1A6` | `687640` | `685610` |
| `1A7` | `68765C` | `685604` |
| `1C2` | `687678` | `6855F8` |
| `1C4` | `6876AC` | `6855EC` |
| `1C5` | `6876C8` | `6855E0` |
| `1F4` | `6876E4` | `6855D4` |
| `1F5` | `687700` | `6855C8` |
| `1F6` | `68771C` | `6855BC` |
| `1F7` | `687738` | `6855B0` |
| `1FA` | `687754` | `6855A4` |
| `1FB` | `687770` | `685598` |
| `1FC` | `68778C` | `68558C` |

Owned whole catalogue interval SHA-256`80f9ae302146d9fa31286a8b392f6e25436392b9ccb18d58be0573ddfc1bb171`; 99 literal motion comparisons, 86 distinct branch targets. No cost, root-cause or runtime audio outcome measured.

Audit: 2080 owned instruction words matched, 133 omitted aligned zero/NOP words, zero omitted nonzero words.
