#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E6328
// Address: 0x1e6328 - 0x1e63f8
void sub_001E6328_0x1e6328(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E6328_0x1e6328");
#endif

    switch (ctx->pc) {
        case 0x1e63dcu: goto label_1e63dc;
        default: break;
    }

    ctx->pc = 0x1e6328u;

    // 0x1e6328: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e6328u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e632c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e632cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e6330: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e6330u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e6334: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e6334u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6338: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e6338u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e633c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e633cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e6340: 0xafc00008  sw          $zero, 0x8($fp)
    ctx->pc = 0x1e6340u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1e6344: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e6344u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6348: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e6348u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e634c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E634Cu;
    {
        const bool branch_taken_0x1e634c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e634c) {
            ctx->pc = 0x1E6374u;
            goto label_1e6374;
        }
    }
    ctx->pc = 0x1E6354u;
    // 0x1e6354: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e6354u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6358: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6358u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e635c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e635cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6360: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6360u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e6364: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6364u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6368: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6368u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e636c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E636Cu;
    {
        const bool branch_taken_0x1e636c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e636c) {
            ctx->pc = 0x1E6388u;
            goto label_1e6388;
        }
    }
    ctx->pc = 0x1E6374u;
label_1e6374:
    // 0x1e6374: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e6374u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e6378: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6378u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e637c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e637cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6380: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1E6380u;
    {
        const bool branch_taken_0x1e6380 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6380) {
            ctx->pc = 0x1E63E0u;
            goto label_1e63e0;
        }
    }
    ctx->pc = 0x1E6388u;
label_1e6388:
    // 0x1e6388: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e6388u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e638c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e638cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6390: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e6390u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6394: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6394u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e6398: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6398u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e639c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e639cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e63a0: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e63a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e63a4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e63a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e63a8: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e63a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e63ac: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E63ACu;
    {
        const bool branch_taken_0x1e63ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e63ac) {
            ctx->pc = 0x1E63C8u;
            goto label_1e63c8;
        }
    }
    ctx->pc = 0x1E63B4u;
    // 0x1e63b4: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e63b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e63b8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e63b8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e63bc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e63bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e63c0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E63C0u;
    {
        const bool branch_taken_0x1e63c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e63c0) {
            ctx->pc = 0x1E63E0u;
            goto label_1e63e0;
        }
    }
    ctx->pc = 0x1E63C8u;
label_1e63c8:
    // 0x1e63c8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e63c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e63cc: 0x2405002d  addiu       $a1, $zero, 0x2D
    ctx->pc = 0x1e63ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
    // 0x1e63d0: 0x8fc60004  lw          $a2, 0x4($fp)
    ctx->pc = 0x1e63d0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e63d4: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E63D4u;
    SET_GPR_U32(ctx, 31, 0x1E63DCu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E63DCu; }
        if (ctx->pc != 0x1E63DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E63DCu; }
        if (ctx->pc != 0x1E63DCu) { return; }
    }
    ctx->pc = 0x1E63DCu;
label_1e63dc:
    // 0x1e63dc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e63dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e63e0:
    // 0x1e63e0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e63e0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e63e4: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e63e4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e63e8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e63e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e63ec: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e63ecu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e63f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1E63F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E6374u: goto label_1e6374;
            case 0x1E6388u: goto label_1e6388;
            case 0x1E63C8u: goto label_1e63c8;
            case 0x1E63DCu: goto label_1e63dc;
            case 0x1E63E0u: goto label_1e63e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E63F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
