"""Freeze interpreter v2 and independent scene resource boundary receipts."""
import hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    names=['gameplay-scenario-llvm-v7','gameplay-scenario-gcc-v5','gameplay-scene-resources-llvm-v4','gameplay-scene-resources-gcc-v4']
    paths=[ROOT/'build-native-sjuni'/n/'receipt.json' for n in names];data=[json.loads(p.read_text()) for p in paths]
    assert all(d['status']=='passed' and not d['game_launched'] and not d['installed_in_game'] for d in data)
    for a,b in [(data[0],data[1]),(data[2],data[3])]:assert a['source_sha256']==b['source_sha256'] and a['result']==b['result']
    source={}
    for d in data:
        for p,digest in d['source_sha256'].items():
            assert sha(ROOT/p)==digest
            if p in source:assert source[p]==digest
            source[p]=digest
    raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();owned=hashlib.sha256(raw).hexdigest()
    assert owned=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    ordinary=struct.unpack_from('<432I',raw,0x717830-0x570000);offline=[struct.unpack_from('<IBBBB',raw,0x73cbe0-0x570000+i*8) for i in range(432)]
    masks=data[0]['result']['coverage'];bindings=[]
    for i in range(432):
        bindings.append(dict(opcode=i,opcode_hex=f'{i:03X}',ordinary=dict(original_target=f'{ordinary[i]:08X}',native_algorithm=masks['ordinary']['native_algorithm'][i]),
            offline_actor=dict(original_target=f'{offline[i][0]:08X}',native_algorithm=masks['offline_actor']['native_algorithm'][i],relation_one=offline[i][1],restricted_category=offline[i][2],relation_two=offline[i][3]),
            installed_in_game=False,production_provider_coverage_proven=False))
    docs=[ROOT/'docs/native-gameplay/SCENARIO_RESOURCE_LIFECYCLE.md',Path(__file__)]
    result=dict(schema='reo.native.gameplay.scenario.qualification.v2',status='qualified_partial_algorithm_and_scene_descriptor_boundary',complete=False,stage4_complete=False,installed_in_game=False,
        game_launched=False,live_process_access=False,owned_overlay_sha256=owned,source_sha256=source,
        documentation_and_tools_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in docs},
        receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),compiler=d['compiler'],compiler_sha256=d['compiler_sha256'],assertions=d['result']['checks'],
            original_invocations=d['result'].get('original_dispatch_invocations',d['result'].get('original_invocations')),checked_owned_instruction_comments=d['checked_owned_instruction_comments']) for p,d in zip(paths,data)],
        coverage={k:dict(native_algorithm=v['count'],total=432,unsupported=432-v['count'],includes_original_noop_bindings=True) for k,v in masks.items()},
        bindings=bindings,new_scene_opcodes=[0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37],
        native_ownership=dict(script_channels=6,scene_descriptor_capacity=256,resource_identity='native_domain_generation_slot',actor_identity='gameplay_actors::EntityId',guest_addresses=False),
        limitations=['Algorithm masks do not establish stock-program coverage, provider migration, caller installation, performance or complete gameplay.',
            'Every program containing an unsupported opcode is refused before native installation; no mixed partial fallback is implemented.',
            'Construction/release/actor-resource effects, message/notification production owners, stock-content importer and actual game adapters remain integration gates.',
            'Native scene descriptors are an explicit state projection and ownership boundary, not a complete replacement of scene construction, serialization or rendering.',
            'Original instruction/register/memory scaffolding is an offline comparison oracle only; effect implementations are explicit fixture doubles.',
            'Receipt instruction counts overlap; independent cohort counts must not be added as unique original instruction coverage.'])
    out=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v2.json';assert not out.exists();out.write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out),coverage=result['coverage'])))
if __name__=='__main__':main()
