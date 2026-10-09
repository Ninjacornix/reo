#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6AF0
// Address: 0x1d6af0 - 0x1d6b50
void sub_001D6AF0_0x1d6af0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6AF0_0x1d6af0");
#endif

    switch (ctx->pc) {
        case 0x1d6b1cu: goto label_1d6b1c;
        case 0x1d6b30u: goto label_1d6b30;
        default: break;
    }

    ctx->pc = 0x1d6af0u;

    // 0x1d6af0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d6af0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d6af4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d6af4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d6af8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d6af8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d6afc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d6afcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d6b00: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1d6b00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d6b04: 0x60082a  slt         $at, $v1, $zero
    ctx->pc = 0x1d6b04u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 0)) ? 1 : 0);
    // 0x1d6b08: 0x1420000b  bnez        $at, . + 4 + (0xB << 2)
    ctx->pc = 0x1D6B08u;
    {
        const bool branch_taken_0x1d6b08 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D6B0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6B08u;
            // 0x1d6b0c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6b08) {
            ctx->pc = 0x1D6B38u;
            goto label_1d6b38;
        }
    }
    ctx->pc = 0x1D6B10u;
    // 0x1d6b10: 0x3243c  dsll32      $a0, $v1, 16
    ctx->pc = 0x1d6b10u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1d6b14: 0xc075f18  jal         func_1D7C60
    ctx->pc = 0x1D6B14u;
    SET_GPR_U32(ctx, 31, 0x1D6B1Cu);
    ctx->pc = 0x1D6B18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6B14u;
            // 0x1d6b18: 0x4243f  dsra32      $a0, $a0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7C60u;
    if (runtime->hasFunction(0x1D7C60u)) {
        auto targetFn = runtime->lookupFunction(0x1D7C60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6B1Cu; }
        if (ctx->pc != 0x1D6B1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7C60_0x1d7c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6B1Cu; }
        if (ctx->pc != 0x1D6B1Cu) { return; }
    }
    ctx->pc = 0x1D6B1Cu;
label_1d6b1c:
    // 0x1d6b1c: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1d6b1cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d6b20: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d6b20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d6b24: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1d6b24u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1d6b28: 0xc0759b4  jal         func_1D66D0
    ctx->pc = 0x1D6B28u;
    SET_GPR_U32(ctx, 31, 0x1D6B30u);
    ctx->pc = 0x1D6B2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6B28u;
            // 0x1d6b2c: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D66D0u;
    if (runtime->hasFunction(0x1D66D0u)) {
        auto targetFn = runtime->lookupFunction(0x1D66D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6B30u; }
        if (ctx->pc != 0x1D6B30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D66D0_0x1d66d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6B30u; }
        if (ctx->pc != 0x1D6B30u) { return; }
    }
    ctx->pc = 0x1D6B30u;
label_1d6b30:
    // 0x1d6b30: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D6B30u;
    {
        const bool branch_taken_0x1d6b30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d6b30) {
            ctx->pc = 0x1D6B40u;
            goto label_1d6b40;
        }
    }
    ctx->pc = 0x1D6B38u;
label_1d6b38:
    // 0x1d6b38: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1d6b38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d6b3c: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x1d6b3cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
label_1d6b40:
    // 0x1d6b40: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d6b40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d6b44: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d6b44u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d6b48: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6B48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6B4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6B48u;
            // 0x1d6b4c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6B1Cu: goto label_1d6b1c;
            case 0x1D6B30u: goto label_1d6b30;
            case 0x1D6B38u: goto label_1d6b38;
            case 0x1D6B40u: goto label_1d6b40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6B50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
