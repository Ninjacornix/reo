#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013B268
// Address: 0x13b268 - 0x13b308
void sub_0013B268_0x13b268(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013B268_0x13b268");
#endif

    switch (ctx->pc) {
        case 0x13b28cu: goto label_13b28c;
        case 0x13b2acu: goto label_13b2ac;
        case 0x13b2b4u: goto label_13b2b4;
        case 0x13b2c0u: goto label_13b2c0;
        case 0x13b2ccu: goto label_13b2cc;
        case 0x13b2e0u: goto label_13b2e0;
        case 0x13b2e8u: goto label_13b2e8;
        case 0x13b2f0u: goto label_13b2f0;
        default: break;
    }

    ctx->pc = 0x13b268u;

    // 0x13b268: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13b268u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13b26c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13b26cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b270: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x13b270u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x13b274: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13b274u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b278: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x13b278u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x13b27c: 0x1200001d  beqz        $s0, . + 4 + (0x1D << 2)
    ctx->pc = 0x13B27Cu;
    {
        const bool branch_taken_0x13b27c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B27Cu;
            // 0x13b280: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b27c) {
            ctx->pc = 0x13B2F4u;
            goto label_13b2f4;
        }
    }
    ctx->pc = 0x13B284u;
    // 0x13b284: 0xc04f1fa  jal         func_13C7E8
    ctx->pc = 0x13B284u;
    SET_GPR_U32(ctx, 31, 0x13B28Cu);
    ctx->pc = 0x13B288u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B284u;
            // 0x13b288: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C7E8u;
    if (runtime->hasFunction(0x13C7E8u)) {
        auto targetFn = runtime->lookupFunction(0x13C7E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B28Cu; }
        if (ctx->pc != 0x13B28Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C7E8_0x13c7e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B28Cu; }
        if (ctx->pc != 0x13B28Cu) { return; }
    }
    ctx->pc = 0x13B28Cu;
label_13b28c:
    // 0x13b28c: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13b28cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13b290: 0x2451dd60  addiu       $s1, $v0, -0x22A0
    ctx->pc = 0x13b290u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958432));
    // 0x13b294: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x13b294u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x13b298: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13b298u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b29c: 0x14400014  bnez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x13B29Cu;
    {
        const bool branch_taken_0x13b29c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13B2A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B29Cu;
            // 0x13b2a0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b29c) {
            ctx->pc = 0x13B2F0u;
            goto label_13b2f0;
        }
    }
    ctx->pc = 0x13B2A4u;
    // 0x13b2a4: 0xc04efa0  jal         func_13BE80
    ctx->pc = 0x13B2A4u;
    SET_GPR_U32(ctx, 31, 0x13B2ACu);
    ctx->pc = 0x13BE80u;
    if (runtime->hasFunction(0x13BE80u)) {
        auto targetFn = runtime->lookupFunction(0x13BE80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2ACu; }
        if (ctx->pc != 0x13B2ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BE80_0x13be80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2ACu; }
        if (ctx->pc != 0x13B2ACu) { return; }
    }
    ctx->pc = 0x13B2ACu;
label_13b2ac:
    // 0x13b2ac: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B2ACu;
    SET_GPR_U32(ctx, 31, 0x13B2B4u);
    ctx->pc = 0x13B2B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B2ACu;
            // 0x13b2b0: 0x24044200  addiu       $a0, $zero, 0x4200 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16896));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2B4u; }
        if (ctx->pc != 0x13B2B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2B4u; }
        if (ctx->pc != 0x13B2B4u) { return; }
    }
    ctx->pc = 0x13B2B4u;
label_13b2b4:
    // 0x13b2b4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13b2b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b2b8: 0xc04e146  jal         func_138518
    ctx->pc = 0x13B2B8u;
    SET_GPR_U32(ctx, 31, 0x13B2C0u);
    ctx->pc = 0x13B2BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B2B8u;
            // 0x13b2bc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138518u;
    if (runtime->hasFunction(0x138518u)) {
        auto targetFn = runtime->lookupFunction(0x138518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2C0u; }
        if (ctx->pc != 0x13B2C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138518_0x138518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2C0u; }
        if (ctx->pc != 0x13B2C0u) { return; }
    }
    ctx->pc = 0x13B2C0u;
label_13b2c0:
    // 0x13b2c0: 0x24044201  addiu       $a0, $zero, 0x4201
    ctx->pc = 0x13b2c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16897));
    // 0x13b2c4: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B2C4u;
    SET_GPR_U32(ctx, 31, 0x13B2CCu);
    ctx->pc = 0x13B2C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B2C4u;
            // 0x13b2c8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2CCu; }
        if (ctx->pc != 0x13B2CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2CCu; }
        if (ctx->pc != 0x13B2CCu) { return; }
    }
    ctx->pc = 0x13B2CCu;
label_13b2cc:
    // 0x13b2cc: 0x24044300  addiu       $a0, $zero, 0x4300
    ctx->pc = 0x13b2ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17152));
    // 0x13b2d0: 0x6000008  bltz        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13B2D0u;
    {
        const bool branch_taken_0x13b2d0 = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x13B2D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B2D0u;
            // 0x13b2d4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b2d0) {
            ctx->pc = 0x13B2F4u;
            goto label_13b2f4;
        }
    }
    ctx->pc = 0x13B2D8u;
    // 0x13b2d8: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B2D8u;
    SET_GPR_U32(ctx, 31, 0x13B2E0u);
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2E0u; }
        if (ctx->pc != 0x13B2E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2E0u; }
        if (ctx->pc != 0x13B2E0u) { return; }
    }
    ctx->pc = 0x13B2E0u;
label_13b2e0:
    // 0x13b2e0: 0xc04e160  jal         func_138580
    ctx->pc = 0x13B2E0u;
    SET_GPR_U32(ctx, 31, 0x13B2E8u);
    ctx->pc = 0x13B2E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B2E0u;
            // 0x13b2e4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138580u;
    if (runtime->hasFunction(0x138580u)) {
        auto targetFn = runtime->lookupFunction(0x138580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2E8u; }
        if (ctx->pc != 0x13B2E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138580_0x138580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2E8u; }
        if (ctx->pc != 0x13B2E8u) { return; }
    }
    ctx->pc = 0x13B2E8u;
label_13b2e8:
    // 0x13b2e8: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B2E8u;
    SET_GPR_U32(ctx, 31, 0x13B2F0u);
    ctx->pc = 0x13B2ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B2E8u;
            // 0x13b2ec: 0x24044301  addiu       $a0, $zero, 0x4301 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17153));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2F0u; }
        if (ctx->pc != 0x13B2F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2F0u; }
        if (ctx->pc != 0x13B2F0u) { return; }
    }
    ctx->pc = 0x13B2F0u;
label_13b2f0:
    // 0x13b2f0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13b2f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_13b2f4:
    // 0x13b2f4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x13b2f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13b2f8: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x13b2f8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13b2fc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13b2fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13b300: 0x3e00008  jr          $ra
    ctx->pc = 0x13B300u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13B304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B300u;
            // 0x13b304: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B28Cu: goto label_13b28c;
            case 0x13B2ACu: goto label_13b2ac;
            case 0x13B2B4u: goto label_13b2b4;
            case 0x13B2C0u: goto label_13b2c0;
            case 0x13B2CCu: goto label_13b2cc;
            case 0x13B2E0u: goto label_13b2e0;
            case 0x13B2E8u: goto label_13b2e8;
            case 0x13B2F0u: goto label_13b2f0;
            case 0x13B2F4u: goto label_13b2f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13B308u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
