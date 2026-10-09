#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00127FC8
// Address: 0x127fc8 - 0x128038
void sub_00127FC8_0x127fc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00127FC8_0x127fc8");
#endif

    ctx->pc = 0x127fc8u;

    // 0x127fc8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x127fc8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x127fcc: 0xa5400  sll         $t2, $t2, 16
    ctx->pc = 0x127fccu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 16));
    // 0x127fd0: 0xb5c00  sll         $t3, $t3, 16
    ctx->pc = 0x127fd0u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 16));
    // 0x127fd4: 0x8c43c7a8  lw          $v1, -0x3858($v0)
    ctx->pc = 0x127fd4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294952872)));
    // 0x127fd8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x127fd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x127fdc: 0xa6403  sra         $t4, $t2, 16
    ctx->pc = 0x127fdcu;
    SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 10), 16));
    // 0x127fe0: 0xb6c03  sra         $t5, $t3, 16
    ctx->pc = 0x127fe0u;
    SET_GPR_S32(ctx, 13, SRA32(GPR_S32(ctx, 11), 16));
    // 0x127fe4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x127fe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x127fe8: 0x180502d  daddu       $t2, $t4, $zero
    ctx->pc = 0x127fe8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127fec: 0x1a0582d  daddu       $t3, $t5, $zero
    ctx->pc = 0x127fecu;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 13) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127ff0: 0x8fae0030  lw          $t6, 0x30($sp)
    ctx->pc = 0x127ff0u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x127ff4: 0x87af0038  lh          $t7, 0x38($sp)
    ctx->pc = 0x127ff4u;
    SET_GPR_S32(ctx, 15, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x127ff8: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x127FF8u;
    {
        const bool branch_taken_0x127ff8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x127FFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127FF8u;
            // 0x127ffc: 0x87a20040  lh          $v0, 0x40($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127ff8) {
            ctx->pc = 0x128018u;
            goto label_128018;
        }
    }
    ctx->pc = 0x128000u;
    // 0x128000: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x128000u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x128004: 0xafa20040  sw          $v0, 0x40($sp)
    ctx->pc = 0x128004u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 2));
    // 0x128008: 0xafaf0038  sw          $t7, 0x38($sp)
    ctx->pc = 0x128008u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 15));
    // 0x12800c: 0x8049f20  j           func_127C80
    ctx->pc = 0x12800Cu;
    ctx->pc = 0x128010u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12800Cu;
            // 0x128010: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x127C80u;
    if (runtime->hasFunction(0x127C80u)) {
        auto targetFn = runtime->lookupFunction(0x127C80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00127C80_0x127c80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x128014u;
    // 0x128014: 0x0  nop
    ctx->pc = 0x128014u;
    // NOP
label_128018:
    // 0x128018: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x128018u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12801c: 0x180502d  daddu       $t2, $t4, $zero
    ctx->pc = 0x12801cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128020: 0x1a0582d  daddu       $t3, $t5, $zero
    ctx->pc = 0x128020u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 13) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128024: 0xafa20040  sw          $v0, 0x40($sp)
    ctx->pc = 0x128024u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 2));
    // 0x128028: 0xafae0030  sw          $t6, 0x30($sp)
    ctx->pc = 0x128028u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 14));
    // 0x12802c: 0xafaf0038  sw          $t7, 0x38($sp)
    ctx->pc = 0x12802cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 15));
    // 0x128030: 0x8049e2e  j           func_1278B8
    ctx->pc = 0x128030u;
    ctx->pc = 0x128034u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128030u;
            // 0x128034: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1278B8u;
    if (runtime->hasFunction(0x1278B8u)) {
        auto targetFn = runtime->lookupFunction(0x1278B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001278B8_0x1278b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x128038u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
