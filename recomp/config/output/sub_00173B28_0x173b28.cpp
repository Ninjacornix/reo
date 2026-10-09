#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173B28
// Address: 0x173b28 - 0x173b80
void sub_00173B28_0x173b28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173B28_0x173b28");
#endif

    switch (ctx->pc) {
        case 0x173b3cu: goto label_173b3c;
        case 0x173b68u: goto label_173b68;
        default: break;
    }

    ctx->pc = 0x173b28u;

    // 0x173b28: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x173b28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x173b2c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x173b2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x173b30: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x173b30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x173b34: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x173B34u;
    SET_GPR_U32(ctx, 31, 0x173B3Cu);
    ctx->pc = 0x173B38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173B34u;
            // 0x173b38: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173B3Cu; }
        if (ctx->pc != 0x173B3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173B3Cu; }
        if (ctx->pc != 0x173B3Cu) { return; }
    }
    ctx->pc = 0x173B3Cu;
label_173b3c:
    // 0x173b3c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x173b3cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x173b40: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x173b40u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173b44: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x173B44u;
    {
        const bool branch_taken_0x173b44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x173B48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173B44u;
            // 0x173b48: 0x34a50133  ori         $a1, $a1, 0x133 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)307);
        ctx->in_delay_slot = false;
        if (branch_taken_0x173b44) {
            ctx->pc = 0x173B60u;
            goto label_173b60;
        }
    }
    ctx->pc = 0x173B4Cu;
    // 0x173b4c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x173b4cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173b50: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x173b50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173b54: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x173b54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173b58: 0x805a704  j           func_169C10
    ctx->pc = 0x173B58u;
    ctx->pc = 0x173B5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173B58u;
            // 0x173b5c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x173B60u;
label_173b60:
    // 0x173b60: 0xc05cee0  jal         func_173B80
    ctx->pc = 0x173B60u;
    SET_GPR_U32(ctx, 31, 0x173B68u);
    ctx->pc = 0x173B80u;
    if (runtime->hasFunction(0x173B80u)) {
        auto targetFn = runtime->lookupFunction(0x173B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173B68u; }
        if (ctx->pc != 0x173B68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173B80_0x173b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173B68u; }
        if (ctx->pc != 0x173B68u) { return; }
    }
    ctx->pc = 0x173B68u;
label_173b68:
    // 0x173b68: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x173b68u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x173b6c: 0xae030044  sw          $v1, 0x44($s0)
    ctx->pc = 0x173b6cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 3));
    // 0x173b70: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x173b70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173b74: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x173b74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173b78: 0x3e00008  jr          $ra
    ctx->pc = 0x173B78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173B7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173B78u;
            // 0x173b7c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173B3Cu: goto label_173b3c;
            case 0x173B60u: goto label_173b60;
            case 0x173B68u: goto label_173b68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x173B80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
