#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00104F00
// Address: 0x104f00 - 0x104fac
void sub_00104F00_0x104f00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00104F00_0x104f00");
#endif

    switch (ctx->pc) {
        case 0x104f38u: goto label_104f38;
        case 0x104f50u: goto label_104f50;
        case 0x104f5cu: goto label_104f5c;
        case 0x104f88u: goto label_104f88;
        default: break;
    }

    ctx->pc = 0x104f00u;

    // 0x104f00: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x104f00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x104f04: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x104f04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x104f08: 0x3c140021  lui         $s4, 0x21
    ctx->pc = 0x104f08u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)33 << 16));
    // 0x104f0c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x104f0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x104f10: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x104f10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x104f14: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x104f14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x104f18: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x104f18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x104f1c: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x104f1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x104f20: 0x8e8297f0  lw          $v0, -0x6810($s4)
    ctx->pc = 0x104f20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4294940656)));
    // 0x104f24: 0x8c520148  lw          $s2, 0x148($v0)
    ctx->pc = 0x104f24u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 328)));
    // 0x104f28: 0x12400011  beqz        $s2, . + 4 + (0x11 << 2)
    ctx->pc = 0x104F28u;
    {
        const bool branch_taken_0x104f28 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x104F2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104F28u;
            // 0x104f2c: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104f28) {
            ctx->pc = 0x104F70u;
            goto label_104f70;
        }
    }
    ctx->pc = 0x104F30u;
    // 0x104f30: 0x8e500004  lw          $s0, 0x4($s2)
    ctx->pc = 0x104f30u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x104f34: 0x0  nop
    ctx->pc = 0x104f34u;
    // NOP
label_104f38:
    // 0x104f38: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x104f38u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x104f3c: 0x6000009  bltz        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x104F3Cu;
    {
        const bool branch_taken_0x104f3c = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x104F40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104F3Cu;
            // 0x104f40: 0x26430008  addiu       $v1, $s2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104f3c) {
            ctx->pc = 0x104F64u;
            goto label_104f64;
        }
    }
    ctx->pc = 0x104F44u;
    // 0x104f44: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x104f44u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x104f48: 0x438821  addu        $s1, $v0, $v1
    ctx->pc = 0x104f48u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x104f4c: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x104f4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_104f50:
    // 0x104f50: 0x2631fffc  addiu       $s1, $s1, -0x4
    ctx->pc = 0x104f50u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967292));
    // 0x104f54: 0x40f809  jalr        $v0
    ctx->pc = 0x104F54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x104F5Cu);
        ctx->pc = 0x104F58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104F54u;
            // 0x104f58: 0x2610ffff  addiu       $s0, $s0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x104F5Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x104F38u: goto label_104f38;
            case 0x104F50u: goto label_104f50;
            case 0x104F5Cu: goto label_104f5c;
            case 0x104F64u: goto label_104f64;
            case 0x104F70u: goto label_104f70;
            case 0x104F88u: goto label_104f88;
            case 0x104F8Cu: goto label_104f8c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x104F5Cu; }
            if (ctx->pc != 0x104F5Cu) { return; }
        }
        }
    }
    ctx->pc = 0x104F5Cu;
label_104f5c:
    // 0x104f5c: 0x603fffc  bgezl       $s0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x104F5Cu;
    {
        const bool branch_taken_0x104f5c = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x104f5c) {
            ctx->pc = 0x104F60u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104F5Cu;
            // 0x104f60: 0x8e220000  lw          $v0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104F50u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_104f50;
        }
    }
    ctx->pc = 0x104F64u;
label_104f64:
    // 0x104f64: 0x8e520000  lw          $s2, 0x0($s2)
    ctx->pc = 0x104f64u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x104f68: 0x5640fff3  bnel        $s2, $zero, . + 4 + (-0xD << 2)
    ctx->pc = 0x104F68u;
    {
        const bool branch_taken_0x104f68 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x104f68) {
            ctx->pc = 0x104F6Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104F68u;
            // 0x104f6c: 0x8e500004  lw          $s0, 0x4($s2) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104F38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_104f38;
        }
    }
    ctx->pc = 0x104F70u;
label_104f70:
    // 0x104f70: 0x8e8497f0  lw          $a0, -0x6810($s4)
    ctx->pc = 0x104f70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4294940656)));
    // 0x104f74: 0x8c82003c  lw          $v0, 0x3C($a0)
    ctx->pc = 0x104f74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x104f78: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x104F78u;
    {
        const bool branch_taken_0x104f78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x104f78) {
            ctx->pc = 0x104F7Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104F78u;
            // 0x104f7c: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104F8Cu;
            goto label_104f8c;
        }
    }
    ctx->pc = 0x104F80u;
    // 0x104f80: 0x40f809  jalr        $v0
    ctx->pc = 0x104F80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x104F88u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x104F88u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x104F38u: goto label_104f38;
            case 0x104F50u: goto label_104f50;
            case 0x104F5Cu: goto label_104f5c;
            case 0x104F64u: goto label_104f64;
            case 0x104F70u: goto label_104f70;
            case 0x104F88u: goto label_104f88;
            case 0x104F8Cu: goto label_104f8c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x104F88u; }
            if (ctx->pc != 0x104F88u) { return; }
        }
        }
    }
    ctx->pc = 0x104F88u;
label_104f88:
    // 0x104f88: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x104f88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_104f8c:
    // 0x104f8c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x104f8cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x104f90: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x104f90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x104f94: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x104f94u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x104f98: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x104f98u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x104f9c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x104f9cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x104fa0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x104fa0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x104fa4: 0x8040086  j           func_100218
    ctx->pc = 0x104FA4u;
    ctx->pc = 0x104FA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104FA4u;
            // 0x104fa8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100218u;
    if (runtime->hasFunction(0x100218u)) {
        auto targetFn = runtime->lookupFunction(0x100218u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00100218_0x100218(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x104FACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
