#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E8254
// Address: 0x1e8254 - 0x1e8440
void sub_001E8254_0x1e8254(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E8254_0x1e8254");
#endif

    switch (ctx->pc) {
        case 0x1e82a0u: goto label_1e82a0;
        case 0x1e82e8u: goto label_1e82e8;
        case 0x1e8324u: goto label_1e8324;
        case 0x1e8348u: goto label_1e8348;
        case 0x1e8360u: goto label_1e8360;
        case 0x1e8378u: goto label_1e8378;
        case 0x1e839cu: goto label_1e839c;
        case 0x1e83a4u: goto label_1e83a4;
        case 0x1e8408u: goto label_1e8408;
        default: break;
    }

    ctx->pc = 0x1e8254u;

    // 0x1e8254: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e8254u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e8258: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e8258u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e825c: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e825cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e8260: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e8260u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8264: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e8264u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e8268: 0xafc00008  sw          $zero, 0x8($fp)
    ctx->pc = 0x1e8268u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1e826c: 0x8f828028  lw          $v0, -0x7FD8($gp)
    ctx->pc = 0x1e826cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934568)));
    // 0x1e8270: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e8270u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e8274: 0x8f828038  lw          $v0, -0x7FC8($gp)
    ctx->pc = 0x1e8274u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934584)));
    // 0x1e8278: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e8278u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e827c: 0xaf828038  sw          $v0, -0x7FC8($gp)
    ctx->pc = 0x1e827cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934584), GPR_U32(ctx, 2));
    // 0x1e8280: 0x8f828038  lw          $v0, -0x7FC8($gp)
    ctx->pc = 0x1e8280u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934584)));
    // 0x1e8284: 0x28420002  slti        $v0, $v0, 0x2
    ctx->pc = 0x1e8284u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1e8288: 0x10400045  beqz        $v0, . + 4 + (0x45 << 2)
    ctx->pc = 0x1E8288u;
    {
        const bool branch_taken_0x1e8288 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8288) {
            ctx->pc = 0x1E83A0u;
            goto label_1e83a0;
        }
    }
    ctx->pc = 0x1E8290u;
    // 0x1e8290: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e8290u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e8294: 0x10400020  beqz        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x1E8294u;
    {
        const bool branch_taken_0x1e8294 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8294) {
            ctx->pc = 0x1E8318u;
            goto label_1e8318;
        }
    }
    ctx->pc = 0x1E829Cu;
    // 0x1e829c: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1e829cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1e82a0:
    // 0x1e82a0: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e82a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e82a4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e82a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e82a8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e82a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e82ac: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e82acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e82b0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e82b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e82b4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E82B4u;
    {
        const bool branch_taken_0x1e82b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e82b4) {
            ctx->pc = 0x1E82C4u;
            goto label_1e82c4;
        }
    }
    ctx->pc = 0x1E82BCu;
    // 0x1e82bc: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1E82BCu;
    {
        const bool branch_taken_0x1e82bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e82bc) {
            ctx->pc = 0x1E8318u;
            goto label_1e8318;
        }
    }
    ctx->pc = 0x1E82C4u;
label_1e82c4:
    // 0x1e82c4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e82c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e82c8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e82c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e82cc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e82ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e82d0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e82d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e82d4: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1e82d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e82d8: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x1e82d8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x1e82dc: 0x24a58008  addiu       $a1, $a1, -0x7FF8
    ctx->pc = 0x1e82dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294934536));
    // 0x1e82e0: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1E82E0u;
    SET_GPR_U32(ctx, 31, 0x1E82E8u);
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E82E8u; }
        if (ctx->pc != 0x1E82E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E82E8u; }
        if (ctx->pc != 0x1E82E8u) { return; }
    }
    ctx->pc = 0x1E82E8u;
label_1e82e8:
    // 0x1e82e8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E82E8u;
    {
        const bool branch_taken_0x1e82e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e82e8) {
            ctx->pc = 0x1E82F8u;
            goto label_1e82f8;
        }
    }
    ctx->pc = 0x1E82F0u;
    // 0x1e82f0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e82f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e82f4: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e82f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
label_1e82f8:
    // 0x1e82f8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e82f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e82fc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e82fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e8300: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e8300u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e8304: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e8304u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e8308: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e8308u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e830c: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e830cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e8310: 0x1000ffe3  b           . + 4 + (-0x1D << 2)
    ctx->pc = 0x1E8310u;
    {
        const bool branch_taken_0x1e8310 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8310) {
            ctx->pc = 0x1E82A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e82a0;
        }
    }
    ctx->pc = 0x1E8318u;
label_1e8318:
    // 0x1e8318: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1e8318u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e831c: 0xc04042a  jal         func_1010A8
    ctx->pc = 0x1E831Cu;
    SET_GPR_U32(ctx, 31, 0x1E8324u);
    ctx->pc = 0x1010A8u;
    if (runtime->hasFunction(0x1010A8u)) {
        auto targetFn = runtime->lookupFunction(0x1010A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8324u; }
        if (ctx->pc != 0x1E8324u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001010A8_0x1010a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8324u; }
        if (ctx->pc != 0x1E8324u) { return; }
    }
    ctx->pc = 0x1E8324u;
label_1e8324:
    // 0x1e8324: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e8324u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e8328: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e8328u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e832c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E832Cu;
    {
        const bool branch_taken_0x1e832c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e832c) {
            ctx->pc = 0x1E8348u;
            goto label_1e8348;
        }
    }
    ctx->pc = 0x1E8334u;
    // 0x1e8334: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1e8334u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1e8338: 0x24848018  addiu       $a0, $a0, -0x7FE8
    ctx->pc = 0x1e8338u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294934552));
    // 0x1e833c: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e833cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e8340: 0xc045a12  jal         func_116848
    ctx->pc = 0x1E8340u;
    SET_GPR_U32(ctx, 31, 0x1E8348u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8348u; }
        if (ctx->pc != 0x1E8348u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8348u; }
        if (ctx->pc != 0x1E8348u) { return; }
    }
    ctx->pc = 0x1E8348u;
label_1e8348:
    // 0x1e8348: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e8348u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e834c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1E834Cu;
    {
        const bool branch_taken_0x1e834c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e834c) {
            ctx->pc = 0x1E836Cu;
            goto label_1e836c;
        }
    }
    ctx->pc = 0x1E8354u;
    // 0x1e8354: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1e8354u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e8358: 0xc04070e  jal         func_101C38
    ctx->pc = 0x1E8358u;
    SET_GPR_U32(ctx, 31, 0x1E8360u);
    ctx->pc = 0x101C38u;
    if (runtime->hasFunction(0x101C38u)) {
        auto targetFn = runtime->lookupFunction(0x101C38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8360u; }
        if (ctx->pc != 0x1E8360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101C38_0x101c38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8360u; }
        if (ctx->pc != 0x1E8360u) { return; }
    }
    ctx->pc = 0x1E8360u;
label_1e8360:
    // 0x1e8360: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e8360u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e8364: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1E8364u;
    {
        const bool branch_taken_0x1e8364 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8364) {
            ctx->pc = 0x1E837Cu;
            goto label_1e837c;
        }
    }
    ctx->pc = 0x1E836Cu;
label_1e836c:
    // 0x1e836c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1e836cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e8370: 0xc04070e  jal         func_101C38
    ctx->pc = 0x1E8370u;
    SET_GPR_U32(ctx, 31, 0x1E8378u);
    ctx->pc = 0x101C38u;
    if (runtime->hasFunction(0x101C38u)) {
        auto targetFn = runtime->lookupFunction(0x101C38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8378u; }
        if (ctx->pc != 0x1E8378u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101C38_0x101c38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8378u; }
        if (ctx->pc != 0x1E8378u) { return; }
    }
    ctx->pc = 0x1E8378u;
label_1e8378:
    // 0x1e8378: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e8378u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
label_1e837c:
    // 0x1e837c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e837cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e8380: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E8380u;
    {
        const bool branch_taken_0x1e8380 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e8380) {
            ctx->pc = 0x1E839Cu;
            goto label_1e839c;
        }
    }
    ctx->pc = 0x1E8388u;
    // 0x1e8388: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1e8388u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1e838c: 0x24848040  addiu       $a0, $a0, -0x7FC0
    ctx->pc = 0x1e838cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294934592));
    // 0x1e8390: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e8390u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e8394: 0xc045a12  jal         func_116848
    ctx->pc = 0x1E8394u;
    SET_GPR_U32(ctx, 31, 0x1E839Cu);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E839Cu; }
        if (ctx->pc != 0x1E839Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E839Cu; }
        if (ctx->pc != 0x1E839Cu) { return; }
    }
    ctx->pc = 0x1E839Cu;
label_1e839c:
    // 0x1e839c: 0xff808030  sd          $zero, -0x7FD0($gp)
    ctx->pc = 0x1e839cu;
    WRITE64(ADD32(GPR_U32(ctx, 28), 4294934576), GPR_U64(ctx, 0));
label_1e83a0:
    // 0x1e83a0: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1e83a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1e83a4:
    // 0x1e83a4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e83a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e83a8: 0x28420040  slti        $v0, $v0, 0x40
    ctx->pc = 0x1e83a8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x1e83ac: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E83ACu;
    {
        const bool branch_taken_0x1e83ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e83ac) {
            ctx->pc = 0x1E83BCu;
            goto label_1e83bc;
        }
    }
    ctx->pc = 0x1E83B4u;
    // 0x1e83b4: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1E83B4u;
    {
        const bool branch_taken_0x1e83b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e83b4) {
            ctx->pc = 0x1E8428u;
            goto label_1e8428;
        }
    }
    ctx->pc = 0x1E83BCu;
label_1e83bc:
    // 0x1e83bc: 0x8f828038  lw          $v0, -0x7FC8($gp)
    ctx->pc = 0x1e83bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934584)));
    // 0x1e83c0: 0x28420002  slti        $v0, $v0, 0x2
    ctx->pc = 0x1e83c0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1e83c4: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1E83C4u;
    {
        const bool branch_taken_0x1e83c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e83c4) {
            ctx->pc = 0x1E83F0u;
            goto label_1e83f0;
        }
    }
    ctx->pc = 0x1E83CCu;
    // 0x1e83cc: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e83ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e83d0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e83d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e83d4: 0xa4620000  sh          $v0, 0x0($v1)
    ctx->pc = 0x1e83d4u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e83d8: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e83d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e83dc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e83dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e83e0: 0xa4620002  sh          $v0, 0x2($v1)
    ctx->pc = 0x1e83e0u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e83e4: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e83e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e83e8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e83e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e83ec: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1e83ecu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
label_1e83f0:
    // 0x1e83f0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e83f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e83f4: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e83f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e83f8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e83f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e83fc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e83fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8400: 0xc07c417  jal         func_1F105C
    ctx->pc = 0x1E8400u;
    SET_GPR_U32(ctx, 31, 0x1E8408u);
    ctx->pc = 0x1F105Cu;
    if (runtime->hasFunction(0x1F105Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F105Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8408u; }
        if (ctx->pc != 0x1E8408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F105C_0x1f105c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8408u; }
        if (ctx->pc != 0x1E8408u) { return; }
    }
    ctx->pc = 0x1E8408u;
label_1e8408:
    // 0x1e8408: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e8408u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e840c: 0x24420024  addiu       $v0, $v0, 0x24
    ctx->pc = 0x1e840cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x1e8410: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e8410u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e8414: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e8414u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e8418: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e8418u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e841c: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e841cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e8420: 0x1000ffe0  b           . + 4 + (-0x20 << 2)
    ctx->pc = 0x1E8420u;
    {
        const bool branch_taken_0x1e8420 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8420) {
            ctx->pc = 0x1E83A4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e83a4;
        }
    }
    ctx->pc = 0x1E8428u;
label_1e8428:
    // 0x1e8428: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e8428u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e842c: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e842cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e8430: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e8430u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e8434: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e8434u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e8438: 0x3e00008  jr          $ra
    ctx->pc = 0x1E8438u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E82A0u: goto label_1e82a0;
            case 0x1E82C4u: goto label_1e82c4;
            case 0x1E82E8u: goto label_1e82e8;
            case 0x1E82F8u: goto label_1e82f8;
            case 0x1E8318u: goto label_1e8318;
            case 0x1E8324u: goto label_1e8324;
            case 0x1E8348u: goto label_1e8348;
            case 0x1E8360u: goto label_1e8360;
            case 0x1E836Cu: goto label_1e836c;
            case 0x1E8378u: goto label_1e8378;
            case 0x1E837Cu: goto label_1e837c;
            case 0x1E839Cu: goto label_1e839c;
            case 0x1E83A0u: goto label_1e83a0;
            case 0x1E83A4u: goto label_1e83a4;
            case 0x1E83BCu: goto label_1e83bc;
            case 0x1E83F0u: goto label_1e83f0;
            case 0x1E8408u: goto label_1e8408;
            case 0x1E8428u: goto label_1e8428;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E8440u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
