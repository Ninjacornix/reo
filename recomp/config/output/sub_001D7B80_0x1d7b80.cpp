#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7B80
// Address: 0x1d7b80 - 0x1d7c00
void sub_001D7B80_0x1d7b80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7B80_0x1d7b80");
#endif

    switch (ctx->pc) {
        case 0x1d7ba4u: goto label_1d7ba4;
        case 0x1d7bd8u: goto label_1d7bd8;
        case 0x1d7be4u: goto label_1d7be4;
        default: break;
    }

    ctx->pc = 0x1d7b80u;

    // 0x1d7b80: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1d7b80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1d7b84: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1d7b84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d7b88: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d7b88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d7b8c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d7b8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d7b90: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1d7b90u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7b94: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d7b94u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d7b98: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1d7b98u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7b9c: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D7B9Cu;
    SET_GPR_U32(ctx, 31, 0x1D7BA4u);
    ctx->pc = 0x1D7BA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7B9Cu;
            // 0x1d7ba0: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7BA4u; }
        if (ctx->pc != 0x1D7BA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7BA4u; }
        if (ctx->pc != 0x1D7BA4u) { return; }
    }
    ctx->pc = 0x1D7BA4u;
label_1d7ba4:
    // 0x1d7ba4: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d7ba4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d7ba8: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d7ba8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d7bac: 0x2442729c  addiu       $v0, $v0, 0x729C
    ctx->pc = 0x1d7bacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 29340));
    // 0x1d7bb0: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d7bb0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d7bb4: 0xac520000  sw          $s2, 0x0($v0)
    ctx->pc = 0x1d7bb4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 18));
    // 0x1d7bb8: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1d7bb8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1d7bbc: 0xa4510004  sh          $s1, 0x4($v0)
    ctx->pc = 0x1d7bbcu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 4), (uint16_t)GPR_U32(ctx, 17));
    // 0x1d7bc0: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d7bc0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d7bc4: 0x24060028  addiu       $a2, $zero, 0x28
    ctx->pc = 0x1d7bc4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1d7bc8: 0xa4500006  sh          $s0, 0x6($v0)
    ctx->pc = 0x1d7bc8u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 6), (uint16_t)GPR_U32(ctx, 16));
    // 0x1d7bcc: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d7bccu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d7bd0: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D7BD0u;
    SET_GPR_U32(ctx, 31, 0x1D7BD8u);
    ctx->pc = 0x1D7BD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7BD0u;
            // 0x1d7bd4: 0x24080020  addiu       $t0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7BD8u; }
        if (ctx->pc != 0x1D7BD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7BD8u; }
        if (ctx->pc != 0x1D7BD8u) { return; }
    }
    ctx->pc = 0x1D7BD8u;
label_1d7bd8:
    // 0x1d7bd8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7bd8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7bdc: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D7BDCu;
    SET_GPR_U32(ctx, 31, 0x1D7BE4u);
    ctx->pc = 0x1D7BE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7BDCu;
            // 0x1d7be0: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7BE4u; }
        if (ctx->pc != 0x1D7BE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7BE4u; }
        if (ctx->pc != 0x1D7BE4u) { return; }
    }
    ctx->pc = 0x1D7BE4u;
label_1d7be4:
    // 0x1d7be4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d7be4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7be8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1d7be8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d7bec: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d7becu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d7bf0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d7bf0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d7bf4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d7bf4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d7bf8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D7BF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D7BFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7BF8u;
            // 0x1d7bfc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7BA4u: goto label_1d7ba4;
            case 0x1D7BD8u: goto label_1d7bd8;
            case 0x1D7BE4u: goto label_1d7be4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D7C00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
