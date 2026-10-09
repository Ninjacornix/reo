#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013C9E8
// Address: 0x13c9e8 - 0x13ca18
void sub_0013C9E8_0x13c9e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013C9E8_0x13c9e8");
#endif

    ctx->pc = 0x13c9e8u;

    // 0x13c9e8: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13C9E8u;
    {
        const bool branch_taken_0x13c9e8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x13C9ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C9E8u;
            // 0x13c9ec: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c9e8) {
            ctx->pc = 0x13CA08u;
            goto label_13ca08;
        }
    }
    ctx->pc = 0x13C9F0u;
    // 0x13c9f0: 0x14820006  bne         $a0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13C9F0u;
    {
        const bool branch_taken_0x13c9f0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x13C9F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C9F0u;
            // 0x13c9f4: 0x3c030022  lui         $v1, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c9f0) {
            ctx->pc = 0x13CA0Cu;
            goto label_13ca0c;
        }
    }
    ctx->pc = 0x13C9F8u;
    // 0x13c9f8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13c9f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13c9fc: 0x3e00008  jr          $ra
    ctx->pc = 0x13C9FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CA00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C9FCu;
            // 0x13ca00: 0xac44dea0  sw          $a0, -0x2160($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294958752), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CA08u: goto label_13ca08;
            case 0x13CA0Cu: goto label_13ca0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CA04u;
    // 0x13ca04: 0x0  nop
    ctx->pc = 0x13ca04u;
    // NOP
label_13ca08:
    // 0x13ca08: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13ca08u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
label_13ca0c:
    // 0x13ca0c: 0x34028001  ori         $v0, $zero, 0x8001
    ctx->pc = 0x13ca0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32769);
    // 0x13ca10: 0x3e00008  jr          $ra
    ctx->pc = 0x13CA10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CA14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CA10u;
            // 0x13ca14: 0xac62dea0  sw          $v0, -0x2160($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294958752), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CA08u: goto label_13ca08;
            case 0x13CA0Cu: goto label_13ca0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CA18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
