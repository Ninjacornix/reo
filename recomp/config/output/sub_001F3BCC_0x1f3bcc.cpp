#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F3BCC
// Address: 0x1f3bcc - 0x1f3e54
void sub_001F3BCC_0x1f3bcc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F3BCC_0x1f3bcc");
#endif

    switch (ctx->pc) {
        case 0x1f3becu: goto label_1f3bec;
        case 0x1f3bfcu: goto label_1f3bfc;
        case 0x1f3c00u: goto label_1f3c00;
        case 0x1f3c40u: goto label_1f3c40;
        case 0x1f3c70u: goto label_1f3c70;
        case 0x1f3c8cu: goto label_1f3c8c;
        case 0x1f3cacu: goto label_1f3cac;
        case 0x1f3cc8u: goto label_1f3cc8;
        case 0x1f3ce4u: goto label_1f3ce4;
        case 0x1f3d00u: goto label_1f3d00;
        case 0x1f3d68u: goto label_1f3d68;
        case 0x1f3d88u: goto label_1f3d88;
        case 0x1f3dd8u: goto label_1f3dd8;
        default: break;
    }

    ctx->pc = 0x1f3bccu;

    // 0x1f3bcc: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1f3bccu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1f3bd0: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1f3bd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1f3bd4: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1f3bd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1f3bd8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f3bd8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3bdc: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f3bdcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f3be0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f3be0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3be4: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1F3BE4u;
    SET_GPR_U32(ctx, 31, 0x1F3BECu);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3BECu; }
        if (ctx->pc != 0x1F3BECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3BECu; }
        if (ctx->pc != 0x1F3BECu) { return; }
    }
    ctx->pc = 0x1F3BECu;
label_1f3bec:
    // 0x1f3bec: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1f3becu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1f3bf0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f3bf0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3bf4: 0xc07cd3b  jal         func_1F34EC
    ctx->pc = 0x1F3BF4u;
    SET_GPR_U32(ctx, 31, 0x1F3BFCu);
    ctx->pc = 0x1F34ECu;
    if (runtime->hasFunction(0x1F34ECu)) {
        auto targetFn = runtime->lookupFunction(0x1F34ECu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3BFCu; }
        if (ctx->pc != 0x1F3BFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F34EC_0x1f34ec(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3BFCu; }
        if (ctx->pc != 0x1F3BFCu) { return; }
    }
    ctx->pc = 0x1F3BFCu;
label_1f3bfc:
    // 0x1f3bfc: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f3bfcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
label_1f3c00:
    // 0x1f3c00: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f3c00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f3c04: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F3C04u;
    {
        const bool branch_taken_0x1f3c04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f3c04) {
            ctx->pc = 0x1F3C14u;
            goto label_1f3c14;
        }
    }
    ctx->pc = 0x1F3C0Cu;
    // 0x1f3c0c: 0x10000075  b           . + 4 + (0x75 << 2)
    ctx->pc = 0x1F3C0Cu;
    {
        const bool branch_taken_0x1f3c0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3c0c) {
            ctx->pc = 0x1F3DE4u;
            goto label_1f3de4;
        }
    }
    ctx->pc = 0x1F3C14u;
label_1f3c14:
    // 0x1f3c14: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f3c14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f3c18: 0x28420010  slti        $v0, $v0, 0x10
    ctx->pc = 0x1f3c18u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1f3c1c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F3C1Cu;
    {
        const bool branch_taken_0x1f3c1c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3c1c) {
            ctx->pc = 0x1F3C30u;
            goto label_1f3c30;
        }
    }
    ctx->pc = 0x1F3C24u;
    // 0x1f3c24: 0x2402e0c3  addiu       $v0, $zero, -0x1F3D
    ctx->pc = 0x1f3c24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294959299));
    // 0x1f3c28: 0x1000006f  b           . + 4 + (0x6F << 2)
    ctx->pc = 0x1F3C28u;
    {
        const bool branch_taken_0x1f3c28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3c28) {
            ctx->pc = 0x1F3DE8u;
            goto label_1f3de8;
        }
    }
    ctx->pc = 0x1F3C30u;
label_1f3c30:
    // 0x1f3c30: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f3c30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3c34: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1f3c34u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f3c38: 0xc07ce10  jal         func_1F3840
    ctx->pc = 0x1F3C38u;
    SET_GPR_U32(ctx, 31, 0x1F3C40u);
    ctx->pc = 0x1F3840u;
    if (runtime->hasFunction(0x1F3840u)) {
        auto targetFn = runtime->lookupFunction(0x1F3840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3C40u; }
        if (ctx->pc != 0x1F3C40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3840_0x1f3840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3C40u; }
        if (ctx->pc != 0x1F3C40u) { return; }
    }
    ctx->pc = 0x1F3C40u;
label_1f3c40:
    // 0x1f3c40: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F3C40u;
    {
        const bool branch_taken_0x1f3c40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3c40) {
            ctx->pc = 0x1F3C58u;
            goto label_1f3c58;
        }
    }
    ctx->pc = 0x1F3C48u;
    // 0x1f3c48: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f3c48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f3c4c: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1f3c4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1f3c50: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1F3C50u;
    {
        const bool branch_taken_0x1f3c50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3c50) {
            ctx->pc = 0x1F3C78u;
            goto label_1f3c78;
        }
    }
    ctx->pc = 0x1F3C58u;
label_1f3c58:
    // 0x1f3c58: 0x27c20020  addiu       $v0, $fp, 0x20
    ctx->pc = 0x1f3c58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1f3c5c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f3c5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3c60: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1f3c60u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f3c64: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1f3c64u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1f3c68: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F3C68u;
    SET_GPR_U32(ctx, 31, 0x1F3C70u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3C70u; }
        if (ctx->pc != 0x1F3C70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3C70u; }
        if (ctx->pc != 0x1F3C70u) { return; }
    }
    ctx->pc = 0x1F3C70u;
label_1f3c70:
    // 0x1f3c70: 0x27c20020  addiu       $v0, $fp, 0x20
    ctx->pc = 0x1f3c70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1f3c74: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1f3c74u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
label_1f3c78:
    // 0x1f3c78: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f3c78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f3c7c: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1f3c7cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f3c80: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f3c80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3c84: 0xc07a083  jal         func_1E820C
    ctx->pc = 0x1F3C84u;
    SET_GPR_U32(ctx, 31, 0x1F3C8Cu);
    ctx->pc = 0x1E820Cu;
    if (runtime->hasFunction(0x1E820Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E820Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3C8Cu; }
        if (ctx->pc != 0x1F3C8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E820C_0x1e820c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3C8Cu; }
        if (ctx->pc != 0x1F3C8Cu) { return; }
    }
    ctx->pc = 0x1F3C8Cu;
label_1f3c8c:
    // 0x1f3c8c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1f3c8cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3c90: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f3c90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f3c94: 0xa4430000  sh          $v1, 0x0($v0)
    ctx->pc = 0x1f3c94u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1f3c98: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f3c98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f3c9c: 0x94420002  lhu         $v0, 0x2($v0)
    ctx->pc = 0x1f3c9cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1f3ca0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f3ca0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3ca4: 0xc07a083  jal         func_1E820C
    ctx->pc = 0x1F3CA4u;
    SET_GPR_U32(ctx, 31, 0x1F3CACu);
    ctx->pc = 0x1E820Cu;
    if (runtime->hasFunction(0x1E820Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E820Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3CACu; }
        if (ctx->pc != 0x1F3CACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E820C_0x1e820c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3CACu; }
        if (ctx->pc != 0x1F3CACu) { return; }
    }
    ctx->pc = 0x1F3CACu;
label_1f3cac:
    // 0x1f3cac: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1f3cacu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3cb0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f3cb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f3cb4: 0xa4430002  sh          $v1, 0x2($v0)
    ctx->pc = 0x1f3cb4u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 2), (uint16_t)GPR_U32(ctx, 3));
    // 0x1f3cb8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f3cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f3cbc: 0x8c440004  lw          $a0, 0x4($v0)
    ctx->pc = 0x1f3cbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1f3cc0: 0xc07a071  jal         func_1E81C4
    ctx->pc = 0x1F3CC0u;
    SET_GPR_U32(ctx, 31, 0x1F3CC8u);
    ctx->pc = 0x1E81C4u;
    if (runtime->hasFunction(0x1E81C4u)) {
        auto targetFn = runtime->lookupFunction(0x1E81C4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3CC8u; }
        if (ctx->pc != 0x1F3CC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E81C4_0x1e81c4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3CC8u; }
        if (ctx->pc != 0x1F3CC8u) { return; }
    }
    ctx->pc = 0x1F3CC8u;
label_1f3cc8:
    // 0x1f3cc8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1f3cc8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3ccc: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f3cccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f3cd0: 0xac430004  sw          $v1, 0x4($v0)
    ctx->pc = 0x1f3cd0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 3));
    // 0x1f3cd4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f3cd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f3cd8: 0x8c440008  lw          $a0, 0x8($v0)
    ctx->pc = 0x1f3cd8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1f3cdc: 0xc07a071  jal         func_1E81C4
    ctx->pc = 0x1F3CDCu;
    SET_GPR_U32(ctx, 31, 0x1F3CE4u);
    ctx->pc = 0x1E81C4u;
    if (runtime->hasFunction(0x1E81C4u)) {
        auto targetFn = runtime->lookupFunction(0x1E81C4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3CE4u; }
        if (ctx->pc != 0x1F3CE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E81C4_0x1e81c4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3CE4u; }
        if (ctx->pc != 0x1F3CE4u) { return; }
    }
    ctx->pc = 0x1F3CE4u;
label_1f3ce4:
    // 0x1f3ce4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1f3ce4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3ce8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f3ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f3cec: 0xac430008  sw          $v1, 0x8($v0)
    ctx->pc = 0x1f3cecu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
    // 0x1f3cf0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f3cf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f3cf4: 0x8c44000c  lw          $a0, 0xC($v0)
    ctx->pc = 0x1f3cf4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1f3cf8: 0xc07a071  jal         func_1E81C4
    ctx->pc = 0x1F3CF8u;
    SET_GPR_U32(ctx, 31, 0x1F3D00u);
    ctx->pc = 0x1E81C4u;
    if (runtime->hasFunction(0x1E81C4u)) {
        auto targetFn = runtime->lookupFunction(0x1E81C4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3D00u; }
        if (ctx->pc != 0x1F3D00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E81C4_0x1e81c4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3D00u; }
        if (ctx->pc != 0x1F3D00u) { return; }
    }
    ctx->pc = 0x1F3D00u;
label_1f3d00:
    // 0x1f3d00: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1f3d00u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3d04: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f3d04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f3d08: 0xac43000c  sw          $v1, 0xC($v0)
    ctx->pc = 0x1f3d08u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 3));
    // 0x1f3d0c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f3d0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f3d10: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1f3d10u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f3d14: 0x304203ff  andi        $v0, $v0, 0x3FF
    ctx->pc = 0x1f3d14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1023);
    // 0x1f3d18: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1f3d18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f3d1c: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f3d1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f3d20: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f3d20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f3d24: 0x28420010  slti        $v0, $v0, 0x10
    ctx->pc = 0x1f3d24u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1f3d28: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1F3D28u;
    {
        const bool branch_taken_0x1f3d28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f3d28) {
            ctx->pc = 0x1F3D4Cu;
            goto label_1f3d4c;
        }
    }
    ctx->pc = 0x1F3D30u;
    // 0x1f3d30: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f3d30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f3d34: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1f3d34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f3d38: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1f3d38u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1f3d3c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F3D3Cu;
    {
        const bool branch_taken_0x1f3d3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f3d3c) {
            ctx->pc = 0x1F3D4Cu;
            goto label_1f3d4c;
        }
    }
    ctx->pc = 0x1F3D44u;
    // 0x1f3d44: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1F3D44u;
    {
        const bool branch_taken_0x1f3d44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3d44) {
            ctx->pc = 0x1F3D58u;
            goto label_1f3d58;
        }
    }
    ctx->pc = 0x1F3D4Cu;
label_1f3d4c:
    // 0x1f3d4c: 0x2402e0c5  addiu       $v0, $zero, -0x1F3B
    ctx->pc = 0x1f3d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294959301));
    // 0x1f3d50: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1F3D50u;
    {
        const bool branch_taken_0x1f3d50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3d50) {
            ctx->pc = 0x1F3DE8u;
            goto label_1f3de8;
        }
    }
    ctx->pc = 0x1F3D58u;
label_1f3d58:
    // 0x1f3d58: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f3d58u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3d5c: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1f3d5cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f3d60: 0xc07ce10  jal         func_1F3840
    ctx->pc = 0x1F3D60u;
    SET_GPR_U32(ctx, 31, 0x1F3D68u);
    ctx->pc = 0x1F3840u;
    if (runtime->hasFunction(0x1F3840u)) {
        auto targetFn = runtime->lookupFunction(0x1F3840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3D68u; }
        if (ctx->pc != 0x1F3D68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3840_0x1f3840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3D68u; }
        if (ctx->pc != 0x1F3D68u) { return; }
    }
    ctx->pc = 0x1F3D68u;
label_1f3d68:
    // 0x1f3d68: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1F3D68u;
    {
        const bool branch_taken_0x1f3d68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f3d68) {
            ctx->pc = 0x1F3D88u;
            goto label_1f3d88;
        }
    }
    ctx->pc = 0x1F3D70u;
    // 0x1f3d70: 0x27c20020  addiu       $v0, $fp, 0x20
    ctx->pc = 0x1f3d70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1f3d74: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1f3d74u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f3d78: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f3d78u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3d7c: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1f3d7cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1f3d80: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F3D80u;
    SET_GPR_U32(ctx, 31, 0x1F3D88u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3D88u; }
        if (ctx->pc != 0x1F3D88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3D88u; }
        if (ctx->pc != 0x1F3D88u) { return; }
    }
    ctx->pc = 0x1F3D88u;
label_1f3d88:
    // 0x1f3d88: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1f3d88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f3d8c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f3d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f3d90: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x1f3d90u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f3d94: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1f3d94u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1f3d98: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f3d98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f3d9c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F3D9Cu;
    {
        const bool branch_taken_0x1f3d9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f3d9c) {
            ctx->pc = 0x1F3DACu;
            goto label_1f3dac;
        }
    }
    ctx->pc = 0x1F3DA4u;
    // 0x1f3da4: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1F3DA4u;
    {
        const bool branch_taken_0x1f3da4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3da4) {
            ctx->pc = 0x1F3DE4u;
            goto label_1f3de4;
        }
    }
    ctx->pc = 0x1F3DACu;
label_1f3dac:
    // 0x1f3dac: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f3dacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f3db0: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F3DB0u;
    {
        const bool branch_taken_0x1f3db0 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1f3db0) {
            ctx->pc = 0x1F3DC4u;
            goto label_1f3dc4;
        }
    }
    ctx->pc = 0x1F3DB8u;
    // 0x1f3db8: 0x2402e0c3  addiu       $v0, $zero, -0x1F3D
    ctx->pc = 0x1f3db8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294959299));
    // 0x1f3dbc: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1F3DBCu;
    {
        const bool branch_taken_0x1f3dbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3dbc) {
            ctx->pc = 0x1F3DE8u;
            goto label_1f3de8;
        }
    }
    ctx->pc = 0x1F3DC4u;
label_1f3dc4:
    // 0x1f3dc4: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f3dc4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3dc8: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1f3dc8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f3dcc: 0x8fc60004  lw          $a2, 0x4($fp)
    ctx->pc = 0x1f3dccu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f3dd0: 0xc07cfa4  jal         func_1F3E90
    ctx->pc = 0x1F3DD0u;
    SET_GPR_U32(ctx, 31, 0x1F3DD8u);
    ctx->pc = 0x1F3E90u;
    if (runtime->hasFunction(0x1F3E90u)) {
        auto targetFn = runtime->lookupFunction(0x1F3E90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3DD8u; }
        if (ctx->pc != 0x1F3DD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3E90_0x1f3e90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3DD8u; }
        if (ctx->pc != 0x1F3DD8u) { return; }
    }
    ctx->pc = 0x1F3DD8u;
label_1f3dd8:
    // 0x1f3dd8: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f3dd8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f3ddc: 0x1000ff88  b           . + 4 + (-0x78 << 2)
    ctx->pc = 0x1F3DDCu;
    {
        const bool branch_taken_0x1f3ddc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3ddc) {
            ctx->pc = 0x1F3C00u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f3c00;
        }
    }
    ctx->pc = 0x1F3DE4u;
label_1f3de4:
    // 0x1f3de4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f3de4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f3de8:
    // 0x1f3de8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f3de8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3dec: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1f3decu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1f3df0: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1f3df0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1f3df4: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1f3df4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1f3df8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3DF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F3BECu: goto label_1f3bec;
            case 0x1F3BFCu: goto label_1f3bfc;
            case 0x1F3C00u: goto label_1f3c00;
            case 0x1F3C14u: goto label_1f3c14;
            case 0x1F3C30u: goto label_1f3c30;
            case 0x1F3C40u: goto label_1f3c40;
            case 0x1F3C58u: goto label_1f3c58;
            case 0x1F3C70u: goto label_1f3c70;
            case 0x1F3C78u: goto label_1f3c78;
            case 0x1F3C8Cu: goto label_1f3c8c;
            case 0x1F3CACu: goto label_1f3cac;
            case 0x1F3CC8u: goto label_1f3cc8;
            case 0x1F3CE4u: goto label_1f3ce4;
            case 0x1F3D00u: goto label_1f3d00;
            case 0x1F3D4Cu: goto label_1f3d4c;
            case 0x1F3D58u: goto label_1f3d58;
            case 0x1F3D68u: goto label_1f3d68;
            case 0x1F3D88u: goto label_1f3d88;
            case 0x1F3DACu: goto label_1f3dac;
            case 0x1F3DC4u: goto label_1f3dc4;
            case 0x1F3DD8u: goto label_1f3dd8;
            case 0x1F3DE4u: goto label_1f3de4;
            case 0x1F3DE8u: goto label_1f3de8;
            case 0x1F3E3Cu: goto label_1f3e3c;
            case 0x1F3E40u: goto label_1f3e40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F3E00u;
    // 0x1f3e00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f3e00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f3e04: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f3e04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f3e08: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f3e08u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3e0c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f3e0cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f3e10: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f3e10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f3e14: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f3e14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3e18: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1f3e18u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1f3e1c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f3e1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f3e20: 0x8c430028  lw          $v1, 0x28($v0)
    ctx->pc = 0x1f3e20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x1f3e24: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f3e24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f3e28: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F3E28u;
    {
        const bool branch_taken_0x1f3e28 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f3e28) {
            ctx->pc = 0x1F3E3Cu;
            goto label_1f3e3c;
        }
    }
    ctx->pc = 0x1F3E30u;
    // 0x1f3e30: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1f3e30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f3e34: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F3E34u;
    {
        const bool branch_taken_0x1f3e34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3e34) {
            ctx->pc = 0x1F3E40u;
            goto label_1f3e40;
        }
    }
    ctx->pc = 0x1F3E3Cu;
label_1f3e3c:
    // 0x1f3e3c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f3e3cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f3e40:
    // 0x1f3e40: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f3e40u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3e44: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f3e44u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f3e48: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f3e48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f3e4c: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3E4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F3BECu: goto label_1f3bec;
            case 0x1F3BFCu: goto label_1f3bfc;
            case 0x1F3C00u: goto label_1f3c00;
            case 0x1F3C14u: goto label_1f3c14;
            case 0x1F3C30u: goto label_1f3c30;
            case 0x1F3C40u: goto label_1f3c40;
            case 0x1F3C58u: goto label_1f3c58;
            case 0x1F3C70u: goto label_1f3c70;
            case 0x1F3C78u: goto label_1f3c78;
            case 0x1F3C8Cu: goto label_1f3c8c;
            case 0x1F3CACu: goto label_1f3cac;
            case 0x1F3CC8u: goto label_1f3cc8;
            case 0x1F3CE4u: goto label_1f3ce4;
            case 0x1F3D00u: goto label_1f3d00;
            case 0x1F3D4Cu: goto label_1f3d4c;
            case 0x1F3D58u: goto label_1f3d58;
            case 0x1F3D68u: goto label_1f3d68;
            case 0x1F3D88u: goto label_1f3d88;
            case 0x1F3DACu: goto label_1f3dac;
            case 0x1F3DC4u: goto label_1f3dc4;
            case 0x1F3DD8u: goto label_1f3dd8;
            case 0x1F3DE4u: goto label_1f3de4;
            case 0x1F3DE8u: goto label_1f3de8;
            case 0x1F3E3Cu: goto label_1f3e3c;
            case 0x1F3E40u: goto label_1f3e40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F3E54u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
