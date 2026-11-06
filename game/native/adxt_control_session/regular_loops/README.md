# Regular file-loop owner qualification

The actual control session and phased player now admit the bounded regular-loop
profile. Read the [contract](../../../../docs/native-media/ADXT_REGULAR_LOOP_PLAYER_CONTRACT.md)
and [implementation evidence](../../../../docs/native-media/ADXT_REGULAR_LOOP_PLAYER_IMPLEMENTATION.md).
This is not a seamless/LSC implementation or a selected game backend.

The manifest pins tested sources. The qualification retains both full imported
loop runs, independent earlier decoder cycle comparisons, finite regression,
clock/control negatives, PCM/R3 storage evidence and full parent tests.

`tools/native_reconstruction/verify_imported_adxt_loop_player.py` takes the
installed File1 `--data-root`, exact `--cxx` and a fresh scoped `--output`.
Its derived verification-only observer measures accepted PCM copies; no ISO or
real device is used. `compare_imported_adxt_loop_player_runs.py` compares full
runs while explicitly retaining differing scheduling and later-prefix fields.
