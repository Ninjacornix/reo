"""Compare the complete ordinary descriptor loader and parser using all owned admitted descriptors."""
import argparse,hashlib,json,os,re,struct,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';main_read=elf_reader(elf.read_bytes());overlay=ROOT/'build-function-index/owned-overlays/o0.bin';assert sha(overlay)=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2';blob=overlay.read_bytes()
    o2=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(o2)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';o2blob=o2.read_bytes()
    entries={}
    for owner,addresses in [('o2',[0x5ed900,0x5f15a0]),('sub',[0x1aa3e0,0x1cc8f0,0x1aa480,0x1a9f20,0x1a9d70,0x1ab050,0x1a9750,0x129c08,0x130e40])]:
        directory=ROOT/('recomp/config/output'if owner=='sub'else'recomp/config/output_ovl/'+owner)
        for address in addresses:entries[address]=next(directory.glob(f'{owner}_{address:08X}_*')).relative_to(ROOT).as_posix()
    static_authorities=[]
    for owner,address in [('sub',0x1baec0),('sub',0x1af910),('sub',0x1af970),('sub',0x1aa110),('o2',0x5ed900),('o2',0x5eda40)]:
        directory=ROOT/('recomp/config/output'if owner=='sub'else'recomp/config/output_ovl/o2');name=next(directory.glob(f'{owner}_{address:08X}_*')).relative_to(ROOT).as_posix();text=(ROOT/name).read_text();start,end=(int(value,16)for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',text).groups());static_authorities.append(compare_source('static startup cold-clear, partition allocation, ordinary overlay or movie-prefix clear authority',name,start,end,main_read if owner=='sub'else lambda at,n:o2blob[at-0x570000:at-0x570000+n]))
    proof=[]
    for name in set(entries.values()):
        text=(ROOT/name).read_text();start,end=(int(value,16)for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',text).groups());proof.append(compare_source('complete descriptor loader, resident selector or parser',name,start,end,main_read if start<0x570000 else lambda at,n:o2blob[at-0x570000:at-0x570000+n]))
    units=['game/native/'+group+'/'+name+'.cpp'for group,names in [
        ('gameplay_world',['world','linked_models','auxiliary_actors','scene_primary_actors','model_poses','model_constraints','bodies','cinematic_objects','cinematic_object_attachment','model_attachments','scripted_motion','cutscene_actor','motion_transforms','surface_orientation','surface_orientation_math','humanoid_motion_bindings']),
        ('gameplay_actors',['entity','input','health']),('gameplay_collision',['collision','response','actors','actor_views','room_objects']),
        ('animation',['model','model_math','curves','constraints','constraint_math','playback','model_blend','motion_bank','scalar_playback']),('transform_math',['transform_math','heading','direction_basis']),('gameplay_session',['session']),('gameplay_navigation',['bank']),
        ('gameplay_scenario',['cutscene_playback','cutscene_camera','camera_curves','camera_math','camera_projection','display_fade','fullscreen_color','cutscene_descriptor_workspace','workspace_fullscreen_color','cutscene_view_controls','lighting','cutscene_light_curves','cutscene_lights','scene_models','content','fog','cutscene_cues','cutscene_requests','flags','stream_channels','scene_voice_assets','scene_voice_preparation','cutscene_actor_tracks','cutscene_actor_commands','cutscene_object_tracks','cutscene_descriptor','scene_resources','resource_templates','cutscene_descriptor_loader','scenario_archive'])]for name in names];files=set(units);pending=list(units)
    while pending:
        name=pending.pop()
        for relative in re.findall(r'^#include "([^"]+)"',(ROOT/name).read_text(),re.M):
            path=((ROOT/name).parent/relative).resolve()
            if not path.is_file():path=(ROOT/relative).resolve()
            assert path.is_file()and path.is_relative_to(ROOT),(name,relative);key=path.relative_to(ROOT).as_posix()
            if key not in files:files.add(key);pending.append(key)
    helpers=['tools/native_reconstruction/cutscene_descriptor_loader_tests.cpp','tools/native_reconstruction/verify_cutscene_descriptor_loader.py','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'];files=sorted(files|set(entries.values())|{item['path']for item in static_authorities}|set(helpers)|{'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h','runtime/assets/virtual_afs.h'});before={name:sha(ROOT/name)for name in files};out.mkdir();record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),original_owned_bodies=proof,static_workspace_authorities=static_authorities,game_run=False,stage4_complete=False,limits=['Complete5ED900,5F15A0 and1AA3E0 execute. Physical archive reads and standard formatting are explicit independent owned-fixture operations; native production uses actual ScenarioArchive authored resource lookup. Movie5EDA40 merging, disk SDK scheduling and game installation are not established. No CPU context or absolute RAM is included in production.','Finite FP32 nearest-rounding/native scalar-SIMD profile; physical PS2 exceptional arithmetic equivalence is not claimed.'])
    try:
        record['limits'][0]='Complete5ED900,5F15A0,1AA3E0,1CC8F0,1AA480,1A9F20,1A9D70,1AB050,1A9750,129C08 and130E40 execute with all1342 owned default encoded keys. SDK task allocation, real archive sector transfer/completion/close and standard formatting/string primitives are explicit fixture operations. The independent AFS range contract establishes SDK storage-sector metadata; native production reads the actual retained archive sectors. Movie5EDA40 merging, disk scheduling and game installation remain unestablished. No CPU context or absolute RAM is included in production.'
        for name in files:target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
        reference=(ROOT/helpers[2]).read_text()+'\n'+(ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h').read_text()+'\n#define SRA32(a,b) (std::bit_cast<std::int32_t>(std::uint32_t(a))>>(unsigned(b)&31))\n#define FPU_CVT_W_S(a) Ps2FpuConvertWord(a)\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n'+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n';(out/'reference.hpp').write_text(reference)
        body='\n'.join((ROOT/name).read_text()for name in sorted(set(entries.values())));actual={Path(name).stem for name in entries.values()};calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(address)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for address,name in sorted(entries.items())))
        for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
        for name in ['ps2_recompiled_functions.h','o0_functions.h','o2_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
        for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
        constants='inline void owned_constants(std::uint8_t* p){\n'
        for at,n in [(0x73ed20,48),(0x73ed50,32)]:
            data=o2blob[at-0x570000:at-0x570000+n];constants+='{const std::uint8_t b[]{'+','.join(map(str,data))+'};std::memcpy(p+'+str(at)+',b,sizeof b);}\n'
        names=[];table=main_read(0x2322c0,1342*4)
        for at,data in [(0x2322c0,table)]+[(pointer,main_read(pointer,512).split(b'\0')[0]+b'\0')for pointer in struct.unpack('<1342I',table)]:
            constants+='{const std::uint8_t b[]{'+','.join(map(str,data))+'};std::memcpy(p+'+str(at)+',b,sizeof b);}\n'
            if at!=0x2322c0:names.append(bytes(value^255 for value in data[:-1]).decode('ascii'))
        assert len(names)==1342 and not any(re.search(r'(?:^|_)DM\d{4}[A-Z]_BIN$',name)for name in names)
        record['default_catalogue']={'pointer_table':0x2322c0,'count':len(names),'decoded_names_sha256':hashlib.sha256('\n'.join(names).encode()).hexdigest(),'matching_scene_dm_names':0}
        (out/'owned_constants.hpp').write_text(constants+'}\n');env=dict(os.environ,PATH=str(a.compiler.resolve().parent)+os.pathsep+os.environ.get('PATH',''));exe=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-O2','-ffunction-sections','-fdata-sections','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'source'/helpers[0]),str(out/'original.cpp'),'-Wl,--gc-sections','-o',str(exe)];record['command']=command
        result=subprocess.run(command,env=env,capture_output=True,timeout=600);(out/'compile.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'compile failed'
        inventory_path=ROOT/'build-native-sjuni/cutscene-descriptor-inventory-v2/receipt.json';inventory=json.loads(inventory_path.read_text());rows=[row for row in inventory['rows']if row['version']=='0950'];assert len(rows)==548
        prior=json.loads((ROOT/'build-native-sjuni/primary-scene-scope-llvm-v4/receipt.json').read_text());archive=Path(prior['commands'][2]['command'][1]);stamp=archive.stat().st_size,archive.stat().st_mtime_ns
        record['owned_sector_storage_sha256']={}
        with archive.open('rb')as owned:
            for row in rows:
                owned.seek(row['offset']);data=owned.read((row['bytes']+2047)//2048*2048);assert hashlib.sha256(data[:row['bytes']]).hexdigest()==row['sha256'];record['owned_sector_storage_sha256'][str(row['scenario'])+'/'+row['name']]=hashlib.sha256(data).hexdigest()
        manifest=out/'scenes.txt';lines=[]
        for row in rows:
            area,scene,suffix=re.fullmatch(r'dm(\d{2})(\d{2})([a-z])\.bin',row['name'],re.I).groups();lines.append(f"{row['scenario']} {int(area)} {int(scene)} {ord(suffix.lower())-97} {row['offset']} {row['bytes']}\n")
        manifest.write_text(''.join(lines));record['owned_manifest_sha256']=sha(manifest);record['inventory_sha256']=sha(inventory_path);record['owned_descriptor_sha256']={row['name']:row['sha256']for row in rows};record['run_command']=[str(exe),str(archive),str(manifest)]
        result=subprocess.run(record['run_command'],env=env,capture_output=True,timeout=180);assert stamp==(archive.stat().st_size,archive.stat().st_mtime_ns);(out/'run.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'comparison failed'
        record.update(status='passed',observed=json.loads(result.stdout),source_unchanged=all(sha(ROOT/name)==digest for name,digest in before.items()));assert record['source_unchanged']
    except BaseException as error:
        record['error']=repr(error);raise
    finally:
        record['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.rglob('*')if path.is_file()and path.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(dict(status=record['status'],observed=record['observed'])))
if __name__=='__main__':main()
