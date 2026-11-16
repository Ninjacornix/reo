"""Reproduce ordinary File1 definition byte5 for actual ground-effect node selection."""
import hashlib,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def source_profile(raw):
 assert hashlib.sha256(raw).hexdigest()=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'
 rows=[struct.unpack_from('<II',raw,0x387e90-0x370000+8*i)for i in range(62)]
 pointers=sorted({ptr for ptr,count in rows if ptr}|{0x387e90});groups=[]
 for i,ptr in enumerate(pointers[:-1]):
  count=max(count for p,count in rows if p==ptr);end=max(pointers[i+1],ptr+16*count);assert end<=0x387e90 and (end-ptr)%16==0
  flags=[raw[ptr-0x370000+16*j+5]for j in range((end-ptr)//16)]
  groups.append('constexpr std::array<std::uint8_t,'+str(len(flags))+'> attachment_flags_'+str(i)+'{{'+','.join(map(str,flags))+'}};')
 groups.append('constexpr std::array<std::span<const std::uint8_t>,62> attachment_flags{{')
 for ptr,count in rows:groups.append('    '+('attachment_flags_'+str(pointers.index(ptr))if ptr else 'std::span<const std::uint8_t>{}')+',')
 groups.append('}};')
 return '// Actual file-backed ordinary definition byte5, directory387E90; source image identity is sealed by verification.\n'+'\n'.join(groups)+'\n'
def main():
 p=ROOT/'game/native/gameplay_world/ground_pose_attachment_profile.inc';body=source_profile((ROOT/'build-function-index/owned-overlays/o0.bin').read_bytes())
 if p.exists():assert p.read_text()==body
 else:p.write_text(body)
 print(hashlib.sha256(p.read_bytes()).hexdigest())
if __name__=='__main__':main()
