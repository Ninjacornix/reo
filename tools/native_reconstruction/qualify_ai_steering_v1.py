"""Seal active-room AI action and steering comparisons on both compilers."""

import json

from seal_gameplay_component import ROOT, seal, sha


if __name__ == "__main__":
    prior = "tools/native_reconstruction/native_gameplay_ai_goal_dispatch_qualification_v1.json"
    previous = json.loads((ROOT / prior).read_bytes())["cohorts"]["llvm"]["observed"]
    navigation_receipts = [
        f"build-native-sjuni/gameplay-ai-steering-nav-{compiler}-v1/receipt.json"
        for compiler in ("llvm", "gcc")
    ]
    navigation_results = []
    for name in navigation_receipts:
        receipt = json.loads((ROOT / name).read_bytes())
        assert receipt["status"] == "passed" and receipt["source_unchanged"]
        assert receipt["observed"]["destination_cases"] == 15884
        for path, expected in receipt["source_sha256"].items():
            assert sha(ROOT / path) == expected
        navigation_results.append(receipt["observed"])
    assert navigation_results[0] == navigation_results[1]

    seal(
        target="tools/native_reconstruction/native_gameplay_ai_steering_qualification_v1.json",
        suite="gameplay-ai-steering",
        status="qualified native steering and active-room action callbacks 0 and 1",
        expected=previous | {
            "checks": 436930288,
            "steering_cases": 393220,
            "active_room_action_cases": 65542,
        },
        extra_sources=[
            "docs/native-gameplay/AI_STEERING.md",
            "game/native/gameplay_navigation/destination.cpp",
            "game/native/gameplay_update/ai.cpp",
            "game/native/gameplay_update/ai_tests.cpp",
            "game/native/gameplay_update/update.hpp",
            "tools/native_reconstruction/gameplay_update_sources.py",
            "tools/native_reconstruction/qualify_ai_steering_v1.py",
        ],
        binaries=[
            "gameplay_ai/gameplay_ai_tests.exe",
            "gameplay_ai/CMakeFiles/reo_native_gameplay_ai.dir/steering.cpp.obj",
            "gameplay_update/gameplay_ai_owner_tests.exe",
            "gameplay_update/gameplay_navigation_owner_tests.exe",
        ],
        prior=prior,
        limitations=[
            "Complete 81BB80, 81A720, 81A770 and 81A780 execute in the reference. The heading child calls are declared ports.",
            "The current navigation regression executes the complete 370140 heading chain against the shared native implementation.",
            "Actual camera and session gate providers, the remaining action callbacks and game acceptance are open.",
        ],
        test_count=13,
        additional_evidence=navigation_receipts,
    )
