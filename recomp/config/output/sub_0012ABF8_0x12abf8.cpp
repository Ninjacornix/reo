#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012ABF8
// Address: 0x12abf8 - 0x12ac90
void sub_0012ABF8_0x12abf8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012ABF8_0x12abf8");
#endif

    switch (ctx->pc) {
        case 0x12ac40u: goto label_12ac40;
        case 0x12ac54u: goto label_12ac54;
        case 0x12ac5cu: goto label_12ac5c;
        default: break;
    }

    ctx->pc = 0x12abf8u;

    // 0x12abf8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x12abf8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x12abfc: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12abfcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12ac00: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12ac00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12ac04: 0x24440508  addiu       $a0, $v0, 0x508
    ctx->pc = 0x12ac04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 1288));
    // 0x12ac08: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12ac08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12ac0c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12ac0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12ac10: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12ac10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12ac14: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x12ac14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x12ac18: 0xdc830000  ld          $v1, 0x0($a0)
    ctx->pc = 0x12ac18u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12ac1c: 0x14600012  bnez        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x12AC1Cu;
    {
        const bool branch_taken_0x12ac1c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12AC20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AC1Cu;
            // 0x12ac20: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ac1c) {
            ctx->pc = 0x12AC68u;
            goto label_12ac68;
        }
    }
    ctx->pc = 0x12AC24u;
    // 0x12ac24: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12ac24u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12ac28: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12ac28u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12ac2c: 0x245104a8  addiu       $s1, $v0, 0x4A8
    ctx->pc = 0x12ac2cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 1192));
    // 0x12ac30: 0x2470048c  addiu       $s0, $v1, 0x48C
    ctx->pc = 0x12ac30u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 1164));
    // 0x12ac34: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x12ac34u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ac38: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x12ac38u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12ac3c: 0x0  nop
    ctx->pc = 0x12ac3cu;
    // NOP
label_12ac40:
    // 0x12ac40: 0xde220000  ld          $v0, 0x0($s1)
    ctx->pc = 0x12ac40u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12ac44: 0x64420001  daddiu      $v0, $v0, 0x1
    ctx->pc = 0x12ac44u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)1);
    // 0x12ac48: 0xfe220000  sd          $v0, 0x0($s1)
    ctx->pc = 0x12ac48u;
    WRITE64(ADD32(GPR_U32(ctx, 17), 0), GPR_U64(ctx, 2));
    // 0x12ac4c: 0xc0507ea  jal         func_141FA8
    ctx->pc = 0x12AC4Cu;
    SET_GPR_U32(ctx, 31, 0x12AC54u);
    ctx->pc = 0x12AC50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AC4Cu;
            // 0x12ac50: 0xae120000  sw          $s2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141FA8u;
    if (runtime->hasFunction(0x141FA8u)) {
        auto targetFn = runtime->lookupFunction(0x141FA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AC54u; }
        if (ctx->pc != 0x12AC54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141FA8_0x141fa8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AC54u; }
        if (ctx->pc != 0x12AC54u) { return; }
    }
    ctx->pc = 0x12AC54u;
label_12ac54:
    // 0x12ac54: 0xc04ac36  jal         func_12B0D8
    ctx->pc = 0x12AC54u;
    SET_GPR_U32(ctx, 31, 0x12AC5Cu);
    ctx->pc = 0x12AC58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AC54u;
            // 0x12ac58: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B0D8u;
    if (runtime->hasFunction(0x12B0D8u)) {
        auto targetFn = runtime->lookupFunction(0x12B0D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AC5Cu; }
        if (ctx->pc != 0x12AC5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0D8_0x12b0d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AC5Cu; }
        if (ctx->pc != 0x12AC5Cu) { return; }
    }
    ctx->pc = 0x12AC5Cu;
label_12ac5c:
    // 0x12ac5c: 0xde620000  ld          $v0, 0x0($s3)
    ctx->pc = 0x12ac5cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12ac60: 0x1040fff7  beqz        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x12AC60u;
    {
        const bool branch_taken_0x12ac60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12AC64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AC60u;
            // 0x12ac64: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ac60) {
            ctx->pc = 0x12AC40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12ac40;
        }
    }
    ctx->pc = 0x12AC68u;
label_12ac68:
    // 0x12ac68: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12ac68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12ac6c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12ac6cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12ac70: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12ac70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12ac74: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12ac74u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12ac78: 0x24420510  addiu       $v0, $v0, 0x510
    ctx->pc = 0x12ac78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1296));
    // 0x12ac7c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12ac7cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12ac80: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x12ac80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12ac84: 0xfc430000  sd          $v1, 0x0($v0)
    ctx->pc = 0x12ac84u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 3));
    // 0x12ac88: 0x8045118  j           func_114460
    ctx->pc = 0x12AC88u;
    ctx->pc = 0x12AC8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AC88u;
            // 0x12ac8c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114460u;
    if (runtime->hasFunction(0x114460u)) {
        auto targetFn = runtime->lookupFunction(0x114460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114460_0x114460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12AC90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
