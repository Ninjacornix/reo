// REO: functions the static recompiler did not discover as entry points.
//
// Each body below is the recompiler's own generated code, extracted verbatim from the
// function it was merged into (see docs/DIVERGENCES.md, D6). Only edits: a new function
// header with the correct entry, and jr-switch cases for labels outside the extracted
// range removed (their default path returns to the dispatcher, which is correct). Registered
// as function entries in reo_override.cpp.

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00115F30 (putchar-style console output; reached only via a function
// pointer stored by 0x116848, so the analyzer merged it into sub_00115EF0)
// Address: 0x115f30 - 0x115fe0  (extracted from sub_00115EF0_0x115ef0.cpp)
void sub_00115F30_0x115f30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x115f30u;

    // 0x115f30: 0x27bdffc0
    ctx->pc = 0x115f30u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x115f34: 0xffb10010
    ctx->pc = 0x115f34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x115f38: 0x3c110021
    ctx->pc = 0x115f38u;
    SET_GPR_U32(ctx, 17, ((uint32_t)33 << 16));
    // 0x115f3c: 0xffb00000
    ctx->pc = 0x115f3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x115f40: 0x8e259d40
    ctx->pc = 0x115f40u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 4294942016)));
    // 0x115f44: 0x80802d
    ctx->pc = 0x115f44u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115f48: 0xffbf0030
    ctx->pc = 0x115f48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x115f4c: 0x28a2007e
    ctx->pc = 0x115f4cu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 5), 126));
    // 0x115f50: 0x14400009
    ctx->pc = 0x115F50u;
    {
        const bool branch_taken_0x115f50 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x115F54u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
        if (branch_taken_0x115f50) {
            ctx->pc = 0x115F78u;
            goto label_115f78;
        }
    }
    ctx->pc = 0x115F58u;
    // 0x115f58: 0x3c120026
    ctx->pc = 0x115f58u;
    SET_GPR_U32(ctx, 18, ((uint32_t)38 << 16));
    // 0x115f5c: 0xae209d40
    ctx->pc = 0x115f5cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4294942016), GPR_U32(ctx, 0));
    // 0x115f60: 0x2642ae40
    ctx->pc = 0x115f60u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 18), 4294946368));
    // 0x115f64: 0x40202d
    ctx->pc = 0x115f64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115f68: 0xc045660
    ctx->pc = 0x115F68u;
    SET_GPR_U32(ctx, 31, 0x115F70u);
    ctx->pc = 0x115F6Cu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 127), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0x115980u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00115980_0x115980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115F70u; }
    }
    if (ctx->pc != 0x115F70u) { return; }
    ctx->pc = 0x115F70u;
    // 0x115f70: 0x10000002
    ctx->pc = 0x115F70u;
    {
        const bool branch_taken_0x115f70 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x115F74u;
        SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 4294942016)));
        if (branch_taken_0x115f70) {
            ctx->pc = 0x115F7Cu;
            goto label_115f7c;
        }
    }
    ctx->pc = 0x115F78u;
label_115f78:
    // 0x115f78: 0x3c120026
    ctx->pc = 0x115f78u;
    SET_GPR_U32(ctx, 18, ((uint32_t)38 << 16));
label_115f7c:
    // 0x115f7c: 0x2402000a
    ctx->pc = 0x115f7cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 10));
    // 0x115f80: 0x1602000d
    ctx->pc = 0x115F80u;
    {
        const bool branch_taken_0x115f80 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 2));
        ctx->pc = 0x115F84u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 18), 4294946368));
        if (branch_taken_0x115f80) {
            ctx->pc = 0x115FB8u;
            goto label_115fb8;
        }
    }
    ctx->pc = 0x115F88u;
    // 0x115f88: 0x2644ae40
    ctx->pc = 0x115f88u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 18), 4294946368));
    // 0x115f8c: 0xae209d40
    ctx->pc = 0x115f8cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4294942016), GPR_U32(ctx, 0));
    // 0x115f90: 0xa41021
    ctx->pc = 0x115f90u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x115f94: 0xdfbf0030
    ctx->pc = 0x115f94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x115f98: 0xa0500000
    ctx->pc = 0x115f98u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 16));
    // 0x115f9c: 0x40182d
    ctx->pc = 0x115f9cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115fa0: 0xdfb20020
    ctx->pc = 0x115fa0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x115fa4: 0xdfb10010
    ctx->pc = 0x115fa4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x115fa8: 0xdfb00000
    ctx->pc = 0x115fa8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x115fac: 0xa0600001
    ctx->pc = 0x115facu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x115fb0: 0x8045660
    ctx->pc = 0x115FB0u;
    ctx->pc = 0x115FB4u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
    ctx->pc = 0x115980u;
    sub_00115980_0x115980(rdram, ctx, runtime); return;
    ctx->pc = 0x115FB8u;
label_115fb8:
    // 0x115fb8: 0x24a30001
    ctx->pc = 0x115fb8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 5), 1));
    // 0x115fbc: 0xae239d40
    ctx->pc = 0x115fbcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4294942016), GPR_U32(ctx, 3));
    // 0x115fc0: 0xa21021
    ctx->pc = 0x115fc0u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x115fc4: 0xa0500000
    ctx->pc = 0x115fc4u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 16));
    // 0x115fc8: 0xdfbf0030
    ctx->pc = 0x115fc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x115fcc: 0xdfb20020
    ctx->pc = 0x115fccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x115fd0: 0xdfb10010
    ctx->pc = 0x115fd0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x115fd4: 0xdfb00000
    ctx->pc = 0x115fd4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x115fd8: 0x3e00008
    ctx->pc = 0x115FD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x115FDCu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115F78u: goto label_115f78;
            case 0x115F7Cu: goto label_115f7c;
            case 0x115FB8u: goto label_115fb8;
            default: break;
        }
        return;
    }
}
