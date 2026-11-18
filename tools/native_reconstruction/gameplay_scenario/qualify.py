"""Freeze the versioned, explicitly partial scenario capability ledger."""
import hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    receipts=[ROOT/'build-native-sjuni'/name/'receipt.json' for name in ['gameplay-scenario-llvm-v6','gameplay-scenario-gcc-v4']]
    data=[json.loads(p.read_text()) for p in receipts]
    assert all(d['status']=='passed' and not d['game_launched'] and not d['installed_in_game'] for d in data)
    assert data[0]['source_sha256']==data[1]['source_sha256'] and data[0]['result']==data[1]['result']
    assert all(sha(ROOT/name)==digest for name,digest in data[0]['source_sha256'].items())
    raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
    assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    ordinary=struct.unpack_from('<432I',raw,0x717830-0x570000)
    offline=[struct.unpack_from('<IBBBB',raw,0x73cbe0-0x570000+i*8) for i in range(432)]
    masks=data[0]['result']['coverage']
    bindings=[]
    for i in range(432):
        bindings.append(dict(opcode=i,opcode_hex=f'{i:03X}',ordinary=dict(original_target=f'{ordinary[i]:08X}',native_algorithm=masks['ordinary']['native_algorithm'][i]),
            offline_actor=dict(original_target=f'{offline[i][0]:08X}',native_algorithm=masks['offline_actor']['native_algorithm'][i],relation_one=offline[i][1],restricted_category=offline[i][2],relation_two=offline[i][3]),
            installed_in_game=False,production_provider_coverage_proven=False))
    docs=[ROOT/'docs/native-gameplay/SCENARIO_VM.md',Path(__file__),ROOT/'tools/native_reconstruction/gameplay_scenario/make_bindings.py',ROOT/'tools/native_reconstruction/gameplay_scenario/make_offline_bindings.py']
    result=dict(schema='reo.native.gameplay.scenario.qualification.v1',status='qualified_partial_algorithm_boundary',complete=False,stage4_complete=False,installed_in_game=False,
        game_launched=False,live_process_access=False,owned_overlay_sha256=hashlib.sha256(raw).hexdigest(),checked_owned_instruction_comments=data[0]['checked_owned_instruction_comments'],
        source_sha256=data[0]['source_sha256'],documentation_and_tools_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in docs},
        receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),compiler=d['compiler'],compiler_sha256=d['compiler_sha256'],assertions=d['result']['checks'],original_invocations=d['result']['original_dispatch_invocations']) for p,d in zip(receipts,data)],
        coverage={k:dict(native_algorithm=v['count'],total=432,unsupported=432-v['count'],includes_original_noop_bindings=True) for k,v in masks.items()},
        distinct_original_target_counts=dict(ordinary=len(set(ordinary)),offline_actor=len({o[0] for o in offline}),union=len(set(ordinary)|{o[0] for o in offline})),
        differing_handler_bindings=sum(ordinary[i]!=offline[i][0] for i in range(432)),bindings=bindings,
        limitations=['Algorithm masks do not establish stock-program coverage, provider migration, caller installation, performance or complete gameplay.',
            'Every program containing an unsupported opcode is refused before native installation; no mixed partial fallback is implemented.',
            'Message/notification production owners, admitted stock-content importer and actual game adapters remain integration gates.',
            'Original instruction/register/memory scaffolding is an offline comparison oracle only, never production native code.',
            'The canonical native flags and three-actor offline delta coordinator are qualified but not yet the game authoritative owners.'])
    out=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v1.json'
    assert not out.exists()
    out.write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out),coverage=result['coverage'],differing_handler_bindings=result['differing_handler_bindings'])))
if __name__=='__main__':main()
