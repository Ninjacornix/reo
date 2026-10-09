#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E853C
// Address: 0x1e853c - 0x1e8758
void sub_001E853C_0x1e853c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E853C_0x1e853c");
#endif

    switch (ctx->pc) {
        case 0x1e8560u: goto label_1e8560;
        case 0x1e857cu: goto label_1e857c;
        case 0x1e85ccu: goto label_1e85cc;
        case 0x1e8600u: goto label_1e8600;
        case 0x1e866cu: goto label_1e866c;
        case 0x1e86ccu: goto label_1e86cc;
        case 0x1e873cu: goto label_1e873c;
        default: break;
    }

    ctx->pc = 0x1e853cu;

    // 0x1e853c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1e853cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1e8540: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e8540u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e8544: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e8544u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e8548: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e8548u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e854c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e854cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e8550: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e8550u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e8554: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e8554u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e8558: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8558u;
    SET_GPR_U32(ctx, 31, 0x1E8560u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8560u; }
        if (ctx->pc != 0x1E8560u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8560u; }
        if (ctx->pc != 0x1E8560u) { return; }
    }
    ctx->pc = 0x1E8560u;
label_1e8560:
    // 0x1e8560: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1e8560u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1e8564: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e8564u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e8568: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e8568u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e856c: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E856Cu;
    {
        const bool branch_taken_0x1e856c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e856c) {
            ctx->pc = 0x1E8594u;
            goto label_1e8594;
        }
    }
    ctx->pc = 0x1E8574u;
    // 0x1e8574: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8574u;
    SET_GPR_U32(ctx, 31, 0x1E857Cu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E857Cu; }
        if (ctx->pc != 0x1E857Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E857Cu; }
        if (ctx->pc != 0x1E857Cu) { return; }
    }
    ctx->pc = 0x1E857Cu;
label_1e857c:
    // 0x1e857c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e857cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8580: 0x24020060  addiu       $v0, $zero, 0x60
    ctx->pc = 0x1e8580u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
    // 0x1e8584: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e8584u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8588: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8588u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e858c: 0x1000006c  b           . + 4 + (0x6C << 2)
    ctx->pc = 0x1E858Cu;
    {
        const bool branch_taken_0x1e858c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e858c) {
            ctx->pc = 0x1E8740u;
            goto label_1e8740;
        }
    }
    ctx->pc = 0x1E8594u;
label_1e8594:
    // 0x1e8594: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e8594u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e8598: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e8598u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e859c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e859cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e85a0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e85a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e85a4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e85a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e85a8: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1e85a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e85ac: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1E85ACu;
    {
        const bool branch_taken_0x1e85ac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e85ac) {
            ctx->pc = 0x1E85E4u;
            goto label_1e85e4;
        }
    }
    ctx->pc = 0x1E85B4u;
    // 0x1e85b4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e85b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e85b8: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1e85b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e85bc: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1E85BCu;
    {
        const bool branch_taken_0x1e85bc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e85bc) {
            ctx->pc = 0x1E85F4u;
            goto label_1e85f4;
        }
    }
    ctx->pc = 0x1E85C4u;
    // 0x1e85c4: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E85C4u;
    SET_GPR_U32(ctx, 31, 0x1E85CCu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E85CCu; }
        if (ctx->pc != 0x1E85CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E85CCu; }
        if (ctx->pc != 0x1E85CCu) { return; }
    }
    ctx->pc = 0x1E85CCu;
label_1e85cc:
    // 0x1e85cc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e85ccu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e85d0: 0x2402006d  addiu       $v0, $zero, 0x6D
    ctx->pc = 0x1e85d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 109));
    // 0x1e85d4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e85d4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e85d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e85d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e85dc: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x1E85DCu;
    {
        const bool branch_taken_0x1e85dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e85dc) {
            ctx->pc = 0x1E8740u;
            goto label_1e8740;
        }
    }
    ctx->pc = 0x1E85E4u;
label_1e85e4:
    // 0x1e85e4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e85e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e85e8: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e85e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e85ec: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1E85ECu;
    {
        const bool branch_taken_0x1e85ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e85ec) {
            ctx->pc = 0x1E85FCu;
            goto label_1e85fc;
        }
    }
    ctx->pc = 0x1E85F4u;
label_1e85f4:
    // 0x1e85f4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e85f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e85f8: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e85f8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
label_1e85fc:
    // 0x1e85fc: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e85fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
label_1e8600:
    // 0x1e8600: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e8600u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e8604: 0x28420040  slti        $v0, $v0, 0x40
    ctx->pc = 0x1e8604u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x1e8608: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E8608u;
    {
        const bool branch_taken_0x1e8608 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e8608) {
            ctx->pc = 0x1E8618u;
            goto label_1e8618;
        }
    }
    ctx->pc = 0x1E8610u;
    // 0x1e8610: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1E8610u;
    {
        const bool branch_taken_0x1e8610 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8610) {
            ctx->pc = 0x1E86B4u;
            goto label_1e86b4;
        }
    }
    ctx->pc = 0x1E8618u;
label_1e8618:
    // 0x1e8618: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e8618u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e861c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e861cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8620: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e8620u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e8624: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e8624u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e8628: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e8628u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e862c: 0x8f828028  lw          $v0, -0x7FD8($gp)
    ctx->pc = 0x1e862cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934568)));
    // 0x1e8630: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e8630u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e8634: 0x94430002  lhu         $v1, 0x2($v0)
    ctx->pc = 0x1e8634u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e8638: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e8638u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e863c: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E863Cu;
    {
        const bool branch_taken_0x1e863c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e863c) {
            ctx->pc = 0x1E866Cu;
            goto label_1e866c;
        }
    }
    ctx->pc = 0x1E8644u;
    // 0x1e8644: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e8644u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e8648: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e8648u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e864c: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e864cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e8650: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e8650u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e8654: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e8654u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e8658: 0x8f828028  lw          $v0, -0x7FD8($gp)
    ctx->pc = 0x1e8658u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934568)));
    // 0x1e865c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e865cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e8660: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e8660u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8664: 0xc07aa87  jal         func_1EAA1C
    ctx->pc = 0x1E8664u;
    SET_GPR_U32(ctx, 31, 0x1E866Cu);
    ctx->pc = 0x1EAA1Cu;
    if (runtime->hasFunction(0x1EAA1Cu)) {
        auto targetFn = runtime->lookupFunction(0x1EAA1Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E866Cu; }
        if (ctx->pc != 0x1E866Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EAA1C_0x1eaa1c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E866Cu; }
        if (ctx->pc != 0x1E866Cu) { return; }
    }
    ctx->pc = 0x1E866Cu;
label_1e866c:
    // 0x1e866c: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e866cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e8670: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e8670u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8674: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e8674u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e8678: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e8678u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e867c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e867cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e8680: 0x8f828028  lw          $v0, -0x7FD8($gp)
    ctx->pc = 0x1e8680u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934568)));
    // 0x1e8684: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e8684u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e8688: 0x94430002  lhu         $v1, 0x2($v0)
    ctx->pc = 0x1e8688u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e868c: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1e868cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1e8690: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E8690u;
    {
        const bool branch_taken_0x1e8690 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e8690) {
            ctx->pc = 0x1E86A0u;
            goto label_1e86a0;
        }
    }
    ctx->pc = 0x1E8698u;
    // 0x1e8698: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1E8698u;
    {
        const bool branch_taken_0x1e8698 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8698) {
            ctx->pc = 0x1E86B4u;
            goto label_1e86b4;
        }
    }
    ctx->pc = 0x1E86A0u;
label_1e86a0:
    // 0x1e86a0: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e86a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e86a4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e86a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e86a8: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e86a8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e86ac: 0x1000ffd4  b           . + 4 + (-0x2C << 2)
    ctx->pc = 0x1E86ACu;
    {
        const bool branch_taken_0x1e86ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e86ac) {
            ctx->pc = 0x1E8600u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e8600;
        }
    }
    ctx->pc = 0x1E86B4u;
label_1e86b4:
    // 0x1e86b4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e86b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e86b8: 0x28420040  slti        $v0, $v0, 0x40
    ctx->pc = 0x1e86b8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x1e86bc: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E86BCu;
    {
        const bool branch_taken_0x1e86bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e86bc) {
            ctx->pc = 0x1E86E4u;
            goto label_1e86e4;
        }
    }
    ctx->pc = 0x1E86C4u;
    // 0x1e86c4: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E86C4u;
    SET_GPR_U32(ctx, 31, 0x1E86CCu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E86CCu; }
        if (ctx->pc != 0x1E86CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E86CCu; }
        if (ctx->pc != 0x1E86CCu) { return; }
    }
    ctx->pc = 0x1E86CCu;
label_1e86cc:
    // 0x1e86cc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e86ccu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e86d0: 0x2402006c  addiu       $v0, $zero, 0x6C
    ctx->pc = 0x1e86d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1e86d4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e86d4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e86d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e86d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e86dc: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1E86DCu;
    {
        const bool branch_taken_0x1e86dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e86dc) {
            ctx->pc = 0x1E8740u;
            goto label_1e8740;
        }
    }
    ctx->pc = 0x1E86E4u;
label_1e86e4:
    // 0x1e86e4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e86e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e86e8: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e86e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e86ec: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1e86ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e86f0: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e86f0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e86f4: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e86f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e86f8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e86f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e86fc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e86fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e8700: 0x8f828028  lw          $v0, -0x7FD8($gp)
    ctx->pc = 0x1e8700u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934568)));
    // 0x1e8704: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e8704u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e8708: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e8708u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e870c: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1e870cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e8710: 0x97c20010  lhu         $v0, 0x10($fp)
    ctx->pc = 0x1e8710u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e8714: 0xa4620002  sh          $v0, 0x2($v1)
    ctx->pc = 0x1e8714u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8718: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1e8718u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e871c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e871cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8720: 0xa4620000  sh          $v0, 0x0($v1)
    ctx->pc = 0x1e8720u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8724: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1e8724u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e8728: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8728u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e872c: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1e872cu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8730: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e8730u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e8734: 0xc07a121  jal         func_1E8484
    ctx->pc = 0x1E8734u;
    SET_GPR_U32(ctx, 31, 0x1E873Cu);
    ctx->pc = 0x1E8484u;
    if (runtime->hasFunction(0x1E8484u)) {
        auto targetFn = runtime->lookupFunction(0x1E8484u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E873Cu; }
        if (ctx->pc != 0x1E873Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8484_0x1e8484(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E873Cu; }
        if (ctx->pc != 0x1E873Cu) { return; }
    }
    ctx->pc = 0x1E873Cu;
label_1e873c:
    // 0x1e873c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e873cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
label_1e8740:
    // 0x1e8740: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e8740u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8744: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e8744u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e8748: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e8748u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e874c: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1e874cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1e8750: 0x3e00008  jr          $ra
    ctx->pc = 0x1E8750u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E8560u: goto label_1e8560;
            case 0x1E857Cu: goto label_1e857c;
            case 0x1E8594u: goto label_1e8594;
            case 0x1E85CCu: goto label_1e85cc;
            case 0x1E85E4u: goto label_1e85e4;
            case 0x1E85F4u: goto label_1e85f4;
            case 0x1E85FCu: goto label_1e85fc;
            case 0x1E8600u: goto label_1e8600;
            case 0x1E8618u: goto label_1e8618;
            case 0x1E866Cu: goto label_1e866c;
            case 0x1E86A0u: goto label_1e86a0;
            case 0x1E86B4u: goto label_1e86b4;
            case 0x1E86CCu: goto label_1e86cc;
            case 0x1E86E4u: goto label_1e86e4;
            case 0x1E873Cu: goto label_1e873c;
            case 0x1E8740u: goto label_1e8740;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E8758u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
