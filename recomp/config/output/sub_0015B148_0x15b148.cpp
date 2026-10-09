#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B148
// Address: 0x15b148 - 0x15b1c0
void sub_0015B148_0x15b148(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B148_0x15b148");
#endif

    switch (ctx->pc) {
        case 0x15b198u: goto label_15b198;
        case 0x15b1a4u: goto label_15b1a4;
        default: break;
    }

    ctx->pc = 0x15b148u;

    // 0x15b148: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x15b148u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x15b14c: 0x3c035a5a  lui         $v1, 0x5A5A
    ctx->pc = 0x15b14cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)23130 << 16));
    // 0x15b150: 0x8c44e650  lw          $a0, -0x19B0($v0)
    ctx->pc = 0x15b150u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294960720)));
    // 0x15b154: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15b154u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15b158: 0x34635a5a  ori         $v1, $v1, 0x5A5A
    ctx->pc = 0x15b158u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)23130);
    // 0x15b15c: 0x10830008  beq         $a0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x15B15Cu;
    {
        const bool branch_taken_0x15b15c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x15B160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B15Cu;
            // 0x15b160: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15b15c) {
            ctx->pc = 0x15B180u;
            goto label_15b180;
        }
    }
    ctx->pc = 0x15B164u;
    // 0x15b164: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x15b164u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x15b168: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15b168u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15b16c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x15b16cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b170: 0x34a5ff02  ori         $a1, $a1, 0xFF02
    ctx->pc = 0x15b170u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)65282);
    // 0x15b174: 0x80563ce  j           func_158F38
    ctx->pc = 0x15B174u;
    ctx->pc = 0x15B178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B174u;
            // 0x15b178: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158F38u;
    if (runtime->hasFunction(0x158F38u)) {
        auto targetFn = runtime->lookupFunction(0x158F38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00158F38_0x158f38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15B17Cu;
    // 0x15b17c: 0x0  nop
    ctx->pc = 0x15b17cu;
    // NOP
label_15b180:
    // 0x15b180: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x15b180u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x15b184: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x15b184u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x15b188: 0x9043e664  lbu         $v1, -0x199C($v0)
    ctx->pc = 0x15b188u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294960740)));
    // 0x15b18c: 0x10640008  beq         $v1, $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x15B18Cu;
    {
        const bool branch_taken_0x15b18c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x15B190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B18Cu;
            // 0x15b190: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15b18c) {
            ctx->pc = 0x15B1B0u;
            goto label_15b1b0;
        }
    }
    ctx->pc = 0x15B194u;
    // 0x15b194: 0x0  nop
    ctx->pc = 0x15b194u;
    // NOP
label_15b198:
    // 0x15b198: 0x2401ffff  addiu       $at, $zero, -0x1
    ctx->pc = 0x15b198u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x15b19c: 0x20f809  jalr        $at
    ctx->pc = 0x15B19Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 1);
        SET_GPR_U32(ctx, 31, 0x15B1A4u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x15B1A4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B180u: goto label_15b180;
            case 0x15B198u: goto label_15b198;
            case 0x15B1A4u: goto label_15b1a4;
            case 0x15B1B0u: goto label_15b1b0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15B1A4u; }
            if (ctx->pc != 0x15B1A4u) { return; }
        }
        }
    }
    ctx->pc = 0x15B1A4u;
label_15b1a4:
    // 0x15b1a4: 0x1000fffc  b           . + 4 + (-0x4 << 2)
    ctx->pc = 0x15B1A4u;
    {
        const bool branch_taken_0x15b1a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x15b1a4) {
            ctx->pc = 0x15B198u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15b198;
        }
    }
    ctx->pc = 0x15B1ACu;
    // 0x15b1ac: 0x0  nop
    ctx->pc = 0x15b1acu;
    // NOP
label_15b1b0:
    // 0x15b1b0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15b1b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b1b4: 0x3e00008  jr          $ra
    ctx->pc = 0x15B1B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15B1B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B1B4u;
            // 0x15b1b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B180u: goto label_15b180;
            case 0x15B198u: goto label_15b198;
            case 0x15B1A4u: goto label_15b1a4;
            case 0x15B1B0u: goto label_15b1b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15B1BCu;
    // 0x15b1bc: 0x0  nop
    ctx->pc = 0x15b1bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
