#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D8FC0
// Address: 0x1d8fc0 - 0x1d9030
void sub_001D8FC0_0x1d8fc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D8FC0_0x1d8fc0");
#endif

    switch (ctx->pc) {
        case 0x1d8fdcu: goto label_1d8fdc;
        case 0x1d900cu: goto label_1d900c;
        case 0x1d9018u: goto label_1d9018;
        default: break;
    }

    ctx->pc = 0x1d8fc0u;

    // 0x1d8fc0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d8fc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d8fc4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d8fc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d8fc8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d8fc8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d8fcc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d8fccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d8fd0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d8fd0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8fd4: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D8FD4u;
    SET_GPR_U32(ctx, 31, 0x1D8FDCu);
    ctx->pc = 0x1D8FD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8FD4u;
            // 0x1d8fd8: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8FDCu; }
        if (ctx->pc != 0x1D8FDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8FDCu; }
        if (ctx->pc != 0x1D8FDCu) { return; }
    }
    ctx->pc = 0x1D8FDCu;
label_1d8fdc:
    // 0x1d8fdc: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d8fdcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d8fe0: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d8fe0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d8fe4: 0x2442729c  addiu       $v0, $v0, 0x729C
    ctx->pc = 0x1d8fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 29340));
    // 0x1d8fe8: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d8fe8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d8fec: 0xac510000  sw          $s1, 0x0($v0)
    ctx->pc = 0x1d8fecu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 17));
    // 0x1d8ff0: 0x24040037  addiu       $a0, $zero, 0x37
    ctx->pc = 0x1d8ff0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 55));
    // 0x1d8ff4: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d8ff4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d8ff8: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x1d8ff8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x1d8ffc: 0x24060028  addiu       $a2, $zero, 0x28
    ctx->pc = 0x1d8ffcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1d9000: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d9000u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d9004: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D9004u;
    SET_GPR_U32(ctx, 31, 0x1D900Cu);
    ctx->pc = 0x1D9008u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9004u;
            // 0x1d9008: 0x24080020  addiu       $t0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D900Cu; }
        if (ctx->pc != 0x1D900Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D900Cu; }
        if (ctx->pc != 0x1D900Cu) { return; }
    }
    ctx->pc = 0x1D900Cu;
label_1d900c:
    // 0x1d900c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d900cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d9010: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D9010u;
    SET_GPR_U32(ctx, 31, 0x1D9018u);
    ctx->pc = 0x1D9014u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9010u;
            // 0x1d9014: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9018u; }
        if (ctx->pc != 0x1D9018u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9018u; }
        if (ctx->pc != 0x1D9018u) { return; }
    }
    ctx->pc = 0x1D9018u;
label_1d9018:
    // 0x1d9018: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d9018u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d901c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d901cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d9020: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d9020u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d9024: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d9024u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d9028: 0x3e00008  jr          $ra
    ctx->pc = 0x1D9028u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D902Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9028u;
            // 0x1d902c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D8FDCu: goto label_1d8fdc;
            case 0x1D900Cu: goto label_1d900c;
            case 0x1D9018u: goto label_1d9018;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D9030u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
