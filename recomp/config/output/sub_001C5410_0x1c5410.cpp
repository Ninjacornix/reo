#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5410
// Address: 0x1c5410 - 0x1c5480
void sub_001C5410_0x1c5410(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5410_0x1c5410");
#endif

    switch (ctx->pc) {
        case 0x1c5438u: goto label_1c5438;
        case 0x1c5440u: goto label_1c5440;
        case 0x1c5448u: goto label_1c5448;
        case 0x1c5454u: goto label_1c5454;
        case 0x1c545cu: goto label_1c545c;
        case 0x1c5464u: goto label_1c5464;
        default: break;
    }

    ctx->pc = 0x1c5410u;

    // 0x1c5410: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1c5410u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1c5414: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1c5414u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1c5418: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c5418u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c541c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c541cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c5420: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c5420u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c5424: 0x8c9200e8  lw          $s2, 0xE8($a0)
    ctx->pc = 0x1c5424u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 232)));
    // 0x1c5428: 0x26510008  addiu       $s1, $s2, 0x8
    ctx->pc = 0x1c5428u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), 8));
    // 0x1c542c: 0x26500108  addiu       $s0, $s2, 0x108
    ctx->pc = 0x1c542cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 264));
    // 0x1c5430: 0xc06fd98  jal         func_1BF660
    ctx->pc = 0x1C5430u;
    SET_GPR_U32(ctx, 31, 0x1C5438u);
    ctx->pc = 0x1C5434u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5430u;
            // 0x1c5434: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BF660u;
    if (runtime->hasFunction(0x1BF660u)) {
        auto targetFn = runtime->lookupFunction(0x1BF660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5438u; }
        if (ctx->pc != 0x1C5438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF660_0x1bf660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5438u; }
        if (ctx->pc != 0x1C5438u) { return; }
    }
    ctx->pc = 0x1C5438u;
label_1c5438:
    // 0x1c5438: 0xc0714ac  jal         func_1C52B0
    ctx->pc = 0x1C5438u;
    SET_GPR_U32(ctx, 31, 0x1C5440u);
    ctx->pc = 0x1C543Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5438u;
            // 0x1c543c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C52B0u;
    if (runtime->hasFunction(0x1C52B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C52B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5440u; }
        if (ctx->pc != 0x1C5440u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C52B0_0x1c52b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5440u; }
        if (ctx->pc != 0x1C5440u) { return; }
    }
    ctx->pc = 0x1C5440u;
label_1c5440:
    // 0x1c5440: 0xc0714c0  jal         func_1C5300
    ctx->pc = 0x1C5440u;
    SET_GPR_U32(ctx, 31, 0x1C5448u);
    ctx->pc = 0x1C5444u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5440u;
            // 0x1c5444: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C5300u;
    if (runtime->hasFunction(0x1C5300u)) {
        auto targetFn = runtime->lookupFunction(0x1C5300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5448u; }
        if (ctx->pc != 0x1C5448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5300_0x1c5300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5448u; }
        if (ctx->pc != 0x1C5448u) { return; }
    }
    ctx->pc = 0x1C5448u;
label_1c5448:
    // 0x1c5448: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1c5448u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c544c: 0xc0714d0  jal         func_1C5340
    ctx->pc = 0x1C544Cu;
    SET_GPR_U32(ctx, 31, 0x1C5454u);
    ctx->pc = 0x1C5450u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C544Cu;
            // 0x1c5450: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C5340u;
    if (runtime->hasFunction(0x1C5340u)) {
        auto targetFn = runtime->lookupFunction(0x1C5340u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5454u; }
        if (ctx->pc != 0x1C5454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5340_0x1c5340(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5454u; }
        if (ctx->pc != 0x1C5454u) { return; }
    }
    ctx->pc = 0x1C5454u;
label_1c5454:
    // 0x1c5454: 0xc0714ec  jal         func_1C53B0
    ctx->pc = 0x1C5454u;
    SET_GPR_U32(ctx, 31, 0x1C545Cu);
    ctx->pc = 0x1C5458u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5454u;
            // 0x1c5458: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C53B0u;
    if (runtime->hasFunction(0x1C53B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C53B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C545Cu; }
        if (ctx->pc != 0x1C545Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C53B0_0x1c53b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C545Cu; }
        if (ctx->pc != 0x1C545Cu) { return; }
    }
    ctx->pc = 0x1C545Cu;
label_1c545c:
    // 0x1c545c: 0xc0715a8  jal         func_1C56A0
    ctx->pc = 0x1C545Cu;
    SET_GPR_U32(ctx, 31, 0x1C5464u);
    ctx->pc = 0x1C5460u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C545Cu;
            // 0x1c5460: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C56A0u;
    if (runtime->hasFunction(0x1C56A0u)) {
        auto targetFn = runtime->lookupFunction(0x1C56A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5464u; }
        if (ctx->pc != 0x1C5464u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C56A0_0x1c56a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5464u; }
        if (ctx->pc != 0x1C5464u) { return; }
    }
    ctx->pc = 0x1C5464u;
label_1c5464:
    // 0x1c5464: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1c5464u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c5468: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c5468u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c546c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c546cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c5470: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c5470u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c5474: 0x3e00008  jr          $ra
    ctx->pc = 0x1C5474u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C5478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5474u;
            // 0x1c5478: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C5438u: goto label_1c5438;
            case 0x1C5440u: goto label_1c5440;
            case 0x1C5448u: goto label_1c5448;
            case 0x1C5454u: goto label_1c5454;
            case 0x1C545Cu: goto label_1c545c;
            case 0x1C5464u: goto label_1c5464;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C547Cu;
    // 0x1c547c: 0x0  nop
    ctx->pc = 0x1c547cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
