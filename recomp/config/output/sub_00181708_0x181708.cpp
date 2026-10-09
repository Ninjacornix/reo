#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00181708
// Address: 0x181708 - 0x1817c8
void sub_00181708_0x181708(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00181708_0x181708");
#endif

    switch (ctx->pc) {
        case 0x181748u: goto label_181748;
        case 0x181778u: goto label_181778;
        case 0x1817a0u: goto label_1817a0;
        case 0x1817a8u: goto label_1817a8;
        default: break;
    }

    ctx->pc = 0x181708u;

    // 0x181708: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x181708u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x18170c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x18170cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x181710: 0x8c67fa10  lw          $a3, -0x5F0($v1)
    ctx->pc = 0x181710u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294965776)));
    // 0x181714: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181714u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181718: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x181718u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x18171c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x18171cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181720: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x181720u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x181724: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x181724u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181728: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x181728u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x18172c: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x18172cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181730: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x181730u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x181734: 0x34428001  ori         $v0, $v0, 0x8001
    ctx->pc = 0x181734u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
    // 0x181738: 0x10e0001c  beqz        $a3, . + 4 + (0x1C << 2)
    ctx->pc = 0x181738u;
    {
        const bool branch_taken_0x181738 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x18173Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181738u;
            // 0x18173c: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181738) {
            ctx->pc = 0x1817ACu;
            goto label_1817ac;
        }
    }
    ctx->pc = 0x181740u;
    // 0x181740: 0xc061e90  jal         func_187A40
    ctx->pc = 0x181740u;
    SET_GPR_U32(ctx, 31, 0x181748u);
    ctx->pc = 0x187A40u;
    if (runtime->hasFunction(0x187A40u)) {
        auto targetFn = runtime->lookupFunction(0x187A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181748u; }
        if (ctx->pc != 0x181748u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187A40_0x187a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181748u; }
        if (ctx->pc != 0x181748u) { return; }
    }
    ctx->pc = 0x181748u;
label_181748:
    // 0x181748: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x181748u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x18174c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18174Cu;
    {
        const bool branch_taken_0x18174c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18174Cu;
            // 0x181750: 0x24709500  addiu       $s0, $v1, -0x6B00 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294939904));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18174c) {
            ctx->pc = 0x181760u;
            goto label_181760;
        }
    }
    ctx->pc = 0x181754u;
    // 0x181754: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181754u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181758: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x181758u;
    {
        const bool branch_taken_0x181758 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18175Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181758u;
            // 0x18175c: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181758) {
            ctx->pc = 0x1817ACu;
            goto label_1817ac;
        }
    }
    ctx->pc = 0x181760u;
label_181760:
    // 0x181760: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x181760u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x181764: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181764u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181768: 0x14600010  bnez        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x181768u;
    {
        const bool branch_taken_0x181768 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x18176Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181768u;
            // 0x18176c: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181768) {
            ctx->pc = 0x1817ACu;
            goto label_1817ac;
        }
    }
    ctx->pc = 0x181770u;
    // 0x181770: 0xc042c56  jal         func_10B158
    ctx->pc = 0x181770u;
    SET_GPR_U32(ctx, 31, 0x181778u);
    ctx->pc = 0x181774u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181770u;
            // 0x181774: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181778u; }
        if (ctx->pc != 0x181778u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181778u; }
        if (ctx->pc != 0x181778u) { return; }
    }
    ctx->pc = 0x181778u;
label_181778:
    // 0x181778: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x181778u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18177c: 0x2c430080  sltiu       $v1, $v0, 0x80
    ctx->pc = 0x18177cu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x181780: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181780u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181784: 0x2604041c  addiu       $a0, $s0, 0x41C
    ctx->pc = 0x181784u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
    // 0x181788: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x181788u;
    {
        const bool branch_taken_0x181788 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x18178Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181788u;
            // 0x18178c: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181788) {
            ctx->pc = 0x1817ACu;
            goto label_1817ac;
        }
    }
    ctx->pc = 0x181790u;
    // 0x181790: 0x2402000c  addiu       $v0, $zero, 0xC
    ctx->pc = 0x181790u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x181794: 0xae120000  sw          $s2, 0x0($s0)
    ctx->pc = 0x181794u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
    // 0x181798: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x181798u;
    SET_GPR_U32(ctx, 31, 0x1817A0u);
    ctx->pc = 0x18179Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181798u;
            // 0x18179c: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1817A0u; }
        if (ctx->pc != 0x1817A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1817A0u; }
        if (ctx->pc != 0x1817A0u) { return; }
    }
    ctx->pc = 0x1817A0u;
label_1817a0:
    // 0x1817a0: 0xc062228  jal         func_1888A0
    ctx->pc = 0x1817A0u;
    SET_GPR_U32(ctx, 31, 0x1817A8u);
    ctx->pc = 0x1817A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1817A0u;
            // 0x1817a4: 0xae13000c  sw          $s3, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1888A0u;
    if (runtime->hasFunction(0x1888A0u)) {
        auto targetFn = runtime->lookupFunction(0x1888A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1817A8u; }
        if (ctx->pc != 0x1817A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001888A0_0x1888a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1817A8u; }
        if (ctx->pc != 0x1817A8u) { return; }
    }
    ctx->pc = 0x1817A8u;
label_1817a8:
    // 0x1817a8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1817a8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1817ac:
    // 0x1817ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1817acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1817b0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1817b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1817b4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1817b4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1817b8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1817b8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1817bc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1817bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1817c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1817C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1817C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1817C0u;
            // 0x1817c4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181748u: goto label_181748;
            case 0x181760u: goto label_181760;
            case 0x181778u: goto label_181778;
            case 0x1817A0u: goto label_1817a0;
            case 0x1817A8u: goto label_1817a8;
            case 0x1817ACu: goto label_1817ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1817C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
