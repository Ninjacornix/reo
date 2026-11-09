"""Focused owned-word and actual-original dispatcher differential qualification."""
import argparse,hashlib,json,os,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
IDS=['0068C660','0068C950','0068C990','0068C9E0','0068CBE0','0068CD80','0068CD90','0068CDF0','0068CE30','0068CE90','0068CEC0','0068CF40','0068CF70','0068CFE0','0068D0B0','0068D0F0','0068D1B0','0068D2A0','0068E110','0068E140','0068E170','0068E1A0','0068E1D0','0068E1F0','0068E250','0068E280','0068E310','0068E3A0','0068E570','0068E590','00691240','00691260','00692710','00692750','00692790','006927D0','00692970','00694E90']
IDS += ['007003E0','007006D0','007009A0','00700A50','00700B00','00700BB0','00700E70','00700F00']
IDS += ['0068D670','0068D690','0068D6B0','0068D6D0','0068D6F0','0068D760','0068D780','0068D8F0','00592900','00592960','00592A10','00592B00','00592B90','00592C20','00592D50','005B4A50','00592CA0']
IDS += ['00691170','00691290','006918C0','006919D0','00691C10','006908E0','006909B0','00691E70','00691EB0','00701D10','00701DA0','00701E60','007008C0','00700930']
IDS += ['006915C0','00691630']
IDS += ['0068D310','0068D350','0068D380','0068D3D0','0068D400','0068D450','0068D4E0','0068D550','005BF0F0','005BF1B0']
IDS += ['0068D5D0','0068D5F0','0068D610','0068D630','006B1DC0','006B1EC0','006B1FE0','006B2020','006B2170','006B2FA0','006B3020','006B3090']
IDS += ['00690340','00690370','006903A0','006903C0']
IDS += ['00694E50','005C45C0','0068E630','0068E6D0','0068E730','0068E800','0068E8B0','0068E920','0068E9E0','0068EA70','0068EB30','0068EBF0','0068ECC0','0068ED30','0068EDA0','0068EE30','0068EEC0','0068F5C0','00691F00','00690810']
IDS += ['0068F570','0068F5A0']
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def invoke(command,out,label):
    p=subprocess.run(command,capture_output=True,text=True,timeout=120)
    (out/(label+'.stdout.txt')).write_text(p.stdout);(out/(label+'.stderr.txt')).write_text(p.stderr)
    if p.returncode:raise RuntimeError(label+' failed: '+p.stderr[-5000:])
    return dict(command=command,exit_code=p.returncode,stdout_sha256=sha(out/(label+'.stdout.txt')),stderr_sha256=sha(out/(label+'.stderr.txt')))
def main(a):
    cc=Path(a.compiler).resolve();out=a.output.resolve();assert cc.exists() and not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir(parents=True)
    raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    texts=[];sources={};words=0
    for ident in IDS:
        p=next((ROOT/'recomp/config/output_ovl/o2').glob('o2_'+ident+'_*'));text=p.read_text();sources[p.relative_to(ROOT).as_posix()]=sha(p);shutil.copyfile(p,out/p.name)
        for pc,opcode in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',text):
            assert struct.unpack_from('<I',raw,int(pc,16)-0x570000)[0]==int(opcode,16),(p,pc);words+=1
        texts.append('\n'.join(l for l in text.splitlines() if not l.startswith('#include')))
    elf_path=Path(os.environ['LOCALAPPDATA'])/'OutbreakRecomp/launcher/imports/file1/25e64b631bbaa0cac9a4822cb66174ff14c3531851d1e502c0a06704379bf446/data/SLUS_207.65'
    elf=elf_path.read_bytes();elf_sha=hashlib.sha256(elf).hexdigest();assert elf_sha=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    phoff=struct.unpack_from('<I',elf,28)[0];phsize,phcount=struct.unpack_from('<HH',elf,42);loads=[struct.unpack_from('<8I',elf,phoff+i*phsize) for i in range(phcount)];loads=[p for p in loads if p[0]==1]
    main_source=next((ROOT/'recomp/config/output').glob('sub_001B3C30_*'));main_text=main_source.read_text();sources[main_source.relative_to(ROOT).as_posix()]=sha(main_source);shutil.copyfile(main_source,out/main_source.name)
    for pc,opcode in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',main_text):
        at=int(pc,16);segment=next(p for p in loads if p[2]<=at and at+4<=p[2]+p[4]);assert struct.unpack_from('<I',elf,segment[1]+at-segment[2])[0]==int(opcode,16);words+=1
    segment=next(p for p in loads if p[2]<=0x1b3c30 and 0x1b3c38<=p[2]+p[4]);body=elf[segment[1]+0x1b3c30-segment[2]:segment[1]+0x1b3c38-segment[2]]
    assert struct.unpack('<II',body)==(0x03e00008,0);texts.append('\n'.join(l for l in main_text.splitlines() if not l.startswith('#include')))
    previous_names=set(re.findall(r'\b((?:o2|sub)_[A-Za-z0-9_]+)\(','\n'.join(texts)))|{'sub_00107AB0_0x107ab0'}
    stream_main=['001BA170','001ADA20','001ADFD0','001ADF50','001AE2E0','001AE3F0','001AE190'];stream_functions=set()
    for ident in stream_main:
        p=next((ROOT/'recomp/config/output').glob('sub_'+ident+'_*'));source=p.read_text();sources[p.relative_to(ROOT).as_posix()]=sha(p);shutil.copyfile(p,out/p.name)
        for pc,opcode in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',source):
            at=int(pc,16);segment=next(p for p in loads if p[2]<=at and at+4<=p[2]+p[4]);assert struct.unpack_from('<I',elf,segment[1]+at-segment[2])[0]==int(opcode,16);words+=1
        texts.append('\n'.join(l for l in source.splitlines() if not l.startswith('#include')));stream_functions.add('sub_'+ident+'_0x'+format(int(ident,16),'x'))
    stream_ports={f'sub_{a:08X}_0x{a:x}' for a in [0x131e38,0x131ef8,0x1327b8,0x132e50,0x133490,0x1b82a0,0x12bef8]}
    text='\n'.join(texts);names=sorted(set(re.findall(r'\b((?:o2|sub)_[A-Za-z0-9_]+)\(',text))|previous_names|stream_ports)
    unexecuted=set(names)-previous_names-stream_functions-stream_ports
    text+='\n'+'\n'.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Unexecuted main stream dependency '+name+'");}' for name in sorted(unexecuted))
    declarations=['void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);' for n in names]
    table=struct.unpack_from('<432I',raw,0x717830-0x570000)
    opener=[];at=0x717600-0x570000
    while True:
        value=struct.unpack_from('<I',raw,at)[0];at+=4;opener.append(value)
        if value==0xffffffff:break
    segment=next(p for p in loads if p[2]<=0x234060 and 0x234260<=p[2]+p[4]);curve=elf[segment[1]+0x234060-segment[2]:segment[1]+0x234260-segment[2]];assert hashlib.sha256(curve).hexdigest()=='36fb2dc8488a843da5b2ff8d7538afee1af1edbdb005746582e79cdd80032387'
    declarations+=['inline constexpr std::array<std::int32_t,128> original_stream_curve{'+','.join(str(v) for v in struct.unpack('<128i',curve))+'};',
        'inline constexpr std::array<std::uint32_t,432> original_opcode_table{'+','.join(hex(v) for v in table)+'};',
        'inline constexpr std::array<std::uint32_t,6> original_signed_comparisons{'+','.join(hex(v) for v in struct.unpack_from('<6I',raw,0x740890-0x570000))+'};',
        'inline constexpr std::array<std::uint32_t,'+str(len(opener))+'> original_opener_table{'+','.join(hex(v) for v in opener)+'};',
        'inline constexpr std::array<std::uint32_t,6> original_counter_comparisons{'+','.join(hex(v) for v in struct.unpack_from('<6I',raw,0x7408d0-0x570000))+'};',
        'inline constexpr std::array<std::uint32_t,864> original_offline_table{'+','.join(hex(v) for v in struct.unpack_from('<864I',raw,0x73cbe0-0x570000))+'};',
        'inline constexpr std::array<std::uint32_t,4> original_party_channels{'+','.join(hex(v) for v in struct.unpack_from('<4I',raw,0x73cbd0-0x570000))+'};']
    (out/'original_declarations.inc').write_text('\n'.join(declarations)+'\n')
    (out/'original_lookup.inc').write_text('\n'.join('case 0x'+n.split('_')[-1].removeprefix('0x')+':return '+n+';' for n in names)+'\n')
    fixture=(ROOT/'tools/native_reconstruction/gameplay_save/original_fixture.hpp').read_text().replace('0x400000','0x800000').replace('#include <cstdint>','#include <cstdint>\n#include <array>\n#include <bit>')
    fixture=fixture.replace('std::uint64_t lo{},hi{};','std::uint64_t lo{},hi{};float f[32]{};std::uint32_t fcr31{};')
    fixture=fixture.replace('Function lookupFunction(std::uint32_t)const{throw std::runtime_error("Unexpected original dynamic dispatch");}','Function lookupFunction(std::uint32_t)const;')
    shutil.copyfile(ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',out/'word_conversion.hpp');fixture+='#include "word_conversion.hpp"\n#define FPU_CVT_W_S(a) Ps2FpuConvertWord(float(a))\n#define FPU_SUB_S(a,b) (float(a)-float(b))\n#define FPU_MUL_S(a,b) (float(a)*float(b))\n#define FPU_DIV_S(a,b) (float(a)/float(b))\n#define FPU_MOV_S(a) (float(a))\n#define FPU_C_EQ_S(a,b) (float(a)==float(b))\n#define FPU_C_OLT_S(a,b) (float(a)<float(b))\n'
    fixture+='\n#define FPU_C_OLE_S(a,b) ((a)<=(b))\n#define FPU_CVT_S_W(a) (float(std::int32_t(a)))\n#define FPU_ADD_S(a,b) (float(a)+float(b))\n#define SRL32(a,b) (std::uint32_t(std::uint32_t(a)>>(std::uint32_t(b)&31)))\n#define SRA32(a,b) (std::int32_t(std::int32_t(a)>>(std::uint32_t(b)&31)))\n#define SUB32(a,b) (std::uint32_t(std::uint32_t(a)-std::uint32_t(b)))\n#define WRITE32(a,v) fixture_write<std::uint32_t>(rdram,a,v)\n'
    (out/'original_fixture.hpp').write_text(fixture);(out/'original.cpp').write_text('#include "original_fixture.hpp"\n#include "original_declarations.inc"\n'+text)
    shutil.copyfile(HERE/'tests.cpp',out/'tests.cpp')
    shutil.copyfile(HERE/'offline_tests.inc',out/'offline_tests.inc')
    shutil.copyfile(HERE/'scene_vm_fixture.inc',out/'scene_vm_fixture.inc')
    shutil.copyfile(HERE/'sequence_vm_fixture.inc',out/'sequence_vm_fixture.inc')
    shutil.copyfile(HERE/'lighting_vm_fixture.inc',out/'lighting_vm_fixture.inc')
    shutil.copyfile(HERE/'control_vm_fixture.inc',out/'control_vm_fixture.inc')
    shutil.copyfile(HERE/'stream_vm_fixture.inc',out/'stream_vm_fixture.inc')
    source_paths=[HERE/'tests.cpp',HERE/'offline_tests.inc',HERE/'scene_vm_fixture.inc',HERE/'sequence_vm_fixture.inc',HERE/'lighting_vm_fixture.inc',HERE/'control_vm_fixture.inc',HERE/'stream_vm_fixture.inc',HERE/'verify.py',ROOT/'game/native/gameplay_tasks/tasks.hpp',ROOT/'game/native/gameplay_tasks/tasks.cpp',ROOT/'game/native/gameplay_actors/entity.hpp',ROOT/'game/native/gameplay_actors/entity.cpp',ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_runtime_macros.h',ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h']
    source_paths += list((ROOT/'game/native/gameplay_scenario').glob('*.hpp'))+list((ROOT/'game/native/gameplay_scenario').glob('*.cpp'))+list((ROOT/'game/native/gameplay_scenario').glob('*.inc'))
    before={p.relative_to(ROOT).as_posix():sha(p) for p in source_paths}
    for p in source_paths:shutil.copyfile(p,out/(p.parent.name+'-'+p.name))
    os.environ['PATH']=str(cc.parent)+os.pathsep+os.environ.get('PATH','');base=[str(cc),'-std=c++20','-O2','-I'+str(ROOT),'-I'+str(out)]
    checks=[invoke(base+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')],out,'compile-original')]
    units=[('core',ROOT/'game/native/gameplay_scenario/interpreter.cpp'),('flags',ROOT/'game/native/gameplay_scenario/flags.cpp'),('offline',ROOT/'game/native/gameplay_scenario/offline.cpp'),('scene',ROOT/'game/native/gameplay_scenario/scene_resources.cpp'),('sequence',ROOT/'game/native/gameplay_scenario/sequence_control.cpp'),('lighting',ROOT/'game/native/gameplay_scenario/lighting.cpp'),('controls',ROOT/'game/native/gameplay_scenario/scene_controls.cpp'),('streams',ROOT/'game/native/gameplay_scenario/stream_channels.cpp'),('entities',ROOT/'game/native/gameplay_actors/entity.cpp'),('tasks',ROOT/'game/native/gameplay_tasks/tasks.cpp'),('tests',out/'tests.cpp')]
    for label,path in units:checks.append(invoke(base+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(path),'-o',str(out/(label+'.o'))],out,'compile-'+label))
    checks.append(invoke([str(cc)]+[str(out/(n+'.o')) for n in ['original','core','flags','offline','scene','sequence','lighting','controls','streams','entities','tasks','tests']]+['-o',str(out/'checks.exe')],out,'link'))
    checks.append(invoke([str(out/'checks.exe')],out,'test'));assert all(sha(ROOT/n)==digest for n,digest in before.items())
    receipt=dict(status='passed',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=before,original_sources_sha256=sources,checked_owned_instruction_comments=words,
        original_main_elf_sha256=elf_sha,original_main_leaf=dict(address='1B3C30',bytes=8,sha256=hashlib.sha256(body).hexdigest(),instructions=['jr ra','nop'],context_cases=4096),
        original_table_sha256=hashlib.sha256(struct.pack('<432I',*table)).hexdigest(),checks=checks,result=json.loads((out/'test.stdout.txt').read_text()),
        installed_in_game=False,game_launched=False,live_process_access=False,limitations=['Native opcode algorithm coverage is partial; entire programs with unsupported handlers are refused before native install.','Canonical flag storage and offline actor-delta merging are native; actual game caller/content import, notification delivery and message services remain external integration gates.','Actual original dispatcher and handler bodies are used only in the test oracle, with bounded memory/register scaffolding. No MIPS execution ships in native core.'])
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(status='passed',checks=receipt['result']['checks'],original_invocations=receipt['result']['original_dispatch_invocations'],coverage={k:v['count'] for k,v in receipt['result']['coverage'].items()},instruction_comments=words,output=str(out))))
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--compiler',required=True);p.add_argument('--output',required=True,type=Path);main(p.parse_args())
