#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001353F8
// Address: 0x1353f8 - 0x135488
void sub_001353F8_0x1353f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001353F8_0x1353f8");
#endif

    switch (ctx->pc) {
        case 0x135448u: goto label_135448;
        case 0x13547cu: goto label_13547c;
        default: break;
    }

    ctx->pc = 0x1353f8u;

    // 0x1353f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1353f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1353fc: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1353fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x135400: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x135400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x135404: 0x2442bb78  addiu       $v0, $v0, -0x4488
    ctx->pc = 0x135404u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949752));
    // 0x135408: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x135408u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13540c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x13540cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x135410: 0x14800005  bnez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x135410u;
    {
        const bool branch_taken_0x135410 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x135414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135410u;
            // 0x135414: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135410) {
            ctx->pc = 0x135428u;
            goto label_135428;
        }
    }
    ctx->pc = 0x135418u;
    // 0x135418: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x135418u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13541c: 0x2484b7b0  addiu       $a0, $a0, -0x4850
    ctx->pc = 0x13541cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948784));
    // 0x135420: 0x804d480  j           func_135200
    ctx->pc = 0x135420u;
    ctx->pc = 0x135424u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135420u;
            // 0x135424: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135200_0x135200(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x135428u;
label_135428:
    // 0x135428: 0x14c00005  bnez        $a2, . + 4 + (0x5 << 2)
    ctx->pc = 0x135428u;
    {
        const bool branch_taken_0x135428 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        if (branch_taken_0x135428) {
            ctx->pc = 0x135440u;
            goto label_135440;
        }
    }
    ctx->pc = 0x135430u;
    // 0x135430: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x135430u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x135434: 0x2484b7d8  addiu       $a0, $a0, -0x4828
    ctx->pc = 0x135434u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948824));
    // 0x135438: 0x804d480  j           func_135200
    ctx->pc = 0x135438u;
    ctx->pc = 0x13543Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135438u;
            // 0x13543c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135200_0x135200(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x135440u;
label_135440:
    // 0x135440: 0xc04d522  jal         func_135488
    ctx->pc = 0x135440u;
    SET_GPR_U32(ctx, 31, 0x135448u);
    ctx->pc = 0x135488u;
    if (runtime->hasFunction(0x135488u)) {
        auto targetFn = runtime->lookupFunction(0x135488u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135448u; }
        if (ctx->pc != 0x135448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135488_0x135488(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135448u; }
        if (ctx->pc != 0x135448u) { return; }
    }
    ctx->pc = 0x135448u;
label_135448:
    // 0x135448: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x135448u;
    {
        const bool branch_taken_0x135448 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x135448) {
            ctx->pc = 0x13544Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x135448u;
            // 0x13544c: 0x8c420004  lw          $v0, 0x4($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x135468u;
            goto label_135468;
        }
    }
    ctx->pc = 0x135450u;
    // 0x135450: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x135450u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x135454: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x135454u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135458: 0x2484b800  addiu       $a0, $a0, -0x4800
    ctx->pc = 0x135458u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948864));
    // 0x13545c: 0x804d480  j           func_135200
    ctx->pc = 0x13545Cu;
    ctx->pc = 0x135460u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13545Cu;
            // 0x135460: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135200_0x135200(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x135464u;
    // 0x135464: 0x0  nop
    ctx->pc = 0x135464u;
    // NOP
label_135468:
    // 0x135468: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x135468u;
    {
        const bool branch_taken_0x135468 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13546Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135468u;
            // 0x13546c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135468) {
            ctx->pc = 0x13547Cu;
            goto label_13547c;
        }
    }
    ctx->pc = 0x135470u;
    // 0x135470: 0x3c040013  lui         $a0, 0x13
    ctx->pc = 0x135470u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)19 << 16));
    // 0x135474: 0x40f809  jalr        $v0
    ctx->pc = 0x135474u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13547Cu);
        ctx->pc = 0x135478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135474u;
            // 0x135478: 0x248451d0  addiu       $a0, $a0, 0x51D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20944));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13547Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135428u: goto label_135428;
            case 0x135440u: goto label_135440;
            case 0x135448u: goto label_135448;
            case 0x135468u: goto label_135468;
            case 0x13547Cu: goto label_13547c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13547Cu; }
            if (ctx->pc != 0x13547Cu) { return; }
        }
        }
    }
    ctx->pc = 0x13547Cu;
label_13547c:
    // 0x13547c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13547cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135480: 0x3e00008  jr          $ra
    ctx->pc = 0x135480u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135484u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135480u;
            // 0x135484: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135428u: goto label_135428;
            case 0x135440u: goto label_135440;
            case 0x135448u: goto label_135448;
            case 0x135468u: goto label_135468;
            case 0x13547Cu: goto label_13547c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x135488u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
