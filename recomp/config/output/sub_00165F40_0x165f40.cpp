#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00165F40
// Address: 0x165f40 - 0x165fc8
void sub_00165F40_0x165f40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00165F40_0x165f40");
#endif

    switch (ctx->pc) {
        case 0x165fa8u: goto label_165fa8;
        default: break;
    }

    ctx->pc = 0x165f40u;

    // 0x165f40: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x165f40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x165f44: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x165f44u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165f48: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x165f48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x165f4c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x165f4cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165f50: 0x8c831b74  lw          $v1, 0x1B74($a0)
    ctx->pc = 0x165f50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7028)));
    // 0x165f54: 0x24840f60  addiu       $a0, $a0, 0xF60
    ctx->pc = 0x165f54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3936));
    // 0x165f58: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x165f58u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165f5c: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x165F5Cu;
    {
        const bool branch_taken_0x165f5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x165F60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165F5Cu;
            // 0x165f60: 0x8c640000  lw          $a0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165f5c) {
            ctx->pc = 0x165F74u;
            goto label_165f74;
        }
    }
    ctx->pc = 0x165F64u;
    // 0x165f64: 0x8c63002c  lw          $v1, 0x2C($v1)
    ctx->pc = 0x165f64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 44)));
    // 0x165f68: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x165f68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x165f6c: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x165F6Cu;
    {
        const bool branch_taken_0x165f6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x165F70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165F6Cu;
            // 0x165f70: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165f6c) {
            ctx->pc = 0x165F80u;
            goto label_165f80;
        }
    }
    ctx->pc = 0x165F74u;
label_165f74:
    // 0x165f74: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x165f74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x165f78: 0x80597e2  j           func_165F88
    ctx->pc = 0x165F78u;
    ctx->pc = 0x165F7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165F78u;
            // 0x165f7c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x165F88u;
    goto label_165f88;
    ctx->pc = 0x165F80u;
label_165f80:
    // 0x165f80: 0x3e00008  jr          $ra
    ctx->pc = 0x165F80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165F84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165F80u;
            // 0x165f84: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165F74u: goto label_165f74;
            case 0x165F80u: goto label_165f80;
            case 0x165F88u: goto label_165f88;
            case 0x165FA8u: goto label_165fa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x165F88u;
label_165f88:
    // 0x165f88: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x165f88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x165f8c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x165f8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x165f90: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x165f90u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165f94: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x165f94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x165f98: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x165f98u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165f9c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x165f9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x165fa0: 0xc04cb94  jal         func_132E50
    ctx->pc = 0x165FA0u;
    SET_GPR_U32(ctx, 31, 0x165FA8u);
    ctx->pc = 0x165FA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165FA0u;
            // 0x165fa4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132E50u;
    if (runtime->hasFunction(0x132E50u)) {
        auto targetFn = runtime->lookupFunction(0x132E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165FA8u; }
        if (ctx->pc != 0x165FA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132E50_0x132e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165FA8u; }
        if (ctx->pc != 0x165FA8u) { return; }
    }
    ctx->pc = 0x165FA8u;
label_165fa8:
    // 0x165fa8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x165fa8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165fac: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x165facu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165fb0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x165fb0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x165fb4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x165fb4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x165fb8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x165fb8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x165fbc: 0x805df92  j           func_177E48
    ctx->pc = 0x165FBCu;
    ctx->pc = 0x165FC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165FBCu;
            // 0x165fc0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177E48u;
    {
        auto targetFn = runtime->lookupFunction(0x177E48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x165FC4u;
    // 0x165fc4: 0x0  nop
    ctx->pc = 0x165fc4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
