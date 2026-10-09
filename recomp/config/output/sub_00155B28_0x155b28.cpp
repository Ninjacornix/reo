#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00155B28
// Address: 0x155b28 - 0x155bc8
void sub_00155B28_0x155b28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00155B28_0x155b28");
#endif

    switch (ctx->pc) {
        case 0x155ba0u: goto label_155ba0;
        default: break;
    }

    ctx->pc = 0x155b28u;

    // 0x155b28: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x155b28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x155b2c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x155b2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x155b30: 0xac830050  sw          $v1, 0x50($a0)
    ctx->pc = 0x155b30u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 80), GPR_U32(ctx, 3));
    // 0x155b34: 0xac820038  sw          $v0, 0x38($a0)
    ctx->pc = 0x155b34u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 2));
    // 0x155b38: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x155b38u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x155b3c: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x155b3cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x155b40: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x155b40u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x155b44: 0xac80000c  sw          $zero, 0xC($a0)
    ctx->pc = 0x155b44u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
    // 0x155b48: 0xac800010  sw          $zero, 0x10($a0)
    ctx->pc = 0x155b48u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 0));
    // 0x155b4c: 0xac800014  sw          $zero, 0x14($a0)
    ctx->pc = 0x155b4cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 0));
    // 0x155b50: 0xac800018  sw          $zero, 0x18($a0)
    ctx->pc = 0x155b50u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 0));
    // 0x155b54: 0xac80001c  sw          $zero, 0x1C($a0)
    ctx->pc = 0x155b54u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 0));
    // 0x155b58: 0xac800020  sw          $zero, 0x20($a0)
    ctx->pc = 0x155b58u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 0));
    // 0x155b5c: 0xac800024  sw          $zero, 0x24($a0)
    ctx->pc = 0x155b5cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 0));
    // 0x155b60: 0xac800028  sw          $zero, 0x28($a0)
    ctx->pc = 0x155b60u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 0));
    // 0x155b64: 0xac80002c  sw          $zero, 0x2C($a0)
    ctx->pc = 0x155b64u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 0));
    // 0x155b68: 0xac800030  sw          $zero, 0x30($a0)
    ctx->pc = 0x155b68u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 48), GPR_U32(ctx, 0));
    // 0x155b6c: 0xac800034  sw          $zero, 0x34($a0)
    ctx->pc = 0x155b6cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 0));
    // 0x155b70: 0xac83003c  sw          $v1, 0x3C($a0)
    ctx->pc = 0x155b70u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 3));
    // 0x155b74: 0xac830040  sw          $v1, 0x40($a0)
    ctx->pc = 0x155b74u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 64), GPR_U32(ctx, 3));
    // 0x155b78: 0xac800044  sw          $zero, 0x44($a0)
    ctx->pc = 0x155b78u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 68), GPR_U32(ctx, 0));
    // 0x155b7c: 0xac800048  sw          $zero, 0x48($a0)
    ctx->pc = 0x155b7cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 0));
    // 0x155b80: 0x3e00008  jr          $ra
    ctx->pc = 0x155B80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x155B84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155B80u;
            // 0x155b84: 0xac80004c  sw          $zero, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155BA0u: goto label_155ba0;
            case 0x155BB8u: goto label_155bb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155B88u;
    // 0x155b88: 0x3e00008  jr          $ra
    ctx->pc = 0x155B88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155BA0u: goto label_155ba0;
            case 0x155BB8u: goto label_155bb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155B90u;
    // 0x155b90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x155b90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x155b94: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x155b94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x155b98: 0xc0556f2  jal         func_155BC8
    ctx->pc = 0x155B98u;
    SET_GPR_U32(ctx, 31, 0x155BA0u);
    ctx->pc = 0x155BC8u;
    if (runtime->hasFunction(0x155BC8u)) {
        auto targetFn = runtime->lookupFunction(0x155BC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155BA0u; }
        if (ctx->pc != 0x155BA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155BC8_0x155bc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155BA0u; }
        if (ctx->pc != 0x155BA0u) { return; }
    }
    ctx->pc = 0x155BA0u;
label_155ba0:
    // 0x155ba0: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x155ba0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155ba4: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x155BA4u;
    {
        const bool branch_taken_0x155ba4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x155BA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155BA4u;
            // 0x155ba8: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155ba4) {
            ctx->pc = 0x155BB8u;
            goto label_155bb8;
        }
    }
    ctx->pc = 0x155BACu;
    // 0x155bac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x155bacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155bb0: 0x8055706  j           func_155C18
    ctx->pc = 0x155BB0u;
    ctx->pc = 0x155BB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155BB0u;
            // 0x155bb4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155C18u;
    if (runtime->hasFunction(0x155C18u)) {
        auto targetFn = runtime->lookupFunction(0x155C18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00155C18_0x155c18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x155BB8u;
label_155bb8:
    // 0x155bb8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x155bb8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155bbc: 0x3e00008  jr          $ra
    ctx->pc = 0x155BBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x155BC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155BBCu;
            // 0x155bc0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155BA0u: goto label_155ba0;
            case 0x155BB8u: goto label_155bb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155BC4u;
    // 0x155bc4: 0x0  nop
    ctx->pc = 0x155bc4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
