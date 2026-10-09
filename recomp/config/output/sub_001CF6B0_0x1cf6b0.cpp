#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CF6B0
// Address: 0x1cf6b0 - 0x1cf740
void sub_001CF6B0_0x1cf6b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CF6B0_0x1cf6b0");
#endif

    switch (ctx->pc) {
        case 0x1cf6d8u: goto label_1cf6d8;
        case 0x1cf708u: goto label_1cf708;
        default: break;
    }

    ctx->pc = 0x1cf6b0u;

    // 0x1cf6b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cf6b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cf6b4: 0x80682d  daddu       $t5, $a0, $zero
    ctx->pc = 0x1cf6b4u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf6b8: 0x15a00003  bnez        $t5, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CF6B8u;
    {
        const bool branch_taken_0x1cf6b8 = (GPR_U64(ctx, 13) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CF6BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF6B8u;
            // 0x1cf6bc: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf6b8) {
            ctx->pc = 0x1CF6C8u;
            goto label_1cf6c8;
        }
    }
    ctx->pc = 0x1CF6C0u;
    // 0x1cf6c0: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1CF6C0u;
    {
        const bool branch_taken_0x1cf6c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF6C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF6C0u;
            // 0x1cf6c4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf6c0) {
            ctx->pc = 0x1CF72Cu;
            goto label_1cf72c;
        }
    }
    ctx->pc = 0x1CF6C8u;
label_1cf6c8:
    // 0x1cf6c8: 0x3c0c0034  lui         $t4, 0x34
    ctx->pc = 0x1cf6c8u;
    SET_GPR_S32(ctx, 12, (int32_t)((uint32_t)52 << 16));
    // 0x1cf6cc: 0x582d  daddu       $t3, $zero, $zero
    ctx->pc = 0x1cf6ccu;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf6d0: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1CF6D0u;
    {
        const bool branch_taken_0x1cf6d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF6D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF6D0u;
            // 0x1cf6d4: 0x258c1430  addiu       $t4, $t4, 0x1430 (Delay Slot)
        SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 5168));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf6d0) {
            ctx->pc = 0x1CF720u;
            goto label_1cf720;
        }
    }
    ctx->pc = 0x1CF6D8u;
label_1cf6d8:
    // 0x1cf6d8: 0x91820000  lbu         $v0, 0x0($t4)
    ctx->pc = 0x1cf6d8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x1cf6dc: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1CF6DCu;
    {
        const bool branch_taken_0x1cf6dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cf6dc) {
            ctx->pc = 0x1CF718u;
            goto label_1cf718;
        }
    }
    ctx->pc = 0x1CF6E4u;
    // 0x1cf6e4: 0x91820003  lbu         $v0, 0x3($t4)
    ctx->pc = 0x1cf6e4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 12), 3)));
    // 0x1cf6e8: 0x30420004  andi        $v0, $v0, 0x4
    ctx->pc = 0x1cf6e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x1cf6ec: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1CF6ECu;
    {
        const bool branch_taken_0x1cf6ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cf6ec) {
            ctx->pc = 0x1CF718u;
            goto label_1cf718;
        }
    }
    ctx->pc = 0x1CF6F4u;
    // 0x1cf6f4: 0x8d840004  lw          $a0, 0x4($t4)
    ctx->pc = 0x1cf6f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 4)));
    // 0x1cf6f8: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CF6F8u;
    {
        const bool branch_taken_0x1cf6f8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF6FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF6F8u;
            // 0x1cf6fc: 0x1a0282d  daddu       $a1, $t5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 13) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf6f8) {
            ctx->pc = 0x1CF718u;
            goto label_1cf718;
        }
    }
    ctx->pc = 0x1CF700u;
    // 0x1cf700: 0xc073d7c  jal         func_1CF5F0
    ctx->pc = 0x1CF700u;
    SET_GPR_U32(ctx, 31, 0x1CF708u);
    ctx->pc = 0x1CF5F0u;
    if (runtime->hasFunction(0x1CF5F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CF5F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF708u; }
        if (ctx->pc != 0x1CF708u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF5F0_0x1cf5f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF708u; }
        if (ctx->pc != 0x1CF708u) { return; }
    }
    ctx->pc = 0x1CF708u;
label_1cf708:
    // 0x1cf708: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CF708u;
    {
        const bool branch_taken_0x1cf708 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cf708) {
            ctx->pc = 0x1CF718u;
            goto label_1cf718;
        }
    }
    ctx->pc = 0x1CF710u;
    // 0x1cf710: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1CF710u;
    {
        const bool branch_taken_0x1cf710 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF710u;
            // 0x1cf714: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf710) {
            ctx->pc = 0x1CF72Cu;
            goto label_1cf72c;
        }
    }
    ctx->pc = 0x1CF718u;
label_1cf718:
    // 0x1cf718: 0x256b0001  addiu       $t3, $t3, 0x1
    ctx->pc = 0x1cf718u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
    // 0x1cf71c: 0x258c000c  addiu       $t4, $t4, 0xC
    ctx->pc = 0x1cf71cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 12));
label_1cf720:
    // 0x1cf720: 0x29620010  slti        $v0, $t3, 0x10
    ctx->pc = 0x1cf720u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 11) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1cf724: 0x1440ffec  bnez        $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x1CF724u;
    {
        const bool branch_taken_0x1cf724 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CF728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF724u;
            // 0x1cf728: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf724) {
            ctx->pc = 0x1CF6D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cf6d8;
        }
    }
    ctx->pc = 0x1CF72Cu;
label_1cf72c:
    // 0x1cf72c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cf72cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cf730: 0x3e00008  jr          $ra
    ctx->pc = 0x1CF730u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CF734u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF730u;
            // 0x1cf734: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CF6C8u: goto label_1cf6c8;
            case 0x1CF6D8u: goto label_1cf6d8;
            case 0x1CF708u: goto label_1cf708;
            case 0x1CF718u: goto label_1cf718;
            case 0x1CF720u: goto label_1cf720;
            case 0x1CF72Cu: goto label_1cf72c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CF738u;
    // 0x1cf738: 0x0  nop
    ctx->pc = 0x1cf738u;
    // NOP
    // 0x1cf73c: 0x0  nop
    ctx->pc = 0x1cf73cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
