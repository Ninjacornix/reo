"""Native gameplay audio against unchanged owned callers and real bank Session."""
import argparse
import hashlib
import json
import os
import re
import subprocess
import struct
from pathlib import Path
from audit_retail_effect_descriptors import compare_source, elf_reader
from verify_gameplay_collision import COMPILERS

ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler', choices=COMPILERS, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--animation-frontends',action='store_true')
    parser.add_argument('--surface-frontends',action='store_true')
    args = parser.parse_args()
    args.animation_frontends=args.animation_frontends or args.surface_frontends
    out = args.output.resolve()
    allowed = (ROOT / 'build-native-sjuni').resolve()
    if out.exists() or out == allowed or not out.is_relative_to(allowed):
        raise ValueError('Fresh private output required')
    image = ROOT / 'game_data/SLUS_207.65'
    if sha(image) != '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46':
        raise ValueError('Owned executable changed')
    read = elf_reader(image.read_bytes())
    addresses = [0x1ac7f0,0x1acb60,0x1aec80,0x1acfb0,0x1ad220,
                 0x1a7310,0x1a7430,0x1a7550,0x1b8d40,0x1b93d0,0x1b94b0,
                 0x191ab0,0x1aceb0,0x1acf60,0x1b86f0,0x1b8780]
    if args.animation_frontends:addresses += [0x1b8bb0,0x1b8b20,0x1b8c70]
    if args.surface_frontends:addresses += [0x1b8d70,0x1b8f40]
    bodies, originals, audits = [], [], []
    for at in addresses:
        source = ROOT / f'recomp/config/output/sub_{at:08X}_0x{at:x}.cpp'
        text = source.read_text()
        end = int(re.search(r'// Address: 0x[0-9a-fA-F]+ - 0x([0-9a-fA-F]+)', text)[1],16)
        audits.append(compare_source('native-gameplay-audio',source.relative_to(ROOT).as_posix(),at,end,read))
        originals.append(source)
        bodies.append(text[text.index('// Function:'):])
    if args.animation_frontends:
        overlay=ROOT/'build-function-index/owned-overlays/o2.bin'
        assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
        raw=overlay.read_bytes();source=ROOT/'recomp/config/output_ovl/o2/o2_005B4CE0_0x5b4ce0.cpp';text=source.read_text()
        end=int(re.search(r'// Address: 0x[0-9a-fA-F]+ - 0x([0-9a-fA-F]+)',text)[1],16)
        audits.append(compare_source('actual resource sound selector',source.relative_to(ROOT).as_posix(),0x5b4ce0,end,lambda at,n:raw[at-0x570000:at-0x570000+n]))
        originals.append(source);bodies.append(text[text.index('// Function:'):])
    production = list((ROOT/'game/native/gameplay_audio').glob('*'))
    dependencies = [ROOT/'game/native'/d/n for d,n in [
        ('gameplay_session','session.hpp'),('gameplay_session','session.cpp'),
        ('transform_math','transform_math.hpp'),('transform_math','transform_math.cpp')]]
    dependencies += list((ROOT/'game/native/audio_banks/v2').glob('*.hpp'))
    dependencies += [ROOT/'game/native/audio_banks/v2'/n for n in ['algorithms.cpp','session.cpp']]
    dependencies += list((ROOT/'game/native/audio_banks').glob('source*.inc'))
    dependencies += [ROOT/'game/native/gameplay_scenario'/n for n in ['stream_channels.hpp','stream_channels.cpp']]
    inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
    if sha(inventory)!='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2':
        raise ValueError('Owned member inventory changed')
    members=[m for m in json.loads(inventory.read_text()) if m.get('names') and m['names'][-1].lower().endswith('.snd')]
    helper=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    tests=ROOT/'tools/native_reconstruction/gameplay_audio_tests.cpp'
    paths=[p for p in production if p.is_file()]+dependencies+[helper,tests,Path(__file__),inventory,*originals]
    frontend_units=[]
    if args.animation_frontends:
        from effect_work_sources import SURFACE_WORLD_UNITS
        frontend_units=[ROOT/n for n in SURFACE_WORLD_UNITS if '/gameplay_effects/' not in n]
        frontend_units += [ROOT/'game/native'/n for n in ['gameplay_world/animation_audio.cpp','gameplay_world/footwear.cpp','gameplay_scenario/scene_resources.cpp','gameplay_scenario/resource_templates.cpp','gameplay_collision/regions.cpp','gameplay_actors/entity.cpp','animation/model.cpp','animation/model_math.cpp','animation/curves.cpp','transform_math/transform_math.cpp']]
        paths += frontend_units+[ROOT/'tools/native_reconstruction/animation_audio_tests.inc',ROOT/'tools/native_reconstruction/effect_work_sources.py']
    if args.surface_frontends:
        frontend_units += [ROOT/'game/native/gameplay_collision'/n for n in ['regions.cpp','room_objects.cpp']]
        paths += frontend_units+[ROOT/'tools/native_reconstruction/surface_audio_tests.inc',ROOT/'game/native/gameplay_world/model_scale_profile.inc',ROOT/'tools/native_reconstruction/generate_footwear_profile.py']
    paths=list(dict.fromkeys(paths))
    for source in paths:
        for include in re.findall(r'^\s*#include "([^"]+)"',source.read_text(),re.M):
            local=(source.parent/include).resolve();target=local if local.is_file() else (ROOT/include).resolve()
            if target.is_file() and target.is_relative_to(ROOT) and target not in paths:paths.append(target)
    inputs={p.relative_to(ROOT).as_posix():sha(p) for p in paths}
    names={f'sub_{at:08X}_0x{at:x}' for at in addresses}
    if args.animation_frontends:names.add('o2_005B4CE0_0x5b4ce0')
    all_calls=set(re.findall(r'\b((?:sub|o2)_[0-9A-F]+_0x[0-9a-f]+)\(', '\n'.join(bodies)))
    header=helper.read_text().replace('Register r[32];','Register r[32];std::uint64_t hi{},lo{};')
    header+='\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n#define SRA32(a,b) (std::bit_cast<std::int32_t>(std::uint32_t(a)) >> unsigned(b))\n#define FPU_CVT_W_S(a) _mm_cvttss_si32(_mm_set_ss(a))\n'
    header+='\n'.join(f'void {name}(std::uint8_t*,R5900Context*,PS2Runtime*);' for name in sorted(names))+'\n'
    for name in sorted(all_calls-names):
        header+=f'inline void {name}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}\n'
    out.mkdir()
    for source in paths:
        target=out/'source'/source.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(source.read_bytes())
    with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as source, (out/'owned_sounds.bin').open('wb') as corpus:
        corpus.write(struct.pack('<I',len(members)))
        for member in members:
            source.seek(member['iso_offset']);data=source.read(member['bytes'])
            if hashlib.sha256(data).hexdigest()!=member['sha256']:raise ValueError('Owned sound bytes changed')
            corpus.write(struct.pack('<I',len(data)));corpus.write(data)
    (out/'owned_sounds.json').write_text(json.dumps(members,indent=2)+'\n')
    owned_tables=read(0x234bf0,16)
    for at in struct.unpack('<4I',owned_tables):
        owned_tables+=read(at,68)
    owned_tables+=read(0x250230,4)
    (out/'owned_attenuation.bin').write_bytes(owned_tables)
    if args.surface_frontends:
        raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
        (out/'owned_footwear.bin').write_bytes(raw[0x7313c0-0x570000:0x7313c0-0x570000+2*208])
        receipt=ROOT/'build-native-sjuni/footwear-profile-v1/receipt.json';profile=json.loads(receipt.read_bytes());assert profile['output_sha256']==sha(ROOT/'game/native/gameplay_world/footwear_profile.inc')
    (out/'audio_reference.hpp').write_text(header)
    original=out/'original.cpp'
    original.write_text('#include "audio_reference.hpp"\n#pragma GCC diagnostic ignored "-Wunused-variable"\n'+'\n'.join(bodies))
    compiler=COMPILERS[args.compiler]
    executable=out/'audio.exe'
    sources=[ROOT/'game/native/gameplay_audio'/n for n in ['routing.cpp','import.cpp','spatial.cpp','owner.cpp','options.cpp']]
    sources += [ROOT/'game/native/gameplay_session/session.cpp',ROOT/'game/native/audio_banks/v2/session.cpp',ROOT/'game/native/audio_banks/v2/algorithms.cpp',ROOT/'game/native/gameplay_scenario/stream_channels.cpp',tests,original]
    sources=list(dict.fromkeys(sources+frontend_units))
    sources=[out/'source'/p.relative_to(ROOT) if p.is_relative_to(ROOT) and not p.is_relative_to(out) else p for p in sources]
    command=[str(compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-msse4.1','-I'+str(out/'source'),'-I'+str(out),*[str(p) for p in sources],'-o',str(executable)]
    if args.animation_frontends:command+=['-DREO_ANIMATION_AUDIO_TESTS=1']
    if args.surface_frontends:command+=['-DREO_SURFACE_AUDIO_TESTS=1']
    record=dict(schema=1,status='failed',source_sha256=inputs,compiler_sha256=sha(compiler),original_word_audits=audits,game_launched=False,checks=[])
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','')
    try:
        for label,cmd in [('compile',command),('test',[str(executable),str(out/'owned_sounds.bin'),str(out/'owned_attenuation.bin')])]:
            result=subprocess.run(cmd,capture_output=True,env=env,timeout=180)
            (out/(label+'.stdout.txt')).write_bytes(result.stdout)
            (out/(label+'.stderr.txt')).write_bytes(result.stderr)
            record['checks'].append(dict(label=label,command=cmd,exit=result.returncode))
            if result.returncode:
                raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-6000:])
            if label=='test': record['results']=json.loads(result.stdout)
        record['source_drift']={name:sha(ROOT/name) for name,digest in inputs.items() if sha(ROOT/name)!=digest}
        if record['source_drift']: raise ValueError('Source changed')
        record['status']='passed'
    finally:
        record['output_sha256']={p.relative_to(out).as_posix():sha(p) for p in out.rglob('*') if p.is_file()}
        (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(record['results']))


if __name__=='__main__':
    main()
