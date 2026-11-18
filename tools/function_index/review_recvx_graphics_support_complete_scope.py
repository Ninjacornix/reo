"""Read-only reference/owned-word review of the43 CVX ps2_dummy.c definitions."""
import collections
import hashlib
import json
import pathlib
import re
import sqlite3
import subprocess
import sys

from review_recvx_ninja_complete_scope import REF, BASE, PIN, definitions, implementation, mask
from index import Elf

ROLES = {
 '_builtin_set_imask': 'Empty reference hook; no interrupt-mask operation available.',
 'Ps2Init': 'CVX platform boot sequence: fixed GS buffers/NTSC graph, IOPRP213/module paths, device callbacks, table setup and CVX VU uploads. Not an Outbreak boot ABI.',
 'Ps2LoadModule': 'sceSifLoadModule(path,0,NULL); negative result prints and exits. Generic platform wrapper; no same Outbreak failure/result ABI admitted.',
 'Snd_init': 'Empty reference sound-init hook; not the sound driver implementation.',
 'Cd_init': 'Empty reference CD-init hook; not the disc filesystem implementation.',
 'Card_init': 'Empty reference card-init hook; not the memory-card implementation.',
 'PS2_jikken': 'CVX peripheral poll then buffer swap; wrapper has no admitted Outbreak application contract.',
 'PS2_swap': 'GS sprite copy to display FBP150 using fixed640-wide texture/depth state; alpha FIX changes with CVX movie flag. Different from a generic present/swap call.',
 'Ps2AddPrim': 'CVX48byte vertex records to GS GIF packet, texture/admission state, coordinate/depth clipping, fixed-point conversion; transparency chooses OT enqueue versus immediate loadImage.',
 'Ps2AddPrim2D': 'Exact local wrapper Ps2AddPrim(prim,dp,num,0); preserves all CVX packet/state dependencies.',
 'Ps2AddPrim3D': 'CVX48byte vertex/GIF emission, VU clipping and fixed-point depth conversion; optional depth-priority OT queue. Not an admitted Outbreak draw record.',
 'Ps2AddPrim3DEx': 'CVX3D packet path with additional VU colour FTOI0 conversion before emission; CVX current texture/clip/OT contracts retained.',
 'Ps2AddPrim3DEx1P': 'CVX3D packet path with albinoid flag/caller priority exception and immediate/OT routing. Game-specific selector prevents generic renderer alias.',
 'Ps2AddPrim3DMod': 'CVX modifier packet selects GS context2, converts/clips vertices and submits immediately. No admitted Outbreak modifier-packet layout.',
 'Ps2ClearOT': 'Resets CVX8192record cursor,4096head/tail buckets and uncached Ps2_PBUFF write pointer. Does not clear an Outbreak queue.',
 'Ps2AddOT': 'CVX4096bucket append captures current texture/bank/TEX0/ALPHA and copies packet into its own buffer. Ice-flag texture IDs change depth shift12 versus4; no generic sort-key equivalence.',
 'Ps2DrawOTag': 'Disables CVX depth state, repeatedly traverses OT from returned bucket index, then restores depth and breaks texture cache.',
 'Ps2DrawOTagSub': 'CVX OT traversal/relinked DMA packets and up-to64 texture/bank tag cache; resumes a bucket when fixed GS texture range fills, uploads and restores blend modes. Different queue/cache ownership from Outbreak.',
 'Ps2BitCount': 'EE PLZCW(value-1) followed by31-count, used for texture exponents; not population count or unrestricted CLZ. Compare bounded dimension helper below.',
 'Ps2InitTexCache': 'Clears four CVX texture cache pointers/flags and stores cache-count4.',
 'Ps2GlobalIndexTexLoad': 'SearchNumber(index,-1), call Ps2TexLoad on hit, print on miss; source has no explicit return despite int signature.',
 'Ps2TexLoad': 'CVX NJS/TIM2 extension, current-texture/cache/TP/bank/render-texture flags; fixed GS upload destinations and TEX0/TEX1/CLAMP/TEST packet. Cache flag is return, not upload completion proof.',
 'Ps2SetFogColor': 'Packs CVX global RGB into GS FOGCOL and immediately emits DMA/GIF packet with D2_SyncTag boundaries.',
 'Ps2SetFogColorSys': 'Same CVX FOGCOL packet from explicit RGB arguments; generic GS register vocabulary does not prove Outbreak buffer/submission ABI.',
 'Ps2AlphaIs000': 'For num RGBA words, clears nonzero alpha when RGB are all zero. Distinct black-key transparency rule; no same admitted Outbreak image utility.',
 'Ps2AlphaIsHalf': 'For num RGBA words, stores(alpha+1)>>1; compared original Outbreak half-range paths use different low-alpha/rounding rules.',
 'Ps2Alpha4to8': 'For num RGBA words stores byte val|(val>>4); no local input-nibble validation and no explicit C return. No same admitted Outbreak utility.',
 'Ps2CheckTextureAlpha': 'CVX TIM2 extension cached ClutChange, palette adjustments by OrgColorType/isVQ, hardcoded texture-ID clamp exceptions, then Ps2PxlconvCheck. Game/format wrapper, not universal alpha conversion.',
 'Ps2InitPS2_GS_SAVE': 'Initializes CVX GS register save struct and fixed packet tags/register IDs, then FlushCache.',
 'Ps2ScreenClear': 'Fixed GS context2 framebuffer0 sprite clear with coordinate/depth/test state and immediate packet submission.',
 'Ps2DispScreenClear': 'Fixed GS context2 display framebuffer150 sprite clear; different target from Ps2ScreenClear.',
 'Ps2ZbuffOff': 'Emits GS TEST_1 alpha/depth rule only; despite name does not write ZBUF in this body.',
 'Ps2ZbuffOff2': 'Writes fixed ZBUF_1 mask1 and TEST_1, then submits packet; different from Ps2ZbuffOff.',
 'Ps2ZbuffOn': 'Writes fixed ZBUF_1 mask0 and TEST_1, then submits packet; CVX state/buffer ownership retained.',
 'Ps2ShadowStart': 'Fixed GS shadow framebuffer380/context2, depth mask, clear sprite and TEXA state, then submit.',
 'Ps2ShadowDraw': 'CVX four-coordinate shadow bounds/clamps and fog-derived grayscale; draws/clears fixed render texture targets with GS sprites.',
 'Ps2ShadowMain0': 'Sets extreme shadow bounds and emits fixed head packet; exact CVX GS packet/state operation.',
 'Ps2ShadowMain1': 'Emits fixed shadow tail packet through loadImage; not an empty hook.',
 'Ps2ShadowEnd': 'Restores fixed framebuffer0/context2 TEST/ZBUF/ALPHA packet after shadow rendering.',
 'Ps2Vu0ProgSend': 'Selects one of three identical CVX VU0 program pointers, DMA channel0 then sync; no bounds check. Does not establish any Outbreak program identity.',
 'Ps2Vu1ProgSend': 'Selects one of two CVX VU1 program pointers, DMA channel1 then sync; no bounds check. Similar upload mechanism is not exact-program identity.',
 'Ps2AddPrim3DExI': 'CVX3D packet variant optionally decomposes strips into triangles and sorts by ViewType-specific keys, then OT/immediate submission. Layout/state and depth policy remain CVX-specific.',
 'PS2_Render_Tex_Sub': 'Copies fixed GS framebuffer0 view into FBP476 at reduced dimensions, marks CVX render-texture flag, then clears screen. Not host GPU readback or generic render-target API.',
}

def main():
    assert subprocess.check_output(['git','-C',str(REF),'rev-parse','HEAD'],text=True).strip()==PIN
    assert not subprocess.check_output(['git','-C',str(REF),'status','--porcelain','--untracked-files=no'],text=True).strip()
    path=BASE/'ps2_dummy.c';raw=path.read_bytes();source=raw.decode();assert source.isascii()
    sha=lambda data:hashlib.sha256(data).hexdigest()
    rows=[]
    for name,a,b,z in definitions(source):
        body=source[b:z];clean=mask(body)
        status=implementation(body)
        ids=[]
        disposition='empty_reference_body' if status=='empty' else 'cvx_packet_or_state_boundary'
        depth='complete_source_body_and_ownership_boundary'
        if name=='Ps2BitCount':
            ids=['main:0019DAC0'];disposition='related_different_contract';depth='direct_full_body_contract'
        if name=='Ps2AlphaIsHalf':
            ids=['main:0018E1B0','main:0019E130'];disposition='related_different_contract';depth='direct_full_body_contract'
        if name in ('Ps2AlphaIs000','Ps2Alpha4to8'):disposition='generic_colour_operation_unpaired'
        rows.append({'id':'ps2_dummy.c:'+name,'file':path.relative_to(REF).as_posix(),'symbol':name,
          'signature_start':a,'body_start':b,'end_exclusive':z,'line_start':source.count('\n',0,a)+1,
          'body_line_start':source.count('\n',0,b)+1,'line_end':source.count('\n',0,z)+1,
          'signature':re.sub(r'\s+',' ',source[a:b]).strip(),'source_sha256':sha(raw),
          'definition_sha256':sha(source[a:z].encode()),'body_sha256':sha(body.encode()),
          'implementation_status':status,'implementation_detail':('empty_reference_body' if status=='empty' else ('inline_ee_vu_source' if re.search(r'\basm\b',clean) else 'c_operations')),
          'source_facts':{'call_or_macro_tokens':sorted(set(re.findall(r'\b([A-Za-z_]\w*)\s*\(',clean))-{'if','for','while','switch','sizeof','return','volatile','asm','void','float','int'}),
           'member_expressions':sorted(set(re.findall(r'\b[A-Za-z_]\w*(?:(?:->|\.)[A-Za-z_]\w*)+',clean)))},
          'disposition':disposition,'reason':ROLES[name],'comparison_depth':depth,'outbreak_comparisons':ids,
          'evidence':[f'https://github.com/AshfordFamily/recvx-decomp/blob/{PIN}/src/ps2/veronica/prog/ps2_dummy.c#L{source.count(chr(10),0,a)+1}']})
    assert set(ROLES)=={r['symbol'] for r in rows}
    shared=json.loads(pathlib.Path('build-function-index/recvx-complete-source-inventory.json').read_text())
    f=next(f for f in shared['files'] if f['path']=='src/ps2/veronica/prog/ps2_dummy.c')
    assert {(r['symbol'],r['line_start'],r['body_sha256']) for r in rows}=={(r['symbol'],r['start_line'],r['body_sha256']) for r in f['functions']}
    assert not f['assembly_placeholders']
    elf_path=pathlib.Path('game_data/SLUS_207.65');elf_hash=sha(elf_path.read_bytes())
    assert elf_hash=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    elf=Elf(str(elf_path));db=sqlite3.connect('file:build-function-index/index.sqlite?mode=ro',uri=True);db.row_factory=sqlite3.Row
    audit=[]
    for key in sorted({key for row in rows for key in row['outbreak_comparisons']}):
        image,address=key.split(':');start=int(address,16)
        owned=db.execute('SELECT * FROM functions WHERE image=? AND start=?',(image,start)).fetchone();assert owned
        original=pathlib.Path(owned['source']);words={}
        for m in re.finditer(r'// 0x([\da-f]+): 0x([\da-f]+)\s+',original.read_text(),re.I):
            pc,word=int(m[1],16),int(m[2],16)
            if start<=pc<owned['end']:words[pc]=word
        zero=0
        for pc in range(start,owned['end'],4):
            word=int.from_bytes(elf.read(pc,4),'little')
            if pc in words:assert words[pc]==word
            else:assert word==0;zero+=1
        audit.append({'id':key,'source':owned['source'],'source_sha256':sha(original.read_bytes()),
                      'start':start,'end':owned['end'],'verified_comments':len(words),'omitted_zero_words':zero})
    result={'schema':1,'kind':'static-source-contract-inventory','reference_commit':PIN,
      'enhanced_context_commit':'2fa8a14224ebb92d0103a8c828e6a032c338d6d4','files':[{'file':f['path'],'sha256':sha(raw),'bytes':len(raw),'definitions':len(rows)}],
      'definitions':rows,'counts':{'definitions':len(rows),'implementation':dict(collections.Counter(r['implementation_status'] for r in rows)),
      'disposition':dict(collections.Counter(r['disposition'] for r in rows))},
      'independent_inventory_reconciliation':{'definitions':len(rows),'missing':0,'extra':0,'different_body_hashes':0,'assembly_placeholders':0},
      'outbreak_evidence':{'elf_sha256':elf_hash,'complete_catalogue_bodies':audit,
        'verified_comments':sum(r['verified_comments'] for r in audit),'omitted_zero_words':sum(r['omitted_zero_words'] for r in audit),
        'conflicts':0,'omitted_nonzero_words':0}}
    pathlib.Path('build-function-index/recvx-graphics-support-complete-scope.json').write_text(json.dumps(result,indent=2)+'\n')
    note=['# Complete graphics support reference scope','',
      f'Static review, 2026-11-05. Pinned CVX source `{PIN}`. This transferred scope is exactly `src/ps2/veronica/prog/ps2_dummy.c`: **43 definitions, 39 nonempty bodies, four empty bodies**, with zero declarations-only definitions and zero assembly placeholders. Independent inventory reconciliation matches every symbol, source line and body hash. Raw source SHA-256: `{sha(raw)}`. No game, build, target execution, attachment, live-memory read or rendering was performed.','',
      'Every complete source definition was read, including inline EE/VU assembly, sorting/texture-cache branches and fixed packets. Each row has a specific contract disposition. This establishes static implementation/ownership boundaries, not every possible Outbreak counterpart or whole-state equivalence. Empty `_builtin_set_imask`, `Snd_init`, `Cd_init` and `Card_init` supply no usable implementation; they are not proof of equivalent empty Outbreak functions.','',
      'The complete machine ledger is `build-function-index/recvx-graphics-support-complete-scope.json`; [its static generator](../../tools/function_index/review_recvx_graphics_support_complete_scope.py) preserves exact UTF-8 byte/line bounds, source/definition/body hashes, signatures, call and member evidence, each individual reason and image-qualified comparison IDs. No aliases, catalogue counts or authoritative mapping rows changed.','',
      '## Useful differences','',
      '- CVX `Ps2AlphaIsHalf` stores `(alpha+1)>>1`. Owned Outbreak `0x18E1B0` maps255 to128, preserves0, and otherwise uses `max(alpha>>1,1)`; `0x19E130` uses255-to128 or plain right-shift when converting toward PS2 alpha. At alpha3 their ordinary integer arithmetic gives CVX2 versus Outbreak1. Sharing a PS2 half-range goal does not make their rounding interchangeable.',
      '- CVX `Ps2BitCount` is a texture-exponent operation built from `PLZCW(value-1)` and subtraction, not a population count. Outbreak `0x19DAC0` narrows signed16 and searches exponents1..10, with1 also retained outside its admitted range. Even input1 differs: CVX0 versus Outbreak1 by these paths. No unrestricted log2 equivalence was inferred.',
      '- CVX `Ps2AddOT` and `Ps2DrawOTagSub` own4096 buckets,8192 records, captured texture/bank/TEX0/ALPHA state, and a64-entry submission texture cache. Special ice-mode texture IDs alter the depth shift. These concrete queue/key/cache contracts prevent replacing an Outbreak Clay/native submission function from the generic name “ordering table.”',
      '- `Ps2ZbuffOff` only emits TEST_1; `Ps2ZbuffOff2` and `Ps2ZbuffOn` also emit ZBUF_1. `PS2_swap` is a fixed GS display copy with a movie-dependent blending constant, not a host presentation API. VU upload helpers select exact CVX program pointers before DMA; no common Outbreak microprogram identity follows.','',
      f'The focused owned-word audit checks three complete main-image bodies: **{result["outbreak_evidence"]["verified_comments"]} original instruction comments, {result["outbreak_evidence"]["omitted_zero_words"]} omitted zeros, zero conflicts and zero omitted nonzero words**. Relevant prior contracts: [image loading](../SYMBOLS_TEXTURE_IMAGE_LOADING.md), [render-state controller](../SYMBOLS_RENDER_STATE_CONTROLLER.md), [render math](../SYMBOLS_RENDER_MATH.md) and [Ninja inventory](NINJA_COMPLETE_SCOPE.md).','',
      '## Per-symbol ledger','',
      '| Definition / complete source lines | Implementation | Disposition and evidence limit | Complete body SHA-256 |','| --- | --- | --- | --- |']
    for r in rows:
        ids=' '.join('`'+i+'`' for i in r['outbreak_comparisons'])
        reason=r['reason'].replace('|','\\|')
        note.append(f'| [{r["symbol"]}]({r["evidence"][0]}) {r["line_start"]}–{r["line_end"]} | {r["implementation_status"]}; {r["implementation_detail"]} | `{r["disposition"]}` {ids}. {reason} | `{r["body_sha256"]}` |')
    text='\n'.join(note)+'\n'
    for old,new in [('maps255','maps 255'),('to128','to 128'),('preserves0','preserves 0'),('alpha3','alpha 3'),('CVX2','CVX 2'),('Outbreak1','Outbreak 1'),('signed16','signed 16'),('exponents1..10','exponents 1..10'),('with1','with 1'),('input1','input 1'),('CVX0','CVX 0'),('own4096','own 4096'),('buckets,8192','buckets, 8192'),('a64-entry','a 64-entry')]:text=text.replace(old,new)
    pathlib.Path('docs/recvx-crosscheck/GRAPHICS_SUPPORT_COMPLETE_SCOPE.md').write_text(text,encoding='utf-8')
    print(json.dumps({'counts':result['counts'],'word_audit':result['outbreak_evidence']['verified_comments'],'omitted_zero':result['outbreak_evidence']['omitted_zero_words']}))

if __name__=='__main__':main()
