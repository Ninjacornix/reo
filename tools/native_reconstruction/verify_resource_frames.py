"""Compare native resource callbacks against complete owned original bodies."""
import argparse, hashlib, json, os, re, struct, subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source, elf_reader
from verify_gameplay_collision import COMPILERS
ROOT = Path(__file__).resolve().parents[2]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    p = argparse.ArgumentParser()
    p.add_argument('--compiler', choices=COMPILERS, required=True)
    p.add_argument('--output', type=Path, required=True)
    args = p.parse_args(); out = args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
    elf = ROOT/'game_data/SLUS_207.65'; overlay = ROOT/'build-function-index/owned-overlays/o2.bin'
    assert sha(elf) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    assert sha(overlay) == '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    read = elf_reader(elf.read_bytes()); raw = overlay.read_bytes()
    addresses = [0x590be0,0x590c70,0x590d80,0x590ea0,0x5932f0,0x592770,0x591be0,0x5b43f0,0x5b1850,0x5b1a90,0x5c1120,0x5c11b0,0x5c12a0,0x591ae0,0x5b42b0,0x5921d0,
                 0x6b4420,0x6b45c0,0x6b4a30,0x1902d0,0x18fe20,0x18f570,0x1900e0,0x190060,
                 0x1904a0,0x191f80,0x190020,0x18feb0,0x1913e0]
    originals=[]; bodies=[]; proof=[]
    for at in addresses:
        directory='recomp/config/output' if at<0x570000 else 'recomp/config/output_ovl/o2'
        source=next((ROOT/directory).glob(f'*_{at:08X}_*')); text=source.read_text()
        end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',text)[1],16)
        proof.append(compare_source('complete reached resource owner/callback/math body',source.relative_to(ROOT).as_posix(),at,end,read if at<0x570000 else lambda pos,size:raw[pos-0x570000:pos-0x570000+size]))
        originals.append(source); bodies.append(text[text.index('// Function:'):])
    units=[ROOT/'game/native'/n for n in [
        'gameplay_world/resource_frames.cpp','gameplay_world/resource_models.cpp','gameplay_world/resource_programs.cpp',
        'gameplay_world/world.cpp','gameplay_world/linked_models.cpp','gameplay_world/auxiliary_actors.cpp','gameplay_world/scene_primary_actors.cpp','gameplay_world/bodies.cpp',
        'gameplay_world/model_poses.cpp','gameplay_world/model_constraints.cpp',
        'gameplay_actors/entity.cpp','gameplay_actors/input.cpp','gameplay_actors/health.cpp',
        'gameplay_collision/contact_packets.cpp','gameplay_collision/contact_content.cpp','gameplay_collision/collision.cpp','gameplay_collision/response.cpp',
        'gameplay_collision/actors.cpp','gameplay_collision/actor_views.cpp','gameplay_session/session.cpp',
        'gameplay_collision/ownership.cpp','gameplay_collision/sweep.cpp',
        'gameplay_scenario/scene_resources.cpp','gameplay_scenario/resource_templates.cpp','animation/weapon_program.cpp','animation/model_math.cpp',
        'gameplay_scenario/periodic_effects.cpp','gameplay_scenario/scene_controls.cpp','gameplay_scenario/flags.cpp','gameplay_tasks/tasks.cpp',
        'animation/model.cpp','animation/curves.cpp','animation/constraints.cpp','animation/constraint_math.cpp',
        'transform_math/transform_math.cpp']]
    tests=ROOT/'tools/native_reconstruction/resource_frames_tests.cpp'
    helper=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    paths=units+[tests,helper,Path(__file__),*originals]
    for source in paths:
        for include in re.findall(r'^\s*#include "([^"]+)"',source.read_text(),re.M):
            local=(source.parent/include).resolve(); dep=local if local.is_file() else (ROOT/include).resolve()
            if dep.is_file() and dep.is_relative_to(ROOT) and dep not in paths: paths.append(dep)
    before={n.relative_to(ROOT).as_posix():sha(n) for n in paths}; out.mkdir()
    for source in paths:
        target=out/'source'/source.relative_to(ROOT); target.parent.mkdir(parents=True,exist_ok=True); target.write_bytes(source.read_bytes())
    names={n.stem for n in originals}; calls=set(re.findall(r'\b((?:sub|o2)_[0-9A-F]+_0x[0-9a-f]+)\(','\n'.join(bodies)))
    reference=helper.read_text().replace('Register r[32];','std::uint64_t lo{},hi{},lo1{},hi1{};Register r[32];')
    reference+='\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n'
    reference+='\n'.join(f'void {n}(std::uint8_t*,R5900Context*,PS2Runtime*);' for n in sorted(names))+'\n'
    reference+='\n'.join(f'inline void {n}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}' for n in sorted(calls-names))+'\n'
    (out/'reference.hpp').write_text(reference)
    (out/'original.cpp').write_text('#include "reference.hpp"\n#pragma GCC diagnostic ignored "-Wunused-variable"\n'+'\n'.join(bodies))
    (out/'dispatch.inc').write_text('\n'.join(f'case 0x{at:x}:return {n.stem}(ram,ctx,runtime);' for at,n in zip(addresses,originals))+'\n')
    init='inline void owned_constants(std::uint8_t* p){\n'; constants={}
    for at,size in [(0x22fe20,32),(0x241c78,40)]:
        payload=read(at,size); constants[hex(at)]=payload.hex()
        init+='{const std::uint8_t bytes[]{'+','.join(str(v) for v in payload)+'};std::memcpy(p+'+str(at)+',bytes,sizeof bytes);}\n'
    (out/'owned_constants.hpp').write_text(init+'}\n')
    inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
    assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2'
    members=[m for m in json.loads(inventory.read_bytes()) if m.get('names') and m['names'][-1].endswith('.wmd')]
    assert len(members)==16
    with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as iso,(out/'owned_wmd.bin').open('wb') as data:
        data.write(struct.pack('<I',len(members)))
        for member in members:
            iso.seek(member['iso_offset']); payload=iso.read(member['bytes'])
            assert hashlib.sha256(payload).hexdigest()==member['sha256']
            data.write(struct.pack('<I',len(payload))+payload)
    template_members=[m for m in json.loads(inventory.read_bytes()) if any(n.lower().startswith('item') and n.lower().endswith('.dat') for n in m.get('names',[]))]
    assert len(template_members)==5
    with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as iso,(out/'owned_templates.bin').open('wb') as data:
        data.write(struct.pack('<I',len(template_members)))
        for member in template_members:
            iso.seek(member['iso_offset']);payload=iso.read(member['bytes']);assert hashlib.sha256(payload).hexdigest()==member['sha256']
            offset,size=struct.unpack_from('<II',payload,0);assert offset+size<=len(payload);section=payload[offset:offset+size];data.write(struct.pack('<I',len(section))+section)
    cc=COMPILERS[args.compiler]; exe=out/'frames.exe'
    command=[str(cc),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror',
             '-Wno-unused-parameter','-Wno-unused-label','-fno-fast-math','-ffp-contract=off',
             '-I'+str(out/'source'),'-I'+str(out),*[str(out/'source'/n.relative_to(ROOT)) for n in units],
             str(out/'source'/tests.relative_to(ROOT)),str(out/'original.cpp'),'-o',str(exe)]
    record=dict(schema=1,status='failed',game_run=False,source_sha256=before,original_word_audits=proof,
                compiler_sha256=sha(cc),owned_constants=constants,weapon_assets=members,template_assets=template_members,checks=[])
    env=dict(os.environ); env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','')
    try:
        for label,cmd in [('compile',command),('test',[str(exe),str(out/'owned_wmd.bin'),str(out/'owned_templates.bin')])]:
            result=subprocess.run(cmd,capture_output=True,env=env,timeout=180)
            (out/(label+'.stdout.txt')).write_bytes(result.stdout); (out/(label+'.stderr.txt')).write_bytes(result.stderr)
            record['checks'].append(dict(label=label,exit=result.returncode,command=cmd))
            if result.returncode: raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-5000:])
            if label=='test': record['results']=json.loads(result.stdout)
        record['source_drift']={n:sha(ROOT/n) for n,h in before.items() if sha(ROOT/n)!=h}
        assert not record['source_drift']; record['status']='passed'
    finally:
        record['output_sha256']={n.relative_to(out).as_posix():sha(n) for n in out.rglob('*') if n.is_file()}
        (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(record['results']))
if __name__=='__main__': main()
