#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016B538
// Address: 0x16b538 - 0x16b5e8
void sub_0016B538_0x16b538(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016B538_0x16b538");
#endif

    switch (ctx->pc) {
        case 0x16b578u: goto label_16b578;
        case 0x16b58cu: goto label_16b58c;
        default: break;
    }

    ctx->pc = 0x16b538u;

    // 0x16b538: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x16b538u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x16b53c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x16b53cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x16b540: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x16b540u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b544: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x16b544u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x16b548: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x16b548u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b54c: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x16b54cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x16b550: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x16b550u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b554: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x16b554u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x16b558: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x16b558u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b55c: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x16b55cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x16b560: 0xc0b02d  daddu       $s6, $a2, $zero
    ctx->pc = 0x16b560u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b564: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x16b564u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x16b568: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x16b568u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x16b56c: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x16b56cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x16b570: 0x8c931aec  lw          $s3, 0x1AEC($a0)
    ctx->pc = 0x16b570u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6892)));
    // 0x16b574: 0x8e740000  lw          $s4, 0x0($s3)
    ctx->pc = 0x16b574u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
label_16b578:
    // 0x16b578: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x16b578u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b57c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x16b57cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x16b580: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x16b580u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b584: 0xc055f90  jal         func_157E40
    ctx->pc = 0x16B584u;
    SET_GPR_U32(ctx, 31, 0x16B58Cu);
    ctx->pc = 0x16B588u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B584u;
            // 0x16b588: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x157E40u;
    if (runtime->hasFunction(0x157E40u)) {
        auto targetFn = runtime->lookupFunction(0x157E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B58Cu; }
        if (ctx->pc != 0x16B58Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00157E40_0x157e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B58Cu; }
        if (ctx->pc != 0x16B58Cu) { return; }
    }
    ctx->pc = 0x16B58Cu;
label_16b58c:
    // 0x16b58c: 0x2a060003  slti        $a2, $s0, 0x3
    ctx->pc = 0x16b58cu;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x16b590: 0x8fa40008  lw          $a0, 0x8($sp)
    ctx->pc = 0x16b590u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b594: 0x8fa5000c  lw          $a1, 0xC($sp)
    ctx->pc = 0x16b594u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x16b598: 0x92102a  slt         $v0, $a0, $s2
    ctx->pc = 0x16b598u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x16b59c: 0xb1182a  slt         $v1, $a1, $s1
    ctx->pc = 0x16b59cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x16b5a0: 0x82900a  movz        $s2, $a0, $v0
    ctx->pc = 0x16b5a0u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 18, GPR_VEC(ctx, 4));
    // 0x16b5a4: 0x14c0fff4  bnez        $a2, . + 4 + (-0xC << 2)
    ctx->pc = 0x16B5A4u;
    {
        const bool branch_taken_0x16b5a4 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x16B5A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B5A4u;
            // 0x16b5a8: 0xa3880a  movz        $s1, $a1, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b5a4) {
            ctx->pc = 0x16B578u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16b578;
        }
    }
    ctx->pc = 0x16B5ACu;
    // 0x16b5ac: 0xae710004  sw          $s1, 0x4($s3)
    ctx->pc = 0x16b5acu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 17));
    // 0x16b5b0: 0xae720008  sw          $s2, 0x8($s3)
    ctx->pc = 0x16b5b0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 8), GPR_U32(ctx, 18));
    // 0x16b5b4: 0xaeb20000  sw          $s2, 0x0($s5)
    ctx->pc = 0x16b5b4u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 18));
    // 0x16b5b8: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x16b5b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16b5bc: 0x8e620004  lw          $v0, 0x4($s3)
    ctx->pc = 0x16b5bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x16b5c0: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x16b5c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16b5c4: 0xaec20000  sw          $v0, 0x0($s6)
    ctx->pc = 0x16b5c4u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 2));
    // 0x16b5c8: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x16b5c8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16b5cc: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x16b5ccu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16b5d0: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x16b5d0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16b5d4: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x16b5d4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x16b5d8: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x16b5d8u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x16b5dc: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x16b5dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x16b5e0: 0x3e00008  jr          $ra
    ctx->pc = 0x16B5E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16B5E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B5E0u;
            // 0x16b5e4: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16B578u: goto label_16b578;
            case 0x16B58Cu: goto label_16b58c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16B5E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
