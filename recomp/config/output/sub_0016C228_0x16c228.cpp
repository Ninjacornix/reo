#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016C228
// Address: 0x16c228 - 0x16c304
void sub_0016C228_0x16c228(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016C228_0x16c228");
#endif

    switch (ctx->pc) {
        case 0x16c238u: goto label_16c238;
        case 0x16c240u: goto label_16c240;
        case 0x16c248u: goto label_16c248;
        case 0x16c274u: goto label_16c274;
        case 0x16c2c4u: goto label_16c2c4;
        case 0x16c2d8u: goto label_16c2d8;
        case 0x16c2ecu: goto label_16c2ec;
        default: break;
    }

    ctx->pc = 0x16c228u;

    // 0x16c228: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16c228u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16c22c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16c22cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16c230: 0xc05c550  jal         func_171540
    ctx->pc = 0x16C230u;
    SET_GPR_U32(ctx, 31, 0x16C238u);
    ctx->pc = 0x171540u;
    if (runtime->hasFunction(0x171540u)) {
        auto targetFn = runtime->lookupFunction(0x171540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C238u; }
        if (ctx->pc != 0x16C238u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171540_0x171540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C238u; }
        if (ctx->pc != 0x16C238u) { return; }
    }
    ctx->pc = 0x16C238u;
label_16c238:
    // 0x16c238: 0xc05b0c2  jal         func_16C308
    ctx->pc = 0x16C238u;
    SET_GPR_U32(ctx, 31, 0x16C240u);
    ctx->pc = 0x16C308u;
    if (runtime->hasFunction(0x16C308u)) {
        auto targetFn = runtime->lookupFunction(0x16C308u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C240u; }
        if (ctx->pc != 0x16C240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016C308_0x16c308(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C240u; }
        if (ctx->pc != 0x16C240u) { return; }
    }
    ctx->pc = 0x16C240u;
label_16c240:
    // 0x16c240: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x16C240u;
    {
        const bool branch_taken_0x16c240 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C240u;
            // 0x16c244: 0x3c050027  lui         $a1, 0x27 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)39 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c240) {
            ctx->pc = 0x16C268u;
            goto label_16c268;
        }
    }
    ctx->pc = 0x16C248u;
label_16c248:
    // 0x16c248: 0x0  nop
    ctx->pc = 0x16c248u;
    // NOP
    // 0x16c24c: 0x0  nop
    ctx->pc = 0x16c24cu;
    // NOP
    // 0x16c250: 0x0  nop
    ctx->pc = 0x16c250u;
    // NOP
    // 0x16c254: 0x0  nop
    ctx->pc = 0x16c254u;
    // NOP
    // 0x16c258: 0x0  nop
    ctx->pc = 0x16c258u;
    // NOP
    // 0x16c25c: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x16C25Cu;
    {
        const bool branch_taken_0x16c25c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x16c25c) {
            ctx->pc = 0x16C248u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16c248;
        }
    }
    ctx->pc = 0x16C264u;
    // 0x16c264: 0x0  nop
    ctx->pc = 0x16c264u;
    // NOP
label_16c268:
    // 0x16c268: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x16c268u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x16c26c: 0xc056c1e  jal         func_15B078
    ctx->pc = 0x16C26Cu;
    SET_GPR_U32(ctx, 31, 0x16C274u);
    ctx->pc = 0x16C270u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C26Cu;
            // 0x16c270: 0x24a52028  addiu       $a1, $a1, 0x2028 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8232));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B078u;
    if (runtime->hasFunction(0x15B078u)) {
        auto targetFn = runtime->lookupFunction(0x15B078u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C274u; }
        if (ctx->pc != 0x16C274u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B078_0x15b078(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C274u; }
        if (ctx->pc != 0x16C274u) { return; }
    }
    ctx->pc = 0x16C274u;
label_16c274:
    // 0x16c274: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x16c274u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c278: 0x1080000d  beqz        $a0, . + 4 + (0xD << 2)
    ctx->pc = 0x16C278u;
    {
        const bool branch_taken_0x16c278 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C27Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C278u;
            // 0x16c27c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c278) {
            ctx->pc = 0x16C2B0u;
            goto label_16c2b0;
        }
    }
    ctx->pc = 0x16C280u;
    // 0x16c280: 0x3c02ff03  lui         $v0, 0xFF03
    ctx->pc = 0x16c280u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65283 << 16));
    // 0x16c284: 0x3c03ff00  lui         $v1, 0xFF00
    ctx->pc = 0x16c284u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65280 << 16));
    // 0x16c288: 0x3442ff05  ori         $v0, $v0, 0xFF05
    ctx->pc = 0x16c288u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65285);
    // 0x16c28c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16c28cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16c290: 0x821026  xor         $v0, $a0, $v0
    ctx->pc = 0x16c290u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) ^ GPR_U64(ctx, 2));
    // 0x16c294: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x16c294u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c298: 0x34630f01  ori         $v1, $v1, 0xF01
    ctx->pc = 0x16c298u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)3841);
    // 0x16c29c: 0x34a50f13  ori         $a1, $a1, 0xF13
    ctx->pc = 0x16c29cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3859);
    // 0x16c2a0: 0x62280b  movn        $a1, $v1, $v0
    ctx->pc = 0x16c2a0u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 3));
    // 0x16c2a4: 0x805a704  j           func_169C10
    ctx->pc = 0x16C2A4u;
    ctx->pc = 0x16C2A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C2A4u;
            // 0x16c2a8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16C2ACu;
    // 0x16c2ac: 0x0  nop
    ctx->pc = 0x16c2acu;
    // NOP
label_16c2b0:
    // 0x16c2b0: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x16c2b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x16c2b4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x16c2b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c2b8: 0x24846068  addiu       $a0, $a0, 0x6068
    ctx->pc = 0x16c2b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24680));
    // 0x16c2bc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x16C2BCu;
    SET_GPR_U32(ctx, 31, 0x16C2C4u);
    ctx->pc = 0x16C2C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C2BCu;
            // 0x16c2c0: 0x24060024  addiu       $a2, $zero, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C2C4u; }
        if (ctx->pc != 0x16C2C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C2C4u; }
        if (ctx->pc != 0x16C2C4u) { return; }
    }
    ctx->pc = 0x16C2C4u;
label_16c2c4:
    // 0x16c2c4: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x16c2c4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x16c2c8: 0x24846090  addiu       $a0, $a0, 0x6090
    ctx->pc = 0x16c2c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24720));
    // 0x16c2cc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x16c2ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c2d0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x16C2D0u;
    SET_GPR_U32(ctx, 31, 0x16C2D8u);
    ctx->pc = 0x16C2D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C2D0u;
            // 0x16c2d4: 0x24060008  addiu       $a2, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C2D8u; }
        if (ctx->pc != 0x16C2D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C2D8u; }
        if (ctx->pc != 0x16C2D8u) { return; }
    }
    ctx->pc = 0x16C2D8u;
label_16c2d8:
    // 0x16c2d8: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x16c2d8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x16c2dc: 0x24846098  addiu       $a0, $a0, 0x6098
    ctx->pc = 0x16c2dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24728));
    // 0x16c2e0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x16c2e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c2e4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x16C2E4u;
    SET_GPR_U32(ctx, 31, 0x16C2ECu);
    ctx->pc = 0x16C2E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C2E4u;
            // 0x16c2e8: 0x24060040  addiu       $a2, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C2ECu; }
        if (ctx->pc != 0x16C2ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C2ECu; }
        if (ctx->pc != 0x16C2ECu) { return; }
    }
    ctx->pc = 0x16C2ECu;
label_16c2ec:
    // 0x16c2ec: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x16c2ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x16c2f0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16c2f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c2f4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16c2f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c2f8: 0xac60f1b8  sw          $zero, -0xE48($v1)
    ctx->pc = 0x16c2f8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294963640), GPR_U32(ctx, 0));
    // 0x16c2fc: 0x3e00008  jr          $ra
    ctx->pc = 0x16C2FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16C300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C2FCu;
            // 0x16c300: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16C238u: goto label_16c238;
            case 0x16C240u: goto label_16c240;
            case 0x16C248u: goto label_16c248;
            case 0x16C268u: goto label_16c268;
            case 0x16C274u: goto label_16c274;
            case 0x16C2B0u: goto label_16c2b0;
            case 0x16C2C4u: goto label_16c2c4;
            case 0x16C2D8u: goto label_16c2d8;
            case 0x16C2ECu: goto label_16c2ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C304u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
