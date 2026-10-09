#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E1C90
// Address: 0x1e1c90 - 0x1e1d2c
void sub_001E1C90_0x1e1c90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E1C90_0x1e1c90");
#endif

    switch (ctx->pc) {
        case 0x1e1d14u: goto label_1e1d14;
        default: break;
    }

    ctx->pc = 0x1e1c90u;

    // 0x1e1c90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e1c90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e1c94: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e1c94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e1c98: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e1c98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e1c9c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e1c9cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1ca0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e1ca0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e1ca4: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1e1ca4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
    // 0x1e1ca8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e1ca8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1cac: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e1cacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e1cb0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E1CB0u;
    {
        const bool branch_taken_0x1e1cb0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e1cb0) {
            ctx->pc = 0x1E1CD8u;
            goto label_1e1cd8;
        }
    }
    ctx->pc = 0x1E1CB8u;
    // 0x1e1cb8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1cbc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1cbcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1cc0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1cc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e1cc4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e1cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e1cc8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e1cc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e1ccc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e1cccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1cd0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1CD0u;
    {
        const bool branch_taken_0x1e1cd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1cd0) {
            ctx->pc = 0x1E1CECu;
            goto label_1e1cec;
        }
    }
    ctx->pc = 0x1E1CD8u;
label_1e1cd8:
    // 0x1e1cd8: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e1cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e1cdc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1cdcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1ce0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1ce0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1ce4: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1E1CE4u;
    {
        const bool branch_taken_0x1e1ce4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1ce4) {
            ctx->pc = 0x1E1D14u;
            goto label_1e1d14;
        }
    }
    ctx->pc = 0x1E1CECu;
label_1e1cec:
    // 0x1e1cec: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1cecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1cf0: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1cf0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1cf4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1cf4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e1cf8: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e1cf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e1cfc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e1cfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e1d00: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e1d00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1d04: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e1d04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e1d08: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e1d08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e1d0c: 0xc0786cf  jal         func_1E1B3C
    ctx->pc = 0x1E1D0Cu;
    SET_GPR_U32(ctx, 31, 0x1E1D14u);
    ctx->pc = 0x1E1B3Cu;
    if (runtime->hasFunction(0x1E1B3Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E1B3Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1D14u; }
        if (ctx->pc != 0x1E1D14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E1B3C_0x1e1b3c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1D14u; }
        if (ctx->pc != 0x1E1D14u) { return; }
    }
    ctx->pc = 0x1E1D14u;
label_1e1d14:
    // 0x1e1d14: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e1d14u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1d18: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e1d18u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e1d1c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e1d1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e1d20: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e1d20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e1d24: 0x3e00008  jr          $ra
    ctx->pc = 0x1E1D24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E1D2Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
