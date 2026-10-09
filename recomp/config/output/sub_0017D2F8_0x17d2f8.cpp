#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D2F8
// Address: 0x17d2f8 - 0x17d390
void sub_0017D2F8_0x17d2f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D2F8_0x17d2f8");
#endif

    switch (ctx->pc) {
        case 0x17d348u: goto label_17d348;
        case 0x17d360u: goto label_17d360;
        case 0x17d374u: goto label_17d374;
        default: break;
    }

    ctx->pc = 0x17d2f8u;

    // 0x17d2f8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17d2f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17d2fc: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x17d2fcu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d300: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x17d300u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x17d304: 0x25110014  addiu       $s1, $t0, 0x14
    ctx->pc = 0x17d304u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 8), 20));
    // 0x17d308: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x17d308u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x17d30c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x17d30cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d310: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17d310u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17d314: 0xc0182d  daddu       $v1, $a2, $zero
    ctx->pc = 0x17d314u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d318: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x17d318u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x17d31c: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x17d31cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x17d320: 0xae230008  sw          $v1, 0x8($s1)
    ctx->pc = 0x17d320u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 3));
    // 0x17d324: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17d324u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17d328: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17d328u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d32c: 0x24a51438  addiu       $a1, $a1, 0x1438
    ctx->pc = 0x17d32cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5176));
    // 0x17d330: 0x24c61440  addiu       $a2, $a2, 0x1440
    ctx->pc = 0x17d330u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 5184));
    // 0x17d334: 0x8d100024  lw          $s0, 0x24($t0)
    ctx->pc = 0x17d334u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 36)));
    // 0x17d338: 0x27a70010  addiu       $a3, $sp, 0x10
    ctx->pc = 0x17d338u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x17d33c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x17d33cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x17d340: 0xc050288  jal         func_140A20
    ctx->pc = 0x17D340u;
    SET_GPR_U32(ctx, 31, 0x17D348u);
    ctx->pc = 0x17D344u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D340u;
            // 0x17d344: 0xafa30004  sw          $v1, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140A20u;
    if (runtime->hasFunction(0x140A20u)) {
        auto targetFn = runtime->lookupFunction(0x140A20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D348u; }
        if (ctx->pc != 0x17D348u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140A20_0x140a20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D348u; }
        if (ctx->pc != 0x17D348u) { return; }
    }
    ctx->pc = 0x17D348u;
label_17d348:
    // 0x17d348: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x17d348u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d34c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x17d34cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d350: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17D350u;
    {
        const bool branch_taken_0x17d350 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x17D354u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D350u;
            // 0x17d354: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17d350) {
            ctx->pc = 0x17D368u;
            goto label_17d368;
        }
    }
    ctx->pc = 0x17D358u;
    // 0x17d358: 0xc05f60a  jal         func_17D828
    ctx->pc = 0x17D358u;
    SET_GPR_U32(ctx, 31, 0x17D360u);
    ctx->pc = 0x17D828u;
    if (runtime->hasFunction(0x17D828u)) {
        auto targetFn = runtime->lookupFunction(0x17D828u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D360u; }
        if (ctx->pc != 0x17D360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D828_0x17d828(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D360u; }
        if (ctx->pc != 0x17D360u) { return; }
    }
    ctx->pc = 0x17D360u;
label_17d360:
    // 0x17d360: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x17D360u;
    {
        const bool branch_taken_0x17d360 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17D364u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D360u;
            // 0x17d364: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17d360) {
            ctx->pc = 0x17D378u;
            goto label_17d378;
        }
    }
    ctx->pc = 0x17D368u;
label_17d368:
    // 0x17d368: 0x8fa50010  lw          $a1, 0x10($sp)
    ctx->pc = 0x17d368u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17d36c: 0xc05f60a  jal         func_17D828
    ctx->pc = 0x17D36Cu;
    SET_GPR_U32(ctx, 31, 0x17D374u);
    ctx->pc = 0x17D370u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D36Cu;
            // 0x17d370: 0x8fa60014  lw          $a2, 0x14($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D828u;
    if (runtime->hasFunction(0x17D828u)) {
        auto targetFn = runtime->lookupFunction(0x17D828u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D374u; }
        if (ctx->pc != 0x17D374u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D828_0x17d828(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D374u; }
        if (ctx->pc != 0x17D374u) { return; }
    }
    ctx->pc = 0x17D374u;
label_17d374:
    // 0x17d374: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17d374u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_17d378:
    // 0x17d378: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x17d378u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17d37c: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x17d37cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x17d380: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x17d380u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17d384: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x17d384u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x17d388: 0x3e00008  jr          $ra
    ctx->pc = 0x17D388u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D38Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D388u;
            // 0x17d38c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D348u: goto label_17d348;
            case 0x17D360u: goto label_17d360;
            case 0x17D368u: goto label_17d368;
            case 0x17D374u: goto label_17d374;
            case 0x17D378u: goto label_17d378;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D390u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
