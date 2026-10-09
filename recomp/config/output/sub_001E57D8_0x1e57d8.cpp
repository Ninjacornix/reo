#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E57D8
// Address: 0x1e57d8 - 0x1e5900
void sub_001E57D8_0x1e57d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E57D8_0x1e57d8");
#endif

    switch (ctx->pc) {
        case 0x1e5884u: goto label_1e5884;
        case 0x1e58c8u: goto label_1e58c8;
        default: break;
    }

    ctx->pc = 0x1e57d8u;

    // 0x1e57d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e57d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e57dc: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e57dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e57e0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e57e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e57e4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e57e4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e57e8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e57e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e57ec: 0xafc00008  sw          $zero, 0x8($fp)
    ctx->pc = 0x1e57ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1e57f0: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e57f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e57f4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e57f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e57f8: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E57F8u;
    {
        const bool branch_taken_0x1e57f8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e57f8) {
            ctx->pc = 0x1E5820u;
            goto label_1e5820;
        }
    }
    ctx->pc = 0x1E5800u;
    // 0x1e5800: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5800u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5804: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5804u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5808: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5808u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e580c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e580cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5810: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5810u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5814: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5814u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5818: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5818u;
    {
        const bool branch_taken_0x1e5818 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5818) {
            ctx->pc = 0x1E5834u;
            goto label_1e5834;
        }
    }
    ctx->pc = 0x1E5820u;
label_1e5820:
    // 0x1e5820: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e5820u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e5824: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5824u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5828: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5828u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e582c: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x1E582Cu;
    {
        const bool branch_taken_0x1e582c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e582c) {
            ctx->pc = 0x1E58E8u;
            goto label_1e58e8;
        }
    }
    ctx->pc = 0x1E5834u;
label_1e5834:
    // 0x1e5834: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5834u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5838: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5838u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e583c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e583cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5840: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5840u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5844: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5844u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5848: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5848u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e584c: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e584cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e5850: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e5850u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5854: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e5854u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e5858: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5858u;
    {
        const bool branch_taken_0x1e5858 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5858) {
            ctx->pc = 0x1E5874u;
            goto label_1e5874;
        }
    }
    ctx->pc = 0x1E5860u;
    // 0x1e5860: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5860u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e5864: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5864u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5868: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5868u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e586c: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1E586Cu;
    {
        const bool branch_taken_0x1e586c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e586c) {
            ctx->pc = 0x1E58E8u;
            goto label_1e58e8;
        }
    }
    ctx->pc = 0x1E5874u;
label_1e5874:
    // 0x1e5874: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1e5874u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5878: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e5878u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e587c: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E587Cu;
    SET_GPR_U32(ctx, 31, 0x1E5884u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5884u; }
        if (ctx->pc != 0x1E5884u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5884u; }
        if (ctx->pc != 0x1E5884u) { return; }
    }
    ctx->pc = 0x1E5884u;
label_1e5884:
    // 0x1e5884: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e5884u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e5888: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e5888u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e588c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E588Cu;
    {
        const bool branch_taken_0x1e588c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e588c) {
            ctx->pc = 0x1E58A8u;
            goto label_1e58a8;
        }
    }
    ctx->pc = 0x1E5894u;
    // 0x1e5894: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e5894u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e5898: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5898u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e589c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e589cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e58a0: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1E58A0u;
    {
        const bool branch_taken_0x1e58a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e58a0) {
            ctx->pc = 0x1E58E8u;
            goto label_1e58e8;
        }
    }
    ctx->pc = 0x1E58A8u;
label_1e58a8:
    // 0x1e58a8: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1e58a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e58ac: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e58acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e58b0: 0x24062000  addiu       $a2, $zero, 0x2000
    ctx->pc = 0x1e58b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1e58b4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1e58b4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e58b8: 0x24080012  addiu       $t0, $zero, 0x12
    ctx->pc = 0x1e58b8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1e58bc: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e58bcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e58c0: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E58C0u;
    SET_GPR_U32(ctx, 31, 0x1E58C8u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E58C8u; }
        if (ctx->pc != 0x1E58C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E58C8u; }
        if (ctx->pc != 0x1E58C8u) { return; }
    }
    ctx->pc = 0x1E58C8u;
label_1e58c8:
    // 0x1e58c8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E58C8u;
    {
        const bool branch_taken_0x1e58c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e58c8) {
            ctx->pc = 0x1E58E4u;
            goto label_1e58e4;
        }
    }
    ctx->pc = 0x1E58D0u;
    // 0x1e58d0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e58d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e58d4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e58d4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e58d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e58d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e58dc: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E58DCu;
    {
        const bool branch_taken_0x1e58dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e58dc) {
            ctx->pc = 0x1E58E8u;
            goto label_1e58e8;
        }
    }
    ctx->pc = 0x1E58E4u;
label_1e58e4:
    // 0x1e58e4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e58e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e58e8:
    // 0x1e58e8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e58e8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e58ec: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e58ecu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e58f0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e58f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e58f4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e58f4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e58f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1E58F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5820u: goto label_1e5820;
            case 0x1E5834u: goto label_1e5834;
            case 0x1E5874u: goto label_1e5874;
            case 0x1E5884u: goto label_1e5884;
            case 0x1E58A8u: goto label_1e58a8;
            case 0x1E58C8u: goto label_1e58c8;
            case 0x1E58E4u: goto label_1e58e4;
            case 0x1E58E8u: goto label_1e58e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E5900u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
