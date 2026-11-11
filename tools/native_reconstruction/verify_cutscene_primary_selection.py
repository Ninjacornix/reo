"""Compare full cinematic primary-choice orchestration with explicit clone ports."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True)
    a=p.parse_args();compiler=COMPILERS[a.compiler];out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes()
    originals=[];proof=[]
    for at,end in [(0x5f0c60,0x5f0ce4),(0x5f0cf0,0x5f0d84),(0x5f0d90,0x5f0dc0),(0x5f0dc0,0x5f1290),(0x5f1330,0x5f1384),(0x5f1400,0x5f1598)]:
        path=next((ROOT/'recomp/config/output_ovl/o2').glob(f'*_{at:08X}_*'));originals.append(path)
        proof.append(compare_source('complete primary character choice source',path.relative_to(ROOT).as_posix(),at,end,lambda address,size:raw[address-0x570000:address-0x570000+size]))
    package=ROOT/'build-native-sjuni/cutscene-descriptor-inventory-v2/owned_descriptors.bin';inventory=package.with_name('receipt.json');ir=json.loads(inventory.read_bytes())
    assert ir['status']=='static_layout_inventory'and ir['stats']['parsed_0950']==548 and sha(package)==ir['package_sha256']=='047d14cca0b28ad1f4335660db09389a525679c313f1841bfda1779c2c49629c'
    native=ROOT/'game/native/gameplay_scenario';source=native/'cutscene_primary_selection_tests.cpp';helper=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    pending=[source,native/'cutscene_primary_selection.hpp',native/'cutscene_actor_reservations.hpp',native/'cutscene_descriptor.cpp',native/'cutscene_actor_tracks.cpp',native/'CMakeLists.txt'];files=set(pending)
    # Freeze the actual transitive native header closure, including entity IDs
    # and stream declarations used by the retained descriptor parser.
    while pending:
        at=pending.pop()
        for name in re.findall(r'^#include "([^"]+)"',at.read_text(),re.M):
            path=(at.parent/name).resolve()
            if path.exists()and path.is_relative_to(ROOT)and path not in files:files.add(path);pending.append(path)
    files.update(originals+[Path(__file__),helper]);before={f.relative_to(ROOT).as_posix():sha(f)for f in sorted(files)};out.mkdir()
    for name in before:
        target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
    (out/'owned_descriptors.bin').write_bytes(package.read_bytes())
    reference=helper.read_text();body='\n'.join(f.read_text()for f in originals);actual={f.stem for f in originals};calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    reference+=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual))
    reference+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-actual))
    (out/'selection_reference.hpp').write_text(reference);(out/'original.cpp').write_text(body)
    for name in ['ps2_runtime.h','ps2_runtime_macros.h','ps2_recompiled_functions.h','o2_functions.h']:(out/name).write_text('#pragma once\n#include "selection_reference.hpp"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
    # Compile the exact three production immutable stream methods without the
    # unrelated live World scheduler methods later in their translation unit.
    # This is source extraction, not replacement behavior or a method stub.
    stream_source=(native/'cutscene_actor_tracks.cpp').read_text();marker='CutsceneActorTracks::CutsceneActorTracks('
    assert stream_source.count(marker)==1
    stream_prefix=stream_source.split(marker)[0];assert stream_prefix.count('CutsceneActorStream::')==3
    (out/'native_stream_import.cpp').write_text(stream_prefix+'}\n')
    common=[str(compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-I'+str(native),str(source),str(native/'cutscene_descriptor.cpp'),str(out/'native_stream_import.cpp')]
    commands=[('build-basic',common+['-o',str(out/'native.exe')]),('basic',[str(out/'native.exe'),str(out/'owned_descriptors.bin')]),('build-original',common+['-Wno-unused-label','-Wno-unused-parameter','-DREO_CUTSCENE_SELECTION_ORIGINAL=1','-I'+str(out),str(out/'original.cpp'),'-o',str(out/'compared.exe')]),('compared',[str(out/'compared.exe'),str(out/'owned_descriptors.bin')])]
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','')
    result=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(compiler),original_owned_bodies=proof,descriptor_inventory=dict(path=inventory.relative_to(ROOT).as_posix(),sha256=sha(inventory),package_sha256=sha(package)),commands=[],game_run=False,installed_in_game=False,stage4_complete=False,declared_ports=[
        'Complete5F1400 executes with bounded raw canonical records. Native choice preparation predicts matched slots, retirement requests and the subsequent roster mutations, not complete native Actor value cloning.',
        '5F1400 output metadata arguments are relocated into a nonoverlapping32-record fixture arena. This models native typed output storage; original overlapping arrays above16 groups are not admitted as a live storage contract.',
        '107C68/107AB0 are bounded fill/copy ports. Complete5F0C60/5F0CF0/5F0D90/5F1330 execute. 5EC270 resource retirement is observed, not implemented by the pure selector.',
        'Native preparation reports full with a selected prefix. Full/null-dereference original calls and invalid roster preferences do not execute.',
        'All548 owned0950 raw headers feed the original independently of native typed header decoding. Older0930/0940 are outside this profile.'])
    result['native_stream_source_extraction']=dict(path='game/native/gameplay_scenario/cutscene_actor_tracks.cpp',sha256=sha(native/'cutscene_actor_tracks.cpp'),prefix_sha256=hashlib.sha256(stream_prefix.encode()).hexdigest(),methods=['CutsceneActorStream::import','CutsceneActorStream::record','CutsceneActorStream::frame'],live_scheduler_executed=False)
    try:
        for name,command in commands:
            done=subprocess.run(command,env=env,capture_output=True,timeout=180);(out/(name+'.stdout.txt')).write_bytes(done.stdout);(out/(name+'.stderr.txt')).write_bytes(done.stderr)
            result['commands'].append(dict(command=command,exit_code=done.returncode));assert done.returncode==0,name+' '+(done.stdout+done.stderr).decode(errors='replace')[-2500:]
            if name in ['basic','compared']:result[name]=json.loads(done.stdout)
        assert all(sha(ROOT/name)==digest for name,digest in before.items());result.update(status='passed',source_unchanged=True)
    finally:
        result['output_sha256']={f.relative_to(out).as_posix():sha(f)for f in out.rglob('*')if f.is_file()};(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(status=result['status'],observed=result['compared'])))
if __name__=='__main__':main()
