#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132FE8
// Address: 0x132fe8 - 0x133058
void sub_00132FE8_0x132fe8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132FE8_0x132fe8");
#endif

    ctx->pc = 0x132fe8u;

    // 0x132fe8: 0x3e00008  jr          $ra
    ctx->pc = 0x132FE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x132FF0u;
    // 0x132ff0: 0x3e00008  jr          $ra
    ctx->pc = 0x132FF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132FF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132FF0u;
            // 0x132ff4: 0x8c820008  lw          $v0, 0x8($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x132FF8u;
    // 0x132ff8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132ff8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132ffc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x132ffcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x133000: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x133000u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x133004: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x133004u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133008: 0x804b314  j           func_12CC50
    ctx->pc = 0x133008u;
    ctx->pc = 0x13300Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133008u;
            // 0x13300c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CC50u;
    if (runtime->hasFunction(0x12CC50u)) {
        auto targetFn = runtime->lookupFunction(0x12CC50u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012CC50_0x12cc50(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133010u;
    // 0x133010: 0x3e00008  jr          $ra
    ctx->pc = 0x133010u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x133018u;
    // 0x133018: 0x3e00008  jr          $ra
    ctx->pc = 0x133018u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13301Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133018u;
            // 0x13301c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x133020u;
    // 0x133020: 0x3e00008  jr          $ra
    ctx->pc = 0x133020u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x133028u;
    // 0x133028: 0x3e00008  jr          $ra
    ctx->pc = 0x133028u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x133030u;
    // 0x133030: 0x3e00008  jr          $ra
    ctx->pc = 0x133030u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x133038u;
    // 0x133038: 0x3e00008  jr          $ra
    ctx->pc = 0x133038u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x133040u;
    // 0x133040: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x133040u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x133044: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x133044u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x133048: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x133048u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13304c: 0x804a02a  j           func_1280A8
    ctx->pc = 0x13304Cu;
    ctx->pc = 0x133050u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13304Cu;
            // 0x133050: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280A8u;
    if (runtime->hasFunction(0x1280A8u)) {
        auto targetFn = runtime->lookupFunction(0x1280A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280A8_0x1280a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133054u;
    // 0x133054: 0x0  nop
    ctx->pc = 0x133054u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
