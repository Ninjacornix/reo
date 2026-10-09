#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6148
// Address: 0x1d6148 - 0x1d61b8
void sub_001D6148_0x1d6148(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6148_0x1d6148");
#endif

    ctx->pc = 0x1d6148u;

    // 0x1d6148: 0x24020038  addiu       $v0, $zero, 0x38
    ctx->pc = 0x1d6148u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
    // 0x1d614c: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d614cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d6150: 0x822018  mult        $a0, $a0, $v0
    ctx->pc = 0x1d6150u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1d6154: 0x8c662844  lw          $a2, 0x2844($v1)
    ctx->pc = 0x1d6154u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10308)));
    // 0x1d6158: 0xc43021  addu        $a2, $a2, $a0
    ctx->pc = 0x1d6158u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x1d615c: 0x24c40010  addiu       $a0, $a2, 0x10
    ctx->pc = 0x1d615cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
    // 0x1d6160: 0x8c820024  lw          $v0, 0x24($a0)
    ctx->pc = 0x1d6160u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x1d6164: 0x28420004  slti        $v0, $v0, 0x4
    ctx->pc = 0x1d6164u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1d6168: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D6168u;
    {
        const bool branch_taken_0x1d6168 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D616Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6168u;
            // 0x1d616c: 0x30a5ffff  andi        $a1, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6168) {
            ctx->pc = 0x1D6178u;
            goto label_1d6178;
        }
    }
    ctx->pc = 0x1D6170u;
    // 0x1d6170: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6170u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6174u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6170u;
            // 0x1d6174: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6178u: goto label_1d6178;
            case 0x1D61A0u: goto label_1d61a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6178u;
label_1d6178:
    // 0x1d6178: 0x8cc3002c  lw          $v1, 0x2C($a2)
    ctx->pc = 0x1d6178u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 44)));
    // 0x1d617c: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1d617cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1d6180: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x1d6180u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1d6184: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1d6184u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1d6188: 0xa4450022  sh          $a1, 0x22($v0)
    ctx->pc = 0x1d6188u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 34), (uint16_t)GPR_U32(ctx, 5));
    // 0x1d618c: 0xacc3002c  sw          $v1, 0x2C($a2)
    ctx->pc = 0x1d618cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 3));
    // 0x1d6190: 0x8c82001c  lw          $v0, 0x1C($a0)
    ctx->pc = 0x1d6190u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x1d6194: 0x28420004  slti        $v0, $v0, 0x4
    ctx->pc = 0x1d6194u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1d6198: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1D6198u;
    {
        const bool branch_taken_0x1d6198 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d6198) {
            ctx->pc = 0x1D619Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6198u;
            // 0x1d619c: 0xac80001c  sw          $zero, 0x1C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D61A0u;
            goto label_1d61a0;
        }
    }
    ctx->pc = 0x1D61A0u;
label_1d61a0:
    // 0x1d61a0: 0x8c830024  lw          $v1, 0x24($a0)
    ctx->pc = 0x1d61a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x1d61a4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d61a4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d61a8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1d61a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1d61ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1D61ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D61B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D61ACu;
            // 0x1d61b0: 0xac830024  sw          $v1, 0x24($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6178u: goto label_1d6178;
            case 0x1D61A0u: goto label_1d61a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D61B4u;
    // 0x1d61b4: 0x0  nop
    ctx->pc = 0x1d61b4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
