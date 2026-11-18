# Native media background close investigation

2026-11-09. Step 3 remains incomplete. The user is at the PC and requires
background tests without activation, restoration or desktop capture.

V32 (`d73c8233`, executable SHA-256
`973543320c9b63c61bd1195e787505e578fd9ca73f481c660f704ab61faae1ff`)
passes the full opening/scenario/bar route and joined shutdown. It accepts zero
queued preparations on that route. Its 81.8439 ms opening publication gap is
retained; zero recorded audio underruns does not mean stutter-free playback.
See `tools/native_reconstruction/host_movie_v32_cue_qualification.json`.

Two subsequent background main-menu cases require forced termination after
the normal close grace period. The second has no capture or sampling calls.
Their hashed evidence is in `host_movie_v32_background_close_failure.json` and
`host_movie_v32_background_short_close_failure.json` beside the qualification.
A third main-menu case, session `20261109-014458-947`, exits normally after
91.9754845 seconds, including native audio, cue and movie worker retirement.
The hang is intermittent. Missing retirement reports do not identify a blocked
worker: the window loop may never have recognized Close.

Source and the actual sealed raylib archive agree on a concrete defect.
`PollInputEvents` waits in `glfwWaitEvents` while minimized unless
`FLAG_WINDOW_ALWAYS_RUN` is set. GLFW receives WM_CLOSE, but raylib copies the
close flag only after leaving that minimized loop. The exact archive SHA-256 is
`bd5ba7baf25e93ac68ec92fa70d72321750e80b4ef2188637ee9240af4319c3c`.
This mechanism is established independently of the game's intermittent hang;
no successful game stack sample yet attributes either failed run to it.

`verify_minimized_window_close.py` links `minimized_window_close.cpp` against
the sealed game's archive and headers. It creates only a small hidden probe,
shows it minimized without activation, and posts WM_CLOSE after 500 ms. The
baseline times out; configuring ALWAYS_RUN before initialization observes
Close and exits while still minimized. The receipt is
`build-native-sjuni/minimized-close-regression-v2/receipt.json`. Both runs request
no focus; the successful run also records unchanged foreground identity.
No game or audio device is involved. The timed-out synthetic child is joined.

The candidate changes only native-media window initialization: set ALWAYS_RUN
before creating the window. Existing runtime vblank pacing is retained. No
fullscreen setter, game clock, VU or rendering selection is changed. The public
raylib API uses the existing matching library; no dependency patch is required.
An explicit developer-only `REO_NATIVE_MEDIA_BACKGROUND_TEST=1` creates the
test window hidden and then minimized with SW_SHOWMINNOACTIVE. The launcher
fixture checks `REO_NATIVE_MEDIA_BACKGROUND_TEST_V1` in the selected executable
before using it, so older builds cannot silently activate a supposed background
test. Actual candidate game rebuild and minimized retirement retest remain.

The first private PSS helper failed its process-liveness check because its
process handle lacked SYNCHRONIZE access. Its stderr and failed receipt are
preserved in the third session. That failure is not a captured game stack.
The later scheduled sample did not run because that game exited normally first.
The helper is not part of player diagnostics. DXGI's indefinite latency/fence
waits remain alternative candidates until runtime evidence distinguishes them;
changing the frame-count allowance to UINT_MAX would not create a timeout.
