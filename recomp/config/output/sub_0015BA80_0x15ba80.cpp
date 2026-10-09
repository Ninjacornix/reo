#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015BA80
// Address: 0x15ba80 - 0x15baf0
void sub_0015BA80_0x15ba80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015BA80_0x15ba80");
#endif

    switch (ctx->pc) {
        case 0x15bad8u: goto label_15bad8;
        default: break;
    }

    ctx->pc = 0x15ba80u;

    // 0x15ba80: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x15ba80u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ba84: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x15ba84u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ba88: 0x820018  mult        $zero, $a0, $v0
    ctx->pc = 0x15ba88u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x15ba8c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ba8cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ba90: 0x822026  xor         $a0, $a0, $v0
    ctx->pc = 0x15ba90u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) ^ GPR_U64(ctx, 2));
    // 0x15ba94: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ba94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ba98: 0x28840000  slti        $a0, $a0, 0x0
    ctx->pc = 0x15ba98u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x15ba9c: 0x3812  mflo        $a3
    ctx->pc = 0x15ba9cu;
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x15baa0: 0x1810  mfhi        $v1
    ctx->pc = 0x15baa0u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x15baa4: 0x7383c  dsll32      $a3, $a3, 0
    ctx->pc = 0x15baa4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) << (32 + 0));
    // 0x15baa8: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x15baa8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x15baac: 0x7383e  dsrl32      $a3, $a3, 0
    ctx->pc = 0x15baacu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) >> (32 + 0));
    // 0x15bab0: 0x14c00007  bnez        $a2, . + 4 + (0x7 << 2)
    ctx->pc = 0x15BAB0u;
    {
        const bool branch_taken_0x15bab0 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x15BAB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BAB0u;
            // 0x15bab4: 0x671825  or          $v1, $v1, $a3 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15bab0) {
            ctx->pc = 0x15BAD0u;
            goto label_15bad0;
        }
    }
    ctx->pc = 0x15BAB8u;
    // 0x15bab8: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x15bab8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x15babc: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x15babcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x15bac0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x15bac0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x15bac4: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x15BAC4u;
    {
        const bool branch_taken_0x15bac4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15BAC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BAC4u;
            // 0x15bac8: 0x64100b  movn        $v0, $v1, $a0 (Delay Slot)
        if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15bac4) {
            ctx->pc = 0x15BAE0u;
            goto label_15bae0;
        }
    }
    ctx->pc = 0x15BACCu;
    // 0x15bacc: 0x0  nop
    ctx->pc = 0x15baccu;
    // NOP
label_15bad0:
    // 0x15bad0: 0xc043ec6  jal         func_10FB18
    ctx->pc = 0x15BAD0u;
    SET_GPR_U32(ctx, 31, 0x15BAD8u);
    ctx->pc = 0x15BAD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BAD0u;
            // 0x15bad4: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FB18u;
    if (runtime->hasFunction(0x10FB18u)) {
        auto targetFn = runtime->lookupFunction(0x10FB18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BAD8u; }
        if (ctx->pc != 0x15BAD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BAD8u; }
        if (ctx->pc != 0x15BAD8u) { return; }
    }
    ctx->pc = 0x15BAD8u;
label_15bad8:
    // 0x15bad8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x15bad8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x15badc: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x15badcu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
label_15bae0:
    // 0x15bae0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15bae0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15bae4: 0x3e00008  jr          $ra
    ctx->pc = 0x15BAE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15BAE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BAE4u;
            // 0x15bae8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15BAD0u: goto label_15bad0;
            case 0x15BAD8u: goto label_15bad8;
            case 0x15BAE0u: goto label_15bae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15BAECu;
    // 0x15baec: 0x0  nop
    ctx->pc = 0x15baecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
