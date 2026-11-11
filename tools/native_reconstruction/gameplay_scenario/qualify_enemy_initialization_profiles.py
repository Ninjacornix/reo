"""Reproduce owned model definitions and the three enemy priority banks."""
import argparse
import hashlib
from pathlib import Path
import struct

ROOT=Path(__file__).resolve().parents[3]
MODELS=ROOT/'game/native/gameplay_world/linked_model_definitions.inc'
PRIORITIES=ROOT/'game/native/gameplay_world/enemy_priority_profiles.inc'


def generate():
    zero=(ROOT/'build-function-index/owned-overlays/o0.bin').read_bytes()
    two=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
    assert hashlib.sha256(zero).hexdigest()=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'
    assert hashlib.sha256(two).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    roots=[struct.unpack_from('<II',zero,0x387e90-0x370000+8*index) for index in range(62)]
    pointers=sorted({pointer for pointer,count in roots}|{0x387e90})
    models=['// Initialized File #1 o0 model definitions. Reproduce with qualify_enemy_initialization_profiles.py.']
    for index,pointer in enumerate(pointers[:-1]):
        end=pointers[index+1]
        assert (end-pointer)%16==0 and 0x370000<=pointer<end<=0x370000+len(zero)
        count=(end-pointer)//16
        models.append('constexpr std::array<LinkedModelDefinition,'+str(count)+'> model_group_'+str(index)+'{{')
        for variant in range(count):
            at=pointer-0x370000+16*variant
            model,texture,sound=struct.unpack_from('<3B',zero,at)
            scale=struct.unpack_from('<I',zero,at+8)[0]
            visibility=struct.unpack_from('<b',zero,at+12)[0]
            models.append('    {'+','.join(map(str,(model,texture,sound)))+',std::bit_cast<float>('+hex(scale)+'u),'+str(visibility)+'},')
        models.append('}};')
    models.append('constexpr std::array<std::span<const LinkedModelDefinition>,62> model_definitions{{')
    for pointer,declared in roots:
        physical=(pointers[pointers.index(pointer)+1]-pointer)//16
        assert declared<=physical
        models.append('    model_group_'+str(pointers.index(pointer))+',')
    models.append('}};')
    priorities=['// Initialized File #1 o2 enemy priority banks. Reproduce with qualify_enemy_initialization_profiles.py.',
                'constexpr std::array<std::array<std::uint8_t,5>,24> enemy_priorities{{']
    for index in range(24):
        row=two[0x72f830-0x570000+5*index:0x72f830-0x570000+5*index+5]
        assert len(row)==5
        priorities.append('    {{'+','.join(map(str,row))+'}},')
    priorities.append('}};')
    return '\n'.join(models)+'\n','\n'.join(priorities)+'\n'


if __name__=='__main__':
    parser=argparse.ArgumentParser()
    parser.add_argument('--write',action='store_true')
    arguments=parser.parse_args()
    for path,text in zip((MODELS,PRIORITIES),generate()):
        if arguments.write:path.write_text(text,encoding='utf-8')
        assert path.read_text(encoding='utf-8')==text
        print(path.name,hashlib.sha256(path.read_bytes()).hexdigest())
