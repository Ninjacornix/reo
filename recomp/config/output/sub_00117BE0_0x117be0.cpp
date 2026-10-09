#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00117BE0
// Address: 0x117be0 - 0x117c20
void sub_00117BE0_0x117be0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00117BE0_0x117be0");
#endif

    ctx->pc = 0x117be0u;

    // 0x117be0: 0x8c850000  lw          $a1, 0x0($a0)
    ctx->pc = 0x117be0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x117be4: 0x10a00009  beqz        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x117BE4u;
    {
        const bool branch_taken_0x117be4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x117be4) {
            ctx->pc = 0x117C0Cu;
            goto label_117c0c;
        }
    }
    ctx->pc = 0x117BECu;
    // 0x117bec: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x117becu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x117bf0: 0x8ca20018  lw          $v0, 0x18($a1)
    ctx->pc = 0x117bf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x117bf4: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x117BF4u;
    {
        const bool branch_taken_0x117bf4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x117bf4) {
            ctx->pc = 0x117C0Cu;
            goto label_117c0c;
        }
    }
    ctx->pc = 0x117BFCu;
    // 0x117bfc: 0x8ca20010  lw          $v0, 0x10($a1)
    ctx->pc = 0x117bfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x117c00: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x117c00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x117c04: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x117C04u;
    {
        const bool branch_taken_0x117c04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x117c04) {
            ctx->pc = 0x117C14u;
            goto label_117c14;
        }
    }
    ctx->pc = 0x117C0Cu;
label_117c0c:
    // 0x117c0c: 0x3e00008  jr          $ra
    ctx->pc = 0x117C0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x117C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117C0Cu;
            // 0x117c10: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117C0Cu: goto label_117c0c;
            case 0x117C14u: goto label_117c14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117C14u;
label_117c14:
    // 0x117c14: 0x3e00008  jr          $ra
    ctx->pc = 0x117C14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x117C18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117C14u;
            // 0x117c18: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117C0Cu: goto label_117c0c;
            case 0x117C14u: goto label_117c14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117C1Cu;
    // 0x117c1c: 0x0  nop
    ctx->pc = 0x117c1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
