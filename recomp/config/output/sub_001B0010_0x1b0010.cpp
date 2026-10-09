#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0010
// Address: 0x1b0010 - 0x1b0084
void sub_001B0010_0x1b0010(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0010_0x1b0010");
#endif

    switch (ctx->pc) {
        case 0x1b0024u: goto label_1b0024;
        case 0x1b0060u: goto label_1b0060;
        case 0x1b0074u: goto label_1b0074;
        default: break;
    }

    ctx->pc = 0x1b0010u;

    // 0x1b0010: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b0010u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b0014: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b0014u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b0018: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b0018u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b001c: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B001Cu;
    SET_GPR_U32(ctx, 31, 0x1B0024u);
    ctx->pc = 0x1B0020u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B001Cu;
            // 0x1b0020: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0024u; }
        if (ctx->pc != 0x1B0024u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0024u; }
        if (ctx->pc != 0x1B0024u) { return; }
    }
    ctx->pc = 0x1B0024u;
label_1b0024:
    // 0x1b0024: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1b0024u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b0028: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B0028u;
    {
        const bool branch_taken_0x1b0028 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B002Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0028u;
            // 0x1b002c: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0028) {
            ctx->pc = 0x1B0074u;
            goto label_1b0074;
        }
    }
    ctx->pc = 0x1B0030u;
    // 0x1b0030: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B0030u;
    {
        const bool branch_taken_0x1b0030 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b0030) {
            ctx->pc = 0x1B0074u;
            goto label_1b0074;
        }
    }
    ctx->pc = 0x1B0038u;
    // 0x1b0038: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b0038u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b003c: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1B003Cu;
    {
        const bool branch_taken_0x1b003c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B0040u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B003Cu;
            // 0x1b0040: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b003c) {
            ctx->pc = 0x1B0068u;
            goto label_1b0068;
        }
    }
    ctx->pc = 0x1B0044u;
    // 0x1b0044: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B0044u;
    {
        const bool branch_taken_0x1b0044 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0048u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0044u;
            // 0x1b0048: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0044) {
            ctx->pc = 0x1B0054u;
            goto label_1b0054;
        }
    }
    ctx->pc = 0x1B004Cu;
    // 0x1b004c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1B004Cu;
    {
        const bool branch_taken_0x1b004c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B004Cu;
            // 0x1b0050: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b004c) {
            ctx->pc = 0x1B0078u;
            goto label_1b0078;
        }
    }
    ctx->pc = 0x1B0054u;
label_1b0054:
    // 0x1b0054: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b0054u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b0058: 0xc2046cc  jal         func_811B30
    ctx->pc = 0x1B0058u;
    SET_GPR_U32(ctx, 31, 0x1B0060u);
    ctx->pc = 0x1B005Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0058u;
            // 0x1b005c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x811B30u;
    {
        auto targetFn = runtime->lookupFunction(0x811B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0060u; }
        if (ctx->pc != 0x1B0060u) { return; }
    }
    ctx->pc = 0x1B0060u;
label_1b0060:
    // 0x1b0060: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B0060u;
    {
        const bool branch_taken_0x1b0060 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b0060) {
            ctx->pc = 0x1B0074u;
            goto label_1b0074;
        }
    }
    ctx->pc = 0x1B0068u;
label_1b0068:
    // 0x1b0068: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b0068u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b006c: 0xc2044c0  jal         func_811300
    ctx->pc = 0x1B006Cu;
    SET_GPR_U32(ctx, 31, 0x1B0074u);
    ctx->pc = 0x1B0070u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B006Cu;
            // 0x1b0070: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x811300u;
    {
        auto targetFn = runtime->lookupFunction(0x811300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0074u; }
        if (ctx->pc != 0x1B0074u) { return; }
    }
    ctx->pc = 0x1B0074u;
label_1b0074:
    // 0x1b0074: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b0074u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b0078:
    // 0x1b0078: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b0078u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b007c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B007Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B007Cu;
            // 0x1b0080: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0024u: goto label_1b0024;
            case 0x1B0054u: goto label_1b0054;
            case 0x1B0060u: goto label_1b0060;
            case 0x1B0068u: goto label_1b0068;
            case 0x1B0074u: goto label_1b0074;
            case 0x1B0078u: goto label_1b0078;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0084u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
