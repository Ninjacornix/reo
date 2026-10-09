#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D8E70
// Address: 0x1d8e70 - 0x1d8ee0
void sub_001D8E70_0x1d8e70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D8E70_0x1d8e70");
#endif

    switch (ctx->pc) {
        case 0x1d8e8cu: goto label_1d8e8c;
        case 0x1d8ebcu: goto label_1d8ebc;
        case 0x1d8ec8u: goto label_1d8ec8;
        default: break;
    }

    ctx->pc = 0x1d8e70u;

    // 0x1d8e70: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d8e70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d8e74: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d8e74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d8e78: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d8e78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d8e7c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d8e7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d8e80: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d8e80u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8e84: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D8E84u;
    SET_GPR_U32(ctx, 31, 0x1D8E8Cu);
    ctx->pc = 0x1D8E88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8E84u;
            // 0x1d8e88: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8E8Cu; }
        if (ctx->pc != 0x1D8E8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8E8Cu; }
        if (ctx->pc != 0x1D8E8Cu) { return; }
    }
    ctx->pc = 0x1D8E8Cu;
label_1d8e8c:
    // 0x1d8e8c: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d8e8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d8e90: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d8e90u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d8e94: 0x2442729c  addiu       $v0, $v0, 0x729C
    ctx->pc = 0x1d8e94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 29340));
    // 0x1d8e98: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d8e98u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d8e9c: 0xac510000  sw          $s1, 0x0($v0)
    ctx->pc = 0x1d8e9cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 17));
    // 0x1d8ea0: 0x24040033  addiu       $a0, $zero, 0x33
    ctx->pc = 0x1d8ea0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 51));
    // 0x1d8ea4: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d8ea4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d8ea8: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x1d8ea8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x1d8eac: 0x24060028  addiu       $a2, $zero, 0x28
    ctx->pc = 0x1d8eacu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1d8eb0: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d8eb0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d8eb4: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D8EB4u;
    SET_GPR_U32(ctx, 31, 0x1D8EBCu);
    ctx->pc = 0x1D8EB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8EB4u;
            // 0x1d8eb8: 0x24080020  addiu       $t0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8EBCu; }
        if (ctx->pc != 0x1D8EBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8EBCu; }
        if (ctx->pc != 0x1D8EBCu) { return; }
    }
    ctx->pc = 0x1D8EBCu;
label_1d8ebc:
    // 0x1d8ebc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d8ebcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d8ec0: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D8EC0u;
    SET_GPR_U32(ctx, 31, 0x1D8EC8u);
    ctx->pc = 0x1D8EC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8EC0u;
            // 0x1d8ec4: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8EC8u; }
        if (ctx->pc != 0x1D8EC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8EC8u; }
        if (ctx->pc != 0x1D8EC8u) { return; }
    }
    ctx->pc = 0x1D8EC8u;
label_1d8ec8:
    // 0x1d8ec8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d8ec8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8ecc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d8eccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d8ed0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d8ed0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d8ed4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d8ed4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d8ed8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D8ED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D8EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8ED8u;
            // 0x1d8edc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D8E8Cu: goto label_1d8e8c;
            case 0x1D8EBCu: goto label_1d8ebc;
            case 0x1D8EC8u: goto label_1d8ec8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D8EE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
