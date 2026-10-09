#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0AC0
// Address: 0x1b0ac0 - 0x1b0b74
void sub_001B0AC0_0x1b0ac0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0AC0_0x1b0ac0");
#endif

    switch (ctx->pc) {
        case 0x1b0adcu: goto label_1b0adc;
        case 0x1b0ae4u: goto label_1b0ae4;
        case 0x1b0b38u: goto label_1b0b38;
        default: break;
    }

    ctx->pc = 0x1b0ac0u;

    // 0x1b0ac0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b0ac0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b0ac4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b0ac4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b0ac8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b0ac8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b0acc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b0accu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b0ad0: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1b0ad0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b0ad4: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1B0AD4u;
    {
        const bool branch_taken_0x1b0ad4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0AD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0AD4u;
            // 0x1b0ad8: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0ad4) {
            ctx->pc = 0x1B0B44u;
            goto label_1b0b44;
        }
    }
    ctx->pc = 0x1B0ADCu;
label_1b0adc:
    // 0x1b0adc: 0xc068750  jal         func_1A1D40
    ctx->pc = 0x1B0ADCu;
    SET_GPR_U32(ctx, 31, 0x1B0AE4u);
    ctx->pc = 0x1B0AE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0ADCu;
            // 0x1b0ae0: 0x4263f  dsra32      $a0, $a0, 24 (Delay Slot)
        SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1D40u;
    if (runtime->hasFunction(0x1A1D40u)) {
        auto targetFn = runtime->lookupFunction(0x1A1D40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0AE4u; }
        if (ctx->pc != 0x1B0AE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1D40_0x1a1d40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0AE4u; }
        if (ctx->pc != 0x1B0AE4u) { return; }
    }
    ctx->pc = 0x1B0AE4u;
label_1b0ae4:
    // 0x1b0ae4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b0ae4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b0ae8: 0x14430014  bne         $v0, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1B0AE8u;
    {
        const bool branch_taken_0x1b0ae8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1B0AECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0AE8u;
            // 0x1b0aec: 0x26230001  addiu       $v1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0ae8) {
            ctx->pc = 0x1B0B3Cu;
            goto label_1b0b3c;
        }
    }
    ctx->pc = 0x1B0AF0u;
    // 0x1b0af0: 0x102e3c  dsll32      $a1, $s0, 24
    ctx->pc = 0x1b0af0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) << (32 + 24));
    // 0x1b0af4: 0x3c03004a  lui         $v1, 0x4A
    ctx->pc = 0x1b0af4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)74 << 16));
    // 0x1b0af8: 0x52e3f  dsra32      $a1, $a1, 24
    ctx->pc = 0x1b0af8u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 24));
    // 0x1b0afc: 0x24635c30  addiu       $v1, $v1, 0x5C30
    ctx->pc = 0x1b0afcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 23600));
    // 0x1b0b00: 0x52100  sll         $a0, $a1, 4
    ctx->pc = 0x1b0b00u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x1b0b04: 0x852823  subu        $a1, $a0, $a1
    ctx->pc = 0x1b0b04u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1b0b08: 0x520c0  sll         $a0, $a1, 3
    ctx->pc = 0x1b0b08u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1b0b0c: 0xa42021  addu        $a0, $a1, $a0
    ctx->pc = 0x1b0b0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1b0b10: 0x42140  sll         $a0, $a0, 5
    ctx->pc = 0x1b0b10u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
    // 0x1b0b14: 0x642021  addu        $a0, $v1, $a0
    ctx->pc = 0x1b0b14u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b0b18: 0x80830000  lb          $v1, 0x0($a0)
    ctx->pc = 0x1b0b18u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1b0b1c: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B0B1Cu;
    {
        const bool branch_taken_0x1b0b1c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b0b1c) {
            ctx->pc = 0x1B0B38u;
            goto label_1b0b38;
        }
    }
    ctx->pc = 0x1B0B24u;
    // 0x1b0b24: 0x26020001  addiu       $v0, $s0, 0x1
    ctx->pc = 0x1b0b24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b0b28: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1b0b28u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b0b2c: 0x2863c  dsll32      $s0, $v0, 24
    ctx->pc = 0x1b0b2cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) << (32 + 24));
    // 0x1b0b30: 0xc06c2a8  jal         func_1B0AA0
    ctx->pc = 0x1B0B30u;
    SET_GPR_U32(ctx, 31, 0x1B0B38u);
    ctx->pc = 0x1B0B34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0B30u;
            // 0x1b0b34: 0x10863f  dsra32      $s0, $s0, 24 (Delay Slot)
        SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0AA0u;
    if (runtime->hasFunction(0x1B0AA0u)) {
        auto targetFn = runtime->lookupFunction(0x1B0AA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0B38u; }
        if (ctx->pc != 0x1B0B38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0AA0_0x1b0aa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0B38u; }
        if (ctx->pc != 0x1B0B38u) { return; }
    }
    ctx->pc = 0x1B0B38u;
label_1b0b38:
    // 0x1b0b38: 0x26230001  addiu       $v1, $s1, 0x1
    ctx->pc = 0x1b0b38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1b0b3c:
    // 0x1b0b3c: 0x38e3c  dsll32      $s1, $v1, 24
    ctx->pc = 0x1b0b3cu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 3) << (32 + 24));
    // 0x1b0b40: 0x118e3f  dsra32      $s1, $s1, 24
    ctx->pc = 0x1b0b40u;
    SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 24));
label_1b0b44:
    // 0x1b0b44: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0b44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0b48: 0x11263c  dsll32      $a0, $s1, 24
    ctx->pc = 0x1b0b48u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) << (32 + 24));
    // 0x1b0b4c: 0x802341f0  lb          $v1, 0x41F0($at)
    ctx->pc = 0x1b0b4cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16880)));
    // 0x1b0b50: 0x4263f  dsra32      $a0, $a0, 24
    ctx->pc = 0x1b0b50u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 24));
    // 0x1b0b54: 0x83182a  slt         $v1, $a0, $v1
    ctx->pc = 0x1b0b54u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1b0b58: 0x1460ffe0  bnez        $v1, . + 4 + (-0x20 << 2)
    ctx->pc = 0x1B0B58u;
    {
        const bool branch_taken_0x1b0b58 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B0B5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0B58u;
            // 0x1b0b5c: 0x11263c  dsll32      $a0, $s1, 24 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) << (32 + 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0b58) {
            ctx->pc = 0x1B0ADCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b0adc;
        }
    }
    ctx->pc = 0x1B0B60u;
    // 0x1b0b60: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b0b60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b0b64: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b0b64u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b0b68: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b0b68u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b0b6c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0B6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0B70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0B6Cu;
            // 0x1b0b70: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0ADCu: goto label_1b0adc;
            case 0x1B0AE4u: goto label_1b0ae4;
            case 0x1B0B38u: goto label_1b0b38;
            case 0x1B0B3Cu: goto label_1b0b3c;
            case 0x1B0B44u: goto label_1b0b44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0B74u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
