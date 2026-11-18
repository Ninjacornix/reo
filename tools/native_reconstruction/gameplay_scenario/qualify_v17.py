"""Seal opcode131 with the actual native task/visual provider composition."""
import hashlib
import json
import struct
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    paths = [ROOT / 'build-native-sjuni' / n / 'receipt.json' for n in ['gameplay-scenario-llvm-v35', 'gameplay-scenario-gcc-v25']]
    data = [json.loads(path.read_bytes()) for path in paths]
    for record in data:
        assert record['status'] == 'passed' and not record['game_launched'] and not record['installed_in_game']
        for name, digest in record['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
        assert record['oracle_profile']['compiled_private_source_snapshot']
        assert record['oracle_profile']['actual_native_periodic_visual_owner']
    assert data[0]['source_sha256'] == data[1]['source_sha256'] and data[0]['result'] == data[1]['result']
    raw = (ROOT / 'build-function-index/owned-overlays/o2.bin').read_bytes()
    digest = hashlib.sha256(raw).hexdigest()
    assert digest == '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    ordinary = struct.unpack_from('<432I', raw, 0x717830 - 0x570000)
    offline = [struct.unpack_from('<IBBBB', raw, 0x73cbe0 - 0x570000 + i * 8) for i in range(432)]
    masks = data[0]['result']['coverage']
    bindings = [dict(opcode=i, opcode_hex=f'{i:03X}',
                     ordinary=dict(original_target=f'{ordinary[i]:08X}', native_algorithm=masks['ordinary']['native_algorithm'][i]),
                     offline_actor=dict(original_target=f'{offline[i][0]:08X}', native_algorithm=masks['offline_actor']['native_algorithm'][i],
                                        relation_one=offline[i][1], restricted_category=offline[i][2], relation_two=offline[i][3]),
                     selected_native_provider_composition_qualified=i == 0x131,
                     installed_in_game=False, production_provider_coverage_proven=False) for i in range(432)]
    previous = ROOT / 'tools/native_reconstruction/gameplay_scenario_qualification_v16.json'
    visual = ROOT / 'tools/native_reconstruction/native_periodic_visuals_qualification_v1.json'
    docs = [ROOT / 'docs/native-gameplay/SCENARIO_PERIODIC_EFFECTS.md', Path(__file__)]
    result = dict(schema='reo.native.gameplay.scenario.qualification.v17', status='qualified_partial_native_periodic_command_and_actual_task_visual_composition',
                  complete=False, stage4_complete=False, installed_in_game=False, game_launched=False, live_process_access=False, new_opcodes=[0x131],
                  previous_qualification=dict(path=previous.relative_to(ROOT).as_posix(), sha256=sha(previous)),
                  periodic_visual_qualification=dict(path=visual.relative_to(ROOT).as_posix(), sha256=sha(visual)),
                  owned_overlay_sha256=digest, source_sha256=data[0]['source_sha256'],
                  documentation_and_tools_sha256={p.relative_to(ROOT).as_posix(): sha(p) for p in docs},
                  receipts=[dict(path=p.relative_to(ROOT).as_posix(), sha256=sha(p), compiler=d['compiler'], compiler_sha256=d['compiler_sha256'], result=d['result'],
                                 checked_owned_instruction_comments=d['checked_owned_instruction_comments']) for p, d in zip(paths, data)],
                  coverage={k: dict(native_algorithm=v['count'], total=432, unsupported=432 - v['count'], includes_original_noop_bindings=True) for k, v in masks.items()},
                  bindings=bindings,
                  canonical_periodic_owner=dict(all_matching_type5=True, fullword_authored_id=True, enabled_filter=False,
                                                complete_reset_then_enable_counter_parameters_factory_order=True,
                                                native_scheduler_full_is_natural_miss=True, owns_actual_native_visual_resource_consumer=True,
                                                canonical_controls_flags_rng_identity_checked=True, task_domain_closed_admission_checked=True,
                                                byte_flag_profile_0_to_127=True, source_halfword_mask_preserved=True),
                  limitations=['Projected SceneControls must join the same128-record collision/proxy owner before game installation.',
                               'Selected periodic visual profile is complete; other event/effect factories and whole stock programs remain open.',
                               '573630 allocation is a declared fixture seam; the real native scheduler and real visual owner execute in the native composition.',
                               'Opcode masks include original no-ops and are not overall gameplay completion.',
                               'No game, actual renderer submission or complete Stage4 migration is claimed.'])
    output = ROOT / 'tools/native_reconstruction/gameplay_scenario_qualification_v17.json'
    assert not output.exists()
    output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(dict(path=output.relative_to(ROOT).as_posix(), sha256=sha(output), coverage=result['coverage'])))


if __name__ == '__main__':
    main()
