#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F0C0C
// Address: 0x1f0c0c - 0x1f0eb8
void sub_001F0C0C_0x1f0c0c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F0C0C_0x1f0c0c");
#endif

    switch (ctx->pc) {
        case 0x1f0c40u: goto label_1f0c40;
        case 0x1f0c58u: goto label_1f0c58;
        case 0x1f0c74u: goto label_1f0c74;
        case 0x1f0c80u: goto label_1f0c80;
        case 0x1f0cacu: goto label_1f0cac;
        case 0x1f0cbcu: goto label_1f0cbc;
        case 0x1f0cd8u: goto label_1f0cd8;
        case 0x1f0cfcu: goto label_1f0cfc;
        case 0x1f0d08u: goto label_1f0d08;
        case 0x1f0d24u: goto label_1f0d24;
        case 0x1f0d94u: goto label_1f0d94;
        case 0x1f0da4u: goto label_1f0da4;
        case 0x1f0dc8u: goto label_1f0dc8;
        case 0x1f0dd4u: goto label_1f0dd4;
        case 0x1f0e00u: goto label_1f0e00;
        case 0x1f0e10u: goto label_1f0e10;
        case 0x1f0e2cu: goto label_1f0e2c;
        case 0x1f0e50u: goto label_1f0e50;
        case 0x1f0e5cu: goto label_1f0e5c;
        case 0x1f0e78u: goto label_1f0e78;
        default: break;
    }

    ctx->pc = 0x1f0c0cu;

    // 0x1f0c0c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f0c0cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f0c10: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1f0c10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1f0c14: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1f0c14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1f0c18: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f0c18u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0c1c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f0c1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f0c20: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f0c20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f0c24: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f0c24u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f0c28: 0x27c20008  addiu       $v0, $fp, 0x8
    ctx->pc = 0x1f0c28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x1f0c2c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0c2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0c30: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1f0c30u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0c34: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f0c34u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0c38: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0C38u;
    SET_GPR_U32(ctx, 31, 0x1F0C40u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0C40u; }
        if (ctx->pc != 0x1F0C40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0C40u; }
        if (ctx->pc != 0x1F0C40u) { return; }
    }
    ctx->pc = 0x1F0C40u;
label_1f0c40:
    // 0x1f0c40: 0x87c20008  lh          $v0, 0x8($fp)
    ctx->pc = 0x1f0c40u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f0c44: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1f0c44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1f0c48: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1f0c48u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f0c4c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0c4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0c50: 0xc07a05f  jal         func_1E817C
    ctx->pc = 0x1F0C50u;
    SET_GPR_U32(ctx, 31, 0x1F0C58u);
    ctx->pc = 0x1E817Cu;
    if (runtime->hasFunction(0x1E817Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E817Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0C58u; }
        if (ctx->pc != 0x1F0C58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E817C_0x1e817c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0C58u; }
        if (ctx->pc != 0x1F0C58u) { return; }
    }
    ctx->pc = 0x1F0C58u;
label_1f0c58:
    // 0x1f0c58: 0xa7c20008  sh          $v0, 0x8($fp)
    ctx->pc = 0x1f0c58u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f0c5c: 0x27c20008  addiu       $v0, $fp, 0x8
    ctx->pc = 0x1f0c5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x1f0c60: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f0c60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0c64: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f0c64u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0c68: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f0c68u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0c6c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0C6Cu;
    SET_GPR_U32(ctx, 31, 0x1F0C74u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0C74u; }
        if (ctx->pc != 0x1F0C74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0C74u; }
        if (ctx->pc != 0x1F0C74u) { return; }
    }
    ctx->pc = 0x1F0C74u;
label_1f0c74:
    // 0x1f0c74: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f0c74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0c78: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1f0c78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1f0c7c: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f0c7cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
label_1f0c80:
    // 0x1f0c80: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f0c80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f0c84: 0x1c400003  bgtz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F0C84u;
    {
        const bool branch_taken_0x1f0c84 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1f0c84) {
            ctx->pc = 0x1F0C94u;
            goto label_1f0c94;
        }
    }
    ctx->pc = 0x1F0C8Cu;
    // 0x1f0c8c: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x1F0C8Cu;
    {
        const bool branch_taken_0x1f0c8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f0c8c) {
            ctx->pc = 0x1F0D44u;
            goto label_1f0d44;
        }
    }
    ctx->pc = 0x1F0C94u;
label_1f0c94:
    // 0x1f0c94: 0x27c2000a  addiu       $v0, $fp, 0xA
    ctx->pc = 0x1f0c94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 10));
    // 0x1f0c98: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0c98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0c9c: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1f0c9cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0ca0: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f0ca0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0ca4: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0CA4u;
    SET_GPR_U32(ctx, 31, 0x1F0CACu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0CACu; }
        if (ctx->pc != 0x1F0CACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0CACu; }
        if (ctx->pc != 0x1F0CACu) { return; }
    }
    ctx->pc = 0x1F0CACu;
label_1f0cac:
    // 0x1f0cac: 0x97c2000a  lhu         $v0, 0xA($fp)
    ctx->pc = 0x1f0cacu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 10)));
    // 0x1f0cb0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0cb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0cb4: 0xc07a05f  jal         func_1E817C
    ctx->pc = 0x1F0CB4u;
    SET_GPR_U32(ctx, 31, 0x1F0CBCu);
    ctx->pc = 0x1E817Cu;
    if (runtime->hasFunction(0x1E817Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E817Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0CBCu; }
        if (ctx->pc != 0x1F0CBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E817C_0x1e817c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0CBCu; }
        if (ctx->pc != 0x1F0CBCu) { return; }
    }
    ctx->pc = 0x1F0CBCu;
label_1f0cbc:
    // 0x1f0cbc: 0xa7c2000a  sh          $v0, 0xA($fp)
    ctx->pc = 0x1f0cbcu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 10), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f0cc0: 0x27c2000a  addiu       $v0, $fp, 0xA
    ctx->pc = 0x1f0cc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 10));
    // 0x1f0cc4: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f0cc4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0cc8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f0cc8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0ccc: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f0cccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0cd0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0CD0u;
    SET_GPR_U32(ctx, 31, 0x1F0CD8u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0CD8u; }
        if (ctx->pc != 0x1F0CD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0CD8u; }
        if (ctx->pc != 0x1F0CD8u) { return; }
    }
    ctx->pc = 0x1F0CD8u;
label_1f0cd8:
    // 0x1f0cd8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f0cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0cdc: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1f0cdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1f0ce0: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f0ce0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f0ce4: 0x27c2000c  addiu       $v0, $fp, 0xC
    ctx->pc = 0x1f0ce4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 12));
    // 0x1f0ce8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0ce8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0cec: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1f0cecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0cf0: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1f0cf0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f0cf4: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0CF4u;
    SET_GPR_U32(ctx, 31, 0x1F0CFCu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0CFCu; }
        if (ctx->pc != 0x1F0CFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0CFCu; }
        if (ctx->pc != 0x1F0CFCu) { return; }
    }
    ctx->pc = 0x1F0CFCu;
label_1f0cfc:
    // 0x1f0cfc: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1f0cfcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f0d00: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1F0D00u;
    SET_GPR_U32(ctx, 31, 0x1F0D08u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0D08u; }
        if (ctx->pc != 0x1F0D08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0D08u; }
        if (ctx->pc != 0x1F0D08u) { return; }
    }
    ctx->pc = 0x1F0D08u;
label_1f0d08:
    // 0x1f0d08: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f0d08u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f0d0c: 0x27c2000c  addiu       $v0, $fp, 0xC
    ctx->pc = 0x1f0d0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 12));
    // 0x1f0d10: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f0d10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0d14: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f0d14u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0d18: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1f0d18u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f0d1c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0D1Cu;
    SET_GPR_U32(ctx, 31, 0x1F0D24u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0D24u; }
        if (ctx->pc != 0x1F0D24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0D24u; }
        if (ctx->pc != 0x1F0D24u) { return; }
    }
    ctx->pc = 0x1F0D24u;
label_1f0d24:
    // 0x1f0d24: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f0d24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0d28: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f0d28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f0d2c: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f0d2cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f0d30: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f0d30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f0d34: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1f0d34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1f0d38: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1f0d38u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1f0d3c: 0x1000ffd0  b           . + 4 + (-0x30 << 2)
    ctx->pc = 0x1F0D3Cu;
    {
        const bool branch_taken_0x1f0d3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f0d3c) {
            ctx->pc = 0x1F0C80u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f0c80;
        }
    }
    ctx->pc = 0x1F0D44u;
label_1f0d44:
    // 0x1f0d44: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f0d44u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0d48: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f0d48u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0d4c: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1f0d4cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f0d50: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1f0d50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1f0d54: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1f0d54u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f0d58: 0x3e00008  jr          $ra
    ctx->pc = 0x1F0D58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F0C40u: goto label_1f0c40;
            case 0x1F0C58u: goto label_1f0c58;
            case 0x1F0C74u: goto label_1f0c74;
            case 0x1F0C80u: goto label_1f0c80;
            case 0x1F0C94u: goto label_1f0c94;
            case 0x1F0CACu: goto label_1f0cac;
            case 0x1F0CBCu: goto label_1f0cbc;
            case 0x1F0CD8u: goto label_1f0cd8;
            case 0x1F0CFCu: goto label_1f0cfc;
            case 0x1F0D08u: goto label_1f0d08;
            case 0x1F0D24u: goto label_1f0d24;
            case 0x1F0D44u: goto label_1f0d44;
            case 0x1F0D94u: goto label_1f0d94;
            case 0x1F0DA4u: goto label_1f0da4;
            case 0x1F0DC8u: goto label_1f0dc8;
            case 0x1F0DD4u: goto label_1f0dd4;
            case 0x1F0DE8u: goto label_1f0de8;
            case 0x1F0E00u: goto label_1f0e00;
            case 0x1F0E10u: goto label_1f0e10;
            case 0x1F0E2Cu: goto label_1f0e2c;
            case 0x1F0E50u: goto label_1f0e50;
            case 0x1F0E5Cu: goto label_1f0e5c;
            case 0x1F0E78u: goto label_1f0e78;
            case 0x1F0E98u: goto label_1f0e98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F0D60u;
    // 0x1f0d60: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f0d60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f0d64: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1f0d64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1f0d68: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1f0d68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1f0d6c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f0d6cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0d70: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f0d70u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f0d74: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f0d74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f0d78: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f0d78u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f0d7c: 0x27c20008  addiu       $v0, $fp, 0x8
    ctx->pc = 0x1f0d7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x1f0d80: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0d80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0d84: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1f0d84u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0d88: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f0d88u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0d8c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0D8Cu;
    SET_GPR_U32(ctx, 31, 0x1F0D94u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0D94u; }
        if (ctx->pc != 0x1F0D94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0D94u; }
        if (ctx->pc != 0x1F0D94u) { return; }
    }
    ctx->pc = 0x1F0D94u;
label_1f0d94:
    // 0x1f0d94: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1f0d94u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f0d98: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0d98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0d9c: 0xc07a083  jal         func_1E820C
    ctx->pc = 0x1F0D9Cu;
    SET_GPR_U32(ctx, 31, 0x1F0DA4u);
    ctx->pc = 0x1E820Cu;
    if (runtime->hasFunction(0x1E820Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E820Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0DA4u; }
        if (ctx->pc != 0x1F0DA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E820C_0x1e820c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0DA4u; }
        if (ctx->pc != 0x1F0DA4u) { return; }
    }
    ctx->pc = 0x1F0DA4u;
label_1f0da4:
    // 0x1f0da4: 0xa7c20008  sh          $v0, 0x8($fp)
    ctx->pc = 0x1f0da4u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f0da8: 0x87c20008  lh          $v0, 0x8($fp)
    ctx->pc = 0x1f0da8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f0dac: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1f0dacu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1f0db0: 0x27c20008  addiu       $v0, $fp, 0x8
    ctx->pc = 0x1f0db0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x1f0db4: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f0db4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0db8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f0db8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0dbc: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f0dbcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0dc0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0DC0u;
    SET_GPR_U32(ctx, 31, 0x1F0DC8u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0DC8u; }
        if (ctx->pc != 0x1F0DC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0DC8u; }
        if (ctx->pc != 0x1F0DC8u) { return; }
    }
    ctx->pc = 0x1F0DC8u;
label_1f0dc8:
    // 0x1f0dc8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f0dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0dcc: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1f0dccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1f0dd0: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f0dd0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
label_1f0dd4:
    // 0x1f0dd4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f0dd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f0dd8: 0x1c400003  bgtz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F0DD8u;
    {
        const bool branch_taken_0x1f0dd8 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1f0dd8) {
            ctx->pc = 0x1F0DE8u;
            goto label_1f0de8;
        }
    }
    ctx->pc = 0x1F0DE0u;
    // 0x1f0de0: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x1F0DE0u;
    {
        const bool branch_taken_0x1f0de0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f0de0) {
            ctx->pc = 0x1F0E98u;
            goto label_1f0e98;
        }
    }
    ctx->pc = 0x1F0DE8u;
label_1f0de8:
    // 0x1f0de8: 0x27c2000a  addiu       $v0, $fp, 0xA
    ctx->pc = 0x1f0de8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 10));
    // 0x1f0dec: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0decu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0df0: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1f0df0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0df4: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f0df4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0df8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0DF8u;
    SET_GPR_U32(ctx, 31, 0x1F0E00u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0E00u; }
        if (ctx->pc != 0x1F0E00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0E00u; }
        if (ctx->pc != 0x1F0E00u) { return; }
    }
    ctx->pc = 0x1F0E00u;
label_1f0e00:
    // 0x1f0e00: 0x97c2000a  lhu         $v0, 0xA($fp)
    ctx->pc = 0x1f0e00u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 10)));
    // 0x1f0e04: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0e04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0e08: 0xc07a083  jal         func_1E820C
    ctx->pc = 0x1F0E08u;
    SET_GPR_U32(ctx, 31, 0x1F0E10u);
    ctx->pc = 0x1E820Cu;
    if (runtime->hasFunction(0x1E820Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E820Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0E10u; }
        if (ctx->pc != 0x1F0E10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E820C_0x1e820c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0E10u; }
        if (ctx->pc != 0x1F0E10u) { return; }
    }
    ctx->pc = 0x1F0E10u;
label_1f0e10:
    // 0x1f0e10: 0xa7c2000a  sh          $v0, 0xA($fp)
    ctx->pc = 0x1f0e10u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 10), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f0e14: 0x27c2000a  addiu       $v0, $fp, 0xA
    ctx->pc = 0x1f0e14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 10));
    // 0x1f0e18: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f0e18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0e1c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f0e1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0e20: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f0e20u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0e24: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0E24u;
    SET_GPR_U32(ctx, 31, 0x1F0E2Cu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0E2Cu; }
        if (ctx->pc != 0x1F0E2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0E2Cu; }
        if (ctx->pc != 0x1F0E2Cu) { return; }
    }
    ctx->pc = 0x1F0E2Cu;
label_1f0e2c:
    // 0x1f0e2c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f0e2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0e30: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1f0e30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1f0e34: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f0e34u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f0e38: 0x27c2000c  addiu       $v0, $fp, 0xC
    ctx->pc = 0x1f0e38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 12));
    // 0x1f0e3c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0e3cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0e40: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1f0e40u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0e44: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1f0e44u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f0e48: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0E48u;
    SET_GPR_U32(ctx, 31, 0x1F0E50u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0E50u; }
        if (ctx->pc != 0x1F0E50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0E50u; }
        if (ctx->pc != 0x1F0E50u) { return; }
    }
    ctx->pc = 0x1F0E50u;
label_1f0e50:
    // 0x1f0e50: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1f0e50u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f0e54: 0xc07a071  jal         func_1E81C4
    ctx->pc = 0x1F0E54u;
    SET_GPR_U32(ctx, 31, 0x1F0E5Cu);
    ctx->pc = 0x1E81C4u;
    if (runtime->hasFunction(0x1E81C4u)) {
        auto targetFn = runtime->lookupFunction(0x1E81C4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0E5Cu; }
        if (ctx->pc != 0x1F0E5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E81C4_0x1e81c4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0E5Cu; }
        if (ctx->pc != 0x1F0E5Cu) { return; }
    }
    ctx->pc = 0x1F0E5Cu;
label_1f0e5c:
    // 0x1f0e5c: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f0e5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f0e60: 0x27c2000c  addiu       $v0, $fp, 0xC
    ctx->pc = 0x1f0e60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 12));
    // 0x1f0e64: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f0e64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0e68: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f0e68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0e6c: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1f0e6cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f0e70: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0E70u;
    SET_GPR_U32(ctx, 31, 0x1F0E78u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0E78u; }
        if (ctx->pc != 0x1F0E78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0E78u; }
        if (ctx->pc != 0x1F0E78u) { return; }
    }
    ctx->pc = 0x1F0E78u;
label_1f0e78:
    // 0x1f0e78: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f0e78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0e7c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f0e7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f0e80: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f0e80u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f0e84: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f0e84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f0e88: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1f0e88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1f0e8c: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1f0e8cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1f0e90: 0x1000ffd0  b           . + 4 + (-0x30 << 2)
    ctx->pc = 0x1F0E90u;
    {
        const bool branch_taken_0x1f0e90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f0e90) {
            ctx->pc = 0x1F0DD4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f0dd4;
        }
    }
    ctx->pc = 0x1F0E98u;
label_1f0e98:
    // 0x1f0e98: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f0e98u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0e9c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f0e9cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0ea0: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1f0ea0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f0ea4: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1f0ea4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1f0ea8: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1f0ea8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f0eac: 0x3e00008  jr          $ra
    ctx->pc = 0x1F0EACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F0C40u: goto label_1f0c40;
            case 0x1F0C58u: goto label_1f0c58;
            case 0x1F0C74u: goto label_1f0c74;
            case 0x1F0C80u: goto label_1f0c80;
            case 0x1F0C94u: goto label_1f0c94;
            case 0x1F0CACu: goto label_1f0cac;
            case 0x1F0CBCu: goto label_1f0cbc;
            case 0x1F0CD8u: goto label_1f0cd8;
            case 0x1F0CFCu: goto label_1f0cfc;
            case 0x1F0D08u: goto label_1f0d08;
            case 0x1F0D24u: goto label_1f0d24;
            case 0x1F0D44u: goto label_1f0d44;
            case 0x1F0D94u: goto label_1f0d94;
            case 0x1F0DA4u: goto label_1f0da4;
            case 0x1F0DC8u: goto label_1f0dc8;
            case 0x1F0DD4u: goto label_1f0dd4;
            case 0x1F0DE8u: goto label_1f0de8;
            case 0x1F0E00u: goto label_1f0e00;
            case 0x1F0E10u: goto label_1f0e10;
            case 0x1F0E2Cu: goto label_1f0e2c;
            case 0x1F0E50u: goto label_1f0e50;
            case 0x1F0E5Cu: goto label_1f0e5c;
            case 0x1F0E78u: goto label_1f0e78;
            case 0x1F0E98u: goto label_1f0e98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F0EB4u;
    // 0x1f0eb4: 0x0  nop
    ctx->pc = 0x1f0eb4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
