#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018C570
// Address: 0x18c570 - 0x18c5f0
void sub_0018C570_0x18c570(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018C570_0x18c570");
#endif

    ctx->pc = 0x18c570u;

    // 0x18c570: 0x1080001d  beqz        $a0, . + 4 + (0x1D << 2)
    ctx->pc = 0x18C570u;
    {
        const bool branch_taken_0x18c570 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x18c570) {
            ctx->pc = 0x18C5E8u;
            goto label_18c5e8;
        }
    }
    ctx->pc = 0x18C578u;
    // 0x18c578: 0x2c810281  sltiu       $at, $a0, 0x281
    ctx->pc = 0x18c578u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)641) ? 1 : 0);
    // 0x18c57c: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x18C57Cu;
    {
        const bool branch_taken_0x18c57c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x18c57c) {
            ctx->pc = 0x18C58Cu;
            goto label_18c58c;
        }
    }
    ctx->pc = 0x18C584u;
    // 0x18c584: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x18C584u;
    {
        const bool branch_taken_0x18c584 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18c584) {
            ctx->pc = 0x18C5E8u;
            goto label_18c5e8;
        }
    }
    ctx->pc = 0x18C58Cu;
label_18c58c:
    // 0x18c58c: 0x4a00016  bltz        $a1, . + 4 + (0x16 << 2)
    ctx->pc = 0x18C58Cu;
    {
        const bool branch_taken_0x18c58c = (GPR_S64(ctx, 5) < 0);
        if (branch_taken_0x18c58c) {
            ctx->pc = 0x18C5E8u;
            goto label_18c5e8;
        }
    }
    ctx->pc = 0x18C594u;
    // 0x18c594: 0x28a30020  slti        $v1, $a1, 0x20
    ctx->pc = 0x18c594u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x18c598: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x18C598u;
    {
        const bool branch_taken_0x18c598 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x18c598) {
            ctx->pc = 0x18C5A8u;
            goto label_18c5a8;
        }
    }
    ctx->pc = 0x18C5A0u;
    // 0x18c5a0: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x18C5A0u;
    {
        const bool branch_taken_0x18c5a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18c5a0) {
            ctx->pc = 0x18C5E8u;
            goto label_18c5e8;
        }
    }
    ctx->pc = 0x18C5A8u;
label_18c5a8:
    // 0x18c5a8: 0x10c0000f  beqz        $a2, . + 4 + (0xF << 2)
    ctx->pc = 0x18C5A8u;
    {
        const bool branch_taken_0x18c5a8 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x18c5a8) {
            ctx->pc = 0x18C5E8u;
            goto label_18c5e8;
        }
    }
    ctx->pc = 0x18C5B0u;
    // 0x18c5b0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18c5b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18c5b4: 0x2487ffff  addiu       $a3, $a0, -0x1
    ctx->pc = 0x18c5b4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x18c5b8: 0x8c2341a0  lw          $v1, 0x41A0($at)
    ctx->pc = 0x18c5b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16800)));
    // 0x18c5bc: 0x72040  sll         $a0, $a3, 1
    ctx->pc = 0x18c5bcu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x18c5c0: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x18c5c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x18c5c4: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x18c5c4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x18c5c8: 0x421c0  sll         $a0, $a0, 7
    ctx->pc = 0x18c5c8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
    // 0x18c5cc: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x18c5ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x18c5d0: 0xa32021  addu        $a0, $a1, $v1
    ctx->pc = 0x18c5d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x18c5d4: 0x8c830080  lw          $v1, 0x80($a0)
    ctx->pc = 0x18c5d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 128)));
    // 0x18c5d8: 0x10660003  beq         $v1, $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x18C5D8u;
    {
        const bool branch_taken_0x18c5d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 6));
        ctx->pc = 0x18C5DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C5D8u;
            // 0x18c5dc: 0x24850080  addiu       $a1, $a0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c5d8) {
            ctx->pc = 0x18C5E8u;
            goto label_18c5e8;
        }
    }
    ctx->pc = 0x18C5E0u;
    // 0x18c5e0: 0xaca60000  sw          $a2, 0x0($a1)
    ctx->pc = 0x18c5e0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 6));
    // 0x18c5e4: 0xac860100  sw          $a2, 0x100($a0)
    ctx->pc = 0x18c5e4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 256), GPR_U32(ctx, 6));
label_18c5e8:
    // 0x18c5e8: 0x3e00008  jr          $ra
    ctx->pc = 0x18C5E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18C58Cu: goto label_18c58c;
            case 0x18C5A8u: goto label_18c5a8;
            case 0x18C5E8u: goto label_18c5e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18C5F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
