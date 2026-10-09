#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167D70
// Address: 0x167d70 - 0x167dd0
void sub_00167D70_0x167d70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167D70_0x167d70");
#endif

    switch (ctx->pc) {
        case 0x167d84u: goto label_167d84;
        case 0x167db8u: goto label_167db8;
        default: break;
    }

    ctx->pc = 0x167d70u;

    // 0x167d70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x167d70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x167d74: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x167d74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x167d78: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x167d78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x167d7c: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x167D7Cu;
    SET_GPR_U32(ctx, 31, 0x167D84u);
    ctx->pc = 0x167D80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167D7Cu;
            // 0x167d80: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167D84u; }
        if (ctx->pc != 0x167D84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167D84u; }
        if (ctx->pc != 0x167D84u) { return; }
    }
    ctx->pc = 0x167D84u;
label_167d84:
    // 0x167d84: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x167d84u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x167d88: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x167d88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167d8c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x167d8cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x167d90: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x167D90u;
    {
        const bool branch_taken_0x167d90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x167D94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167D90u;
            // 0x167d94: 0x34a50161  ori         $a1, $a1, 0x161 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)353);
        ctx->in_delay_slot = false;
        if (branch_taken_0x167d90) {
            ctx->pc = 0x167DB0u;
            goto label_167db0;
        }
    }
    ctx->pc = 0x167D98u;
    // 0x167d98: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x167d98u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x167d9c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x167d9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167da0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x167da0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x167da4: 0x805a704  j           func_169C10
    ctx->pc = 0x167DA4u;
    ctx->pc = 0x167DA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167DA4u;
            // 0x167da8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x167DACu;
    // 0x167dac: 0x0  nop
    ctx->pc = 0x167dacu;
    // NOP
label_167db0:
    // 0x167db0: 0xc05d518  jal         func_175460
    ctx->pc = 0x167DB0u;
    SET_GPR_U32(ctx, 31, 0x167DB8u);
    ctx->pc = 0x167DB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167DB0u;
            // 0x167db4: 0x24050031  addiu       $a1, $zero, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 49));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167DB8u; }
        if (ctx->pc != 0x167DB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167DB8u; }
        if (ctx->pc != 0x167DB8u) { return; }
    }
    ctx->pc = 0x167DB8u;
label_167db8:
    // 0x167db8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x167db8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167dbc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x167dbcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x167dc0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x167dc0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x167dc4: 0x3e00008  jr          $ra
    ctx->pc = 0x167DC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167DC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167DC4u;
            // 0x167dc8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167D84u: goto label_167d84;
            case 0x167DB0u: goto label_167db0;
            case 0x167DB8u: goto label_167db8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167DCCu;
    // 0x167dcc: 0x0  nop
    ctx->pc = 0x167dccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
