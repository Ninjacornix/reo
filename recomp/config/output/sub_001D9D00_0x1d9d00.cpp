#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D9D00
// Address: 0x1d9d00 - 0x1d9d98
void sub_001D9D00_0x1d9d00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D9D00_0x1d9d00");
#endif

    switch (ctx->pc) {
        case 0x1d9d14u: goto label_1d9d14;
        case 0x1d9d30u: goto label_1d9d30;
        default: break;
    }

    ctx->pc = 0x1d9d00u;

    // 0x1d9d00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d9d00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d9d04: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d9d04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d9d08: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d9d08u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d9d0c: 0xc07651c  jal         func_1D9470
    ctx->pc = 0x1D9D0Cu;
    SET_GPR_U32(ctx, 31, 0x1D9D14u);
    ctx->pc = 0x1D9D10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9D0Cu;
            // 0x1d9d10: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9470u;
    if (runtime->hasFunction(0x1D9470u)) {
        auto targetFn = runtime->lookupFunction(0x1D9470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9D14u; }
        if (ctx->pc != 0x1D9D14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9470_0x1d9470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9D14u; }
        if (ctx->pc != 0x1D9D14u) { return; }
    }
    ctx->pc = 0x1D9D14u;
label_1d9d14:
    // 0x1d9d14: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D9D14u;
    {
        const bool branch_taken_0x1d9d14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9d14) {
            ctx->pc = 0x1D9D28u;
            goto label_1d9d28;
        }
    }
    ctx->pc = 0x1D9D1Cu;
    // 0x1d9d1c: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1D9D1Cu;
    {
        const bool branch_taken_0x1d9d1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9d1c) {
            ctx->pc = 0x1D9D88u;
            goto label_1d9d88;
        }
    }
    ctx->pc = 0x1D9D24u;
    // 0x1d9d24: 0x0  nop
    ctx->pc = 0x1d9d24u;
    // NOP
label_1d9d28:
    // 0x1d9d28: 0xc0766a8  jal         func_1D9AA0
    ctx->pc = 0x1D9D28u;
    SET_GPR_U32(ctx, 31, 0x1D9D30u);
    ctx->pc = 0x1D9D2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9D28u;
            // 0x1d9d2c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9AA0u;
    if (runtime->hasFunction(0x1D9AA0u)) {
        auto targetFn = runtime->lookupFunction(0x1D9AA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9D30u; }
        if (ctx->pc != 0x1D9D30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9AA0_0x1d9aa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9D30u; }
        if (ctx->pc != 0x1D9D30u) { return; }
    }
    ctx->pc = 0x1D9D30u;
label_1d9d30:
    // 0x1d9d30: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D9D30u;
    {
        const bool branch_taken_0x1d9d30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d9d30) {
            ctx->pc = 0x1D9D40u;
            goto label_1d9d40;
        }
    }
    ctx->pc = 0x1D9D38u;
    // 0x1d9d38: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1D9D38u;
    {
        const bool branch_taken_0x1d9d38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9D3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9D38u;
            // 0x1d9d3c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9d38) {
            ctx->pc = 0x1D9D88u;
            goto label_1d9d88;
        }
    }
    ctx->pc = 0x1D9D40u;
label_1d9d40:
    // 0x1d9d40: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1d9d40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1d9d44: 0x3c0400ff  lui         $a0, 0xFF
    ctx->pc = 0x1d9d44u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)255 << 16));
    // 0x1d9d48: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1d9d48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d9d4c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1d9d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1d9d50: 0x90670001  lbu         $a3, 0x1($v1)
    ctx->pc = 0x1d9d50u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1)));
    // 0x1d9d54: 0x90650002  lbu         $a1, 0x2($v1)
    ctx->pc = 0x1d9d54u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 2)));
    // 0x1d9d58: 0x90660000  lbu         $a2, 0x0($v1)
    ctx->pc = 0x1d9d58u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d9d5c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1d9d5cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1d9d60: 0x30e7ff00  andi        $a3, $a3, 0xFF00
    ctx->pc = 0x1d9d60u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)65280);
    // 0x1d9d64: 0x52c00  sll         $a1, $a1, 16
    ctx->pc = 0x1d9d64u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x1d9d68: 0x90630003  lbu         $v1, 0x3($v1)
    ctx->pc = 0x1d9d68u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 3)));
    // 0x1d9d6c: 0xc73025  or          $a2, $a2, $a3
    ctx->pc = 0x1d9d6cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 7));
    // 0x1d9d70: 0xa42024  and         $a0, $a1, $a0
    ctx->pc = 0x1d9d70u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & GPR_U64(ctx, 4));
    // 0x1d9d74: 0x862025  or          $a0, $a0, $a2
    ctx->pc = 0x1d9d74u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 6));
    // 0x1d9d78: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1d9d78u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1d9d7c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1d9d7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1d9d80: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x1d9d80u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x1d9d84: 0x0  nop
    ctx->pc = 0x1d9d84u;
    // NOP
label_1d9d88:
    // 0x1d9d88: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d9d88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d9d8c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d9d8cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d9d90: 0x3e00008  jr          $ra
    ctx->pc = 0x1D9D90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D9D94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9D90u;
            // 0x1d9d94: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9D14u: goto label_1d9d14;
            case 0x1D9D28u: goto label_1d9d28;
            case 0x1D9D30u: goto label_1d9d30;
            case 0x1D9D40u: goto label_1d9d40;
            case 0x1D9D88u: goto label_1d9d88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D9D98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
