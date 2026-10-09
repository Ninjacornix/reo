#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F3E00
// Address: 0x1f3e00 - 0x1f3e54
void sub_001F3E00_0x1f3e00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F3E00_0x1f3e00");
#endif

    ctx->pc = 0x1f3e00u;

    // 0x1f3e00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f3e00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f3e04: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f3e04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f3e08: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f3e08u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3e0c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f3e0cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f3e10: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f3e10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f3e14: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f3e14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3e18: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1f3e18u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1f3e1c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f3e1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f3e20: 0x8c430028  lw          $v1, 0x28($v0)
    ctx->pc = 0x1f3e20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x1f3e24: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f3e24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f3e28: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F3E28u;
    {
        const bool branch_taken_0x1f3e28 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f3e28) {
            ctx->pc = 0x1F3E3Cu;
            goto label_1f3e3c;
        }
    }
    ctx->pc = 0x1F3E30u;
    // 0x1f3e30: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1f3e30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f3e34: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F3E34u;
    {
        const bool branch_taken_0x1f3e34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3e34) {
            ctx->pc = 0x1F3E40u;
            goto label_1f3e40;
        }
    }
    ctx->pc = 0x1F3E3Cu;
label_1f3e3c:
    // 0x1f3e3c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f3e3cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f3e40:
    // 0x1f3e40: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f3e40u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3e44: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f3e44u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f3e48: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f3e48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f3e4c: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3E4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F3E3Cu: goto label_1f3e3c;
            case 0x1F3E40u: goto label_1f3e40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F3E54u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
