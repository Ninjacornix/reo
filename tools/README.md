# Developer tools

Keep build tools and regression checks in source control. Their output, captures, and machine-specific experiments belong in ignored build directories.

| Area | Tools |
| --- | --- |
| Dependencies and game build | `setup_deps.ps1`, `iso_extract/`, `elf_analyze/` |
| Recompilation and overlays | `overlay_extract.py`, `overlay_recomp.py`, `extra_recomp.py`, Ghidra export scripts |
| Interactive and smoke runs | `play.ps1`, `smoke_test.ps1` |
| CPU, DMA and scheduling checks | `runtime_selftest/`, `thread_wakeup_check/`, `vif*_check/`, `vu*_check/` |
| Graphics and movie checks | `gs*_check/`, `parallel_gs_check/`, `ipu_selftest/`, `resident_reset_check/` |
| Graphics implementation | `parallel_gs_backend/`, `gpu_backend_bridge/`, `vu_whole_aot/` |
| Read-only diagnostics | `ps2_debug/`, `ext_sampler/`, timing/audio analysis scripts |

Individual check directories describe their requirements. Several use a locally built runtime or GPU backend and are not standalone unit tests. Build against matching headers and libraries; keep game captures local.

`ps2_debug` utilities use PCSX2 PINE for reference captures. They are developer tooling, not a dependency of the native launcher. Private handoffs and agent-specific build scripts are excluded from publication.
