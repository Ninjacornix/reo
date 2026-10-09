#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8B50
// Address: 0x1c8b50 - 0x1c8bc0
void sub_001C8B50_0x1c8b50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8B50_0x1c8b50");
#endif

    switch (ctx->pc) {
        case 0x1c8bacu: goto label_1c8bac;
        default: break;
    }

    ctx->pc = 0x1c8b50u;

    // 0x1c8b50: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c8b50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c8b54: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8b54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8b58: 0xa022b21a  sb          $v0, -0x4DE6($at)
    ctx->pc = 0x1c8b58u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294947354), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c8b5c: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1c8b5cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c8b60: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8b60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8b64: 0xa022b219  sb          $v0, -0x4DE7($at)
    ctx->pc = 0x1c8b64u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294947353), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c8b68: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1c8b68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c8b6c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8b6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8b70: 0xac22b220  sw          $v0, -0x4DE0($at)
    ctx->pc = 0x1c8b70u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294947360), GPR_U32(ctx, 2));
    // 0x1c8b74: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8b74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8b78: 0x8072308  j           func_1C8C20
    ctx->pc = 0x1C8B78u;
    ctx->pc = 0x1C8B7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8B78u;
            // 0x1c8b7c: 0xa024b218  sb          $a0, -0x4DE8($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294947352), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8C20u;
    if (runtime->hasFunction(0x1C8C20u)) {
        auto targetFn = runtime->lookupFunction(0x1C8C20u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C8C20_0x1c8c20(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C8B80u;
    // 0x1c8b80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c8b80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c8b84: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8b84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8b88: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c8b88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c8b8c: 0x9023b219  lbu         $v1, -0x4DE7($at)
    ctx->pc = 0x1c8b8cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294947353)));
    // 0x1c8b90: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1C8B90u;
    {
        const bool branch_taken_0x1c8b90 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8B94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8B90u;
            // 0x1c8b94: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8b90) {
            ctx->pc = 0x1C8BACu;
            goto label_1c8bac;
        }
    }
    ctx->pc = 0x1C8B98u;
    // 0x1c8b98: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x1c8b98u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c8b9c: 0xa020b219  sb          $zero, -0x4DE7($at)
    ctx->pc = 0x1c8b9cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294947353), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c8ba0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8ba0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8ba4: 0xc072308  jal         func_1C8C20
    ctx->pc = 0x1C8BA4u;
    SET_GPR_U32(ctx, 31, 0x1C8BACu);
    ctx->pc = 0x1C8BA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8BA4u;
            // 0x1c8ba8: 0xa024b218  sb          $a0, -0x4DE8($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294947352), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8C20u;
    if (runtime->hasFunction(0x1C8C20u)) {
        auto targetFn = runtime->lookupFunction(0x1C8C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8BACu; }
        if (ctx->pc != 0x1C8BACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8C20_0x1c8c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8BACu; }
        if (ctx->pc != 0x1C8BACu) { return; }
    }
    ctx->pc = 0x1C8BACu;
label_1c8bac:
    // 0x1c8bac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c8bacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c8bb0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8BB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8BB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8BB0u;
            // 0x1c8bb4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8BACu: goto label_1c8bac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C8BB8u;
    // 0x1c8bb8: 0x0  nop
    ctx->pc = 0x1c8bb8u;
    // NOP
    // 0x1c8bbc: 0x0  nop
    ctx->pc = 0x1c8bbcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
