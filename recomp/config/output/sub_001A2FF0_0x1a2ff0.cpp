#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A2FF0
// Address: 0x1a2ff0 - 0x1a3090
void sub_001A2FF0_0x1a2ff0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A2FF0_0x1a2ff0");
#endif

    switch (ctx->pc) {
        case 0x1a300cu: goto label_1a300c;
        case 0x1a3030u: goto label_1a3030;
        case 0x1a3054u: goto label_1a3054;
        default: break;
    }

    ctx->pc = 0x1a2ff0u;

    // 0x1a2ff0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1a2ff0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1a2ff4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1a2ff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1a2ff8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a2ff8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a2ffc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1a2ffcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3000: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1a3000u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3004: 0xc068c84  jal         func_1A3210
    ctx->pc = 0x1A3004u;
    SET_GPR_U32(ctx, 31, 0x1A300Cu);
    ctx->pc = 0x1A3008u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3004u;
            // 0x1a3008: 0xc0282d  daddu       $a1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3210u;
    if (runtime->hasFunction(0x1A3210u)) {
        auto targetFn = runtime->lookupFunction(0x1A3210u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A300Cu; }
        if (ctx->pc != 0x1A300Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3210_0x1a3210(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A300Cu; }
        if (ctx->pc != 0x1A300Cu) { return; }
    }
    ctx->pc = 0x1A300Cu;
label_1a300c:
    // 0x1a300c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1a300cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a3010: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1a3010u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1a3014: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3014u;
    {
        const bool branch_taken_0x1a3014 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A3018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3014u;
            // 0x1a3018: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3014) {
            ctx->pc = 0x1A3024u;
            goto label_1a3024;
        }
    }
    ctx->pc = 0x1A301Cu;
    // 0x1a301c: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1A301Cu;
    {
        const bool branch_taken_0x1a301c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3020u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A301Cu;
            // 0x1a3020: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a301c) {
            ctx->pc = 0x1A3078u;
            goto label_1a3078;
        }
    }
    ctx->pc = 0x1A3024u;
label_1a3024:
    // 0x1a3024: 0x3c050010  lui         $a1, 0x10
    ctx->pc = 0x1a3024u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)16 << 16));
    // 0x1a3028: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A3028u;
    SET_GPR_U32(ctx, 31, 0x1A3030u);
    ctx->pc = 0x1A302Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3028u;
            // 0x1a302c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3030u; }
        if (ctx->pc != 0x1A3030u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3030u; }
        if (ctx->pc != 0x1A3030u) { return; }
    }
    ctx->pc = 0x1A3030u;
label_1a3030:
    // 0x1a3030: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3030u;
    {
        const bool branch_taken_0x1a3030 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3030) {
            ctx->pc = 0x1A3040u;
            goto label_1a3040;
        }
    }
    ctx->pc = 0x1A3038u;
    // 0x1a3038: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1A3038u;
    {
        const bool branch_taken_0x1a3038 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A303Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3038u;
            // 0x1a303c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3038) {
            ctx->pc = 0x1A3078u;
            goto label_1a3078;
        }
    }
    ctx->pc = 0x1A3040u;
label_1a3040:
    // 0x1a3040: 0x8c440004  lw          $a0, 0x4($v0)
    ctx->pc = 0x1a3040u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1a3044: 0x2446000c  addiu       $a2, $v0, 0xC
    ctx->pc = 0x1a3044u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1a3048: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1a3048u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a304c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1A304Cu;
    {
        const bool branch_taken_0x1a304c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A304Cu;
            // 0x1a3050: 0xa6040000  sh          $a0, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a304c) {
            ctx->pc = 0x1A306Cu;
            goto label_1a306c;
        }
    }
    ctx->pc = 0x1A3054u;
label_1a3054:
    // 0x1a3054: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x1a3054u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1a3058: 0x51040  sll         $v0, $a1, 1
    ctx->pc = 0x1a3058u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1a305c: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x1a305cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1a3060: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1a3060u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1a3064: 0xa4430002  sh          $v1, 0x2($v0)
    ctx->pc = 0x1a3064u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 2), (uint16_t)GPR_U32(ctx, 3));
    // 0x1a3068: 0x24c60004  addiu       $a2, $a2, 0x4
    ctx->pc = 0x1a3068u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
label_1a306c:
    // 0x1a306c: 0xa4102a  slt         $v0, $a1, $a0
    ctx->pc = 0x1a306cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1a3070: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1A3070u;
    {
        const bool branch_taken_0x1a3070 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A3074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3070u;
            // 0x1a3074: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3070) {
            ctx->pc = 0x1A3054u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a3054;
        }
    }
    ctx->pc = 0x1A3078u;
label_1a3078:
    // 0x1a3078: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1a3078u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a307c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a307cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a3080: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3080u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A3084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3080u;
            // 0x1a3084: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A300Cu: goto label_1a300c;
            case 0x1A3024u: goto label_1a3024;
            case 0x1A3030u: goto label_1a3030;
            case 0x1A3040u: goto label_1a3040;
            case 0x1A3054u: goto label_1a3054;
            case 0x1A306Cu: goto label_1a306c;
            case 0x1A3078u: goto label_1a3078;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A3088u;
    // 0x1a3088: 0x0  nop
    ctx->pc = 0x1a3088u;
    // NOP
    // 0x1a308c: 0x0  nop
    ctx->pc = 0x1a308cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
