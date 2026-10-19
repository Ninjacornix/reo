Build the Release PS2Recomp runtime, then run:

```bat
tools\gs_dispatch_pace_check\run.bat [PS2Recomp-build-dir]
```

This focused fixture enables dispatcher pacing and a private GS execution gate. The main guest submits through an actual DMA callback under the MMIO mutex; another guest submits graphics too. Both producers must wait at dispatcher boundaries while a real VBlank handler reads MMIO and an unrelated guest progresses. After gate release, independent framebuffer color assertions verify ordered pixels and both producer continuations. Three runtime sessions cover normal release, cancellation while blocked, and reinitialization without stale debt.

Coordinator result: all three sessions pass with zero failures against the Release runtime including0063/0064. See ignored build-ninja/m2-dispatch-pacing-validation.log. This verifies scheduling, ordering and teardown; native music and performance acceptance remain separate. Never enable REO_GS_DISPATCH_PACE_TEST_GATE in a game run.

The expanded runner also invokes mode2 in a separate process. Three more sessions verify recursive Store8 DMA callback suppression and in-place waiting from a nested callee at its exact entry PC, with the same progress/FIFO/stop/restart checks. Coordinator result: both modes pass, zero failures (build-ninja/m2-backedge-pacing-validation.log). Native results remain separate.
