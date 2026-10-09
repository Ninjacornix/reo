#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C16E8
// Address: 0x1c16e8 - 0x1c1724
void sub_001C16E8_0x1c16e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C16E8_0x1c16e8");
#endif

    switch (ctx->pc) {
        case 0x1c16f8u: goto label_1c16f8;
        case 0x1c1710u: goto label_1c1710;
        default: break;
    }

    ctx->pc = 0x1c16e8u;

    // 0x1c16e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c16e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c16ec: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c16ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c16f0: 0xc07057a  jal         func_1C15E8
    ctx->pc = 0x1C16F0u;
    SET_GPR_U32(ctx, 31, 0x1C16F8u);
    ctx->pc = 0x1C15E8u;
    if (runtime->hasFunction(0x1C15E8u)) {
        auto targetFn = runtime->lookupFunction(0x1C15E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C16F8u; }
        if (ctx->pc != 0x1C16F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C15E8_0x1c15e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C16F8u; }
        if (ctx->pc != 0x1C16F8u) { return; }
    }
    ctx->pc = 0x1C16F8u;
label_1c16f8:
    // 0x1c16f8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C16F8u;
    {
        const bool branch_taken_0x1c16f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C16FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C16F8u;
            // 0x1c16fc: 0x3c030023  lui         $v1, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c16f8) {
            ctx->pc = 0x1C1708u;
            goto label_1c1708;
        }
    }
    ctx->pc = 0x1C1700u;
    // 0x1c1700: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C1700u;
    {
        const bool branch_taken_0x1c1700 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1700u;
            // 0x1c1704: 0x906252d5  lbu         $v0, 0x52D5($v1) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 21205)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1700) {
            ctx->pc = 0x1C1718u;
            goto label_1c1718;
        }
    }
    ctx->pc = 0x1C1708u;
label_1c1708:
    // 0x1c1708: 0xc0451b4  jal         func_1146D0
    ctx->pc = 0x1C1708u;
    SET_GPR_U32(ctx, 31, 0x1C1710u);
    ctx->pc = 0x1C170Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1708u;
            // 0x1c170c: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1146D0u;
    if (runtime->hasFunction(0x1146D0u)) {
        auto targetFn = runtime->lookupFunction(0x1146D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1710u; }
        if (ctx->pc != 0x1C1710u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001146D0_0x1146d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1710u; }
        if (ctx->pc != 0x1C1710u) { return; }
    }
    ctx->pc = 0x1C1710u;
label_1c1710:
    // 0x1c1710: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1c1710u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1714: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x1c1714u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
label_1c1718:
    // 0x1c1718: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c1718u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c171c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C171Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C171Cu;
            // 0x1c1720: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C16F8u: goto label_1c16f8;
            case 0x1C1708u: goto label_1c1708;
            case 0x1C1710u: goto label_1c1710;
            case 0x1C1718u: goto label_1c1718;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1724u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
