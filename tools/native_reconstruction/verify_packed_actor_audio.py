"""Full packed audio frontends against immutable native owners and real PCM."""
import argparse,hashlib,json,os,re,shutil,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    parent=ROOT/'build-native-sjuni'/f'pose-work-updates-{a.compiler}-v4';prior=json.loads((parent/'receipt.json').read_bytes());assert prior['status']=='passed'
    unit='game/native/gameplay_world/packed_actor_audio.cpp';fixture='tools/native_reconstruction/packed_actor_audio_tests.cpp';helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';files=[unit,fixture,helper,Path(__file__).relative_to(ROOT).as_posix()];frozen={}
    for name,digest in prior['source_sha256'].items():assert sha(parent/'source'/name)==digest;frozen[name]=(parent/'source'/name).read_bytes()
    pending=list(files)
    for name in pending:
        if name not in frozen or name==unit:frozen[name]=(ROOT/name).read_bytes()
        if name.startswith('game/native/'):
            for include in re.findall(r'^\s*#include "([^"]+)"',frozen[name].decode(),re.M):
                path=((ROOT/name).parent/include).resolve();path=path if path.is_file()else(ROOT/include).resolve();assert path.is_file()and path.is_relative_to(ROOT);relative=path.relative_to(ROOT).as_posix()
                if relative not in pending:pending.append(relative)
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());entries={};proof=[]
    for at in [0x1ba5e0,0x1ba4c0,0x1b91e0,0x1b8bb0,0x1aec80]:
        path=next((ROOT/'recomp/config/output').glob(f'sub_{at:08X}_*'));name=path.relative_to(ROOT).as_posix();contents=path.read_bytes();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',contents.decode())[1],16);proof.append(compare_source('complete packed actor sound frontend or random helper',name,at,end,read));frozen[name]=contents;entries[at]=name
    out.mkdir(parents=True)
    for name,contents in frozen.items():
        path=out/'source'/name;path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(contents)
    (out/'reference.hpp').write_text(frozen[helper].decode().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#define GPR_S32(c,i) std::int32_t(GPR_U32(c,i))\n#define SRA32(v,s) (std::int32_t(v)>>((s)&31))\n')
    body='\n'.join(frozen[name].decode()for name in entries.values());actual={Path(name).stem for name in entries.values()};called=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(called-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for at,name in entries.items()));(out/'original.cpp').write_text('#include "reference.hpp"\n#include "functions.h"\n'+body)
    for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
    libraries=[]
    for name,digest in prior['native_library_sha256'].items():
        source=parent/'libraries'/name;assert sha(source)==digest;target=out/'libraries'/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(source,target);libraries.append(str(target))
    cue_parent=ROOT/'build-native-sjuni/resource-flight-owner-llvm-v4';cue_record=json.loads((cue_parent/'receipt.json').read_bytes());cue=cue_parent/'owned_flight_cue.bin';assert sha(cue)==cue_record['flight_cue_asset']['sha256'];shutil.copyfile(cue,out/'owned_cue.bin')
    compiler=COMPILERS[a.compiler];binary=out/'checks.exe';command=[str(compiler),'-std=c++20','-O2','-msse4.1','-ffunction-sections','-fdata-sections','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),str(out/'source'/unit),str(out/'source'/fixture),str(out/'original.cpp'),'-Wl,--gc-sections','-Wl,--start-group',*libraries,'-Wl,--end-group','-o',str(binary)];env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''));record=dict(schema=1,status='failed',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,source_sha256={name:hashlib.sha256(value).hexdigest()for name,value in frozen.items()},compiler_sha256=sha(compiler),native_parent={'path':str(parent/'receipt.json'),'sha256':sha(parent/'receipt.json')},native_library_sha256=prior['native_library_sha256'],owned_cue=cue_record['flight_cue_asset'],original_word_audits=proof,command=command,declared_ports=['Complete1BA5E0/1BA4C0/1B91E0/1B8BB0 and1AEC80 execute; final1B93D0 invokes independent actual native bank/spatial/PCM owners.', 'Class2/3 program tags are explicit test inputs through a required provider; unknown real producer remains unadmitted. Registers unassigned by original class routes are excluded.'])
    try:
        for label,cmd in [('compile',command),('run',[str(binary),str(out/'owned_cue.bin')])]:
            result=subprocess.run(cmd,capture_output=True,env=env,timeout=300);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);assert result.returncode==0,label+' failed; see retained logs'
            if label=='run':record['observed']=json.loads(result.stdout)
        owned={unit,fixture,Path(__file__).relative_to(ROOT).as_posix()}|{n for n in pending if n not in prior['source_sha256']};record['owned_source_drift']={n:sha(ROOT/n)for n in owned if (ROOT/n).read_bytes()!=frozen[n]};assert not record['owned_source_drift'];record['subsequent_parent_header_changes']={n:sha(ROOT/n)for n in pending if n in prior['source_sha256']and(ROOT/n).read_bytes()!=frozen[n]};record.update(status='passed',binary_sha256=sha(binary))
    finally:
        record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(record['observed']))


if __name__=='__main__':main()
