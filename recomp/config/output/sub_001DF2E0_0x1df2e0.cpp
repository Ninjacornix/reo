#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DF2E0
// Address: 0x1df2e0 - 0x1df380
void sub_001DF2E0_0x1df2e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DF2E0_0x1df2e0");
#endif

    switch (ctx->pc) {
        case 0x1df358u: goto label_1df358;
        default: break;
    }

    ctx->pc = 0x1df2e0u;

    // 0x1df2e0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1df2e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1df2e4: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1df2e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1df2e8: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1df2e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1df2ec: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1df2ecu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df2f0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1df2f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1df2f4: 0x24020027  addiu       $v0, $zero, 0x27
    ctx->pc = 0x1df2f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 39));
    // 0x1df2f8: 0xa3c20010  sb          $v0, 0x10($fp)
    ctx->pc = 0x1df2f8u;
    WRITE8(ADD32(GPR_U32(ctx, 30), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0x1df2fc: 0xafc00018  sw          $zero, 0x18($fp)
    ctx->pc = 0x1df2fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
    // 0x1df300: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1df300u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1df304: 0xa7c20014  sh          $v0, 0x14($fp)
    ctx->pc = 0x1df304u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 20), (uint16_t)GPR_U32(ctx, 2));
    // 0x1df308: 0x24021000  addiu       $v0, $zero, 0x1000
    ctx->pc = 0x1df308u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1df30c: 0xa7c20016  sh          $v0, 0x16($fp)
    ctx->pc = 0x1df30cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 22), (uint16_t)GPR_U32(ctx, 2));
    // 0x1df310: 0xa3c00011  sb          $zero, 0x11($fp)
    ctx->pc = 0x1df310u;
    WRITE8(ADD32(GPR_U32(ctx, 30), 17), (uint8_t)GPR_U32(ctx, 0));
    // 0x1df314: 0xa7c00012  sh          $zero, 0x12($fp)
    ctx->pc = 0x1df314u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 18), (uint16_t)GPR_U32(ctx, 0));
    // 0x1df318: 0xafc0001c  sw          $zero, 0x1C($fp)
    ctx->pc = 0x1df318u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x1df31c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1df31cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1df320: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1df320u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1df324: 0x24020014  addiu       $v0, $zero, 0x14
    ctx->pc = 0x1df324u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1df328: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1df328u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1df32c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df32cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df330: 0x8c4205b8  lw          $v0, 0x5B8($v0)
    ctx->pc = 0x1df330u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1464)));
    // 0x1df334: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1DF334u;
    {
        const bool branch_taken_0x1df334 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1df334) {
            ctx->pc = 0x1DF358u;
            goto label_1df358;
        }
    }
    ctx->pc = 0x1DF33Cu;
    // 0x1df33c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df33cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df340: 0x27c30010  addiu       $v1, $fp, 0x10
    ctx->pc = 0x1df340u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1df344: 0x27c50020  addiu       $a1, $fp, 0x20
    ctx->pc = 0x1df344u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1df348: 0x8c4205b8  lw          $v0, 0x5B8($v0)
    ctx->pc = 0x1df348u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1464)));
    // 0x1df34c: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x1df34cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df350: 0x40f809  jalr        $v0
    ctx->pc = 0x1DF350u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1DF358u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1DF358u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DF358u: goto label_1df358;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1DF358u; }
            if (ctx->pc != 0x1DF358u) { return; }
        }
        }
    }
    ctx->pc = 0x1DF358u;
label_1df358:
    // 0x1df358: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df358u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df35c: 0xac40007c  sw          $zero, 0x7C($v0)
    ctx->pc = 0x1df35cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 124), GPR_U32(ctx, 0));
    // 0x1df360: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df360u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df364: 0xac400080  sw          $zero, 0x80($v0)
    ctx->pc = 0x1df364u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 128), GPR_U32(ctx, 0));
    // 0x1df368: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1df368u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df36c: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1df36cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1df370: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1df370u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1df374: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1df374u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1df378: 0x3e00008  jr          $ra
    ctx->pc = 0x1DF378u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DF358u: goto label_1df358;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DF380u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
