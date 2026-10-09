#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D8290
// Address: 0x1d8290 - 0x1d82f0
void sub_001D8290_0x1d8290(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D8290_0x1d8290");
#endif

    switch (ctx->pc) {
        case 0x1d82a4u: goto label_1d82a4;
        case 0x1d82ccu: goto label_1d82cc;
        case 0x1d82d8u: goto label_1d82d8;
        default: break;
    }

    ctx->pc = 0x1d8290u;

    // 0x1d8290: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d8290u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d8294: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d8294u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d8298: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d8298u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d829c: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D829Cu;
    SET_GPR_U32(ctx, 31, 0x1D82A4u);
    ctx->pc = 0x1D82A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D829Cu;
            // 0x1d82a0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D82A4u; }
        if (ctx->pc != 0x1D82A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D82A4u; }
        if (ctx->pc != 0x1D82A4u) { return; }
    }
    ctx->pc = 0x1D82A4u;
label_1d82a4:
    // 0x1d82a4: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d82a4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d82a8: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d82a8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d82ac: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d82acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d82b0: 0x24040017  addiu       $a0, $zero, 0x17
    ctx->pc = 0x1d82b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 23));
    // 0x1d82b4: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d82b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d82b8: 0x24060022  addiu       $a2, $zero, 0x22
    ctx->pc = 0x1d82b8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1d82bc: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d82bcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d82c0: 0x24080020  addiu       $t0, $zero, 0x20
    ctx->pc = 0x1d82c0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d82c4: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D82C4u;
    SET_GPR_U32(ctx, 31, 0x1D82CCu);
    ctx->pc = 0x1D82C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D82C4u;
            // 0x1d82c8: 0xa430729c  sh          $s0, 0x729C($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 29340), (uint16_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D82CCu; }
        if (ctx->pc != 0x1D82CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D82CCu; }
        if (ctx->pc != 0x1D82CCu) { return; }
    }
    ctx->pc = 0x1D82CCu;
label_1d82cc:
    // 0x1d82cc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d82ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d82d0: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D82D0u;
    SET_GPR_U32(ctx, 31, 0x1D82D8u);
    ctx->pc = 0x1D82D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D82D0u;
            // 0x1d82d4: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D82D8u; }
        if (ctx->pc != 0x1D82D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D82D8u; }
        if (ctx->pc != 0x1D82D8u) { return; }
    }
    ctx->pc = 0x1D82D8u;
label_1d82d8:
    // 0x1d82d8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d82d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d82dc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d82dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d82e0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d82e0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d82e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D82E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D82E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D82E4u;
            // 0x1d82e8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D82A4u: goto label_1d82a4;
            case 0x1D82CCu: goto label_1d82cc;
            case 0x1D82D8u: goto label_1d82d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D82ECu;
    // 0x1d82ec: 0x0  nop
    ctx->pc = 0x1d82ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
