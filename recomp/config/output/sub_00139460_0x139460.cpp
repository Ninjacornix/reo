#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00139460
// Address: 0x139460 - 0x139568
void sub_00139460_0x139460(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00139460_0x139460");
#endif

    switch (ctx->pc) {
        case 0x139498u: goto label_139498;
        case 0x1394a8u: goto label_1394a8;
        case 0x139508u: goto label_139508;
        case 0x139518u: goto label_139518;
        case 0x139540u: goto label_139540;
        default: break;
    }

    ctx->pc = 0x139460u;

    // 0x139460: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x139460u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x139464: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x139464u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x139468: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x139468u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13946c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x13946cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x139470: 0x100882d  daddu       $s1, $t0, $zero
    ctx->pc = 0x139470u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139474: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x139474u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x139478: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x139478u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13947c: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x13947cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x139480: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x139480u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139484: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x139484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x139488: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x139488u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x13948c: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x13948cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x139490: 0xc0505b4  jal         func_1416D0
    ctx->pc = 0x139490u;
    SET_GPR_U32(ctx, 31, 0x139498u);
    ctx->pc = 0x139494u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139490u;
            // 0x139494: 0xe0a02d  daddu       $s4, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416D0u;
    if (runtime->hasFunction(0x1416D0u)) {
        auto targetFn = runtime->lookupFunction(0x1416D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139498u; }
        if (ctx->pc != 0x139498u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416D0_0x1416d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139498u; }
        if (ctx->pc != 0x139498u) { return; }
    }
    ctx->pc = 0x139498u;
label_139498:
    // 0x139498: 0x1a00000d  blez        $s0, . + 4 + (0xD << 2)
    ctx->pc = 0x139498u;
    {
        const bool branch_taken_0x139498 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x13949Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139498u;
            // 0x13949c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139498) {
            ctx->pc = 0x1394D0u;
            goto label_1394d0;
        }
    }
    ctx->pc = 0x1394A0u;
    // 0x1394a0: 0x3c070026  lui         $a3, 0x26
    ctx->pc = 0x1394a0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)38 << 16));
    // 0x1394a4: 0x24e823c0  addiu       $t0, $a3, 0x23C0
    ctx->pc = 0x1394a4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), 9152));
label_1394a8:
    // 0x1394a8: 0x61080  sll         $v0, $a2, 2
    ctx->pc = 0x1394a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1394ac: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1394acu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1394b0: 0x521821  addu        $v1, $v0, $s2
    ctx->pc = 0x1394b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1394b4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1394b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1394b8: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x1394b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1394bc: 0xd0282a  slt         $a1, $a2, $s0
    ctx->pc = 0x1394bcu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x1394c0: 0x14a0fff9  bnez        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1394C0u;
    {
        const bool branch_taken_0x1394c0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1394C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1394C0u;
            // 0x1394c4: 0xac440000  sw          $a0, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1394c0) {
            ctx->pc = 0x1394A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1394a8;
        }
    }
    ctx->pc = 0x1394C8u;
    // 0x1394c8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1394C8u;
    {
        const bool branch_taken_0x1394c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1394CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1394C8u;
            // 0x1394cc: 0x3c150026  lui         $s5, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1394c8) {
            ctx->pc = 0x1394D8u;
            goto label_1394d8;
        }
    }
    ctx->pc = 0x1394D0u;
label_1394d0:
    // 0x1394d0: 0x3c070026  lui         $a3, 0x26
    ctx->pc = 0x1394d0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)38 << 16));
    // 0x1394d4: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x1394d4u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
label_1394d8:
    // 0x1394d8: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x1394d8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x1394dc: 0x26b224c0  addiu       $s2, $s5, 0x24C0
    ctx->pc = 0x1394dcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 21), 9408));
    // 0x1394e0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1394e0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1394e4: 0x2484c870  addiu       $a0, $a0, -0x3790
    ctx->pc = 0x1394e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953072));
    // 0x1394e8: 0x26650400  addiu       $a1, $s3, 0x400
    ctx->pc = 0x1394e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 1024));
    // 0x1394ec: 0x24e723c0  addiu       $a3, $a3, 0x23C0
    ctx->pc = 0x1394ecu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 9152));
    // 0x1394f0: 0x104080  sll         $t0, $s0, 2
    ctx->pc = 0x1394f0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1394f4: 0x240482d  daddu       $t1, $s2, $zero
    ctx->pc = 0x1394f4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1394f8: 0x115080  sll         $t2, $s1, 2
    ctx->pc = 0x1394f8u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1394fc: 0x582d  daddu       $t3, $zero, $zero
    ctx->pc = 0x1394fcu;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139500: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x139500u;
    SET_GPR_U32(ctx, 31, 0x139508u);
    ctx->pc = 0x139504u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139500u;
            // 0x139504: 0xafa00000  sw          $zero, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139508u; }
        if (ctx->pc != 0x139508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139508u; }
        if (ctx->pc != 0x139508u) { return; }
    }
    ctx->pc = 0x139508u;
label_139508:
    // 0x139508: 0x1a20000b  blez        $s1, . + 4 + (0xB << 2)
    ctx->pc = 0x139508u;
    {
        const bool branch_taken_0x139508 = (GPR_S64(ctx, 17) <= 0);
        ctx->pc = 0x13950Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139508u;
            // 0x13950c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139508) {
            ctx->pc = 0x139538u;
            goto label_139538;
        }
    }
    ctx->pc = 0x139510u;
    // 0x139510: 0x240482d  daddu       $t1, $s2, $zero
    ctx->pc = 0x139510u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139514: 0x0  nop
    ctx->pc = 0x139514u;
    // NOP
label_139518:
    // 0x139518: 0x61080  sll         $v0, $a2, 2
    ctx->pc = 0x139518u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x13951c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x13951cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x139520: 0x491821  addu        $v1, $v0, $t1
    ctx->pc = 0x139520u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x139524: 0x541021  addu        $v0, $v0, $s4
    ctx->pc = 0x139524u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 20)));
    // 0x139528: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x139528u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13952c: 0xd1282a  slt         $a1, $a2, $s1
    ctx->pc = 0x13952cu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x139530: 0x14a0fff9  bnez        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x139530u;
    {
        const bool branch_taken_0x139530 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x139534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139530u;
            // 0x139534: 0xac440000  sw          $a0, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139530) {
            ctx->pc = 0x139518u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_139518;
        }
    }
    ctx->pc = 0x139538u;
label_139538:
    // 0x139538: 0xc0505ba  jal         func_1416E8
    ctx->pc = 0x139538u;
    SET_GPR_U32(ctx, 31, 0x139540u);
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139540u; }
        if (ctx->pc != 0x139540u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416E8_0x1416e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139540u; }
        if (ctx->pc != 0x139540u) { return; }
    }
    ctx->pc = 0x139540u;
label_139540:
    // 0x139540: 0x8ea224c0  lw          $v0, 0x24C0($s5)
    ctx->pc = 0x139540u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 9408)));
    // 0x139544: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x139544u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x139548: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x139548u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13954c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x13954cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x139550: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x139550u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x139554: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x139554u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x139558: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x139558u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x13955c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x13955cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x139560: 0x3e00008  jr          $ra
    ctx->pc = 0x139560u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x139564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139560u;
            // 0x139564: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x139498u: goto label_139498;
            case 0x1394A8u: goto label_1394a8;
            case 0x1394D0u: goto label_1394d0;
            case 0x1394D8u: goto label_1394d8;
            case 0x139508u: goto label_139508;
            case 0x139518u: goto label_139518;
            case 0x139538u: goto label_139538;
            case 0x139540u: goto label_139540;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139568u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
