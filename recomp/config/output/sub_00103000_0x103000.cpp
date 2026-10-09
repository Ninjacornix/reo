#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00103000
// Address: 0x103000 - 0x103028
void sub_00103000_0x103000(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00103000_0x103000");
#endif

    ctx->pc = 0x103000u;

    // 0x103000: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x103000u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x103004: 0x41702  srl         $v0, $a0, 28
    ctx->pc = 0x103004u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 28));
    // 0x103008: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x103008u;
    {
        const bool branch_taken_0x103008 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x10300Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103008u;
            // 0x10300c: 0x3c020fff  lui         $v0, 0xFFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4095 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103008) {
            ctx->pc = 0x103020u;
            goto label_103020;
        }
    }
    ctx->pc = 0x103010u;
    // 0x103010: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x103010u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x103014: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x103014u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x103018: 0x822024  and         $a0, $a0, $v0
    ctx->pc = 0x103018u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x10301c: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x10301cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
label_103020:
    // 0x103020: 0x3e00008  jr          $ra
    ctx->pc = 0x103020u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103024u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103020u;
            // 0x103024: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x103020u: goto label_103020;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103028u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
