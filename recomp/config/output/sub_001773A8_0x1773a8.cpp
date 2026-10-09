#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001773A8
// Address: 0x1773a8 - 0x177440
void sub_001773A8_0x1773a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001773A8_0x1773a8");
#endif

    switch (ctx->pc) {
        case 0x1773ecu: goto label_1773ec;
        case 0x177428u: goto label_177428;
        default: break;
    }

    ctx->pc = 0x1773a8u;

    // 0x1773a8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1773a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1773ac: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x1773acu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1773b0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1773b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1773b4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1773b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1773b8: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1773b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1773bc: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1773bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1773c0: 0x8c65094c  lw          $a1, 0x94C($v1)
    ctx->pc = 0x1773c0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 2380)));
    // 0x1773c4: 0x24630cc0  addiu       $v1, $v1, 0xCC0
    ctx->pc = 0x1773c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3264));
    // 0x1773c8: 0x8c70023c  lw          $s0, 0x23C($v1)
    ctx->pc = 0x1773c8u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 572)));
    // 0x1773cc: 0x10a00017  beqz        $a1, . + 4 + (0x17 << 2)
    ctx->pc = 0x1773CCu;
    {
        const bool branch_taken_0x1773cc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1773D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1773CCu;
            // 0x1773d0: 0x8c710238  lw          $s1, 0x238($v1) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 568)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1773cc) {
            ctx->pc = 0x17742Cu;
            goto label_17742c;
        }
    }
    ctx->pc = 0x1773D4u;
    // 0x1773d4: 0x2403fffb  addiu       $v1, $zero, -0x5
    ctx->pc = 0x1773d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967291));
    // 0x1773d8: 0x12230014  beq         $s1, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1773D8u;
    {
        const bool branch_taken_0x1773d8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 3));
        ctx->pc = 0x1773DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1773D8u;
            // 0x1773dc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1773d8) {
            ctx->pc = 0x17742Cu;
            goto label_17742c;
        }
    }
    ctx->pc = 0x1773E0u;
    // 0x1773e0: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1773e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1773e4: 0xc05d8d4  jal         func_176350
    ctx->pc = 0x1773E4u;
    SET_GPR_U32(ctx, 31, 0x1773ECu);
    ctx->pc = 0x1773E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1773E4u;
            // 0x1773e8: 0x27a60004  addiu       $a2, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176350u;
    if (runtime->hasFunction(0x176350u)) {
        auto targetFn = runtime->lookupFunction(0x176350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1773ECu; }
        if (ctx->pc != 0x1773ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176350_0x176350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1773ECu; }
        if (ctx->pc != 0x1773ECu) { return; }
    }
    ctx->pc = 0x1773ECu;
label_1773ec:
    // 0x1773ec: 0x3403ea24  ori         $v1, $zero, 0xEA24
    ctx->pc = 0x1773ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)59940);
    // 0x1773f0: 0x102140  sll         $a0, $s0, 5
    ctx->pc = 0x1773f0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 16), 5));
    // 0x1773f4: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1773F4u;
    {
        const bool branch_taken_0x1773f4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1773f4) {
            ctx->pc = 0x1773F8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1773F4u;
            // 0x1773f8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1773FCu;
            goto label_1773fc;
        }
    }
    ctx->pc = 0x1773FCu;
label_1773fc:
    // 0x1773fc: 0x902023  subu        $a0, $a0, $s0
    ctx->pc = 0x1773fcu;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x177400: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x177400u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x177404: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x177404u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x177408: 0x8fa70004  lw          $a3, 0x4($sp)
    ctx->pc = 0x177408u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x17740c: 0x902021  addu        $a0, $a0, $s0
    ctx->pc = 0x17740cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x177410: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x177410u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177414: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x177414u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x177418: 0x83001a  div         $zero, $a0, $v1
    ctx->pc = 0x177418u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x17741c: 0x2012  mflo        $a0
    ctx->pc = 0x17741cu;
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x177420: 0xc05407a  jal         func_1501E8
    ctx->pc = 0x177420u;
    SET_GPR_U32(ctx, 31, 0x177428u);
    ctx->pc = 0x177424u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177420u;
            // 0x177424: 0x2242021  addu        $a0, $s1, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1501E8u;
    if (runtime->hasFunction(0x1501E8u)) {
        auto targetFn = runtime->lookupFunction(0x1501E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177428u; }
        if (ctx->pc != 0x177428u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001501E8_0x1501e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177428u; }
        if (ctx->pc != 0x177428u) { return; }
    }
    ctx->pc = 0x177428u;
label_177428:
    // 0x177428: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x177428u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_17742c:
    // 0x17742c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x17742cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x177430: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x177430u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x177434: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x177434u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x177438: 0x3e00008  jr          $ra
    ctx->pc = 0x177438u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17743Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177438u;
            // 0x17743c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1773ECu: goto label_1773ec;
            case 0x1773FCu: goto label_1773fc;
            case 0x177428u: goto label_177428;
            case 0x17742Cu: goto label_17742c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x177440u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
