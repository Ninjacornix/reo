"""Compare original alias lookup and test actual bounded native bank loading."""
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
    addresses=[0x1ab050,0x1ab310,0x10afc0,0x10b158,0x10ae78,0x10cda8];originals=[];bodies=[];audits=[]
    for at in addresses:
        source=ROOT/f'recomp/config/output/sub_{at:08X}_0x{at:x}.cpp';text=source.read_text();end=int(re.search(r'// Address: 0x[0-9a-fA-F]+ - 0x([0-9a-fA-F]+)',text)[1],16)
        audits.append(compare_source('complete original sound alias lookup',source.relative_to(ROOT).as_posix(),at,end,read));originals.append(source);bodies.append(text[text.index('// Function:'):])
    units=[ROOT/'game/native'/n for n in ['gameplay_bank_loading/aliases.cpp','gameplay_bank_loading/loader.cpp','gameplay_audio/owner.cpp','gameplay_audio/import.cpp','gameplay_audio/routing.cpp','gameplay_audio/spatial.cpp','gameplay_session/session.cpp','audio_banks/v2/session.cpp','audio_banks/v2/algorithms.cpp','resources/bounded_view.cpp','resources/virtual_file_view.cpp','resources/resource_session.cpp','resources_windows/pinned_file.cpp','resource_io/async_read_owner.cpp','afs_source_range/afs_source_range.cpp','tasks/serial_worker.cpp']]
    helper=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';tests=ROOT/'tools/native_reconstruction/bank_loading_tests.cpp';sdk=ROOT/'build-native-sjuni/dependency-muted-rna-reapply-v1/ps2xRuntime/include/ps2_runtime_macros.h'
    paths=units+[helper,tests,Path(__file__),ROOT/'tools/native_reconstruction/generate_bank_aliases.py',ROOT/'game/native/gameplay_bank_loading/CMakeLists.txt',ROOT/'game/native/CMakeLists.txt',sdk,*originals]
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
    header=helper.read_text()+'\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n#define SRA32(a,b) (std::bit_cast<std::int32_t>(std::uint32_t(a)) >> unsigned(b))\n'+'\n'.join(macros.values())+'\n'
    header+='\n'.join(f'void {name}(std::uint8_t*,R5900Context*,PS2Runtime*);'for name in sorted(names))+'\n'
    header+='\n'.join(f'inline void {name}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}'for name in sorted(calls-names))+'\n'
    (out/'reference.hpp').write_text(header);(out/'original.cpp').write_text('#include "reference.hpp"\n#pragma GCC diagnostic ignored "-Wunused-variable"\n'+'\n'.join(bodies));(out/'original_dispatch.inc').write_text('\n'.join(f'case 0x{at:x}:return sub_{at:08X}_0x{at:x}(memory,context,runtime);'for at in addresses)+'\n')
    segments=[(0x2337c0,read(0x2337c0,422*4)),(0x2376e9,read(0x2376e9,256))]
    for at in struct.unpack('<422I',segments[0][1]):
        data=bytearray()
        for i in range(256):
            value=read(at+i,1)[0];data.append(value)
            if not value:break
        else:raise ValueError('Unbounded original name')
        segments.append((at,bytes(data)))
    (out/'owned_lookup.bin').write_bytes(struct.pack('<I',len(segments))+b''.join(struct.pack('<II',at,len(data))+data for at,data in segments))
    inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';members=[m for m in json.loads(inventory.read_bytes())if m.get('names')and m['names'][-1].endswith('.snd')];assert len(members)==104
    (out/'owned_banks.txt').write_text('104\n'+''.join(m['member'].rsplit('/',1)[1]+' '+m['names'][-1]+'\n'for m in members))
    digest='69ae2c48e6f01e2605659feabb54eb9b82c63a809bdc8a78ad2d160b3c59a4a1';(out/'owned_iso.hpp').write_text('constexpr std::uint64_t owned_iso_bytes=4698767360ull;\nconstexpr reo::native::resources::win32::Digest owned_iso_sha{'+','.join(str(v)for v in bytes.fromhex(digest))+'};\n')
    cc=COMPILERS[args.compiler];exe=out/'banks.exe';command=[str(cc),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out/'source'),'-I'+str(out),*[str(out/'source'/p.relative_to(ROOT))for p in units],str(out/'source'/tests.relative_to(ROOT)),str(out/'original.cpp'),'-lbcrypt','-o',str(exe)]
    record={'schema':1,'status':'failed','game_run':False,'installed_in_game':False,'source_sha256':before,'compiler_sha256':sha(cc),'original_word_audits':audits,'owned_iso_sha256':digest,'inventory_sha256':sha(inventory),'checks':[]};env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','')
    try:
        for name,cmd in [('compile',command),('test',[str(exe),str(out/'owned_lookup.bin'),str(out/'owned_banks.txt'),str(ROOT/'iso/Resident Evil - Outbreak (v2.00).iso')])]:
            result=subprocess.run(cmd,capture_output=True,env=env,timeout=240);(out/(name+'.stdout.txt')).write_bytes(result.stdout);(out/(name+'.stderr.txt')).write_bytes(result.stderr);record['checks'].append({'label':name,'exit':result.returncode,'command':cmd})
            if result.returncode:raise RuntimeError(name+': '+result.stderr.decode(errors='replace')[-6000:])
            if name=='test':record['results']=json.loads(result.stdout)
        record['source_drift']={p:sha(ROOT/p)for p,h in before.items()if sha(ROOT/p)!=h};assert not record['source_drift'];record['status']='passed'
    finally:
        record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(record['results']))
if __name__=='__main__':main()
