"""Seal native off-room waypoint timing and movement on both compilers."""

import json

from seal_gameplay_component import ROOT, seal, sha


if __name__ == "__main__":
    prior = "tools/native_reconstruction/native_gameplay_ai_off_room_qualification_v1.json"
    previous = json.loads((ROOT / prior).read_bytes())["cohorts"]["llvm"]["observed"]
    frame_receipts = [
        f"build-native-sjuni/gameplay-ai-waypoints-frame-{compiler}-v1/receipt.json"
        for compiler in ("llvm", "gcc")
    ]
    for compiler, name in zip(("llvm", "gcc"), frame_receipts):
        receipt = json.loads((ROOT / name).read_bytes())
        assert receipt["status"] == "passed" and receipt["source_unchanged"]
        prior_frame = ROOT / f"build-native-sjuni/gameplay-ai-off-room-frame-{compiler}-v1/receipt.json"
        assert receipt["observed"] == json.loads(prior_frame.read_bytes())["observed"]
        for path, expected in receipt["source_sha256"].items():
            assert sha(ROOT / path) == expected

    seal(
        target="tools/native_reconstruction/native_gameplay_ai_waypoints_qualification_v1.json",
        suite="gameplay-ai-waypoints",
        status="qualified native ordinary off-room waypoint timing and arrival",
        expected=previous | {
            "checks": 451107390,
            "waypoint_timing_cases": 147456,
            "waypoint_travel_cases": 4096,
        },
        extra_sources=[
            "docs/native-gameplay/AI_OFF_ROOM_WAYPOINTS.md",
            "game/native/gameplay_update/ai.cpp",
            "tools/native_reconstruction/qualify_ai_waypoints_v1.py",
        ],
        binaries=[
            "gameplay_ai/gameplay_ai_tests.exe",
            "gameplay_ai/CMakeFiles/reo_native_gameplay_ai.dir/off_room_travel.cpp.obj",
            "gameplay_update/gameplay_ai_owner_tests.exe",
        ],
        prior=prior,
        limitations=[
            "The original duration, XYZ distance and ordinary waypoint movement bodies execute completely for the compared profiles.",
            "The 4,096 movement cases use a controlled graph with duplicate target edges to verify first-match order.",
            "Six scripted arrival actions, room transitions, live scheduling and game acceptance remain open.",
        ],
        test_count=13,
        additional_evidence=frame_receipts,
    )
