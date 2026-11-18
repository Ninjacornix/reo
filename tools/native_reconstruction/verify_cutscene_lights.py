"""Compare cinematic light ownership over immutable current app archives and real room floors."""
import argparse,hashlib,json,os,re,shutil,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    parent=ROOT/'build-native-sjuni'/f'session-rooms-{a.compiler}-v6';prior=json.loads((parent/'receipt.json').read_bytes());assert prior['status']=='passed'and not prior['current_shared_source_drift']
    units=['game/native/gameplay_scenario/'+name+'.cpp'for name in ['lighting','cutscene_light_curves','cutscene_lights']]
    fixture='tools/native_reconstruction/cutscene_lights_tests.cpp';helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';conversion='third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h'
    owned={*units,fixture,Path(__file__).relative_to(ROOT).as_posix(),'game/native/gameplay_scenario/lighting.hpp','game/native/gameplay_scenario/cutscene_light_curves.hpp','game/native/gameplay_scenario/cutscene_lights.hpp'};frozen={}
    for name,digest in prior['source_sha256'].items():assert sha(parent/'source'/name)==digest;frozen[name]=(parent/'source'/name).read_bytes()
    pending=list(owned)+[helper,conversion]
    for name in pending:
        if name not in frozen or name in owned:frozen[name]=(ROOT/name).read_bytes()
        if name.startswith('game/native/'):
            for include in re.findall(r'^\s*#include "([^"]+)"',frozen[name].decode(),re.M):
                target=((ROOT/name).parent/include).resolve();target=target if target.is_file()else(ROOT/include).resolve();assert target.is_file()and target.is_relative_to(ROOT);relative=target.relative_to(ROOT).as_posix()
                if relative not in pending:pending.append(relative)
    image=ROOT/'game_data/SLUS_207.65';assert sha(image)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read_main=elf_reader(image.read_bytes());banks={}
    for bank,digest in [('o0','bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'),('o2','45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226')]:
        path=ROOT/'build-function-index/owned-overlays'/f'{bank}.bin';assert sha(path)==digest;banks[bank]=path.read_bytes()
    entries={};proof=[];covered=[];ports={0x107ab0,0x107c68,0x617000};calls=[0x6b3830,0x5ef640,0x6b38d0,0x6b3900,0x6b3bb0,0x616f60,0x371600,0x370420]
    while calls:
        address=calls.pop()
        if address in entries or address in ports or any(begin<=address<end for begin,end in covered):continue
        bank='sub'if address<0x370000 else'o0'if address<0x570000 else'o2';folder=ROOT/('recomp/config/output'if bank=='sub'else'recomp/config/output_ovl/'+bank);path=next(folder.glob(f'{bank}_{address:08X}_*'));name=path.relative_to(ROOT).as_posix();body=path.read_bytes();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',body.decode())[1],16)
        read=read_main if bank=='sub'else lambda at,n,b=bank,base=0x370000 if bank=='o0'else 0x570000:banks[b][at-base:at-base+n];proof.append(compare_source('complete cinematic light constructor, track consumer, pool operation or value helper',name,address,end,read));entries[address]=name;covered.append((address,end));frozen[name]=body
        calls.extend(int(value,16)for value in re.findall(r'// 0x[0-9a-f]+: 0x[0-9a-f]+\s+(?:jal|j)\s+func_([0-9A-Fa-f]+)',body.decode()))
    out.mkdir()
    for name,body in frozen.items():target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(body)
    reference=frozen[helper].decode().replace('Register r[32];','std::uint64_t lo{},hi{},lo1{},hi1{};Register r[32];')+'\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define SRA32(a,b) (std::int32_t(a)>>(unsigned(b)&31))\n#define SLLV32(a,b) (std::uint32_t(a)<<(unsigned(b)&31))\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(a) Ps2FpuConvertWord(a)\n';(out/'reference.hpp').write_text(reference);(out/'ps2_fpu_convert.h').write_bytes(frozen[conversion])
    body='\n'.join(frozen[name].decode()for name in entries.values());actual={Path(name).stem for name in entries.values()};called=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(called-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(address)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for address,name in entries.items()))
    for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    for name in ['ps2_recompiled_functions.h','o0_functions.h','o2_functions.h','ps2_overlay_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
    constants='inline void owned_constants(std::uint8_t* p){\n'
    for at,n in [(0x22fe20,32),(0x241c78,32)]:data=read_main(at,n);constants+='{const std::uint8_t b[]{'+','.join(map(str,data))+'};std::memcpy(p+'+str(at)+',b,sizeof b);}\n'
    (out/'owned_constants.hpp').write_text(constants+'}\n');libraries=[]
    for name,digest in prior['native_library_sha256'].items():
        candidates=[parent/'libraries'/name,ROOT/'build-native-sjuni'/f'cutscene-lights-{a.compiler}-v2'/'libraries'/name,ROOT/'build-native-sjuni'/f'gameplay-native-{a.compiler}-v1'/name]
        source=next((candidate for candidate in candidates if candidate.is_file()and sha(candidate)==digest),None);assert source is not None,name
        target=out/'libraries'/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(source,target);assert sha(target)==digest;libraries.append(str(target))
    compiler=COMPILERS[a.compiler];env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''));exe=out/'checks.exe';command=[str(compiler),'-std=c++20','-O2','-msse4.1','-ffunction-sections','-fdata-sections','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'source'/fixture),str(out/'original.cpp'),'-Wl,--gc-sections','-Wl,--start-group',*libraries,'-Wl,--end-group','-o',str(exe)]
    record=dict(schema=1,status='failed',source_sha256={name:hashlib.sha256(body).hexdigest()for name,body in frozen.items()},compiler_sha256=sha(compiler),native_parent=dict(path=parent.relative_to(ROOT).as_posix()+'/receipt.json',sha256=sha(parent/'receipt.json')),native_library_sha256=prior['native_library_sha256'],original_owned_bodies=proof,command=command,game_run=False,stage4_complete=False,limits=['Complete6B3830 and light pool children,5EF640,6B3900 and6B3BB0 execute. Source617000 is explicitly bound to the independently qualified native real retained Grid; complete616F60 executes. Original transitive grid traversal is not re-executed in this cohort.','Actual NativeSession/SessionRooms install r0417300; every admitted descriptor is evaluated against this same retained real floor graph. This is not a claim that all548 complete scene lifecycles or their distinct room geometry are installed. Fog0 uses the actual unsupported-version inactive-record fallback, rather than a successful provider stub.','Lighting registration is inside its opaque domain. Complete currentLighting.cpp overrides its prior archive unit without changing public class layout. All other native libraries and matching source headers are immutable copies of the exact current parent.'])
    try:
        result=subprocess.run(command,env=env,capture_output=True,timeout=240);(out/'compile.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'compile failed'
        manifest_parent=ROOT/'build-native-sjuni/cutscene-descriptor-loader-llvm-v3';manifest_receipt=json.loads((manifest_parent/'receipt.json').read_bytes());assert manifest_receipt['status']=='passed';manifest=manifest_parent/'scenes.txt';assert sha(manifest)==manifest_receipt['owned_manifest_sha256'];shutil.copyfile(manifest,out/'scenes.txt');archive=Path(manifest_receipt['run_command'][1]);stamp=archive.stat().st_size,archive.stat().st_mtime_ns;record['manifest_sha256']=sha(out/'scenes.txt');record['run_command']=[str(exe),str(archive),str(out/'scenes.txt')]
        assert prior['archive_identity']==dict(size=stamp[0],mtime_ns=stamp[1])
        inventory_path=ROOT/'build-native-sjuni/cutscene-descriptor-inventory-v2/receipt.json';inventory=json.loads(inventory_path.read_bytes());rows=[row for row in inventory['rows']if row['version']=='0950'];assert len(rows)==548
        with archive.open('rb')as data:
            for row in rows:data.seek(row['offset']);assert hashlib.sha256(data.read(row['bytes'])).hexdigest()==row['sha256']
            for row in prior['owned_members']:data.seek(row['archive_offset']);assert hashlib.sha256(data.read(row['bytes'])).hexdigest()==row['sha256']
        record['inventory_sha256']=sha(inventory_path);record['owned_descriptors']=[dict(scenario=row['scenario'],name=row['name'],sha256=row['sha256'])for row in rows];record['owned_room_members']=prior['owned_members']
        result=subprocess.run(record['run_command'],env=env,capture_output=True,timeout=300);(out/'run.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'comparison failed';assert stamp==(archive.stat().st_size,archive.stat().st_mtime_ns)
        record['owned_source_drift']={name:sha(ROOT/name)for name in owned if(ROOT/name).read_bytes()!=frozen[name]};assert not record['owned_source_drift'];record['subsequent_parent_header_changes']={name:sha(ROOT/name)for name in pending if name in prior['source_sha256']and name not in owned and(ROOT/name).read_bytes()!=frozen[name]};record.update(status='passed',observed=json.loads(result.stdout))
    finally:
        record['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.rglob('*')if path.is_file()and path.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(record['observed']))
if __name__=='__main__':main()
