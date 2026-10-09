#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011BE78
// Address: 0x11be78 - 0x11bf08
void sub_0011BE78_0x11be78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011BE78_0x11be78");
#endif

    switch (ctx->pc) {
        case 0x11beb4u: goto label_11beb4;
        case 0x11beccu: goto label_11becc;
        case 0x11bee0u: goto label_11bee0;
        default: break;
    }

    ctx->pc = 0x11be78u;

    // 0x11be78: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x11be78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x11be7c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11be7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11be80: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x11be80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x11be84: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x11be84u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x11be88: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11be88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11be8c: 0x24539d2c  addiu       $s3, $v0, -0x62D4
    ctx->pc = 0x11be8cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941996));
    // 0x11be90: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11be90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11be94: 0x2471e628  addiu       $s1, $v1, -0x19D8
    ctx->pc = 0x11be94u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 4294960680));
    // 0x11be98: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x11be98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x11be9c: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x11be9cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bea0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11bea0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11bea4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11bea4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bea8: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x11bea8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11beac: 0xc041e86  jal         func_107A18
    ctx->pc = 0x11BEACu;
    SET_GPR_U32(ctx, 31, 0x11BEB4u);
    ctx->pc = 0x11BEB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11BEACu;
            // 0x11beb0: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BEB4u; }
        if (ctx->pc != 0x11BEB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BEB4u; }
        if (ctx->pc != 0x11BEB4u) { return; }
    }
    ctx->pc = 0x11BEB4u;
label_11beb4:
    // 0x11beb4: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x11BEB4u;
    {
        const bool branch_taken_0x11beb4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BEB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BEB4u;
            // 0x11beb8: 0x3c100021  lui         $s0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11beb4) {
            ctx->pc = 0x11BEE4u;
            goto label_11bee4;
        }
    }
    ctx->pc = 0x11BEBCu;
    // 0x11bebc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11bebcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bec0: 0x8e059e04  lw          $a1, -0x61FC($s0)
    ctx->pc = 0x11bec0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942212)));
    // 0x11bec4: 0xc041e86  jal         func_107A18
    ctx->pc = 0x11BEC4u;
    SET_GPR_U32(ctx, 31, 0x11BECCu);
    ctx->pc = 0x11BEC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11BEC4u;
            // 0x11bec8: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BECCu; }
        if (ctx->pc != 0x11BECCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BECCu; }
        if (ctx->pc != 0x11BECCu) { return; }
    }
    ctx->pc = 0x11BECCu;
label_11becc:
    // 0x11becc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11BECCu;
    {
        const bool branch_taken_0x11becc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BECCu;
            // 0x11bed0: 0x8e059e04  lw          $a1, -0x61FC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942212)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11becc) {
            ctx->pc = 0x11BEE4u;
            goto label_11bee4;
        }
    }
    ctx->pc = 0x11BED4u;
    // 0x11bed4: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x11bed4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bed8: 0xc041e86  jal         func_107A18
    ctx->pc = 0x11BED8u;
    SET_GPR_U32(ctx, 31, 0x11BEE0u);
    ctx->pc = 0x11BEDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11BED8u;
            // 0x11bedc: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BEE0u; }
        if (ctx->pc != 0x11BEE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BEE0u; }
        if (ctx->pc != 0x11BEE0u) { return; }
    }
    ctx->pc = 0x11BEE0u;
label_11bee0:
    // 0x11bee0: 0x2902b  sltu        $s2, $zero, $v0
    ctx->pc = 0x11bee0u;
    SET_GPR_U64(ctx, 18, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_11bee4:
    // 0x11bee4: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x11bee4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bee8: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x11bee8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11beec: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x11beecu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11bef0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11bef0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11bef4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11bef4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11bef8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11bef8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11befc: 0x3e00008  jr          $ra
    ctx->pc = 0x11BEFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11BF00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BEFCu;
            // 0x11bf00: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11BEB4u: goto label_11beb4;
            case 0x11BECCu: goto label_11becc;
            case 0x11BEE0u: goto label_11bee0;
            case 0x11BEE4u: goto label_11bee4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11BF04u;
    // 0x11bf04: 0x0  nop
    ctx->pc = 0x11bf04u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
