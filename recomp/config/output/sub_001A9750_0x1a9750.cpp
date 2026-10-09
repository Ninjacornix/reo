#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A9750
// Address: 0x1a9750 - 0x1a97c0
void sub_001A9750_0x1a9750(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A9750_0x1a9750");
#endif

    ctx->pc = 0x1a9750u;

    // 0x1a9750: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1a9750u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a9754: 0x10a20012  beq         $a1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1A9754u;
    {
        const bool branch_taken_0x1a9754 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x1A9758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9754u;
            // 0x1a9758: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9754) {
            ctx->pc = 0x1A97A0u;
            goto label_1a97a0;
        }
    }
    ctx->pc = 0x1A975Cu;
    // 0x1a975c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a975cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a9760: 0x10a2000a  beq         $a1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1A9760u;
    {
        const bool branch_taken_0x1a9760 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x1A9764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9760u;
            // 0x1a9764: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9760) {
            ctx->pc = 0x1A978Cu;
            goto label_1a978c;
        }
    }
    ctx->pc = 0x1A9768u;
    // 0x1a9768: 0x10a00003  beqz        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A9768u;
    {
        const bool branch_taken_0x1a9768 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A976Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9768u;
            // 0x1a976c: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9768) {
            ctx->pc = 0x1A9778u;
            goto label_1a9778;
        }
    }
    ctx->pc = 0x1A9770u;
    // 0x1a9770: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1A9770u;
    {
        const bool branch_taken_0x1a9770 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9770u;
            // 0x1a9774: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9770) {
            ctx->pc = 0x1A97B8u;
            goto label_1a97b8;
        }
    }
    ctx->pc = 0x1A9778u;
label_1a9778:
    // 0x1a9778: 0x902343f8  lbu         $v1, 0x43F8($at)
    ctx->pc = 0x1a9778u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17400)));
    // 0x1a977c: 0x1464000d  bne         $v1, $a0, . + 4 + (0xD << 2)
    ctx->pc = 0x1A977Cu;
    {
        const bool branch_taken_0x1a977c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1a977c) {
            ctx->pc = 0x1A97B4u;
            goto label_1a97b4;
        }
    }
    ctx->pc = 0x1A9784u;
    // 0x1a9784: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A9784u;
    {
        const bool branch_taken_0x1a9784 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a9784) {
            ctx->pc = 0x1A97B8u;
            goto label_1a97b8;
        }
    }
    ctx->pc = 0x1A978Cu;
label_1a978c:
    // 0x1a978c: 0x902343f9  lbu         $v1, 0x43F9($at)
    ctx->pc = 0x1a978cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17401)));
    // 0x1a9790: 0x14640008  bne         $v1, $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1A9790u;
    {
        const bool branch_taken_0x1a9790 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1a9790) {
            ctx->pc = 0x1A97B4u;
            goto label_1a97b4;
        }
    }
    ctx->pc = 0x1A9798u;
    // 0x1a9798: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1A9798u;
    {
        const bool branch_taken_0x1a9798 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a9798) {
            ctx->pc = 0x1A97B8u;
            goto label_1a97b8;
        }
    }
    ctx->pc = 0x1A97A0u;
label_1a97a0:
    // 0x1a97a0: 0x9022448a  lbu         $v0, 0x448A($at)
    ctx->pc = 0x1a97a0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17546)));
    // 0x1a97a4: 0x14440003  bne         $v0, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A97A4u;
    {
        const bool branch_taken_0x1a97a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x1A97A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A97A4u;
            // 0x1a97a8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a97a4) {
            ctx->pc = 0x1A97B4u;
            goto label_1a97b4;
        }
    }
    ctx->pc = 0x1A97ACu;
    // 0x1a97ac: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1A97ACu;
    {
        const bool branch_taken_0x1a97ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a97ac) {
            ctx->pc = 0x1A97B8u;
            goto label_1a97b8;
        }
    }
    ctx->pc = 0x1A97B4u;
label_1a97b4:
    // 0x1a97b4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a97b4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a97b8:
    // 0x1a97b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1A97B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A9778u: goto label_1a9778;
            case 0x1A978Cu: goto label_1a978c;
            case 0x1A97A0u: goto label_1a97a0;
            case 0x1A97B4u: goto label_1a97b4;
            case 0x1A97B8u: goto label_1a97b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A97C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
