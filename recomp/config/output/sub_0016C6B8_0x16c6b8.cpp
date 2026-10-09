#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016C6B8
// Address: 0x16c6b8 - 0x16c760
void sub_0016C6B8_0x16c6b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016C6B8_0x16c6b8");
#endif

    switch (ctx->pc) {
        case 0x16c6d8u: goto label_16c6d8;
        case 0x16c6f0u: goto label_16c6f0;
        case 0x16c718u: goto label_16c718;
        default: break;
    }

    ctx->pc = 0x16c6b8u;

    // 0x16c6b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16c6b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16c6bc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16c6bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16c6c0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16c6c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c6c4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16c6c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16c6c8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16c6c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16c6cc: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x16c6ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x16c6d0: 0xc05c164  jal         func_170590
    ctx->pc = 0x16C6D0u;
    SET_GPR_U32(ctx, 31, 0x16C6D8u);
    ctx->pc = 0x16C6D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C6D0u;
            // 0x16c6d4: 0x2612094c  addiu       $s2, $s0, 0x94C (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 2380));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170590u;
    if (runtime->hasFunction(0x170590u)) {
        auto targetFn = runtime->lookupFunction(0x170590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C6D8u; }
        if (ctx->pc != 0x16C6D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170590_0x170590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C6D8u; }
        if (ctx->pc != 0x16C6D8u) { return; }
    }
    ctx->pc = 0x16C6D8u;
label_16c6d8:
    // 0x16c6d8: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x16c6d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c6dc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x16c6dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x16c6e0: 0x1222000a  beq         $s1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x16C6E0u;
    {
        const bool branch_taken_0x16c6e0 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x16C6E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C6E0u;
            // 0x16c6e4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c6e0) {
            ctx->pc = 0x16C70Cu;
            goto label_16c70c;
        }
    }
    ctx->pc = 0x16C6E8u;
    // 0x16c6e8: 0xc05c15c  jal         func_170570
    ctx->pc = 0x16C6E8u;
    SET_GPR_U32(ctx, 31, 0x16C6F0u);
    ctx->pc = 0x170570u;
    if (runtime->hasFunction(0x170570u)) {
        auto targetFn = runtime->lookupFunction(0x170570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C6F0u; }
        if (ctx->pc != 0x16C6F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170570_0x170570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C6F0u; }
        if (ctx->pc != 0x16C6F0u) { return; }
    }
    ctx->pc = 0x16C6F0u;
label_16c6f0:
    // 0x16c6f0: 0x10400015  beqz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x16C6F0u;
    {
        const bool branch_taken_0x16c6f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C6F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C6F0u;
            // 0x16c6f4: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c6f0) {
            ctx->pc = 0x16C748u;
            goto label_16c748;
        }
    }
    ctx->pc = 0x16C6F8u;
    // 0x16c6f8: 0x56230014  bnel        $s1, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x16C6F8u;
    {
        const bool branch_taken_0x16c6f8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 3));
        if (branch_taken_0x16c6f8) {
            ctx->pc = 0x16C6FCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16C6F8u;
            // 0x16c6fc: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16C74Cu;
            goto label_16c74c;
        }
    }
    ctx->pc = 0x16C700u;
    // 0x16c700: 0x8e420014  lw          $v0, 0x14($s2)
    ctx->pc = 0x16c700u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x16c704: 0x50400011  beql        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x16C704u;
    {
        const bool branch_taken_0x16c704 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16c704) {
            ctx->pc = 0x16C708u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16C704u;
            // 0x16c708: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16C74Cu;
            goto label_16c74c;
        }
    }
    ctx->pc = 0x16C70Cu;
label_16c70c:
    // 0x16c70c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16c70cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c710: 0xc05b1d8  jal         func_16C760
    ctx->pc = 0x16C710u;
    SET_GPR_U32(ctx, 31, 0x16C718u);
    ctx->pc = 0x16C714u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C710u;
            // 0x16c714: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16C760u;
    if (runtime->hasFunction(0x16C760u)) {
        auto targetFn = runtime->lookupFunction(0x16C760u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C718u; }
        if (ctx->pc != 0x16C718u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016C760_0x16c760(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C718u; }
        if (ctx->pc != 0x16C718u) { return; }
    }
    ctx->pc = 0x16C718u;
label_16c718:
    // 0x16c718: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16c718u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c71c: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x16c71cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x16c720: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x16c720u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x16c724: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16C724u;
    {
        const bool branch_taken_0x16c724 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16C728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C724u;
            // 0x16c728: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c724) {
            ctx->pc = 0x16C748u;
            goto label_16c748;
        }
    }
    ctx->pc = 0x16C72Cu;
    // 0x16c72c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16c72cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c730: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16c730u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c734: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16c734u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16c738: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16c738u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16c73c: 0x805d518  j           func_175460
    ctx->pc = 0x16C73Cu;
    ctx->pc = 0x16C740u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C73Cu;
            // 0x16c740: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175460_0x175460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16C744u;
    // 0x16c744: 0x0  nop
    ctx->pc = 0x16c744u;
    // NOP
label_16c748:
    // 0x16c748: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16c748u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_16c74c:
    // 0x16c74c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16c74cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c750: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16c750u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16c754: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16c754u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16c758: 0x3e00008  jr          $ra
    ctx->pc = 0x16C758u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16C75Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C758u;
            // 0x16c75c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16C6D8u: goto label_16c6d8;
            case 0x16C6F0u: goto label_16c6f0;
            case 0x16C70Cu: goto label_16c70c;
            case 0x16C718u: goto label_16c718;
            case 0x16C748u: goto label_16c748;
            case 0x16C74Cu: goto label_16c74c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C760u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
