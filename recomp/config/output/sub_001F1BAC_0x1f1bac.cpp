#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F1BAC
// Address: 0x1f1bac - 0x1f1c58
void sub_001F1BAC_0x1f1bac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F1BAC_0x1f1bac");
#endif

    ctx->pc = 0x1f1bacu;

    // 0x1f1bac: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f1bacu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f1bb0: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f1bb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f1bb4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f1bb4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1bb8: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1f1bb8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1bbc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1f1bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f1bc0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1bc0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1bc4: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f1bc4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f1bc8: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f1bc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f1bcc: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1BCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F1C40u: goto label_1f1c40;
            case 0x1F1C44u: goto label_1f1c44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F1BD4u;
    // 0x1f1bd4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f1bd4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f1bd8: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f1bd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f1bdc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f1bdcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1be0: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1f1be0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1be4: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1f1be4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1f1be8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1be8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1bec: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f1becu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f1bf0: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f1bf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f1bf4: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1BF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F1C40u: goto label_1f1c40;
            case 0x1F1C44u: goto label_1f1c44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F1BFCu;
    // 0x1f1bfc: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f1bfcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f1c00: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f1c00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f1c04: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f1c04u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1c08: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f1c08u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f1c0c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f1c0cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f1c10: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f1c10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1c14: 0x9443000e  lhu         $v1, 0xE($v0)
    ctx->pc = 0x1f1c14u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 14)));
    // 0x1f1c18: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f1c18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1c1c: 0x21402  srl         $v0, $v0, 16
    ctx->pc = 0x1f1c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x1f1c20: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1f1c20u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1f1c24: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f1c24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1c28: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1f1c28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f1c2c: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1C2Cu;
    {
        const bool branch_taken_0x1f1c2c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f1c2c) {
            ctx->pc = 0x1F1C40u;
            goto label_1f1c40;
        }
    }
    ctx->pc = 0x1F1C34u;
    // 0x1f1c34: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1f1c34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f1c38: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F1C38u;
    {
        const bool branch_taken_0x1f1c38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1c38) {
            ctx->pc = 0x1F1C44u;
            goto label_1f1c44;
        }
    }
    ctx->pc = 0x1F1C40u;
label_1f1c40:
    // 0x1f1c40: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f1c40u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f1c44:
    // 0x1f1c44: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1c44u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1c48: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f1c48u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f1c4c: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f1c4cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f1c50: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1C50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F1C40u: goto label_1f1c40;
            case 0x1F1C44u: goto label_1f1c44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F1C58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
