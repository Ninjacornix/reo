"""Seal current complete VM regressions after AI goal/reaction/observation work."""
import json
from seal_gameplay_component import ROOT,sha
if __name__=='__main__':
    target=ROOT/'tools/native_reconstruction/native_ai_observation_vm_qualification_v1.json';assert not target.exists()
    sources,cohorts={},{ };observed=None
    for cc in ['llvm','gcc']:
        path=ROOT/f'build-native-sjuni/ai-observation-vm-{cc}-v1/receipt.json';receipt=json.loads(path.read_bytes());data=receipt['result']
        assert receipt['status']=='passed' and not receipt['pinned_shared_sources'] and not receipt['pinned_current_source_drift'];assert observed is None or observed==data;observed=data
        for key,value in dict(checks=19719138,original_dispatch_invocations=30245,room_variant_handlers=32768,room_variant_dispatches=60,room_variant_refusals=7,room_variant_world_cases=4).items():assert data[key]==value,key
        assert receipt['checked_owned_instruction_comments']==7001
        assert {kind:(item['count'],item['total']) for kind,item in data['coverage'].items()}=={'ordinary':(328,432),'offline_actor':(300,432)}
        for name,digest in (receipt['source_sha256']|receipt['original_sources_sha256']).items():
            assert sha(ROOT/name)==digest,name;assert name not in sources or sources[name]==digest,name;sources[name]=digest
        for name,key in [('checks.exe','executable_sha256'),('original_fixture.hpp','generated_fixture_sha256'),('original.cpp','generated_original_sha256')]:assert sha(path.parent/name)==receipt[key],name
        cohorts[cc]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),executable_sha256=receipt['executable_sha256'],checks=data['checks'],original_dispatch_invocations=data['original_dispatch_invocations'])
    sources['tools/native_reconstruction/qualify_ai_observation_vm_v1.py']=sha(ROOT/'tools/native_reconstruction/qualify_ai_observation_vm_v1.py')
    prior='tools/native_reconstruction/native_gameplay_ai_observation_gates_qualification_v1.json';assert sha(ROOT/prior)=='39f74403c4adc6e773ff551b34c43e1470212af7f26604e6f7ffafc2acbf64b7'
    target.write_text(json.dumps(dict(schema=1,status='passed current-source full VM regressions after AI goal reaction and observation gates',game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,cohorts=cohorts,prior=dict(path=prior,sha256=sha(ROOT/prior)),limitations=[
        'Both compilers pass19719138 identical full VM checks,30245 original dispatcher invocations and7001 owned instruction comments with current sources and no historical pins. Ordinary328/432 and offline300/432 include no-op bindings and are not overall Stage4 percentages.',
        'The complete frozen native closure now includes priority goal reevaluation, canonical resource selection, reaction scheduling, Session RNG and observation admission helpers with the existing World/scenario/navigation modules. This is a composition regression, not transitive execution of all compiled AI functions; separate original comparisons qualify their individual behavior.',
        'Full observation/cache production, goal/action execution, real actor/assets/control/VM/input/network/save ownership and coherent native game acceptance remain open. Installed V39 is unchanged; no game launch or Stage4 completion is claimed.'
    ]),indent=2)+'\n');print(sha(target))
