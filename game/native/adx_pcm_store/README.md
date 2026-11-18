# ADX PCM storage and credits

Independent, serialized two-plane PCM storage for future Window2. See the
[contract](../../../docs/native-media/ADX_PCM_STORE_CONTRACT.md) and
[implementation evidence](../../../docs/native-media/ADX_PCM_STORE_IMPLEMENTATION.md).

`Store` owns real SJRB rings, explicit producer/consumer tokens and fixed staging.
Raw padding, corrected production and publication are distinct values.
Destructors return no credit. Stop retains drainable PCM; retire requires an
empty, sound ledger. No guest/runtime/device dependencies.

Standalone CMake builds `adx_pcm_store_tests`. `verify.py --cxx <compiler>
--output <fresh-build-native-sjuni/adx-pcm-store/path>` adds private partial-effect,
ID-exhaustion and negative controls. `original_projection.py` freezes storage-only
inputs; `compare_original.py` compares backing bytes and accounting. The
projection supplies original decoded PCM as input; it does not test a codec or
establish complete Window2 equivalence.
