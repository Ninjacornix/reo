#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF7A0
// Address: 0x1af7a0 - 0x1af850
void sub_001AF7A0_0x1af7a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF7A0_0x1af7a0");
#endif

    switch (ctx->pc) {
        case 0x1af7c8u: goto label_1af7c8;
        case 0x1af7f4u: goto label_1af7f4;
        case 0x1af818u: goto label_1af818;
        default: break;
    }

    ctx->pc = 0x1af7a0u;

    // 0x1af7a0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1af7a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1af7a4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1af7a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1af7a8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1af7a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1af7ac: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1af7acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1af7b0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1af7b0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1af7b4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1af7b4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1af7b8: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1af7b8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1af7bc: 0x3c10002c  lui         $s0, 0x2C
    ctx->pc = 0x1af7bcu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)44 << 16));
    // 0x1af7c0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1AF7C0u;
    {
        const bool branch_taken_0x1af7c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AF7C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF7C0u;
            // 0x1af7c4: 0x26108e50  addiu       $s0, $s0, -0x71B0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294938192));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1af7c0) {
            ctx->pc = 0x1AF7DCu;
            goto label_1af7dc;
        }
    }
    ctx->pc = 0x1AF7C8u;
label_1af7c8:
    // 0x1af7c8: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1af7c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1af7cc: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1AF7CCu;
    {
        const bool branch_taken_0x1af7cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AF7D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF7CCu;
            // 0x1af7d0: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1af7cc) {
            ctx->pc = 0x1AF7ECu;
            goto label_1af7ec;
        }
    }
    ctx->pc = 0x1AF7D4u;
    // 0x1af7d4: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1af7d4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1af7d8: 0x26100008  addiu       $s0, $s0, 0x8
    ctx->pc = 0x1af7d8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
label_1af7dc:
    // 0x1af7dc: 0x2a220008  slti        $v0, $s1, 0x8
    ctx->pc = 0x1af7dcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1af7e0: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1AF7E0u;
    {
        const bool branch_taken_0x1af7e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1af7e0) {
            ctx->pc = 0x1AF7C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1af7c8;
        }
    }
    ctx->pc = 0x1AF7E8u;
    // 0x1af7e8: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1af7e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_1af7ec:
    // 0x1af7ec: 0x16220008  bne         $s1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1AF7ECu;
    {
        const bool branch_taken_0x1af7ec = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x1AF7F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF7ECu;
            // 0x1af7f0: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1af7ec) {
            ctx->pc = 0x1AF810u;
            goto label_1af810;
        }
    }
    ctx->pc = 0x1AF7F4u;
label_1af7f4:
    // 0x1af7f4: 0x0  nop
    ctx->pc = 0x1af7f4u;
    // NOP
    // 0x1af7f8: 0x0  nop
    ctx->pc = 0x1af7f8u;
    // NOP
    // 0x1af7fc: 0x0  nop
    ctx->pc = 0x1af7fcu;
    // NOP
    // 0x1af800: 0x0  nop
    ctx->pc = 0x1af800u;
    // NOP
    // 0x1af804: 0x0  nop
    ctx->pc = 0x1af804u;
    // NOP
    // 0x1af808: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AF808u;
    {
        const bool branch_taken_0x1af808 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1af808) {
            ctx->pc = 0x1AF7F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1af7f4;
        }
    }
    ctx->pc = 0x1AF810u;
label_1af810:
    // 0x1af810: 0xc063700  jal         func_18DC00
    ctx->pc = 0x1AF810u;
    SET_GPR_U32(ctx, 31, 0x1AF818u);
    ctx->pc = 0x18DC00u;
    if (runtime->hasFunction(0x18DC00u)) {
        auto targetFn = runtime->lookupFunction(0x18DC00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF818u; }
        if (ctx->pc != 0x1AF818u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC00_0x18dc00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF818u; }
        if (ctx->pc != 0x1AF818u) { return; }
    }
    ctx->pc = 0x1AF818u;
label_1af818:
    // 0x1af818: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1af818u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1af81c: 0x8c238dd8  lw          $v1, -0x7228($at)
    ctx->pc = 0x1af81cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938072)));
    // 0x1af820: 0x71082a  slt         $at, $v1, $s1
    ctx->pc = 0x1af820u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x1af824: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1AF824u;
    {
        const bool branch_taken_0x1af824 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AF828u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF824u;
            // 0x1af828: 0x3c01002c  lui         $at, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1af824) {
            ctx->pc = 0x1AF830u;
            goto label_1af830;
        }
    }
    ctx->pc = 0x1AF82Cu;
    // 0x1af82c: 0xac318dd8  sw          $s1, -0x7228($at)
    ctx->pc = 0x1af82cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938072), GPR_U32(ctx, 17));
label_1af830:
    // 0x1af830: 0xae120000  sw          $s2, 0x0($s0)
    ctx->pc = 0x1af830u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
    // 0x1af834: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1af834u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1af838: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1af838u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1af83c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1af83cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1af840: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1af840u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1af844: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF844u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AF848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF844u;
            // 0x1af848: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AF7C8u: goto label_1af7c8;
            case 0x1AF7DCu: goto label_1af7dc;
            case 0x1AF7ECu: goto label_1af7ec;
            case 0x1AF7F4u: goto label_1af7f4;
            case 0x1AF810u: goto label_1af810;
            case 0x1AF818u: goto label_1af818;
            case 0x1AF830u: goto label_1af830;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AF84Cu;
    // 0x1af84c: 0x0  nop
    ctx->pc = 0x1af84cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
