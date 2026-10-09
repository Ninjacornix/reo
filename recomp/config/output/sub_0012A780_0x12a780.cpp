#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A780
// Address: 0x12a780 - 0x12a830
void sub_0012A780_0x12a780(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A780_0x12a780");
#endif

    switch (ctx->pc) {
        case 0x12a7c0u: goto label_12a7c0;
        case 0x12a7c8u: goto label_12a7c8;
        case 0x12a7d4u: goto label_12a7d4;
        case 0x12a7e8u: goto label_12a7e8;
        case 0x12a800u: goto label_12a800;
        case 0x12a808u: goto label_12a808;
        case 0x12a810u: goto label_12a810;
        default: break;
    }

    ctx->pc = 0x12a780u;

    // 0x12a780: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12a780u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12a784: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12a784u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12a788: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12a788u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a78c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12a78cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12a790: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x12a790u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x12a794: 0x16000008  bnez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x12A794u;
    {
        const bool branch_taken_0x12a794 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x12A798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A794u;
            // 0x12a798: 0x8e110094  lw          $s1, 0x94($s0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12a794) {
            ctx->pc = 0x12A7B8u;
            goto label_12a7b8;
        }
    }
    ctx->pc = 0x12A79Cu;
    // 0x12a79c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x12a79cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x12a7a0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12a7a0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a7a4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12a7a4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12a7a8: 0x2484a398  addiu       $a0, $a0, -0x5C68
    ctx->pc = 0x12a7a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943640));
    // 0x12a7ac: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x12a7acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12a7b0: 0x804a034  j           func_1280D0
    ctx->pc = 0x12A7B0u;
    ctx->pc = 0x12A7B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A7B0u;
            // 0x12a7b4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12A7B8u;
label_12a7b8:
    // 0x12a7b8: 0xc04c766  jal         func_131D98
    ctx->pc = 0x12A7B8u;
    SET_GPR_U32(ctx, 31, 0x12A7C0u);
    ctx->pc = 0x131D98u;
    if (runtime->hasFunction(0x131D98u)) {
        auto targetFn = runtime->lookupFunction(0x131D98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A7C0u; }
        if (ctx->pc != 0x12A7C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131D98_0x131d98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A7C0u; }
        if (ctx->pc != 0x12A7C0u) { return; }
    }
    ctx->pc = 0x12A7C0u;
label_12a7c0:
    // 0x12a7c0: 0xc049938  jal         func_1264E0
    ctx->pc = 0x12A7C0u;
    SET_GPR_U32(ctx, 31, 0x12A7C8u);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A7C8u; }
        if (ctx->pc != 0x12A7C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A7C8u; }
        if (ctx->pc != 0x12A7C8u) { return; }
    }
    ctx->pc = 0x12A7C8u;
label_12a7c8:
    // 0x12a7c8: 0x8e050010  lw          $a1, 0x10($s0)
    ctx->pc = 0x12a7c8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x12a7cc: 0xc04c6d8  jal         func_131B60
    ctx->pc = 0x12A7CCu;
    SET_GPR_U32(ctx, 31, 0x12A7D4u);
    ctx->pc = 0x12A7D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A7CCu;
            // 0x12a7d0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131B60u;
    if (runtime->hasFunction(0x131B60u)) {
        auto targetFn = runtime->lookupFunction(0x131B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A7D4u; }
        if (ctx->pc != 0x12A7D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131B60_0x131b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A7D4u; }
        if (ctx->pc != 0x12A7D4u) { return; }
    }
    ctx->pc = 0x12A7D4u;
label_12a7d4:
    // 0x12a7d4: 0x8e040014  lw          $a0, 0x14($s0)
    ctx->pc = 0x12a7d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x12a7d8: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x12a7d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12a7dc: 0x8c620014  lw          $v0, 0x14($v1)
    ctx->pc = 0x12a7dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x12a7e0: 0x40f809  jalr        $v0
    ctx->pc = 0x12A7E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12A7E8u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x12A7E8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A7B8u: goto label_12a7b8;
            case 0x12A7C0u: goto label_12a7c0;
            case 0x12A7C8u: goto label_12a7c8;
            case 0x12A7D4u: goto label_12a7d4;
            case 0x12A7E8u: goto label_12a7e8;
            case 0x12A800u: goto label_12a800;
            case 0x12A808u: goto label_12a808;
            case 0x12A810u: goto label_12a810;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12A7E8u; }
            if (ctx->pc != 0x12A7E8u) { return; }
        }
        }
    }
    ctx->pc = 0x12A7E8u;
label_12a7e8:
    // 0x12a7e8: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x12a7e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12a7ec: 0x8605003e  lh          $a1, 0x3E($s0)
    ctx->pc = 0x12a7ecu;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 62)));
    // 0x12a7f0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12a7f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a7f4: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x12a7f4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x12a7f8: 0xc04f4d6  jal         func_13D358
    ctx->pc = 0x12A7F8u;
    SET_GPR_U32(ctx, 31, 0x12A800u);
    ctx->pc = 0x12A7FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A7F8u;
            // 0x12a7fc: 0x52ac0  sll         $a1, $a1, 11 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 11));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D358u;
    if (runtime->hasFunction(0x13D358u)) {
        auto targetFn = runtime->lookupFunction(0x13D358u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A800u; }
        if (ctx->pc != 0x12A800u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D358_0x13d358(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A800u; }
        if (ctx->pc != 0x12A800u) { return; }
    }
    ctx->pc = 0x12A800u;
label_12a800:
    // 0x12a800: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x12A800u;
    SET_GPR_U32(ctx, 31, 0x12A808u);
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A808u; }
        if (ctx->pc != 0x12A808u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A808u; }
        if (ctx->pc != 0x12A808u) { return; }
    }
    ctx->pc = 0x12A808u;
label_12a808:
    // 0x12a808: 0xc04f3c4  jal         func_13CF10
    ctx->pc = 0x12A808u;
    SET_GPR_U32(ctx, 31, 0x12A810u);
    ctx->pc = 0x12A80Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A808u;
            // 0x12a80c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CF10u;
    if (runtime->hasFunction(0x13CF10u)) {
        auto targetFn = runtime->lookupFunction(0x13CF10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A810u; }
        if (ctx->pc != 0x12A810u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CF10_0x13cf10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A810u; }
        if (ctx->pc != 0x12A810u) { return; }
    }
    ctx->pc = 0x12A810u;
label_12a810:
    // 0x12a810: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12a810u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12a814: 0xa2020098  sb          $v0, 0x98($s0)
    ctx->pc = 0x12a814u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 152), (uint8_t)GPR_U32(ctx, 2));
    // 0x12a818: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12a818u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12a81c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12a81cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a820: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x12a820u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12a824: 0x3e00008  jr          $ra
    ctx->pc = 0x12A824u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A828u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A824u;
            // 0x12a828: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A7B8u: goto label_12a7b8;
            case 0x12A7C0u: goto label_12a7c0;
            case 0x12A7C8u: goto label_12a7c8;
            case 0x12A7D4u: goto label_12a7d4;
            case 0x12A7E8u: goto label_12a7e8;
            case 0x12A800u: goto label_12a800;
            case 0x12A808u: goto label_12a808;
            case 0x12A810u: goto label_12a810;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A82Cu;
    // 0x12a82c: 0x0  nop
    ctx->pc = 0x12a82cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
