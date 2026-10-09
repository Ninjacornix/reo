#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B7EE0
// Address: 0x1b7ee0 - 0x1b7f40
void sub_001B7EE0_0x1b7ee0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B7EE0_0x1b7ee0");
#endif

    switch (ctx->pc) {
        case 0x1b7f1cu: goto label_1b7f1c;
        default: break;
    }

    ctx->pc = 0x1b7ee0u;

    // 0x1b7ee0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b7ee0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b7ee4: 0x51c3c  dsll32      $v1, $a1, 16
    ctx->pc = 0x1b7ee4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) << (32 + 16));
    // 0x1b7ee8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b7ee8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b7eec: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1b7eecu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1b7ef0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b7ef0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b7ef4: 0x3c020031  lui         $v0, 0x31
    ctx->pc = 0x1b7ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49 << 16));
    // 0x1b7ef8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b7ef8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b7efc: 0x24426350  addiu       $v0, $v0, 0x6350
    ctx->pc = 0x1b7efcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 25424));
    // 0x1b7f00: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x1b7f00u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x1b7f04: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1b7f04u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7f08: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x1b7f08u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b7f0c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b7f0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7f10: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x1b7f10u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1b7f14: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B7F14u;
    SET_GPR_U32(ctx, 31, 0x1B7F1Cu);
    ctx->pc = 0x1B7F18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7F14u;
            // 0x1b7f18: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7F1Cu; }
        if (ctx->pc != 0x1B7F1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7F1Cu; }
        if (ctx->pc != 0x1B7F1Cu) { return; }
    }
    ctx->pc = 0x1B7F1Cu;
label_1b7f1c:
    // 0x1b7f1c: 0x2403000c  addiu       $v1, $zero, 0xC
    ctx->pc = 0x1b7f1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1b7f20: 0xa6030000  sh          $v1, 0x0($s0)
    ctx->pc = 0x1b7f20u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b7f24: 0xae110004  sw          $s1, 0x4($s0)
    ctx->pc = 0x1b7f24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 17));
    // 0x1b7f28: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b7f28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b7f2c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b7f2cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b7f30: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b7f30u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b7f34: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7F34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B7F38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7F34u;
            // 0x1b7f38: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7F1Cu: goto label_1b7f1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B7F3Cu;
    // 0x1b7f3c: 0x0  nop
    ctx->pc = 0x1b7f3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
