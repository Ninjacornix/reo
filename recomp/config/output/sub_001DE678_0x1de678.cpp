#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DE678
// Address: 0x1de678 - 0x1de74c
void sub_001DE678_0x1de678(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DE678_0x1de678");
#endif

    switch (ctx->pc) {
        case 0x1de698u: goto label_1de698;
        case 0x1de6ccu: goto label_1de6cc;
        case 0x1de6f8u: goto label_1de6f8;
        default: break;
    }

    ctx->pc = 0x1de678u;

    // 0x1de678: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1de678u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1de67c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1de67cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1de680: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1de680u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1de684: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1de684u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de688: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1de688u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1de68c: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1de68cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de690: 0xc077950  jal         func_1DE540
    ctx->pc = 0x1DE690u;
    SET_GPR_U32(ctx, 31, 0x1DE698u);
    ctx->pc = 0x1DE540u;
    if (runtime->hasFunction(0x1DE540u)) {
        auto targetFn = runtime->lookupFunction(0x1DE540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DE698u; }
        if (ctx->pc != 0x1DE698u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DE540_0x1de540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DE698u; }
        if (ctx->pc != 0x1DE698u) { return; }
    }
    ctx->pc = 0x1DE698u;
label_1de698:
    // 0x1de698: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de698u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de69c: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1de69cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1de6a0: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1de6a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1de6a4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1de6a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1de6a8: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1de6a8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1de6ac: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de6acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de6b0: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1de6b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de6b4: 0x2842037d  slti        $v0, $v0, 0x37D
    ctx->pc = 0x1de6b4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)893) ? 1 : 0);
    // 0x1de6b8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DE6B8u;
    {
        const bool branch_taken_0x1de6b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1de6b8) {
            ctx->pc = 0x1DE6C8u;
            goto label_1de6c8;
        }
    }
    ctx->pc = 0x1DE6C0u;
    // 0x1de6c0: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1DE6C0u;
    {
        const bool branch_taken_0x1de6c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1de6c0) {
            ctx->pc = 0x1DE734u;
            goto label_1de734;
        }
    }
    ctx->pc = 0x1DE6C8u;
label_1de6c8:
    // 0x1de6c8: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1de6c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1de6cc:
    // 0x1de6cc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de6ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de6d0: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1de6d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1de6d4: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1de6d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de6d8: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1de6d8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1de6dc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DE6DCu;
    {
        const bool branch_taken_0x1de6dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1de6dc) {
            ctx->pc = 0x1DE6ECu;
            goto label_1de6ec;
        }
    }
    ctx->pc = 0x1DE6E4u;
    // 0x1de6e4: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1DE6E4u;
    {
        const bool branch_taken_0x1de6e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1de6e4) {
            ctx->pc = 0x1DE734u;
            goto label_1de734;
        }
    }
    ctx->pc = 0x1DE6ECu;
label_1de6ec:
    // 0x1de6ec: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1de6ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1de6f0: 0xc0777be  jal         func_1DDEF8
    ctx->pc = 0x1DE6F0u;
    SET_GPR_U32(ctx, 31, 0x1DE6F8u);
    ctx->pc = 0x1DDEF8u;
    if (runtime->hasFunction(0x1DDEF8u)) {
        auto targetFn = runtime->lookupFunction(0x1DDEF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DE6F8u; }
        if (ctx->pc != 0x1DE6F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DDEF8_0x1ddef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DE6F8u; }
        if (ctx->pc != 0x1DE6F8u) { return; }
    }
    ctx->pc = 0x1DE6F8u;
label_1de6f8:
    // 0x1de6f8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1de6f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1de6fc: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x1de6fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1de700: 0x2442001b  addiu       $v0, $v0, 0x1B
    ctx->pc = 0x1de700u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27));
    // 0x1de704: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1de704u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1de708: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1de708u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1de70c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1de70cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1de710: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1de710u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1de714: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1de714u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1de718: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1de718u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1de71c: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1de71cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1de720: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1de720u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1de724: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1de724u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1de728: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1de728u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1de72c: 0x1000ffe7  b           . + 4 + (-0x19 << 2)
    ctx->pc = 0x1DE72Cu;
    {
        const bool branch_taken_0x1de72c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1de72c) {
            ctx->pc = 0x1DE6CCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1de6cc;
        }
    }
    ctx->pc = 0x1DE734u;
label_1de734:
    // 0x1de734: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1de734u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de738: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1de738u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1de73c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1de73cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1de740: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1de740u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1de744: 0x3e00008  jr          $ra
    ctx->pc = 0x1DE744u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DE698u: goto label_1de698;
            case 0x1DE6C8u: goto label_1de6c8;
            case 0x1DE6CCu: goto label_1de6cc;
            case 0x1DE6ECu: goto label_1de6ec;
            case 0x1DE6F8u: goto label_1de6f8;
            case 0x1DE734u: goto label_1de734;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DE74Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
