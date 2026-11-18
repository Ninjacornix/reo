"""Seal the source-identified native observation frame and parent checks."""

import json

from seal_gameplay_component import ROOT, seal, sha


if __name__ == "__main__":
    prior = "tools/native_reconstruction/native_gameplay_ai_descriptor_alias_qualification_v1.json"
    assert sha(ROOT / prior) == "e9546aff4e7a36b9b8d05cd32dce1977977ab199f717a3321a4a1c803dd15196"
    core_receipts = [
        f"build-native-sjuni/gameplay-ai-observer-core-{compiler}-v1/receipt.json"
        for compiler in ("llvm", "gcc")
    ]
    expected_core = json.loads((ROOT / prior).read_bytes())["cohorts"]["llvm"]["observed"]
    for name in core_receipts:
        receipt = json.loads((ROOT / name).read_bytes())
        assert receipt["status"] == "passed" and receipt["source_unchanged"]
        assert receipt["observed"] == expected_core
        for path, expected in receipt["source_sha256"].items():
            assert sha(ROOT / path) == expected
    seal(
        target="tools/native_reconstruction/native_gameplay_ai_observation_frame_qualification_v1.json",
        suite="gameplay-ai-observer",
        status="qualified complete admitted native AI observation frame",
        expected={
            "cases": 4096,
            "checks": 131859,
            "draw_calls": 5402,
            "scene_calls": 3723,
            "wall_calls": 2479,
            "wall_hits": 495,
            "wall_resets": 371,
            "event_calls": 3239,
            "refused_frames": 2,
            "threat_bands": [1311, 885, 900, 1000],
        },
        extra_sources=[
            "docs/native-gameplay/AI_OBSERVATION_FRAME.md",
            "game/native/gameplay_update/CMakeLists.txt",
            "game/native/gameplay_world/inventory.cpp",
            "tools/native_reconstruction/qualify_gameplay_ai_observation_frame_v1.py",
        ],
        binaries=[
            "gameplay_update/gameplay_ai_owner_tests.exe",
            "gameplay_update/libreo_native_gameplay_update.a",
            "gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/ai_observation.cpp.obj",
            "gameplay_ai/gameplay_ai_tests.exe",
            "gameplay_world/gameplay_target_metrics_tests.exe",
            "gameplay_world/owned_resource_recipes_tests.exe",
        ],
        prior=prior,
        limitations=[
            "Ten complete original bodies are audited against owned images and executed within the stated fixture ports.",
            "The single-node navigation fixture and empty scene owner are controlled. The wall check uses real native trace geometry on both sides.",
            "The full 50-entry order row can lack an in-row source sentinel. Native observation refuses that row and unavailable or stale inputs without claiming completed timers.",
            "The native Owner is exercised directly. The outer AI frame caller, remaining goal/action dispatch and coherent native gameplay candidate remain open.",
        ],
        test_count=13,
        receipt_version=8,
        parent_version=1,
        additional_evidence=core_receipts,
    )
