#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E1C00
// Address: 0x1e1c00 - 0x1e1c90
void sub_001E1C00_0x1e1c00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E1C00_0x1e1c00");
#endif

    ctx->pc = 0x1e1c00u;

    // 0x1e1c00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e1c00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e1c04: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e1c04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e1c08: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e1c08u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1c0c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e1c0cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e1c10: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1e1c10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
    // 0x1e1c14: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e1c14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1c18: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e1c18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e1c1c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E1C1Cu;
    {
        const bool branch_taken_0x1e1c1c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e1c1c) {
            ctx->pc = 0x1E1C44u;
            goto label_1e1c44;
        }
    }
    ctx->pc = 0x1E1C24u;
    // 0x1e1c24: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1c24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1c28: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1c28u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1c2c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1c2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e1c30: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e1c30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e1c34: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e1c34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e1c38: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e1c38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1c3c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1C3Cu;
    {
        const bool branch_taken_0x1e1c3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1c3c) {
            ctx->pc = 0x1E1C58u;
            goto label_1e1c58;
        }
    }
    ctx->pc = 0x1E1C44u;
label_1e1c44:
    // 0x1e1c44: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e1c44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e1c48: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1c48u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1c4c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1c50: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1E1C50u;
    {
        const bool branch_taken_0x1e1c50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1c50) {
            ctx->pc = 0x1E1C7Cu;
            goto label_1e1c7c;
        }
    }
    ctx->pc = 0x1E1C58u;
label_1e1c58:
    // 0x1e1c58: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1c58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1c5c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1c5cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1c60: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1c60u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e1c64: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e1c64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e1c68: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e1c68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e1c6c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e1c6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1c70: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e1c70u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e1c74: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e1c74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e1c78: 0x8c420508  lw          $v0, 0x508($v0)
    ctx->pc = 0x1e1c78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1288)));
label_1e1c7c:
    // 0x1e1c7c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e1c7cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1c80: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e1c80u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e1c84: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e1c84u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e1c88: 0x3e00008  jr          $ra
    ctx->pc = 0x1E1C88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E1C90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
