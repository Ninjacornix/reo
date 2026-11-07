# Native stream-only aggregate composition

`derive.py` checks the frozen aggregate-two identity and mechanically extends it
with an optional render-only native submix. The null-submix profile preserves
the qualified parent observations, including its declared terminal differences.

The new profile adds native stream PCM before the existing bank and master tail
in the same callback. Original PCM producer and post-source reset operations
explicitly refuse. Cold wire reset is admitted before the first native producer
under one serialized controller. General mixed PCM clipping/order and guest reset/control
binding are not implemented. It is not installed by a runtime factory or game
bootstrap. See [results](../../../../docs/native-media/NATIVE_AUDIO_SUBMIX_RESULTS.md).

`verify.py` uses an explicit matching native-build receipt, retained facade
mocks and current audited SDK headers. `compare_parent.py` replays unchanged
original inputs and retains the exact raw reference differences. Both tools
require fresh private output scopes and launch no game/audio device.
