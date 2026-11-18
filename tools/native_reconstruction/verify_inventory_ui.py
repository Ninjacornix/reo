"""Actual6DEC80 initialization and108/5F4FD0/6E1430 cold UI lifecycle."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
from verify_native_session import dependency_sources
ROOT=Path(__file__).resolve().parents[2]
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
    build=ROOT/'build-native-sjuni'/f'gameplay-native-{a.compiler}-v1';paths,libraries=dependency_sources(build)
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes()
    addresses=[0x6dec80,0x6925c0,0x5f4fd0,0x6e1430]
    originals=[next((ROOT/'recomp/config/output_ovl/o2').glob(f'*_{at:08X}_*'))for at in addresses]
    audits=[]
    for source in originals:
        start,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',source.read_text()).groups()]
        audits.append(compare_source('complete UI constructor/closed command body',source.relative_to(ROOT).as_posix(),start,end,lambda at,n:raw[at-0x570000:at-0x570000+n]))
    fixture=ROOT/'tools/native_reconstruction/inventory_ui_tests.cpp';reference=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';native=ROOT/'game/native/gameplay_application/native_session.cpp';ui=ROOT/'game/native/gameplay_world/inventory_ui.cpp'
    paths=set(paths)|set(originals)|{fixture,reference,Path(__file__).resolve(),native,native.with_suffix('.hpp'),ui,ui.with_suffix('.hpp')}
    before={x.relative_to(ROOT).as_posix():sha(x)for x in sorted(paths)}
    for name in before:
        target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
    lib_hash={name:sha(build/name)for name in libraries}
    for name in libraries:
        target=out/'libraries'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((build/name).read_bytes())
        assert sha(target)==lib_hash[name], 'Native archive changed during capture: '+name
    (out/'reference.hpp').write_text(reference.read_text().replace('Register r[32];','std::uint64_t lo{},hi{},lo1{},hi1{};Register r[32];')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n')
    body='\n'.join(x.read_text()for x in originals);(out/'original.cpp').write_text(body)
    actual={x.stem for x in originals};called=set(re.findall(r'\b((?:sub|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    decl=''.join(f'void {name}(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual))
    decl+=''.join(f'inline void {name}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}\n'for name in sorted(called-actual))
    (out/'functions.h').write_text('#pragma once\n'+decl)
    (out/'original_dispatch.hpp').write_text(''.join(f'case {hex(at)}:{source.stem}(memory,context,runtime);return;\n'for at,source in zip(addresses,originals)))
    for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    for name in ['o2_functions.h','ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
    inventory=json.loads((ROOT/'build-native-sjuni/gameplay-script-content-llvm-v21/inventory.json').read_bytes());archive=Path(inventory[0]['archive']);compiler=COMPILERS[a.compiler];exe=out/'checks.exe'
    command=[str(compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/x.relative_to(ROOT))for x in [native,ui,fixture]],'-Wl,--start-group',*[str(out/'libraries'/name)for name in libraries],'-Wl,--end-group','-lpthread','-o',str(exe)]
    receipt=dict(schema='reo.native.inventory_ui.v1',status='failed',source_sha256=before,native_library_sha256=lib_hash,compiler_sha256=sha(compiler),original_word_audits=audits,boundaries=['Complete6DEC80 establishes the typed cold UI projection; other16004-byte payload roles are not invented as a native RAM bank.','Complete108/5F4FD0/6E1430 execute with actual phase0; active phases require real equipment/audio/UI teardown owners and are outside this admitted profile.','All eight whole affected source actor records are checked through test-only projections; actual NativeSession owns the sole InventoryUi and shares RecoveryUi.'],game_launched=False)
    env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''))
    try:
        for label,cmd in [('compile',command),('run',[str(exe),str(archive)])]:
            result=subprocess.run(cmd,capture_output=True,text=True,env=env,timeout=600);(out/(label+'.txt')).write_text(result.stdout+result.stderr);assert result.returncode==0,label+': '+(result.stdout+result.stderr)[-4000:]
            if label=='run':receipt['observed']=json.loads(result.stdout)
        receipt['source_drift']={name:sha(ROOT/name)for name,digest in before.items()if sha(ROOT/name)!=digest};assert not receipt['source_drift'];receipt['source_unchanged']=True;receipt['status']='passed'
    finally:
        receipt['output_sha256']={x.relative_to(out).as_posix():sha(x)for x in out.rglob('*')if x.is_file()and x.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(receipt['observed']))
if __name__=='__main__':main()
