"""Execute the fixed default catalogue route reached by cinematic speech cues."""
import argparse,hashlib,json,os,re,struct,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import elf_reader,compare_source
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    parser=argparse.ArgumentParser();parser.add_argument('--compiler',choices=COMPILERS,required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    out=args.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    image=ROOT/'game_data/SLUS_207.65';assert sha(image)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(image.read_bytes())
    addresses=[0x1ab450,0x1ae7d0,0x1adfd0,0x1ae6d0,0x1b82a0,0x1adb30,0x1ab2f0,0x1ab050,0x1ab310,0x10afc0,0x10b158,0x10ae78,0x10cda8];originals=[];bodies=[];audits=[]
    for at in addresses:
        source=ROOT/f'recomp/config/output/sub_{at:08X}_0x{at:x}.cpp';text=source.read_text();end=int(re.search(r'// Address: 0x[0-9a-fA-F]+ - 0x([0-9a-fA-F]+)',text)[1],16)
        audits.append(compare_source('complete original sound alias lookup',source.relative_to(ROOT).as_posix(),at,end,read));originals.append(source);bodies.append(text[text.index('// Function:'):])
    units=[ROOT/'game/native/gameplay_bank_loading/aliases.cpp']
    helper=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';tests=ROOT/'tools/native_reconstruction/cinematic_speech_lookup_tests.cpp';sdk=ROOT/'build-native-sjuni/dependency-muted-rna-reapply-v1/ps2xRuntime/include/ps2_runtime_macros.h'
    paths=units+[ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',helper,tests,Path(__file__),ROOT/'tools/native_reconstruction/generate_bank_aliases.py',sdk,*originals]
    for source in paths:
        for include in re.findall(r'^\s*#include "([^"]+)"',source.read_text(),re.M):
            local=(source.parent/include).resolve();target=local if local.is_file()else(ROOT/include).resolve()
            if target.is_file()and target.is_relative_to(ROOT)and target not in paths:paths.append(target)
    # Reuse the exact admitted SDK SIMD operations, not guessed packed semantics.
    macros={}
    for name in ['PS2_PSUBW','PS2_PSUBB','PS2_PAND','PS2_PNOR','PS2_PCPYLD']:
        macros[name]=next(line for line in sdk.read_text().splitlines()if line.startswith('#define '+name+'('))
    before={p.relative_to(ROOT).as_posix():sha(p)for p in paths};out.mkdir()
    for source in paths:
        p=out/'source'/source.relative_to(ROOT);p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(source.read_bytes())
    names={f'sub_{at:08X}_0x{at:x}'for at in addresses};calls=set(re.findall(r'\b((?:sub|o2)_[0-9A-F]+_0x[0-9a-f]+)\(','\n'.join(bodies)))
    header=helper.read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#include \"third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h\"\n#define FPU_CVT_W_S(a) Ps2FpuConvertWord(a)\n#define FPU_DIV_S(a,b) ((a)/(b))\n'+'\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n#define SRA32(a,b) (std::bit_cast<std::int32_t>(std::uint32_t(a)) >> unsigned(b))\n'+'\n'.join(macros.values())+'\n'
    header+='\n'.join(f'void {name}(std::uint8_t*,R5900Context*,PS2Runtime*);'for name in sorted(names))+'\n'
    header+='\n'.join(f'inline void {name}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}'for name in sorted(calls-names))+'\n'
    (out/'reference.hpp').write_text(header);(out/'original.cpp').write_text('#include "reference.hpp"\n#pragma GCC diagnostic ignored "-Wunused-variable"\n'+'\n'.join(bodies));(out/'original_dispatch.inc').write_text('\n'.join(f'case 0x{at:x}:return sub_{at:08X}_0x{at:x}(memory,context,runtime);'for at in addresses)+'\n')
    segments=[(0x2337c0,read(0x2337c0,422*4)),(0x2376e9,read(0x2376e9,256)),(0x24fd10,read(0x24fd10,32)),(0x234060,read(0x234060,512))]
    for at in struct.unpack('<422I',segments[0][1]):
        data=bytearray()
        for i in range(256):
            value=read(at+i,1)[0];data.append(value)
            if not value:break
        else:raise ValueError('Unbounded original name')
        segments.append((at,bytes(data)))
    (out/'owned_lookup.bin').write_bytes(struct.pack('<I',len(segments))+b''.join(struct.pack('<II',at,len(data))+data for at,data in segments))
    inventory=ROOT/'build-native-sjuni/facial-resource-inventory-v2/receipt.json';data=json.loads(inventory.read_bytes());descriptor_inventory=ROOT/'build-native-sjuni/cutscene-descriptor-inventory-v2/receipt.json';descriptors=json.loads(descriptor_inventory.read_bytes());loaded_scenarios={(row['scenario'],row['name']):row['layout']['identity'][0]for row in descriptors['rows']if row['version']=='0950'};assert len(loaded_scenarios)==548;cue_rows=[]
    for scene in data['scenes']:
        for request in scene['requests']:cue_rows.append((loaded_scenarios[scene['scenario'],scene['name']],int(scene['name'][2:4]),request['voice']if request['voice']<32768 else request['voice']-65536))
    assert len(cue_rows)==77;(out/'cues.txt').write_text('\n'.join(' '.join(map(str,row))for row in cue_rows)+'\n')
    cc=COMPILERS[args.compiler];exe=out/'lookup.exe';command=[str(cc),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out/'source'),'-I'+str(out),*[str(out/'source'/p.relative_to(ROOT))for p in units],str(out/'source'/tests.relative_to(ROOT)),str(out/'original.cpp'),'-o',str(exe)]
    record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(cc),original_owned_bodies=audits,inventory_sha256=sha(inventory),descriptor_inventory_sha256=sha(descriptor_inventory),game_run=False,stage4_complete=False,limits=['Complete1ADB30,1AB2F0,1AB050 and original string helpers execute over the actual fixed2337C0 catalogue; every reached SDK child is a throwing failure. All422 positive alias controls execute the lookup;77 actual descriptor requests try nine character suffixes plus signed boundary cases.','This proves the fixed owned default catalogue path only. Complete1AB450 archive activation and1AE7D0 preparation run first with nonzero SDK handles and declared SDK primitives. Their table/string bytes remain unchanged; subsequent VO lookup reaches no SDK children. The SDK primitives do not execute archive/decoder implementations here; those native owners have separate qualifications. No arbitrary replacement table or other locale is claimed.'])
    env=dict(os.environ,PATH=str(cc.parent)+os.pathsep+os.environ.get('PATH',''))
    try:
        result=subprocess.run(command,env=env,capture_output=True,timeout=240);(out/'compile.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'compile failed'
        record['run_command']=[str(exe),str(out/'owned_lookup.bin'),str(out/'cues.txt')];result=subprocess.run(record['run_command'],env=env,capture_output=True,timeout=180);(out/'run.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'lookup failed'
        record.update(status='passed',observed=json.loads(result.stdout),source_drift={name:sha(ROOT/name)for name,digest in before.items()if sha(ROOT/name)!=digest});assert not record['source_drift']
    finally:
        record['command']=command;record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(record['observed']))
if __name__=='__main__':main()
