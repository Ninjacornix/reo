#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016A290
// Address: 0x16a290 - 0x16a2f8
void sub_0016A290_0x16a290(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016A290_0x16a290");
#endif

    switch (ctx->pc) {
        case 0x16a2bcu: goto label_16a2bc;
        default: break;
    }

    ctx->pc = 0x16a290u;

    // 0x16a290: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x16a290u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x16a294: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x16a294u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x16a298: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x16a298u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a29c: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x16a29cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x16a2a0: 0x100882d  daddu       $s1, $t0, $zero
    ctx->pc = 0x16a2a0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a2a4: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x16a2a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x16a2a8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x16a2a8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a2ac: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x16a2acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x16a2b0: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x16a2b0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a2b4: 0xc059bfa  jal         func_166FE8
    ctx->pc = 0x16A2B4u;
    SET_GPR_U32(ctx, 31, 0x16A2BCu);
    ctx->pc = 0x16A2B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A2B4u;
            // 0x16a2b8: 0x8c851af4  lw          $a1, 0x1AF4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6900)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166FE8u;
    if (runtime->hasFunction(0x166FE8u)) {
        auto targetFn = runtime->lookupFunction(0x166FE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A2BCu; }
        if (ctx->pc != 0x16A2BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166FE8_0x166fe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A2BCu; }
        if (ctx->pc != 0x16A2BCu) { return; }
    }
    ctx->pc = 0x16A2BCu;
label_16a2bc:
    // 0x16a2bc: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x16A2BCu;
    {
        const bool branch_taken_0x16a2bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16a2bc) {
            ctx->pc = 0x16A2C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A2BCu;
            // 0x16a2c0: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A2E4u;
            goto label_16a2e4;
        }
    }
    ctx->pc = 0x16A2C4u;
    // 0x16a2c4: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x16a2c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x16a2c8: 0x8fa4000c  lw          $a0, 0xC($sp)
    ctx->pc = 0x16a2c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x16a2cc: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x16a2ccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16a2d0: 0x642021  addu        $a0, $v1, $a0
    ctx->pc = 0x16a2d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x16a2d4: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x16a2d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x16a2d8: 0xae450000  sw          $a1, 0x0($s2)
    ctx->pc = 0x16a2d8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 5));
    // 0x16a2dc: 0xae240000  sw          $a0, 0x0($s1)
    ctx->pc = 0x16a2dcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 4));
    // 0x16a2e0: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x16a2e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_16a2e4:
    // 0x16a2e4: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x16a2e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16a2e8: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x16a2e8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16a2ec: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x16a2ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16a2f0: 0x3e00008  jr          $ra
    ctx->pc = 0x16A2F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16A2F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A2F0u;
            // 0x16a2f4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A2BCu: goto label_16a2bc;
            case 0x16A2E4u: goto label_16a2e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16A2F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
