#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016C780
// Address: 0x16c780 - 0x16c7f0
void sub_0016C780_0x16c780(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016C780_0x16c780");
#endif

    switch (ctx->pc) {
        case 0x16c798u: goto label_16c798;
        case 0x16c7a4u: goto label_16c7a4;
        case 0x16c7c0u: goto label_16c7c0;
        default: break;
    }

    ctx->pc = 0x16c780u;

    // 0x16c780: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16c780u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16c784: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x16c784u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x16c788: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16c788u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16c78c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16c78cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c790: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16c790u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c794: 0x0  nop
    ctx->pc = 0x16c794u;
    // NOP
label_16c798:
    // 0x16c798: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x16c798u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c79c: 0xc05b1fc  jal         func_16C7F0
    ctx->pc = 0x16C79Cu;
    SET_GPR_U32(ctx, 31, 0x16C7A4u);
    ctx->pc = 0x16C7A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C79Cu;
            // 0x16c7a0: 0x27a60004  addiu       $a2, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16C7F0u;
    if (runtime->hasFunction(0x16C7F0u)) {
        auto targetFn = runtime->lookupFunction(0x16C7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C7A4u; }
        if (ctx->pc != 0x16C7A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016C7F0_0x16c7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C7A4u; }
        if (ctx->pc != 0x16C7A4u) { return; }
    }
    ctx->pc = 0x16C7A4u;
label_16c7a4:
    // 0x16c7a4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16c7a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c7a8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x16c7a8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c7ac: 0x1460000a  bnez        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x16C7ACu;
    {
        const bool branch_taken_0x16c7ac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x16C7B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C7ACu;
            // 0x16c7b0: 0x27a70008  addiu       $a3, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c7ac) {
            ctx->pc = 0x16C7D8u;
            goto label_16c7d8;
        }
    }
    ctx->pc = 0x16C7B4u;
    // 0x16c7b4: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x16c7b4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c7b8: 0xc05b3d6  jal         func_16CF58
    ctx->pc = 0x16C7B8u;
    SET_GPR_U32(ctx, 31, 0x16C7C0u);
    ctx->pc = 0x16C7BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C7B8u;
            // 0x16c7bc: 0x8fa60004  lw          $a2, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16CF58u;
    if (runtime->hasFunction(0x16CF58u)) {
        auto targetFn = runtime->lookupFunction(0x16CF58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C7C0u; }
        if (ctx->pc != 0x16C7C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016CF58_0x16cf58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C7C0u; }
        if (ctx->pc != 0x16C7C0u) { return; }
    }
    ctx->pc = 0x16C7C0u;
label_16c7c0:
    // 0x16c7c0: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x16c7c0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c7c4: 0x54600005  bnel        $v1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x16C7C4u;
    {
        const bool branch_taken_0x16c7c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x16c7c4) {
            ctx->pc = 0x16C7C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16C7C4u;
            // 0x16c7c8: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16C7DCu;
            goto label_16c7dc;
        }
    }
    ctx->pc = 0x16C7CCu;
    // 0x16c7cc: 0x8fa20008  lw          $v0, 0x8($sp)
    ctx->pc = 0x16c7ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c7d0: 0x1440fff1  bnez        $v0, . + 4 + (-0xF << 2)
    ctx->pc = 0x16C7D0u;
    {
        const bool branch_taken_0x16c7d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16C7D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C7D0u;
            // 0x16c7d4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c7d0) {
            ctx->pc = 0x16C798u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16c798;
        }
    }
    ctx->pc = 0x16C7D8u;
label_16c7d8:
    // 0x16c7d8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16c7d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_16c7dc:
    // 0x16c7dc: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x16c7dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c7e0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16c7e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16c7e4: 0x3e00008  jr          $ra
    ctx->pc = 0x16C7E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16C7E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C7E4u;
            // 0x16c7e8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16C798u: goto label_16c798;
            case 0x16C7A4u: goto label_16c7a4;
            case 0x16C7C0u: goto label_16c7c0;
            case 0x16C7D8u: goto label_16c7d8;
            case 0x16C7DCu: goto label_16c7dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C7ECu;
    // 0x16c7ec: 0x0  nop
    ctx->pc = 0x16c7ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
