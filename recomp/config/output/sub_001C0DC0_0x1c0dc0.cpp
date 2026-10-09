#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C0DC0
// Address: 0x1c0dc0 - 0x1c1260
void sub_001C0DC0_0x1c0dc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C0DC0_0x1c0dc0");
#endif

    switch (ctx->pc) {
        case 0x1c0e28u: goto label_1c0e28;
        case 0x1c0e60u: goto label_1c0e60;
        case 0x1c0e98u: goto label_1c0e98;
        case 0x1c0ed0u: goto label_1c0ed0;
        case 0x1c0f20u: goto label_1c0f20;
        case 0x1c0f80u: goto label_1c0f80;
        case 0x1c0ff8u: goto label_1c0ff8;
        case 0x1c1038u: goto label_1c1038;
        case 0x1c1078u: goto label_1c1078;
        case 0x1c10b0u: goto label_1c10b0;
        case 0x1c1118u: goto label_1c1118;
        case 0x1c1164u: goto label_1c1164;
        case 0x1c11c4u: goto label_1c11c4;
        case 0x1c124cu: goto label_1c124c;
        default: break;
    }

    ctx->pc = 0x1c0dc0u;

    // 0x1c0dc0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0dc0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0dc4: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1c0dc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c0dc8: 0xac246c64  sw          $a0, 0x6C64($at)
    ctx->pc = 0x1c0dc8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27748), GPR_U32(ctx, 4));
    // 0x1c0dcc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0dccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0dd0: 0xac206c50  sw          $zero, 0x6C50($at)
    ctx->pc = 0x1c0dd0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27728), GPR_U32(ctx, 0));
    // 0x1c0dd4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0dd4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0dd8: 0xac236ce8  sw          $v1, 0x6CE8($at)
    ctx->pc = 0x1c0dd8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27880), GPR_U32(ctx, 3));
    // 0x1c0ddc: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c0ddcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c0de0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0de0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0de4: 0xac236c74  sw          $v1, 0x6C74($at)
    ctx->pc = 0x1c0de4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27764), GPR_U32(ctx, 3));
    // 0x1c0de8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0de8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0dec: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0decu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0df0: 0xac236cf8  sw          $v1, 0x6CF8($at)
    ctx->pc = 0x1c0df0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27896), GPR_U32(ctx, 3));
    // 0x1c0df4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0df4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0df8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C0DF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C0DFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0DF8u;
            // 0x1c0dfc: 0xac206c54  sw          $zero, 0x6C54($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 27732), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C0E20u: goto label_1c0e20;
            case 0x1C0E28u: goto label_1c0e28;
            case 0x1C0E44u: goto label_1c0e44;
            case 0x1C0E4Cu: goto label_1c0e4c;
            case 0x1C0E54u: goto label_1c0e54;
            case 0x1C0E58u: goto label_1c0e58;
            case 0x1C0E60u: goto label_1c0e60;
            case 0x1C0E90u: goto label_1c0e90;
            case 0x1C0E98u: goto label_1c0e98;
            case 0x1C0EB4u: goto label_1c0eb4;
            case 0x1C0EBCu: goto label_1c0ebc;
            case 0x1C0EC4u: goto label_1c0ec4;
            case 0x1C0EC8u: goto label_1c0ec8;
            case 0x1C0ED0u: goto label_1c0ed0;
            case 0x1C0F18u: goto label_1c0f18;
            case 0x1C0F20u: goto label_1c0f20;
            case 0x1C0F50u: goto label_1c0f50;
            case 0x1C0F5Cu: goto label_1c0f5c;
            case 0x1C0F68u: goto label_1c0f68;
            case 0x1C0F78u: goto label_1c0f78;
            case 0x1C0F80u: goto label_1c0f80;
            case 0x1C0FB0u: goto label_1c0fb0;
            case 0x1C0FC0u: goto label_1c0fc0;
            case 0x1C0FD0u: goto label_1c0fd0;
            case 0x1C0FE0u: goto label_1c0fe0;
            case 0x1C0FF0u: goto label_1c0ff0;
            case 0x1C0FF8u: goto label_1c0ff8;
            case 0x1C1014u: goto label_1c1014;
            case 0x1C1020u: goto label_1c1020;
            case 0x1C102Cu: goto label_1c102c;
            case 0x1C1030u: goto label_1c1030;
            case 0x1C1038u: goto label_1c1038;
            case 0x1C1070u: goto label_1c1070;
            case 0x1C1078u: goto label_1c1078;
            case 0x1C1094u: goto label_1c1094;
            case 0x1C109Cu: goto label_1c109c;
            case 0x1C10A4u: goto label_1c10a4;
            case 0x1C10A8u: goto label_1c10a8;
            case 0x1C10B0u: goto label_1c10b0;
            case 0x1C1118u: goto label_1c1118;
            case 0x1C115Cu: goto label_1c115c;
            case 0x1C1164u: goto label_1c1164;
            case 0x1C1194u: goto label_1c1194;
            case 0x1C11A0u: goto label_1c11a0;
            case 0x1C11ACu: goto label_1c11ac;
            case 0x1C11BCu: goto label_1c11bc;
            case 0x1C11C4u: goto label_1c11c4;
            case 0x1C11E0u: goto label_1c11e0;
            case 0x1C11F0u: goto label_1c11f0;
            case 0x1C1224u: goto label_1c1224;
            case 0x1C122Cu: goto label_1c122c;
            case 0x1C1234u: goto label_1c1234;
            case 0x1C123Cu: goto label_1c123c;
            case 0x1C1240u: goto label_1c1240;
            case 0x1C1244u: goto label_1c1244;
            case 0x1C124Cu: goto label_1c124c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C0E00u;
    // 0x1c0e00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c0e00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c0e04: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c0e04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c0e08: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c0e08u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c0e0c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1c0e0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c0e10: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0E10u;
    {
        const bool branch_taken_0x1c0e10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0E14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0E10u;
            // 0x1c0e14: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0e10) {
            ctx->pc = 0x1C0E20u;
            goto label_1c0e20;
        }
    }
    ctx->pc = 0x1C0E18u;
    // 0x1c0e18: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1C0E18u;
    {
        const bool branch_taken_0x1c0e18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0E1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0E18u;
            // 0x1c0e1c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0e18) {
            ctx->pc = 0x1C0E58u;
            goto label_1c0e58;
        }
    }
    ctx->pc = 0x1C0E20u;
label_1c0e20:
    // 0x1c0e20: 0xc06ffdc  jal         func_1BFF70
    ctx->pc = 0x1C0E20u;
    SET_GPR_U32(ctx, 31, 0x1C0E28u);
    ctx->pc = 0x1BFF70u;
    if (runtime->hasFunction(0x1BFF70u)) {
        auto targetFn = runtime->lookupFunction(0x1BFF70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0E28u; }
        if (ctx->pc != 0x1C0E28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BFF70_0x1bff70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0E28u; }
        if (ctx->pc != 0x1C0E28u) { return; }
    }
    ctx->pc = 0x1C0E28u;
label_1c0e28:
    // 0x1c0e28: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0e28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0e2c: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C0E2Cu;
    {
        const bool branch_taken_0x1c0e2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0e2c) {
            ctx->pc = 0x1C0E4Cu;
            goto label_1c0e4c;
        }
    }
    ctx->pc = 0x1C0E34u;
    // 0x1c0e34: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0E34u;
    {
        const bool branch_taken_0x1c0e34 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0e34) {
            ctx->pc = 0x1C0E44u;
            goto label_1c0e44;
        }
    }
    ctx->pc = 0x1C0E3Cu;
    // 0x1c0e3c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C0E3Cu;
    {
        const bool branch_taken_0x1c0e3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0e3c) {
            ctx->pc = 0x1C0E54u;
            goto label_1c0e54;
        }
    }
    ctx->pc = 0x1C0E44u;
label_1c0e44:
    // 0x1c0e44: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0E44u;
    {
        const bool branch_taken_0x1c0e44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0E48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0E44u;
            // 0x1c0e48: 0xae000024  sw          $zero, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0e44) {
            ctx->pc = 0x1C0E54u;
            goto label_1c0e54;
        }
    }
    ctx->pc = 0x1C0E4Cu;
label_1c0e4c:
    // 0x1c0e4c: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c0e4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c0e50: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x1c0e50u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
label_1c0e54:
    // 0x1c0e54: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c0e54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c0e58:
    // 0x1c0e58: 0xc070108  jal         func_1C0420
    ctx->pc = 0x1C0E58u;
    SET_GPR_U32(ctx, 31, 0x1C0E60u);
    ctx->pc = 0x1C0420u;
    if (runtime->hasFunction(0x1C0420u)) {
        auto targetFn = runtime->lookupFunction(0x1C0420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0E60u; }
        if (ctx->pc != 0x1C0E60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0420_0x1c0420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0E60u; }
        if (ctx->pc != 0x1C0E60u) { return; }
    }
    ctx->pc = 0x1C0E60u;
label_1c0e60:
    // 0x1c0e60: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c0e60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c0e64: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c0e64u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c0e68: 0x3e00008  jr          $ra
    ctx->pc = 0x1C0E68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C0E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0E68u;
            // 0x1c0e6c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C0E20u: goto label_1c0e20;
            case 0x1C0E28u: goto label_1c0e28;
            case 0x1C0E44u: goto label_1c0e44;
            case 0x1C0E4Cu: goto label_1c0e4c;
            case 0x1C0E54u: goto label_1c0e54;
            case 0x1C0E58u: goto label_1c0e58;
            case 0x1C0E60u: goto label_1c0e60;
            case 0x1C0E90u: goto label_1c0e90;
            case 0x1C0E98u: goto label_1c0e98;
            case 0x1C0EB4u: goto label_1c0eb4;
            case 0x1C0EBCu: goto label_1c0ebc;
            case 0x1C0EC4u: goto label_1c0ec4;
            case 0x1C0EC8u: goto label_1c0ec8;
            case 0x1C0ED0u: goto label_1c0ed0;
            case 0x1C0F18u: goto label_1c0f18;
            case 0x1C0F20u: goto label_1c0f20;
            case 0x1C0F50u: goto label_1c0f50;
            case 0x1C0F5Cu: goto label_1c0f5c;
            case 0x1C0F68u: goto label_1c0f68;
            case 0x1C0F78u: goto label_1c0f78;
            case 0x1C0F80u: goto label_1c0f80;
            case 0x1C0FB0u: goto label_1c0fb0;
            case 0x1C0FC0u: goto label_1c0fc0;
            case 0x1C0FD0u: goto label_1c0fd0;
            case 0x1C0FE0u: goto label_1c0fe0;
            case 0x1C0FF0u: goto label_1c0ff0;
            case 0x1C0FF8u: goto label_1c0ff8;
            case 0x1C1014u: goto label_1c1014;
            case 0x1C1020u: goto label_1c1020;
            case 0x1C102Cu: goto label_1c102c;
            case 0x1C1030u: goto label_1c1030;
            case 0x1C1038u: goto label_1c1038;
            case 0x1C1070u: goto label_1c1070;
            case 0x1C1078u: goto label_1c1078;
            case 0x1C1094u: goto label_1c1094;
            case 0x1C109Cu: goto label_1c109c;
            case 0x1C10A4u: goto label_1c10a4;
            case 0x1C10A8u: goto label_1c10a8;
            case 0x1C10B0u: goto label_1c10b0;
            case 0x1C1118u: goto label_1c1118;
            case 0x1C115Cu: goto label_1c115c;
            case 0x1C1164u: goto label_1c1164;
            case 0x1C1194u: goto label_1c1194;
            case 0x1C11A0u: goto label_1c11a0;
            case 0x1C11ACu: goto label_1c11ac;
            case 0x1C11BCu: goto label_1c11bc;
            case 0x1C11C4u: goto label_1c11c4;
            case 0x1C11E0u: goto label_1c11e0;
            case 0x1C11F0u: goto label_1c11f0;
            case 0x1C1224u: goto label_1c1224;
            case 0x1C122Cu: goto label_1c122c;
            case 0x1C1234u: goto label_1c1234;
            case 0x1C123Cu: goto label_1c123c;
            case 0x1C1240u: goto label_1c1240;
            case 0x1C1244u: goto label_1c1244;
            case 0x1C124Cu: goto label_1c124c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C0E70u;
    // 0x1c0e70: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c0e70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c0e74: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c0e74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c0e78: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c0e78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c0e7c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1c0e7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c0e80: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0E80u;
    {
        const bool branch_taken_0x1c0e80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0E84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0E80u;
            // 0x1c0e84: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0e80) {
            ctx->pc = 0x1C0E90u;
            goto label_1c0e90;
        }
    }
    ctx->pc = 0x1C0E88u;
    // 0x1c0e88: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1C0E88u;
    {
        const bool branch_taken_0x1c0e88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0E8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0E88u;
            // 0x1c0e8c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0e88) {
            ctx->pc = 0x1C0EC8u;
            goto label_1c0ec8;
        }
    }
    ctx->pc = 0x1C0E90u;
label_1c0e90:
    // 0x1c0e90: 0xc070008  jal         func_1C0020
    ctx->pc = 0x1C0E90u;
    SET_GPR_U32(ctx, 31, 0x1C0E98u);
    ctx->pc = 0x1C0020u;
    if (runtime->hasFunction(0x1C0020u)) {
        auto targetFn = runtime->lookupFunction(0x1C0020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0E98u; }
        if (ctx->pc != 0x1C0E98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0020_0x1c0020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0E98u; }
        if (ctx->pc != 0x1C0E98u) { return; }
    }
    ctx->pc = 0x1C0E98u;
label_1c0e98:
    // 0x1c0e98: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0e98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0e9c: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C0E9Cu;
    {
        const bool branch_taken_0x1c0e9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0e9c) {
            ctx->pc = 0x1C0EBCu;
            goto label_1c0ebc;
        }
    }
    ctx->pc = 0x1C0EA4u;
    // 0x1c0ea4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0EA4u;
    {
        const bool branch_taken_0x1c0ea4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0ea4) {
            ctx->pc = 0x1C0EB4u;
            goto label_1c0eb4;
        }
    }
    ctx->pc = 0x1C0EACu;
    // 0x1c0eac: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C0EACu;
    {
        const bool branch_taken_0x1c0eac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0eac) {
            ctx->pc = 0x1C0EC4u;
            goto label_1c0ec4;
        }
    }
    ctx->pc = 0x1C0EB4u;
label_1c0eb4:
    // 0x1c0eb4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0EB4u;
    {
        const bool branch_taken_0x1c0eb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0EB4u;
            // 0x1c0eb8: 0xae000024  sw          $zero, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0eb4) {
            ctx->pc = 0x1C0EC4u;
            goto label_1c0ec4;
        }
    }
    ctx->pc = 0x1C0EBCu;
label_1c0ebc:
    // 0x1c0ebc: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c0ebcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c0ec0: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x1c0ec0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
label_1c0ec4:
    // 0x1c0ec4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c0ec4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c0ec8:
    // 0x1c0ec8: 0xc070108  jal         func_1C0420
    ctx->pc = 0x1C0EC8u;
    SET_GPR_U32(ctx, 31, 0x1C0ED0u);
    ctx->pc = 0x1C0420u;
    if (runtime->hasFunction(0x1C0420u)) {
        auto targetFn = runtime->lookupFunction(0x1C0420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0ED0u; }
        if (ctx->pc != 0x1C0ED0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0420_0x1c0420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0ED0u; }
        if (ctx->pc != 0x1C0ED0u) { return; }
    }
    ctx->pc = 0x1C0ED0u;
label_1c0ed0:
    // 0x1c0ed0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c0ed0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c0ed4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c0ed4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c0ed8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C0ED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C0EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0ED8u;
            // 0x1c0edc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C0E20u: goto label_1c0e20;
            case 0x1C0E28u: goto label_1c0e28;
            case 0x1C0E44u: goto label_1c0e44;
            case 0x1C0E4Cu: goto label_1c0e4c;
            case 0x1C0E54u: goto label_1c0e54;
            case 0x1C0E58u: goto label_1c0e58;
            case 0x1C0E60u: goto label_1c0e60;
            case 0x1C0E90u: goto label_1c0e90;
            case 0x1C0E98u: goto label_1c0e98;
            case 0x1C0EB4u: goto label_1c0eb4;
            case 0x1C0EBCu: goto label_1c0ebc;
            case 0x1C0EC4u: goto label_1c0ec4;
            case 0x1C0EC8u: goto label_1c0ec8;
            case 0x1C0ED0u: goto label_1c0ed0;
            case 0x1C0F18u: goto label_1c0f18;
            case 0x1C0F20u: goto label_1c0f20;
            case 0x1C0F50u: goto label_1c0f50;
            case 0x1C0F5Cu: goto label_1c0f5c;
            case 0x1C0F68u: goto label_1c0f68;
            case 0x1C0F78u: goto label_1c0f78;
            case 0x1C0F80u: goto label_1c0f80;
            case 0x1C0FB0u: goto label_1c0fb0;
            case 0x1C0FC0u: goto label_1c0fc0;
            case 0x1C0FD0u: goto label_1c0fd0;
            case 0x1C0FE0u: goto label_1c0fe0;
            case 0x1C0FF0u: goto label_1c0ff0;
            case 0x1C0FF8u: goto label_1c0ff8;
            case 0x1C1014u: goto label_1c1014;
            case 0x1C1020u: goto label_1c1020;
            case 0x1C102Cu: goto label_1c102c;
            case 0x1C1030u: goto label_1c1030;
            case 0x1C1038u: goto label_1c1038;
            case 0x1C1070u: goto label_1c1070;
            case 0x1C1078u: goto label_1c1078;
            case 0x1C1094u: goto label_1c1094;
            case 0x1C109Cu: goto label_1c109c;
            case 0x1C10A4u: goto label_1c10a4;
            case 0x1C10A8u: goto label_1c10a8;
            case 0x1C10B0u: goto label_1c10b0;
            case 0x1C1118u: goto label_1c1118;
            case 0x1C115Cu: goto label_1c115c;
            case 0x1C1164u: goto label_1c1164;
            case 0x1C1194u: goto label_1c1194;
            case 0x1C11A0u: goto label_1c11a0;
            case 0x1C11ACu: goto label_1c11ac;
            case 0x1C11BCu: goto label_1c11bc;
            case 0x1C11C4u: goto label_1c11c4;
            case 0x1C11E0u: goto label_1c11e0;
            case 0x1C11F0u: goto label_1c11f0;
            case 0x1C1224u: goto label_1c1224;
            case 0x1C122Cu: goto label_1c122c;
            case 0x1C1234u: goto label_1c1234;
            case 0x1C123Cu: goto label_1c123c;
            case 0x1C1240u: goto label_1c1240;
            case 0x1C1244u: goto label_1c1244;
            case 0x1C124Cu: goto label_1c124c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C0EE0u;
    // 0x1c0ee0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c0ee0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c0ee4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c0ee4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c0ee8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c0ee8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c0eec: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c0eecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c0ef0: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1c0ef0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c0ef4: 0x1062003e  beq         $v1, $v0, . + 4 + (0x3E << 2)
    ctx->pc = 0x1C0EF4u;
    {
        const bool branch_taken_0x1c0ef4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C0EF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0EF4u;
            // 0x1c0ef8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0ef4) {
            ctx->pc = 0x1C0FF0u;
            goto label_1c0ff0;
        }
    }
    ctx->pc = 0x1C0EFCu;
    // 0x1c0efc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c0efcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0f00: 0x1062001d  beq         $v1, $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1C0F00u;
    {
        const bool branch_taken_0x1c0f00 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c0f00) {
            ctx->pc = 0x1C0F78u;
            goto label_1c0f78;
        }
    }
    ctx->pc = 0x1C0F08u;
    // 0x1c0f08: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0F08u;
    {
        const bool branch_taken_0x1c0f08 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0f08) {
            ctx->pc = 0x1C0F18u;
            goto label_1c0f18;
        }
    }
    ctx->pc = 0x1C0F10u;
    // 0x1c0f10: 0x10000047  b           . + 4 + (0x47 << 2)
    ctx->pc = 0x1C0F10u;
    {
        const bool branch_taken_0x1c0f10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0F14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0F10u;
            // 0x1c0f14: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0f10) {
            ctx->pc = 0x1C1030u;
            goto label_1c1030;
        }
    }
    ctx->pc = 0x1C0F18u;
label_1c0f18:
    // 0x1c0f18: 0xc06fe10  jal         func_1BF840
    ctx->pc = 0x1C0F18u;
    SET_GPR_U32(ctx, 31, 0x1C0F20u);
    ctx->pc = 0x1BF840u;
    if (runtime->hasFunction(0x1BF840u)) {
        auto targetFn = runtime->lookupFunction(0x1BF840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0F20u; }
        if (ctx->pc != 0x1C0F20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF840_0x1bf840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0F20u; }
        if (ctx->pc != 0x1C0F20u) { return; }
    }
    ctx->pc = 0x1C0F20u;
label_1c0f20:
    // 0x1c0f20: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c0f20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c0f24: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1C0F24u;
    {
        const bool branch_taken_0x1c0f24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C0F28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0F24u;
            // 0x1c0f28: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0f24) {
            ctx->pc = 0x1C0F68u;
            goto label_1c0f68;
        }
    }
    ctx->pc = 0x1C0F2Cu;
    // 0x1c0f2c: 0x1043000e  beq         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1C0F2Cu;
    {
        const bool branch_taken_0x1c0f2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0f2c) {
            ctx->pc = 0x1C0F68u;
            goto label_1c0f68;
        }
    }
    ctx->pc = 0x1C0F34u;
    // 0x1c0f34: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c0f34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c0f38: 0x10430008  beq         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C0F38u;
    {
        const bool branch_taken_0x1c0f38 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0f38) {
            ctx->pc = 0x1C0F5Cu;
            goto label_1c0f5c;
        }
    }
    ctx->pc = 0x1C0F40u;
    // 0x1c0f40: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0F40u;
    {
        const bool branch_taken_0x1c0f40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0f40) {
            ctx->pc = 0x1C0F50u;
            goto label_1c0f50;
        }
    }
    ctx->pc = 0x1C0F48u;
    // 0x1c0f48: 0x10000038  b           . + 4 + (0x38 << 2)
    ctx->pc = 0x1C0F48u;
    {
        const bool branch_taken_0x1c0f48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0f48) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0F50u;
label_1c0f50:
    // 0x1c0f50: 0x2402ff01  addiu       $v0, $zero, -0xFF
    ctx->pc = 0x1c0f50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967041));
    // 0x1c0f54: 0x10000035  b           . + 4 + (0x35 << 2)
    ctx->pc = 0x1C0F54u;
    {
        const bool branch_taken_0x1c0f54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0F58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0F54u;
            // 0x1c0f58: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0f54) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0F5Cu;
label_1c0f5c:
    // 0x1c0f5c: 0x2402ff02  addiu       $v0, $zero, -0xFE
    ctx->pc = 0x1c0f5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967042));
    // 0x1c0f60: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x1C0F60u;
    {
        const bool branch_taken_0x1c0f60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0F64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0F60u;
            // 0x1c0f64: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0f60) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0F68u;
label_1c0f68:
    // 0x1c0f68: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1c0f68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1c0f6c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c0f6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c0f70: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x1C0F70u;
    {
        const bool branch_taken_0x1c0f70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0F74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0F70u;
            // 0x1c0f74: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0f70) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0F78u;
label_1c0f78:
    // 0x1c0f78: 0xc06fe94  jal         func_1BFA50
    ctx->pc = 0x1C0F78u;
    SET_GPR_U32(ctx, 31, 0x1C0F80u);
    ctx->pc = 0x1BFA50u;
    if (runtime->hasFunction(0x1BFA50u)) {
        auto targetFn = runtime->lookupFunction(0x1BFA50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0F80u; }
        if (ctx->pc != 0x1C0F80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BFA50_0x1bfa50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0F80u; }
        if (ctx->pc != 0x1C0F80u) { return; }
    }
    ctx->pc = 0x1C0F80u;
label_1c0f80:
    // 0x1c0f80: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c0f80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c0f84: 0x10430016  beq         $v0, $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x1C0F84u;
    {
        const bool branch_taken_0x1c0f84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C0F88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0F84u;
            // 0x1c0f88: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0f84) {
            ctx->pc = 0x1C0FE0u;
            goto label_1c0fe0;
        }
    }
    ctx->pc = 0x1C0F8Cu;
    // 0x1c0f8c: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1C0F8Cu;
    {
        const bool branch_taken_0x1c0f8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0f8c) {
            ctx->pc = 0x1C0FD0u;
            goto label_1c0fd0;
        }
    }
    ctx->pc = 0x1C0F94u;
    // 0x1c0f94: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0f94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0f98: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1C0F98u;
    {
        const bool branch_taken_0x1c0f98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0f98) {
            ctx->pc = 0x1C0FC0u;
            goto label_1c0fc0;
        }
    }
    ctx->pc = 0x1C0FA0u;
    // 0x1c0fa0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0FA0u;
    {
        const bool branch_taken_0x1c0fa0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0fa0) {
            ctx->pc = 0x1C0FB0u;
            goto label_1c0fb0;
        }
    }
    ctx->pc = 0x1C0FA8u;
    // 0x1c0fa8: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1C0FA8u;
    {
        const bool branch_taken_0x1c0fa8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0fa8) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0FB0u;
label_1c0fb0:
    // 0x1c0fb0: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1c0fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1c0fb4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c0fb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c0fb8: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1C0FB8u;
    {
        const bool branch_taken_0x1c0fb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0FBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0FB8u;
            // 0x1c0fbc: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0fb8) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0FC0u;
label_1c0fc0:
    // 0x1c0fc0: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c0fc0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c0fc4: 0x2402ff03  addiu       $v0, $zero, -0xFD
    ctx->pc = 0x1c0fc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967043));
    // 0x1c0fc8: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1C0FC8u;
    {
        const bool branch_taken_0x1c0fc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0FCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0FC8u;
            // 0x1c0fcc: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0fc8) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0FD0u;
label_1c0fd0:
    // 0x1c0fd0: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c0fd0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c0fd4: 0x2402ff01  addiu       $v0, $zero, -0xFF
    ctx->pc = 0x1c0fd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967041));
    // 0x1c0fd8: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1C0FD8u;
    {
        const bool branch_taken_0x1c0fd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0FDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0FD8u;
            // 0x1c0fdc: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0fd8) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0FE0u;
label_1c0fe0:
    // 0x1c0fe0: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c0fe0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c0fe4: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c0fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c0fe8: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1C0FE8u;
    {
        const bool branch_taken_0x1c0fe8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0FECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0FE8u;
            // 0x1c0fec: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0fe8) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0FF0u;
label_1c0ff0:
    // 0x1c0ff0: 0xc070034  jal         func_1C00D0
    ctx->pc = 0x1C0FF0u;
    SET_GPR_U32(ctx, 31, 0x1C0FF8u);
    ctx->pc = 0x1C00D0u;
    if (runtime->hasFunction(0x1C00D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C00D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0FF8u; }
        if (ctx->pc != 0x1C0FF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C00D0_0x1c00d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0FF8u; }
        if (ctx->pc != 0x1C0FF8u) { return; }
    }
    ctx->pc = 0x1C0FF8u;
label_1c0ff8:
    // 0x1c0ff8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0ff8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0ffc: 0x10430008  beq         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C0FFCu;
    {
        const bool branch_taken_0x1c0ffc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0ffc) {
            ctx->pc = 0x1C1020u;
            goto label_1c1020;
        }
    }
    ctx->pc = 0x1C1004u;
    // 0x1c1004: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1004u;
    {
        const bool branch_taken_0x1c1004 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c1004) {
            ctx->pc = 0x1C1014u;
            goto label_1c1014;
        }
    }
    ctx->pc = 0x1C100Cu;
    // 0x1c100c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C100Cu;
    {
        const bool branch_taken_0x1c100c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c100c) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C1014u;
label_1c1014:
    // 0x1c1014: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c1014u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c1018: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1C1018u;
    {
        const bool branch_taken_0x1c1018 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C101Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1018u;
            // 0x1c101c: 0xae000024  sw          $zero, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1018) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C1020u;
label_1c1020:
    // 0x1c1020: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c1020u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c1024: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c1024u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c1028: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x1c1028u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
label_1c102c:
    // 0x1c102c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c102cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c1030:
    // 0x1c1030: 0xc070108  jal         func_1C0420
    ctx->pc = 0x1C1030u;
    SET_GPR_U32(ctx, 31, 0x1C1038u);
    ctx->pc = 0x1C0420u;
    if (runtime->hasFunction(0x1C0420u)) {
        auto targetFn = runtime->lookupFunction(0x1C0420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1038u; }
        if (ctx->pc != 0x1C1038u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0420_0x1c0420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1038u; }
        if (ctx->pc != 0x1C1038u) { return; }
    }
    ctx->pc = 0x1C1038u;
label_1c1038:
    // 0x1c1038: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c1038u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c103c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c103cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1040: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1040u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1040u;
            // 0x1c1044: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C0E20u: goto label_1c0e20;
            case 0x1C0E28u: goto label_1c0e28;
            case 0x1C0E44u: goto label_1c0e44;
            case 0x1C0E4Cu: goto label_1c0e4c;
            case 0x1C0E54u: goto label_1c0e54;
            case 0x1C0E58u: goto label_1c0e58;
            case 0x1C0E60u: goto label_1c0e60;
            case 0x1C0E90u: goto label_1c0e90;
            case 0x1C0E98u: goto label_1c0e98;
            case 0x1C0EB4u: goto label_1c0eb4;
            case 0x1C0EBCu: goto label_1c0ebc;
            case 0x1C0EC4u: goto label_1c0ec4;
            case 0x1C0EC8u: goto label_1c0ec8;
            case 0x1C0ED0u: goto label_1c0ed0;
            case 0x1C0F18u: goto label_1c0f18;
            case 0x1C0F20u: goto label_1c0f20;
            case 0x1C0F50u: goto label_1c0f50;
            case 0x1C0F5Cu: goto label_1c0f5c;
            case 0x1C0F68u: goto label_1c0f68;
            case 0x1C0F78u: goto label_1c0f78;
            case 0x1C0F80u: goto label_1c0f80;
            case 0x1C0FB0u: goto label_1c0fb0;
            case 0x1C0FC0u: goto label_1c0fc0;
            case 0x1C0FD0u: goto label_1c0fd0;
            case 0x1C0FE0u: goto label_1c0fe0;
            case 0x1C0FF0u: goto label_1c0ff0;
            case 0x1C0FF8u: goto label_1c0ff8;
            case 0x1C1014u: goto label_1c1014;
            case 0x1C1020u: goto label_1c1020;
            case 0x1C102Cu: goto label_1c102c;
            case 0x1C1030u: goto label_1c1030;
            case 0x1C1038u: goto label_1c1038;
            case 0x1C1070u: goto label_1c1070;
            case 0x1C1078u: goto label_1c1078;
            case 0x1C1094u: goto label_1c1094;
            case 0x1C109Cu: goto label_1c109c;
            case 0x1C10A4u: goto label_1c10a4;
            case 0x1C10A8u: goto label_1c10a8;
            case 0x1C10B0u: goto label_1c10b0;
            case 0x1C1118u: goto label_1c1118;
            case 0x1C115Cu: goto label_1c115c;
            case 0x1C1164u: goto label_1c1164;
            case 0x1C1194u: goto label_1c1194;
            case 0x1C11A0u: goto label_1c11a0;
            case 0x1C11ACu: goto label_1c11ac;
            case 0x1C11BCu: goto label_1c11bc;
            case 0x1C11C4u: goto label_1c11c4;
            case 0x1C11E0u: goto label_1c11e0;
            case 0x1C11F0u: goto label_1c11f0;
            case 0x1C1224u: goto label_1c1224;
            case 0x1C122Cu: goto label_1c122c;
            case 0x1C1234u: goto label_1c1234;
            case 0x1C123Cu: goto label_1c123c;
            case 0x1C1240u: goto label_1c1240;
            case 0x1C1244u: goto label_1c1244;
            case 0x1C124Cu: goto label_1c124c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1048u;
    // 0x1c1048: 0x0  nop
    ctx->pc = 0x1c1048u;
    // NOP
    // 0x1c104c: 0x0  nop
    ctx->pc = 0x1c104cu;
    // NOP
    // 0x1c1050: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c1050u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c1054: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c1054u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c1058: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c1058u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c105c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1c105cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c1060: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1060u;
    {
        const bool branch_taken_0x1c1060 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1060u;
            // 0x1c1064: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1060) {
            ctx->pc = 0x1C1070u;
            goto label_1c1070;
        }
    }
    ctx->pc = 0x1C1068u;
    // 0x1c1068: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1C1068u;
    {
        const bool branch_taken_0x1c1068 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C106Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1068u;
            // 0x1c106c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1068) {
            ctx->pc = 0x1C10A8u;
            goto label_1c10a8;
        }
    }
    ctx->pc = 0x1C1070u;
label_1c1070:
    // 0x1c1070: 0xc070034  jal         func_1C00D0
    ctx->pc = 0x1C1070u;
    SET_GPR_U32(ctx, 31, 0x1C1078u);
    ctx->pc = 0x1C00D0u;
    if (runtime->hasFunction(0x1C00D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C00D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1078u; }
        if (ctx->pc != 0x1C1078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C00D0_0x1c00d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1078u; }
        if (ctx->pc != 0x1C1078u) { return; }
    }
    ctx->pc = 0x1C1078u;
label_1c1078:
    // 0x1c1078: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c1078u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c107c: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C107Cu;
    {
        const bool branch_taken_0x1c107c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c107c) {
            ctx->pc = 0x1C109Cu;
            goto label_1c109c;
        }
    }
    ctx->pc = 0x1C1084u;
    // 0x1c1084: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1084u;
    {
        const bool branch_taken_0x1c1084 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c1084) {
            ctx->pc = 0x1C1094u;
            goto label_1c1094;
        }
    }
    ctx->pc = 0x1C108Cu;
    // 0x1c108c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C108Cu;
    {
        const bool branch_taken_0x1c108c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c108c) {
            ctx->pc = 0x1C10A4u;
            goto label_1c10a4;
        }
    }
    ctx->pc = 0x1C1094u;
label_1c1094:
    // 0x1c1094: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1094u;
    {
        const bool branch_taken_0x1c1094 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1098u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1094u;
            // 0x1c1098: 0xae000024  sw          $zero, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1094) {
            ctx->pc = 0x1C10A4u;
            goto label_1c10a4;
        }
    }
    ctx->pc = 0x1C109Cu;
label_1c109c:
    // 0x1c109c: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c109cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c10a0: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x1c10a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
label_1c10a4:
    // 0x1c10a4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c10a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c10a8:
    // 0x1c10a8: 0xc070108  jal         func_1C0420
    ctx->pc = 0x1C10A8u;
    SET_GPR_U32(ctx, 31, 0x1C10B0u);
    ctx->pc = 0x1C0420u;
    if (runtime->hasFunction(0x1C0420u)) {
        auto targetFn = runtime->lookupFunction(0x1C0420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C10B0u; }
        if (ctx->pc != 0x1C10B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0420_0x1c0420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C10B0u; }
        if (ctx->pc != 0x1C10B0u) { return; }
    }
    ctx->pc = 0x1C10B0u;
label_1c10b0:
    // 0x1c10b0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c10b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c10b4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c10b4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c10b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C10B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C10BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C10B8u;
            // 0x1c10bc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C0E20u: goto label_1c0e20;
            case 0x1C0E28u: goto label_1c0e28;
            case 0x1C0E44u: goto label_1c0e44;
            case 0x1C0E4Cu: goto label_1c0e4c;
            case 0x1C0E54u: goto label_1c0e54;
            case 0x1C0E58u: goto label_1c0e58;
            case 0x1C0E60u: goto label_1c0e60;
            case 0x1C0E90u: goto label_1c0e90;
            case 0x1C0E98u: goto label_1c0e98;
            case 0x1C0EB4u: goto label_1c0eb4;
            case 0x1C0EBCu: goto label_1c0ebc;
            case 0x1C0EC4u: goto label_1c0ec4;
            case 0x1C0EC8u: goto label_1c0ec8;
            case 0x1C0ED0u: goto label_1c0ed0;
            case 0x1C0F18u: goto label_1c0f18;
            case 0x1C0F20u: goto label_1c0f20;
            case 0x1C0F50u: goto label_1c0f50;
            case 0x1C0F5Cu: goto label_1c0f5c;
            case 0x1C0F68u: goto label_1c0f68;
            case 0x1C0F78u: goto label_1c0f78;
            case 0x1C0F80u: goto label_1c0f80;
            case 0x1C0FB0u: goto label_1c0fb0;
            case 0x1C0FC0u: goto label_1c0fc0;
            case 0x1C0FD0u: goto label_1c0fd0;
            case 0x1C0FE0u: goto label_1c0fe0;
            case 0x1C0FF0u: goto label_1c0ff0;
            case 0x1C0FF8u: goto label_1c0ff8;
            case 0x1C1014u: goto label_1c1014;
            case 0x1C1020u: goto label_1c1020;
            case 0x1C102Cu: goto label_1c102c;
            case 0x1C1030u: goto label_1c1030;
            case 0x1C1038u: goto label_1c1038;
            case 0x1C1070u: goto label_1c1070;
            case 0x1C1078u: goto label_1c1078;
            case 0x1C1094u: goto label_1c1094;
            case 0x1C109Cu: goto label_1c109c;
            case 0x1C10A4u: goto label_1c10a4;
            case 0x1C10A8u: goto label_1c10a8;
            case 0x1C10B0u: goto label_1c10b0;
            case 0x1C1118u: goto label_1c1118;
            case 0x1C115Cu: goto label_1c115c;
            case 0x1C1164u: goto label_1c1164;
            case 0x1C1194u: goto label_1c1194;
            case 0x1C11A0u: goto label_1c11a0;
            case 0x1C11ACu: goto label_1c11ac;
            case 0x1C11BCu: goto label_1c11bc;
            case 0x1C11C4u: goto label_1c11c4;
            case 0x1C11E0u: goto label_1c11e0;
            case 0x1C11F0u: goto label_1c11f0;
            case 0x1C1224u: goto label_1c1224;
            case 0x1C122Cu: goto label_1c122c;
            case 0x1C1234u: goto label_1c1234;
            case 0x1C123Cu: goto label_1c123c;
            case 0x1C1240u: goto label_1c1240;
            case 0x1C1244u: goto label_1c1244;
            case 0x1C124Cu: goto label_1c124c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C10C0u;
    // 0x1c10c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c10c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c10c4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c10c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c10c8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c10c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c10cc: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1c10ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1c10d0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c10d0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c10d4: 0xac206c50  sw          $zero, 0x6C50($at)
    ctx->pc = 0x1c10d4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27728), GPR_U32(ctx, 0));
    // 0x1c10d8: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1c10d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c10dc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c10dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c10e0: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1c10e0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c10e4: 0xac206c54  sw          $zero, 0x6C54($at)
    ctx->pc = 0x1c10e4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27732), GPR_U32(ctx, 0));
    // 0x1c10e8: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c10e8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c10ec: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c10ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c10f0: 0x24a50638  addiu       $a1, $a1, 0x638
    ctx->pc = 0x1c10f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1592));
    // 0x1c10f4: 0xac246c64  sw          $a0, 0x6C64($at)
    ctx->pc = 0x1c10f4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27748), GPR_U32(ctx, 4));
    // 0x1c10f8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c10f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c10fc: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1c10fcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1c1100: 0xac226ce8  sw          $v0, 0x6CE8($at)
    ctx->pc = 0x1c1100u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27880), GPR_U32(ctx, 2));
    // 0x1c1104: 0x24846c94  addiu       $a0, $a0, 0x6C94
    ctx->pc = 0x1c1104u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 27796));
    // 0x1c1108: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1c1108u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c110c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c110cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c1110: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1C1110u;
    SET_GPR_U32(ctx, 31, 0x1C1118u);
    ctx->pc = 0x1C1114u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1110u;
            // 0x1c1114: 0xac226c74  sw          $v0, 0x6C74($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 27764), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1118u; }
        if (ctx->pc != 0x1C1118u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1118u; }
        if (ctx->pc != 0x1C1118u) { return; }
    }
    ctx->pc = 0x1C1118u;
label_1c1118:
    // 0x1c1118: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c1118u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c111c: 0xac306cec  sw          $s0, 0x6CEC($at)
    ctx->pc = 0x1c111cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27884), GPR_U32(ctx, 16));
    // 0x1c1120: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c1120u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c1124: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c1124u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1128: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1128u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C112Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1128u;
            // 0x1c112c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C0E20u: goto label_1c0e20;
            case 0x1C0E28u: goto label_1c0e28;
            case 0x1C0E44u: goto label_1c0e44;
            case 0x1C0E4Cu: goto label_1c0e4c;
            case 0x1C0E54u: goto label_1c0e54;
            case 0x1C0E58u: goto label_1c0e58;
            case 0x1C0E60u: goto label_1c0e60;
            case 0x1C0E90u: goto label_1c0e90;
            case 0x1C0E98u: goto label_1c0e98;
            case 0x1C0EB4u: goto label_1c0eb4;
            case 0x1C0EBCu: goto label_1c0ebc;
            case 0x1C0EC4u: goto label_1c0ec4;
            case 0x1C0EC8u: goto label_1c0ec8;
            case 0x1C0ED0u: goto label_1c0ed0;
            case 0x1C0F18u: goto label_1c0f18;
            case 0x1C0F20u: goto label_1c0f20;
            case 0x1C0F50u: goto label_1c0f50;
            case 0x1C0F5Cu: goto label_1c0f5c;
            case 0x1C0F68u: goto label_1c0f68;
            case 0x1C0F78u: goto label_1c0f78;
            case 0x1C0F80u: goto label_1c0f80;
            case 0x1C0FB0u: goto label_1c0fb0;
            case 0x1C0FC0u: goto label_1c0fc0;
            case 0x1C0FD0u: goto label_1c0fd0;
            case 0x1C0FE0u: goto label_1c0fe0;
            case 0x1C0FF0u: goto label_1c0ff0;
            case 0x1C0FF8u: goto label_1c0ff8;
            case 0x1C1014u: goto label_1c1014;
            case 0x1C1020u: goto label_1c1020;
            case 0x1C102Cu: goto label_1c102c;
            case 0x1C1030u: goto label_1c1030;
            case 0x1C1038u: goto label_1c1038;
            case 0x1C1070u: goto label_1c1070;
            case 0x1C1078u: goto label_1c1078;
            case 0x1C1094u: goto label_1c1094;
            case 0x1C109Cu: goto label_1c109c;
            case 0x1C10A4u: goto label_1c10a4;
            case 0x1C10A8u: goto label_1c10a8;
            case 0x1C10B0u: goto label_1c10b0;
            case 0x1C1118u: goto label_1c1118;
            case 0x1C115Cu: goto label_1c115c;
            case 0x1C1164u: goto label_1c1164;
            case 0x1C1194u: goto label_1c1194;
            case 0x1C11A0u: goto label_1c11a0;
            case 0x1C11ACu: goto label_1c11ac;
            case 0x1C11BCu: goto label_1c11bc;
            case 0x1C11C4u: goto label_1c11c4;
            case 0x1C11E0u: goto label_1c11e0;
            case 0x1C11F0u: goto label_1c11f0;
            case 0x1C1224u: goto label_1c1224;
            case 0x1C122Cu: goto label_1c122c;
            case 0x1C1234u: goto label_1c1234;
            case 0x1C123Cu: goto label_1c123c;
            case 0x1C1240u: goto label_1c1240;
            case 0x1C1244u: goto label_1c1244;
            case 0x1C124Cu: goto label_1c124c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1130u;
    // 0x1c1130: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c1130u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c1134: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c1134u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c1138: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c1138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c113c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c113cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c1140: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1c1140u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c1144: 0x1062001d  beq         $v1, $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1C1144u;
    {
        const bool branch_taken_0x1c1144 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C1148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1144u;
            // 0x1c1148: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1144) {
            ctx->pc = 0x1C11BCu;
            goto label_1c11bc;
        }
    }
    ctx->pc = 0x1C114Cu;
    // 0x1c114c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C114Cu;
    {
        const bool branch_taken_0x1c114c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c114c) {
            ctx->pc = 0x1C115Cu;
            goto label_1c115c;
        }
    }
    ctx->pc = 0x1C1154u;
    // 0x1c1154: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1C1154u;
    {
        const bool branch_taken_0x1c1154 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1154u;
            // 0x1c1158: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1154) {
            ctx->pc = 0x1C1244u;
            goto label_1c1244;
        }
    }
    ctx->pc = 0x1C115Cu;
label_1c115c:
    // 0x1c115c: 0xc06fe10  jal         func_1BF840
    ctx->pc = 0x1C115Cu;
    SET_GPR_U32(ctx, 31, 0x1C1164u);
    ctx->pc = 0x1BF840u;
    if (runtime->hasFunction(0x1BF840u)) {
        auto targetFn = runtime->lookupFunction(0x1BF840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1164u; }
        if (ctx->pc != 0x1C1164u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF840_0x1bf840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1164u; }
        if (ctx->pc != 0x1C1164u) { return; }
    }
    ctx->pc = 0x1C1164u;
label_1c1164:
    // 0x1c1164: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c1164u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c1168: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1C1168u;
    {
        const bool branch_taken_0x1c1168 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C116Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1168u;
            // 0x1c116c: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1168) {
            ctx->pc = 0x1C11ACu;
            goto label_1c11ac;
        }
    }
    ctx->pc = 0x1C1170u;
    // 0x1c1170: 0x1043000e  beq         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1C1170u;
    {
        const bool branch_taken_0x1c1170 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c1170) {
            ctx->pc = 0x1C11ACu;
            goto label_1c11ac;
        }
    }
    ctx->pc = 0x1C1178u;
    // 0x1c1178: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c1178u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c117c: 0x10430008  beq         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C117Cu;
    {
        const bool branch_taken_0x1c117c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c117c) {
            ctx->pc = 0x1C11A0u;
            goto label_1c11a0;
        }
    }
    ctx->pc = 0x1C1184u;
    // 0x1c1184: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1184u;
    {
        const bool branch_taken_0x1c1184 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c1184) {
            ctx->pc = 0x1C1194u;
            goto label_1c1194;
        }
    }
    ctx->pc = 0x1C118Cu;
    // 0x1c118c: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x1C118Cu;
    {
        const bool branch_taken_0x1c118c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c118c) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C1194u;
label_1c1194:
    // 0x1c1194: 0x2402ff01  addiu       $v0, $zero, -0xFF
    ctx->pc = 0x1c1194u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967041));
    // 0x1c1198: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1C1198u;
    {
        const bool branch_taken_0x1c1198 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C119Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1198u;
            // 0x1c119c: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1198) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C11A0u;
label_1c11a0:
    // 0x1c11a0: 0x2402ff02  addiu       $v0, $zero, -0xFE
    ctx->pc = 0x1c11a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967042));
    // 0x1c11a4: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1C11A4u;
    {
        const bool branch_taken_0x1c11a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C11A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C11A4u;
            // 0x1c11a8: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c11a4) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C11ACu;
label_1c11ac:
    // 0x1c11ac: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1c11acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1c11b0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c11b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c11b4: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1C11B4u;
    {
        const bool branch_taken_0x1c11b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C11B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C11B4u;
            // 0x1c11b8: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c11b4) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C11BCu;
label_1c11bc:
    // 0x1c11bc: 0xc0700a8  jal         func_1C02A0
    ctx->pc = 0x1C11BCu;
    SET_GPR_U32(ctx, 31, 0x1C11C4u);
    ctx->pc = 0x1C02A0u;
    if (runtime->hasFunction(0x1C02A0u)) {
        auto targetFn = runtime->lookupFunction(0x1C02A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C11C4u; }
        if (ctx->pc != 0x1C11C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C02A0_0x1c02a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C11C4u; }
        if (ctx->pc != 0x1C11C4u) { return; }
    }
    ctx->pc = 0x1C11C4u;
label_1c11c4:
    // 0x1c11c4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c11c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c11c8: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1C11C8u;
    {
        const bool branch_taken_0x1c11c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c11c8) {
            ctx->pc = 0x1C11F0u;
            goto label_1c11f0;
        }
    }
    ctx->pc = 0x1C11D0u;
    // 0x1c11d0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C11D0u;
    {
        const bool branch_taken_0x1c11d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c11d0) {
            ctx->pc = 0x1C11E0u;
            goto label_1c11e0;
        }
    }
    ctx->pc = 0x1C11D8u;
    // 0x1c11d8: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1C11D8u;
    {
        const bool branch_taken_0x1c11d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c11d8) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C11E0u;
label_1c11e0:
    // 0x1c11e0: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c11e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c11e4: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x1c11e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1c11e8: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1C11E8u;
    {
        const bool branch_taken_0x1c11e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C11ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C11E8u;
            // 0x1c11ec: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c11e8) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C11F0u;
label_1c11f0:
    // 0x1c11f0: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c11f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c11f4: 0x34029002  ori         $v0, $zero, 0x9002
    ctx->pc = 0x1c11f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36866);
    // 0x1c11f8: 0x9603001c  lhu         $v1, 0x1C($s0)
    ctx->pc = 0x1c11f8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1c11fc: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C11FCu;
    {
        const bool branch_taken_0x1c11fc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C1200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C11FCu;
            // 0x1c1200: 0x2402ff05  addiu       $v0, $zero, -0xFB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967045));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c11fc) {
            ctx->pc = 0x1C1234u;
            goto label_1c1234;
        }
    }
    ctx->pc = 0x1C1204u;
    // 0x1c1204: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c1204u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c1208: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C1208u;
    {
        const bool branch_taken_0x1c1208 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C120Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1208u;
            // 0x1c120c: 0x2402ff03  addiu       $v0, $zero, -0xFD (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967043));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1208) {
            ctx->pc = 0x1C122Cu;
            goto label_1c122c;
        }
    }
    ctx->pc = 0x1C1210u;
    // 0x1c1210: 0x24020013  addiu       $v0, $zero, 0x13
    ctx->pc = 0x1c1210u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x1c1214: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1214u;
    {
        const bool branch_taken_0x1c1214 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C1218u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1214u;
            // 0x1c1218: 0x2402ff01  addiu       $v0, $zero, -0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967041));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1214) {
            ctx->pc = 0x1C1224u;
            goto label_1c1224;
        }
    }
    ctx->pc = 0x1C121Cu;
    // 0x1c121c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C121Cu;
    {
        const bool branch_taken_0x1c121c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C121Cu;
            // 0x1c1220: 0x2402ff00  addiu       $v0, $zero, -0x100 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c121c) {
            ctx->pc = 0x1C123Cu;
            goto label_1c123c;
        }
    }
    ctx->pc = 0x1C1224u;
label_1c1224:
    // 0x1c1224: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1C1224u;
    {
        const bool branch_taken_0x1c1224 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1224u;
            // 0x1c1228: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1224) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C122Cu;
label_1c122c:
    // 0x1c122c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1C122Cu;
    {
        const bool branch_taken_0x1c122c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C122Cu;
            // 0x1c1230: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c122c) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C1234u;
label_1c1234:
    // 0x1c1234: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C1234u;
    {
        const bool branch_taken_0x1c1234 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1234u;
            // 0x1c1238: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1234) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C123Cu;
label_1c123c:
    // 0x1c123c: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x1c123cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
label_1c1240:
    // 0x1c1240: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c1240u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c1244:
    // 0x1c1244: 0xc070108  jal         func_1C0420
    ctx->pc = 0x1C1244u;
    SET_GPR_U32(ctx, 31, 0x1C124Cu);
    ctx->pc = 0x1C0420u;
    if (runtime->hasFunction(0x1C0420u)) {
        auto targetFn = runtime->lookupFunction(0x1C0420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C124Cu; }
        if (ctx->pc != 0x1C124Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0420_0x1c0420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C124Cu; }
        if (ctx->pc != 0x1C124Cu) { return; }
    }
    ctx->pc = 0x1C124Cu;
label_1c124c:
    // 0x1c124c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c124cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c1250: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c1250u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1254: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1254u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1258u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1254u;
            // 0x1c1258: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C0E20u: goto label_1c0e20;
            case 0x1C0E28u: goto label_1c0e28;
            case 0x1C0E44u: goto label_1c0e44;
            case 0x1C0E4Cu: goto label_1c0e4c;
            case 0x1C0E54u: goto label_1c0e54;
            case 0x1C0E58u: goto label_1c0e58;
            case 0x1C0E60u: goto label_1c0e60;
            case 0x1C0E90u: goto label_1c0e90;
            case 0x1C0E98u: goto label_1c0e98;
            case 0x1C0EB4u: goto label_1c0eb4;
            case 0x1C0EBCu: goto label_1c0ebc;
            case 0x1C0EC4u: goto label_1c0ec4;
            case 0x1C0EC8u: goto label_1c0ec8;
            case 0x1C0ED0u: goto label_1c0ed0;
            case 0x1C0F18u: goto label_1c0f18;
            case 0x1C0F20u: goto label_1c0f20;
            case 0x1C0F50u: goto label_1c0f50;
            case 0x1C0F5Cu: goto label_1c0f5c;
            case 0x1C0F68u: goto label_1c0f68;
            case 0x1C0F78u: goto label_1c0f78;
            case 0x1C0F80u: goto label_1c0f80;
            case 0x1C0FB0u: goto label_1c0fb0;
            case 0x1C0FC0u: goto label_1c0fc0;
            case 0x1C0FD0u: goto label_1c0fd0;
            case 0x1C0FE0u: goto label_1c0fe0;
            case 0x1C0FF0u: goto label_1c0ff0;
            case 0x1C0FF8u: goto label_1c0ff8;
            case 0x1C1014u: goto label_1c1014;
            case 0x1C1020u: goto label_1c1020;
            case 0x1C102Cu: goto label_1c102c;
            case 0x1C1030u: goto label_1c1030;
            case 0x1C1038u: goto label_1c1038;
            case 0x1C1070u: goto label_1c1070;
            case 0x1C1078u: goto label_1c1078;
            case 0x1C1094u: goto label_1c1094;
            case 0x1C109Cu: goto label_1c109c;
            case 0x1C10A4u: goto label_1c10a4;
            case 0x1C10A8u: goto label_1c10a8;
            case 0x1C10B0u: goto label_1c10b0;
            case 0x1C1118u: goto label_1c1118;
            case 0x1C115Cu: goto label_1c115c;
            case 0x1C1164u: goto label_1c1164;
            case 0x1C1194u: goto label_1c1194;
            case 0x1C11A0u: goto label_1c11a0;
            case 0x1C11ACu: goto label_1c11ac;
            case 0x1C11BCu: goto label_1c11bc;
            case 0x1C11C4u: goto label_1c11c4;
            case 0x1C11E0u: goto label_1c11e0;
            case 0x1C11F0u: goto label_1c11f0;
            case 0x1C1224u: goto label_1c1224;
            case 0x1C122Cu: goto label_1c122c;
            case 0x1C1234u: goto label_1c1234;
            case 0x1C123Cu: goto label_1c123c;
            case 0x1C1240u: goto label_1c1240;
            case 0x1C1244u: goto label_1c1244;
            case 0x1C124Cu: goto label_1c124c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C125Cu;
    // 0x1c125c: 0x0  nop
    ctx->pc = 0x1c125cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
