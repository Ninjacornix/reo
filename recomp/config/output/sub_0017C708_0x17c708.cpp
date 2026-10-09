#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017C708
// Address: 0x17c708 - 0x17c940
void sub_0017C708_0x17c708(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017C708_0x17c708");
#endif

    switch (ctx->pc) {
        case 0x17c7a0u: goto label_17c7a0;
        case 0x17c820u: goto label_17c820;
        case 0x17c858u: goto label_17c858;
        case 0x17c8a8u: goto label_17c8a8;
        default: break;
    }

    ctx->pc = 0x17c708u;

    // 0x17c708: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17c708u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17c70c: 0x24030064  addiu       $v1, $zero, 0x64
    ctx->pc = 0x17c70cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x17c710: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17c710u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17c714: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x17c714u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17c718: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x17c718u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17c71c: 0x8c860038  lw          $a2, 0x38($a0)
    ctx->pc = 0x17c71cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 56)));
    // 0x17c720: 0x10c30023  beq         $a2, $v1, . + 4 + (0x23 << 2)
    ctx->pc = 0x17C720u;
    {
        const bool branch_taken_0x17c720 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        ctx->pc = 0x17C724u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C720u;
            // 0x17c724: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c720) {
            ctx->pc = 0x17C7B0u;
            goto label_17c7b0;
        }
    }
    ctx->pc = 0x17C728u;
    // 0x17c728: 0x14c50021  bne         $a2, $a1, . + 4 + (0x21 << 2)
    ctx->pc = 0x17C728u;
    {
        const bool branch_taken_0x17c728 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 5));
        ctx->pc = 0x17C72Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C728u;
            // 0x17c72c: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c728) {
            ctx->pc = 0x17C7B0u;
            goto label_17c7b0;
        }
    }
    ctx->pc = 0x17C730u;
    // 0x17c730: 0x2ca2000e  sltiu       $v0, $a1, 0xE
    ctx->pc = 0x17c730u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)14) ? 1 : 0);
    // 0x17c734: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x17C734u;
    {
        const bool branch_taken_0x17c734 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17C738u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C734u;
            // 0x17c738: 0x2ca20015  sltiu       $v0, $a1, 0x15 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)21) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c734) {
            ctx->pc = 0x17C778u;
            goto label_17c778;
        }
    }
    ctx->pc = 0x17C73Cu;
    // 0x17c73c: 0x2ca2000b  sltiu       $v0, $a1, 0xB
    ctx->pc = 0x17c73cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)11) ? 1 : 0);
    // 0x17c740: 0x5040001b  beql        $v0, $zero, . + 4 + (0x1B << 2)
    ctx->pc = 0x17C740u;
    {
        const bool branch_taken_0x17c740 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17c740) {
            ctx->pc = 0x17C744u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17C740u;
            // 0x17c744: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17C7B0u;
            goto label_17c7b0;
        }
    }
    ctx->pc = 0x17C748u;
    // 0x17c748: 0x50b00018  beql        $a1, $s0, . + 4 + (0x18 << 2)
    ctx->pc = 0x17C748u;
    {
        const bool branch_taken_0x17c748 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 16));
        if (branch_taken_0x17c748) {
            ctx->pc = 0x17C74Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17C748u;
            // 0x17c74c: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17C7ACu;
            goto label_17c7ac;
        }
    }
    ctx->pc = 0x17C750u;
    // 0x17c750: 0x10a00017  beqz        $a1, . + 4 + (0x17 << 2)
    ctx->pc = 0x17C750u;
    {
        const bool branch_taken_0x17c750 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x17C754u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C750u;
            // 0x17c754: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c750) {
            ctx->pc = 0x17C7B0u;
            goto label_17c7b0;
        }
    }
    ctx->pc = 0x17C758u;
    // 0x17c758: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x17c758u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x17c75c: 0x10a2000e  beq         $a1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x17C75Cu;
    {
        const bool branch_taken_0x17c75c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x17C760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C75Cu;
            // 0x17c760: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c75c) {
            ctx->pc = 0x17C798u;
            goto label_17c798;
        }
    }
    ctx->pc = 0x17C764u;
    // 0x17c764: 0x10a20010  beq         $a1, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x17C764u;
    {
        const bool branch_taken_0x17c764 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x17C768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C764u;
            // 0x17c768: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c764) {
            ctx->pc = 0x17C7A8u;
            goto label_17c7a8;
        }
    }
    ctx->pc = 0x17C76Cu;
    // 0x17c76c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x17C76Cu;
    {
        const bool branch_taken_0x17c76c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17C770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C76Cu;
            // 0x17c770: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c76c) {
            ctx->pc = 0x17C7B4u;
            goto label_17c7b4;
        }
    }
    ctx->pc = 0x17C774u;
    // 0x17c774: 0x0  nop
    ctx->pc = 0x17c774u;
    // NOP
label_17c778:
    // 0x17c778: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x17C778u;
    {
        const bool branch_taken_0x17c778 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x17C77Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C778u;
            // 0x17c77c: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c778) {
            ctx->pc = 0x17C7B0u;
            goto label_17c7b0;
        }
    }
    ctx->pc = 0x17C780u;
    // 0x17c780: 0x2ca20017  sltiu       $v0, $a1, 0x17
    ctx->pc = 0x17c780u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)23) ? 1 : 0);
    // 0x17c784: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x17C784u;
    {
        const bool branch_taken_0x17c784 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17c784) {
            ctx->pc = 0x17C788u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17C784u;
            // 0x17c788: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17C7ACu;
            goto label_17c7ac;
        }
    }
    ctx->pc = 0x17C78Cu;
    // 0x17c78c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x17C78Cu;
    {
        const bool branch_taken_0x17c78c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17C790u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C78Cu;
            // 0x17c790: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c78c) {
            ctx->pc = 0x17C7B0u;
            goto label_17c7b0;
        }
    }
    ctx->pc = 0x17C794u;
    // 0x17c794: 0x0  nop
    ctx->pc = 0x17c794u;
    // NOP
label_17c798:
    // 0x17c798: 0xc05e9f4  jal         func_17A7D0
    ctx->pc = 0x17C798u;
    SET_GPR_U32(ctx, 31, 0x17C7A0u);
    ctx->pc = 0x17C79Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C798u;
            // 0x17c79c: 0x8c840030  lw          $a0, 0x30($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A7D0u;
    if (runtime->hasFunction(0x17A7D0u)) {
        auto targetFn = runtime->lookupFunction(0x17A7D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C7A0u; }
        if (ctx->pc != 0x17C7A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A7D0_0x17a7d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C7A0u; }
        if (ctx->pc != 0x17C7A0u) { return; }
    }
    ctx->pc = 0x17C7A0u;
label_17c7a0:
    // 0x17c7a0: 0x10500003  beq         $v0, $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x17C7A0u;
    {
        const bool branch_taken_0x17c7a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 16));
        ctx->pc = 0x17C7A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C7A0u;
            // 0x17c7a4: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c7a0) {
            ctx->pc = 0x17C7B0u;
            goto label_17c7b0;
        }
    }
    ctx->pc = 0x17C7A8u;
label_17c7a8:
    // 0x17c7a8: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x17c7a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_17c7ac:
    // 0x17c7ac: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x17c7acu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_17c7b0:
    // 0x17c7b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17c7b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17c7b4:
    // 0x17c7b4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17c7b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17c7b8: 0x3e00008  jr          $ra
    ctx->pc = 0x17C7B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17C7BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C7B8u;
            // 0x17c7bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17C778u: goto label_17c778;
            case 0x17C798u: goto label_17c798;
            case 0x17C7A0u: goto label_17c7a0;
            case 0x17C7A8u: goto label_17c7a8;
            case 0x17C7ACu: goto label_17c7ac;
            case 0x17C7B0u: goto label_17c7b0;
            case 0x17C7B4u: goto label_17c7b4;
            case 0x17C818u: goto label_17c818;
            case 0x17C820u: goto label_17c820;
            case 0x17C858u: goto label_17c858;
            case 0x17C894u: goto label_17c894;
            case 0x17C8A8u: goto label_17c8a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17C7C0u;
    // 0x17c7c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17c7c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17c7c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17c7c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17c7c8: 0x8c86003c  lw          $a2, 0x3C($a0)
    ctx->pc = 0x17c7c8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x17c7cc: 0x8ca5004c  lw          $a1, 0x4C($a1)
    ctx->pc = 0x17c7ccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 76)));
    // 0x17c7d0: 0x8c840024  lw          $a0, 0x24($a0)
    ctx->pc = 0x17c7d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x17c7d4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17c7d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c7d8: 0x805f798  j           func_17DE60
    ctx->pc = 0x17C7D8u;
    ctx->pc = 0x17C7DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C7D8u;
            // 0x17c7dc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17DE60u;
    if (runtime->hasFunction(0x17DE60u)) {
        auto targetFn = runtime->lookupFunction(0x17DE60u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017DE60_0x17de60(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C7E0u;
    // 0x17c7e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17c7e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17c7e4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17c7e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17c7e8: 0x8c86003c  lw          $a2, 0x3C($a0)
    ctx->pc = 0x17c7e8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x17c7ec: 0x8ca5004c  lw          $a1, 0x4C($a1)
    ctx->pc = 0x17c7ecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 76)));
    // 0x17c7f0: 0x8c840024  lw          $a0, 0x24($a0)
    ctx->pc = 0x17c7f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x17c7f4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17c7f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c7f8: 0x805f834  j           func_17E0D0
    ctx->pc = 0x17C7F8u;
    ctx->pc = 0x17C7FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C7F8u;
            // 0x17c7fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E0D0u;
    if (runtime->hasFunction(0x17E0D0u)) {
        auto targetFn = runtime->lookupFunction(0x17E0D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017E0D0_0x17e0d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C800u;
    // 0x17c800: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17c800u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17c804: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17c804u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17c808: 0x8c84003c  lw          $a0, 0x3C($a0)
    ctx->pc = 0x17c808u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x17c80c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17c80cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c810: 0x805f206  j           func_17C818
    ctx->pc = 0x17C810u;
    ctx->pc = 0x17C814u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C810u;
            // 0x17c814: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C818u;
    goto label_17c818;
    ctx->pc = 0x17C818u;
label_17c818:
    // 0x17c818: 0x2405000f  addiu       $a1, $zero, 0xF
    ctx->pc = 0x17c818u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x17c81c: 0x2482000f  addiu       $v0, $a0, 0xF
    ctx->pc = 0x17c81cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 15));
label_17c820:
    // 0x17c820: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x17c820u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x17c824: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x17c824u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x17c828: 0x0  nop
    ctx->pc = 0x17c828u;
    // NOP
    // 0x17c82c: 0x0  nop
    ctx->pc = 0x17c82cu;
    // NOP
    // 0x17c830: 0x0  nop
    ctx->pc = 0x17c830u;
    // NOP
    // 0x17c834: 0x4a1fffa  bgez        $a1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x17C834u;
    {
        const bool branch_taken_0x17c834 = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x17C838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C834u;
            // 0x17c838: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c834) {
            ctx->pc = 0x17C820u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17c820;
        }
    }
    ctx->pc = 0x17C83Cu;
    // 0x17c83c: 0x3c013f14  lui         $at, 0x3F14
    ctx->pc = 0x17c83cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16148 << 16));
    // 0x17c840: 0x3421fdf3  ori         $at, $at, 0xFDF3
    ctx->pc = 0x17c840u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)65011);
    // 0x17c844: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x17c844u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x17c848: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x17c848u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x17c84c: 0x3c014f00  lui         $at, 0x4F00
    ctx->pc = 0x17c84cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)20224 << 16));
    // 0x17c850: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x17c850u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x17c854: 0x3c078000  lui         $a3, 0x8000
    ctx->pc = 0x17c854u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)32768 << 16));
label_17c858:
    // 0x17c858: 0x24a2fff0  addiu       $v0, $a1, -0x10
    ctx->pc = 0x17c858u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967280));
    // 0x17c85c: 0x853021  addu        $a2, $a0, $a1
    ctx->pc = 0x17c85cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x17c860: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x17c860u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x17c864: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x17c864u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x17c868: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x17c868u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x17c86c: 0x46020002  mul.s       $f0, $f0, $f2
    ctx->pc = 0x17c86cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[2]);
    // 0x17c870: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x17c870u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x17c874: 0x460000e4  .word       0x460000E4                   # cvt.w.s     $f3, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x17c874u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x17c878: 0x44021800  mfc1        $v0, $f3
    ctx->pc = 0x17c878u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x17c87c: 0x45000005  bc1f        . + 4 + (0x5 << 2)
    ctx->pc = 0x17C87Cu;
    {
        const bool branch_taken_0x17c87c = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x17C880u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C87Cu;
            // 0x17c880: 0x28a300ec  slti        $v1, $a1, 0xEC (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)236) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c87c) {
            ctx->pc = 0x17C894u;
            goto label_17c894;
        }
    }
    ctx->pc = 0x17C884u;
    // 0x17c884: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x17c884u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x17c888: 0x460000e4  .word       0x460000E4                   # cvt.w.s     $f3, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x17c888u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x17c88c: 0x44021800  mfc1        $v0, $f3
    ctx->pc = 0x17c88cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x17c890: 0x471025  or          $v0, $v0, $a3
    ctx->pc = 0x17c890u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 7));
label_17c894:
    // 0x17c894: 0x1460fff0  bnez        $v1, . + 4 + (-0x10 << 2)
    ctx->pc = 0x17C894u;
    {
        const bool branch_taken_0x17c894 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x17C898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C894u;
            // 0x17c898: 0xa0c20000  sb          $v0, 0x0($a2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c894) {
            ctx->pc = 0x17C858u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17c858;
        }
    }
    ctx->pc = 0x17C89Cu;
    // 0x17c89c: 0x240500ec  addiu       $a1, $zero, 0xEC
    ctx->pc = 0x17c89cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 236));
    // 0x17c8a0: 0x2406ff80  addiu       $a2, $zero, -0x80
    ctx->pc = 0x17c8a0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967168));
    // 0x17c8a4: 0x0  nop
    ctx->pc = 0x17c8a4u;
    // NOP
label_17c8a8:
    // 0x17c8a8: 0x851821  addu        $v1, $a0, $a1
    ctx->pc = 0x17c8a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x17c8ac: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x17c8acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x17c8b0: 0x28a20100  slti        $v0, $a1, 0x100
    ctx->pc = 0x17c8b0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x17c8b4: 0x0  nop
    ctx->pc = 0x17c8b4u;
    // NOP
    // 0x17c8b8: 0x0  nop
    ctx->pc = 0x17c8b8u;
    // NOP
    // 0x17c8bc: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x17C8BCu;
    {
        const bool branch_taken_0x17c8bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x17C8C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C8BCu;
            // 0x17c8c0: 0xa0660000  sb          $a2, 0x0($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c8bc) {
            ctx->pc = 0x17C8A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17c8a8;
        }
    }
    ctx->pc = 0x17C8C4u;
    // 0x17c8c4: 0x3e00008  jr          $ra
    ctx->pc = 0x17C8C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17C778u: goto label_17c778;
            case 0x17C798u: goto label_17c798;
            case 0x17C7A0u: goto label_17c7a0;
            case 0x17C7A8u: goto label_17c7a8;
            case 0x17C7ACu: goto label_17c7ac;
            case 0x17C7B0u: goto label_17c7b0;
            case 0x17C7B4u: goto label_17c7b4;
            case 0x17C818u: goto label_17c818;
            case 0x17C820u: goto label_17c820;
            case 0x17C858u: goto label_17c858;
            case 0x17C894u: goto label_17c894;
            case 0x17C8A8u: goto label_17c8a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17C8CCu;
    // 0x17c8cc: 0x0  nop
    ctx->pc = 0x17c8ccu;
    // NOP
    // 0x17c8d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17c8d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17c8d4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17c8d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17c8d8: 0x8c86003c  lw          $a2, 0x3C($a0)
    ctx->pc = 0x17c8d8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x17c8dc: 0x8ca5004c  lw          $a1, 0x4C($a1)
    ctx->pc = 0x17c8dcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 76)));
    // 0x17c8e0: 0x8c840030  lw          $a0, 0x30($a0)
    ctx->pc = 0x17c8e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
    // 0x17c8e4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17c8e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c8e8: 0x805e9de  j           func_17A778
    ctx->pc = 0x17C8E8u;
    ctx->pc = 0x17C8ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C8E8u;
            // 0x17c8ec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A778u;
    if (runtime->hasFunction(0x17A778u)) {
        auto targetFn = runtime->lookupFunction(0x17A778u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017A778_0x17a778(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C8F0u;
    // 0x17c8f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17c8f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17c8f4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17c8f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17c8f8: 0x8c86003c  lw          $a2, 0x3C($a0)
    ctx->pc = 0x17c8f8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x17c8fc: 0x8ca5004c  lw          $a1, 0x4C($a1)
    ctx->pc = 0x17c8fcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 76)));
    // 0x17c900: 0x8c840030  lw          $a0, 0x30($a0)
    ctx->pc = 0x17c900u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
    // 0x17c904: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17c904u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c908: 0x805e9ee  j           func_17A7B8
    ctx->pc = 0x17C908u;
    ctx->pc = 0x17C90Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C908u;
            // 0x17c90c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A7B8u;
    if (runtime->hasFunction(0x17A7B8u)) {
        auto targetFn = runtime->lookupFunction(0x17A7B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017A7B8_0x17a7b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C910u;
    // 0x17c910: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17c910u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17c914: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17c914u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17c918: 0x8c84003c  lw          $a0, 0x3C($a0)
    ctx->pc = 0x17c918u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x17c91c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17c91cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c920: 0x8053fa4  j           func_14FE90
    ctx->pc = 0x17C920u;
    ctx->pc = 0x17C924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C920u;
            // 0x17c924: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14FE90u;
    if (runtime->hasFunction(0x14FE90u)) {
        auto targetFn = runtime->lookupFunction(0x14FE90u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0014FE90_0x14fe90(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C928u;
    // 0x17c928: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17c928u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17c92c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17c92cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17c930: 0x8c84003c  lw          $a0, 0x3C($a0)
    ctx->pc = 0x17c930u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x17c934: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17c934u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c938: 0x8053fa2  j           func_14FE88
    ctx->pc = 0x17C938u;
    ctx->pc = 0x17C93Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C938u;
            // 0x17c93c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14FE88u;
    if (runtime->hasFunction(0x14FE88u)) {
        auto targetFn = runtime->lookupFunction(0x14FE88u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0014FE88_0x14fe88(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C940u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
