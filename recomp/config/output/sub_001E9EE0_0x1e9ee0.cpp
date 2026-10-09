#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E9EE0
// Address: 0x1e9ee0 - 0x1ea000
void sub_001E9EE0_0x1e9ee0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E9EE0_0x1e9ee0");
#endif

    switch (ctx->pc) {
        case 0x1e9f0cu: goto label_1e9f0c;
        case 0x1e9f24u: goto label_1e9f24;
        case 0x1e9f58u: goto label_1e9f58;
        case 0x1e9f8cu: goto label_1e9f8c;
        case 0x1e9fb8u: goto label_1e9fb8;
        case 0x1e9fd4u: goto label_1e9fd4;
        default: break;
    }

    ctx->pc = 0x1e9ee0u;

    // 0x1e9ee0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e9ee0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e9ee4: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e9ee4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e9ee8: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e9ee8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e9eec: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e9eecu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9ef0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e9ef0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e9ef4: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e9ef4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e9ef8: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e9ef8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e9efc: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e9efcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e9f00: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e9f00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e9f04: 0xc07a216  jal         func_1E8858
    ctx->pc = 0x1E9F04u;
    SET_GPR_U32(ctx, 31, 0x1E9F0Cu);
    ctx->pc = 0x1E8858u;
    if (runtime->hasFunction(0x1E8858u)) {
        auto targetFn = runtime->lookupFunction(0x1E8858u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9F0Cu; }
        if (ctx->pc != 0x1E9F0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8858_0x1e8858(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9F0Cu; }
        if (ctx->pc != 0x1E9F0Cu) { return; }
    }
    ctx->pc = 0x1E9F0Cu;
label_1e9f0c:
    // 0x1e9f0c: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e9f0cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e9f10: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e9f10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e9f14: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E9F14u;
    {
        const bool branch_taken_0x1e9f14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e9f14) {
            ctx->pc = 0x1E9F3Cu;
            goto label_1e9f3c;
        }
    }
    ctx->pc = 0x1E9F1Cu;
    // 0x1e9f1c: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E9F1Cu;
    SET_GPR_U32(ctx, 31, 0x1E9F24u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9F24u; }
        if (ctx->pc != 0x1E9F24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9F24u; }
        if (ctx->pc != 0x1E9F24u) { return; }
    }
    ctx->pc = 0x1E9F24u;
label_1e9f24:
    // 0x1e9f24: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e9f24u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9f28: 0x2402006c  addiu       $v0, $zero, 0x6C
    ctx->pc = 0x1e9f28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1e9f2c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e9f2cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e9f30: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e9f30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e9f34: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x1E9F34u;
    {
        const bool branch_taken_0x1e9f34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9f34) {
            ctx->pc = 0x1E9FE8u;
            goto label_1e9fe8;
        }
    }
    ctx->pc = 0x1E9F3Cu;
label_1e9f3c:
    // 0x1e9f3c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e9f3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e9f40: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e9f40u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e9f44: 0x2402007f  addiu       $v0, $zero, 0x7F
    ctx->pc = 0x1e9f44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1e9f48: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E9F48u;
    {
        const bool branch_taken_0x1e9f48 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e9f48) {
            ctx->pc = 0x1E9F70u;
            goto label_1e9f70;
        }
    }
    ctx->pc = 0x1E9F50u;
    // 0x1e9f50: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E9F50u;
    SET_GPR_U32(ctx, 31, 0x1E9F58u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9F58u; }
        if (ctx->pc != 0x1E9F58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9F58u; }
        if (ctx->pc != 0x1E9F58u) { return; }
    }
    ctx->pc = 0x1E9F58u;
label_1e9f58:
    // 0x1e9f58: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e9f58u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9f5c: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1e9f5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1e9f60: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e9f60u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e9f64: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e9f64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e9f68: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1E9F68u;
    {
        const bool branch_taken_0x1e9f68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9f68) {
            ctx->pc = 0x1E9FE8u;
            goto label_1e9fe8;
        }
    }
    ctx->pc = 0x1E9F70u;
label_1e9f70:
    // 0x1e9f70: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e9f70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9f74: 0x3c027104  lui         $v0, 0x7104
    ctx->pc = 0x1e9f74u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28932 << 16));
    // 0x1e9f78: 0x34425ead  ori         $v0, $v0, 0x5EAD
    ctx->pc = 0x1e9f78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)24237);
    // 0x1e9f7c: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E9F7Cu;
    {
        const bool branch_taken_0x1e9f7c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e9f7c) {
            ctx->pc = 0x1E9FA4u;
            goto label_1e9fa4;
        }
    }
    ctx->pc = 0x1E9F84u;
    // 0x1e9f84: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E9F84u;
    SET_GPR_U32(ctx, 31, 0x1E9F8Cu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9F8Cu; }
        if (ctx->pc != 0x1E9F8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9F8Cu; }
        if (ctx->pc != 0x1E9F8Cu) { return; }
    }
    ctx->pc = 0x1E9F8Cu;
label_1e9f8c:
    // 0x1e9f8c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e9f8cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9f90: 0x24020016  addiu       $v0, $zero, 0x16
    ctx->pc = 0x1e9f90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x1e9f94: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e9f94u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e9f98: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e9f98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e9f9c: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1E9F9Cu;
    {
        const bool branch_taken_0x1e9f9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9f9c) {
            ctx->pc = 0x1E9FE8u;
            goto label_1e9fe8;
        }
    }
    ctx->pc = 0x1E9FA4u;
label_1e9fa4:
    // 0x1e9fa4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e9fa4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e9fa8: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e9fa8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e9fac: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e9facu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9fb0: 0xc07c6e1  jal         func_1F1B84
    ctx->pc = 0x1E9FB0u;
    SET_GPR_U32(ctx, 31, 0x1E9FB8u);
    ctx->pc = 0x1F1B84u;
    if (runtime->hasFunction(0x1F1B84u)) {
        auto targetFn = runtime->lookupFunction(0x1F1B84u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9FB8u; }
        if (ctx->pc != 0x1E9FB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1B84_0x1f1b84(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9FB8u; }
        if (ctx->pc != 0x1E9FB8u) { return; }
    }
    ctx->pc = 0x1E9FB8u;
label_1e9fb8:
    // 0x1e9fb8: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e9fb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e9fbc: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e9fbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e9fc0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1E9FC0u;
    {
        const bool branch_taken_0x1e9fc0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9fc0) {
            ctx->pc = 0x1E9FD8u;
            goto label_1e9fd8;
        }
    }
    ctx->pc = 0x1E9FC8u;
    // 0x1e9fc8: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e9fc8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e9fcc: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1E9FCCu;
    SET_GPR_U32(ctx, 31, 0x1E9FD4u);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9FD4u; }
        if (ctx->pc != 0x1E9FD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9FD4u; }
        if (ctx->pc != 0x1E9FD4u) { return; }
    }
    ctx->pc = 0x1E9FD4u;
label_1e9fd4:
    // 0x1e9fd4: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e9fd4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
label_1e9fd8:
    // 0x1e9fd8: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e9fd8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e9fdc: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e9fdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9fe0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e9fe0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e9fe4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e9fe4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e9fe8:
    // 0x1e9fe8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e9fe8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9fec: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e9fecu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e9ff0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e9ff0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e9ff4: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e9ff4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e9ff8: 0x3e00008  jr          $ra
    ctx->pc = 0x1E9FF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E9F0Cu: goto label_1e9f0c;
            case 0x1E9F24u: goto label_1e9f24;
            case 0x1E9F3Cu: goto label_1e9f3c;
            case 0x1E9F58u: goto label_1e9f58;
            case 0x1E9F70u: goto label_1e9f70;
            case 0x1E9F8Cu: goto label_1e9f8c;
            case 0x1E9FA4u: goto label_1e9fa4;
            case 0x1E9FB8u: goto label_1e9fb8;
            case 0x1E9FD4u: goto label_1e9fd4;
            case 0x1E9FD8u: goto label_1e9fd8;
            case 0x1E9FE8u: goto label_1e9fe8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1EA000u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
