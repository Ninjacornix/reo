#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D8BE0
// Address: 0x1d8be0 - 0x1d8c40
void sub_001D8BE0_0x1d8be0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D8BE0_0x1d8be0");
#endif

    switch (ctx->pc) {
        case 0x1d8bf4u: goto label_1d8bf4;
        case 0x1d8c1cu: goto label_1d8c1c;
        case 0x1d8c28u: goto label_1d8c28;
        default: break;
    }

    ctx->pc = 0x1d8be0u;

    // 0x1d8be0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d8be0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d8be4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d8be4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d8be8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d8be8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d8bec: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D8BECu;
    SET_GPR_U32(ctx, 31, 0x1D8BF4u);
    ctx->pc = 0x1D8BF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8BECu;
            // 0x1d8bf0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8BF4u; }
        if (ctx->pc != 0x1D8BF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8BF4u; }
        if (ctx->pc != 0x1D8BF4u) { return; }
    }
    ctx->pc = 0x1D8BF4u;
label_1d8bf4:
    // 0x1d8bf4: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d8bf4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d8bf8: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x1d8bf8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d8bfc: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d8bfcu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d8c00: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d8c00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d8c04: 0x24040029  addiu       $a0, $zero, 0x29
    ctx->pc = 0x1d8c04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 41));
    // 0x1d8c08: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d8c08u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d8c0c: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d8c0cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d8c10: 0xc0402d  daddu       $t0, $a2, $zero
    ctx->pc = 0x1d8c10u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8c14: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D8C14u;
    SET_GPR_U32(ctx, 31, 0x1D8C1Cu);
    ctx->pc = 0x1D8C18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8C14u;
            // 0x1d8c18: 0xac307280  sw          $s0, 0x7280($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 29312), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8C1Cu; }
        if (ctx->pc != 0x1D8C1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8C1Cu; }
        if (ctx->pc != 0x1D8C1Cu) { return; }
    }
    ctx->pc = 0x1D8C1Cu;
label_1d8c1c:
    // 0x1d8c1c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d8c1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d8c20: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D8C20u;
    SET_GPR_U32(ctx, 31, 0x1D8C28u);
    ctx->pc = 0x1D8C24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8C20u;
            // 0x1d8c24: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8C28u; }
        if (ctx->pc != 0x1D8C28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8C28u; }
        if (ctx->pc != 0x1D8C28u) { return; }
    }
    ctx->pc = 0x1D8C28u;
label_1d8c28:
    // 0x1d8c28: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d8c28u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8c2c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d8c2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d8c30: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d8c30u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d8c34: 0x3e00008  jr          $ra
    ctx->pc = 0x1D8C34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D8C38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8C34u;
            // 0x1d8c38: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D8BF4u: goto label_1d8bf4;
            case 0x1D8C1Cu: goto label_1d8c1c;
            case 0x1D8C28u: goto label_1d8c28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D8C3Cu;
    // 0x1d8c3c: 0x0  nop
    ctx->pc = 0x1d8c3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
