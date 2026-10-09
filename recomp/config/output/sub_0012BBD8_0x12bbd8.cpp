#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012BBD8
// Address: 0x12bbd8 - 0x12bca8
void sub_0012BBD8_0x12bbd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012BBD8_0x12bbd8");
#endif

    switch (ctx->pc) {
        case 0x12bc28u: goto label_12bc28;
        case 0x12bc38u: goto label_12bc38;
        case 0x12bc40u: goto label_12bc40;
        case 0x12bc48u: goto label_12bc48;
        default: break;
    }

    ctx->pc = 0x12bbd8u;

    // 0x12bbd8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12bbd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12bbdc: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x12bbdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x12bbe0: 0x3c160021  lui         $s6, 0x21
    ctx->pc = 0x12bbe0u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)33 << 16));
    // 0x12bbe4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12bbe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12bbe8: 0x26c30510  addiu       $v1, $s6, 0x510
    ctx->pc = 0x12bbe8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 22), 1296));
    // 0x12bbec: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12bbecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12bbf0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12bbf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12bbf4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12bbf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12bbf8: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x12bbf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12bbfc: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x12bbfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x12bc00: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x12bc00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x12bc04: 0xdc620000  ld          $v0, 0x0($v1)
    ctx->pc = 0x12bc04u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12bc08: 0x14400015  bnez        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x12BC08u;
    {
        const bool branch_taken_0x12bc08 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12BC0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BC08u;
            // 0x12bc0c: 0x3c150021  lui         $s5, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12bc08) {
            ctx->pc = 0x12BC60u;
            goto label_12bc60;
        }
    }
    ctx->pc = 0x12BC10u;
    // 0x12bc10: 0x3c140021  lui         $s4, 0x21
    ctx->pc = 0x12bc10u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)33 << 16));
    // 0x12bc14: 0x60982d  daddu       $s3, $v1, $zero
    ctx->pc = 0x12bc14u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12bc18: 0x26b20508  addiu       $s2, $s5, 0x508
    ctx->pc = 0x12bc18u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 21), 1288));
    // 0x12bc1c: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x12bc1cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12bc20: 0x269004dc  addiu       $s0, $s4, 0x4DC
    ctx->pc = 0x12bc20u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), 1244));
    // 0x12bc24: 0x0  nop
    ctx->pc = 0x12bc24u;
    // NOP
label_12bc28:
    // 0x12bc28: 0xfe510000  sd          $s1, 0x0($s2)
    ctx->pc = 0x12bc28u;
    WRITE64(ADD32(GPR_U32(ctx, 18), 0), GPR_U64(ctx, 17));
    // 0x12bc2c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12bc2cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12bc30: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12BC30u;
    SET_GPR_U32(ctx, 31, 0x12BC38u);
    ctx->pc = 0x12BC34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BC30u;
            // 0x12bc34: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BC38u; }
        if (ctx->pc != 0x12BC38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BC38u; }
        if (ctx->pc != 0x12BC38u) { return; }
    }
    ctx->pc = 0x12BC38u;
label_12bc38:
    // 0x12bc38: 0xc045154  jal         func_114550
    ctx->pc = 0x12BC38u;
    SET_GPR_U32(ctx, 31, 0x12BC40u);
    ctx->pc = 0x12BC3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BC38u;
            // 0x12bc3c: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114550u;
    if (runtime->hasFunction(0x114550u)) {
        auto targetFn = runtime->lookupFunction(0x114550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BC40u; }
        if (ctx->pc != 0x12BC40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114550_0x114550(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BC40u; }
        if (ctx->pc != 0x12BC40u) { return; }
    }
    ctx->pc = 0x12BC40u;
label_12bc40:
    // 0x12bc40: 0xc04516c  jal         func_1145B0
    ctx->pc = 0x12BC40u;
    SET_GPR_U32(ctx, 31, 0x12BC48u);
    ctx->pc = 0x12BC44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BC40u;
            // 0x12bc44: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1145B0u;
    if (runtime->hasFunction(0x1145B0u)) {
        auto targetFn = runtime->lookupFunction(0x1145B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BC48u; }
        if (ctx->pc != 0x12BC48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001145B0_0x1145b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BC48u; }
        if (ctx->pc != 0x12BC48u) { return; }
    }
    ctx->pc = 0x12BC48u;
label_12bc48:
    // 0x12bc48: 0xde630000  ld          $v1, 0x0($s3)
    ctx->pc = 0x12bc48u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12bc4c: 0x1060fff6  beqz        $v1, . + 4 + (-0xA << 2)
    ctx->pc = 0x12BC4Cu;
    {
        const bool branch_taken_0x12bc4c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x12BC50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BC4Cu;
            // 0x12bc50: 0x26c20510  addiu       $v0, $s6, 0x510 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), 1296));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12bc4c) {
            ctx->pc = 0x12BC28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12bc28;
        }
    }
    ctx->pc = 0x12BC54u;
    // 0x12bc54: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x12BC54u;
    {
        const bool branch_taken_0x12bc54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12BC58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BC54u;
            // 0x12bc58: 0xdfb60030  ld          $s6, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12bc54) {
            ctx->pc = 0x12BC6Cu;
            goto label_12bc6c;
        }
    }
    ctx->pc = 0x12BC5Cu;
    // 0x12bc5c: 0x0  nop
    ctx->pc = 0x12bc5cu;
    // NOP
label_12bc60:
    // 0x12bc60: 0x3c140021  lui         $s4, 0x21
    ctx->pc = 0x12bc60u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)33 << 16));
    // 0x12bc64: 0x26c20510  addiu       $v0, $s6, 0x510
    ctx->pc = 0x12bc64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), 1296));
    // 0x12bc68: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x12bc68u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_12bc6c:
    // 0x12bc6c: 0x26a30508  addiu       $v1, $s5, 0x508
    ctx->pc = 0x12bc6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 1288));
    // 0x12bc70: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x12bc70u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12bc74: 0x268404dc  addiu       $a0, $s4, 0x4DC
    ctx->pc = 0x12bc74u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 1244));
    // 0x12bc78: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12bc78u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12bc7c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12bc7cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12bc80: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12bc80u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12bc84: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12bc84u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12bc88: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12bc88u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12bc8c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x12bc8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12bc90: 0xfc400000  sd          $zero, 0x0($v0)
    ctx->pc = 0x12bc90u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 0));
    // 0x12bc94: 0xfc600000  sd          $zero, 0x0($v1)
    ctx->pc = 0x12bc94u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 0));
    // 0x12bc98: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x12bc98u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x12bc9c: 0x3e00008  jr          $ra
    ctx->pc = 0x12BC9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12BCA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BC9Cu;
            // 0x12bca0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12BC28u: goto label_12bc28;
            case 0x12BC38u: goto label_12bc38;
            case 0x12BC40u: goto label_12bc40;
            case 0x12BC48u: goto label_12bc48;
            case 0x12BC60u: goto label_12bc60;
            case 0x12BC6Cu: goto label_12bc6c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12BCA4u;
    // 0x12bca4: 0x0  nop
    ctx->pc = 0x12bca4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
