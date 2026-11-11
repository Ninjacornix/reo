"""Reproduce owned model definitions and the three enemy priority banks."""
import argparse
import hashlib
from pathlib import Path
import struct

ROOT=Path(__file__).resolve().parents[3]
MODELS=ROOT/'game/native/gameplay_world/linked_model_definitions.inc'
PRIORITIES=ROOT/'game/native/gameplay_world/enemy_priority_profiles.inc'


def append_model_bank(models,raw,directory,prefix):
    roots=[struct.unpack_from('<II',raw,directory-0x370000+8*index) for index in range(62)]
    pointers=sorted({pointer for pointer,count in roots if pointer}|{directory})
    for index,pointer in enumerate(pointers[:-1]):
        declared=max(count for root,count in roots if root==pointer)
        end=max(pointers[index+1],pointer+16*declared)
        assert end<=directory
        assert (end-pointer)%16==0 and 0x370000<=pointer<end<=0x370000+len(raw)
        count=(end-pointer)//16
        models.append('constexpr std::array<LinkedModelDefinition,'+str(count)+'> '+prefix+'group_'+str(index)+'{{')
        for variant in range(count):
            at=pointer-0x370000+16*variant
            model,texture,sound=struct.unpack_from('<3B',raw,at)
            scale=struct.unpack_from('<I',raw,at+8)[0]
            visibility=struct.unpack_from('<b',raw,at+12)[0]
            construction=raw[at+4]
            shadow,shadow_asset=struct.unpack_from('<bh',raw,at+13)
            models.append('    {'+','.join(map(str,(model,texture,sound)))+',std::bit_cast<float>('+hex(scale)+'u),'+str(visibility)+','+str(construction)+','+str(shadow)+','+str(shadow_asset)+'},')
        models.append('}};')
    models.append('constexpr std::array<std::span<const LinkedModelDefinition>,62> '+prefix+'definitions{{')
    for pointer,declared in roots:
        if not pointer:
            assert not declared
            models.append('    std::span<const LinkedModelDefinition>{},')
            continue
        models.append('    '+prefix+'group_'+str(pointers.index(pointer))+',')
    models.append('}};')


def generate():
    zero=(ROOT/'build-function-index/owned-overlays/o0.bin').read_bytes()
    two=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
    assert hashlib.sha256(zero).hexdigest()=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'
    assert hashlib.sha256(two).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    models=['// Initialized File #1 o0 model definitions. Reproduce with qualify_enemy_initialization_profiles.py.']
    append_model_bank(models,zero,0x387e90,'model_')
    append_model_bank(models,zero,0x3887f0,'alternate_model_')
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
