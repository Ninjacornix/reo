#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015EEC8
// Address: 0x15eec8 - 0x15ef24
void sub_0015EEC8_0x15eec8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015EEC8_0x15eec8");
#endif

    switch (ctx->pc) {
        case 0x15eef4u: goto label_15eef4;
        default: break;
    }

    ctx->pc = 0x15eec8u;

    // 0x15eec8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x15eec8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x15eecc: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x15eeccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x15eed0: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x15eed0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15eed4: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x15eed4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x15eed8: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x15eed8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15eedc: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x15eedcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x15eee0: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x15eee0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15eee4: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x15eee4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x15eee8: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x15eee8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15eeec: 0xc05cf8e  jal         func_173E38
    ctx->pc = 0x15EEECu;
    SET_GPR_U32(ctx, 31, 0x15EEF4u);
    ctx->pc = 0x15EEF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EEECu;
            // 0x15eef0: 0x8c840040  lw          $a0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173E38u;
    if (runtime->hasFunction(0x173E38u)) {
        auto targetFn = runtime->lookupFunction(0x173E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EEF4u; }
        if (ctx->pc != 0x15EEF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173E38_0x173e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EEF4u; }
        if (ctx->pc != 0x15EEF4u) { return; }
    }
    ctx->pc = 0x15EEF4u;
label_15eef4:
    // 0x15eef4: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x15eef4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15eef8: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x15eef8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x15eefc: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x15eefcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x15ef00: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x15ef00u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x15ef04: 0xae440000  sw          $a0, 0x0($s2)
    ctx->pc = 0x15ef04u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 4));
    // 0x15ef08: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x15ef08u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x15ef0c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x15ef0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15ef10: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x15ef10u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15ef14: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x15ef14u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x15ef18: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x15ef18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x15ef1c: 0x3e00008  jr          $ra
    ctx->pc = 0x15EF1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EF20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF1Cu;
            // 0x15ef20: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EEF4u: goto label_15eef4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EF24u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
