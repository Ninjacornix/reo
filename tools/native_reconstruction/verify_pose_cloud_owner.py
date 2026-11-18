"""Complete pose-cloud constructor/service/callback with actual visual/light owners."""
import argparse,hashlib,json,os,re,shutil,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    parent=ROOT/'build-native-sjuni'/f'pose-work-updates-{a.compiler}-v4';prior=json.loads((parent/'receipt.json').read_bytes());assert prior['status']=='passed'
    units=['game/native/'+s for s in ['gameplay_world/pose_cloud.cpp','gameplay_world/pose_cloud_policy.cpp','gameplay_world/resource_pose_work.cpp','gameplay_world/pose_work_pool.cpp','gameplay_effects/pose_lifetime.cpp','gameplay_lighting/timed_lights.cpp','gameplay_lighting/lights.cpp']];fixture='tools/native_reconstruction/pose_cloud_owner_tests.cpp';helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';owned={*units,fixture,'game/native/gameplay_world/resource_pose_work.hpp','game/native/gameplay_lighting/timed_lights.hpp',Path(__file__).relative_to(ROOT).as_posix()};frozen={}
    for name,digest in prior['source_sha256'].items():assert sha(parent/'source'/name)==digest;frozen[name]=(parent/'source'/name).read_bytes()
    pending=list(owned)+[helper]
    for name in pending:
        if name not in frozen or name in owned:frozen[name]=(ROOT/name).read_bytes()
        if name.startswith('game/native/'):
            for include in re.findall(r'^\s*#include "([^"]+)"',frozen[name].decode(),re.M):
                path=((ROOT/name).parent/include).resolve();path=path if path.is_file()else(ROOT/include).resolve();assert path.is_file()and path.is_relative_to(ROOT);relative=path.relative_to(ROOT).as_posix()
                if relative not in pending:pending.append(relative)
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());banks={}
    for bank,digest in [('o0','bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'),('o2','45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226')]:
        image=ROOT/'build-function-index/owned-overlays'/f'{bank}.bin';assert sha(image)==digest;banks[bank]=image.read_bytes()
    entries={};proof=[]
    for at in [0x5822a0,0x581f50,0x581fe0,0x5820f0,0x582de0,0x5821f0,0x582b80,0x582df0,0x5846c0]:
        bank='sub'if at<0x370000 else'o0'if at<0x570000 else'o2';folder=ROOT/('recomp/config/output'if bank=='sub'else'recomp/config/output_ovl/'+bank);path=next(folder.glob(f'{bank}_{at:08X}_*'));name=path.relative_to(ROOT).as_posix();body=path.read_bytes();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',body.decode())[1],16);reader=read if bank=='sub'else lambda address,n,b=bank,base=0x370000 if bank=='o0'else 0x570000:banks[b][address-base:address-base+n];proof.append(compare_source('complete pose pool, cloud constructor/service/callback',name,at,end,reader));frozen[name]=body;entries[at]=name
    out.mkdir(parents=True)
    for name,contents in frozen.items():
        path=out/'source'/name;path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(contents)
    reference=frozen[helper].decode().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#define GPR_S32(c,i) std::int32_t(GPR_U32(c,i))\n#define SRA32(v,s) (std::int32_t(v)>>((s)&31))\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n';(out/'reference.hpp').write_text(reference)
    body='\n'.join(frozen[name].decode()for name in entries.values());actual={Path(name).stem for name in entries.values()};called=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(called-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for at,name in entries.items()));(out/'original.cpp').write_text('#include "reference.hpp"\n#include "functions.h"\n'+body)
    for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    for name in ['ps2_recompiled_functions.h','o0_functions.h','o2_functions.h','ps2_overlay_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
    constants='inline void owned_constants(std::uint8_t* memory){';ranges={}
    for at,n in [(0x7123f5,1)]:
        data=banks['o2'][at-0x570000:at-0x570000+n];ranges[hex(at)]={'bytes':n,'sha256':hashlib.sha256(data).hexdigest()};constants+='{const std::uint8_t data[]{'+','.join(str(v)for v in data)+'};std::memcpy(memory+'+str(at)+',data,sizeof data);}'
    (out/'owned_constants.hpp').write_text(constants+'}\n');libraries=[]
    for name,digest in prior['native_library_sha256'].items():
        source=parent/'libraries'/name;assert sha(source)==digest;target=out/'libraries'/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(source,target);libraries.append(str(target))
    content=parent/'contact-content-v1.bin';assert sha(content)=='6e205620e37747181b4a14280f579e2cd85ed907f9b4634ffe28048e1e87a213';shutil.copyfile(content,out/content.name)
    compiler=COMPILERS[a.compiler];binary=out/'checks.exe';command=[str(compiler),'-std=c++20','-O2','-msse4.1','-ffunction-sections','-fdata-sections','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/n)for n in units],str(out/'source'/fixture),str(out/'original.cpp'),'-Wl,--gc-sections','-Wl,--start-group',*libraries,'-Wl,--end-group','-o',str(binary)];env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''));record=dict(schema=1,status='failed',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256={name:hashlib.sha256(v).hexdigest()for name,v in frozen.items()},compiler_sha256=sha(compiler),native_parent={'path':str(parent/'receipt.json'),'sha256':sha(parent/'receipt.json')},native_library_sha256=prior['native_library_sha256'],original_word_audits=proof,owned_ranges=ranges,command=command,declared_ports=['Complete583C50,5822A0,actual pose allocator/free and all reached math bodies execute.','Flight floor/burst/light/sound/packet are ordered controlled observations; independent actual owner composition is a separate gate. Generic constructor uses actual Catalog/Packets, original5DA2C0 observes its request.'])
    run=[str(binary),str(out/content.name)]
    asset_parent=ROOT/'build-native-sjuni/resource-flight-owner-llvm-v4';asset_receipt=json.loads((asset_parent/'receipt.json').read_bytes());asset=asset_parent/'owned_effect_geometry.bin';assert asset_receipt['status']=='passed'and sha(asset)==asset_receipt['output_sha256'][asset.name];shutil.copyfile(asset,out/asset.name);record['effect_corpus']={'path':str(asset),'sha256':sha(asset)};run+=[str(out/asset.name)]
    record['declared_ports']=['Complete581F50/581FE0/5822A0/5821F0/582B80/5846C0/582DE0 and reached free/visibility helpers execute.','6525C0 and6B2680 boundaries invoke independent actual PeriodicVisuals and TimedLights owners with the authored request. Full value bodies behind those owners are separately qualified.','Original5DA2C0 observes the constructor request; native constructors allocate actual owned Catalog/Packets.']
    record['limits']=['Effect55 is admitted on EF01/global and r001 plus the actual empty group255 profile in EF35. EF28/EF41 lack geometry55: the constructor early no-effect result precedes their unconsumed map255 data. EF02 has geometry55 but its map255 apparent part table remains unadmitted. Explicit prefix-preserving refusal is tested for EF02; no synthetic group or successful original continuation is claimed there.']
    try:
        for label,cmd in [('compile',command),('run',run)]:
            result=subprocess.run(cmd,capture_output=True,env=env,timeout=300);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);assert result.returncode==0,label+' failed; see retained logs'
            if label=='run':record['observed']=json.loads(result.stdout)
        owned|={n for n in pending if n not in prior['source_sha256']};record['owned_source_drift']={n:sha(ROOT/n)for n in owned if (ROOT/n).read_bytes()!=frozen[n]};assert not record['owned_source_drift'];record['subsequent_parent_header_changes']={n:sha(ROOT/n)for n in pending if n in prior['source_sha256']and n not in owned and(ROOT/n).read_bytes()!=frozen[n]};record.update(status='passed',binary_sha256=sha(binary))
    finally:
        record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(record['observed']))


if __name__=='__main__':main()
