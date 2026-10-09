#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B7FB0
// Address: 0x1b7fb0 - 0x1b8010
void sub_001B7FB0_0x1b7fb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B7FB0_0x1b7fb0");
#endif

    switch (ctx->pc) {
        case 0x1b7fecu: goto label_1b7fec;
        case 0x1b7ffcu: goto label_1b7ffc;
        default: break;
    }

    ctx->pc = 0x1b7fb0u;

    // 0x1b7fb0: 0x4143c  dsll32      $v0, $a0, 16
    ctx->pc = 0x1b7fb0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) << (32 + 16));
    // 0x1b7fb4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b7fb4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b7fb8: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1b7fb8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1b7fbc: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b7fbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b7fc0: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1b7fc0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1b7fc4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b7fc4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b7fc8: 0x3c020031  lui         $v0, 0x31
    ctx->pc = 0x1b7fc8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49 << 16));
    // 0x1b7fcc: 0x24426350  addiu       $v0, $v0, 0x6350
    ctx->pc = 0x1b7fccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 25424));
    // 0x1b7fd0: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x1b7fd0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b7fd4: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1b7fd4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b7fd8: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x1b7fd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1b7fdc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B7FDCu;
    {
        const bool branch_taken_0x1b7fdc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b7fdc) {
            ctx->pc = 0x1B7FECu;
            goto label_1b7fec;
        }
    }
    ctx->pc = 0x1B7FE4u;
    // 0x1b7fe4: 0x40f809  jalr        $v0
    ctx->pc = 0x1B7FE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1B7FECu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1B7FECu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7FECu: goto label_1b7fec;
            case 0x1B7FFCu: goto label_1b7ffc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1B7FECu; }
            if (ctx->pc != 0x1B7FECu) { return; }
        }
        }
    }
    ctx->pc = 0x1B7FECu;
label_1b7fec:
    // 0x1b7fec: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b7fecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7ff0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b7ff0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7ff4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B7FF4u;
    SET_GPR_U32(ctx, 31, 0x1B7FFCu);
    ctx->pc = 0x1B7FF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7FF4u;
            // 0x1b7ff8: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7FFCu; }
        if (ctx->pc != 0x1B7FFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7FFCu; }
        if (ctx->pc != 0x1B7FFCu) { return; }
    }
    ctx->pc = 0x1B7FFCu;
label_1b7ffc:
    // 0x1b7ffc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b7ffcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b8000: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b8000u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b8004: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8004u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B8008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8004u;
            // 0x1b8008: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7FECu: goto label_1b7fec;
            case 0x1B7FFCu: goto label_1b7ffc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B800Cu;
    // 0x1b800c: 0x0  nop
    ctx->pc = 0x1b800cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
