#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001652C8
// Address: 0x1652c8 - 0x165318
void sub_001652C8_0x1652c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001652C8_0x1652c8");
#endif

    switch (ctx->pc) {
        case 0x1652e4u: goto label_1652e4;
        default: break;
    }

    ctx->pc = 0x1652c8u;

    // 0x1652c8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1652c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1652cc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1652ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1652d0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1652d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1652d4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1652d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1652d8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1652d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1652dc: 0xc05984a  jal         func_166128
    ctx->pc = 0x1652DCu;
    SET_GPR_U32(ctx, 31, 0x1652E4u);
    ctx->pc = 0x1652E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1652DCu;
            // 0x1652e0: 0xc0882d  daddu       $s1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166128u;
    if (runtime->hasFunction(0x166128u)) {
        auto targetFn = runtime->lookupFunction(0x166128u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1652E4u; }
        if (ctx->pc != 0x1652E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166128_0x166128(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1652E4u; }
        if (ctx->pc != 0x1652E4u) { return; }
    }
    ctx->pc = 0x1652E4u;
label_1652e4:
    // 0x1652e4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1652e4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1652e8: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1652E8u;
    {
        const bool branch_taken_0x1652e8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1652ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1652E8u;
            // 0x1652ec: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1652e8) {
            ctx->pc = 0x165304u;
            goto label_165304;
        }
    }
    ctx->pc = 0x1652F0u;
    // 0x1652f0: 0x8c64000c  lw          $a0, 0xC($v1)
    ctx->pc = 0x1652f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x1652f4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1652f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1652f8: 0xae040000  sw          $a0, 0x0($s0)
    ctx->pc = 0x1652f8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 4));
    // 0x1652fc: 0x8c630010  lw          $v1, 0x10($v1)
    ctx->pc = 0x1652fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x165300: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x165300u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
label_165304:
    // 0x165304: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x165304u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x165308: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x165308u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16530c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16530cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x165310: 0x3e00008  jr          $ra
    ctx->pc = 0x165310u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165310u;
            // 0x165314: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1652E4u: goto label_1652e4;
            case 0x165304u: goto label_165304;
            default: break;
        }
        return;
    }
    ctx->pc = 0x165318u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
