"""Compare complete cinematic light key binding and incremental interpolation."""
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
    for owner,addresses in [('o2',[0x6b38d0,0x6b3900,0x6b3bb0,0x616f60]),('o0',[0x371600,0x370420])]:
        directory=ROOT/('recomp/config/output'if owner=='sub'else'recomp/config/output_ovl/'+owner)
        for address in addresses:entries[address]=next(directory.glob(f'{owner}_{address:08X}_*')).relative_to(ROOT).as_posix()
    proof=[]
    for name in set(entries.values()):
        text=(ROOT/name).read_text();start,end=(int(value,16)for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',text).groups());proof.append(compare_source('complete camera view or math helper',name,start,end,(lambda at,n:o2blob[at-0x570000:at-0x570000+n]) if start>=0x570000 else (lambda at,n:blob[at-0x370000:at-0x370000+n]) if start>=0x370000 else main_read))
    units=['game/native/gameplay_scenario/cutscene_light_curves.cpp'];files=set(units);pending=list(units)
    while pending:
        name=pending.pop()
        for relative in re.findall(r'^#include "([^"]+)"',(ROOT/name).read_text(),re.M):
            path=((ROOT/name).parent/relative).resolve();assert path.is_file()and path.is_relative_to(ROOT);key=path.relative_to(ROOT).as_posix()
            if key not in files:files.add(key);pending.append(key)
    helpers=['tools/native_reconstruction/cutscene_light_curves_tests.cpp','tools/native_reconstruction/verify_cutscene_light_curves.py','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'];files=sorted(files|set(entries.values())|set(helpers)|{'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h'});before={name:sha(ROOT/name)for name in files};out.mkdir();record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),original_owned_bodies=proof,game_run=False,stage4_complete=False,limits=['Complete6B38D0,6B3900,6B3BB0,616F60 and371600 execute;617000 is an explicit numeric material seam for this pure policy comparison, not a claim of transitive original grid execution. Canonical Lighting owns the actual pools; complete native pool admission/track ownership is qualified separately.','Finite FP32 nearest-rounding/native scalar-SIMD profile; physical PS2 exceptional arithmetic equivalence is not claimed.'])
    try:
        for name in files:target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
        reference=(ROOT/helpers[2]).read_text()+'\n'+(ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h').read_text()+'\n#define SRA32(a,b) (std::bit_cast<std::int32_t>(std::uint32_t(a))>>(unsigned(b)&31))\n#define SLLV32(a,b) (std::uint32_t(a)<<(unsigned(b)&31))\n#define FPU_CVT_W_S(a) Ps2FpuConvertWord(a)\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n'+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n';(out/'reference.hpp').write_text(reference)
        body='\n'.join((ROOT/name).read_text()for name in sorted(set(entries.values())));actual={Path(name).stem for name in entries.values()};calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(address)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for address,name in sorted(entries.items())))
        for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
        for name in ['ps2_recompiled_functions.h','o0_functions.h','o2_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
        for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
        constants='inline void owned_constants(std::uint8_t* p){\n'
        for at,n in [(0x22fe20,32),(0x241c78,32)]:
            data=main_read(at,n);constants+='{const std::uint8_t b[]{'+','.join(map(str,data))+'};std::memcpy(p+'+str(at)+',b,sizeof b);}\n'
        (out/'owned_constants.hpp').write_text(constants+'}\n');env=dict(os.environ,PATH=str(a.compiler.resolve().parent)+os.pathsep+os.environ.get('PATH',''));exe=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-O2','-ffunction-sections','-fdata-sections','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'source'/helpers[0]),str(out/'original.cpp'),'-Wl,--gc-sections','-o',str(exe)];record['command']=command
        result=subprocess.run(command,env=env,capture_output=True,timeout=240);(out/'compile.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'compile failed'
        result=subprocess.run([str(exe)],env=env,capture_output=True,timeout=180);(out/'run.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'comparison failed'
        record.update(status='passed',observed=json.loads(result.stdout),source_unchanged=all(sha(ROOT/name)==digest for name,digest in before.items()));assert record['source_unchanged']
    finally:
        record['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.rglob('*')if path.is_file()and path.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(dict(status=record['status'],observed=record['observed'])))
if __name__=='__main__':main()
