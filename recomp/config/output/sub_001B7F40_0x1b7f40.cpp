#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B7F40
// Address: 0x1b7f40 - 0x1b7fb0
void sub_001B7F40_0x1b7f40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B7F40_0x1b7f40");
#endif

    switch (ctx->pc) {
        case 0x1b7f7cu: goto label_1b7f7c;
        case 0x1b7f8cu: goto label_1b7f8c;
        default: break;
    }

    ctx->pc = 0x1b7f40u;

    // 0x1b7f40: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b7f40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b7f44: 0x51c3c  dsll32      $v1, $a1, 16
    ctx->pc = 0x1b7f44u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) << (32 + 16));
    // 0x1b7f48: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b7f48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b7f4c: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1b7f4cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1b7f50: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b7f50u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b7f54: 0x3c020031  lui         $v0, 0x31
    ctx->pc = 0x1b7f54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49 << 16));
    // 0x1b7f58: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b7f58u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b7f5c: 0x24426350  addiu       $v0, $v0, 0x6350
    ctx->pc = 0x1b7f5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 25424));
    // 0x1b7f60: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x1b7f60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x1b7f64: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x1b7f64u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b7f68: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x1b7f68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1b7f6c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B7F6Cu;
    {
        const bool branch_taken_0x1b7f6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7F70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7F6Cu;
            // 0x1b7f70: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7f6c) {
            ctx->pc = 0x1B7F7Cu;
            goto label_1b7f7c;
        }
    }
    ctx->pc = 0x1B7F74u;
    // 0x1b7f74: 0x40f809  jalr        $v0
    ctx->pc = 0x1B7F74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1B7F7Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1B7F7Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7F7Cu: goto label_1b7f7c;
            case 0x1B7F8Cu: goto label_1b7f8c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1B7F7Cu; }
            if (ctx->pc != 0x1B7F7Cu) { return; }
        }
        }
    }
    ctx->pc = 0x1B7F7Cu;
label_1b7f7c:
    // 0x1b7f7c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b7f7cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7f80: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b7f80u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7f84: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B7F84u;
    SET_GPR_U32(ctx, 31, 0x1B7F8Cu);
    ctx->pc = 0x1B7F88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7F84u;
            // 0x1b7f88: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7F8Cu; }
        if (ctx->pc != 0x1B7F8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7F8Cu; }
        if (ctx->pc != 0x1B7F8Cu) { return; }
    }
    ctx->pc = 0x1B7F8Cu;
label_1b7f8c:
    // 0x1b7f8c: 0xae110004  sw          $s1, 0x4($s0)
    ctx->pc = 0x1b7f8cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 17));
    // 0x1b7f90: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1b7f90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b7f94: 0xa6030000  sh          $v1, 0x0($s0)
    ctx->pc = 0x1b7f94u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b7f98: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b7f98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b7f9c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b7f9cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b7fa0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b7fa0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b7fa4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7FA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B7FA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7FA4u;
            // 0x1b7fa8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7F7Cu: goto label_1b7f7c;
            case 0x1B7F8Cu: goto label_1b7f8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B7FACu;
    // 0x1b7fac: 0x0  nop
    ctx->pc = 0x1b7facu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
