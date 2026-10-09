#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00168578
// Address: 0x168578 - 0x168610
void sub_00168578_0x168578(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00168578_0x168578");
#endif

    switch (ctx->pc) {
        case 0x1685a0u: goto label_1685a0;
        case 0x1685c4u: goto label_1685c4;
        case 0x1685e4u: goto label_1685e4;
        case 0x1685ecu: goto label_1685ec;
        default: break;
    }

    ctx->pc = 0x168578u;

    // 0x168578: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x168578u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x16857c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x16857cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x168580: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x168580u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168584: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x168584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x168588: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x168588u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16858c: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x16858cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x168590: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x168590u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x168594: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x168594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x168598: 0xc0560fc  jal         func_1583F0
    ctx->pc = 0x168598u;
    SET_GPR_U32(ctx, 31, 0x1685A0u);
    ctx->pc = 0x16859Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168598u;
            // 0x16859c: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1583F0u;
    if (runtime->hasFunction(0x1583F0u)) {
        auto targetFn = runtime->lookupFunction(0x1583F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1685A0u; }
        if (ctx->pc != 0x1685A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001583F0_0x1583f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1685A0u; }
        if (ctx->pc != 0x1685A0u) { return; }
    }
    ctx->pc = 0x1685A0u;
label_1685a0:
    // 0x1685a0: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1685a0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1685a4: 0x27a70010  addiu       $a3, $sp, 0x10
    ctx->pc = 0x1685a4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1685a8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1685a8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1685ac: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1685acu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1685b0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1685b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1685b4: 0x1240000f  beqz        $s2, . + 4 + (0xF << 2)
    ctx->pc = 0x1685B4u;
    {
        const bool branch_taken_0x1685b4 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x1685B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1685B4u;
            // 0x1685b8: 0x27a80014  addiu       $t0, $sp, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1685b4) {
            ctx->pc = 0x1685F4u;
            goto label_1685f4;
        }
    }
    ctx->pc = 0x1685BCu;
    // 0x1685bc: 0xc055900  jal         func_156400
    ctx->pc = 0x1685BCu;
    SET_GPR_U32(ctx, 31, 0x1685C4u);
    ctx->pc = 0x156400u;
    if (runtime->hasFunction(0x156400u)) {
        auto targetFn = runtime->lookupFunction(0x156400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1685C4u; }
        if (ctx->pc != 0x1685C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00156400_0x156400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1685C4u; }
        if (ctx->pc != 0x1685C4u) { return; }
    }
    ctx->pc = 0x1685C4u;
label_1685c4:
    // 0x1685c4: 0x3c030001  lui         $v1, 0x1
    ctx->pc = 0x1685c4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0x1685c8: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x1685c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1685cc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1685ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1685d0: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x1685d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1685d4: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1685D4u;
    {
        const bool branch_taken_0x1685d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1685D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1685D4u;
            // 0x1685d8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1685d4) {
            ctx->pc = 0x1685F4u;
            goto label_1685f4;
        }
    }
    ctx->pc = 0x1685DCu;
    // 0x1685dc: 0xc055f74  jal         func_157DD0
    ctx->pc = 0x1685DCu;
    SET_GPR_U32(ctx, 31, 0x1685E4u);
    ctx->pc = 0x157DD0u;
    if (runtime->hasFunction(0x157DD0u)) {
        auto targetFn = runtime->lookupFunction(0x157DD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1685E4u; }
        if (ctx->pc != 0x1685E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00157DD0_0x157dd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1685E4u; }
        if (ctx->pc != 0x1685E4u) { return; }
    }
    ctx->pc = 0x1685E4u;
label_1685e4:
    // 0x1685e4: 0xc05615a  jal         func_158568
    ctx->pc = 0x1685E4u;
    SET_GPR_U32(ctx, 31, 0x1685ECu);
    ctx->pc = 0x1685E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1685E4u;
            // 0x1685e8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158568u;
    if (runtime->hasFunction(0x158568u)) {
        auto targetFn = runtime->lookupFunction(0x158568u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1685ECu; }
        if (ctx->pc != 0x1685ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158568_0x158568(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1685ECu; }
        if (ctx->pc != 0x1685ECu) { return; }
    }
    ctx->pc = 0x1685ECu;
label_1685ec:
    // 0x1685ec: 0x8fa30008  lw          $v1, 0x8($sp)
    ctx->pc = 0x1685ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1685f0: 0xae630000  sw          $v1, 0x0($s3)
    ctx->pc = 0x1685f0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
label_1685f4:
    // 0x1685f4: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x1685f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1685f8: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x1685f8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1685fc: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x1685fcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x168600: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x168600u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x168604: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x168604u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x168608: 0x3e00008  jr          $ra
    ctx->pc = 0x168608u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16860Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168608u;
            // 0x16860c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1685A0u: goto label_1685a0;
            case 0x1685C4u: goto label_1685c4;
            case 0x1685E4u: goto label_1685e4;
            case 0x1685ECu: goto label_1685ec;
            case 0x1685F4u: goto label_1685f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x168610u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
