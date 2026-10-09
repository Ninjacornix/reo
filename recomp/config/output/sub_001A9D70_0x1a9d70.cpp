#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A9D70
// Address: 0x1a9d70 - 0x1a9f20
void sub_001A9D70_0x1a9d70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A9D70_0x1a9d70");
#endif

    switch (ctx->pc) {
        case 0x1a9d94u: goto label_1a9d94;
        case 0x1a9db0u: goto label_1a9db0;
        case 0x1a9dc0u: goto label_1a9dc0;
        case 0x1a9dccu: goto label_1a9dcc;
        case 0x1a9de0u: goto label_1a9de0;
        case 0x1a9df0u: goto label_1a9df0;
        case 0x1a9e04u: goto label_1a9e04;
        case 0x1a9e14u: goto label_1a9e14;
        case 0x1a9e20u: goto label_1a9e20;
        case 0x1a9e48u: goto label_1a9e48;
        case 0x1a9eacu: goto label_1a9eac;
        case 0x1a9eb8u: goto label_1a9eb8;
        case 0x1a9ec8u: goto label_1a9ec8;
        default: break;
    }

    ctx->pc = 0x1a9d70u;

    // 0x1a9d70: 0x27bdfd90  addiu       $sp, $sp, -0x270
    ctx->pc = 0x1a9d70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966672));
    // 0x1a9d74: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1a9d74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1a9d78: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1a9d78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1a9d7c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1a9d7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1a9d80: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a9d80u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a9d84: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1a9d84u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9d88: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a9d88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a9d8c: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1A9D8Cu;
    SET_GPR_U32(ctx, 31, 0x1A9D94u);
    ctx->pc = 0x1A9D90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9D8Cu;
            // 0x1a9d90: 0x27a40170  addiu       $a0, $sp, 0x170 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9D94u; }
        if (ctx->pc != 0x1A9D94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9D94u; }
        if (ctx->pc != 0x1A9D94u) { return; }
    }
    ctx->pc = 0x1A9D94u;
label_1a9d94:
    // 0x1a9d94: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1a9d94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1a9d98: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1A9D98u;
    {
        const bool branch_taken_0x1a9d98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A9D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9D98u;
            // 0x1a9d9c: 0x27a40170  addiu       $a0, $sp, 0x170 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9d98) {
            ctx->pc = 0x1A9DB8u;
            goto label_1a9db8;
        }
    }
    ctx->pc = 0x1A9DA0u;
    // 0x1a9da0: 0x8e24000c  lw          $a0, 0xC($s1)
    ctx->pc = 0x1a9da0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1a9da4: 0x8e250014  lw          $a1, 0x14($s1)
    ctx->pc = 0x1a9da4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1a9da8: 0xc06ac14  jal         func_1AB050
    ctx->pc = 0x1A9DA8u;
    SET_GPR_U32(ctx, 31, 0x1A9DB0u);
    ctx->pc = 0x1A9DACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9DA8u;
            // 0x1a9dac: 0x27a60170  addiu       $a2, $sp, 0x170 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AB050u;
    if (runtime->hasFunction(0x1AB050u)) {
        auto targetFn = runtime->lookupFunction(0x1AB050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9DB0u; }
        if (ctx->pc != 0x1A9DB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB050_0x1ab050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9DB0u; }
        if (ctx->pc != 0x1A9DB0u) { return; }
    }
    ctx->pc = 0x1A9DB0u;
label_1a9db0:
    // 0x1a9db0: 0x10000052  b           . + 4 + (0x52 << 2)
    ctx->pc = 0x1A9DB0u;
    {
        const bool branch_taken_0x1a9db0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9DB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9DB0u;
            // 0x1a9db4: 0xdfbf0040  ld          $ra, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9db0) {
            ctx->pc = 0x1A9EFCu;
            goto label_1a9efc;
        }
    }
    ctx->pc = 0x1A9DB8u;
label_1a9db8:
    // 0x1a9db8: 0xc04336a  jal         func_10CDA8
    ctx->pc = 0x1A9DB8u;
    SET_GPR_U32(ctx, 31, 0x1A9DC0u);
    ctx->pc = 0x10CDA8u;
    if (runtime->hasFunction(0x10CDA8u)) {
        auto targetFn = runtime->lookupFunction(0x10CDA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9DC0u; }
        if (ctx->pc != 0x1A9DC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010CDA8_0x10cda8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9DC0u; }
        if (ctx->pc != 0x1A9DC0u) { return; }
    }
    ctx->pc = 0x1A9DC0u;
label_1a9dc0:
    // 0x1a9dc0: 0x27a40170  addiu       $a0, $sp, 0x170
    ctx->pc = 0x1a9dc0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
    // 0x1a9dc4: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1A9DC4u;
    SET_GPR_U32(ctx, 31, 0x1A9DCCu);
    ctx->pc = 0x1A9DC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9DC4u;
            // 0x1a9dc8: 0x2405002f  addiu       $a1, $zero, 0x2F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9DCCu; }
        if (ctx->pc != 0x1A9DCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9DCCu; }
        if (ctx->pc != 0x1A9DCCu) { return; }
    }
    ctx->pc = 0x1A9DCCu;
label_1a9dcc:
    // 0x1a9dcc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A9DCCu;
    {
        const bool branch_taken_0x1a9dcc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9DCCu;
            // 0x1a9dd0: 0x27a40170  addiu       $a0, $sp, 0x170 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9dcc) {
            ctx->pc = 0x1A9DE8u;
            goto label_1a9de8;
        }
    }
    ctx->pc = 0x1A9DD4u;
    // 0x1a9dd4: 0x24450001  addiu       $a1, $v0, 0x1
    ctx->pc = 0x1a9dd4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a9dd8: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1A9DD8u;
    SET_GPR_U32(ctx, 31, 0x1A9DE0u);
    ctx->pc = 0x1A9DDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9DD8u;
            // 0x1a9ddc: 0x27a40070  addiu       $a0, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9DE0u; }
        if (ctx->pc != 0x1A9DE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9DE0u; }
        if (ctx->pc != 0x1A9DE0u) { return; }
    }
    ctx->pc = 0x1A9DE0u;
label_1a9de0:
    // 0x1a9de0: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1A9DE0u;
    {
        const bool branch_taken_0x1a9de0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9DE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9DE0u;
            // 0x1a9de4: 0x27a40070  addiu       $a0, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9de0) {
            ctx->pc = 0x1A9E18u;
            goto label_1a9e18;
        }
    }
    ctx->pc = 0x1A9DE8u;
label_1a9de8:
    // 0x1a9de8: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1A9DE8u;
    SET_GPR_U32(ctx, 31, 0x1A9DF0u);
    ctx->pc = 0x1A9DECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9DE8u;
            // 0x1a9dec: 0x2405005c  addiu       $a1, $zero, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9DF0u; }
        if (ctx->pc != 0x1A9DF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9DF0u; }
        if (ctx->pc != 0x1A9DF0u) { return; }
    }
    ctx->pc = 0x1A9DF0u;
label_1a9df0:
    // 0x1a9df0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A9DF0u;
    {
        const bool branch_taken_0x1a9df0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A9DF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9DF0u;
            // 0x1a9df4: 0x24450001  addiu       $a1, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9df0) {
            ctx->pc = 0x1A9E0Cu;
            goto label_1a9e0c;
        }
    }
    ctx->pc = 0x1A9DF8u;
    // 0x1a9df8: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1a9df8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1a9dfc: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1A9DFCu;
    SET_GPR_U32(ctx, 31, 0x1A9E04u);
    ctx->pc = 0x1A9E00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9DFCu;
            // 0x1a9e00: 0x27a50170  addiu       $a1, $sp, 0x170 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9E04u; }
        if (ctx->pc != 0x1A9E04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9E04u; }
        if (ctx->pc != 0x1A9E04u) { return; }
    }
    ctx->pc = 0x1A9E04u;
label_1a9e04:
    // 0x1a9e04: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A9E04u;
    {
        const bool branch_taken_0x1a9e04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a9e04) {
            ctx->pc = 0x1A9E14u;
            goto label_1a9e14;
        }
    }
    ctx->pc = 0x1A9E0Cu;
label_1a9e0c:
    // 0x1a9e0c: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1A9E0Cu;
    SET_GPR_U32(ctx, 31, 0x1A9E14u);
    ctx->pc = 0x1A9E10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9E0Cu;
            // 0x1a9e10: 0x27a40070  addiu       $a0, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9E14u; }
        if (ctx->pc != 0x1A9E14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9E14u; }
        if (ctx->pc != 0x1A9E14u) { return; }
    }
    ctx->pc = 0x1A9E14u;
label_1a9e14:
    // 0x1a9e14: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1a9e14u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
label_1a9e18:
    // 0x1a9e18: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1A9E18u;
    SET_GPR_U32(ctx, 31, 0x1A9E20u);
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9E20u; }
        if (ctx->pc != 0x1A9E20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9E20u; }
        if (ctx->pc != 0x1A9E20u) { return; }
    }
    ctx->pc = 0x1A9E20u;
label_1a9e20:
    // 0x1a9e20: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A9E20u;
    {
        const bool branch_taken_0x1a9e20 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A9E24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9E20u;
            // 0x1a9e24: 0x27a80070  addiu       $t0, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9e20) {
            ctx->pc = 0x1A9E30u;
            goto label_1a9e30;
        }
    }
    ctx->pc = 0x1A9E28u;
    // 0x1a9e28: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x1A9E28u;
    {
        const bool branch_taken_0x1a9e28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9E2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9E28u;
            // 0x1a9e2c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9e28) {
            ctx->pc = 0x1A9EF8u;
            goto label_1a9ef8;
        }
    }
    ctx->pc = 0x1A9E30u;
label_1a9e30:
    // 0x1a9e30: 0x2406005f  addiu       $a2, $zero, 0x5F
    ctx->pc = 0x1a9e30u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 95));
    // 0x1a9e34: 0x2407005c  addiu       $a3, $zero, 0x5C
    ctx->pc = 0x1a9e34u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
    // 0x1a9e38: 0x2405002f  addiu       $a1, $zero, 0x2F
    ctx->pc = 0x1a9e38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x1a9e3c: 0x2404002e  addiu       $a0, $zero, 0x2E
    ctx->pc = 0x1a9e3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
    // 0x1a9e40: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1A9E40u;
    {
        const bool branch_taken_0x1a9e40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9E44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9E40u;
            // 0x1a9e44: 0x2402002d  addiu       $v0, $zero, 0x2D (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9e40) {
            ctx->pc = 0x1A9E90u;
            goto label_1a9e90;
        }
    }
    ctx->pc = 0x1A9E48u;
label_1a9e48:
    // 0x1a9e48: 0x31e3c  dsll32      $v1, $v1, 24
    ctx->pc = 0x1a9e48u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 24));
    // 0x1a9e4c: 0x31e3f  dsra32      $v1, $v1, 24
    ctx->pc = 0x1a9e4cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 24));
    // 0x1a9e50: 0x14670002  bne         $v1, $a3, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A9E50u;
    {
        const bool branch_taken_0x1a9e50 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 7));
        if (branch_taken_0x1a9e50) {
            ctx->pc = 0x1A9E5Cu;
            goto label_1a9e5c;
        }
    }
    ctx->pc = 0x1A9E58u;
    // 0x1a9e58: 0xa1060000  sb          $a2, 0x0($t0)
    ctx->pc = 0x1a9e58u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 6));
label_1a9e5c:
    // 0x1a9e5c: 0x81030000  lb          $v1, 0x0($t0)
    ctx->pc = 0x1a9e5cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1a9e60: 0x14650002  bne         $v1, $a1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A9E60u;
    {
        const bool branch_taken_0x1a9e60 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x1a9e60) {
            ctx->pc = 0x1A9E6Cu;
            goto label_1a9e6c;
        }
    }
    ctx->pc = 0x1A9E68u;
    // 0x1a9e68: 0xa1060000  sb          $a2, 0x0($t0)
    ctx->pc = 0x1a9e68u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 6));
label_1a9e6c:
    // 0x1a9e6c: 0x81030000  lb          $v1, 0x0($t0)
    ctx->pc = 0x1a9e6cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1a9e70: 0x14640002  bne         $v1, $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A9E70u;
    {
        const bool branch_taken_0x1a9e70 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1a9e70) {
            ctx->pc = 0x1A9E7Cu;
            goto label_1a9e7c;
        }
    }
    ctx->pc = 0x1A9E78u;
    // 0x1a9e78: 0xa1060000  sb          $a2, 0x0($t0)
    ctx->pc = 0x1a9e78u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 6));
label_1a9e7c:
    // 0x1a9e7c: 0x81030000  lb          $v1, 0x0($t0)
    ctx->pc = 0x1a9e7cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1a9e80: 0x14620002  bne         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A9E80u;
    {
        const bool branch_taken_0x1a9e80 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1a9e80) {
            ctx->pc = 0x1A9E8Cu;
            goto label_1a9e8c;
        }
    }
    ctx->pc = 0x1A9E88u;
    // 0x1a9e88: 0xa1060000  sb          $a2, 0x0($t0)
    ctx->pc = 0x1a9e88u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 6));
label_1a9e8c:
    // 0x1a9e8c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1a9e8cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
label_1a9e90:
    // 0x1a9e90: 0x81030000  lb          $v1, 0x0($t0)
    ctx->pc = 0x1a9e90u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1a9e94: 0x1460ffec  bnez        $v1, . + 4 + (-0x14 << 2)
    ctx->pc = 0x1A9E94u;
    {
        const bool branch_taken_0x1a9e94 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a9e94) {
            ctx->pc = 0x1A9E48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a9e48;
        }
    }
    ctx->pc = 0x1A9E9Cu;
    // 0x1a9e9c: 0x8e33000c  lw          $s3, 0xC($s1)
    ctx->pc = 0x1a9e9cu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1a9ea0: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1a9ea0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9ea4: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1A9EA4u;
    {
        const bool branch_taken_0x1a9ea4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9EA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9EA4u;
            // 0x1a9ea8: 0x27b20060  addiu       $s2, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9ea4) {
            ctx->pc = 0x1A9EE4u;
            goto label_1a9ee4;
        }
    }
    ctx->pc = 0x1A9EACu;
label_1a9eac:
    // 0x1a9eac: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1a9eacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9eb0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1A9EB0u;
    SET_GPR_U32(ctx, 31, 0x1A9EB8u);
    ctx->pc = 0x1A9EB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9EB0u;
            // 0x1a9eb4: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9EB8u; }
        if (ctx->pc != 0x1A9EB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9EB8u; }
        if (ctx->pc != 0x1A9EB8u) { return; }
    }
    ctx->pc = 0x1A9EB8u;
label_1a9eb8:
    // 0x1a9eb8: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1a9eb8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1a9ebc: 0x27a50050  addiu       $a1, $sp, 0x50
    ctx->pc = 0x1a9ebcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1a9ec0: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1A9EC0u;
    SET_GPR_U32(ctx, 31, 0x1A9EC8u);
    ctx->pc = 0x1A9EC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9EC0u;
            // 0x1a9ec4: 0xa2400000  sb          $zero, 0x0($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9EC8u; }
        if (ctx->pc != 0x1A9EC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9EC8u; }
        if (ctx->pc != 0x1A9EC8u) { return; }
    }
    ctx->pc = 0x1A9EC8u;
label_1a9ec8:
    // 0x1a9ec8: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A9EC8u;
    {
        const bool branch_taken_0x1a9ec8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a9ec8) {
            ctx->pc = 0x1A9EDCu;
            goto label_1a9edc;
        }
    }
    ctx->pc = 0x1A9ED0u;
    // 0x1a9ed0: 0x8e220018  lw          $v0, 0x18($s1)
    ctx->pc = 0x1a9ed0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1a9ed4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A9ED4u;
    {
        const bool branch_taken_0x1a9ed4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9ED4u;
            // 0x1a9ed8: 0x2021021  addu        $v0, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9ed4) {
            ctx->pc = 0x1A9EF8u;
            goto label_1a9ef8;
        }
    }
    ctx->pc = 0x1A9EDCu;
label_1a9edc:
    // 0x1a9edc: 0x26730010  addiu       $s3, $s3, 0x10
    ctx->pc = 0x1a9edcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 16));
    // 0x1a9ee0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1a9ee0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1a9ee4:
    // 0x1a9ee4: 0x8e220014  lw          $v0, 0x14($s1)
    ctx->pc = 0x1a9ee4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1a9ee8: 0x202102a  slt         $v0, $s0, $v0
    ctx->pc = 0x1a9ee8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1a9eec: 0x1440ffef  bnez        $v0, . + 4 + (-0x11 << 2)
    ctx->pc = 0x1A9EECu;
    {
        const bool branch_taken_0x1a9eec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A9EF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9EECu;
            // 0x1a9ef0: 0x27a40050  addiu       $a0, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9eec) {
            ctx->pc = 0x1A9EACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a9eac;
        }
    }
    ctx->pc = 0x1A9EF4u;
    // 0x1a9ef4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1a9ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1a9ef8:
    // 0x1a9ef8: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1a9ef8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1a9efc:
    // 0x1a9efc: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1a9efcu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a9f00: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1a9f00u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a9f04: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a9f04u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a9f08: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a9f08u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a9f0c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A9F0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A9F10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9F0Cu;
            // 0x1a9f10: 0x27bd0270  addiu       $sp, $sp, 0x270 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 624));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A9D94u: goto label_1a9d94;
            case 0x1A9DB0u: goto label_1a9db0;
            case 0x1A9DB8u: goto label_1a9db8;
            case 0x1A9DC0u: goto label_1a9dc0;
            case 0x1A9DCCu: goto label_1a9dcc;
            case 0x1A9DE0u: goto label_1a9de0;
            case 0x1A9DE8u: goto label_1a9de8;
            case 0x1A9DF0u: goto label_1a9df0;
            case 0x1A9E04u: goto label_1a9e04;
            case 0x1A9E0Cu: goto label_1a9e0c;
            case 0x1A9E14u: goto label_1a9e14;
            case 0x1A9E18u: goto label_1a9e18;
            case 0x1A9E20u: goto label_1a9e20;
            case 0x1A9E30u: goto label_1a9e30;
            case 0x1A9E48u: goto label_1a9e48;
            case 0x1A9E5Cu: goto label_1a9e5c;
            case 0x1A9E6Cu: goto label_1a9e6c;
            case 0x1A9E7Cu: goto label_1a9e7c;
            case 0x1A9E8Cu: goto label_1a9e8c;
            case 0x1A9E90u: goto label_1a9e90;
            case 0x1A9EACu: goto label_1a9eac;
            case 0x1A9EB8u: goto label_1a9eb8;
            case 0x1A9EC8u: goto label_1a9ec8;
            case 0x1A9EDCu: goto label_1a9edc;
            case 0x1A9EE4u: goto label_1a9ee4;
            case 0x1A9EF8u: goto label_1a9ef8;
            case 0x1A9EFCu: goto label_1a9efc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A9F14u;
    // 0x1a9f14: 0x0  nop
    ctx->pc = 0x1a9f14u;
    // NOP
    // 0x1a9f18: 0x0  nop
    ctx->pc = 0x1a9f18u;
    // NOP
    // 0x1a9f1c: 0x0  nop
    ctx->pc = 0x1a9f1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
