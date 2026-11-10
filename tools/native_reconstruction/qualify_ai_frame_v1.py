"""Seal the composed native AI frame on both compilers."""

from seal_gameplay_component import seal


if __name__ == "__main__":
    seal(
        target="tools/native_reconstruction/native_gameplay_ai_frame_qualification_v1.json",
        suite="gameplay-ai-frame",
        status="qualified native AI frame for gated and admitted active-room profiles",
        expected={
            "cases": 4096,
            "checks": 174145,
            "draw_calls": 6332,
            "scene_calls": 4353,
            "wall_calls": 3109,
            "wall_hits": 495,
            "wall_resets": 371,
            "event_calls": 3805,
            "refused_frames": 2,
            "threat_bands": [1311, 885, 900, 1000],
            "ai_frames": 1024,
            "gated_frames": 331,
            "refused_actions": 1,
        },
        extra_sources=[
            "docs/native-gameplay/AI_FRAME.md",
            "game/native/gameplay_update/CMakeLists.txt",
            "tools/native_reconstruction/qualify_ai_frame_v1.py",
        ],
        binaries=[
            "gameplay_update/gameplay_ai_owner_tests.exe",
            "gameplay_update/libreo_native_gameplay_update.a",
            "gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/ai.cpp.obj",
        ],
        prior="tools/native_reconstruction/native_gameplay_ai_steering_qualification_v1.json",
        limitations=[
            "The complete 812460 entry executes across all combinations of five gates and admitted goal and action paths. The fixture declares its shared geometry and math ports.",
            "The live session update gate producer, remaining callbacks, game scheduler integration and acceptance remain open.",
        ],
        test_count=13,
        receipt_version=2,
        parent_version=1,
    )
