#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F30A0
// Address: 0x1f30a0 - 0x1f30f0
void sub_001F30A0_0x1f30a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F30A0_0x1f30a0");
#endif

    switch (ctx->pc) {
        case 0x1f30c8u: goto label_1f30c8;
        case 0x1f30d4u: goto label_1f30d4;
        default: break;
    }

    ctx->pc = 0x1f30a0u;

    // 0x1f30a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f30a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f30a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1f30a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1f30a8: 0xffbe0008  sd          $fp, 0x8($sp)
    ctx->pc = 0x1f30a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 30));
    // 0x1f30ac: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f30acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f30b0: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f30b0u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f30b4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1f30b4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f30b8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f30b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f30bc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f30bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f30c0: 0xc07c6c0  jal         func_1F1B00
    ctx->pc = 0x1F30C0u;
    SET_GPR_U32(ctx, 31, 0x1F30C8u);
    ctx->pc = 0x1F1B00u;
    if (runtime->hasFunction(0x1F1B00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1B00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F30C8u; }
        if (ctx->pc != 0x1F30C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1B00_0x1f1b00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F30C8u; }
        if (ctx->pc != 0x1F30C8u) { return; }
    }
    ctx->pc = 0x1F30C8u;
label_1f30c8:
    // 0x1f30c8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f30c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f30cc: 0xc07cc13  jal         func_1F304C
    ctx->pc = 0x1F30CCu;
    SET_GPR_U32(ctx, 31, 0x1F30D4u);
    ctx->pc = 0x1F304Cu;
    if (runtime->hasFunction(0x1F304Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F304Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F30D4u; }
        if (ctx->pc != 0x1F30D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F304C_0x1f304c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F30D4u; }
        if (ctx->pc != 0x1F30D4u) { return; }
    }
    ctx->pc = 0x1F30D4u;
label_1f30d4:
    // 0x1f30d4: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f30d4u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f30d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1f30d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f30dc: 0xdfbe0008  ld          $fp, 0x8($sp)
    ctx->pc = 0x1f30dcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1f30e0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f30e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f30e4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f30e4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f30e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F30E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F30C8u: goto label_1f30c8;
            case 0x1F30D4u: goto label_1f30d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F30F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
