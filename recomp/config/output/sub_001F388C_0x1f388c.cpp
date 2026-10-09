#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F388C
// Address: 0x1f388c - 0x1f3900
void sub_001F388C_0x1f388c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F388C_0x1f388c");
#endif

    switch (ctx->pc) {
        case 0x1f38bcu: goto label_1f38bc;
        case 0x1f38e0u: goto label_1f38e0;
        default: break;
    }

    ctx->pc = 0x1f388cu;

    // 0x1f388c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f388cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f3890: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1f3890u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1f3894: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1f3894u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1f3898: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f3898u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f389c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f389cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f38a0: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f38a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f38a4: 0x27c20010  addiu       $v0, $fp, 0x10
    ctx->pc = 0x1f38a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1f38a8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f38a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f38ac: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1f38acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f38b0: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1f38b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1f38b4: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F38B4u;
    SET_GPR_U32(ctx, 31, 0x1F38BCu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F38BCu; }
        if (ctx->pc != 0x1F38BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F38BCu; }
        if (ctx->pc != 0x1F38BCu) { return; }
    }
    ctx->pc = 0x1F38BCu;
label_1f38bc:
    // 0x1f38bc: 0x97c20010  lhu         $v0, 0x10($fp)
    ctx->pc = 0x1f38bcu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f38c0: 0x304203ff  andi        $v0, $v0, 0x3FF
    ctx->pc = 0x1f38c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1023);
    // 0x1f38c4: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1f38c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f38c8: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f38c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f38cc: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f38ccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f38d0: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1f38d0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f38d4: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1f38d4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f38d8: 0xc07cd5f  jal         func_1F357C
    ctx->pc = 0x1F38D8u;
    SET_GPR_U32(ctx, 31, 0x1F38E0u);
    ctx->pc = 0x1F357Cu;
    if (runtime->hasFunction(0x1F357Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F357Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F38E0u; }
        if (ctx->pc != 0x1F38E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F357C_0x1f357c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F38E0u; }
        if (ctx->pc != 0x1F38E0u) { return; }
    }
    ctx->pc = 0x1F38E0u;
label_1f38e0:
    // 0x1f38e0: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1f38e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1f38e4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f38e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f38e8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f38e8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f38ec: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1f38ecu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f38f0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1f38f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1f38f4: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1f38f4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f38f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F38F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F38BCu: goto label_1f38bc;
            case 0x1F38E0u: goto label_1f38e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F3900u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
