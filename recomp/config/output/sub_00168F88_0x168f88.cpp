#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00168F88
// Address: 0x168f88 - 0x169040
void sub_00168F88_0x168f88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00168F88_0x168f88");
#endif

    switch (ctx->pc) {
        case 0x168fd4u: goto label_168fd4;
        case 0x168fecu: goto label_168fec;
        case 0x169004u: goto label_169004;
        case 0x16901cu: goto label_16901c;
        default: break;
    }

    ctx->pc = 0x168f88u;

    // 0x168f88: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x168f88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x168f8c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x168f8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x168f90: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x168f90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x168f94: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x168f94u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168f98: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x168f98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x168f9c: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x168f9cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168fa0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x168fa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x168fa4: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x168fa4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168fa8: 0x2610fffa  addiu       $s0, $s0, -0x6
    ctx->pc = 0x168fa8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967290));
    // 0x168fac: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x168facu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x168fb0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x168fb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x168fb4: 0x26310006  addiu       $s1, $s1, 0x6
    ctx->pc = 0x168fb4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 6));
    // 0x168fb8: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x168fb8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168fbc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x168fbcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168fc0: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x168fc0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x168fc4: 0x14a30017  bne         $a1, $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x168FC4u;
    {
        const bool branch_taken_0x168fc4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x168FC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168FC4u;
            // 0x168fc8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168fc4) {
            ctx->pc = 0x169024u;
            goto label_169024;
        }
    }
    ctx->pc = 0x168FCCu;
    // 0x168fcc: 0xc05a410  jal         func_169040
    ctx->pc = 0x168FCCu;
    SET_GPR_U32(ctx, 31, 0x168FD4u);
    ctx->pc = 0x169040u;
    if (runtime->hasFunction(0x169040u)) {
        auto targetFn = runtime->lookupFunction(0x169040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168FD4u; }
        if (ctx->pc != 0x168FD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169040_0x169040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168FD4u; }
        if (ctx->pc != 0x168FD4u) { return; }
    }
    ctx->pc = 0x168FD4u;
label_168fd4:
    // 0x168fd4: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x168FD4u;
    {
        const bool branch_taken_0x168fd4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x168fd4) {
            ctx->pc = 0x168FD8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x168FD4u;
            // 0x168fd8: 0x2610fff4  addiu       $s0, $s0, -0xC (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967284));
        ctx->in_delay_slot = false;
            ctx->pc = 0x168FF4u;
            goto label_168ff4;
        }
    }
    ctx->pc = 0x168FDCu;
    // 0x168fdc: 0x2610fffe  addiu       $s0, $s0, -0x2
    ctx->pc = 0x168fdcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967294));
    // 0x168fe0: 0x26310002  addiu       $s1, $s1, 0x2
    ctx->pc = 0x168fe0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 2));
    // 0x168fe4: 0xc05a410  jal         func_169040
    ctx->pc = 0x168FE4u;
    SET_GPR_U32(ctx, 31, 0x168FECu);
    ctx->pc = 0x168FE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168FE4u;
            // 0x168fe8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169040u;
    if (runtime->hasFunction(0x169040u)) {
        auto targetFn = runtime->lookupFunction(0x169040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168FECu; }
        if (ctx->pc != 0x168FECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169040_0x169040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168FECu; }
        if (ctx->pc != 0x168FECu) { return; }
    }
    ctx->pc = 0x168FECu;
label_168fec:
    // 0x168fec: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x168FECu;
    {
        const bool branch_taken_0x168fec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x168FF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168FECu;
            // 0x168ff0: 0x2610fff4  addiu       $s0, $s0, -0xC (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967284));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168fec) {
            ctx->pc = 0x169024u;
            goto label_169024;
        }
    }
    ctx->pc = 0x168FF4u;
label_168ff4:
    // 0x168ff4: 0x2631000c  addiu       $s1, $s1, 0xC
    ctx->pc = 0x168ff4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
    // 0x168ff8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x168ff8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168ffc: 0xc05a426  jal         func_169098
    ctx->pc = 0x168FFCu;
    SET_GPR_U32(ctx, 31, 0x169004u);
    ctx->pc = 0x169000u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168FFCu;
            // 0x169000: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169098u;
    if (runtime->hasFunction(0x169098u)) {
        auto targetFn = runtime->lookupFunction(0x169098u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169004u; }
        if (ctx->pc != 0x169004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169098_0x169098(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169004u; }
        if (ctx->pc != 0x169004u) { return; }
    }
    ctx->pc = 0x169004u;
label_169004:
    // 0x169004: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x169004u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169008: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x169008u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16900c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16900Cu;
    {
        const bool branch_taken_0x16900c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x169010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16900Cu;
            // 0x169010: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16900c) {
            ctx->pc = 0x169024u;
            goto label_169024;
        }
    }
    ctx->pc = 0x169014u;
    // 0x169014: 0xc05a43c  jal         func_1690F0
    ctx->pc = 0x169014u;
    SET_GPR_U32(ctx, 31, 0x16901Cu);
    ctx->pc = 0x1690F0u;
    if (runtime->hasFunction(0x1690F0u)) {
        auto targetFn = runtime->lookupFunction(0x1690F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16901Cu; }
        if (ctx->pc != 0x16901Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001690F0_0x1690f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16901Cu; }
        if (ctx->pc != 0x16901Cu) { return; }
    }
    ctx->pc = 0x16901Cu;
label_16901c:
    // 0x16901c: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x16901cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x169020: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x169020u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_169024:
    // 0x169024: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x169024u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169028: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x169028u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16902c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16902cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x169030: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x169030u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x169034: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x169034u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x169038: 0x3e00008  jr          $ra
    ctx->pc = 0x169038u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16903Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169038u;
            // 0x16903c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x168FD4u: goto label_168fd4;
            case 0x168FECu: goto label_168fec;
            case 0x168FF4u: goto label_168ff4;
            case 0x169004u: goto label_169004;
            case 0x16901Cu: goto label_16901c;
            case 0x169024u: goto label_169024;
            default: break;
        }
        return;
    }
    ctx->pc = 0x169040u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
