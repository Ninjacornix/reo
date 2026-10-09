#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF280
// Address: 0x1af280 - 0x1af320
void sub_001AF280_0x1af280(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF280_0x1af280");
#endif

    switch (ctx->pc) {
        case 0x1af294u: goto label_1af294;
        case 0x1af2a4u: goto label_1af2a4;
        case 0x1af2acu: goto label_1af2ac;
        case 0x1af2b4u: goto label_1af2b4;
        case 0x1af2bcu: goto label_1af2bc;
        case 0x1af2c4u: goto label_1af2c4;
        case 0x1af2ccu: goto label_1af2cc;
        case 0x1af2d8u: goto label_1af2d8;
        case 0x1af2e8u: goto label_1af2e8;
        case 0x1af2f4u: goto label_1af2f4;
        case 0x1af304u: goto label_1af304;
        case 0x1af30cu: goto label_1af30c;
        default: break;
    }

    ctx->pc = 0x1af280u;

    // 0x1af280: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1af280u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1af284: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1af284u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1af288: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1af288u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1af28c: 0xc06a5d4  jal         func_1A9750
    ctx->pc = 0x1AF28Cu;
    SET_GPR_U32(ctx, 31, 0x1AF294u);
    ctx->pc = 0x1AF290u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF28Cu;
            // 0x1af290: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9750u;
    if (runtime->hasFunction(0x1A9750u)) {
        auto targetFn = runtime->lookupFunction(0x1A9750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF294u; }
        if (ctx->pc != 0x1AF294u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9750_0x1a9750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF294u; }
        if (ctx->pc != 0x1AF294u) { return; }
    }
    ctx->pc = 0x1AF294u;
label_1af294:
    // 0x1af294: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1AF294u;
    {
        const bool branch_taken_0x1af294 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AF298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF294u;
            // 0x1af298: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1af294) {
            ctx->pc = 0x1AF2ACu;
            goto label_1af2ac;
        }
    }
    ctx->pc = 0x1AF29Cu;
    // 0x1af29c: 0xc17af1c  jal         func_5EBC70
    ctx->pc = 0x1AF29Cu;
    SET_GPR_U32(ctx, 31, 0x1AF2A4u);
    ctx->pc = 0x1AF2A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF29Cu;
            // 0x1af2a0: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x5EBC70u;
    {
        auto targetFn = runtime->lookupFunction(0x5EBC70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF2A4u; }
        if (ctx->pc != 0x1AF2A4u) { return; }
    }
    ctx->pc = 0x1AF2A4u;
label_1af2a4:
    // 0x1af2a4: 0xc073df8  jal         func_1CF7E0
    ctx->pc = 0x1AF2A4u;
    SET_GPR_U32(ctx, 31, 0x1AF2ACu);
    ctx->pc = 0x1CF7E0u;
    if (runtime->hasFunction(0x1CF7E0u)) {
        auto targetFn = runtime->lookupFunction(0x1CF7E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF2ACu; }
        if (ctx->pc != 0x1AF2ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF7E0_0x1cf7e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF2ACu; }
        if (ctx->pc != 0x1AF2ACu) { return; }
    }
    ctx->pc = 0x1AF2ACu;
label_1af2ac:
    // 0x1af2ac: 0xc07326c  jal         func_1CC9B0
    ctx->pc = 0x1AF2ACu;
    SET_GPR_U32(ctx, 31, 0x1AF2B4u);
    ctx->pc = 0x1CC9B0u;
    if (runtime->hasFunction(0x1CC9B0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC9B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF2B4u; }
        if (ctx->pc != 0x1AF2B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC9B0_0x1cc9b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF2B4u; }
        if (ctx->pc != 0x1AF2B4u) { return; }
    }
    ctx->pc = 0x1AF2B4u;
label_1af2b4:
    // 0x1af2b4: 0xc06c63c  jal         func_1B18F0
    ctx->pc = 0x1AF2B4u;
    SET_GPR_U32(ctx, 31, 0x1AF2BCu);
    ctx->pc = 0x1B18F0u;
    if (runtime->hasFunction(0x1B18F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B18F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF2BCu; }
        if (ctx->pc != 0x1AF2BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B18F0_0x1b18f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF2BCu; }
        if (ctx->pc != 0x1AF2BCu) { return; }
    }
    ctx->pc = 0x1AF2BCu;
label_1af2bc:
    // 0x1af2bc: 0xc06c838  jal         func_1B20E0
    ctx->pc = 0x1AF2BCu;
    SET_GPR_U32(ctx, 31, 0x1AF2C4u);
    ctx->pc = 0x1B20E0u;
    if (runtime->hasFunction(0x1B20E0u)) {
        auto targetFn = runtime->lookupFunction(0x1B20E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF2C4u; }
        if (ctx->pc != 0x1AF2C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B20E0_0x1b20e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF2C4u; }
        if (ctx->pc != 0x1AF2C4u) { return; }
    }
    ctx->pc = 0x1AF2C4u;
label_1af2c4:
    // 0x1af2c4: 0xc06c65c  jal         func_1B1970
    ctx->pc = 0x1AF2C4u;
    SET_GPR_U32(ctx, 31, 0x1AF2CCu);
    ctx->pc = 0x1B1970u;
    if (runtime->hasFunction(0x1B1970u)) {
        auto targetFn = runtime->lookupFunction(0x1B1970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF2CCu; }
        if (ctx->pc != 0x1AF2CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1970_0x1b1970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF2CCu; }
        if (ctx->pc != 0x1AF2CCu) { return; }
    }
    ctx->pc = 0x1AF2CCu;
label_1af2cc:
    // 0x1af2cc: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1af2ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1af2d0: 0xc06a5d4  jal         func_1A9750
    ctx->pc = 0x1AF2D0u;
    SET_GPR_U32(ctx, 31, 0x1AF2D8u);
    ctx->pc = 0x1AF2D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF2D0u;
            // 0x1af2d4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9750u;
    if (runtime->hasFunction(0x1A9750u)) {
        auto targetFn = runtime->lookupFunction(0x1A9750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF2D8u; }
        if (ctx->pc != 0x1AF2D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9750_0x1a9750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF2D8u; }
        if (ctx->pc != 0x1AF2D8u) { return; }
    }
    ctx->pc = 0x1AF2D8u;
label_1af2d8:
    // 0x1af2d8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AF2D8u;
    {
        const bool branch_taken_0x1af2d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AF2DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF2D8u;
            // 0x1af2dc: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1af2d8) {
            ctx->pc = 0x1AF2ECu;
            goto label_1af2ec;
        }
    }
    ctx->pc = 0x1AF2E0u;
    // 0x1af2e0: 0xc17ab74  jal         func_5EADD0
    ctx->pc = 0x1AF2E0u;
    SET_GPR_U32(ctx, 31, 0x1AF2E8u);
    ctx->pc = 0x5EADD0u;
    {
        auto targetFn = runtime->lookupFunction(0x5EADD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF2E8u; }
        if (ctx->pc != 0x1AF2E8u) { return; }
    }
    ctx->pc = 0x1AF2E8u;
label_1af2e8:
    // 0x1af2e8: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1af2e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_1af2ec:
    // 0x1af2ec: 0xc06a5d4  jal         func_1A9750
    ctx->pc = 0x1AF2ECu;
    SET_GPR_U32(ctx, 31, 0x1AF2F4u);
    ctx->pc = 0x1AF2F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF2ECu;
            // 0x1af2f0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9750u;
    if (runtime->hasFunction(0x1A9750u)) {
        auto targetFn = runtime->lookupFunction(0x1A9750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF2F4u; }
        if (ctx->pc != 0x1AF2F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9750_0x1a9750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF2F4u; }
        if (ctx->pc != 0x1AF2F4u) { return; }
    }
    ctx->pc = 0x1AF2F4u;
label_1af2f4:
    // 0x1af2f4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AF2F4u;
    {
        const bool branch_taken_0x1af2f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1af2f4) {
            ctx->pc = 0x1AF304u;
            goto label_1af304;
        }
    }
    ctx->pc = 0x1AF2FCu;
    // 0x1af2fc: 0xc15d6a0  jal         func_575A80
    ctx->pc = 0x1AF2FCu;
    SET_GPR_U32(ctx, 31, 0x1AF304u);
    ctx->pc = 0x575A80u;
    {
        auto targetFn = runtime->lookupFunction(0x575A80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF304u; }
        if (ctx->pc != 0x1AF304u) { return; }
    }
    ctx->pc = 0x1AF304u;
label_1af304:
    // 0x1af304: 0xc06bcc8  jal         func_1AF320
    ctx->pc = 0x1AF304u;
    SET_GPR_U32(ctx, 31, 0x1AF30Cu);
    ctx->pc = 0x1AF320u;
    if (runtime->hasFunction(0x1AF320u)) {
        auto targetFn = runtime->lookupFunction(0x1AF320u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF30Cu; }
        if (ctx->pc != 0x1AF30Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF320_0x1af320(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF30Cu; }
        if (ctx->pc != 0x1AF30Cu) { return; }
    }
    ctx->pc = 0x1AF30Cu;
label_1af30c:
    // 0x1af30c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1af30cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1af310: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF310u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AF314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF310u;
            // 0x1af314: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AF294u: goto label_1af294;
            case 0x1AF2A4u: goto label_1af2a4;
            case 0x1AF2ACu: goto label_1af2ac;
            case 0x1AF2B4u: goto label_1af2b4;
            case 0x1AF2BCu: goto label_1af2bc;
            case 0x1AF2C4u: goto label_1af2c4;
            case 0x1AF2CCu: goto label_1af2cc;
            case 0x1AF2D8u: goto label_1af2d8;
            case 0x1AF2E8u: goto label_1af2e8;
            case 0x1AF2ECu: goto label_1af2ec;
            case 0x1AF2F4u: goto label_1af2f4;
            case 0x1AF304u: goto label_1af304;
            case 0x1AF30Cu: goto label_1af30c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AF318u;
    // 0x1af318: 0x0  nop
    ctx->pc = 0x1af318u;
    // NOP
    // 0x1af31c: 0x0  nop
    ctx->pc = 0x1af31cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
