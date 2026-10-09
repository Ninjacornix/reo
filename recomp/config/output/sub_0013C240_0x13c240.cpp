#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013C240
// Address: 0x13c240 - 0x13c3a0
void sub_0013C240_0x13c240(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013C240_0x13c240");
#endif

    switch (ctx->pc) {
        case 0x13c270u: goto label_13c270;
        case 0x13c27cu: goto label_13c27c;
        case 0x13c284u: goto label_13c284;
        case 0x13c290u: goto label_13c290;
        case 0x13c29cu: goto label_13c29c;
        case 0x13c2b0u: goto label_13c2b0;
        case 0x13c2c0u: goto label_13c2c0;
        case 0x13c2ccu: goto label_13c2cc;
        case 0x13c2e0u: goto label_13c2e0;
        case 0x13c2f0u: goto label_13c2f0;
        case 0x13c300u: goto label_13c300;
        case 0x13c320u: goto label_13c320;
        case 0x13c334u: goto label_13c334;
        case 0x13c340u: goto label_13c340;
        case 0x13c350u: goto label_13c350;
        case 0x13c358u: goto label_13c358;
        case 0x13c360u: goto label_13c360;
        case 0x13c370u: goto label_13c370;
        case 0x13c378u: goto label_13c378;
        case 0x13c380u: goto label_13c380;
        default: break;
    }

    ctx->pc = 0x13c240u;

    // 0x13c240: 0x27bdfed0  addiu       $sp, $sp, -0x130
    ctx->pc = 0x13c240u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966992));
    // 0x13c244: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x13c244u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x13c248: 0xffb00100  sd          $s0, 0x100($sp)
    ctx->pc = 0x13c248u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 256), GPR_U64(ctx, 16));
    // 0x13c24c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13c24cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c250: 0xffb30118  sd          $s3, 0x118($sp)
    ctx->pc = 0x13c250u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 280), GPR_U64(ctx, 19));
    // 0x13c254: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x13c254u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c258: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x13c258u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c25c: 0xffb20110  sd          $s2, 0x110($sp)
    ctx->pc = 0x13c25cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 272), GPR_U64(ctx, 18));
    // 0x13c260: 0xffb10108  sd          $s1, 0x108($sp)
    ctx->pc = 0x13c260u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 264), GPR_U64(ctx, 17));
    // 0x13c264: 0xffbf0120  sd          $ra, 0x120($sp)
    ctx->pc = 0x13c264u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 288), GPR_U64(ctx, 31));
    // 0x13c268: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13C268u;
    SET_GPR_U32(ctx, 31, 0x13C270u);
    ctx->pc = 0x13C26Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C268u;
            // 0x13c26c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C270u; }
        if (ctx->pc != 0x13C270u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C270u; }
        if (ctx->pc != 0x13C270u) { return; }
    }
    ctx->pc = 0x13C270u;
label_13c270:
    // 0x13c270: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x13c270u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c274: 0xc04efa0  jal         func_13BE80
    ctx->pc = 0x13C274u;
    SET_GPR_U32(ctx, 31, 0x13C27Cu);
    ctx->pc = 0x13C278u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C274u;
            // 0x13c278: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13BE80u;
    if (runtime->hasFunction(0x13BE80u)) {
        auto targetFn = runtime->lookupFunction(0x13BE80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C27Cu; }
        if (ctx->pc != 0x13C27Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BE80_0x13be80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C27Cu; }
        if (ctx->pc != 0x13C27Cu) { return; }
    }
    ctx->pc = 0x13C27Cu;
label_13c27c:
    // 0x13c27c: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C27Cu;
    SET_GPR_U32(ctx, 31, 0x13C284u);
    ctx->pc = 0x13C280u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C27Cu;
            // 0x13c280: 0x24046000  addiu       $a0, $zero, 0x6000 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 24576));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C284u; }
        if (ctx->pc != 0x13C284u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C284u; }
        if (ctx->pc != 0x13C284u) { return; }
    }
    ctx->pc = 0x13C284u;
label_13c284:
    // 0x13c284: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x13c284u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13c288: 0xc04e146  jal         func_138518
    ctx->pc = 0x13C288u;
    SET_GPR_U32(ctx, 31, 0x13C290u);
    ctx->pc = 0x13C28Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C288u;
            // 0x13c28c: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138518u;
    if (runtime->hasFunction(0x138518u)) {
        auto targetFn = runtime->lookupFunction(0x138518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C290u; }
        if (ctx->pc != 0x13C290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138518_0x138518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C290u; }
        if (ctx->pc != 0x13C290u) { return; }
    }
    ctx->pc = 0x13C290u;
label_13c290:
    // 0x13c290: 0x24046001  addiu       $a0, $zero, 0x6001
    ctx->pc = 0x13c290u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 24577));
    // 0x13c294: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C294u;
    SET_GPR_U32(ctx, 31, 0x13C29Cu);
    ctx->pc = 0x13C298u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C294u;
            // 0x13c298: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C29Cu; }
        if (ctx->pc != 0x13C29Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C29Cu; }
        if (ctx->pc != 0x13C29Cu) { return; }
    }
    ctx->pc = 0x13C29Cu;
label_13c29c:
    // 0x13c29c: 0x24046100  addiu       $a0, $zero, 0x6100
    ctx->pc = 0x13c29cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 24832));
    // 0x13c2a0: 0x6400038  bltz        $s2, . + 4 + (0x38 << 2)
    ctx->pc = 0x13C2A0u;
    {
        const bool branch_taken_0x13c2a0 = (GPR_S64(ctx, 18) < 0);
        ctx->pc = 0x13C2A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C2A0u;
            // 0x13c2a4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c2a0) {
            ctx->pc = 0x13C384u;
            goto label_13c384;
        }
    }
    ctx->pc = 0x13C2A8u;
    // 0x13c2a8: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C2A8u;
    SET_GPR_U32(ctx, 31, 0x13C2B0u);
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C2B0u; }
        if (ctx->pc != 0x13C2B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C2B0u; }
        if (ctx->pc != 0x13C2B0u) { return; }
    }
    ctx->pc = 0x13C2B0u;
label_13c2b0:
    // 0x13c2b0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x13c2b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c2b4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13c2b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c2b8: 0xc04e0fa  jal         func_1383E8
    ctx->pc = 0x13C2B8u;
    SET_GPR_U32(ctx, 31, 0x13C2C0u);
    ctx->pc = 0x13C2BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C2B8u;
            // 0x13c2bc: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1383E8u;
    if (runtime->hasFunction(0x1383E8u)) {
        auto targetFn = runtime->lookupFunction(0x1383E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C2C0u; }
        if (ctx->pc != 0x13C2C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001383E8_0x1383e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C2C0u; }
        if (ctx->pc != 0x13C2C0u) { return; }
    }
    ctx->pc = 0x13C2C0u;
label_13c2c0:
    // 0x13c2c0: 0x24046101  addiu       $a0, $zero, 0x6101
    ctx->pc = 0x13c2c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 24833));
    // 0x13c2c4: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C2C4u;
    SET_GPR_U32(ctx, 31, 0x13C2CCu);
    ctx->pc = 0x13C2C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C2C4u;
            // 0x13c2c8: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C2CCu; }
        if (ctx->pc != 0x13C2CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C2CCu; }
        if (ctx->pc != 0x13C2CCu) { return; }
    }
    ctx->pc = 0x13C2CCu;
label_13c2cc:
    // 0x13c2cc: 0x24046200  addiu       $a0, $zero, 0x6200
    ctx->pc = 0x13c2ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 25088));
    // 0x13c2d0: 0x620002c  bltz        $s1, . + 4 + (0x2C << 2)
    ctx->pc = 0x13C2D0u;
    {
        const bool branch_taken_0x13c2d0 = (GPR_S64(ctx, 17) < 0);
        ctx->pc = 0x13C2D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C2D0u;
            // 0x13c2d4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c2d0) {
            ctx->pc = 0x13C384u;
            goto label_13c384;
        }
    }
    ctx->pc = 0x13C2D8u;
    // 0x13c2d8: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C2D8u;
    SET_GPR_U32(ctx, 31, 0x13C2E0u);
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C2E0u; }
        if (ctx->pc != 0x13C2E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C2E0u; }
        if (ctx->pc != 0x13C2E0u) { return; }
    }
    ctx->pc = 0x13C2E0u;
label_13c2e0:
    // 0x13c2e0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x13c2e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c2e4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13c2e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c2e8: 0xc04e0fa  jal         func_1383E8
    ctx->pc = 0x13C2E8u;
    SET_GPR_U32(ctx, 31, 0x13C2F0u);
    ctx->pc = 0x13C2ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C2E8u;
            // 0x13c2ec: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1383E8u;
    if (runtime->hasFunction(0x1383E8u)) {
        auto targetFn = runtime->lookupFunction(0x1383E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C2F0u; }
        if (ctx->pc != 0x13C2F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001383E8_0x1383e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C2F0u; }
        if (ctx->pc != 0x13C2F0u) { return; }
    }
    ctx->pc = 0x13C2F0u;
label_13c2f0:
    // 0x13c2f0: 0x2803c  dsll32      $s0, $v0, 0
    ctx->pc = 0x13c2f0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) << (32 + 0));
    // 0x13c2f4: 0x10803f  dsra32      $s0, $s0, 0
    ctx->pc = 0x13c2f4u;
    SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 0));
    // 0x13c2f8: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C2F8u;
    SET_GPR_U32(ctx, 31, 0x13C300u);
    ctx->pc = 0x13C2FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C2F8u;
            // 0x13c2fc: 0x24046201  addiu       $a0, $zero, 0x6201 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 25089));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C300u; }
        if (ctx->pc != 0x13C300u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C300u; }
        if (ctx->pc != 0x13C300u) { return; }
    }
    ctx->pc = 0x13C300u;
label_13c300:
    // 0x13c300: 0x24021000  addiu       $v0, $zero, 0x1000
    ctx->pc = 0x13c300u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x13c304: 0x2a231001  slti        $v1, $s1, 0x1001
    ctx->pc = 0x13c304u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)4097) ? 1 : 0);
    // 0x13c308: 0x43880a  movz        $s1, $v0, $v1
    ctx->pc = 0x13c308u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 2));
    // 0x13c30c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13c30cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c310: 0x600001c  bltz        $s0, . + 4 + (0x1C << 2)
    ctx->pc = 0x13C310u;
    {
        const bool branch_taken_0x13c310 = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x13C314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C310u;
            // 0x13c314: 0x24046300  addiu       $a0, $zero, 0x6300 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 25344));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c310) {
            ctx->pc = 0x13C384u;
            goto label_13c384;
        }
    }
    ctx->pc = 0x13C318u;
    // 0x13c318: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C318u;
    SET_GPR_U32(ctx, 31, 0x13C320u);
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C320u; }
        if (ctx->pc != 0x13C320u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C320u; }
        if (ctx->pc != 0x13C320u) { return; }
    }
    ctx->pc = 0x13C320u;
label_13c320:
    // 0x13c320: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x13c320u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c324: 0x11303c  dsll32      $a2, $s1, 0
    ctx->pc = 0x13c324u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 17) << (32 + 0));
    // 0x13c328: 0x6303f  dsra32      $a2, $a2, 0
    ctx->pc = 0x13c328u;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 0));
    // 0x13c32c: 0xc04e176  jal         func_1385D8
    ctx->pc = 0x13C32Cu;
    SET_GPR_U32(ctx, 31, 0x13C334u);
    ctx->pc = 0x13C330u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C32Cu;
            // 0x13c330: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1385D8u;
    if (runtime->hasFunction(0x1385D8u)) {
        auto targetFn = runtime->lookupFunction(0x1385D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C334u; }
        if (ctx->pc != 0x13C334u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001385D8_0x1385d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C334u; }
        if (ctx->pc != 0x13C334u) { return; }
    }
    ctx->pc = 0x13C334u;
label_13c334:
    // 0x13c334: 0x24046301  addiu       $a0, $zero, 0x6301
    ctx->pc = 0x13c334u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 25345));
    // 0x13c338: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C338u;
    SET_GPR_U32(ctx, 31, 0x13C340u);
    ctx->pc = 0x13C33Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C338u;
            // 0x13c33c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C340u; }
        if (ctx->pc != 0x13C340u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C340u; }
        if (ctx->pc != 0x13C340u) { return; }
    }
    ctx->pc = 0x13C340u;
label_13c340:
    // 0x13c340: 0x6010009  bgez        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x13C340u;
    {
        const bool branch_taken_0x13c340 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x13C344u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C340u;
            // 0x13c344: 0x24046500  addiu       $a0, $zero, 0x6500 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 25856));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c340) {
            ctx->pc = 0x13C368u;
            goto label_13c368;
        }
    }
    ctx->pc = 0x13C348u;
    // 0x13c348: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C348u;
    SET_GPR_U32(ctx, 31, 0x13C350u);
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C350u; }
        if (ctx->pc != 0x13C350u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C350u; }
        if (ctx->pc != 0x13C350u) { return; }
    }
    ctx->pc = 0x13C350u;
label_13c350:
    // 0x13c350: 0xc04e160  jal         func_138580
    ctx->pc = 0x13C350u;
    SET_GPR_U32(ctx, 31, 0x13C358u);
    ctx->pc = 0x13C354u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C350u;
            // 0x13c354: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138580u;
    if (runtime->hasFunction(0x138580u)) {
        auto targetFn = runtime->lookupFunction(0x138580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C358u; }
        if (ctx->pc != 0x13C358u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138580_0x138580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C358u; }
        if (ctx->pc != 0x13C358u) { return; }
    }
    ctx->pc = 0x13C358u;
label_13c358:
    // 0x13c358: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C358u;
    SET_GPR_U32(ctx, 31, 0x13C360u);
    ctx->pc = 0x13C35Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C358u;
            // 0x13c35c: 0x24046501  addiu       $a0, $zero, 0x6501 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 25857));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C360u; }
        if (ctx->pc != 0x13C360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C360u; }
        if (ctx->pc != 0x13C360u) { return; }
    }
    ctx->pc = 0x13C360u;
label_13c360:
    // 0x13c360: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x13C360u;
    {
        const bool branch_taken_0x13c360 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13C364u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C360u;
            // 0x13c364: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c360) {
            ctx->pc = 0x13C384u;
            goto label_13c384;
        }
    }
    ctx->pc = 0x13C368u;
label_13c368:
    // 0x13c368: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C368u;
    SET_GPR_U32(ctx, 31, 0x13C370u);
    ctx->pc = 0x13C36Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C368u;
            // 0x13c36c: 0x24046400  addiu       $a0, $zero, 0x6400 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 25600));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C370u; }
        if (ctx->pc != 0x13C370u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C370u; }
        if (ctx->pc != 0x13C370u) { return; }
    }
    ctx->pc = 0x13C370u;
label_13c370:
    // 0x13c370: 0xc04e160  jal         func_138580
    ctx->pc = 0x13C370u;
    SET_GPR_U32(ctx, 31, 0x13C378u);
    ctx->pc = 0x13C374u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C370u;
            // 0x13c374: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138580u;
    if (runtime->hasFunction(0x138580u)) {
        auto targetFn = runtime->lookupFunction(0x138580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C378u; }
        if (ctx->pc != 0x13C378u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138580_0x138580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C378u; }
        if (ctx->pc != 0x13C378u) { return; }
    }
    ctx->pc = 0x13C378u;
label_13c378:
    // 0x13c378: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C378u;
    SET_GPR_U32(ctx, 31, 0x13C380u);
    ctx->pc = 0x13C37Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C378u;
            // 0x13c37c: 0x24046401  addiu       $a0, $zero, 0x6401 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 25601));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C380u; }
        if (ctx->pc != 0x13C380u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C380u; }
        if (ctx->pc != 0x13C380u) { return; }
    }
    ctx->pc = 0x13C380u;
label_13c380:
    // 0x13c380: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13c380u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_13c384:
    // 0x13c384: 0xdfb00100  ld          $s0, 0x100($sp)
    ctx->pc = 0x13c384u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 256)));
    // 0x13c388: 0xdfb10108  ld          $s1, 0x108($sp)
    ctx->pc = 0x13c388u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 264)));
    // 0x13c38c: 0xdfb20110  ld          $s2, 0x110($sp)
    ctx->pc = 0x13c38cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 272)));
    // 0x13c390: 0xdfb30118  ld          $s3, 0x118($sp)
    ctx->pc = 0x13c390u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 280)));
    // 0x13c394: 0xdfbf0120  ld          $ra, 0x120($sp)
    ctx->pc = 0x13c394u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 288)));
    // 0x13c398: 0x3e00008  jr          $ra
    ctx->pc = 0x13C398u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13C39Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C398u;
            // 0x13c39c: 0x27bd0130  addiu       $sp, $sp, 0x130 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13C270u: goto label_13c270;
            case 0x13C27Cu: goto label_13c27c;
            case 0x13C284u: goto label_13c284;
            case 0x13C290u: goto label_13c290;
            case 0x13C29Cu: goto label_13c29c;
            case 0x13C2B0u: goto label_13c2b0;
            case 0x13C2C0u: goto label_13c2c0;
            case 0x13C2CCu: goto label_13c2cc;
            case 0x13C2E0u: goto label_13c2e0;
            case 0x13C2F0u: goto label_13c2f0;
            case 0x13C300u: goto label_13c300;
            case 0x13C320u: goto label_13c320;
            case 0x13C334u: goto label_13c334;
            case 0x13C340u: goto label_13c340;
            case 0x13C350u: goto label_13c350;
            case 0x13C358u: goto label_13c358;
            case 0x13C360u: goto label_13c360;
            case 0x13C368u: goto label_13c368;
            case 0x13C370u: goto label_13c370;
            case 0x13C378u: goto label_13c378;
            case 0x13C380u: goto label_13c380;
            case 0x13C384u: goto label_13c384;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13C3A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
