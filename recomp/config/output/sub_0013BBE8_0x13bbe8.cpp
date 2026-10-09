#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013BBE8
// Address: 0x13bbe8 - 0x13bc34
void sub_0013BBE8_0x13bbe8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013BBE8_0x13bbe8");
#endif

    switch (ctx->pc) {
        case 0x13bc04u: goto label_13bc04;
        default: break;
    }

    ctx->pc = 0x13bbe8u;

    // 0x13bbe8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13bbe8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13bbec: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x13bbecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13bbf0: 0x14a00007  bnez        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x13BBF0u;
    {
        const bool branch_taken_0x13bbf0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x13BBF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BBF0u;
            // 0x13bbf4: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bbf0) {
            ctx->pc = 0x13BC10u;
            goto label_13bc10;
        }
    }
    ctx->pc = 0x13BBF8u;
    // 0x13bbf8: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13bbf8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x13bbfc: 0xc04ebf2  jal         func_13AFC8
    ctx->pc = 0x13BBFCu;
    SET_GPR_U32(ctx, 31, 0x13BC04u);
    ctx->pc = 0x13BC00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BBFCu;
            // 0x13bc00: 0x24a5d0b0  addiu       $a1, $a1, -0x2F50 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AFC8u;
    if (runtime->hasFunction(0x13AFC8u)) {
        auto targetFn = runtime->lookupFunction(0x13AFC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BC04u; }
        if (ctx->pc != 0x13BC04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AFC8_0x13afc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BC04u; }
        if (ctx->pc != 0x13BC04u) { return; }
    }
    ctx->pc = 0x13BC04u;
label_13bc04:
    // 0x13bc04: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x13BC04u;
    {
        const bool branch_taken_0x13bc04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13BC08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BC04u;
            // 0x13bc08: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bc04) {
            ctx->pc = 0x13BC28u;
            goto label_13bc28;
        }
    }
    ctx->pc = 0x13BC0Cu;
    // 0x13bc0c: 0x0  nop
    ctx->pc = 0x13bc0cu;
    // NOP
label_13bc10:
    // 0x13bc10: 0x80a30002  lb          $v1, 0x2($a1)
    ctx->pc = 0x13bc10u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x13bc14: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13bc14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13bc18: 0x54620003  bnel        $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13BC18u;
    {
        const bool branch_taken_0x13bc18 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x13bc18) {
            ctx->pc = 0x13BC1Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13BC18u;
            // 0x13bc1c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13BC28u;
            goto label_13bc28;
        }
    }
    ctx->pc = 0x13BC20u;
    // 0x13bc20: 0x8ca20028  lw          $v0, 0x28($a1)
    ctx->pc = 0x13bc20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 40)));
    // 0x13bc24: 0x212c0  sll         $v0, $v0, 11
    ctx->pc = 0x13bc24u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
label_13bc28:
    // 0x13bc28: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13bc28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13bc2c: 0x3e00008  jr          $ra
    ctx->pc = 0x13BC2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13BC30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BC2Cu;
            // 0x13bc30: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13BC04u: goto label_13bc04;
            case 0x13BC10u: goto label_13bc10;
            case 0x13BC28u: goto label_13bc28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13BC34u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
