#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2790
// Address: 0x1b2790 - 0x1b2810
void sub_001B2790_0x1b2790(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2790_0x1b2790");
#endif

    switch (ctx->pc) {
        case 0x1b27f4u: goto label_1b27f4;
        default: break;
    }

    ctx->pc = 0x1b2790u;

    // 0x1b2790: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b2790u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b2794: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b2794u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b2798: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b2798u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b279c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b279cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b27a0: 0x842268c8  lh          $v0, 0x68C8($at)
    ctx->pc = 0x1b27a0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 26824)));
    // 0x1b27a4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B27A4u;
    {
        const bool branch_taken_0x1b27a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B27A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B27A4u;
            // 0x1b27a8: 0x3c010031  lui         $at, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b27a4) {
            ctx->pc = 0x1B27B4u;
            goto label_1b27b4;
        }
    }
    ctx->pc = 0x1B27ACu;
    // 0x1b27ac: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1B27ACu;
    {
        const bool branch_taken_0x1b27ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B27B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B27ACu;
            // 0x1b27b0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b27ac) {
            ctx->pc = 0x1B27F8u;
            goto label_1b27f8;
        }
    }
    ctx->pc = 0x1B27B4u;
label_1b27b4:
    // 0x1b27b4: 0x2444ffff  addiu       $a0, $v0, -0x1
    ctx->pc = 0x1b27b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1b27b8: 0x8c2366b0  lw          $v1, 0x66B0($at)
    ctx->pc = 0x1b27b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26288)));
    // 0x1b27bc: 0x3c020031  lui         $v0, 0x31
    ctx->pc = 0x1b27bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49 << 16));
    // 0x1b27c0: 0x244268e0  addiu       $v0, $v0, 0x68E0
    ctx->pc = 0x1b27c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26848));
    // 0x1b27c4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b27c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b27c8: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x1b27c8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1b27cc: 0x94670000  lhu         $a3, 0x0($v1)
    ctx->pc = 0x1b27ccu;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b27d0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b27d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b27d4: 0x24630002  addiu       $v1, $v1, 0x2
    ctx->pc = 0x1b27d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x1b27d8: 0xac2366b0  sw          $v1, 0x66B0($at)
    ctx->pc = 0x1b27d8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26288), GPR_U32(ctx, 3));
    // 0x1b27dc: 0x71940  sll         $v1, $a3, 5
    ctx->pc = 0x1b27dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 5));
    // 0x1b27e0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b27e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b27e4: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x1b27e4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b27e8: 0xa42468c8  sh          $a0, 0x68C8($at)
    ctx->pc = 0x1b27e8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26824), (uint16_t)GPR_U32(ctx, 4));
    // 0x1b27ec: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B27ECu;
    SET_GPR_U32(ctx, 31, 0x1B27F4u);
    ctx->pc = 0x1B27F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B27ECu;
            // 0x1b27f0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B27F4u; }
        if (ctx->pc != 0x1B27F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B27F4u; }
        if (ctx->pc != 0x1B27F4u) { return; }
    }
    ctx->pc = 0x1B27F4u;
label_1b27f4:
    // 0x1b27f4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1b27f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1b27f8:
    // 0x1b27f8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b27f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b27fc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b27fcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b2800: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2800u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B2804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2800u;
            // 0x1b2804: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B27B4u: goto label_1b27b4;
            case 0x1B27F4u: goto label_1b27f4;
            case 0x1B27F8u: goto label_1b27f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B2808u;
    // 0x1b2808: 0x0  nop
    ctx->pc = 0x1b2808u;
    // NOP
    // 0x1b280c: 0x0  nop
    ctx->pc = 0x1b280cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
