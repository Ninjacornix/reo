#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CC8A0
// Address: 0x1cc8a0 - 0x1cc8f0
void sub_001CC8A0_0x1cc8a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CC8A0_0x1cc8a0");
#endif

    switch (ctx->pc) {
        case 0x1cc8ccu: goto label_1cc8cc;
        default: break;
    }

    ctx->pc = 0x1cc8a0u;

    // 0x1cc8a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cc8a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cc8a4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc8a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc8a8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cc8a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cc8ac: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cc8acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cc8b0: 0x8c220a20  lw          $v0, 0xA20($at)
    ctx->pc = 0x1cc8b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2592)));
    // 0x1cc8b4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1cc8b4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc8b8: 0x8c86000c  lw          $a2, 0xC($a0)
    ctx->pc = 0x1cc8b8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1cc8bc: 0x8c870010  lw          $a3, 0x10($a0)
    ctx->pc = 0x1cc8bcu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1cc8c0: 0x8c440084  lw          $a0, 0x84($v0)
    ctx->pc = 0x1cc8c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 132)));
    // 0x1cc8c4: 0xc0ded6c  jal         func_37B5B0
    ctx->pc = 0x1CC8C4u;
    SET_GPR_U32(ctx, 31, 0x1CC8CCu);
    ctx->pc = 0x1CC8C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC8C4u;
            // 0x1cc8c8: 0x8e05002c  lw          $a1, 0x2C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x37B5B0u;
    {
        auto targetFn = runtime->lookupFunction(0x37B5B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC8CCu; }
        if (ctx->pc != 0x1CC8CCu) { return; }
    }
    ctx->pc = 0x1CC8CCu;
label_1cc8cc:
    // 0x1cc8cc: 0x8e030024  lw          $v1, 0x24($s0)
    ctx->pc = 0x1cc8ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x1cc8d0: 0x38630001  xori        $v1, $v1, 0x1
    ctx->pc = 0x1cc8d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
    // 0x1cc8d4: 0xae030024  sw          $v1, 0x24($s0)
    ctx->pc = 0x1cc8d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 3));
    // 0x1cc8d8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cc8d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cc8dc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cc8dcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cc8e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1CC8E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CC8E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC8E0u;
            // 0x1cc8e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CC8CCu: goto label_1cc8cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CC8E8u;
    // 0x1cc8e8: 0x0  nop
    ctx->pc = 0x1cc8e8u;
    // NOP
    // 0x1cc8ec: 0x0  nop
    ctx->pc = 0x1cc8ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
