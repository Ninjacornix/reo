#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F0A3C
// Address: 0x1f0a3c - 0x1f0ba0
void sub_001F0A3C_0x1f0a3c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F0A3C_0x1f0a3c");
#endif

    switch (ctx->pc) {
        case 0x1f0a7cu: goto label_1f0a7c;
        case 0x1f0a8cu: goto label_1f0a8c;
        case 0x1f0ac0u: goto label_1f0ac0;
        case 0x1f0b38u: goto label_1f0b38;
        case 0x1f0b58u: goto label_1f0b58;
        case 0x1f0b84u: goto label_1f0b84;
        default: break;
    }

    ctx->pc = 0x1f0a3cu;

    // 0x1f0a3c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f0a3cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f0a40: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1f0a40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1f0a44: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1f0a44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1f0a48: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f0a48u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0a4c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f0a4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f0a50: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1f0a50u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0a54: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1f0a54u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1f0a58: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1f0a58u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f0a5c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f0a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f0a60: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1f0a60u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1f0a64: 0x27c2000c  addiu       $v0, $fp, 0xC
    ctx->pc = 0x1f0a64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 12));
    // 0x1f0a68: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0a68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0a6c: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1f0a6cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0a70: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f0a70u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0a74: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0A74u;
    SET_GPR_U32(ctx, 31, 0x1F0A7Cu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0A7Cu; }
        if (ctx->pc != 0x1F0A7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0A7Cu; }
        if (ctx->pc != 0x1F0A7Cu) { return; }
    }
    ctx->pc = 0x1F0A7Cu;
label_1f0a7c:
    // 0x1f0a7c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1f0a7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0a80: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1f0a80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1f0a84: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1f0a84u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1f0a88: 0xafc00018  sw          $zero, 0x18($fp)
    ctx->pc = 0x1f0a88u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
label_1f0a8c:
    // 0x1f0a8c: 0x87c2000c  lh          $v0, 0xC($fp)
    ctx->pc = 0x1f0a8cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f0a90: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1f0a90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1f0a94: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1f0a94u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1f0a98: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F0A98u;
    {
        const bool branch_taken_0x1f0a98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f0a98) {
            ctx->pc = 0x1F0AA8u;
            goto label_1f0aa8;
        }
    }
    ctx->pc = 0x1F0AA0u;
    // 0x1f0aa0: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1F0AA0u;
    {
        const bool branch_taken_0x1f0aa0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f0aa0) {
            ctx->pc = 0x1F0B04u;
            goto label_1f0b04;
        }
    }
    ctx->pc = 0x1F0AA8u;
label_1f0aa8:
    // 0x1f0aa8: 0x27c2000e  addiu       $v0, $fp, 0xE
    ctx->pc = 0x1f0aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 14));
    // 0x1f0aac: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0aacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0ab0: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1f0ab0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0ab4: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f0ab4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0ab8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0AB8u;
    SET_GPR_U32(ctx, 31, 0x1F0AC0u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0AC0u; }
        if (ctx->pc != 0x1F0AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0AC0u; }
        if (ctx->pc != 0x1F0AC0u) { return; }
    }
    ctx->pc = 0x1F0AC0u;
label_1f0ac0:
    // 0x1f0ac0: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1f0ac0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0ac4: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1f0ac4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1f0ac8: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1f0ac8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1f0acc: 0x87c3000e  lh          $v1, 0xE($fp)
    ctx->pc = 0x1f0accu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 14)));
    // 0x1f0ad0: 0x87c20004  lh          $v0, 0x4($fp)
    ctx->pc = 0x1f0ad0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0ad4: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F0AD4u;
    {
        const bool branch_taken_0x1f0ad4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f0ad4) {
            ctx->pc = 0x1F0AE4u;
            goto label_1f0ae4;
        }
    }
    ctx->pc = 0x1F0ADCu;
    // 0x1f0adc: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1F0ADCu;
    {
        const bool branch_taken_0x1f0adc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f0adc) {
            ctx->pc = 0x1F0B04u;
            goto label_1f0b04;
        }
    }
    ctx->pc = 0x1F0AE4u;
label_1f0ae4:
    // 0x1f0ae4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1f0ae4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0ae8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f0ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f0aec: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1f0aecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1f0af0: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1f0af0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1f0af4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f0af4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f0af8: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1f0af8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1f0afc: 0x1000ffe3  b           . + 4 + (-0x1D << 2)
    ctx->pc = 0x1F0AFCu;
    {
        const bool branch_taken_0x1f0afc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f0afc) {
            ctx->pc = 0x1F0A8Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f0a8c;
        }
    }
    ctx->pc = 0x1F0B04u;
label_1f0b04:
    // 0x1f0b04: 0x87c3000c  lh          $v1, 0xC($fp)
    ctx->pc = 0x1f0b04u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f0b08: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1f0b08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1f0b0c: 0x14430015  bne         $v0, $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x1F0B0Cu;
    {
        const bool branch_taken_0x1f0b0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1f0b0c) {
            ctx->pc = 0x1F0B64u;
            goto label_1f0b64;
        }
    }
    ctx->pc = 0x1F0B14u;
    // 0x1f0b14: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1f0b14u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f0b18: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f0b18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f0b1c: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1f0b1cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f0b20: 0x27c2000c  addiu       $v0, $fp, 0xC
    ctx->pc = 0x1f0b20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 12));
    // 0x1f0b24: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f0b24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f0b28: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f0b28u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0b2c: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f0b2cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0b30: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0B30u;
    SET_GPR_U32(ctx, 31, 0x1F0B38u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0B38u; }
        if (ctx->pc != 0x1F0B38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0B38u; }
        if (ctx->pc != 0x1F0B38u) { return; }
    }
    ctx->pc = 0x1F0B38u;
label_1f0b38:
    // 0x1f0b38: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1f0b38u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0b3c: 0xa7c2000e  sh          $v0, 0xE($fp)
    ctx->pc = 0x1f0b3cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 14), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f0b40: 0x27c2000e  addiu       $v0, $fp, 0xE
    ctx->pc = 0x1f0b40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 14));
    // 0x1f0b44: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1f0b44u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0b48: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f0b48u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0b4c: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f0b4cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0b50: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0B50u;
    SET_GPR_U32(ctx, 31, 0x1F0B58u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0B58u; }
        if (ctx->pc != 0x1F0B58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0B58u; }
        if (ctx->pc != 0x1F0B58u) { return; }
    }
    ctx->pc = 0x1F0B58u;
label_1f0b58:
    // 0x1f0b58: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1f0b58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0b5c: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1f0b5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1f0b60: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1f0b60u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
label_1f0b64:
    // 0x1f0b64: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f0b64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f0b68: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1f0b68u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1f0b6c: 0x27c20010  addiu       $v0, $fp, 0x10
    ctx->pc = 0x1f0b6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1f0b70: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1f0b70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0b74: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f0b74u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0b78: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1f0b78u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f0b7c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0B7Cu;
    SET_GPR_U32(ctx, 31, 0x1F0B84u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0B84u; }
        if (ctx->pc != 0x1F0B84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0B84u; }
        if (ctx->pc != 0x1F0B84u) { return; }
    }
    ctx->pc = 0x1F0B84u;
label_1f0b84:
    // 0x1f0b84: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f0b84u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0b88: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f0b88u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0b8c: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1f0b8cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f0b90: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1f0b90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1f0b94: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1f0b94u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f0b98: 0x3e00008  jr          $ra
    ctx->pc = 0x1F0B98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F0A7Cu: goto label_1f0a7c;
            case 0x1F0A8Cu: goto label_1f0a8c;
            case 0x1F0AA8u: goto label_1f0aa8;
            case 0x1F0AC0u: goto label_1f0ac0;
            case 0x1F0AE4u: goto label_1f0ae4;
            case 0x1F0B04u: goto label_1f0b04;
            case 0x1F0B38u: goto label_1f0b38;
            case 0x1F0B58u: goto label_1f0b58;
            case 0x1F0B64u: goto label_1f0b64;
            case 0x1F0B84u: goto label_1f0b84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F0BA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
