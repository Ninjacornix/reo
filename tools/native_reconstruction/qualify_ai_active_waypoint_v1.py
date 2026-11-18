"""Seal native default active-room waypoint dispatch and composed frame tests."""

from seal_gameplay_component import seal


if __name__ == "__main__":
    seal(
        target="tools/native_reconstruction/native_gameplay_ai_active_waypoint_qualification_v1.json",
        suite="gameplay-ai-active-waypoint",
        status="qualified native default active-room waypoints in the AI frame",
        expected={
            "cases": 4096,
            "checks": 184956,
            "draw_calls": 6332,
            "scene_calls": 4353,
            "wall_calls": 3109,
            "wall_hits": 548,
            "wall_resets": 371,
            "event_calls": 3805,
            "refused_frames": 2,
            "threat_bands": [1311, 885, 900, 1000],
            "ai_frames": 1024,
            "gated_frames": 331,
            "refused_actions": 1,
            "off_room_frames": 100,
            "active_waypoint_frames": 120,
            "waypoint_contacts": 53,
            "waypoint_flags": 47,
        },
        extra_sources=[
            "docs/native-gameplay/AI_ACTIVE_WAYPOINTS.md",
            "game/native/gameplay_update/CMakeLists.txt",
            "tools/native_reconstruction/qualify_ai_active_waypoint_v1.py",
        ],
        binaries=[
            "gameplay_update/gameplay_ai_owner_tests.exe",
            "gameplay_update/libreo_native_gameplay_update.a",
            "gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/ai_waypoints.cpp.obj",
        ],
        prior="tools/native_reconstruction/native_gameplay_ai_waypoints_qualification_v1.json",
        limitations=[
            "The composed reference executes the complete reached action, waypoint, and angular predicate bodies.",
            "The original waypoint tail dispatch retains the original entry address and return link. Heading and ordered wall trace remain explicit qualified ports.",
            "Condition-specific waypoint actions and live scheduling, camera ownership, and game acceptance remain open.",
        ],
        test_count=13,
        receipt_version=2,
        parent_version=1,
    )
