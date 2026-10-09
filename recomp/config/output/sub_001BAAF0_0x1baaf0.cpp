#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BAAF0
// Address: 0x1baaf0 - 0x1bab60
void sub_001BAAF0_0x1baaf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BAAF0_0x1baaf0");
#endif

    switch (ctx->pc) {
        case 0x1bab0cu: goto label_1bab0c;
        case 0x1bab28u: goto label_1bab28;
        case 0x1bab40u: goto label_1bab40;
        default: break;
    }

    ctx->pc = 0x1baaf0u;

    // 0x1baaf0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1baaf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1baaf4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1baaf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1baaf8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1baaf8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1baafc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1baafcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bab00: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1bab00u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bab04: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1BAB04u;
    {
        const bool branch_taken_0x1bab04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BAB08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAB04u;
            // 0x1bab08: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bab04) {
            ctx->pc = 0x1BAB2Cu;
            goto label_1bab2c;
        }
    }
    ctx->pc = 0x1BAB0Cu;
label_1bab0c:
    // 0x1bab0c: 0x902243c0  lbu         $v0, 0x43C0($at)
    ctx->pc = 0x1bab0cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17344)));
    // 0x1bab10: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BAB10u;
    {
        const bool branch_taken_0x1bab10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BAB14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAB10u;
            // 0x1bab14: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bab10) {
            ctx->pc = 0x1BAB20u;
            goto label_1bab20;
        }
    }
    ctx->pc = 0x1BAB18u;
    // 0x1bab18: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x1bab18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x1bab1c: 0xac204178  sw          $zero, 0x4178($at)
    ctx->pc = 0x1bab1cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16760), GPR_U32(ctx, 0));
label_1bab20:
    // 0x1bab20: 0xc067db0  jal         func_19F6C0
    ctx->pc = 0x1BAB20u;
    SET_GPR_U32(ctx, 31, 0x1BAB28u);
    ctx->pc = 0x19F6C0u;
    if (runtime->hasFunction(0x19F6C0u)) {
        auto targetFn = runtime->lookupFunction(0x19F6C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAB28u; }
        if (ctx->pc != 0x1BAB28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019F6C0_0x19f6c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAB28u; }
        if (ctx->pc != 0x1BAB28u) { return; }
    }
    ctx->pc = 0x1BAB28u;
label_1bab28:
    // 0x1bab28: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1bab28u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1bab2c:
    // 0x1bab2c: 0x211102a  slt         $v0, $s0, $s1
    ctx->pc = 0x1bab2cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x1bab30: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1BAB30u;
    {
        const bool branch_taken_0x1bab30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BAB34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAB30u;
            // 0x1bab34: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bab30) {
            ctx->pc = 0x1BAB0Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bab0c;
        }
    }
    ctx->pc = 0x1BAB38u;
    // 0x1bab38: 0xc06b18c  jal         func_1AC630
    ctx->pc = 0x1BAB38u;
    SET_GPR_U32(ctx, 31, 0x1BAB40u);
    ctx->pc = 0x1AC630u;
    if (runtime->hasFunction(0x1AC630u)) {
        auto targetFn = runtime->lookupFunction(0x1AC630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAB40u; }
        if (ctx->pc != 0x1BAB40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AC630_0x1ac630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAB40u; }
        if (ctx->pc != 0x1BAB40u) { return; }
    }
    ctx->pc = 0x1BAB40u;
label_1bab40:
    // 0x1bab40: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bab40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bab44: 0xac2243f4  sw          $v0, 0x43F4($at)
    ctx->pc = 0x1bab44u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17396), GPR_U32(ctx, 2));
    // 0x1bab48: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1bab48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1bab4c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1bab4cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bab50: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bab50u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bab54: 0x3e00008  jr          $ra
    ctx->pc = 0x1BAB54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BAB58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAB54u;
            // 0x1bab58: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BAB0Cu: goto label_1bab0c;
            case 0x1BAB20u: goto label_1bab20;
            case 0x1BAB28u: goto label_1bab28;
            case 0x1BAB2Cu: goto label_1bab2c;
            case 0x1BAB40u: goto label_1bab40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BAB5Cu;
    // 0x1bab5c: 0x0  nop
    ctx->pc = 0x1bab5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
