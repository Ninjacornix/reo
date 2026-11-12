"""Owned-asset scene actor composition over a sealed native-library cohort.

The new lifecycle units compile in a fresh snapshot and independent project.
The sealed base archive set is reused read-only; no cached parent build changes.
"""
import argparse, hashlib, json, os, re, shutil, struct, subprocess
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
CMAKE=Path('C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe')
NINJA=CMAKE.parent.parent.parent/'Ninja/ninja.exe'
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--base',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
    base=a.base.resolve();prior=json.loads((base/'receipt.json').read_bytes());assert prior['status']=='passed' and prior['snapshot_unchanged'];assert sha(a.compiler)==prior['compiler_sha256']
    record=dict(schema=1,status='failed',base_receipt=str(base/'receipt.json'),base_receipt_sha256=sha(base/'receipt.json'),compiler_sha256=sha(a.compiler),game_run=False,hardware_output=False,stage4_complete=False,limits=['Native composition uses the actual canonical World/Update, primary/NPC/scripted constructors, owned models/motion banks and both registered track domains.','This cohort does not newly execute a complete original5ECF90/5ED340/5ED770 scene entry/exit; their remaining resource/render/media phase owners are still required.','The sealed parent cohort executes the existing complete model/cache/5F0C00 comparisons and retained separate initializer/resource observation boundaries.','Only0950 descriptor layout is admitted; older authored versions are not silently converted.'])
    try:
        source=out/'source';shutil.copytree(base/'source',source)
        names=['game/native/gameplay_scenario/cutscene_scene_actors.hpp','game/native/gameplay_scenario/cutscene_scene_actors.cpp','game/native/gameplay_world/cinematic_object_construction.hpp','game/native/gameplay_world/cinematic_object_construction.cpp','tools/native_reconstruction/cutscene_scene_actors_tests.cpp','tools/native_reconstruction/verify_cutscene_scene_actors.py','game/native/gameplay_world/resource_factory.cpp']
        for name in names:target=source/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
        units=['game/native/gameplay_scenario/cutscene_scene_actors.cpp','game/native/gameplay_world/cinematic_object_construction.cpp','game/native/gameplay_world/cinematic_object_assets.cpp','game/native/gameplay_world/npc_actor_construction.cpp','game/native/gameplay_world/cutscene_npc_construction.cpp','game/native/gameplay_update/scripted_actor_construction.cpp','game/native/gameplay_update/cutscene_scripted_construction.cpp','tools/native_reconstruction/cutscene_scene_actors_tests.cpp','game/native/gameplay_world/resource_factory.cpp']
        record['new_source_sha256']={name:sha(source/name) for name in names}
        env=dict(os.environ,PATH=str(a.compiler.resolve().parent)+os.pathsep+os.environ.get('PATH',''))
        graph=out/'dependencies.dot'
        generated=subprocess.run(list(map(str,[CMAKE,'-S',base/'source/game/native','-B',base/'build','--graphviz='+str(graph)])),env=env,capture_output=True,timeout=120);assert generated.returncode==0,generated.stderr
        graph_text=graph.read_text();labels=dict(re.findall(r'\"(node\d+)\" \[ label = \"([^\"]+)\"',graph_text));edges={}
        for left,right in re.findall(r'\"(node\d+)\" -> \"(node\d+)\"',graph_text):edges.setdefault(left,[]).append(right)
        roots={'reo_native_gameplay_update','reo_native_cinematic_object_assets','reo_native_npc_actor_construction','reo_native_scripted_actor_construction','reo_native_model_attachments'};pending=[node for node,label in labels.items() if label in roots];reached=set()
        while pending:
            node=pending.pop()
            if node in reached:continue
            reached.add(node);pending.extend(edges.get(node,[]))
        targets=sorted({labels[node] for node in reached if labels[node].startswith('reo_native_')});assert roots.issubset(targets),labels
        record['native_target_closure']=targets
        command=[CMAKE,'--build',base/'build','--parallel','2','--target',*targets]
        done=subprocess.run(list(map(str,command)),env=env,capture_output=True,timeout=600);(out/'base-libraries.txt').write_bytes(done.stdout+done.stderr);record['base_build_command']=list(map(str,command));assert done.returncode==0,(done.stdout+done.stderr).decode(errors='replace')[-2000:]
        record['native_library_sha256']={path.relative_to(base).as_posix():sha(path) for path in (base/'build').rglob('*.a')};assert len(record['native_library_sha256'])>20
        record['snapshot_sha256']={path.relative_to(source).as_posix():sha(path) for path in source.rglob('*') if path.is_file()}
        archive=Path(prior['commands'][2]['command'][1]);stamp=archive.stat().st_size,archive.stat().st_mtime_ns
        inventory_path=ROOT/'build-native-sjuni/cutscene-descriptor-inventory-v2/receipt.json';inventory=json.loads(inventory_path.read_bytes());assert inventory['status']=='static_layout_inventory';record['inventory_sha256']=sha(inventory_path)
        cases={};selected=[]
        with archive.open('rb') as stream:
            for row in inventory['rows']:
                if row['version']!='0950':continue
                stream.seek(row['offset']);data=stream.read(row['bytes']);assert hashlib.sha256(data).hexdigest()==row['sha256'];kinds=[]
                for group in row['layout']['actors']:
                    offset=group[7]['offset'];enabled,kind=struct.unpack_from('<Hh',data,offset+2)
                    if enabled!=65535:kinds.append(kind)
                mask=(1 if any(kind in (0,3) for kind in kinds) else 0)|(2 if 1 in kinds else 0)|(4 if 2 in kinds else 0)|(8 if row['layout']['objects'] else 0)
                if cases.get(mask,0)>=2:continue
                cases[mask]=cases.get(mask,0)+1;match=re.fullmatch(r'dm(\d{2})(\d{2})([a-z])\.bin',row['name'].lower());assert match
                selected.append(dict(scenario=row['scenario'],area=int(match[1]),scene=int(match[2]),suffix=ord(match[3])-97,mask=mask,name=row['name'],sha256=row['sha256']))
        record['owned_descriptors']=selected;manifest=out/'scenes.txt';manifest.write_text('\n'.join(f"{row['scenario']} {row['area']} {row['scene']} {row['suffix']}" for row in selected)+'\n')
        project=out/'project';project.mkdir();paths='\n'.join('"'+str(source/name).replace('\\','/')+'"' for name in units);libraries='\n'.join('"'+str(base/name).replace('\\','/')+'"' for name in record['native_library_sha256'])
        (project/'CMakeLists.txt').write_text('cmake_minimum_required(VERSION 3.20)\nproject(scene_actor_composition LANGUAGES CXX)\nadd_executable(checks\n'+paths+'\n)\ntarget_compile_features(checks PRIVATE cxx_std_20)\ntarget_include_directories(checks PRIVATE "'+str(source).replace('\\','/')+'")\ntarget_compile_options(checks PRIVATE -Wall -Wextra -Wpedantic -Werror -fno-fast-math -ffp-contract=off)\ntarget_link_libraries(checks PRIVATE -Wl,--start-group\n'+libraries+'\n-Wl,--end-group)\n')
        build=out/'build';env=dict(os.environ,PATH=str(a.compiler.resolve().parent)+os.pathsep+os.environ.get('PATH',''));record['commands']=[]
        for label,command in [('configure',[CMAKE,'-S',project,'-B',build,'-G','Ninja','-DCMAKE_MAKE_PROGRAM='+str(NINJA),'-DCMAKE_CXX_COMPILER='+str(a.compiler.resolve()),'-DCMAKE_BUILD_TYPE=Release']),('build',[CMAKE,'--build',build,'--parallel','2']),('owned',[build/'checks.exe',archive,manifest])]:
            done=subprocess.run(list(map(str,command)),env=env,capture_output=True,timeout=600);(out/(label+'.txt')).write_bytes(done.stdout+done.stderr);record['commands'].append(dict(command=list(map(str,command)),exit_code=done.returncode));assert done.returncode==0,label+': '+(done.stdout+done.stderr).decode(errors='replace')[-2000:]
            if label=='owned':record['observed']=json.loads(done.stdout)
        assert (archive.stat().st_size,archive.stat().st_mtime_ns)==stamp
        record['snapshot_unchanged']=all(sha(source/name)==digest for name,digest in record['snapshot_sha256'].items());assert record['snapshot_unchanged']
        assert all(sha(base/name)==digest for name,digest in record['native_library_sha256'].items());record['new_source_unchanged']=all(sha(ROOT/name)==digest for name,digest in record['new_source_sha256'].items());assert record['new_source_unchanged'];record['status']='passed'
    finally:
        record['output_sha256']={name:sha(out/name) for name in ('base-libraries.txt','configure.txt','build.txt','owned.txt','scenes.txt') if (out/name).is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(dict(status=record['status'],observed=record['observed'])))

if __name__=='__main__':main()
