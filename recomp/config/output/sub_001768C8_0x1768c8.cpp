#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001768C8
// Address: 0x1768c8 - 0x176930
void sub_001768C8_0x1768c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001768C8_0x1768c8");
#endif

    switch (ctx->pc) {
        case 0x1768dcu: goto label_1768dc;
        case 0x176908u: goto label_176908;
        case 0x17691cu: goto label_17691c;
        default: break;
    }

    ctx->pc = 0x1768c8u;

    // 0x1768c8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1768c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1768cc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1768ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1768d0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1768d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1768d4: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1768D4u;
    SET_GPR_U32(ctx, 31, 0x1768DCu);
    ctx->pc = 0x1768D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1768D4u;
            // 0x1768d8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1768DCu; }
        if (ctx->pc != 0x1768DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1768DCu; }
        if (ctx->pc != 0x1768DCu) { return; }
    }
    ctx->pc = 0x1768DCu;
label_1768dc:
    // 0x1768dc: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1768dcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1768e0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1768e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1768e4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1768E4u;
    {
        const bool branch_taken_0x1768e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1768E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1768E4u;
            // 0x1768e8: 0x34a5012a  ori         $a1, $a1, 0x12A (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)298);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1768e4) {
            ctx->pc = 0x176900u;
            goto label_176900;
        }
    }
    ctx->pc = 0x1768ECu;
    // 0x1768ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1768ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1768f0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1768f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1768f4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1768f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1768f8: 0x805a704  j           func_169C10
    ctx->pc = 0x1768F8u;
    ctx->pc = 0x1768FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1768F8u;
            // 0x1768fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x176900u;
label_176900:
    // 0x176900: 0xc05d58a  jal         func_175628
    ctx->pc = 0x176900u;
    SET_GPR_U32(ctx, 31, 0x176908u);
    ctx->pc = 0x176904u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176900u;
            // 0x176904: 0x24050047  addiu       $a1, $zero, 0x47 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176908u; }
        if (ctx->pc != 0x176908u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176908u; }
        if (ctx->pc != 0x176908u) { return; }
    }
    ctx->pc = 0x176908u;
label_176908:
    // 0x176908: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x176908u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17690c: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x17690Cu;
    {
        const bool branch_taken_0x17690c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x176910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17690Cu;
            // 0x176910: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17690c) {
            ctx->pc = 0x17691Cu;
            goto label_17691c;
        }
    }
    ctx->pc = 0x176914u;
    // 0x176914: 0xc05da4c  jal         func_176930
    ctx->pc = 0x176914u;
    SET_GPR_U32(ctx, 31, 0x17691Cu);
    ctx->pc = 0x176930u;
    if (runtime->hasFunction(0x176930u)) {
        auto targetFn = runtime->lookupFunction(0x176930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17691Cu; }
        if (ctx->pc != 0x17691Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176930_0x176930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17691Cu; }
        if (ctx->pc != 0x17691Cu) { return; }
    }
    ctx->pc = 0x17691Cu;
label_17691c:
    // 0x17691c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x17691cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176920: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176920u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176924: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x176924u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176928: 0x3e00008  jr          $ra
    ctx->pc = 0x176928u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17692Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176928u;
            // 0x17692c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1768DCu: goto label_1768dc;
            case 0x176900u: goto label_176900;
            case 0x176908u: goto label_176908;
            case 0x17691Cu: goto label_17691c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176930u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
