"""Seal the corrected canonical descriptor content field in AI selection."""
import json
from seal_gameplay_component import ROOT,seal,sha
if __name__=='__main__':
    prior='tools/native_reconstruction/native_gameplay_ai_observation_gates_qualification_v1.json'
    assert sha(ROOT/prior)=='39f74403c4adc6e773ff551b34c43e1470212af7f26604e6f7ffafc2acbf64b7'
    expected=json.loads((ROOT/prior).read_bytes())['cohorts']['llvm']['observed']|dict(checks=400438140,goal_resource_cases=470019)
    seal(target='tools/native_reconstruction/native_gameplay_ai_descriptor_alias_qualification_v1.json',suite='gameplay-ai-descriptor-alias',test_count=13,
        status='qualified corrected canonical AI descriptor attachment ID selection',expected=expected,prior=prior,
        extra_sources=['game/native/gameplay_update/ai_tests.cpp','game/native/gameplay_update/ai.cpp','game/native/gameplay_update/CMakeLists.txt',
            'game/native/gameplay_world/inventory.cpp','tools/native_reconstruction/gameplay_scenario/scene_resource_tests.cpp',
            'tools/native_reconstruction/qualify_ai_descriptor_alias_v1.py'],
        binaries=['gameplay_ai/gameplay_ai_tests.exe','gameplay_ai/CMakeFiles/reo_native_gameplay_ai.dir/priority_goals.cpp.obj','gameplay_update/gameplay_ai_owner_tests.exe'],
        additional_evidence=['tools/native_reconstruction/native_gameplay_ai_priority_qualification_v1.json','tools/native_reconstruction/native_target_metrics_worker_qualification_v1.json'],
        ports=['107C68 exact two eight-byte zero fills in original-only profile selection surroundings'],limitations=[
            'Corrects prior825CC0 integration mapping. The original source reads descriptor+6 on both special and extended paths. The existing canonical descriptor projection distinguishes +4 authored descriptor lookup ID from +6 attachment/content ID. Production now compares attachment_id. The old fixture mistakenly projected authored_id at+6, masking the error in its comparisons.',
            'The corrected fixture exports both canonical fields independently and crosses authored/content IDs in three cases. Actual Owner tests reject an authored-only match and accept the attachment ID after replacing the same descriptor. The active-byte, inventory order and goal-resource low-byte effects remain unchanged.',
            'Both compilers pass400438140 current checks including470019 resource cases and all prior62722 goal reevaluations. All thirteen current parent tests pass. This supersedes the earlier resource-field claim without changing the prior immutable receipt.',
            'No game caller is installed or tested. Full observation/action execution and whole Stage4 verification remain open; V39 is unchanged.'
        ])
