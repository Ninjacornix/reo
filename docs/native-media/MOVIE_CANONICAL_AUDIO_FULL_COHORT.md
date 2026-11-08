# Complete native cohort after the canonical movie audio extension

Both the pinned LLVM toolchain and GCC build the complete current native project
and pass all **78 standalone suites**. This supersedes the earlier checkpoint's
explicit limitation that only changed production units and focused regressions
had been rebuilt. All class consumers now share the same current headers.

The source manifest is
`tools/native_reconstruction/native_movie_capability_manifest_v1.json` (292
inputs, SHA-256 `06676ae214796a4bd2eb4a97f366f81b34430e7a4117237cf43571d19f1cfdd7`).
The build receipts retain the actual compiler/CMake/Ninja identities, commands,
complete test logs and hashes for every produced archive:

- `build-native-sjuni/movie-instance-audio/native-llvm-v1/receipt.json`
- `build-native-sjuni/movie-instance-audio/native-gcc-v1/receipt.json`

The runs include the canonical source capability and existing ownership,
lifecycle, decoder, source, control, queue, output and resource suites. Their
hardware/device ports remain standalone test models. No game or physical audio
device was launched by this cohort build. These checks do not qualify actual
movie runtime acquisition, paced GPU playback, audible A/V or the cinematic hitch.

The accompanying ordinary-adapter qualification uses these matching new
archives. It passes 21 declared-port scenarios, detects eight compiled faults at
runtime and compiles five units against the audited SDK130 headers in each
compiler cohort. See [V20's order boundary](ADXT_CANDIDATE_V20_ORDER.md) for what
the bounded correction admits and what remains required.
