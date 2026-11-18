"""Seal complete admitted actor AI initialization and actual native Owner."""
import json
from seal_gameplay_component import ROOT,seal,sha


if __name__=='__main__':
    prior='tools/native_reconstruction/native_gameplay_activity_qualification_v1.json'
    assert sha(ROOT/prior)=='13cd9682d4a0a209b1ef341c63e9208ead14d33385725f51473e93dcb236f61f'
    expected=json.loads((ROOT/prior).read_bytes())['cohorts']['llvm']['observed']|dict(
        checks=80542165,copies=2068,clears=4136,initialization_cases=3072,
        initialization_disabled=1024,initialization_limited=1024,initialization_refusals=3)
    failed=[f'build-native-sjuni/gameplay-ai-initialize-{cc}-v1/receipt.json' for cc in ['llvm','gcc']]
    assert all(json.loads((ROOT/name).read_bytes())['status']=='failed' for name in failed)
    seal(target='tools/native_reconstruction/native_gameplay_ai_initialize_qualification_v1.json',
        suite='gameplay-ai-initialize',receipt_version=2,status='qualified complete admitted native actor AI initialization',
        expected=expected,extra_sources=['game/native/CMakeLists.txt','game/native/gameplay_world/world.hpp',
            'game/native/gameplay_world/world.cpp','game/native/gameplay_actors/entity.cpp',
            'game/native/gameplay_update/ai.cpp','game/native/gameplay_update/ai_tests.cpp',
            'game/native/gameplay_update/update.hpp','game/native/gameplay_update/CMakeLists.txt',
            'tools/native_reconstruction/gameplay_update_sources.py','tools/native_reconstruction/effect_work_sources.py',
            'tools/native_reconstruction/qualify_gameplay_ai_initialize_v1.py'],
        binaries=['gameplay_update/gameplay_ai_owner_tests.exe','gameplay_update/libreo_native_gameplay_update.a',
            'gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/ai.cpp.obj',
            'gameplay_ai/gameplay_ai_tests.exe','gameplay_ai/libreo_native_gameplay_ai.a',
            'gameplay_ai/CMakeFiles/reo_native_gameplay_ai.dir/initialization.cpp.obj',
            'gameplay_navigation/libreo_native_gameplay_navigation.a',
            'gameplay_navigation/CMakeFiles/reo_native_gameplay_navigation.dir/bank.cpp.obj'],
        prior=prior,additional_evidence=failed,
        ports=['107C68 exact two eight-byte zero fills in original-only profile selection surroundings'],
        limitations=[
            'Both compilers pass80542165 identical checks with3072 complete8120C0 comparisons. All256 actor slots, AI-control0/1/255 and four registration/queue profiles compare complete actor, shared control table/pending bytes and header effects.1024 disabled profiles change only the header;1024 enabled profiles retain source full-registration/full-request behavior while completing subsequent initialization. All previous AI/control/activity comparisons retain their counts.',
            'The loaded native Bank owns the mutable first header byte once, separate from immutable SGL import provenance. A different admitted asset starts byte24; same-asset rebinding preserves the runtime byte. Initialization clears it unconditionally, including when AI is disabled or the Bank is unbound. Its broader semantic role remains unnamed; no shared immutable Asset is corrupted or duplicated mutable navigation bank introduced.',
            'Enabled initialization registers control0/actor-slot, publishes the exact initial four-byte value, sets the canonical route selection/refresh bytes, initializes execution/reaction/counter/memo/forced-priority fields, then calls the actual goal/action/profile primitives. Previous goal/action derive from their real old fields, and combined weights/current route/other actor fields remain unchanged. Capacity results are diagnostics, not a reason to skip the source subsequent resets.',
            'Missing enabled execution/route components refuse after the known header clear and before further admitted effects; they are not constructed with guessed prior state. Disabled AI needs neither component. A closed Bank refuses. These are native capability/lifetime admission boundaries, not matching original null-object or invalid-pointer cases. Real actor construction/import remains required.',
            'Both current parent builds and twelve integration tests pass. Actual Owner checks unconditional disabled clear, missing state, canonical previous/current IDs and route fields, same Session control queue, repeat initialization, full-queue completion and retirement/closure. v1 failed compilation because the fixture supplied a cost member to the cost-free RouteProjection. v2 corrects the fixture type without changing production behavior; failed evidence remains.',
            'Real actor/component construction, mode producers, outgoing control service/reset, full observations/goal/action dispatch, remaining stock VM/input/network/save ownership and coherent native gameplay installation remain open. Installed V39 is unchanged; no game launch, recorded slowdown fix or Stage4 completion is claimed.'
        ])
