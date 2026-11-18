# Ready enable correction r1

Build target `reo_native_stream_window_v2_ready_flag_r1` implements the existing
`v2::StreamWindowOwner` with the corrected signed enable-flag predicate. It is
mutually exclusive with the frozen implementation in a linked executable.

See [correction and evidence](../../../../../docs/native-media/ADX_READY_FLAG_IMPLEMENTATION.md).
The private Source2 link and all dependency freezes remain unchanged. No game
adapter or full-player behavior is enabled by this independent target.
