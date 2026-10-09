#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001034E8
// Address: 0x1034e8 - 0x103530
void sub_001034E8_0x1034e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001034E8_0x1034e8");
#endif

    switch (ctx->pc) {
        case 0x1034fcu: goto label_1034fc;
        default: break;
    }

    ctx->pc = 0x1034e8u;

    // 0x1034e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1034e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1034ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1034ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1034f0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1034f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1034f4: 0xc040bc2  jal         func_102F08
    ctx->pc = 0x1034F4u;
    SET_GPR_U32(ctx, 31, 0x1034FCu);
    ctx->pc = 0x1034F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1034F4u;
            // 0x1034f8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102F08u;
    if (runtime->hasFunction(0x102F08u)) {
        auto targetFn = runtime->lookupFunction(0x102F08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1034FCu; }
        if (ctx->pc != 0x1034FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102F08_0x102f08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1034FCu; }
        if (ctx->pc != 0x1034FCu) { return; }
    }
    ctx->pc = 0x1034FCu;
label_1034fc:
    // 0x1034fc: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1034fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x103500: 0x2403fff3  addiu       $v1, $zero, -0xD
    ctx->pc = 0x103500u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967283));
    // 0x103504: 0x2404fffe  addiu       $a0, $zero, -0x2
    ctx->pc = 0x103504u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x103508: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x103508u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x10350c: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x10350cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x103510: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x103510u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x103514: 0x34420004  ori         $v0, $v0, 0x4
    ctx->pc = 0x103514u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4);
    // 0x103518: 0x441024  and         $v0, $v0, $a0
    ctx->pc = 0x103518u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x10351c: 0x34420100  ori         $v0, $v0, 0x100
    ctx->pc = 0x10351cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)256);
    // 0x103520: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x103520u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x103524: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x103524u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x103528: 0x3e00008  jr          $ra
    ctx->pc = 0x103528u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10352Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103528u;
            // 0x10352c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1034FCu: goto label_1034fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103530u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
