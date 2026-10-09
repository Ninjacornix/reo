#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1970
// Address: 0x1b1970 - 0x1b19d0
void sub_001B1970_0x1b1970(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1970_0x1b1970");
#endif

    switch (ctx->pc) {
        case 0x1b198cu: goto label_1b198c;
        case 0x1b19a4u: goto label_1b19a4;
        default: break;
    }

    ctx->pc = 0x1b1970u;

    // 0x1b1970: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b1970u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b1974: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b1974u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b1978: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b1978u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b197c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b197cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b1980: 0x3c110057  lui         $s1, 0x57
    ctx->pc = 0x1b1980u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)87 << 16));
    // 0x1b1984: 0x263197d0  addiu       $s1, $s1, -0x6830
    ctx->pc = 0x1b1984u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294940624));
    // 0x1b1988: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1b1988u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b198c:
    // 0x1b198c: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x1b198cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1b1990: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1b1990u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b1994: 0x10830005  beq         $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B1994u;
    {
        const bool branch_taken_0x1b1994 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b1994) {
            ctx->pc = 0x1B19ACu;
            goto label_1b19ac;
        }
    }
    ctx->pc = 0x1B199Cu;
    // 0x1b199c: 0xc064960  jal         func_192580
    ctx->pc = 0x1B199Cu;
    SET_GPR_U32(ctx, 31, 0x1B19A4u);
    ctx->pc = 0x192580u;
    if (runtime->hasFunction(0x192580u)) {
        auto targetFn = runtime->lookupFunction(0x192580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B19A4u; }
        if (ctx->pc != 0x1B19A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192580_0x192580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B19A4u; }
        if (ctx->pc != 0x1B19A4u) { return; }
    }
    ctx->pc = 0x1B19A4u;
label_1b19a4:
    // 0x1b19a4: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1b19a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b19a8: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1b19a8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
label_1b19ac:
    // 0x1b19ac: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b19acu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b19b0: 0x2a030040  slti        $v1, $s0, 0x40
    ctx->pc = 0x1b19b0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x1b19b4: 0x1460fff5  bnez        $v1, . + 4 + (-0xB << 2)
    ctx->pc = 0x1B19B4u;
    {
        const bool branch_taken_0x1b19b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B19B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B19B4u;
            // 0x1b19b8: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b19b4) {
            ctx->pc = 0x1B198Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b198c;
        }
    }
    ctx->pc = 0x1B19BCu;
    // 0x1b19bc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b19bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b19c0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b19c0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b19c4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b19c4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b19c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B19C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B19CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B19C8u;
            // 0x1b19cc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B198Cu: goto label_1b198c;
            case 0x1B19A4u: goto label_1b19a4;
            case 0x1B19ACu: goto label_1b19ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B19D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
