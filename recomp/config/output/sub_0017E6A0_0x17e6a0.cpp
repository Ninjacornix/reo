#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E6A0
// Address: 0x17e6a0 - 0x17e768
void sub_0017E6A0_0x17e6a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E6A0_0x17e6a0");
#endif

    switch (ctx->pc) {
        case 0x17e6f8u: goto label_17e6f8;
        case 0x17e708u: goto label_17e708;
        case 0x17e720u: goto label_17e720;
        case 0x17e734u: goto label_17e734;
        default: break;
    }

    ctx->pc = 0x17e6a0u;

    // 0x17e6a0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17e6a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17e6a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17e6a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17e6a8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17e6a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e6ac: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17e6acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17e6b0: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x17e6b0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e6b4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x17e6b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x17e6b8: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x17e6b8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e6bc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17e6bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17e6c0: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x17e6c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x17e6c4: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x17e6c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x17e6c8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17e6c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17e6cc: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x17e6ccu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x17e6d0: 0x1200001c  beqz        $s0, . + 4 + (0x1C << 2)
    ctx->pc = 0x17E6D0u;
    {
        const bool branch_taken_0x17e6d0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E6D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E6D0u;
            // 0x17e6d4: 0xae600000  sw          $zero, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e6d0) {
            ctx->pc = 0x17E744u;
            goto label_17e744;
        }
    }
    ctx->pc = 0x17E6D8u;
    // 0x17e6d8: 0x58a0001b  blezl       $a1, . + 4 + (0x1B << 2)
    ctx->pc = 0x17E6D8u;
    {
        const bool branch_taken_0x17e6d8 = (GPR_S64(ctx, 5) <= 0);
        if (branch_taken_0x17e6d8) {
            ctx->pc = 0x17E6DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17E6D8u;
            // 0x17e6dc: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17E748u;
            goto label_17e748;
        }
    }
    ctx->pc = 0x17E6E0u;
    // 0x17e6e0: 0x58a00019  blezl       $a1, . + 4 + (0x19 << 2)
    ctx->pc = 0x17E6E0u;
    {
        const bool branch_taken_0x17e6e0 = (GPR_S64(ctx, 5) <= 0);
        if (branch_taken_0x17e6e0) {
            ctx->pc = 0x17E6E4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17E6E0u;
            // 0x17e6e4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17E748u;
            goto label_17e748;
        }
    }
    ctx->pc = 0x17E6E8u;
    // 0x17e6e8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17e6e8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e6ec: 0x3c150024  lui         $s5, 0x24
    ctx->pc = 0x17e6ecu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)36 << 16));
    // 0x17e6f0: 0x3c140024  lui         $s4, 0x24
    ctx->pc = 0x17e6f0u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)36 << 16));
    // 0x17e6f4: 0x0  nop
    ctx->pc = 0x17e6f4u;
    // NOP
label_17e6f8:
    // 0x17e6f8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17e6f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e6fc: 0x26a51578  addiu       $a1, $s5, 0x1578
    ctx->pc = 0x17e6fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), 5496));
    // 0x17e700: 0xc041e86  jal         func_107A18
    ctx->pc = 0x17E700u;
    SET_GPR_U32(ctx, 31, 0x17E708u);
    ctx->pc = 0x17E704u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E700u;
            // 0x17e704: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E708u; }
        if (ctx->pc != 0x17E708u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E708u; }
        if (ctx->pc != 0x17E708u) { return; }
    }
    ctx->pc = 0x17E708u;
label_17e708:
    // 0x17e708: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17e708u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e70c: 0x26851500  addiu       $a1, $s4, 0x1500
    ctx->pc = 0x17e70cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), 5376));
    // 0x17e710: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x17E710u;
    {
        const bool branch_taken_0x17e710 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x17E714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E710u;
            // 0x17e714: 0x24060008  addiu       $a2, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e710) {
            ctx->pc = 0x17E738u;
            goto label_17e738;
        }
    }
    ctx->pc = 0x17E718u;
    // 0x17e718: 0xc041e86  jal         func_107A18
    ctx->pc = 0x17E718u;
    SET_GPR_U32(ctx, 31, 0x17E720u);
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E720u; }
        if (ctx->pc != 0x17E720u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E720u; }
        if (ctx->pc != 0x17E720u) { return; }
    }
    ctx->pc = 0x17E720u;
label_17e720:
    // 0x17e720: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x17E720u;
    {
        const bool branch_taken_0x17e720 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17e720) {
            ctx->pc = 0x17E724u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17E720u;
            // 0x17e724: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17E73Cu;
            goto label_17e73c;
        }
    }
    ctx->pc = 0x17E728u;
    // 0x17e728: 0xae700000  sw          $s0, 0x0($s3)
    ctx->pc = 0x17e728u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 16));
    // 0x17e72c: 0xc05f9da  jal         func_17E768
    ctx->pc = 0x17E72Cu;
    SET_GPR_U32(ctx, 31, 0x17E734u);
    ctx->pc = 0x17E730u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E72Cu;
            // 0x17e730: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E768u;
    if (runtime->hasFunction(0x17E768u)) {
        auto targetFn = runtime->lookupFunction(0x17E768u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E734u; }
        if (ctx->pc != 0x17E734u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E768_0x17e768(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E734u; }
        if (ctx->pc != 0x17E734u) { return; }
    }
    ctx->pc = 0x17E734u;
label_17e734:
    // 0x17e734: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x17e734u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
label_17e738:
    // 0x17e738: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x17e738u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_17e73c:
    // 0x17e73c: 0x1620ffee  bnez        $s1, . + 4 + (-0x12 << 2)
    ctx->pc = 0x17E73Cu;
    {
        const bool branch_taken_0x17e73c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x17E740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E73Cu;
            // 0x17e740: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e73c) {
            ctx->pc = 0x17E6F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17e6f8;
        }
    }
    ctx->pc = 0x17E744u;
label_17e744:
    // 0x17e744: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17e744u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17e748:
    // 0x17e748: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17e748u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17e74c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17e74cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17e750: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17e750u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17e754: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x17e754u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17e758: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x17e758u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x17e75c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x17e75cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17e760: 0x3e00008  jr          $ra
    ctx->pc = 0x17E760u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E760u;
            // 0x17e764: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E6F8u: goto label_17e6f8;
            case 0x17E708u: goto label_17e708;
            case 0x17E720u: goto label_17e720;
            case 0x17E734u: goto label_17e734;
            case 0x17E738u: goto label_17e738;
            case 0x17E73Cu: goto label_17e73c;
            case 0x17E744u: goto label_17e744;
            case 0x17E748u: goto label_17e748;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E768u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
