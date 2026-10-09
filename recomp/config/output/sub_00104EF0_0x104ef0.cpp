#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00104EF0
// Address: 0x104ef0 - 0x1050b0
void sub_00104EF0_0x104ef0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00104EF0_0x104ef0");
#endif

    switch (ctx->pc) {
        case 0x104f38u: goto label_104f38;
        case 0x104f50u: goto label_104f50;
        case 0x104f5cu: goto label_104f5c;
        case 0x104f88u: goto label_104f88;
        case 0x104ff8u: goto label_104ff8;
        case 0x10501cu: goto label_10501c;
        case 0x105034u: goto label_105034;
        case 0x10505cu: goto label_10505c;
        case 0x105078u: goto label_105078;
        case 0x105090u: goto label_105090;
        default: break;
    }

    ctx->pc = 0x104ef0u;

    // 0x104ef0: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x104ef0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x104ef4: 0x3e00008  jr          $ra
    ctx->pc = 0x104EF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x104EF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104EF4u;
            // 0x104ef8: 0x8c6297f0  lw          $v0, -0x6810($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294940656)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x104F38u: goto label_104f38;
            case 0x104F50u: goto label_104f50;
            case 0x104F5Cu: goto label_104f5c;
            case 0x104F64u: goto label_104f64;
            case 0x104F70u: goto label_104f70;
            case 0x104F88u: goto label_104f88;
            case 0x104F8Cu: goto label_104f8c;
            case 0x104FE8u: goto label_104fe8;
            case 0x104FF8u: goto label_104ff8;
            case 0x104FFCu: goto label_104ffc;
            case 0x10501Cu: goto label_10501c;
            case 0x105020u: goto label_105020;
            case 0x105034u: goto label_105034;
            case 0x105044u: goto label_105044;
            case 0x10505Cu: goto label_10505c;
            case 0x105060u: goto label_105060;
            case 0x105078u: goto label_105078;
            case 0x10507Cu: goto label_10507c;
            case 0x105090u: goto label_105090;
            case 0x105098u: goto label_105098;
            case 0x10509Cu: goto label_10509c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x104EFCu;
    // 0x104efc: 0x0  nop
    ctx->pc = 0x104efcu;
    // NOP
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
            case 0x104FE8u: goto label_104fe8;
            case 0x104FF8u: goto label_104ff8;
            case 0x104FFCu: goto label_104ffc;
            case 0x10501Cu: goto label_10501c;
            case 0x105020u: goto label_105020;
            case 0x105034u: goto label_105034;
            case 0x105044u: goto label_105044;
            case 0x10505Cu: goto label_10505c;
            case 0x105060u: goto label_105060;
            case 0x105078u: goto label_105078;
            case 0x10507Cu: goto label_10507c;
            case 0x105090u: goto label_105090;
            case 0x105098u: goto label_105098;
            case 0x10509Cu: goto label_10509c;
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
            case 0x104FE8u: goto label_104fe8;
            case 0x104FF8u: goto label_104ff8;
            case 0x104FFCu: goto label_104ffc;
            case 0x10501Cu: goto label_10501c;
            case 0x105020u: goto label_105020;
            case 0x105034u: goto label_105034;
            case 0x105044u: goto label_105044;
            case 0x10505Cu: goto label_10505c;
            case 0x105060u: goto label_105060;
            case 0x105078u: goto label_105078;
            case 0x10507Cu: goto label_10507c;
            case 0x105090u: goto label_105090;
            case 0x105098u: goto label_105098;
            case 0x10509Cu: goto label_10509c;
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
    // 0x104fac: 0x0  nop
    ctx->pc = 0x104facu;
    // NOP
    // 0x104fb0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x104fb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x104fb4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x104fb4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104fb8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x104fb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x104fbc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x104fbcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104fc0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x104fc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x104fc4: 0x12000035  beqz        $s0, . + 4 + (0x35 << 2)
    ctx->pc = 0x104FC4u;
    {
        const bool branch_taken_0x104fc4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x104FC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104FC4u;
            // 0x104fc8: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104fc4) {
            ctx->pc = 0x10509Cu;
            goto label_10509c;
        }
    }
    ctx->pc = 0x104FCCu;
    // 0x104fcc: 0x8e030054  lw          $v1, 0x54($s0)
    ctx->pc = 0x104fccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x104fd0: 0x54600005  bnel        $v1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x104FD0u;
    {
        const bool branch_taken_0x104fd0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x104fd0) {
            ctx->pc = 0x104FD4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104FD0u;
            // 0x104fd4: 0x8c620038  lw          $v0, 0x38($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104FE8u;
            goto label_104fe8;
        }
    }
    ctx->pc = 0x104FD8u;
    // 0x104fd8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x104fd8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x104fdc: 0x8c4397f0  lw          $v1, -0x6810($v0)
    ctx->pc = 0x104fdcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x104fe0: 0xae030054  sw          $v1, 0x54($s0)
    ctx->pc = 0x104fe0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 3));
    // 0x104fe4: 0x8c620038  lw          $v0, 0x38($v1)
    ctx->pc = 0x104fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 56)));
label_104fe8:
    // 0x104fe8: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x104FE8u;
    {
        const bool branch_taken_0x104fe8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x104fe8) {
            ctx->pc = 0x104FECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104FE8u;
            // 0x104fec: 0x8603000c  lh          $v1, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104FFCu;
            goto label_104ffc;
        }
    }
    ctx->pc = 0x104FF0u;
    // 0x104ff0: 0xc041544  jal         func_105510
    ctx->pc = 0x104FF0u;
    SET_GPR_U32(ctx, 31, 0x104FF8u);
    ctx->pc = 0x104FF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104FF0u;
            // 0x104ff4: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x105510u;
    if (runtime->hasFunction(0x105510u)) {
        auto targetFn = runtime->lookupFunction(0x105510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104FF8u; }
        if (ctx->pc != 0x104FF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00105510_0x105510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104FF8u; }
        if (ctx->pc != 0x104FF8u) { return; }
    }
    ctx->pc = 0x104FF8u;
label_104ff8:
    // 0x104ff8: 0x8603000c  lh          $v1, 0xC($s0)
    ctx->pc = 0x104ff8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
label_104ffc:
    // 0x104ffc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x104ffcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105000: 0x10600026  beqz        $v1, . + 4 + (0x26 << 2)
    ctx->pc = 0x105000u;
    {
        const bool branch_taken_0x105000 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x105004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105000u;
            // 0x105004: 0x9604000c  lhu         $a0, 0xC($s0) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105000) {
            ctx->pc = 0x10509Cu;
            goto label_10509c;
        }
    }
    ctx->pc = 0x105008u;
    // 0x105008: 0x30820008  andi        $v0, $a0, 0x8
    ctx->pc = 0x105008u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)8);
    // 0x10500c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10500Cu;
    {
        const bool branch_taken_0x10500c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x105010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10500Cu;
            // 0x105010: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10500c) {
            ctx->pc = 0x105020u;
            goto label_105020;
        }
    }
    ctx->pc = 0x105014u;
    // 0x105014: 0xc04142c  jal         func_1050B0
    ctx->pc = 0x105014u;
    SET_GPR_U32(ctx, 31, 0x10501Cu);
    ctx->pc = 0x105018u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105014u;
            // 0x105018: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1050B0u;
    if (runtime->hasFunction(0x1050B0u)) {
        auto targetFn = runtime->lookupFunction(0x1050B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10501Cu; }
        if (ctx->pc != 0x10501Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001050B0_0x1050b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10501Cu; }
        if (ctx->pc != 0x10501Cu) { return; }
    }
    ctx->pc = 0x10501Cu;
label_10501c:
    // 0x10501c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x10501cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_105020:
    // 0x105020: 0x8e02002c  lw          $v0, 0x2C($s0)
    ctx->pc = 0x105020u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x105024: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x105024u;
    {
        const bool branch_taken_0x105024 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x105024) {
            ctx->pc = 0x105028u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105024u;
            // 0x105028: 0x9602000c  lhu         $v0, 0xC($s0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x105044u;
            goto label_105044;
        }
    }
    ctx->pc = 0x10502Cu;
    // 0x10502c: 0x40f809  jalr        $v0
    ctx->pc = 0x10502Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x105034u);
        ctx->pc = 0x105030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10502Cu;
            // 0x105030: 0x8e04001c  lw          $a0, 0x1C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x105034u;
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
            case 0x104FE8u: goto label_104fe8;
            case 0x104FF8u: goto label_104ff8;
            case 0x104FFCu: goto label_104ffc;
            case 0x10501Cu: goto label_10501c;
            case 0x105020u: goto label_105020;
            case 0x105034u: goto label_105034;
            case 0x105044u: goto label_105044;
            case 0x10505Cu: goto label_10505c;
            case 0x105060u: goto label_105060;
            case 0x105078u: goto label_105078;
            case 0x10507Cu: goto label_10507c;
            case 0x105090u: goto label_105090;
            case 0x105098u: goto label_105098;
            case 0x10509Cu: goto label_10509c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x105034u; }
            if (ctx->pc != 0x105034u) { return; }
        }
        }
    }
    ctx->pc = 0x105034u;
label_105034:
    // 0x105034: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x105034u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x105038: 0x28420000  slti        $v0, $v0, 0x0
    ctx->pc = 0x105038u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x10503c: 0x62880b  movn        $s1, $v1, $v0
    ctx->pc = 0x10503cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 3));
    // 0x105040: 0x9602000c  lhu         $v0, 0xC($s0)
    ctx->pc = 0x105040u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
label_105044:
    // 0x105044: 0x30420080  andi        $v0, $v0, 0x80
    ctx->pc = 0x105044u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x105048: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x105048u;
    {
        const bool branch_taken_0x105048 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x105048) {
            ctx->pc = 0x10504Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105048u;
            // 0x10504c: 0x8e050030  lw          $a1, 0x30($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x105060u;
            goto label_105060;
        }
    }
    ctx->pc = 0x105050u;
    // 0x105050: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x105050u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x105054: 0xc041636  jal         func_1058D8
    ctx->pc = 0x105054u;
    SET_GPR_U32(ctx, 31, 0x10505Cu);
    ctx->pc = 0x105058u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105054u;
            // 0x105058: 0x8e050010  lw          $a1, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1058D8u;
    if (runtime->hasFunction(0x1058D8u)) {
        auto targetFn = runtime->lookupFunction(0x1058D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10505Cu; }
        if (ctx->pc != 0x10505Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001058D8_0x1058d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10505Cu; }
        if (ctx->pc != 0x10505Cu) { return; }
    }
    ctx->pc = 0x10505Cu;
label_10505c:
    // 0x10505c: 0x8e050030  lw          $a1, 0x30($s0)
    ctx->pc = 0x10505cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
label_105060:
    // 0x105060: 0x10a00006  beqz        $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x105060u;
    {
        const bool branch_taken_0x105060 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x105064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105060u;
            // 0x105064: 0x26020040  addiu       $v0, $s0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105060) {
            ctx->pc = 0x10507Cu;
            goto label_10507c;
        }
    }
    ctx->pc = 0x105068u;
    // 0x105068: 0x50a20004  beql        $a1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x105068u;
    {
        const bool branch_taken_0x105068 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x105068) {
            ctx->pc = 0x10506Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105068u;
            // 0x10506c: 0xae000030  sw          $zero, 0x30($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10507Cu;
            goto label_10507c;
        }
    }
    ctx->pc = 0x105070u;
    // 0x105070: 0xc041636  jal         func_1058D8
    ctx->pc = 0x105070u;
    SET_GPR_U32(ctx, 31, 0x105078u);
    ctx->pc = 0x105074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105070u;
            // 0x105074: 0x8e040054  lw          $a0, 0x54($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1058D8u;
    if (runtime->hasFunction(0x1058D8u)) {
        auto targetFn = runtime->lookupFunction(0x1058D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105078u; }
        if (ctx->pc != 0x105078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001058D8_0x1058d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105078u; }
        if (ctx->pc != 0x105078u) { return; }
    }
    ctx->pc = 0x105078u;
label_105078:
    // 0x105078: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x105078u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
label_10507c:
    // 0x10507c: 0x8e050044  lw          $a1, 0x44($s0)
    ctx->pc = 0x10507cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x105080: 0x50a00005  beql        $a1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x105080u;
    {
        const bool branch_taken_0x105080 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x105080) {
            ctx->pc = 0x105084u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105080u;
            // 0x105084: 0xa600000c  sh          $zero, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x105098u;
            goto label_105098;
        }
    }
    ctx->pc = 0x105088u;
    // 0x105088: 0xc041636  jal         func_1058D8
    ctx->pc = 0x105088u;
    SET_GPR_U32(ctx, 31, 0x105090u);
    ctx->pc = 0x10508Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105088u;
            // 0x10508c: 0x8e040054  lw          $a0, 0x54($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1058D8u;
    if (runtime->hasFunction(0x1058D8u)) {
        auto targetFn = runtime->lookupFunction(0x1058D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105090u; }
        if (ctx->pc != 0x105090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001058D8_0x1058d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105090u; }
        if (ctx->pc != 0x105090u) { return; }
    }
    ctx->pc = 0x105090u;
label_105090:
    // 0x105090: 0xae000044  sw          $zero, 0x44($s0)
    ctx->pc = 0x105090u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 0));
    // 0x105094: 0xa600000c  sh          $zero, 0xC($s0)
    ctx->pc = 0x105094u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 0));
label_105098:
    // 0x105098: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x105098u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_10509c:
    // 0x10509c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10509cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1050a0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1050a0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1050a4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1050a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1050a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1050A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1050ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1050A8u;
            // 0x1050ac: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x104F38u: goto label_104f38;
            case 0x104F50u: goto label_104f50;
            case 0x104F5Cu: goto label_104f5c;
            case 0x104F64u: goto label_104f64;
            case 0x104F70u: goto label_104f70;
            case 0x104F88u: goto label_104f88;
            case 0x104F8Cu: goto label_104f8c;
            case 0x104FE8u: goto label_104fe8;
            case 0x104FF8u: goto label_104ff8;
            case 0x104FFCu: goto label_104ffc;
            case 0x10501Cu: goto label_10501c;
            case 0x105020u: goto label_105020;
            case 0x105034u: goto label_105034;
            case 0x105044u: goto label_105044;
            case 0x10505Cu: goto label_10505c;
            case 0x105060u: goto label_105060;
            case 0x105078u: goto label_105078;
            case 0x10507Cu: goto label_10507c;
            case 0x105090u: goto label_105090;
            case 0x105098u: goto label_105098;
            case 0x10509Cu: goto label_10509c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1050B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
