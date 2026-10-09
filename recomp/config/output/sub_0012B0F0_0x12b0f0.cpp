#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B0F0
// Address: 0x12b0f0 - 0x12b158
void sub_0012B0F0_0x12b0f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B0F0_0x12b0f0");
#endif

    switch (ctx->pc) {
        case 0x12b114u: goto label_12b114;
        case 0x12b138u: goto label_12b138;
        default: break;
    }

    ctx->pc = 0x12b0f0u;

    // 0x12b0f0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x12b0f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x12b0f4: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x12b0f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x12b0f8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12b0f8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b0fc: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x12b0fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x12b100: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x12b100u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b104: 0x1200000d  beqz        $s0, . + 4 + (0xD << 2)
    ctx->pc = 0x12B104u;
    {
        const bool branch_taken_0x12b104 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x12B108u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B104u;
            // 0x12b108: 0xffbf0040  sd          $ra, 0x40($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12b104) {
            ctx->pc = 0x12B13Cu;
            goto label_12b13c;
        }
    }
    ctx->pc = 0x12B10Cu;
    // 0x12b10c: 0xc045148  jal         func_114520
    ctx->pc = 0x12B10Cu;
    SET_GPR_U32(ctx, 31, 0x12B114u);
    ctx->pc = 0x12B110u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B10Cu;
            // 0x12b110: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114520u;
    if (runtime->hasFunction(0x114520u)) {
        auto targetFn = runtime->lookupFunction(0x114520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B114u; }
        if (ctx->pc != 0x12B114u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114520_0x114520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B114u; }
        if (ctx->pc != 0x12B114u) { return; }
    }
    ctx->pc = 0x12B114u;
label_12b114:
    // 0x12b114: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12b114u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b118: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x12b118u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12b11c: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x12b11cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x12b120: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x12B120u;
    {
        const bool branch_taken_0x12b120 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x12B124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B120u;
            // 0x12b124: 0x2405000c  addiu       $a1, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12b120) {
            ctx->pc = 0x12B130u;
            goto label_12b130;
        }
    }
    ctx->pc = 0x12B128u;
    // 0x12b128: 0x14650005  bne         $v1, $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x12B128u;
    {
        const bool branch_taken_0x12b128 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x12B12Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B128u;
            // 0x12b12c: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12b128) {
            ctx->pc = 0x12B140u;
            goto label_12b140;
        }
    }
    ctx->pc = 0x12B130u;
label_12b130:
    // 0x12b130: 0xc04516c  jal         func_1145B0
    ctx->pc = 0x12B130u;
    SET_GPR_U32(ctx, 31, 0x12B138u);
    ctx->pc = 0x1145B0u;
    if (runtime->hasFunction(0x1145B0u)) {
        auto targetFn = runtime->lookupFunction(0x1145B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B138u; }
        if (ctx->pc != 0x12B138u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001145B0_0x1145b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B138u; }
        if (ctx->pc != 0x12B138u) { return; }
    }
    ctx->pc = 0x12B138u;
label_12b138:
    // 0x12b138: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12b138u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_12b13c:
    // 0x12b13c: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x12b13cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_12b140:
    // 0x12b140: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x12b140u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12b144: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x12b144u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12b148: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x12b148u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12b14c: 0x3e00008  jr          $ra
    ctx->pc = 0x12B14Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12B150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B14Cu;
            // 0x12b150: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12B114u: goto label_12b114;
            case 0x12B130u: goto label_12b130;
            case 0x12B138u: goto label_12b138;
            case 0x12B13Cu: goto label_12b13c;
            case 0x12B140u: goto label_12b140;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12B154u;
    // 0x12b154: 0x0  nop
    ctx->pc = 0x12b154u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
