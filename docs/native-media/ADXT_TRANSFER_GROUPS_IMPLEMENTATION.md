# Native transfer group dispatch evidence

The complete outer audio/transfer dispatch envelopes now match **128 frozen
original cases**, using **82,740 original instructions**, under GCC15.2 and
bundled LLVM21.1.8. This includes both original DTX scans. **Stage3 remains open**:
the individual transfer protocols and actual phased native players are separate
integration obligations. No game ran and no audio device opened.

The [contract](ADXT_TRANSFER_GROUPS_CONTRACT.md) adds original `1389D8`,
`139568` and `141268` to the previously qualified audio dispatch. Actual owned
words execute32 DTR visits and two8-slot DTX scans. Only per-slot decoder,
controller, file-tail, RNA, DTR and DTX children remain external. The original
inputs were frozen before the new native implementation existed.

The added cases cover every DTR/DTX index, signed activity admission, later-slot
activation, DTR-to-DTX membership changes, DTX activating an earlier slot for the
second scan, retirement between scans and DTX changes to DTR after its pass.
They retain all previous audio dispatch cases and actual busy reentry execution.
Every child/guard event, shared service phase, all three guard depths and all
five final activity tables match. There is no frame-count or completion hook.

Native tests also prove34 ownership/lifetime assertions, including retained
current work after its own entry is cleared, shared DTX state across both scans,
independent32/8 bounds, actual shared-clock busy state and allocation-free service.
Both parent Release CTest targets pass. The parent project registers46 suites;
that count is not a migration percentage.

Three compiling controls differ from original execution under both compilers:
accepting any nonzero activity differs2 cases, omitting the first DTX scan differs
124 cases, and adding an early DTX scan differs124 cases. Ordered guard events
matter even in an otherwise empty group; an extra scan is not silently ignored.

The first GCC unit build failed under `-Werror` because its inlined allocation
counter's replacement delete/free triggered `mismatched-new-delete`. The complete
freeze and failed log remain under `frozen-v1`/`qualified-gcc-v1`; LLVM passed that
freeze. Only the test deallocation helper changed to an explicit out-of-line
function. Current GCC verification passes; both parent compilers also pass the
updated unit. No native implementation, input, expected result or warning policy
changed. The qualification pins both freezes and the changed test source.

| Artifact under build-native-sjuni/adxt-transfer-groups | Receipt SHA-256 |
| --- | --- |
| original-v1 | `bd8db6700f9beb87d7f803ad2163278433da56436883942d0a471fcd1b404c6a` |
| qualified-gcc-v2 | `e8435e66f38c505415ca01a450cc12bda758242c25ec8bd3320dcea3d7617eb4` |
| qualified-llvm-v1 | `8df053e28ace32f21a92eb4f585ca91823c9d070ffa3a3dafe093f6b2ee3b757` |

The source-qualified native stereo-copy/source-credit binding is a possible
replacement for hardware transport. These dispatch checks alone do not bind
that data plane, prove full original DMA/RPC parity, advance a device clock or
close the clock's currently refused unowned-service path. File polling, actual
phased children, bank/packet output, LSC, movies and controlled game validation
remain required before stage3 completes. Stages4–6 are still required afterward.
