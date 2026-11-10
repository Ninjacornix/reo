"""Seal current complete VM regressions after native navigation/AI additions."""
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target=ROOT/'tools/native_reconstruction/native_ai_initialize_vm_qualification_v1.json';assert not target.exists()
    sources,cohorts,failures={},{},{}
    observed=None
    for cc in ['llvm','gcc']:
        path=ROOT/f'build-native-sjuni/ai-initialize-vm-{cc}-v2/receipt.json';receipt=json.loads(path.read_bytes())
        assert receipt['status']=='passed' and not receipt['pinned_shared_sources'] and not receipt['pinned_current_source_drift']
        data=receipt['result'];assert observed is None or observed==data;observed=data
        for key,value in dict(checks=19719138,original_dispatch_invocations=30245,room_variant_handlers=32768,
            room_variant_dispatches=60,room_variant_refusals=7,room_variant_world_cases=4).items():assert data[key]==value,key
        assert receipt['checked_owned_instruction_comments']==7001
        assert {kind:(item['count'],item['total']) for kind,item in data['coverage'].items()}=={'ordinary':(328,432),'offline_actor':(300,432)}
        for name,digest in (receipt['source_sha256']|receipt['original_sources_sha256']).items():
            assert sha(ROOT/name)==digest,name
            assert name not in sources or sources[name]==digest,name
            sources[name]=digest
        assert sha(path.parent/'checks.exe')==receipt['executable_sha256']
        assert sha(path.parent/'original_fixture.hpp')==receipt['generated_fixture_sha256']
        assert sha(path.parent/'original.cpp')==receipt['generated_original_sha256']
        cohorts[cc]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),executable_sha256=receipt['executable_sha256'],
            checks=data['checks'],original_dispatch_invocations=data['original_dispatch_invocations'],coverage={k:v['count'] for k,v in data['coverage'].items()})
        for suffix in ['link.stderr.txt']:
            path=ROOT/f'build-native-sjuni/ai-initialize-vm-{cc}-v1'/suffix
            assert 'quadrant_angle' in path.read_text();failures[path.relative_to(ROOT).as_posix()]=sha(path)
        path=ROOT/f'build-native-sjuni/ai-initialize-vm-{cc}-v1.log';failures[path.relative_to(ROOT).as_posix()]=sha(path)
    sources[Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__))
    prior=ROOT/'tools/native_reconstruction/native_gameplay_ai_initialize_qualification_v1.json'
    target.write_text(json.dumps(dict(schema=1,status='passed current-source full VM regressions after AI initialization',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,cohorts=cohorts,
        failed_build_evidence=failures,prior_initialization=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior)),limitations=[
            'Both compilers pass19719138 identical full VM checks,30245 original dispatcher invocations,7001 owned instruction comments,32768 room-variant handlers,60 real dispatcher room-variant cases and four canonical World/navigation compositions. No historical source pins are used. Ordinary328/432 and offline300/432 include no-op bindings and are not overall Stage4 percentages.',
            'The source-frozen native closure includes current AI execution/control/initialization, navigation/cross-room/destination/visibility/scene lookup, room ordinal production and canonical World/scene owners. This is a composition regression, not transitive dynamic execution of every included native function. Their individual complete original comparisons remain separate qualifications.',
            'v1 standalone VM links failed because the maintained surface dependency list lacked heading.cpp after destination routing adopted quadrant_angle. Both actual CMake parent builds had already linked it correctly. v2 adds the missing dependency, recompiles the complete private closure and passes without production algorithm changes. Failed logs/snapshots remain retained.',
            'Remaining stock opcode families, complete AI observations/goal/action execution, native scene/input/network/save integration and coherent gameplay installation/acceptance stay open. Installed V39 remains unchanged and Stage4 is incomplete. No game was launched, slowdown reproduced or performance improvement measured.'
        ]),indent=2)+'\n');print(sha(target))


if __name__=='__main__':main()
