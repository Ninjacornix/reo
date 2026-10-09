#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180F60
// Address: 0x180f60 - 0x180fe0
void sub_00180F60_0x180f60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180F60_0x180f60");
#endif

    switch (ctx->pc) {
        case 0x180f8cu: goto label_180f8c;
        case 0x180fc8u: goto label_180fc8;
        default: break;
    }

    ctx->pc = 0x180f60u;

    // 0x180f60: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x180f60u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x180f64: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x180f64u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x180f68: 0x8c65fa10  lw          $a1, -0x5F0($v1)
    ctx->pc = 0x180f68u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294965776)));
    // 0x180f6c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180f6cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180f70: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x180f70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x180f74: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x180f74u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180f78: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x180f78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x180f7c: 0x10a00013  beqz        $a1, . + 4 + (0x13 << 2)
    ctx->pc = 0x180F7Cu;
    {
        const bool branch_taken_0x180f7c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x180F80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180F7Cu;
            // 0x180f80: 0x34428001  ori         $v0, $v0, 0x8001 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180f7c) {
            ctx->pc = 0x180FCCu;
            goto label_180fcc;
        }
    }
    ctx->pc = 0x180F84u;
    // 0x180f84: 0xc061e90  jal         func_187A40
    ctx->pc = 0x180F84u;
    SET_GPR_U32(ctx, 31, 0x180F8Cu);
    ctx->pc = 0x187A40u;
    if (runtime->hasFunction(0x187A40u)) {
        auto targetFn = runtime->lookupFunction(0x187A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180F8Cu; }
        if (ctx->pc != 0x180F8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187A40_0x187a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180F8Cu; }
        if (ctx->pc != 0x180F8Cu) { return; }
    }
    ctx->pc = 0x180F8Cu;
label_180f8c:
    // 0x180f8c: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x180f8cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x180f90: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x180F90u;
    {
        const bool branch_taken_0x180f90 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x180F94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180F90u;
            // 0x180f94: 0x24649500  addiu       $a0, $v1, -0x6B00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294939904));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180f90) {
            ctx->pc = 0x180FA8u;
            goto label_180fa8;
        }
    }
    ctx->pc = 0x180F98u;
    // 0x180f98: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180f98u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180f9c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x180F9Cu;
    {
        const bool branch_taken_0x180f9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x180FA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180F9Cu;
            // 0x180fa0: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180f9c) {
            ctx->pc = 0x180FCCu;
            goto label_180fcc;
        }
    }
    ctx->pc = 0x180FA4u;
    // 0x180fa4: 0x0  nop
    ctx->pc = 0x180fa4u;
    // NOP
label_180fa8:
    // 0x180fa8: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x180fa8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x180fac: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180facu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180fb0: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x180FB0u;
    {
        const bool branch_taken_0x180fb0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x180FB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180FB0u;
            // 0x180fb4: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180fb0) {
            ctx->pc = 0x180FCCu;
            goto label_180fcc;
        }
    }
    ctx->pc = 0x180FB8u;
    // 0x180fb8: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x180fb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x180fbc: 0xac900000  sw          $s0, 0x0($a0)
    ctx->pc = 0x180fbcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 16));
    // 0x180fc0: 0xc062228  jal         func_1888A0
    ctx->pc = 0x180FC0u;
    SET_GPR_U32(ctx, 31, 0x180FC8u);
    ctx->pc = 0x180FC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180FC0u;
            // 0x180fc4: 0xac820004  sw          $v0, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1888A0u;
    if (runtime->hasFunction(0x1888A0u)) {
        auto targetFn = runtime->lookupFunction(0x1888A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180FC8u; }
        if (ctx->pc != 0x180FC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001888A0_0x1888a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180FC8u; }
        if (ctx->pc != 0x180FC8u) { return; }
    }
    ctx->pc = 0x180FC8u;
label_180fc8:
    // 0x180fc8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x180fc8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_180fcc:
    // 0x180fcc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x180fccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180fd0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x180fd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x180fd4: 0x3e00008  jr          $ra
    ctx->pc = 0x180FD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180FD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180FD4u;
            // 0x180fd8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180F8Cu: goto label_180f8c;
            case 0x180FA8u: goto label_180fa8;
            case 0x180FC8u: goto label_180fc8;
            case 0x180FCCu: goto label_180fcc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180FDCu;
    // 0x180fdc: 0x0  nop
    ctx->pc = 0x180fdcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
