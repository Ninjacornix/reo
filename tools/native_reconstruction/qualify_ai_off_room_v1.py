"""Seal off-room action comparisons and the composed native AI frame."""

import json

from seal_gameplay_component import ROOT, seal, sha


if __name__ == "__main__":
    prior = "tools/native_reconstruction/native_gameplay_ai_frame_qualification_v1.json"
    core = "tools/native_reconstruction/native_gameplay_ai_steering_qualification_v1.json"
    previous = json.loads((ROOT / core).read_bytes())["cohorts"]["llvm"]["observed"]
    previous_frame = json.loads((ROOT / prior).read_bytes())["cohorts"]["llvm"]["observed"]
    frame_receipts = [
        f"build-native-sjuni/gameplay-ai-off-room-frame-{compiler}-v1/receipt.json"
        for compiler in ("llvm", "gcc")
    ]
    for name in frame_receipts:
        receipt = json.loads((ROOT / name).read_bytes())
        assert receipt["status"] == "passed" and receipt["source_unchanged"]
        assert receipt["observed"] == previous_frame | {"checks": 179265, "off_room_frames": 100}
        for path, expected in receipt["source_sha256"].items():
            assert sha(ROOT / path) == expected
    seal(
        target="tools/native_reconstruction/native_gameplay_ai_off_room_qualification_v1.json",
        suite="gameplay-ai-off-room",
        status="qualified native off-room motion synthesis and admitted action dispatch",
        expected=previous | {
            "checks": 450075184,
            "off_room_motion_cases": 196608,
            "off_room_action_cases": 2557,
        },
        extra_sources=[
            "docs/native-gameplay/AI_OFF_ROOM_ACTIONS.md",
            "game/native/gameplay_update/ai.cpp",
            "tools/native_reconstruction/qualify_ai_off_room_v1.py",
        ],
        binaries=[
            "gameplay_ai/gameplay_ai_tests.exe",
            "gameplay_ai/CMakeFiles/reo_native_gameplay_ai.dir/off_room_actions.cpp.obj",
            "gameplay_update/gameplay_ai_owner_tests.exe",
        ],
        prior=prior,
        limitations=[
            "The off-room dispatcher, motion synthesis, reset handler and reached request phases execute in complete original bodies.",
            "Waypoint movement and the initial resource request producers remain unavailable.",
            "The actual native Owner is tested with a controlled World. Live scheduling, installation, and gameplay acceptance are open.",
        ],
        test_count=13,
        additional_evidence=frame_receipts,
    )
