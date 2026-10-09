#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160E28
// Address: 0x160e28 - 0x160e98
void sub_00160E28_0x160e28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160E28_0x160e28");
#endif

    switch (ctx->pc) {
        case 0x160e80u: goto label_160e80;
        default: break;
    }

    ctx->pc = 0x160e28u;

    // 0x160e28: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160e28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160e2c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x160e2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x160e30: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x160e30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x160e34: 0x24100003  addiu       $s0, $zero, 0x3
    ctx->pc = 0x160e34u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x160e38: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x160e38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x160e3c: 0x8c830088  lw          $v1, 0x88($a0)
    ctx->pc = 0x160e3cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 136)));
    // 0x160e40: 0x1062000b  beq         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x160E40u;
    {
        const bool branch_taken_0x160e40 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x160E44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160E40u;
            // 0x160e44: 0x2c640003  sltiu       $a0, $v1, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x160e40) {
            ctx->pc = 0x160E70u;
            goto label_160e70;
        }
    }
    ctx->pc = 0x160E48u;
    // 0x160e48: 0x10800005  beqz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x160E48u;
    {
        const bool branch_taken_0x160e48 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x160E4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160E48u;
            // 0x160e4c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160e48) {
            ctx->pc = 0x160E60u;
            goto label_160e60;
        }
    }
    ctx->pc = 0x160E50u;
    // 0x160e50: 0x5062000b  beql        $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x160E50u;
    {
        const bool branch_taken_0x160e50 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x160e50) {
            ctx->pc = 0x160E54u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x160E50u;
            // 0x160e54: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x160E80u;
            goto label_160e80;
        }
    }
    ctx->pc = 0x160E58u;
    // 0x160e58: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x160E58u;
    {
        const bool branch_taken_0x160e58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160E5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160E58u;
            // 0x160e5c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160e58) {
            ctx->pc = 0x160E78u;
            goto label_160e78;
        }
    }
    ctx->pc = 0x160E60u;
label_160e60:
    // 0x160e60: 0x10700008  beq         $v1, $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x160E60u;
    {
        const bool branch_taken_0x160e60 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 16));
        ctx->pc = 0x160E64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160E60u;
            // 0x160e64: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160e60) {
            ctx->pc = 0x160E84u;
            goto label_160e84;
        }
    }
    ctx->pc = 0x160E68u;
    // 0x160e68: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x160E68u;
    {
        const bool branch_taken_0x160e68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160E68u;
            // 0x160e6c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160e68) {
            ctx->pc = 0x160E78u;
            goto label_160e78;
        }
    }
    ctx->pc = 0x160E70u;
label_160e70:
    // 0x160e70: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x160E70u;
    {
        const bool branch_taken_0x160e70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160E74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160E70u;
            // 0x160e74: 0x24100002  addiu       $s0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160e70) {
            ctx->pc = 0x160E80u;
            goto label_160e80;
        }
    }
    ctx->pc = 0x160E78u;
label_160e78:
    // 0x160e78: 0xc058dd4  jal         func_163750
    ctx->pc = 0x160E78u;
    SET_GPR_U32(ctx, 31, 0x160E80u);
    ctx->pc = 0x160E7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160E78u;
            // 0x160e7c: 0x2484f8d0  addiu       $a0, $a0, -0x730 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965456));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160E80u; }
        if (ctx->pc != 0x160E80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160E80u; }
        if (ctx->pc != 0x160E80u) { return; }
    }
    ctx->pc = 0x160E80u;
label_160e80:
    // 0x160e80: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x160e80u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_160e84:
    // 0x160e84: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160e84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160e88: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x160e88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160e8c: 0x3e00008  jr          $ra
    ctx->pc = 0x160E8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160E90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160E8Cu;
            // 0x160e90: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160E60u: goto label_160e60;
            case 0x160E70u: goto label_160e70;
            case 0x160E78u: goto label_160e78;
            case 0x160E80u: goto label_160e80;
            case 0x160E84u: goto label_160e84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160E94u;
    // 0x160e94: 0x0  nop
    ctx->pc = 0x160e94u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
