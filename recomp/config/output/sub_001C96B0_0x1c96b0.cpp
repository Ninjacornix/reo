#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C96B0
// Address: 0x1c96b0 - 0x1c9770
void sub_001C96B0_0x1c96b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C96B0_0x1c96b0");
#endif

    switch (ctx->pc) {
        case 0x1c96e0u: goto label_1c96e0;
        case 0x1c970cu: goto label_1c970c;
        case 0x1c971cu: goto label_1c971c;
        case 0x1c972cu: goto label_1c972c;
        default: break;
    }

    ctx->pc = 0x1c96b0u;

    // 0x1c96b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c96b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c96b4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c96b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c96b8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c96b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c96bc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c96bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c96c0: 0x8c23d158  lw          $v1, -0x2EA8($at)
    ctx->pc = 0x1c96c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1c96c4: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1c96c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1c96c8: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C96C8u;
    {
        const bool branch_taken_0x1c96c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C96CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C96C8u;
            // 0x1c96cc: 0x27a4001c  addiu       $a0, $sp, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c96c8) {
            ctx->pc = 0x1C96D8u;
            goto label_1c96d8;
        }
    }
    ctx->pc = 0x1C96D0u;
    // 0x1c96d0: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1C96D0u;
    {
        const bool branch_taken_0x1c96d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C96D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C96D0u;
            // 0x1c96d4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c96d0) {
            ctx->pc = 0x1C9760u;
            goto label_1c9760;
        }
    }
    ctx->pc = 0x1C96D8u;
label_1c96d8:
    // 0x1c96d8: 0xc075db0  jal         func_1D76C0
    ctx->pc = 0x1C96D8u;
    SET_GPR_U32(ctx, 31, 0x1C96E0u);
    ctx->pc = 0x1D76C0u;
    if (runtime->hasFunction(0x1D76C0u)) {
        auto targetFn = runtime->lookupFunction(0x1D76C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C96E0u; }
        if (ctx->pc != 0x1C96E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D76C0_0x1d76c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C96E0u; }
        if (ctx->pc != 0x1C96E0u) { return; }
    }
    ctx->pc = 0x1C96E0u;
label_1c96e0:
    // 0x1c96e0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c96e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c96e4: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C96E4u;
    {
        const bool branch_taken_0x1c96e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C96E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C96E4u;
            // 0x1c96e8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c96e4) {
            ctx->pc = 0x1C9704u;
            goto label_1c9704;
        }
    }
    ctx->pc = 0x1C96ECu;
    // 0x1c96ec: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C96ECu;
    {
        const bool branch_taken_0x1c96ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c96ec) {
            ctx->pc = 0x1C96FCu;
            goto label_1c96fc;
        }
    }
    ctx->pc = 0x1C96F4u;
    // 0x1c96f4: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1C96F4u;
    {
        const bool branch_taken_0x1c96f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C96F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C96F4u;
            // 0x1c96f8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c96f4) {
            ctx->pc = 0x1C9760u;
            goto label_1c9760;
        }
    }
    ctx->pc = 0x1C96FCu;
label_1c96fc:
    // 0x1c96fc: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1C96FCu;
    {
        const bool branch_taken_0x1c96fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C96FCu;
            // 0x1c9700: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c96fc) {
            ctx->pc = 0x1C9760u;
            goto label_1c9760;
        }
    }
    ctx->pc = 0x1C9704u;
label_1c9704:
    // 0x1c9704: 0xc075dcc  jal         func_1D7730
    ctx->pc = 0x1C9704u;
    SET_GPR_U32(ctx, 31, 0x1C970Cu);
    ctx->pc = 0x1C9708u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9704u;
            // 0x1c9708: 0x27a50018  addiu       $a1, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7730u;
    if (runtime->hasFunction(0x1D7730u)) {
        auto targetFn = runtime->lookupFunction(0x1D7730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C970Cu; }
        if (ctx->pc != 0x1C970Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7730_0x1d7730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C970Cu; }
        if (ctx->pc != 0x1C970Cu) { return; }
    }
    ctx->pc = 0x1C970Cu;
label_1c970c:
    // 0x1c970c: 0x1840000f  blez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1C970Cu;
    {
        const bool branch_taken_0x1c970c = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1c970c) {
            ctx->pc = 0x1C974Cu;
            goto label_1c974c;
        }
    }
    ctx->pc = 0x1C9714u;
    // 0x1c9714: 0xc0759c4  jal         func_1D6710
    ctx->pc = 0x1C9714u;
    SET_GPR_U32(ctx, 31, 0x1C971Cu);
    ctx->pc = 0x1D6710u;
    if (runtime->hasFunction(0x1D6710u)) {
        auto targetFn = runtime->lookupFunction(0x1D6710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C971Cu; }
        if (ctx->pc != 0x1C971Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6710_0x1d6710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C971Cu; }
        if (ctx->pc != 0x1C971Cu) { return; }
    }
    ctx->pc = 0x1C971Cu;
label_1c971c:
    // 0x1c971c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1C971Cu;
    {
        const bool branch_taken_0x1c971c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c971c) {
            ctx->pc = 0x1C974Cu;
            goto label_1c974c;
        }
    }
    ctx->pc = 0x1C9724u;
    // 0x1c9724: 0xc075dec  jal         func_1D77B0
    ctx->pc = 0x1C9724u;
    SET_GPR_U32(ctx, 31, 0x1C972Cu);
    ctx->pc = 0x1C9728u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9724u;
            // 0x1c9728: 0x8fa40018  lw          $a0, 0x18($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D77B0u;
    if (runtime->hasFunction(0x1D77B0u)) {
        auto targetFn = runtime->lookupFunction(0x1D77B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C972Cu; }
        if (ctx->pc != 0x1C972Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D77B0_0x1d77b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C972Cu; }
        if (ctx->pc != 0x1C972Cu) { return; }
    }
    ctx->pc = 0x1C972Cu;
label_1c972c:
    // 0x1c972c: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C972Cu;
    {
        const bool branch_taken_0x1c972c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c972c) {
            ctx->pc = 0x1C974Cu;
            goto label_1c974c;
        }
    }
    ctx->pc = 0x1C9734u;
    // 0x1c9734: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9734u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9738: 0x8fa40018  lw          $a0, 0x18($sp)
    ctx->pc = 0x1c9738u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1c973c: 0x8c23d158  lw          $v1, -0x2EA8($at)
    ctx->pc = 0x1c973cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1c9740: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c9740u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9744: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1C9744u;
    {
        const bool branch_taken_0x1c9744 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9744u;
            // 0x1c9748: 0xac640010  sw          $a0, 0x10($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9744) {
            ctx->pc = 0x1C9760u;
            goto label_1c9760;
        }
    }
    ctx->pc = 0x1C974Cu;
label_1c974c:
    // 0x1c974c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c974cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9750: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c9750u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c9754: 0x8c22d158  lw          $v0, -0x2EA8($at)
    ctx->pc = 0x1c9754u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1c9758: 0xac430010  sw          $v1, 0x10($v0)
    ctx->pc = 0x1c9758u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 3));
    // 0x1c975c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1c975cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1c9760:
    // 0x1c9760: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c9760u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c9764: 0x3e00008  jr          $ra
    ctx->pc = 0x1C9764u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C9768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9764u;
            // 0x1c9768: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C96D8u: goto label_1c96d8;
            case 0x1C96E0u: goto label_1c96e0;
            case 0x1C96FCu: goto label_1c96fc;
            case 0x1C9704u: goto label_1c9704;
            case 0x1C970Cu: goto label_1c970c;
            case 0x1C971Cu: goto label_1c971c;
            case 0x1C972Cu: goto label_1c972c;
            case 0x1C974Cu: goto label_1c974c;
            case 0x1C9760u: goto label_1c9760;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C976Cu;
    // 0x1c976c: 0x0  nop
    ctx->pc = 0x1c976cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
