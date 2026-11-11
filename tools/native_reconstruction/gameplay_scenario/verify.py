"""Focused owned-word and actual-original dispatcher differential qualification."""
import argparse,hashlib,json,os,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
IDS=['0068C660','0068C950','0068C990','0068C9E0','0068CBE0','0068CD80','0068CD90','0068CDF0','0068CE30','0068CE90','0068CEC0','0068CF40','0068CF70','0068CFE0','0068D0B0','0068D0F0','0068D1B0','0068D2A0','0068E110','0068E140','0068E170','0068E1A0','0068E1D0','0068E1F0','0068E250','0068E280','0068E310','0068E3A0','0068E570','0068E590','00691240','00691260','00692710','00692750','00692790','006927D0','00692970','00694E90']
IDS += ['007003E0','007006D0','007009A0','00700A50','00700B00','00700BB0','00700E70','00700F00']
IDS += ['0068D670','0068D690','0068D6B0','0068D6D0','0068D6F0','0068D760','0068D780','0068D8F0','00592900','00592960','00592A10','00592B00','00592B90','00592C20','00592D50','005B4A50','00592CA0']
IDS += ['00691170','00691290','006918C0','006919D0','00691C10','006908E0','006909B0','00691E70','00691EB0','00701D10','00701DA0','00701E60','007008C0','00700930']
IDS += ['006915C0','00691630']
IDS += ['0068ECA0']
IDS += ['0068D310','0068D350','0068D380','0068D3D0','0068D400','0068D450','0068D4E0','0068D550','005BF0F0','005BF1B0']
IDS += ['0068D5D0','0068D5F0','0068D610','0068D630','006B1DC0','006B1EC0','006B1FE0','006B2020','006B2170','006B2FA0','006B3020','006B3090']
IDS += ['00690340','00690370','006903A0','006903C0']
IDS += ['00694E50','005C45C0','0068E630','0068E6D0','0068E730','0068E800','0068E8B0','0068E920','0068E9E0','0068EA70','0068EB30','0068EBF0','0068ECC0','0068ED30','0068EDA0','0068EE30','0068EEC0','0068F5C0','00691F00','00690810']
IDS += ['0068F570','0068F5A0']
IDS += ['006920E0','006922B0','007020E0','00702380','00693020','00693840','00694DA0','00581830','00690600','00690640','00690700','00694E70','005705F0','005704B0','00570550']
IDS += ['00690AC0','00690B80','00690C40','00690D40','00690DD0','00690E60','006B0780','006AD260','006AD360','006AD310']

IDS += ['00691FA0','00692630','0064AE50','006261D0','00626310','006263D0','0057E840','006269B0','00667370']
IDS += ['00692B10','005D9630','00573890']
IDS += ['00690490','005DFA90']
IDS += ['00691D20','005D7CF0']
IDS += ['0068F1D0','0068F1F0','0068F280','0068F3C0','006268D0']
IDS += ['0068D920','0068DA50','00694BC0','00592A90','00591AE0','005B42B0','005F2810','005F2330','005B43F0']
IDS += ['0068F010','005F0150','006B73F0','00692A00','006BA230','006B7480','006B74D0','006B80A0','00691720','006929A0','006929D0']
IDS += ['0068FDC0','0068FE40','0068FEB0','00684770']
IDS += ['005F0380','005F0230','00662C90','006040A0']
IDS += ['0068EFF0']
IDS += ['005EB0D0']
IDS += ['00683A90','00684010','006841E0','006842B0','00684450','00681240','006812B0','0068DBA0','0068DF10']
IDS += ['0068F8D0','0068F920','0068F970','0068FA40','0068FAC0','0068FB20','0068FB80','00681330']
IDS += ['006BAA40','006BB010','006BC210','006D45A0','006D4650','005A7BC0']
IDS += ['0068FC00']
IDS += ['006BB9F0']
IDS += ['006BBDA0','006EFAF0']

PINNED={};PIN_COMMITS={}
def source_bytes(p):
    path=p.resolve();name=path.relative_to(ROOT).as_posix() if path.is_relative_to(ROOT) else None
    return PINNED[name] if name in PINNED else p.read_bytes()
def sha(p):return hashlib.sha256(source_bytes(p)).hexdigest()
def invoke(command,out,label):
    p=subprocess.run(command,capture_output=True,text=True,timeout=120)
    (out/(label+'.stdout.txt')).write_text(p.stdout);(out/(label+'.stderr.txt')).write_text(p.stderr)
    if p.returncode:raise RuntimeError(label+' failed: '+p.stderr[-5000:])
    return dict(command=command,exit_code=p.returncode,stdout_sha256=sha(out/(label+'.stdout.txt')),stderr_sha256=sha(out/(label+'.stderr.txt')))
def main(a):
    cc=Path(a.compiler).resolve();out=a.output.resolve();assert cc.exists() and not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir(parents=True)
    groups=[]
    if a.pin_domain_commit:groups.append((a.pin_domain_commit,['game/native/gameplay_world/world.hpp','game/native/gameplay_world/world.cpp','game/native/gameplay_scenario/scene_resources.hpp','game/native/gameplay_scenario/scene_resources.cpp']))
    if a.pin_effects_commit:groups.append((a.pin_effects_commit,['game/native/gameplay_effects/'+base+suffix for base in ['periodic_visuals','geometry','tracks']for suffix in ['.hpp','.cpp']]))
    for commit,names in groups:
        for name in names:
            PINNED[name]=subprocess.run(['git','show',commit+':'+name],cwd=ROOT,capture_output=True,check=True).stdout;PIN_COMMITS[name]=commit
    raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    assert raw[0x717820-0x570000:0x717830-0x570000]==bytes([0,0,1,1,0,0,1,1,2,2,3,3,2,2,3,3])
    texts=[];sources={};words=0
    for ident in IDS:
        p=next((ROOT/'recomp/config/output_ovl/o2').glob('o2_'+ident+'_*'));text=p.read_text();sources[p.relative_to(ROOT).as_posix()]=sha(p);shutil.copyfile(p,out/p.name)
        for pc,opcode in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',text):
            assert struct.unpack_from('<I',raw,int(pc,16)-0x570000)[0]==int(opcode,16),(p,pc);words+=1
        if ident=='005F2330':
            text=text.replace('void o2_005F2330_0x5f2330(', 'void original_inventory_compact(')
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
    stream_main=['001BA170','001ADA20','001ADFD0','001ADF50','001AE2E0','001AE3F0','001AE190','001B0340','001B02D0','001B0300','001AEC80','0018F570','0018FDF0','00190A10','001913E0','00191530','001919D0','001B3C40','001D45F0','001B2D80'];stream_functions=set()
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
    declarations.append('void original_inventory_compact(std::uint8_t*,R5900Context*,PS2Runtime*);')
    fallback=raw[0x7174d0-0x570000:0x7174e4-0x570000]
    declarations.append('inline constexpr std::array<std::uint8_t,20> original_cutscene_fallback{'+','.join(str(v) for v in fallback)+'};')
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
        'inline constexpr std::array<std::uint32_t,4> original_party_channels{'+','.join(hex(v) for v in struct.unpack_from('<4I',raw,0x73cbd0-0x570000))+'};',
        'inline constexpr std::array<std::int16_t,64> original_room_counter_policy{'+','.join(str(v) for v in struct.unpack_from('<64h',raw,0x717690-0x570000))+'};']
    initialization='inline void owned_model_constants(std::uint8_t* p){\n'
    for at,size in [(0x22fe20,32),(0x241c78,32)]:
        segment=next(p for p in loads if p[2]<=at and at+size<=p[2]+p[4]);chunk=elf[segment[1]+at-segment[2]:segment[1]+at-segment[2]+size];values=struct.unpack('<'+str(size//4)+'I',chunk)
        initialization+='const std::array<std::uint32_t,'+str(len(values))+'> c'+str(at)+'{'+','.join(hex(v)+'u' for v in values)+'};std::memcpy(p+'+str(at)+',c'+str(at)+'.data(),'+str(size)+');\n'
    presets=struct.unpack_from('<48I',raw,0x7174f0-0x570000);initialization+='const std::array<std::uint32_t,48> presets{'+','.join(hex(v)+'u'for v in presets)+'};std::memcpy(p+0x7174f0,presets.data(),192);\n}\n'
    footprint=raw[0x723740-0x570000:0x723740-0x570000+200];assert hashlib.sha256(footprint).hexdigest()=='c49896573cdc5137476866c5b6ac54566e95893b9a0e97b786ee31eabc403659'
    initialization+='inline void owned_object_constants(std::uint8_t* p){const std::array<std::uint8_t,200> b{'+','.join(str(x) for x in footprint)+'};std::memcpy(p+0x723740,b.data(),b.size());}\n'
    request_table=struct.unpack_from('<43I',raw,0x711960-0x570000);assert request_table[0x28]==0x6269b0 and struct.unpack_from('<I',raw,0x711960-0x570000+43*4)[0]==0
    initialization+='inline void owned_request_constants(std::uint8_t* p){const std::array<std::uint32_t,43> b{'+','.join(hex(x)+'u' for x in request_table)+'};std::memcpy(p+0x711960,b.data(),sizeof(b));}\n'
    declarations.append(initialization)
    initialization='inline void owned_enemy_constants(std::uint8_t* p){\n'
    for address,size in [(0x729270,0x1f00),(0x72f820,256),(0x7318c0,0x280)]:
        chunk=raw[address-0x570000:address-0x570000+size]
        assert len(chunk)==size
        initialization+='const std::array<std::uint8_t,'+str(size)+'> bytes_'+str(address)+'{'+','.join(str(byte) for byte in chunk)+'};std::memcpy(p+'+str(address)+',bytes_'+str(address)+'.data(),'+str(size)+');\n'
    declarations.append(initialization+'}\n')
    zero=(ROOT/'build-function-index/owned-overlays/o0.bin').read_bytes()
    assert hashlib.sha256(zero).hexdigest()=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'
    chunk=zero[0x3872b0-0x370000:0x3889e0-0x370000]
    declarations.append('inline void owned_linked_definition_constants(std::uint8_t* p){const std::array<std::uint8_t,'+str(len(chunk))+'> b{'+','.join(map(str,chunk))+'};std::memcpy(p+0x3872b0,b.data(),b.size());}\n')
    initialization='inline void owned_enemy_binding_constants(std::uint8_t* p){\n'
    for address,size in [(0x72b170,0x60),(0x72bc20,0x100),(0x72be20,62),(0x734640,0xa0)]:
        chunk=raw[address-0x570000:address-0x570000+size]
        assert len(chunk)==size
        initialization+='const std::array<std::uint8_t,'+str(size)+'> bytes_'+str(address)+'{'+','.join(map(str,chunk))+'};std::memcpy(p+'+str(address)+',bytes_'+str(address)+'.data(),'+str(size)+');\n'
    declarations.append(initialization+'}\n')
    (out/'original_declarations.inc').write_text('\n'.join(declarations)+'\n')
    actual_definitions=set(re.findall(r'^void ((?:o2|sub)_[A-Za-z0-9_]+)\(','\n'.join(texts),re.M));lookup={}
    for n in names:
        at=int(n.split('_')[-1],16)
        if at not in lookup or n in actual_definitions:lookup[at]=n
    (out/'original_lookup.inc').write_text('\n'.join(f'case 0x{at:x}:return {n};'for at,n in sorted(lookup.items()))+'\n')
    reference=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    fixture=reference.read_text().replace('float vu0_q{};','float vu0_q{};std::uint64_t lo{},hi{};')
    fixture=fixture.replace('Function lookupFunction(std::uint32_t)const noexcept{return original_transform_port;}','Function lookupFunction(std::uint32_t)const;')
    fixture+='\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n'
    fixture+='\ntemplate<class T>T fixture_read(const std::uint8_t* p,std::uint32_t a){return transform_read<T>(p,a);}'
    fixture+='\ntemplate<class T>void fixture_write(std::uint8_t* p,std::uint32_t a,T value){transform_write(p,a,value);}\n'
    shutil.copyfile(ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',out/'word_conversion.hpp')
    fixture+='#include "word_conversion.hpp"\n#define FPU_CVT_W_S(a) Ps2FpuConvertWord(float(a))\n#define FPU_DIV_S(a,b) (float(a)/float(b))\n#define FPU_C_EQ_S(a,b) (float(a)==float(b))\n#define SRA32(a,b) (std::int32_t(std::int32_t(a)>>(std::uint32_t(b)&31)))\n'
    (out/'original_fixture.hpp').write_text(fixture);(out/'original.cpp').write_text('#include "original_fixture.hpp"\n#include "original_declarations.inc"\n'+text)
    shutil.copyfile(HERE/'tests.cpp',out/'tests.cpp')
    shutil.copyfile(HERE/'no_model_vm_tests.inc',out/'no_model_vm_tests.inc')
    shutil.copyfile(HERE/'surface_vm_tests.inc',out/'surface_vm_tests.inc')
    shutil.copyfile(HERE/'offline_tests.inc',out/'offline_tests.inc')
    shutil.copyfile(HERE/'actor_request_vm_tests.inc',out/'actor_request_vm_tests.inc')
    shutil.copyfile(HERE/'room_variant_vm_tests.inc',out/'room_variant_vm_tests.inc')
    shutil.copyfile(HERE/'room_counter_vm_tests.inc',out/'room_counter_vm_tests.inc')
    shutil.copyfile(HERE/'stock_room_vm_tests.inc',out/'stock_room_vm_tests.inc')
    shutil.copyfile(HERE/'actor_placement_vm_tests.inc',out/'actor_placement_vm_tests.inc')
    shutil.copyfile(HERE/'actor_inventory_vm_tests.inc',out/'actor_inventory_vm_tests.inc')
    shutil.copyfile(HERE/'scene_boot_vm_tests.inc',out/'scene_boot_vm_tests.inc')
    shutil.copyfile(HERE/'room_actor_assets_vm_tests.inc',out/'room_actor_assets_vm_tests.inc')
    shutil.copyfile(HERE/'transition_input_vm_tests.inc',out/'transition_input_vm_tests.inc')
    shutil.copyfile(HERE/'launch_roster_vm_tests.inc',out/'launch_roster_vm_tests.inc')
    shutil.copyfile(HERE/'npc_vm_tests.inc',out/'npc_vm_tests.inc')
    from npc_fixtures import write_fixture
    npc_members=write_fixture(out)
    from npc_fixtures import write_enemy_fixture
    enemy_members=write_enemy_fixture(out)
    from qualify_enemy_route_profile import generate as route_profile, OUTPUT as route_output
    from qualify_enemy_spawn_profile import generate as spawn_profile, OUTPUT as spawn_output
    assert route_output.read_text()==route_profile() and spawn_output.read_text()==spawn_profile()
    shutil.copyfile(HERE/'enemy_vm_tests.inc',out/'enemy_vm_tests.inc')
    shutil.copyfile(HERE/'character_remap_vm_tests.inc',out/'character_remap_vm_tests.inc')
    from qualify_enemy_initialization_profiles import generate as initialization_profiles, MODELS, PRIORITIES
    for path,expected in zip((MODELS,PRIORITIES),initialization_profiles()):
        assert path.read_text()==expected
    shutil.copyfile(HERE/'enemy_initialization_vm_tests.inc',out/'enemy_initialization_vm_tests.inc')
    from qualify_enemy_binding_profiles import generate as binding_profile, OUTPUT as binding_output
    assert binding_output.read_text()==binding_profile()
    shutil.copyfile(HERE/'enemy_binding_vm_tests.inc',out/'enemy_binding_vm_tests.inc')
    shutil.copyfile(HERE/'periodic_control_vm_tests.inc',out/'periodic_control_vm_tests.inc')
    shutil.copyfile(HERE/'room_rule_tests.inc',out/'room_rule_tests.inc')
    shutil.copyfile(HERE/'room_object_vm_tests.inc',out/'room_object_vm_tests.inc')
    shutil.copyfile(HERE/'scene_vm_fixture.inc',out/'scene_vm_fixture.inc')
    shutil.copyfile(HERE/'sequence_vm_fixture.inc',out/'sequence_vm_fixture.inc')
    shutil.copyfile(HERE/'lighting_vm_fixture.inc',out/'lighting_vm_fixture.inc')
    shutil.copyfile(HERE/'control_vm_fixture.inc',out/'control_vm_fixture.inc')
    shutil.copyfile(HERE/'stream_vm_fixture.inc',out/'stream_vm_fixture.inc')
    shutil.copyfile(HERE/'actor_vm_fixture.inc',out/'actor_vm_fixture.inc')
    shutil.copyfile(HERE/'model_vm_fixture.inc',out/'model_vm_fixture.inc')
    units=[('core',ROOT/'game/native/gameplay_scenario/interpreter.cpp'),('flags',ROOT/'game/native/gameplay_scenario/flags.cpp'),('offline',ROOT/'game/native/gameplay_scenario/offline.cpp'),('scene',ROOT/'game/native/gameplay_scenario/scene_resources.cpp'),('sequence',ROOT/'game/native/gameplay_scenario/sequence_control.cpp'),('lighting',ROOT/'game/native/gameplay_scenario/lighting.cpp'),('controls',ROOT/'game/native/gameplay_scenario/scene_controls.cpp'),('streams',ROOT/'game/native/gameplay_scenario/stream_channels.cpp'),('rules',ROOT/'game/native/gameplay_scenario/room_rules.cpp'),('models',ROOT/'game/native/gameplay_scenario/scene_models.cpp'),('room_scene_input',ROOT/'game/native/gameplay_scenario/room_scene_input.cpp'),('room_scene_owner',ROOT/'game/native/gameplay_scenario/room_scene_owner.cpp'),('model_bindings',ROOT/'game/native/gameplay_scenario/scene_model_bindings.cpp'),('matrix_programs',ROOT/'game/native/gameplay_scenario/scene_matrix_programs.cpp'),('matrix_playback',ROOT/'game/native/gameplay_scenario/scene_matrix_playback.cpp'),('matrix_tables',ROOT/'game/native/gameplay_scenario/scene_matrix_tables.cpp'),('content',ROOT/'game/native/gameplay_scenario/content.cpp'),('math',ROOT/'game/native/transform_math/transform_math.cpp'),('world',ROOT/'game/native/gameplay_world/world.cpp'),('input',ROOT/'game/native/gameplay_actors/input.cpp'),('session',ROOT/'game/native/gameplay_session/session.cpp'),('entities',ROOT/'game/native/gameplay_actors/entity.cpp'),('tasks',ROOT/'game/native/gameplay_tasks/tasks.cpp'),('actor_requests',ROOT/'game/native/gameplay_scenario/actor_requests.cpp'),('motion',ROOT/'game/native/gameplay_world/motion.cpp'),('object_commands',ROOT/'game/native/gameplay_scenario/room_object_commands.cpp'),('tests',out/'tests.cpp')]
    units += [('object_'+n,ROOT/'game/native/gameplay_collision'/(n+'.cpp'))for n in ['collision','response','sweep','actors','ownership','room_objects','footprint','trace','room_geometry','object_interactions','object_lifetime']]
    units += [('canonical_light_access',ROOT/'game/native/gameplay_lighting/lights.cpp')]
    units += [('effect_'+n,ROOT/'game/native/gameplay_effects'/(n+'.cpp'))for n in ['periodic_visuals','geometry','tracks','resource_debris']]
    units += [('companion_'+n,ROOT/'game/native'/folder/(n+'.cpp'))for folder,n in [('gameplay_effects','resource_companion'),('gameplay_world','resource_models'),('gameplay_world','model_attachments'),('gameplay_scenario','resource_templates')]]
    units += [('animation_'+n,ROOT/'game/native/animation'/(n+'.cpp'))for n in ['model','model_math','curves']]
    units += [('periodic_tasks',ROOT/'game/native/gameplay_scenario/periodic_effects.cpp')]
    units += [('room_damage',ROOT/'game/native/gameplay_collision/room_damage.cpp')]
    units += [('script_program',ROOT/'game/native/gameplay_scenario/script_program.cpp')]
    units += [('actor_placements',ROOT/'game/native/gameplay_world/actor_placements.cpp')]
    units += [('actor_inventory_commands',ROOT/'game/native/gameplay_scenario/actor_inventory_commands.cpp')]
    units += [(name,ROOT/'game/native/gameplay_scenario'/(name+'.cpp')) for name in ['auxiliary_room_rows','cutscene_requests']]
    units += [('cutscene_cues',ROOT/'game/native/gameplay_scenario/cutscene_cues.cpp')]
    units += [('launch',ROOT/'game/native/gameplay_session/launch.cpp'),('launch_roster',ROOT/'game/native/gameplay_world/launch_roster.cpp')]
    units += [('npc_descriptors',ROOT/'game/native/gameplay_scenario/npc_descriptors.cpp')]
    units += [(name,ROOT/'game/native/gameplay_scenario'/(name+'.cpp')) for name in ('enemy_descriptors','enemy_routes')]
    units += [('character_remap',ROOT/'game/native/gameplay_scenario/character_remap.cpp')]
    units += [('enemy_initialization',ROOT/'game/native/gameplay_world/enemy_initialization.cpp')]
    if not a.pin_effects_commit:
        import sys
        sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
        from effect_work_sources import SURFACE_WORLD_UNITS
        for i,name in enumerate(SURFACE_WORLD_UNITS+['game/native/gameplay_scenario/fog.cpp']):
            path=ROOT/name
            if path not in [p for _,p in units]:units.append(('surface_dependency_'+str(i),path))
    source_paths=[HERE/'no_model_vm_tests.inc',HERE/'actor_request_vm_tests.inc',HERE/'room_object_vm_tests.inc',HERE/'tests.cpp',HERE/'offline_tests.inc',HERE/'room_rule_tests.inc',HERE/'scene_vm_fixture.inc',HERE/'sequence_vm_fixture.inc',HERE/'lighting_vm_fixture.inc',HERE/'control_vm_fixture.inc',HERE/'stream_vm_fixture.inc',HERE/'actor_vm_fixture.inc',HERE/'model_vm_fixture.inc',reference,HERE/'verify.py',ROOT/'game/native/gameplay_tasks/tasks.hpp',ROOT/'game/native/gameplay_tasks/tasks.cpp',ROOT/'game/native/gameplay_actors/entity.hpp',ROOT/'game/native/gameplay_actors/entity.cpp',ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_runtime_macros.h',ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h']
    source_paths += [path for label,path in units if not path.is_relative_to(ROOT/'build-native-sjuni')]
    source_paths.append(HERE/'periodic_control_vm_tests.inc')
    source_paths.append(HERE/'room_variant_vm_tests.inc')
    source_paths.append(HERE/'room_counter_vm_tests.inc')
    source_paths.append(HERE/'stock_room_vm_tests.inc')
    source_paths.append(HERE/'actor_placement_vm_tests.inc')
    source_paths.append(HERE/'actor_inventory_vm_tests.inc')
    source_paths.append(HERE/'scene_boot_vm_tests.inc')
    source_paths.append(HERE/'room_actor_assets_vm_tests.inc')
    source_paths.append(HERE/'transition_input_vm_tests.inc')
    source_paths.append(HERE/'launch_roster_vm_tests.inc')
    source_paths += [HERE/'npc_vm_tests.inc',HERE/'npc_fixtures.py']
    source_paths += [HERE/'enemy_vm_tests.inc',HERE/'qualify_enemy_route_profile.py',HERE/'qualify_enemy_spawn_profile.py']
    source_paths.append(HERE/'character_remap_vm_tests.inc')
    source_paths += [HERE/'enemy_initialization_vm_tests.inc',HERE/'qualify_enemy_initialization_profiles.py']
    source_paths += [HERE/'enemy_binding_vm_tests.inc',HERE/'qualify_enemy_binding_profiles.py']
    source_paths += [HERE/'surface_vm_tests.inc',ROOT/'tools/native_reconstruction/effect_work_sources.py']
    source_paths += [ROOT/p for p in ['game/native/gameplay_world/world.hpp','game/native/gameplay_world/world.cpp','game/native/gameplay_actors/input.hpp','game/native/gameplay_actors/input.cpp','game/native/gameplay_actors/health.hpp','game/native/gameplay_actors/hit.hpp','game/native/gameplay_actors/status.hpp','game/native/gameplay_session/session.hpp','game/native/gameplay_session/session.cpp']]
    source_paths += [ROOT/'game/native/transform_math/transform_math.hpp',ROOT/'game/native/transform_math/transform_math.cpp']
    pending=list(source_paths);closure=set(p.resolve() for p in source_paths)
    while pending:
        path=pending.pop()
        for included in re.findall(r'#include "([^"]+)"',source_bytes(path).decode()):
            candidate=next((p.resolve() for p in [path.parent/included,ROOT/included] if p.exists()),None)
            if candidate and candidate.is_relative_to(ROOT/'game/native') and candidate not in closure:closure.add(candidate);pending.append(candidate)
    source_paths=sorted(closure)
    before={p.relative_to(ROOT).as_posix():sha(p) for p in source_paths}
    for p in source_paths:
        target=out/'source'/p.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(source_bytes(p))
    corpus=ROOT/'build-native-sjuni/effect-geometry-owned-v1';corpus_receipt=json.loads((corpus/'receipt.json').read_bytes());assert len(corpus_receipt['assets'])==12 and sha(corpus/'owned_effect_geometry.bin')==corpus_receipt['package_sha256'];shutil.copyfile(corpus/'owned_effect_geometry.bin',out/'owned_effect_geometry.bin')
    index=ROOT/'build-native-sjuni/gameplay-script-content-llvm-v14'
    index_receipt=json.loads((index/'receipt.json').read_bytes())
    assert index_receipt['status']=='passed' and sha(index/'inventory.json')==index_receipt['output_sha256']['inventory.json']
    members=json.loads((index/'inventory.json').read_bytes())
    evbs=[r for r in members if r['format']=='E']
    assert len(evbs)==5
    policy_path=out/'owned_counter_evbs.bin'
    with policy_path.open('wb') as package:
        for evb in evbs:
            with Path(evb['archive']).open('rb') as stream:
                stream.seek(evb['archive_offset'])
                bank=stream.read(evb['bytes'])
            assert hashlib.sha256(bank).hexdigest()==evb['sha256']
            obj=next(r for r in evb['declared_objects'] if r['table_index']==13)
            start=obj['offset']
            assert obj['upper_bound_bytes']==256 and struct.unpack_from('<I',bank,0x34)[0]==start
            package.write(struct.pack('<I',len(bank)))
            package.write(bank)
    stock=next(r for r in members if r['name']=='r0417300.rdt')
    with Path(stock['archive']).open('rb') as stream:
        stream.seek(stock['archive_offset'])
        room=stream.read(stock['bytes'])
    assert hashlib.sha256(room).hexdigest()==stock['sha256']
    stock_path=out/'owned_stock_room.rdt'
    stock_path.write_bytes(room)
    os.environ['PATH']=str(cc.parent)+os.pathsep+os.environ.get('PATH','');base=[str(cc),'-std=c++20','-O2','-msse4.1','-pthread','-fno-fast-math','-ffp-contract=off','-I'+str(out/'source'),'-I'+str(out)]
    if a.pin_effects_commit:base+=['-DREO_VM_PINNED_EFFECTS=1']
    checks=[invoke(base+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')],out,'compile-original')]
    for label,path in units:
        frozen=out/'source'/path.relative_to(ROOT)if not path.is_relative_to(ROOT/'build-native-sjuni')else path
        checks.append(invoke(base+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(frozen),'-o',str(out/(label+'.o'))],out,'compile-'+label))
    checks.append(invoke([str(cc)]+[str(out/'original.o')]+[str(out/(n+'.o')) for n,p in units]+['-o',str(out/'checks.exe')],out,'link'))
    checks.append(invoke([str(out/'checks.exe'),str(out/'owned_effect_geometry.bin'),str(policy_path),str(stock_path),str(out/'owned_enemy_members.bin')],out,'test'));assert all(sha(ROOT/n)==digest for n,digest in before.items())
    receipt=dict(status='passed',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=before,original_sources_sha256=sources,checked_owned_instruction_comments=words,
        pinned_shared_sources={name:dict(commit=PIN_COMMITS[name],sha256=hashlib.sha256(data).hexdigest())for name,data in PINNED.items()},pinned_current_source_drift={name:hashlib.sha256((ROOT/name).read_bytes()).hexdigest()for name,data in PINNED.items()if (ROOT/name).read_bytes()!=data},oracle_profile=dict(reference_sha256=sha(reference),sdk131_sign_extended_word_setter=True,finite_simd=True,transitive_native_headers=True,compiled_private_source_snapshot=True,periodic_scheduler_allocation_declared_port=True,actual_native_periodic_visual_owner=True),periodic_effect_corpus=dict(receipt=str((corpus/'receipt.json').relative_to(ROOT)),sha256=sha(corpus/'receipt.json'),package_sha256=corpus_receipt['package_sha256']),executable_sha256=sha(out/'checks.exe'),generated_fixture_sha256=sha(out/'original_fixture.hpp'),generated_original_sha256=sha(out/'original.cpp'),original_main_elf_sha256=elf_sha,original_main_leaf=dict(address='1B3C30',bytes=8,sha256=hashlib.sha256(body).hexdigest(),instructions=['jr ra','nop'],context_cases=4096),
        original_table_sha256=hashlib.sha256(struct.pack('<432I',*table)).hexdigest(),npc_members=npc_members,
        npc_fixture_sha256=sha(out/'owned_npc_fixtures.inc'),checks=checks,result=json.loads((out/'test.stdout.txt').read_text()),
        enemy_members=enemy_members,enemy_fixture_sha256=sha(out/'owned_enemy_members.bin'),
        installed_in_game=False,game_launched=False,live_process_access=False,limitations=['Native opcode algorithm coverage is partial; entire programs with unsupported handlers are refused before native install.','Canonical flag storage and offline actor-delta merging are native; actual game caller/content import, notification delivery and message services remain external integration gates.','Actual original dispatcher and handler bodies are used only in the test oracle, with bounded memory/register scaffolding. No MIPS execution ships in native core.'])
    receipt['room_counter_policy']=dict(index_receipt_sha256=sha(index/'receipt.json'),owned_members={e['name']:e['sha256'] for e in evbs},package_sha256=sha(policy_path))
    receipt['stock_room']=dict(name=stock['name'],sha256=sha(stock_path),installed_in_game=False)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(status='passed',checks=receipt['result']['checks'],original_invocations=receipt['result']['original_dispatch_invocations'],coverage={k:v['count'] for k,v in receipt['result']['coverage'].items()},instruction_comments=words,output=str(out))))
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--compiler',required=True);p.add_argument('--output',required=True,type=Path);p.add_argument('--pin-domain-commit');p.add_argument('--pin-effects-commit');main(p.parse_args())
