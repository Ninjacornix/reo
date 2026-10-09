#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D29F0
// Address: 0x1d29f0 - 0x1d2c00
void sub_001D29F0_0x1d29f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D29F0_0x1d29f0");
#endif

    switch (ctx->pc) {
        case 0x1d2a28u: goto label_1d2a28;
        case 0x1d2a68u: goto label_1d2a68;
        case 0x1d2a80u: goto label_1d2a80;
        case 0x1d2ac0u: goto label_1d2ac0;
        case 0x1d2ae0u: goto label_1d2ae0;
        case 0x1d2b00u: goto label_1d2b00;
        case 0x1d2b20u: goto label_1d2b20;
        case 0x1d2b40u: goto label_1d2b40;
        case 0x1d2b60u: goto label_1d2b60;
        case 0x1d2b94u: goto label_1d2b94;
        case 0x1d2ba4u: goto label_1d2ba4;
        case 0x1d2bb8u: goto label_1d2bb8;
        default: break;
    }

    ctx->pc = 0x1d29f0u;

    // 0x1d29f0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d29f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d29f4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d29f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d29f8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d29f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d29fc: 0x24426768  addiu       $v0, $v0, 0x6768
    ctx->pc = 0x1d29fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26472));
    // 0x1d2a00: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d2a00u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d2a04: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d2a04u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d2a08: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d2a08u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2a0c: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1d2a0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1d2a10: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1d2a10u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2a14: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d2a14u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d2a18: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d2a18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d2a1c: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1d2a1cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d2a20: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D2A20u;
    SET_GPR_U32(ctx, 31, 0x1D2A28u);
    ctx->pc = 0x1D2A24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2A20u;
            // 0x1d2a24: 0x24040015  addiu       $a0, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2A28u; }
        if (ctx->pc != 0x1D2A28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2A28u; }
        if (ctx->pc != 0x1D2A28u) { return; }
    }
    ctx->pc = 0x1D2A28u;
label_1d2a28:
    // 0x1d2a28: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x1d2a28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1d2a2c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d2a2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d2a30: 0x24426768  addiu       $v0, $v0, 0x6768
    ctx->pc = 0x1d2a30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26472));
    // 0x1d2a34: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1d2a34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d2a38: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d2a38u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d2a3c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d2a3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d2a40: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1d2a40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d2a44: 0x1444000c  bne         $v0, $a0, . + 4 + (0xC << 2)
    ctx->pc = 0x1D2A44u;
    {
        const bool branch_taken_0x1d2a44 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x1D2A48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2A44u;
            // 0x1d2a48: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2a44) {
            ctx->pc = 0x1D2A78u;
            goto label_1d2a78;
        }
    }
    ctx->pc = 0x1D2A4Cu;
    // 0x1d2a4c: 0x8e230008  lw          $v1, 0x8($s1)
    ctx->pc = 0x1d2a4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1d2a50: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d2a50u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d2a54: 0x244267b0  addiu       $v0, $v0, 0x67B0
    ctx->pc = 0x1d2a54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26544));
    // 0x1d2a58: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d2a58u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d2a5c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d2a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d2a60: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D2A60u;
    SET_GPR_U32(ctx, 31, 0x1D2A68u);
    ctx->pc = 0x1D2A64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2A60u;
            // 0x1d2a64: 0x8c450000  lw          $a1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2A68u; }
        if (ctx->pc != 0x1D2A68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2A68u; }
        if (ctx->pc != 0x1D2A68u) { return; }
    }
    ctx->pc = 0x1D2A68u;
label_1d2a68:
    // 0x1d2a68: 0xa200008d  sb          $zero, 0x8D($s0)
    ctx->pc = 0x1d2a68u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 141), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d2a6c: 0x8e220014  lw          $v0, 0x14($s1)
    ctx->pc = 0x1d2a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1d2a70: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1D2A70u;
    {
        const bool branch_taken_0x1d2a70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2A74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2A70u;
            // 0x1d2a74: 0xa2020090  sb          $v0, 0x90($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 144), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2a70) {
            ctx->pc = 0x1D2AA0u;
            goto label_1d2aa0;
        }
    }
    ctx->pc = 0x1D2A78u;
label_1d2a78:
    // 0x1d2a78: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D2A78u;
    SET_GPR_U32(ctx, 31, 0x1D2A80u);
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2A80u; }
        if (ctx->pc != 0x1D2A80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2A80u; }
        if (ctx->pc != 0x1D2A80u) { return; }
    }
    ctx->pc = 0x1D2A80u;
label_1d2a80:
    // 0x1d2a80: 0xa2000090  sb          $zero, 0x90($s0)
    ctx->pc = 0x1d2a80u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 144), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d2a84: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x1d2a84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1d2a88: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x1d2a88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1d2a8c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D2A8Cu;
    {
        const bool branch_taken_0x1d2a8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2A90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2A8Cu;
            // 0x1d2a90: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2a8c) {
            ctx->pc = 0x1D2A9Cu;
            goto label_1d2a9c;
        }
    }
    ctx->pc = 0x1D2A94u;
    // 0x1d2a94: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1D2A94u;
    {
        const bool branch_taken_0x1d2a94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2A98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2A94u;
            // 0x1d2a98: 0xa202008d  sb          $v0, 0x8D($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 141), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2a94) {
            ctx->pc = 0x1D2AA0u;
            goto label_1d2aa0;
        }
    }
    ctx->pc = 0x1D2A9Cu;
label_1d2a9c:
    // 0x1d2a9c: 0xa200008d  sb          $zero, 0x8D($s0)
    ctx->pc = 0x1d2a9cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 141), (uint8_t)GPR_U32(ctx, 0));
label_1d2aa0:
    // 0x1d2aa0: 0x8e230020  lw          $v1, 0x20($s1)
    ctx->pc = 0x1d2aa0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x1d2aa4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d2aa4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d2aa8: 0x24426770  addiu       $v0, $v0, 0x6770
    ctx->pc = 0x1d2aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26480));
    // 0x1d2aac: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d2aacu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d2ab0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d2ab0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d2ab4: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1d2ab4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d2ab8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D2AB8u;
    SET_GPR_U32(ctx, 31, 0x1D2AC0u);
    ctx->pc = 0x1D2ABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2AB8u;
            // 0x1d2abc: 0x24040012  addiu       $a0, $zero, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2AC0u; }
        if (ctx->pc != 0x1D2AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2AC0u; }
        if (ctx->pc != 0x1D2AC0u) { return; }
    }
    ctx->pc = 0x1D2AC0u;
label_1d2ac0:
    // 0x1d2ac0: 0x8e230014  lw          $v1, 0x14($s1)
    ctx->pc = 0x1d2ac0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1d2ac4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d2ac4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d2ac8: 0x24426780  addiu       $v0, $v0, 0x6780
    ctx->pc = 0x1d2ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26496));
    // 0x1d2acc: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d2accu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d2ad0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d2ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d2ad4: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1d2ad4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d2ad8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D2AD8u;
    SET_GPR_U32(ctx, 31, 0x1D2AE0u);
    ctx->pc = 0x1D2ADCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2AD8u;
            // 0x1d2adc: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2AE0u; }
        if (ctx->pc != 0x1D2AE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2AE0u; }
        if (ctx->pc != 0x1D2AE0u) { return; }
    }
    ctx->pc = 0x1D2AE0u;
label_1d2ae0:
    // 0x1d2ae0: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x1d2ae0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x1d2ae4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d2ae4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d2ae8: 0x244267d0  addiu       $v0, $v0, 0x67D0
    ctx->pc = 0x1d2ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26576));
    // 0x1d2aec: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d2aecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d2af0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d2af0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d2af4: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1d2af4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d2af8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D2AF8u;
    SET_GPR_U32(ctx, 31, 0x1D2B00u);
    ctx->pc = 0x1D2AFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2AF8u;
            // 0x1d2afc: 0x24040066  addiu       $a0, $zero, 0x66 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2B00u; }
        if (ctx->pc != 0x1D2B00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2B00u; }
        if (ctx->pc != 0x1D2B00u) { return; }
    }
    ctx->pc = 0x1D2B00u;
label_1d2b00:
    // 0x1d2b00: 0x8e23001c  lw          $v1, 0x1C($s1)
    ctx->pc = 0x1d2b00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1d2b04: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d2b04u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d2b08: 0x244267d8  addiu       $v0, $v0, 0x67D8
    ctx->pc = 0x1d2b08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26584));
    // 0x1d2b0c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d2b0cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d2b10: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d2b10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d2b14: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1d2b14u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d2b18: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D2B18u;
    SET_GPR_U32(ctx, 31, 0x1D2B20u);
    ctx->pc = 0x1D2B1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2B18u;
            // 0x1d2b1c: 0x24040062  addiu       $a0, $zero, 0x62 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2B20u; }
        if (ctx->pc != 0x1D2B20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2B20u; }
        if (ctx->pc != 0x1D2B20u) { return; }
    }
    ctx->pc = 0x1D2B20u;
label_1d2b20:
    // 0x1d2b20: 0x8e230010  lw          $v1, 0x10($s1)
    ctx->pc = 0x1d2b20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1d2b24: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d2b24u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d2b28: 0x244267e0  addiu       $v0, $v0, 0x67E0
    ctx->pc = 0x1d2b28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26592));
    // 0x1d2b2c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d2b2cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d2b30: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d2b30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d2b34: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1d2b34u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d2b38: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D2B38u;
    SET_GPR_U32(ctx, 31, 0x1D2B40u);
    ctx->pc = 0x1D2B3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2B38u;
            // 0x1d2b3c: 0x2404000c  addiu       $a0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2B40u; }
        if (ctx->pc != 0x1D2B40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2B40u; }
        if (ctx->pc != 0x1D2B40u) { return; }
    }
    ctx->pc = 0x1D2B40u;
label_1d2b40:
    // 0x1d2b40: 0x8e23000c  lw          $v1, 0xC($s1)
    ctx->pc = 0x1d2b40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1d2b44: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d2b44u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d2b48: 0x244267f0  addiu       $v0, $v0, 0x67F0
    ctx->pc = 0x1d2b48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26608));
    // 0x1d2b4c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d2b4cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d2b50: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d2b50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d2b54: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1d2b54u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d2b58: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D2B58u;
    SET_GPR_U32(ctx, 31, 0x1D2B60u);
    ctx->pc = 0x1D2B5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2B58u;
            // 0x1d2b5c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2B60u; }
        if (ctx->pc != 0x1D2B60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2B60u; }
        if (ctx->pc != 0x1D2B60u) { return; }
    }
    ctx->pc = 0x1D2B60u;
label_1d2b60:
    // 0x1d2b60: 0x8e230028  lw          $v1, 0x28($s1)
    ctx->pc = 0x1d2b60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 40)));
    // 0x1d2b64: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1D2B64u;
    {
        const bool branch_taken_0x1d2b64 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2B68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2B64u;
            // 0x1d2b68: 0x2404005d  addiu       $a0, $zero, 0x5D (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 93));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2b64) {
            ctx->pc = 0x1D2BB0u;
            goto label_1d2bb0;
        }
    }
    ctx->pc = 0x1D2B6Cu;
    // 0x1d2b6c: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1d2b6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1d2b70: 0x1062000a  beq         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1D2B70u;
    {
        const bool branch_taken_0x1d2b70 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D2B74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2B70u;
            // 0x1d2b74: 0x2404005d  addiu       $a0, $zero, 0x5D (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 93));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2b70) {
            ctx->pc = 0x1D2B9Cu;
            goto label_1d2b9c;
        }
    }
    ctx->pc = 0x1D2B78u;
    // 0x1d2b78: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1d2b78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1d2b7c: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D2B7Cu;
    {
        const bool branch_taken_0x1d2b7c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D2B80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2B7Cu;
            // 0x1d2b80: 0x2404005d  addiu       $a0, $zero, 0x5D (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 93));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2b7c) {
            ctx->pc = 0x1D2B8Cu;
            goto label_1d2b8c;
        }
    }
    ctx->pc = 0x1D2B84u;
    // 0x1d2b84: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1D2B84u;
    {
        const bool branch_taken_0x1d2b84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d2b84) {
            ctx->pc = 0x1D2BACu;
            goto label_1d2bac;
        }
    }
    ctx->pc = 0x1D2B8Cu;
label_1d2b8c:
    // 0x1d2b8c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D2B8Cu;
    SET_GPR_U32(ctx, 31, 0x1D2B94u);
    ctx->pc = 0x1D2B90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2B8Cu;
            // 0x1d2b90: 0x3c050600  lui         $a1, 0x600 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)1536 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2B94u; }
        if (ctx->pc != 0x1D2B94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2B94u; }
        if (ctx->pc != 0x1D2B94u) { return; }
    }
    ctx->pc = 0x1D2B94u;
label_1d2b94:
    // 0x1d2b94: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1D2B94u;
    {
        const bool branch_taken_0x1d2b94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2B98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2B94u;
            // 0x1d2b98: 0x8e23002c  lw          $v1, 0x2C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 44)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2b94) {
            ctx->pc = 0x1D2BBCu;
            goto label_1d2bbc;
        }
    }
    ctx->pc = 0x1D2B9Cu;
label_1d2b9c:
    // 0x1d2b9c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D2B9Cu;
    SET_GPR_U32(ctx, 31, 0x1D2BA4u);
    ctx->pc = 0x1D2BA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2B9Cu;
            // 0x1d2ba0: 0x3c050500  lui         $a1, 0x500 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)1280 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2BA4u; }
        if (ctx->pc != 0x1D2BA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2BA4u; }
        if (ctx->pc != 0x1D2BA4u) { return; }
    }
    ctx->pc = 0x1D2BA4u;
label_1d2ba4:
    // 0x1d2ba4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1D2BA4u;
    {
        const bool branch_taken_0x1d2ba4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d2ba4) {
            ctx->pc = 0x1D2BB8u;
            goto label_1d2bb8;
        }
    }
    ctx->pc = 0x1D2BACu;
label_1d2bac:
    // 0x1d2bac: 0x2404005d  addiu       $a0, $zero, 0x5D
    ctx->pc = 0x1d2bacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 93));
label_1d2bb0:
    // 0x1d2bb0: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D2BB0u;
    SET_GPR_U32(ctx, 31, 0x1D2BB8u);
    ctx->pc = 0x1D2BB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2BB0u;
            // 0x1d2bb4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2BB8u; }
        if (ctx->pc != 0x1D2BB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2BB8u; }
        if (ctx->pc != 0x1D2BB8u) { return; }
    }
    ctx->pc = 0x1D2BB8u;
label_1d2bb8:
    // 0x1d2bb8: 0x8e23002c  lw          $v1, 0x2C($s1)
    ctx->pc = 0x1d2bb8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 44)));
label_1d2bbc:
    // 0x1d2bbc: 0xa2030089  sb          $v1, 0x89($s0)
    ctx->pc = 0x1d2bbcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 137), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d2bc0: 0x8e230030  lw          $v1, 0x30($s1)
    ctx->pc = 0x1d2bc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 48)));
    // 0x1d2bc4: 0xa203008a  sb          $v1, 0x8A($s0)
    ctx->pc = 0x1d2bc4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 138), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d2bc8: 0x8e230034  lw          $v1, 0x34($s1)
    ctx->pc = 0x1d2bc8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 52)));
    // 0x1d2bcc: 0xa203008b  sb          $v1, 0x8B($s0)
    ctx->pc = 0x1d2bccu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 139), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d2bd0: 0x8e230040  lw          $v1, 0x40($s1)
    ctx->pc = 0x1d2bd0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
    // 0x1d2bd4: 0x31c03  sra         $v1, $v1, 16
    ctx->pc = 0x1d2bd4u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 16));
    // 0x1d2bd8: 0xa203008c  sb          $v1, 0x8C($s0)
    ctx->pc = 0x1d2bd8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 140), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d2bdc: 0x8e23003c  lw          $v1, 0x3C($s1)
    ctx->pc = 0x1d2bdcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 60)));
    // 0x1d2be0: 0xa203008f  sb          $v1, 0x8F($s0)
    ctx->pc = 0x1d2be0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 143), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d2be4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d2be4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d2be8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d2be8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d2bec: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d2becu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d2bf0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D2BF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D2BF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2BF0u;
            // 0x1d2bf4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2A28u: goto label_1d2a28;
            case 0x1D2A68u: goto label_1d2a68;
            case 0x1D2A78u: goto label_1d2a78;
            case 0x1D2A80u: goto label_1d2a80;
            case 0x1D2A9Cu: goto label_1d2a9c;
            case 0x1D2AA0u: goto label_1d2aa0;
            case 0x1D2AC0u: goto label_1d2ac0;
            case 0x1D2AE0u: goto label_1d2ae0;
            case 0x1D2B00u: goto label_1d2b00;
            case 0x1D2B20u: goto label_1d2b20;
            case 0x1D2B40u: goto label_1d2b40;
            case 0x1D2B60u: goto label_1d2b60;
            case 0x1D2B8Cu: goto label_1d2b8c;
            case 0x1D2B94u: goto label_1d2b94;
            case 0x1D2B9Cu: goto label_1d2b9c;
            case 0x1D2BA4u: goto label_1d2ba4;
            case 0x1D2BACu: goto label_1d2bac;
            case 0x1D2BB0u: goto label_1d2bb0;
            case 0x1D2BB8u: goto label_1d2bb8;
            case 0x1D2BBCu: goto label_1d2bbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2BF8u;
    // 0x1d2bf8: 0x0  nop
    ctx->pc = 0x1d2bf8u;
    // NOP
    // 0x1d2bfc: 0x0  nop
    ctx->pc = 0x1d2bfcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
