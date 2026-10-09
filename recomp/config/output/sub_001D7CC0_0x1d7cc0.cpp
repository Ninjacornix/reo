#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7CC0
// Address: 0x1d7cc0 - 0x1d7d20
void sub_001D7CC0_0x1d7cc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7CC0_0x1d7cc0");
#endif

    switch (ctx->pc) {
        case 0x1d7cd4u: goto label_1d7cd4;
        case 0x1d7cfcu: goto label_1d7cfc;
        case 0x1d7d08u: goto label_1d7d08;
        default: break;
    }

    ctx->pc = 0x1d7cc0u;

    // 0x1d7cc0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d7cc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d7cc4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d7cc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d7cc8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d7cc8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d7ccc: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D7CCCu;
    SET_GPR_U32(ctx, 31, 0x1D7CD4u);
    ctx->pc = 0x1D7CD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7CCCu;
            // 0x1d7cd0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7CD4u; }
        if (ctx->pc != 0x1D7CD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7CD4u; }
        if (ctx->pc != 0x1D7CD4u) { return; }
    }
    ctx->pc = 0x1D7CD4u;
label_1d7cd4:
    // 0x1d7cd4: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d7cd4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d7cd8: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d7cd8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d7cdc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7cdcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7ce0: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x1d7ce0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d7ce4: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d7ce4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d7ce8: 0x24060022  addiu       $a2, $zero, 0x22
    ctx->pc = 0x1d7ce8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1d7cec: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d7cecu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d7cf0: 0x24080020  addiu       $t0, $zero, 0x20
    ctx->pc = 0x1d7cf0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d7cf4: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D7CF4u;
    SET_GPR_U32(ctx, 31, 0x1D7CFCu);
    ctx->pc = 0x1D7CF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7CF4u;
            // 0x1d7cf8: 0xa430729c  sh          $s0, 0x729C($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 29340), (uint16_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7CFCu; }
        if (ctx->pc != 0x1D7CFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7CFCu; }
        if (ctx->pc != 0x1D7CFCu) { return; }
    }
    ctx->pc = 0x1D7CFCu;
label_1d7cfc:
    // 0x1d7cfc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7cfcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7d00: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D7D00u;
    SET_GPR_U32(ctx, 31, 0x1D7D08u);
    ctx->pc = 0x1D7D04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7D00u;
            // 0x1d7d04: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7D08u; }
        if (ctx->pc != 0x1D7D08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7D08u; }
        if (ctx->pc != 0x1D7D08u) { return; }
    }
    ctx->pc = 0x1D7D08u;
label_1d7d08:
    // 0x1d7d08: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d7d08u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7d0c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d7d0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d7d10: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d7d10u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d7d14: 0x3e00008  jr          $ra
    ctx->pc = 0x1D7D14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D7D18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7D14u;
            // 0x1d7d18: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7CD4u: goto label_1d7cd4;
            case 0x1D7CFCu: goto label_1d7cfc;
            case 0x1D7D08u: goto label_1d7d08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D7D1Cu;
    // 0x1d7d1c: 0x0  nop
    ctx->pc = 0x1d7d1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
