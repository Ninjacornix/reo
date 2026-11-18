#!/usr/bin/env python3
"""Owned binary reference candidates for fourteen purpose-gap investigations.
No runtime observation, pointer dereference into a process, or guest execution.
"""
from pathlib import Path
import json,struct,hashlib,sqlite3,bisect,re
from index import Elf
ROOT=Path(__file__).resolve().parents[2]
ENTRIES=(0x1264D0,0x12C918,0x12C930,0x130E88,0x138EA8,0x13F1F8,0x13F208,0x13F218,0x13F230,0x13F248,0x1D6EB0,0x1DB090,0x1F2AE0,0x683AB0)
GLOBALS=(0x20C7A0,0x217D80,0x21C420,0x224758,0x224760,0x3901E0)

def main():
 elf=Elf(ROOT/'game_data/SLUS_207.65')
 regions=[('main',a,elf.data[o:o+n],elf.sha256) for a,o,n in elf.segments]
 for r in json.loads((ROOT/'tools/function_index/overlay_identities.json').read_text())['images']:
  raw=(ROOT/f"build-function-index/owned-overlays/{r['image']}.bin").read_bytes()
  assert hashlib.sha256(raw).hexdigest()==r['imageSha256']
  regions.append((r['image'],r['base'],raw,r['imageSha256']))
 c=sqlite3.connect(f'file:{ROOT / "build-function-index/index.sqlite"}?mode=ro',uri=True)
 owners={}
 for im,a,z,name in c.execute('select image,start,end,proposed_name from functions order by image,start'):
  owners.setdefault(im,[]).append((a,z,name))
 def owner(im,pc):
  rows=owners[im];i=bisect.bisect_right(rows,(pc,0xFFFFFFFF,chr(0x10FFFF)))-1
  return dict(start=hex(rows[i][0]),end=hex(rows[i][1]),name=rows[i][2]) if i>=0 and rows[i][0]<=pc<rows[i][1] else None
 refs=[];globalrefs=[]
 bodies=[]
 for address in ENTRIES:
  im='o2' if address==0x683AB0 else 'main'
  end,source=c.execute('select end,source from functions where image=? and start=?',(im,address)).fetchone()
  def original(pc,n):
   if im=='main':return elf.read(pc,n)
   _,base,raw,_=next(r for r in regions if r[0]==im)
   return raw[pc-base:pc-base+n]
  interval=original(address,end-address);assert interval is not None and len(interval)==end-address
  pcs=set()
  for m in re.finditer(r'// 0x([\da-f]+): 0x([\da-f]+)\s+', (ROOT/source).read_text(), re.I):
   pc=int(m[1],16)
   if address<=pc<end:
    assert int.from_bytes(original(pc,4),'little')==int(m[2],16)
    pcs.add(pc)
  missing=[pc for pc in range(address,end,4) if pc not in pcs]
  assert all(original(pc,4)==b'\0'*4 for pc in missing)
  bodies.append(dict(image=im,start=hex(address),end_exclusive=hex(end),source=source,
    sha256=hashlib.sha256(interval).hexdigest(),source_comments=len(pcs),omitted_zero_words=len(missing)))
 for im,base,raw,sha in regions:
  for target in ENTRIES+GLOBALS:
   needle=struct.pack('<I',target);pos=raw.find(needle)
   while pos>=0:
    refs.append(dict(image=im,address=hex(base+pos),target=hex(target),kind='literal_u32_candidate',aligned=(base+pos)%4==0,owner=owner(im,base+pos)))
    pos=raw.find(needle,pos+1)
  for pos in range(0,len(raw)-3,4):
   w=struct.unpack_from('<I',raw,pos)[0];pc=base+pos
   if w>>26 in (2,3):
    target=((pc+4)&0xF0000000)|((w&0x3FFFFFF)<<2)
    if target in ENTRIES:refs.append(dict(image=im,address=hex(pc),target=hex(target),kind='jal_candidate' if w>>26==3 else 'jump_candidate',owner=owner(im,pc)))
   if w>>26!=15:continue
   reg=(w>>16)&31;value=(w&65535)<<16
   for n in range(1,25):
    if pos+4*n+4>len(raw):break
    p=pc+4*n;v=struct.unpack_from('<I',raw,pos+4*n)[0]
    op,rs,rt,rd=v>>26,(v>>21)&31,(v>>16)&31,(v>>11)&31
    imm=v&65535;signed=imm-65536 if imm&32768 else imm
    if rs==reg and op in (9,13):
     address=(value+signed)&0xFFFFFFFF if op==9 else value|imm
     if address in ENTRIES+GLOBALS:globalrefs.append(dict(image=im,lui=hex(pc),site=hex(p),address=hex(address),kind='materialized_candidate',owner=owner(im,p)))
     if rt==reg:value=address;continue
    if rs==reg and (0x20<=op<=0x3F or op in (0x1E,0x1F)):
     address=(value+signed)&0xFFFFFFFF
     if any(a<=address<a+(40 if a==0x3901E0 else 4) for a in GLOBALS):globalrefs.append(dict(image=im,lui=hex(pc),site=hex(p),address=hex(address),kind='memory_candidate',word=f'{v:08X}',owner=owner(im,p)))
    writes=(rd if op==0 and v&63 not in (8,0x18,0x19,0x1A,0x1B,0x11,0x13) else rt if op in (8,9,10,11,12,13,14,15,0x18,0x19,0x1A,0x1B,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x37) else 31 if op==3 else None)
    if writes==reg:break
 recoveredrefs=[];recovered=[]
 for filename,image in (('dnas-primary-recovery-inventory.json','o4'),('dnas-upper-recovery-inventory.json','o4'),('dnas-o5-family-recovery-inventory.json','o5')):
  path=ROOT/'build-function-index'/filename;data=json.loads(path.read_text())
  expected=next(sha for im,a,b,sha in regions if im==image)
  assert data['image_sha256']==expected
  recovered.append(dict(path=filename,image=image,spans=len(data['spans']),payload_words=sum(len(s['candidate_words']) for s in data['spans'])))
  for s in data['spans']:
   for i,encoded in enumerate(s['candidate_words']):
    w=int(encoded,16);pc=int(s['start'],16)+4*i
    target=((pc+4)&0xF0000000)|((w&0x3FFFFFF)<<2)
    if w in ENTRIES+GLOBALS:recoveredrefs.append(dict(image=image,address=hex(pc),target=hex(w),kind='candidate_payload_literal'))
    if w>>26 in (2,3) and target in ENTRIES:recoveredrefs.append(dict(image=image,address=hex(pc),target=hex(target),kind='candidate_payload_direct_control'))
 out=ROOT/'build-function-index/purpose-gap-owned-refs.json'
 shoff=struct.unpack_from('<I',elf.data,32)[0];stride,count=struct.unpack_from('<HH',elf.data,46)
 reginfo=[struct.unpack_from('<10I',elf.data,shoff+i*stride) for i in range(count) if struct.unpack_from('<I',elf.data,shoff+i*stride+4)[0]==0x70000006]
 assert len(reginfo)==1
 gp=struct.unpack_from('<I',elf.data,reginfo[0][4]+20)[0];assert gp==0x261CF0
 assert all(not gp-32768<=a<gp+32768 for a in GLOBALS)
 out.write_text(json.dumps(dict(schema=1,entries=[hex(a) for a in ENTRIES],bodies=bodies,globals=[hex(a) for a in GLOBALS],regions=[dict(image=im,base=hex(a),length=len(raw),sha256=sha) for im,a,raw,sha in regions],references=refs,global_candidates=globalrefs,recovered_payload_inventories=recovered,recovered_payload_matches=recoveredrefs,elf_reginfo_gp=hex(gp),gp_direct_window_excludes_all_six_globals=True,no_guest_execution=True,limitations='Raw values/instruction patterns are candidates, including data or encoded bytes. Linear short-window address tracking is not complete control-flow or alias analysis; inspect all hits before attribution. Recovered-word scans check direct J/JAL and literal values only, not arbitrary computed aliases.'),indent=2)+'\n')
 for target in ENTRIES:
  print('ENTRY',hex(target))
  for r in refs+globalrefs:
   if int(r.get('target',r.get('address','0')),16)==target:print(r)
 for target in GLOBALS:
  print('GLOBAL',hex(target))
  for r in globalrefs:
   if target<=int(r['address'],16)<target+(40 if target==0x3901E0 else 4):print(r)
 print('Regions',len(regions),'refs',len(refs),'globalcandidates',len(globalrefs))
 print('Recovered payloads',sum(r['spans'] for r in recovered),sum(r['payload_words'] for r in recovered),'words; matches',recoveredrefs)
if __name__=='__main__':main()
