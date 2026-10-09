#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AA3E0
// Address: 0x1aa3e0 - 0x1aa480
void sub_001AA3E0_0x1aa3e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AA3E0_0x1aa3e0");
#endif

    switch (ctx->pc) {
        case 0x1aa404u: goto label_1aa404;
        case 0x1aa41cu: goto label_1aa41c;
        case 0x1aa454u: goto label_1aa454;
        case 0x1aa46cu: goto label_1aa46c;
        default: break;
    }

    ctx->pc = 0x1aa3e0u;

    // 0x1aa3e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1aa3e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1aa3e4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aa3e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aa3e8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1aa3e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1aa3ec: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1aa3ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1aa3f0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1aa3f0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1aa3f4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1aa3f4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa3f8: 0x942443da  lhu         $a0, 0x43DA($at)
    ctx->pc = 0x1aa3f8u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1aa3fc: 0xc06a878  jal         func_1AA1E0
    ctx->pc = 0x1AA3FCu;
    SET_GPR_U32(ctx, 31, 0x1AA404u);
    ctx->pc = 0x1AA400u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA3FCu;
            // 0x1aa400: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA1E0u;
    if (runtime->hasFunction(0x1AA1E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AA1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA404u; }
        if (ctx->pc != 0x1AA404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA1E0_0x1aa1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA404u; }
        if (ctx->pc != 0x1AA404u) { return; }
    }
    ctx->pc = 0x1AA404u;
label_1aa404:
    // 0x1aa404: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa404u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa408: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1aa408u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa40c: 0x8c2416a0  lw          $a0, 0x16A0($at)
    ctx->pc = 0x1aa40cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5792)));
    // 0x1aa410: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1aa410u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa414: 0xc06a7c8  jal         func_1A9F20
    ctx->pc = 0x1AA414u;
    SET_GPR_U32(ctx, 31, 0x1AA41Cu);
    ctx->pc = 0x1AA418u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA414u;
            // 0x1aa418: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9F20u;
    if (runtime->hasFunction(0x1A9F20u)) {
        auto targetFn = runtime->lookupFunction(0x1A9F20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA41Cu; }
        if (ctx->pc != 0x1AA41Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9F20_0x1a9f20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA41Cu; }
        if (ctx->pc != 0x1AA41Cu) { return; }
    }
    ctx->pc = 0x1AA41Cu;
label_1aa41c:
    // 0x1aa41c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1aa41cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1aa420: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1aa420u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1aa424: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1aa424u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aa428: 0x3e00008  jr          $ra
    ctx->pc = 0x1AA428u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AA42Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA428u;
            // 0x1aa42c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AA404u: goto label_1aa404;
            case 0x1AA41Cu: goto label_1aa41c;
            case 0x1AA454u: goto label_1aa454;
            case 0x1AA46Cu: goto label_1aa46c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AA430u;
    // 0x1aa430: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1aa430u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1aa434: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aa434u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aa438: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1aa438u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1aa43c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1aa43cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1aa440: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1aa440u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1aa444: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1aa444u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa448: 0x942443da  lhu         $a0, 0x43DA($at)
    ctx->pc = 0x1aa448u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1aa44c: 0xc06a878  jal         func_1AA1E0
    ctx->pc = 0x1AA44Cu;
    SET_GPR_U32(ctx, 31, 0x1AA454u);
    ctx->pc = 0x1AA450u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA44Cu;
            // 0x1aa450: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA1E0u;
    if (runtime->hasFunction(0x1AA1E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AA1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA454u; }
        if (ctx->pc != 0x1AA454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA1E0_0x1aa1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA454u; }
        if (ctx->pc != 0x1AA454u) { return; }
    }
    ctx->pc = 0x1AA454u;
label_1aa454:
    // 0x1aa454: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa454u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa458: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1aa458u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa45c: 0x8c2416a0  lw          $a0, 0x16A0($at)
    ctx->pc = 0x1aa45cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5792)));
    // 0x1aa460: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1aa460u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa464: 0xc06a7c8  jal         func_1A9F20
    ctx->pc = 0x1AA464u;
    SET_GPR_U32(ctx, 31, 0x1AA46Cu);
    ctx->pc = 0x1AA468u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA464u;
            // 0x1aa468: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9F20u;
    if (runtime->hasFunction(0x1A9F20u)) {
        auto targetFn = runtime->lookupFunction(0x1A9F20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA46Cu; }
        if (ctx->pc != 0x1AA46Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9F20_0x1a9f20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA46Cu; }
        if (ctx->pc != 0x1AA46Cu) { return; }
    }
    ctx->pc = 0x1AA46Cu;
label_1aa46c:
    // 0x1aa46c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1aa46cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1aa470: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1aa470u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1aa474: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1aa474u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aa478: 0x3e00008  jr          $ra
    ctx->pc = 0x1AA478u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AA47Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA478u;
            // 0x1aa47c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AA404u: goto label_1aa404;
            case 0x1AA41Cu: goto label_1aa41c;
            case 0x1AA454u: goto label_1aa454;
            case 0x1AA46Cu: goto label_1aa46c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AA480u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
