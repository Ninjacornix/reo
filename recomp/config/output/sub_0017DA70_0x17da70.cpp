#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017DA70
// Address: 0x17da70 - 0x17daf0
void sub_0017DA70_0x17da70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017DA70_0x17da70");
#endif

    switch (ctx->pc) {
        case 0x17daccu: goto label_17dacc;
        default: break;
    }

    ctx->pc = 0x17da70u;

    // 0x17da70: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17da70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17da74: 0x24840028  addiu       $a0, $a0, 0x28
    ctx->pc = 0x17da74u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 40));
    // 0x17da78: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x17da78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x17da7c: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x17da7cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17da80: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x17da80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x17da84: 0x100882d  daddu       $s1, $t0, $zero
    ctx->pc = 0x17da84u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17da88: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17da88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17da8c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17da8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17da90: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x17da90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17da94: 0x54430005  bnel        $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x17DA94u;
    {
        const bool branch_taken_0x17da94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x17da94) {
            ctx->pc = 0x17DA98u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17DA94u;
            // 0x17da98: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17DAACu;
            goto label_17daac;
        }
    }
    ctx->pc = 0x17DA9Cu;
    // 0x17da9c: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x17da9cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x17daa0: 0x54600005  bnel        $v1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x17DAA0u;
    {
        const bool branch_taken_0x17daa0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x17daa0) {
            ctx->pc = 0x17DAA4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17DAA0u;
            // 0x17daa4: 0x8c820008  lw          $v0, 0x8($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17DAB8u;
            goto label_17dab8;
        }
    }
    ctx->pc = 0x17DAA8u;
    // 0x17daa8: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x17daa8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_17daac:
    // 0x17daac: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x17DAACu;
    {
        const bool branch_taken_0x17daac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17DAB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DAACu;
            // 0x17dab0: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17daac) {
            ctx->pc = 0x17DADCu;
            goto label_17dadc;
        }
    }
    ctx->pc = 0x17DAB4u;
    // 0x17dab4: 0x0  nop
    ctx->pc = 0x17dab4u;
    // NOP
label_17dab8:
    // 0x17dab8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17dab8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17dabc: 0x27a70010  addiu       $a3, $sp, 0x10
    ctx->pc = 0x17dabcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x17dac0: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x17dac0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x17dac4: 0xc050288  jal         func_140A20
    ctx->pc = 0x17DAC4u;
    SET_GPR_U32(ctx, 31, 0x17DACCu);
    ctx->pc = 0x17DAC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17DAC4u;
            // 0x17dac8: 0xafa20004  sw          $v0, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140A20u;
    if (runtime->hasFunction(0x140A20u)) {
        auto targetFn = runtime->lookupFunction(0x140A20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DACCu; }
        if (ctx->pc != 0x17DACCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140A20_0x140a20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DACCu; }
        if (ctx->pc != 0x17DACCu) { return; }
    }
    ctx->pc = 0x17DACCu;
label_17dacc:
    // 0x17dacc: 0x8fa30010  lw          $v1, 0x10($sp)
    ctx->pc = 0x17daccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17dad0: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x17dad0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x17dad4: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x17dad4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x17dad8: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x17dad8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
label_17dadc:
    // 0x17dadc: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x17dadcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17dae0: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x17dae0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x17dae4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x17dae4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17dae8: 0x3e00008  jr          $ra
    ctx->pc = 0x17DAE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17DAECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DAE8u;
            // 0x17daec: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17DAACu: goto label_17daac;
            case 0x17DAB8u: goto label_17dab8;
            case 0x17DACCu: goto label_17dacc;
            case 0x17DADCu: goto label_17dadc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17DAF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
