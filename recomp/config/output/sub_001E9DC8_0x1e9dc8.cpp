#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E9DC8
// Address: 0x1e9dc8 - 0x1e9ee0
void sub_001E9DC8_0x1e9dc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E9DC8_0x1e9dc8");
#endif

    switch (ctx->pc) {
        case 0x1e9de4u: goto label_1e9de4;
        case 0x1e9df4u: goto label_1e9df4;
        case 0x1e9e0cu: goto label_1e9e0c;
        case 0x1e9e4cu: goto label_1e9e4c;
        case 0x1e9e7cu: goto label_1e9e7c;
        case 0x1e9e84u: goto label_1e9e84;
        case 0x1e9e8cu: goto label_1e9e8c;
        case 0x1e9ea0u: goto label_1e9ea0;
        case 0x1e9ec4u: goto label_1e9ec4;
        default: break;
    }

    ctx->pc = 0x1e9dc8u;

    // 0x1e9dc8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e9dc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e9dcc: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e9dccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e9dd0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e9dd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e9dd4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e9dd4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9dd8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e9dd8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e9ddc: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E9DDCu;
    SET_GPR_U32(ctx, 31, 0x1E9DE4u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9DE4u; }
        if (ctx->pc != 0x1E9DE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9DE4u; }
        if (ctx->pc != 0x1E9DE4u) { return; }
    }
    ctx->pc = 0x1E9DE4u;
label_1e9de4:
    // 0x1e9de4: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1e9de4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1e9de8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e9de8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e9dec: 0xc07a216  jal         func_1E8858
    ctx->pc = 0x1E9DECu;
    SET_GPR_U32(ctx, 31, 0x1E9DF4u);
    ctx->pc = 0x1E8858u;
    if (runtime->hasFunction(0x1E8858u)) {
        auto targetFn = runtime->lookupFunction(0x1E8858u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9DF4u; }
        if (ctx->pc != 0x1E9DF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8858_0x1e8858(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9DF4u; }
        if (ctx->pc != 0x1E9DF4u) { return; }
    }
    ctx->pc = 0x1E9DF4u;
label_1e9df4:
    // 0x1e9df4: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e9df4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e9df8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e9df8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9dfc: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E9DFCu;
    {
        const bool branch_taken_0x1e9dfc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e9dfc) {
            ctx->pc = 0x1E9E24u;
            goto label_1e9e24;
        }
    }
    ctx->pc = 0x1E9E04u;
    // 0x1e9e04: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E9E04u;
    SET_GPR_U32(ctx, 31, 0x1E9E0Cu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9E0Cu; }
        if (ctx->pc != 0x1E9E0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9E0Cu; }
        if (ctx->pc != 0x1E9E0Cu) { return; }
    }
    ctx->pc = 0x1E9E0Cu;
label_1e9e0c:
    // 0x1e9e0c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e9e0cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9e10: 0x2402006c  addiu       $v0, $zero, 0x6C
    ctx->pc = 0x1e9e10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1e9e14: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e9e14u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e9e18: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e9e18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e9e1c: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1E9E1Cu;
    {
        const bool branch_taken_0x1e9e1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9e1c) {
            ctx->pc = 0x1E9EC8u;
            goto label_1e9ec8;
        }
    }
    ctx->pc = 0x1E9E24u;
label_1e9e24:
    // 0x1e9e24: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e9e24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9e28: 0x94430002  lhu         $v1, 0x2($v0)
    ctx->pc = 0x1e9e28u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e9e2c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e9e2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e9e30: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E9E30u;
    {
        const bool branch_taken_0x1e9e30 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e9e30) {
            ctx->pc = 0x1E9E60u;
            goto label_1e9e60;
        }
    }
    ctx->pc = 0x1E9E38u;
    // 0x1e9e38: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e9e38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9e3c: 0x84420000  lh          $v0, 0x0($v0)
    ctx->pc = 0x1e9e3cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e9e40: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e9e40u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9e44: 0xc075f18  jal         func_1D7C60
    ctx->pc = 0x1E9E44u;
    SET_GPR_U32(ctx, 31, 0x1E9E4Cu);
    ctx->pc = 0x1D7C60u;
    if (runtime->hasFunction(0x1D7C60u)) {
        auto targetFn = runtime->lookupFunction(0x1D7C60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9E4Cu; }
        if (ctx->pc != 0x1E9E4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7C60_0x1d7c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9E4Cu; }
        if (ctx->pc != 0x1E9E4Cu) { return; }
    }
    ctx->pc = 0x1E9E4Cu;
label_1e9e4c:
    // 0x1e9e4c: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e9e4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9e50: 0x24020ff3  addiu       $v0, $zero, 0xFF3
    ctx->pc = 0x1e9e50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4083));
    // 0x1e9e54: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1e9e54u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e9e58: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1E9E58u;
    {
        const bool branch_taken_0x1e9e58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9e58) {
            ctx->pc = 0x1E9EB8u;
            goto label_1e9eb8;
        }
    }
    ctx->pc = 0x1E9E60u;
label_1e9e60:
    // 0x1e9e60: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e9e60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9e64: 0x94430002  lhu         $v1, 0x2($v0)
    ctx->pc = 0x1e9e64u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e9e68: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e9e68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e9e6c: 0x14620012  bne         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1E9E6Cu;
    {
        const bool branch_taken_0x1e9e6c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e9e6c) {
            ctx->pc = 0x1E9EB8u;
            goto label_1e9eb8;
        }
    }
    ctx->pc = 0x1E9E74u;
    // 0x1e9e74: 0xc07a61b  jal         func_1E986C
    ctx->pc = 0x1E9E74u;
    SET_GPR_U32(ctx, 31, 0x1E9E7Cu);
    ctx->pc = 0x1E986Cu;
    if (runtime->hasFunction(0x1E986Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E986Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9E7Cu; }
        if (ctx->pc != 0x1E9E7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E986C_0x1e986c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9E7Cu; }
        if (ctx->pc != 0x1E9E7Cu) { return; }
    }
    ctx->pc = 0x1E9E7Cu;
label_1e9e7c:
    // 0x1e9e7c: 0xc07a61b  jal         func_1E986C
    ctx->pc = 0x1E9E7Cu;
    SET_GPR_U32(ctx, 31, 0x1E9E84u);
    ctx->pc = 0x1E986Cu;
    if (runtime->hasFunction(0x1E986Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E986Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9E84u; }
        if (ctx->pc != 0x1E9E84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E986C_0x1e986c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9E84u; }
        if (ctx->pc != 0x1E9E84u) { return; }
    }
    ctx->pc = 0x1E9E84u;
label_1e9e84:
    // 0x1e9e84: 0xc07a61b  jal         func_1E986C
    ctx->pc = 0x1E9E84u;
    SET_GPR_U32(ctx, 31, 0x1E9E8Cu);
    ctx->pc = 0x1E986Cu;
    if (runtime->hasFunction(0x1E986Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E986Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9E8Cu; }
        if (ctx->pc != 0x1E9E8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E986C_0x1e986c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9E8Cu; }
        if (ctx->pc != 0x1E9E8Cu) { return; }
    }
    ctx->pc = 0x1E9E8Cu;
label_1e9e8c:
    // 0x1e9e8c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e9e8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9e90: 0x84420000  lh          $v0, 0x0($v0)
    ctx->pc = 0x1e9e90u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e9e94: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e9e94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9e98: 0xc0761c8  jal         func_1D8720
    ctx->pc = 0x1E9E98u;
    SET_GPR_U32(ctx, 31, 0x1E9EA0u);
    ctx->pc = 0x1D8720u;
    if (runtime->hasFunction(0x1D8720u)) {
        auto targetFn = runtime->lookupFunction(0x1D8720u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9EA0u; }
        if (ctx->pc != 0x1E9EA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8720_0x1d8720(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9EA0u; }
        if (ctx->pc != 0x1E9EA0u) { return; }
    }
    ctx->pc = 0x1E9EA0u;
label_1e9ea0:
    // 0x1e9ea0: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e9ea0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9ea4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e9ea4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e9ea8: 0xa4620002  sh          $v0, 0x2($v1)
    ctx->pc = 0x1e9ea8u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e9eac: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e9eacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9eb0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e9eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e9eb4: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1e9eb4u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
label_1e9eb8:
    // 0x1e9eb8: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e9eb8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9ebc: 0xc07a121  jal         func_1E8484
    ctx->pc = 0x1E9EBCu;
    SET_GPR_U32(ctx, 31, 0x1E9EC4u);
    ctx->pc = 0x1E8484u;
    if (runtime->hasFunction(0x1E8484u)) {
        auto targetFn = runtime->lookupFunction(0x1E8484u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9EC4u; }
        if (ctx->pc != 0x1E9EC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8484_0x1e8484(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9EC4u; }
        if (ctx->pc != 0x1E9EC4u) { return; }
    }
    ctx->pc = 0x1E9EC4u;
label_1e9ec4:
    // 0x1e9ec4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e9ec4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e9ec8:
    // 0x1e9ec8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e9ec8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9ecc: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e9eccu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e9ed0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e9ed0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e9ed4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e9ed4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e9ed8: 0x3e00008  jr          $ra
    ctx->pc = 0x1E9ED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E9DE4u: goto label_1e9de4;
            case 0x1E9DF4u: goto label_1e9df4;
            case 0x1E9E0Cu: goto label_1e9e0c;
            case 0x1E9E24u: goto label_1e9e24;
            case 0x1E9E4Cu: goto label_1e9e4c;
            case 0x1E9E60u: goto label_1e9e60;
            case 0x1E9E7Cu: goto label_1e9e7c;
            case 0x1E9E84u: goto label_1e9e84;
            case 0x1E9E8Cu: goto label_1e9e8c;
            case 0x1E9EA0u: goto label_1e9ea0;
            case 0x1E9EB8u: goto label_1e9eb8;
            case 0x1E9EC4u: goto label_1e9ec4;
            case 0x1E9EC8u: goto label_1e9ec8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E9EE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
