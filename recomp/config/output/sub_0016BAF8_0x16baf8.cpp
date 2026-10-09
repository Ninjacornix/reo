#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016BAF8
// Address: 0x16baf8 - 0x16bb98
void sub_0016BAF8_0x16baf8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016BAF8_0x16baf8");
#endif

    switch (ctx->pc) {
        case 0x16bb3cu: goto label_16bb3c;
        case 0x16bb58u: goto label_16bb58;
        case 0x16bb78u: goto label_16bb78;
        default: break;
    }

    ctx->pc = 0x16baf8u;

    // 0x16baf8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x16baf8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x16bafc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16bafcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16bb00: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x16bb00u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bb04: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x16bb04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x16bb08: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x16bb08u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bb0c: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x16bb0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x16bb10: 0x26500024  addiu       $s0, $s2, 0x24
    ctx->pc = 0x16bb10u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 36));
    // 0x16bb14: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x16bb14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x16bb18: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x16bb18u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bb1c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16bb1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x16bb20: 0x27a80004  addiu       $t0, $sp, 0x4
    ctx->pc = 0x16bb20u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x16bb24: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x16bb24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x16bb28: 0x8cb10000  lw          $s1, 0x0($a1)
    ctx->pc = 0x16bb28u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x16bb2c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x16bb2cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bb30: 0x8e060160  lw          $a2, 0x160($s0)
    ctx->pc = 0x16bb30u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 352)));
    // 0x16bb34: 0xc055900  jal         func_156400
    ctx->pc = 0x16BB34u;
    SET_GPR_U32(ctx, 31, 0x16BB3Cu);
    ctx->pc = 0x16BB38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16BB34u;
            // 0x16bb38: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x156400u;
    if (runtime->hasFunction(0x156400u)) {
        auto targetFn = runtime->lookupFunction(0x156400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BB3Cu; }
        if (ctx->pc != 0x16BB3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00156400_0x156400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BB3Cu; }
        if (ctx->pc != 0x16BB3Cu) { return; }
    }
    ctx->pc = 0x16BB3Cu;
label_16bb3c:
    // 0x16bb3c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16bb3cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bb40: 0x8e060164  lw          $a2, 0x164($s0)
    ctx->pc = 0x16bb40u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 356)));
    // 0x16bb44: 0x264500d4  addiu       $a1, $s2, 0xD4
    ctx->pc = 0x16bb44u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), 212));
    // 0x16bb48: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x16bb48u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bb4c: 0x27a80004  addiu       $t0, $sp, 0x4
    ctx->pc = 0x16bb4cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x16bb50: 0xc055900  jal         func_156400
    ctx->pc = 0x16BB50u;
    SET_GPR_U32(ctx, 31, 0x16BB58u);
    ctx->pc = 0x16BB54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16BB50u;
            // 0x16bb54: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x156400u;
    if (runtime->hasFunction(0x156400u)) {
        auto targetFn = runtime->lookupFunction(0x156400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BB58u; }
        if (ctx->pc != 0x16BB58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00156400_0x156400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BB58u; }
        if (ctx->pc != 0x16BB58u) { return; }
    }
    ctx->pc = 0x16BB58u;
label_16bb58:
    // 0x16bb58: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x16bb58u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bb5c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16bb5cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16bb60: 0x16600003  bnez        $s3, . + 4 + (0x3 << 2)
    ctx->pc = 0x16BB60u;
    {
        const bool branch_taken_0x16bb60 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        ctx->pc = 0x16BB64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BB60u;
            // 0x16bb64: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16bb60) {
            ctx->pc = 0x16BB70u;
            goto label_16bb70;
        }
    }
    ctx->pc = 0x16BB68u;
    // 0x16bb68: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x16BB68u;
    {
        const bool branch_taken_0x16bb68 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16BB6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BB68u;
            // 0x16bb6c: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16bb68) {
            ctx->pc = 0x16BB7Cu;
            goto label_16bb7c;
        }
    }
    ctx->pc = 0x16BB70u;
label_16bb70:
    // 0x16bb70: 0xc05a704  jal         func_169C10
    ctx->pc = 0x16BB70u;
    SET_GPR_U32(ctx, 31, 0x16BB78u);
    ctx->pc = 0x16BB74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16BB70u;
            // 0x16bb74: 0x34a50d0d  ori         $a1, $a1, 0xD0D (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3341);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BB78u; }
        if (ctx->pc != 0x16BB78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BB78u; }
        if (ctx->pc != 0x16BB78u) { return; }
    }
    ctx->pc = 0x16BB78u;
label_16bb78:
    // 0x16bb78: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16bb78u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_16bb7c:
    // 0x16bb7c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16bb7cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16bb80: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x16bb80u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16bb84: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x16bb84u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16bb88: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x16bb88u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16bb8c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x16bb8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16bb90: 0x3e00008  jr          $ra
    ctx->pc = 0x16BB90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16BB94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BB90u;
            // 0x16bb94: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16BB3Cu: goto label_16bb3c;
            case 0x16BB58u: goto label_16bb58;
            case 0x16BB70u: goto label_16bb70;
            case 0x16BB78u: goto label_16bb78;
            case 0x16BB7Cu: goto label_16bb7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16BB98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
