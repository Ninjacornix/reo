#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0090
// Address: 0x1b0090 - 0x1b0104
void sub_001B0090_0x1b0090(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0090_0x1b0090");
#endif

    switch (ctx->pc) {
        case 0x1b00a4u: goto label_1b00a4;
        case 0x1b00e0u: goto label_1b00e0;
        case 0x1b00f4u: goto label_1b00f4;
        default: break;
    }

    ctx->pc = 0x1b0090u;

    // 0x1b0090: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b0090u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b0094: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b0094u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b0098: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b0098u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b009c: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B009Cu;
    SET_GPR_U32(ctx, 31, 0x1B00A4u);
    ctx->pc = 0x1B00A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B009Cu;
            // 0x1b00a0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B00A4u; }
        if (ctx->pc != 0x1B00A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B00A4u; }
        if (ctx->pc != 0x1B00A4u) { return; }
    }
    ctx->pc = 0x1B00A4u;
label_1b00a4:
    // 0x1b00a4: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1b00a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b00a8: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B00A8u;
    {
        const bool branch_taken_0x1b00a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B00ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B00A8u;
            // 0x1b00ac: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b00a8) {
            ctx->pc = 0x1B00F4u;
            goto label_1b00f4;
        }
    }
    ctx->pc = 0x1B00B0u;
    // 0x1b00b0: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B00B0u;
    {
        const bool branch_taken_0x1b00b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b00b0) {
            ctx->pc = 0x1B00F4u;
            goto label_1b00f4;
        }
    }
    ctx->pc = 0x1B00B8u;
    // 0x1b00b8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b00b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b00bc: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1B00BCu;
    {
        const bool branch_taken_0x1b00bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B00C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B00BCu;
            // 0x1b00c0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b00bc) {
            ctx->pc = 0x1B00E8u;
            goto label_1b00e8;
        }
    }
    ctx->pc = 0x1B00C4u;
    // 0x1b00c4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B00C4u;
    {
        const bool branch_taken_0x1b00c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B00C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B00C4u;
            // 0x1b00c8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b00c4) {
            ctx->pc = 0x1B00D4u;
            goto label_1b00d4;
        }
    }
    ctx->pc = 0x1B00CCu;
    // 0x1b00cc: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1B00CCu;
    {
        const bool branch_taken_0x1b00cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B00D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B00CCu;
            // 0x1b00d0: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b00cc) {
            ctx->pc = 0x1B00F8u;
            goto label_1b00f8;
        }
    }
    ctx->pc = 0x1B00D4u;
label_1b00d4:
    // 0x1b00d4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b00d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b00d8: 0xc2046cc  jal         func_811B30
    ctx->pc = 0x1B00D8u;
    SET_GPR_U32(ctx, 31, 0x1B00E0u);
    ctx->pc = 0x1B00DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B00D8u;
            // 0x1b00dc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x811B30u;
    {
        auto targetFn = runtime->lookupFunction(0x811B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B00E0u; }
        if (ctx->pc != 0x1B00E0u) { return; }
    }
    ctx->pc = 0x1B00E0u;
label_1b00e0:
    // 0x1b00e0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B00E0u;
    {
        const bool branch_taken_0x1b00e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b00e0) {
            ctx->pc = 0x1B00F4u;
            goto label_1b00f4;
        }
    }
    ctx->pc = 0x1B00E8u;
label_1b00e8:
    // 0x1b00e8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b00e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b00ec: 0xc204504  jal         func_811410
    ctx->pc = 0x1B00ECu;
    SET_GPR_U32(ctx, 31, 0x1B00F4u);
    ctx->pc = 0x1B00F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B00ECu;
            // 0x1b00f0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x811410u;
    {
        auto targetFn = runtime->lookupFunction(0x811410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B00F4u; }
        if (ctx->pc != 0x1B00F4u) { return; }
    }
    ctx->pc = 0x1B00F4u;
label_1b00f4:
    // 0x1b00f4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b00f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b00f8:
    // 0x1b00f8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b00f8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b00fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1B00FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0100u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B00FCu;
            // 0x1b0100: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B00A4u: goto label_1b00a4;
            case 0x1B00D4u: goto label_1b00d4;
            case 0x1B00E0u: goto label_1b00e0;
            case 0x1B00E8u: goto label_1b00e8;
            case 0x1B00F4u: goto label_1b00f4;
            case 0x1B00F8u: goto label_1b00f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0104u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
