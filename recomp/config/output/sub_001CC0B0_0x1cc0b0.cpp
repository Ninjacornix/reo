#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CC0B0
// Address: 0x1cc0b0 - 0x1cc110
void sub_001CC0B0_0x1cc0b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CC0B0_0x1cc0b0");
#endif

    switch (ctx->pc) {
        case 0x1cc0e8u: goto label_1cc0e8;
        default: break;
    }

    ctx->pc = 0x1cc0b0u;

    // 0x1cc0b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cc0b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cc0b4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cc0b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cc0b8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cc0b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cc0bc: 0x8ca3000c  lw          $v1, 0xC($a1)
    ctx->pc = 0x1cc0bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x1cc0c0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1cc0c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc0c4: 0x8ca20010  lw          $v0, 0x10($a1)
    ctx->pc = 0x1cc0c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x1cc0c8: 0x432823  subu        $a1, $v0, $v1
    ctx->pc = 0x1cc0c8u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1cc0cc: 0x28a10385  slti        $at, $a1, 0x385
    ctx->pc = 0x1cc0ccu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)901) ? 1 : 0);
    // 0x1cc0d0: 0x14200002  bnez        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CC0D0u;
    {
        const bool branch_taken_0x1cc0d0 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cc0d0) {
            ctx->pc = 0x1CC0DCu;
            goto label_1cc0dc;
        }
    }
    ctx->pc = 0x1CC0D8u;
    // 0x1cc0d8: 0x24050384  addiu       $a1, $zero, 0x384
    ctx->pc = 0x1cc0d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 900));
label_1cc0dc:
    // 0x1cc0dc: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x1cc0dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1cc0e0: 0xc072f40  jal         func_1CBD00
    ctx->pc = 0x1CC0E0u;
    SET_GPR_U32(ctx, 31, 0x1CC0E8u);
    ctx->pc = 0x1CC0E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC0E0u;
            // 0x1cc0e4: 0x432021  addu        $a0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CBD00u;
    if (runtime->hasFunction(0x1CBD00u)) {
        auto targetFn = runtime->lookupFunction(0x1CBD00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC0E8u; }
        if (ctx->pc != 0x1CC0E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBD00_0x1cbd00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC0E8u; }
        if (ctx->pc != 0x1CC0E8u) { return; }
    }
    ctx->pc = 0x1CC0E8u;
label_1cc0e8:
    // 0x1cc0e8: 0x18400004  blez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CC0E8u;
    {
        const bool branch_taken_0x1cc0e8 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1cc0e8) {
            ctx->pc = 0x1CC0FCu;
            goto label_1cc0fc;
        }
    }
    ctx->pc = 0x1CC0F0u;
    // 0x1cc0f0: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x1cc0f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1cc0f4: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1cc0f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1cc0f8: 0xae03000c  sw          $v1, 0xC($s0)
    ctx->pc = 0x1cc0f8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
label_1cc0fc:
    // 0x1cc0fc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cc0fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cc100: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cc100u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cc104: 0x3e00008  jr          $ra
    ctx->pc = 0x1CC104u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CC108u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC104u;
            // 0x1cc108: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CC0DCu: goto label_1cc0dc;
            case 0x1CC0E8u: goto label_1cc0e8;
            case 0x1CC0FCu: goto label_1cc0fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CC10Cu;
    // 0x1cc10c: 0x0  nop
    ctx->pc = 0x1cc10cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
