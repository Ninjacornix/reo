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
from comparison_objects import compile_objects
from comparison_oracle import compile_oracle
from gameplay_update_sources import UPDATE_UNITS
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
    p.add_argument('--resource-content', action='store_true')
    p.add_argument('--resource-pairs', action='store_true')
    p.add_argument('--resource-recipes', action='store_true')
    p.add_argument('--owned-recipes', action='store_true')
    p.add_argument('--resource-consumption', action='store_true')
    p.add_argument('--resource-wrappers', action='store_true')
    p.add_argument('--resource-health', action='store_true')
    p.add_argument('--resource-deployment', action='store_true')
    p.add_argument('--resource-effects', action='store_true')
    p.add_argument('--resource-debris', action='store_true')
    p.add_argument('--resource-depletion', action='store_true')
    p.add_argument('--stock-wmd-absence', action='store_true')
    p.add_argument('--resource-use', action='store_true')
    p.add_argument('--resource-ownership', action='store_true')
    p.add_argument('--actor-resource-operations', action='store_true')
    p.add_argument('--resource-auxiliary', action='store_true')
    p.add_argument('--actor-terminal', action='store_true')
    p.add_argument('--actor-progression', action='store_true')
    p.add_argument('--actor-recovery', action='store_true')
    p.add_argument('--focus-recovery', action='store_true')
    p.add_argument('--actor-reception', action='store_true')
    p.add_argument('--focus-reception', action='store_true')
    p.add_argument('--actor-zero-health', action='store_true')
    p.add_argument('--focus-zero-health', action='store_true')
    p.add_argument('--weapon-resources', action='store_true')
    p.add_argument('--equipment-resources', action='store_true')
    p.add_argument('--equipment-selection', action='store_true')
    p.add_argument('--resource-companion-policy', action='store_true')
    p.add_argument('--resource-companions', action='store_true')
    p.add_argument('--focus-companions', action='store_true')
    args = p.parse_args()
    assert not args.resource_factory or args.resource_static
    assert not args.resource_placement or args.resource_factory
    assert not args.resource_delayed or args.resource_placement
    assert not args.resource_actions or args.resource_delayed
    assert not args.resource_inventory or args.resource_actions
    assert not args.resource_content or args.resource_inventory
    assert not args.resource_pairs or args.resource_content
    assert not args.resource_recipes or args.resource_pairs
    assert not args.owned_recipes or args.resource_recipes
    assert not args.resource_consumption or args.owned_recipes
    assert not args.resource_wrappers or args.resource_consumption
    assert not args.resource_health or args.resource_wrappers
    assert not args.resource_deployment or (args.resource_health and args.resource_companions)
    assert not args.resource_effects or args.resource_deployment
    assert not args.resource_debris or args.resource_effects
    assert not args.resource_depletion or args.resource_debris
    assert not args.stock_wmd_absence or args.resource_depletion
    assert not args.resource_use or args.stock_wmd_absence
    assert not args.resource_ownership or args.resource_use
    assert not args.actor_resource_operations or args.resource_ownership
    assert not args.resource_auxiliary or args.actor_resource_operations
    assert not args.actor_terminal or args.resource_auxiliary
    assert not args.actor_progression or args.actor_terminal
    assert not args.actor_recovery or args.actor_progression
    assert not args.focus_recovery or args.actor_recovery
    assert not args.actor_reception or (args.actor_zero_health and args.equipment_selection)
    assert not args.focus_reception or (args.actor_reception and not args.focus_recovery and not args.focus_zero_health and not args.focus_companions)
    assert not args.actor_zero_health or args.actor_recovery
    assert not args.focus_zero_health or (args.actor_zero_health and not args.focus_recovery)
    assert not args.weapon_resources or args.resource_inventory
    assert not args.equipment_resources or args.weapon_resources
    assert not args.equipment_selection or args.equipment_resources
    assert not args.resource_companion_policy or args.resource_placement
    assert not args.resource_companions or (args.resource_companion_policy and args.weapon_resources)
    assert not args.focus_companions or args.resource_companions
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
    if args.resource_debris: pending += [0x1900e0]
    ports = [0x107c68, 0x18dc50, 0x18dca0, 0x18dc90, 0x1b10c0, 0x1b1110, 0x1b3830, 0x573740]
    if args.resource_companions:
        pending += [0x654180,0x652880,0x654720,0x5df450]
        ports += [0x6b2680,0x1b8c70]
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
        for at in [0x591400,0x5919f0]:
            entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_actions:
        for at in [0x592900,0x592960,0x592a10,0x592b00,0x592b90,0x5b1850,0x591be0]:
            entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_inventory:
        for at in [0x5f2120,0x5f2180,0x5f22c0,0x5f2330,0x5f27b0,0x5b43f0,0x5b1a90,0x592ca0,0x5b4a50]:
            entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_content:
        for at in [0x591510,0x5b4c90,0x5b4bf0,0x5b4e60,0x5b3c70]:
            entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_pairs:
        for at in [0x5b3690,0x5b3820,0x5b3920,0x5b39a0,0x5b3dd0,0x5b3e40,0x5b4020,0x5b4320,0x5b1af0]:
            entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_recipes:
        for at in [0x5b2d00,0x5b2dc0,0x5b2e70,0x5b2ec0,0x5b2f00,0x5b3080,0x5b30f0,0x5b31b0,0x5b3200,0x5b3380,0x5b3400,0x5b3490,0x5b3590,0x5b3640,0x5b1b50]:
            entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.owned_recipes:
        for at in [0x5b28f0,0x5b6740,0x1b0340,0x1b02d0,0x37bfb0,0x37c060,0x37c170,0x37c200,0x37c2c0,0x37c3b0]:
            bank='sub'if at<0x370000 else'o0'if at<0x570000 else'o2';folder=ROOT/('recomp/config/output'if bank=='sub'else'recomp/config/output_ovl/'+bank);entries[at]=next(folder.glob(f'{bank}_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_consumption:
        for at in [0x5b4550,0x5b46a0,0x5b4900,0x5b4990,0x37b990,0x37bbc0,0x37c470]:
            bank='o0'if at<0x570000 else'o2';entries[at]=next((ROOT/'recomp/config/output_ovl'/bank).glob(f'{bank}_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_wrappers:
        for at in [0x5b4460,0x5b45e0,0x5b47f0,0x5b58c0,0x1afdd0,0x1b0310]:
            bank='sub'if at<0x370000 else'o2';folder=ROOT/('recomp/config/output'if bank=='sub'else'recomp/config/output_ovl/o2');entries[at]=next(folder.glob(f'{bank}_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_health:
        for at in [0x5b2230,0x5b6610,0x6605b0,0x67e230,0x1b0240,0x5f4fd0]:
            bank='sub'if at<0x370000 else'o2';folder=ROOT/('recomp/config/output'if bank=='sub'else'recomp/config/output_ovl/o2');entries[at]=next(folder.glob(f'{bank}_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_deployment:
        for at in [0x5b5940,0x5b5af0,0x5b5cb0,0x5b26d0,0x5b2770,0x5b2870,0x5b2880,0x5b2890,0x5b28e0]:entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_effects:
        for at in [0x5b2080,0x5b2760]:entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_debris:
        for at in [0x5df2a0,0x5df340,0x58fbc0,0x58fd10,0x58fe50]:entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_depletion:
        for at in [0x5b4ad0,0x5b2590]:entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
        for at in [0x1b8c70,0x1b8b20]:entries[at]=next((ROOT/'recomp/config/output').glob(f'sub_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_use:
        at=0x5b1f30;entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_ownership:
        for at in [0x593060,0x5f2210,0x5b15d0,0x5b1610,0x5b1670,0x5b16d0,0x5b1710,0x5b1760,0x5b1bf0,0x5b1de0]:entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.actor_resource_operations:
        for at in [0x5f4fe0,0x5f5c50,0x5f6a80]:entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.resource_auxiliary:
        for at in [0x5b5f10,0x5b6180,0x5b6300,0x5f6800]:entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.actor_terminal:
        for at in [0x6687a0,0x667370]:entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.actor_progression:
        for at in [0x667420,0x667e90,0x668050,0x1b0340,0x65fc90]:
            bank='sub'if at<0x370000 else'o2';folder=ROOT/('recomp/config/output'if bank=='sub'else'recomp/config/output_ovl/o2');entries[at]=next(folder.glob(f'{bank}_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.actor_recovery:
        for at in [0x65fcb0,0x65fab0,0x5d4cf0,0x5d4bf0,0x5d50e0,0x5d50f0,0x5d4570,0x5d5950,0x5d4810,0x5d4470,0x5d46c0,0x663350,0x58c7b0,0x664d00,0x667f90,0x668c80]:
            entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.actor_reception:
        for at in [0x67ed50,0x682c60,0x682d10,0x682e30,0x666640]:entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    if args.actor_zero_health:
        for at in [0x65fba0,0x6607d0]:entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
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
    if args.resource_companions:
        at=0x654180;entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
    originals = list(entries.values())
    proof = []
    for at, name in entries.items():
        begin, end = [int(v, 16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)', (ROOT / name).read_text()).groups()]
        reader = main_read if at < 0x370000 else (lambda a, n: overlay['o0'][a - 0x370000:a - 0x370000 + n]) if at < 0x570000 else lambda a, n: overlay['o2'][a - 0x570000:a - 0x570000 + n]
        proof.append(compare_source('complete periodic visual factory, pools, update, resource sampling or camera helper', name, begin, end, reader))
    if args.owned_recipes:
        getter='recomp/config/output/sub_001B0300_0x1b0300.cpp';proof.append(compare_source('exact three-word raw-mode getter; bounded fixture port',getter,0x1b0300,0x1b030c,main_read))
    units = ['game/native/gameplay_effects/' + n + '.cpp' for n in ['periodic_visuals', 'geometry', 'tracks']]
    units += ['game/native/animation/' + n + '.cpp' for n in ['model', 'model_math', 'curves']]
    units += ['game/native/transform_math/transform_math.cpp', 'game/native/gameplay_actors/entity.cpp']
    units += ['game/native/gameplay_scenario/' + n + '.cpp' for n in ['periodic_effects', 'scene_controls', 'flags', 'fog']]
    units += ['game/native/gameplay_session/session.cpp', 'game/native/gameplay_tasks/tasks.cpp']
    units += ['game/native/'+n for n in ['gameplay_effects/resource_companion.cpp','gameplay_world/resource_models.cpp','gameplay_world/model_attachments.cpp','gameplay_scenario/scene_resources.cpp','gameplay_scenario/resource_templates.cpp']]
    units=list(dict.fromkeys(units+SURFACE_WORLD_UNITS))
    if args.resource_pulses:
        units += ['game/native/'+n for n in ['gameplay_world/resource_frames.cpp','gameplay_world/resource_models.cpp','gameplay_world/resource_programs.cpp','gameplay_scenario/scene_resources.cpp','animation/weapon_program.cpp']]
    if args.resource_static: units += ['game/native/gameplay_world/resource_static_assets.cpp']
    if args.resource_factory:
        units += ['game/native/'+n for n in ['gameplay_world/resource_frames.cpp','gameplay_world/resource_models.cpp','gameplay_world/resource_programs.cpp','gameplay_world/resource_factory.cpp','gameplay_scenario/scene_resources.cpp','gameplay_scenario/resource_templates.cpp','gameplay_scenario/resource_collisions.cpp','animation/weapon_program.cpp']]
    units=list(dict.fromkeys(units))
    if args.resource_inventory: units+=['game/native/gameplay_world/inventory.cpp']
    if args.resource_content: units+=['game/native/gameplay_world/resource_use.cpp','game/native/gameplay_world/resource_contents.cpp']
    if args.resource_pairs: units+=['game/native/gameplay_world/resource_pairs.cpp']
    if args.resource_recipes: units+=['game/native/gameplay_world/resource_recipes.cpp']
    if args.owned_recipes: units+=UPDATE_UNITS+['game/native/gameplay_world/owned_resource_recipes.cpp']
    if args.resource_consumption: units+=['game/native/gameplay_world/resource_consumption.cpp']
    if args.resource_health: units+=['game/native/gameplay_world/resource_health_effects.cpp']
    if args.resource_deployment: units+=['game/native/gameplay_world/resource_deployment.cpp']
    if args.resource_effects: units+=['game/native/gameplay_world/resource_effects.cpp']
    if args.resource_depletion: units+=['game/native/gameplay_world/resource_depletion.cpp']
    if args.resource_ownership: units+=['game/native/gameplay_world/resource_ownership.cpp']
    if args.actor_resource_operations: units+=['game/native/gameplay_world/actor_resource_operations.cpp','game/native/gameplay_world/equipment_notice.cpp','game/native/gameplay_world/resource_auxiliary_lists.cpp']
    if args.actor_terminal: units+=['game/native/gameplay_world/actor_terminal_timer.cpp']
    if args.actor_progression:
        units+=['game/native/'+n for n in ['gameplay_world/actor_gauge_progression.cpp','gameplay_world/actor_recovery.cpp','gameplay_world/animation.cpp','gameplay_world/motion_selection.cpp','gameplay_world/motion_resources.cpp','gameplay_world/motion_profiles.cpp','gameplay_actors/health_class.cpp','animation/playback.cpp','animation/model_blend.cpp','animation/motion_bank.cpp','animation/motion_descriptors.cpp']]
    if args.weapon_resources:
        units+=['game/native/'+n for n in ['gameplay_weapon_resources/weapon_resources.cpp','gameplay_bank_loading/aliases.cpp','gameplay_bank_loading/loader.cpp','gameplay_audio/owner.cpp','gameplay_audio/import.cpp','gameplay_audio/routing.cpp','gameplay_audio/spatial.cpp','audio_banks/v2/session.cpp','audio_banks/v2/algorithms.cpp','resources/bounded_view.cpp','resources/virtual_file_view.cpp','resources/resource_session.cpp','resources_windows/pinned_file.cpp','resource_io/async_read_owner.cpp','afs_source_range/afs_source_range.cpp','tasks/serial_worker.cpp']]
        units=list(dict.fromkeys(units))
    if args.actor_reception: units+=['game/native/gameplay_update/reception.cpp','game/native/gameplay_update/actor_message_queue.cpp']
    if args.equipment_resources: units+=['game/native/gameplay_weapon_resources/equipment.cpp']
    if args.resource_companion_policy: units+=['game/native/gameplay_effects/resource_companion.cpp']
    if args.resource_companions: units+=['game/native/'+n for n in ['gameplay_effects/resource_companion_actions.cpp','gameplay_world/animation_audio.cpp','gameplay_world/footwear.cpp','gameplay_scenario/scene_models.cpp','gameplay_scenario/content.cpp','gameplay_audio/scenario_cues.cpp','gameplay_collision/regions.cpp','gameplay_lighting/lights.cpp','gameplay_lighting/timed_lights.cpp','gameplay_scenario/lighting.cpp']]
    units=list(dict.fromkeys(units))
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
    for name in originals + [fixture, helper, Path(__file__).relative_to(ROOT).as_posix(),'tools/native_reconstruction/comparison_objects.py','tools/native_reconstruction/comparison_oracle.py','tools/native_reconstruction/effect_work_sources.py','tools/native_reconstruction/gameplay_update_sources.py']:
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
    if args.resource_content:
        name='tools/native_reconstruction/resource_content_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_pairs:
        name='tools/native_reconstruction/resource_pairs_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_recipes:
        name='tools/native_reconstruction/resource_recipes_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.owned_recipes:
        for name in ['tools/native_reconstruction/owned_resource_recipes_tests.inc',getter]:frozen[name]=(ROOT/name).read_bytes()
    if args.resource_consumption:
        name='tools/native_reconstruction/resource_consumption_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_wrappers:
        name='tools/native_reconstruction/resource_wrappers_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_health:
        name='tools/native_reconstruction/resource_health_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_deployment:
        name='tools/native_reconstruction/resource_deployment_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_effects:
        name='tools/native_reconstruction/resource_effects_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_debris:
        name='tools/native_reconstruction/resource_debris_tests.inc';frozen[name]=(ROOT/name).read_bytes()
        name='tools/native_reconstruction/resource_debris_capacity_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_depletion:
        name='tools/native_reconstruction/resource_depletion_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_ownership:
        name='tools/native_reconstruction/resource_ownership_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.actor_resource_operations:
        name='tools/native_reconstruction/actor_resource_operations_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_auxiliary:
        name='tools/native_reconstruction/resource_auxiliary_lists_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.actor_terminal:
        name='tools/native_reconstruction/actor_terminal_timer_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.actor_progression:
        name='tools/native_reconstruction/actor_gauge_progression_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.actor_recovery:
        name='tools/native_reconstruction/actor_recovery_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.actor_reception:
        name='tools/native_reconstruction/actor_reception_tests.inc';frozen[name]=(ROOT/name).read_bytes()
        name='tools/native_reconstruction/actor_reception_equipment_tests.inc';frozen[name]=(ROOT/name).read_bytes()
        name='tools/native_reconstruction/actor_message_queue_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.actor_zero_health:
        name='tools/native_reconstruction/actor_zero_health_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.weapon_resources:
        name='tools/native_reconstruction/weapon_resources_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.equipment_resources:
        name='tools/native_reconstruction/equipment_resources_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.equipment_selection:
        name='tools/native_reconstruction/equipment_selection_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_companion_policy:
        name='tools/native_reconstruction/resource_companion_policy_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    if args.resource_companions:
        name='tools/native_reconstruction/resource_companions_tests.inc';frozen[name]=(ROOT/name).read_bytes()
    out.mkdir(parents=True)
    record = dict(schema=1, status='failed', game_run=False, installed_in_game=False, stage4_complete=False,
                  focused_companion_run=args.focus_companions,
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
        if args.resource_pairs:
            raw_pairs=overlay['o2'][0x709ef0-0x570000:0x709ef0-0x570000+44]
            native_pairs=re.findall(r'\{(\d+),(\d+)\}',frozen['game/native/gameplay_world/resource_special_recipe_profile.inc'].decode())
            assert struct.pack('<22h',*(int(v)for pair in native_pairs for v in pair))==raw_pairs
            record['special_recipe_table']={'address':'0x709ef0','bytes':raw_pairs.hex()};init+='{const std::uint8_t data[]{'+','.join(str(v)for v in raw_pairs)+'};std::memcpy(memory+0x709ef0,data,sizeof data);}'
        if args.owned_recipes:
            for at,size in [(0x73e4f0,24*4),(0x73e590,8*4),(0x389d30,39)]:
                raw=overlay['o2'][at-0x570000:at-0x570000+size]if at>=0x570000 else overlay['o0'][at-0x370000:at-0x370000+size];record.setdefault('owned_recipe_constants',{})[hex(at)]=raw.hex();init+='{const std::uint8_t data[]{'+','.join(str(v)for v in raw)+'};std::memcpy(memory+'+str(at)+',data,sizeof data);}'
            record['declared_ports'].append('1B0300 exact three-word raw-mode getter3243F2; actual1B0340/1B02D0 bodies execute')
        if args.resource_consumption:
            native_rules=frozen['game/native/gameplay_events/scenario_event_rules.inc'].decode();tables=re.findall(r'\{ // (0x[0-9a-f]+)\r?\n(.*?)\r?\n\s*\},',native_rules,re.S);assert len(tables)==10
            for address,body in tables:
                at=int(address,16);rows=re.findall(r'\{(\d+),(\d+),(\d+),(\d+),(\d+),(\d+)\}',body);encoded=b''.join(struct.pack('<BB4H',*(int(v)for v in row))for row in rows);assert encoded==overlay['o0'][at-0x370000:at-0x370000+len(encoded)]and overlay['o0'][at-0x370000+len(encoded)]==255
            mapping=bytes(int(v)for v in re.search(r'mapping\{([^}]*)\}',native_rules)[1].split(','));assert mapping==overlay['o0'][0x38a4a0-0x370000:0x38a4d0-0x370000]
            at=0x389d60;raw=overlay['o0'][at-0x370000:0x38a4f8-0x370000];record['completion_rule_data']={'address':hex(at),'bytes':len(raw),'sha256':hashlib.sha256(raw).hexdigest()};init+='{const std::uint8_t data[]{'+','.join(str(v)for v in raw)+'};std::memcpy(memory+'+str(at)+',data,sizeof data);}'
        if args.resource_health:
            profile=frozen['game/native/gameplay_world/resource_healing_profile.inc'].decode().split('\n',1)[1];amounts=[int(v)for v in profile.strip().split(',')];raw=overlay['o2'][0x709c68-0x570000+600:0x709c68-0x570000+638];assert struct.pack('<19h',*amounts)==raw
            record['healing_profile']={'first_content':300,'count':19,'bytes':raw.hex()}
            for at,size in [(0x709c68+600,38),(0x740340,40),(0x740710,64)]:
                raw=overlay['o2'][at-0x570000:at-0x570000+size];record.setdefault('health_constants',{})[hex(at)]=raw.hex();init+='{const std::uint8_t data[]{'+','.join(str(v)for v in raw)+'};std::memcpy(memory+'+str(at)+',data,sizeof data);}'
            record['declared_ports'].append('UI close6E1430, controller feedback665CA0, text resolve1C1CE0 and notice1B4820; actual UI/device consumers remain open')
        if args.resource_debris:
            for at,size in [(0x709538,12),(0x70b860,48),(0x73e0b0,12)]:
                raw=overlay['o2'][at-0x570000:at-0x570000+size];record.setdefault('debris_constants',{})[hex(at)]=raw.hex();init+='{const std::uint8_t data[]{'+','.join(str(v)for v in raw)+'};std::memcpy(memory+'+str(at)+',data,sizeof data);}'
            assert struct.unpack('<3I',overlay['o2'][0x709538-0x570000:0x709544-0x570000])==(0x58fbe0,0x58fd10,0x58fe50)
            assert struct.unpack('<12f',overlay['o2'][0x70b860-0x570000:0x70b890-0x570000])==(-60.,0.,0.,-40.,0.,0.,0.,0.,0.,0.,0.,0.)
            assert overlay['o2'][0x73e0b0-0x570000:0x73e0b4-0x570000]==struct.pack('<I',0xbf7ae148)
            assert overlay['o2'][0x73e0b8-0x570000:0x73e0bc-0x570000]==struct.pack('<I',0x3d4ccccd)
            record['declared_ports'].append('57D560 delegates to actual canonical Grid/trace.floor; independent trace internals are not requalified by debris lifecycle comparisons')
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
        if args.resource_companions:
            at,size=0x73ebc0,48;value=overlay['o2'][at-0x570000:at-0x570000+size];record['companion_offset_constants']=value.hex();init+='{const std::uint8_t data[]{'+','.join(str(v)for v in value)+'};std::memcpy(memory+'+str(at)+',data,sizeof data);}'
        if args.actor_progression:
            for at,size in [(0x71adb0,32),(0x71add0,32),(0x71ad10,32),(0x740478,4)]:
                value=overlay['o2'][at-0x570000:at-0x570000+size];record.setdefault('gauge_progression_tables',{})[hex(at)]={'bytes':size,'sha256':hashlib.sha256(value).hexdigest()};init+='{const std::uint8_t data[]{'+','.join(str(v)for v in value)+'};std::memcpy(memory+'+str(at)+',data,sizeof data);}'
            record['declared_ports'].append('667420 global UI/timer request6DF160, close-admission6DEE80, UI-close6E1430, recovery65FCB0 and off-room notice81C690 are explicit controlled effects; actual inventory5F6800 and pose667370 execute')
        if args.actor_recovery:
            profiles=json.loads((ROOT/'build-native-sjuni/motion-body-profile-v1/receipt.json').read_bytes())
            spans=[(0x71b030,8),(0x740340,40),(0x740710,64),(0x73ea60,128),(0x73eae0,12),(0x71bd80,64),(0x70afa0,4),(0x70c2d0,36),(0x70c4e0,36),(0x710248,16),(0x719a60,64*68),(0x725ca0,0x726aa0+1112*8-0x725ca0)]+[(int(x['address'],16),x['bytes']) for x in profiles['owned_content']]
            for at,size in spans:
                value=overlay['o2'][at-0x570000:at-0x570000+size];record.setdefault('recovery_tables',{})[hex(at)]={'bytes':size,'sha256':hashlib.sha256(value).hexdigest()};init+='{const std::uint8_t data[]{'+','.join(str(v)for v in value)+'};std::memcpy(memory+'+str(at)+',data,sizeof data);}'
            skeleton=ROOT/'build-native-sjuni/animation-owned-corpus-v2/owned_skeletons.bin';receipt=json.loads((skeleton.parent/'receipt.json').read_bytes());assert sha(skeleton)==receipt['output_sha256']['owned_skeletons.bin'];(out/skeleton.name).write_bytes(skeleton.read_bytes());record['recovery_skeletons_sha256']=sha(skeleton)
            record['recovery_admission']='Complete65FCB0 with actual status publications, inventory/model consumers, pose snapshots, health classification and WorldAnimation/Playback activation using confirmed absent banks; enabled selector1 delivery, retained failures and native gauge-to-recovery composition are compared or checked separately'
            record['declared_ports'].append('Recovery UI6E1430 and final room/message sinks remain declared; actual WorldAnimation selects with confirmed absent banks for the current online profile, then actual Playback activation. Real clip-bearing recovery acceptance remains open.')
        if args.actor_reception:
            at,size=0x740750,64;value=overlay['o2'][at-0x570000:at-0x570000+size];record['actor_reception_switch_sha256']=hashlib.sha256(value).hexdigest();init+='{const std::uint8_t data[]{'+','.join(str(v)for v in value)+'};std::memcpy(memory+'+str(at)+',data,sizeof data);}'
            record['actor_reception_admission']='Complete67ED50 selectors4/6/8/9/10/12/14/15 and shared admission/pose/equipment tail through canonical World/RoomObject/Equipment owners; remaining selectors and actual transport remain open'
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
            values={}
            with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as iso:
                for selector,member in zip(selectors,selected):
                    iso.seek(member['iso_offset']);payload=iso.read(member['bytes']);assert hashlib.sha256(payload).hexdigest()==member['sha256'];values[selector]=payload
            if args.stock_wmd_absence:
                # Derive absence independently from the complete named inventory
                # and every owned ITEM row, then verify the production profile.
                members=json.loads(inventory.read_bytes())
                named={int(re.fullmatch(r'wp(\d+)\.wmd',n.lower()).group(1)):m['member'] for m in members for n in m.get('names',[]) if re.fullmatch(r'wp(\d+)\.wmd',n.lower())}
                assert named=={selector:member['member'] for selector,member in zip(selectors,selected)}
                item_selectors=set();rows=[]
                with (out/'owned_templates.bin').open('rb')as data:
                    assert struct.unpack('<I',data.read(4))[0]==5
                    for bank in range(5):
                        size=struct.unpack('<I',data.read(4))[0];section=data.read(size);count=struct.unpack_from('<I',section,4)[0];start=struct.unpack_from('<I',section,16)[0]
                        assert len(section)==size and start+count*24<=size
                        for row in range(count):
                            selector=struct.unpack_from('<b',section,start+row*24+14)[0]
                            if selector>=0:item_selectors.add(selector);rows.append(dict(bank=bank,row=row,selector=selector))
                absent=sorted(item_selectors-set(named));profile=frozen['game/native/gameplay_weapon_resources/known_wmd_absences.inc'].decode().split('\n',1)[1]
                assert absent==[int(v)for v in profile.strip().split(',')]
                assert len(item_selectors)==29 and len(absent)==18
                for selector in absent:values[selector]=b''
                record['stock_wmd_absence_audit']=dict(inventory_sha256=sha(inventory),named_members=named,item_selectors=sorted(item_selectors),absent=absent,item_rows=rows)
            values=['{'+str(selector)+',{'+','.join(str(v)for v in payload)+'}}' for selector,payload in sorted(values.items())]
            (out/'owned_weapons.hpp').write_text('struct OwnedWeapon {int selector;std::vector<std::uint8_t> bytes;};\ninline const std::array<OwnedWeapon,'+str(len(values))+'> owned_weapons{{'+','.join(values)+'}};\n')
            digest='69ae2c48e6f01e2605659feabb54eb9b82c63a809bdc8a78ad2d160b3c59a4a1'
            (out/'owned_iso.hpp').write_text('constexpr std::uint64_t owned_iso_bytes=4698767360ull;\nconstexpr reo::native::resources::win32::Digest owned_iso_sha{'+','.join(str(v)for v in bytes.fromhex(digest))+'};\n')
        if args.resource_depletion:
            cue_name='weapon35.snd' if args.stock_wmd_absence else 'weapon33.snd'
            cue=next(m for m in json.loads(inventory.read_bytes()) if cue_name in [n.lower()for n in m.get('names',[])])
            with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb')as iso:
                iso.seek(cue['iso_offset']);data=iso.read(cue['bytes']);assert hashlib.sha256(data).hexdigest()==cue['sha256']
            descriptor=struct.unpack_from('<I',data,32)[0]+16+5*16;assert data[descriptor]==0 and data[descriptor+9]==255
            (out/'owned_depletion_cue.bin').write_bytes(data);record['depletion_cue_asset']=cue
            record['declared_ports'].append('1B93D0 final positioned bank request uses an independently qualified native audio owner/mixer; complete1B8C70 frontend executes; '+cue_name+' cue bank is a controlled identity-bank assignment')
            if args.stock_wmd_absence:
                record['declared_ports'].append('1CC8F0 returns0 without writing only for the18 independently audited missing stock WMD paths; complete original refresh/depletion callers execute. Original filesystem worker internals are not newly executed.')
        env = dict(os.environ)
        env['PATH'] = str(args.compiler.resolve().parent) + os.pathsep + env.get('PATH', '')
        binary = out / 'checks.exe'
        command = [str(args.compiler), '-std=c++20', '-O2', '-msse4.1', '-pthread', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
                   '-Wno-unused-label', '-Wno-unused-parameter', '-fno-fast-math', '-ffp-contract=off', '-I' + str(out), '-I' + str(out / 'source')]
        if args.resource_pulses: command.insert(1,'-DREO_RESOURCE_PULSES=1')
        if args.resource_static: command.insert(1,'-DREO_RESOURCE_STATIC=1')
        if args.resource_factory: command.insert(1,'-DREO_RESOURCE_FACTORY=1')
        if args.resource_placement: command.insert(1,'-DREO_RESOURCE_PLACEMENT=1')
        if args.resource_delayed: command.insert(1,'-DREO_RESOURCE_DELAYED=1')
        if args.resource_actions: command.insert(1,'-DREO_RESOURCE_ACTIONS=1')
        if args.resource_inventory: command.insert(1,'-DREO_RESOURCE_INVENTORY=1')
        if args.resource_content: command.insert(1,'-DREO_RESOURCE_CONTENT=1')
        if args.resource_pairs: command.insert(1,'-DREO_RESOURCE_PAIRS=1')
        if args.resource_recipes: command.insert(1,'-DREO_RESOURCE_RECIPES=1')
        if args.owned_recipes: command.insert(1,'-DREO_OWNED_RECIPES=1')
        if args.resource_consumption: command.insert(1,'-DREO_RESOURCE_CONSUMPTION=1')
        if args.resource_wrappers: command.insert(1,'-DREO_RESOURCE_WRAPPERS=1')
        if args.resource_health: command.insert(1,'-DREO_RESOURCE_HEALTH=1')
        if args.resource_deployment: command.insert(1,'-DREO_RESOURCE_DEPLOYMENT=1')
        if args.resource_effects: command.insert(1,'-DREO_RESOURCE_EFFECTS=1')
        if args.resource_debris: command.insert(1,'-DREO_RESOURCE_DEBRIS=1')
        if args.resource_depletion: command.insert(1,'-DREO_RESOURCE_DEPLETION=1')
        if args.stock_wmd_absence: command.insert(1,'-DREO_STOCK_WMD_ABSENCE=1')
        if args.resource_use: command.insert(1,'-DREO_RESOURCE_USE=1')
        if args.resource_ownership: command.insert(1,'-DREO_RESOURCE_OWNERSHIP=1')
        if args.actor_resource_operations: command.insert(1,'-DREO_ACTOR_RESOURCE_OPERATIONS=1')
        if args.resource_auxiliary: command.insert(1,'-DREO_RESOURCE_AUXILIARY_LISTS=1')
        if args.actor_terminal: command.insert(1,'-DREO_ACTOR_TERMINAL_TIMER=1')
        if args.actor_progression: command.insert(1,'-DREO_ACTOR_GAUGE_PROGRESSION=1')
        if args.actor_recovery: command.insert(1,'-DREO_ACTOR_RECOVERY=1')
        if args.focus_recovery: command.insert(1,'-DREO_RECOVERY_ONLY=1')
        if args.actor_reception: command.insert(1,'-DREO_ACTOR_RECEPTION=1')
        if args.focus_reception: command.insert(1,'-DREO_RECEPTION_ONLY=1')
        if args.actor_zero_health: command.insert(1,'-DREO_ACTOR_ZERO_HEALTH=1')
        if args.focus_zero_health: command.insert(1,'-DREO_ZERO_HEALTH_ONLY=1')
        if args.weapon_resources: command.insert(1,'-DREO_WEAPON_RESOURCES=1')
        if args.equipment_resources: command.insert(1,'-DREO_EQUIPMENT_RESOURCES=1')
        if args.equipment_selection: command.insert(1,'-DREO_EQUIPMENT_SELECTION=1')
        if args.resource_companion_policy: command.insert(1,'-DREO_RESOURCE_COMPANION_POLICY=1')
        if args.resource_companions: command.insert(1,'-DREO_RESOURCE_COMPANIONS=1')
        if args.focus_companions: command.insert(1,'-DREO_RESOURCE_COMPANIONS_FOCUSED=1')
        objects,object_receipts=compile_objects(ROOT,out,args.compiler,command[1:],units,frozen,env)
        record['focused_recovery_run']=args.focus_recovery
        record['focused_zero_health_run']=args.focus_zero_health
        record['production_objects']=object_receipts
        original_object,original_receipt=compile_oracle(ROOT,out,args.compiler,command[1:],env)
        record['original_object']=original_receipt
        command += objects+[original_object,str(out/'tests.cpp'),'-o',str(binary)]
        if args.weapon_resources:command+=['-lbcrypt']
        record['command'] = command
        for label, cmd in [('compile', command), ('run', [str(binary), str(out / 'owned_effect_geometry.bin')]+([str(out/'owned_static_nbd.bin')] if args.resource_static else [])+([str(out/'owned_templates.bin')] if args.resource_factory else [])+([str(ROOT/'iso/Resident Evil - Outbreak (v2.00).iso')] if args.weapon_resources else []))]:
            result = subprocess.run(cmd, env=env, capture_output=True, timeout=420 if args.resource_ownership else 240 if args.weapon_resources else 180)
            (out / (label + '.stdout.txt')).write_bytes(result.stdout)
            (out / (label + '.stderr.txt')).write_bytes(result.stderr)
            record.setdefault('returncodes', {})[label] = result.returncode
            assert result.returncode == 0, label + ' failed with code ' + str(result.returncode) + '; see retained logs'
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
