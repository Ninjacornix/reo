#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135560
// Address: 0x135560 - 0x1355f8
void sub_00135560_0x135560(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135560_0x135560");
#endif

    switch (ctx->pc) {
        case 0x13558cu: goto label_13558c;
        case 0x1355a0u: goto label_1355a0;
        case 0x1355b4u: goto label_1355b4;
        default: break;
    }

    ctx->pc = 0x135560u;

    // 0x135560: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x135560u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x135564: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x135564u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x135568: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x135568u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13556c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13556cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x135570: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x135570u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x135574: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x135574u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x135578: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x135578u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x13557c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13557cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x135580: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x135580u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x135584: 0xc042c56  jal         func_10B158
    ctx->pc = 0x135584u;
    SET_GPR_U32(ctx, 31, 0x13558Cu);
    ctx->pc = 0x135588u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135584u;
            // 0x135588: 0x80a02d  daddu       $s4, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13558Cu; }
        if (ctx->pc != 0x13558Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13558Cu; }
        if (ctx->pc != 0x13558Cu) { return; }
    }
    ctx->pc = 0x13558Cu;
label_13558c:
    // 0x13558c: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x13558cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135590: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x135590u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x135594: 0x2452206c  addiu       $s2, $v0, 0x206C
    ctx->pc = 0x135594u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), 8300));
    // 0x135598: 0x2655fffc  addiu       $s5, $s2, -0x4
    ctx->pc = 0x135598u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967292));
    // 0x13559c: 0x118100  sll         $s0, $s1, 4
    ctx->pc = 0x13559cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
label_1355a0:
    // 0x1355a0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1355a0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1355a4: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1355a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1355a8: 0x2122821  addu        $a1, $s0, $s2
    ctx->pc = 0x1355a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
    // 0x1355ac: 0xc042d10  jal         func_10B440
    ctx->pc = 0x1355ACu;
    SET_GPR_U32(ctx, 31, 0x1355B4u);
    ctx->pc = 0x1355B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1355ACu;
            // 0x1355b0: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1355B4u; }
        if (ctx->pc != 0x1355B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1355B4u; }
        if (ctx->pc != 0x1355B4u) { return; }
    }
    ctx->pc = 0x1355B4u;
label_1355b4:
    // 0x1355b4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1355B4u;
    {
        const bool branch_taken_0x1355b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1355B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1355B4u;
            // 0x1355b8: 0x2e230020  sltiu       $v1, $s1, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1355b4) {
            ctx->pc = 0x1355C8u;
            goto label_1355c8;
        }
    }
    ctx->pc = 0x1355BCu;
    // 0x1355bc: 0x2151821  addu        $v1, $s0, $s5
    ctx->pc = 0x1355bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 21)));
    // 0x1355c0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1355C0u;
    {
        const bool branch_taken_0x1355c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1355C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1355C0u;
            // 0x1355c4: 0x8c620000  lw          $v0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1355c0) {
            ctx->pc = 0x1355D4u;
            goto label_1355d4;
        }
    }
    ctx->pc = 0x1355C8u;
label_1355c8:
    // 0x1355c8: 0x1460fff5  bnez        $v1, . + 4 + (-0xB << 2)
    ctx->pc = 0x1355C8u;
    {
        const bool branch_taken_0x1355c8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1355CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1355C8u;
            // 0x1355cc: 0x118100  sll         $s0, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1355c8) {
            ctx->pc = 0x1355A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1355a0;
        }
    }
    ctx->pc = 0x1355D0u;
    // 0x1355d0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1355d0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1355d4:
    // 0x1355d4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1355d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1355d8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1355d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1355dc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1355dcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1355e0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1355e0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1355e4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1355e4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1355e8: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1355e8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1355ec: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1355ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1355f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1355F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1355F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1355F0u;
            // 0x1355f4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13558Cu: goto label_13558c;
            case 0x1355A0u: goto label_1355a0;
            case 0x1355B4u: goto label_1355b4;
            case 0x1355C8u: goto label_1355c8;
            case 0x1355D4u: goto label_1355d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1355F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
