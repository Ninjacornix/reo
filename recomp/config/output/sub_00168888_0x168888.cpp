#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00168888
// Address: 0x168888 - 0x168908
void sub_00168888_0x168888(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00168888_0x168888");
#endif

    switch (ctx->pc) {
        case 0x1688a8u: goto label_1688a8;
        case 0x1688dcu: goto label_1688dc;
        case 0x1688e4u: goto label_1688e4;
        default: break;
    }

    ctx->pc = 0x168888u;

    // 0x168888: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x168888u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16888c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16888cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x168890: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x168890u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168894: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x168894u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x168898: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x168898u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x16889c: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x16889cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1688a0: 0xc0560fc  jal         func_1583F0
    ctx->pc = 0x1688A0u;
    SET_GPR_U32(ctx, 31, 0x1688A8u);
    ctx->pc = 0x1688A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1688A0u;
            // 0x1688a4: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1583F0u;
    if (runtime->hasFunction(0x1583F0u)) {
        auto targetFn = runtime->lookupFunction(0x1583F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1688A8u; }
        if (ctx->pc != 0x1688A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001583F0_0x1583f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1688A8u; }
        if (ctx->pc != 0x1688A8u) { return; }
    }
    ctx->pc = 0x1688A8u;
label_1688a8:
    // 0x1688a8: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1688a8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1688ac: 0x2a020007  slti        $v0, $s0, 0x7
    ctx->pc = 0x1688acu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)7) ? 1 : 0);
    // 0x1688b0: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x1688b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1688b4: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1688b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1688b8: 0x202180b  movn        $v1, $s0, $v0
    ctx->pc = 0x1688b8u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 16));
    // 0x1688bc: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1688bcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1688c0: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x1688c0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1688c4: 0x27a80004  addiu       $t0, $sp, 0x4
    ctx->pc = 0x1688c4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x1688c8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1688c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1688cc: 0x12200007  beqz        $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1688CCu;
    {
        const bool branch_taken_0x1688cc = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1688D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1688CCu;
            // 0x1688d0: 0x2431021  addu        $v0, $s2, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1688cc) {
            ctx->pc = 0x1688ECu;
            goto label_1688ec;
        }
    }
    ctx->pc = 0x1688D4u;
    // 0x1688d4: 0xc055900  jal         func_156400
    ctx->pc = 0x1688D4u;
    SET_GPR_U32(ctx, 31, 0x1688DCu);
    ctx->pc = 0x156400u;
    if (runtime->hasFunction(0x156400u)) {
        auto targetFn = runtime->lookupFunction(0x156400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1688DCu; }
        if (ctx->pc != 0x1688DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00156400_0x156400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1688DCu; }
        if (ctx->pc != 0x1688DCu) { return; }
    }
    ctx->pc = 0x1688DCu;
label_1688dc:
    // 0x1688dc: 0xc05615a  jal         func_158568
    ctx->pc = 0x1688DCu;
    SET_GPR_U32(ctx, 31, 0x1688E4u);
    ctx->pc = 0x1688E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1688DCu;
            // 0x1688e0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158568u;
    if (runtime->hasFunction(0x158568u)) {
        auto targetFn = runtime->lookupFunction(0x158568u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1688E4u; }
        if (ctx->pc != 0x1688E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158568_0x158568(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1688E4u; }
        if (ctx->pc != 0x1688E4u) { return; }
    }
    ctx->pc = 0x1688E4u;
label_1688e4:
    // 0x1688e4: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1688e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1688e8: 0x2421021  addu        $v0, $s2, $v0
    ctx->pc = 0x1688e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
label_1688ec:
    // 0x1688ec: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1688ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1688f0: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1688f0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1688f4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1688f4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1688f8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1688f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1688fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1688FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x168900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1688FCu;
            // 0x168900: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1688A8u: goto label_1688a8;
            case 0x1688DCu: goto label_1688dc;
            case 0x1688E4u: goto label_1688e4;
            case 0x1688ECu: goto label_1688ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x168904u;
    // 0x168904: 0x0  nop
    ctx->pc = 0x168904u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
