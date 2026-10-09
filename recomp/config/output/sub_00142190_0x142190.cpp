#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00142190
// Address: 0x142190 - 0x142240
void sub_00142190_0x142190(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00142190_0x142190");
#endif

    switch (ctx->pc) {
        case 0x1421b4u: goto label_1421b4;
        case 0x1421c8u: goto label_1421c8;
        case 0x1421e0u: goto label_1421e0;
        case 0x1421f8u: goto label_1421f8;
        default: break;
    }

    ctx->pc = 0x142190u;

    // 0x142190: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x142190u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x142194: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x142194u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x142198: 0x8c4249f8  lw          $v0, 0x49F8($v0)
    ctx->pc = 0x142198u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18936)));
    // 0x14219c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x14219cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1421a0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1421a0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1421a4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1421A4u;
    {
        const bool branch_taken_0x1421a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1421A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1421A4u;
            // 0x1421a8: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1421a4) {
            ctx->pc = 0x1421C0u;
            goto label_1421c0;
        }
    }
    ctx->pc = 0x1421ACu;
    // 0x1421ac: 0x40f809  jalr        $v0
    ctx->pc = 0x1421ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1421B4u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1421B4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1421B4u: goto label_1421b4;
            case 0x1421C0u: goto label_1421c0;
            case 0x1421C8u: goto label_1421c8;
            case 0x1421E0u: goto label_1421e0;
            case 0x1421F8u: goto label_1421f8;
            case 0x142214u: goto label_142214;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1421B4u; }
            if (ctx->pc != 0x1421B4u) { return; }
        }
        }
    }
    ctx->pc = 0x1421B4u;
label_1421b4:
    // 0x1421b4: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1421B4u;
    {
        const bool branch_taken_0x1421b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1421B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1421B4u;
            // 0x1421b8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1421b4) {
            ctx->pc = 0x1421E0u;
            goto label_1421e0;
        }
    }
    ctx->pc = 0x1421BCu;
    // 0x1421bc: 0x0  nop
    ctx->pc = 0x1421bcu;
    // NOP
label_1421c0:
    // 0x1421c0: 0xc0505b4  jal         func_1416D0
    ctx->pc = 0x1421C0u;
    SET_GPR_U32(ctx, 31, 0x1421C8u);
    ctx->pc = 0x1416D0u;
    if (runtime->hasFunction(0x1416D0u)) {
        auto targetFn = runtime->lookupFunction(0x1416D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1421C8u; }
        if (ctx->pc != 0x1421C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416D0_0x1416d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1421C8u; }
        if (ctx->pc != 0x1421C8u) { return; }
    }
    ctx->pc = 0x1421C8u;
label_1421c8:
    // 0x1421c8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1421c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1421cc: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1421ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1421d0: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x1421d0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x1421d4: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1421d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1421d8: 0xc0505ba  jal         func_1416E8
    ctx->pc = 0x1421D8u;
    SET_GPR_U32(ctx, 31, 0x1421E0u);
    ctx->pc = 0x1421DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1421D8u;
            // 0x1421dc: 0x2802b  sltu        $s0, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1421E0u; }
        if (ctx->pc != 0x1421E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416E8_0x1416e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1421E0u; }
        if (ctx->pc != 0x1421E0u) { return; }
    }
    ctx->pc = 0x1421E0u;
label_1421e0:
    // 0x1421e0: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1421e0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1421e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1421e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1421e8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1421e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1421ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1421ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1421F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1421ECu;
            // 0x1421f0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1421B4u: goto label_1421b4;
            case 0x1421C0u: goto label_1421c0;
            case 0x1421C8u: goto label_1421c8;
            case 0x1421E0u: goto label_1421e0;
            case 0x1421F8u: goto label_1421f8;
            case 0x142214u: goto label_142214;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1421F4u;
    // 0x1421f4: 0x0  nop
    ctx->pc = 0x1421f4u;
    // NOP
label_1421f8:
    // 0x1421f8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1421f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1421fc: 0x244549f8  addiu       $a1, $v0, 0x49F8
    ctx->pc = 0x1421fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 18936));
    // 0x142200: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x142200u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x142204: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x142204u;
    {
        const bool branch_taken_0x142204 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x142208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142204u;
            // 0x142208: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142204) {
            ctx->pc = 0x142214u;
            goto label_142214;
        }
    }
    ctx->pc = 0x14220Cu;
    // 0x14220c: 0xaca40000  sw          $a0, 0x0($a1)
    ctx->pc = 0x14220cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4));
    // 0x142210: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x142210u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_142214:
    // 0x142214: 0x3e00008  jr          $ra
    ctx->pc = 0x142214u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1421B4u: goto label_1421b4;
            case 0x1421C0u: goto label_1421c0;
            case 0x1421C8u: goto label_1421c8;
            case 0x1421E0u: goto label_1421e0;
            case 0x1421F8u: goto label_1421f8;
            case 0x142214u: goto label_142214;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14221Cu;
    // 0x14221c: 0x0  nop
    ctx->pc = 0x14221cu;
    // NOP
    // 0x142220: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x142220u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x142224: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x142224u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142228: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x142228u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x14222c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x14222cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x142230: 0x805087e  j           func_1421F8
    ctx->pc = 0x142230u;
    ctx->pc = 0x142234u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142230u;
            // 0x142234: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1421F8u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1421f8;
    ctx->pc = 0x142238u;
    // 0x142238: 0x0  nop
    ctx->pc = 0x142238u;
    // NOP
    // 0x14223c: 0x0  nop
    ctx->pc = 0x14223cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
