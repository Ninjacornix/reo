"""Complete pinned CVX TIM2 support definitions and bounded owned Outbreak comparisons."""
import collections
import hashlib
import json
import pathlib
import re
import subprocess

from review_recvx_ninja_complete_scope import REF, BASE, PIN, definitions, implementation, mask
from review_recvx_platform_complete_scope import audit_owned

ROLES={
 'Tim2CalcBufWidth':('generic_gs_width_unpaired',[], 'For accepted GS PSMs returns(w+63)/64; indexed4/8 rounds odd result upward to even. UnknownPSM0. No admitted exact Outbreak width-helper ABI; positive-width GS storage role only.'),
 'Set_GsTex':('related_different_contract',['main:0019DAC0'], 'Mutates CVX picture TEX0 using addresses, imageformat and power-of-two1..1024 exponents, exits on bad dimension. Outbreak19DAC0 signed16 exponent search starts1,so dimension1 differs; this is not the same validator or wholeTEX0 builder.'),
 'MakeRenderTexHeader':('supported_shared_suboperation',['main:001A57B0'], 'Writes TIM2 magic/version4/format1/singlepicture, admitted by the independently reviewed Outbreak header validator as format vocabulary only. CVX constructs fixed512x512RGBA render image, ImageSize1048576,128bytefile/pictureheaders; not a generic parser. Stored TW/TH8 despite512 dimensions is preserved source, not silently corrected.'),
 'StoreRenderTex':('cvx_render_target_readback_boundary',[], 'Builds fixed renderheader, sceGsStoreImage framebuffer0/stride10/PSM32 in chunks at most255 rows, FlushCache, then Ps2ScreenClear. No matching Outbreak readback/host GPU completion contract established.'),
 'LoadToVram':('supported_shared_suboperation',['main:0018C8C0','main:0018CD00'], 'Common GS BITBLTBUF/TRXPOS/TRXREG/TRXDIR +IMAGE referenced-data register sequence. CVX builds static GIF-DMA packet, appends TEXFLUSH and submits immediately. Outbreak builds caller-owned VIF DIRECTHL chunk chains and separate flush packet without submission here. Buffer/tag/lifetime/IRQ contracts differ.'),
 'UncAddr':('generic_guest_address_alias_unpaired',[], 'Exactly narrows pointer to u_int, masks0FFFFFFF andOR20000000 per pinnedtypes.h. Not a portable hostpointer transform or an admitted Outbreak handle/memoryownership alias.'),
 'Send_1024_Clut_data':('cvx_clut_packet_layout_boundary',[], 'Nested4x16 loops emit fixed8x2 GS transfer regions, source advances4quadwords each iteration; packet image/ref QWC hardcoded64. No universal1024entry count is inferred from name, and no Outbreak extent/tag equivalence established.'),
 'Send_Tim2_dataEx':('supported_shared_suboperation',['main:001A5850','main:001A58C0'], 'Shared firstpicture location: filebyte5zero=>+16,nonzero=>+128. CVX no local magic/version/picturecount check; CLUTtype gatesupload and256/512indexedimages select P32 route. Outbreak walker also supports further picture offsets with header-selected alignment; not a wholeupload alias.'),
 'Clut_Load_Func':('related_different_contract',['main:001A5A20'], 'CVX palettepointer=picture+HeaderSize+ImageSize,onlyRGB32 indexed4/8 admitted; loops palettecount in256steps but does not advance pClut/destination inside suppliedloop. Outbreak palette locator handles aligned mip-dependent headers and missingClutSize, no upload. Pointer-role only, not sameAPI.'),
 'P32_Image_Load':('cvx_preconverted_storage_upload_boundary',['main:0019E490','main:0019E7D0'], 'Uploads alreadyconverted indexedimage as PSM32 with reducedwidth/height; Outbreak comparison entries perform CPU full-page packed4/8 reordering. Explicit layer difference; neither expands palette indices intoRGBA.'),
 'Tim2_Image_Load':('related_different_contract',['main:0018C8C0'], 'CVX supports three-entry imageType3..5 table, splits uploads at32764quadword bytes into rowblocks and submits viaLoadToVram. Outbreak chunk builder uses0x70000byte limit and VIF DIRECTHL plus REF/REFE, receives format/dest/payload separately and does not submit. Countunits/thresholds/buffercontracts differ.'),
 'Ps2PxlconvCheck':('cvx_conversion_admission_boundary',['main:0019E440'], 'CVX admits only bothdimensions>128and<1024 and indexedtype4/5 then invokes formatchecker; Outbreak dispatcher onlynumericmode0/1,without same dimension or TIM2header gate. Same GS task does not transfer admission rules.'),
 'SyncPath':('related_different_contract',['main:00113488'], 'Both inspect DMA/VIF/VU/GIF progression conditions, including VIF1mask1F000003,VUvi29bit100,GIFmaskC00. CVX manipulates D_PCR and busywaits withoutlocaliterationlimit; Outbreak supports pollingbitmask or sharedboundedwait/log/-1 path. Same condition vocabulary does not imply same return/scheduling/MMIOeffects.'),
 'D2_SyncTag':('related_different_contract',['main:00113488'], 'CVX manipulates D_PCR, conditionallywaits BC0 then restoresbits, no localtimeout/result. Outbreak polls DMA busy registers with ownbounded/polling policy. No fence-removal or hostwait equivalence established.'),
 'loadImage':('cvx_gif_dma_submission_boundary',[], 'WaitsBC0 then writesD_PCR4,D_STAT4,D2_TADRtags,D2_CHCR261. ExactPS2DMA launch, not an image decoder and not proof of Outbreak renderqueue/hostsubmission identity.'),
 'ClearVram':('cvx_gs_clear_sequence_boundary',[], 'Zeros1024-byteclearbuffer, loops16384 calls to fixed16x16PSM32 loadimages atbasei*4 withFlushCache/GSsync. No VRAMsize/wrap or equivalent Outbreak hostclear inferred from name.'),
}

def main():
    assert subprocess.check_output(['git','-C',str(REF),'rev-parse','HEAD'],text=True).strip()==PIN
    assert not subprocess.check_output(['git','-C',str(REF),'status','--porcelain','--untracked-files=no'],text=True).strip()
    p=BASE/'ps2_loadtim2.c';raw=p.read_bytes();source=raw.decode();assert source.isascii();sha=lambda b:hashlib.sha256(b).hexdigest()
    rows=[]
    for name,a,b,z in definitions(source):
        body=source[b:z];clean=mask(body);verdict,ids,reason=ROLES[name]
        rows.append({'id':'src/ps2/veronica/prog/ps2_loadtim2.c:'+name,'file':'src/ps2/veronica/prog/ps2_loadtim2.c','symbol':name,
          'signature_start':a,'body_start':b,'end_exclusive':z,'line_start':source.count('\n',0,a)+1,'body_line_start':source.count('\n',0,b)+1,'line_end':source.count('\n',0,z)+1,
          'signature':re.sub(r'\s+',' ',source[a:b]).strip(),'source_sha256':sha(raw),'definition_sha256':sha(source[a:z].encode()),'body_sha256':sha(body.encode()),
          'implementation_status':implementation(body),'implementation_detail':'inline_ee_vu_source' if re.search(r'\basm\b',clean) else 'c_operations',
          'disposition':verdict,'reason':reason,'outbreak_comparisons':ids,'comparison_depth':'direct_full_body_contract' if ids else 'complete_source_body_and_ownership_boundary',
          'source_facts':{'call_or_macro_tokens':sorted(set(re.findall(r'\b([A-Za-z_]\w*)\s*\(',clean))-{'if','for','while','switch','sizeof','return','volatile','asm','void','int','float'}),
           'member_expressions':sorted(set(re.findall(r'\b[A-Za-z_]\w*(?:(?:->|\.)[A-Za-z_]\w*)+',clean)))},
          'evidence':[f'https://github.com/AshfordFamily/recvx-decomp/blob/{PIN}/src/ps2/veronica/prog/ps2_loadtim2.c#L{source.count(chr(10),0,a)+1}']})
    assert set(ROLES)=={r['symbol'] for r in rows}
    shared=json.loads(pathlib.Path('build-function-index/recvx-complete-source-inventory.json').read_text());f=next(f for f in shared['files'] if f['path']=='src/ps2/veronica/prog/ps2_loadtim2.c')
    assert {(r['symbol'],r['line_start'],r['body_sha256']) for r in rows}=={(r['symbol'],r['start_line'],r['body_sha256']) for r in f['functions']}
    assert not f['assembly_placeholders']
    types=(REF/'include/ps2/veronica/prog/types.h').read_bytes();assert b'#define UNCMASK 0x0fffffff' in types and b'#define UNCBASE 0x20000000' in types
    audit=audit_owned({key for r in rows for key in r['outbreak_comparisons']})
    result={'schema':1,'kind':'static-source-contract-inventory','reference_commit':PIN,
      'files':[{'file':f['path'],'sha256':sha(raw),'bytes':len(raw),'definitions':len(rows)}],'definitions':rows,
      'counts':{'definitions':len(rows),'implementation':dict(collections.Counter(r['implementation_status'] for r in rows)),'disposition':dict(collections.Counter(r['disposition'] for r in rows))},
      'independent_inventory_reconciliation':{'definitions':len(rows),'missing':0,'extra':0,'different_body_hashes':0,'assembly_placeholders':0},
      'outbreak_evidence':audit,'macro_evidence':{'file':'include/ps2/veronica/prog/types.h','sha256':sha(types),'UNCMASK':'0x0fffffff','UNCBASE':'0x20000000'}}
    pathlib.Path('build-function-index/recvx-tim2-complete-scope.json').write_text(json.dumps(result,indent=2)+'\n')
    note=['# Complete TIM2 and GS transfer support scope','',
      f'Static review,2026-11-05. Pinned CVX `{PIN}`. **All16 complete definitions** in `src/ps2/veronica/prog/ps2_loadtim2.c` were read, including EE/VU waits and every transfer/header/format branch. All16 have nonempty implementations; no empty, declarations-only or assembly-placeholder bodies occur. Independent whole-tree inventory reconciliation matches every symbol,line and body hash. Raw file SHA-256: `{sha(raw)}`. No game,build,attachment,live memory,GS transfer,readback,texture conversion or target execution occurred.','',
      'The local ledger `build-function-index/recvx-tim2-complete-scope.json` and [static review helper](../../tools/function_index/review_recvx_tim2_complete_scope.py) retain exact UTF-8 bounds, source/definition/body hashes, implementation/disposition, individual reasons and source facts. No canonical Outbreak annotations, aliases or index counts changed.','',
      '## Results','',
      '- **Shared format/suboperations:** first TIM2 picture at+16/+128 according to filebyte5; TIM2 magic/version4/format1/single-picture vocabulary; and GS BITBLTBUF/TRXPOS/TRXREG/TRXDIR plusIMAGE transfer sequence are concretely comparable. These support narrow format/register meanings, not shared engines or wholeupload functions.',
      '- **Transfer composition differs:** CVX `LoadToVram` constructs static GIF/DMA storage, appends TEXFLUSH and immediately submits it. Outbreak`0x18C8C0` builds caller-owned VIF DIRECTHL chunk chains with separate flush builder`0x18CD00`. CVX `Tim2_Image_Load` uses32764quadword transfer limits; Outbreak uses0x70000-byte chunks. Queuing,IRQ choice,tag order,geometry and referenced-data lifetime cannot be erased from an optimization.',
      '- **Synchronization differs:** CVX `SyncPath` manipulates D_PCR and waits DMA,VIF1,VU andGIF states without a localtimeout. Outbreak`0x113488` has a polling bitmask mode and a shared iteration-limited wait with failure diagnostics. Shared busy-bit masks do not justify dropping waits or replacing them with a generic host fence.',
      '- **CVX-specific readback/format policy:** `StoreRenderTex` reads fixed512x512 frame content into its constructed TIM2 and clears the screen. Its header writes TW/TH8 despite dimensions512; preserved source evidence is not repaired by inference. Palette loader uses `picture+HeaderSize+ImageSize` and only accepts RGB32indexed4/8; its loop does not advance the palette pointer/destination. Outbreak locator has aligned,mip-dependent pointer rules. These are different API/layer contracts.',
      '- `UncAddr` is a guest32-bit mask/uncachedalias; `loadImage` starts the GIF DMA channel rather than decoding an image; `ClearVram` emits a fixed16384-iteration transfer sequence. Their names do not establish portable host replacements. No source issue here was assumed to exist in Outbreak.','',
      f'Owned evidence: **{len(audit["complete_catalogue_bodies"])} complete Outbreak bodies/{audit["verified_comments"]} matching instruction comments**, {audit["omitted_zero_words"]} omitted zero words,zero conflicts/nonzero omissions. Existing [texture image loading](../SYMBOLS_TEXTURE_IMAGE_LOADING.md), [texture transfers](../SYMBOLS_TEXTURE_TRANSFER_PACKETS.md), [packed pages](../SYMBOLS_TEXTURE_RESIDENCY_AND_PACKED_PAGES.md), [Ninja](NINJA_COMPLETE_SCOPE.md) and [graphics support](GRAPHICS_SUPPORT_COMPLETE_SCOPE.md) remain consistent with these comparisons.','',
      '## Every-symbol ledger','',
      'Complete body hashes/bounds identify the reviewed source; comparison IDs are investigated targets, not original symbols. Unpaired rows retain honest unknowns instead of matching by generic names.','',
      '| Symbol/source lines | Implementation | Disposition and precise applicability | Complete body SHA-256 |','| --- | --- | --- | --- |']
    for r in rows:
        ids=' '.join('`'+i+'`' for i in r['outbreak_comparisons']);reason=r['reason'].replace('|','\\|')
        note.append(f'| [{r["symbol"]}]({r["evidence"][0]}) {r["line_start"]}–{r["line_end"]} | {r["implementation_status"]}; {r["implementation_detail"]} | `{r["disposition"]}` {ids}. {reason} | `{r["body_sha256"]}` |')
    text='\n'.join(note)+'\n'
    for old,new in [('review,2026','review, 2026'),('All16','All 16'),('symbol,line','symbol, line'),('game,build,attachment,live memory,GS transfer,readback,texture conversion','game, build, attachment, live memory, GS transfer, readback, texture conversion'),('Outbreak`','Outbreak `'),('builder`','builder `'),('uses32764','uses 32764'),('32764quadword','32764 quadword'),('uses0x70000','uses 0x70000'),('DMA,VIF1,VU andGIF','DMA, VIF1, VU and GIF'),('fixed512x512','fixed 512x512'),('dimensions512','dimensions 512'),('TW/TH8','TW/TH 8'),('RGB32indexed4/8','RGB32 indexed4/8'),('guest32-bit','guest 32-bit'),('fixed16384-iteration','fixed 16384-iteration'),('words,zero','words, zero')]:text=text.replace(old,new)
    pathlib.Path('docs/recvx-crosscheck/TIM2_COMPLETE_SCOPE.md').write_text(text,encoding='utf-8')
    print(json.dumps({'counts':result['counts'],'word_audit':audit['verified_comments'],'omitted_zero':audit['omitted_zero_words']}))

if __name__=='__main__':main()
