#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E8E2C
// Address: 0x1e8e2c - 0x1e8f30
void sub_001E8E2C_0x1e8e2c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E8E2C_0x1e8e2c");
#endif

    switch (ctx->pc) {
        case 0x1e8e4cu: goto label_1e8e4c;
        case 0x1e8e5cu: goto label_1e8e5c;
        case 0x1e8e74u: goto label_1e8e74;
        case 0x1e8ea8u: goto label_1e8ea8;
        case 0x1e8ee0u: goto label_1e8ee0;
        default: break;
    }

    ctx->pc = 0x1e8e2cu;

    // 0x1e8e2c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e8e2cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e8e30: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e8e30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e8e34: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e8e34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e8e38: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e8e38u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8e3c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e8e3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e8e40: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e8e40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e8e44: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8E44u;
    SET_GPR_U32(ctx, 31, 0x1E8E4Cu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8E4Cu; }
        if (ctx->pc != 0x1E8E4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8E4Cu; }
        if (ctx->pc != 0x1E8E4Cu) { return; }
    }
    ctx->pc = 0x1E8E4Cu;
label_1e8e4c:
    // 0x1e8e4c: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1e8e4cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1e8e50: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e8e50u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e8e54: 0xc07a216  jal         func_1E8858
    ctx->pc = 0x1E8E54u;
    SET_GPR_U32(ctx, 31, 0x1E8E5Cu);
    ctx->pc = 0x1E8858u;
    if (runtime->hasFunction(0x1E8858u)) {
        auto targetFn = runtime->lookupFunction(0x1E8858u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8E5Cu; }
        if (ctx->pc != 0x1E8E5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8858_0x1e8858(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8E5Cu; }
        if (ctx->pc != 0x1E8E5Cu) { return; }
    }
    ctx->pc = 0x1E8E5Cu;
label_1e8e5c:
    // 0x1e8e5c: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e8e5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e8e60: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e8e60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8e64: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E8E64u;
    {
        const bool branch_taken_0x1e8e64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e8e64) {
            ctx->pc = 0x1E8E8Cu;
            goto label_1e8e8c;
        }
    }
    ctx->pc = 0x1E8E6Cu;
    // 0x1e8e6c: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8E6Cu;
    SET_GPR_U32(ctx, 31, 0x1E8E74u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8E74u; }
        if (ctx->pc != 0x1E8E74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8E74u; }
        if (ctx->pc != 0x1E8E74u) { return; }
    }
    ctx->pc = 0x1E8E74u;
label_1e8e74:
    // 0x1e8e74: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e8e74u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8e78: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e8e78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e8e7c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e8e7cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8e80: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8e80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8e84: 0x10000024  b           . + 4 + (0x24 << 2)
    ctx->pc = 0x1E8E84u;
    {
        const bool branch_taken_0x1e8e84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8e84) {
            ctx->pc = 0x1E8F18u;
            goto label_1e8f18;
        }
    }
    ctx->pc = 0x1E8E8Cu;
label_1e8e8c:
    // 0x1e8e8c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e8e8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8e90: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e8e90u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e8e94: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1e8e94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1e8e98: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E8E98u;
    {
        const bool branch_taken_0x1e8e98 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e8e98) {
            ctx->pc = 0x1E8EC0u;
            goto label_1e8ec0;
        }
    }
    ctx->pc = 0x1E8EA0u;
    // 0x1e8ea0: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8EA0u;
    SET_GPR_U32(ctx, 31, 0x1E8EA8u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8EA8u; }
        if (ctx->pc != 0x1E8EA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8EA8u; }
        if (ctx->pc != 0x1E8EA8u) { return; }
    }
    ctx->pc = 0x1E8EA8u;
label_1e8ea8:
    // 0x1e8ea8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e8ea8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8eac: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e8eacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e8eb0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e8eb0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8eb4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8eb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8eb8: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1E8EB8u;
    {
        const bool branch_taken_0x1e8eb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8eb8) {
            ctx->pc = 0x1E8F18u;
            goto label_1e8f18;
        }
    }
    ctx->pc = 0x1E8EC0u;
label_1e8ec0:
    // 0x1e8ec0: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e8ec0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8ec4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e8ec4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8ec8: 0x94420020  lhu         $v0, 0x20($v0)
    ctx->pc = 0x1e8ec8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1e8ecc: 0x8c64001c  lw          $a0, 0x1C($v1)
    ctx->pc = 0x1e8eccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1e8ed0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e8ed0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8ed4: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1e8ed4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8ed8: 0xc075ee0  jal         func_1D7B80
    ctx->pc = 0x1E8ED8u;
    SET_GPR_U32(ctx, 31, 0x1E8EE0u);
    ctx->pc = 0x1D7B80u;
    if (runtime->hasFunction(0x1D7B80u)) {
        auto targetFn = runtime->lookupFunction(0x1D7B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8EE0u; }
        if (ctx->pc != 0x1E8EE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7B80_0x1d7b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8EE0u; }
        if (ctx->pc != 0x1E8EE0u) { return; }
    }
    ctx->pc = 0x1E8EE0u;
label_1e8ee0:
    // 0x1e8ee0: 0xa7c20008  sh          $v0, 0x8($fp)
    ctx->pc = 0x1e8ee0u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8ee4: 0x87c20008  lh          $v0, 0x8($fp)
    ctx->pc = 0x1e8ee4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e8ee8: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1E8EE8u;
    {
        const bool branch_taken_0x1e8ee8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1e8ee8) {
            ctx->pc = 0x1E8EFCu;
            goto label_1e8efc;
        }
    }
    ctx->pc = 0x1E8EF0u;
    // 0x1e8ef0: 0x87c20008  lh          $v0, 0x8($fp)
    ctx->pc = 0x1e8ef0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e8ef4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1E8EF4u;
    {
        const bool branch_taken_0x1e8ef4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8ef4) {
            ctx->pc = 0x1E8F18u;
            goto label_1e8f18;
        }
    }
    ctx->pc = 0x1E8EFCu;
label_1e8efc:
    // 0x1e8efc: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e8efcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8f00: 0x24020ff5  addiu       $v0, $zero, 0xFF5
    ctx->pc = 0x1e8f00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4085));
    // 0x1e8f04: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1e8f04u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8f08: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e8f08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8f0c: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e8f0cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e8f10: 0xa4620000  sh          $v0, 0x0($v1)
    ctx->pc = 0x1e8f10u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8f14: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e8f14u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e8f18:
    // 0x1e8f18: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e8f18u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8f1c: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e8f1cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e8f20: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e8f20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e8f24: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e8f24u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e8f28: 0x3e00008  jr          $ra
    ctx->pc = 0x1E8F28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E8E4Cu: goto label_1e8e4c;
            case 0x1E8E5Cu: goto label_1e8e5c;
            case 0x1E8E74u: goto label_1e8e74;
            case 0x1E8E8Cu: goto label_1e8e8c;
            case 0x1E8EA8u: goto label_1e8ea8;
            case 0x1E8EC0u: goto label_1e8ec0;
            case 0x1E8EE0u: goto label_1e8ee0;
            case 0x1E8EFCu: goto label_1e8efc;
            case 0x1E8F18u: goto label_1e8f18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E8F30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
