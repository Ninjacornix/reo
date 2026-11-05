# File #1 o3 exact-mask frontend sprite, selection and animation dispatcher

Static full-body review of owned `netwk.bin`, runtime ID 4/base 570000, SHA-256 `5d23ef8bf97c107421f4bcf8589cf8941f3305ae5f6715573ed68837b9511dfb`. Entire original catalogue interval5F8860..5FC174 read in seven consecutive chunks:8860..8F00,8F00..9800,9800..A100,A100..AA00,AA00..B300,B300..BC00,BC00..C174 (all addresses prefixed5F). Entry and branch delay slots included. Seven owned jump tables read directly. No game, build, GPU submission, live attachment or runtime edit.

Companions: [status renderer and caller](SYMBOLS_O3_STATUS_RENDER_DISPATCH.md), [binary choices and marker text](SYMBOLS_O3_BINARY_CHOICES_MARKER_TEXT.md), [profile/texture view primitives](SYMBOLS_O3_PROFILE_CONTAINER_MESSAGE_LAYOUT.md). Hex addresses, masks, layout-kind values and offsets; animation counts explicitly decimal.

| Identity / source | Proposed role | Confidence | Evidence and contract |
| --- | --- | --- | --- |
| [o3 0x5F8860](../recomp/config/output_ovl/o3/o3_005F8860_0x5f8860.cpp) | `draw_exact_frontend_ui_mask_with_selection_tiles_animations_and_status_prompts` | Confirmed full-body static dispatch/render mechanics; original art labels and complete error-class intent partial | Argument a0 is matched by EQUALITY to one of the individual masks below; combined/unknown masks return without drawing. Calls5F8800(resource index) as availability/binding gate, then5FC180(rectangles,count,y offset), or queues prompt5F7910/type2field5F7B40. Uses fixed descriptor banks616D60..617220, local B4-byte scratch, byte layout/style fields6DF184/185 and186/187, selectors179/158/15A and animated tile17B. Seven checked jump tables cover17 layout kinds or9 animation phases; style indexing itself has no local range check. Some drawing paths mutate timers, drawmask6DF17C and shared error/offset fields. No VU/geometry execution, wait loop or provider request is performed in this body. |

The 80/100/200 and80000/100000/200000 triplets use the same17 selection layouts with different style/kind bytes. For the first triplet, style184 and kind185 select row geometry; for the second, style186/kind187 do so. Unselected and selected passes use inverse branch conditions, not one identical filter. Local descriptor size14 bytes per rectangle; copying3C bytes supplies three rectangles; B4 scratch accommodates nine. This function does not establish those descriptors' full downstream GS contract.

| Exact mask -> block | Resource gate / output mechanics |
| --- | --- |
| 1 ->5F89C4 | Index0; descriptor616D60, count1,y0. |
| 2 ->5F89EC | Index2;616D80,count2,y0. |
| 4 ->5F8A14 | Index2;616E50,count3,y0. |
| 8 ->5F8A3C | Index2;617020,count3,y0. |
| 10 ->5F8A64 | Index2;617060,count3,y0. |
| 8000000 ->5F8A8C | Index2;617220,count3,y0. |
| 20 ->5F8AB4 | Index2;6171E0,count3,y0. |
| 40 ->5F8ADC | Index7;6171C0,count1,y0. |
| 80 ->5F8B04 | Index2;zeroB4/copy616E10[3C], apply617260 layout geometry, submit count3 for each row OTHER than selection. Checkedkind185<11; table62A340. |
| 100 ->5F9178 | Index2;zeroB4/copy616DD0[3C],same geometry, submit count3 only for selected row;table62A2F0. |
| 200 ->5F97EC | Index1;zeroB4/copy616DB0[14],position6172A8[style*4];UV tile17B uses32-step vertical shift;tile>=8 adds128 horizontal and uses(tile-8)*32. Resets signed half1B0=-32768, selects row y by table62A2A0, submits count1. Sentinel comparison edge below. |
| 800000 ->5F9E64 | Index1;builds same tile usingstyle184. Signed byte18E increments;value>=11 clears this bit in17C and exits. Otherwise scales width toward560 over10 calls, centersat320;18F increments/clamps6;height half=max(1,trunc((32-trunc(30*18F/6))/2)),centersat224;draws count1 at saved signed offset1B0. Counters shared with1000000. |
| 400 ->5FA0C0 | Index3;zeroB4/copy616E90[B4],selects four y values from617290+8*byte180 for groups of3 rectangles;submit count9,y0. No local bound on180. |
| 800 ->5FA184 | Index7;6170C0,count9,y0. |
| 1000 or10000000 ->5FA1AC/B0 | No pre-copy gate;zeroB4/copy616F50[14],thenindex4 gate. Increments188;when>60 resetsand toggles189,whichchangesUV bounds80/FF. Increments18A;when>90 resets/toggles18B. Increments18C;when>120 resets/increments18D,wrapping at5 if67C500==1 else7. Drawcount1;1000 queues39+18B AND falls through3B+18D;10000000queuesA4+18D only. Counts decimal; all these fields are shared, not per-mask local timers. |
| 2000 ->5FA398 | Index3;zeroB4/copy616F70[50]. Signed timer154>100 is clamped100; signed timer times signed rectangle width is then divided using UNSIGNED divu by100 and storedlow16 width;submitcount4,queue type2field5. Negative154 is not clamped here. |
| 4000 ->5FA430 | Index6;mode165==1 increments18A,wraps at60/toggles18B&1;mode!=0/1 clears18B;mode0 retainsit. Queues1B if18B0 else8D. |
| 8000 ->5FA4E8 | Index6;zeroB4/copy616FC0[28], checkedphase188<9/table62A270. State-controlled alpha crossfades described below;submitcount2,y0. |
| 2000000 ->5FA8A4 | Index6;queues7D and7E. |
| 4000000 ->5FA8CC | Maps shared error1D0 to signedbyte class0..12 and a secondary flag;queues42+class,optionalA1,then type2field8 unlessclass12. This path has no5F8800 gate. Literal register-dependent decision tree is not reduced to an intended error-to-message table; see edge note. |
| 10000 ->5FAB34 | Index3;616FF0,count2,y0. |
| 20000 ->5FAB5C | Index7;617180,count3,y0. |
| 40000 ->5FAB84 | Index3;6170A0,count1,y0. |
| 80000 ->5FABAC | Index2;unselected rectangles as80,usingstyle186/kind187;table62A220. |
| 100000 ->5FB220 | Index2;selected rectangles as100,usingstyle186/kind187;table62A1D0. |
| 200000 ->5FB894 | Index1;selected glyph as200,usingstyle186/kind187, savesoffset1B2;table62A180. |
| 1000000 ->5FBF0C | Index1;animation as800000,usingstyle184/tile17B and savedoffset1B2. Clears1000000 once shared18E>=11. |

Selection layouts below apply to all six17-case tables. Row y offsets are signed hexadecimal; normal selection pass draws when selector equals the row index, while the unselected pass draws when it differs. A selector outside the listed rows can therefore make the unselected pass draw all rows and the selected pass none. KindF explicitly returns in rectangle passes but retains the sentinel in glyph passes. Style geometry uses three clearly adjacent16-byte records at617260: `(180,220,420,200)`, `(160,200,440,240)`, `(220,260,380,120)` (decimal). SHA-256ofthese48bytes:`23e1d2eb7a69dda959d2e7b7943e5e130c5414512993bab138fde4cc6d0516c1`. Code writes first/fourth/third/second fields into x/thirdwidth/thirdx/firstwidth offsets30/48/58/44; do not interchange the tuple fields. Tileposition pairs at6172A8 are(181,278),(157,326),(230,180); callers must constrain style because local code does not.

| Kind | Selector | Row y offsets |
| --- | --- | --- |
| 0 | byte179 | 42,6E |
| 1 | signedhalf158 | -58,-34,-10,14 |
| 2 | signedhalf158 | -58,-10,38 |
| 3 | signedhalf158 | 6E,9A |
| 4 | signedhalf15A | 42,6E |
| 5 | signedhalf158 | -58,-34,-10,14,38 |
| 6 | signedhalf158 | 42,6E,9A |
| 7 | signedhalf15A | 42,6E,9A |
| 8 | signedhalf15A | 6E,9A |
| 9 | signedhalf158 | 42,6E |
| A | signedhalf15A | -42,-16 |
| B | signedhalf15A | 42,6E |
| C | signedhalf15A | 16,42,6E |
| D | signedhalf158 | -58,-10 |
| E | signedhalf158 | 14,38 |
| F | no selection | Rectanglepassesreturn;glyphpassesretain sentinel. |
| 10 | signedhalf158 | 42,6E |

8000 animation uses phase188, counter189 and signed mode165. It modifies high bytes of packed halfword colors40/54 while preserving low bytes: phase0 waits mode1 then1/counter0, alpha0/0;phase1 incrementscounter and ramps firstalpha255*n/48 until>48 thenphase2/full;phase2 waits mode3->3 ormode2->5,counter0,firstfull/second0;phase3 fadesfirstover48 then4;phase4zero/zero;phase5 crossfadesfirst->second over16 then6;phase6 waits mode!=2 then7/counter0,first0/secondfull;phase7 fadessecondover48 then8;phase8zero/zero. Out-of-rangephase still submits the copied two rectangles without phase-specific mutation. Shared use of188/189 with1000 means interpretation depends on caller phase and initialization; do not assume independent clocks.

Two literal details are retained without claiming normal reachability or a reproduced defect. At5F9E44..4C and5FBEEC..F4, signed `lh` of sentinel8000 produces-32768 but comparisonregister is positive32768 (`ori`). The comparison does not reject that sentinel; invalid-kind/selection paths can reach draw with-32768 offset if otherwise admitted. At5FA908..91C the error-class path can overwritev0 with2 before comparing against-105; further branches likewise reusev0 for class constants. Thus a natural error-value switch inferred from comparison literals would overstate actual semantics. Only class emission mechanics and explicit source branch tree are claimed. No runtime/fix recommendation follows without admission/caller evidence.

Owned dispatch tables (index0-based; destinations absolute hex):

```
62A340: 0:5F8BBC, 1:5F8C04, 2:5F8C90, 3:5F8CFC, 4:5F8D44, 5:5F8D8C, 6:5F8E3C, 7:5F8EA8, 8:5F8F14, 9:5F8F5C, A:5F8FA4, B:5F8FEC, C:5F9034, D:5F90A0, E:5F90E8, F:5FC160, 10:5F9130
62A2F0: 0:5F9230, 1:5F9278, 2:5F9304, 3:5F9370, 4:5F93B8, 5:5F9400, 6:5F94B0, 7:5F951C, 8:5F9588, 9:5F95D0, A:5F9618, B:5F9660, C:5F96A8, D:5F9714, E:5F975C, F:5FC160, 10:5F97A4
62A2A0: 0:5F9924, 1:5F9964, 2:5F99E4, 3:5F9A44, 4:5F9A84, 5:5F9AC4, 6:5F9B64, 7:5F9BC4, 8:5F9C24, 9:5F9C64, A:5F9CA4, B:5F9CE4, C:5F9D24, D:5F9D84, E:5F9DC4, F:5F9E40, 10:5F9E04
62A270: 0:5FA548, 1:5FA57C, 2:5FA604, 3:5FA664, 4:5FA6F0, 5:5FA700, 6:5FA7BC, 7:5FA7F4, 8:5FA880
62A220: 0:5FAC64, 1:5FACAC, 2:5FAD38, 3:5FADA4, 4:5FADEC, 5:5FAE34, 6:5FAEE4, 7:5FAF50, 8:5FAFBC, 9:5FB004, A:5FB04C, B:5FB094, C:5FB0DC, D:5FB148, E:5FB190, F:5FC160, 10:5FB1D8
62A1D0: 0:5FB2D8, 1:5FB320, 2:5FB3AC, 3:5FB418, 4:5FB460, 5:5FB4A8, 6:5FB558, 7:5FB5C4, 8:5FB630, 9:5FB678, A:5FB6C0, B:5FB708, C:5FB750, D:5FB7BC, E:5FB804, F:5FC160, 10:5FB84C
62A180: 0:5FB9CC, 1:5FBA0C, 2:5FBA8C, 3:5FBAEC, 4:5FBB2C, 5:5FBB6C, 6:5FBC0C, 7:5FBC6C, 8:5FBCCC, 9:5FBD0C, A:5FBD4C, B:5FBD8C, C:5FBDCC, D:5FBE2C, E:5FBE6C, F:5FBEE8, 10:5FBEAC
```

Audit: 3326 verified instruction words, zero conflicts, 327 omitted zero words (NOP padding), zero omitted nonzero words.
