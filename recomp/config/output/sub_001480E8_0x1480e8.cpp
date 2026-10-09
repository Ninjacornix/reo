#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001480E8
// Address: 0x1480e8 - 0x148170
void sub_001480E8_0x1480e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001480E8_0x1480e8");
#endif

    switch (ctx->pc) {
        case 0x148144u: goto label_148144;
        default: break;
    }

    ctx->pc = 0x1480e8u;

    // 0x1480e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1480e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1480ec: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x1480ecu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1480f0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1480f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1480f4: 0x50e00001  beql        $a3, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1480F4u;
    {
        const bool branch_taken_0x1480f4 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x1480f4) {
            ctx->pc = 0x1480F8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1480F4u;
            // 0x1480f8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1480FCu;
            goto label_1480fc;
        }
    }
    ctx->pc = 0x1480FCu;
label_1480fc:
    // 0x1480fc: 0x8ca20008  lw          $v0, 0x8($a1)
    ctx->pc = 0x1480fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x148100: 0x8ca40004  lw          $a0, 0x4($a1)
    ctx->pc = 0x148100u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x148104: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x148104u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x148108: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x148108u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x14810c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x14810cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x148110: 0x47001b  divu        $zero, $v0, $a3
    ctx->pc = 0x148110u;
    { uint32_t divisor = GPR_U32(ctx, 7); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
    // 0x148114: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x148114u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x148118: 0x1012  mflo        $v0
    ctx->pc = 0x148118u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x14811c: 0x471018  mult        $v0, $v0, $a3
    ctx->pc = 0x14811cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x148120: 0x462021  addu        $a0, $v0, $a2
    ctx->pc = 0x148120u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x148124: 0x64182b  sltu        $v1, $v1, $a0
    ctx->pc = 0x148124u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x148128: 0x54600003  bnel        $v1, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x148128u;
    {
        const bool branch_taken_0x148128 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x148128) {
            ctx->pc = 0x14812Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x148128u;
            // 0x14812c: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x148138u;
            goto label_148138;
        }
    }
    ctx->pc = 0x148130u;
    // 0x148130: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x148130u;
    {
        const bool branch_taken_0x148130 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x148134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148130u;
            // 0x148134: 0xaca40008  sw          $a0, 0x8($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148130) {
            ctx->pc = 0x148148u;
            goto label_148148;
        }
    }
    ctx->pc = 0x148138u;
label_148138:
    // 0x148138: 0x100202d  daddu       $a0, $t0, $zero
    ctx->pc = 0x148138u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14813c: 0xc05221c  jal         func_148870
    ctx->pc = 0x14813Cu;
    SET_GPR_U32(ctx, 31, 0x148144u);
    ctx->pc = 0x148140u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14813Cu;
            // 0x148140: 0x24a5e038  addiu       $a1, $a1, -0x1FC8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148144u; }
        if (ctx->pc != 0x148144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148144u; }
        if (ctx->pc != 0x148144u) { return; }
    }
    ctx->pc = 0x148144u;
label_148144:
    // 0x148144: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x148144u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_148148:
    // 0x148148: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x148148u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14814c: 0x3e00008  jr          $ra
    ctx->pc = 0x14814Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14814Cu;
            // 0x148150: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1480FCu: goto label_1480fc;
            case 0x148138u: goto label_148138;
            case 0x148144u: goto label_148144;
            case 0x148148u: goto label_148148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148154u;
    // 0x148154: 0x0  nop
    ctx->pc = 0x148154u;
    // NOP
    // 0x148158: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x148158u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14815c: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x14815cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x148160: 0x8c850008  lw          $a1, 0x8($a0)
    ctx->pc = 0x148160u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x148164: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x148164u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x148168: 0x3e00008  jr          $ra
    ctx->pc = 0x148168u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14816Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148168u;
            // 0x14816c: 0x451023  subu        $v0, $v0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1480FCu: goto label_1480fc;
            case 0x148138u: goto label_148138;
            case 0x148144u: goto label_148144;
            case 0x148148u: goto label_148148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148170u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
