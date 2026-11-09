"""Decode the original File1 sound lookup names, retaining their AFS ordinals."""
import hashlib,json,struct
from pathlib import Path
from audit_retail_effect_descriptors import elf_reader
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    source=ROOT/'game_data/SLUS_207.65';assert sha(source)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(source.read_bytes());aliases=[]
    for index in range(422):
        at=struct.unpack('<I',read(0x2337c0+4*index,4))[0];raw=bytearray()
        for offset in range(256):
            value=read(at+offset,1)[0]
            if not value:break
            raw.append(value^255)
        else:raise ValueError('Unbounded original alias')
        aliases.append(raw.decode('ascii'))
    text='// Immutable original aliases in sound AFS member order; not display names.\nconstexpr std::array<std::string_view,422> aliases{{\n'+''.join('    '+json.dumps(s)+',\n'for s in aliases)+'}};\n'
    target=ROOT/'game/native/gameplay_bank_loading/aliases_profile.inc';assert not target.exists();target.write_bytes(text.encode())
    out=ROOT/'build-native-sjuni/bank-alias-profile-v1';assert not out.exists();out.mkdir();(out/target.name).write_bytes(target.read_bytes());(out/'receipt.json').write_text(json.dumps({'schema':1,'status':'immutable extraction; original-body comparison required','source_sha256':sha(source),'aliases':aliases,'output_sha256':sha(target),'game_run':False},indent=2)+'\n');print(sha(target))
if __name__=='__main__':main()
