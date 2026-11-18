"""Seal owned reaction policy scheduling with the actual Session RNG."""
import json
from seal_gameplay_component import ROOT,seal,sha
if __name__=='__main__':
    prior='tools/native_reconstruction/native_gameplay_ai_priority_qualification_v1.json'
    assert sha(ROOT/prior)=='f3dd97dd2ec2873fb21f88616a4497a0887124180d2e0847d6118821f55c4558'
    expected=json.loads((ROOT/prior).read_bytes())['cohorts']['llvm']['observed']|dict(
        checks=129158736,reaction_cases=895957,reaction_random_draws=1014101,
        reaction_writes=680504,reaction_refusals=2976)
    seal(target='tools/native_reconstruction/native_gameplay_ai_reactions_qualification_v1.json',
        suite='gameplay-ai-reactions',receipt_version=2,status='qualified native AI reaction scheduling',
        expected=expected,extra_sources=['game/native/gameplay_world/world.hpp','game/native/gameplay_update/ai.cpp',
            'game/native/gameplay_update/ai_tests.cpp','game/native/gameplay_update/update.hpp',
            'tools/native_reconstruction/gameplay_update_sources.py','tools/native_reconstruction/effect_work_sources.py',
            'tools/native_reconstruction/qualify_gameplay_ai_reactions_v1.py'],
        binaries=['gameplay_update/gameplay_ai_owner_tests.exe','gameplay_update/libreo_native_gameplay_update.a',
            'gameplay_ai/gameplay_ai_tests.exe','gameplay_ai/libreo_native_gameplay_ai.a',
            'gameplay_ai/CMakeFiles/reo_native_gameplay_ai.dir/reactions.cpp.obj',
            'gameplay_session/libreo_native_gameplay_session.a'],prior=prior,
        additional_evidence=[f'build-native-sjuni/gameplay-ai-reactions-{cc}-v1/receipt.json' for cc in ['llvm','gcc']],
        ports=['107C68 exact two eight-byte zero fills in original-only profile selection surroundings'],
        limitations=[
            'Complete8130D0 and1AEC80 original bodies are audited and executed. Both compilers pass129158736 identical checks,895957 complete reaction comparisons and1014101 identical random draws. Every16-bit initial primary RNG value is compared for each of13 events, followed by all eight authored character columns, full byte-weight maxima/ties, deterministic and out-of-range event paths. Whole actor ranges and surrounding RNG bytes compare.',
            'Thirteen logical policies replace the guest jump/pointer tables. The generator asserts exact owned dispatch and pointer identities before extracting signed duration/reaction/auxiliary and eight character chance columns. Chance comparisons are inclusive and preserve modulo100 and optional second-draw ordering. Current reaction remains unchanged until its separate timer consumer runs.',
            'Unauthored characters8..255 refuse before effects only when a chance column would be needed;2976 native admission checks preserve state/RNG. Deterministic fallback/event12 and out-of-range no-op events need no character chance profile. The source would read adjacent unrelated table data; that adjacency is not invented as authored character behavior.',
            'Actual Owner uses the same Session random owner, checks actor identity/components and preserves RNG on unavailable/deterministic cases. Both parent builds and twelve integration tests pass. The first original-only fixture lacked HI/LO division-result registers; v2 adds them solely to generated test surroundings. No production context or instruction runtime was introduced.',
            'Full observations, reaction timer integration, goal/action dispatch, real construction/control/VM/input/network/save ownership and coherent game installation remain open. V39 remains installed; no game launch or Stage4 completion is claimed.'
        ])
