"""Bind native model scales to owned loader words, archive names and o2 data."""
import argparse,hashlib,json,re,struct,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/assets'));sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from afs_inspect import read_toc
from audit_retail_effect_descriptors import compare_source,elf_reader
sha=lambda b:hashlib.sha256(b).hexdigest()

def main():
 p=argparse.ArgumentParser();p.add_argument('--data',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--write-include',action='store_true');a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 manifest=a.data.parent/'import.json';assert sha(manifest.read_bytes())=='ae3668c7e98defe0eb16ce107490078451e9c2f57cb2fb87c162f37520f2600b'
 overlay=ROOT/'build-function-index/owned-overlays/o2.bin';raw=overlay.read_bytes();assert sha(raw)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';elf=ROOT/'game_data/SLUS_207.65';blob=elf.read_bytes();assert sha(blob)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
 source='recomp/config/output/sub_001AA740_0x1aa740.cpp';s=(ROOT/source).read_text();begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',s).groups()];proof=compare_source('actual NPC filename uses BB4-1 at1AA7B0 and N%02d/N%d formatting',source,begin,end,elf_reader(blob))
 with(a.data/'NETBIO00.DAT').open('rb')as f:
  top=read_toc(f,0);base=top[0][0][0];toc=read_toc(f,base);names=[n for n,size in toc[2]if re.fullmatch(r'n\d+\.nbd',n,re.I)];ids=sorted({int(re.fullmatch(r'n(\d+)\.nbd',n,re.I)[1])+1 for n in names});assert len(ids)==125
  high_names=[n for n,size in toc[2]if re.fullmatch(r'hn\d+\.nbd',n,re.I)];assert len(high_names)==108
  high_ids={int(re.fullmatch(r'hn(\d+)\.nbd',n,re.I)[1])for n in high_names};ids=sorted(set(ids)|(high_ids-{0}));assert len(ids)==150
  offset,length=toc[1];f.seek(base+offset);name_bytes=f.read(length);assert len(name_bytes)==length
 player=[struct.unpack_from('<I',raw,0x71ae00+12*i-0x570000)[0]for i in range(8)];variants=[(i,struct.unpack_from('<I',raw,0x716444+20*i-0x570000)[0])for i in ids]
 text='// Generated from the qualified File1 native model-scale profile.\nconstexpr std::array<std::uint32_t,8> player_scale_bits{'+','.join(hex(v)+'u'for v in player)+'};\nconstexpr std::array<ScaleEntry,150> variant_scale_bits{{\n'+''.join('    {'+str(i)+','+hex(v)+'u},\n'for i,v in variants)+'}};\n'
 include=ROOT/'game/native/gameplay_world/model_scale_profile.inc'
 if a.write_include:include.write_text(text)
 assert include.read_text()==text
 out.mkdir(parents=True);(out/'model_scale_profile.inc').write_bytes(include.read_bytes());(out/'source_qualify_model_scale_profile.py').write_bytes(Path(__file__).read_bytes())
 extra_proofs=[]
 for address,end in [(0x6837c0,0x683a88),(0x5d6fc0,0x5d7118)]:
  path=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{address:08X}_*'));body=path.read_text();actual_begin,actual_end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',body).groups()];extra_proofs.append(compare_source('NPC constructor raw identity and height-correction variant table authority',path.relative_to(ROOT).as_posix(),actual_begin,actual_end,lambda at,n:raw[at-0x570000:at-0x570000+n]))
 q=dict(schema=1,status='passed',tool_sha256=sha(Path(__file__).read_bytes()),import_manifest=dict(path=str(manifest.resolve()),sha256=sha(manifest.read_bytes())),overlay_sha256=sha(raw),main_elf_sha256=sha(blob),loader_owned_words=proof,high_npc_owned_words=extra_proofs,archive_name_table=dict(path=str((a.data/'NETBIO00.DAT').resolve()),offset=base+offset,bytes=length,sha256=sha(name_bytes)),npc_asset_names=names,high_npc_asset_names=high_names,high_npc_zero_variant='HN00 uses character correction because variant0 selects the character branch; no variant0 row is admitted.',player_scale_bits=player,variant_scale_bits=variants,output_sha256=sha(include.read_bytes()),game_run=False,limits=['Metadata maps BB4 to NPC filename indexBB4-1 and exact owned scale-table bytes; it does not prove every NPC model/animation path reconstructed.','Unsupported character/variant IDs refuse lookup; absent data is not replaced by1.'])
 (out/'receipt.json').write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(status=q['status'],variants=len(ids),receipt_sha256=sha((out/'receipt.json').read_bytes()))))
if __name__=='__main__':main()
