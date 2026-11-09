"""Compare the actual64-primary-model allocation/list/update owner."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--compiler',choices=COMPILERS,required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();out=args.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    image=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=image.read_bytes();addresses=[0x590be0,0x590c70,0x590d80,0x590ea0];originals=[];bodies=[];proof=[]
    for at in addresses:
        p=ROOT/f'recomp/config/output_ovl/o2/o2_{at:08X}_0x{at:x}.cpp';text=p.read_text();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',text)[1],16);proof.append(compare_source('complete primary resource model owner',p.relative_to(ROOT).as_posix(),at,end,lambda pos,size:raw[pos-0x570000:pos-0x570000+size]));originals.append(p);bodies.append(text[text.index('// Function:'):])
    units=[ROOT/'game/native/gameplay_world/resource_models.cpp',ROOT/'game/native/gameplay_actors/entity.cpp'];tests=ROOT/'tools/native_reconstruction/resource_models_tests.cpp';helper=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';paths=units+[tests,helper,Path(__file__),*originals]
    for source in paths:
        for include in re.findall(r'^\s*#include "([^"]+)"',source.read_text(),re.M):
            local=(source.parent/include).resolve();p=local if local.is_file()else(ROOT/include).resolve()
            if p.is_file()and p.is_relative_to(ROOT)and p not in paths:paths.append(p)
    before={p.relative_to(ROOT).as_posix():sha(p)for p in paths};out.mkdir()
    for source in paths:
        p=out/'source'/source.relative_to(ROOT);p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(source.read_bytes())
    names={f'o2_{at:08X}_0x{at:x}'for at in addresses};calls=set(re.findall(r'\b((?:sub|o2)_[0-9A-F]+_0x[0-9a-f]+)\(','\n'.join(bodies)))
    header=helper.read_text().replace('Register r[32];','std::uint64_t hi{},lo{};Register r[32];')+'\n'
    header+='\n'.join(f'void {n}(std::uint8_t*,R5900Context*,PS2Runtime*);'for n in sorted(names))+'\n'
    header+='\n'.join(f'inline void {n}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}'for n in sorted(calls-names))+'\n'
    (out/'reference.hpp').write_text(header);(out/'original.cpp').write_text('#include "reference.hpp"\n#pragma GCC diagnostic ignored "-Wunused-variable"\n'+'\n'.join(bodies));(out/'dispatch.inc').write_text('\n'.join(f'case 0x{at:x}:return o2_{at:08X}_0x{at:x}(ram,ctx,runtime);'for at in addresses)+'\n')
    cc=COMPILERS[args.compiler];exe=out/'models.exe';cmd=[str(cc),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out/'source'),'-I'+str(out),*[str(out/'source'/p.relative_to(ROOT))for p in units],str(out/'source'/tests.relative_to(ROOT)),str(out/'original.cpp'),'-o',str(exe)];record={'schema':1,'status':'failed','game_run':False,'source_sha256':before,'original_word_audits':proof,'compiler_sha256':sha(cc),'checks':[]};env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','')
    try:
        for label,command in [('compile',cmd),('test',[str(exe)])]:
            result=subprocess.run(command,capture_output=True,env=env,timeout=120);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);record['checks'].append({'label':label,'exit':result.returncode,'command':command})
            if result.returncode:raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-5000:])
            if label=='test':record['results']=json.loads(result.stdout)
        record['source_drift']={p:sha(ROOT/p)for p,h in before.items()if sha(ROOT/p)!=h};assert not record['source_drift'];record['status']='passed'
    finally:
        record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(record['results']))
if __name__=='__main__':main()
