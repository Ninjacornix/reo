#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DE828
// Address: 0x1de828 - 0x1de8e0
void sub_001DE828_0x1de828(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DE828_0x1de828");
#endif

    switch (ctx->pc) {
        case 0x1de848u: goto label_1de848;
        case 0x1de860u: goto label_1de860;
        case 0x1de88cu: goto label_1de88c;
        default: break;
    }

    ctx->pc = 0x1de828u;

    // 0x1de828: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1de828u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1de82c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1de82cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1de830: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1de830u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1de834: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1de834u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de838: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1de838u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1de83c: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1de83cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de840: 0xc077950  jal         func_1DE540
    ctx->pc = 0x1DE840u;
    SET_GPR_U32(ctx, 31, 0x1DE848u);
    ctx->pc = 0x1DE540u;
    if (runtime->hasFunction(0x1DE540u)) {
        auto targetFn = runtime->lookupFunction(0x1DE540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DE848u; }
        if (ctx->pc != 0x1DE848u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DE540_0x1de540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DE848u; }
        if (ctx->pc != 0x1DE848u) { return; }
    }
    ctx->pc = 0x1DE848u;
label_1de848:
    // 0x1de848: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de848u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de84c: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1de84cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1de850: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1de850u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1de854: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1de854u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1de858: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1de858u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1de85c: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1de85cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1de860:
    // 0x1de860: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de860u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de864: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1de864u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1de868: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1de868u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de86c: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1de86cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1de870: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DE870u;
    {
        const bool branch_taken_0x1de870 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1de870) {
            ctx->pc = 0x1DE880u;
            goto label_1de880;
        }
    }
    ctx->pc = 0x1DE878u;
    // 0x1de878: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1DE878u;
    {
        const bool branch_taken_0x1de878 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1de878) {
            ctx->pc = 0x1DE8C8u;
            goto label_1de8c8;
        }
    }
    ctx->pc = 0x1DE880u;
label_1de880:
    // 0x1de880: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1de880u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1de884: 0xc0779d3  jal         func_1DE74C
    ctx->pc = 0x1DE884u;
    SET_GPR_U32(ctx, 31, 0x1DE88Cu);
    ctx->pc = 0x1DE74Cu;
    if (runtime->hasFunction(0x1DE74Cu)) {
        auto targetFn = runtime->lookupFunction(0x1DE74Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DE88Cu; }
        if (ctx->pc != 0x1DE88Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DE74C_0x1de74c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DE88Cu; }
        if (ctx->pc != 0x1DE88Cu) { return; }
    }
    ctx->pc = 0x1DE88Cu;
label_1de88c:
    // 0x1de88c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1de88cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1de890: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1de890u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1de894: 0x2442001f  addiu       $v0, $v0, 0x1F
    ctx->pc = 0x1de894u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 31));
    // 0x1de898: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1de898u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1de89c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1de89cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1de8a0: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1de8a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1de8a4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1de8a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1de8a8: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1de8a8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1de8ac: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1de8acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1de8b0: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1de8b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1de8b4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1de8b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1de8b8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1de8b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1de8bc: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1de8bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1de8c0: 0x1000ffe7  b           . + 4 + (-0x19 << 2)
    ctx->pc = 0x1DE8C0u;
    {
        const bool branch_taken_0x1de8c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1de8c0) {
            ctx->pc = 0x1DE860u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1de860;
        }
    }
    ctx->pc = 0x1DE8C8u;
label_1de8c8:
    // 0x1de8c8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1de8c8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de8cc: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1de8ccu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1de8d0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1de8d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1de8d4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1de8d4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1de8d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1DE8D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DE848u: goto label_1de848;
            case 0x1DE860u: goto label_1de860;
            case 0x1DE880u: goto label_1de880;
            case 0x1DE88Cu: goto label_1de88c;
            case 0x1DE8C8u: goto label_1de8c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DE8E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
