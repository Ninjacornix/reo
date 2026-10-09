#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013FA38
// Address: 0x13fa38 - 0x13fa84
void sub_0013FA38_0x13fa38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013FA38_0x13fa38");
#endif

    switch (ctx->pc) {
        case 0x13fa74u: goto label_13fa74;
        default: break;
    }

    ctx->pc = 0x13fa38u;

    // 0x13fa38: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13fa38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13fa3c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13fa3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13fa40: 0x14a20003  bne         $a1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13FA40u;
    {
        const bool branch_taken_0x13fa40 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x13FA44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FA40u;
            // 0x13fa44: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fa40) {
            ctx->pc = 0x13FA50u;
            goto label_13fa50;
        }
    }
    ctx->pc = 0x13FA48u;
    // 0x13fa48: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x13FA48u;
    {
        const bool branch_taken_0x13fa48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FA4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FA48u;
            // 0x13fa4c: 0x8c82000c  lw          $v0, 0xC($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fa48) {
            ctx->pc = 0x13FA78u;
            goto label_13fa78;
        }
    }
    ctx->pc = 0x13FA50u;
label_13fa50:
    // 0x13fa50: 0x54a00003  bnel        $a1, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x13FA50u;
    {
        const bool branch_taken_0x13fa50 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x13fa50) {
            ctx->pc = 0x13FA54u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FA50u;
            // 0x13fa54: 0x8c820038  lw          $v0, 0x38($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FA60u;
            goto label_13fa60;
        }
    }
    ctx->pc = 0x13FA58u;
    // 0x13fa58: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x13FA58u;
    {
        const bool branch_taken_0x13fa58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FA5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FA58u;
            // 0x13fa5c: 0x8c820010  lw          $v0, 0x10($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fa58) {
            ctx->pc = 0x13FA78u;
            goto label_13fa78;
        }
    }
    ctx->pc = 0x13FA60u;
label_13fa60:
    // 0x13fa60: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x13FA60u;
    {
        const bool branch_taken_0x13fa60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fa60) {
            ctx->pc = 0x13FA64u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FA60u;
            // 0x13fa64: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FA78u;
            goto label_13fa78;
        }
    }
    ctx->pc = 0x13FA68u;
    // 0x13fa68: 0x8c84003c  lw          $a0, 0x3C($a0)
    ctx->pc = 0x13fa68u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x13fa6c: 0x40f809  jalr        $v0
    ctx->pc = 0x13FA6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13FA74u);
        ctx->pc = 0x13FA70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FA6Cu;
            // 0x13fa70: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13FA74u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FA50u: goto label_13fa50;
            case 0x13FA60u: goto label_13fa60;
            case 0x13FA74u: goto label_13fa74;
            case 0x13FA78u: goto label_13fa78;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13FA74u; }
            if (ctx->pc != 0x13FA74u) { return; }
        }
        }
    }
    ctx->pc = 0x13FA74u;
label_13fa74:
    // 0x13fa74: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13fa74u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_13fa78:
    // 0x13fa78: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13fa78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13fa7c: 0x3e00008  jr          $ra
    ctx->pc = 0x13FA7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13FA80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FA7Cu;
            // 0x13fa80: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FA50u: goto label_13fa50;
            case 0x13FA60u: goto label_13fa60;
            case 0x13FA74u: goto label_13fa74;
            case 0x13FA78u: goto label_13fa78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13FA84u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
