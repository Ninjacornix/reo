#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00122FA0
// Address: 0x122fa0 - 0x122ff0
void sub_00122FA0_0x122fa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00122FA0_0x122fa0");
#endif

    ctx->pc = 0x122fa0u;

    // 0x122fa0: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x122fa0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122fa4: 0x2403000b  addiu       $v1, $zero, 0xB
    ctx->pc = 0x122fa4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x122fa8: 0x90a20000  lbu         $v0, 0x0($a1)
    ctx->pc = 0x122fa8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x122fac: 0x54430006  bnel        $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x122FACu;
    {
        const bool branch_taken_0x122fac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x122fac) {
            ctx->pc = 0x122FB0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x122FACu;
            // 0x122fb0: 0x90a30010  lbu         $v1, 0x10($a1) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x122FC8u;
            goto label_122fc8;
        }
    }
    ctx->pc = 0x122FB4u;
    // 0x122fb4: 0x90a40001  lbu         $a0, 0x1($a1)
    ctx->pc = 0x122fb4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x122fb8: 0x24030077  addiu       $v1, $zero, 0x77
    ctx->pc = 0x122fb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 119));
    // 0x122fbc: 0x1083000a  beq         $a0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x122FBCu;
    {
        const bool branch_taken_0x122fbc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x122FC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122FBCu;
            // 0x122fc0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122fbc) {
            ctx->pc = 0x122FE8u;
            goto label_122fe8;
        }
    }
    ctx->pc = 0x122FC4u;
    // 0x122fc4: 0x90a30010  lbu         $v1, 0x10($a1)
    ctx->pc = 0x122fc4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 16)));
label_122fc8:
    // 0x122fc8: 0x2402000b  addiu       $v0, $zero, 0xB
    ctx->pc = 0x122fc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x122fcc: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x122FCCu;
    {
        const bool branch_taken_0x122fcc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x122FD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122FCCu;
            // 0x122fd0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122fcc) {
            ctx->pc = 0x122FE8u;
            goto label_122fe8;
        }
    }
    ctx->pc = 0x122FD4u;
    // 0x122fd4: 0x90a40011  lbu         $a0, 0x11($a1)
    ctx->pc = 0x122fd4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 17)));
    // 0x122fd8: 0x24030077  addiu       $v1, $zero, 0x77
    ctx->pc = 0x122fd8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 119));
    // 0x122fdc: 0x10830002  beq         $a0, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x122FDCu;
    {
        const bool branch_taken_0x122fdc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x122FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122FDCu;
            // 0x122fe0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122fdc) {
            ctx->pc = 0x122FE8u;
            goto label_122fe8;
        }
    }
    ctx->pc = 0x122FE4u;
    // 0x122fe4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x122fe4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_122fe8:
    // 0x122fe8: 0x3e00008  jr          $ra
    ctx->pc = 0x122FE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122FC8u: goto label_122fc8;
            case 0x122FE8u: goto label_122fe8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122FF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
