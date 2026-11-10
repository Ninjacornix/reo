"""Seal complete observation admission helpers and actual canonical Owner."""
import json
from seal_gameplay_component import ROOT,seal,sha
if __name__=='__main__':
    prior='tools/native_reconstruction/native_gameplay_ai_reactions_qualification_v1.json'
    assert sha(ROOT/prior)=='b0a7e722620488102da690be32aefe0f88c07bb7632141f42067df916045642b'
    expected=json.loads((ROOT/prior).read_bytes())['cohorts']['llvm']['observed']|dict(
        checks=400434754,observation_blocked_cases=278784,observation_gate_cases=2887680,
        observation_gate_random_draws=2363390,observation_gate_admitted=1714691,observation_gate_refusals=499)
    seal(target='tools/native_reconstruction/native_gameplay_ai_observation_gates_qualification_v1.json',
        suite='gameplay-ai-observation-gates',status='qualified complete native AI observation admission helpers',
        expected=expected,extra_sources=['game/native/gameplay_world/world.hpp','game/native/gameplay_update/ai.cpp',
            'game/native/gameplay_update/ai_tests.cpp','game/native/gameplay_update/update.hpp',
            'tools/native_reconstruction/gameplay_update_sources.py','tools/native_reconstruction/effect_work_sources.py',
            'tools/native_reconstruction/qualify_gameplay_ai_observation_gates_v1.py'],
        binaries=['gameplay_update/gameplay_ai_owner_tests.exe','gameplay_update/libreo_native_gameplay_update.a',
            'gameplay_ai/gameplay_ai_tests.exe','gameplay_ai/libreo_native_gameplay_ai.a',
            'gameplay_ai/CMakeFiles/reo_native_gameplay_ai.dir/observation_gates.cpp.obj',
            'gameplay_session/libreo_native_gameplay_session.a'],prior=prior,
        ports=['107C68 exact two eight-byte zero fills in original-only profile selection surroundings'],
        limitations=[
            'Complete812EF0/813BD0 bodies are audited against owned binaries and executed. Both compilers pass400434754 identical checks with2887680 admission comparisons,2363390 identical RNG draws,278784 blocked-state predicate comparisons and499 separate native refusals. Earlier goal/control/reaction counts retain their qualified values.',
            'The eight authored normal/room chance columns and exact FP32 multipliers are generated from owned immutable o9 bytes. Source multiply order and bounded toward-zero conversion are preserved. Original-only CVT.W.S uses the frozen current dependency conversion header, not a private build folder or invented cast profile; production uses bounded finite C++ conversion and no guest context.',
            'Direct probability checks read both canonical weight-mode bytes. Nonzero modes first apply room/memo and room-gate suppression, need no reference, and write the existing room_memo only on a failed probability decision. Zero RNG output rejects even if remainder0 would pass the inclusive threshold. Deterministic100-percent branches consume no RNG. Character profiles8..255 are unavailable only after earlier independent no-op gates.',
            'All65536 initial RNG states are compared for all eight character columns and four scaling combinations plus room mode. All65536 room values compare equal/unequal memo and zero/nonzero gates. Full byte mode values, actor aliasing, surrounding actor preservation and actual Session RNG ownership are checked. Twelve current parent tests pass per compiler.',
            'These complete helpers do not implement the entire812540 observation consumer or6D6240 target-cache producer. Required cache/model/collision owners, remaining goal/action dispatch, construction/control/VM/input/network/save ownership and coherent native gameplay installation remain open. Installed V39 is unchanged; no game launch or Stage4 completion is claimed.'
        ])
