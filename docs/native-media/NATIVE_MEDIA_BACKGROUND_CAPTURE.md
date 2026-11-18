# Background compositor validation

The explicit native-media diagnostic now has two window startup modes. Value
`1` remains minimized. Value `2` creates the window hidden, then shows it at the
bottom of the window stack using `SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE |
SWP_SHOWWINDOW`. This preserves its geometry and keeps other applications in
front while allowing Windows Graphics Capture to observe the game's surface.
It does not capture the desktop or install a keyboard hook.

The launcher checks `REO_NATIVE_MEDIA_BACKGROUND_CAPTURE_V1` before requesting
mode two, and the harness requires the actual native startup handshake. Both
background modes bypass the launcher's ordinary window placement task. That
task otherwise calls SetWindowPos without NOACTIVATE; it must not run in a
background diagnostic. Normal player launch placement remains unchanged.

An owned synthetic 320x240 raylib window, linked against the actual pinned
library, validates this startup sequence. The window stays behind other apps;
the Windows capture API returns a 322x279 image including its frame, with the
expected magenta background and green inset. Both helpers report unchanged
foreground identity and no focus request. No game or audio device is opened.
Source is `tools/native_reconstruction/background_capture_probe.cpp`; evidence
is `build-native-sjuni/background-window-capture-probe-v1/receipt.json`, with its
qualification beside the source.

This proves the controlled capture mechanism, not the game's final pixels or
A/V phase. The native game run must bind the actual process identity, compare
its compositor images with native media evidence and retain capture timestamps.
Process-loopback audio and game-frame handoff already have a separate digital
timing comparison; physical speaker/display latency is not inferred from those
ports alone. The feature is a developer test mode, not a default player setting.
