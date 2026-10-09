#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012BB08
// Address: 0x12bb08 - 0x12bbd8
void sub_0012BB08_0x12bb08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012BB08_0x12bb08");
#endif

    switch (ctx->pc) {
        case 0x12bb58u: goto label_12bb58;
        case 0x12bb68u: goto label_12bb68;
        case 0x12bb70u: goto label_12bb70;
        case 0x12bb78u: goto label_12bb78;
        default: break;
    }

    ctx->pc = 0x12bb08u;

    // 0x12bb08: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12bb08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12bb0c: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x12bb0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x12bb10: 0x3c160021  lui         $s6, 0x21
    ctx->pc = 0x12bb10u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)33 << 16));
    // 0x12bb14: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12bb14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12bb18: 0x26c30530  addiu       $v1, $s6, 0x530
    ctx->pc = 0x12bb18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 22), 1328));
    // 0x12bb1c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12bb1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12bb20: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12bb20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12bb24: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12bb24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12bb28: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x12bb28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12bb2c: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x12bb2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x12bb30: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x12bb30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x12bb34: 0xdc620000  ld          $v0, 0x0($v1)
    ctx->pc = 0x12bb34u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12bb38: 0x14400015  bnez        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x12BB38u;
    {
        const bool branch_taken_0x12bb38 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12BB3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BB38u;
            // 0x12bb3c: 0x3c150021  lui         $s5, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12bb38) {
            ctx->pc = 0x12BB90u;
            goto label_12bb90;
        }
    }
    ctx->pc = 0x12BB40u;
    // 0x12bb40: 0x3c140021  lui         $s4, 0x21
    ctx->pc = 0x12bb40u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)33 << 16));
    // 0x12bb44: 0x60982d  daddu       $s3, $v1, $zero
    ctx->pc = 0x12bb44u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12bb48: 0x26b20528  addiu       $s2, $s5, 0x528
    ctx->pc = 0x12bb48u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 21), 1320));
    // 0x12bb4c: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x12bb4cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12bb50: 0x269004e4  addiu       $s0, $s4, 0x4E4
    ctx->pc = 0x12bb50u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), 1252));
    // 0x12bb54: 0x0  nop
    ctx->pc = 0x12bb54u;
    // NOP
label_12bb58:
    // 0x12bb58: 0xfe510000  sd          $s1, 0x0($s2)
    ctx->pc = 0x12bb58u;
    WRITE64(ADD32(GPR_U32(ctx, 18), 0), GPR_U64(ctx, 17));
    // 0x12bb5c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12bb5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12bb60: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12BB60u;
    SET_GPR_U32(ctx, 31, 0x12BB68u);
    ctx->pc = 0x12BB64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BB60u;
            // 0x12bb64: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BB68u; }
        if (ctx->pc != 0x12BB68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BB68u; }
        if (ctx->pc != 0x12BB68u) { return; }
    }
    ctx->pc = 0x12BB68u;
label_12bb68:
    // 0x12bb68: 0xc045154  jal         func_114550
    ctx->pc = 0x12BB68u;
    SET_GPR_U32(ctx, 31, 0x12BB70u);
    ctx->pc = 0x12BB6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BB68u;
            // 0x12bb6c: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114550u;
    if (runtime->hasFunction(0x114550u)) {
        auto targetFn = runtime->lookupFunction(0x114550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BB70u; }
        if (ctx->pc != 0x12BB70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114550_0x114550(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BB70u; }
        if (ctx->pc != 0x12BB70u) { return; }
    }
    ctx->pc = 0x12BB70u;
label_12bb70:
    // 0x12bb70: 0xc04516c  jal         func_1145B0
    ctx->pc = 0x12BB70u;
    SET_GPR_U32(ctx, 31, 0x12BB78u);
    ctx->pc = 0x12BB74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BB70u;
            // 0x12bb74: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1145B0u;
    if (runtime->hasFunction(0x1145B0u)) {
        auto targetFn = runtime->lookupFunction(0x1145B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BB78u; }
        if (ctx->pc != 0x12BB78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001145B0_0x1145b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BB78u; }
        if (ctx->pc != 0x12BB78u) { return; }
    }
    ctx->pc = 0x12BB78u;
label_12bb78:
    // 0x12bb78: 0xde630000  ld          $v1, 0x0($s3)
    ctx->pc = 0x12bb78u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12bb7c: 0x1060fff6  beqz        $v1, . + 4 + (-0xA << 2)
    ctx->pc = 0x12BB7Cu;
    {
        const bool branch_taken_0x12bb7c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x12BB80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BB7Cu;
            // 0x12bb80: 0x26c20530  addiu       $v0, $s6, 0x530 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), 1328));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12bb7c) {
            ctx->pc = 0x12BB58u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12bb58;
        }
    }
    ctx->pc = 0x12BB84u;
    // 0x12bb84: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x12BB84u;
    {
        const bool branch_taken_0x12bb84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12BB88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BB84u;
            // 0x12bb88: 0xdfb60030  ld          $s6, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12bb84) {
            ctx->pc = 0x12BB9Cu;
            goto label_12bb9c;
        }
    }
    ctx->pc = 0x12BB8Cu;
    // 0x12bb8c: 0x0  nop
    ctx->pc = 0x12bb8cu;
    // NOP
label_12bb90:
    // 0x12bb90: 0x3c140021  lui         $s4, 0x21
    ctx->pc = 0x12bb90u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)33 << 16));
    // 0x12bb94: 0x26c20530  addiu       $v0, $s6, 0x530
    ctx->pc = 0x12bb94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), 1328));
    // 0x12bb98: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x12bb98u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_12bb9c:
    // 0x12bb9c: 0x26a30528  addiu       $v1, $s5, 0x528
    ctx->pc = 0x12bb9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 1320));
    // 0x12bba0: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x12bba0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12bba4: 0x268404e4  addiu       $a0, $s4, 0x4E4
    ctx->pc = 0x12bba4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 1252));
    // 0x12bba8: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12bba8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12bbac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12bbacu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12bbb0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12bbb0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12bbb4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12bbb4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12bbb8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12bbb8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12bbbc: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x12bbbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12bbc0: 0xfc400000  sd          $zero, 0x0($v0)
    ctx->pc = 0x12bbc0u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 0));
    // 0x12bbc4: 0xfc600000  sd          $zero, 0x0($v1)
    ctx->pc = 0x12bbc4u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 0));
    // 0x12bbc8: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x12bbc8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x12bbcc: 0x3e00008  jr          $ra
    ctx->pc = 0x12BBCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12BBD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BBCCu;
            // 0x12bbd0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12BB58u: goto label_12bb58;
            case 0x12BB68u: goto label_12bb68;
            case 0x12BB70u: goto label_12bb70;
            case 0x12BB78u: goto label_12bb78;
            case 0x12BB90u: goto label_12bb90;
            case 0x12BB9Cu: goto label_12bb9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12BBD4u;
    // 0x12bbd4: 0x0  nop
    ctx->pc = 0x12bbd4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
