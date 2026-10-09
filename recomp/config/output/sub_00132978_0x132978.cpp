#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132978
// Address: 0x132978 - 0x132a08
void sub_00132978_0x132978(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132978_0x132978");
#endif

    switch (ctx->pc) {
        case 0x1329c0u: goto label_1329c0;
        case 0x1329e4u: goto label_1329e4;
        default: break;
    }

    ctx->pc = 0x132978u;

    // 0x132978: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132978u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13297c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13297Cu;
    {
        const bool branch_taken_0x13297c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13297Cu;
            // 0x132980: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13297c) {
            ctx->pc = 0x132998u;
            goto label_132998;
        }
    }
    ctx->pc = 0x132984u;
    // 0x132984: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132984u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132988: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132988u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13298c: 0x2484b238  addiu       $a0, $a0, -0x4DC8
    ctx->pc = 0x13298cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947384));
    // 0x132990: 0x804a034  j           func_1280D0
    ctx->pc = 0x132990u;
    ctx->pc = 0x132994u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132990u;
            // 0x132994: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x132998u;
label_132998:
    // 0x132998: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132998u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13299c: 0xa485003e  sh          $a1, 0x3E($a0)
    ctx->pc = 0x13299cu;
    WRITE16(ADD32(GPR_U32(ctx, 4), 62), (uint16_t)GPR_U32(ctx, 5));
    // 0x1329a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1329A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1329A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1329A0u;
            // 0x1329a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132998u: goto label_132998;
            case 0x1329C0u: goto label_1329c0;
            case 0x1329C8u: goto label_1329c8;
            case 0x1329E4u: goto label_1329e4;
            case 0x1329F8u: goto label_1329f8;
            case 0x1329FCu: goto label_1329fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1329A8u;
    // 0x1329a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1329a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1329ac: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1329ACu;
    {
        const bool branch_taken_0x1329ac = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1329B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1329ACu;
            // 0x1329b0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1329ac) {
            ctx->pc = 0x1329C8u;
            goto label_1329c8;
        }
    }
    ctx->pc = 0x1329B4u;
    // 0x1329b4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1329b4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1329b8: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x1329B8u;
    SET_GPR_U32(ctx, 31, 0x1329C0u);
    ctx->pc = 0x1329BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1329B8u;
            // 0x1329bc: 0x2484b268  addiu       $a0, $a0, -0x4D98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947432));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1329C0u; }
        if (ctx->pc != 0x1329C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1329C0u; }
        if (ctx->pc != 0x1329C0u) { return; }
    }
    ctx->pc = 0x1329C0u;
label_1329c0:
    // 0x1329c0: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1329C0u;
    {
        const bool branch_taken_0x1329c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1329C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1329C0u;
            // 0x1329c4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1329c0) {
            ctx->pc = 0x1329FCu;
            goto label_1329fc;
        }
    }
    ctx->pc = 0x1329C8u;
label_1329c8:
    // 0x1329c8: 0x8c830014  lw          $v1, 0x14($a0)
    ctx->pc = 0x1329c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1329cc: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1329CCu;
    {
        const bool branch_taken_0x1329cc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1329D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1329CCu;
            // 0x1329d0: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1329cc) {
            ctx->pc = 0x1329F8u;
            goto label_1329f8;
        }
    }
    ctx->pc = 0x1329D4u;
    // 0x1329d4: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1329d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1329d8: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x1329d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x1329dc: 0x40f809  jalr        $v0
    ctx->pc = 0x1329DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1329E4u);
        ctx->pc = 0x1329E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1329DCu;
            // 0x1329e0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1329E4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132998u: goto label_132998;
            case 0x1329C0u: goto label_1329c0;
            case 0x1329C8u: goto label_1329c8;
            case 0x1329E4u: goto label_1329e4;
            case 0x1329F8u: goto label_1329f8;
            case 0x1329FCu: goto label_1329fc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1329E4u; }
            if (ctx->pc != 0x1329E4u) { return; }
        }
        }
    }
    ctx->pc = 0x1329E4u;
label_1329e4:
    // 0x1329e4: 0x244407ff  addiu       $a0, $v0, 0x7FF
    ctx->pc = 0x1329e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 2047));
    // 0x1329e8: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x1329e8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1329ec: 0x83100b  movn        $v0, $a0, $v1
    ctx->pc = 0x1329ecu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x1329f0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1329F0u;
    {
        const bool branch_taken_0x1329f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1329F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1329F0u;
            // 0x1329f4: 0x212c3  sra         $v0, $v0, 11 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1329f0) {
            ctx->pc = 0x1329FCu;
            goto label_1329fc;
        }
    }
    ctx->pc = 0x1329F8u;
label_1329f8:
    // 0x1329f8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1329f8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1329fc:
    // 0x1329fc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1329fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132a00: 0x3e00008  jr          $ra
    ctx->pc = 0x132A00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132A04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132A00u;
            // 0x132a04: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132998u: goto label_132998;
            case 0x1329C0u: goto label_1329c0;
            case 0x1329C8u: goto label_1329c8;
            case 0x1329E4u: goto label_1329e4;
            case 0x1329F8u: goto label_1329f8;
            case 0x1329FCu: goto label_1329fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132A08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
