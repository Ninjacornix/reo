#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00147F68
// Address: 0x147f68 - 0x147fe0
void sub_00147F68_0x147f68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00147F68_0x147f68");
#endif

    switch (ctx->pc) {
        case 0x147fc0u: goto label_147fc0;
        default: break;
    }

    ctx->pc = 0x147f68u;

    // 0x147f68: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x147f68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x147f6c: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x147f6cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147f70: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x147f70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x147f74: 0x10800014  beqz        $a0, . + 4 + (0x14 << 2)
    ctx->pc = 0x147F74u;
    {
        const bool branch_taken_0x147f74 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x147F78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147F74u;
            // 0x147f78: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x147f74) {
            ctx->pc = 0x147FC8u;
            goto label_147fc8;
        }
    }
    ctx->pc = 0x147F7Cu;
    // 0x147f7c: 0x8c860040  lw          $a2, 0x40($a0)
    ctx->pc = 0x147f7cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x147f80: 0x10c00011  beqz        $a2, . + 4 + (0x11 << 2)
    ctx->pc = 0x147F80u;
    {
        const bool branch_taken_0x147f80 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x147F84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147F80u;
            // 0x147f84: 0x2408000c  addiu       $t0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x147f80) {
            ctx->pc = 0x147FC8u;
            goto label_147fc8;
        }
    }
    ctx->pc = 0x147F88u;
    // 0x147f88: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x147f88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x147f8c: 0x681818  mult        $v1, $v1, $t0
    ctx->pc = 0x147f8cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x147f90: 0xc31021  addu        $v0, $a2, $v1
    ctx->pc = 0x147f90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x147f94: 0x8c47000c  lw          $a3, 0xC($v0)
    ctx->pc = 0x147f94u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x147f98: 0x10e0000c  beqz        $a3, . + 4 + (0xC << 2)
    ctx->pc = 0x147F98u;
    {
        const bool branch_taken_0x147f98 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x147F9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147F98u;
            // 0x147f9c: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x147f98) {
            ctx->pc = 0x147FCCu;
            goto label_147fcc;
        }
    }
    ctx->pc = 0x147FA0u;
    // 0x147fa0: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x147fa0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x147fa4: 0x380802d  daddu       $s0, $gp, $zero
    ctx->pc = 0x147fa4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147fa8: 0x60e02d  daddu       $gp, $v1, $zero
    ctx->pc = 0x147fa8u;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147fac: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x147facu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x147fb0: 0x481818  mult        $v1, $v0, $t0
    ctx->pc = 0x147fb0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x147fb4: 0x661021  addu        $v0, $v1, $a2
    ctx->pc = 0x147fb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x147fb8: 0xe0f809  jalr        $a3
    ctx->pc = 0x147FB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 7);
        SET_GPR_U32(ctx, 31, 0x147FC0u);
        ctx->pc = 0x147FBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147FB8u;
            // 0x147fbc: 0x8c460010  lw          $a2, 0x10($v0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x147FC0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147FC0u: goto label_147fc0;
            case 0x147FC8u: goto label_147fc8;
            case 0x147FCCu: goto label_147fcc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x147FC0u; }
            if (ctx->pc != 0x147FC0u) { return; }
        }
        }
    }
    ctx->pc = 0x147FC0u;
label_147fc0:
    // 0x147fc0: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x147fc0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147fc4: 0x200e02d  daddu       $gp, $s0, $zero
    ctx->pc = 0x147fc4u;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_147fc8:
    // 0x147fc8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x147fc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_147fcc:
    // 0x147fcc: 0x120102d  daddu       $v0, $t1, $zero
    ctx->pc = 0x147fccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147fd0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x147fd0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x147fd4: 0x3e00008  jr          $ra
    ctx->pc = 0x147FD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147FD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147FD4u;
            // 0x147fd8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147FC0u: goto label_147fc0;
            case 0x147FC8u: goto label_147fc8;
            case 0x147FCCu: goto label_147fcc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x147FDCu;
    // 0x147fdc: 0x0  nop
    ctx->pc = 0x147fdcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
