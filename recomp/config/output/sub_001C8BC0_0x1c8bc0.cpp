#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8BC0
// Address: 0x1c8bc0 - 0x1c8c10
void sub_001C8BC0_0x1c8bc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8BC0_0x1c8bc0");
#endif

    switch (ctx->pc) {
        case 0x1c8be8u: goto label_1c8be8;
        default: break;
    }

    ctx->pc = 0x1c8bc0u;

    // 0x1c8bc0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c8bc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c8bc4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8bc4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8bc8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c8bc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c8bcc: 0x9022b219  lbu         $v0, -0x4DE7($at)
    ctx->pc = 0x1c8bccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294947353)));
    // 0x1c8bd0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C8BD0u;
    {
        const bool branch_taken_0x1c8bd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C8BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8BD0u;
            // 0x1c8bd4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8bd0) {
            ctx->pc = 0x1C8BE0u;
            goto label_1c8be0;
        }
    }
    ctx->pc = 0x1C8BD8u;
    // 0x1c8bd8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1C8BD8u;
    {
        const bool branch_taken_0x1c8bd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8BDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8BD8u;
            // 0x1c8bdc: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8bd8) {
            ctx->pc = 0x1C8BFCu;
            goto label_1c8bfc;
        }
    }
    ctx->pc = 0x1C8BE0u;
label_1c8be0:
    // 0x1c8be0: 0xc07230c  jal         func_1C8C30
    ctx->pc = 0x1C8BE0u;
    SET_GPR_U32(ctx, 31, 0x1C8BE8u);
    ctx->pc = 0x1C8C30u;
    if (runtime->hasFunction(0x1C8C30u)) {
        auto targetFn = runtime->lookupFunction(0x1C8C30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8BE8u; }
        if (ctx->pc != 0x1C8BE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8C30_0x1c8c30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8BE8u; }
        if (ctx->pc != 0x1C8BE8u) { return; }
    }
    ctx->pc = 0x1C8BE8u;
label_1c8be8:
    // 0x1c8be8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8be8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8bec: 0xa022b218  sb          $v0, -0x4DE8($at)
    ctx->pc = 0x1c8becu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294947352), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c8bf0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8bf0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8bf4: 0x9022b218  lbu         $v0, -0x4DE8($at)
    ctx->pc = 0x1c8bf4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294947352)));
    // 0x1c8bf8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c8bf8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1c8bfc:
    // 0x1c8bfc: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8BFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8C00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8BFCu;
            // 0x1c8c00: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8BE0u: goto label_1c8be0;
            case 0x1C8BE8u: goto label_1c8be8;
            case 0x1C8BFCu: goto label_1c8bfc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C8C04u;
    // 0x1c8c04: 0x0  nop
    ctx->pc = 0x1c8c04u;
    // NOP
    // 0x1c8c08: 0x0  nop
    ctx->pc = 0x1c8c08u;
    // NOP
    // 0x1c8c0c: 0x0  nop
    ctx->pc = 0x1c8c0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
