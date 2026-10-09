#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B6A8
// Address: 0x15b6a8 - 0x15b760
void sub_0015B6A8_0x15b6a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B6A8_0x15b6a8");
#endif

    switch (ctx->pc) {
        case 0x15b6f0u: goto label_15b6f0;
        case 0x15b708u: goto label_15b708;
        default: break;
    }

    ctx->pc = 0x15b6a8u;

    // 0x15b6a8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15b6a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15b6ac: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x15b6acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x15b6b0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15b6b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15b6b4: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x15b6b4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b6b8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15b6b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15b6bc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15b6bcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b6c0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15b6c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15b6c4: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x15b6c4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b6c8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x15b6c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15b6cc: 0x16420004  bne         $s2, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x15B6CCu;
    {
        const bool branch_taken_0x15b6cc = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        ctx->pc = 0x15B6D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B6CCu;
            // 0x15b6d0: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15b6cc) {
            ctx->pc = 0x15B6E0u;
            goto label_15b6e0;
        }
    }
    ctx->pc = 0x15B6D4u;
    // 0x15b6d4: 0x16200002  bnez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x15B6D4u;
    {
        const bool branch_taken_0x15b6d4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x15B6D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B6D4u;
            // 0x15b6d8: 0x3c020016  lui         $v0, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)22 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15b6d4) {
            ctx->pc = 0x15B6E0u;
            goto label_15b6e0;
        }
    }
    ctx->pc = 0x15B6DCu;
    // 0x15b6dc: 0x2451b6a0  addiu       $s1, $v0, -0x4960
    ctx->pc = 0x15b6dcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294948512));
label_15b6e0:
    // 0x15b6e0: 0x16000007  bnez        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15B6E0u;
    {
        const bool branch_taken_0x15b6e0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x15b6e0) {
            ctx->pc = 0x15B700u;
            goto label_15b700;
        }
    }
    ctx->pc = 0x15B6E8u;
    // 0x15b6e8: 0xc056dd8  jal         func_15B760
    ctx->pc = 0x15B6E8u;
    SET_GPR_U32(ctx, 31, 0x15B6F0u);
    ctx->pc = 0x15B6ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B6E8u;
            // 0x15b6ec: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B760u;
    if (runtime->hasFunction(0x15B760u)) {
        auto targetFn = runtime->lookupFunction(0x15B760u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B6F0u; }
        if (ctx->pc != 0x15B6F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B760_0x15b760(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B6F0u; }
        if (ctx->pc != 0x15B6F0u) { return; }
    }
    ctx->pc = 0x15B6F0u;
label_15b6f0:
    // 0x15b6f0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x15b6f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x15b6f4: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x15B6F4u;
    {
        const bool branch_taken_0x15b6f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15B6F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B6F4u;
            // 0x15b6f8: 0x24444c70  addiu       $a0, $v0, 0x4C70 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 19568));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15b6f4) {
            ctx->pc = 0x15B734u;
            goto label_15b734;
        }
    }
    ctx->pc = 0x15B6FCu;
    // 0x15b6fc: 0x0  nop
    ctx->pc = 0x15b6fcu;
    // NOP
label_15b700:
    // 0x15b700: 0xc056dec  jal         func_15B7B0
    ctx->pc = 0x15B700u;
    SET_GPR_U32(ctx, 31, 0x15B708u);
    ctx->pc = 0x15B704u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B700u;
            // 0x15b704: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B7B0u;
    if (runtime->hasFunction(0x15B7B0u)) {
        auto targetFn = runtime->lookupFunction(0x15B7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B708u; }
        if (ctx->pc != 0x15B708u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B7B0_0x15b7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B708u; }
        if (ctx->pc != 0x15B708u) { return; }
    }
    ctx->pc = 0x15B708u;
label_15b708:
    // 0x15b708: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x15b708u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x15b70c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x15B70Cu;
    {
        const bool branch_taken_0x15b70c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15B710u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B70Cu;
            // 0x15b710: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15b70c) {
            ctx->pc = 0x15B730u;
            goto label_15b730;
        }
    }
    ctx->pc = 0x15B714u;
    // 0x15b714: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15b714u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15b718: 0x34a50202  ori         $a1, $a1, 0x202
    ctx->pc = 0x15b718u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)514);
    // 0x15b71c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15b71cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15b720: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15b720u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15b724: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15b724u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15b728: 0x80563ce  j           func_158F38
    ctx->pc = 0x15B728u;
    ctx->pc = 0x15B72Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B728u;
            // 0x15b72c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158F38u;
    if (runtime->hasFunction(0x158F38u)) {
        auto targetFn = runtime->lookupFunction(0x158F38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00158F38_0x158f38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15B730u;
label_15b730:
    // 0x15b730: 0x26040190  addiu       $a0, $s0, 0x190
    ctx->pc = 0x15b730u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 400));
label_15b734:
    // 0x15b734: 0x121880  sll         $v1, $s2, 2
    ctx->pc = 0x15b734u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x15b738: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15b738u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15b73c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x15b73cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x15b740: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15b740u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15b744: 0xac710000  sw          $s1, 0x0($v1)
    ctx->pc = 0x15b744u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 17));
    // 0x15b748: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15b748u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b74c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15b74cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15b750: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15b750u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15b754: 0x3e00008  jr          $ra
    ctx->pc = 0x15B754u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15B758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B754u;
            // 0x15b758: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B6E0u: goto label_15b6e0;
            case 0x15B6F0u: goto label_15b6f0;
            case 0x15B700u: goto label_15b700;
            case 0x15B708u: goto label_15b708;
            case 0x15B730u: goto label_15b730;
            case 0x15B734u: goto label_15b734;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15B75Cu;
    // 0x15b75c: 0x0  nop
    ctx->pc = 0x15b75cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
