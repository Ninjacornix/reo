# Superseded focused patches

These earlier patches are retained as change history:

- `0093-async-owned-vif1-worker.patch`
- `0094-host-window-fullscreen-and-close-shortcuts.patch`
- `0095-wake-resource-waits-on-thread-termination.patch`

Their authored changes are included in the current
`../ps2recomp/0093-native-runtime-and-host-integration.patch`. Do not apply these
again after the current series. `tools/setup_deps.ps1` intentionally reads only
the active `ps2recomp/` directory. This consolidation preserves the active local
runtime and the pinned upstream submodule revision.
