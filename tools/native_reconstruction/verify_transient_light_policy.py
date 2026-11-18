"""Compare the complete dual-light callback against the native finite policy."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS
from comparison_objects import compile_objects
from comparison_oracle import compile_oracle
from gameplay_update_sources import UPDATE_UNITS
from effect_work_sources import SURFACE_WORLD_UNITS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--auxiliary-pool',action='store_true');p.add_argument('--owner',action='store_true');args=p.parse_args()
    if args.owner:args.auxiliary_pool=True
    out=args.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
    banks={}
    for bank,digest in [('o0','bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'),('o2','45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226')]:
        path=ROOT/'build-function-index/owned-overlays'/f'{bank}.bin';assert sha(path)==digest;banks[bank]=path.read_bytes()
    entries={};proof=[]
    for address in [0x5d83d0,0x371760,0x370490]+([0x6b2bd0,0x6b2cc0,0x6b2c50] if args.auxiliary_pool else [])+([0x6b24f0,0x6b3090,0x6b2fa0,0x6b3020] if args.owner else []):
        bank='o2' if address>=0x570000 else 'o0';path=next((ROOT/'recomp/config/output_ovl'/bank).glob(f'{bank}_{address:08X}_*'));name=path.relative_to(ROOT).as_posix()
        end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',path.read_text())[1],16);base=0x570000 if bank=='o2' else 0x370000
        proof.append(compare_source('complete transient callback or ordered quadratic helper',name,address,end,lambda at,n:banks[bank][at-base:at-base+n]));entries[address]=name
    unit='game/native/gameplay_lighting/transient_light_policy.cpp';fixture='tools/native_reconstruction/transient_light_policy_tests.cpp';helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    files=[unit,fixture,helper,Path(__file__).relative_to(ROOT).as_posix(),*entries.values()]
    if args.auxiliary_pool:files+=['game/native/gameplay_scenario/lighting.cpp','tools/native_reconstruction/auxiliary_lighting_tests.inc']
    units=[unit]+(['game/native/gameplay_scenario/lighting.cpp'] if args.auxiliary_pool else [])
    if args.owner:
        units=list(dict.fromkeys(units+UPDATE_UNITS+SURFACE_WORLD_UNITS+['game/native/gameplay_lighting/transient_lights.cpp','game/native/gameplay_world/transient_weapon_effects.cpp']))
        files+=units+['tools/native_reconstruction/transient_lights_owner_tests.inc','tools/native_reconstruction/comparison_objects.py','tools/native_reconstruction/comparison_oracle.py','tools/native_reconstruction/gameplay_update_sources.py','tools/native_reconstruction/effect_work_sources.py']
        files=list(dict.fromkeys(files))
    for name in files:
        if name.startswith('game/native/'):
            for include in re.findall(r'^\s*#include "([^"]+)"',(ROOT/name).read_text(),re.M):
                path=((ROOT/name).parent/include).resolve()
                if not path.is_file():path=(ROOT/include).resolve()
                assert path.is_file() and path.is_relative_to(ROOT),(name,include)
                relative=path.relative_to(ROOT).as_posix()
                if relative not in files:files.append(relative)
    frozen={name:(ROOT/name).read_bytes()for name in files};out.mkdir(parents=True)
    for name,body in frozen.items():path=out/'source'/name;path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(body)
    (out/'reference.hpp').write_text(frozen[helper].decode()+'\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n#define FPU_DIV_S(a,b) ((a)/(b))\n')
    body='\n'.join(frozen[name].decode()for name in entries.values());(out/'original.cpp').write_text(body)
    if args.owner:(out/'original_visuals.cpp').write_text(body)
    actual={Path(name).stem for name in entries.values()};called=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual))
    decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(called-actual))
    (out/'functions.h').write_text('#pragma once\n'+decl)
    (out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for at,name in entries.items()))
    for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    for name in ['o0_functions.h','o2_functions.h','ps2_recompiled_functions.h','ps2_overlay_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
    constants='inline void owned_constants(std::uint8_t* memory){';ranges={}
    for at,size in [(0x70b350,16),(0x720240,52),(0x73eb30,4)]:
        data=banks['o2'][at-0x570000:at-0x570000+size];ranges[hex(at)]={'bytes':size,'sha256':hashlib.sha256(data).hexdigest()}
        constants+='{const std::uint8_t data[]{'+','.join(str(v)for v in data)+'};std::memcpy(memory+'+str(at)+',data,sizeof data);}'
    (out/'owned_constants.hpp').write_text(constants+'}\n')
    compiler=COMPILERS[args.compiler];binary=out/'checks.exe';command=[str(compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),str(out/'source'/unit),str(out/'source'/fixture),str(out/'original.cpp'),'-o',str(binary)]
    if args.auxiliary_pool:command[1:1]=['-DREO_AUXILIARY_LIGHT_POOL=1',str(out/'source/game/native/gameplay_scenario/lighting.cpp')]
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');record=dict(schema=1,status='failed',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256={name:hashlib.sha256(body).hexdigest()for name,body in frozen.items()},compiler_sha256=sha(compiler),original_word_audits=proof,owned_ranges=ranges,command=command,declared_ports=['6B3020/6B2C50 light releases and573740 task retirement are captured; actual native pool/scheduler ownership is a separate cohort.'])
    try:
        if args.owner:
            flags=command[1:command.index(str(out/'source'/unit))]
            # The auxiliary-pool simple command adds a source before its flags.
            flags=[value for value in flags if not value.endswith('.cpp')]+['-DREO_TRANSIENT_OWNER=1']
            objects,production=compile_objects(ROOT,out,compiler,flags,units,frozen,env)
            original,oracle=compile_oracle(ROOT,out,compiler,flags,env)
            command=[str(compiler),*flags,*objects,original,str(out/'source'/fixture),'-o',str(binary)]
            record.update(command=command,production_objects=production,original_object=oracle)
            record['declared_ports']=['Policy corpus captures releases/retirement; complete6B24F0/5D83D0 and both real original light pools execute in the separate owner cases.','573890 task admission and573740 retirement are controlled original ports; native uses the actual canonical Update scheduler.','107C68/107AB0 perform bounded56-byte clearing and52-byte payload copies.']
        for label,cmd in [('compile',command),('run',[str(binary)])]:
            result=subprocess.run(cmd,capture_output=True,env=env,timeout=150);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);assert result.returncode==0,label+' failed; see retained logs'
            if label=='run':record['observed']=json.loads(result.stdout)
        record['source_unchanged']=all((ROOT/name).read_bytes()==body for name,body in frozen.items());assert record['source_unchanged'];record.update(status='passed',binary_sha256=sha(binary))
    finally:
        record['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.rglob('*')if path.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(record['observed']))
if __name__=='__main__':main()
