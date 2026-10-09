#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001383E8
// Address: 0x1383e8 - 0x1384a0
void sub_001383E8_0x1383e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001383E8_0x1383e8");
#endif

    switch (ctx->pc) {
        case 0x13840cu: goto label_13840c;
        case 0x138434u: goto label_138434;
        case 0x138450u: goto label_138450;
        case 0x138460u: goto label_138460;
        case 0x13847cu: goto label_13847c;
        case 0x138484u: goto label_138484;
        default: break;
    }

    ctx->pc = 0x1383e8u;

    // 0x1383e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1383e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1383ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1383ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1383f0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1383f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1383f4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1383f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1383f8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1383f8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1383fc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1383fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x138400: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x138400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x138404: 0xc04e0bc  jal         func_1382F0
    ctx->pc = 0x138404u;
    SET_GPR_U32(ctx, 31, 0x13840Cu);
    ctx->pc = 0x138408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138404u;
            // 0x138408: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1382F0u;
    if (runtime->hasFunction(0x1382F0u)) {
        auto targetFn = runtime->lookupFunction(0x1382F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13840Cu; }
        if (ctx->pc != 0x13840Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001382F0_0x1382f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13840Cu; }
        if (ctx->pc != 0x13840Cu) { return; }
    }
    ctx->pc = 0x13840Cu;
label_13840c:
    // 0x13840c: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13840cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x138410: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x138410u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x138414: 0x8c47bbf8  lw          $a3, -0x4408($v0)
    ctx->pc = 0x138414u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949880)));
    // 0x138418: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x138418u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13841c: 0x11283c  dsll32      $a1, $s1, 0
    ctx->pc = 0x13841cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 17) << (32 + 0));
    // 0x138420: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x138420u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x138424: 0x14e3000c  bne         $a3, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x138424u;
    {
        const bool branch_taken_0x138424 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 3));
        ctx->pc = 0x138428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138424u;
            // 0x138428: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138424) {
            ctx->pc = 0x138458u;
            goto label_138458;
        }
    }
    ctx->pc = 0x13842Cu;
    // 0x13842c: 0xc046c04  jal         func_11B010
    ctx->pc = 0x13842Cu;
    SET_GPR_U32(ctx, 31, 0x138434u);
    ctx->pc = 0x138430u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13842Cu;
            // 0x138430: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B010u;
    if (runtime->hasFunction(0x11B010u)) {
        auto targetFn = runtime->lookupFunction(0x11B010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138434u; }
        if (ctx->pc != 0x138434u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B010_0x11b010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138434u; }
        if (ctx->pc != 0x138434u) { return; }
    }
    ctx->pc = 0x138434u;
label_138434:
    // 0x138434: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138434u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138438: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x138438u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13843c: 0x2484c700  addiu       $a0, $a0, -0x3900
    ctx->pc = 0x13843cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952704));
    // 0x138440: 0x601000e  bgez        $s0, . + 4 + (0xE << 2)
    ctx->pc = 0x138440u;
    {
        const bool branch_taken_0x138440 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x138444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138440u;
            // 0x138444: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138440) {
            ctx->pc = 0x13847Cu;
            goto label_13847c;
        }
    }
    ctx->pc = 0x138448u;
    // 0x138448: 0xc045a12  jal         func_116848
    ctx->pc = 0x138448u;
    SET_GPR_U32(ctx, 31, 0x138450u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138450u; }
        if (ctx->pc != 0x138450u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138450u; }
        if (ctx->pc != 0x138450u) { return; }
    }
    ctx->pc = 0x138450u;
label_138450:
    // 0x138450: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x138450u;
    {
        const bool branch_taken_0x138450 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x138450) {
            ctx->pc = 0x13847Cu;
            goto label_13847c;
        }
    }
    ctx->pc = 0x138458u;
label_138458:
    // 0x138458: 0xc04639e  jal         func_118E78
    ctx->pc = 0x138458u;
    SET_GPR_U32(ctx, 31, 0x138460u);
    ctx->pc = 0x118E78u;
    if (runtime->hasFunction(0x118E78u)) {
        auto targetFn = runtime->lookupFunction(0x118E78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138460u; }
        if (ctx->pc != 0x138460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118E78_0x118e78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138460u; }
        if (ctx->pc != 0x138460u) { return; }
    }
    ctx->pc = 0x138460u;
label_138460:
    // 0x138460: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138460u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138464: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x138464u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138468: 0x2484c720  addiu       $a0, $a0, -0x38E0
    ctx->pc = 0x138468u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952736));
    // 0x13846c: 0x6010003  bgez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13846Cu;
    {
        const bool branch_taken_0x13846c = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x138470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13846Cu;
            // 0x138470: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13846c) {
            ctx->pc = 0x13847Cu;
            goto label_13847c;
        }
    }
    ctx->pc = 0x138474u;
    // 0x138474: 0xc045a12  jal         func_116848
    ctx->pc = 0x138474u;
    SET_GPR_U32(ctx, 31, 0x13847Cu);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13847Cu; }
        if (ctx->pc != 0x13847Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13847Cu; }
        if (ctx->pc != 0x13847Cu) { return; }
    }
    ctx->pc = 0x13847Cu;
label_13847c:
    // 0x13847c: 0xc04e0ca  jal         func_138328
    ctx->pc = 0x13847Cu;
    SET_GPR_U32(ctx, 31, 0x138484u);
    ctx->pc = 0x138328u;
    if (runtime->hasFunction(0x138328u)) {
        auto targetFn = runtime->lookupFunction(0x138328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138484u; }
        if (ctx->pc != 0x138484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138328_0x138328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138484u; }
        if (ctx->pc != 0x138484u) { return; }
    }
    ctx->pc = 0x138484u;
label_138484:
    // 0x138484: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x138484u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138488: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x138488u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13848c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13848cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138490: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x138490u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x138494: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x138494u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x138498: 0x3e00008  jr          $ra
    ctx->pc = 0x138498u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13849Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138498u;
            // 0x13849c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13840Cu: goto label_13840c;
            case 0x138434u: goto label_138434;
            case 0x138450u: goto label_138450;
            case 0x138458u: goto label_138458;
            case 0x138460u: goto label_138460;
            case 0x13847Cu: goto label_13847c;
            case 0x138484u: goto label_138484;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1384A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
