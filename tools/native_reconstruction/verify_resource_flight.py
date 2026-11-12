"""Compare the complete original type7 update with native physics/query policy."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--compiler',choices=COMPILERS,required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    out=args.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';main_read=elf_reader(elf.read_bytes());banks={}
    for bank,digest in [('o0','bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'),('o2','45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226')]:
        path=ROOT/'build-function-index/owned-overlays'/f'{bank}.bin';assert sha(path)==digest;banks[bank]=path.read_bytes()
    entries={};proof=[];covered=[];ports={0x5795e0,0x57d560,0x1b93d0,0x1b8b20,0x651d00,0x652390,0x372720};pending=[0x58e850,0x58e6d0,0x652f00]
    while pending:
        address=pending.pop()
        if address in entries or address in ports or any(start<=address<end for start,end in covered):continue
        bank='sub' if address<0x370000 else 'o0' if address<0x570000 else 'o2';folder=ROOT/('recomp/config/output'if bank=='sub'else'recomp/config/output_ovl/'+bank)
        matches=list(folder.glob(f'{bank}_{address:08X}_*'));assert matches,hex(address)
        path=matches[0];name=path.relative_to(ROOT).as_posix();body=path.read_text();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',body)[1],16)
        reader=main_read if bank=='sub'else lambda at,n,b=bank,base=0x370000 if bank=='o0'else 0x570000:banks[b][at-base:at-base+n]
        proof.append(compare_source('complete resource flight update or reached value helper',name,address,end,reader));entries[address]=name;covered.append((address,end))
        pending.extend(int(value,16)for value in re.findall(r'// 0x[0-9a-f]+: 0x[0-9a-f]+\s+(?:jal|j)\s+func_([0-9A-Fa-f]+)',body))
    units=['game/native/'+name for name in ['gameplay_effects/resource_flight.cpp','gameplay_session/session.cpp','animation/constraint_math.cpp','transform_math/transform_math.cpp','transform_math/heading.cpp']]
    fixture='tools/native_reconstruction/resource_flight_tests.cpp';helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';conversion='third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h';files=[*units,fixture,helper,conversion,Path(__file__).relative_to(ROOT).as_posix(),*entries.values()]
    for name in files:
        if name.startswith('game/native/'):
            for include in re.findall(r'^\s*#include "([^"]+)"',(ROOT/name).read_text(),re.M):
                target=((ROOT/name).parent/include).resolve()
                if not target.is_file():target=(ROOT/include).resolve()
                assert target.is_file()and target.is_relative_to(ROOT),(name,include)
                relative=target.relative_to(ROOT).as_posix()
                if relative not in files:files.append(relative)
    frozen={name:(ROOT/name).read_bytes()for name in files};out.mkdir(parents=True)
    for name,body in frozen.items():path=out/'source'/name;path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(body)
    reference=frozen[helper].decode().replace('Register r[32];','std::uint64_t lo{},hi{},lo1{},hi1{};Register r[32];').replace('pc{},branch_pc{},fcr31{}','pc{},branch_pc{},fcr31{},vu0_vpu_stat{}')
    reference+='\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define FPU_SQRT_S(a) std::sqrt(a)\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n'
    reference+='\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(a) Ps2FpuConvertWord(a)\n#define SRA32(a,b) (std::int32_t(a)>>unsigned(b))\n'
    (out/'reference.hpp').write_text(reference)
    (out/'ps2_fpu_convert.h').write_bytes(frozen[conversion])
    body='\n'.join(frozen[name].decode()for name in entries.values());(out/'original.cpp').write_text('#include "reference.hpp"\n#include "functions.h"\n#pragma GCC diagnostic push\n#pragma GCC diagnostic ignored "-Wunused-variable"\n'+body+'\n#pragma GCC diagnostic pop\n')
    actual={Path(name).stem for name in entries.values()};called=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(called-actual))
    (out/'functions.h').write_text('#pragma once\n'+decl);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for at,name in entries.items()))
    for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    for name in ['o0_functions.h','o2_functions.h','ps2_recompiled_functions.h','ps2_overlay_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
    constants='inline void owned_constants(std::uint8_t* memory){';ranges={}
    for bank,at,size in [('sub',0x22fe20,32),('sub',0x241c00,0x400),('sub',0x2392b8,76),('o0',0x38b290,4),('o2',0x7093d8,24),('o2',0x7093f0,108),('o2',0x709460,32)]:
        base=0x370000 if bank=='o0' else 0x570000;data=main_read(at,size)if bank=='sub'else banks[bank][at-base:at-base+size];ranges[hex(at)]={'bytes':size,'sha256':hashlib.sha256(data).hexdigest()}
        constants+='{const std::uint8_t data[]{'+','.join(str(value)for value in data)+'};std::memcpy(memory+'+str(at)+',data,sizeof data);}'
    constants+='const std::array<float,16> identity{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};std::memcpy(memory+0x294e00,identity.data(),64);'
    (out/'owned_constants.hpp').write_text(constants+'}\n');compiler=COMPILERS[args.compiler];binary=out/'checks.exe'
    command=[str(compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'source'/fixture),str(out/'original.cpp'),'-o',str(binary)]
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');record=dict(schema=1,status='failed',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256={name:hashlib.sha256(body).hexdigest()for name,body in frozen.items()},compiler_sha256=sha(compiler),original_word_audits=proof,owned_ranges=ranges,command=command,declared_ports=['Complete58E850 and reached math/RNG bodies execute.5795E0/57D560 queries and final audio/retirement are controlled; actual room/effect/audio lifetime remains separate.'])
    try:
        for label,cmd in [('compile',command),('run',[str(binary)])]:
            result=subprocess.run(cmd,capture_output=True,env=env,timeout=180);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);assert result.returncode==0,label+' failed; see retained logs'
            if label=='run':record['observed']=json.loads(result.stdout)
        record['source_unchanged']=all((ROOT/name).read_bytes()==body for name,body in frozen.items());assert record['source_unchanged'];record.update(status='passed',binary_sha256=sha(binary))
    finally:
        record['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.rglob('*')if path.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(record['observed']))
if __name__=='__main__':main()
