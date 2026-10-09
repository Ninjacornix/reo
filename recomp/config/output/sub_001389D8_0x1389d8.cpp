#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001389D8
// Address: 0x1389d8 - 0x138ab8
void sub_001389D8_0x1389d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001389D8_0x1389d8");
#endif

    switch (ctx->pc) {
        case 0x138a00u: goto label_138a00;
        case 0x138a14u: goto label_138a14;
        case 0x138a5cu: goto label_138a5c;
        case 0x138a7cu: goto label_138a7c;
        default: break;
    }

    ctx->pc = 0x1389d8u;

    // 0x1389d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1389d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1389dc: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1389dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x1389e0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1389e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1389e4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1389e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1389e8: 0x2450bc08  addiu       $s0, $v0, -0x43F8
    ctx->pc = 0x1389e8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949896));
    // 0x1389ec: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1389ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1389f0: 0x2411001f  addiu       $s1, $zero, 0x1F
    ctx->pc = 0x1389f0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x1389f4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1389f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1389f8: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x1389f8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1389fc: 0x0  nop
    ctx->pc = 0x1389fcu;
    // NOP
label_138a00:
    // 0x138a00: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x138a00u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x138a04: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x138A04u;
    {
        const bool branch_taken_0x138a04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x138a04) {
            ctx->pc = 0x138A08u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x138A04u;
            // 0x138a08: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x138A18u;
            goto label_138a18;
        }
    }
    ctx->pc = 0x138A0Cu;
    // 0x138a0c: 0xc04e194  jal         func_138650
    ctx->pc = 0x138A0Cu;
    SET_GPR_U32(ctx, 31, 0x138A14u);
    ctx->pc = 0x138A10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138A0Cu;
            // 0x138a10: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138650u;
    if (runtime->hasFunction(0x138650u)) {
        auto targetFn = runtime->lookupFunction(0x138650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138A14u; }
        if (ctx->pc != 0x138A14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138650_0x138650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138A14u; }
        if (ctx->pc != 0x138A14u) { return; }
    }
    ctx->pc = 0x138A14u;
label_138a14:
    // 0x138a14: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x138a14u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_138a18:
    // 0x138a18: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x138A18u;
    {
        const bool branch_taken_0x138a18 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x138A1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138A18u;
            // 0x138a1c: 0x26100040  addiu       $s0, $s0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138a18) {
            ctx->pc = 0x138A00u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_138a00;
        }
    }
    ctx->pc = 0x138A20u;
    // 0x138a20: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x138a20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138a24: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x138a24u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x138a28: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x138a28u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x138a2c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x138a2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x138a30: 0x804e55a  j           func_139568
    ctx->pc = 0x138A30u;
    ctx->pc = 0x138A34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138A30u;
            // 0x138a34: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139568u;
    if (runtime->hasFunction(0x139568u)) {
        auto targetFn = runtime->lookupFunction(0x139568u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00139568_0x139568(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x138A38u;
    // 0x138a38: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x138a38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x138a3c: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x138a3cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x138a40: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x138a40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x138a44: 0x2450bc04  addiu       $s0, $v0, -0x43FC
    ctx->pc = 0x138a44u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949892));
    // 0x138a48: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x138a48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x138a4c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138a4cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138a50: 0x2484c8e0  addiu       $a0, $a0, -0x3720
    ctx->pc = 0x138a50u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953184));
    // 0x138a54: 0xc045a12  jal         func_116848
    ctx->pc = 0x138A54u;
    SET_GPR_U32(ctx, 31, 0x138A5Cu);
    ctx->pc = 0x138A58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138A54u;
            // 0x138a58: 0x8e050000  lw          $a1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138A5Cu; }
        if (ctx->pc != 0x138A5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138A5Cu; }
        if (ctx->pc != 0x138A5Cu) { return; }
    }
    ctx->pc = 0x138A5Cu;
label_138a5c:
    // 0x138a5c: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x138a5cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x138a60: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x138a60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x138a64: 0x2484bc08  addiu       $a0, $a0, -0x43F8
    ctx->pc = 0x138a64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949896));
    // 0x138a68: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x138a68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138a6c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x138A6Cu;
    {
        const bool branch_taken_0x138a6c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x138A70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138A6Cu;
            // 0x138a70: 0x24060800  addiu       $a2, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138a6c) {
            ctx->pc = 0x138A80u;
            goto label_138a80;
        }
    }
    ctx->pc = 0x138A74u;
    // 0x138a74: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x138A74u;
    SET_GPR_U32(ctx, 31, 0x138A7Cu);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138A7Cu; }
        if (ctx->pc != 0x138A7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138A7Cu; }
        if (ctx->pc != 0x138A7Cu) { return; }
    }
    ctx->pc = 0x138A7Cu;
label_138a7c:
    // 0x138a7c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x138a7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_138a80:
    // 0x138a80: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x138a80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x138a84: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138a84u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138a88: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x138a88u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x138a8c: 0x2484c8f8  addiu       $a0, $a0, -0x3708
    ctx->pc = 0x138a8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953208));
    // 0x138a90: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x138a90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138a94: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x138a94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x138a98: 0x8045a12  j           func_116848
    ctx->pc = 0x138A98u;
    ctx->pc = 0x138A9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138A98u;
            // 0x138a9c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x138AA0u;
    // 0x138aa0: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x138aa0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x138aa4: 0x2463bc04  addiu       $v1, $v1, -0x43FC
    ctx->pc = 0x138aa4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949892));
    // 0x138aa8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x138aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x138aac: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x138aacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x138ab0: 0x3e00008  jr          $ra
    ctx->pc = 0x138AB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138AB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138AB0u;
            // 0x138ab4: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138A00u: goto label_138a00;
            case 0x138A14u: goto label_138a14;
            case 0x138A18u: goto label_138a18;
            case 0x138A5Cu: goto label_138a5c;
            case 0x138A7Cu: goto label_138a7c;
            case 0x138A80u: goto label_138a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138AB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
