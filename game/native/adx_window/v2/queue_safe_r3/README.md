# Queue-safe native decode window R3

This links the same concrete Window2/R2 header with a separate request scheduler.
Link exactly one window implementation into an executable. The phased player
selects R3; historical R2 tests and owners retain R2.

Before codec effects, R3 sizes whole ADPCM groups against the actual PCM lease's
pure admission query. Queued and held PCM remain protected. All other algorithms
are mechanically compared to R2 by `verify.py`.

See [contract](../../../../../docs/native-media/ADX_QUEUE_SAFE_WINDOW_CONTRACT.md),
[validation](../../../../../docs/native-media/ADXT_REGULAR_LOOP_PLAYER_IMPLEMENTATION.md)
and `qualification.json`. Model checks do not open the game or a real device.

Run the standalone qualifier with an exact compiler and a fresh scoped output:

```powershell
python game/native/adx_window/v2/queue_safe_r3/verify.py --cxx C:/msys64/mingw64/bin/g++.exe --output build-native-sjuni/adx-queue-safe-window/new-gcc-run
```
