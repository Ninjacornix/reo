#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D9AA0
// Address: 0x1d9aa0 - 0x1da330
void sub_001D9AA0_0x1d9aa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D9AA0_0x1d9aa0");
#endif

    switch (ctx->pc) {
        case 0x1d9abcu: goto label_1d9abc;
        case 0x1d9ac8u: goto label_1d9ac8;
        case 0x1d9ad8u: goto label_1d9ad8;
        case 0x1d9b1cu: goto label_1d9b1c;
        case 0x1d9b50u: goto label_1d9b50;
        case 0x1d9b58u: goto label_1d9b58;
        case 0x1d9b68u: goto label_1d9b68;
        case 0x1d9b98u: goto label_1d9b98;
        case 0x1d9bccu: goto label_1d9bcc;
        case 0x1d9c08u: goto label_1d9c08;
        case 0x1d9c2cu: goto label_1d9c2c;
        case 0x1d9c34u: goto label_1d9c34;
        case 0x1d9c48u: goto label_1d9c48;
        case 0x1d9c50u: goto label_1d9c50;
        case 0x1d9c60u: goto label_1d9c60;
        case 0x1d9c70u: goto label_1d9c70;
        case 0x1d9cd0u: goto label_1d9cd0;
        case 0x1d9ce0u: goto label_1d9ce0;
        case 0x1d9d14u: goto label_1d9d14;
        case 0x1d9d30u: goto label_1d9d30;
        case 0x1d9e28u: goto label_1d9e28;
        case 0x1d9e30u: goto label_1d9e30;
        case 0x1d9e60u: goto label_1d9e60;
        case 0x1d9e70u: goto label_1d9e70;
        case 0x1d9ea0u: goto label_1d9ea0;
        case 0x1d9eb4u: goto label_1d9eb4;
        case 0x1d9ef8u: goto label_1d9ef8;
        case 0x1d9f90u: goto label_1d9f90;
        case 0x1d9fd4u: goto label_1d9fd4;
        case 0x1da128u: goto label_1da128;
        case 0x1da13cu: goto label_1da13c;
        case 0x1da180u: goto label_1da180;
        case 0x1da1b4u: goto label_1da1b4;
        case 0x1da248u: goto label_1da248;
        case 0x1da280u: goto label_1da280;
        case 0x1da290u: goto label_1da290;
        case 0x1da2b8u: goto label_1da2b8;
        case 0x1da2ccu: goto label_1da2cc;
        case 0x1da2d4u: goto label_1da2d4;
        case 0x1da2f0u: goto label_1da2f0;
        default: break;
    }

    ctx->pc = 0x1d9aa0u;

label_1d9aa0:
    // 0x1d9aa0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1d9aa0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1d9aa4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1d9aa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d9aa8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d9aa8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d9aac: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d9aacu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d9ab0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1d9ab0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9ab4: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1D9AB4u;
    SET_GPR_U32(ctx, 31, 0x1D9ABCu);
    ctx->pc = 0x1D9AB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9AB4u;
            // 0x1d9ab8: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9ABCu; }
        if (ctx->pc != 0x1D9ABCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9ABCu; }
        if (ctx->pc != 0x1D9ABCu) { return; }
    }
    ctx->pc = 0x1D9ABCu;
label_1d9abc:
    // 0x1d9abc: 0x3c100035  lui         $s0, 0x35
    ctx->pc = 0x1d9abcu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)53 << 16));
    // 0x1d9ac0: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1d9ac0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9ac4: 0x261082d0  addiu       $s0, $s0, -0x7D30
    ctx->pc = 0x1d9ac4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294935248));
label_1d9ac8:
    // 0x1d9ac8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d9ac8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9acc: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1d9accu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9ad0: 0xc042d10  jal         func_10B440
    ctx->pc = 0x1D9AD0u;
    SET_GPR_U32(ctx, 31, 0x1D9AD8u);
    ctx->pc = 0x1D9AD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9AD0u;
            // 0x1d9ad4: 0x24060100  addiu       $a2, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9AD8u; }
        if (ctx->pc != 0x1D9AD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9AD8u; }
        if (ctx->pc != 0x1D9AD8u) { return; }
    }
    ctx->pc = 0x1D9AD8u;
label_1d9ad8:
    // 0x1d9ad8: 0x10400073  beqz        $v0, . + 4 + (0x73 << 2)
    ctx->pc = 0x1D9AD8u;
    {
        const bool branch_taken_0x1d9ad8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9ad8) {
            ctx->pc = 0x1D9CA8u;
            goto label_1d9ca8;
        }
    }
    ctx->pc = 0x1D9AE0u;
    // 0x1d9ae0: 0x26220001  addiu       $v0, $s1, 0x1
    ctx->pc = 0x1d9ae0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1d9ae4: 0x28c3c  dsll32      $s1, $v0, 16
    ctx->pc = 0x1d9ae4u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d9ae8: 0x118c3f  dsra32      $s1, $s1, 16
    ctx->pc = 0x1d9ae8u;
    SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
    // 0x1d9aec: 0x2a220008  slti        $v0, $s1, 0x8
    ctx->pc = 0x1d9aecu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1d9af0: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x1D9AF0u;
    {
        const bool branch_taken_0x1d9af0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D9AF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9AF0u;
            // 0x1d9af4: 0x26100134  addiu       $s0, $s0, 0x134 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 308));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9af0) {
            ctx->pc = 0x1D9AC8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d9ac8;
        }
    }
    ctx->pc = 0x1D9AF8u;
    // 0x1d9af8: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9af8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9afc: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1d9afcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1d9b00: 0x8c2582c8  lw          $a1, -0x7D38($at)
    ctx->pc = 0x1d9b00u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294935240)));
    // 0x1d9b04: 0x24030134  addiu       $v1, $zero, 0x134
    ctx->pc = 0x1d9b04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 308));
    // 0x1d9b08: 0x244282d0  addiu       $v0, $v0, -0x7D30
    ctx->pc = 0x1d9b08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294935248));
    // 0x1d9b0c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1d9b0cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9b10: 0xa31818  mult        $v1, $a1, $v1
    ctx->pc = 0x1d9b10u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1d9b14: 0xc07644c  jal         func_1D9130
    ctx->pc = 0x1D9B14u;
    SET_GPR_U32(ctx, 31, 0x1D9B1Cu);
    ctx->pc = 0x1D9B18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9B14u;
            // 0x1d9b18: 0x438021  addu        $s0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9130u;
    if (runtime->hasFunction(0x1D9130u)) {
        auto targetFn = runtime->lookupFunction(0x1D9130u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9B1Cu; }
        if (ctx->pc != 0x1D9B1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9130_0x1d9130(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9B1Cu; }
        if (ctx->pc != 0x1D9B1Cu) { return; }
    }
    ctx->pc = 0x1D9B1Cu;
label_1d9b1c:
    // 0x1d9b1c: 0x28c3c  dsll32      $s1, $v0, 16
    ctx->pc = 0x1d9b1cu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d9b20: 0x118c3f  dsra32      $s1, $s1, 16
    ctx->pc = 0x1d9b20u;
    SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
    // 0x1d9b24: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d9b24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9b28: 0x12220003  beq         $s1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D9B28u;
    {
        const bool branch_taken_0x1d9b28 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        if (branch_taken_0x1d9b28) {
            ctx->pc = 0x1D9B38u;
            goto label_1d9b38;
        }
    }
    ctx->pc = 0x1D9B30u;
    // 0x1d9b30: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1D9B30u;
    {
        const bool branch_taken_0x1d9b30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9b30) {
            ctx->pc = 0x1D9B48u;
            goto label_1d9b48;
        }
    }
    ctx->pc = 0x1D9B38u;
label_1d9b38:
    // 0x1d9b38: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9b38u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9b3c: 0x10000066  b           . + 4 + (0x66 << 2)
    ctx->pc = 0x1D9B3Cu;
    {
        const bool branch_taken_0x1d9b3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9B40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9B3Cu;
            // 0x1d9b40: 0xac228c80  sw          $v0, -0x7380($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937728), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9b3c) {
            ctx->pc = 0x1D9CD8u;
            goto label_1d9cd8;
        }
    }
    ctx->pc = 0x1D9B44u;
    // 0x1d9b44: 0x0  nop
    ctx->pc = 0x1d9b44u;
    // NOP
label_1d9b48:
    // 0x1d9b48: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9B48u;
    SET_GPR_U32(ctx, 31, 0x1D9B50u);
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9B50u; }
        if (ctx->pc != 0x1D9B50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9B50u; }
        if (ctx->pc != 0x1D9B50u) { return; }
    }
    ctx->pc = 0x1D9B50u;
label_1d9b50:
    // 0x1d9b50: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1D9B50u;
    SET_GPR_U32(ctx, 31, 0x1D9B58u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9B58u; }
        if (ctx->pc != 0x1D9B58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9B58u; }
        if (ctx->pc != 0x1D9B58u) { return; }
    }
    ctx->pc = 0x1D9B58u;
label_1d9b58:
    // 0x1d9b58: 0x3c040035  lui         $a0, 0x35
    ctx->pc = 0x1d9b58u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)53 << 16));
    // 0x1d9b5c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d9b5cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9b60: 0x24848c70  addiu       $a0, $a0, -0x7390
    ctx->pc = 0x1d9b60u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937712));
    // 0x1d9b64: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d9b64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1d9b68:
    // 0x1d9b68: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1d9b68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d9b6c: 0x1443000e  bne         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1D9B6Cu;
    {
        const bool branch_taken_0x1d9b6c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1D9B70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9B6Cu;
            // 0x1d9b70: 0x5143c  dsll32      $v0, $a1, 16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) << (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9b6c) {
            ctx->pc = 0x1D9BA8u;
            goto label_1d9ba8;
        }
    }
    ctx->pc = 0x1D9B74u;
    // 0x1d9b74: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1d9b74u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9b78: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d9b78u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d9b7c: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1d9b7cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9b80: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1d9b80u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1d9b84: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1d9b84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1d9b88: 0x24428c70  addiu       $v0, $v0, -0x7390
    ctx->pc = 0x1d9b88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937712));
    // 0x1d9b8c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d9b8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d9b90: 0xc076468  jal         func_1D91A0
    ctx->pc = 0x1D9B90u;
    SET_GPR_U32(ctx, 31, 0x1D9B98u);
    ctx->pc = 0x1D9B94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9B90u;
            // 0x1d9b94: 0xac450000  sw          $a1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D91A0u;
    if (runtime->hasFunction(0x1D91A0u)) {
        auto targetFn = runtime->lookupFunction(0x1D91A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9B98u; }
        if (ctx->pc != 0x1D9B98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D91A0_0x1d91a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9B98u; }
        if (ctx->pc != 0x1D9B98u) { return; }
    }
    ctx->pc = 0x1D9B98u;
label_1d9b98:
    // 0x1d9b98: 0x24020071  addiu       $v0, $zero, 0x71
    ctx->pc = 0x1d9b98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 113));
    // 0x1d9b9c: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9b9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9ba0: 0x1000004d  b           . + 4 + (0x4D << 2)
    ctx->pc = 0x1D9BA0u;
    {
        const bool branch_taken_0x1d9ba0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9BA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9BA0u;
            // 0x1d9ba4: 0xac228c80  sw          $v0, -0x7380($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937728), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9ba0) {
            ctx->pc = 0x1D9CD8u;
            goto label_1d9cd8;
        }
    }
    ctx->pc = 0x1D9BA8u;
label_1d9ba8:
    // 0x1d9ba8: 0x24a20001  addiu       $v0, $a1, 0x1
    ctx->pc = 0x1d9ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1d9bac: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x1d9bacu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d9bb0: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x1d9bb0u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x1d9bb4: 0x28a20003  slti        $v0, $a1, 0x3
    ctx->pc = 0x1d9bb4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1d9bb8: 0x1440ffeb  bnez        $v0, . + 4 + (-0x15 << 2)
    ctx->pc = 0x1D9BB8u;
    {
        const bool branch_taken_0x1d9bb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D9BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9BB8u;
            // 0x1d9bbc: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9bb8) {
            ctx->pc = 0x1D9B68u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d9b68;
        }
    }
    ctx->pc = 0x1D9BC0u;
    // 0x1d9bc0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1d9bc0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9bc4: 0xc076480  jal         func_1D9200
    ctx->pc = 0x1D9BC4u;
    SET_GPR_U32(ctx, 31, 0x1D9BCCu);
    ctx->pc = 0x1D9BC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9BC4u;
            // 0x1d9bc8: 0x26050100  addiu       $a1, $s0, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9200u;
    if (runtime->hasFunction(0x1D9200u)) {
        auto targetFn = runtime->lookupFunction(0x1D9200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9BCCu; }
        if (ctx->pc != 0x1D9BCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9200_0x1d9200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9BCCu; }
        if (ctx->pc != 0x1D9BCCu) { return; }
    }
    ctx->pc = 0x1D9BCCu;
label_1d9bcc:
    // 0x1d9bcc: 0x21c3c  dsll32      $v1, $v0, 16
    ctx->pc = 0x1d9bccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d9bd0: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1d9bd0u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1d9bd4: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x1d9bd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1d9bd8: 0x1062000f  beq         $v1, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1D9BD8u;
    {
        const bool branch_taken_0x1d9bd8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1d9bd8) {
            ctx->pc = 0x1D9C18u;
            goto label_1d9c18;
        }
    }
    ctx->pc = 0x1D9BE0u;
    // 0x1d9be0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d9be0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9be4: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D9BE4u;
    {
        const bool branch_taken_0x1d9be4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D9BE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9BE4u;
            // 0x1d9be8: 0x2402fffa  addiu       $v0, $zero, -0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967290));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9be4) {
            ctx->pc = 0x1D9C00u;
            goto label_1d9c00;
        }
    }
    ctx->pc = 0x1D9BECu;
    // 0x1d9bec: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D9BECu;
    {
        const bool branch_taken_0x1d9bec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1d9bec) {
            ctx->pc = 0x1D9C00u;
            goto label_1d9c00;
        }
    }
    ctx->pc = 0x1D9BF4u;
    // 0x1d9bf4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1D9BF4u;
    {
        const bool branch_taken_0x1d9bf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9bf4) {
            ctx->pc = 0x1D9C18u;
            goto label_1d9c18;
        }
    }
    ctx->pc = 0x1D9BFCu;
    // 0x1d9bfc: 0x0  nop
    ctx->pc = 0x1d9bfcu;
    // NOP
label_1d9c00:
    // 0x1d9c00: 0xc076468  jal         func_1D91A0
    ctx->pc = 0x1D9C00u;
    SET_GPR_U32(ctx, 31, 0x1D9C08u);
    ctx->pc = 0x1D9C04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9C00u;
            // 0x1d9c04: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D91A0u;
    if (runtime->hasFunction(0x1D91A0u)) {
        auto targetFn = runtime->lookupFunction(0x1D91A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9C08u; }
        if (ctx->pc != 0x1D9C08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D91A0_0x1d91a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9C08u; }
        if (ctx->pc != 0x1D9C08u) { return; }
    }
    ctx->pc = 0x1D9C08u;
label_1d9c08:
    // 0x1d9c08: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d9c08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d9c0c: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9c0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9c10: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1D9C10u;
    {
        const bool branch_taken_0x1d9c10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9C14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9C10u;
            // 0x1d9c14: 0xac228c80  sw          $v0, -0x7380($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937728), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9c10) {
            ctx->pc = 0x1D9CD8u;
            goto label_1d9cd8;
        }
    }
    ctx->pc = 0x1D9C18u;
label_1d9c18:
    // 0x1d9c18: 0x3082a  slt         $at, $zero, $v1
    ctx->pc = 0x1d9c18u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1d9c1c: 0x10200008  beqz        $at, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D9C1Cu;
    {
        const bool branch_taken_0x1d9c1c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9C20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9C1Cu;
            // 0x1d9c20: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9c1c) {
            ctx->pc = 0x1D9C40u;
            goto label_1d9c40;
        }
    }
    ctx->pc = 0x1D9C24u;
    // 0x1d9c24: 0xc076468  jal         func_1D91A0
    ctx->pc = 0x1D9C24u;
    SET_GPR_U32(ctx, 31, 0x1D9C2Cu);
    ctx->pc = 0x1D91A0u;
    if (runtime->hasFunction(0x1D91A0u)) {
        auto targetFn = runtime->lookupFunction(0x1D91A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9C2Cu; }
        if (ctx->pc != 0x1D9C2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D91A0_0x1d91a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9C2Cu; }
        if (ctx->pc != 0x1D9C2Cu) { return; }
    }
    ctx->pc = 0x1D9C2Cu;
label_1d9c2c:
    // 0x1d9c2c: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9C2Cu;
    SET_GPR_U32(ctx, 31, 0x1D9C34u);
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9C34u; }
        if (ctx->pc != 0x1D9C34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9C34u; }
        if (ctx->pc != 0x1D9C34u) { return; }
    }
    ctx->pc = 0x1D9C34u;
label_1d9c34:
    // 0x1d9c34: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1D9C34u;
    {
        const bool branch_taken_0x1d9c34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9c34) {
            ctx->pc = 0x1D9C58u;
            goto label_1d9c58;
        }
    }
    ctx->pc = 0x1D9C3Cu;
    // 0x1d9c3c: 0x0  nop
    ctx->pc = 0x1d9c3cu;
    // NOP
label_1d9c40:
    // 0x1d9c40: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9C40u;
    SET_GPR_U32(ctx, 31, 0x1D9C48u);
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9C48u; }
        if (ctx->pc != 0x1D9C48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9C48u; }
        if (ctx->pc != 0x1D9C48u) { return; }
    }
    ctx->pc = 0x1D9C48u;
label_1d9c48:
    // 0x1d9c48: 0xc07690c  jal         func_1DA430
    ctx->pc = 0x1D9C48u;
    SET_GPR_U32(ctx, 31, 0x1D9C50u);
    ctx->pc = 0x1DA430u;
    if (runtime->hasFunction(0x1DA430u)) {
        auto targetFn = runtime->lookupFunction(0x1DA430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9C50u; }
        if (ctx->pc != 0x1D9C50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DA430_0x1da430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9C50u; }
        if (ctx->pc != 0x1D9C50u) { return; }
    }
    ctx->pc = 0x1D9C50u;
label_1d9c50:
    // 0x1d9c50: 0x1000ffbf  b           . + 4 + (-0x41 << 2)
    ctx->pc = 0x1D9C50u;
    {
        const bool branch_taken_0x1d9c50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9c50) {
            ctx->pc = 0x1D9B50u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d9b50;
        }
    }
    ctx->pc = 0x1D9C58u;
label_1d9c58:
    // 0x1d9c58: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1D9C58u;
    SET_GPR_U32(ctx, 31, 0x1D9C60u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9C60u; }
        if (ctx->pc != 0x1D9C60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9C60u; }
        if (ctx->pc != 0x1D9C60u) { return; }
    }
    ctx->pc = 0x1D9C60u;
label_1d9c60:
    // 0x1d9c60: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1d9c60u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9c64: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d9c64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9c68: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1D9C68u;
    SET_GPR_U32(ctx, 31, 0x1D9C70u);
    ctx->pc = 0x1D9C6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9C68u;
            // 0x1d9c6c: 0x24060100  addiu       $a2, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9C70u; }
        if (ctx->pc != 0x1D9C70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9C70u; }
        if (ctx->pc != 0x1D9C70u) { return; }
    }
    ctx->pc = 0x1D9C70u;
label_1d9c70:
    // 0x1d9c70: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9c70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9c74: 0x8c2282c8  lw          $v0, -0x7D38($at)
    ctx->pc = 0x1d9c74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294935240)));
    // 0x1d9c78: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1d9c78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1d9c7c: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9c7cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9c80: 0xac2282c8  sw          $v0, -0x7D38($at)
    ctx->pc = 0x1d9c80u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294935240), GPR_U32(ctx, 2));
    // 0x1d9c84: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9c84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9c88: 0x8c2382c8  lw          $v1, -0x7D38($at)
    ctx->pc = 0x1d9c88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294935240)));
    // 0x1d9c8c: 0x4610004  bgez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D9C8Cu;
    {
        const bool branch_taken_0x1d9c8c = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1D9C90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9C8Cu;
            // 0x1d9c90: 0x30620007  andi        $v0, $v1, 0x7 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)7);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9c8c) {
            ctx->pc = 0x1D9CA0u;
            goto label_1d9ca0;
        }
    }
    ctx->pc = 0x1D9C94u;
    // 0x1d9c94: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1D9C94u;
    {
        const bool branch_taken_0x1d9c94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9c94) {
            ctx->pc = 0x1D9CA0u;
            goto label_1d9ca0;
        }
    }
    ctx->pc = 0x1D9C9Cu;
    // 0x1d9c9c: 0x2442fff8  addiu       $v0, $v0, -0x8
    ctx->pc = 0x1d9c9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967288));
label_1d9ca0:
    // 0x1d9ca0: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9ca0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9ca4: 0xac2282c8  sw          $v0, -0x7D38($at)
    ctx->pc = 0x1d9ca4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294935240), GPR_U32(ctx, 2));
label_1d9ca8:
    // 0x1d9ca8: 0xae000124  sw          $zero, 0x124($s0)
    ctx->pc = 0x1d9ca8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 292), GPR_U32(ctx, 0));
    // 0x1d9cac: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1d9cacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d9cb0: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1d9cb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d9cb4: 0xae030128  sw          $v1, 0x128($s0)
    ctx->pc = 0x1d9cb4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 296), GPR_U32(ctx, 3));
    // 0x1d9cb8: 0xae02012c  sw          $v0, 0x12C($s0)
    ctx->pc = 0x1d9cb8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 300), GPR_U32(ctx, 2));
    // 0x1d9cbc: 0x26030100  addiu       $v1, $s0, 0x100
    ctx->pc = 0x1d9cbcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 256));
    // 0x1d9cc0: 0x26020110  addiu       $v0, $s0, 0x110
    ctx->pc = 0x1d9cc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 272));
    // 0x1d9cc4: 0xae030110  sw          $v1, 0x110($s0)
    ctx->pc = 0x1d9cc4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 272), GPR_U32(ctx, 3));
    // 0x1d9cc8: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9CC8u;
    SET_GPR_U32(ctx, 31, 0x1D9CD0u);
    ctx->pc = 0x1D9CCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9CC8u;
            // 0x1d9ccc: 0xae020130  sw          $v0, 0x130($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 304), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9CD0u; }
        if (ctx->pc != 0x1D9CD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9CD0u; }
        if (ctx->pc != 0x1D9CD0u) { return; }
    }
    ctx->pc = 0x1D9CD0u;
label_1d9cd0:
    // 0x1d9cd0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1D9CD0u;
    {
        const bool branch_taken_0x1d9cd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9CD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9CD0u;
            // 0x1d9cd4: 0x26020120  addiu       $v0, $s0, 0x120 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 288));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9cd0) {
            ctx->pc = 0x1D9CE8u;
            goto label_1d9ce8;
        }
    }
    ctx->pc = 0x1D9CD8u;
label_1d9cd8:
    // 0x1d9cd8: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9CD8u;
    SET_GPR_U32(ctx, 31, 0x1D9CE0u);
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9CE0u; }
        if (ctx->pc != 0x1D9CE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9CE0u; }
        if (ctx->pc != 0x1D9CE0u) { return; }
    }
    ctx->pc = 0x1D9CE0u;
label_1d9ce0:
    // 0x1d9ce0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d9ce0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9ce4: 0x0  nop
    ctx->pc = 0x1d9ce4u;
    // NOP
label_1d9ce8:
    // 0x1d9ce8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1d9ce8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d9cec: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d9cecu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d9cf0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d9cf0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d9cf4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d9cf4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d9cf8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D9CF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D9CFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9CF8u;
            // 0x1d9cfc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9AA0u: goto label_1d9aa0;
            case 0x1D9ABCu: goto label_1d9abc;
            case 0x1D9AC8u: goto label_1d9ac8;
            case 0x1D9AD8u: goto label_1d9ad8;
            case 0x1D9B1Cu: goto label_1d9b1c;
            case 0x1D9B38u: goto label_1d9b38;
            case 0x1D9B48u: goto label_1d9b48;
            case 0x1D9B50u: goto label_1d9b50;
            case 0x1D9B58u: goto label_1d9b58;
            case 0x1D9B68u: goto label_1d9b68;
            case 0x1D9B98u: goto label_1d9b98;
            case 0x1D9BA8u: goto label_1d9ba8;
            case 0x1D9BCCu: goto label_1d9bcc;
            case 0x1D9C00u: goto label_1d9c00;
            case 0x1D9C08u: goto label_1d9c08;
            case 0x1D9C18u: goto label_1d9c18;
            case 0x1D9C2Cu: goto label_1d9c2c;
            case 0x1D9C34u: goto label_1d9c34;
            case 0x1D9C40u: goto label_1d9c40;
            case 0x1D9C48u: goto label_1d9c48;
            case 0x1D9C50u: goto label_1d9c50;
            case 0x1D9C58u: goto label_1d9c58;
            case 0x1D9C60u: goto label_1d9c60;
            case 0x1D9C70u: goto label_1d9c70;
            case 0x1D9CA0u: goto label_1d9ca0;
            case 0x1D9CA8u: goto label_1d9ca8;
            case 0x1D9CD0u: goto label_1d9cd0;
            case 0x1D9CD8u: goto label_1d9cd8;
            case 0x1D9CE0u: goto label_1d9ce0;
            case 0x1D9CE8u: goto label_1d9ce8;
            case 0x1D9D14u: goto label_1d9d14;
            case 0x1D9D28u: goto label_1d9d28;
            case 0x1D9D30u: goto label_1d9d30;
            case 0x1D9D40u: goto label_1d9d40;
            case 0x1D9D88u: goto label_1d9d88;
            case 0x1D9DE0u: goto label_1d9de0;
            case 0x1D9DF8u: goto label_1d9df8;
            case 0x1D9E28u: goto label_1d9e28;
            case 0x1D9E30u: goto label_1d9e30;
            case 0x1D9E60u: goto label_1d9e60;
            case 0x1D9E68u: goto label_1d9e68;
            case 0x1D9E70u: goto label_1d9e70;
            case 0x1D9EA0u: goto label_1d9ea0;
            case 0x1D9EB4u: goto label_1d9eb4;
            case 0x1D9ED8u: goto label_1d9ed8;
            case 0x1D9EF0u: goto label_1d9ef0;
            case 0x1D9EF8u: goto label_1d9ef8;
            case 0x1D9F18u: goto label_1d9f18;
            case 0x1D9F40u: goto label_1d9f40;
            case 0x1D9F60u: goto label_1d9f60;
            case 0x1D9F78u: goto label_1d9f78;
            case 0x1D9F90u: goto label_1d9f90;
            case 0x1D9F98u: goto label_1d9f98;
            case 0x1D9FA8u: goto label_1d9fa8;
            case 0x1D9FC0u: goto label_1d9fc0;
            case 0x1D9FD4u: goto label_1d9fd4;
            case 0x1D9FF8u: goto label_1d9ff8;
            case 0x1DA010u: goto label_1da010;
            case 0x1DA030u: goto label_1da030;
            case 0x1DA040u: goto label_1da040;
            case 0x1DA050u: goto label_1da050;
            case 0x1DA0B8u: goto label_1da0b8;
            case 0x1DA0D0u: goto label_1da0d0;
            case 0x1DA100u: goto label_1da100;
            case 0x1DA128u: goto label_1da128;
            case 0x1DA13Cu: goto label_1da13c;
            case 0x1DA160u: goto label_1da160;
            case 0x1DA178u: goto label_1da178;
            case 0x1DA180u: goto label_1da180;
            case 0x1DA1A0u: goto label_1da1a0;
            case 0x1DA1B4u: goto label_1da1b4;
            case 0x1DA1D8u: goto label_1da1d8;
            case 0x1DA1E0u: goto label_1da1e0;
            case 0x1DA228u: goto label_1da228;
            case 0x1DA240u: goto label_1da240;
            case 0x1DA248u: goto label_1da248;
            case 0x1DA280u: goto label_1da280;
            case 0x1DA288u: goto label_1da288;
            case 0x1DA290u: goto label_1da290;
            case 0x1DA2B0u: goto label_1da2b0;
            case 0x1DA2B8u: goto label_1da2b8;
            case 0x1DA2CCu: goto label_1da2cc;
            case 0x1DA2D4u: goto label_1da2d4;
            case 0x1DA2F0u: goto label_1da2f0;
            case 0x1DA2F8u: goto label_1da2f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D9D00u;
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
    goto label_1d9aa0;
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
            case 0x1D9AA0u: goto label_1d9aa0;
            case 0x1D9ABCu: goto label_1d9abc;
            case 0x1D9AC8u: goto label_1d9ac8;
            case 0x1D9AD8u: goto label_1d9ad8;
            case 0x1D9B1Cu: goto label_1d9b1c;
            case 0x1D9B38u: goto label_1d9b38;
            case 0x1D9B48u: goto label_1d9b48;
            case 0x1D9B50u: goto label_1d9b50;
            case 0x1D9B58u: goto label_1d9b58;
            case 0x1D9B68u: goto label_1d9b68;
            case 0x1D9B98u: goto label_1d9b98;
            case 0x1D9BA8u: goto label_1d9ba8;
            case 0x1D9BCCu: goto label_1d9bcc;
            case 0x1D9C00u: goto label_1d9c00;
            case 0x1D9C08u: goto label_1d9c08;
            case 0x1D9C18u: goto label_1d9c18;
            case 0x1D9C2Cu: goto label_1d9c2c;
            case 0x1D9C34u: goto label_1d9c34;
            case 0x1D9C40u: goto label_1d9c40;
            case 0x1D9C48u: goto label_1d9c48;
            case 0x1D9C50u: goto label_1d9c50;
            case 0x1D9C58u: goto label_1d9c58;
            case 0x1D9C60u: goto label_1d9c60;
            case 0x1D9C70u: goto label_1d9c70;
            case 0x1D9CA0u: goto label_1d9ca0;
            case 0x1D9CA8u: goto label_1d9ca8;
            case 0x1D9CD0u: goto label_1d9cd0;
            case 0x1D9CD8u: goto label_1d9cd8;
            case 0x1D9CE0u: goto label_1d9ce0;
            case 0x1D9CE8u: goto label_1d9ce8;
            case 0x1D9D14u: goto label_1d9d14;
            case 0x1D9D28u: goto label_1d9d28;
            case 0x1D9D30u: goto label_1d9d30;
            case 0x1D9D40u: goto label_1d9d40;
            case 0x1D9D88u: goto label_1d9d88;
            case 0x1D9DE0u: goto label_1d9de0;
            case 0x1D9DF8u: goto label_1d9df8;
            case 0x1D9E28u: goto label_1d9e28;
            case 0x1D9E30u: goto label_1d9e30;
            case 0x1D9E60u: goto label_1d9e60;
            case 0x1D9E68u: goto label_1d9e68;
            case 0x1D9E70u: goto label_1d9e70;
            case 0x1D9EA0u: goto label_1d9ea0;
            case 0x1D9EB4u: goto label_1d9eb4;
            case 0x1D9ED8u: goto label_1d9ed8;
            case 0x1D9EF0u: goto label_1d9ef0;
            case 0x1D9EF8u: goto label_1d9ef8;
            case 0x1D9F18u: goto label_1d9f18;
            case 0x1D9F40u: goto label_1d9f40;
            case 0x1D9F60u: goto label_1d9f60;
            case 0x1D9F78u: goto label_1d9f78;
            case 0x1D9F90u: goto label_1d9f90;
            case 0x1D9F98u: goto label_1d9f98;
            case 0x1D9FA8u: goto label_1d9fa8;
            case 0x1D9FC0u: goto label_1d9fc0;
            case 0x1D9FD4u: goto label_1d9fd4;
            case 0x1D9FF8u: goto label_1d9ff8;
            case 0x1DA010u: goto label_1da010;
            case 0x1DA030u: goto label_1da030;
            case 0x1DA040u: goto label_1da040;
            case 0x1DA050u: goto label_1da050;
            case 0x1DA0B8u: goto label_1da0b8;
            case 0x1DA0D0u: goto label_1da0d0;
            case 0x1DA100u: goto label_1da100;
            case 0x1DA128u: goto label_1da128;
            case 0x1DA13Cu: goto label_1da13c;
            case 0x1DA160u: goto label_1da160;
            case 0x1DA178u: goto label_1da178;
            case 0x1DA180u: goto label_1da180;
            case 0x1DA1A0u: goto label_1da1a0;
            case 0x1DA1B4u: goto label_1da1b4;
            case 0x1DA1D8u: goto label_1da1d8;
            case 0x1DA1E0u: goto label_1da1e0;
            case 0x1DA228u: goto label_1da228;
            case 0x1DA240u: goto label_1da240;
            case 0x1DA248u: goto label_1da248;
            case 0x1DA280u: goto label_1da280;
            case 0x1DA288u: goto label_1da288;
            case 0x1DA290u: goto label_1da290;
            case 0x1DA2B0u: goto label_1da2b0;
            case 0x1DA2B8u: goto label_1da2b8;
            case 0x1DA2CCu: goto label_1da2cc;
            case 0x1DA2D4u: goto label_1da2d4;
            case 0x1DA2F0u: goto label_1da2f0;
            case 0x1DA2F8u: goto label_1da2f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D9D98u;
    // 0x1d9d98: 0x0  nop
    ctx->pc = 0x1d9d98u;
    // NOP
    // 0x1d9d9c: 0x0  nop
    ctx->pc = 0x1d9d9cu;
    // NOP
    // 0x1d9da0: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x1d9da0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1d9da4: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1d9da4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1d9da8: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1d9da8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1d9dac: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1d9dacu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1d9db0: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x1d9db0u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9db4: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d9db4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d9db8: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x1d9db8u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9dbc: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d9dbcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d9dc0: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d9dc0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d9dc4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d9dc4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d9dc8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d9dc8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d9dcc: 0x4800004  bltz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D9DCCu;
    {
        const bool branch_taken_0x1d9dcc = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x1D9DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9DCCu;
            // 0x1d9dd0: 0xa7a0008e  sh          $zero, 0x8E($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 142), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9dcc) {
            ctx->pc = 0x1D9DE0u;
            goto label_1d9de0;
        }
    }
    ctx->pc = 0x1D9DD4u;
    // 0x1d9dd4: 0x28820003  slti        $v0, $a0, 0x3
    ctx->pc = 0x1d9dd4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1d9dd8: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D9DD8u;
    {
        const bool branch_taken_0x1d9dd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d9dd8) {
            ctx->pc = 0x1D9DF8u;
            goto label_1d9df8;
        }
    }
    ctx->pc = 0x1D9DE0u;
label_1d9de0:
    // 0x1d9de0: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1d9de0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1d9de4: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9de4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9de8: 0xac228c88  sw          $v0, -0x7378($at)
    ctx->pc = 0x1d9de8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 2));
    // 0x1d9dec: 0x10000098  b           . + 4 + (0x98 << 2)
    ctx->pc = 0x1D9DECu;
    {
        const bool branch_taken_0x1d9dec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9DF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9DECu;
            // 0x1d9df0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9dec) {
            ctx->pc = 0x1DA050u;
            goto label_1da050;
        }
    }
    ctx->pc = 0x1D9DF4u;
    // 0x1d9df4: 0x0  nop
    ctx->pc = 0x1d9df4u;
    // NOP
label_1d9df8:
    // 0x1d9df8: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1d9df8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1d9dfc: 0x49080  sll         $s2, $a0, 2
    ctx->pc = 0x1d9dfcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1d9e00: 0x24428c90  addiu       $v0, $v0, -0x7370
    ctx->pc = 0x1d9e00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937744));
    // 0x1d9e04: 0x528021  addu        $s0, $v0, $s2
    ctx->pc = 0x1d9e04u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1d9e08: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1d9e08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d9e0c: 0x441008c  bgez        $v0, . + 4 + (0x8C << 2)
    ctx->pc = 0x1D9E0Cu;
    {
        const bool branch_taken_0x1d9e0c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1D9E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9E0Cu;
            // 0x1d9e10: 0x24030009  addiu       $v1, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9e0c) {
            ctx->pc = 0x1DA040u;
            goto label_1da040;
        }
    }
    ctx->pc = 0x1D9E14u;
    // 0x1d9e14: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9e14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9e18: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d9e18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9e1c: 0x1000008c  b           . + 4 + (0x8C << 2)
    ctx->pc = 0x1D9E1Cu;
    {
        const bool branch_taken_0x1d9e1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9E20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9E1Cu;
            // 0x1d9e20: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9e1c) {
            ctx->pc = 0x1DA050u;
            goto label_1da050;
        }
    }
    ctx->pc = 0x1D9E24u;
    // 0x1d9e24: 0x0  nop
    ctx->pc = 0x1d9e24u;
    // NOP
label_1d9e28:
    // 0x1d9e28: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1D9E28u;
    SET_GPR_U32(ctx, 31, 0x1D9E30u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9E30u; }
        if (ctx->pc != 0x1D9E30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9E30u; }
        if (ctx->pc != 0x1D9E30u) { return; }
    }
    ctx->pc = 0x1D9E30u;
label_1d9e30:
    // 0x1d9e30: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1d9e30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1d9e34: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d9e34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d9e38: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1D9E38u;
    {
        const bool branch_taken_0x1d9e38 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1D9E3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9E38u;
            // 0x1d9e3c: 0x3c020035  lui         $v0, 0x35 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9e38) {
            ctx->pc = 0x1D9E68u;
            goto label_1d9e68;
        }
    }
    ctx->pc = 0x1D9E40u;
    // 0x1d9e40: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1d9e40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9e44: 0x24428c70  addiu       $v0, $v0, -0x7390
    ctx->pc = 0x1d9e44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937712));
    // 0x1d9e48: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9e48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9e4c: 0x521821  addu        $v1, $v0, $s2
    ctx->pc = 0x1d9e4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1d9e50: 0x24020071  addiu       $v0, $zero, 0x71
    ctx->pc = 0x1d9e50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 113));
    // 0x1d9e54: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x1d9e54u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x1d9e58: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9E58u;
    SET_GPR_U32(ctx, 31, 0x1D9E60u);
    ctx->pc = 0x1D9E5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9E58u;
            // 0x1d9e5c: 0xac228c88  sw          $v0, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9E60u; }
        if (ctx->pc != 0x1D9E60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9E60u; }
        if (ctx->pc != 0x1D9E60u) { return; }
    }
    ctx->pc = 0x1D9E60u;
label_1d9e60:
    // 0x1d9e60: 0x1000007b  b           . + 4 + (0x7B << 2)
    ctx->pc = 0x1D9E60u;
    {
        const bool branch_taken_0x1d9e60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9E64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9E60u;
            // 0x1d9e64: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9e60) {
            ctx->pc = 0x1DA050u;
            goto label_1da050;
        }
    }
    ctx->pc = 0x1D9E68u;
label_1d9e68:
    // 0x1d9e68: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9E68u;
    SET_GPR_U32(ctx, 31, 0x1D9E70u);
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9E70u; }
        if (ctx->pc != 0x1D9E70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9E70u; }
        if (ctx->pc != 0x1D9E70u) { return; }
    }
    ctx->pc = 0x1D9E70u;
label_1d9e70:
    // 0x1d9e70: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1d9e70u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9e74: 0x280182d  daddu       $v1, $s4, $zero
    ctx->pc = 0x1d9e74u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9e78: 0x26820001  addiu       $v0, $s4, 0x1
    ctx->pc = 0x1d9e78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x1d9e7c: 0x2a43c  dsll32      $s4, $v0, 16
    ctx->pc = 0x1d9e7cu;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d9e80: 0x3143c  dsll32      $v0, $v1, 16
    ctx->pc = 0x1d9e80u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1d9e84: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d9e84u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d9e88: 0x284141a0  slti        $at, $v0, 0x41A0
    ctx->pc = 0x1d9e88u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16800) ? 1 : 0);
    // 0x1d9e8c: 0x10200022  beqz        $at, . + 4 + (0x22 << 2)
    ctx->pc = 0x1D9E8Cu;
    {
        const bool branch_taken_0x1d9e8c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9E90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9E8Cu;
            // 0x1d9e90: 0x14a43f  dsra32      $s4, $s4, 16 (Delay Slot)
        SET_GPR_S64(ctx, 20, GPR_S64(ctx, 20) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9e8c) {
            ctx->pc = 0x1D9F18u;
            goto label_1d9f18;
        }
    }
    ctx->pc = 0x1D9E94u;
    // 0x1d9e94: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1d9e94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1d9e98: 0x24428c90  addiu       $v0, $v0, -0x7370
    ctx->pc = 0x1d9e98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937744));
    // 0x1d9e9c: 0x529821  addu        $s3, $v0, $s2
    ctx->pc = 0x1d9e9cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_1d9ea0:
    // 0x1d9ea0: 0x86640000  lh          $a0, 0x0($s3)
    ctx->pc = 0x1d9ea0u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1d9ea4: 0x27a5008e  addiu       $a1, $sp, 0x8E
    ctx->pc = 0x1d9ea4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 142));
    // 0x1d9ea8: 0x27a6008c  addiu       $a2, $sp, 0x8C
    ctx->pc = 0x1d9ea8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 140));
    // 0x1d9eac: 0xc075f48  jal         func_1D7D20
    ctx->pc = 0x1D9EACu;
    SET_GPR_U32(ctx, 31, 0x1D9EB4u);
    ctx->pc = 0x1D9EB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9EACu;
            // 0x1d9eb0: 0x27a7008a  addiu       $a3, $sp, 0x8A (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 138));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7D20u;
    if (runtime->hasFunction(0x1D7D20u)) {
        auto targetFn = runtime->lookupFunction(0x1D7D20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9EB4u; }
        if (ctx->pc != 0x1D9EB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7D20_0x1d7d20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9EB4u; }
        if (ctx->pc != 0x1D9EB4u) { return; }
    }
    ctx->pc = 0x1D9EB4u;
label_1d9eb4:
    // 0x1d9eb4: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d9eb4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d9eb8: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d9eb8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d9ebc: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D9EBCu;
    {
        const bool branch_taken_0x1d9ebc = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1D9EC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9EBCu;
            // 0x1d9ec0: 0x24030068  addiu       $v1, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9ebc) {
            ctx->pc = 0x1D9ED8u;
            goto label_1d9ed8;
        }
    }
    ctx->pc = 0x1D9EC4u;
    // 0x1d9ec4: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9ec4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9ec8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d9ec8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9ecc: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1D9ECCu;
    {
        const bool branch_taken_0x1d9ecc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9ECCu;
            // 0x1d9ed0: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9ecc) {
            ctx->pc = 0x1DA050u;
            goto label_1da050;
        }
    }
    ctx->pc = 0x1D9ED4u;
    // 0x1d9ed4: 0x0  nop
    ctx->pc = 0x1d9ed4u;
    // NOP
label_1d9ed8:
    // 0x1d9ed8: 0x87a3008e  lh          $v1, 0x8E($sp)
    ctx->pc = 0x1d9ed8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 142)));
    // 0x1d9edc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1d9edcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d9ee0: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D9EE0u;
    {
        const bool branch_taken_0x1d9ee0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D9EE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9EE0u;
            // 0x1d9ee4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9ee0) {
            ctx->pc = 0x1D9EF0u;
            goto label_1d9ef0;
        }
    }
    ctx->pc = 0x1D9EE8u;
    // 0x1d9ee8: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1D9EE8u;
    {
        const bool branch_taken_0x1d9ee8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d9ee8) {
            ctx->pc = 0x1D9F18u;
            goto label_1d9f18;
        }
    }
    ctx->pc = 0x1D9EF0u;
label_1d9ef0:
    // 0x1d9ef0: 0xc07690c  jal         func_1DA430
    ctx->pc = 0x1D9EF0u;
    SET_GPR_U32(ctx, 31, 0x1D9EF8u);
    ctx->pc = 0x1DA430u;
    if (runtime->hasFunction(0x1DA430u)) {
        auto targetFn = runtime->lookupFunction(0x1DA430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9EF8u; }
        if (ctx->pc != 0x1D9EF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DA430_0x1da430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9EF8u; }
        if (ctx->pc != 0x1D9EF8u) { return; }
    }
    ctx->pc = 0x1D9EF8u;
label_1d9ef8:
    // 0x1d9ef8: 0x280182d  daddu       $v1, $s4, $zero
    ctx->pc = 0x1d9ef8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9efc: 0x26820001  addiu       $v0, $s4, 0x1
    ctx->pc = 0x1d9efcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x1d9f00: 0x2a43c  dsll32      $s4, $v0, 16
    ctx->pc = 0x1d9f00u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d9f04: 0x3143c  dsll32      $v0, $v1, 16
    ctx->pc = 0x1d9f04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1d9f08: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d9f08u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d9f0c: 0x284241a0  slti        $v0, $v0, 0x41A0
    ctx->pc = 0x1d9f0cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16800) ? 1 : 0);
    // 0x1d9f10: 0x1440ffe3  bnez        $v0, . + 4 + (-0x1D << 2)
    ctx->pc = 0x1D9F10u;
    {
        const bool branch_taken_0x1d9f10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D9F14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9F10u;
            // 0x1d9f14: 0x14a43f  dsra32      $s4, $s4, 16 (Delay Slot)
        SET_GPR_S64(ctx, 20, GPR_S64(ctx, 20) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9f10) {
            ctx->pc = 0x1D9EA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d9ea0;
        }
    }
    ctx->pc = 0x1D9F18u;
label_1d9f18:
    // 0x1d9f18: 0x87a4008e  lh          $a0, 0x8E($sp)
    ctx->pc = 0x1d9f18u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 142)));
    // 0x1d9f1c: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1d9f1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1d9f20: 0x14820007  bne         $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D9F20u;
    {
        const bool branch_taken_0x1d9f20 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d9f20) {
            ctx->pc = 0x1D9F40u;
            goto label_1d9f40;
        }
    }
    ctx->pc = 0x1D9F28u;
    // 0x1d9f28: 0x87a3008a  lh          $v1, 0x8A($sp)
    ctx->pc = 0x1d9f28u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 138)));
    // 0x1d9f2c: 0x14600012  bnez        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1D9F2Cu;
    {
        const bool branch_taken_0x1d9f2c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d9f2c) {
            ctx->pc = 0x1D9F78u;
            goto label_1d9f78;
        }
    }
    ctx->pc = 0x1D9F34u;
    // 0x1d9f34: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1D9F34u;
    {
        const bool branch_taken_0x1d9f34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9f34) {
            ctx->pc = 0x1D9F98u;
            goto label_1d9f98;
        }
    }
    ctx->pc = 0x1D9F3Cu;
    // 0x1d9f3c: 0x0  nop
    ctx->pc = 0x1d9f3cu;
    // NOP
label_1d9f40:
    // 0x1d9f40: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d9f40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9f44: 0x14820006  bne         $a0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D9F44u;
    {
        const bool branch_taken_0x1d9f44 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d9f44) {
            ctx->pc = 0x1D9F60u;
            goto label_1d9f60;
        }
    }
    ctx->pc = 0x1D9F4Cu;
    // 0x1d9f4c: 0x87a3008a  lh          $v1, 0x8A($sp)
    ctx->pc = 0x1d9f4cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 138)));
    // 0x1d9f50: 0x14600009  bnez        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D9F50u;
    {
        const bool branch_taken_0x1d9f50 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d9f50) {
            ctx->pc = 0x1D9F78u;
            goto label_1d9f78;
        }
    }
    ctx->pc = 0x1D9F58u;
    // 0x1d9f58: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1D9F58u;
    {
        const bool branch_taken_0x1d9f58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9f58) {
            ctx->pc = 0x1D9F98u;
            goto label_1d9f98;
        }
    }
    ctx->pc = 0x1D9F60u;
label_1d9f60:
    // 0x1d9f60: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1d9f60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d9f64: 0x10830004  beq         $a0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D9F64u;
    {
        const bool branch_taken_0x1d9f64 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1D9F68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9F64u;
            // 0x1d9f68: 0x24030068  addiu       $v1, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9f64) {
            ctx->pc = 0x1D9F78u;
            goto label_1d9f78;
        }
    }
    ctx->pc = 0x1D9F6Cu;
    // 0x1d9f6c: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9f6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9f70: 0x10000037  b           . + 4 + (0x37 << 2)
    ctx->pc = 0x1D9F70u;
    {
        const bool branch_taken_0x1d9f70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9F74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9F70u;
            // 0x1d9f74: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9f70) {
            ctx->pc = 0x1DA050u;
            goto label_1da050;
        }
    }
    ctx->pc = 0x1D9F78u;
label_1d9f78:
    // 0x1d9f78: 0x87a3008a  lh          $v1, 0x8A($sp)
    ctx->pc = 0x1d9f78u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 138)));
    // 0x1d9f7c: 0x3102a  slt         $v0, $zero, $v1
    ctx->pc = 0x1d9f7cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1d9f80: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D9F80u;
    {
        const bool branch_taken_0x1d9f80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d9f80) {
            ctx->pc = 0x1D9F98u;
            goto label_1d9f98;
        }
    }
    ctx->pc = 0x1D9F88u;
    // 0x1d9f88: 0xc07690c  jal         func_1DA430
    ctx->pc = 0x1D9F88u;
    SET_GPR_U32(ctx, 31, 0x1D9F90u);
    ctx->pc = 0x1DA430u;
    if (runtime->hasFunction(0x1DA430u)) {
        auto targetFn = runtime->lookupFunction(0x1DA430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9F90u; }
        if (ctx->pc != 0x1D9F90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DA430_0x1da430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9F90u; }
        if (ctx->pc != 0x1D9F90u) { return; }
    }
    ctx->pc = 0x1D9F90u;
label_1d9f90:
    // 0x1d9f90: 0x1000ffa5  b           . + 4 + (-0x5B << 2)
    ctx->pc = 0x1D9F90u;
    {
        const bool branch_taken_0x1d9f90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9f90) {
            ctx->pc = 0x1D9E28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d9e28;
        }
    }
    ctx->pc = 0x1D9F98u;
label_1d9f98:
    // 0x1d9f98: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D9F98u;
    {
        const bool branch_taken_0x1d9f98 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D9F9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9F98u;
            // 0x1d9f9c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9f98) {
            ctx->pc = 0x1D9FA8u;
            goto label_1d9fa8;
        }
    }
    ctx->pc = 0x1D9FA0u;
    // 0x1d9fa0: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1D9FA0u;
    {
        const bool branch_taken_0x1d9fa0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9fa0) {
            ctx->pc = 0x1DA030u;
            goto label_1da030;
        }
    }
    ctx->pc = 0x1D9FA8u;
label_1d9fa8:
    // 0x1d9fa8: 0x75082b  sltu        $at, $v1, $s5
    ctx->pc = 0x1d9fa8u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 21)) ? 1 : 0);
    // 0x1d9fac: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D9FACu;
    {
        const bool branch_taken_0x1d9fac = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9fac) {
            ctx->pc = 0x1D9FC0u;
            goto label_1d9fc0;
        }
    }
    ctx->pc = 0x1D9FB4u;
    // 0x1d9fb4: 0x3ac3c  dsll32      $s5, $v1, 16
    ctx->pc = 0x1d9fb4u;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1d9fb8: 0x15ac3f  dsra32      $s5, $s5, 16
    ctx->pc = 0x1d9fb8u;
    SET_GPR_S64(ctx, 21, GPR_S64(ctx, 21) >> (32 + 16));
    // 0x1d9fbc: 0x0  nop
    ctx->pc = 0x1d9fbcu;
    // NOP
label_1d9fc0:
    // 0x1d9fc0: 0x86040000  lh          $a0, 0x0($s0)
    ctx->pc = 0x1d9fc0u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d9fc4: 0x15343c  dsll32      $a2, $s5, 16
    ctx->pc = 0x1d9fc4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 21) << (32 + 16));
    // 0x1d9fc8: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x1d9fc8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9fcc: 0xc075fd8  jal         func_1D7F60
    ctx->pc = 0x1D9FCCu;
    SET_GPR_U32(ctx, 31, 0x1D9FD4u);
    ctx->pc = 0x1D9FD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9FCCu;
            // 0x1d9fd0: 0x6343f  dsra32      $a2, $a2, 16 (Delay Slot)
        SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7F60u;
    if (runtime->hasFunction(0x1D7F60u)) {
        auto targetFn = runtime->lookupFunction(0x1D7F60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9FD4u; }
        if (ctx->pc != 0x1D9FD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7F60_0x1d7f60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9FD4u; }
        if (ctx->pc != 0x1D9FD4u) { return; }
    }
    ctx->pc = 0x1D9FD4u;
label_1d9fd4:
    // 0x1d9fd4: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1d9fd4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d9fd8: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1d9fd8u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1d9fdc: 0x4810006  bgez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D9FDCu;
    {
        const bool branch_taken_0x1d9fdc = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x1D9FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9FDCu;
            // 0x1d9fe0: 0x24030068  addiu       $v1, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9fdc) {
            ctx->pc = 0x1D9FF8u;
            goto label_1d9ff8;
        }
    }
    ctx->pc = 0x1D9FE4u;
    // 0x1d9fe4: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9fe4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9fe8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d9fe8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9fec: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1D9FECu;
    {
        const bool branch_taken_0x1d9fec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9FF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9FECu;
            // 0x1d9ff0: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9fec) {
            ctx->pc = 0x1DA050u;
            goto label_1da050;
        }
    }
    ctx->pc = 0x1D9FF4u;
    // 0x1d9ff4: 0x0  nop
    ctx->pc = 0x1d9ff4u;
    // NOP
label_1d9ff8:
    // 0x1d9ff8: 0x87a3008e  lh          $v1, 0x8E($sp)
    ctx->pc = 0x1d9ff8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 142)));
    // 0x1d9ffc: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1d9ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1da000: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DA000u;
    {
        const bool branch_taken_0x1da000 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1DA004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA000u;
            // 0x1da004: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da000) {
            ctx->pc = 0x1DA010u;
            goto label_1da010;
        }
    }
    ctx->pc = 0x1DA008u;
    // 0x1da008: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DA008u;
    {
        const bool branch_taken_0x1da008 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1da008) {
            ctx->pc = 0x1DA030u;
            goto label_1da030;
        }
    }
    ctx->pc = 0x1DA010u;
label_1da010:
    // 0x1da010: 0x14950007  bne         $a0, $s5, . + 4 + (0x7 << 2)
    ctx->pc = 0x1DA010u;
    {
        const bool branch_taken_0x1da010 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 21));
        if (branch_taken_0x1da010) {
            ctx->pc = 0x1DA030u;
            goto label_1da030;
        }
    }
    ctx->pc = 0x1DA018u;
    // 0x1da018: 0x87a2008a  lh          $v0, 0x8A($sp)
    ctx->pc = 0x1da018u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 138)));
    // 0x1da01c: 0x14820004  bne         $a0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DA01Cu;
    {
        const bool branch_taken_0x1da01c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x1DA020u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA01Cu;
            // 0x1da020: 0x24020068  addiu       $v0, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da01c) {
            ctx->pc = 0x1DA030u;
            goto label_1da030;
        }
    }
    ctx->pc = 0x1DA024u;
    // 0x1da024: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1da024u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1da028: 0xac228c88  sw          $v0, -0x7378($at)
    ctx->pc = 0x1da028u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 2));
    // 0x1da02c: 0x0  nop
    ctx->pc = 0x1da02cu;
    // NOP
label_1da030:
    // 0x1da030: 0x4143c  dsll32      $v0, $a0, 16
    ctx->pc = 0x1da030u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) << (32 + 16));
    // 0x1da034: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1DA034u;
    {
        const bool branch_taken_0x1da034 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA034u;
            // 0x1da038: 0x2143f  dsra32      $v0, $v0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da034) {
            ctx->pc = 0x1DA050u;
            goto label_1da050;
        }
    }
    ctx->pc = 0x1DA03Cu;
    // 0x1da03c: 0x0  nop
    ctx->pc = 0x1da03cu;
    // NOP
label_1da040:
    // 0x1da040: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1da040u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1da044: 0x24428c70  addiu       $v0, $v0, -0x7390
    ctx->pc = 0x1da044u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937712));
    // 0x1da048: 0x1000ff77  b           . + 4 + (-0x89 << 2)
    ctx->pc = 0x1DA048u;
    {
        const bool branch_taken_0x1da048 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA04Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA048u;
            // 0x1da04c: 0x528821  addu        $s1, $v0, $s2 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da048) {
            ctx->pc = 0x1D9E28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d9e28;
        }
    }
    ctx->pc = 0x1DA050u;
label_1da050:
    // 0x1da050: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1da050u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1da054: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1da054u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1da058: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1da058u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1da05c: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1da05cu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1da060: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1da060u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1da064: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1da064u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1da068: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1da068u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1da06c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1da06cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1da070: 0x3e00008  jr          $ra
    ctx->pc = 0x1DA070u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1DA074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA070u;
            // 0x1da074: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9AA0u: goto label_1d9aa0;
            case 0x1D9ABCu: goto label_1d9abc;
            case 0x1D9AC8u: goto label_1d9ac8;
            case 0x1D9AD8u: goto label_1d9ad8;
            case 0x1D9B1Cu: goto label_1d9b1c;
            case 0x1D9B38u: goto label_1d9b38;
            case 0x1D9B48u: goto label_1d9b48;
            case 0x1D9B50u: goto label_1d9b50;
            case 0x1D9B58u: goto label_1d9b58;
            case 0x1D9B68u: goto label_1d9b68;
            case 0x1D9B98u: goto label_1d9b98;
            case 0x1D9BA8u: goto label_1d9ba8;
            case 0x1D9BCCu: goto label_1d9bcc;
            case 0x1D9C00u: goto label_1d9c00;
            case 0x1D9C08u: goto label_1d9c08;
            case 0x1D9C18u: goto label_1d9c18;
            case 0x1D9C2Cu: goto label_1d9c2c;
            case 0x1D9C34u: goto label_1d9c34;
            case 0x1D9C40u: goto label_1d9c40;
            case 0x1D9C48u: goto label_1d9c48;
            case 0x1D9C50u: goto label_1d9c50;
            case 0x1D9C58u: goto label_1d9c58;
            case 0x1D9C60u: goto label_1d9c60;
            case 0x1D9C70u: goto label_1d9c70;
            case 0x1D9CA0u: goto label_1d9ca0;
            case 0x1D9CA8u: goto label_1d9ca8;
            case 0x1D9CD0u: goto label_1d9cd0;
            case 0x1D9CD8u: goto label_1d9cd8;
            case 0x1D9CE0u: goto label_1d9ce0;
            case 0x1D9CE8u: goto label_1d9ce8;
            case 0x1D9D14u: goto label_1d9d14;
            case 0x1D9D28u: goto label_1d9d28;
            case 0x1D9D30u: goto label_1d9d30;
            case 0x1D9D40u: goto label_1d9d40;
            case 0x1D9D88u: goto label_1d9d88;
            case 0x1D9DE0u: goto label_1d9de0;
            case 0x1D9DF8u: goto label_1d9df8;
            case 0x1D9E28u: goto label_1d9e28;
            case 0x1D9E30u: goto label_1d9e30;
            case 0x1D9E60u: goto label_1d9e60;
            case 0x1D9E68u: goto label_1d9e68;
            case 0x1D9E70u: goto label_1d9e70;
            case 0x1D9EA0u: goto label_1d9ea0;
            case 0x1D9EB4u: goto label_1d9eb4;
            case 0x1D9ED8u: goto label_1d9ed8;
            case 0x1D9EF0u: goto label_1d9ef0;
            case 0x1D9EF8u: goto label_1d9ef8;
            case 0x1D9F18u: goto label_1d9f18;
            case 0x1D9F40u: goto label_1d9f40;
            case 0x1D9F60u: goto label_1d9f60;
            case 0x1D9F78u: goto label_1d9f78;
            case 0x1D9F90u: goto label_1d9f90;
            case 0x1D9F98u: goto label_1d9f98;
            case 0x1D9FA8u: goto label_1d9fa8;
            case 0x1D9FC0u: goto label_1d9fc0;
            case 0x1D9FD4u: goto label_1d9fd4;
            case 0x1D9FF8u: goto label_1d9ff8;
            case 0x1DA010u: goto label_1da010;
            case 0x1DA030u: goto label_1da030;
            case 0x1DA040u: goto label_1da040;
            case 0x1DA050u: goto label_1da050;
            case 0x1DA0B8u: goto label_1da0b8;
            case 0x1DA0D0u: goto label_1da0d0;
            case 0x1DA100u: goto label_1da100;
            case 0x1DA128u: goto label_1da128;
            case 0x1DA13Cu: goto label_1da13c;
            case 0x1DA160u: goto label_1da160;
            case 0x1DA178u: goto label_1da178;
            case 0x1DA180u: goto label_1da180;
            case 0x1DA1A0u: goto label_1da1a0;
            case 0x1DA1B4u: goto label_1da1b4;
            case 0x1DA1D8u: goto label_1da1d8;
            case 0x1DA1E0u: goto label_1da1e0;
            case 0x1DA228u: goto label_1da228;
            case 0x1DA240u: goto label_1da240;
            case 0x1DA248u: goto label_1da248;
            case 0x1DA280u: goto label_1da280;
            case 0x1DA288u: goto label_1da288;
            case 0x1DA290u: goto label_1da290;
            case 0x1DA2B0u: goto label_1da2b0;
            case 0x1DA2B8u: goto label_1da2b8;
            case 0x1DA2CCu: goto label_1da2cc;
            case 0x1DA2D4u: goto label_1da2d4;
            case 0x1DA2F0u: goto label_1da2f0;
            case 0x1DA2F8u: goto label_1da2f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DA078u;
    // 0x1da078: 0x0  nop
    ctx->pc = 0x1da078u;
    // NOP
    // 0x1da07c: 0x0  nop
    ctx->pc = 0x1da07cu;
    // NOP
    // 0x1da080: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1da080u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1da084: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1da084u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1da088: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1da088u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1da08c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1da08cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1da090: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1da090u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da094: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1da094u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1da098: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1da098u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da09c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1da09cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1da0a0: 0x4800005  bltz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1DA0A0u;
    {
        const bool branch_taken_0x1da0a0 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x1DA0A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA0A0u;
            // 0x1da0a4: 0xa7a0005e  sh          $zero, 0x5E($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 94), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da0a0) {
            ctx->pc = 0x1DA0B8u;
            goto label_1da0b8;
        }
    }
    ctx->pc = 0x1DA0A8u;
    // 0x1da0a8: 0x28820003  slti        $v0, $a0, 0x3
    ctx->pc = 0x1da0a8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1da0ac: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1DA0ACu;
    {
        const bool branch_taken_0x1da0ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1da0ac) {
            ctx->pc = 0x1DA0D0u;
            goto label_1da0d0;
        }
    }
    ctx->pc = 0x1DA0B4u;
    // 0x1da0b4: 0x0  nop
    ctx->pc = 0x1da0b4u;
    // NOP
label_1da0b8:
    // 0x1da0b8: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1da0b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1da0bc: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1da0bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1da0c0: 0xac228c88  sw          $v0, -0x7378($at)
    ctx->pc = 0x1da0c0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 2));
    // 0x1da0c4: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x1DA0C4u;
    {
        const bool branch_taken_0x1da0c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA0C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA0C4u;
            // 0x1da0c8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da0c4) {
            ctx->pc = 0x1DA1E0u;
            goto label_1da1e0;
        }
    }
    ctx->pc = 0x1DA0CCu;
    // 0x1da0cc: 0x0  nop
    ctx->pc = 0x1da0ccu;
    // NOP
label_1da0d0:
    // 0x1da0d0: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1da0d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1da0d4: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1da0d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1da0d8: 0x24428c90  addiu       $v0, $v0, -0x7370
    ctx->pc = 0x1da0d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937744));
    // 0x1da0dc: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x1da0dcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1da0e0: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1da0e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1da0e4: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1DA0E4u;
    {
        const bool branch_taken_0x1da0e4 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1DA0E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA0E4u;
            // 0x1da0e8: 0x24030009  addiu       $v1, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da0e4) {
            ctx->pc = 0x1DA100u;
            goto label_1da100;
        }
    }
    ctx->pc = 0x1DA0ECu;
    // 0x1da0ec: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1da0ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1da0f0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1da0f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1da0f4: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1DA0F4u;
    {
        const bool branch_taken_0x1da0f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA0F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA0F4u;
            // 0x1da0f8: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da0f4) {
            ctx->pc = 0x1DA1E0u;
            goto label_1da1e0;
        }
    }
    ctx->pc = 0x1DA0FCu;
    // 0x1da0fc: 0x0  nop
    ctx->pc = 0x1da0fcu;
    // NOP
label_1da100:
    // 0x1da100: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1da100u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da104: 0x220182d  daddu       $v1, $s1, $zero
    ctx->pc = 0x1da104u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da108: 0x26220001  addiu       $v0, $s1, 0x1
    ctx->pc = 0x1da108u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1da10c: 0x28c3c  dsll32      $s1, $v0, 16
    ctx->pc = 0x1da10cu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1da110: 0x3143c  dsll32      $v0, $v1, 16
    ctx->pc = 0x1da110u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1da114: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1da114u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1da118: 0x284141a0  slti        $at, $v0, 0x41A0
    ctx->pc = 0x1da118u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16800) ? 1 : 0);
    // 0x1da11c: 0x10200020  beqz        $at, . + 4 + (0x20 << 2)
    ctx->pc = 0x1DA11Cu;
    {
        const bool branch_taken_0x1da11c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA11Cu;
            // 0x1da120: 0x118c3f  dsra32      $s1, $s1, 16 (Delay Slot)
        SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da11c) {
            ctx->pc = 0x1DA1A0u;
            goto label_1da1a0;
        }
    }
    ctx->pc = 0x1DA124u;
    // 0x1da124: 0x0  nop
    ctx->pc = 0x1da124u;
    // NOP
label_1da128:
    // 0x1da128: 0x86040000  lh          $a0, 0x0($s0)
    ctx->pc = 0x1da128u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1da12c: 0x27a5005e  addiu       $a1, $sp, 0x5E
    ctx->pc = 0x1da12cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 94));
    // 0x1da130: 0x27a6005c  addiu       $a2, $sp, 0x5C
    ctx->pc = 0x1da130u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 92));
    // 0x1da134: 0xc075f48  jal         func_1D7D20
    ctx->pc = 0x1DA134u;
    SET_GPR_U32(ctx, 31, 0x1DA13Cu);
    ctx->pc = 0x1DA138u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA134u;
            // 0x1da138: 0x27a7005a  addiu       $a3, $sp, 0x5A (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 90));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7D20u;
    if (runtime->hasFunction(0x1D7D20u)) {
        auto targetFn = runtime->lookupFunction(0x1D7D20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA13Cu; }
        if (ctx->pc != 0x1DA13Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7D20_0x1d7d20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA13Cu; }
        if (ctx->pc != 0x1DA13Cu) { return; }
    }
    ctx->pc = 0x1DA13Cu;
label_1da13c:
    // 0x1da13c: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1da13cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1da140: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1da140u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1da144: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1DA144u;
    {
        const bool branch_taken_0x1da144 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1DA148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA144u;
            // 0x1da148: 0x24030068  addiu       $v1, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da144) {
            ctx->pc = 0x1DA160u;
            goto label_1da160;
        }
    }
    ctx->pc = 0x1DA14Cu;
    // 0x1da14c: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1da14cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1da150: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1da150u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1da154: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1DA154u;
    {
        const bool branch_taken_0x1da154 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA154u;
            // 0x1da158: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da154) {
            ctx->pc = 0x1DA1E0u;
            goto label_1da1e0;
        }
    }
    ctx->pc = 0x1DA15Cu;
    // 0x1da15c: 0x0  nop
    ctx->pc = 0x1da15cu;
    // NOP
label_1da160:
    // 0x1da160: 0x87a3005e  lh          $v1, 0x5E($sp)
    ctx->pc = 0x1da160u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 94)));
    // 0x1da164: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1da164u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1da168: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DA168u;
    {
        const bool branch_taken_0x1da168 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1DA16Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA168u;
            // 0x1da16c: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da168) {
            ctx->pc = 0x1DA178u;
            goto label_1da178;
        }
    }
    ctx->pc = 0x1DA170u;
    // 0x1da170: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1DA170u;
    {
        const bool branch_taken_0x1da170 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1da170) {
            ctx->pc = 0x1DA1A0u;
            goto label_1da1a0;
        }
    }
    ctx->pc = 0x1DA178u;
label_1da178:
    // 0x1da178: 0xc07690c  jal         func_1DA430
    ctx->pc = 0x1DA178u;
    SET_GPR_U32(ctx, 31, 0x1DA180u);
    ctx->pc = 0x1DA430u;
    if (runtime->hasFunction(0x1DA430u)) {
        auto targetFn = runtime->lookupFunction(0x1DA430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA180u; }
        if (ctx->pc != 0x1DA180u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DA430_0x1da430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA180u; }
        if (ctx->pc != 0x1DA180u) { return; }
    }
    ctx->pc = 0x1DA180u;
label_1da180:
    // 0x1da180: 0x220182d  daddu       $v1, $s1, $zero
    ctx->pc = 0x1da180u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da184: 0x26220001  addiu       $v0, $s1, 0x1
    ctx->pc = 0x1da184u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1da188: 0x28c3c  dsll32      $s1, $v0, 16
    ctx->pc = 0x1da188u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1da18c: 0x3143c  dsll32      $v0, $v1, 16
    ctx->pc = 0x1da18cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1da190: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1da190u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1da194: 0x284241a0  slti        $v0, $v0, 0x41A0
    ctx->pc = 0x1da194u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16800) ? 1 : 0);
    // 0x1da198: 0x1440ffe3  bnez        $v0, . + 4 + (-0x1D << 2)
    ctx->pc = 0x1DA198u;
    {
        const bool branch_taken_0x1da198 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1DA19Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA198u;
            // 0x1da19c: 0x118c3f  dsra32      $s1, $s1, 16 (Delay Slot)
        SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da198) {
            ctx->pc = 0x1DA128u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1da128;
        }
    }
    ctx->pc = 0x1DA1A0u;
label_1da1a0:
    // 0x1da1a0: 0x86040000  lh          $a0, 0x0($s0)
    ctx->pc = 0x1da1a0u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1da1a4: 0x12343c  dsll32      $a2, $s2, 16
    ctx->pc = 0x1da1a4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 18) << (32 + 16));
    // 0x1da1a8: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1da1a8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da1ac: 0xc075f70  jal         func_1D7DC0
    ctx->pc = 0x1DA1ACu;
    SET_GPR_U32(ctx, 31, 0x1DA1B4u);
    ctx->pc = 0x1DA1B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA1ACu;
            // 0x1da1b0: 0x6343f  dsra32      $a2, $a2, 16 (Delay Slot)
        SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7DC0u;
    if (runtime->hasFunction(0x1D7DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D7DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA1B4u; }
        if (ctx->pc != 0x1DA1B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7DC0_0x1d7dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA1B4u; }
        if (ctx->pc != 0x1DA1B4u) { return; }
    }
    ctx->pc = 0x1DA1B4u;
label_1da1b4:
    // 0x1da1b4: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1da1b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1da1b8: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1da1b8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1da1bc: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1DA1BCu;
    {
        const bool branch_taken_0x1da1bc = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1DA1C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA1BCu;
            // 0x1da1c0: 0x24030068  addiu       $v1, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da1bc) {
            ctx->pc = 0x1DA1D8u;
            goto label_1da1d8;
        }
    }
    ctx->pc = 0x1DA1C4u;
    // 0x1da1c4: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1da1c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1da1c8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1da1c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1da1cc: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1DA1CCu;
    {
        const bool branch_taken_0x1da1cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA1D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA1CCu;
            // 0x1da1d0: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da1cc) {
            ctx->pc = 0x1DA1E0u;
            goto label_1da1e0;
        }
    }
    ctx->pc = 0x1DA1D4u;
    // 0x1da1d4: 0x0  nop
    ctx->pc = 0x1da1d4u;
    // NOP
label_1da1d8:
    // 0x1da1d8: 0x12103c  dsll32      $v0, $s2, 0
    ctx->pc = 0x1da1d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) << (32 + 0));
    // 0x1da1dc: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1da1dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
label_1da1e0:
    // 0x1da1e0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1da1e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1da1e4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1da1e4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1da1e8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1da1e8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1da1ec: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1da1ecu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1da1f0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1da1f0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1da1f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1DA1F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1DA1F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA1F4u;
            // 0x1da1f8: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9AA0u: goto label_1d9aa0;
            case 0x1D9ABCu: goto label_1d9abc;
            case 0x1D9AC8u: goto label_1d9ac8;
            case 0x1D9AD8u: goto label_1d9ad8;
            case 0x1D9B1Cu: goto label_1d9b1c;
            case 0x1D9B38u: goto label_1d9b38;
            case 0x1D9B48u: goto label_1d9b48;
            case 0x1D9B50u: goto label_1d9b50;
            case 0x1D9B58u: goto label_1d9b58;
            case 0x1D9B68u: goto label_1d9b68;
            case 0x1D9B98u: goto label_1d9b98;
            case 0x1D9BA8u: goto label_1d9ba8;
            case 0x1D9BCCu: goto label_1d9bcc;
            case 0x1D9C00u: goto label_1d9c00;
            case 0x1D9C08u: goto label_1d9c08;
            case 0x1D9C18u: goto label_1d9c18;
            case 0x1D9C2Cu: goto label_1d9c2c;
            case 0x1D9C34u: goto label_1d9c34;
            case 0x1D9C40u: goto label_1d9c40;
            case 0x1D9C48u: goto label_1d9c48;
            case 0x1D9C50u: goto label_1d9c50;
            case 0x1D9C58u: goto label_1d9c58;
            case 0x1D9C60u: goto label_1d9c60;
            case 0x1D9C70u: goto label_1d9c70;
            case 0x1D9CA0u: goto label_1d9ca0;
            case 0x1D9CA8u: goto label_1d9ca8;
            case 0x1D9CD0u: goto label_1d9cd0;
            case 0x1D9CD8u: goto label_1d9cd8;
            case 0x1D9CE0u: goto label_1d9ce0;
            case 0x1D9CE8u: goto label_1d9ce8;
            case 0x1D9D14u: goto label_1d9d14;
            case 0x1D9D28u: goto label_1d9d28;
            case 0x1D9D30u: goto label_1d9d30;
            case 0x1D9D40u: goto label_1d9d40;
            case 0x1D9D88u: goto label_1d9d88;
            case 0x1D9DE0u: goto label_1d9de0;
            case 0x1D9DF8u: goto label_1d9df8;
            case 0x1D9E28u: goto label_1d9e28;
            case 0x1D9E30u: goto label_1d9e30;
            case 0x1D9E60u: goto label_1d9e60;
            case 0x1D9E68u: goto label_1d9e68;
            case 0x1D9E70u: goto label_1d9e70;
            case 0x1D9EA0u: goto label_1d9ea0;
            case 0x1D9EB4u: goto label_1d9eb4;
            case 0x1D9ED8u: goto label_1d9ed8;
            case 0x1D9EF0u: goto label_1d9ef0;
            case 0x1D9EF8u: goto label_1d9ef8;
            case 0x1D9F18u: goto label_1d9f18;
            case 0x1D9F40u: goto label_1d9f40;
            case 0x1D9F60u: goto label_1d9f60;
            case 0x1D9F78u: goto label_1d9f78;
            case 0x1D9F90u: goto label_1d9f90;
            case 0x1D9F98u: goto label_1d9f98;
            case 0x1D9FA8u: goto label_1d9fa8;
            case 0x1D9FC0u: goto label_1d9fc0;
            case 0x1D9FD4u: goto label_1d9fd4;
            case 0x1D9FF8u: goto label_1d9ff8;
            case 0x1DA010u: goto label_1da010;
            case 0x1DA030u: goto label_1da030;
            case 0x1DA040u: goto label_1da040;
            case 0x1DA050u: goto label_1da050;
            case 0x1DA0B8u: goto label_1da0b8;
            case 0x1DA0D0u: goto label_1da0d0;
            case 0x1DA100u: goto label_1da100;
            case 0x1DA128u: goto label_1da128;
            case 0x1DA13Cu: goto label_1da13c;
            case 0x1DA160u: goto label_1da160;
            case 0x1DA178u: goto label_1da178;
            case 0x1DA180u: goto label_1da180;
            case 0x1DA1A0u: goto label_1da1a0;
            case 0x1DA1B4u: goto label_1da1b4;
            case 0x1DA1D8u: goto label_1da1d8;
            case 0x1DA1E0u: goto label_1da1e0;
            case 0x1DA228u: goto label_1da228;
            case 0x1DA240u: goto label_1da240;
            case 0x1DA248u: goto label_1da248;
            case 0x1DA280u: goto label_1da280;
            case 0x1DA288u: goto label_1da288;
            case 0x1DA290u: goto label_1da290;
            case 0x1DA2B0u: goto label_1da2b0;
            case 0x1DA2B8u: goto label_1da2b8;
            case 0x1DA2CCu: goto label_1da2cc;
            case 0x1DA2D4u: goto label_1da2d4;
            case 0x1DA2F0u: goto label_1da2f0;
            case 0x1DA2F8u: goto label_1da2f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DA1FCu;
    // 0x1da1fc: 0x0  nop
    ctx->pc = 0x1da1fcu;
    // NOP
    // 0x1da200: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1da200u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1da204: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1da204u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1da208: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1da208u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1da20c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1da20cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1da210: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1da210u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da214: 0x6000004  bltz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DA214u;
    {
        const bool branch_taken_0x1da214 = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x1DA218u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA214u;
            // 0x1da218: 0x2a020003  slti        $v0, $s0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da214) {
            ctx->pc = 0x1DA228u;
            goto label_1da228;
        }
    }
    ctx->pc = 0x1DA21Cu;
    // 0x1da21c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1DA21Cu;
    {
        const bool branch_taken_0x1da21c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1da21c) {
            ctx->pc = 0x1DA240u;
            goto label_1da240;
        }
    }
    ctx->pc = 0x1DA224u;
    // 0x1da224: 0x0  nop
    ctx->pc = 0x1da224u;
    // NOP
label_1da228:
    // 0x1da228: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1da228u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1da22c: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1da22cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1da230: 0xac228c88  sw          $v0, -0x7378($at)
    ctx->pc = 0x1da230u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 2));
    // 0x1da234: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x1DA234u;
    {
        const bool branch_taken_0x1da234 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA234u;
            // 0x1da238: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da234) {
            ctx->pc = 0x1DA2F8u;
            goto label_1da2f8;
        }
    }
    ctx->pc = 0x1DA23Cu;
    // 0x1da23c: 0x0  nop
    ctx->pc = 0x1da23cu;
    // NOP
label_1da240:
    // 0x1da240: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1DA240u;
    SET_GPR_U32(ctx, 31, 0x1DA248u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA248u; }
        if (ctx->pc != 0x1DA248u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA248u; }
        if (ctx->pc != 0x1DA248u) { return; }
    }
    ctx->pc = 0x1DA248u;
label_1da248:
    // 0x1da248: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1da248u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1da24c: 0x108080  sll         $s0, $s0, 2
    ctx->pc = 0x1da24cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1da250: 0x24428c90  addiu       $v0, $v0, -0x7370
    ctx->pc = 0x1da250u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937744));
    // 0x1da254: 0x508821  addu        $s1, $v0, $s0
    ctx->pc = 0x1da254u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1da258: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1da258u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1da25c: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x1da25cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1da260: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DA260u;
    {
        const bool branch_taken_0x1da260 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1DA264u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA260u;
            // 0x1da264: 0x3c020035  lui         $v0, 0x35 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da260) {
            ctx->pc = 0x1DA288u;
            goto label_1da288;
        }
    }
    ctx->pc = 0x1DA268u;
    // 0x1da268: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1da268u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1da26c: 0x24428c70  addiu       $v0, $v0, -0x7390
    ctx->pc = 0x1da26cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937712));
    // 0x1da270: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1da270u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x1da274: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1da274u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1da278: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1DA278u;
    SET_GPR_U32(ctx, 31, 0x1DA280u);
    ctx->pc = 0x1DA27Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA278u;
            // 0x1da27c: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA280u; }
        if (ctx->pc != 0x1DA280u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA280u; }
        if (ctx->pc != 0x1DA280u) { return; }
    }
    ctx->pc = 0x1DA280u;
label_1da280:
    // 0x1da280: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1DA280u;
    {
        const bool branch_taken_0x1da280 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA280u;
            // 0x1da284: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da280) {
            ctx->pc = 0x1DA2F8u;
            goto label_1da2f8;
        }
    }
    ctx->pc = 0x1DA288u;
label_1da288:
    // 0x1da288: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1DA288u;
    SET_GPR_U32(ctx, 31, 0x1DA290u);
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA290u; }
        if (ctx->pc != 0x1DA290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA290u; }
        if (ctx->pc != 0x1DA290u) { return; }
    }
    ctx->pc = 0x1DA290u;
label_1da290:
    // 0x1da290: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1da290u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1da294: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1DA294u;
    {
        const bool branch_taken_0x1da294 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1DA298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA294u;
            // 0x1da298: 0x24030009  addiu       $v1, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da294) {
            ctx->pc = 0x1DA2B0u;
            goto label_1da2b0;
        }
    }
    ctx->pc = 0x1DA29Cu;
    // 0x1da29c: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1da29cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1da2a0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1da2a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1da2a4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1DA2A4u;
    {
        const bool branch_taken_0x1da2a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA2A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA2A4u;
            // 0x1da2a8: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da2a4) {
            ctx->pc = 0x1DA2F8u;
            goto label_1da2f8;
        }
    }
    ctx->pc = 0x1DA2ACu;
    // 0x1da2ac: 0x0  nop
    ctx->pc = 0x1da2acu;
    // NOP
label_1da2b0:
    // 0x1da2b0: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1DA2B0u;
    SET_GPR_U32(ctx, 31, 0x1DA2B8u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA2B8u; }
        if (ctx->pc != 0x1DA2B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA2B8u; }
        if (ctx->pc != 0x1DA2B8u) { return; }
    }
    ctx->pc = 0x1DA2B8u;
label_1da2b8:
    // 0x1da2b8: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1da2b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1da2bc: 0x24428c90  addiu       $v0, $v0, -0x7370
    ctx->pc = 0x1da2bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937744));
    // 0x1da2c0: 0x508821  addu        $s1, $v0, $s0
    ctx->pc = 0x1da2c0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1da2c4: 0xc075f30  jal         func_1D7CC0
    ctx->pc = 0x1DA2C4u;
    SET_GPR_U32(ctx, 31, 0x1DA2CCu);
    ctx->pc = 0x1DA2C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA2C4u;
            // 0x1da2c8: 0x86240000  lh          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7CC0u;
    if (runtime->hasFunction(0x1D7CC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D7CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA2CCu; }
        if (ctx->pc != 0x1DA2CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7CC0_0x1d7cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA2CCu; }
        if (ctx->pc != 0x1DA2CCu) { return; }
    }
    ctx->pc = 0x1DA2CCu;
label_1da2cc:
    // 0x1da2cc: 0xc076060  jal         func_1D8180
    ctx->pc = 0x1DA2CCu;
    SET_GPR_U32(ctx, 31, 0x1DA2D4u);
    ctx->pc = 0x1DA2D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA2CCu;
            // 0x1da2d0: 0x86240000  lh          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D8180u;
    if (runtime->hasFunction(0x1D8180u)) {
        auto targetFn = runtime->lookupFunction(0x1D8180u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA2D4u; }
        if (ctx->pc != 0x1DA2D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8180_0x1d8180(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA2D4u; }
        if (ctx->pc != 0x1DA2D4u) { return; }
    }
    ctx->pc = 0x1DA2D4u;
label_1da2d4:
    // 0x1da2d4: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1da2d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1da2d8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1da2d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1da2dc: 0x24428c70  addiu       $v0, $v0, -0x7390
    ctx->pc = 0x1da2dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937712));
    // 0x1da2e0: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1da2e0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x1da2e4: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1da2e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1da2e8: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1DA2E8u;
    SET_GPR_U32(ctx, 31, 0x1DA2F0u);
    ctx->pc = 0x1DA2ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA2E8u;
            // 0x1da2ec: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA2F0u; }
        if (ctx->pc != 0x1DA2F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA2F0u; }
        if (ctx->pc != 0x1DA2F0u) { return; }
    }
    ctx->pc = 0x1DA2F0u;
label_1da2f0:
    // 0x1da2f0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1da2f0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da2f4: 0x0  nop
    ctx->pc = 0x1da2f4u;
    // NOP
label_1da2f8:
    // 0x1da2f8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1da2f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1da2fc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1da2fcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1da300: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1da300u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1da304: 0x3e00008  jr          $ra
    ctx->pc = 0x1DA304u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1DA308u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA304u;
            // 0x1da308: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9AA0u: goto label_1d9aa0;
            case 0x1D9ABCu: goto label_1d9abc;
            case 0x1D9AC8u: goto label_1d9ac8;
            case 0x1D9AD8u: goto label_1d9ad8;
            case 0x1D9B1Cu: goto label_1d9b1c;
            case 0x1D9B38u: goto label_1d9b38;
            case 0x1D9B48u: goto label_1d9b48;
            case 0x1D9B50u: goto label_1d9b50;
            case 0x1D9B58u: goto label_1d9b58;
            case 0x1D9B68u: goto label_1d9b68;
            case 0x1D9B98u: goto label_1d9b98;
            case 0x1D9BA8u: goto label_1d9ba8;
            case 0x1D9BCCu: goto label_1d9bcc;
            case 0x1D9C00u: goto label_1d9c00;
            case 0x1D9C08u: goto label_1d9c08;
            case 0x1D9C18u: goto label_1d9c18;
            case 0x1D9C2Cu: goto label_1d9c2c;
            case 0x1D9C34u: goto label_1d9c34;
            case 0x1D9C40u: goto label_1d9c40;
            case 0x1D9C48u: goto label_1d9c48;
            case 0x1D9C50u: goto label_1d9c50;
            case 0x1D9C58u: goto label_1d9c58;
            case 0x1D9C60u: goto label_1d9c60;
            case 0x1D9C70u: goto label_1d9c70;
            case 0x1D9CA0u: goto label_1d9ca0;
            case 0x1D9CA8u: goto label_1d9ca8;
            case 0x1D9CD0u: goto label_1d9cd0;
            case 0x1D9CD8u: goto label_1d9cd8;
            case 0x1D9CE0u: goto label_1d9ce0;
            case 0x1D9CE8u: goto label_1d9ce8;
            case 0x1D9D14u: goto label_1d9d14;
            case 0x1D9D28u: goto label_1d9d28;
            case 0x1D9D30u: goto label_1d9d30;
            case 0x1D9D40u: goto label_1d9d40;
            case 0x1D9D88u: goto label_1d9d88;
            case 0x1D9DE0u: goto label_1d9de0;
            case 0x1D9DF8u: goto label_1d9df8;
            case 0x1D9E28u: goto label_1d9e28;
            case 0x1D9E30u: goto label_1d9e30;
            case 0x1D9E60u: goto label_1d9e60;
            case 0x1D9E68u: goto label_1d9e68;
            case 0x1D9E70u: goto label_1d9e70;
            case 0x1D9EA0u: goto label_1d9ea0;
            case 0x1D9EB4u: goto label_1d9eb4;
            case 0x1D9ED8u: goto label_1d9ed8;
            case 0x1D9EF0u: goto label_1d9ef0;
            case 0x1D9EF8u: goto label_1d9ef8;
            case 0x1D9F18u: goto label_1d9f18;
            case 0x1D9F40u: goto label_1d9f40;
            case 0x1D9F60u: goto label_1d9f60;
            case 0x1D9F78u: goto label_1d9f78;
            case 0x1D9F90u: goto label_1d9f90;
            case 0x1D9F98u: goto label_1d9f98;
            case 0x1D9FA8u: goto label_1d9fa8;
            case 0x1D9FC0u: goto label_1d9fc0;
            case 0x1D9FD4u: goto label_1d9fd4;
            case 0x1D9FF8u: goto label_1d9ff8;
            case 0x1DA010u: goto label_1da010;
            case 0x1DA030u: goto label_1da030;
            case 0x1DA040u: goto label_1da040;
            case 0x1DA050u: goto label_1da050;
            case 0x1DA0B8u: goto label_1da0b8;
            case 0x1DA0D0u: goto label_1da0d0;
            case 0x1DA100u: goto label_1da100;
            case 0x1DA128u: goto label_1da128;
            case 0x1DA13Cu: goto label_1da13c;
            case 0x1DA160u: goto label_1da160;
            case 0x1DA178u: goto label_1da178;
            case 0x1DA180u: goto label_1da180;
            case 0x1DA1A0u: goto label_1da1a0;
            case 0x1DA1B4u: goto label_1da1b4;
            case 0x1DA1D8u: goto label_1da1d8;
            case 0x1DA1E0u: goto label_1da1e0;
            case 0x1DA228u: goto label_1da228;
            case 0x1DA240u: goto label_1da240;
            case 0x1DA248u: goto label_1da248;
            case 0x1DA280u: goto label_1da280;
            case 0x1DA288u: goto label_1da288;
            case 0x1DA290u: goto label_1da290;
            case 0x1DA2B0u: goto label_1da2b0;
            case 0x1DA2B8u: goto label_1da2b8;
            case 0x1DA2CCu: goto label_1da2cc;
            case 0x1DA2D4u: goto label_1da2d4;
            case 0x1DA2F0u: goto label_1da2f0;
            case 0x1DA2F8u: goto label_1da2f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DA30Cu;
    // 0x1da30c: 0x0  nop
    ctx->pc = 0x1da30cu;
    // NOP
    // 0x1da310: 0x3e00008  jr          $ra
    ctx->pc = 0x1DA310u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1DA314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA310u;
            // 0x1da314: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9AA0u: goto label_1d9aa0;
            case 0x1D9ABCu: goto label_1d9abc;
            case 0x1D9AC8u: goto label_1d9ac8;
            case 0x1D9AD8u: goto label_1d9ad8;
            case 0x1D9B1Cu: goto label_1d9b1c;
            case 0x1D9B38u: goto label_1d9b38;
            case 0x1D9B48u: goto label_1d9b48;
            case 0x1D9B50u: goto label_1d9b50;
            case 0x1D9B58u: goto label_1d9b58;
            case 0x1D9B68u: goto label_1d9b68;
            case 0x1D9B98u: goto label_1d9b98;
            case 0x1D9BA8u: goto label_1d9ba8;
            case 0x1D9BCCu: goto label_1d9bcc;
            case 0x1D9C00u: goto label_1d9c00;
            case 0x1D9C08u: goto label_1d9c08;
            case 0x1D9C18u: goto label_1d9c18;
            case 0x1D9C2Cu: goto label_1d9c2c;
            case 0x1D9C34u: goto label_1d9c34;
            case 0x1D9C40u: goto label_1d9c40;
            case 0x1D9C48u: goto label_1d9c48;
            case 0x1D9C50u: goto label_1d9c50;
            case 0x1D9C58u: goto label_1d9c58;
            case 0x1D9C60u: goto label_1d9c60;
            case 0x1D9C70u: goto label_1d9c70;
            case 0x1D9CA0u: goto label_1d9ca0;
            case 0x1D9CA8u: goto label_1d9ca8;
            case 0x1D9CD0u: goto label_1d9cd0;
            case 0x1D9CD8u: goto label_1d9cd8;
            case 0x1D9CE0u: goto label_1d9ce0;
            case 0x1D9CE8u: goto label_1d9ce8;
            case 0x1D9D14u: goto label_1d9d14;
            case 0x1D9D28u: goto label_1d9d28;
            case 0x1D9D30u: goto label_1d9d30;
            case 0x1D9D40u: goto label_1d9d40;
            case 0x1D9D88u: goto label_1d9d88;
            case 0x1D9DE0u: goto label_1d9de0;
            case 0x1D9DF8u: goto label_1d9df8;
            case 0x1D9E28u: goto label_1d9e28;
            case 0x1D9E30u: goto label_1d9e30;
            case 0x1D9E60u: goto label_1d9e60;
            case 0x1D9E68u: goto label_1d9e68;
            case 0x1D9E70u: goto label_1d9e70;
            case 0x1D9EA0u: goto label_1d9ea0;
            case 0x1D9EB4u: goto label_1d9eb4;
            case 0x1D9ED8u: goto label_1d9ed8;
            case 0x1D9EF0u: goto label_1d9ef0;
            case 0x1D9EF8u: goto label_1d9ef8;
            case 0x1D9F18u: goto label_1d9f18;
            case 0x1D9F40u: goto label_1d9f40;
            case 0x1D9F60u: goto label_1d9f60;
            case 0x1D9F78u: goto label_1d9f78;
            case 0x1D9F90u: goto label_1d9f90;
            case 0x1D9F98u: goto label_1d9f98;
            case 0x1D9FA8u: goto label_1d9fa8;
            case 0x1D9FC0u: goto label_1d9fc0;
            case 0x1D9FD4u: goto label_1d9fd4;
            case 0x1D9FF8u: goto label_1d9ff8;
            case 0x1DA010u: goto label_1da010;
            case 0x1DA030u: goto label_1da030;
            case 0x1DA040u: goto label_1da040;
            case 0x1DA050u: goto label_1da050;
            case 0x1DA0B8u: goto label_1da0b8;
            case 0x1DA0D0u: goto label_1da0d0;
            case 0x1DA100u: goto label_1da100;
            case 0x1DA128u: goto label_1da128;
            case 0x1DA13Cu: goto label_1da13c;
            case 0x1DA160u: goto label_1da160;
            case 0x1DA178u: goto label_1da178;
            case 0x1DA180u: goto label_1da180;
            case 0x1DA1A0u: goto label_1da1a0;
            case 0x1DA1B4u: goto label_1da1b4;
            case 0x1DA1D8u: goto label_1da1d8;
            case 0x1DA1E0u: goto label_1da1e0;
            case 0x1DA228u: goto label_1da228;
            case 0x1DA240u: goto label_1da240;
            case 0x1DA248u: goto label_1da248;
            case 0x1DA280u: goto label_1da280;
            case 0x1DA288u: goto label_1da288;
            case 0x1DA290u: goto label_1da290;
            case 0x1DA2B0u: goto label_1da2b0;
            case 0x1DA2B8u: goto label_1da2b8;
            case 0x1DA2CCu: goto label_1da2cc;
            case 0x1DA2D4u: goto label_1da2d4;
            case 0x1DA2F0u: goto label_1da2f0;
            case 0x1DA2F8u: goto label_1da2f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DA318u;
    // 0x1da318: 0x0  nop
    ctx->pc = 0x1da318u;
    // NOP
    // 0x1da31c: 0x0  nop
    ctx->pc = 0x1da31cu;
    // NOP
    // 0x1da320: 0x3e00008  jr          $ra
    ctx->pc = 0x1DA320u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1DA324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA320u;
            // 0x1da324: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9AA0u: goto label_1d9aa0;
            case 0x1D9ABCu: goto label_1d9abc;
            case 0x1D9AC8u: goto label_1d9ac8;
            case 0x1D9AD8u: goto label_1d9ad8;
            case 0x1D9B1Cu: goto label_1d9b1c;
            case 0x1D9B38u: goto label_1d9b38;
            case 0x1D9B48u: goto label_1d9b48;
            case 0x1D9B50u: goto label_1d9b50;
            case 0x1D9B58u: goto label_1d9b58;
            case 0x1D9B68u: goto label_1d9b68;
            case 0x1D9B98u: goto label_1d9b98;
            case 0x1D9BA8u: goto label_1d9ba8;
            case 0x1D9BCCu: goto label_1d9bcc;
            case 0x1D9C00u: goto label_1d9c00;
            case 0x1D9C08u: goto label_1d9c08;
            case 0x1D9C18u: goto label_1d9c18;
            case 0x1D9C2Cu: goto label_1d9c2c;
            case 0x1D9C34u: goto label_1d9c34;
            case 0x1D9C40u: goto label_1d9c40;
            case 0x1D9C48u: goto label_1d9c48;
            case 0x1D9C50u: goto label_1d9c50;
            case 0x1D9C58u: goto label_1d9c58;
            case 0x1D9C60u: goto label_1d9c60;
            case 0x1D9C70u: goto label_1d9c70;
            case 0x1D9CA0u: goto label_1d9ca0;
            case 0x1D9CA8u: goto label_1d9ca8;
            case 0x1D9CD0u: goto label_1d9cd0;
            case 0x1D9CD8u: goto label_1d9cd8;
            case 0x1D9CE0u: goto label_1d9ce0;
            case 0x1D9CE8u: goto label_1d9ce8;
            case 0x1D9D14u: goto label_1d9d14;
            case 0x1D9D28u: goto label_1d9d28;
            case 0x1D9D30u: goto label_1d9d30;
            case 0x1D9D40u: goto label_1d9d40;
            case 0x1D9D88u: goto label_1d9d88;
            case 0x1D9DE0u: goto label_1d9de0;
            case 0x1D9DF8u: goto label_1d9df8;
            case 0x1D9E28u: goto label_1d9e28;
            case 0x1D9E30u: goto label_1d9e30;
            case 0x1D9E60u: goto label_1d9e60;
            case 0x1D9E68u: goto label_1d9e68;
            case 0x1D9E70u: goto label_1d9e70;
            case 0x1D9EA0u: goto label_1d9ea0;
            case 0x1D9EB4u: goto label_1d9eb4;
            case 0x1D9ED8u: goto label_1d9ed8;
            case 0x1D9EF0u: goto label_1d9ef0;
            case 0x1D9EF8u: goto label_1d9ef8;
            case 0x1D9F18u: goto label_1d9f18;
            case 0x1D9F40u: goto label_1d9f40;
            case 0x1D9F60u: goto label_1d9f60;
            case 0x1D9F78u: goto label_1d9f78;
            case 0x1D9F90u: goto label_1d9f90;
            case 0x1D9F98u: goto label_1d9f98;
            case 0x1D9FA8u: goto label_1d9fa8;
            case 0x1D9FC0u: goto label_1d9fc0;
            case 0x1D9FD4u: goto label_1d9fd4;
            case 0x1D9FF8u: goto label_1d9ff8;
            case 0x1DA010u: goto label_1da010;
            case 0x1DA030u: goto label_1da030;
            case 0x1DA040u: goto label_1da040;
            case 0x1DA050u: goto label_1da050;
            case 0x1DA0B8u: goto label_1da0b8;
            case 0x1DA0D0u: goto label_1da0d0;
            case 0x1DA100u: goto label_1da100;
            case 0x1DA128u: goto label_1da128;
            case 0x1DA13Cu: goto label_1da13c;
            case 0x1DA160u: goto label_1da160;
            case 0x1DA178u: goto label_1da178;
            case 0x1DA180u: goto label_1da180;
            case 0x1DA1A0u: goto label_1da1a0;
            case 0x1DA1B4u: goto label_1da1b4;
            case 0x1DA1D8u: goto label_1da1d8;
            case 0x1DA1E0u: goto label_1da1e0;
            case 0x1DA228u: goto label_1da228;
            case 0x1DA240u: goto label_1da240;
            case 0x1DA248u: goto label_1da248;
            case 0x1DA280u: goto label_1da280;
            case 0x1DA288u: goto label_1da288;
            case 0x1DA290u: goto label_1da290;
            case 0x1DA2B0u: goto label_1da2b0;
            case 0x1DA2B8u: goto label_1da2b8;
            case 0x1DA2CCu: goto label_1da2cc;
            case 0x1DA2D4u: goto label_1da2d4;
            case 0x1DA2F0u: goto label_1da2f0;
            case 0x1DA2F8u: goto label_1da2f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DA328u;
    // 0x1da328: 0x0  nop
    ctx->pc = 0x1da328u;
    // NOP
    // 0x1da32c: 0x0  nop
    ctx->pc = 0x1da32cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
