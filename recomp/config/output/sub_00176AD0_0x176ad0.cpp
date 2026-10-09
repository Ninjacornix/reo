#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176AD0
// Address: 0x176ad0 - 0x176b08
void sub_00176AD0_0x176ad0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176AD0_0x176ad0");
#endif

    switch (ctx->pc) {
        case 0x176af0u: goto label_176af0;
        default: break;
    }

    ctx->pc = 0x176ad0u;

    // 0x176ad0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x176ad0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x176ad4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x176ad4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x176ad8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x176ad8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176adc: 0x24045dc0  addiu       $a0, $zero, 0x5DC0
    ctx->pc = 0x176adcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 24000));
    // 0x176ae0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x176ae0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x176ae4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x176ae4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x176ae8: 0xc05da98  jal         func_176A60
    ctx->pc = 0x176AE8u;
    SET_GPR_U32(ctx, 31, 0x176AF0u);
    ctx->pc = 0x176AECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176AE8u;
            // 0x176aec: 0xe0802d  daddu       $s0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176A60u;
    if (runtime->hasFunction(0x176A60u)) {
        auto targetFn = runtime->lookupFunction(0x176A60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176AF0u; }
        if (ctx->pc != 0x176AF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176A60_0x176a60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176AF0u; }
        if (ctx->pc != 0x176AF0u) { return; }
    }
    ctx->pc = 0x176AF0u;
label_176af0:
    // 0x176af0: 0xae110000  sw          $s1, 0x0($s0)
    ctx->pc = 0x176af0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
    // 0x176af4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x176af4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176af8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176af8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176afc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x176afcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176b00: 0x3e00008  jr          $ra
    ctx->pc = 0x176B00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176B04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176B00u;
            // 0x176b04: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176AF0u: goto label_176af0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176B08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
