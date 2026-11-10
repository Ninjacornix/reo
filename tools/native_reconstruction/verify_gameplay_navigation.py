"""Compare bounded native SGL ownership/queries with hash-pinned originals.

Headless tests only. Never opens the game, devices, windows or live memory.
"""
import argparse
import hashlib
import json
import os
import re
import subprocess
import struct
from pathlib import Path
from audit_retail_effect_descriptors import compare_source, elf_reader
from verify_gameplay_collision import COMPILERS

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
PINS = {
    'build-function-index/owned-overlays/o2.bin': '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226',
    'build-function-index/owned-overlays/o0.bin': 'bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2',
    'build-function-index/owned-overlays/o9.bin': '604126d6edca1b1333948d79d1d2c8d2f2e22f4a233efbdfb769c106dafe7343',
    'game_data/SLUS_207.65': '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46',
    'build-native-sjuni/audio-asset-inventory/file1-v1/members.json': '276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2',
}
ASSETS = {
    'r001.sgl': '73df31bfd576bc6095fe44b6c51f1eb1e6c955c73b25d2ff9d5e4312cb475faf',
    'r002.sgl': '0347121969ec0a76d4baf6d0e5256e874bf5f93eaa95fe6f147187dd4877a64a',
    'r028.sgl': 'e79050973d67a082954357452782bd571e1fd71c87802b8ec4799f8766afbe36',
    'r035.sgl': '64776cadc528f509bde1d864bb1c1684072a8fbdeed3e49940eabbf02e94a468',
    'r041.sgl': '55e3a5e8d1ef8a8a04599736315322323a5facbc995298742c32fedfbb01e17d',
}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler', choices=COMPILERS, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    out = args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
    for name, digest in PINS.items():
        assert sha(ROOT/name) == digest, name
    overlay = (ROOT/'build-function-index/owned-overlays/o9.bin').read_bytes()
    elf = elf_reader((ROOT/'game_data/SLUS_207.65').read_bytes())
    sources, entries, audits = [], {}, []
    selected = {0x815e30, 0x815e70, 0x817170, 0x8171d0, 0x8171e0, 0x816890, 0x816ef0, 0x817100, 0x8171c0, 0x815bc0, 0x813bd0, 0x81a340, 0x8173d0, 0x817470, 0x817820, 0x8179f0, 0x817db0, 0x818010, 0x818390, 0x8185c0, 0x818940, 0x818b70, 0x818e30, 0x819010, 0x819220, 0x819360, 0x819370, 0x8193a0, 0x819410, 0x8194d0, 0x8194f0, 0x8196e0, 0x81a0e0}
    for path in sorted((ROOT/'recomp/config/output_ovl/o9').glob('o9_*.cpp')):
        address = int(path.stem.split('_')[-1], 16)
        if 0x816000 <= address < 0x816460 or address in selected:
            text = path.read_text()
            end = int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)', text)[1], 16)
            relative = path.relative_to(ROOT).as_posix()
            audits.append(compare_source('Complete original navigation input/binding, query, predicate or local route body', relative, address, end, lambda a, n: overlay[a-0x810000:a-0x810000+n]))
            sources.append(relative)
            entries[address] = relative
    name = 'recomp/config/output/sub_00191D10_0x191d10.cpp'
    audits.append(compare_source('Complete distance body; finite audited SDK scalar/SIMD profile', name, 0x191d10, 0x191d80, elf))
    entries[0x191d10] = name
    sources.append(name)
    name = 'recomp/config/output/sub_00107AB0_0x107ab0.cpp'
    audits.append(compare_source('Complete original visit-snapshot copy body', name, 0x107ab0, 0x107b60, elf))
    entries[0x107ab0] = name
    sources.append(name)
    for address in [0x192180,0x1226f0,0x120908,0x122140,0x1224a8,0x191ef0]:
        path = next((ROOT/'recomp/config/output').glob(f'sub_{address:08X}_*'))
        name = path.relative_to(ROOT).as_posix()
        end = int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)', path.read_text())[1], 16)
        audits.append(compare_source('Complete original destination heading/math body', name, address, end, elf))
        entries[address] = name
        sources.append(name)
    name = 'recomp/config/output_ovl/o0/o0_00370140_0x370140.cpp'
    raw_o0 = (ROOT/'build-function-index/owned-overlays/o0.bin').read_bytes()
    audits.append(compare_source('Complete370140 route heading; zero Z bias differs from contact heading', name, 0x370140, 0x370198, lambda a,n: raw_o0[a-0x370000:a-0x370000+n]))
    entries[0x370140] = name
    sources.append(name)
    for bank, addresses in [('sub',[0x191cc0,0x191d80,0x191df0,0x191ed0,0x192100,0x1226d8,0x1204e0,0x120e98]),('o0',[0x3705e0,0x370fe0]),('o2',[0x579980,0x579730,0x579a50,0x579300,0x617430,0x6175c0,0x616cc0,0x6161e0,0x619a50])]:
        raw = None if bank == 'sub' else (ROOT/f'build-function-index/owned-overlays/{bank}.bin').read_bytes()
        read = elf if bank == 'sub' else lambda a,n,raw=raw,base=(0x370000 if bank=='o0' else 0x570000): raw[a-base:a-base+n]
        folder = ROOT/('recomp/config/output' if bank=='sub' else 'recomp/config/output_ovl/'+bank)
        for address in addresses:
            path = next(folder.glob(f'{bank}_{address:08X}_*'))
            name = path.relative_to(ROOT).as_posix()
            end = int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)', path.read_text())[1], 16)
            audits.append(compare_source('Complete original navigation visibility, geometry and finite SDK math body', name, address,end,read))
            entries[address] = name
            sources.append(name)
    caller = 'recomp/config/output_ovl/o9/o9_00812540_0x812540.cpp'
    audits.append(compare_source('Static812540 current-node producer prefix only; rest of caller not executed', caller,0x812594,0x8125a8,lambda a,n: overlay[a-0x810000:a-0x810000+n]))
    sources.append(caller)
    assert selected.issubset(entries)
    unit = 'game/native/gameplay_navigation/navigation.cpp'
    fixture = 'game/native/gameplay_navigation/navigation_tests.cpp'
    helper = 'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    files = [unit, fixture, 'game/native/gameplay_navigation/navigation.hpp', 'game/native/gameplay_navigation/bank.cpp', 'game/native/gameplay_navigation/bank.hpp', 'game/native/gameplay_navigation/conditions.cpp', 'game/native/gameplay_navigation/conditions.hpp', 'game/native/gameplay_navigation/edges.cpp', 'game/native/gameplay_navigation/edges.hpp', 'game/native/gameplay_navigation/routes.cpp', 'game/native/gameplay_navigation/routes.hpp', 'game/native/gameplay_navigation/ranked_route_tests.inc', 'game/native/gameplay_navigation/cost_routes.cpp', 'game/native/gameplay_navigation/cost_routes.hpp', 'game/native/gameplay_navigation/cost_route_tests.inc', 'game/native/gameplay_navigation/cost_graph.cpp', 'game/native/gameplay_navigation/cost_graph.hpp', 'game/native/gameplay_navigation/cost_graph_tests.inc', 'game/native/gameplay_navigation/local_routes.cpp', 'game/native/gameplay_navigation/local_routes.hpp', 'game/native/gameplay_navigation/local_route_tests.inc', 'game/native/gameplay_navigation/link_collection.cpp', 'game/native/gameplay_navigation/link_collection.hpp', 'game/native/gameplay_navigation/link_collection_tests.inc', 'game/native/gameplay_navigation/cross_room.cpp', 'game/native/gameplay_navigation/cross_room.hpp', 'game/native/gameplay_navigation/cross_room_tests.inc', 'game/native/gameplay_navigation/actor_routes.cpp', 'game/native/gameplay_navigation/actor_routes.hpp', 'game/native/gameplay_navigation/actor_route_tests.inc', 'game/native/gameplay_navigation/destination.cpp', 'game/native/gameplay_navigation/destination.hpp', 'game/native/gameplay_navigation/destination_tests.inc', 'game/native/gameplay_navigation/visibility.cpp', 'game/native/gameplay_navigation/visibility.hpp', 'game/native/gameplay_navigation/visibility_tests.inc', 'game/native/gameplay_collision/collision.cpp', 'game/native/gameplay_collision/collision.hpp', 'game/native/gameplay_collision/response.cpp', 'game/native/gameplay_collision/response.hpp', 'game/native/gameplay_collision/trace.cpp', 'game/native/gameplay_collision/trace.hpp', 'game/native/transform_math/heading.cpp', 'game/native/transform_math/heading.hpp', 'game/native/transform_math/heading_profile.inc', 'game/native/transform_math/transform_math.cpp', 'game/native/transform_math/transform_math.hpp', 'game/native/gameplay_session/room_variants.hpp', 'game/native/gameplay_navigation/CMakeLists.txt', 'game/native/CMakeLists.txt', helper, Path(__file__).relative_to(ROOT).as_posix(), *sources]
    frozen = {name: (ROOT/name).read_bytes() for name in files}
    out.mkdir(parents=True)
    for name, data in frozen.items():
        path = out/'source'/name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(data)
    reference = frozen[helper].replace(b'Register r[32];', b'Register r[32];std::uint64_t hi{},lo{};')+b'\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n#define SRA32(a,b) (std::int32_t(a) >> (std::uint32_t(b)&31))\n'
    assert reference.count(b'std::memcpy(p+at,&value,sizeof value);') == 1
    reference = reference.replace(b'#include <stdexcept>', b'#include <stdexcept>\n#include <cstddef>\nvoid navigation_reference_write(std::uint32_t,std::size_t);')
    reference = reference.replace(b'std::memcpy(p+at,&value,sizeof value);', b'navigation_reference_write(at,sizeof(T));std::memcpy(p+at,&value,sizeof value);')
    reference += b'\n#define FPU_C_EQ_S(a,b) ((a)==(b))\ninline std::int32_t navigation_heading_word(float value,std::uint32_t pc){const bool heading=pc==0x191f50u||pc==0x191f68u,sample=pc==0x57986cu||pc==0x579888u;if((!heading&&!sample)||!std::isfinite(value)||value<0.f||!(value<2147483648.f)||(heading&&value>65536.f))throw std::runtime_error("Unadmitted navigation finite conversion");return std::int32_t(value); }\n#define FPU_CVT_W_S(x) navigation_heading_word(x,ctx->pc)\n'
    reference += b'\nvoid navigation_reference_cost_entry();\n'
    (out/'reference.hpp').write_bytes(reference)
    body = '\n'.join(frozen[name].decode() for name in entries.values())
    assert body.count('label_818e30:') == 1
    body = body.replace('label_818e30:', 'label_818e30:\n    navigation_reference_cost_entry();')
    (out/'original.cpp').write_text(body)
    actual = {Path(name).stem for name in entries.values()}
    calls = set(re.findall(r'\b((?:sub|o[0-9]+)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram', body))
    (out/'functions.h').write_text('#pragma once\n'+''.join(f'void {name}(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for name in sorted(actual))+''.join(f'inline void {name}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}\n' for name in sorted(calls-actual)))
    (out/'dispatch.inc').write_text(''.join(f'case {address}:{Path(name).stem}(memory,context,runtime);return;\n' for address, name in entries.items()))
    for name in ['ps2_runtime.h', 'ps2_runtime_macros.h']:
        (out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    for name in ['o0_functions.h', 'o2_functions.h', 'o9_functions.h', 'ps2_recompiled_functions.h']:
        (out/name).write_text('#pragma once\n#include "functions.h"\n')
    for name in ['ps2_recompiled_stubs.h', 'ps2_stubs.h', 'ps2_syscalls.h']:
        (out/name).write_text('#pragma once\n')
    # Re-read exact owned ISO extents using the pinned inventory. The recorded
    # full ISO digest is historical; only selected members are rehashed here.
    members = json.loads((ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json').read_bytes())
    assert isinstance(members, list)
    asset_evidence = []
    with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as iso:
        for basename, digest in ASSETS.items():
            rows = [row for row in members if basename in row.get('names', [])]
            assert len(rows) == 1
            row = rows[0]
            assert row['sha256'] == digest
            iso.seek(row['iso_offset'])
            data = iso.read(row['bytes'])
            assert hashlib.sha256(data).hexdigest() == digest
            (out/basename).write_bytes(data)
            asset_evidence.append(row)
    words = [int(x,16) for x in re.findall(r'0x([0-9a-fA-F]+)', frozen['game/native/transform_math/heading_profile.inc'].decode().split('atan_words',1)[1])]
    assert struct.pack('<19I', *words) == elf(0x2392b8,76)
    constants = [(0x2392b8,elf(0x2392b8,76)),(0x22fe20,elf(0x22fe20,32)),(0x241c78,elf(0x241c78,40)),(0x38b288,raw_o0[0x38b288-0x370000:0x38b288-0x370000+4])]
    assert struct.unpack('<I', constants[-1][1])[0] == 0x38d1b717
    main_image = (ROOT/'game_data/SLUS_207.65').read_bytes()
    assert main_image[:6] == b'\x7fELF\x01\x01'
    phoff = struct.unpack_from('<I', main_image,28)[0]
    stride,count = struct.unpack_from('<HH', main_image,42)
    for index in range(count):
        kind,offset,address,_,size,_,_,_ = struct.unpack_from('<8I',main_image,phoff+stride*index)
        if kind == 1 and size:
            assert offset+size<=len(main_image) and address+size<=0x2000000
            constants.append((address,main_image[offset:offset+size]))
    raw_o2 = (ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
    constants.append((0x570000,raw_o2))
    with (out/'heading_constants.bin').open('wb') as data:
        for address, block in constants:
            data.write(struct.pack('<II', address,len(block))+block)
    (out/'o9.bin').write_bytes(overlay)
    compiler = COMPILERS[args.compiler]
    env = dict(os.environ)
    env['PATH'] = str(compiler.parent)+os.pathsep+env.get('PATH', '')
    exe = out/'navigation.exe'
    command = [str(compiler), '-std=c++20', '-O2', '-msse4.1', '-DREO_NAVIGATION_ORIGINAL=1', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-Wno-unused-label', '-Wno-unused-parameter', '-fno-fast-math', '-ffp-contract=off', '-I'+str(out), '-I'+str(out/'source'), str(out/'source'/unit), str(out/'source/game/native/gameplay_navigation/bank.cpp'), str(out/'source/game/native/gameplay_navigation/conditions.cpp'), str(out/'source/game/native/gameplay_navigation/edges.cpp'), str(out/'source/game/native/gameplay_navigation/routes.cpp'), str(out/'source/game/native/gameplay_navigation/cost_routes.cpp'), str(out/'source/game/native/gameplay_navigation/cost_graph.cpp'), str(out/'source/game/native/gameplay_navigation/local_routes.cpp'), str(out/'source/game/native/gameplay_navigation/link_collection.cpp'), str(out/'source/game/native/gameplay_navigation/cross_room.cpp'), str(out/'source/game/native/gameplay_navigation/actor_routes.cpp'), str(out/'source/game/native/gameplay_navigation/destination.cpp'), str(out/'source/game/native/gameplay_navigation/visibility.cpp'), str(out/'source/game/native/gameplay_collision/collision.cpp'), str(out/'source/game/native/gameplay_collision/response.cpp'), str(out/'source/game/native/gameplay_collision/trace.cpp'), str(out/'source/game/native/transform_math/heading.cpp'), str(out/'source/game/native/transform_math/transform_math.cpp'), str(out/'source'/fixture), str(out/'original.cpp'), '-o', str(exe)]
    receipt = dict(schema=1,status='failed',game_launched=False,installed_in_game=False,stage4_complete=False,compiler_sha256=sha(compiler),source_sha256={name: hashlib.sha256(data).hexdigest() for name, data in frozen.items()},original_word_audits=audits,pinned_inputs=PINS,assets=asset_evidence,commands=[],declared_ports=['107C68 bounded zero-fill in original-only test surroundings; real runtime allocator not installed'],limitations=['Native immutable input/query owner only; canonical mutable room-variant, occupancy, visits, dynamic conditions and actual AI/scene consumers remain open.', 'Nearest comparison covers flags0 with finite distance; flags1 segment collision is not admitted. Empty or overflowed distances return unavailable.', 'Malformed reachable neighbor/condition references return unavailable; no adjacent-section emulation or silent asset repair.', 'Original route ordering is preserved; no measured performance fix or game installation is claimed.'])
    receipt['original_cost_observation_limit'] = dict(recursive_entries_per_extended_query=16384,total_extended_recursive_entries=2000000,limited_rows=['function_kind_0_cost_1_local_2_candidate','room','current_variant','source','destination','actor_status','room_flags','actor_slot','attempted_recursive_entries','limit_reason_0_query_1_total'],original_body_instructions_unchanged=True,guard_only_in_test_dispatcher=False,guard_at_test_recursive_label=True,guard_self_test_required=True)
    receipt['limitations'] = [
        'Native immutable input/query and mutable Bank component; World/session/VM composition is qualified separately by the current full VM runner.',
        'Controlled explicit variants reproduce mode2 room selection/clearing. Actor facts and flag values exercise complete dynamic condition and admitted link selection; actual UpdateOwner composition is qualified separately. Mode0/1 callbacks, live SGL loader and route/AI/scene execution remain open.',
        'Same asset rebinding preserves mutable visits, clears occupancy and rereads variants. A different asset starts from its authored visit bytes; unknown required variants refuse binding before effects.',
        'Nearest flags0 finite-distance and bounded reverse-action profiles only. Empty/nonfinite/overflowed nearest queries and reachable malformed references return unavailable.',
        'No game launched or installed; no measured performance fix or Stage4 completion is claimed.',
        'Complete819010 edge admission uses four source slots, status gates, packed byte predicates and node-condition routing. Four mutable edge flags are owned once per loaded immutable graph and survive same-asset rebinds; higher-level flag writers and scene/AI route execution remain open.',
        'Ranked policies and bounded-cost policy execute complete original bodies. Cost search has an explicit deterministic work admission budget; only completed native searches execute original comparisons. Exhausted/malformed contexts remain unavailable without committing an approximate route.',
        'Complete817DB0 local dispatch preserves pre-routing target-link node denial, policy selection, current-session variant reads, post-routing admitted link lookup and known output prefixes. Cross-room dispatch, actual actor/AI execution and game installation remain open.',
        'Extended source comparisons of previously over-budget retail queries stop before original recursive entry16385 or after2000000 total extended entries in one cohort. A test-only observation guard at the recursive entry label throws without changing source instructions or pretending a completed original result. Limited query identities remain structured evidence; native completed graph results and original-completed comparisons are counted separately.',
        'The cost API selects a fixed-array graph solver for fully known queries when its edge budget admits16*N+28 inspections, with an independent2*N*N vertex-scan bound. Tiny budgets retain bounded enumeration; unknown whole-graph admission falls back within the remaining budget. Exhaustive four-node topologies and seeded self/duplicate/zero-cycle graphs compare complete818B70/818E30 bodies. Actual game installation remains open.',
        'Complete815BC0/813BD0 actor node selection compares all policy directions and all256 motion classes. The actual Owner publishes the selector result in the statically audited812540 entry prefix; the remainder of812540 and real scene loading are not executed or claimed migrated.',
        'Complete visibility81A340, flags1 nearest8171E0/8171C0, collision579980 and its full sampler/filter/triangle/acos chain execute. No clear-path geometry port or host-acos replacement is used. Native fully sampled finite profiles refuse incomplete geometry; actual scene loading and current-node AI callers remain open.',
        'Complete816890 destination setup and the full370140/atan/quadrant/turn/distance chain compare finite profiles. The route helper biases Z when zero; the separately qualified contact helper biases X and is not substituted. Initial/current-node production, remaining AI and game installation remain open.',
        'Complete8173D0/816EF0 mutate one native actor route component: last-current-node, actual Bank occupancy, first direct versus last reverse action, and final-position substitution. Real initial/current-node producers, target selection, remaining AI and installation stay open.',
        'Complete817470/817820 cross-room bodies and107AB0 copy execute in the original-only oracle. Strict unknown-cost contexts are refused; an explicit separate profile zeroes cost at each collector entry in both native and reference. This declared deterministic correction is not claimed as unmodified-original equivalence or installed game validation.',
        'Complete8179F0 link collection compares only bounded known-cost/valid-record profiles. Initial uninitialized source cost is not invented: native unknown-cost results stay unavailable. A test-only write observer verifies lower-query cost_written metadata without changing original memory effects. Metadata omission, reversed endpoints and original pairwise tie behavior are retained.',
    ]
    receipt['declared_ports'].append('107C68 exact128-byte FF fill of original-only route scratch893780; native search uses typed local state')
    try:
        for label, cmd in [('compile', command), ('test', [str(exe), str(out/'o9.bin'), str(out/'heading_constants.bin'), *(str(out/name) for name in ASSETS)])]:
            result = subprocess.run(cmd, capture_output=True, env=env, timeout=240)
            (out/(label+'.stdout.txt')).write_bytes(result.stdout)
            (out/(label+'.stderr.txt')).write_bytes(result.stderr)
            receipt['commands'].append(dict(label=label,command=cmd,exit=result.returncode))
            if result.returncode:
                raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-4000:])
            if label == 'test':
                receipt['observed'] = json.loads(result.stdout)
        receipt['source_unchanged'] = all((ROOT/name).read_bytes() == data for name, data in frozen.items())
        assert receipt['source_unchanged']
        receipt['status'] = 'passed'
    finally:
        receipt['output_sha256'] = {path.relative_to(out).as_posix(): sha(path) for path in out.rglob('*') if path.is_file()}
        (out/'receipt.json').write_text(json.dumps(receipt, indent=2)+'\n')
    print(json.dumps(receipt['observed']))


if __name__ == '__main__':
    main()
