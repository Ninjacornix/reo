#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0980
// Address: 0x1b0980 - 0x1b0a00
void sub_001B0980_0x1b0980(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0980_0x1b0980");
#endif

    ctx->pc = 0x1b0980u;

    // 0x1b0980: 0xac800018  sw          $zero, 0x18($a0)
    ctx->pc = 0x1b0980u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 0));
    // 0x1b0984: 0x3c03000f  lui         $v1, 0xF
    ctx->pc = 0x1b0984u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)15 << 16));
    // 0x1b0988: 0x8c860000  lw          $a2, 0x0($a0)
    ctx->pc = 0x1b0988u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1b098c: 0x3465000f  ori         $a1, $v1, 0xF
    ctx->pc = 0x1b098cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)15);
    // 0x1b0990: 0xc51824  and         $v1, $a2, $a1
    ctx->pc = 0x1b0990u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & GPR_U64(ctx, 5));
    // 0x1b0994: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B0994u;
    {
        const bool branch_taken_0x1b0994 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0994u;
            // 0x1b0998: 0x2403000c  addiu       $v1, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0994) {
            ctx->pc = 0x1B09ACu;
            goto label_1b09ac;
        }
    }
    ctx->pc = 0x1B099Cu;
    // 0x1b099c: 0xac83001c  sw          $v1, 0x1C($a0)
    ctx->pc = 0x1b099cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 3));
    // 0x1b09a0: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1b09a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1b09a4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1B09A4u;
    {
        const bool branch_taken_0x1b09a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B09A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B09A4u;
            // 0x1b09a8: 0xac830018  sw          $v1, 0x18($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b09a4) {
            ctx->pc = 0x1B09F8u;
            goto label_1b09f8;
        }
    }
    ctx->pc = 0x1B09ACu;
label_1b09ac:
    // 0x1b09ac: 0x8c830008  lw          $v1, 0x8($a0)
    ctx->pc = 0x1b09acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1b09b0: 0x651824  and         $v1, $v1, $a1
    ctx->pc = 0x1b09b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 5));
    // 0x1b09b4: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1B09B4u;
    {
        const bool branch_taken_0x1b09b4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B09B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B09B4u;
            // 0x1b09b8: 0x2403000c  addiu       $v1, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b09b4) {
            ctx->pc = 0x1B09E0u;
            goto label_1b09e0;
        }
    }
    ctx->pc = 0x1B09BCu;
    // 0x1b09bc: 0x8c83001c  lw          $v1, 0x1C($a0)
    ctx->pc = 0x1b09bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x1b09c0: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1b09c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1b09c4: 0x4610007  bgez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B09C4u;
    {
        const bool branch_taken_0x1b09c4 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1B09C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B09C4u;
            // 0x1b09c8: 0xac83001c  sw          $v1, 0x1C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b09c4) {
            ctx->pc = 0x1B09E4u;
            goto label_1b09e4;
        }
    }
    ctx->pc = 0x1B09CCu;
    // 0x1b09cc: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1b09ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b09d0: 0xac83001c  sw          $v1, 0x1C($a0)
    ctx->pc = 0x1b09d0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 3));
    // 0x1b09d4: 0x8c830008  lw          $v1, 0x8($a0)
    ctx->pc = 0x1b09d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1b09d8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1B09D8u;
    {
        const bool branch_taken_0x1b09d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B09DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B09D8u;
            // 0x1b09dc: 0xac830018  sw          $v1, 0x18($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b09d8) {
            ctx->pc = 0x1B09E4u;
            goto label_1b09e4;
        }
    }
    ctx->pc = 0x1B09E0u;
label_1b09e0:
    // 0x1b09e0: 0xac83001c  sw          $v1, 0x1C($a0)
    ctx->pc = 0x1b09e0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 3));
label_1b09e4:
    // 0x1b09e4: 0x8c850000  lw          $a1, 0x0($a0)
    ctx->pc = 0x1b09e4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1b09e8: 0x8c830018  lw          $v1, 0x18($a0)
    ctx->pc = 0x1b09e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x1b09ec: 0x30a58ff0  andi        $a1, $a1, 0x8FF0
    ctx->pc = 0x1b09ecu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)36848);
    // 0x1b09f0: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x1b09f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x1b09f4: 0xac830018  sw          $v1, 0x18($a0)
    ctx->pc = 0x1b09f4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 3));
label_1b09f8:
    // 0x1b09f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B09F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B09ACu: goto label_1b09ac;
            case 0x1B09E0u: goto label_1b09e0;
            case 0x1B09E4u: goto label_1b09e4;
            case 0x1B09F8u: goto label_1b09f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0A00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
