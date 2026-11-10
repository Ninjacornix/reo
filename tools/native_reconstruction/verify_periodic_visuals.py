"""Compare native periodic visuals with complete owned creation/update bodies."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import struct
from effect_work_sources import SURFACE_WORLD_UNITS
from audit_retail_effect_descriptors import compare_source, elf_reader
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    p = argparse.ArgumentParser()
    p.add_argument('--compiler', type=Path, required=True)
    p.add_argument('--corpus', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    p.add_argument('--resource-pulses', action='store_true')
    p.add_argument('--resource-static', action='store_true')
    p.add_argument('--resource-factory', action='store_true')
    p.add_argument('--resource-placement', action='store_true')
    p.add_argument('--resource-delayed', action='store_true')
    p.add_argument('--resource-actions', action='store_true')
    p.add_argument('--resource-inventory', action='store_true')
    p.add_argument('--weapon-resources', action='store_true')
    p.add_argument('--equipment-resources', action='store_true')
    p.add_argument('--equipment-selection', action='store_true')
    p.add_argument('--resource-companion-policy', action='store_true')
    args = p.parse_args()
    assert not args.resource_factory or args.resource_static
    assert not args.resource_placement or args.resource_factory
    assert not args.resource_delayed or args.resource_placement
    assert not args.resource_actions or args.resource_delayed
    assert not args.resource_inventory or args.resource_actions
    assert not args.weapon_resources or args.resource_inventory
    assert not args.equipment_resources or args.weapon_resources
    assert not args.equipment_selection or args.equipment_resources
    assert not args.resource_companion_policy or args.resource_placement
    out = args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT / 'build-native-sjuni')
    corpus = args.corpus.resolve()
    cr = json.loads((corpus / 'receipt.json').read_bytes())
    assert len(cr['assets']) == 12 and sha(corpus / 'owned_effect_geometry.bin') == cr['package_sha256']
    elf = ROOT / 'game_data/SLUS_207.65'
    assert sha(elf) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    main_read = elf_reader(elf.read_bytes())
    overlay = {}
    for bank, digest in [('o0', 'bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'), ('o2', '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226')]:
        path = ROOT / 'build-function-index/owned-overlays' / (bank + '.bin')
        assert sha(path) == digest
        overlay[bank] = path.read_bytes()
    pending = [0x1d3350, 0x1a31b0, 0x1a34b0, 0x1a3500, 0x6525d0, 0x6535c0, 0x651850, 0x652ce0, 0x5d9680]
    if args.resource_pulses: pending += [0x5925c0]
    if args.resource_static: pending += [0x1d3100,0x372490]
    if args.resource_factory: pending += [0x18fdf0,0x191530]
    if args.resource_placement: pending += [0x370320,0x191a40,0x1aec80]
    if args.resource_delayed: pending += [0x1904a0,0x190020]
    ports = [0x107c68, 0x18dc50, 0x18dca0, 0x18dc90, 0x1b10c0, 0x1b1110, 0x1b3830, 0x573740]
    entries = {}
    while pending:
        at = pending.pop()
        if at in entries or at in ports:
            continue
        bank = 'o2' if at >= 0x570000 else 'o0' if at >= 0x370000 else None
        folder = ROOT / ('recomp/config/output_ovl/' + bank if bank else 'recomp/config/output')
        matches = list(folder.glob(f'{bank or "sub"}_{at:08X}_*'))
        if not matches:
            continue
        name = matches[0].relative_to(ROOT).as_posix()
        entries[at] = name
        pending.extend(int(v, 16) for v in re.findall(r'// 0x[0-9a-f]+: 0x[0-9a-f]+\s+(?:jal|j)\s+func_([0-9A-Fa-f]+)', matches[0].read_text()))
    if args.resource_pulses:
        # Do not recursively admit the unused common/release callback families.
        for at in [0x5932f0,0x590be0,0x590c70]:
            entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_factory:
        for at in [0x591230,0x590be0,0x590c70,0x590d80,0x590ea0,0x5b42b0,0x5921d0,0x5df450,0x5932f0,0x593550,0x6b45c0,0x6b4a30]:
            entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_placement:
        for at in [0x591620,0x591860,0x5b4380,0x5927f0,0x5c62f0,0x5c1120,0x5c11b0,0x5c12a0]:
            entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_delayed:
        at=0x591400;entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_actions:
        for at in [0x592900,0x592960,0x592a10,0x592b00,0x592b90,0x5b1850,0x591be0]:
            entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_inventory:
        for at in [0x5f2120,0x5f2180,0x5f22c0,0x5f2330,0x5f27b0,0x5b43f0,0x5b1a90,0x592ca0,0x5b4a50]:
            entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.weapon_resources:
        for at in [0x1d3b00,0x1ad610,0x6b4ae0,0x5b4ce0]:
            folder=ROOT/('recomp/config/output' if at<0x370000 else 'recomp/config/output_ovl/o2')
            entries[at]=next(folder.glob(f'{"sub" if at<0x370000 else "o2"}_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.equipment_resources:
        for at in [0x5b18d0,0x5b4320]:
            entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.equipment_selection:
        for at in [0x666de0,0x5f1f70,0x5b4d50]:
            entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_companion_policy:
        for at in [0x654720,0x1919d0,0x370500]:
            bank='sub' if at<0x370000 else 'o0' if at<0x570000 else 'o2'
            folder=ROOT/('recomp/config/output' if bank=='sub' else 'recomp/config/output_ovl/'+bank)
            entries[at]=next(folder.glob(f'{bank}_{at:08X}_*')).relative_to(ROOT).as_posix()
    originals = list(entries.values())
    proof = []
    for at, name in entries.items():
        begin, end = [int(v, 16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)', (ROOT / name).read_text()).groups()]
        reader = main_read if at < 0x370000 else (lambda a, n: overlay['o0'][a - 0x370000:a - 0x370000 + n]) if at < 0x570000 else lambda a, n: overlay['o2'][a - 0x570000:a - 0x570000 + n]
        proof.append(compare_source('complete periodic visual factory, pools, update, resource sampling or camera helper', name, begin, end, reader))
    units = ['game/native/gameplay_effects/' + n + '.cpp' for n in ['periodic_visuals', 'geometry', 'tracks']]
    units += ['game/native/animation/' + n + '.cpp' for n in ['model', 'model_math', 'curves']]
    units += ['game/native/transform_math/transform_math.cpp', 'game/native/gameplay_actors/entity.cpp']
    units += ['game/native/gameplay_scenario/' + n + '.cpp' for n in ['periodic_effects', 'scene_controls', 'flags', 'fog']]
    units += ['game/native/gameplay_session/session.cpp', 'game/native/gameplay_tasks/tasks.cpp']
    units=list(dict.fromkeys(units+SURFACE_WORLD_UNITS))
    if args.resource_pulses:
        units += ['game/native/'+n for n in ['gameplay_world/resource_frames.cpp','gameplay_world/resource_models.cpp','gameplay_world/resource_programs.cpp','gameplay_scenario/scene_resources.cpp','animation/weapon_program.cpp']]
    if args.resource_static: units += ['game/native/gameplay_world/resource_static_assets.cpp']
    if args.resource_factory:
        units += ['game/native/'+n for n in ['gameplay_world/resource_frames.cpp','gameplay_world/resource_models.cpp','gameplay_world/resource_programs.cpp','gameplay_world/resource_factory.cpp','gameplay_scenario/scene_resources.cpp','gameplay_scenario/resource_templates.cpp','gameplay_scenario/resource_collisions.cpp','animation/weapon_program.cpp']]
    units=list(dict.fromkeys(units))
    if args.resource_inventory: units+=['game/native/gameplay_world/inventory.cpp']
    if args.weapon_resources:
        units+=['game/native/'+n for n in ['gameplay_weapon_resources/weapon_resources.cpp','gameplay_bank_loading/aliases.cpp','gameplay_bank_loading/loader.cpp','gameplay_audio/owner.cpp','gameplay_audio/import.cpp','gameplay_audio/routing.cpp','gameplay_audio/spatial.cpp','audio_banks/v2/session.cpp','audio_banks/v2/algorithms.cpp','resources/bounded_view.cpp','resources/virtual_file_view.cpp','resources/resource_session.cpp','resources_windows/pinned_file.cpp','resource_io/async_read_owner.cpp','afs_source_range/afs_source_range.cpp','tasks/serial_worker.cpp']]
        units=list(dict.fromkeys(units))
    if args.equipment_resources: units+=['game/native/gameplay_weapon_resources/equipment.cpp']
    if args.resource_companion_policy: units+=['game/native/gameplay_effects/resource_companion.cpp']
    files = list(units)
    frozen = {}
    for name in files:
        body = (ROOT / name).read_bytes()
        frozen[name] = body
        for include in re.findall(r'^\s*#include "([^"]+)"', body.decode(), re.M):
            local = ((ROOT / name).parent / include).resolve()
            target = local if local.is_file() else (ROOT / include).resolve()
            assert target.is_relative_to(ROOT) and target.is_file(), (name, include)
            relative = target.relative_to(ROOT).as_posix()
            if relative not in files:
                files.append(relative)
    fixture = 'tools/native_reconstruction/periodic_visuals_tests.cpp'
    helper = 'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    for name in originals + [fixture, helper, Path(__file__).relative_to(ROOT).as_posix()]:
        frozen[name] = (ROOT / name).read_bytes()
    if args.resource_pulses:
        name='tools/native_reconstruction/resource_pulses_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_static:
        name='tools/native_reconstruction/resource_static_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_factory:
        name='tools/native_reconstruction/resource_factory_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_placement:
        name='tools/native_reconstruction/resource_placement_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_delayed:
        name='tools/native_reconstruction/resource_delayed_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_actions:
        name='tools/native_reconstruction/resource_actions_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_inventory:
        name='tools/native_reconstruction/resource_inventory_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.weapon_resources:
        name='tools/native_reconstruction/weapon_resources_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.equipment_resources:
        name='tools/native_reconstruction/equipment_resources_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.equipment_selection:
        name='tools/native_reconstruction/equipment_selection_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_companion_policy:
        name='tools/native_reconstruction/resource_companion_policy_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    out.mkdir(parents=True)
    record = dict(schema=1, status='failed', game_run=False, installed_in_game=False, stage4_complete=False,
                  selected_visual_family='variant0 logical36/37/38, flags1A193, null parent, complete6535C0 callback',
                  physical_ps2_exceptional_parity=False, opcode131_installed=False,
                  source_sha256={n: hashlib.sha256(b).hexdigest() for n, b in frozen.items()},
                  compiler_sha256=sha(args.compiler), original_owned_bodies=proof,
                  corpus=dict(path=str(corpus / 'receipt.json'), sha256=sha(corpus / 'receipt.json')),
                  declared_ports=['107C68 bounded memset;18DC50/18DCA0/18DC90 private resource allocation/lookup/release',
                                  '1B10C0/1B1110 resource-cache bookkeeping',
                                  '1B3830 debug-overfree diagnostic remains unadmitted and throws if reached',
                                  '573740 task retirement is a declared independently qualified native scheduler seam'],
                  native_modernization=['Immutable native frame/resource leases replace work pointers in renderer handoff.',
                                        'Unused fourth stack rotation halfword is not an invented native angle.',
                                        'New native ownership clears all256 piece states; original reset clears only168 active bytes; fresh zeroed source-pool profile compared.'])
    if args.resource_factory:
        record['declared_ports'].append('107AB0 bounded byte copy for owned version3 template sections')
        record['factory_profile'] = dict(owned_static_banks=16, owned_template_banks=5,
            controlled_static_banks=1, controlled_template_banks=1,
            controlled_root_parts=6, controlled_callback_classes=[0,1,2,3,4,255],
            unsupported_classes=[4,255], source_calls_on_unsupported_profiles=False,
            unadmitted_companion_contents=['0x75','0x135','0x1d','0x1c','0x3200','0x72'])
    if args.resource_placement:
        record['declared_ports'].append('616F60 actual native Grid.floor consumer; independently qualified floor policy, not another comparison of its internals')
        record['placement_profile']=dict(shape_rows=20,orientation_rows=8,template_angle_columns=3,game_installed=False)
    if args.resource_inventory:
        record['declared_ports'].append('18DBB0 bounded29-byte source stack-to-character7 inventory copy; no source arena alias emulation')
    if args.weapon_resources:
        record['declared_ports']+=['10A830 bounded formatting of two exact owned weapon format strings','1CC8F0 copies owned WMD bytes into the bounded original cleared buffer; unused return not compared','107AB0 bounded16-byte source queue name copy','Native bank loader and PCM mixer internals are independently qualified; this checks their concrete composition']
    if args.resource_companion_policy:
        record['declared_ports']+=['654720 state-policy cohort captures652880 child rendering,652D60/651D00 retirement,654180 child fade,6B2680 gameplay spawn and1B8C70 resource audio as intents only; their actual integration is not qualified by these policy cases']
    try:
        for name, body in frozen.items():
            target = out / 'source' / name
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(body)
        (out / 'tests.cpp').write_bytes(frozen[fixture])
        reference = frozen[helper].decode().replace('pc{},branch_pc{},fcr31{}', 'pc{},branch_pc{},fcr31{},vu0_vpu_stat{}')
        reference = reference.replace('Register r[32];', 'Register r[32];std::uint64_t lo{},hi{};')
        if args.resource_pulses or args.resource_static: reference += '\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n'
        if args.resource_companion_policy: reference += '\n#define FPU_C_LT_S(a,b) ((a)<(b))\n'
        reference += '\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n#define SRA32(a,b) (static_cast<std::int32_t>(a) >> (static_cast<std::uint32_t>(b)&31))\n#define FPU_CVT_W_S(a) static_cast<std::int32_t>(a)\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n'
        (out / 'reference.hpp').write_text(reference)
        body = '\n'.join(frozen[n].decode() for n in originals)
        (out / 'original_visuals.cpp').write_text(body)
        actual = {Path(n).stem for n in originals}
        names = set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram', body))
        decl = ''.join('void ' + n + '(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for n in sorted(actual))
        decl += ''.join('inline void ' + n + '(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n' for n in sorted(names - actual))
        (out / 'functions.h').write_text('#pragma once\n' + decl)
        (out / 'original_dispatch.hpp').write_text(''.join('case ' + hex(at) + ':' + Path(n).stem + '(memory,context,runtime);return;\n' for at, n in sorted(entries.items())))
        for name in ['ps2_runtime.h', 'ps2_runtime_macros.h']:
            (out / name).write_text('#pragma once\n#include "reference.hpp"\n')
        for name in ['o0_functions.h', 'o2_functions.h', 'ps2_recompiled_functions.h']:
            (out / name).write_text('#pragma once\n#include "functions.h"\n')
        for name in ['ps2_recompiled_stubs.h', 'ps2_stubs.h', 'ps2_syscalls.h']:
            (out / name).write_text('#pragma once\n')
        raw = overlay['o2'][0x73e110 - 0x570000:0x73e110 - 0x570000 + 36]
        record['owned_transform_switch_table'] = dict(address='0x73e110', bytes=raw.hex())
        init='inline void owned_constants(std::uint8_t* memory){const std::uint8_t bytes[]{' + ','.join(str(v) for v in raw) + '};std::memcpy(memory+0x73e110,bytes,sizeof bytes);'
        if args.resource_pulses or args.resource_static:
            record['pulse_math_constants']={}
            for at,size in [(0x22fe20,32),(0x241c78,40),(0x38b290,4)]:
                value=main_read(at,size) if at<0x370000 else overlay['o0'][at-0x370000:at-0x370000+size]
                record['pulse_math_constants'][hex(at)]=value.hex();init+='{const std::uint8_t data[]{'+','.join(str(v) for v in value)+'};std::memcpy(memory+'+str(at)+',data,sizeof data);}'
        if args.resource_factory:
            raw_callbacks=overlay['o2'][0x709580-0x570000:0x709580-0x570000+16];assert struct.unpack('<4I',raw_callbacks)==(0x5932f0,0x6b45c0,0x593550,0x5932f0)
            record['resource_callback_table']=raw_callbacks.hex();init+='{const std::uint8_t data[]{'+','.join(str(v) for v in raw_callbacks)+'};std::memcpy(memory+0x709580,data,sizeof data);}'
        if args.resource_placement:
            for at,size in [(0x723340,800),(0x723660,224)]:
                raw=overlay['o2'][at-0x570000:at-0x570000+size];record.setdefault('placement_constants',{})[hex(at)]=raw.hex();init+='{const std::uint8_t data[]{'+','.join(str(v) for v in raw)+'};std::memcpy(memory+'+str(at)+',data,sizeof data);}'
        if args.weapon_resources:
            for at,value in [(0x256648,main_read(0x256648,11)),(0x740c90,overlay['o2'][0x740c90-0x570000:0x740c90-0x570000+34])]:
                assert value in [b'weapon%02d\0',b'data/rom/motion/weapon/wp%02d.wmd\0']
                record.setdefault('weapon_constants',{})[hex(at)]=value.hex();init+='{const std::uint8_t data[]{'+','.join(str(v)for v in value)+'};std::memcpy(memory+'+str(at)+',data,sizeof data);}'
        if args.resource_companion_policy:
            for at,size in [(0x7401b0,28),(0x7401d0,28)]:
                value=overlay['o2'][at-0x570000:at-0x570000+size];record.setdefault('resource_companion_switches',{})[hex(at)]=value.hex();init+='{const std::uint8_t data[]{'+','.join(str(v)for v in value)+'};std::memcpy(memory+'+str(at)+',data,sizeof data);}'
        (out/'owned_constants.hpp').write_text(init+'}\n')
        (out / 'owned_effect_geometry.bin').write_bytes((corpus / 'owned_effect_geometry.bin').read_bytes())
        if args.resource_static:
            inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2'
            members=json.loads(inventory.read_bytes());selected=[m for m in members if m.get('names') and m['names'][-1].upper().startswith('DEF') and m['names'][-1].upper().endswith('.NBD')]
            assert len(selected)==4
            obj=json.loads((ROOT/'build-native-sjuni/resource-static-asset-audit-v1.json').read_bytes());assert len(obj)==12
            selected += [entry['asset'] for entry in obj]
            record['static_assets']=selected;record['static_asset_audit_sha256']=sha(ROOT/'build-native-sjuni/resource-static-asset-audit-v1.json')
            with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as iso,(out/'owned_static_nbd.bin').open('wb') as data:
                data.write(len(selected).to_bytes(4,'little'))
                for member in selected:
                    iso.seek(member['iso_offset']);payload=iso.read(member['bytes']);assert hashlib.sha256(payload).hexdigest()==member['sha256'];data.write(len(payload).to_bytes(4,'little')+payload)
        if args.resource_factory:
            inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2'
            selected=[m for m in json.loads(inventory.read_bytes()) if any(n.lower().startswith('item') and n.lower().endswith('.dat') for n in m.get('names',[]))];assert len(selected)==5;record['template_assets']=selected
            with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as iso,(out/'owned_templates.bin').open('wb') as data:
                data.write(struct.pack('<I',len(selected)))
                for member in selected:
                    iso.seek(member['iso_offset']);payload=iso.read(member['bytes']);assert hashlib.sha256(payload).hexdigest()==member['sha256'];offset,size=struct.unpack_from('<II',payload);assert offset+size<=len(payload);section=payload[offset:offset+size];data.write(struct.pack('<I',len(section))+section)
        if args.weapon_resources:
            selectors=[0,1,2,4,5,7,8,9,12,18,22,23,24,25,26,51]
            selected=[next(m for m in json.loads(inventory.read_bytes()) if m['member']==f'NETBIO00.DAT/0/{1260+i}')for i in range(16)]
            record['weapon_assets']=selected
            values=[]
            with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as iso:
                for selector,member in zip(selectors,selected):
                    iso.seek(member['iso_offset']);payload=iso.read(member['bytes']);assert hashlib.sha256(payload).hexdigest()==member['sha256'];values.append('{'+str(selector)+',{'+','.join(str(v)for v in payload)+'}}')
            (out/'owned_weapons.hpp').write_text('struct OwnedWeapon {int selector;std::vector<std::uint8_t> bytes;};\ninline const std::array<OwnedWeapon,16> owned_weapons{{'+','.join(values)+'}};\n')
            digest='69ae2c48e6f01e2605659feabb54eb9b82c63a809bdc8a78ad2d160b3c59a4a1'
            (out/'owned_iso.hpp').write_text('constexpr std::uint64_t owned_iso_bytes=4698767360ull;\nconstexpr reo::native::resources::win32::Digest owned_iso_sha{'+','.join(str(v)for v in bytes.fromhex(digest))+'};\n')
        env = dict(os.environ)
        env['PATH'] = str(args.compiler.resolve().parent) + os.pathsep + env.get('PATH', '')
        binary = out / 'checks.exe'
        command = [str(args.compiler), '-std=c++20', '-O2', '-msse4.1', '-pthread', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
                   '-Wno-unused-label', '-Wno-unused-parameter', '-fno-fast-math', '-ffp-contract=off', '-I' + str(out), '-I' + str(out / 'source')]
        command += [str(out / 'source' / name) for name in units] + [str(out / 'tests.cpp'), '-o', str(binary)]
        if args.resource_pulses: command.insert(1,'-DREO_RESOURCE_PULSES=1')
        if args.resource_static: command.insert(1,'-DREO_RESOURCE_STATIC=1')
        if args.resource_factory: command.insert(1,'-DREO_RESOURCE_FACTORY=1')
        if args.resource_placement: command.insert(1,'-DREO_RESOURCE_PLACEMENT=1')
        if args.resource_delayed: command.insert(1,'-DREO_RESOURCE_DELAYED=1')
        if args.resource_actions: command.insert(1,'-DREO_RESOURCE_ACTIONS=1')
        if args.resource_inventory: command.insert(1,'-DREO_RESOURCE_INVENTORY=1')
        if args.weapon_resources: command.insert(1,'-DREO_WEAPON_RESOURCES=1');command.insert(-2,'-lbcrypt')
        if args.equipment_resources: command.insert(1,'-DREO_EQUIPMENT_RESOURCES=1')
        if args.equipment_selection: command.insert(1,'-DREO_EQUIPMENT_SELECTION=1')
        if args.resource_companion_policy: command.insert(1,'-DREO_RESOURCE_COMPANION_POLICY=1')
        record['command'] = command
        for label, cmd in [('compile', command), ('run', [str(binary), str(out / 'owned_effect_geometry.bin')]+([str(out/'owned_static_nbd.bin')] if args.resource_static else [])+([str(out/'owned_templates.bin')] if args.resource_factory else [])+([str(ROOT/'iso/Resident Evil - Outbreak (v2.00).iso')] if args.weapon_resources else []))]:
            result = subprocess.run(cmd, env=env, capture_output=True, timeout=240 if args.weapon_resources else 180)
            (out / (label + '.stdout.txt')).write_bytes(result.stdout)
            (out / (label + '.stderr.txt')).write_bytes(result.stderr)
            assert result.returncode == 0, label + ' failed; see retained logs'
            if label == 'run':
                record['observed'] = json.loads(result.stdout)
        record['source_unchanged'] = all((ROOT / n).read_bytes() == b for n, b in frozen.items())
        assert record['source_unchanged']
        record.update(status='passed', binary_sha256=sha(binary))
    finally:
        record['output_sha256'] = {p.relative_to(out).as_posix(): sha(p) for p in out.rglob('*') if p.is_file() and p.name != 'receipt.json'}
        (out / 'receipt.json').write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps(record['observed']))


if __name__ == '__main__':
    main()
