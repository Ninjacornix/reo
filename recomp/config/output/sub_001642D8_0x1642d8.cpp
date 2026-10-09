#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001642D8
// Address: 0x1642d8 - 0x164328
void sub_001642D8_0x1642d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001642D8_0x1642d8");
#endif

    switch (ctx->pc) {
        case 0x1642ecu: goto label_1642ec;
        case 0x164300u: goto label_164300;
        case 0x164310u: goto label_164310;
        default: break;
    }

    ctx->pc = 0x1642d8u;

    // 0x1642d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1642d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1642dc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1642dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1642e0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1642e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1642e4: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1642E4u;
    SET_GPR_U32(ctx, 31, 0x1642ECu);
    ctx->pc = 0x1642E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1642E4u;
            // 0x1642e8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1642ECu; }
        if (ctx->pc != 0x1642ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1642ECu; }
        if (ctx->pc != 0x1642ECu) { return; }
    }
    ctx->pc = 0x1642ECu;
label_1642ec:
    // 0x1642ec: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1642ECu;
    {
        const bool branch_taken_0x1642ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1642F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1642ECu;
            // 0x1642f0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1642ec) {
            ctx->pc = 0x164308u;
            goto label_164308;
        }
    }
    ctx->pc = 0x1642F4u;
    // 0x1642f4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1642f4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1642f8: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1642F8u;
    SET_GPR_U32(ctx, 31, 0x164300u);
    ctx->pc = 0x1642FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1642F8u;
            // 0x1642fc: 0x24840570  addiu       $a0, $a0, 0x570 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1392));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164300u; }
        if (ctx->pc != 0x164300u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164300u; }
        if (ctx->pc != 0x164300u) { return; }
    }
    ctx->pc = 0x164300u;
label_164300:
    // 0x164300: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x164300u;
    {
        const bool branch_taken_0x164300 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x164304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164300u;
            // 0x164304: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164300) {
            ctx->pc = 0x164318u;
            goto label_164318;
        }
    }
    ctx->pc = 0x164308u;
label_164308:
    // 0x164308: 0xc0590b0  jal         func_1642C0
    ctx->pc = 0x164308u;
    SET_GPR_U32(ctx, 31, 0x164310u);
    ctx->pc = 0x1642C0u;
    if (runtime->hasFunction(0x1642C0u)) {
        auto targetFn = runtime->lookupFunction(0x1642C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164310u; }
        if (ctx->pc != 0x164310u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001642C0_0x1642c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164310u; }
        if (ctx->pc != 0x164310u) { return; }
    }
    ctx->pc = 0x164310u;
label_164310:
    // 0x164310: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x164310u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x164314: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x164314u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_164318:
    // 0x164318: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x164318u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16431c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16431cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x164320: 0x3e00008  jr          $ra
    ctx->pc = 0x164320u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164320u;
            // 0x164324: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1642ECu: goto label_1642ec;
            case 0x164300u: goto label_164300;
            case 0x164308u: goto label_164308;
            case 0x164310u: goto label_164310;
            case 0x164318u: goto label_164318;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164328u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
