#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00108248
// Address: 0x108248 - 0x108280
void sub_00108248_0x108248(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00108248_0x108248");
#endif

    switch (ctx->pc) {
        case 0x108260u: goto label_108260;
        default: break;
    }

    ctx->pc = 0x108248u;

    // 0x108248: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x108248u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10824c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10824cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x108250: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x108250u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108254: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x108254u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x108258: 0xc041f7e  jal         func_107DF8
    ctx->pc = 0x108258u;
    SET_GPR_U32(ctx, 31, 0x108260u);
    ctx->pc = 0x10825Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x108258u;
            // 0x10825c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DF8u;
    if (runtime->hasFunction(0x107DF8u)) {
        auto targetFn = runtime->lookupFunction(0x107DF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108260u; }
        if (ctx->pc != 0x108260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DF8_0x107df8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108260u; }
        if (ctx->pc != 0x108260u) { return; }
    }
    ctx->pc = 0x108260u;
label_108260:
    // 0x108260: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x108260u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x108264: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x108264u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108268: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x108268u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10826c: 0xac900014  sw          $s0, 0x14($a0)
    ctx->pc = 0x10826cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 16));
    // 0x108270: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x108270u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x108274: 0xac830010  sw          $v1, 0x10($a0)
    ctx->pc = 0x108274u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 3));
    // 0x108278: 0x3e00008  jr          $ra
    ctx->pc = 0x108278u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10827Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108278u;
            // 0x10827c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108260u: goto label_108260;
            default: break;
        }
        return;
    }
    ctx->pc = 0x108280u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
