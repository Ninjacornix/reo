#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1050
// Address: 0x1c1050 - 0x1c10c0
void sub_001C1050_0x1c1050(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1050_0x1c1050");
#endif

    switch (ctx->pc) {
        case 0x1c1078u: goto label_1c1078;
        case 0x1c10b0u: goto label_1c10b0;
        default: break;
    }

    ctx->pc = 0x1c1050u;

    // 0x1c1050: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c1050u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c1054: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c1054u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c1058: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c1058u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c105c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1c105cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c1060: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1060u;
    {
        const bool branch_taken_0x1c1060 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1060u;
            // 0x1c1064: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1060) {
            ctx->pc = 0x1C1070u;
            goto label_1c1070;
        }
    }
    ctx->pc = 0x1C1068u;
    // 0x1c1068: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1C1068u;
    {
        const bool branch_taken_0x1c1068 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C106Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1068u;
            // 0x1c106c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1068) {
            ctx->pc = 0x1C10A8u;
            goto label_1c10a8;
        }
    }
    ctx->pc = 0x1C1070u;
label_1c1070:
    // 0x1c1070: 0xc070034  jal         func_1C00D0
    ctx->pc = 0x1C1070u;
    SET_GPR_U32(ctx, 31, 0x1C1078u);
    ctx->pc = 0x1C00D0u;
    if (runtime->hasFunction(0x1C00D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C00D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1078u; }
        if (ctx->pc != 0x1C1078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C00D0_0x1c00d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1078u; }
        if (ctx->pc != 0x1C1078u) { return; }
    }
    ctx->pc = 0x1C1078u;
label_1c1078:
    // 0x1c1078: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c1078u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c107c: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C107Cu;
    {
        const bool branch_taken_0x1c107c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c107c) {
            ctx->pc = 0x1C109Cu;
            goto label_1c109c;
        }
    }
    ctx->pc = 0x1C1084u;
    // 0x1c1084: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1084u;
    {
        const bool branch_taken_0x1c1084 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c1084) {
            ctx->pc = 0x1C1094u;
            goto label_1c1094;
        }
    }
    ctx->pc = 0x1C108Cu;
    // 0x1c108c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C108Cu;
    {
        const bool branch_taken_0x1c108c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c108c) {
            ctx->pc = 0x1C10A4u;
            goto label_1c10a4;
        }
    }
    ctx->pc = 0x1C1094u;
label_1c1094:
    // 0x1c1094: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1094u;
    {
        const bool branch_taken_0x1c1094 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1098u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1094u;
            // 0x1c1098: 0xae000024  sw          $zero, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1094) {
            ctx->pc = 0x1C10A4u;
            goto label_1c10a4;
        }
    }
    ctx->pc = 0x1C109Cu;
label_1c109c:
    // 0x1c109c: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c109cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c10a0: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x1c10a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
label_1c10a4:
    // 0x1c10a4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c10a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c10a8:
    // 0x1c10a8: 0xc070108  jal         func_1C0420
    ctx->pc = 0x1C10A8u;
    SET_GPR_U32(ctx, 31, 0x1C10B0u);
    ctx->pc = 0x1C0420u;
    if (runtime->hasFunction(0x1C0420u)) {
        auto targetFn = runtime->lookupFunction(0x1C0420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C10B0u; }
        if (ctx->pc != 0x1C10B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0420_0x1c0420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C10B0u; }
        if (ctx->pc != 0x1C10B0u) { return; }
    }
    ctx->pc = 0x1C10B0u;
label_1c10b0:
    // 0x1c10b0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c10b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c10b4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c10b4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c10b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C10B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C10BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C10B8u;
            // 0x1c10bc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1070u: goto label_1c1070;
            case 0x1C1078u: goto label_1c1078;
            case 0x1C1094u: goto label_1c1094;
            case 0x1C109Cu: goto label_1c109c;
            case 0x1C10A4u: goto label_1c10a4;
            case 0x1C10A8u: goto label_1c10a8;
            case 0x1C10B0u: goto label_1c10b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C10C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
