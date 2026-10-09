#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F105C
// Address: 0x1f105c - 0x1f1104
void sub_001F105C_0x1f105c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F105C_0x1f105c");
#endif

    switch (ctx->pc) {
        case 0x1f10e4u: goto label_1f10e4;
        default: break;
    }

    ctx->pc = 0x1f105cu;

    // 0x1f105c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f105cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f1060: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f1060u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f1064: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f1064u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f1068: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f1068u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f106c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f106cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f1070: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f1070u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f1074: 0xafc00008  sw          $zero, 0x8($fp)
    ctx->pc = 0x1f1074u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1f1078: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f1078u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f107c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f107cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1080: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f1080u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f1084: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f1084u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1088: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f1088u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f108c: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x1f108cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1f1090: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f1090u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1094: 0xa440000c  sh          $zero, 0xC($v0)
    ctx->pc = 0x1f1094u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 12), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f1098: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f1098u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f109c: 0xa440000e  sh          $zero, 0xE($v0)
    ctx->pc = 0x1f109cu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 14), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f10a0: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f10a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f10a4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f10a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f10a8: 0xac620008  sw          $v0, 0x8($v1)
    ctx->pc = 0x1f10a8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 2));
    // 0x1f10ac: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f10acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f10b0: 0xac400010  sw          $zero, 0x10($v0)
    ctx->pc = 0x1f10b0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 0));
    // 0x1f10b4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f10b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f10b8: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1f10b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1f10bc: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1F10BCu;
    {
        const bool branch_taken_0x1f10bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f10bc) {
            ctx->pc = 0x1F10E8u;
            goto label_1f10e8;
        }
    }
    ctx->pc = 0x1F10C4u;
    // 0x1f10c4: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f10c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f10c8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f10c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f10cc: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1f10ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1f10d0: 0x8c630008  lw          $v1, 0x8($v1)
    ctx->pc = 0x1f10d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1f10d4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f10d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f10d8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f10d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f10dc: 0x60f809  jalr        $v1
    ctx->pc = 0x1F10DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1F10E4u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1F10E4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F10E4u: goto label_1f10e4;
            case 0x1F10E8u: goto label_1f10e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1F10E4u; }
            if (ctx->pc != 0x1F10E4u) { return; }
        }
        }
    }
    ctx->pc = 0x1F10E4u;
label_1f10e4:
    // 0x1f10e4: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1f10e4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
label_1f10e8:
    // 0x1f10e8: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f10e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f10ec: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f10ecu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f10f0: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f10f0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f10f4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f10f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f10f8: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f10f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f10fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1F10FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F10E4u: goto label_1f10e4;
            case 0x1F10E8u: goto label_1f10e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F1104u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
