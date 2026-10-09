#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D5A0
// Address: 0x15d5a0 - 0x15d640
void sub_0015D5A0_0x15d5a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D5A0_0x15d5a0");
#endif

    switch (ctx->pc) {
        case 0x15d5d0u: goto label_15d5d0;
        case 0x15d5f4u: goto label_15d5f4;
        case 0x15d608u: goto label_15d608;
        case 0x15d628u: goto label_15d628;
        default: break;
    }

    ctx->pc = 0x15d5a0u;

    // 0x15d5a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15d5a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15d5a4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15d5a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15d5a8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x15d5a8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d5ac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15d5acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15d5b0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15d5b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15d5b4: 0x8e220168  lw          $v0, 0x168($s1)
    ctx->pc = 0x15d5b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 360)));
    // 0x15d5b8: 0x28420020  slti        $v0, $v0, 0x20
    ctx->pc = 0x15d5b8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x15d5bc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15D5BCu;
    {
        const bool branch_taken_0x15d5bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15D5C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D5BCu;
            // 0x15d5c0: 0xa0182d  daddu       $v1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d5bc) {
            ctx->pc = 0x15D5D8u;
            goto label_15d5d8;
        }
    }
    ctx->pc = 0x15D5C4u;
    // 0x15d5c4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15d5c4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15d5c8: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15D5C8u;
    SET_GPR_U32(ctx, 31, 0x15D5D0u);
    ctx->pc = 0x15D5CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D5C8u;
            // 0x15d5cc: 0x2484ebc8  addiu       $a0, $a0, -0x1438 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962120));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D5D0u; }
        if (ctx->pc != 0x15D5D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D5D0u; }
        if (ctx->pc != 0x15D5D0u) { return; }
    }
    ctx->pc = 0x15D5D0u;
label_15d5d0:
    // 0x15d5d0: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x15D5D0u;
    {
        const bool branch_taken_0x15d5d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D5D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D5D0u;
            // 0x15d5d4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d5d0) {
            ctx->pc = 0x15D62Cu;
            goto label_15d62c;
        }
    }
    ctx->pc = 0x15D5D8u;
label_15d5d8:
    // 0x15d5d8: 0x4600014  bltz        $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x15D5D8u;
    {
        const bool branch_taken_0x15d5d8 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x15D5DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D5D8u;
            // 0x15d5dc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d5d8) {
            ctx->pc = 0x15D62Cu;
            goto label_15d62c;
        }
    }
    ctx->pc = 0x15D5E0u;
    // 0x15d5e0: 0x8e220158  lw          $v0, 0x158($s1)
    ctx->pc = 0x15d5e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 344)));
    // 0x15d5e4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15D5E4u;
    {
        const bool branch_taken_0x15d5e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x15d5e4) {
            ctx->pc = 0x15D600u;
            goto label_15d600;
        }
    }
    ctx->pc = 0x15D5ECu;
    // 0x15d5ec: 0xc057590  jal         func_15D640
    ctx->pc = 0x15D5ECu;
    SET_GPR_U32(ctx, 31, 0x15D5F4u);
    ctx->pc = 0x15D640u;
    if (runtime->hasFunction(0x15D640u)) {
        auto targetFn = runtime->lookupFunction(0x15D640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D5F4u; }
        if (ctx->pc != 0x15D5F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D640_0x15d640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D5F4u; }
        if (ctx->pc != 0x15D5F4u) { return; }
    }
    ctx->pc = 0x15D5F4u;
label_15d5f4:
    // 0x15d5f4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x15D5F4u;
    {
        const bool branch_taken_0x15d5f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D5F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D5F4u;
            // 0x15d5f8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d5f4) {
            ctx->pc = 0x15D60Cu;
            goto label_15d60c;
        }
    }
    ctx->pc = 0x15D5FCu;
    // 0x15d5fc: 0x0  nop
    ctx->pc = 0x15d5fcu;
    // NOP
label_15d600:
    // 0x15d600: 0xc05759e  jal         func_15D678
    ctx->pc = 0x15D600u;
    SET_GPR_U32(ctx, 31, 0x15D608u);
    ctx->pc = 0x15D604u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D600u;
            // 0x15d604: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D678u;
    if (runtime->hasFunction(0x15D678u)) {
        auto targetFn = runtime->lookupFunction(0x15D678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D608u; }
        if (ctx->pc != 0x15D608u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D678_0x15d678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D608u; }
        if (ctx->pc != 0x15D608u) { return; }
    }
    ctx->pc = 0x15D608u;
label_15d608:
    // 0x15d608: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x15d608u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_15d60c:
    // 0x15d60c: 0x12000006  beqz        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15D60Cu;
    {
        const bool branch_taken_0x15d60c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D610u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D60Cu;
            // 0x15d610: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d60c) {
            ctx->pc = 0x15D628u;
            goto label_15d628;
        }
    }
    ctx->pc = 0x15D614u;
    // 0x15d614: 0x8e220168  lw          $v0, 0x168($s1)
    ctx->pc = 0x15d614u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 360)));
    // 0x15d618: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x15d618u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x15d61c: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x15d61cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x15d620: 0xc0575e8  jal         func_15D7A0
    ctx->pc = 0x15D620u;
    SET_GPR_U32(ctx, 31, 0x15D628u);
    ctx->pc = 0x15D624u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D620u;
            // 0x15d624: 0xac50016c  sw          $s0, 0x16C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 364), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D7A0u;
    if (runtime->hasFunction(0x15D7A0u)) {
        auto targetFn = runtime->lookupFunction(0x15D7A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D628u; }
        if (ctx->pc != 0x15D628u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D7A0_0x15d7a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D628u; }
        if (ctx->pc != 0x15D628u) { return; }
    }
    ctx->pc = 0x15D628u;
label_15d628:
    // 0x15d628: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x15d628u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_15d62c:
    // 0x15d62c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15d62cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15d630: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15d630u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15d634: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15d634u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15d638: 0x3e00008  jr          $ra
    ctx->pc = 0x15D638u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D63Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D638u;
            // 0x15d63c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D5D0u: goto label_15d5d0;
            case 0x15D5D8u: goto label_15d5d8;
            case 0x15D5F4u: goto label_15d5f4;
            case 0x15D600u: goto label_15d600;
            case 0x15D608u: goto label_15d608;
            case 0x15D60Cu: goto label_15d60c;
            case 0x15D628u: goto label_15d628;
            case 0x15D62Cu: goto label_15d62c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D640u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
