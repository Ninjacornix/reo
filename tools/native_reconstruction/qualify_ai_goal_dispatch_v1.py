"""Seal native direct AI goal dispatch evidence on both compilers."""

import json

from seal_gameplay_component import ROOT, seal


if __name__ == "__main__":
    prior = "tools/native_reconstruction/native_gameplay_ai_observation_frame_qualification_v1.json"
    descriptor_evidence = "tools/native_reconstruction/native_gameplay_ai_descriptor_alias_qualification_v1.json"
    previous = json.loads((ROOT / descriptor_evidence).read_bytes())["cohorts"]["llvm"]["observed"]
    seal(
        target="tools/native_reconstruction/native_gameplay_ai_goal_dispatch_qualification_v1.json",
        suite="gameplay-ai-goal-dispatch",
        status="qualified native dispatcher for direct goal callbacks 0, 6 and 14",
        expected=previous | {
            "checks": 407323740,
            "goal_dispatch_cases": 131841,
            "goal_dispatch_refusals": 14,
        },
        extra_sources=[
            "docs/native-gameplay/AI_GOAL_DISPATCH.md",
            "game/native/gameplay_update/ai.cpp",
            "game/native/gameplay_update/ai_tests.cpp",
            "game/native/gameplay_update/update.hpp",
            "tools/native_reconstruction/qualify_ai_goal_dispatch_v1.py",
        ],
        binaries=[
            "gameplay_ai/gameplay_ai_tests.exe",
            "gameplay_ai/CMakeFiles/reo_native_gameplay_ai.dir/priority_goals.cpp.obj",
            "gameplay_update/gameplay_ai_owner_tests.exe",
        ],
        prior=prior,
        limitations=[
            "Complete 813330 and callbacks 813DE0, 814B30 and 815820 are executed.",
            "None of the three admitted callbacks requests immediate redispatch. Other callback families and the live actor update caller are open.",
        ],
        test_count=13,
    )
