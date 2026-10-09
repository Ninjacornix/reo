#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D8720
// Address: 0x1d8720 - 0x1d8780
void sub_001D8720_0x1d8720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D8720_0x1d8720");
#endif

    switch (ctx->pc) {
        case 0x1d8734u: goto label_1d8734;
        case 0x1d875cu: goto label_1d875c;
        case 0x1d8768u: goto label_1d8768;
        default: break;
    }

    ctx->pc = 0x1d8720u;

    // 0x1d8720: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d8720u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d8724: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d8724u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d8728: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d8728u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d872c: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D872Cu;
    SET_GPR_U32(ctx, 31, 0x1D8734u);
    ctx->pc = 0x1D8730u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D872Cu;
            // 0x1d8730: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8734u; }
        if (ctx->pc != 0x1D8734u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8734u; }
        if (ctx->pc != 0x1D8734u) { return; }
    }
    ctx->pc = 0x1D8734u;
label_1d8734:
    // 0x1d8734: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d8734u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d8738: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d8738u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d873c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d873cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d8740: 0x2404001a  addiu       $a0, $zero, 0x1A
    ctx->pc = 0x1d8740u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 26));
    // 0x1d8744: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d8744u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d8748: 0x24060022  addiu       $a2, $zero, 0x22
    ctx->pc = 0x1d8748u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1d874c: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d874cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d8750: 0x24080020  addiu       $t0, $zero, 0x20
    ctx->pc = 0x1d8750u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d8754: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D8754u;
    SET_GPR_U32(ctx, 31, 0x1D875Cu);
    ctx->pc = 0x1D8758u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8754u;
            // 0x1d8758: 0xa430729c  sh          $s0, 0x729C($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 29340), (uint16_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D875Cu; }
        if (ctx->pc != 0x1D875Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D875Cu; }
        if (ctx->pc != 0x1D875Cu) { return; }
    }
    ctx->pc = 0x1D875Cu;
label_1d875c:
    // 0x1d875c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d875cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d8760: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D8760u;
    SET_GPR_U32(ctx, 31, 0x1D8768u);
    ctx->pc = 0x1D8764u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8760u;
            // 0x1d8764: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8768u; }
        if (ctx->pc != 0x1D8768u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8768u; }
        if (ctx->pc != 0x1D8768u) { return; }
    }
    ctx->pc = 0x1D8768u;
label_1d8768:
    // 0x1d8768: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d8768u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d876c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d876cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d8770: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d8770u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d8774: 0x3e00008  jr          $ra
    ctx->pc = 0x1D8774u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D8778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8774u;
            // 0x1d8778: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D8734u: goto label_1d8734;
            case 0x1D875Cu: goto label_1d875c;
            case 0x1D8768u: goto label_1d8768;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D877Cu;
    // 0x1d877c: 0x0  nop
    ctx->pc = 0x1d877cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
