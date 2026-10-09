#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016D2B0
// Address: 0x16d2b0 - 0x16d300
void sub_0016D2B0_0x16d2b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016D2B0_0x16d2b0");
#endif

    switch (ctx->pc) {
        case 0x16d2ccu: goto label_16d2cc;
        case 0x16d2e4u: goto label_16d2e4;
        default: break;
    }

    ctx->pc = 0x16d2b0u;

    // 0x16d2b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16d2b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16d2b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16d2b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16d2b8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16d2b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d2bc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16d2bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16d2c0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x16d2c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16d2c4: 0xc05b4c0  jal         func_16D300
    ctx->pc = 0x16D2C4u;
    SET_GPR_U32(ctx, 31, 0x16D2CCu);
    ctx->pc = 0x16D2C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D2C4u;
            // 0x16d2c8: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D300u;
    if (runtime->hasFunction(0x16D300u)) {
        auto targetFn = runtime->lookupFunction(0x16D300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D2CCu; }
        if (ctx->pc != 0x16D2CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D300_0x16d300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D2CCu; }
        if (ctx->pc != 0x16D2CCu) { return; }
    }
    ctx->pc = 0x16D2CCu;
label_16d2cc:
    // 0x16d2cc: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x16d2ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x16d2d0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16d2d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d2d4: 0x10430004  beq         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x16D2D4u;
    {
        const bool branch_taken_0x16d2d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x16D2D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D2D4u;
            // 0x16d2d8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d2d4) {
            ctx->pc = 0x16D2E8u;
            goto label_16d2e8;
        }
    }
    ctx->pc = 0x16D2DCu;
    // 0x16d2dc: 0xc05b542  jal         func_16D508
    ctx->pc = 0x16D2DCu;
    SET_GPR_U32(ctx, 31, 0x16D2E4u);
    ctx->pc = 0x16D508u;
    if (runtime->hasFunction(0x16D508u)) {
        auto targetFn = runtime->lookupFunction(0x16D508u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D2E4u; }
        if (ctx->pc != 0x16D2E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D508_0x16d508(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D2E4u; }
        if (ctx->pc != 0x16D2E4u) { return; }
    }
    ctx->pc = 0x16D2E4u;
label_16d2e4:
    // 0x16d2e4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16d2e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_16d2e8:
    // 0x16d2e8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16d2e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16d2ec: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16d2ecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16d2f0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16d2f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16d2f4: 0x3e00008  jr          $ra
    ctx->pc = 0x16D2F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16D2F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D2F4u;
            // 0x16d2f8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16D2CCu: goto label_16d2cc;
            case 0x16D2E4u: goto label_16d2e4;
            case 0x16D2E8u: goto label_16d2e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16D2FCu;
    // 0x16d2fc: 0x0  nop
    ctx->pc = 0x16d2fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
