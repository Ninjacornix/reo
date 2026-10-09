#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141640
// Address: 0x141640 - 0x1416cc
void sub_00141640_0x141640(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141640_0x141640");
#endif

    switch (ctx->pc) {
        case 0x1416a4u: goto label_1416a4;
        case 0x1416b8u: goto label_1416b8;
        default: break;
    }

    ctx->pc = 0x141640u;

    // 0x141640: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x141640u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x141644: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x141644u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141648: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x141648u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x14164c: 0x3c110026  lui         $s1, 0x26
    ctx->pc = 0x14164cu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)38 << 16));
    // 0x141650: 0x8e2249e8  lw          $v0, 0x49E8($s1)
    ctx->pc = 0x141650u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 18920)));
    // 0x141654: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x141654u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x141658: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x141658u;
    {
        const bool branch_taken_0x141658 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x14165Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141658u;
            // 0x14165c: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141658) {
            ctx->pc = 0x1416B8u;
            goto label_1416b8;
        }
    }
    ctx->pc = 0x141660u;
    // 0x141660: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x141660u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x141664: 0x2442a5f0  addiu       $v0, $v0, -0x5A10
    ctx->pc = 0x141664u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294944240));
    // 0x141668: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x141668u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14166c: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x14166cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x141670: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x141670u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x141674: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x141674u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x141678: 0x1480000c  bnez        $a0, . + 4 + (0xC << 2)
    ctx->pc = 0x141678u;
    {
        const bool branch_taken_0x141678 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x14167Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141678u;
            // 0x14167c: 0x262349e8  addiu       $v1, $s1, 0x49E8 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 18920));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141678) {
            ctx->pc = 0x1416ACu;
            goto label_1416ac;
        }
    }
    ctx->pc = 0x141680u;
    // 0x141680: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x141680u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x141684: 0x2450a5f4  addiu       $s0, $v0, -0x5A0C
    ctx->pc = 0x141684u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294944244));
    // 0x141688: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x141688u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x14168c: 0x10660005  beq         $v1, $a2, . + 4 + (0x5 << 2)
    ctx->pc = 0x14168Cu;
    {
        const bool branch_taken_0x14168c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 6));
        if (branch_taken_0x14168c) {
            ctx->pc = 0x1416A4u;
            goto label_1416a4;
        }
    }
    ctx->pc = 0x141694u;
    // 0x141694: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x141694u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x141698: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x141698u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x14169c: 0xc050600  jal         func_141800
    ctx->pc = 0x14169Cu;
    SET_GPR_U32(ctx, 31, 0x1416A4u);
    ctx->pc = 0x1416A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14169Cu;
            // 0x1416a0: 0x2484dba8  addiu       $a0, $a0, -0x2458 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957992));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141800u;
    if (runtime->hasFunction(0x141800u)) {
        auto targetFn = runtime->lookupFunction(0x141800u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1416A4u; }
        if (ctx->pc != 0x1416A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141800_0x141800(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1416A4u; }
        if (ctx->pc != 0x1416A4u) { return; }
    }
    ctx->pc = 0x1416A4u;
label_1416a4:
    // 0x1416a4: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1416a4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1416a8: 0x262349e8  addiu       $v1, $s1, 0x49E8
    ctx->pc = 0x1416a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 18920));
label_1416ac:
    // 0x1416ac: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1416acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1416b0: 0x40f809  jalr        $v0
    ctx->pc = 0x1416B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1416B8u);
        ctx->pc = 0x1416B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1416B0u;
            // 0x1416b4: 0x8c640004  lw          $a0, 0x4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1416B8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1416A4u: goto label_1416a4;
            case 0x1416ACu: goto label_1416ac;
            case 0x1416B8u: goto label_1416b8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1416B8u; }
            if (ctx->pc != 0x1416B8u) { return; }
        }
        }
    }
    ctx->pc = 0x1416B8u;
label_1416b8:
    // 0x1416b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1416b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1416bc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1416bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1416c0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1416c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1416c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1416C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1416C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1416C4u;
            // 0x1416c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1416A4u: goto label_1416a4;
            case 0x1416ACu: goto label_1416ac;
            case 0x1416B8u: goto label_1416b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1416CCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
