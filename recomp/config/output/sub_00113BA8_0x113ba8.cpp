#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00113BA8
// Address: 0x113ba8 - 0x113c20
void sub_00113BA8_0x113ba8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x113ba8u;

    // 0x113ba8: 0x27bdffe0
    ctx->pc = 0x113ba8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x113bac: 0xffb00000
    ctx->pc = 0x113bacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x113bb0: 0xffbf0010
    ctx->pc = 0x113bb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x113bb4: 0xc047598
    ctx->pc = 0x113BB4u;
    SET_GPR_U32(ctx, 31, 0x113BBCu);
    ctx->pc = 0x113BB8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113BBCu; }
    }
    if (ctx->pc != 0x113BBCu) { return; }
    ctx->pc = 0x113BBCu;
    // 0x113bbc: 0x3c061000
    ctx->pc = 0x113bbcu;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x113bc0: 0x3c071000
    ctx->pc = 0x113bc0u;
    SET_GPR_U32(ctx, 7, ((uint32_t)4096 << 16));
    // 0x113bc4: 0x34c6f520
    ctx->pc = 0x113bc4u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 62752));
    // 0x113bc8: 0x3c080001
    ctx->pc = 0x113bc8u;
    SET_GPR_U32(ctx, 8, ((uint32_t)1 << 16));
    // 0x113bcc: 0x8cc30000
    ctx->pc = 0x113bccu;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 6), 0))); // MMIO: 0x10000000
    // 0x113bd0: 0x34e7f590
    ctx->pc = 0x113bd0u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), 62864));
    // 0x113bd4: 0x3c041000
    ctx->pc = 0x113bd4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x113bd8: 0x3c05fffe
    ctx->pc = 0x113bd8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)65534 << 16));
    // 0x113bdc: 0x681825
    ctx->pc = 0x113bdcu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x113be0: 0x3484b000
    ctx->pc = 0x113be0u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 45056));
    // 0x113be4: 0xace30000
    ctx->pc = 0x113be4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    // 0x113be8: 0x34a5ffff
    ctx->pc = 0x113be8u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 65535));
    // 0x113bec: 0xac900000
    ctx->pc = 0x113becu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 16));
    // 0x113bf0: 0x8cc30000
    ctx->pc = 0x113bf0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x113bf4: 0x651824
    ctx->pc = 0x113bf4u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x113bf8: 0xace30000
    ctx->pc = 0x113bf8u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    // 0x113bfc: 0x10400004
    ctx->pc = 0x113BFCu;
    {
        const bool branch_taken_0x113bfc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x113C00u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        if (branch_taken_0x113bfc) {
            ctx->pc = 0x113C10u;
            goto label_113c10;
        }
    }
    ctx->pc = 0x113C04u;
    // 0x113c04: 0xdfb00000
    ctx->pc = 0x113c04u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x113c08: 0x80475ae
    ctx->pc = 0x113C08u;
    ctx->pc = 0x113C0Cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x11D6B8u;
    sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    ctx->pc = 0x113C10u;
label_113c10:
    // 0x113c10: 0xdfb00000
    ctx->pc = 0x113c10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x113c14: 0x3e00008
    ctx->pc = 0x113C14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x113C18u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113C10u: goto label_113c10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x113C1Cu;
    // 0x113c1c: 0x0
    ctx->pc = 0x113c1cu;
    // NOP
}
