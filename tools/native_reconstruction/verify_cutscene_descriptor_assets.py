"""Qualify actual retained File1 DM reads and immutable native0950 imports."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from verify_gameplay_collision import COMPILERS
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
    files=[p for p in (ROOT/'game/native').rglob('*')if p.is_file() and (p.suffix in ['.cpp','.hpp','.h','.inc']or p.name=='CMakeLists.txt')]
    files+=[Path(__file__),ROOT/'runtime/assets/virtual_afs.h'];before={p.relative_to(ROOT).as_posix():sha(p)for p in files}
    out.mkdir()
    for name in before:
        target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
    manifest=out/'members.txt';manifest.write_text('\n'.join(lines)+'\n')
    result=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(compiler),inventory=dict(path=str(inventory),sha256=sha(inventory)),game_run=False,installed_in_game=False,stage4_complete=False,commands=[])
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+str(a.cmake.parent)+os.pathsep+env.get('PATH','')
    targets=['cutscene_descriptor_assets_tests','gameplay_actor_assets_tests','scripted_motion_assets_tests','gameplay_target_metrics_tests','gameplay_cooperative_events_tests','gameplay_collision_workers_tests','gameplay_ai_owner_tests']
    regex='^(native_cutscene_descriptor_assets|native_gameplay_actor_assets|native_scripted_motion_assets|native_gameplay_target_metrics|native_gameplay_cooperative_events|native_gameplay_collision_workers|native_gameplay_ai_owner)$'
    commands=[('configure',[str(a.cmake),'-S',str(ROOT/'game/native'),'-B',str(build)]),('build',[str(a.cmake),'--build',str(build),'--parallel','2','--target',*targets]),('owned',[str(build/'gameplay_scenario/cutscene_descriptor_assets_tests.exe'),str(archive),str(manifest)]),('parents',[str(a.cmake.parent/'ctest.exe'),'--test-dir',str(build),'-R',regex,'--output-on-failure'])]
    try:
        for name,command in commands:
            done=subprocess.run(command,env=env,capture_output=True,timeout=240)
            (out/(name+'.stdout.txt')).write_bytes(done.stdout);(out/(name+'.stderr.txt')).write_bytes(done.stderr)
            result['commands'].append(dict(command=command,exit_code=done.returncode));assert done.returncode==0,name+' '+(done.stdout+done.stderr).decode(errors='replace')[-3000:]
            if name=='owned':result['observed']=json.loads(done.stdout)
            if name=='parents':assert b'100% tests passed, 0 tests failed out of 7'in done.stdout
        assert (archive.stat().st_size,archive.stat().st_mtime_ns)==stamp
        assert all(sha(ROOT/name)==digest for name,digest in before.items())
        result.update(status='passed',source_unchanged=True)
    finally:
        result['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(status=result['status'],observed=result['observed'])))
if __name__=='__main__':main()
