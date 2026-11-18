"""Qualify intermediate cinematic physical-model continuation on owned assets.

Builds a fresh source snapshot; unrelated parallel live edits are recorded rather
than mixed into the compiled proof. Existing complete original cache/entry bodies
still execute, with their declared independent initialization/resource ports.
"""
import argparse, hashlib, json, os, re, shutil, subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source, elf_reader

ROOT=Path(__file__).resolve().parents[2]
CMAKE=Path('C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe')
NINJA=CMAKE.parent.parent.parent/'Ninja/ninja.exe'
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    parser=argparse.ArgumentParser();parser.add_argument('--compiler',type=Path,required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    out=args.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
    prior=ROOT/'build-native-sjuni/primary-scene-scope-llvm-v4';receipt=json.loads((prior/'receipt.json').read_bytes());assert receipt['status']=='passed'
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';main_read=elf_reader(elf.read_bytes())
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes()
    read=lambda at,n:raw[at-0x570000:at-0x570000+n] if at>=0x570000 else main_read(at,n)
    proof=[]
    for row in receipt['original_owned_bodies']:
        path=ROOT/row['path'];text=path.read_text();begin,end=(int(value,16) for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',text).groups())
        proof.append(compare_source('complete inherited primary-model reference body',path.relative_to(ROOT).as_posix(),begin,end,read))
    for address in (0x5ee680,0x5ed770):
        path=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{address:08X}_*'));begin,end=(int(value,16) for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups())
        proof.append(compare_source('static enclosing queued/final lifecycle ordering; not a new complete native scene owner',path.relative_to(ROOT).as_posix(),begin,end,read))
    record=dict(schema=1,status='failed',compiler_sha256=sha(args.compiler),original_owned_bodies=proof,prior_reference_receipt_sha256=sha(prior/'receipt.json'),game_run=False,stage4_complete=False,limits=['Exercises actual native physical resources through two consecutive scene epochs, retained old model leases and the next original5F0C00 comparison.','The enclosing5EE680/5ED770 bodies are static call-order evidence in this cohort, not complete native scene construction/retirement proof.','Inherited source model/cache comparisons retain their declared archive/render/initializer/resource observation ports.'])
    try:
        source=out/'source'
        for name in ('game/native','runtime','tools/native_reconstruction','recomp/overrides/native_banks'):shutil.copytree(ROOT/name,source/name,ignore=shutil.ignore_patterns('__pycache__'))
        for name in ('primary_models_original.cpp','primary_models_reference.hpp','ps2_runtime.h','ps2_runtime_macros.h','ps2_recompiled_functions.h','o2_functions.h','ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h','scenes.txt'):shutil.copy2(prior/name,out/name)
        shutil.copy2(ROOT/'tools/native_reconstruction/primary_models_reference.inc',out/'primary_models_reference.inc')
        record['source_sha256']={path.relative_to(source).as_posix():sha(path) for path in source.rglob('*') if path.is_file()}
        record['reference_sha256']={name:sha(out/name) for name in ('primary_models_original.cpp','primary_models_reference.hpp','primary_models_reference.inc','scenes.txt')}
        build=out/'build';env=dict(os.environ,PATH=str(args.compiler.resolve().parent)+os.pathsep+os.environ.get('PATH',''))
        archive=Path(receipt['commands'][2]['command'][1]);stamp=archive.stat().st_size,archive.stat().st_mtime_ns
        commands=[('configure',[CMAKE,'-S',source/'game/native','-B',build,'-G','Ninja','-DCMAKE_MAKE_PROGRAM='+str(NINJA),'-DCMAKE_CXX_COMPILER='+str(args.compiler.resolve()),'-DCMAKE_BUILD_TYPE=Release','-DREO_PRIMARY_MODELS_REFERENCE_DIR='+str(out)]),('build',[CMAKE,'--build',build,'--parallel','2','--target','primary_actor_models_tests']),('owned',[build/'gameplay_world/primary_actor_models_tests.exe',archive,out/'scenes.txt']),('fixture',[build/'gameplay_world/primary_actor_models_tests.exe'])]
        record['commands']=[];record['observed']={}
        for label,command in commands:
            result=subprocess.run(list(map(str,command)),env=env,capture_output=True,timeout=600);(out/(label+'.txt')).write_bytes(result.stdout+result.stderr);record['commands'].append(dict(command=list(map(str,command)),exit_code=result.returncode));assert result.returncode==0,label+': '+(result.stdout+result.stderr).decode(errors='replace')[-1800:]
            if label in ('owned','fixture'):record['observed'][label]=json.loads(result.stdout)
        assert record['observed']['owned']['queued_scene_transitions']>0
        assert (archive.stat().st_size,archive.stat().st_mtime_ns)==stamp
        record['snapshot_unchanged']=all(sha(source/name)==digest for name,digest in record['source_sha256'].items());assert record['snapshot_unchanged']
        record['live_source_drift']=[name for name,digest in record['source_sha256'].items() if not(ROOT/name).is_file() or sha(ROOT/name)!=digest]
        record['status']='passed'
    finally:
        record['output_sha256']={name:sha(out/name) for name in ('configure.txt','build.txt','owned.txt','fixture.txt') if (out/name).is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(dict(status=record['status'],observed=record['observed'],live_source_drift=record['live_source_drift'])))

if __name__=='__main__':main()
