# Native movie timestamps

Independent temporal-reference and joined timecode/baseline/latest publication.
The [contract](../../../docs/native-media/MOVIE_TIMESTAMP_CONTRACT.md) specifies
the original clock domain and prepared profile. See the
[results](../../../docs/native-media/MOVIE_TIMESTAMP_RESULTS.md) and
[qualification](qualification.json) for original, native and full short-stream
hardware evidence. Production game selection remains unchanged.

```powershell
python game/native/movie_timestamp/verify.py --cxx <compiler.exe> --output build-native-sjuni/movie-timestamp/<fresh-scope>
python game/native/movie_timestamp/verify_timecode.py --cxx <compiler.exe> --output build-native-sjuni/movie-timecode/<fresh-scope>
```

The original oracles require the owned File #1 ELF and qualified emitted-word
workers; verification checks their frozen receipts and original source hashes.
The native CMake target has no PS2Recomp dependency. A clean native library
receipt for hardware testing can be built with explicit tools:

```powershell
python tools/native_reconstruction/build_media_native.py --compiler <compiler.exe> --cmake <cmake.exe> --ninja <ninja.exe> --manifest game/native/movie_timestamp/manifest.json --build build-native-sjuni/<fresh-build> --output build-native-sjuni/<fresh-receipt-folder>
```

`run_movie_pipeline_gpu.py` takes the sealed kit, exact toolchain, imported data
and this native receipt. It creates no window and opens no audio device. That
fixture's explicit unpaced clock selection is only for finite offline decode/
ownership verification; it does not change the player's movie cadence.
