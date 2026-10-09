#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001372B0
// Address: 0x1372b0 - 0x13730c
void sub_001372B0_0x1372b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001372B0_0x1372b0");
#endif

    switch (ctx->pc) {
        case 0x1372ccu: goto label_1372cc;
        case 0x1372f8u: goto label_1372f8;
        default: break;
    }

    ctx->pc = 0x1372b0u;

    // 0x1372b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1372b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1372b4: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x1372b4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1372b8: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1372B8u;
    {
        const bool branch_taken_0x1372b8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1372BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1372B8u;
            // 0x1372bc: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1372b8) {
            ctx->pc = 0x1372D8u;
            goto label_1372d8;
        }
    }
    ctx->pc = 0x1372C0u;
    // 0x1372c0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1372c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1372c4: 0xc04d480  jal         func_135200
    ctx->pc = 0x1372C4u;
    SET_GPR_U32(ctx, 31, 0x1372CCu);
    ctx->pc = 0x1372C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1372C4u;
            // 0x1372c8: 0x2484c400  addiu       $a0, $a0, -0x3C00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951936));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1372CCu; }
        if (ctx->pc != 0x1372CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1372CCu; }
        if (ctx->pc != 0x1372CCu) { return; }
    }
    ctx->pc = 0x1372CCu;
label_1372cc:
    // 0x1372cc: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1372CCu;
    {
        const bool branch_taken_0x1372cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1372D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1372CCu;
            // 0x1372d0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1372cc) {
            ctx->pc = 0x137300u;
            goto label_137300;
        }
    }
    ctx->pc = 0x1372D4u;
    // 0x1372d4: 0x0  nop
    ctx->pc = 0x1372d4u;
    // NOP
label_1372d8:
    // 0x1372d8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1372d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1372dc: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1372dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1372e0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1372E0u;
    {
        const bool branch_taken_0x1372e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1372E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1372E0u;
            // 0x1372e4: 0x2405012b  addiu       $a1, $zero, 0x12B (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 299));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1372e0) {
            ctx->pc = 0x1372FCu;
            goto label_1372fc;
        }
    }
    ctx->pc = 0x1372E8u;
    // 0x1372e8: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x1372e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1372ec: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1372ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1372f0: 0x40f809  jalr        $v0
    ctx->pc = 0x1372F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1372F8u);
        ctx->pc = 0x1372F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1372F0u;
            // 0x1372f4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1372F8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1372CCu: goto label_1372cc;
            case 0x1372D8u: goto label_1372d8;
            case 0x1372F8u: goto label_1372f8;
            case 0x1372FCu: goto label_1372fc;
            case 0x137300u: goto label_137300;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1372F8u; }
            if (ctx->pc != 0x1372F8u) { return; }
        }
        }
    }
    ctx->pc = 0x1372F8u;
label_1372f8:
    // 0x1372f8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1372f8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1372fc:
    // 0x1372fc: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1372fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_137300:
    // 0x137300: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x137300u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x137304: 0x3e00008  jr          $ra
    ctx->pc = 0x137304u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137308u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137304u;
            // 0x137308: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1372CCu: goto label_1372cc;
            case 0x1372D8u: goto label_1372d8;
            case 0x1372F8u: goto label_1372f8;
            case 0x1372FCu: goto label_1372fc;
            case 0x137300u: goto label_137300;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13730Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
