#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00181DC8
// Address: 0x181dc8 - 0x182198
void sub_00181DC8_0x181dc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00181DC8_0x181dc8");
#endif

    switch (ctx->pc) {
        case 0x181e28u: goto label_181e28;
        case 0x181e44u: goto label_181e44;
        case 0x181e68u: goto label_181e68;
        case 0x181e84u: goto label_181e84;
        case 0x181ea8u: goto label_181ea8;
        case 0x181ec4u: goto label_181ec4;
        case 0x181ee8u: goto label_181ee8;
        case 0x181f04u: goto label_181f04;
        case 0x181f28u: goto label_181f28;
        case 0x181f44u: goto label_181f44;
        case 0x181f68u: goto label_181f68;
        case 0x181f84u: goto label_181f84;
        case 0x181fa8u: goto label_181fa8;
        case 0x181fc4u: goto label_181fc4;
        case 0x181fe8u: goto label_181fe8;
        case 0x182004u: goto label_182004;
        case 0x182028u: goto label_182028;
        case 0x182044u: goto label_182044;
        case 0x182068u: goto label_182068;
        case 0x182084u: goto label_182084;
        case 0x1820a8u: goto label_1820a8;
        case 0x1820c4u: goto label_1820c4;
        case 0x1820e8u: goto label_1820e8;
        case 0x182104u: goto label_182104;
        case 0x182128u: goto label_182128;
        case 0x182144u: goto label_182144;
        case 0x182168u: goto label_182168;
        case 0x182184u: goto label_182184;
        default: break;
    }

    ctx->pc = 0x181dc8u;

    // 0x181dc8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x181dc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x181dcc: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x181dccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181dd0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x181dd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x181dd4: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x181dd4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181dd8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x181dd8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x181ddc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x181ddcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181de0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x181de0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x181de4: 0x806074a  j           func_181D28
    ctx->pc = 0x181DE4u;
    ctx->pc = 0x181DE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181DE4u;
            // 0x181de8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00181D28_0x181d28(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x181DECu;
    // 0x181dec: 0x0  nop
    ctx->pc = 0x181decu;
    // NOP
    // 0x181df0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x181df0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x181df4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x181df4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181df8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x181df8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x181dfc: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x181dfcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181e00: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x181e00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181e04: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x181e04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181e08: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x181e08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x181e0c: 0x806074a  j           func_181D28
    ctx->pc = 0x181E0Cu;
    ctx->pc = 0x181E10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181E0Cu;
            // 0x181e10: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00181D28_0x181d28(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x181E14u;
    // 0x181e14: 0x0  nop
    ctx->pc = 0x181e14u;
    // NOP
    // 0x181e18: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x181e18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x181e1c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x181e1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x181e20: 0xc060418  jal         func_181060
    ctx->pc = 0x181E20u;
    SET_GPR_U32(ctx, 31, 0x181E28u);
    ctx->pc = 0x181060u;
    if (runtime->hasFunction(0x181060u)) {
        auto targetFn = runtime->lookupFunction(0x181060u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181E28u; }
        if (ctx->pc != 0x181E28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181060_0x181060(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181E28u; }
        if (ctx->pc != 0x181E28u) { return; }
    }
    ctx->pc = 0x181E28u;
label_181e28:
    // 0x181e28: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x181e28u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181e2c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x181e2cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x181e30: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x181e30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181e34: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x181E34u;
    {
        const bool branch_taken_0x181e34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181E38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181E34u;
            // 0x181e38: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181e34) {
            ctx->pc = 0x181E48u;
            goto label_181e48;
        }
    }
    ctx->pc = 0x181E3Cu;
    // 0x181e3c: 0xc06074a  jal         func_181D28
    ctx->pc = 0x181E3Cu;
    SET_GPR_U32(ctx, 31, 0x181E44u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181E44u; }
        if (ctx->pc != 0x181E44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181E44u; }
        if (ctx->pc != 0x181E44u) { return; }
    }
    ctx->pc = 0x181E44u;
label_181e44:
    // 0x181e44: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x181e44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_181e48:
    // 0x181e48: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x181e48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x181e4c: 0x3e00008  jr          $ra
    ctx->pc = 0x181E4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181E50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181E4Cu;
            // 0x181e50: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181E28u: goto label_181e28;
            case 0x181E44u: goto label_181e44;
            case 0x181E48u: goto label_181e48;
            case 0x181E68u: goto label_181e68;
            case 0x181E84u: goto label_181e84;
            case 0x181E88u: goto label_181e88;
            case 0x181EA8u: goto label_181ea8;
            case 0x181EC4u: goto label_181ec4;
            case 0x181EC8u: goto label_181ec8;
            case 0x181EE8u: goto label_181ee8;
            case 0x181F04u: goto label_181f04;
            case 0x181F08u: goto label_181f08;
            case 0x181F28u: goto label_181f28;
            case 0x181F44u: goto label_181f44;
            case 0x181F48u: goto label_181f48;
            case 0x181F68u: goto label_181f68;
            case 0x181F84u: goto label_181f84;
            case 0x181F88u: goto label_181f88;
            case 0x181FA8u: goto label_181fa8;
            case 0x181FC4u: goto label_181fc4;
            case 0x181FC8u: goto label_181fc8;
            case 0x181FE8u: goto label_181fe8;
            case 0x182004u: goto label_182004;
            case 0x182008u: goto label_182008;
            case 0x182028u: goto label_182028;
            case 0x182044u: goto label_182044;
            case 0x182048u: goto label_182048;
            case 0x182068u: goto label_182068;
            case 0x182084u: goto label_182084;
            case 0x182088u: goto label_182088;
            case 0x1820A8u: goto label_1820a8;
            case 0x1820C4u: goto label_1820c4;
            case 0x1820C8u: goto label_1820c8;
            case 0x1820E8u: goto label_1820e8;
            case 0x182104u: goto label_182104;
            case 0x182108u: goto label_182108;
            case 0x182128u: goto label_182128;
            case 0x182144u: goto label_182144;
            case 0x182148u: goto label_182148;
            case 0x182168u: goto label_182168;
            case 0x182184u: goto label_182184;
            case 0x182188u: goto label_182188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181E54u;
    // 0x181e54: 0x0  nop
    ctx->pc = 0x181e54u;
    // NOP
    // 0x181e58: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x181e58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x181e5c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x181e5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x181e60: 0xc0603d8  jal         func_180F60
    ctx->pc = 0x181E60u;
    SET_GPR_U32(ctx, 31, 0x181E68u);
    ctx->pc = 0x180F60u;
    if (runtime->hasFunction(0x180F60u)) {
        auto targetFn = runtime->lookupFunction(0x180F60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181E68u; }
        if (ctx->pc != 0x181E68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180F60_0x180f60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181E68u; }
        if (ctx->pc != 0x181E68u) { return; }
    }
    ctx->pc = 0x181E68u;
label_181e68:
    // 0x181e68: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x181e68u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181e6c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x181e6cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x181e70: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x181e70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181e74: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x181E74u;
    {
        const bool branch_taken_0x181e74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181E78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181E74u;
            // 0x181e78: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181e74) {
            ctx->pc = 0x181E88u;
            goto label_181e88;
        }
    }
    ctx->pc = 0x181E7Cu;
    // 0x181e7c: 0xc06074a  jal         func_181D28
    ctx->pc = 0x181E7Cu;
    SET_GPR_U32(ctx, 31, 0x181E84u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181E84u; }
        if (ctx->pc != 0x181E84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181E84u; }
        if (ctx->pc != 0x181E84u) { return; }
    }
    ctx->pc = 0x181E84u;
label_181e84:
    // 0x181e84: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x181e84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_181e88:
    // 0x181e88: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x181e88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x181e8c: 0x3e00008  jr          $ra
    ctx->pc = 0x181E8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181E90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181E8Cu;
            // 0x181e90: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181E28u: goto label_181e28;
            case 0x181E44u: goto label_181e44;
            case 0x181E48u: goto label_181e48;
            case 0x181E68u: goto label_181e68;
            case 0x181E84u: goto label_181e84;
            case 0x181E88u: goto label_181e88;
            case 0x181EA8u: goto label_181ea8;
            case 0x181EC4u: goto label_181ec4;
            case 0x181EC8u: goto label_181ec8;
            case 0x181EE8u: goto label_181ee8;
            case 0x181F04u: goto label_181f04;
            case 0x181F08u: goto label_181f08;
            case 0x181F28u: goto label_181f28;
            case 0x181F44u: goto label_181f44;
            case 0x181F48u: goto label_181f48;
            case 0x181F68u: goto label_181f68;
            case 0x181F84u: goto label_181f84;
            case 0x181F88u: goto label_181f88;
            case 0x181FA8u: goto label_181fa8;
            case 0x181FC4u: goto label_181fc4;
            case 0x181FC8u: goto label_181fc8;
            case 0x181FE8u: goto label_181fe8;
            case 0x182004u: goto label_182004;
            case 0x182008u: goto label_182008;
            case 0x182028u: goto label_182028;
            case 0x182044u: goto label_182044;
            case 0x182048u: goto label_182048;
            case 0x182068u: goto label_182068;
            case 0x182084u: goto label_182084;
            case 0x182088u: goto label_182088;
            case 0x1820A8u: goto label_1820a8;
            case 0x1820C4u: goto label_1820c4;
            case 0x1820C8u: goto label_1820c8;
            case 0x1820E8u: goto label_1820e8;
            case 0x182104u: goto label_182104;
            case 0x182108u: goto label_182108;
            case 0x182128u: goto label_182128;
            case 0x182144u: goto label_182144;
            case 0x182148u: goto label_182148;
            case 0x182168u: goto label_182168;
            case 0x182184u: goto label_182184;
            case 0x182188u: goto label_182188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181E94u;
    // 0x181e94: 0x0  nop
    ctx->pc = 0x181e94u;
    // NOP
    // 0x181e98: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x181e98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x181e9c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x181e9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x181ea0: 0xc0603f8  jal         func_180FE0
    ctx->pc = 0x181EA0u;
    SET_GPR_U32(ctx, 31, 0x181EA8u);
    ctx->pc = 0x180FE0u;
    if (runtime->hasFunction(0x180FE0u)) {
        auto targetFn = runtime->lookupFunction(0x180FE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181EA8u; }
        if (ctx->pc != 0x181EA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180FE0_0x180fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181EA8u; }
        if (ctx->pc != 0x181EA8u) { return; }
    }
    ctx->pc = 0x181EA8u;
label_181ea8:
    // 0x181ea8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x181ea8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181eac: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x181eacu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x181eb0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x181eb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181eb4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x181EB4u;
    {
        const bool branch_taken_0x181eb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181EB4u;
            // 0x181eb8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181eb4) {
            ctx->pc = 0x181EC8u;
            goto label_181ec8;
        }
    }
    ctx->pc = 0x181EBCu;
    // 0x181ebc: 0xc06074a  jal         func_181D28
    ctx->pc = 0x181EBCu;
    SET_GPR_U32(ctx, 31, 0x181EC4u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181EC4u; }
        if (ctx->pc != 0x181EC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181EC4u; }
        if (ctx->pc != 0x181EC4u) { return; }
    }
    ctx->pc = 0x181EC4u;
label_181ec4:
    // 0x181ec4: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x181ec4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_181ec8:
    // 0x181ec8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x181ec8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x181ecc: 0x3e00008  jr          $ra
    ctx->pc = 0x181ECCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181ECCu;
            // 0x181ed0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181E28u: goto label_181e28;
            case 0x181E44u: goto label_181e44;
            case 0x181E48u: goto label_181e48;
            case 0x181E68u: goto label_181e68;
            case 0x181E84u: goto label_181e84;
            case 0x181E88u: goto label_181e88;
            case 0x181EA8u: goto label_181ea8;
            case 0x181EC4u: goto label_181ec4;
            case 0x181EC8u: goto label_181ec8;
            case 0x181EE8u: goto label_181ee8;
            case 0x181F04u: goto label_181f04;
            case 0x181F08u: goto label_181f08;
            case 0x181F28u: goto label_181f28;
            case 0x181F44u: goto label_181f44;
            case 0x181F48u: goto label_181f48;
            case 0x181F68u: goto label_181f68;
            case 0x181F84u: goto label_181f84;
            case 0x181F88u: goto label_181f88;
            case 0x181FA8u: goto label_181fa8;
            case 0x181FC4u: goto label_181fc4;
            case 0x181FC8u: goto label_181fc8;
            case 0x181FE8u: goto label_181fe8;
            case 0x182004u: goto label_182004;
            case 0x182008u: goto label_182008;
            case 0x182028u: goto label_182028;
            case 0x182044u: goto label_182044;
            case 0x182048u: goto label_182048;
            case 0x182068u: goto label_182068;
            case 0x182084u: goto label_182084;
            case 0x182088u: goto label_182088;
            case 0x1820A8u: goto label_1820a8;
            case 0x1820C4u: goto label_1820c4;
            case 0x1820C8u: goto label_1820c8;
            case 0x1820E8u: goto label_1820e8;
            case 0x182104u: goto label_182104;
            case 0x182108u: goto label_182108;
            case 0x182128u: goto label_182128;
            case 0x182144u: goto label_182144;
            case 0x182148u: goto label_182148;
            case 0x182168u: goto label_182168;
            case 0x182184u: goto label_182184;
            case 0x182188u: goto label_182188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181ED4u;
    // 0x181ed4: 0x0  nop
    ctx->pc = 0x181ed4u;
    // NOP
    // 0x181ed8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x181ed8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x181edc: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x181edcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x181ee0: 0xc06048c  jal         func_181230
    ctx->pc = 0x181EE0u;
    SET_GPR_U32(ctx, 31, 0x181EE8u);
    ctx->pc = 0x181230u;
    if (runtime->hasFunction(0x181230u)) {
        auto targetFn = runtime->lookupFunction(0x181230u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181EE8u; }
        if (ctx->pc != 0x181EE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181230_0x181230(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181EE8u; }
        if (ctx->pc != 0x181EE8u) { return; }
    }
    ctx->pc = 0x181EE8u;
label_181ee8:
    // 0x181ee8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x181ee8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181eec: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x181eecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x181ef0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x181ef0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181ef4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x181EF4u;
    {
        const bool branch_taken_0x181ef4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181EF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181EF4u;
            // 0x181ef8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181ef4) {
            ctx->pc = 0x181F08u;
            goto label_181f08;
        }
    }
    ctx->pc = 0x181EFCu;
    // 0x181efc: 0xc06074a  jal         func_181D28
    ctx->pc = 0x181EFCu;
    SET_GPR_U32(ctx, 31, 0x181F04u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F04u; }
        if (ctx->pc != 0x181F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F04u; }
        if (ctx->pc != 0x181F04u) { return; }
    }
    ctx->pc = 0x181F04u;
label_181f04:
    // 0x181f04: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x181f04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_181f08:
    // 0x181f08: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x181f08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x181f0c: 0x3e00008  jr          $ra
    ctx->pc = 0x181F0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181F10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181F0Cu;
            // 0x181f10: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181E28u: goto label_181e28;
            case 0x181E44u: goto label_181e44;
            case 0x181E48u: goto label_181e48;
            case 0x181E68u: goto label_181e68;
            case 0x181E84u: goto label_181e84;
            case 0x181E88u: goto label_181e88;
            case 0x181EA8u: goto label_181ea8;
            case 0x181EC4u: goto label_181ec4;
            case 0x181EC8u: goto label_181ec8;
            case 0x181EE8u: goto label_181ee8;
            case 0x181F04u: goto label_181f04;
            case 0x181F08u: goto label_181f08;
            case 0x181F28u: goto label_181f28;
            case 0x181F44u: goto label_181f44;
            case 0x181F48u: goto label_181f48;
            case 0x181F68u: goto label_181f68;
            case 0x181F84u: goto label_181f84;
            case 0x181F88u: goto label_181f88;
            case 0x181FA8u: goto label_181fa8;
            case 0x181FC4u: goto label_181fc4;
            case 0x181FC8u: goto label_181fc8;
            case 0x181FE8u: goto label_181fe8;
            case 0x182004u: goto label_182004;
            case 0x182008u: goto label_182008;
            case 0x182028u: goto label_182028;
            case 0x182044u: goto label_182044;
            case 0x182048u: goto label_182048;
            case 0x182068u: goto label_182068;
            case 0x182084u: goto label_182084;
            case 0x182088u: goto label_182088;
            case 0x1820A8u: goto label_1820a8;
            case 0x1820C4u: goto label_1820c4;
            case 0x1820C8u: goto label_1820c8;
            case 0x1820E8u: goto label_1820e8;
            case 0x182104u: goto label_182104;
            case 0x182108u: goto label_182108;
            case 0x182128u: goto label_182128;
            case 0x182144u: goto label_182144;
            case 0x182148u: goto label_182148;
            case 0x182168u: goto label_182168;
            case 0x182184u: goto label_182184;
            case 0x182188u: goto label_182188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181F14u;
    // 0x181f14: 0x0  nop
    ctx->pc = 0x181f14u;
    // NOP
    // 0x181f18: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x181f18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x181f1c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x181f1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x181f20: 0xc0604c4  jal         func_181310
    ctx->pc = 0x181F20u;
    SET_GPR_U32(ctx, 31, 0x181F28u);
    ctx->pc = 0x181310u;
    if (runtime->hasFunction(0x181310u)) {
        auto targetFn = runtime->lookupFunction(0x181310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F28u; }
        if (ctx->pc != 0x181F28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181310_0x181310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F28u; }
        if (ctx->pc != 0x181F28u) { return; }
    }
    ctx->pc = 0x181F28u;
label_181f28:
    // 0x181f28: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x181f28u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181f2c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x181f2cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x181f30: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x181f30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181f34: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x181F34u;
    {
        const bool branch_taken_0x181f34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181F38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181F34u;
            // 0x181f38: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181f34) {
            ctx->pc = 0x181F48u;
            goto label_181f48;
        }
    }
    ctx->pc = 0x181F3Cu;
    // 0x181f3c: 0xc06074a  jal         func_181D28
    ctx->pc = 0x181F3Cu;
    SET_GPR_U32(ctx, 31, 0x181F44u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F44u; }
        if (ctx->pc != 0x181F44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F44u; }
        if (ctx->pc != 0x181F44u) { return; }
    }
    ctx->pc = 0x181F44u;
label_181f44:
    // 0x181f44: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x181f44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_181f48:
    // 0x181f48: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x181f48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x181f4c: 0x3e00008  jr          $ra
    ctx->pc = 0x181F4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181F50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181F4Cu;
            // 0x181f50: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181E28u: goto label_181e28;
            case 0x181E44u: goto label_181e44;
            case 0x181E48u: goto label_181e48;
            case 0x181E68u: goto label_181e68;
            case 0x181E84u: goto label_181e84;
            case 0x181E88u: goto label_181e88;
            case 0x181EA8u: goto label_181ea8;
            case 0x181EC4u: goto label_181ec4;
            case 0x181EC8u: goto label_181ec8;
            case 0x181EE8u: goto label_181ee8;
            case 0x181F04u: goto label_181f04;
            case 0x181F08u: goto label_181f08;
            case 0x181F28u: goto label_181f28;
            case 0x181F44u: goto label_181f44;
            case 0x181F48u: goto label_181f48;
            case 0x181F68u: goto label_181f68;
            case 0x181F84u: goto label_181f84;
            case 0x181F88u: goto label_181f88;
            case 0x181FA8u: goto label_181fa8;
            case 0x181FC4u: goto label_181fc4;
            case 0x181FC8u: goto label_181fc8;
            case 0x181FE8u: goto label_181fe8;
            case 0x182004u: goto label_182004;
            case 0x182008u: goto label_182008;
            case 0x182028u: goto label_182028;
            case 0x182044u: goto label_182044;
            case 0x182048u: goto label_182048;
            case 0x182068u: goto label_182068;
            case 0x182084u: goto label_182084;
            case 0x182088u: goto label_182088;
            case 0x1820A8u: goto label_1820a8;
            case 0x1820C4u: goto label_1820c4;
            case 0x1820C8u: goto label_1820c8;
            case 0x1820E8u: goto label_1820e8;
            case 0x182104u: goto label_182104;
            case 0x182108u: goto label_182108;
            case 0x182128u: goto label_182128;
            case 0x182144u: goto label_182144;
            case 0x182148u: goto label_182148;
            case 0x182168u: goto label_182168;
            case 0x182184u: goto label_182184;
            case 0x182188u: goto label_182188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181F54u;
    // 0x181f54: 0x0  nop
    ctx->pc = 0x181f54u;
    // NOP
    // 0x181f58: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x181f58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x181f5c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x181f5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x181f60: 0xc0604fc  jal         func_1813F0
    ctx->pc = 0x181F60u;
    SET_GPR_U32(ctx, 31, 0x181F68u);
    ctx->pc = 0x1813F0u;
    if (runtime->hasFunction(0x1813F0u)) {
        auto targetFn = runtime->lookupFunction(0x1813F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F68u; }
        if (ctx->pc != 0x181F68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001813F0_0x1813f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F68u; }
        if (ctx->pc != 0x181F68u) { return; }
    }
    ctx->pc = 0x181F68u;
label_181f68:
    // 0x181f68: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x181f68u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181f6c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x181f6cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x181f70: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x181f70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181f74: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x181F74u;
    {
        const bool branch_taken_0x181f74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181F78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181F74u;
            // 0x181f78: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181f74) {
            ctx->pc = 0x181F88u;
            goto label_181f88;
        }
    }
    ctx->pc = 0x181F7Cu;
    // 0x181f7c: 0xc06074a  jal         func_181D28
    ctx->pc = 0x181F7Cu;
    SET_GPR_U32(ctx, 31, 0x181F84u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F84u; }
        if (ctx->pc != 0x181F84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F84u; }
        if (ctx->pc != 0x181F84u) { return; }
    }
    ctx->pc = 0x181F84u;
label_181f84:
    // 0x181f84: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x181f84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_181f88:
    // 0x181f88: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x181f88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x181f8c: 0x3e00008  jr          $ra
    ctx->pc = 0x181F8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181F90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181F8Cu;
            // 0x181f90: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181E28u: goto label_181e28;
            case 0x181E44u: goto label_181e44;
            case 0x181E48u: goto label_181e48;
            case 0x181E68u: goto label_181e68;
            case 0x181E84u: goto label_181e84;
            case 0x181E88u: goto label_181e88;
            case 0x181EA8u: goto label_181ea8;
            case 0x181EC4u: goto label_181ec4;
            case 0x181EC8u: goto label_181ec8;
            case 0x181EE8u: goto label_181ee8;
            case 0x181F04u: goto label_181f04;
            case 0x181F08u: goto label_181f08;
            case 0x181F28u: goto label_181f28;
            case 0x181F44u: goto label_181f44;
            case 0x181F48u: goto label_181f48;
            case 0x181F68u: goto label_181f68;
            case 0x181F84u: goto label_181f84;
            case 0x181F88u: goto label_181f88;
            case 0x181FA8u: goto label_181fa8;
            case 0x181FC4u: goto label_181fc4;
            case 0x181FC8u: goto label_181fc8;
            case 0x181FE8u: goto label_181fe8;
            case 0x182004u: goto label_182004;
            case 0x182008u: goto label_182008;
            case 0x182028u: goto label_182028;
            case 0x182044u: goto label_182044;
            case 0x182048u: goto label_182048;
            case 0x182068u: goto label_182068;
            case 0x182084u: goto label_182084;
            case 0x182088u: goto label_182088;
            case 0x1820A8u: goto label_1820a8;
            case 0x1820C4u: goto label_1820c4;
            case 0x1820C8u: goto label_1820c8;
            case 0x1820E8u: goto label_1820e8;
            case 0x182104u: goto label_182104;
            case 0x182108u: goto label_182108;
            case 0x182128u: goto label_182128;
            case 0x182144u: goto label_182144;
            case 0x182148u: goto label_182148;
            case 0x182168u: goto label_182168;
            case 0x182184u: goto label_182184;
            case 0x182188u: goto label_182188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181F94u;
    // 0x181f94: 0x0  nop
    ctx->pc = 0x181f94u;
    // NOP
    // 0x181f98: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x181f98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x181f9c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x181f9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x181fa0: 0xc06052a  jal         func_1814A8
    ctx->pc = 0x181FA0u;
    SET_GPR_U32(ctx, 31, 0x181FA8u);
    ctx->pc = 0x1814A8u;
    if (runtime->hasFunction(0x1814A8u)) {
        auto targetFn = runtime->lookupFunction(0x1814A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181FA8u; }
        if (ctx->pc != 0x181FA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001814A8_0x1814a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181FA8u; }
        if (ctx->pc != 0x181FA8u) { return; }
    }
    ctx->pc = 0x181FA8u;
label_181fa8:
    // 0x181fa8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x181fa8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181fac: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x181facu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x181fb0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x181fb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181fb4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x181FB4u;
    {
        const bool branch_taken_0x181fb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181FB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181FB4u;
            // 0x181fb8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181fb4) {
            ctx->pc = 0x181FC8u;
            goto label_181fc8;
        }
    }
    ctx->pc = 0x181FBCu;
    // 0x181fbc: 0xc06074a  jal         func_181D28
    ctx->pc = 0x181FBCu;
    SET_GPR_U32(ctx, 31, 0x181FC4u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181FC4u; }
        if (ctx->pc != 0x181FC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181FC4u; }
        if (ctx->pc != 0x181FC4u) { return; }
    }
    ctx->pc = 0x181FC4u;
label_181fc4:
    // 0x181fc4: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x181fc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_181fc8:
    // 0x181fc8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x181fc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x181fcc: 0x3e00008  jr          $ra
    ctx->pc = 0x181FCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181FD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181FCCu;
            // 0x181fd0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181E28u: goto label_181e28;
            case 0x181E44u: goto label_181e44;
            case 0x181E48u: goto label_181e48;
            case 0x181E68u: goto label_181e68;
            case 0x181E84u: goto label_181e84;
            case 0x181E88u: goto label_181e88;
            case 0x181EA8u: goto label_181ea8;
            case 0x181EC4u: goto label_181ec4;
            case 0x181EC8u: goto label_181ec8;
            case 0x181EE8u: goto label_181ee8;
            case 0x181F04u: goto label_181f04;
            case 0x181F08u: goto label_181f08;
            case 0x181F28u: goto label_181f28;
            case 0x181F44u: goto label_181f44;
            case 0x181F48u: goto label_181f48;
            case 0x181F68u: goto label_181f68;
            case 0x181F84u: goto label_181f84;
            case 0x181F88u: goto label_181f88;
            case 0x181FA8u: goto label_181fa8;
            case 0x181FC4u: goto label_181fc4;
            case 0x181FC8u: goto label_181fc8;
            case 0x181FE8u: goto label_181fe8;
            case 0x182004u: goto label_182004;
            case 0x182008u: goto label_182008;
            case 0x182028u: goto label_182028;
            case 0x182044u: goto label_182044;
            case 0x182048u: goto label_182048;
            case 0x182068u: goto label_182068;
            case 0x182084u: goto label_182084;
            case 0x182088u: goto label_182088;
            case 0x1820A8u: goto label_1820a8;
            case 0x1820C4u: goto label_1820c4;
            case 0x1820C8u: goto label_1820c8;
            case 0x1820E8u: goto label_1820e8;
            case 0x182104u: goto label_182104;
            case 0x182108u: goto label_182108;
            case 0x182128u: goto label_182128;
            case 0x182144u: goto label_182144;
            case 0x182148u: goto label_182148;
            case 0x182168u: goto label_182168;
            case 0x182184u: goto label_182184;
            case 0x182188u: goto label_182188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181FD4u;
    // 0x181fd4: 0x0  nop
    ctx->pc = 0x181fd4u;
    // NOP
    // 0x181fd8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x181fd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x181fdc: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x181fdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x181fe0: 0xc060622  jal         func_181888
    ctx->pc = 0x181FE0u;
    SET_GPR_U32(ctx, 31, 0x181FE8u);
    ctx->pc = 0x181888u;
    if (runtime->hasFunction(0x181888u)) {
        auto targetFn = runtime->lookupFunction(0x181888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181FE8u; }
        if (ctx->pc != 0x181FE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181888_0x181888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181FE8u; }
        if (ctx->pc != 0x181FE8u) { return; }
    }
    ctx->pc = 0x181FE8u;
label_181fe8:
    // 0x181fe8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x181fe8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181fec: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x181fecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x181ff0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x181ff0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181ff4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x181FF4u;
    {
        const bool branch_taken_0x181ff4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181FF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181FF4u;
            // 0x181ff8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181ff4) {
            ctx->pc = 0x182008u;
            goto label_182008;
        }
    }
    ctx->pc = 0x181FFCu;
    // 0x181ffc: 0xc06074a  jal         func_181D28
    ctx->pc = 0x181FFCu;
    SET_GPR_U32(ctx, 31, 0x182004u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182004u; }
        if (ctx->pc != 0x182004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182004u; }
        if (ctx->pc != 0x182004u) { return; }
    }
    ctx->pc = 0x182004u;
label_182004:
    // 0x182004: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x182004u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_182008:
    // 0x182008: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x182008u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18200c: 0x3e00008  jr          $ra
    ctx->pc = 0x18200Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18200Cu;
            // 0x182010: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181E28u: goto label_181e28;
            case 0x181E44u: goto label_181e44;
            case 0x181E48u: goto label_181e48;
            case 0x181E68u: goto label_181e68;
            case 0x181E84u: goto label_181e84;
            case 0x181E88u: goto label_181e88;
            case 0x181EA8u: goto label_181ea8;
            case 0x181EC4u: goto label_181ec4;
            case 0x181EC8u: goto label_181ec8;
            case 0x181EE8u: goto label_181ee8;
            case 0x181F04u: goto label_181f04;
            case 0x181F08u: goto label_181f08;
            case 0x181F28u: goto label_181f28;
            case 0x181F44u: goto label_181f44;
            case 0x181F48u: goto label_181f48;
            case 0x181F68u: goto label_181f68;
            case 0x181F84u: goto label_181f84;
            case 0x181F88u: goto label_181f88;
            case 0x181FA8u: goto label_181fa8;
            case 0x181FC4u: goto label_181fc4;
            case 0x181FC8u: goto label_181fc8;
            case 0x181FE8u: goto label_181fe8;
            case 0x182004u: goto label_182004;
            case 0x182008u: goto label_182008;
            case 0x182028u: goto label_182028;
            case 0x182044u: goto label_182044;
            case 0x182048u: goto label_182048;
            case 0x182068u: goto label_182068;
            case 0x182084u: goto label_182084;
            case 0x182088u: goto label_182088;
            case 0x1820A8u: goto label_1820a8;
            case 0x1820C4u: goto label_1820c4;
            case 0x1820C8u: goto label_1820c8;
            case 0x1820E8u: goto label_1820e8;
            case 0x182104u: goto label_182104;
            case 0x182108u: goto label_182108;
            case 0x182128u: goto label_182128;
            case 0x182144u: goto label_182144;
            case 0x182148u: goto label_182148;
            case 0x182168u: goto label_182168;
            case 0x182184u: goto label_182184;
            case 0x182188u: goto label_182188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182014u;
    // 0x182014: 0x0  nop
    ctx->pc = 0x182014u;
    // NOP
    // 0x182018: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x182018u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18201c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18201cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x182020: 0xc060594  jal         func_181650
    ctx->pc = 0x182020u;
    SET_GPR_U32(ctx, 31, 0x182028u);
    ctx->pc = 0x181650u;
    if (runtime->hasFunction(0x181650u)) {
        auto targetFn = runtime->lookupFunction(0x181650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182028u; }
        if (ctx->pc != 0x182028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181650_0x181650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182028u; }
        if (ctx->pc != 0x182028u) { return; }
    }
    ctx->pc = 0x182028u;
label_182028:
    // 0x182028: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x182028u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18202c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x18202cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x182030: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x182030u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182034: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x182034u;
    {
        const bool branch_taken_0x182034 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x182038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182034u;
            // 0x182038: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182034) {
            ctx->pc = 0x182048u;
            goto label_182048;
        }
    }
    ctx->pc = 0x18203Cu;
    // 0x18203c: 0xc06074a  jal         func_181D28
    ctx->pc = 0x18203Cu;
    SET_GPR_U32(ctx, 31, 0x182044u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182044u; }
        if (ctx->pc != 0x182044u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182044u; }
        if (ctx->pc != 0x182044u) { return; }
    }
    ctx->pc = 0x182044u;
label_182044:
    // 0x182044: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x182044u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_182048:
    // 0x182048: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x182048u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18204c: 0x3e00008  jr          $ra
    ctx->pc = 0x18204Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18204Cu;
            // 0x182050: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181E28u: goto label_181e28;
            case 0x181E44u: goto label_181e44;
            case 0x181E48u: goto label_181e48;
            case 0x181E68u: goto label_181e68;
            case 0x181E84u: goto label_181e84;
            case 0x181E88u: goto label_181e88;
            case 0x181EA8u: goto label_181ea8;
            case 0x181EC4u: goto label_181ec4;
            case 0x181EC8u: goto label_181ec8;
            case 0x181EE8u: goto label_181ee8;
            case 0x181F04u: goto label_181f04;
            case 0x181F08u: goto label_181f08;
            case 0x181F28u: goto label_181f28;
            case 0x181F44u: goto label_181f44;
            case 0x181F48u: goto label_181f48;
            case 0x181F68u: goto label_181f68;
            case 0x181F84u: goto label_181f84;
            case 0x181F88u: goto label_181f88;
            case 0x181FA8u: goto label_181fa8;
            case 0x181FC4u: goto label_181fc4;
            case 0x181FC8u: goto label_181fc8;
            case 0x181FE8u: goto label_181fe8;
            case 0x182004u: goto label_182004;
            case 0x182008u: goto label_182008;
            case 0x182028u: goto label_182028;
            case 0x182044u: goto label_182044;
            case 0x182048u: goto label_182048;
            case 0x182068u: goto label_182068;
            case 0x182084u: goto label_182084;
            case 0x182088u: goto label_182088;
            case 0x1820A8u: goto label_1820a8;
            case 0x1820C4u: goto label_1820c4;
            case 0x1820C8u: goto label_1820c8;
            case 0x1820E8u: goto label_1820e8;
            case 0x182104u: goto label_182104;
            case 0x182108u: goto label_182108;
            case 0x182128u: goto label_182128;
            case 0x182144u: goto label_182144;
            case 0x182148u: goto label_182148;
            case 0x182168u: goto label_182168;
            case 0x182184u: goto label_182184;
            case 0x182188u: goto label_182188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182054u;
    // 0x182054: 0x0  nop
    ctx->pc = 0x182054u;
    // NOP
    // 0x182058: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x182058u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18205c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18205cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x182060: 0xc0605c2  jal         func_181708
    ctx->pc = 0x182060u;
    SET_GPR_U32(ctx, 31, 0x182068u);
    ctx->pc = 0x181708u;
    if (runtime->hasFunction(0x181708u)) {
        auto targetFn = runtime->lookupFunction(0x181708u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182068u; }
        if (ctx->pc != 0x182068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181708_0x181708(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182068u; }
        if (ctx->pc != 0x182068u) { return; }
    }
    ctx->pc = 0x182068u;
label_182068:
    // 0x182068: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x182068u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18206c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x18206cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x182070: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x182070u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182074: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x182074u;
    {
        const bool branch_taken_0x182074 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x182078u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182074u;
            // 0x182078: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182074) {
            ctx->pc = 0x182088u;
            goto label_182088;
        }
    }
    ctx->pc = 0x18207Cu;
    // 0x18207c: 0xc06074a  jal         func_181D28
    ctx->pc = 0x18207Cu;
    SET_GPR_U32(ctx, 31, 0x182084u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182084u; }
        if (ctx->pc != 0x182084u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182084u; }
        if (ctx->pc != 0x182084u) { return; }
    }
    ctx->pc = 0x182084u;
label_182084:
    // 0x182084: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x182084u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_182088:
    // 0x182088: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x182088u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18208c: 0x3e00008  jr          $ra
    ctx->pc = 0x18208Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182090u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18208Cu;
            // 0x182090: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181E28u: goto label_181e28;
            case 0x181E44u: goto label_181e44;
            case 0x181E48u: goto label_181e48;
            case 0x181E68u: goto label_181e68;
            case 0x181E84u: goto label_181e84;
            case 0x181E88u: goto label_181e88;
            case 0x181EA8u: goto label_181ea8;
            case 0x181EC4u: goto label_181ec4;
            case 0x181EC8u: goto label_181ec8;
            case 0x181EE8u: goto label_181ee8;
            case 0x181F04u: goto label_181f04;
            case 0x181F08u: goto label_181f08;
            case 0x181F28u: goto label_181f28;
            case 0x181F44u: goto label_181f44;
            case 0x181F48u: goto label_181f48;
            case 0x181F68u: goto label_181f68;
            case 0x181F84u: goto label_181f84;
            case 0x181F88u: goto label_181f88;
            case 0x181FA8u: goto label_181fa8;
            case 0x181FC4u: goto label_181fc4;
            case 0x181FC8u: goto label_181fc8;
            case 0x181FE8u: goto label_181fe8;
            case 0x182004u: goto label_182004;
            case 0x182008u: goto label_182008;
            case 0x182028u: goto label_182028;
            case 0x182044u: goto label_182044;
            case 0x182048u: goto label_182048;
            case 0x182068u: goto label_182068;
            case 0x182084u: goto label_182084;
            case 0x182088u: goto label_182088;
            case 0x1820A8u: goto label_1820a8;
            case 0x1820C4u: goto label_1820c4;
            case 0x1820C8u: goto label_1820c8;
            case 0x1820E8u: goto label_1820e8;
            case 0x182104u: goto label_182104;
            case 0x182108u: goto label_182108;
            case 0x182128u: goto label_182128;
            case 0x182144u: goto label_182144;
            case 0x182148u: goto label_182148;
            case 0x182168u: goto label_182168;
            case 0x182184u: goto label_182184;
            case 0x182188u: goto label_182188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182094u;
    // 0x182094: 0x0  nop
    ctx->pc = 0x182094u;
    // NOP
    // 0x182098: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x182098u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18209c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18209cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1820a0: 0xc060558  jal         func_181560
    ctx->pc = 0x1820A0u;
    SET_GPR_U32(ctx, 31, 0x1820A8u);
    ctx->pc = 0x181560u;
    if (runtime->hasFunction(0x181560u)) {
        auto targetFn = runtime->lookupFunction(0x181560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1820A8u; }
        if (ctx->pc != 0x1820A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181560_0x181560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1820A8u; }
        if (ctx->pc != 0x1820A8u) { return; }
    }
    ctx->pc = 0x1820A8u;
label_1820a8:
    // 0x1820a8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1820a8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1820ac: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x1820acu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x1820b0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1820b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1820b4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1820B4u;
    {
        const bool branch_taken_0x1820b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1820B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1820B4u;
            // 0x1820b8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1820b4) {
            ctx->pc = 0x1820C8u;
            goto label_1820c8;
        }
    }
    ctx->pc = 0x1820BCu;
    // 0x1820bc: 0xc06074a  jal         func_181D28
    ctx->pc = 0x1820BCu;
    SET_GPR_U32(ctx, 31, 0x1820C4u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1820C4u; }
        if (ctx->pc != 0x1820C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1820C4u; }
        if (ctx->pc != 0x1820C4u) { return; }
    }
    ctx->pc = 0x1820C4u;
label_1820c4:
    // 0x1820c4: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1820c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_1820c8:
    // 0x1820c8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1820c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1820cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1820CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1820D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1820CCu;
            // 0x1820d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181E28u: goto label_181e28;
            case 0x181E44u: goto label_181e44;
            case 0x181E48u: goto label_181e48;
            case 0x181E68u: goto label_181e68;
            case 0x181E84u: goto label_181e84;
            case 0x181E88u: goto label_181e88;
            case 0x181EA8u: goto label_181ea8;
            case 0x181EC4u: goto label_181ec4;
            case 0x181EC8u: goto label_181ec8;
            case 0x181EE8u: goto label_181ee8;
            case 0x181F04u: goto label_181f04;
            case 0x181F08u: goto label_181f08;
            case 0x181F28u: goto label_181f28;
            case 0x181F44u: goto label_181f44;
            case 0x181F48u: goto label_181f48;
            case 0x181F68u: goto label_181f68;
            case 0x181F84u: goto label_181f84;
            case 0x181F88u: goto label_181f88;
            case 0x181FA8u: goto label_181fa8;
            case 0x181FC4u: goto label_181fc4;
            case 0x181FC8u: goto label_181fc8;
            case 0x181FE8u: goto label_181fe8;
            case 0x182004u: goto label_182004;
            case 0x182008u: goto label_182008;
            case 0x182028u: goto label_182028;
            case 0x182044u: goto label_182044;
            case 0x182048u: goto label_182048;
            case 0x182068u: goto label_182068;
            case 0x182084u: goto label_182084;
            case 0x182088u: goto label_182088;
            case 0x1820A8u: goto label_1820a8;
            case 0x1820C4u: goto label_1820c4;
            case 0x1820C8u: goto label_1820c8;
            case 0x1820E8u: goto label_1820e8;
            case 0x182104u: goto label_182104;
            case 0x182108u: goto label_182108;
            case 0x182128u: goto label_182128;
            case 0x182144u: goto label_182144;
            case 0x182148u: goto label_182148;
            case 0x182168u: goto label_182168;
            case 0x182184u: goto label_182184;
            case 0x182188u: goto label_182188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1820D4u;
    // 0x1820d4: 0x0  nop
    ctx->pc = 0x1820d4u;
    // NOP
    // 0x1820d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1820d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1820dc: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1820dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1820e0: 0xc0605f2  jal         func_1817C8
    ctx->pc = 0x1820E0u;
    SET_GPR_U32(ctx, 31, 0x1820E8u);
    ctx->pc = 0x1820E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1820E0u;
            // 0x1820e4: 0x30c6ffff  andi        $a2, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1817C8u;
    if (runtime->hasFunction(0x1817C8u)) {
        auto targetFn = runtime->lookupFunction(0x1817C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1820E8u; }
        if (ctx->pc != 0x1820E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001817C8_0x1817c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1820E8u; }
        if (ctx->pc != 0x1820E8u) { return; }
    }
    ctx->pc = 0x1820E8u;
label_1820e8:
    // 0x1820e8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1820e8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1820ec: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x1820ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x1820f0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1820f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1820f4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1820F4u;
    {
        const bool branch_taken_0x1820f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1820F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1820F4u;
            // 0x1820f8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1820f4) {
            ctx->pc = 0x182108u;
            goto label_182108;
        }
    }
    ctx->pc = 0x1820FCu;
    // 0x1820fc: 0xc06074a  jal         func_181D28
    ctx->pc = 0x1820FCu;
    SET_GPR_U32(ctx, 31, 0x182104u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182104u; }
        if (ctx->pc != 0x182104u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182104u; }
        if (ctx->pc != 0x182104u) { return; }
    }
    ctx->pc = 0x182104u;
label_182104:
    // 0x182104: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x182104u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_182108:
    // 0x182108: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x182108u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18210c: 0x3e00008  jr          $ra
    ctx->pc = 0x18210Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18210Cu;
            // 0x182110: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181E28u: goto label_181e28;
            case 0x181E44u: goto label_181e44;
            case 0x181E48u: goto label_181e48;
            case 0x181E68u: goto label_181e68;
            case 0x181E84u: goto label_181e84;
            case 0x181E88u: goto label_181e88;
            case 0x181EA8u: goto label_181ea8;
            case 0x181EC4u: goto label_181ec4;
            case 0x181EC8u: goto label_181ec8;
            case 0x181EE8u: goto label_181ee8;
            case 0x181F04u: goto label_181f04;
            case 0x181F08u: goto label_181f08;
            case 0x181F28u: goto label_181f28;
            case 0x181F44u: goto label_181f44;
            case 0x181F48u: goto label_181f48;
            case 0x181F68u: goto label_181f68;
            case 0x181F84u: goto label_181f84;
            case 0x181F88u: goto label_181f88;
            case 0x181FA8u: goto label_181fa8;
            case 0x181FC4u: goto label_181fc4;
            case 0x181FC8u: goto label_181fc8;
            case 0x181FE8u: goto label_181fe8;
            case 0x182004u: goto label_182004;
            case 0x182008u: goto label_182008;
            case 0x182028u: goto label_182028;
            case 0x182044u: goto label_182044;
            case 0x182048u: goto label_182048;
            case 0x182068u: goto label_182068;
            case 0x182084u: goto label_182084;
            case 0x182088u: goto label_182088;
            case 0x1820A8u: goto label_1820a8;
            case 0x1820C4u: goto label_1820c4;
            case 0x1820C8u: goto label_1820c8;
            case 0x1820E8u: goto label_1820e8;
            case 0x182104u: goto label_182104;
            case 0x182108u: goto label_182108;
            case 0x182128u: goto label_182128;
            case 0x182144u: goto label_182144;
            case 0x182148u: goto label_182148;
            case 0x182168u: goto label_182168;
            case 0x182184u: goto label_182184;
            case 0x182188u: goto label_182188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182114u;
    // 0x182114: 0x0  nop
    ctx->pc = 0x182114u;
    // NOP
    // 0x182118: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x182118u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18211c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18211cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x182120: 0xc06043c  jal         func_1810F0
    ctx->pc = 0x182120u;
    SET_GPR_U32(ctx, 31, 0x182128u);
    ctx->pc = 0x1810F0u;
    if (runtime->hasFunction(0x1810F0u)) {
        auto targetFn = runtime->lookupFunction(0x1810F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182128u; }
        if (ctx->pc != 0x182128u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001810F0_0x1810f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182128u; }
        if (ctx->pc != 0x182128u) { return; }
    }
    ctx->pc = 0x182128u;
label_182128:
    // 0x182128: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x182128u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18212c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x18212cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x182130: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x182130u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182134: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x182134u;
    {
        const bool branch_taken_0x182134 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x182138u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182134u;
            // 0x182138: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182134) {
            ctx->pc = 0x182148u;
            goto label_182148;
        }
    }
    ctx->pc = 0x18213Cu;
    // 0x18213c: 0xc06074a  jal         func_181D28
    ctx->pc = 0x18213Cu;
    SET_GPR_U32(ctx, 31, 0x182144u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182144u; }
        if (ctx->pc != 0x182144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182144u; }
        if (ctx->pc != 0x182144u) { return; }
    }
    ctx->pc = 0x182144u;
label_182144:
    // 0x182144: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x182144u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_182148:
    // 0x182148: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x182148u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18214c: 0x3e00008  jr          $ra
    ctx->pc = 0x18214Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18214Cu;
            // 0x182150: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181E28u: goto label_181e28;
            case 0x181E44u: goto label_181e44;
            case 0x181E48u: goto label_181e48;
            case 0x181E68u: goto label_181e68;
            case 0x181E84u: goto label_181e84;
            case 0x181E88u: goto label_181e88;
            case 0x181EA8u: goto label_181ea8;
            case 0x181EC4u: goto label_181ec4;
            case 0x181EC8u: goto label_181ec8;
            case 0x181EE8u: goto label_181ee8;
            case 0x181F04u: goto label_181f04;
            case 0x181F08u: goto label_181f08;
            case 0x181F28u: goto label_181f28;
            case 0x181F44u: goto label_181f44;
            case 0x181F48u: goto label_181f48;
            case 0x181F68u: goto label_181f68;
            case 0x181F84u: goto label_181f84;
            case 0x181F88u: goto label_181f88;
            case 0x181FA8u: goto label_181fa8;
            case 0x181FC4u: goto label_181fc4;
            case 0x181FC8u: goto label_181fc8;
            case 0x181FE8u: goto label_181fe8;
            case 0x182004u: goto label_182004;
            case 0x182008u: goto label_182008;
            case 0x182028u: goto label_182028;
            case 0x182044u: goto label_182044;
            case 0x182048u: goto label_182048;
            case 0x182068u: goto label_182068;
            case 0x182084u: goto label_182084;
            case 0x182088u: goto label_182088;
            case 0x1820A8u: goto label_1820a8;
            case 0x1820C4u: goto label_1820c4;
            case 0x1820C8u: goto label_1820c8;
            case 0x1820E8u: goto label_1820e8;
            case 0x182104u: goto label_182104;
            case 0x182108u: goto label_182108;
            case 0x182128u: goto label_182128;
            case 0x182144u: goto label_182144;
            case 0x182148u: goto label_182148;
            case 0x182168u: goto label_182168;
            case 0x182184u: goto label_182184;
            case 0x182188u: goto label_182188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182154u;
    // 0x182154: 0x0  nop
    ctx->pc = 0x182154u;
    // NOP
    // 0x182158: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x182158u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18215c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18215cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x182160: 0xc06065c  jal         func_181970
    ctx->pc = 0x182160u;
    SET_GPR_U32(ctx, 31, 0x182168u);
    ctx->pc = 0x181970u;
    if (runtime->hasFunction(0x181970u)) {
        auto targetFn = runtime->lookupFunction(0x181970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182168u; }
        if (ctx->pc != 0x182168u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181970_0x181970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182168u; }
        if (ctx->pc != 0x182168u) { return; }
    }
    ctx->pc = 0x182168u;
label_182168:
    // 0x182168: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x182168u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18216c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x18216cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x182170: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x182170u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182174: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x182174u;
    {
        const bool branch_taken_0x182174 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x182178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182174u;
            // 0x182178: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182174) {
            ctx->pc = 0x182188u;
            goto label_182188;
        }
    }
    ctx->pc = 0x18217Cu;
    // 0x18217c: 0xc06074a  jal         func_181D28
    ctx->pc = 0x18217Cu;
    SET_GPR_U32(ctx, 31, 0x182184u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182184u; }
        if (ctx->pc != 0x182184u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182184u; }
        if (ctx->pc != 0x182184u) { return; }
    }
    ctx->pc = 0x182184u;
label_182184:
    // 0x182184: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x182184u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_182188:
    // 0x182188: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x182188u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18218c: 0x3e00008  jr          $ra
    ctx->pc = 0x18218Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18218Cu;
            // 0x182190: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181E28u: goto label_181e28;
            case 0x181E44u: goto label_181e44;
            case 0x181E48u: goto label_181e48;
            case 0x181E68u: goto label_181e68;
            case 0x181E84u: goto label_181e84;
            case 0x181E88u: goto label_181e88;
            case 0x181EA8u: goto label_181ea8;
            case 0x181EC4u: goto label_181ec4;
            case 0x181EC8u: goto label_181ec8;
            case 0x181EE8u: goto label_181ee8;
            case 0x181F04u: goto label_181f04;
            case 0x181F08u: goto label_181f08;
            case 0x181F28u: goto label_181f28;
            case 0x181F44u: goto label_181f44;
            case 0x181F48u: goto label_181f48;
            case 0x181F68u: goto label_181f68;
            case 0x181F84u: goto label_181f84;
            case 0x181F88u: goto label_181f88;
            case 0x181FA8u: goto label_181fa8;
            case 0x181FC4u: goto label_181fc4;
            case 0x181FC8u: goto label_181fc8;
            case 0x181FE8u: goto label_181fe8;
            case 0x182004u: goto label_182004;
            case 0x182008u: goto label_182008;
            case 0x182028u: goto label_182028;
            case 0x182044u: goto label_182044;
            case 0x182048u: goto label_182048;
            case 0x182068u: goto label_182068;
            case 0x182084u: goto label_182084;
            case 0x182088u: goto label_182088;
            case 0x1820A8u: goto label_1820a8;
            case 0x1820C4u: goto label_1820c4;
            case 0x1820C8u: goto label_1820c8;
            case 0x1820E8u: goto label_1820e8;
            case 0x182104u: goto label_182104;
            case 0x182108u: goto label_182108;
            case 0x182128u: goto label_182128;
            case 0x182144u: goto label_182144;
            case 0x182148u: goto label_182148;
            case 0x182168u: goto label_182168;
            case 0x182184u: goto label_182184;
            case 0x182188u: goto label_182188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182194u;
    // 0x182194: 0x0  nop
    ctx->pc = 0x182194u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
