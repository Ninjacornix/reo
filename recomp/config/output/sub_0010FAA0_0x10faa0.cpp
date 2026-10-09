#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010FAA0
// Address: 0x10faa0 - 0x10fb18
void sub_0010FAA0_0x10faa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010FAA0_0x10faa0");
#endif

    ctx->pc = 0x10faa0u;

    // 0x10faa0: 0x5103c  dsll32      $v0, $a1, 0
    ctx->pc = 0x10faa0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) << (32 + 0));
    // 0x10faa4: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x10faa4u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x10faa8: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x10faa8u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x10faac: 0x4183c  dsll32      $v1, $a0, 0
    ctx->pc = 0x10faacu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 0));
    // 0x10fab0: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x10fab0u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x10fab4: 0x620019  multu       $v1, $v0
    ctx->pc = 0x10fab4u;
    { uint64_t result = (uint64_t)GPR_U32(ctx, 3) * (uint64_t)GPR_U32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x10fab8: 0x3012  mflo        $a2
    ctx->pc = 0x10fab8u;
    SET_GPR_U64(ctx, 6, ctx->lo);
    // 0x10fabc: 0x4010  mfhi        $t0
    ctx->pc = 0x10fabcu;
    SET_GPR_U64(ctx, 8, ctx->hi);
    // 0x10fac0: 0x6303c  dsll32      $a2, $a2, 0
    ctx->pc = 0x10fac0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 0));
    // 0x10fac4: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x10fac4u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x10fac8: 0x651818  mult        $v1, $v1, $a1
    ctx->pc = 0x10fac8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x10facc: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x10faccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10fad0: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x10fad0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x10fad4: 0x70822018  mult1       $a0, $a0, $v0
    ctx->pc = 0x10fad4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 2); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x10fad8: 0x6303e  dsrl32      $a2, $a2, 0
    ctx->pc = 0x10fad8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x10fadc: 0x1254824  and         $t1, $t1, $a1
    ctx->pc = 0x10fadcu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) & GPR_U64(ctx, 5));
    // 0x10fae0: 0x3c07ffff  lui         $a3, 0xFFFF
    ctx->pc = 0x10fae0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)65535 << 16));
    // 0x10fae4: 0x7383e  dsrl32      $a3, $a3, 0
    ctx->pc = 0x10fae4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) >> (32 + 0));
    // 0x10fae8: 0x1264825  or          $t1, $t1, $a2
    ctx->pc = 0x10fae8u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 6));
    // 0x10faec: 0x8403c  dsll32      $t0, $t0, 0
    ctx->pc = 0x10faecu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) << (32 + 0));
    // 0x10faf0: 0x1274824  and         $t1, $t1, $a3
    ctx->pc = 0x10faf0u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) & GPR_U64(ctx, 7));
    // 0x10faf4: 0x1284825  or          $t1, $t1, $t0
    ctx->pc = 0x10faf4u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 8));
    // 0x10faf8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x10faf8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x10fafc: 0x9103f  dsra32      $v0, $t1, 0
    ctx->pc = 0x10fafcu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 9) >> (32 + 0));
    // 0x10fb00: 0x1273824  and         $a3, $t1, $a3
    ctx->pc = 0x10fb00u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 9) & GPR_U64(ctx, 7));
    // 0x10fb04: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x10fb04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x10fb08: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x10fb08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10fb0c: 0x3e00008  jr          $ra
    ctx->pc = 0x10FB0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10FB10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FB0Cu;
            // 0x10fb10: 0xe21025  or          $v0, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x10FB14u;
    // 0x10fb14: 0x0  nop
    ctx->pc = 0x10fb14u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
