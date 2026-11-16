# Hybrid swap test tools

Tools for building and testing the hybrid native swaps described in
[docs/native-gameplay/HYBRID_INTEGRATION_PLAN.md](../../docs/native-gameplay/HYBRID_INTEGRATION_PLAN.md).
They need your own File #1 ISO import; nothing here contains game data.

## Build a hybrid game

1. Refresh a kit with changed/added sources (`tools/local_build/refresh_inputs.py`),
   using an existing native candidate kit as the seed.
2. Add the native Stage 4 archives and a per-unit define:

   ```
   python tools/hybrid/kit_add_native_archives.py KIT NATIVE_BUILD ARCHIVE_LIST DEFINE UNIT [UNIT ...]
   ```

   `NATIVE_BUILD` is the LLVM build of `game/native` (same llvm-mingw as the game);
   `ARCHIVE_LIST` holds one archive path per line, relative to it. Archives are added
   as `authored-runtime` independent inputs and the kit manifest is resealed.
3. Build with the kit's own `tools/local_build/build_game.py`. When reusing a work
   directory, delete `precompiled-headers/*.pch` first: refreshed sources get new
   timestamps and the old headers are refused.

## Drive a scenario

```
python tools/hybrid/room_driver.py --exe <reo_recomp.exe> --scenario 0..4 --out <new dir> ^
    --data <import>/data --seconds 150 --move-at 8 --explore --env REO_NATIVE_ROOM_CAMERA=shadow
```

- `--env KEY=VALUE` passes switches to the game (the base driver strips `REO_*`).
- `--explore` walks forward, turns and presses cross in 6-second cycles, which
  crosses camera zones and opens doors.
- Screenshots use `PrintWindow` (`window_capture.py`), so covering windows don't
  end up in them.
- Swap counters print to the run's `stderr.log`, every 1,000 calls and at exit.
