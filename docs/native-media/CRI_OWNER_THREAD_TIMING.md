# CRI dispatch timing without background context sampling

The V13 late cinematic hitch coincides with long scheduler ownership by guest
thread six, the CRI group-four worker. Its full child/step timing was disabled
in that run. The existing observer can time those original calls and their
SifInitRpc/SifCallRpc boundaries on the dispatching owner.

Before using that observer for the next test, its background PC sampler was
removed. It read a plain, concurrently written `R5900Context::pc` through volatile
and ran an infinite detached thread. Neither volatile nor its registration mutex
made the guest's ordinary PC writes atomic. The current observer creates no
sampler thread, retains no context pointer for another thread and explicitly
reports `pc_samples=unavailable` rather than an invented zero-sample result.

The original dispatcher, file/audio steps, RPC bodies and marker calls remain
delegated exactly once. Existing timing, callback/marker identity and bounded
slow-report output remain opt-in through `REO_CRI_SERVER_SLOW_MS`. Elapsed time
minus scheduler-acquire wait remains an approximation: host blocking and
descheduling are not distinguished from CPU work. These observations do not
by themselves prove a function's bottleneck or a root cause.

Both compiler fixtures compile the actual observer header against declared
runtime/guest ports and check unchanged delegated call sequences/results,
scoped file-step markers, RPC counts, unadmitted groups and movie-part timing.
They launch no game, audio device or sampling thread. This is observer delegation
evidence; a linked candidate and actual late-cinematic retest are still needed.

| Receipt below `build-native-sjuni` | SHA-256 |
| --- | --- |
| `cri-timer/qualified-llvm-v1/receipt.json` | `35e5a5df4bc181fb1e3ffd34b345d4b6ffbf2b4bf21b425f0c3552f35a109ce9` |
| `cri-timer/qualified-gcc-v1/receipt.json` | `bbcb4d040823b4c065f118d8d6e702e0794a2af01acc35a03a162f6efdb4a48f` |
