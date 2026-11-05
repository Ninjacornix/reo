# Function-level audit of the non-actor exclusions

Static reference applicability review, 2026-11-05. Pinned Code Veronica source commit `657b0c0c9489943116c71f151804ad7304fca975`. No game, build, replay, guest execution, process attachment, memory read or runtime/native changes. This report is an eligibility and bounded contract audit, not proof that all game code is unique or that every admitted helper has an Outbreak equivalent.

The original remaining corpus partition is explicit by `(file, symbol, start_line)` in the receipt: **1,102 non-actor definitions** and **1,850 actor definitions**. The 57 definitions in `sdc.c`/`sdcwrap.c` were transferred to the separate sound-adapter audit. This report screens the other **1,045 definitions in 28 files**, admits **76 utilities/framework adapters**, and retains **969 CVX integration definitions**. The two previously admitted `sub1.c` platform functions are already in the availability ledger and are not duplicated.

Every screened definition retains its complete source header/body, original parser bounds/body SHA-256, raw line-span hash, file SHA-256, calls, source callers, member accesses and concrete owner/type references. Signatures with scalar/array/NJS arguments are leads, not automatic equivalence. Complete candidate bodies and their callers were checked for hidden state, data formats, authored node/room/item identifiers, and edge behavior. `eligibility_screen` contains all 1,045 records; only admitted records appear in `files[].functions`, so exclusions cannot inflate compared coverage.

Owner-token extraction and call relationships support a repeatable screen; they do not prove a function cannot be generalized or that no equal instruction sequence exists elsewhere. The retained cases have source applicability dispositions, rather than newly recovered Outbreak purposes. Empty handlers and constant placeholders are kept separately from implemented utility contracts.

## What changed

Filename-only exclusions missed actual reusable bodies. The admitted set includes MSB-first bit arrays; selector comparisons with undefined unsupported-selector returns; matrix movement/direction helpers; a half-triangle predicate; caller-model tree flag walks; quads, palettes, PVPL/TIM2 setup, glyph layout and width parsing; BUP callbacks; a circular callback pool; singleton file requests; and small middleware/command adapters. Global ownership is stated even when the algorithm is reusable. This pass adds **no Outbreak alias, mapping row or runtime fix**.

The exact checked flag candidates are materially different: CVX bit0 is `0x80000000`, whereas the owned set/clear routines use `1 << (ID & 31)` in a fixed bank; the owned contextual query also selects a bank. A raw nonzero return does not erase the bit-numbering or ownership difference. The renderer comparison likewise distinguishes Ninja floating-point descriptors/state from Outbreak signed-half endpoints, GS packet templates and queue publication.

Several tempting generic signatures remain integration: `RoomNameSwitch` hardcodes CVX rooms; `Combi_01/04` operate packed inventory IDs/ammo policy; `LighterOpen`/`FileSyu` edit authored nodes; `FsubZoomScreen`/`FsubCompass` draw authored map widgets; `bhDispTime/Ex` have game-mode-specific caps; `bhChangeClipVolume` uses stage/room/event overrides; `Get3DSoundParameter` depends on camera and room-specific attenuation tables. Conversely, `MdlHideCheck`/`FlagErase` and the callback pool are admitted despite living in those same game files.

## Exact screened boundary

| Source file | Screened | Admitted | Retained integration | Raw source SHA-256 |
| --- | ---: | ---: | ---: | --- |
| `src/ps2/veronica/prog/adv.c` | 84 | 23 | 61 | `bc05ad2d77b6b7f81f348384393f5a7cfe3f1217e5247dc0467c09fdee91163c` |
| `src/ps2/veronica/prog/backup.c` | 6 | 6 | 0 | `e03ab2688056a2e4e2135fa9379e0c8e950c4ce745dbfb970aa0d3510e21a866` |
| `src/ps2/veronica/prog/bup_00.c` | 8 | 0 | 8 | `1317f828eb4902e47af2299ad522c786f9e114b43a10e69ee663664b51453555` |
| `src/ps2/veronica/prog/camera.c` | 4 | 0 | 4 | `92a226a125e6d653a334449ec299d129eb6d28e670f21697bcfb5e0a737f8f94` |
| `src/ps2/veronica/prog/cut.c` | 26 | 1 | 25 | `9d8ed313f48db34ddd4e6a4e058de9f0e1c6772e85971b518a330373aaa3f109` |
| `src/ps2/veronica/prog/door.c` | 33 | 4 | 29 | `576eac5866d61085fdfb4c7cd6ca44a5320e016f7510b2f86c8433ccdc356d21` |
| `src/ps2/veronica/prog/event.c` | 240 | 0 | 240 | `6c8f08b2f031ecbd753f1f0a814afd97315b4a380e2825a6147bee77dd16d094` |
| `src/ps2/veronica/prog/fileview.c` | 22 | 0 | 22 | `92249ce8e5990709c004cda86649c5ee35ddd2a432d3c85af01190e1db68c7b1` |
| `src/ps2/veronica/prog/flag.c` | 3 | 3 | 0 | `727d5d65c066a4f6b9cb51a220b248474e6e81d6a906f26eba07f67e09446186` |
| `src/ps2/veronica/prog/game.c` | 4 | 0 | 4 | `cc19965cb9f8f4fce6fbc33984096e9b472ad43aac4450968ebbddc0174964ec` |
| `src/ps2/veronica/prog/gameover.c` | 6 | 0 | 6 | `5dc4bbe0426aaf9b4530745f62cf40978f6be6630fb3f961ed2be12e73d6f5ba` |
| `src/ps2/veronica/prog/itemview.c` | 22 | 3 | 19 | `95661d9631d100dc3f763bfe4741b49056e16a36b3b37ec52f61dae3519bd4c1` |
| `src/ps2/veronica/prog/light.c` | 7 | 1 | 6 | `838df7d96e2883351cec67696f76ac7331afbf81a4225173f7d6279d69987061` |
| `src/ps2/veronica/prog/main.c` | 3 | 0 | 3 | `12db1a00f23eedebb4a5c9e3f769d7c79ff92581f6d20b69014558c03b8ae384` |
| `src/ps2/veronica/prog/map.c` | 61 | 11 | 50 | `f0a310f4a1cb9a3133067e583d912681a9401f1994ff449cf1a733d519a98712` |
| `src/ps2/veronica/prog/message.c` | 12 | 5 | 7 | `4eecd08c919441f3aa3356cc36962ff484547bbbf226060eb3994f7bfb723fca` |
| `src/ps2/veronica/prog/objitm.c` | 26 | 0 | 26 | `351eb99550f90e834cba7af26e165d93903757851a5b9b19acd5e3feb430d133` |
| `src/ps2/veronica/prog/ps2_LoadScreen.c` | 39 | 0 | 39 | `61d262219eace3d9325f8f44bb03de67f74906dadce5da495d382ff47d39ce8e` |
| `src/ps2/veronica/prog/ps2_SaveScreen.c` | 58 | 0 | 58 | `57a10bdebd4bb890b7d8ab00b8bd90a17af83c104ef99a760f78fb2c62508a38` |
| `src/ps2/veronica/prog/ps2_SystemLoadScreen.c` | 23 | 0 | 23 | `832233c8f96767114c3f5f06dc76c6939bd4c982991d049563c8fe927c94f57c` |
| `src/ps2/veronica/prog/ps2_SystemSaveScreen.c` | 50 | 0 | 50 | `3db66c2d0a3c02d97b078f7f528121d1dd57d1dbb31e4f5bac783d2d0ed0e8e8` |
| `src/ps2/veronica/prog/ranking.c` | 24 | 0 | 24 | `b8ada21b1eda2bc4d336965763ce58d9c20da78721e0f143756bb3951a50b929` |
| `src/ps2/veronica/prog/room.c` | 16 | 0 | 16 | `495088fa708ae7c7036bf8113af75357eb7135cc7f11c8d46dcf7e265264d0d3` |
| `src/ps2/veronica/prog/screen.c` | 15 | 0 | 15 | `280268d04f5aeb09bd8c45c69c7f9b8ccd0d60ca2f936ab5339154b10f7c13c8` |
| `src/ps2/veronica/prog/sdfunc.c` | 131 | 16 | 115 | `744a983e011b581b95d58520f112c770143697f02dc8f082e6ab26ecaf9aa512` |
| `src/ps2/veronica/prog/sp_evt.c` | 20 | 0 | 20 | `f6726e999ecd3ce4f5ed979eb1fc65de6933ae81968bd85c2ca7ce812277e105` |
| `src/ps2/veronica/prog/sub1.c` | 69 | 3 | 66 | `c74dd5b01d040248b60e22766e07d2bbeb852e9df7a13c8a2b4f8690dffe9848` |
| `src/ps2/veronica/prog/system.c` | 33 | 0 | 33 | `b5cffd82ab39e3a4c0936068c3e3c3f1c38abe2dee6704798355a185c05b2f99` |

## Admitted complete-body contracts

These are additional eligible reference units with bounded comparisons or scoped unmatched results. They are not 76 proven equivalents and do not raise the fixed Outbreak function denominator. Each receipt record links its exact comparison group and evidence boundary.

| Reference definition | Full source lines | Contract and limits |
| --- | --- | --- |
| `adv.c:GetSamurai` | 56–59 | Returns reciprocal of integer expression(Time/100)*30+((Time%100)*6)/10. Integer truncation precedes float conversion; zero denominator unguarded; packed-time unit remains qualified. |
| `adv.c:AdvGetResourcePtr` | 167–170 | Returns bp+((int*)bp)[ResId], no table/span validation; reusable relative-offset lookup, not archive format identification. |
| `adv.c:AdvDrawFadePolygon` | 419–448 | Static quad(-2,-2)..(642,482); depth table[Type]={.98,.90,1.99,1.98}; OR quantized alpha into BaseColor, Ninja polygon attr1; no Type bound. |
| `adv.c:SetPvrInfo` | 576–591 | TIM2 picture format reset0; gindex and picture metadata at+128 feed texture-info/name constructors with attributes40800000. Extra C parameters unused in body; no whole-file validation. |
| `adv.c:TransPvpData` | 594–617 | Checks four-byte PVPL tag, else-1; reads category/bank, optionally sets palette mode and returns signed bank. It does not upload palette payload here. |
| `adv.c:AdvTransShadowPalette` | 620–638 | Allocates64 aligned32, initializes first word00FFFFFF and remaining15 wordsFF000000, sets palette16/count16 then releases. Allocation/transfer lifetime delegated. |
| `adv.c:AdvEasyDrawWindow` | 641–688 | Four border quads: top/bottom4px,left3px,right3px offsetright-4; then interior fill with depth-.001; Ninja state/draw wrappers, not owned packet ABI. |
| `adv.c:AdvEasyDrawTexture` | 691–705 | Optionally OR8000 into current TIM2 ClutChange; starts quad mode, selects texture/color, draws caller QUAD/depth, ends. Mutates texture metadata/render state. |
| `adv.c:AdvEasyDrawTextureS` | 708–725 | Draws original first; copies32-byte QUAD to global Qtex15, offsets XY+3, draws shadow alpha<<24 at depth-.001 in trans mode1. Global scratch and draw order matter. |
| `adv.c:SetQuadPos` | 728–735 | Sets inclusive endpoints start+(size-1), caller QUAD; no clipping or size validation. |
| `adv.c:SetQuadUv2Ex` | 738–754 | Uses AdvTexList selected NJS_TEXMEMLIST dimensions, divides negative dimensions by3, normalizes UV and size-1 endpoints. Index/zero dimensions unguarded; framework table ownership explicit. |
| `adv.c:SetQuadUv2` | 757–760 | List0 adapter to SetQuadUv2Ex; same texture-table and denominator contract. |
| `adv.c:AdvDwawOnePictureEx` | 763–777 | Global Qtex, filter1, fixed1024x512 position/UV, draw at.01, filter0. Framework fullscreen adapter; fixed canvas is not Outbreak screen identity. |
| `adv.c:AdvDwawOnePicture` | 780–783 | Forwards to AdvDwawOnePictureEx with BaseColor=-1; fixed canvas/global state retained. |
| `adv.c:AdvEasySetupTextureBasic` | 786–810 | Two relative offsets select optional PVPL and TIM2; records AdvWork PalNo/PalFlag and per-list palette bank then SetPvrInfo. This is a CVX texture framework object, not a universal resource layout. |
| `adv.c:AdvEasySetupTextureEx` | 813–822 | Uses AdvWork.ptr[Count], selected list and Count as texture index, then increments Count. No count bound. |
| `adv.c:AdvEasySetupTexture` | 825–828 | List0 adapter to setupEx; framework ownership, not a new texture-loader identity. |
| `adv.c:AdvEasySetTextureList` | 831–836 | Selects AdvTexList[ListNo] then texture0. Mutable Ninja binding and unchecked list index. |
| `adv.c:AdvEasyTransTextureBasic` | 839–859 | Publishes texture count, loads/selects list; Flag0 frees Adv memory, then Count0/SetTexture[list]1. Delegated success and retained payload lifetime not guaranteed. |
| `adv.c:AdvEasyTransTextureEx` | 862–869 | Uses AdvWork.Count and Flag0 for selected list; same load/free/state contract. |
| `adv.c:AdvEasyTransTexture` | 872–875 | List0 adapter to TransTextureEx; no independent transfer completion proof. |
| `adv.c:AdvEasyReleaseTextureEx` | 878–892 | If SetTexture[list] nonzero releases list and clears flag, always calls bhGarbageTexture(NULL,0); no reference-count equivalence asserted. |
| `adv.c:AdvEasyReleaseTexture` | 895–898 | List0 adapter to releaseEx; same renderer/cache side effects. |
| `backup.c:BupInit` | 9–14 | Zeroes global BACKUPINFO then buInit(MAX_CAPS,USE_DRIVES,0,BupInitCallback); generic BUP wrapper, not Outbreak libmc2 ABI. |
| `backup.c:BupExit` | 17–23 | Calls buExit repeatedly until OK; no timeout/admission guard. Synchronous busy-loop behavior retained. |
| `backup.c:ClearInfo` | 26–44 | Clears selected drive progress/operation/readiness/format/work and disc information fields; no CVX save payload/schema consumed. |
| `backup.c:BupComplete` | 47–104 | Connect/mount/unmount/save/load completion callback updates BACKUPINFO; unmount frees nonnull MemMode0 work, drive info/errors follow distinct operation branches, operation cleared. BUP enums/layout not shared by assumption. |
| `backup.c:BupProgress` | 107–119 | Stores drive operation/count/max in BACKUPINFO and returns BUD_CB_RET_OK; no save format or UI work. |
| `backup.c:BupInitCallback` | 122–126 | Registers BupComplete and BupProgress with BUP platform; platform implementations absent from this unit. |
| `cut.c:bhCheckCutAreaInnerTriangle` | 196–251 | AABB plus atr_tp1..4 half-triangle test from caller CUT_WRK XZ bounds; fabs/division edge behavior, unsupported type uninitialized locals and degenerate denominator retained. No room/global lookup in body. |
| `door.c:CompareSint32` | 1929–1953 | Selector-1:>=;0:==;1:<=;±2:!=. Other selectors leave ret uninitialized; dead if(0) does not initialize it. |
| `door.c:CompareFloat` | 1956–2008 | Same admitted selector relation as CompareSint32, including ordered/NaN semantics; unsupported selectors leave ret uninitialized. |
| `door.c:VectorMove` | 2011–2023 | Resets global lcmat, copies position into translation, rotatesY(yaw) thenX(pitch), translates along negativeZ by speed, copies translation out. Shared matrix side effect. |
| `door.c:ryExcuteFade` | 2074–2110 | Static640x480 quad and colors; scales packed RGBA using int(256*rate), draws only nonzero alpha, sets Ninja blend8/6 and attr96. State and narrowing differ from owned rectangle emitters. |
| `flag.c:bhStFlg` | 4–7 | Caller-owned32-bit array, OR0x80000000>>(bit&31) in word bit/32; MSB-first, no bounds guard. |
| `flag.c:bhCrFlg` | 10–13 | Caller-owned32-bit array, AND complement of0x80000000>>(bit&31); MSB-first, no bounds guard. |
| `flag.c:bhCkFlg` | 16–19 | Returns raw masked word, not normalized boolean; same MSB-first caller-owned indexing. |
| `itemview.c:MdlDirChk` | 922–940 | Step0 returns1; updates local mdlang modulo65536, subtracts target and compares unsigned wrapped difference with signed short step*2. No normalized shortest-angle replacement admitted. |
| `itemview.c:MdlHideCheck` | 1087–1121 | Recursive child/sibling NJS_CNK_OBJECT flag8 setter using by-value unsigned-char el/chk. chk doubles per recursive edge including siblings; local clearing feeds both calls, but child-call mutations are not returned to the subsequent sibling call. Not one shared preorder bit counter. |
| `itemview.c:FlagErase` | 1148–1162 | Recursively clears evalflags bits2 and1 on root, child and sibling; no game globals or authored node indices. Null root/cycles not admitted. |
| `light.c:bhGetLightVector` | 1058–1069 | Resets Ninja current matrix, appliesZ(zr),Y(yr),X(xr), transforms fixed(0,0,-1) into vec. Mutates current matrix; angle units/call convention not inherited by owned VU math. |
| `map.c:MapFuncInit` | 1289–1307 | Allocates(func_num+2)*64, global mwP busy/free circular sentinels, inserts free nodes. Generic callback framework inside map owner; no topology/schema equivalence. |
| `map.c:MapFuncAlloc` | 1310–1333 | Removes free-head next, inserts busy, writes callback/mode/param and clears remaining parameters/nine workwords. No empty-free-list admission check. |
| `map.c:MapFuncFree` | 1336–1340 | Unlinks and inserts into global mwP free list. Caller owns valid membership; no duplicate-free guard. |
| `map.c:MapFuncDel` | 1343–1347 | Intrusive doubly-linked unlink updates neighbors; self links retained. Requires valid neighbors, no NULL/cycle checks. |
| `map.c:MapFuncIns` | 1350–1359 | Intrusive insert after base; declared pointer return but no explicit return statement. Do not invent a usable returned node. |
| `map.c:MapFuncExec` | 1362–1375 | Walks busy list, saves next before optional callback; current unlink accommodated, unrestricted mutation safety not proved. |
| `map.c:MapDrawLine2` | 2319–2334 | Static2-point/color descriptor, copies XY and palette, Ninja line count1 attr40, no rounding. |
| `map.c:MapDrawLine` | 2337–2352 | Same line facade but floor(XY+.5) and attr0; not interchangeable with MapDrawLine2. |
| `map.c:MapDrawFill` | 2355–2372 | Builds static four-point rectangle from endpoints then MapDrawPolyFill; no clipping. |
| `map.c:MapDrawPolyFill` | 2375–2385 | Borrows caller points in static four-point descriptor, repeats packed color, Ninja polygon attr60. Not same descriptor/packet as Outbreak. |
| `map.c:MapCnvArgb2Color` | 2563–2573 | Multiplies float ARGB channels by255 into byte components without explicit clamp. Conversion and exceptional domain not silently normalized. |
| `message.c:bhDispFont` | 365–450 | Ninja glyph facade over sys->ef_tlist:324 codes/page,18x18 atlas14px cells drawn28px scaledXY; fixed five palette choices, blend8/6, texture filter0. CVX atlas/owner is explicit, not Outbreak glyph encoding. |
| `message.c:bhDispFontEx` | 453–509 | Same324/page18x18 glyph geometry/UV as bhDispFont, caller packed ARGB instead of palette selector. Render state left changed; no admission for negative code. |
| `message.c:bhGetFontSize` | 1007–1015 | Unsigned code>=108 returns0, else FontSz[code]. CVX asset-width table, not a universal font API/result unit. |
| `message.c:bhMesLen` | 1019–1072 | Unsigned16 stream to FFFF, ignoresFF00/FF04/FE00..FE0F, FF01 adds14*FontScaleX, FF02/03 skip next word; other code adds scaled FontSz width. No stream-length bound; distinct CVX control format. |
| `message.c:bhFontScaleSet` | 1076–1082 | Sets global FontScaleX/Y/CR from three float arguments. Framework setter, not a portable output-packet or text-layout identity. |
| `sdfunc.c:InitFirstSofdec` | 176–179 | No-argument mwPlyPreInitSofdec adapter; middleware lifecycle only, not playback or decoder implementation. |
| `sdfunc.c:InitSofdecSystem` | 206–254 | Zeroes MWS_PLY_INIT_SFD, copies hws mode/frame/count, latency2 if any of five vertex counts negative else3; Mode0 InitMwSystem(0,&iprm), else ReinitMwSystem. SDK-facing framework policy, exact hws ownership retained. |
| `sdfunc.c:ExitSofdecSystem` | 257–263 | Calls ExitMwSystem only when MoviePlayTrayOpenFlag0; source tray/playback owner explicit, not unconditional shutdown equivalence. |
| `sdfunc.c:SearchAfsInsideFileId` | 517–538 | Scans borrowed global pSpqList at most1024 unsigned16 entries, stops FFFF sentinel with-1, returns first matching key index else-1. Reusable bounded lookup, sound-pack table ownership explicit, no shared resource-code identity. |
| `sdfunc.c:wadGetAngle` | 819–821 | Returns signed-short(Ang+(int)(10430.381f*atan2f(pos1.x-pos2.x,pos1.z-pos2.z))). Generic heading calculation, exact argument order/quantization matter. |
| `sdfunc.c:CheckPlayEndAdx` | 2174–2177 | Returns AdxPlayFlag[SlotNo] without normalization, fresh poll or index check. Middleware adapter over CVX global slot state; name alone does not prove end flag polarity. |
| `sdfunc.c:GetTimeAdx` | 2180–2183 | Forwards SlotNo to GetAdxPlayTime; no time-unit or owned elapsed-clock equivalence established here. |
| `sdfunc.c:ExecuteSoundCommand` | 2973–2988 | Loops current SoundCommand.MaxCommand, calls nonnull SdComFuncTbl[ComTbl[i]].FuncName(command), clears each queued command then MaxCommand0. No command-index bound; reentrant mutation safety not established. |
| `sdfunc.c:SendSoundCommand` | 2991–3001 | If MaxCommand!=2, appends command, increments then immediately ExecuteSoundCommand; rejects only exact2, not all>=2. Small framework dispatcher with CVX command table owner, no persistent queue/wait claim. |
| `sdfunc.c:RequestReadIsoFile` | 3031–3052 | Single-outstanding global file request: busy returns-1, open failure-1, otherwise request read, store destination and pending/status1. Independent from sound-bank schema. |
| `sdfunc.c:RequestReadInsideFile` | 3055–3076 | Same singleton request protocol for partition/member open; no second concurrent request admitted. |
| `sdfunc.c:GetIsoFileSize` | 3079–3082 | Forwards named size query to GD GetFileSize; no Outbreak size units or missing-file convention imported. |
| `sdfunc.c:GetInsideFileSize` | 3085–3105 | Opens AFS partition/member; negative returns0, else gets size and closes. The0 sentinel conflates failure/empty; handle/provider contract delegated. |
| `sdfunc.c:GetReadFileStatus` | 3108–3111 | Returns singleton FileReadStatus; not proof of fresh completion or a process-wide file-service ABI. |
| `sdfunc.c:ExecFileManager` | 3114–3135 | Checks tray; pending request cancels via StopAfs on tray or soft-reset, status-1; otherwise FileReadStatus1 plus nonzero CheckReadEnd clears pending/status0. Game soft-reset dependency explicitly retained. |
| `sdfunc.c:StopVibrationBasic` | 3409–3412 | Translates caller port to(PortNo*6)+2 then StopVibration; platform addressing adapter, not an Outbreak port numbering alias. |
| `sub1.c:PushPalletBuffer` | 9040–9045 | Copies1024 bytes global palbuf to palbuf+3072 using njMemCopy4, then palette mode6. Specific scratch/global ownership and mode ordering, no stacked push semantics. |
| `sub1.c:PopPalletBuffer` | 9048–9053 | Sets palette mode2 then copies1024 bytes palbuf+3072 back to palbuf. One fixed save area, no nested restoration or Ninja implementation identity. |
| `sub1.c:DrawPoly2D` | 9907–9951 | Four borrowed XY/colors/optionalUV into Ninja descriptor; selects global swork.subtx_list and caller texture, attr80000000 only when UV present. Framework draw adapter with CVX menu texture owner; no packet identity. |

## Owned comparison boundaries

| Family | Reviewed owned notes | Result |
| --- | --- | --- |
| flags | [ROOM_SCRIPT_BANK_RUNTIME](../SYMBOLS_ROOM_SCRIPT_BANK_RUNTIME.md) | CVX uses caller array/MSB-first; owned set/clear use fixed bank and1<<(ID&31), contextual query additionally selects bank. Bit0 CVX80000000 versus owned1 is an exact distinguishing witness. |
| renderer | [UI_RECTANGLE_GLYPH_PACKETS](../SYMBOLS_UI_RECTANGLE_GLYPH_PACKETS.md), [CUTSCENE_COLOR_OVERLAYS_AND_BARS](../SYMBOLS_CUTSCENE_COLOR_OVERLAYS_AND_BARS.md), [COMMON_UI_TEXTURE_BANKS](../SYMBOLS_COMMON_UI_TEXTURE_BANKS.md), [MODEL_TEXTURE_CACHE_LIFECYCLE](../SYMBOLS_MODEL_TEXTURE_CACHE_LIFECYCLE.md) | Ninja QUAD/NJS descriptors, scratch matrices, texture tables and renderer state are distinct from owned signed-half endpoint descriptor and3-QWC GS template/193E20 queue. Shared geometry/drawing concepts do not prove same ABI, canvas or lifetime. |
| math | [RENDER_MATH](../SYMBOLS_RENDER_MATH.md), [ACTOR_6F18A0_TURN_AND_RESTORE](../SYMBOLS_ACTOR_6F18A0_TURN_AND_RESTORE.md), [ACTOR_COMMAND_HEADING_AND_TURN_CLASSIFICATION](../SYMBOLS_ACTOR_COMMAND_HEADING_AND_TURN_CLASSIFICATION.md) | Owned matrix basis-only/full-matrix masks, radians/trig conventions, actor heading state and asymmetric wrapping differ or remain unbound. Pure CVX scalar/tree/triangle helpers have no demonstrated complete counterpart in these reviewed boundaries; no identical algorithms inferred from shared floats/NJS names. |
| framework | [LIBMC2_FILE_IO_AND_DIRECTORY_INSERTION](../SYMBOLS_LIBMC2_FILE_IO_AND_DIRECTORY_INSERTION.md), [CARD_PROFILE_BACKEND_STEPS](../SYMBOLS_CARD_PROFILE_BACKEND_STEPS.md), [CRI_SJUNI_LINKED_CHUNK_POOLS](../SYMBOLS_CRI_SJUNI_LINKED_CHUNK_POOLS.md) | BUP BACKUPINFO callbacks and circular64-byte callback nodes are not libmc2 requests or SJUNI16-byte borrowed-chunk nodes. Tree flags need same node layout/traversal/bit schedule; no Outbreak counterpart established. |
| file_facade | [CRI_BACKENDS](../SYMBOLS_CRI_BACKENDS.md), [CVFS_64BIT_FILE_SIZE_QUERY_ROUTES](../SYMBOLS_CVFS_64BIT_FILE_SIZE_QUERY_ROUTES.md), [CRI_FILE_STREAM_SECTOR_READ_SERVICE](../SYMBOLS_CRI_FILE_STREAM_SECTOR_READ_SERVICE.md) | CVX singleton request/status and GD/AFS facade differ from owned CVFS/ADXF per-handle asynchronous completion, bytes/sectors and size64 dispatch. Earlier stream/GD ledgers cover the actual lower providers; no new facade identity established. |
| text | [FONT_DRAW_CONTROLS](../SYMBOLS_FONT_DRAW_CONTROLS.md), [FONT_CODEPOINTS](../SYMBOLS_FONT_CODEPOINTS.md), [FONT_LAYOUT_RENDERERS](../SYMBOLS_FONT_LAYOUT_RENDERERS.md), [FONT_STORAGE_PACKETS](../SYMBOLS_FONT_STORAGE_PACKETS.md) | CVX16-bit FFFF-terminated controls and324-code texture pages/14px atlas/28px geometry are specific framework contracts. Owned font contexts, multibyte codepoint processing, packet layouts and glyph metrics are separately mapped; no complete same-format counterpart demonstrated. |
| middleware | [SOFDEC_GLOBAL_PROVIDER_LIFECYCLE_AND_STATISTIC_ACCUMULATION](../SYMBOLS_SOFDEC_GLOBAL_PROVIDER_LIFECYCLE_AND_STATISTIC_ACCUMULATION.md), [SOFDEC_GLOBAL_LIFECYCLE_ERROR_RECORDS_AND_CRITICAL_SECTIONS](../SYMBOLS_SOFDEC_GLOBAL_LIFECYCLE_ERROR_RECORDS_AND_CRITICAL_SECTIONS.md) | Small CVX lifecycle/status/port adapters retain hws, MoviePlayTrayOpenFlag and AdxPlayFlag ownership. They do not expose CRI implementations or prove Outbreak slot counts, time units, cancellation/initialization policy or port translation. |

Four original complete intervals were freshly read and hashed as data: `o2:00570370`, `o2:005703A0`, `o2:007008C0`, `main:001ABB60` (**216 words** total). Their interval bounds/hashes are in the receipt; other candidate boundaries cite existing full-body notes. Main ELF SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`; owned o2 image SHA-256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. No guest payload was executed.

## Reproduce and remaining limits

[Checker](../../tools/function_index/review_recvx_extra_utilities_complete_scope.py) reads the clean pinned source and frozen first ten scope identities, checks every raw source/body hash against the shared manifest, rebuilds this report and the [per-function receipt](../../build-function-index/recvx-extra-utilities-complete-scope.json), and checks original interval identities. Run `python tools/function_index/review_recvx_extra_utilities_complete_scope.py`. It writes only its own receipt/report.

The actor eligibility screen and transferred sound adapters have independent ledgers. Declarations, unavailable platform bodies and 223 ASM placeholders remain governed by the reference-availability audit. A scoped no-counterpart result is limited to the documented owned families; it is not a whole-binary absence proof. Reference defects or unguarded domains are static observations, not reproduced Outbreak bugs or measured slowdown causes.
