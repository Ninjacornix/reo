#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013B048
// Address: 0x13b048 - 0x13b0ac
void sub_0013B048_0x13b048(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013B048_0x13b048");
#endif

    switch (ctx->pc) {
        case 0x13b064u: goto label_13b064;
        case 0x13b078u: goto label_13b078;
        case 0x13b084u: goto label_13b084;
        default: break;
    }

    ctx->pc = 0x13b048u;

    // 0x13b048: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13b048u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13b04c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13b04cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13b050: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13b050u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b054: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13b054u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13b058: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x13b058u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x13b05c: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B05Cu;
    SET_GPR_U32(ctx, 31, 0x13B064u);
    ctx->pc = 0x13B060u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B05Cu;
            // 0x13b060: 0x24044000  addiu       $a0, $zero, 0x4000 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B064u; }
        if (ctx->pc != 0x13B064u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B064u; }
        if (ctx->pc != 0x13B064u) { return; }
    }
    ctx->pc = 0x13B064u;
label_13b064:
    // 0x13b064: 0x26110014  addiu       $s1, $s0, 0x14
    ctx->pc = 0x13b064u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x13b068: 0x8e040018  lw          $a0, 0x18($s0)
    ctx->pc = 0x13b068u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x13b06c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x13b06cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13b070: 0xc04e128  jal         func_1384A0
    ctx->pc = 0x13B070u;
    SET_GPR_U32(ctx, 31, 0x13B078u);
    ctx->pc = 0x13B074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B070u;
            // 0x13b074: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1384A0u;
    if (runtime->hasFunction(0x1384A0u)) {
        auto targetFn = runtime->lookupFunction(0x1384A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B078u; }
        if (ctx->pc != 0x13B078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001384A0_0x1384a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B078u; }
        if (ctx->pc != 0x13B078u) { return; }
    }
    ctx->pc = 0x13B078u;
label_13b078:
    // 0x13b078: 0x24044001  addiu       $a0, $zero, 0x4001
    ctx->pc = 0x13b078u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16385));
    // 0x13b07c: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B07Cu;
    SET_GPR_U32(ctx, 31, 0x13B084u);
    ctx->pc = 0x13B080u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B07Cu;
            // 0x13b080: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B084u; }
        if (ctx->pc != 0x13B084u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B084u; }
        if (ctx->pc != 0x13B084u) { return; }
    }
    ctx->pc = 0x13B084u;
label_13b084:
    // 0x13b084: 0x6000004  bltz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13B084u;
    {
        const bool branch_taken_0x13b084 = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x13B088u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B084u;
            // 0x13b088: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b084) {
            ctx->pc = 0x13B098u;
            goto label_13b098;
        }
    }
    ctx->pc = 0x13B08Cu;
    // 0x13b08c: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x13b08cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13b090: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x13b090u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x13b094: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x13b094u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_13b098:
    // 0x13b098: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13b098u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13b09c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13b09cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13b0a0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13b0a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13b0a4: 0x3e00008  jr          $ra
    ctx->pc = 0x13B0A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13B0A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B0A4u;
            // 0x13b0a8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B064u: goto label_13b064;
            case 0x13B078u: goto label_13b078;
            case 0x13B084u: goto label_13b084;
            case 0x13B098u: goto label_13b098;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13B0ACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
