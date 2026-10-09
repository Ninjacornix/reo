#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7C60
// Address: 0x1d7c60 - 0x1d7cc0
void sub_001D7C60_0x1d7c60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7C60_0x1d7c60");
#endif

    switch (ctx->pc) {
        case 0x1d7c74u: goto label_1d7c74;
        case 0x1d7c9cu: goto label_1d7c9c;
        case 0x1d7ca8u: goto label_1d7ca8;
        default: break;
    }

    ctx->pc = 0x1d7c60u;

    // 0x1d7c60: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d7c60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d7c64: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d7c64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d7c68: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d7c68u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d7c6c: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D7C6Cu;
    SET_GPR_U32(ctx, 31, 0x1D7C74u);
    ctx->pc = 0x1D7C70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7C6Cu;
            // 0x1d7c70: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7C74u; }
        if (ctx->pc != 0x1D7C74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7C74u; }
        if (ctx->pc != 0x1D7C74u) { return; }
    }
    ctx->pc = 0x1D7C74u;
label_1d7c74:
    // 0x1d7c74: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d7c74u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d7c78: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d7c78u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d7c7c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7c7cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7c80: 0x2404000b  addiu       $a0, $zero, 0xB
    ctx->pc = 0x1d7c80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1d7c84: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d7c84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d7c88: 0x24060022  addiu       $a2, $zero, 0x22
    ctx->pc = 0x1d7c88u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1d7c8c: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d7c8cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d7c90: 0x24080020  addiu       $t0, $zero, 0x20
    ctx->pc = 0x1d7c90u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d7c94: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D7C94u;
    SET_GPR_U32(ctx, 31, 0x1D7C9Cu);
    ctx->pc = 0x1D7C98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7C94u;
            // 0x1d7c98: 0xa430729c  sh          $s0, 0x729C($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 29340), (uint16_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7C9Cu; }
        if (ctx->pc != 0x1D7C9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7C9Cu; }
        if (ctx->pc != 0x1D7C9Cu) { return; }
    }
    ctx->pc = 0x1D7C9Cu;
label_1d7c9c:
    // 0x1d7c9c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7c9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7ca0: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D7CA0u;
    SET_GPR_U32(ctx, 31, 0x1D7CA8u);
    ctx->pc = 0x1D7CA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7CA0u;
            // 0x1d7ca4: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7CA8u; }
        if (ctx->pc != 0x1D7CA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7CA8u; }
        if (ctx->pc != 0x1D7CA8u) { return; }
    }
    ctx->pc = 0x1D7CA8u;
label_1d7ca8:
    // 0x1d7ca8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d7ca8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7cac: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d7cacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d7cb0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d7cb0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d7cb4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D7CB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D7CB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7CB4u;
            // 0x1d7cb8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7C74u: goto label_1d7c74;
            case 0x1D7C9Cu: goto label_1d7c9c;
            case 0x1D7CA8u: goto label_1d7ca8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D7CBCu;
    // 0x1d7cbc: 0x0  nop
    ctx->pc = 0x1d7cbcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
