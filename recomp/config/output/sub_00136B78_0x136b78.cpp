#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136B78
// Address: 0x136b78 - 0x136c34
void sub_00136B78_0x136b78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136B78_0x136b78");
#endif

    switch (ctx->pc) {
        case 0x136bc0u: goto label_136bc0;
        case 0x136be4u: goto label_136be4;
        case 0x136bf8u: goto label_136bf8;
        case 0x136c20u: goto label_136c20;
        default: break;
    }

    ctx->pc = 0x136b78u;

    // 0x136b78: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x136b78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x136b7c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x136b7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x136b80: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x136b80u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136b84: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x136b84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x136b88: 0x14800005  bnez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136B88u;
    {
        const bool branch_taken_0x136b88 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136B8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136B88u;
            // 0x136b8c: 0xffbf0030  sd          $ra, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136b88) {
            ctx->pc = 0x136BA0u;
            goto label_136ba0;
        }
    }
    ctx->pc = 0x136B90u;
    // 0x136b90: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136b90u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136b94: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x136B94u;
    {
        const bool branch_taken_0x136b94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136B98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136B94u;
            // 0x136b98: 0x2484c140  addiu       $a0, $a0, -0x3EC0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951232));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136b94) {
            ctx->pc = 0x136BDCu;
            goto label_136bdc;
        }
    }
    ctx->pc = 0x136B9Cu;
    // 0x136b9c: 0x0  nop
    ctx->pc = 0x136b9cu;
    // NOP
label_136ba0:
    // 0x136ba0: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136BA0u;
    {
        const bool branch_taken_0x136ba0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x136ba0) {
            ctx->pc = 0x136BB8u;
            goto label_136bb8;
        }
    }
    ctx->pc = 0x136BA8u;
    // 0x136ba8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136ba8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136bac: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x136BACu;
    {
        const bool branch_taken_0x136bac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136BB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136BACu;
            // 0x136bb0: 0x2484c168  addiu       $a0, $a0, -0x3E98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951272));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136bac) {
            ctx->pc = 0x136BDCu;
            goto label_136bdc;
        }
    }
    ctx->pc = 0x136BB4u;
    // 0x136bb4: 0x0  nop
    ctx->pc = 0x136bb4u;
    // NOP
label_136bb8:
    // 0x136bb8: 0xc04d558  jal         func_135560
    ctx->pc = 0x136BB8u;
    SET_GPR_U32(ctx, 31, 0x136BC0u);
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136BC0u; }
        if (ctx->pc != 0x136BC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136BC0u; }
        if (ctx->pc != 0x136BC0u) { return; }
    }
    ctx->pc = 0x136BC0u;
label_136bc0:
    // 0x136bc0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x136bc0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136bc4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x136bc4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136bc8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136bc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136bcc: 0x16200008  bnez        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x136BCCu;
    {
        const bool branch_taken_0x136bcc = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x136BD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136BCCu;
            // 0x136bd0: 0x24060014  addiu       $a2, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136bcc) {
            ctx->pc = 0x136BF0u;
            goto label_136bf0;
        }
    }
    ctx->pc = 0x136BD4u;
    // 0x136bd4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136bd4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136bd8: 0x2484c198  addiu       $a0, $a0, -0x3E68
    ctx->pc = 0x136bd8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951320));
label_136bdc:
    // 0x136bdc: 0xc04d480  jal         func_135200
    ctx->pc = 0x136BDCu;
    SET_GPR_U32(ctx, 31, 0x136BE4u);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136BE4u; }
        if (ctx->pc != 0x136BE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136BE4u; }
        if (ctx->pc != 0x136BE4u) { return; }
    }
    ctx->pc = 0x136BE4u;
label_136be4:
    // 0x136be4: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x136BE4u;
    {
        const bool branch_taken_0x136be4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136BE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136BE4u;
            // 0x136be8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136be4) {
            ctx->pc = 0x136C20u;
            goto label_136c20;
        }
    }
    ctx->pc = 0x136BECu;
    // 0x136bec: 0x0  nop
    ctx->pc = 0x136becu;
    // NOP
label_136bf0:
    // 0x136bf0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x136BF0u;
    SET_GPR_U32(ctx, 31, 0x136BF8u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136BF8u; }
        if (ctx->pc != 0x136BF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136BF8u; }
        if (ctx->pc != 0x136BF8u) { return; }
    }
    ctx->pc = 0x136BF8u;
label_136bf8:
    // 0x136bf8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x136bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x136bfc: 0xafb00000  sw          $s0, 0x0($sp)
    ctx->pc = 0x136bfcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 16));
    // 0x136c00: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136c00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136c04: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x136c04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x136c08: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x136c08u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136c0c: 0x8e230060  lw          $v1, 0x60($s1)
    ctx->pc = 0x136c0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 96)));
    // 0x136c10: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x136C10u;
    {
        const bool branch_taken_0x136c10 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x136C14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136C10u;
            // 0x136c14: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136c10) {
            ctx->pc = 0x136C20u;
            goto label_136c20;
        }
    }
    ctx->pc = 0x136C18u;
    // 0x136c18: 0x60f809  jalr        $v1
    ctx->pc = 0x136C18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x136C20u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x136C20u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136C20u; }
            if (ctx->pc != 0x136C20u) { return; }
        }
        }
    }
    ctx->pc = 0x136C20u;
label_136c20:
    // 0x136c20: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x136c20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x136c24: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x136c24u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x136c28: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x136c28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x136c2c: 0x3e00008  jr          $ra
    ctx->pc = 0x136C2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136C30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136C2Cu;
            // 0x136c30: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136C34u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
