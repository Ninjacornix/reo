#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DF4A8
// Address: 0x1df4a8 - 0x1df99c
void sub_001DF4A8_0x1df4a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DF4A8_0x1df4a8");
#endif

    switch (ctx->pc) {
        case 0x1df500u: goto label_1df500;
        case 0x1df53cu: goto label_1df53c;
        case 0x1df558u: goto label_1df558;
        case 0x1df5d0u: goto label_1df5d0;
        case 0x1df630u: goto label_1df630;
        case 0x1df6acu: goto label_1df6ac;
        case 0x1df7c4u: goto label_1df7c4;
        case 0x1df7d4u: goto label_1df7d4;
        case 0x1df8ccu: goto label_1df8cc;
        default: break;
    }

    ctx->pc = 0x1df4a8u;

    // 0x1df4a8: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1df4a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1df4ac: 0xffbe0060  sd          $fp, 0x60($sp)
    ctx->pc = 0x1df4acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 30));
    // 0x1df4b0: 0xffbf0068  sd          $ra, 0x68($sp)
    ctx->pc = 0x1df4b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 31));
    // 0x1df4b4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1df4b4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df4b8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1df4b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1df4bc: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1df4bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1df4c0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df4c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df4c4: 0x8c430080  lw          $v1, 0x80($v0)
    ctx->pc = 0x1df4c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 128)));
    // 0x1df4c8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1df4c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1df4cc: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DF4CCu;
    {
        const bool branch_taken_0x1df4cc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1df4cc) {
            ctx->pc = 0x1DF4E0u;
            goto label_1df4e0;
        }
    }
    ctx->pc = 0x1DF4D4u;
    // 0x1df4d4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1df4d4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df4d8: 0x1000012a  b           . + 4 + (0x12A << 2)
    ctx->pc = 0x1DF4D8u;
    {
        const bool branch_taken_0x1df4d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1df4d8) {
            ctx->pc = 0x1DF984u;
            goto label_1df984;
        }
    }
    ctx->pc = 0x1DF4E0u;
label_1df4e0:
    // 0x1df4e0: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1df4e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1df4e4: 0x2442003c  addiu       $v0, $v0, 0x3C
    ctx->pc = 0x1df4e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 60));
    // 0x1df4e8: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1df4e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1df4ec: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df4ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df4f0: 0x24420484  addiu       $v0, $v0, 0x484
    ctx->pc = 0x1df4f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1156));
    // 0x1df4f4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1df4f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df4f8: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1DF4F8u;
    SET_GPR_U32(ctx, 31, 0x1DF500u);
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF500u; }
        if (ctx->pc != 0x1DF500u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF500u; }
        if (ctx->pc != 0x1DF500u) { return; }
    }
    ctx->pc = 0x1DF500u;
label_1df500:
    // 0x1df500: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1df500u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df504: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df504u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df508: 0x24430484  addiu       $v1, $v0, 0x484
    ctx->pc = 0x1df508u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1156));
    // 0x1df50c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1df50cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1df510: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1df510u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1df514: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1df514u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1df518: 0x304203ff  andi        $v0, $v0, 0x3FF
    ctx->pc = 0x1df518u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1023);
    // 0x1df51c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1df51cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1df520: 0x2442fff0  addiu       $v0, $v0, -0x10
    ctx->pc = 0x1df520u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967280));
    // 0x1df524: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1df524u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1df528: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1df528u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df52c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1df52cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df530: 0x24080140  addiu       $t0, $zero, 0x140
    ctx->pc = 0x1df530u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 320));
    // 0x1df534: 0xc07acda  jal         func_1EB368
    ctx->pc = 0x1DF534u;
    SET_GPR_U32(ctx, 31, 0x1DF53Cu);
    ctx->pc = 0x1EB368u;
    if (runtime->hasFunction(0x1EB368u)) {
        auto targetFn = runtime->lookupFunction(0x1EB368u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF53Cu; }
        if (ctx->pc != 0x1DF53Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EB368_0x1eb368(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF53Cu; }
        if (ctx->pc != 0x1DF53Cu) { return; }
    }
    ctx->pc = 0x1DF53Cu;
label_1df53c:
    // 0x1df53c: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1df53cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1df540: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df540u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df544: 0x244204ac  addiu       $v0, $v0, 0x4AC
    ctx->pc = 0x1df544u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1196));
    // 0x1df548: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1df548u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df54c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1df54cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df550: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1DF550u;
    SET_GPR_U32(ctx, 31, 0x1DF558u);
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF558u; }
        if (ctx->pc != 0x1DF558u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF558u; }
        if (ctx->pc != 0x1DF558u) { return; }
    }
    ctx->pc = 0x1DF558u;
label_1df558:
    // 0x1df558: 0x1040003c  beqz        $v0, . + 4 + (0x3C << 2)
    ctx->pc = 0x1DF558u;
    {
        const bool branch_taken_0x1df558 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1df558) {
            ctx->pc = 0x1DF64Cu;
            goto label_1df64c;
        }
    }
    ctx->pc = 0x1DF560u;
    // 0x1df560: 0x24020027  addiu       $v0, $zero, 0x27
    ctx->pc = 0x1df560u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 39));
    // 0x1df564: 0xa3c20040  sb          $v0, 0x40($fp)
    ctx->pc = 0x1df564u;
    WRITE8(ADD32(GPR_U32(ctx, 30), 64), (uint8_t)GPR_U32(ctx, 2));
    // 0x1df568: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1df568u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1df56c: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1df56cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1df570: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1df570u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1df574: 0xafc20048  sw          $v0, 0x48($fp)
    ctx->pc = 0x1df574u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 72), GPR_U32(ctx, 2));
    // 0x1df578: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1df578u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1df57c: 0xa7c20044  sh          $v0, 0x44($fp)
    ctx->pc = 0x1df57cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 68), (uint16_t)GPR_U32(ctx, 2));
    // 0x1df580: 0x24021000  addiu       $v0, $zero, 0x1000
    ctx->pc = 0x1df580u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1df584: 0xa7c20046  sh          $v0, 0x46($fp)
    ctx->pc = 0x1df584u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 70), (uint16_t)GPR_U32(ctx, 2));
    // 0x1df588: 0xa3c00041  sb          $zero, 0x41($fp)
    ctx->pc = 0x1df588u;
    WRITE8(ADD32(GPR_U32(ctx, 30), 65), (uint8_t)GPR_U32(ctx, 0));
    // 0x1df58c: 0xa7c00042  sh          $zero, 0x42($fp)
    ctx->pc = 0x1df58cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 66), (uint16_t)GPR_U32(ctx, 0));
    // 0x1df590: 0xafc0004c  sw          $zero, 0x4C($fp)
    ctx->pc = 0x1df590u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 76), GPR_U32(ctx, 0));
    // 0x1df594: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1df594u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1df598: 0xafc20050  sw          $v0, 0x50($fp)
    ctx->pc = 0x1df598u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 80), GPR_U32(ctx, 2));
    // 0x1df59c: 0x24020013  addiu       $v0, $zero, 0x13
    ctx->pc = 0x1df59cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x1df5a0: 0xafc20054  sw          $v0, 0x54($fp)
    ctx->pc = 0x1df5a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 84), GPR_U32(ctx, 2));
    // 0x1df5a4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df5a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df5a8: 0x8c4205b8  lw          $v0, 0x5B8($v0)
    ctx->pc = 0x1df5a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1464)));
    // 0x1df5ac: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1DF5ACu;
    {
        const bool branch_taken_0x1df5ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1df5ac) {
            ctx->pc = 0x1DF5D0u;
            goto label_1df5d0;
        }
    }
    ctx->pc = 0x1DF5B4u;
    // 0x1df5b4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df5b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df5b8: 0x27c30040  addiu       $v1, $fp, 0x40
    ctx->pc = 0x1df5b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 64));
    // 0x1df5bc: 0x27c50050  addiu       $a1, $fp, 0x50
    ctx->pc = 0x1df5bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 30), 80));
    // 0x1df5c0: 0x8c4205b8  lw          $v0, 0x5B8($v0)
    ctx->pc = 0x1df5c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1464)));
    // 0x1df5c4: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x1df5c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df5c8: 0x40f809  jalr        $v0
    ctx->pc = 0x1DF5C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1DF5D0u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1DF5D0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DF4E0u: goto label_1df4e0;
            case 0x1DF500u: goto label_1df500;
            case 0x1DF53Cu: goto label_1df53c;
            case 0x1DF558u: goto label_1df558;
            case 0x1DF5D0u: goto label_1df5d0;
            case 0x1DF630u: goto label_1df630;
            case 0x1DF64Cu: goto label_1df64c;
            case 0x1DF6ACu: goto label_1df6ac;
            case 0x1DF7C4u: goto label_1df7c4;
            case 0x1DF7D4u: goto label_1df7d4;
            case 0x1DF8CCu: goto label_1df8cc;
            case 0x1DF958u: goto label_1df958;
            case 0x1DF984u: goto label_1df984;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1DF5D0u; }
            if (ctx->pc != 0x1DF5D0u) { return; }
        }
        }
    }
    ctx->pc = 0x1DF5D0u;
label_1df5d0:
    // 0x1df5d0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df5d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df5d4: 0x94420030  lhu         $v0, 0x30($v0)
    ctx->pc = 0x1df5d4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 48)));
    // 0x1df5d8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1df5d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1df5dc: 0x22200  sll         $a0, $v0, 8
    ctx->pc = 0x1df5dcu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1df5e0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df5e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df5e4: 0x8c430030  lw          $v1, 0x30($v0)
    ctx->pc = 0x1df5e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 48)));
    // 0x1df5e8: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1df5e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1df5ec: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df5ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df5f0: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1df5f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1df5f4: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x1df5f4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df5f8: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1df5f8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1df5fc: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df5fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df600: 0x8c430030  lw          $v1, 0x30($v0)
    ctx->pc = 0x1df600u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 48)));
    // 0x1df604: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1df604u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1df608: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df608u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df60c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1df60cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1df610: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x1df610u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df614: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1df614u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1df618: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1df618u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1df61c: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1df61cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df620: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1df620u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df624: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1df624u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df628: 0xc076bab  jal         func_1DAEAC
    ctx->pc = 0x1DF628u;
    SET_GPR_U32(ctx, 31, 0x1DF630u);
    ctx->pc = 0x1DAEACu;
    if (runtime->hasFunction(0x1DAEACu)) {
        auto targetFn = runtime->lookupFunction(0x1DAEACu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF630u; }
        if (ctx->pc != 0x1DF630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAEAC_0x1daeac(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF630u; }
        if (ctx->pc != 0x1DF630u) { return; }
    }
    ctx->pc = 0x1DF630u;
label_1df630:
    // 0x1df630: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df630u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df634: 0xac40007c  sw          $zero, 0x7C($v0)
    ctx->pc = 0x1df634u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 124), GPR_U32(ctx, 0));
    // 0x1df638: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df638u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df63c: 0xac400080  sw          $zero, 0x80($v0)
    ctx->pc = 0x1df63cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 128), GPR_U32(ctx, 0));
    // 0x1df640: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1df640u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1df644: 0x100000cf  b           . + 4 + (0xCF << 2)
    ctx->pc = 0x1DF644u;
    {
        const bool branch_taken_0x1df644 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1df644) {
            ctx->pc = 0x1DF984u;
            goto label_1df984;
        }
    }
    ctx->pc = 0x1DF64Cu;
label_1df64c:
    // 0x1df64c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df64cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df650: 0x94420030  lhu         $v0, 0x30($v0)
    ctx->pc = 0x1df650u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 48)));
    // 0x1df654: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1df654u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1df658: 0x22200  sll         $a0, $v0, 8
    ctx->pc = 0x1df658u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1df65c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df65cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df660: 0x8c430030  lw          $v1, 0x30($v0)
    ctx->pc = 0x1df660u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 48)));
    // 0x1df664: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1df664u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1df668: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df668u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df66c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1df66cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1df670: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x1df670u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df674: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1df674u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1df678: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df678u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df67c: 0x8c430030  lw          $v1, 0x30($v0)
    ctx->pc = 0x1df67cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 48)));
    // 0x1df680: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1df680u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1df684: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df684u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df688: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1df688u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1df68c: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x1df68cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df690: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1df690u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1df694: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1df694u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1df698: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1df698u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df69c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1df69cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df6a0: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1df6a0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df6a4: 0xc076bab  jal         func_1DAEAC
    ctx->pc = 0x1DF6A4u;
    SET_GPR_U32(ctx, 31, 0x1DF6ACu);
    ctx->pc = 0x1DAEACu;
    if (runtime->hasFunction(0x1DAEACu)) {
        auto targetFn = runtime->lookupFunction(0x1DAEACu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF6ACu; }
        if (ctx->pc != 0x1DF6ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAEAC_0x1daeac(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF6ACu; }
        if (ctx->pc != 0x1DF6ACu) { return; }
    }
    ctx->pc = 0x1DF6ACu;
label_1df6ac:
    // 0x1df6ac: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1df6acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df6b0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df6b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df6b4: 0x8c420028  lw          $v0, 0x28($v0)
    ctx->pc = 0x1df6b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x1df6b8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1df6b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1df6bc: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1df6bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1df6c0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df6c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df6c4: 0x8c420028  lw          $v0, 0x28($v0)
    ctx->pc = 0x1df6c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x1df6c8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1df6c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1df6cc: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1df6ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1df6d0: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1df6d0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1df6d4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df6d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df6d8: 0x8c430028  lw          $v1, 0x28($v0)
    ctx->pc = 0x1df6d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x1df6dc: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1df6dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1df6e0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df6e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df6e4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1df6e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1df6e8: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1df6e8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df6ec: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df6ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df6f0: 0x8c430028  lw          $v1, 0x28($v0)
    ctx->pc = 0x1df6f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x1df6f4: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1df6f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1df6f8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df6f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df6fc: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1df6fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1df700: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1df700u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df704: 0xaca20028  sw          $v0, 0x28($a1)
    ctx->pc = 0x1df704u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 40), GPR_U32(ctx, 2));
    // 0x1df708: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1df708u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df70c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df70cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df710: 0x8c420038  lw          $v0, 0x38($v0)
    ctx->pc = 0x1df710u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 56)));
    // 0x1df714: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1df714u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1df718: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1df718u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1df71c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df71cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df720: 0x8c420038  lw          $v0, 0x38($v0)
    ctx->pc = 0x1df720u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 56)));
    // 0x1df724: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1df724u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1df728: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1df728u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1df72c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1df72cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1df730: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df730u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df734: 0x8c430038  lw          $v1, 0x38($v0)
    ctx->pc = 0x1df734u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 56)));
    // 0x1df738: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1df738u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1df73c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df73cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df740: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1df740u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1df744: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1df744u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df748: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df748u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df74c: 0x8c430038  lw          $v1, 0x38($v0)
    ctx->pc = 0x1df74cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 56)));
    // 0x1df750: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1df750u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1df754: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df754u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df758: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1df758u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1df75c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1df75cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df760: 0xaca20508  sw          $v0, 0x508($a1)
    ctx->pc = 0x1df760u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 1288), GPR_U32(ctx, 2));
    // 0x1df764: 0x27c40020  addiu       $a0, $fp, 0x20
    ctx->pc = 0x1df764u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1df768: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df768u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df76c: 0x8c430028  lw          $v1, 0x28($v0)
    ctx->pc = 0x1df76cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x1df770: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1df770u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1df774: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df774u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df778: 0x23602  srl         $a2, $v0, 24
    ctx->pc = 0x1df778u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1df77c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df77cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df780: 0x8c430028  lw          $v1, 0x28($v0)
    ctx->pc = 0x1df780u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x1df784: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1df784u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1df788: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df788u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df78c: 0x23c02  srl         $a3, $v0, 16
    ctx->pc = 0x1df78cu;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x1df790: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df790u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df794: 0x8c420028  lw          $v0, 0x28($v0)
    ctx->pc = 0x1df794u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x1df798: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1df798u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1df79c: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x1df79cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1df7a0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df7a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df7a4: 0x8c420028  lw          $v0, 0x28($v0)
    ctx->pc = 0x1df7a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x1df7a8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1df7a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1df7ac: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1df7acu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1df7b0: 0x24a57cf0  addiu       $a1, $a1, 0x7CF0
    ctx->pc = 0x1df7b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 31984));
    // 0x1df7b4: 0x60402d  daddu       $t0, $v1, $zero
    ctx->pc = 0x1df7b4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df7b8: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1df7b8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df7bc: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1DF7BCu;
    SET_GPR_U32(ctx, 31, 0x1DF7C4u);
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF7C4u; }
        if (ctx->pc != 0x1DF7C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF7C4u; }
        if (ctx->pc != 0x1DF7C4u) { return; }
    }
    ctx->pc = 0x1DF7C4u;
label_1df7c4:
    // 0x1df7c4: 0x27c20020  addiu       $v0, $fp, 0x20
    ctx->pc = 0x1df7c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1df7c8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1df7c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df7cc: 0xc07a1d6  jal         func_1E8758
    ctx->pc = 0x1DF7CCu;
    SET_GPR_U32(ctx, 31, 0x1DF7D4u);
    ctx->pc = 0x1E8758u;
    if (runtime->hasFunction(0x1E8758u)) {
        auto targetFn = runtime->lookupFunction(0x1E8758u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF7D4u; }
        if (ctx->pc != 0x1DF7D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8758_0x1e8758(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF7D4u; }
        if (ctx->pc != 0x1DF7D4u) { return; }
    }
    ctx->pc = 0x1DF7D4u;
label_1df7d4:
    // 0x1df7d4: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1df7d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df7d8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1df7d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1df7dc: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1df7dcu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1df7e0: 0xac620500  sw          $v0, 0x500($v1)
    ctx->pc = 0x1df7e0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1280), GPR_U32(ctx, 2));
    // 0x1df7e4: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1df7e4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df7e8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df7e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df7ec: 0x8c42002c  lw          $v0, 0x2C($v0)
    ctx->pc = 0x1df7ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 44)));
    // 0x1df7f0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1df7f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1df7f4: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1df7f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1df7f8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df7f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df7fc: 0x8c42002c  lw          $v0, 0x2C($v0)
    ctx->pc = 0x1df7fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 44)));
    // 0x1df800: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1df800u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1df804: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1df804u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1df808: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1df808u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1df80c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df80cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df810: 0x8c43002c  lw          $v1, 0x2C($v0)
    ctx->pc = 0x1df810u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 44)));
    // 0x1df814: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1df814u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1df818: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df818u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df81c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1df81cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1df820: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1df820u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df824: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df824u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df828: 0x8c43002c  lw          $v1, 0x2C($v0)
    ctx->pc = 0x1df828u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 44)));
    // 0x1df82c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1df82cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1df830: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df830u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df834: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1df834u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1df838: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1df838u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df83c: 0xaca20504  sw          $v0, 0x504($a1)
    ctx->pc = 0x1df83cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 1284), GPR_U32(ctx, 2));
    // 0x1df840: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df840u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df844: 0x24420084  addiu       $v0, $v0, 0x84
    ctx->pc = 0x1df844u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 132));
    // 0x1df848: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1df848u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1df84c: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1df84cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1df850: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df850u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df854: 0x8c420034  lw          $v0, 0x34($v0)
    ctx->pc = 0x1df854u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 52)));
    // 0x1df858: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1df858u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1df85c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1df85cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1df860: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df860u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df864: 0x8c420034  lw          $v0, 0x34($v0)
    ctx->pc = 0x1df864u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 52)));
    // 0x1df868: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1df868u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1df86c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1df86cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1df870: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1df870u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1df874: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df874u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df878: 0x8c430034  lw          $v1, 0x34($v0)
    ctx->pc = 0x1df878u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 52)));
    // 0x1df87c: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1df87cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1df880: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df880u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df884: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1df884u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1df888: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1df888u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df88c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df88cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df890: 0x8c430034  lw          $v1, 0x34($v0)
    ctx->pc = 0x1df890u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 52)));
    // 0x1df894: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1df894u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1df898: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df898u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df89c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1df89cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1df8a0: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1df8a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df8a4: 0xaca20024  sw          $v0, 0x24($a1)
    ctx->pc = 0x1df8a4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 36), GPR_U32(ctx, 2));
    // 0x1df8a8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1df8a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1df8ac: 0x24440028  addiu       $a0, $v0, 0x28
    ctx->pc = 0x1df8acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 40));
    // 0x1df8b0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1df8b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1df8b4: 0x2442003c  addiu       $v0, $v0, 0x3C
    ctx->pc = 0x1df8b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 60));
    // 0x1df8b8: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1df8b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1df8bc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1df8bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df8c0: 0x8c660024  lw          $a2, 0x24($v1)
    ctx->pc = 0x1df8c0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x1df8c4: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1DF8C4u;
    SET_GPR_U32(ctx, 31, 0x1DF8CCu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF8CCu; }
        if (ctx->pc != 0x1DF8CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF8CCu; }
        if (ctx->pc != 0x1DF8CCu) { return; }
    }
    ctx->pc = 0x1DF8CCu;
label_1df8cc:
    // 0x1df8cc: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1df8ccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1df8d0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1df8d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1df8d4: 0x8c420024  lw          $v0, 0x24($v0)
    ctx->pc = 0x1df8d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 36)));
    // 0x1df8d8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1df8d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1df8dc: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1df8dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1df8e0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1df8e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1df8e4: 0x8c420024  lw          $v0, 0x24($v0)
    ctx->pc = 0x1df8e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 36)));
    // 0x1df8e8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1df8e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1df8ec: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1df8ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1df8f0: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1df8f0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1df8f4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1df8f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1df8f8: 0x8c430024  lw          $v1, 0x24($v0)
    ctx->pc = 0x1df8f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 36)));
    // 0x1df8fc: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1df8fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1df900: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df900u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df904: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1df904u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1df908: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1df908u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df90c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1df90cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1df910: 0x8c430024  lw          $v1, 0x24($v0)
    ctx->pc = 0x1df910u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 36)));
    // 0x1df914: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1df914u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1df918: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df918u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df91c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1df91cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1df920: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1df920u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df924: 0xaca20024  sw          $v0, 0x24($a1)
    ctx->pc = 0x1df924u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 36), GPR_U32(ctx, 2));
    // 0x1df928: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df928u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df92c: 0x8c430080  lw          $v1, 0x80($v0)
    ctx->pc = 0x1df92cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 128)));
    // 0x1df930: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1df930u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1df934: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1DF934u;
    {
        const bool branch_taken_0x1df934 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1df934) {
            ctx->pc = 0x1DF958u;
            goto label_1df958;
        }
    }
    ctx->pc = 0x1DF93Cu;
    // 0x1df93c: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1df93cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df940: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1df940u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1df944: 0xac620080  sw          $v0, 0x80($v1)
    ctx->pc = 0x1df944u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 128), GPR_U32(ctx, 2));
    // 0x1df948: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1df948u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df94c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df94cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df950: 0x8c4204fc  lw          $v0, 0x4FC($v0)
    ctx->pc = 0x1df950u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1276)));
    // 0x1df954: 0xac62007c  sw          $v0, 0x7C($v1)
    ctx->pc = 0x1df954u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 124), GPR_U32(ctx, 2));
label_1df958:
    // 0x1df958: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1df958u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df95c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df95cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df960: 0x8c420514  lw          $v0, 0x514($v0)
    ctx->pc = 0x1df960u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1300)));
    // 0x1df964: 0xac620510  sw          $v0, 0x510($v1)
    ctx->pc = 0x1df964u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1296), GPR_U32(ctx, 2));
    // 0x1df968: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1df968u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df96c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df96cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df970: 0x8c420510  lw          $v0, 0x510($v0)
    ctx->pc = 0x1df970u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1296)));
    // 0x1df974: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x1df974u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1df978: 0x24420fa0  addiu       $v0, $v0, 0xFA0
    ctx->pc = 0x1df978u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4000));
    // 0x1df97c: 0xac62051c  sw          $v0, 0x51C($v1)
    ctx->pc = 0x1df97cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1308), GPR_U32(ctx, 2));
    // 0x1df980: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1df980u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1df984:
    // 0x1df984: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1df984u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df988: 0xdfbe0060  ld          $fp, 0x60($sp)
    ctx->pc = 0x1df988u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1df98c: 0xdfbf0068  ld          $ra, 0x68($sp)
    ctx->pc = 0x1df98cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x1df990: 0x27bd0070  addiu       $sp, $sp, 0x70
    ctx->pc = 0x1df990u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1df994: 0x3e00008  jr          $ra
    ctx->pc = 0x1DF994u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DF4E0u: goto label_1df4e0;
            case 0x1DF500u: goto label_1df500;
            case 0x1DF53Cu: goto label_1df53c;
            case 0x1DF558u: goto label_1df558;
            case 0x1DF5D0u: goto label_1df5d0;
            case 0x1DF630u: goto label_1df630;
            case 0x1DF64Cu: goto label_1df64c;
            case 0x1DF6ACu: goto label_1df6ac;
            case 0x1DF7C4u: goto label_1df7c4;
            case 0x1DF7D4u: goto label_1df7d4;
            case 0x1DF8CCu: goto label_1df8cc;
            case 0x1DF958u: goto label_1df958;
            case 0x1DF984u: goto label_1df984;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DF99Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
