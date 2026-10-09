#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163DA0
// Address: 0x163da0 - 0x163e20
void sub_00163DA0_0x163da0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163DA0_0x163da0");
#endif

    switch (ctx->pc) {
        case 0x163dc0u: goto label_163dc0;
        case 0x163dd8u: goto label_163dd8;
        case 0x163de8u: goto label_163de8;
        case 0x163df8u: goto label_163df8;
        case 0x163e00u: goto label_163e00;
        default: break;
    }

    ctx->pc = 0x163da0u;

    // 0x163da0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x163da0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x163da4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x163da4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x163da8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x163da8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163dac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x163dacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x163db0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x163db0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x163db4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x163db4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x163db8: 0xc04ad84  jal         func_12B610
    ctx->pc = 0x163DB8u;
    SET_GPR_U32(ctx, 31, 0x163DC0u);
    ctx->pc = 0x163DBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163DB8u;
            // 0x163dbc: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B610u;
    if (runtime->hasFunction(0x12B610u)) {
        auto targetFn = runtime->lookupFunction(0x12B610u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163DC0u; }
        if (ctx->pc != 0x163DC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B610_0x12b610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163DC0u; }
        if (ctx->pc != 0x163DC0u) { return; }
    }
    ctx->pc = 0x163DC0u;
label_163dc0:
    // 0x163dc0: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x163dc0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163dc4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x163dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x163dc8: 0x16420009  bne         $s2, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x163DC8u;
    {
        const bool branch_taken_0x163dc8 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        ctx->pc = 0x163DCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163DC8u;
            // 0x163dcc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163dc8) {
            ctx->pc = 0x163DF0u;
            goto label_163df0;
        }
    }
    ctx->pc = 0x163DD0u;
    // 0x163dd0: 0xc058fa2  jal         func_163E88
    ctx->pc = 0x163DD0u;
    SET_GPR_U32(ctx, 31, 0x163DD8u);
    ctx->pc = 0x163E88u;
    if (runtime->hasFunction(0x163E88u)) {
        auto targetFn = runtime->lookupFunction(0x163E88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163DD8u; }
        if (ctx->pc != 0x163DD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163E88_0x163e88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163DD8u; }
        if (ctx->pc != 0x163DD8u) { return; }
    }
    ctx->pc = 0x163DD8u;
label_163dd8:
    // 0x163dd8: 0x1452000a  bne         $v0, $s2, . + 4 + (0xA << 2)
    ctx->pc = 0x163DD8u;
    {
        const bool branch_taken_0x163dd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        ctx->pc = 0x163DDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163DD8u;
            // 0x163ddc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163dd8) {
            ctx->pc = 0x163E04u;
            goto label_163e04;
        }
    }
    ctx->pc = 0x163DE0u;
    // 0x163de0: 0xc05900e  jal         func_164038
    ctx->pc = 0x163DE0u;
    SET_GPR_U32(ctx, 31, 0x163DE8u);
    ctx->pc = 0x164038u;
    if (runtime->hasFunction(0x164038u)) {
        auto targetFn = runtime->lookupFunction(0x164038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163DE8u; }
        if (ctx->pc != 0x163DE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164038_0x164038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163DE8u; }
        if (ctx->pc != 0x163DE8u) { return; }
    }
    ctx->pc = 0x163DE8u;
label_163de8:
    // 0x163de8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x163DE8u;
    {
        const bool branch_taken_0x163de8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x163DECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163DE8u;
            // 0x163dec: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163de8) {
            ctx->pc = 0x163E04u;
            goto label_163e04;
        }
    }
    ctx->pc = 0x163DF0u;
label_163df0:
    // 0x163df0: 0xc058faa  jal         func_163EA8
    ctx->pc = 0x163DF0u;
    SET_GPR_U32(ctx, 31, 0x163DF8u);
    ctx->pc = 0x163EA8u;
    if (runtime->hasFunction(0x163EA8u)) {
        auto targetFn = runtime->lookupFunction(0x163EA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163DF8u; }
        if (ctx->pc != 0x163DF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163EA8_0x163ea8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163DF8u; }
        if (ctx->pc != 0x163DF8u) { return; }
    }
    ctx->pc = 0x163DF8u;
label_163df8:
    // 0x163df8: 0xc05900e  jal         func_164038
    ctx->pc = 0x163DF8u;
    SET_GPR_U32(ctx, 31, 0x163E00u);
    ctx->pc = 0x163DFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163DF8u;
            // 0x163dfc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164038u;
    if (runtime->hasFunction(0x164038u)) {
        auto targetFn = runtime->lookupFunction(0x164038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163E00u; }
        if (ctx->pc != 0x163E00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164038_0x164038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163E00u; }
        if (ctx->pc != 0x163E00u) { return; }
    }
    ctx->pc = 0x163E00u;
label_163e00:
    // 0x163e00: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x163e00u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_163e04:
    // 0x163e04: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x163e04u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163e08: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x163e08u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163e0c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x163e0cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163e10: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x163e10u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x163e14: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x163e14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x163e18: 0x3e00008  jr          $ra
    ctx->pc = 0x163E18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163E1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163E18u;
            // 0x163e1c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163DC0u: goto label_163dc0;
            case 0x163DD8u: goto label_163dd8;
            case 0x163DE8u: goto label_163de8;
            case 0x163DF0u: goto label_163df0;
            case 0x163DF8u: goto label_163df8;
            case 0x163E00u: goto label_163e00;
            case 0x163E04u: goto label_163e04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163E20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
