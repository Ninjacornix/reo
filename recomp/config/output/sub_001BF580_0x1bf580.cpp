#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BF580
// Address: 0x1bf580 - 0x1bf660
void sub_001BF580_0x1bf580(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BF580_0x1bf580");
#endif

    switch (ctx->pc) {
        case 0x1bf5b0u: goto label_1bf5b0;
        case 0x1bf5bcu: goto label_1bf5bc;
        case 0x1bf5c4u: goto label_1bf5c4;
        case 0x1bf5e8u: goto label_1bf5e8;
        case 0x1bf610u: goto label_1bf610;
        case 0x1bf644u: goto label_1bf644;
        default: break;
    }

    ctx->pc = 0x1bf580u;

    // 0x1bf580: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1bf580u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1bf584: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bf584u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bf588: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1bf588u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1bf58c: 0x240600ac  addiu       $a2, $zero, 0xAC
    ctx->pc = 0x1bf58cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 172));
    // 0x1bf590: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1bf590u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1bf594: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1bf594u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1bf598: 0x3c120032  lui         $s2, 0x32
    ctx->pc = 0x1bf598u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)50 << 16));
    // 0x1bf59c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1bf59cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1bf5a0: 0x26526c50  addiu       $s2, $s2, 0x6C50
    ctx->pc = 0x1bf5a0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 27728));
    // 0x1bf5a4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bf5a4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bf5a8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1BF5A8u;
    SET_GPR_U32(ctx, 31, 0x1BF5B0u);
    ctx->pc = 0x1BF5ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF5A8u;
            // 0x1bf5ac: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF5B0u; }
        if (ctx->pc != 0x1BF5B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF5B0u; }
        if (ctx->pc != 0x1BF5B0u) { return; }
    }
    ctx->pc = 0x1BF5B0u;
label_1bf5b0:
    // 0x1bf5b0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bf5b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bf5b4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bf5b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bf5b8: 0xac226c60  sw          $v0, 0x6C60($at)
    ctx->pc = 0x1bf5b8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27744), GPR_U32(ctx, 2));
label_1bf5bc:
    // 0x1bf5bc: 0xc0602e2  jal         func_180B88
    ctx->pc = 0x1BF5BCu;
    SET_GPR_U32(ctx, 31, 0x1BF5C4u);
    ctx->pc = 0x1BF5C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF5BCu;
            // 0x1bf5c0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180B88u;
    if (runtime->hasFunction(0x180B88u)) {
        auto targetFn = runtime->lookupFunction(0x180B88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF5C4u; }
        if (ctx->pc != 0x1BF5C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180B88_0x180b88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF5C4u; }
        if (ctx->pc != 0x1BF5C4u) { return; }
    }
    ctx->pc = 0x1BF5C4u;
label_1bf5c4:
    // 0x1bf5c4: 0x0  nop
    ctx->pc = 0x1bf5c4u;
    // NOP
    // 0x1bf5c8: 0x0  nop
    ctx->pc = 0x1bf5c8u;
    // NOP
    // 0x1bf5cc: 0x0  nop
    ctx->pc = 0x1bf5ccu;
    // NOP
    // 0x1bf5d0: 0x440fffa  bltz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1BF5D0u;
    {
        const bool branch_taken_0x1bf5d0 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bf5d0) {
            ctx->pc = 0x1BF5BCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bf5bc;
        }
    }
    ctx->pc = 0x1BF5D8u;
    // 0x1bf5d8: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x1bf5d8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bf5dc: 0x27b10054  addiu       $s1, $sp, 0x54
    ctx->pc = 0x1bf5dcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 84));
    // 0x1bf5e0: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1BF5E0u;
    {
        const bool branch_taken_0x1bf5e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BF5E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF5E0u;
            // 0x1bf5e4: 0x27b00058  addiu       $s0, $sp, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 88));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bf5e0) {
            ctx->pc = 0x1BF628u;
            goto label_1bf628;
        }
    }
    ctx->pc = 0x1BF5E8u;
label_1bf5e8:
    // 0x1bf5e8: 0x26620002  addiu       $v0, $s3, 0x2
    ctx->pc = 0x1bf5e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
    // 0x1bf5ec: 0xafa30050  sw          $v1, 0x50($sp)
    ctx->pc = 0x1bf5ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 3));
    // 0x1bf5f0: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1bf5f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1bf5f4: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1bf5f4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1bf5f8: 0x131a00  sll         $v1, $s3, 8
    ctx->pc = 0x1bf5f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 8));
    // 0x1bf5fc: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1bf5fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1bf600: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1bf600u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1bf604: 0x24426b40  addiu       $v0, $v0, 0x6B40
    ctx->pc = 0x1bf604u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27456));
    // 0x1bf608: 0xc060364  jal         func_180D90
    ctx->pc = 0x1BF608u;
    SET_GPR_U32(ctx, 31, 0x1BF610u);
    ctx->pc = 0x1BF60Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF608u;
            // 0x1bf60c: 0x432821  addu        $a1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180D90u;
    if (runtime->hasFunction(0x180D90u)) {
        auto targetFn = runtime->lookupFunction(0x180D90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF610u; }
        if (ctx->pc != 0x1BF610u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180D90_0x180d90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF610u; }
        if (ctx->pc != 0x1BF610u) { return; }
    }
    ctx->pc = 0x1BF610u;
label_1bf610:
    // 0x1bf610: 0x3c030032  lui         $v1, 0x32
    ctx->pc = 0x1bf610u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)50 << 16));
    // 0x1bf614: 0x132080  sll         $a0, $s3, 2
    ctx->pc = 0x1bf614u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
    // 0x1bf618: 0x24636c40  addiu       $v1, $v1, 0x6C40
    ctx->pc = 0x1bf618u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 27712));
    // 0x1bf61c: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1bf61cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1bf620: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1bf620u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1bf624: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1bf624u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_1bf628:
    // 0x1bf628: 0x8e420010  lw          $v0, 0x10($s2)
    ctx->pc = 0x1bf628u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1bf62c: 0x262102a  slt         $v0, $s3, $v0
    ctx->pc = 0x1bf62cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1bf630: 0x1440ffed  bnez        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1BF630u;
    {
        const bool branch_taken_0x1bf630 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BF634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF630u;
            // 0x1bf634: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bf630) {
            ctx->pc = 0x1BF5E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bf5e8;
        }
    }
    ctx->pc = 0x1BF638u;
    // 0x1bf638: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1bf638u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1bf63c: 0xc040742  jal         func_101D08
    ctx->pc = 0x1BF63Cu;
    SET_GPR_U32(ctx, 31, 0x1BF644u);
    ctx->pc = 0x1BF640u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF63Cu;
            // 0x1bf640: 0x24846aa0  addiu       $a0, $a0, 0x6AA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 27296));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101D08u;
    if (runtime->hasFunction(0x101D08u)) {
        auto targetFn = runtime->lookupFunction(0x101D08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF644u; }
        if (ctx->pc != 0x1BF644u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101D08_0x101d08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF644u; }
        if (ctx->pc != 0x1BF644u) { return; }
    }
    ctx->pc = 0x1BF644u;
label_1bf644:
    // 0x1bf644: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1bf644u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1bf648: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1bf648u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1bf64c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1bf64cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1bf650: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1bf650u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bf654: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bf654u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bf658: 0x3e00008  jr          $ra
    ctx->pc = 0x1BF658u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BF65Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF658u;
            // 0x1bf65c: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BF5B0u: goto label_1bf5b0;
            case 0x1BF5BCu: goto label_1bf5bc;
            case 0x1BF5C4u: goto label_1bf5c4;
            case 0x1BF5E8u: goto label_1bf5e8;
            case 0x1BF610u: goto label_1bf610;
            case 0x1BF628u: goto label_1bf628;
            case 0x1BF644u: goto label_1bf644;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BF660u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
