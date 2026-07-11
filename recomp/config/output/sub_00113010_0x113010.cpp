#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00113010
// Address: 0x113010 - 0x1130f8
void sub_00113010_0x113010(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x113010u;

    // 0x113010: 0x27bdfff0
    ctx->pc = 0x113010u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x113014: 0x3c031000
    ctx->pc = 0x113014u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x113018: 0xffbf0000
    ctx->pc = 0x113018u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11301c: 0x3463a000
    ctx->pc = 0x11301cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 40960));
    // 0x113020: 0x80302d
    ctx->pc = 0x113020u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113024: 0x8c620000
    ctx->pc = 0x113024u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x113028: 0x30420100
    ctx->pc = 0x113028u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 256));
    // 0x11302c: 0x1040000d
    ctx->pc = 0x11302Cu;
    {
        const bool branch_taken_0x11302c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x113030u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x11302c) {
            ctx->pc = 0x113064u;
            goto label_113064;
        }
    }
    ctx->pc = 0x113034u;
    // 0x113034: 0x3c031000
    ctx->pc = 0x113034u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x113038: 0x3c050100
    ctx->pc = 0x113038u;
    SET_GPR_U32(ctx, 5, ((uint32_t)256 << 16));
    // 0x11303c: 0x3463a000
    ctx->pc = 0x11303cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 40960));
    // 0x113040: 0x80102d
    ctx->pc = 0x113040u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113044: 0x0
    ctx->pc = 0x113044u;
    // NOP
label_113048:
    // 0x113048: 0xa2102b
    ctx->pc = 0x113048u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x11304c: 0x14400018
    ctx->pc = 0x11304Cu;
    {
        const bool branch_taken_0x11304c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x113050u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1));
        if (branch_taken_0x11304c) {
            ctx->pc = 0x1130B0u;
            goto label_1130b0;
        }
    }
    ctx->pc = 0x113054u;
    // 0x113054: 0x8c620000
    ctx->pc = 0x113054u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x113058: 0x30420100
    ctx->pc = 0x113058u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 256));
    // 0x11305c: 0x1440fffa
    ctx->pc = 0x11305Cu;
    {
        const bool branch_taken_0x11305c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x113060u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x11305c) {
            ctx->pc = 0x113048u;
            goto label_113048;
        }
    }
    ctx->pc = 0x113064u;
label_113064:
    // 0x113064: 0xdcc20000
    ctx->pc = 0x113064u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x113068: 0x3c031000
    ctx->pc = 0x113068u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x11306c: 0x3463a020
    ctx->pc = 0x11306cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 40992));
    // 0x113070: 0x3c047000
    ctx->pc = 0x113070u;
    SET_GPR_U32(ctx, 4, ((uint32_t)28672 << 16));
    // 0x113074: 0x30427fff
    ctx->pc = 0x113074u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 32767));
    // 0x113078: 0xc42824
    ctx->pc = 0x113078u;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x11307c: 0x2103c
    ctx->pc = 0x11307cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x113080: 0x2103f
    ctx->pc = 0x113080u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x113084: 0x24420001
    ctx->pc = 0x113084u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x113088: 0xac620000
    ctx->pc = 0x113088u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x11308c: 0x14a4000d
    ctx->pc = 0x11308Cu;
    {
        const bool branch_taken_0x11308c = (GPR_U32(ctx, 5) != GPR_U32(ctx, 4));
        ctx->pc = 0x113090u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4095 << 16));
        if (branch_taken_0x11308c) {
            ctx->pc = 0x1130C4u;
            goto label_1130c4;
        }
    }
    ctx->pc = 0x113094u;
    // 0x113094: 0x3c031000
    ctx->pc = 0x113094u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x113098: 0x3442ffff
    ctx->pc = 0x113098u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65535));
    // 0x11309c: 0x3c048000
    ctx->pc = 0x11309cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)32768 << 16));
    // 0x1130a0: 0xc21024
    ctx->pc = 0x1130a0u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1130a4: 0x3463a010
    ctx->pc = 0x1130a4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 40976));
    // 0x1130a8: 0x1000000a
    ctx->pc = 0x1130A8u;
    {
        const bool branch_taken_0x1130a8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1130ACu;
        SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
        if (branch_taken_0x1130a8) {
            ctx->pc = 0x1130D4u;
            goto label_1130d4;
        }
    }
    ctx->pc = 0x1130B0u;
label_1130b0:
    // 0x1130b0: 0x3c040024
    ctx->pc = 0x1130b0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x1130b4: 0xc045a12
    ctx->pc = 0x1130B4u;
    SET_GPR_U32(ctx, 31, 0x1130BCu);
    ctx->pc = 0x1130B8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294936064));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1130BCu; }
    }
    if (ctx->pc != 0x1130BCu) { return; }
    ctx->pc = 0x1130BCu;
    // 0x1130bc: 0x1000000b
    ctx->pc = 0x1130BCu;
    {
        const bool branch_taken_0x1130bc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1130C0u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1130bc) {
            ctx->pc = 0x1130ECu;
            goto label_1130ec;
        }
    }
    ctx->pc = 0x1130C4u;
label_1130c4:
    // 0x1130c4: 0x3c031000
    ctx->pc = 0x1130c4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1130c8: 0x3442ffff
    ctx->pc = 0x1130c8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65535));
    // 0x1130cc: 0x3463a010
    ctx->pc = 0x1130ccu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 40976));
    // 0x1130d0: 0xc21024
    ctx->pc = 0x1130d0u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
label_1130d4:
    // 0x1130d4: 0xac620000
    ctx->pc = 0x1130d4u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2)); // MMIO: 0x10000000
    // 0x1130d8: 0x3c031000
    ctx->pc = 0x1130d8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1130dc: 0x24040101
    ctx->pc = 0x1130dcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 257));
    // 0x1130e0: 0x3463a000
    ctx->pc = 0x1130e0u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 40960));
    // 0x1130e4: 0x102d
    ctx->pc = 0x1130e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1130e8: 0xac640000
    ctx->pc = 0x1130e8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
label_1130ec:
    // 0x1130ec: 0xdfbf0000
    ctx->pc = 0x1130ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1130f0: 0x3e00008
    ctx->pc = 0x1130F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1130F4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113048u: goto label_113048;
            case 0x113064u: goto label_113064;
            case 0x1130B0u: goto label_1130b0;
            case 0x1130C4u: goto label_1130c4;
            case 0x1130D4u: goto label_1130d4;
            case 0x1130ECu: goto label_1130ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1130F8u;
}
