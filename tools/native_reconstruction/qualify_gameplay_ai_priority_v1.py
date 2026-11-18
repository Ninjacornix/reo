"""Seal complete goal reevaluation through canonical Actor/Bank/resource owners."""
import json
from seal_gameplay_component import ROOT,seal,sha

if __name__=='__main__':
    prior='tools/native_reconstruction/native_gameplay_ai_initialize_qualification_v1.json'
    assert sha(ROOT/prior)=='356e14ea0a9e291840ed37cf97883e59ae0d954d0382d24ad0e3a0ce4fd5aa86'
    expected=json.loads((ROOT/prior).read_bytes())['cohorts']['llvm']['observed']|dict(
        checks=94095293,goal_resource_cases=470016,target_busy_cases=2048,
        goal_reevaluation_cases=62722,goal_reevaluation_writes=4027,
        goal_reevaluation_refusals=5,goal_alias_cases=512)
    seal(target='tools/native_reconstruction/native_gameplay_ai_priority_qualification_v1.json',
        suite='gameplay-ai-priority',parent_version=3,status='qualified complete admitted native AI goal reevaluation',
        expected=expected,extra_sources=['game/native/CMakeLists.txt','game/native/gameplay_world/world.hpp',
            'game/native/gameplay_world/world.cpp','game/native/gameplay_actors/entity.cpp',
            'game/native/gameplay_update/ai.cpp','game/native/gameplay_update/ai_tests.cpp',
            'game/native/gameplay_update/update.hpp','game/native/gameplay_update/CMakeLists.txt',
            'tools/native_reconstruction/gameplay_update_sources.py','tools/native_reconstruction/effect_work_sources.py',
            'tools/native_reconstruction/qualify_gameplay_ai_priority_v1.py'],
        binaries=['gameplay_update/gameplay_ai_owner_tests.exe','gameplay_update/libreo_native_gameplay_update.a',
            'gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/ai.cpp.obj',
            'gameplay_ai/gameplay_ai_tests.exe','gameplay_ai/libreo_native_gameplay_ai.a',
            'gameplay_ai/CMakeFiles/reo_native_gameplay_ai.dir/priority_goals.cpp.obj',
            'gameplay_navigation/libreo_native_gameplay_navigation.a',
            'gameplay_scenario/libreo_native_gameplay_scenario.a'],prior=prior,
        additional_evidence=[f'build-native-sjuni/gameplay-ai-priority-{kind}-{cc}-v{version}.log' for cc in ['llvm','gcc'] for kind,version in [('parent',1),('parent',2),('tests',2)]],
        ports=['107C68 exact two eight-byte zero fills in original-only profile selection surroundings'],
        limitations=[
            'Complete8133D0,825CC0,823190 and817140 source bodies are audited against owned immutable binaries and executed in the original-only fixture. Both compilers agree on94095293 checks,62722 reevaluations including512 self/reference/companion aliases,4027 setter calls,470016 resource selections and2048 busy predicates. Native production uses canonical Actor, Bank and SceneResources without a guest-addressed state model.',
            'Source motion/auxiliary/refresh gates precede loaded graph admission. Empty/absent room graphs are source no-ops. The observation byte clears before reference/companion dependencies. Missing native components, missing required actors or unbound/invalid navigation refuse explicitly at the documented prefix. No active/AI-control gate or automatic construction is invented.',
            'Resource selection keeps the exact signed-health threshold, source FP32 multiply/divide order, nine extended inventory slots, special slot and first matching active descriptor. Owned71B034 is25.0; the sign-extended offset must not be mistaken for72B034. The goal-resource word has one mutable owner: item selection replaces its low byte while goal11 zero-extends the reference equipment byte over the whole word.',
            'Both current parent builds and twelve integration tests pass, including actual primary actor selection by physical index, distinct logical actor slot, reference reactions, companion suppression, fullword/lowbyte resource aliases, fallback weights, no-op winners, retirement and closure. First parent builds lacked a fixture include; v2 tests caught a four-byte authored graph-directory fixture error. Corrected fixtures and fresh v3 builds/tests pass. No production algorithm change or dependency substitution was required.',
            'Full observations, reaction/action dispatch, actor construction, control service and transport, remaining stock VM/input/network/save ownership and coherent native gameplay installation remain open. Installed V39 is unchanged; no game launch, slowdown fix or Stage4 completion is claimed.'
        ])
