# Native ADXT attenuation

An immutable injected 1,000-word table converts the original signed-halfword
volume request plus eligible AINF metadata into the existing raw integer PCM
volume. No floating point curve, pitch change or guest ownership is inferred.

See [contract and comparison scope](../../../docs/native-media/ADXT_ATTENUATION_CONTRACT.md).
`verify.py` consumes the frozen original instruction observations and explicit
compiler, creates fresh private output and retains three detected mutations.
Player/game bindings remain separate.
