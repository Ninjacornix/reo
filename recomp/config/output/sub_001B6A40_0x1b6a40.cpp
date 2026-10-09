#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B6A40
// Address: 0x1b6a40 - 0x1b6c70
void sub_001B6A40_0x1b6a40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B6A40_0x1b6a40");
#endif

    switch (ctx->pc) {
        case 0x1b6a78u: goto label_1b6a78;
        case 0x1b6a80u: goto label_1b6a80;
        case 0x1b6ae4u: goto label_1b6ae4;
        case 0x1b6afcu: goto label_1b6afc;
        case 0x1b6b10u: goto label_1b6b10;
        case 0x1b6b1cu: goto label_1b6b1c;
        case 0x1b6b48u: goto label_1b6b48;
        case 0x1b6b74u: goto label_1b6b74;
        case 0x1b6bccu: goto label_1b6bcc;
        case 0x1b6c0cu: goto label_1b6c0c;
        default: break;
    }

    ctx->pc = 0x1b6a40u;

    // 0x1b6a40: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1b6a40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1b6a44: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x1b6a44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x1b6a48: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1b6a48u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1b6a4c: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1b6a4cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1b6a50: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1b6a50u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1b6a54: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1b6a54u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1b6a58: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b6a58u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b6a5c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b6a5cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b6a60: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b6a60u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b6a64: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1b6a64u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b6a68: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b6a68u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b6a6c: 0xafa5009c  sw          $a1, 0x9C($sp)
    ctx->pc = 0x1b6a6cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 156), GPR_U32(ctx, 5));
    // 0x1b6a70: 0x8c910070  lw          $s1, 0x70($a0)
    ctx->pc = 0x1b6a70u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 112)));
    // 0x1b6a74: 0x8c94004c  lw          $s4, 0x4C($a0)
    ctx->pc = 0x1b6a74u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
label_1b6a78:
    // 0x1b6a78: 0xc06d9b0  jal         func_1B66C0
    ctx->pc = 0x1B6A78u;
    SET_GPR_U32(ctx, 31, 0x1B6A80u);
    ctx->pc = 0x1B6A7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6A78u;
            // 0x1b6a7c: 0x27a4009c  addiu       $a0, $sp, 0x9C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 156));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B66C0u;
    if (runtime->hasFunction(0x1B66C0u)) {
        auto targetFn = runtime->lookupFunction(0x1B66C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6A80u; }
        if (ctx->pc != 0x1B6A80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B66C0_0x1b66c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6A80u; }
        if (ctx->pc != 0x1B6A80u) { return; }
    }
    ctx->pc = 0x1B6A80u;
label_1b6a80:
    // 0x1b6a80: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1b6a80u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b6a84: 0x10a0006b  beqz        $a1, . + 4 + (0x6B << 2)
    ctx->pc = 0x1B6A84u;
    {
        const bool branch_taken_0x1b6a84 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b6a84) {
            ctx->pc = 0x1B6C34u;
            goto label_1b6c34;
        }
    }
    ctx->pc = 0x1B6A8Cu;
    // 0x1b6a8c: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x1b6a8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1b6a90: 0x14a20003  bne         $a1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6A90u;
    {
        const bool branch_taken_0x1b6a90 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B6A94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6A90u;
            // 0x1b6a94: 0x2402000a  addiu       $v0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6a90) {
            ctx->pc = 0x1B6AA0u;
            goto label_1b6aa0;
        }
    }
    ctx->pc = 0x1B6A98u;
    // 0x1b6a98: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1B6A98u;
    {
        const bool branch_taken_0x1b6a98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6A9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6A98u;
            // 0x1b6a9c: 0x24150001  addiu       $s5, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6a98) {
            ctx->pc = 0x1B6C1Cu;
            goto label_1b6c1c;
        }
    }
    ctx->pc = 0x1B6AA0u;
label_1b6aa0:
    // 0x1b6aa0: 0x14a20007  bne         $a1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B6AA0u;
    {
        const bool branch_taken_0x1b6aa0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        if (branch_taken_0x1b6aa0) {
            ctx->pc = 0x1B6AC0u;
            goto label_1b6ac0;
        }
    }
    ctx->pc = 0x1B6AA8u;
    // 0x1b6aa8: 0xae510070  sw          $s1, 0x70($s2)
    ctx->pc = 0x1b6aa8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 112), GPR_U32(ctx, 17));
    // 0x1b6aac: 0x8e43006c  lw          $v1, 0x6C($s2)
    ctx->pc = 0x1b6aacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 108)));
    // 0x1b6ab0: 0x8e420074  lw          $v0, 0x74($s2)
    ctx->pc = 0x1b6ab0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 116)));
    // 0x1b6ab4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b6ab4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b6ab8: 0x1000ffef  b           . + 4 + (-0x11 << 2)
    ctx->pc = 0x1B6AB8u;
    {
        const bool branch_taken_0x1b6ab8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6ABCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6AB8u;
            // 0x1b6abc: 0xae420074  sw          $v0, 0x74($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 116), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6ab8) {
            ctx->pc = 0x1B6A78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b6a78;
        }
    }
    ctx->pc = 0x1B6AC0u;
label_1b6ac0:
    // 0x1b6ac0: 0x8e420094  lw          $v0, 0x94($s2)
    ctx->pc = 0x1b6ac0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 148)));
    // 0x1b6ac4: 0x14400010  bnez        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B6AC4u;
    {
        const bool branch_taken_0x1b6ac4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6AC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6AC4u;
            // 0x1b6ac8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6ac4) {
            ctx->pc = 0x1B6B08u;
            goto label_1b6b08;
        }
    }
    ctx->pc = 0x1B6ACCu;
    // 0x1b6acc: 0x2ca10010  sltiu       $at, $a1, 0x10
    ctx->pc = 0x1b6accu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x1b6ad0: 0x10200006  beqz        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B6AD0u;
    {
        const bool branch_taken_0x1b6ad0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6AD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6AD0u;
            // 0x1b6ad4: 0x2ca10080  sltiu       $at, $a1, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6ad0) {
            ctx->pc = 0x1B6AECu;
            goto label_1b6aec;
        }
    }
    ctx->pc = 0x1B6AD8u;
    // 0x1b6ad8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1b6ad8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b6adc: 0xc06da80  jal         func_1B6A00
    ctx->pc = 0x1B6ADCu;
    SET_GPR_U32(ctx, 31, 0x1B6AE4u);
    ctx->pc = 0x1B6AE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6ADCu;
            // 0x1b6ae0: 0xa82d  daddu       $s5, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6A00u;
    if (runtime->hasFunction(0x1B6A00u)) {
        auto targetFn = runtime->lookupFunction(0x1B6A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6AE4u; }
        if (ctx->pc != 0x1B6AE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6A00_0x1b6a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6AE4u; }
        if (ctx->pc != 0x1B6AE4u) { return; }
    }
    ctx->pc = 0x1B6AE4u;
label_1b6ae4:
    // 0x1b6ae4: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1B6AE4u;
    {
        const bool branch_taken_0x1b6ae4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6AE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6AE4u;
            // 0x1b6ae8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6ae4) {
            ctx->pc = 0x1B6B4Cu;
            goto label_1b6b4c;
        }
    }
    ctx->pc = 0x1B6AECu;
label_1b6aec:
    // 0x1b6aec: 0x10200005  beqz        $at, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B6AECu;
    {
        const bool branch_taken_0x1b6aec = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6AF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6AECu;
            // 0x1b6af0: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6aec) {
            ctx->pc = 0x1B6B04u;
            goto label_1b6b04;
        }
    }
    ctx->pc = 0x1B6AF4u;
    // 0x1b6af4: 0xc06da80  jal         func_1B6A00
    ctx->pc = 0x1B6AF4u;
    SET_GPR_U32(ctx, 31, 0x1B6AFCu);
    ctx->pc = 0x1B6AF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6AF4u;
            // 0x1b6af8: 0x24150001  addiu       $s5, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6A00u;
    if (runtime->hasFunction(0x1B6A00u)) {
        auto targetFn = runtime->lookupFunction(0x1B6A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6AFCu; }
        if (ctx->pc != 0x1B6AFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6A00_0x1b6a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6AFCu; }
        if (ctx->pc != 0x1B6AFCu) { return; }
    }
    ctx->pc = 0x1B6AFCu;
label_1b6afc:
    // 0x1b6afc: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1B6AFCu;
    {
        const bool branch_taken_0x1b6afc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6AFCu;
            // 0x1b6b00: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6afc) {
            ctx->pc = 0x1B6B4Cu;
            goto label_1b6b4c;
        }
    }
    ctx->pc = 0x1B6B04u;
label_1b6b04:
    // 0x1b6b04: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1b6b04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_1b6b08:
    // 0x1b6b08: 0xc06d9fc  jal         func_1B67F0
    ctx->pc = 0x1B6B08u;
    SET_GPR_U32(ctx, 31, 0x1B6B10u);
    ctx->pc = 0x1B67F0u;
    if (runtime->hasFunction(0x1B67F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B67F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6B10u; }
        if (ctx->pc != 0x1B6B10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B67F0_0x1b67f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6B10u; }
        if (ctx->pc != 0x1B6B10u) { return; }
    }
    ctx->pc = 0x1B6B10u;
label_1b6b10:
    // 0x1b6b10: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1b6b10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b6b14: 0xc06da8c  jal         func_1B6A30
    ctx->pc = 0x1B6B14u;
    SET_GPR_U32(ctx, 31, 0x1B6B1Cu);
    ctx->pc = 0x1B6B18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6B14u;
            // 0x1b6b18: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6A30u;
    if (runtime->hasFunction(0x1B6A30u)) {
        auto targetFn = runtime->lookupFunction(0x1B6A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6B1Cu; }
        if (ctx->pc != 0x1B6B1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6A30_0x1b6a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6B1Cu; }
        if (ctx->pc != 0x1B6B1Cu) { return; }
    }
    ctx->pc = 0x1B6B1Cu;
label_1b6b1c:
    // 0x1b6b1c: 0x8e43001c  lw          $v1, 0x1C($s2)
    ctx->pc = 0x1b6b1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
    // 0x1b6b20: 0xa3082b  sltu        $at, $a1, $v1
    ctx->pc = 0x1b6b20u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1b6b24: 0x1020003d  beqz        $at, . + 4 + (0x3D << 2)
    ctx->pc = 0x1B6B24u;
    {
        const bool branch_taken_0x1b6b24 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6B28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6B24u;
            // 0x1b6b28: 0x40a82d  daddu       $s5, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6b24) {
            ctx->pc = 0x1B6C1Cu;
            goto label_1b6c1c;
        }
    }
    ctx->pc = 0x1B6B2Cu;
    // 0x1b6b2c: 0x8e460064  lw          $a2, 0x64($s2)
    ctx->pc = 0x1b6b2cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 100)));
    // 0x1b6b30: 0x8e430060  lw          $v1, 0x60($s2)
    ctx->pc = 0x1b6b30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 96)));
    // 0x1b6b34: 0xc3082b  sltu        $at, $a2, $v1
    ctx->pc = 0x1b6b34u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1b6b38: 0x1020003e  beqz        $at, . + 4 + (0x3E << 2)
    ctx->pc = 0x1B6B38u;
    {
        const bool branch_taken_0x1b6b38 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b6b38) {
            ctx->pc = 0x1B6C34u;
            goto label_1b6c34;
        }
    }
    ctx->pc = 0x1B6B40u;
    // 0x1b6b40: 0xc06da18  jal         func_1B6860
    ctx->pc = 0x1B6B40u;
    SET_GPR_U32(ctx, 31, 0x1B6B48u);
    ctx->pc = 0x1B6860u;
    if (runtime->hasFunction(0x1B6860u)) {
        auto targetFn = runtime->lookupFunction(0x1B6860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6B48u; }
        if (ctx->pc != 0x1B6B48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6860_0x1b6860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6B48u; }
        if (ctx->pc != 0x1B6B48u) { return; }
    }
    ctx->pc = 0x1B6B48u;
label_1b6b48:
    // 0x1b6b48: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1b6b48u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1b6b4c:
    // 0x1b6b4c: 0x8e4200a4  lw          $v0, 0xA4($s2)
    ctx->pc = 0x1b6b4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 164)));
    // 0x1b6b50: 0x1440002a  bnez        $v0, . + 4 + (0x2A << 2)
    ctx->pc = 0x1B6B50u;
    {
        const bool branch_taken_0x1b6b50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6B54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6B50u;
            // 0x1b6b54: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6b50) {
            ctx->pc = 0x1B6BFCu;
            goto label_1b6bfc;
        }
    }
    ctx->pc = 0x1B6B58u;
    // 0x1b6b58: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b6b58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b6b5c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1b6b5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b6b60: 0x902343f2  lbu         $v1, 0x43F2($at)
    ctx->pc = 0x1b6b60u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17394)));
    // 0x1b6b64: 0x10620024  beq         $v1, $v0, . + 4 + (0x24 << 2)
    ctx->pc = 0x1B6B64u;
    {
        const bool branch_taken_0x1b6b64 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B6B68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6B64u;
            // 0x1b6b68: 0x24040050  addiu       $a0, $zero, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6b64) {
            ctx->pc = 0x1B6BF8u;
            goto label_1b6bf8;
        }
    }
    ctx->pc = 0x1B6B6Cu;
    // 0x1b6b6c: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1B6B6Cu;
    SET_GPR_U32(ctx, 31, 0x1B6B74u);
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6B74u; }
        if (ctx->pc != 0x1B6B74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6B74u; }
        if (ctx->pc != 0x1B6B74u) { return; }
    }
    ctx->pc = 0x1B6B74u;
label_1b6b74:
    // 0x1b6b74: 0x14400020  bnez        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x1B6B74u;
    {
        const bool branch_taken_0x1b6b74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6B78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6B74u;
            // 0x1b6b78: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6b74) {
            ctx->pc = 0x1B6BF8u;
            goto label_1b6bf8;
        }
    }
    ctx->pc = 0x1B6B7Cu;
    // 0x1b6b7c: 0x8e530070  lw          $s3, 0x70($s2)
    ctx->pc = 0x1b6b7cu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 112)));
    // 0x1b6b80: 0x8e540080  lw          $s4, 0x80($s2)
    ctx->pc = 0x1b6b80u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 128)));
    // 0x1b6b84: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1b6b84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1b6b88: 0x8e560074  lw          $s6, 0x74($s2)
    ctx->pc = 0x1b6b88u;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 116)));
    // 0x1b6b8c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1b6b8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b6b90: 0x8e570078  lw          $s7, 0x78($s2)
    ctx->pc = 0x1b6b90u;
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 120)));
    // 0x1b6b94: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1b6b94u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b6b98: 0x2a0382d  daddu       $a3, $s5, $zero
    ctx->pc = 0x1b6b98u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b6b9c: 0x2821024  and         $v0, $s4, $v0
    ctx->pc = 0x1b6b9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & GPR_U64(ctx, 2));
    // 0x1b6ba0: 0xae420080  sw          $v0, 0x80($s2)
    ctx->pc = 0x1b6ba0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 128), GPR_U32(ctx, 2));
    // 0x1b6ba4: 0x8e420070  lw          $v0, 0x70($s2)
    ctx->pc = 0x1b6ba4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 112)));
    // 0x1b6ba8: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1b6ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1b6bac: 0xae420070  sw          $v0, 0x70($s2)
    ctx->pc = 0x1b6bacu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 112), GPR_U32(ctx, 2));
    // 0x1b6bb0: 0x8e420074  lw          $v0, 0x74($s2)
    ctx->pc = 0x1b6bb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 116)));
    // 0x1b6bb4: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1b6bb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1b6bb8: 0xae420074  sw          $v0, 0x74($s2)
    ctx->pc = 0x1b6bb8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 116), GPR_U32(ctx, 2));
    // 0x1b6bbc: 0x8e420078  lw          $v0, 0x78($s2)
    ctx->pc = 0x1b6bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 120)));
    // 0x1b6bc0: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1b6bc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1b6bc4: 0xc06dc74  jal         func_1B71D0
    ctx->pc = 0x1B6BC4u;
    SET_GPR_U32(ctx, 31, 0x1B6BCCu);
    ctx->pc = 0x1B6BC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6BC4u;
            // 0x1b6bc8: 0xae420078  sw          $v0, 0x78($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 120), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B71D0u;
    if (runtime->hasFunction(0x1B71D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B71D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6BCCu; }
        if (ctx->pc != 0x1B6BCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B71D0_0x1b71d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6BCCu; }
        if (ctx->pc != 0x1B6BCCu) { return; }
    }
    ctx->pc = 0x1B6BCCu;
label_1b6bcc:
    // 0x1b6bcc: 0xae540080  sw          $s4, 0x80($s2)
    ctx->pc = 0x1b6bccu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 128), GPR_U32(ctx, 20));
    // 0x1b6bd0: 0xae530070  sw          $s3, 0x70($s2)
    ctx->pc = 0x1b6bd0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 112), GPR_U32(ctx, 19));
    // 0x1b6bd4: 0xae560074  sw          $s6, 0x74($s2)
    ctx->pc = 0x1b6bd4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 116), GPR_U32(ctx, 22));
    // 0x1b6bd8: 0xae570078  sw          $s7, 0x78($s2)
    ctx->pc = 0x1b6bd8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 120), GPR_U32(ctx, 23));
    // 0x1b6bdc: 0x8e430064  lw          $v1, 0x64($s2)
    ctx->pc = 0x1b6bdcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 100)));
    // 0x1b6be0: 0x24640001  addiu       $a0, $v1, 0x1
    ctx->pc = 0x1b6be0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1b6be4: 0xae440064  sw          $a0, 0x64($s2)
    ctx->pc = 0x1b6be4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 100), GPR_U32(ctx, 4));
    // 0x1b6be8: 0x8e430060  lw          $v1, 0x60($s2)
    ctx->pc = 0x1b6be8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 96)));
    // 0x1b6bec: 0x83082b  sltu        $at, $a0, $v1
    ctx->pc = 0x1b6becu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1b6bf0: 0x10200010  beqz        $at, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B6BF0u;
    {
        const bool branch_taken_0x1b6bf0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6BF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6BF0u;
            // 0x1b6bf4: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6bf0) {
            ctx->pc = 0x1B6C34u;
            goto label_1b6c34;
        }
    }
    ctx->pc = 0x1B6BF8u;
label_1b6bf8:
    // 0x1b6bf8: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1b6bf8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_1b6bfc:
    // 0x1b6bfc: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1b6bfcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b6c00: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1b6c00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b6c04: 0xc06dc74  jal         func_1B71D0
    ctx->pc = 0x1B6C04u;
    SET_GPR_U32(ctx, 31, 0x1B6C0Cu);
    ctx->pc = 0x1B6C08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6C04u;
            // 0x1b6c08: 0x2a0382d  daddu       $a3, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B71D0u;
    if (runtime->hasFunction(0x1B71D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B71D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6C0Cu; }
        if (ctx->pc != 0x1B6C0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B71D0_0x1b71d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6C0Cu; }
        if (ctx->pc != 0x1B6C0Cu) { return; }
    }
    ctx->pc = 0x1B6C0Cu;
label_1b6c0c:
    // 0x1b6c0c: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x1b6c0cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b6c10: 0x8e420064  lw          $v0, 0x64($s2)
    ctx->pc = 0x1b6c10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 100)));
    // 0x1b6c14: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1b6c14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1b6c18: 0xae420064  sw          $v0, 0x64($s2)
    ctx->pc = 0x1b6c18u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 100), GPR_U32(ctx, 2));
label_1b6c1c:
    // 0x1b6c1c: 0x8e43006c  lw          $v1, 0x6C($s2)
    ctx->pc = 0x1b6c1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 108)));
    // 0x1b6c20: 0x8e420070  lw          $v0, 0x70($s2)
    ctx->pc = 0x1b6c20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 112)));
    // 0x1b6c24: 0x2a31806  srlv        $v1, $v1, $s5
    ctx->pc = 0x1b6c24u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), GPR_U32(ctx, 21) & 0x1F));
    // 0x1b6c28: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b6c28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b6c2c: 0x1000ff92  b           . + 4 + (-0x6E << 2)
    ctx->pc = 0x1B6C2Cu;
    {
        const bool branch_taken_0x1b6c2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6C30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6C2Cu;
            // 0x1b6c30: 0xae420070  sw          $v0, 0x70($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 112), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6c2c) {
            ctx->pc = 0x1B6A78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b6a78;
        }
    }
    ctx->pc = 0x1B6C34u;
label_1b6c34:
    // 0x1b6c34: 0xae54004c  sw          $s4, 0x4C($s2)
    ctx->pc = 0x1b6c34u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 76), GPR_U32(ctx, 20));
    // 0x1b6c38: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x1b6c38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1b6c3c: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1b6c3cu;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1b6c40: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1b6c40u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1b6c44: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1b6c44u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1b6c48: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1b6c48u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b6c4c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b6c4cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b6c50: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b6c50u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b6c54: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b6c54u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b6c58: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b6c58u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b6c5c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B6C5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B6C60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6C5Cu;
            // 0x1b6c60: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B6A78u: goto label_1b6a78;
            case 0x1B6A80u: goto label_1b6a80;
            case 0x1B6AA0u: goto label_1b6aa0;
            case 0x1B6AC0u: goto label_1b6ac0;
            case 0x1B6AE4u: goto label_1b6ae4;
            case 0x1B6AECu: goto label_1b6aec;
            case 0x1B6AFCu: goto label_1b6afc;
            case 0x1B6B04u: goto label_1b6b04;
            case 0x1B6B08u: goto label_1b6b08;
            case 0x1B6B10u: goto label_1b6b10;
            case 0x1B6B1Cu: goto label_1b6b1c;
            case 0x1B6B48u: goto label_1b6b48;
            case 0x1B6B4Cu: goto label_1b6b4c;
            case 0x1B6B74u: goto label_1b6b74;
            case 0x1B6BCCu: goto label_1b6bcc;
            case 0x1B6BF8u: goto label_1b6bf8;
            case 0x1B6BFCu: goto label_1b6bfc;
            case 0x1B6C0Cu: goto label_1b6c0c;
            case 0x1B6C1Cu: goto label_1b6c1c;
            case 0x1B6C34u: goto label_1b6c34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B6C64u;
    // 0x1b6c64: 0x0  nop
    ctx->pc = 0x1b6c64u;
    // NOP
    // 0x1b6c68: 0x0  nop
    ctx->pc = 0x1b6c68u;
    // NOP
    // 0x1b6c6c: 0x0  nop
    ctx->pc = 0x1b6c6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
