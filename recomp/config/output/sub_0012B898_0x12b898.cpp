#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B898
// Address: 0x12b898 - 0x12b968
void sub_0012B898_0x12b898(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B898_0x12b898");
#endif

    switch (ctx->pc) {
        case 0x12b8e8u: goto label_12b8e8;
        case 0x12b8f8u: goto label_12b8f8;
        case 0x12b900u: goto label_12b900;
        case 0x12b908u: goto label_12b908;
        default: break;
    }

    ctx->pc = 0x12b898u;

    // 0x12b898: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12b898u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12b89c: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x12b89cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x12b8a0: 0x3c160021  lui         $s6, 0x21
    ctx->pc = 0x12b8a0u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)33 << 16));
    // 0x12b8a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12b8a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12b8a8: 0x26c30550  addiu       $v1, $s6, 0x550
    ctx->pc = 0x12b8a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 22), 1360));
    // 0x12b8ac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12b8acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12b8b0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12b8b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12b8b4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12b8b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12b8b8: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x12b8b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12b8bc: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x12b8bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x12b8c0: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x12b8c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x12b8c4: 0xdc620000  ld          $v0, 0x0($v1)
    ctx->pc = 0x12b8c4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12b8c8: 0x14400015  bnez        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x12B8C8u;
    {
        const bool branch_taken_0x12b8c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12B8CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B8C8u;
            // 0x12b8cc: 0x3c150021  lui         $s5, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12b8c8) {
            ctx->pc = 0x12B920u;
            goto label_12b920;
        }
    }
    ctx->pc = 0x12B8D0u;
    // 0x12b8d0: 0x3c140021  lui         $s4, 0x21
    ctx->pc = 0x12b8d0u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)33 << 16));
    // 0x12b8d4: 0x60982d  daddu       $s3, $v1, $zero
    ctx->pc = 0x12b8d4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b8d8: 0x26b20548  addiu       $s2, $s5, 0x548
    ctx->pc = 0x12b8d8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 21), 1352));
    // 0x12b8dc: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x12b8dcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12b8e0: 0x269004f0  addiu       $s0, $s4, 0x4F0
    ctx->pc = 0x12b8e0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), 1264));
    // 0x12b8e4: 0x0  nop
    ctx->pc = 0x12b8e4u;
    // NOP
label_12b8e8:
    // 0x12b8e8: 0xfe510000  sd          $s1, 0x0($s2)
    ctx->pc = 0x12b8e8u;
    WRITE64(ADD32(GPR_U32(ctx, 18), 0), GPR_U64(ctx, 17));
    // 0x12b8ec: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12b8ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12b8f0: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12B8F0u;
    SET_GPR_U32(ctx, 31, 0x12B8F8u);
    ctx->pc = 0x12B8F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B8F0u;
            // 0x12b8f4: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B8F8u; }
        if (ctx->pc != 0x12B8F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B8F8u; }
        if (ctx->pc != 0x12B8F8u) { return; }
    }
    ctx->pc = 0x12B8F8u;
label_12b8f8:
    // 0x12b8f8: 0xc045154  jal         func_114550
    ctx->pc = 0x12B8F8u;
    SET_GPR_U32(ctx, 31, 0x12B900u);
    ctx->pc = 0x12B8FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B8F8u;
            // 0x12b8fc: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114550u;
    if (runtime->hasFunction(0x114550u)) {
        auto targetFn = runtime->lookupFunction(0x114550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B900u; }
        if (ctx->pc != 0x12B900u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114550_0x114550(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B900u; }
        if (ctx->pc != 0x12B900u) { return; }
    }
    ctx->pc = 0x12B900u;
label_12b900:
    // 0x12b900: 0xc04516c  jal         func_1145B0
    ctx->pc = 0x12B900u;
    SET_GPR_U32(ctx, 31, 0x12B908u);
    ctx->pc = 0x12B904u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B900u;
            // 0x12b904: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1145B0u;
    if (runtime->hasFunction(0x1145B0u)) {
        auto targetFn = runtime->lookupFunction(0x1145B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B908u; }
        if (ctx->pc != 0x12B908u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001145B0_0x1145b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B908u; }
        if (ctx->pc != 0x12B908u) { return; }
    }
    ctx->pc = 0x12B908u;
label_12b908:
    // 0x12b908: 0xde630000  ld          $v1, 0x0($s3)
    ctx->pc = 0x12b908u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12b90c: 0x1060fff6  beqz        $v1, . + 4 + (-0xA << 2)
    ctx->pc = 0x12B90Cu;
    {
        const bool branch_taken_0x12b90c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x12B910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B90Cu;
            // 0x12b910: 0x26c20550  addiu       $v0, $s6, 0x550 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), 1360));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12b90c) {
            ctx->pc = 0x12B8E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12b8e8;
        }
    }
    ctx->pc = 0x12B914u;
    // 0x12b914: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x12B914u;
    {
        const bool branch_taken_0x12b914 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12B918u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B914u;
            // 0x12b918: 0xdfb60030  ld          $s6, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12b914) {
            ctx->pc = 0x12B92Cu;
            goto label_12b92c;
        }
    }
    ctx->pc = 0x12B91Cu;
    // 0x12b91c: 0x0  nop
    ctx->pc = 0x12b91cu;
    // NOP
label_12b920:
    // 0x12b920: 0x3c140021  lui         $s4, 0x21
    ctx->pc = 0x12b920u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)33 << 16));
    // 0x12b924: 0x26c20550  addiu       $v0, $s6, 0x550
    ctx->pc = 0x12b924u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), 1360));
    // 0x12b928: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x12b928u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_12b92c:
    // 0x12b92c: 0x26a30548  addiu       $v1, $s5, 0x548
    ctx->pc = 0x12b92cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 1352));
    // 0x12b930: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x12b930u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12b934: 0x268404f0  addiu       $a0, $s4, 0x4F0
    ctx->pc = 0x12b934u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 1264));
    // 0x12b938: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12b938u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12b93c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12b93cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12b940: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12b940u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12b944: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12b944u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12b948: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12b948u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12b94c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x12b94cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12b950: 0xfc400000  sd          $zero, 0x0($v0)
    ctx->pc = 0x12b950u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 0));
    // 0x12b954: 0xfc600000  sd          $zero, 0x0($v1)
    ctx->pc = 0x12b954u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 0));
    // 0x12b958: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x12b958u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x12b95c: 0x3e00008  jr          $ra
    ctx->pc = 0x12B95Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12B960u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B95Cu;
            // 0x12b960: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12B8E8u: goto label_12b8e8;
            case 0x12B8F8u: goto label_12b8f8;
            case 0x12B900u: goto label_12b900;
            case 0x12B908u: goto label_12b908;
            case 0x12B920u: goto label_12b920;
            case 0x12B92Cu: goto label_12b92c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12B964u;
    // 0x12b964: 0x0  nop
    ctx->pc = 0x12b964u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
