#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D850
// Address: 0x17d850 - 0x17d938
void sub_0017D850_0x17d850(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D850_0x17d850");
#endif

    switch (ctx->pc) {
        case 0x17d8d8u: goto label_17d8d8;
        case 0x17d904u: goto label_17d904;
        default: break;
    }

    ctx->pc = 0x17d850u;

    // 0x17d850: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x17d850u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x17d854: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x17d854u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d858: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x17d858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x17d85c: 0x24530018  addiu       $s3, $v0, 0x18
    ctx->pc = 0x17d85cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 24));
    // 0x17d860: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x17d860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x17d864: 0x24540028  addiu       $s4, $v0, 0x28
    ctx->pc = 0x17d864u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 40));
    // 0x17d868: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x17d868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x17d86c: 0x24430008  addiu       $v1, $v0, 0x8
    ctx->pc = 0x17d86cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x17d870: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x17d870u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x17d874: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x17d874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x17d878: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x17d878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x17d87c: 0x8c680004  lw          $t0, 0x4($v1)
    ctx->pc = 0x17d87cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x17d880: 0x15000009  bnez        $t0, . + 4 + (0x9 << 2)
    ctx->pc = 0x17D880u;
    {
        const bool branch_taken_0x17d880 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x17D884u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D880u;
            // 0x17d884: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17d880) {
            ctx->pc = 0x17D8A8u;
            goto label_17d8a8;
        }
    }
    ctx->pc = 0x17D888u;
    // 0x17d888: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17d888u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17d88c: 0xae600008  sw          $zero, 0x8($s3)
    ctx->pc = 0x17d88cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 8), GPR_U32(ctx, 0));
    // 0x17d890: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x17d890u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x17d894: 0xae600004  sw          $zero, 0x4($s3)
    ctx->pc = 0x17d894u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 0));
    // 0x17d898: 0xae820000  sw          $v0, 0x0($s4)
    ctx->pc = 0x17d898u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 2));
    // 0x17d89c: 0xae800008  sw          $zero, 0x8($s4)
    ctx->pc = 0x17d89cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 8), GPR_U32(ctx, 0));
    // 0x17d8a0: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x17D8A0u;
    {
        const bool branch_taken_0x17d8a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17D8A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D8A0u;
            // 0x17d8a4: 0xae800004  sw          $zero, 0x4($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17d8a0) {
            ctx->pc = 0x17D918u;
            goto label_17d918;
        }
    }
    ctx->pc = 0x17D8A8u;
label_17d8a8:
    // 0x17d8a8: 0x3c100024  lui         $s0, 0x24
    ctx->pc = 0x17d8a8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)36 << 16));
    // 0x17d8ac: 0x27b20010  addiu       $s2, $sp, 0x10
    ctx->pc = 0x17d8acu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x17d8b0: 0x8c620008  lw          $v0, 0x8($v1)
    ctx->pc = 0x17d8b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x17d8b4: 0x26101450  addiu       $s0, $s0, 0x1450
    ctx->pc = 0x17d8b4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 5200));
    // 0x17d8b8: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x17d8b8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x17d8bc: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x17d8bcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d8c0: 0x24a51448  addiu       $a1, $a1, 0x1448
    ctx->pc = 0x17d8c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5192));
    // 0x17d8c4: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x17d8c4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d8c8: 0xafa80000  sw          $t0, 0x0($sp)
    ctx->pc = 0x17d8c8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 8));
    // 0x17d8cc: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x17d8ccu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17d8d0: 0xc050288  jal         func_140A20
    ctx->pc = 0x17D8D0u;
    SET_GPR_U32(ctx, 31, 0x17D8D8u);
    ctx->pc = 0x17D8D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D8D0u;
            // 0x17d8d4: 0xafa20004  sw          $v0, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140A20u;
    if (runtime->hasFunction(0x140A20u)) {
        auto targetFn = runtime->lookupFunction(0x140A20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D8D8u; }
        if (ctx->pc != 0x17D8D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140A20_0x140a20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D8D8u; }
        if (ctx->pc != 0x17D8D8u) { return; }
    }
    ctx->pc = 0x17D8D8u;
label_17d8d8:
    // 0x17d8d8: 0x8fa30010  lw          $v1, 0x10($sp)
    ctx->pc = 0x17d8d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17d8dc: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x17d8dcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x17d8e0: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x17d8e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x17d8e4: 0x24a51458  addiu       $a1, $a1, 0x1458
    ctx->pc = 0x17d8e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5208));
    // 0x17d8e8: 0xae630004  sw          $v1, 0x4($s3)
    ctx->pc = 0x17d8e8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 3));
    // 0x17d8ec: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x17d8ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d8f0: 0xae620008  sw          $v0, 0x8($s3)
    ctx->pc = 0x17d8f0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 8), GPR_U32(ctx, 2));
    // 0x17d8f4: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x17d8f4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d8f8: 0xae710000  sw          $s1, 0x0($s3)
    ctx->pc = 0x17d8f8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 17));
    // 0x17d8fc: 0xc050288  jal         func_140A20
    ctx->pc = 0x17D8FCu;
    SET_GPR_U32(ctx, 31, 0x17D904u);
    ctx->pc = 0x17D900u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D8FCu;
            // 0x17d900: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140A20u;
    if (runtime->hasFunction(0x140A20u)) {
        auto targetFn = runtime->lookupFunction(0x140A20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D904u; }
        if (ctx->pc != 0x17D904u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140A20_0x140a20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D904u; }
        if (ctx->pc != 0x17D904u) { return; }
    }
    ctx->pc = 0x17D904u;
label_17d904:
    // 0x17d904: 0xae910000  sw          $s1, 0x0($s4)
    ctx->pc = 0x17d904u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 17));
    // 0x17d908: 0x8fa20010  lw          $v0, 0x10($sp)
    ctx->pc = 0x17d908u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17d90c: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x17d90cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x17d910: 0xae820004  sw          $v0, 0x4($s4)
    ctx->pc = 0x17d910u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 4), GPR_U32(ctx, 2));
    // 0x17d914: 0xae830008  sw          $v1, 0x8($s4)
    ctx->pc = 0x17d914u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 8), GPR_U32(ctx, 3));
label_17d918:
    // 0x17d918: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x17d918u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17d91c: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x17d91cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x17d920: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x17d920u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17d924: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x17d924u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x17d928: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x17d928u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17d92c: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x17d92cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x17d930: 0x3e00008  jr          $ra
    ctx->pc = 0x17D930u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D930u;
            // 0x17d934: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D8A8u: goto label_17d8a8;
            case 0x17D8D8u: goto label_17d8d8;
            case 0x17D904u: goto label_17d904;
            case 0x17D918u: goto label_17d918;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D938u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
