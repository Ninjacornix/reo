"""Focused owned-word and actual-original dispatcher differential qualification."""
import argparse,hashlib,json,os,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
IDS=['0068C660','0068C950','0068C990','0068C9E0','0068CBE0','0068CD80','0068CD90','0068CDF0','0068CE30','0068CE90','0068CEC0','0068CF40','0068CF70','0068CFE0','0068D0B0','0068D0F0','0068D1B0','0068D2A0','0068E110','0068E140','0068E170','0068E1A0','0068E1D0','0068E1F0','0068E250','0068E280','0068E310','0068E3A0','0068E570','0068E590','00691240','00691260','00692710','00692750','00692790','006927D0','00692970','00694E90']
IDS += ['007003E0','007006D0','007009A0','00700A50','00700B00','00700BB0','00700E70','00700F00']
IDS += ['0068D670','0068D690','0068D6B0','0068D6D0','0068D6F0','0068D760','0068D780','0068D8F0','00592900','00592960','00592A10','00592B00','00592B90','00592C20','00592D50','005B4A50','00592CA0']
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
    text='\n'.join(texts);names=sorted(set(re.findall(r'\b((?:o2|sub)_[A-Za-z0-9_]+)\(',text))|{'sub_00107AB0_0x107ab0'})
    declarations=['void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);' for n in names]
    table=struct.unpack_from('<432I',raw,0x717830-0x570000)
    opener=[];at=0x717600-0x570000
    while True:
        value=struct.unpack_from('<I',raw,at)[0];at+=4;opener.append(value)
        if value==0xffffffff:break
    declarations+=['inline constexpr std::array<std::uint32_t,432> original_opcode_table{'+','.join(hex(v) for v in table)+'};',
        'inline constexpr std::array<std::uint32_t,6> original_signed_comparisons{'+','.join(hex(v) for v in struct.unpack_from('<6I',raw,0x740890-0x570000))+'};',
        'inline constexpr std::array<std::uint32_t,'+str(len(opener))+'> original_opener_table{'+','.join(hex(v) for v in opener)+'};',
        'inline constexpr std::array<std::uint32_t,6> original_counter_comparisons{'+','.join(hex(v) for v in struct.unpack_from('<6I',raw,0x7408d0-0x570000))+'};',
        'inline constexpr std::array<std::uint32_t,864> original_offline_table{'+','.join(hex(v) for v in struct.unpack_from('<864I',raw,0x73cbe0-0x570000))+'};',
        'inline constexpr std::array<std::uint32_t,4> original_party_channels{'+','.join(hex(v) for v in struct.unpack_from('<4I',raw,0x73cbd0-0x570000))+'};']
    (out/'original_declarations.inc').write_text('\n'.join(declarations)+'\n')
    (out/'original_lookup.inc').write_text('\n'.join('case 0x'+n.split('_')[-1].removeprefix('0x')+':return '+n+';' for n in names)+'\n')
    fixture=(ROOT/'tools/native_reconstruction/gameplay_save/original_fixture.hpp').read_text().replace('0x400000','0x800000').replace('#include <cstdint>','#include <cstdint>\n#include <array>')
    fixture=fixture.replace('Function lookupFunction(std::uint32_t)const{throw std::runtime_error("Unexpected original dynamic dispatch");}','Function lookupFunction(std::uint32_t)const;')
    fixture+='\n#define SRL32(a,b) (std::uint32_t(std::uint32_t(a)>>(std::uint32_t(b)&31)))\n#define SUB32(a,b) (std::uint32_t(std::uint32_t(a)-std::uint32_t(b)))\n#define WRITE32(a,v) fixture_write<std::uint32_t>(rdram,a,v)\n'
    (out/'original_fixture.hpp').write_text(fixture);(out/'original.cpp').write_text('#include "original_fixture.hpp"\n#include "original_declarations.inc"\n'+text)
    shutil.copyfile(HERE/'tests.cpp',out/'tests.cpp')
    shutil.copyfile(HERE/'offline_tests.inc',out/'offline_tests.inc')
    shutil.copyfile(HERE/'scene_vm_fixture.inc',out/'scene_vm_fixture.inc')
    source_paths=[HERE/'tests.cpp',HERE/'offline_tests.inc',HERE/'scene_vm_fixture.inc',HERE/'verify.py',ROOT/'game/native/gameplay_tasks/tasks.hpp',ROOT/'game/native/gameplay_tasks/tasks.cpp',ROOT/'game/native/gameplay_actors/entity.hpp',ROOT/'game/native/gameplay_actors/entity.cpp']
    source_paths += list((ROOT/'game/native/gameplay_scenario').glob('*.hpp'))+list((ROOT/'game/native/gameplay_scenario').glob('*.cpp'))+list((ROOT/'game/native/gameplay_scenario').glob('*.inc'))
    before={p.relative_to(ROOT).as_posix():sha(p) for p in source_paths}
    for p in source_paths:shutil.copyfile(p,out/(p.parent.name+'-'+p.name))
    os.environ['PATH']=str(cc.parent)+os.pathsep+os.environ.get('PATH','');base=[str(cc),'-std=c++20','-O2','-I'+str(ROOT),'-I'+str(out)]
    checks=[invoke(base+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')],out,'compile-original')]
    units=[('core',ROOT/'game/native/gameplay_scenario/interpreter.cpp'),('flags',ROOT/'game/native/gameplay_scenario/flags.cpp'),('offline',ROOT/'game/native/gameplay_scenario/offline.cpp'),('scene',ROOT/'game/native/gameplay_scenario/scene_resources.cpp'),('entities',ROOT/'game/native/gameplay_actors/entity.cpp'),('tasks',ROOT/'game/native/gameplay_tasks/tasks.cpp'),('tests',out/'tests.cpp')]
    for label,path in units:checks.append(invoke(base+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(path),'-o',str(out/(label+'.o'))],out,'compile-'+label))
    checks.append(invoke([str(cc)]+[str(out/(n+'.o')) for n in ['original','core','flags','offline','scene','entities','tasks','tests']]+['-o',str(out/'checks.exe')],out,'link'))
    checks.append(invoke([str(out/'checks.exe')],out,'test'));assert all(sha(ROOT/n)==digest for n,digest in before.items())
    receipt=dict(status='passed',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=before,original_sources_sha256=sources,checked_owned_instruction_comments=words,
        original_table_sha256=hashlib.sha256(struct.pack('<432I',*table)).hexdigest(),checks=checks,result=json.loads((out/'test.stdout.txt').read_text()),
        installed_in_game=False,game_launched=False,live_process_access=False,limitations=['Native opcode algorithm coverage is partial; entire programs with unsupported handlers are refused before native install.','Canonical flag storage and offline actor-delta merging are native; actual game caller/content import, notification delivery and message services remain external integration gates.','Actual original dispatcher and handler bodies are used only in the test oracle, with bounded memory/register scaffolding. No MIPS execution ships in native core.'])
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(status='passed',checks=receipt['result']['checks'],original_invocations=receipt['result']['original_dispatch_invocations'],coverage={k:v['count'] for k,v in receipt['result']['coverage'].items()},instruction_comments=words,output=str(out))))
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--compiler',required=True);p.add_argument('--output',required=True,type=Path);main(p.parse_args())
