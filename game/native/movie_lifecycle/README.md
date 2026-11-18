# Prepared native movie lifecycle

`Policy` preserves the owned original constructor/start/stop/rebuild/destroy
decisions and callback ordering. `Session` separately owns physical generations;
`PreparedGraph` composes native positioned source reads, an optional native ADX
audio stream, the shared timing Context and a video backend. The same-device
`NativeVideoGraph` adapter joins the existing MPEG parser and hardware decoder.

See the [contract](../../../docs/native-media/MOVIE_LIFECYCLE_CONTRACT.md),
[results](../../../docs/native-media/MOVIE_LIFECYCLE_RESULTS.md) and
[qualification](qualification.json). These distinguish original policy ports,
actual native ownership checks, hardware first-frame checks and remaining game
integration. No production selection, audible A/V validation or whole-movie
playback claim is made.

The original oracle freezes construction/stop/rebuild workflows before the native
policy exists. Both original cohorts agree on 176 cases/179 operations. Run the
native comparison and eight fault controls with an exact compiler and fresh scope:

```powershell
python game/native/movie_lifecycle/verify.py --cxx <compiler.exe> --output build-native-sjuni/movie-lifecycle/<fresh-scope>
```

The module can be configured independently with CMake or through `game/native`.
The `movie_lifecycle` CTest covers partial construction, blocked reads, GPU fence
models, native audio stream retirement, reentry, ownership and rebuild. Its audio
provider is a model. Raw original transcripts, build logs and GPU receipts remain
under ignored `build-native-sjuni/movie-lifecycle/`.

The offscreen hardware fixture takes explicit sealed build inputs, the imported
owned data and a source/compiler/library-identified native build receipt:

```powershell
python tools/native_reconstruction/run_movie_lifecycle_gpu.py --kit <sealed-kit> --toolchain <exact-toolchain-root> --data <imported-data-directory> --native-receipt <native-build-receipt.json> --output build-native-sjuni/movie-lifecycle/<fresh-gpu-scope>
```

It does not construct a window, launch the game, open audio, mutate dependencies
or use unverified private headers. Native picture timestamp reconstruction,
Sofdec audio PES routing and the logical/physical scheduler adapter remain gates
before representative whole-movie playback can be validated.
