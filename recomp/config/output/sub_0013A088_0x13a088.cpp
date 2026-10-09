#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013A088
// Address: 0x13a088 - 0x13a130
void sub_0013A088_0x13a088(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013A088_0x13a088");
#endif

    switch (ctx->pc) {
        case 0x13a0a4u: goto label_13a0a4;
        case 0x13a0c4u: goto label_13a0c4;
        case 0x13a0ccu: goto label_13a0cc;
        case 0x13a0d4u: goto label_13a0d4;
        case 0x13a0dcu: goto label_13a0dc;
        case 0x13a0e8u: goto label_13a0e8;
        case 0x13a10cu: goto label_13a10c;
        default: break;
    }

    ctx->pc = 0x13a088u;

    // 0x13a088: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x13a088u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x13a08c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x13a08cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a090: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x13a090u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x13a094: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x13a094u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x13a098: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x13a098u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x13a09c: 0xc04ea80  jal         func_13AA00
    ctx->pc = 0x13A09Cu;
    SET_GPR_U32(ctx, 31, 0x13A0A4u);
    ctx->pc = 0x13A0A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A09Cu;
            // 0x13a0a0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AA00u;
    if (runtime->hasFunction(0x13AA00u)) {
        auto targetFn = runtime->lookupFunction(0x13AA00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A0A4u; }
        if (ctx->pc != 0x13A0A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AA00_0x13aa00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A0A4u; }
        if (ctx->pc != 0x13A0A4u) { return; }
    }
    ctx->pc = 0x13A0A4u;
label_13a0a4:
    // 0x13a0a4: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x13a0a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x13a0a8: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13a0a8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13a0ac: 0x2471d7a0  addiu       $s1, $v1, -0x2860
    ctx->pc = 0x13a0acu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 4294956960));
    // 0x13a0b0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13a0b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a0b4: 0x14400019  bnez        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x13A0B4u;
    {
        const bool branch_taken_0x13a0b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13A0B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A0B4u;
            // 0x13a0b8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a0b4) {
            ctx->pc = 0x13A11Cu;
            goto label_13a11c;
        }
    }
    ctx->pc = 0x13A0BCu;
    // 0x13a0bc: 0xc04e892  jal         func_13A248
    ctx->pc = 0x13A0BCu;
    SET_GPR_U32(ctx, 31, 0x13A0C4u);
    ctx->pc = 0x13A248u;
    if (runtime->hasFunction(0x13A248u)) {
        auto targetFn = runtime->lookupFunction(0x13A248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A0C4u; }
        if (ctx->pc != 0x13A0C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A248_0x13a248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A0C4u; }
        if (ctx->pc != 0x13A0C4u) { return; }
    }
    ctx->pc = 0x13A0C4u;
label_13a0c4:
    // 0x13a0c4: 0xc04e082  jal         func_138208
    ctx->pc = 0x13A0C4u;
    SET_GPR_U32(ctx, 31, 0x13A0CCu);
    ctx->pc = 0x13A0C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A0C4u;
            // 0x13a0c8: 0x34048400  ori         $a0, $zero, 0x8400 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33792);
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A0CCu; }
        if (ctx->pc != 0x13A0CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A0CCu; }
        if (ctx->pc != 0x13A0CCu) { return; }
    }
    ctx->pc = 0x13A0CCu;
label_13a0cc:
    // 0x13a0cc: 0xc04035e  jal         func_100D78
    ctx->pc = 0x13A0CCu;
    SET_GPR_U32(ctx, 31, 0x13A0D4u);
    ctx->pc = 0x13A0D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A0CCu;
            // 0x13a0d0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100D78u;
    if (runtime->hasFunction(0x100D78u)) {
        auto targetFn = runtime->lookupFunction(0x100D78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A0D4u; }
        if (ctx->pc != 0x13A0D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A0D4u; }
        if (ctx->pc != 0x13A0D4u) { return; }
    }
    ctx->pc = 0x13A0D4u;
label_13a0d4:
    // 0x13a0d4: 0xc04e082  jal         func_138208
    ctx->pc = 0x13A0D4u;
    SET_GPR_U32(ctx, 31, 0x13A0DCu);
    ctx->pc = 0x13A0D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A0D4u;
            // 0x13a0d8: 0x34048401  ori         $a0, $zero, 0x8401 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33793);
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A0DCu; }
        if (ctx->pc != 0x13A0DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A0DCu; }
        if (ctx->pc != 0x13A0DCu) { return; }
    }
    ctx->pc = 0x13A0DCu;
label_13a0dc:
    // 0x13a0dc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x13a0dcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a0e0: 0xc04e58a  jal         func_139628
    ctx->pc = 0x13A0E0u;
    SET_GPR_U32(ctx, 31, 0x13A0E8u);
    ctx->pc = 0x13A0E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A0E0u;
            // 0x13a0e4: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139628u;
    if (runtime->hasFunction(0x139628u)) {
        auto targetFn = runtime->lookupFunction(0x139628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A0E8u; }
        if (ctx->pc != 0x13A0E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139628_0x139628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A0E8u; }
        if (ctx->pc != 0x13A0E8u) { return; }
    }
    ctx->pc = 0x13A0E8u;
label_13a0e8:
    // 0x13a0e8: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x13A0E8u;
    {
        const bool branch_taken_0x13a0e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13A0ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A0E8u;
            // 0x13a0ec: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a0e8) {
            ctx->pc = 0x13A118u;
            goto label_13a118;
        }
    }
    ctx->pc = 0x13A0F0u;
    // 0x13a0f0: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13a0f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13a0f4: 0x8c43d8e8  lw          $v1, -0x2718($v0)
    ctx->pc = 0x13a0f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957288)));
    // 0x13a0f8: 0x10640004  beq         $v1, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13A0F8u;
    {
        const bool branch_taken_0x13a0f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x13A0FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A0F8u;
            // 0x13a0fc: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a0f8) {
            ctx->pc = 0x13A10Cu;
            goto label_13a10c;
        }
    }
    ctx->pc = 0x13A100u;
    // 0x13a100: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13a100u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13a104: 0xc045a12  jal         func_116848
    ctx->pc = 0x13A104u;
    SET_GPR_U32(ctx, 31, 0x13A10Cu);
    ctx->pc = 0x13A108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A104u;
            // 0x13a108: 0x2484cab8  addiu       $a0, $a0, -0x3548 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953656));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A10Cu; }
        if (ctx->pc != 0x13A10Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A10Cu; }
        if (ctx->pc != 0x13A10Cu) { return; }
    }
    ctx->pc = 0x13A10Cu;
label_13a10c:
    // 0x13a10c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x13A10Cu;
    {
        const bool branch_taken_0x13a10c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A10Cu;
            // 0x13a110: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a10c) {
            ctx->pc = 0x13A11Cu;
            goto label_13a11c;
        }
    }
    ctx->pc = 0x13A114u;
    // 0x13a114: 0x0  nop
    ctx->pc = 0x13a114u;
    // NOP
label_13a118:
    // 0x13a118: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x13a118u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
label_13a11c:
    // 0x13a11c: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x13a11cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13a120: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x13a120u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x13a124: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x13a124u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x13a128: 0x3e00008  jr          $ra
    ctx->pc = 0x13A128u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13A12Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A128u;
            // 0x13a12c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13A0A4u: goto label_13a0a4;
            case 0x13A0C4u: goto label_13a0c4;
            case 0x13A0CCu: goto label_13a0cc;
            case 0x13A0D4u: goto label_13a0d4;
            case 0x13A0DCu: goto label_13a0dc;
            case 0x13A0E8u: goto label_13a0e8;
            case 0x13A10Cu: goto label_13a10c;
            case 0x13A118u: goto label_13a118;
            case 0x13A11Cu: goto label_13a11c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13A130u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
