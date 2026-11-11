"""Qualify native kind2 cutscene construction with owned assets and original routing."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from verify_gameplay_collision import COMPILERS
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser()
    p.add_argument('--compiler',choices=COMPILERS,required=True)
    for name in ['build','cmake','data-root','inventory','output']:p.add_argument('--'+name,type=Path,required=True)
    a=p.parse_args();out=a.output.resolve();build=a.build.resolve();compiler=COMPILERS[a.compiler]
    assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
    configured=re.search(r'^CMAKE_CXX_COMPILER:[^=]+=([^\n]+)',(build/'CMakeCache.txt').read_text(),re.M)[1]
    assert Path(configured.strip()).resolve()==compiler.resolve()
    inventory=a.inventory.resolve()/'receipt.json';receipt=json.loads(inventory.read_bytes())
    assert receipt['status']=='static_layout_inventory' and len(receipt['rows'])==690 and receipt['stats']['parsed_0950']==548
    assert sha(a.inventory/'owned_descriptors.bin')==receipt['package_sha256']=='047d14cca0b28ad1f4335660db09389a525679c313f1841bfda1779c2c49629c'
    archive=a.data_root/'NETBIO00.DAT';stamp=archive.stat().st_size,archive.stat().st_mtime_ns
    lines=[]
    with archive.open('rb')as stream:
        for row in receipt['rows']:
            stream.seek(row['offset']);raw=stream.read(row['bytes']);assert hashlib.sha256(raw).hexdigest()==row['sha256']
            match=re.fullmatch(r'dm(\d{2})(\d{2})([a-z])\.bin',row['name'].lower());assert match
            lines.append(f"{row['scenario']} {int(match[1])} {int(match[2])} {ord(match[3])-97} {row['offset']} {row['bytes']} {int(row['version'])}")
    original=ROOT/'recomp/config/output_ovl/o2/o2_005F0610_0x5f0610.cpp';overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';binary=overlay.read_bytes()
    proof=compare_source('complete scene construction body, selectedkind2 routes',original.relative_to(ROOT).as_posix(),0x5f0610,0x5f0b50,lambda at,n:binary[at-0x570000:at-0x570000+n])
    admission_path=ROOT/'build-native-sjuni/cutscene-model-admission-v1/receipt.json';admission=json.loads(admission_path.read_bytes());assert admission['status']=='passed' and sha(ROOT/'game/native/gameplay_world/cutscene_model_definitions.inc')==admission['output_sha256']
    zero=(ROOT/'build-function-index/owned-overlays/o0.bin').read_bytes();assert hashlib.sha256(zero).hexdigest()==admission['overlay_sha256']
    admitted=['#pragma once','#include <array>','#include <cstdint>','struct AdmittedModelRow{std::uint8_t type;std::uint16_t variant;std::array<std::uint8_t,16> bytes;};','constexpr std::array<AdmittedModelRow,7> admitted_model_rows{{']
    for row in admission['rows']:
        at=int(row['address'],16)-0x370000;raw=zero[at:at+16];assert raw.hex()==row['bytes'];admitted.append('{'+str(row['type'])+','+str(row['variant'])+',{{'+','.join(map(str,raw))+'}}},')
    admitted.append('}};')
    files=[p for p in (ROOT/'game/native').rglob('*')if p.is_file() and (p.suffix in ['.cpp','.hpp','.h','.inc']or p.name=='CMakeLists.txt')]
    files+=[Path(__file__),original,ROOT/'runtime/assets/virtual_afs.h',ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp',ROOT/'tools/native_reconstruction/cutscene_scripted_reference_tests.inc',ROOT/'tools/native_reconstruction/generate_cutscene_model_admission.py'];before={p.relative_to(ROOT).as_posix():sha(p)for p in files}
    out.mkdir()
    for name in before:
        target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
    (out/'admitted_model_rows.hpp').write_text('\n'.join(admitted)+'\n')
    body=original.read_text();reference=(ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n'
    reference+='void o2_005F0610_0x5f0610(std::uint8_t*,R5900Context*,PS2Runtime*);\n'
    for name in sorted(set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))):
        reference+='inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r); }\n'
    (out/'reference.hpp').write_text(reference);(out/'original.cpp').write_text('#include "reference.hpp"\n'+body[body.index('// Function:'):]);(out/'cutscene_scripted_reference_tests.inc').write_bytes((ROOT/'tools/native_reconstruction/cutscene_scripted_reference_tests.inc').read_bytes())
    manifest=out/'members.txt';manifest.write_text('\n'.join(lines)+'\n')
    result=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(compiler),inventory=dict(path=str(inventory),sha256=sha(inventory)),original_owned_body=proof,admitted_model_rows=dict(path=str(admission_path),sha256=sha(admission_path)),original_observation_ports=['5F0DC0 primary actor selection unexecuted in nativekind2 owner','5F0C00 primary backup omitted from selectedkind2 comparison','6BA5C0 constructor argument/return observation; actual native factory tested separately'],game_run=False,installed_in_game=False,stage4_complete=False,commands=[])
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+str(a.cmake.parent)+os.pathsep+env.get('PATH','')
    targets=['cutscene_scripted_construction_tests','cutscene_descriptor_assets_tests','gameplay_actor_assets_tests','scripted_motion_assets_tests','gameplay_target_metrics_tests','gameplay_cooperative_events_tests','gameplay_collision_workers_tests','gameplay_ai_owner_tests']
    regex='^(native_cutscene_scripted_construction|native_cutscene_descriptor_assets|native_gameplay_actor_assets|native_scripted_motion_assets|native_gameplay_target_metrics|native_gameplay_cooperative_events|native_gameplay_collision_workers|native_gameplay_ai_owner)$'
    commands=[('configure',[str(a.cmake),'-S',str(ROOT/'game/native'),'-B',str(build),'-DREO_CUTSCENE_SCRIPTED_REFERENCE_DIR='+str(out)]),('build',[str(a.cmake),'--build',str(build),'--parallel','2','--target',*targets]),('owned',[str(build/'gameplay_update/cutscene_scripted_construction_tests.exe'),str(archive),str(manifest)]),('parents',[str(a.cmake.parent/'ctest.exe'),'--test-dir',str(build),'-R',regex,'--output-on-failure'])]
    try:
        for name,command in commands:
            done=subprocess.run(command,env=env,capture_output=True,timeout=240)
            (out/(name+'.stdout.txt')).write_bytes(done.stdout);(out/(name+'.stderr.txt')).write_bytes(done.stderr)
            result['commands'].append(dict(command=command,exit_code=done.returncode));assert done.returncode==0,name+' '+(done.stdout+done.stderr).decode(errors='replace')[-3000:]
            if name=='owned':result['observed']=json.loads(done.stdout)
            if name=='parents':assert b'100% tests passed, 0 tests failed out of 8'in done.stdout
        assert (archive.stat().st_size,archive.stat().st_mtime_ns)==stamp
        assert all(sha(ROOT/name)==digest for name,digest in before.items())
        result.update(status='passed',source_unchanged=True)
    finally:
        result['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(status=result['status'],observed=result['observed'])))
if __name__=='__main__':main()
