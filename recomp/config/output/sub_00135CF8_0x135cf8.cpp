#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135CF8
// Address: 0x135cf8 - 0x135d60
void sub_00135CF8_0x135cf8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135CF8_0x135cf8");
#endif

    switch (ctx->pc) {
        case 0x135d14u: goto label_135d14;
        case 0x135d38u: goto label_135d38;
        case 0x135d4cu: goto label_135d4c;
        default: break;
    }

    ctx->pc = 0x135cf8u;

    // 0x135cf8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x135cf8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x135cfc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x135cfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x135d00: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x135D00u;
    {
        const bool branch_taken_0x135d00 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x135D04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135D00u;
            // 0x135d04: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135d00) {
            ctx->pc = 0x135D20u;
            goto label_135d20;
        }
    }
    ctx->pc = 0x135D08u;
    // 0x135d08: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x135d08u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x135d0c: 0xc04d480  jal         func_135200
    ctx->pc = 0x135D0Cu;
    SET_GPR_U32(ctx, 31, 0x135D14u);
    ctx->pc = 0x135D10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135D0Cu;
            // 0x135d10: 0x2484b990  addiu       $a0, $a0, -0x4670 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949264));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135D14u; }
        if (ctx->pc != 0x135D14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135D14u; }
        if (ctx->pc != 0x135D14u) { return; }
    }
    ctx->pc = 0x135D14u;
label_135d14:
    // 0x135d14: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x135D14u;
    {
        const bool branch_taken_0x135d14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x135D18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135D14u;
            // 0x135d18: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135d14) {
            ctx->pc = 0x135D50u;
            goto label_135d50;
        }
    }
    ctx->pc = 0x135D1Cu;
    // 0x135d1c: 0x0  nop
    ctx->pc = 0x135d1cu;
    // NOP
label_135d20:
    // 0x135d20: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x135d20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x135d24: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x135d24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x135d28: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x135D28u;
    {
        const bool branch_taken_0x135d28 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x135d28) {
            ctx->pc = 0x135D2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x135D28u;
            // 0x135d2c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x135D40u;
            goto label_135d40;
        }
    }
    ctx->pc = 0x135D30u;
    // 0x135d30: 0x40f809  jalr        $v0
    ctx->pc = 0x135D30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x135D38u);
        ctx->pc = 0x135D34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135D30u;
            // 0x135d34: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x135D38u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135D14u: goto label_135d14;
            case 0x135D20u: goto label_135d20;
            case 0x135D38u: goto label_135d38;
            case 0x135D40u: goto label_135d40;
            case 0x135D4Cu: goto label_135d4c;
            case 0x135D50u: goto label_135d50;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x135D38u; }
            if (ctx->pc != 0x135D38u) { return; }
        }
        }
    }
    ctx->pc = 0x135D38u;
label_135d38:
    // 0x135d38: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x135D38u;
    {
        const bool branch_taken_0x135d38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x135D3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135D38u;
            // 0x135d3c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135d38) {
            ctx->pc = 0x135D4Cu;
            goto label_135d4c;
        }
    }
    ctx->pc = 0x135D40u;
label_135d40:
    // 0x135d40: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x135d40u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135d44: 0xc04d480  jal         func_135200
    ctx->pc = 0x135D44u;
    SET_GPR_U32(ctx, 31, 0x135D4Cu);
    ctx->pc = 0x135D48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135D44u;
            // 0x135d48: 0x2484b9b0  addiu       $a0, $a0, -0x4650 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949296));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135D4Cu; }
        if (ctx->pc != 0x135D4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135D4Cu; }
        if (ctx->pc != 0x135D4Cu) { return; }
    }
    ctx->pc = 0x135D4Cu;
label_135d4c:
    // 0x135d4c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x135d4cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_135d50:
    // 0x135d50: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x135d50u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135d54: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x135d54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x135d58: 0x3e00008  jr          $ra
    ctx->pc = 0x135D58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135D5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135D58u;
            // 0x135d5c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135D14u: goto label_135d14;
            case 0x135D20u: goto label_135d20;
            case 0x135D38u: goto label_135d38;
            case 0x135D40u: goto label_135d40;
            case 0x135D4Cu: goto label_135d4c;
            case 0x135D50u: goto label_135d50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x135D60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
