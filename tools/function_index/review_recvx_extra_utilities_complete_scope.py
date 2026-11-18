"""Function-level static eligibility screen of the non-actor CVX remainder.

Only admitted utility/framework definitions enter files[].functions. The
separate eligibility_screen retains every excluded body and its actual source
dependencies; exclusion is an applicability decision, never equivalence proof.
No original/generated/runtime/index mutation or guest execution.
"""
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import subprocess

from index import ROOT, Elf, ELF_SHA
from recvx_scope_inventory import PIN, function_records, mask
from reconcile_recvx_complete_scope import SCOPES, normalized_records

REF=Path('C:/Users/Ninjacornix/AppData/Local/Temp/reo-recvx-crosscheck-20261104')
OUT=ROOT/'build-function-index/recvx-extra-utilities-complete-scope.json'

# Each entry follows a complete-body inspection, including failure/edge paths.
# No entries below assert a recovered one-to-one Outbreak symbol identity.
ADMIT={
'flag.c':{
'bhStFlg':'Caller-owned32-bit array, OR0x80000000>>(bit&31) in word bit/32; MSB-first, no bounds guard.',
'bhCrFlg':'Caller-owned32-bit array, AND complement of0x80000000>>(bit&31); MSB-first, no bounds guard.',
'bhCkFlg':'Returns raw masked word, not normalized boolean; same MSB-first caller-owned indexing.',
},
'door.c':{
'CompareSint32':'Selector-1:>=;0:==;1:<=;±2:!=. Other selectors leave ret uninitialized; dead if(0) does not initialize it.',
'CompareFloat':'Same admitted selector relation as CompareSint32, including ordered/NaN semantics; unsupported selectors leave ret uninitialized.',
'VectorMove':'Resets global lcmat, copies position into translation, rotatesY(yaw) thenX(pitch), translates along negativeZ by speed, copies translation out. Shared matrix side effect.',
'ryExcuteFade':'Static640x480 quad and colors; scales packed RGBA using int(256*rate), draws only nonzero alpha, sets Ninja blend8/6 and attr96. State and narrowing differ from owned rectangle emitters.',
},
'adv.c':{
'GetSamurai':'Returns reciprocal of integer expression(Time/100)*30+((Time%100)*6)/10. Integer truncation precedes float conversion; zero denominator unguarded; packed-time unit remains qualified.',
'AdvGetResourcePtr':'Returns bp+((int*)bp)[ResId], no table/span validation; reusable relative-offset lookup, not archive format identification.',
'AdvDrawFadePolygon':'Static quad(-2,-2)..(642,482); depth table[Type]={.98,.90,1.99,1.98}; OR quantized alpha into BaseColor, Ninja polygon attr1; no Type bound.',
'SetPvrInfo':'TIM2 picture format reset0; gindex and picture metadata at+128 feed texture-info/name constructors with attributes40800000. Extra C parameters unused in body; no whole-file validation.',
'TransPvpData':'Checks four-byte PVPL tag, else-1; reads category/bank, optionally sets palette mode and returns signed bank. It does not upload palette payload here.',
'AdvTransShadowPalette':'Allocates64 aligned32, initializes first word00FFFFFF and remaining15 wordsFF000000, sets palette16/count16 then releases. Allocation/transfer lifetime delegated.',
'AdvEasyDrawWindow':'Four border quads: top/bottom4px,left3px,right3px offsetright-4; then interior fill with depth-.001; Ninja state/draw wrappers, not owned packet ABI.',
'AdvEasyDrawTexture':'Optionally OR8000 into current TIM2 ClutChange; starts quad mode, selects texture/color, draws caller QUAD/depth, ends. Mutates texture metadata/render state.',
'AdvEasyDrawTextureS':'Draws original first; copies32-byte QUAD to global Qtex15, offsets XY+3, draws shadow alpha<<24 at depth-.001 in trans mode1. Global scratch and draw order matter.',
'SetQuadPos':'Sets inclusive endpoints start+(size-1), caller QUAD; no clipping or size validation.',
'SetQuadUv2Ex':'Uses AdvTexList selected NJS_TEXMEMLIST dimensions, divides negative dimensions by3, normalizes UV and size-1 endpoints. Index/zero dimensions unguarded; framework table ownership explicit.',
'SetQuadUv2':'List0 adapter to SetQuadUv2Ex; same texture-table and denominator contract.',
'AdvDwawOnePictureEx':'Global Qtex, filter1, fixed1024x512 position/UV, draw at.01, filter0. Framework fullscreen adapter; fixed canvas is not Outbreak screen identity.',
'AdvDwawOnePicture':'Forwards to AdvDwawOnePictureEx with BaseColor=-1; fixed canvas/global state retained.',
'AdvEasySetupTextureBasic':'Two relative offsets select optional PVPL and TIM2; records AdvWork PalNo/PalFlag and per-list palette bank then SetPvrInfo. This is a CVX texture framework object, not a universal resource layout.',
'AdvEasySetupTextureEx':'Uses AdvWork.ptr[Count], selected list and Count as texture index, then increments Count. No count bound.',
'AdvEasySetupTexture':'List0 adapter to setupEx; framework ownership, not a new texture-loader identity.',
'AdvEasySetTextureList':'Selects AdvTexList[ListNo] then texture0. Mutable Ninja binding and unchecked list index.',
'AdvEasyTransTextureBasic':'Publishes texture count, loads/selects list; Flag0 frees Adv memory, then Count0/SetTexture[list]1. Delegated success and retained payload lifetime not guaranteed.',
'AdvEasyTransTextureEx':'Uses AdvWork.Count and Flag0 for selected list; same load/free/state contract.',
'AdvEasyTransTexture':'List0 adapter to TransTextureEx; no independent transfer completion proof.',
'AdvEasyReleaseTextureEx':'If SetTexture[list] nonzero releases list and clears flag, always calls bhGarbageTexture(NULL,0); no reference-count equivalence asserted.',
'AdvEasyReleaseTexture':'List0 adapter to releaseEx; same renderer/cache side effects.',
},
'backup.c':{
'BupInit':'Zeroes global BACKUPINFO then buInit(MAX_CAPS,USE_DRIVES,0,BupInitCallback); generic BUP wrapper, not Outbreak libmc2 ABI.',
'BupExit':'Calls buExit repeatedly until OK; no timeout/admission guard. Synchronous busy-loop behavior retained.',
'ClearInfo':'Clears selected drive progress/operation/readiness/format/work and disc information fields; no CVX save payload/schema consumed.',
'BupComplete':'Connect/mount/unmount/save/load completion callback updates BACKUPINFO; unmount frees nonnull MemMode0 work, drive info/errors follow distinct operation branches, operation cleared. BUP enums/layout not shared by assumption.',
'BupProgress':'Stores drive operation/count/max in BACKUPINFO and returns BUD_CB_RET_OK; no save format or UI work.',
'BupInitCallback':'Registers BupComplete and BupProgress with BUP platform; platform implementations absent from this unit.',
},
'cut.c':{'bhCheckCutAreaInnerTriangle':'AABB plus atr_tp1..4 half-triangle test from caller CUT_WRK XZ bounds; fabs/division edge behavior, unsupported type uninitialized locals and degenerate denominator retained. No room/global lookup in body.'},
'itemview.c':{
'MdlDirChk':'Step0 returns1; updates local mdlang modulo65536, subtracts target and compares unsigned wrapped difference with signed short step*2. No normalized shortest-angle replacement admitted.',
'MdlHideCheck':'Recursive child/sibling NJS_CNK_OBJECT flag8 setter using by-value unsigned-char el/chk. chk doubles per recursive edge including siblings; local clearing feeds both calls, but child-call mutations are not returned to the subsequent sibling call. Not one shared preorder bit counter.',
'FlagErase':'Recursively clears evalflags bits2 and1 on root, child and sibling; no game globals or authored node indices. Null root/cycles not admitted.',
},
'light.c':{'bhGetLightVector':'Resets Ninja current matrix, appliesZ(zr),Y(yr),X(xr), transforms fixed(0,0,-1) into vec. Mutates current matrix; angle units/call convention not inherited by owned VU math.'},
'message.c':{
'bhDispFont':'Ninja glyph facade over sys->ef_tlist:324 codes/page,18x18 atlas14px cells drawn28px scaledXY; fixed five palette choices, blend8/6, texture filter0. CVX atlas/owner is explicit, not Outbreak glyph encoding.',
'bhDispFontEx':'Same324/page18x18 glyph geometry/UV as bhDispFont, caller packed ARGB instead of palette selector. Render state left changed; no admission for negative code.',
'bhGetFontSize':'Unsigned code>=108 returns0, else FontSz[code]. CVX asset-width table, not a universal font API/result unit.',
'bhMesLen':'Unsigned16 stream to FFFF, ignoresFF00/FF04/FE00..FE0F, FF01 adds14*FontScaleX, FF02/03 skip next word; other code adds scaled FontSz width. No stream-length bound; distinct CVX control format.',
'bhFontScaleSet':'Sets global FontScaleX/Y/CR from three float arguments. Framework setter, not a portable output-packet or text-layout identity.',
},
'map.c':{
'MapFuncInit':'Allocates(func_num+2)*64, global mwP busy/free circular sentinels, inserts free nodes. Generic callback framework inside map owner; no topology/schema equivalence.',
'MapFuncAlloc':'Removes free-head next, inserts busy, writes callback/mode/param and clears remaining parameters/nine workwords. No empty-free-list admission check.',
'MapFuncFree':'Unlinks and inserts into global mwP free list. Caller owns valid membership; no duplicate-free guard.',
'MapFuncDel':'Intrusive doubly-linked unlink updates neighbors; self links retained. Requires valid neighbors, no NULL/cycle checks.',
'MapFuncIns':'Intrusive insert after base; declared pointer return but no explicit return statement. Do not invent a usable returned node.',
'MapFuncExec':'Walks busy list, saves next before optional callback; current unlink accommodated, unrestricted mutation safety not proved.',
'MapDrawLine2':'Static2-point/color descriptor, copies XY and palette, Ninja line count1 attr40, no rounding.',
'MapDrawLine':'Same line facade but floor(XY+.5) and attr0; not interchangeable with MapDrawLine2.',
'MapDrawFill':'Builds static four-point rectangle from endpoints then MapDrawPolyFill; no clipping.',
'MapDrawPolyFill':'Borrows caller points in static four-point descriptor, repeats packed color, Ninja polygon attr60. Not same descriptor/packet as Outbreak.',
'MapCnvArgb2Color':'Multiplies float ARGB channels by255 into byte components without explicit clamp. Conversion and exceptional domain not silently normalized.',
},
'sdfunc.c':{
'SearchAfsInsideFileId':'Scans borrowed global pSpqList at most1024 unsigned16 entries, stops FFFF sentinel with-1, returns first matching key index else-1. Reusable bounded lookup, sound-pack table ownership explicit, no shared resource-code identity.',
'ExecuteSoundCommand':'Loops current SoundCommand.MaxCommand, calls nonnull SdComFuncTbl[ComTbl[i]].FuncName(command), clears each queued command then MaxCommand0. No command-index bound; reentrant mutation safety not established.',
'SendSoundCommand':'If MaxCommand!=2, appends command, increments then immediately ExecuteSoundCommand; rejects only exact2, not all>=2. Small framework dispatcher with CVX command table owner, no persistent queue/wait claim.',
'InitFirstSofdec':'No-argument mwPlyPreInitSofdec adapter; middleware lifecycle only, not playback or decoder implementation.',
'InitSofdecSystem':'Zeroes MWS_PLY_INIT_SFD, copies hws mode/frame/count, latency2 if any of five vertex counts negative else3; Mode0 InitMwSystem(0,&iprm), else ReinitMwSystem. SDK-facing framework policy, exact hws ownership retained.',
'ExitSofdecSystem':'Calls ExitMwSystem only when MoviePlayTrayOpenFlag0; source tray/playback owner explicit, not unconditional shutdown equivalence.',
'CheckPlayEndAdx':'Returns AdxPlayFlag[SlotNo] without normalization, fresh poll or index check. Middleware adapter over CVX global slot state; name alone does not prove end flag polarity.',
'GetTimeAdx':'Forwards SlotNo to GetAdxPlayTime; no time-unit or owned elapsed-clock equivalence established here.',
'StopVibrationBasic':'Translates caller port to(PortNo*6)+2 then StopVibration; platform addressing adapter, not an Outbreak port numbering alias.',
'wadGetAngle':'Returns signed-short(Ang+(int)(10430.381f*atan2f(pos1.x-pos2.x,pos1.z-pos2.z))). Generic heading calculation, exact argument order/quantization matter.',
'RequestReadIsoFile':'Single-outstanding global file request: busy returns-1, open failure-1, otherwise request read, store destination and pending/status1. Independent from sound-bank schema.',
'RequestReadInsideFile':'Same singleton request protocol for partition/member open; no second concurrent request admitted.',
'GetIsoFileSize':'Forwards named size query to GD GetFileSize; no Outbreak size units or missing-file convention imported.',
'GetInsideFileSize':'Opens AFS partition/member; negative returns0, else gets size and closes. The0 sentinel conflates failure/empty; handle/provider contract delegated.',
'GetReadFileStatus':'Returns singleton FileReadStatus; not proof of fresh completion or a process-wide file-service ABI.',
'ExecFileManager':'Checks tray; pending request cancels via StopAfs on tray or soft-reset, status-1; otherwise FileReadStatus1 plus nonzero CheckReadEnd clears pending/status0. Game soft-reset dependency explicitly retained.',
},
'sub1.c':{
'DrawPoly2D':'Four borrowed XY/colors/optionalUV into Ninja descriptor; selects global swork.subtx_list and caller texture, attr80000000 only when UV present. Framework draw adapter with CVX menu texture owner; no packet identity.',
'PushPalletBuffer':'Copies1024 bytes global palbuf to palbuf+3072 using njMemCopy4, then palette mode6. Specific scratch/global ownership and mode ordering, no stacked push semantics.',
'PopPalletBuffer':'Sets palette mode2 then copies1024 bytes palbuf+3072 back to palbuf. One fixed save area, no nested restoration or Ninja implementation identity.',
},
}

# Bounded comparison candidates, not aliases. Original instruction evidence is
# captured below; broader library notes supply additional rejected candidates.
GROUPS={
'flags':{'files':['flag.c'],'notes':['SYMBOLS_ROOM_SCRIPT_BANK_RUNTIME.md'],'ids':['o2:0x00570370','o2:0x005703A0','o2:0x007008C0'],'comparison':'CVX uses caller array/MSB-first; owned set/clear use fixed bank and1<<(ID&31), contextual query additionally selects bank. Bit0 CVX80000000 versus owned1 is an exact distinguishing witness.'},
'renderer':{'files':['adv.c','map.c','sub1.c','door.c'],'notes':['SYMBOLS_UI_RECTANGLE_GLYPH_PACKETS.md','SYMBOLS_CUTSCENE_COLOR_OVERLAYS_AND_BARS.md','SYMBOLS_COMMON_UI_TEXTURE_BANKS.md','SYMBOLS_MODEL_TEXTURE_CACHE_LIFECYCLE.md'],'ids':['main:0x001ABB60'],'comparison':'Ninja QUAD/NJS descriptors, scratch matrices, texture tables and renderer state are distinct from owned signed-half endpoint descriptor and3-QWC GS template/193E20 queue. Shared geometry/drawing concepts do not prove same ABI, canvas or lifetime.'},
'math':{'files':['cut.c','itemview.c','light.c','sdfunc.c','door.c'],'notes':['SYMBOLS_RENDER_MATH.md','SYMBOLS_ACTOR_6F18A0_TURN_AND_RESTORE.md','SYMBOLS_ACTOR_COMMAND_HEADING_AND_TURN_CLASSIFICATION.md'],'ids':[],'comparison':'Owned matrix basis-only/full-matrix masks, radians/trig conventions, actor heading state and asymmetric wrapping differ or remain unbound. Pure CVX scalar/tree/triangle helpers have no demonstrated complete counterpart in these reviewed boundaries; no identical algorithms inferred from shared floats/NJS names.'},
'framework':{'files':['backup.c','map.c','itemview.c'],'notes':['SYMBOLS_LIBMC2_FILE_IO_AND_DIRECTORY_INSERTION.md','SYMBOLS_CARD_PROFILE_BACKEND_STEPS.md','SYMBOLS_CRI_SJUNI_LINKED_CHUNK_POOLS.md'],'ids':[],'comparison':'BUP BACKUPINFO callbacks and circular64-byte callback nodes are not libmc2 requests or SJUNI16-byte borrowed-chunk nodes. Tree flags need same node layout/traversal/bit schedule; no Outbreak counterpart established.'},
'file_facade':{'files':['sdfunc.c'],'notes':['SYMBOLS_CRI_BACKENDS.md','SYMBOLS_CVFS_64BIT_FILE_SIZE_QUERY_ROUTES.md','SYMBOLS_CRI_FILE_STREAM_SECTOR_READ_SERVICE.md'],'ids':[],'comparison':'CVX singleton request/status and GD/AFS facade differ from owned CVFS/ADXF per-handle asynchronous completion, bytes/sectors and size64 dispatch. Earlier stream/GD ledgers cover the actual lower providers; no new facade identity established.'},
'text':{'files':['message.c'],'notes':['SYMBOLS_FONT_DRAW_CONTROLS.md','SYMBOLS_FONT_CODEPOINTS.md','SYMBOLS_FONT_LAYOUT_RENDERERS.md','SYMBOLS_FONT_STORAGE_PACKETS.md'],'ids':[],'comparison':'CVX16-bit FFFF-terminated controls and324-code texture pages/14px atlas/28px geometry are specific framework contracts. Owned font contexts, multibyte codepoint processing, packet layouts and glyph metrics are separately mapped; no complete same-format counterpart demonstrated.'},
'middleware':{'files':['sdfunc.c'],'notes':['SYMBOLS_SOFDEC_GLOBAL_PROVIDER_LIFECYCLE_AND_STATISTIC_ACCUMULATION.md','SYMBOLS_SOFDEC_GLOBAL_LIFECYCLE_ERROR_RECORDS_AND_CRITICAL_SECTIONS.md'],'ids':[],'comparison':'Small CVX lifecycle/status/port adapters retain hws, MoviePlayTrayOpenFlag and AdxPlayFlag ownership. They do not expose CRI implementations or prove Outbreak slot counts, time units, cancellation/initialization policy or port translation.'},
}

OWNER=re.compile(r'\b(?:sys|rom|cam|plp|swork|fvwork|AdvWork|McState|MovieInfo|RequestInfo|Pad|PDD_PERIPHERAL|ADV_WORK|BH_PWORK|O_WORK|O_WRK|LGT_WORK|LGT_WK|CUT_WORK|CUT_WRK|CAM_WRK|CAM_WORK|CAM_KEYF_WORK|S_WORK|SCD_WORK|_door_wrk|MEMORYCARDSTATE|SELECTFILEWINDOW|SAVEFILE|CONFIGFILE|SELECTFILEINFO|LOAD_SCREEN|SAVE_SCREEN|SYSSAVE_SCREEN|SYSLOAD_SCREEN|ROOM|RDT_WORK|EV_WORK|EVT_WORK|DOOR_WORK|NJS_CNK_OBJECT|PARTS|PULSE_WORK|FADE|FILEVIEW_WORK|mwP|bhScePtr|bhEtask|bhCetask|bhIfelFlg|G_Sp|bhScenarioJmpT|Event_T_timer|pulsework|cen_pos99|cen_pos|parts_07b|fade|pSpqList|ThreeDVolTbl|PanTbl360|PanTbl360Vol|CurrentRoomFxLevel|EnemySeInfo|ObjectSeInfo|RoomSoundInfo|SoundComInfo|SpqFile|mesdeftbl|mesdeftbl2|mesdeftbl3|FontSz|FontScaleX|FontScaleY|FontScaleCR)\b')
CONTROL={'if','for','while','switch','sizeof','return','do'}

RETAIN={
'RoomNameSwitch':'Hardcoded conversion of CVX room numbers0/108/311/500/.../921/604 into menu slots; not a generic integer switch utility.',
'bhChangeClipVolume':'Uses stage-indexed authored VIEW_CLIP tables and room/rcase/event IDs, including fixed stage3/5/6/9 overrides; generic _Make_ClipVolume is separately scoped.',
'CameraInit':'Initializes global item-view st_cam with authored distance20/positionZ12 and camera fields; no caller-owned generic camera structure.',
'CameraSet':'Consumes global item-view st_cam and resets Ninja current matrix to its specific translate/XYZ/translate camera recipe.',
'LighterOpen':'Authored item pose sets one model angleZ29127; no general model-transform utility.',
'FileSyu':'Authored file-item pose writes32768 into root and exactly two sibling angle fields; fixed node topology, not recursive generic transform.',
'ModelScaleSet':'Item model/UI policy chooses1.52 or1.84 divided by size based on specific item IDs1/2/3/4/6/10/11/103.',
'FsubZoomScreen':'Authored map-frame overlay: hardcoded ScrIn(56,64)..(585,417), canvas640x480, radius32, map colors/depths and scripted polygon construction. Shared draw primitives carved separately.',
'FsubCompass':'Authored map compass four-vertex arrow, fixed585/62 location and per-callback1456 rotation; generic Ninja transforms are in existing library scope.',
'MapGetFloorNo':'Searches typed FT_WRK labels using100*room+height and returns packed map/floor fields; CVX map table/header schema, not a generic binary-search identity.',
'MapCnc':'CVX map/floor topology links with special floors2560/512 and authored AdjMapA64/128/832; numeric overrides prevent generic graph identity.',
'MapCncConnect':'FFFF-terminated map pair/control stream, FF control high byte changes state via CVX flagbank8, then MapCnc topology mutation.',
'bhDispTime':'Formats60-count time but branches on sys->gm_mode3 and CVX glyph IDs/cap59:59.99; game mode policy retained.',
'bhDispTimeEx':'Same CVX mode-dependent time cap/glyph layout with caller ARGB; owned text helpers do not establish this game policy.',
'bhDrawScopeNumber':'Authored scope digit/symbol atlas18 entries and fixed16x16 render geometry/depth; Ninja polygon primitive separately scoped.',
'bhDrawThermoNumber':'Authored thermometer digit atlas10 entries and fixed16x16 destination from32x48 source cells; no generic numeric-format algorithm.',
'bhDrawSpEvtComVal':'Authored special-event glyph texture2, fixed atlas204/208 and16x24 cell arithmetic, colorFFC0C0C0/depth.15.',
'CheckCollision4Sound':'Uses rom->flg, global camera world position, game wall-capsule query and fixed radius.1/penalty-28; game spatial policy.',
'Get3DSoundParameter':'Uses global camera matrix/yaw, ThreeDVolTbl/PanTbl360/PanTbl360Vol and CurrentRoomFxLevel; source distance/quantization policy retained rather than generic spatial-audio equivalence.',
'Combi_01':'CVX inventory packed item IDs/ammunition flags, item-specific300/999 capacities and combidata table; arithmetic is subordinate to game schema.',
'Combi_04':'CVX packed item/ammo counts plus combidata[ps+1] replacement IDs and128/1/2 result bits; not generic subtraction utility.',
'bhCalcVtxBuffer':'Constant0 placeholder with no vertex allocation/count calculation; no reusable implemented algorithm to admit.',
}

def groups_for(file,symbol):
    if file=='flag.c':return ['flags']
    if file=='adv.c':return ['math']if symbol=='GetSamurai'else ['framework']if symbol=='AdvGetResourcePtr'else ['renderer']
    if file=='door.c':return ['renderer']if symbol=='ryExcuteFade'else ['math']
    if file=='map.c':return ['framework']if symbol.startswith('MapFunc')else ['renderer']
    if file=='message.c':return ['text']
    if file=='backup.c':return ['framework']
    if file=='sdfunc.c':
        if symbol=='wadGetAngle':return ['math']
        if symbol in ('RequestReadIsoFile','RequestReadInsideFile','GetIsoFileSize','GetInsideFileSize','GetReadFileStatus','ExecFileManager'):return ['file_facade']
        return ['middleware']
    if file=='sub1.c':return ['renderer']
    return ['math','framework']if file=='itemview.c'else ['math']

def actor_file(name):
    return name.startswith(('en','effsub','zonzon')) or name in ('player.c','playpch.c','playpch2.c','pl_evt.c','subpl.c','weapon.c','pwksub.c','effect.c')

def digest(b):return hashlib.sha256(b).hexdigest()

def main():
    git=lambda *a:subprocess.check_output(['git','-C',str(REF),*a],text=True,encoding='utf-8').strip()
    assert git('rev-parse','HEAD')==PIN and not git('status','--porcelain','--untracked-files=no')
    inventory=json.loads((ROOT/'build-function-index/recvx-complete-source-inventory.json').read_text())
    seen=set()
    for _,name,_ in SCOPES[:10]:
        for r,p in normalized_records(json.loads((ROOT/'build-function-index'/name).read_text())):
            seen.add((r.get('reference_file',r.get('file',p)),r['symbol'],r.get('start_line',r.get('line_start'))))
    all_records=[];by_symbol=defaultdict(list);texts={};source_meta={}
    for f in inventory['files']:
        raw=(REF/f['path']).read_bytes();assert digest(raw)==f['sha256']
        text=raw.decode('utf-8-sig',errors='replace');texts[f['path']]=text;source_meta[f['path']]=f
        expected={(r['symbol'],r['start_line']):r for r in f['functions']}
        for r in function_records(text):
            assert r['body_sha256']==expected[r['symbol'],r['start_line']]['body_sha256']
            body=text[r['body_start']:r['body_end_offset']];header=text[r['header_start']:r['body_start']]
            clean=mask(body);calls=sorted(set(re.findall(r'\b([A-Za-z_]\w*)\s*\(',clean))-CONTROL)
            rec={k:v for k,v in r.items() if k!='masked_body'}
            rec.update(reference_file=f['path'],source_header=header.strip(),complete_reference_body=body,source_calls=calls,
                       source_member_names=sorted(set(re.findall(r'(?:->|\.)\s*([A-Za-z_]\w*)',clean))),
                       direct_ownership_tokens=sorted(set(OWNER.findall(header+'\n'+clean))),
                       raw_source_line_span_sha256=digest(b''.join(raw.splitlines(keepends=True)[r['start_line']-1:r['end_line']])))
            all_records.append(rec);by_symbol[r['symbol']].append(rec)
    callers=defaultdict(list)
    for r in all_records:
        for callee in r['source_calls']:
            callers[callee].append({'file':r['reference_file'],'symbol':r['symbol'],'start_line':r['start_line']})
    remaining=[];initial_nonactor=[];actor_identities=[]
    for r in all_records:
        identity=(r['reference_file'],r['symbol'],r['start_line']);name=Path(r['reference_file']).name
        if identity in seen:continue
        if actor_file(name):
            actor_identities.append({'file':r['reference_file'],'symbol':r['symbol'],'start_line':r['start_line']});continue
        initial_nonactor.append({'file':r['reference_file'],'symbol':r['symbol'],'start_line':r['start_line']})
        if name in ('sdc.c','sdcwrap.c'):continue
        r['source_callers']=callers[r['symbol']]
        r['callee_ownership_evidence']=[{'symbol':c,'file':v['reference_file'],'tokens':v['direct_ownership_tokens']}for c in r['source_calls']for v in by_symbol.get(c,[]) if v['direct_ownership_tokens']]
        r['applicability']='admitted-extra-utility' if r['symbol'] in ADMIT.get(name,{}) else 'retained-cvx-integration'
        r['outbreak_ids']=[]
        if r['applicability']=='admitted-extra-utility':
            r['disposition']='compared-bounded-framework-or-algorithm-no-identity'
            r['comparison']=ADMIT[name][r['symbol']]
            r['comparison_groups']=groups_for(name,r['symbol'])
            r['search_boundary']='Complete pinned body, typed/global ownership and source callers; named owned candidate families in comparison_groups. No all-binary absence proof or new equivalence alias.'
        else:
            r['disposition']='source-unimplemented-integration' if r['implementation_shape']!='nonempty' else 'game-integration-ownership-boundary'
            evidence=('Direct owner/type references: '+', '.join(r['direct_ownership_tokens']))if r['direct_ownership_tokens']else ('Delegated owner references: '+', '.join(sorted({x['symbol']for x in r['callee_ownership_evidence']})))if r['callee_ownership_evidence']else ('Exact dependencies: '+', '.join(r['source_calls'])+'; accessed fields: '+', '.join(r['source_member_names']))
            r['comparison']=RETAIN.get(r['symbol'],'CVX integration retained after function-level eligibility screen. '+evidence+'. Complete body/header/callers attached; this applicability decision is not equivalence or a no-shared-instructions proof.')
            r['search_boundary']='Full source dependency screen; generic signature alone is insufficient. Pure/math/framework exceptions explicitly admitted, even inside these same files.'
        remaining.append(r)
    assert len(remaining)==1045,len(remaining)
    assert len({r['reference_file'] for r in remaining})==28
    admitted=[r for r in remaining if r['applicability']=='admitted-extra-utility']
    assert len(admitted)==sum(map(len,ADMIT.values()))
    files=[]
    for path in sorted({r['reference_file']for r in admitted}):
        files.append({'path':path,'sha256':source_meta[path]['sha256'],'functions':[r for r in admitted if r['reference_file']==path]})
    # Static receipts of complete original intervals. Other candidates are
    # bounded by existing full-body notes, without silently widening this audit.
    owned=[];db=sqlite3.connect(f'file:{ROOT.as_posix()}/build-function-index/index.sqlite?mode=ro',uri=True)
    elf=Elf(ROOT/'game_data/SLUS_207.65');o2=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
    assert digest(o2)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    for image,start in [('o2',0x570370),('o2',0x5703A0),('o2',0x7008C0),('main',0x1ABB60)]:
        end,source=db.execute('select end,source from functions where image=? and start=?',(image,start)).fetchone()
        data=elf.read(start,end-start)if image=='main'else o2[start-0x570000:end-0x570000]
        assert len(data)==end-start
        owned.append({'image':image,'start':f'0x{start:08X}','end_exclusive':f'0x{end:08X}','word_count':len(data)//4,'sha256':digest(data),'source':source})
    db.close()
    for group in GROUPS.values():
        for note in group['notes']:assert (ROOT/'docs'/note).exists(),note
    data={'schema':1,'reference_commit':PIN,'original_elf_sha256':ELF_SHA,
          'method':'Complete per-function source eligibility screen, followed by manually supported utility/framework carve-outs; no filename-only equivalence/exclusion proof.',
          'scope':{'screened_definitions':len(remaining),'screened_files':28,'admitted_definitions':len(admitted),'retained_integration_definitions':len(remaining)-len(admitted),'initial_nonactor_definitions':len(initial_nonactor),'transferred_sound_adapters':57,'actor_scope_separate':len(actor_identities)},
          'initial_nonactor_identities':initial_nonactor,'actor_split_identities':actor_identities,
          'comparison_groups':GROUPS,'original_interval_receipts':owned,'files':files,
          'eligibility_screen':remaining,'screen_counts_by_file':dict(Counter(Path(r['reference_file']).name for r in remaining)),
          'admitted_counts_by_file':dict(Counter(Path(r['reference_file']).name for r in admitted))}
    OUT.write_text(json.dumps(data,indent=2,ensure_ascii=True)+'\n',encoding='utf-8')
    lines=['# Function-level audit of the non-actor exclusions','',
           'Static reference applicability review, 2026-11-05. Pinned Code Veronica source commit `'+PIN+'`. No game, build, replay, guest execution, process attachment, memory read or runtime/native changes. This report is an eligibility and bounded contract audit, not proof that all game code is unique or that every admitted helper has an Outbreak equivalent.','',
           'The original remaining corpus partition is explicit by `(file, symbol, start_line)` in the receipt: **1,102 non-actor definitions** and **1,850 actor definitions**. The 57 definitions in `sdc.c`/`sdcwrap.c` were transferred to the separate sound-adapter audit. This report screens the other **1,045 definitions in 28 files**, admits **'+str(len(admitted))+' utilities/framework adapters**, and retains **'+str(len(remaining)-len(admitted))+' CVX integration definitions**. The two previously admitted `sub1.c` platform functions are already in the availability ledger and are not duplicated.','',
           'Every screened definition retains its complete source header/body, original parser bounds/body SHA-256, raw line-span hash, file SHA-256, calls, source callers, member accesses and concrete owner/type references. Signatures with scalar/array/NJS arguments are leads, not automatic equivalence. Complete candidate bodies and their callers were checked for hidden state, data formats, authored node/room/item identifiers, and edge behavior. `eligibility_screen` contains all 1,045 records; only admitted records appear in `files[].functions`, so exclusions cannot inflate compared coverage.','',
           'Owner-token extraction and call relationships support a repeatable screen; they do not prove a function cannot be generalized or that no equal instruction sequence exists elsewhere. The retained cases have source applicability dispositions, rather than newly recovered Outbreak purposes. Empty handlers and constant placeholders are kept separately from implemented utility contracts.','',
           '## What changed','',
           'Filename-only exclusions missed actual reusable bodies. The admitted set includes MSB-first bit arrays; selector comparisons with undefined unsupported-selector returns; matrix movement/direction helpers; a half-triangle predicate; caller-model tree flag walks; quads, palettes, PVPL/TIM2 setup, glyph layout and width parsing; BUP callbacks; a circular callback pool; singleton file requests; and small middleware/command adapters. Global ownership is stated even when the algorithm is reusable. This pass adds **no Outbreak alias, mapping row or runtime fix**.','',
           'The exact checked flag candidates are materially different: CVX bit0 is `0x80000000`, whereas the owned set/clear routines use `1 << (ID & 31)` in a fixed bank; the owned contextual query also selects a bank. A raw nonzero return does not erase the bit-numbering or ownership difference. The renderer comparison likewise distinguishes Ninja floating-point descriptors/state from Outbreak signed-half endpoints, GS packet templates and queue publication.','',
           'Several tempting generic signatures remain integration: `RoomNameSwitch` hardcodes CVX rooms; `Combi_01/04` operate packed inventory IDs/ammo policy; `LighterOpen`/`FileSyu` edit authored nodes; `FsubZoomScreen`/`FsubCompass` draw authored map widgets; `bhDispTime/Ex` have game-mode-specific caps; `bhChangeClipVolume` uses stage/room/event overrides; `Get3DSoundParameter` depends on camera and room-specific attenuation tables. Conversely, `MdlHideCheck`/`FlagErase` and the callback pool are admitted despite living in those same game files.','',
           '## Exact screened boundary','',
           '| Source file | Screened | Admitted | Retained integration | Raw source SHA-256 |','| --- | ---: | ---: | ---: | --- |']
    for path in sorted({r['reference_file']for r in remaining}):
        count=sum(r['reference_file']==path for r in remaining);n=sum(r['reference_file']==path for r in admitted)
        lines.append('| `'+path+'` | '+str(count)+' | '+str(n)+' | '+str(count-n)+' | `'+source_meta[path]['sha256']+'` |')
    lines+=['','## Admitted complete-body contracts','',
            'These are additional eligible reference units with bounded comparisons or scoped unmatched results. They are not 76 proven equivalents and do not raise the fixed Outbreak function denominator. Each receipt record links its exact comparison group and evidence boundary.','',
            '| Reference definition | Full source lines | Contract and limits |','| --- | --- | --- |']
    for r in admitted:
        lines.append('| `'+Path(r['reference_file']).name+':'+r['symbol']+'` | '+str(r['start_line'])+'–'+str(r['end_line'])+' | '+r['comparison'].replace('|','\\|')+' |')
    lines+=['','## Owned comparison boundaries','',
            '| Family | Reviewed owned notes | Result |','| --- | --- | --- |']
    for key,group in GROUPS.items():
        links=', '.join('['+x.removeprefix('SYMBOLS_').removesuffix('.md')+'](../'+x+')'for x in group['notes'])
        lines.append('| '+key+' | '+links+' | '+group['comparison'].replace('|','\\|')+' |')
    lines+=['','Four original complete intervals were freshly read and hashed as data: `o2:00570370`, `o2:005703A0`, `o2:007008C0`, `main:001ABB60` (**216 words** total). Their interval bounds/hashes are in the receipt; other candidate boundaries cite existing full-body notes. Main ELF SHA-256 `'+ELF_SHA+'`; owned o2 image SHA-256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. No guest payload was executed.','',
            '## Reproduce and remaining limits','',
            '[Checker](../../tools/function_index/review_recvx_extra_utilities_complete_scope.py) reads the clean pinned source and frozen first ten scope identities, checks every raw source/body hash against the shared manifest, rebuilds this report and the [per-function receipt](../../build-function-index/recvx-extra-utilities-complete-scope.json), and checks original interval identities. Run `python tools/function_index/review_recvx_extra_utilities_complete_scope.py`. It writes only its own receipt/report.','',
            'The actor eligibility screen and transferred sound adapters have independent ledgers. Declarations, unavailable platform bodies and 223 ASM placeholders remain governed by the reference-availability audit. A scoped no-counterpart result is limited to the documented owned families; it is not a whole-binary absence proof. Reference defects or unguarded domains are static observations, not reproduced Outbreak bugs or measured slowdown causes.','']
    (ROOT/'docs/recvx-crosscheck/EXCLUSION_AUDIT.md').write_text('\n'.join(lines),encoding='utf-8')
    print(json.dumps(data['scope']));print(json.dumps(data['admitted_counts_by_file']))

if __name__=='__main__':main()
