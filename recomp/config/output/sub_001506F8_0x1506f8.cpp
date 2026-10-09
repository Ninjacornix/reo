#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001506F8
// Address: 0x1506f8 - 0x1507b0
void sub_001506F8_0x1506f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001506F8_0x1506f8");
#endif

    switch (ctx->pc) {
        case 0x15071cu: goto label_15071c;
        case 0x150758u: goto label_150758;
        case 0x150760u: goto label_150760;
        case 0x150784u: goto label_150784;
        default: break;
    }

    ctx->pc = 0x1506f8u;

    // 0x1506f8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1506f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1506fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1506fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x150700: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x150700u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150704: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x150704u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x150708: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x150708u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15070c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15070cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x150710: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x150710u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x150714: 0xc05578e  jal         func_155E38
    ctx->pc = 0x150714u;
    SET_GPR_U32(ctx, 31, 0x15071Cu);
    ctx->pc = 0x150718u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150714u;
            // 0x150718: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15071Cu; }
        if (ctx->pc != 0x15071Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15071Cu; }
        if (ctx->pc != 0x15071Cu) { return; }
    }
    ctx->pc = 0x15071Cu;
label_15071c:
    // 0x15071c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x15071Cu;
    {
        const bool branch_taken_0x15071c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15071Cu;
            // 0x150720: 0xdfb10008  ld          $s1, 0x8($sp) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15071c) {
            ctx->pc = 0x150748u;
            goto label_150748;
        }
    }
    ctx->pc = 0x150724u;
    // 0x150724: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x150724u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x150728: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x150728u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15072c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x15072cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150730: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x150730u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x150734: 0x34a5020a  ori         $a1, $a1, 0x20A
    ctx->pc = 0x150734u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)522);
    // 0x150738: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x150738u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15073c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15073cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x150740: 0x805419c  j           func_150670
    ctx->pc = 0x150740u;
    ctx->pc = 0x150744u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150740u;
            // 0x150744: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x150748u;
label_150748:
    // 0x150748: 0x3c11ff03  lui         $s1, 0xFF03
    ctx->pc = 0x150748u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)65283 << 16));
    // 0x15074c: 0x24120004  addiu       $s2, $zero, 0x4
    ctx->pc = 0x15074cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x150750: 0x36310305  ori         $s1, $s1, 0x305
    ctx->pc = 0x150750u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)773);
    // 0x150754: 0x0  nop
    ctx->pc = 0x150754u;
    // NOP
label_150758:
    // 0x150758: 0xc056b7a  jal         func_15ADE8
    ctx->pc = 0x150758u;
    SET_GPR_U32(ctx, 31, 0x150760u);
    ctx->pc = 0x15075Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150758u;
            // 0x15075c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15ADE8u;
    if (runtime->hasFunction(0x15ADE8u)) {
        auto targetFn = runtime->lookupFunction(0x15ADE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150760u; }
        if (ctx->pc != 0x150760u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015ADE8_0x15ade8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150760u; }
        if (ctx->pc != 0x150760u) { return; }
    }
    ctx->pc = 0x150760u;
label_150760:
    // 0x150760: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x150760u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150764: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x150764u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x150768: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x150768u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x15076c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15076Cu;
    {
        const bool branch_taken_0x15076c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15076Cu;
            // 0x150770: 0x304300cc  andi        $v1, $v0, 0xCC (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)204);
        ctx->in_delay_slot = false;
        if (branch_taken_0x15076c) {
            ctx->pc = 0x15078Cu;
            goto label_15078c;
        }
    }
    ctx->pc = 0x150774u;
    // 0x150774: 0x54600005  bnel        $v1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x150774u;
    {
        const bool branch_taken_0x150774 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x150774) {
            ctx->pc = 0x150778u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x150774u;
            // 0x150778: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15078Cu;
            goto label_15078c;
        }
    }
    ctx->pc = 0x15077Cu;
    // 0x15077c: 0xc056c04  jal         func_15B010
    ctx->pc = 0x15077Cu;
    SET_GPR_U32(ctx, 31, 0x150784u);
    ctx->pc = 0x15B010u;
    if (runtime->hasFunction(0x15B010u)) {
        auto targetFn = runtime->lookupFunction(0x15B010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150784u; }
        if (ctx->pc != 0x150784u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B010_0x15b010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150784u; }
        if (ctx->pc != 0x150784u) { return; }
    }
    ctx->pc = 0x150784u;
label_150784:
    // 0x150784: 0x1052fff4  beq         $v0, $s2, . + 4 + (-0xC << 2)
    ctx->pc = 0x150784u;
    {
        const bool branch_taken_0x150784 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 18));
        if (branch_taken_0x150784) {
            ctx->pc = 0x150758u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_150758;
        }
    }
    ctx->pc = 0x15078Cu;
label_15078c:
    // 0x15078c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x15078cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150790: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x150790u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x150794: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x150794u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150798: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x150798u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15079c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15079cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1507a0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1507a0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1507a4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1507a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1507a8: 0x805419c  j           func_150670
    ctx->pc = 0x1507A8u;
    ctx->pc = 0x1507ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1507A8u;
            // 0x1507ac: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1507B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
