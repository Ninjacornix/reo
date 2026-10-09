#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00125248
// Address: 0x125248 - 0x125278
void sub_00125248_0x125248(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00125248_0x125248");
#endif

    switch (ctx->pc) {
        case 0x125260u: goto label_125260;
        default: break;
    }

    ctx->pc = 0x125248u;

    // 0x125248: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x125248u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12524c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12524cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x125250: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x125250u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125254: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x125254u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x125258: 0xc04d408  jal         func_135020
    ctx->pc = 0x125258u;
    SET_GPR_U32(ctx, 31, 0x125260u);
    ctx->pc = 0x12525Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125258u;
            // 0x12525c: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135020u;
    if (runtime->hasFunction(0x135020u)) {
        auto targetFn = runtime->lookupFunction(0x135020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125260u; }
        if (ctx->pc != 0x125260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135020_0x135020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125260u; }
        if (ctx->pc != 0x125260u) { return; }
    }
    ctx->pc = 0x125260u;
label_125260:
    // 0x125260: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x125260u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x125264: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x125264u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x125268: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x125268u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12526c: 0x3e00008  jr          $ra
    ctx->pc = 0x12526Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12526Cu;
            // 0x125270: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125260u: goto label_125260;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125274u;
    // 0x125274: 0x0  nop
    ctx->pc = 0x125274u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
