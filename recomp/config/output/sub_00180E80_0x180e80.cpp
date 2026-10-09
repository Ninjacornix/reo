#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180E80
// Address: 0x180e80 - 0x180eec
void sub_00180E80_0x180e80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180E80_0x180e80");
#endif

    switch (ctx->pc) {
        case 0x180ec4u: goto label_180ec4;
        case 0x180ee0u: goto label_180ee0;
        default: break;
    }

    ctx->pc = 0x180e80u;

    // 0x180e80: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x180e80u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x180e84: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x180e84u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x180e88: 0x8c66fa10  lw          $a2, -0x5F0($v1)
    ctx->pc = 0x180e88u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294965776)));
    // 0x180e8c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180e8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180e90: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x180e90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x180e94: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x180e94u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180e98: 0x10c00011  beqz        $a2, . + 4 + (0x11 << 2)
    ctx->pc = 0x180E98u;
    {
        const bool branch_taken_0x180e98 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x180E9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180E98u;
            // 0x180e9c: 0x34428001  ori         $v0, $v0, 0x8001 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180e98) {
            ctx->pc = 0x180EE0u;
            goto label_180ee0;
        }
    }
    ctx->pc = 0x180EA0u;
    // 0x180ea0: 0x3c040028  lui         $a0, 0x28
    ctx->pc = 0x180ea0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)40 << 16));
    // 0x180ea4: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180ea4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180ea8: 0x8c839504  lw          $v1, -0x6AFC($a0)
    ctx->pc = 0x180ea8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294939908)));
    // 0x180eac: 0x1460000c  bnez        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x180EACu;
    {
        const bool branch_taken_0x180eac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x180EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180EACu;
            // 0x180eb0: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180eac) {
            ctx->pc = 0x180EE0u;
            goto label_180ee0;
        }
    }
    ctx->pc = 0x180EB4u;
    // 0x180eb4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x180eb4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180eb8: 0xafa70008  sw          $a3, 0x8($sp)
    ctx->pc = 0x180eb8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 7));
    // 0x180ebc: 0xc062448  jal         func_189120
    ctx->pc = 0x180EBCu;
    SET_GPR_U32(ctx, 31, 0x180EC4u);
    ctx->pc = 0x180EC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180EBCu;
            // 0x180ec0: 0xafa5000c  sw          $a1, 0xC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189120u;
    if (runtime->hasFunction(0x189120u)) {
        auto targetFn = runtime->lookupFunction(0x189120u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180EC4u; }
        if (ctx->pc != 0x180EC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189120_0x189120(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180EC4u; }
        if (ctx->pc != 0x180EC4u) { return; }
    }
    ctx->pc = 0x180EC4u;
label_180ec4:
    // 0x180ec4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x180ec4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180ec8: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180ec8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180ecc: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x180eccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180ed0: 0x4600003  bltz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x180ED0u;
    {
        const bool branch_taken_0x180ed0 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x180ED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180ED0u;
            // 0x180ed4: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180ed0) {
            ctx->pc = 0x180EE0u;
            goto label_180ee0;
        }
    }
    ctx->pc = 0x180ED8u;
    // 0x180ed8: 0xc061eb4  jal         func_187AD0
    ctx->pc = 0x180ED8u;
    SET_GPR_U32(ctx, 31, 0x180EE0u);
    ctx->pc = 0x187AD0u;
    if (runtime->hasFunction(0x187AD0u)) {
        auto targetFn = runtime->lookupFunction(0x187AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180EE0u; }
        if (ctx->pc != 0x180EE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187AD0_0x187ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180EE0u; }
        if (ctx->pc != 0x180EE0u) { return; }
    }
    ctx->pc = 0x180EE0u;
label_180ee0:
    // 0x180ee0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x180ee0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x180ee4: 0x3e00008  jr          $ra
    ctx->pc = 0x180EE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180EE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180EE4u;
            // 0x180ee8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180EC4u: goto label_180ec4;
            case 0x180EE0u: goto label_180ee0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180EECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
