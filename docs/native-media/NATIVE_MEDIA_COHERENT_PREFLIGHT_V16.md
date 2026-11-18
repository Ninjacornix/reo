# V16 coherent production compilation

The separate V16 preflight passes all **182 authored/runtime compilation
units** with the bundled LLVM toolchain. The prepared source comes from local
commit `885c67f66d76c526bc451f895c5072d69dea86bd`, the exact sealed stock-input
carrier, and the audited 130-patch dependency reconstruction. It excludes dirty
workspace sources and uses no precompiled PS2 runtime.

This checks the expanded complete audio dependency set in the actual production
build plan, including the canonical source/session/controller, original table
attenuation, the explicit source factory and its RAM/output composition. Shared
resource-view translation units appear once. Every C++ unit uses the coordinated
sound-RAM instrumentation cohort.

The source kit SHA-256 is
`a4598294513fab6edcee293881ac2763c6b0d13bc95fdd0fee84ab545c772a3b`.
Exact compiler, sysroot, dependency, source-delta and log identities are retained
in `build-native-sjuni/candidate-work-v16-preflight/candidate-preflight-result.json`
and `tools/native_reconstruction/media_preflight_v16_qualification.json`.

This is compilation, not a linked executable or a game run. The existing
bootstrap still selects the earlier audio factory; the new compressed native
source route has no installed guest ABI hooks. The later game-handle router is
also outside this frozen V16 kit. Actual source/control/reset/callback binding,
movie scheduling/providers and coherent live A/V transitions remain required.
This preflight does not establish a stutter fix or close Step 3.
