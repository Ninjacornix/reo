#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129D78
// Address: 0x129d78 - 0x129e18
void sub_00129D78_0x129d78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129D78_0x129d78");
#endif

    switch (ctx->pc) {
        case 0x129de0u: goto label_129de0;
        case 0x129e0cu: goto label_129e0c;
        default: break;
    }

    ctx->pc = 0x129d78u;

    // 0x129d78: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x129d78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x129d7c: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x129d7cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x129d80: 0x2c840100  sltiu       $a0, $a0, 0x100
    ctx->pc = 0x129d80u;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
    // 0x129d84: 0x14800004  bnez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x129D84u;
    {
        const bool branch_taken_0x129d84 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x129D88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129D84u;
            // 0x129d88: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129d84) {
            ctx->pc = 0x129D98u;
            goto label_129d98;
        }
    }
    ctx->pc = 0x129D8Cu;
    // 0x129d8c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129d8cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x129d90: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x129D90u;
    {
        const bool branch_taken_0x129d90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129D94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129D90u;
            // 0x129d94: 0x2484a238  addiu       $a0, $a0, -0x5DC8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943288));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129d90) {
            ctx->pc = 0x129DD8u;
            goto label_129dd8;
        }
    }
    ctx->pc = 0x129D98u;
label_129d98:
    // 0x129d98: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x129d98u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x129d9c: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x129d9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x129da0: 0x8c84cd00  lw          $a0, -0x3300($a0)
    ctx->pc = 0x129da0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294954240)));
    // 0x129da4: 0x14800004  bnez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x129DA4u;
    {
        const bool branch_taken_0x129da4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x129da4) {
            ctx->pc = 0x129DB8u;
            goto label_129db8;
        }
    }
    ctx->pc = 0x129DACu;
    // 0x129dac: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129dacu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x129db0: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x129DB0u;
    {
        const bool branch_taken_0x129db0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129DB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129DB0u;
            // 0x129db4: 0x2484a238  addiu       $a0, $a0, -0x5DC8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943288));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129db0) {
            ctx->pc = 0x129DD8u;
            goto label_129dd8;
        }
    }
    ctx->pc = 0x129DB8u;
label_129db8:
    // 0x129db8: 0x4a20006  bltzl       $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x129DB8u;
    {
        const bool branch_taken_0x129db8 = (GPR_S64(ctx, 5) < 0);
        if (branch_taken_0x129db8) {
            ctx->pc = 0x129DBCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129DB8u;
            // 0x129dbc: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129DD4u;
            goto label_129dd4;
        }
    }
    ctx->pc = 0x129DC0u;
    // 0x129dc0: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x129dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x129dc4: 0xa2102a  slt         $v0, $a1, $v0
    ctx->pc = 0x129dc4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x129dc8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x129DC8u;
    {
        const bool branch_taken_0x129dc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x129DCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129DC8u;
            // 0x129dcc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129dc8) {
            ctx->pc = 0x129DE4u;
            goto label_129de4;
        }
    }
    ctx->pc = 0x129DD0u;
    // 0x129dd0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129dd0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
label_129dd4:
    // 0x129dd4: 0x2484a260  addiu       $a0, $a0, -0x5DA0
    ctx->pc = 0x129dd4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943328));
label_129dd8:
    // 0x129dd8: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x129DD8u;
    SET_GPR_U32(ctx, 31, 0x129DE0u);
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129DE0u; }
        if (ctx->pc != 0x129DE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129DE0u; }
        if (ctx->pc != 0x129DE0u) { return; }
    }
    ctx->pc = 0x129DE0u;
label_129de0:
    // 0x129de0: 0x2402fffd  addiu       $v0, $zero, -0x3
    ctx->pc = 0x129de0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
label_129de4:
    // 0x129de4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x129de4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129de8: 0x3e00008  jr          $ra
    ctx->pc = 0x129DE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129DECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129DE8u;
            // 0x129dec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129D98u: goto label_129d98;
            case 0x129DB8u: goto label_129db8;
            case 0x129DD4u: goto label_129dd4;
            case 0x129DD8u: goto label_129dd8;
            case 0x129DE0u: goto label_129de0;
            case 0x129DE4u: goto label_129de4;
            case 0x129E0Cu: goto label_129e0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129DF0u;
    // 0x129df0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x129df0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x129df4: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x129df4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129df8: 0x100482d  daddu       $t1, $t0, $zero
    ctx->pc = 0x129df8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129dfc: 0x40402d  daddu       $t0, $v0, $zero
    ctx->pc = 0x129dfcu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129e00: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x129e00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x129e04: 0xc04a786  jal         func_129E18
    ctx->pc = 0x129E04u;
    SET_GPR_U32(ctx, 31, 0x129E0Cu);
    ctx->pc = 0x129E08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129E04u;
            // 0x129e08: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129E18u;
    if (runtime->hasFunction(0x129E18u)) {
        auto targetFn = runtime->lookupFunction(0x129E18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129E0Cu; }
        if (ctx->pc != 0x129E0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129E18_0x129e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129E0Cu; }
        if (ctx->pc != 0x129E0Cu) { return; }
    }
    ctx->pc = 0x129E0Cu;
label_129e0c:
    // 0x129e0c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x129e0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x129e10: 0x3e00008  jr          $ra
    ctx->pc = 0x129E10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129E14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129E10u;
            // 0x129e14: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129D98u: goto label_129d98;
            case 0x129DB8u: goto label_129db8;
            case 0x129DD4u: goto label_129dd4;
            case 0x129DD8u: goto label_129dd8;
            case 0x129DE0u: goto label_129de0;
            case 0x129DE4u: goto label_129de4;
            case 0x129E0Cu: goto label_129e0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129E18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
