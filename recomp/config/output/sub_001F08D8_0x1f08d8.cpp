#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F08D8
// Address: 0x1f08d8 - 0x1f09f0
void sub_001F08D8_0x1f08d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F08D8_0x1f08d8");
#endif

    switch (ctx->pc) {
        case 0x1f0918u: goto label_1f0918;
        case 0x1f0924u: goto label_1f0924;
        case 0x1f0950u: goto label_1f0950;
        case 0x1f0984u: goto label_1f0984;
        default: break;
    }

    ctx->pc = 0x1f08d8u;

    // 0x1f08d8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f08d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f08dc: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1f08dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1f08e0: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1f08e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1f08e4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f08e4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f08e8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f08e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f08ec: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1f08ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f08f0: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1f08f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1f08f4: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1f08f4u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f08f8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f08f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f08fc: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1f08fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1f0900: 0x27c2000c  addiu       $v0, $fp, 0xC
    ctx->pc = 0x1f0900u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 12));
    // 0x1f0904: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0904u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0908: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1f0908u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f090c: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f090cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0910: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0910u;
    SET_GPR_U32(ctx, 31, 0x1F0918u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0918u; }
        if (ctx->pc != 0x1F0918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0918u; }
        if (ctx->pc != 0x1F0918u) { return; }
    }
    ctx->pc = 0x1F0918u;
label_1f0918:
    // 0x1f0918: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1f0918u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f091c: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1f091cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1f0920: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1f0920u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
label_1f0924:
    // 0x1f0924: 0x87c2000c  lh          $v0, 0xC($fp)
    ctx->pc = 0x1f0924u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f0928: 0x1c400003  bgtz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F0928u;
    {
        const bool branch_taken_0x1f0928 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1f0928) {
            ctx->pc = 0x1F0938u;
            goto label_1f0938;
        }
    }
    ctx->pc = 0x1F0930u;
    // 0x1f0930: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1F0930u;
    {
        const bool branch_taken_0x1f0930 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f0930) {
            ctx->pc = 0x1F09ACu;
            goto label_1f09ac;
        }
    }
    ctx->pc = 0x1F0938u;
label_1f0938:
    // 0x1f0938: 0x27c2000e  addiu       $v0, $fp, 0xE
    ctx->pc = 0x1f0938u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 14));
    // 0x1f093c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f093cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0940: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1f0940u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0944: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f0944u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0948: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0948u;
    SET_GPR_U32(ctx, 31, 0x1F0950u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0950u; }
        if (ctx->pc != 0x1F0950u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0950u; }
        if (ctx->pc != 0x1F0950u) { return; }
    }
    ctx->pc = 0x1F0950u;
label_1f0950:
    // 0x1f0950: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1f0950u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0954: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1f0954u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1f0958: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1f0958u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1f095c: 0x87c3000e  lh          $v1, 0xE($fp)
    ctx->pc = 0x1f095cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 14)));
    // 0x1f0960: 0x87c20004  lh          $v0, 0x4($fp)
    ctx->pc = 0x1f0960u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0964: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1F0964u;
    {
        const bool branch_taken_0x1f0964 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f0964) {
            ctx->pc = 0x1F098Cu;
            goto label_1f098c;
        }
    }
    ctx->pc = 0x1F096Cu;
    // 0x1f096c: 0x27c20010  addiu       $v0, $fp, 0x10
    ctx->pc = 0x1f096cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1f0970: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0970u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0974: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1f0974u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0978: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1f0978u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f097c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F097Cu;
    SET_GPR_U32(ctx, 31, 0x1F0984u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0984u; }
        if (ctx->pc != 0x1F0984u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0984u; }
        if (ctx->pc != 0x1F0984u) { return; }
    }
    ctx->pc = 0x1F0984u;
label_1f0984:
    // 0x1f0984: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1F0984u;
    {
        const bool branch_taken_0x1f0984 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f0984) {
            ctx->pc = 0x1F09ACu;
            goto label_1f09ac;
        }
    }
    ctx->pc = 0x1F098Cu;
label_1f098c:
    // 0x1f098c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1f098cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0990: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f0990u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f0994: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1f0994u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1f0998: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1f0998u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f099c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1f099cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1f09a0: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1f09a0u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f09a4: 0x1000ffdf  b           . + 4 + (-0x21 << 2)
    ctx->pc = 0x1F09A4u;
    {
        const bool branch_taken_0x1f09a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f09a4) {
            ctx->pc = 0x1F0924u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f0924;
        }
    }
    ctx->pc = 0x1F09ACu;
label_1f09ac:
    // 0x1f09ac: 0x87c3000e  lh          $v1, 0xE($fp)
    ctx->pc = 0x1f09acu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 14)));
    // 0x1f09b0: 0x87c20004  lh          $v0, 0x4($fp)
    ctx->pc = 0x1f09b0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f09b4: 0x14620007  bne         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1F09B4u;
    {
        const bool branch_taken_0x1f09b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f09b4) {
            ctx->pc = 0x1F09D4u;
            goto label_1f09d4;
        }
    }
    ctx->pc = 0x1F09BCu;
    // 0x1f09bc: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1f09bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f09c0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f09c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f09c4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f09c4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f09c8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f09c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f09cc: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F09CCu;
    {
        const bool branch_taken_0x1f09cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f09cc) {
            ctx->pc = 0x1F09D8u;
            goto label_1f09d8;
        }
    }
    ctx->pc = 0x1F09D4u;
label_1f09d4:
    // 0x1f09d4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1f09d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1f09d8:
    // 0x1f09d8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f09d8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f09dc: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1f09dcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f09e0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1f09e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1f09e4: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1f09e4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f09e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F09E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F0918u: goto label_1f0918;
            case 0x1F0924u: goto label_1f0924;
            case 0x1F0938u: goto label_1f0938;
            case 0x1F0950u: goto label_1f0950;
            case 0x1F0984u: goto label_1f0984;
            case 0x1F098Cu: goto label_1f098c;
            case 0x1F09ACu: goto label_1f09ac;
            case 0x1F09D4u: goto label_1f09d4;
            case 0x1F09D8u: goto label_1f09d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F09F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
