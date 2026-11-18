"""Seal native control payload delivery and reset evidence."""

import json

from seal_gameplay_component import ROOT, seal, sha


if __name__ == "__main__":
    prior = "tools/native_reconstruction/native_gameplay_ai_active_waypoint_qualification_v1.json"
    core = "tools/native_reconstruction/native_gameplay_ai_waypoints_qualification_v1.json"
    previous = json.loads((ROOT / core).read_bytes())["cohorts"]["llvm"]["observed"]
    frame_receipts = [
        f"build-native-sjuni/gameplay-ai-control-update-{compiler}-v2/receipt.json"
        for compiler in ("llvm", "gcc")
    ]
    results = []
    for name in frame_receipts:
        receipt = json.loads((ROOT / name).read_bytes())
        assert receipt["status"] == "passed"
        assert receipt["result"]["cases"] == 2048 and receipt["result"]["phase_cases"] == 4096
        for path, expected in receipt["source_sha256"].items():
            assert sha(ROOT / path) == expected
        results.append(receipt["result"])
    assert results[0] == results[1]

    seal(
        target="tools/native_reconstruction/native_gameplay_ai_control_payloads_qualification_v1.json",
        suite="gameplay-ai-control-payloads",
        status="qualified control payload drain and native frame reset",
        expected=previous | {
            "checks": 451566616,
            "activity_queries": 4086654,
            "control_flush_cases": 516,
            "control_flush_packets": 8576,
            "control_payload_reset_cases": 65,
        },
        extra_sources=[
            "docs/native-gameplay/AI_CONTROL_PAYLOADS.md",
            "game/native/gameplay_update/ai.cpp",
            "game/native/gameplay_update/update.cpp",
            "game/native/gameplay_update/cooperative_events_tests.cpp",
            "tools/native_reconstruction/qualify_ai_control_payloads_v1.py",
        ],
        binaries=[
            "gameplay_ai/gameplay_ai_tests.exe",
            "gameplay_update/gameplay_ai_owner_tests.exe",
            "gameplay_update/gameplay_cooperative_events_tests.exe",
        ],
        prior=prior,
        limitations=[
            "The original drain comparison executes complete 6814E0 in activity-zero mode with a packet-capture port.",
            "The full original reset clears both counts. The canonical native owner currently implements the payload queue and preserves registrations.",
            "The nonzero-activity owner-change lane, live transport, and coherent native gameplay acceptance remain open.",
        ],
        test_count=13,
        parent_version=2,
        additional_evidence=frame_receipts,
    )
