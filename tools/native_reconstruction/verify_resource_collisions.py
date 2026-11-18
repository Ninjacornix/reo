"""Compare real resource footprint/replacement bodies with shared native records."""
import argparse, hashlib, json, os, re, subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source, elf_reader
from verify_gameplay_collision import COMPILERS
ROOT = Path(__file__).resolve().parents[2]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    parser=argparse.ArgumentParser();parser.add_argument('--compiler',choices=COMPILERS,required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    out=args.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes())
    overlays={}
    for bank,digest in [('o0','bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'),('o2','45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226')]:
        p=ROOT/'build-function-index/owned-overlays'/f'{bank}.bin';assert sha(p)==digest;overlays[bank]=p.read_bytes()
    pending=[0x591860,0x5927f0,0x5c62f0,0x5c1120];entries={};bodies={};proof=[];ends={}
    while pending:
        at=pending.pop()
        if at in entries or at in [0x107ab0,0x107c68] or any(begin<=at<end for begin,end in ends.items()):continue
        bank='o2' if at>=0x570000 else 'o0' if at>=0x370000 else None
        folder=ROOT/(f'recomp/config/output_ovl/{bank}' if bank else 'recomp/config/output');matches=list(folder.glob(f'*_{at:08X}_*'));assert len(matches)==1,hex(at);p=matches[0];text=p.read_text();entries[at]=p;bodies[at]=text[text.index('// Function:'):]
        end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',text)[1],16)
        ends[at]=end
        reader=read if not bank else lambda pos,size,bank=bank:overlays[bank][pos-(0x570000 if bank=='o2' else 0x370000):pos-(0x570000 if bank=='o2' else 0x370000)+size]
        proof.append(compare_source('complete resource collision construction or reached math/pool body',p.relative_to(ROOT).as_posix(),at,end,reader))
        pending.extend(int(v,16) for v in re.findall(r'// 0x[0-9a-f]+: 0x[0-9a-f]+\s+(?:jal|j)\s+func_([0-9A-Fa-f]+)',text))
    units=[ROOT/'game/native'/n for n in ['gameplay_scenario/resource_collisions.cpp','gameplay_scenario/scene_resources.cpp','gameplay_scenario/resource_templates.cpp','transform_math/transform_math.cpp']]
    tests=ROOT/'tools/native_reconstruction/resource_collisions_tests.cpp';helper=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';paths=units+[tests,helper,Path(__file__),*entries.values()]
    for p in paths:
        for include in re.findall(r'^\s*#include "([^"]+)"',p.read_text(),re.M):
            local=(p.parent/include).resolve();dep=local if local.is_file() else (ROOT/include).resolve()
            if dep.is_file() and dep.is_relative_to(ROOT) and dep not in paths:paths.append(dep)
    frozen={p.relative_to(ROOT).as_posix():p.read_bytes() for p in paths};out.mkdir()
    for name,body in frozen.items():
        p=out/'source'/name;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(body)
    header=frozen[helper.relative_to(ROOT).as_posix()].decode().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#define FPU_CVT_W_S(a) static_cast<std::int32_t>(a)\n'
    header+='\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n'
    names={p.stem for p in entries.values()};calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(', '\n'.join(bodies.values())))
    header+='\n'.join(f'void {n}(std::uint8_t*,R5900Context*,PS2Runtime*);' for n in names)+'\n'
    header+='\n'.join(f'inline void {n}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}' for n in calls-names)+'\n'
    (out/'reference.hpp').write_text(header);(out/'original.cpp').write_text('#include "reference.hpp"\n#pragma GCC diagnostic ignored "-Wunused-variable"\n'+'\n'.join(bodies.values()))
    (out/'dispatch.inc').write_text('\n'.join(f'case 0x{at:x}:return {p.stem}(ram,ctx,runtime);' for at,p in entries.items())+'\n')
    constants={at:read(at,size) for at,size in [(0x22fe20,32),(0x241c78,40)]};constants[0x723340]=overlays['o2'][0x723340-0x570000:0x723660-0x570000]
    actual=[int(n) for n in re.findall(r'-?\d+', (ROOT/'game/native/gameplay_scenario/resource_collision_profile.inc').read_text().split('\n',1)[1])]
    import struct
    assert struct.pack('<200i',*actual)==constants[0x723340]
    init='inline void owned_constants(std::uint8_t* p){\n'
    for at,payload in constants.items():init+='{const std::uint8_t b[]{'+','.join(str(v) for v in payload)+'};std::memcpy(p+'+str(at)+',b,sizeof b);}\n'
    (out/'owned_constants.hpp').write_text(init+'}\n')
    cc=COMPILERS[args.compiler];exe=out/'collisions.exe';command=[str(cc),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out/'source'),'-I'+str(out),*[str(out/'source'/p.relative_to(ROOT)) for p in units],str(out/'source'/tests.relative_to(ROOT)),str(out/'original.cpp'),'-o',str(exe)]
    record=dict(schema=1,status='failed',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256={n:hashlib.sha256(b).hexdigest() for n,b in frozen.items()},compiler_sha256=sha(cc),original_word_audits=proof,constants={hex(at):b.hex() for at,b in constants.items()},declared_ports=['bounded107C68 zeroing and107AB0 copy, private oracle only','finite in-int32 CVT profile; exceptional/out-of-range source conversions not claimed'],checks=[])
    env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','')
    try:
        for label,cmd in [('compile',command),('test',[str(exe)])]:
            result=subprocess.run(cmd,capture_output=True,env=env,timeout=180);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);record['checks'].append(dict(label=label,exit=result.returncode,command=cmd))
            if result.returncode:raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-4000:])
            if label=='test':record['results']=json.loads(result.stdout)
        record['source_unchanged']=all((ROOT/n).read_bytes()==b for n,b in frozen.items());assert record['source_unchanged'];record['status']='passed'
    finally:
        record['output_sha256']={p.relative_to(out).as_posix():sha(p) for p in out.rglob('*') if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(record['results']))
if __name__=='__main__':main()
