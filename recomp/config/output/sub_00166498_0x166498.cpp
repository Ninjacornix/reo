#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166498
// Address: 0x166498 - 0x166548
void sub_00166498_0x166498(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166498_0x166498");
#endif

    switch (ctx->pc) {
        case 0x1664b8u: goto label_1664b8;
        case 0x1664c8u: goto label_1664c8;
        case 0x166520u: goto label_166520;
        case 0x166534u: goto label_166534;
        default: break;
    }

    ctx->pc = 0x166498u;

    // 0x166498: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x166498u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16649c: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x16649cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1664a0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1664a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1664a4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1664a4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1664a8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1664a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1664ac: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1664acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1664b0: 0xc05df1e  jal         func_177C78
    ctx->pc = 0x1664B0u;
    SET_GPR_U32(ctx, 31, 0x1664B8u);
    ctx->pc = 0x1664B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1664B0u;
            // 0x1664b4: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C78u;
    if (runtime->hasFunction(0x177C78u)) {
        auto targetFn = runtime->lookupFunction(0x177C78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1664B8u; }
        if (ctx->pc != 0x1664B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C78_0x177c78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1664B8u; }
        if (ctx->pc != 0x1664B8u) { return; }
    }
    ctx->pc = 0x1664B8u;
label_1664b8:
    // 0x1664b8: 0x1051000d  beq         $v0, $s1, . + 4 + (0xD << 2)
    ctx->pc = 0x1664B8u;
    {
        const bool branch_taken_0x1664b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 17));
        ctx->pc = 0x1664BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1664B8u;
            // 0x1664bc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1664b8) {
            ctx->pc = 0x1664F0u;
            goto label_1664f0;
        }
    }
    ctx->pc = 0x1664C0u;
    // 0x1664c0: 0xc059f40  jal         func_167D00
    ctx->pc = 0x1664C0u;
    SET_GPR_U32(ctx, 31, 0x1664C8u);
    ctx->pc = 0x1664C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1664C0u;
            // 0x1664c4: 0x8e051c8c  lw          $a1, 0x1C8C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7308)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167D00u;
    if (runtime->hasFunction(0x167D00u)) {
        auto targetFn = runtime->lookupFunction(0x167D00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1664C8u; }
        if (ctx->pc != 0x1664C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167D00_0x167d00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1664C8u; }
        if (ctx->pc != 0x1664C8u) { return; }
    }
    ctx->pc = 0x1664C8u;
label_1664c8:
    // 0x1664c8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1664c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1664cc: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x1664ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1664d0: 0x14510007  bne         $v0, $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1664D0u;
    {
        const bool branch_taken_0x1664d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x1664D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1664D0u;
            // 0x1664d4: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1664d0) {
            ctx->pc = 0x1664F0u;
            goto label_1664f0;
        }
    }
    ctx->pc = 0x1664D8u;
    // 0x1664d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1664d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1664dc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1664dcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1664e0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1664e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1664e4: 0x805df18  j           func_177C60
    ctx->pc = 0x1664E4u;
    ctx->pc = 0x1664E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1664E4u;
            // 0x1664e8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C60u;
    if (runtime->hasFunction(0x177C60u)) {
        auto targetFn = runtime->lookupFunction(0x177C60u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177C60_0x177c60(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1664ECu;
    // 0x1664ec: 0x0  nop
    ctx->pc = 0x1664ecu;
    // NOP
label_1664f0:
    // 0x1664f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1664f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1664f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1664f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1664f8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1664f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1664fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1664FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1664FCu;
            // 0x166500: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1664B8u: goto label_1664b8;
            case 0x1664C8u: goto label_1664c8;
            case 0x1664F0u: goto label_1664f0;
            case 0x166520u: goto label_166520;
            case 0x166534u: goto label_166534;
            case 0x166538u: goto label_166538;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166504u;
    // 0x166504: 0x0  nop
    ctx->pc = 0x166504u;
    // NOP
    // 0x166508: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x166508u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16650c: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x16650cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x166510: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x166510u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166514: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x166514u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x166518: 0xc05d58a  jal         func_175628
    ctx->pc = 0x166518u;
    SET_GPR_U32(ctx, 31, 0x166520u);
    ctx->pc = 0x16651Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166518u;
            // 0x16651c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166520u; }
        if (ctx->pc != 0x166520u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166520u; }
        if (ctx->pc != 0x166520u) { return; }
    }
    ctx->pc = 0x166520u;
label_166520:
    // 0x166520: 0x26032a5c  addiu       $v1, $s0, 0x2A5C
    ctx->pc = 0x166520u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 10844));
    // 0x166524: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x166524u;
    {
        const bool branch_taken_0x166524 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166524u;
            // 0x166528: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166524) {
            ctx->pc = 0x166538u;
            goto label_166538;
        }
    }
    ctx->pc = 0x16652Cu;
    // 0x16652c: 0xc059952  jal         func_166548
    ctx->pc = 0x16652Cu;
    SET_GPR_U32(ctx, 31, 0x166534u);
    ctx->pc = 0x166530u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16652Cu;
            // 0x166530: 0xae031c84  sw          $v1, 0x1C84($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 7300), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166548u;
    if (runtime->hasFunction(0x166548u)) {
        auto targetFn = runtime->lookupFunction(0x166548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166534u; }
        if (ctx->pc != 0x166534u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166548_0x166548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166534u; }
        if (ctx->pc != 0x166534u) { return; }
    }
    ctx->pc = 0x166534u;
label_166534:
    // 0x166534: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x166534u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_166538:
    // 0x166538: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166538u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16653c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16653cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166540: 0x3e00008  jr          $ra
    ctx->pc = 0x166540u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166540u;
            // 0x166544: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1664B8u: goto label_1664b8;
            case 0x1664C8u: goto label_1664c8;
            case 0x1664F0u: goto label_1664f0;
            case 0x166520u: goto label_166520;
            case 0x166534u: goto label_166534;
            case 0x166538u: goto label_166538;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166548u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
