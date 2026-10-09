#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001067D0
// Address: 0x1067d0 - 0x106854
void sub_001067D0_0x1067d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001067D0_0x1067d0");
#endif

    switch (ctx->pc) {
        case 0x106818u: goto label_106818;
        default: break;
    }

    ctx->pc = 0x1067d0u;

    // 0x1067d0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1067d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1067d4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1067d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1067d8: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x1067d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x1067dc: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1067dcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1067e0: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1067e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1067e4: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1067e4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1067e8: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x1067e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x1067ec: 0x2518018  mult        $s0, $s2, $s1
    ctx->pc = 0x1067ecu;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 16, (int32_t)result); }
    // 0x1067f0: 0xafa40010  sw          $a0, 0x10($sp)
    ctx->pc = 0x1067f0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 4));
    // 0x1067f4: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x1067f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1067f8: 0x27a20010  addiu       $v0, $sp, 0x10
    ctx->pc = 0x1067f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1067fc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1067fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106800: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x106800u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x106804: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x106804u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x106808: 0xafa30004  sw          $v1, 0x4($sp)
    ctx->pc = 0x106808u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
    // 0x10680c: 0xafb00014  sw          $s0, 0x14($sp)
    ctx->pc = 0x10680cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 16));
    // 0x106810: 0xc0418d6  jal         func_106358
    ctx->pc = 0x106810u;
    SET_GPR_U32(ctx, 31, 0x106818u);
    ctx->pc = 0x106814u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106810u;
            // 0x106814: 0xafb00008  sw          $s0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106358u;
    if (runtime->hasFunction(0x106358u)) {
        auto targetFn = runtime->lookupFunction(0x106358u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106818u; }
        if (ctx->pc != 0x106818u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106358_0x106358(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106818u; }
        if (ctx->pc != 0x106818u) { return; }
    }
    ctx->pc = 0x106818u;
label_106818:
    // 0x106818: 0x54400003  bnel        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x106818u;
    {
        const bool branch_taken_0x106818 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x106818) {
            ctx->pc = 0x10681Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106818u;
            // 0x10681c: 0x8fa20008  lw          $v0, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106828u;
            goto label_106828;
        }
    }
    ctx->pc = 0x106820u;
    // 0x106820: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x106820u;
    {
        const bool branch_taken_0x106820 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106820u;
            // 0x106824: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106820) {
            ctx->pc = 0x10683Cu;
            goto label_10683c;
        }
    }
    ctx->pc = 0x106828u;
label_106828:
    // 0x106828: 0x52200001  beql        $s1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x106828u;
    {
        const bool branch_taken_0x106828 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x106828) {
            ctx->pc = 0x10682Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106828u;
            // 0x10682c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x106830u;
            goto label_106830;
        }
    }
    ctx->pc = 0x106830u;
label_106830:
    // 0x106830: 0x2021023  subu        $v0, $s0, $v0
    ctx->pc = 0x106830u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x106834: 0x51001b  divu        $zero, $v0, $s1
    ctx->pc = 0x106834u;
    { uint32_t divisor = GPR_U32(ctx, 17); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
    // 0x106838: 0x1012  mflo        $v0
    ctx->pc = 0x106838u;
    SET_GPR_U64(ctx, 2, ctx->lo);
label_10683c:
    // 0x10683c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x10683cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x106840: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x106840u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x106844: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x106844u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x106848: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x106848u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x10684c: 0x3e00008  jr          $ra
    ctx->pc = 0x10684Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x106850u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10684Cu;
            // 0x106850: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x106818u: goto label_106818;
            case 0x106828u: goto label_106828;
            case 0x106830u: goto label_106830;
            case 0x10683Cu: goto label_10683c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x106854u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
