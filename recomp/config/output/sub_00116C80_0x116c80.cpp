#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00116C80
// Address: 0x116c80 - 0x116cd0
void sub_00116C80_0x116c80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00116C80_0x116c80");
#endif

    ctx->pc = 0x116c80u;

    // 0x116c80: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x116c80u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116c84: 0x4c1000b  bgez        $a2, . + 4 + (0xB << 2)
    ctx->pc = 0x116C84u;
    {
        const bool branch_taken_0x116c84 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x116C88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116C84u;
            // 0x116c88: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116c84) {
            ctx->pc = 0x116CB4u;
            goto label_116cb4;
        }
    }
    ctx->pc = 0x116C8Cu;
    // 0x116c8c: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x116c8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x116c90: 0x2405000c  addiu       $a1, $zero, 0xC
    ctx->pc = 0x116c90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x116c94: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x116c94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x116c98: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x116c98u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x116c9c: 0xc21024  and         $v0, $a2, $v0
    ctx->pc = 0x116c9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
    // 0x116ca0: 0x8c64afa4  lw          $a0, -0x505C($v1)
    ctx->pc = 0x116ca0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294946724)));
    // 0x116ca4: 0x451018  mult        $v0, $v0, $a1
    ctx->pc = 0x116ca4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x116ca8: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x116ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x116cac: 0x3e00008  jr          $ra
    ctx->pc = 0x116CACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116CB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116CACu;
            // 0x116cb0: 0xac400000  sw          $zero, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116CB4u: goto label_116cb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x116CB4u;
label_116cb4:
    // 0x116cb4: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x116cb4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x116cb8: 0xc21018  mult        $v0, $a2, $v0
    ctx->pc = 0x116cb8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x116cbc: 0x8c83afac  lw          $v1, -0x5054($a0)
    ctx->pc = 0x116cbcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294946732)));
    // 0x116cc0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x116cc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x116cc4: 0x3e00008  jr          $ra
    ctx->pc = 0x116CC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116CC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116CC4u;
            // 0x116cc8: 0xac400000  sw          $zero, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116CB4u: goto label_116cb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x116CCCu;
    // 0x116ccc: 0x0  nop
    ctx->pc = 0x116cccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
