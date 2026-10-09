#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172278
// Address: 0x172278 - 0x1722c0
void sub_00172278_0x172278(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172278_0x172278");
#endif

    switch (ctx->pc) {
        case 0x17228cu: goto label_17228c;
        default: break;
    }

    ctx->pc = 0x172278u;

    // 0x172278: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x172278u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17227c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17227cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x172280: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x172280u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x172284: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x172284u;
    SET_GPR_U32(ctx, 31, 0x17228Cu);
    ctx->pc = 0x172288u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172284u;
            // 0x172288: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17228Cu; }
        if (ctx->pc != 0x17228Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17228Cu; }
        if (ctx->pc != 0x17228Cu) { return; }
    }
    ctx->pc = 0x17228Cu;
label_17228c:
    // 0x17228c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x17228cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x172290: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x172290u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172294: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x172294u;
    {
        const bool branch_taken_0x172294 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x172298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172294u;
            // 0x172298: 0x34a50143  ori         $a1, $a1, 0x143 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)323);
        ctx->in_delay_slot = false;
        if (branch_taken_0x172294) {
            ctx->pc = 0x1722B0u;
            goto label_1722b0;
        }
    }
    ctx->pc = 0x17229Cu;
    // 0x17229c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17229cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1722a0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1722a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1722a4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1722a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1722a8: 0x805a704  j           func_169C10
    ctx->pc = 0x1722A8u;
    ctx->pc = 0x1722ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1722A8u;
            // 0x1722ac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1722B0u;
label_1722b0:
    // 0x1722b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1722b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1722b4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1722b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1722b8: 0x805c8b0  j           func_1722C0
    ctx->pc = 0x1722B8u;
    ctx->pc = 0x1722BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1722B8u;
            // 0x1722bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1722C0u;
    if (runtime->hasFunction(0x1722C0u)) {
        auto targetFn = runtime->lookupFunction(0x1722C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001722C0_0x1722c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1722C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
