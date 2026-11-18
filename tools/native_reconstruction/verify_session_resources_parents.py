"""Current application resource integration,31 parent contracts and owned callers."""
import argparse,hashlib,json,os,subprocess
from pathlib import Path
from verify_gameplay_collision import COMPILERS
from verify_dialogue_response_parents import sources
ROOT=Path(__file__).resolve().parents[2]
CMAKE=Path('C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
    build=ROOT/'build-native-sjuni'/f'gameplay-native-{a.compiler}-v1';compiler=COMPILERS[a.compiler]
    prior=json.loads((ROOT/'build-native-sjuni'/f'dialogue-response-parents-{a.compiler}-v2/receipt.json').read_text());assert prior['status']=='passed'and prior['parent_tests']==30
    targets=prior['commands'][1][4:-2]+['projectile_trail_owner_tests'];assert len(set(targets))==31
    pattern=prior['commands'][2][-1][:-2]+'|projectile_trail_owner)$'
    targets+=['session_resources_tests','cutscene_actor_speech_assets_tests','cutscene_room_lighting_assets_tests']
    record=dict(schema='reo.native.session_resources.parents.v1',status='failed',parent_tests=31,game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,commands=[],compiler_sha256=sha(compiler))
    env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''))
    def run(command,label):
        command=list(map(str,command));done=subprocess.run(command,capture_output=True,env=env,timeout=600)
        (out/(label+'.log')).write_bytes(done.stdout+done.stderr);record['commands'].append(command)
        assert done.returncode==0,label+': '+(done.stdout+done.stderr).decode(errors='replace')[-4000:]
        return done.stdout.decode().strip()
    try:
        run([CMAKE,'-S',ROOT/'game/native','-B',build],'configure')
        paths=set(sources(build,targets))|{Path(__file__).resolve()};before={p.relative_to(ROOT).as_posix():sha(p)for p in paths};record['source_sha256']=before
        run([CMAKE,'--build',build,'--target',*targets,'--parallel','2'],'build')
        result=run([CMAKE.parent/'ctest.exe','--test-dir',build,'--output-on-failure','-R',pattern],'tests');assert '100% tests passed, 0 tests failed out of 31'in result
        inventory=json.loads((ROOT/'build-native-sjuni/gameplay-script-content-llvm-v21/inventory.json').read_text());archive=Path(inventory[0]['archive']);identity=(archive.stat().st_size,archive.stat().st_mtime_ns)
        record['dialogue_worker']=run([build/'gameplay_application/dialogue_workers_tests.exe',archive],'owned-dialogue-worker')
        content=ROOT/'build-native-sjuni/gameplay-contact-content-llvm-v2/contact-content-v1.bin';effect=ROOT/'build-native-sjuni/resource-flight-owner-llvm-v4/owned_effect_geometry.bin'
        record['resources']=json.loads(run([build/'gameplay_application/session_resources_tests.exe',archive,content,effect],'owned-resources'))
        speech=ROOT/'build-native-sjuni/cutscene-actor-speech-llvm-v4';speech_receipt=json.loads((speech/'receipt.json').read_text());assert speech_receipt['status']=='passed'
        lights=ROOT/'build-native-sjuni/cutscene-room-lighting-llvm-v4';light_receipt=json.loads((lights/'receipt.json').read_text());assert light_receipt['status']=='passed'
        manifests=[speech/'assets.txt',speech/'models.txt',lights/'resources.txt'];record['manifest_sha256']={str(p.relative_to(ROOT)):sha(p)for p in manifests}
        for path in manifests:assert sha(path)==(speech_receipt if path.parent==speech else light_receipt)['output_sha256'][path.name]
        record['speech']=json.loads(run([build/'gameplay_scenario/cutscene_actor_speech_assets_tests.exe',archive,*manifests[:2]],'owned-speech'))
        record['room_lighting']=json.loads(run([build/'gameplay_scenario/cutscene_room_lighting_assets_tests.exe',archive,manifests[2]],'owned-room-lighting'))
        assert identity==(archive.stat().st_size,archive.stat().st_mtime_ns)
        record['owned_archive_identity']=dict(bytes=identity[0],mtime_ns=identity[1]);record['source_drift']={n:sha(ROOT/n)for n,digest in before.items()if sha(ROOT/n)!=digest};assert not record['source_drift'];record['status']='passed'
    finally:
        record['output_sha256']={p.name:sha(p)for p in out.iterdir()if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(dict(status=record['status'],parent_tests=31,resources=record.get('resources'),speech=record.get('speech'),room_lighting=record.get('room_lighting'))))
if __name__=='__main__':main()
