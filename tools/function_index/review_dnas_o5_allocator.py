#!/usr/bin/env python3
"""Static o5 allocator listing and copied-data reconstruction checks only."""
import hashlib,json,struct
from pathlib import Path
from recover_dnas_zero_upper import transform,schedule
BASE=0x6E0000
SHA="97174f5d367cd90bedd5ba397c6492e9fb4bbd0ec7d6021c2be524c49925d38e"
from review_dnas_query_adapters import extra_fields,REG
ROOT=Path(__file__).resolve().parents[2]
LO,HI=0x6E0698,0x6E2778
OWNERS=((0x6E0698,0x6E0838),(0x6E0838,0x6E0F38),(0x6E0F38,0x6E1B44),(0x6E1ED0,0x6E2204),(0x6E2208,0x6E23A4),(0x6E23A8,0x6E2778))

def main():
 raw=(ROOT/'build-function-index/owned-overlays/o5.bin').read_bytes()
 assert hashlib.sha256(raw).hexdigest()==SHA
 def read(a,n):return struct.unpack_from('<'+'I'*n,raw,a-BASE)
 inventory=json.loads((ROOT/'build-function-index/dnas-o5-family-recovery-inventory.json').read_text())
 spans=[s for s in inventory['spans'] if int(s['dispatcher'],16)==0x6E2828]
 assert len(spans)==18
 assert read(0x7096A0,1)==(18,)
 metadata={}
 for i in range(18):
  key,off=read(0x7096A4+8*i,2);a=0x709734+off
  relative,count=read(a,2);metadata[key>>1]=(relative,read(a+8,count))
 candidate={};skip=set();inline=set()
 for s in spans:
  a,z=int(s['start'],16),int(s['end_exclusive'],16)
  h,r=read(a-20,5),read(z+32,4)
  assert list(h)==[int(w,16) for w in s['header']]
  assert list(r)==[int(w,16) for w in s['restore_header']]
  assert h[1]^h[3]==r[0]^r[2]==z-a and h[2]&1==0 and r[1]&1==1
  assert metadata[h[2]>>1]==metadata[r[1]>>1]
  relative,exceptions=metadata[h[2]>>1]
  words=list(read(a,(z-a)//4));elig=[relative+4*i not in exceptions for i in range(len(words))]
  got=words[:]
  for slot in schedule(h[1]):got=[transform(w,slot,True) if elig[i] else w for i,w in enumerate(got)]
  assert got==[int(w,16) for w in s['candidate_words']]
  restored=got[:]
  for slot in schedule(r[0]):restored=[transform(w,slot,False) if elig[i] else w for i,w in enumerate(restored)]
  assert restored==words
  assert read(a-52,2)==(0x1000000C,0),hex(a)
  assert read(z,2)==(0x1000000B,0),hex(a)
  skip.update(range(a-44,a,4));skip.update(range(z+8,z+48,4))
  candidate.update({a+4*i:w for i,w in enumerate(got)})
  # Candidate branch-skipped ASCII/NUL regions are manually reviewed below.
  # Merely being skipped is insufficient: other branches jump over real code.
  for i,w in enumerate(got):
   pc=a+4*i
   if w>>16==0x1000:
    imm=w&65535;target=pc+4+(imm-65536 if imm&32768 else imm)*4
    if pc+8<target<=z:
     blob=struct.pack('<'+'I'*((target-pc-8)//4),*got[i+2:(target-a)//4])
     if any(blob) and all(b==0 or 32<=b<127 for b in blob):inline.update(range(pc+8,target,4))
 words=[];listing=[]
 for p in range(LO,HI,4):
  if p in skip:continue
  w=candidate.get(p,read(p,1)[0])
  origin='candidate_inline_data' if p in inline else 'candidate_code' if p in candidate else 'owned_clear'
  decoded=extra_fields(p,w)
  # EE MULT/MULTU optionally publish the low result to encoded rd as well
  # as HI/LO. Dropping rd would misread allocator byte accounting.
  if w>>26==0 and w&63 in (0x18,0x19):
   decoded='%s $%s, $%s, $%s'%('mult' if w&63==0x18 else 'multu',REG[(w>>11)&31],REG[(w>>21)&31],REG[(w>>16)&31])
  if 'UNDECODED' in decoded and w>>26==0 and w&63==0x27:
   decoded='nor $%s, $%s, $%s'%(REG[(w>>11)&31],REG[(w>>21)&31],REG[(w>>16)&31])
  if 'UNDECODED' in decoded and w>>26==0 and w&63==0x14:
   decoded='dsllv $%s, $%s, $%s'%(REG[(w>>11)&31],REG[(w>>16)&31],REG[(w>>21)&31])
  if 'UNDECODED' in decoded and w>>26==0 and w&63==0x0D:
   decoded='break %d'%((w>>6)&0xFFFFF)
  if p in inline:decoded='INLINE DATA '+struct.pack('<I',w).hex()
  words.append(dict(address=hex(p),word=f'{w:08X}',origin=origin,fields=decoded))
  listing.append(f'{p:08X} {w:08X} {origin:24} {decoded}')
 assert hashlib.sha256((ROOT/'build-function-index/owned-overlays/o5.bin').read_bytes()).hexdigest()==SHA
 out=ROOT/'build-function-index/dnas-o5-allocator-review';out.mkdir(exist_ok=True)
 (out/'words.txt').write_text('\n'.join(listing)+'\n')
 (out/'receipt.json').write_text(json.dumps(dict(schema=1,image_sha256=SHA,lo=hex(LO),hi=hex(HI),spans=spans,words=words,metadata_pair_checks=True,no_guest_execution=True),indent=2)+'\n')
 owner_receipts=[]
 for owner,end in OWNERS:
  body=[w for w in words if owner<=int(w['address'],16)<end]
  code={int(w['address'],16) for w in body if w['origin']!='candidate_inline_data'}
  branches=[];calls=[]
  for row in body:
   pc,w=int(row['address'],16),int(row['word'],16)
   if pc not in code:continue
   op=w>>26
   if op in (1,4,5,6,7,0x14,0x15,0x16,0x17):
    imm=w&65535;target=pc+4+(imm-65536 if imm&32768 else imm)*4
    assert target in code,(hex(pc),hex(target))
    branches.append(dict(pc=hex(pc),target=hex(target)))
   if op==3 and ((w&0x3FFFFFF)<<2)==0x6E2828:calls.append(pc)
  related=[s for s in spans if owner<=int(s['start'],16)<end]
  assert len(calls)==len(related)
  for s in related:
   a=int(s['start'],16)
   hits=[pc for pc in calls if a-80<=pc<a-44]
   assert len(hits)==1
   s['independently_bound_entry_call']=hex(hits[0])
   s['joined_owner']=hex(owner)
   s['owner_has_no_forward_restore_call']=True
  owner_receipts.append(dict(owner=hex(owner),end_exclusive=hex(end),
    original_sha256=hashlib.sha256(raw[owner-BASE:end-BASE]).hexdigest(),
    spans=[s['start'] for s in related],entry_calls=[hex(p) for p in calls],
    code_words=len(code),inline_data_words=len(body)-len(code),branch_targets=branches,
    no_forward_restore_call_in_joined_owner=True))
 receipt_path=out/'receipt.json'
 receipt=json.loads(receipt_path.read_text());receipt['owners']=owner_receipts;receipt['spans']=spans
 receipt_path.write_text(json.dumps(receipt,indent=2)+'\n')
 unknown=[w for w in words if 'UNDECODED' in w['fields']]
 print('Spans',len(spans),'listedwords',len(words),'unknown',len(unknown))
 for w in unknown:print(w)
if __name__=='__main__':main()
