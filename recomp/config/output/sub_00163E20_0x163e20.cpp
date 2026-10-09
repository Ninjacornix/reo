#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163E20
// Address: 0x163e20 - 0x163e88
void sub_00163E20_0x163e20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163E20_0x163e20");
#endif

    switch (ctx->pc) {
        case 0x163e40u: goto label_163e40;
        case 0x163e58u: goto label_163e58;
        case 0x163e68u: goto label_163e68;
        default: break;
    }

    ctx->pc = 0x163e20u;

    // 0x163e20: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x163e20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x163e24: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x163e24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x163e28: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x163e28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x163e2c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x163e2cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163e30: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x163e30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x163e34: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x163e34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x163e38: 0xc04ad84  jal         func_12B610
    ctx->pc = 0x163E38u;
    SET_GPR_U32(ctx, 31, 0x163E40u);
    ctx->pc = 0x163E3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163E38u;
            // 0x163e3c: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B610u;
    if (runtime->hasFunction(0x12B610u)) {
        auto targetFn = runtime->lookupFunction(0x12B610u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163E40u; }
        if (ctx->pc != 0x163E40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B610_0x12b610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163E40u; }
        if (ctx->pc != 0x163E40u) { return; }
    }
    ctx->pc = 0x163E40u;
label_163e40:
    // 0x163e40: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x163e40u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163e44: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x163e44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x163e48: 0x56020009  bnel        $s0, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x163E48u;
    {
        const bool branch_taken_0x163e48 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x163e48) {
            ctx->pc = 0x163E4Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x163E48u;
            // 0x163e4c: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x163E70u;
            goto label_163e70;
        }
    }
    ctx->pc = 0x163E50u;
    // 0x163e50: 0xc058fa2  jal         func_163E88
    ctx->pc = 0x163E50u;
    SET_GPR_U32(ctx, 31, 0x163E58u);
    ctx->pc = 0x163E88u;
    if (runtime->hasFunction(0x163E88u)) {
        auto targetFn = runtime->lookupFunction(0x163E88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163E58u; }
        if (ctx->pc != 0x163E58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163E88_0x163e88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163E58u; }
        if (ctx->pc != 0x163E58u) { return; }
    }
    ctx->pc = 0x163E58u;
label_163e58:
    // 0x163e58: 0x10500004  beq         $v0, $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x163E58u;
    {
        const bool branch_taken_0x163e58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 16));
        ctx->pc = 0x163E5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163E58u;
            // 0x163e5c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163e58) {
            ctx->pc = 0x163E6Cu;
            goto label_163e6c;
        }
    }
    ctx->pc = 0x163E60u;
    // 0x163e60: 0xc05900e  jal         func_164038
    ctx->pc = 0x163E60u;
    SET_GPR_U32(ctx, 31, 0x163E68u);
    ctx->pc = 0x164038u;
    if (runtime->hasFunction(0x164038u)) {
        auto targetFn = runtime->lookupFunction(0x164038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163E68u; }
        if (ctx->pc != 0x163E68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164038_0x164038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163E68u; }
        if (ctx->pc != 0x163E68u) { return; }
    }
    ctx->pc = 0x163E68u;
label_163e68:
    // 0x163e68: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x163e68u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_163e6c:
    // 0x163e6c: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x163e6cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_163e70:
    // 0x163e70: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x163e70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163e74: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x163e74u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163e78: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x163e78u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x163e7c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x163e7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x163e80: 0x3e00008  jr          $ra
    ctx->pc = 0x163E80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163E84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163E80u;
            // 0x163e84: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163E40u: goto label_163e40;
            case 0x163E58u: goto label_163e58;
            case 0x163E68u: goto label_163e68;
            case 0x163E6Cu: goto label_163e6c;
            case 0x163E70u: goto label_163e70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163E88u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
