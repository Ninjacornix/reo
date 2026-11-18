"""Seal complete activity-mode query chain through the canonical Session."""
from seal_gameplay_component import seal


if __name__=='__main__':
    seal(target='tools/native_reconstruction/native_gameplay_activity_qualification_v1.json',
        suite='gameplay-ai-activity',status='qualified complete native activity-mode query and control binding',
        expected=dict(checks=75155916,goal_cases=131072,action_cases=131072,phase_cases=256,
            finish_cases=65536,profile_cases=256,profile_refusals=4,copies=20,clears=40,
            control_membership_cases=64,control_register_cases=152,control_unregister_cases=44,
            control_lookup_cases=18432,control_request_cases=18432,control_publish_cases=66,
            control_apply_cases=4096,control_receive_cases=64516,control_receive_refusals=1020,
            activity_queries=4086138,activity_mode_cases=65536,activity_mode_refusals=2),
        extra_sources=['game/native/CMakeLists.txt','game/native/gameplay_world/world.hpp',
            'game/native/gameplay_world/world.cpp','game/native/gameplay_actors/entity.cpp',
            'game/native/gameplay_update/ai.cpp','game/native/gameplay_update/ai_tests.cpp',
            'game/native/gameplay_update/update.hpp','game/native/gameplay_update/CMakeLists.txt',
            'tools/native_reconstruction/gameplay_update_sources.py','tools/native_reconstruction/effect_work_sources.py',
            'tools/native_reconstruction/qualify_gameplay_activity_v1.py'],
        binaries=['gameplay_update/gameplay_ai_owner_tests.exe','gameplay_update/libreo_native_gameplay_update.a',
            'gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/ai.cpp.obj',
            'gameplay_ai/gameplay_ai_tests.exe','gameplay_ai/libreo_native_gameplay_ai.a',
            'gameplay_session/libreo_native_gameplay_session.a',
            'gameplay_session/CMakeFiles/reo_native_gameplay_session.dir/activity.cpp.obj'],
        prior='tools/native_reconstruction/native_gameplay_ai_receive_qualification_v1.json',
        ports=['107C68 exact two eight-byte zero fills in original-only profile selection surroundings'],
        limitations=[
            'Both compilers pass75155916 identical checks. Complete1AFE70,1B0300, o9 811770 and o8 810F30 execute4086138 times across receive tests and65536 explicit mode queries. The original1AFE70 return port is removed. All256 main-mode bytes and all signed-byte values are compared. Two unknown required native mode facts refuse; other modes return1 without consuming either optional fact.',
            'Canonical Session.activity owns the distinct optional single/online mode facts. Main mode is the existing Session.mode/World.mode alias. Native Owner now derives receive policy from this shared query instead of accepting an external scalar. Actual initialization/network writers remain open; unknown native facts are never silently zeroed.',
            'Both current parent builds and twelve integration tests pass. Actual Owner checks canonical single/online selection, signed returns, constant fallback, unknown-dependent versus independent receive paths and closure. All previous goal/action/control producer/receiver comparison counts remain unchanged.',
            'The merged generated1B0300 source also contains neighboring main entries. Its complete file is word-audited and retained, but only1B0300 is entered or claimed in this query chain. The only remaining declared port is the earlier exact eight-byte clear in profile selection; no activity-mode or packet-handler success double is used.',
            'Real mode initialization/network producers, outgoing control service/reset, complete AI initialization/observations/dispatch, semantic native saves and coherent native gameplay installation/acceptance remain open. Installed V39 and original game speed remain unchanged; no game or performance test occurred.'
        ])
