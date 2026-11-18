# Shared native compressed-stream output

One renderer/provider, up to16 exclusive mono/stereo producer lifetimes.
Per-stream retirement preserves peers and the shared device owner. Stereo
copies and render are atomic under one owner mutex; PCM handles remain private.

See the [contract](../../../docs/native-media/ADXT_SHARED_OUTPUT_CONTRACT.md)
and [implementation evidence](../../../docs/native-media/ADXT_SHARED_OUTPUT_IMPLEMENTATION.md).
Build `adxt_output_session_tests` in the standalone native project. `verify.py`
also compiles the actual runtime provider/static-slot binding against reviewed
raylib source functions and model device primitives. No actual audio device
or game is used, and no runtime adapter is installed.
