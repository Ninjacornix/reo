#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF910
// Address: 0x1af910 - 0x1af970
void sub_001AF910_0x1af910(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF910_0x1af910");
#endif

    switch (ctx->pc) {
        case 0x1af93cu: goto label_1af93c;
        default: break;
    }

    ctx->pc = 0x1af910u;

    // 0x1af910: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1af910u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1af914: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1af914u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1af918: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1af918u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1af91c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1af91cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1af920: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1af920u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1af924: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1af924u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1af928: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1af928u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1af92c: 0x3c04002c  lui         $a0, 0x2C
    ctx->pc = 0x1af92cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)44 << 16));
    // 0x1af930: 0x24848e40  addiu       $a0, $a0, -0x71C0
    ctx->pc = 0x1af930u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294938176));
    // 0x1af934: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1AF934u;
    SET_GPR_U32(ctx, 31, 0x1AF93Cu);
    ctx->pc = 0x1AF938u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF934u;
            // 0x1af938: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF93Cu; }
        if (ctx->pc != 0x1AF93Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF93Cu; }
        if (ctx->pc != 0x1AF93Cu) { return; }
    }
    ctx->pc = 0x1AF93Cu;
label_1af93c:
    // 0x1af93c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1af93cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1af940: 0xac318e40  sw          $s1, -0x71C0($at)
    ctx->pc = 0x1af940u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938176), GPR_U32(ctx, 17));
    // 0x1af944: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1af944u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1af948: 0xac308e44  sw          $s0, -0x71BC($at)
    ctx->pc = 0x1af948u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938180), GPR_U32(ctx, 16));
    // 0x1af94c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1af94cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1af950: 0xac308e4c  sw          $s0, -0x71B4($at)
    ctx->pc = 0x1af950u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938188), GPR_U32(ctx, 16));
    // 0x1af954: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1af954u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1af958: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1af958u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1af95c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1af95cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1af960: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF960u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AF964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF960u;
            // 0x1af964: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AF93Cu: goto label_1af93c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AF968u;
    // 0x1af968: 0x0  nop
    ctx->pc = 0x1af968u;
    // NOP
    // 0x1af96c: 0x0  nop
    ctx->pc = 0x1af96cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
