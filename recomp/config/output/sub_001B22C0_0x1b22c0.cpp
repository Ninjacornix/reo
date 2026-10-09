#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B22C0
// Address: 0x1b22c0 - 0x1b2340
void sub_001B22C0_0x1b22c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B22C0_0x1b22c0");
#endif

    switch (ctx->pc) {
        case 0x1b22d8u: goto label_1b22d8;
        case 0x1b22fcu: goto label_1b22fc;
        default: break;
    }

    ctx->pc = 0x1b22c0u;

    // 0x1b22c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b22c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b22c4: 0x3c050032  lui         $a1, 0x32
    ctx->pc = 0x1b22c4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)50 << 16));
    // 0x1b22c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b22c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b22cc: 0x240400a0  addiu       $a0, $zero, 0xA0
    ctx->pc = 0x1b22ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 160));
    // 0x1b22d0: 0xc0696f4  jal         func_1A5BD0
    ctx->pc = 0x1B22D0u;
    SET_GPR_U32(ctx, 31, 0x1B22D8u);
    ctx->pc = 0x1B22D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B22D0u;
            // 0x1b22d4: 0x24a588e0  addiu       $a1, $a1, -0x7720 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294936800));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5BD0u;
    if (runtime->hasFunction(0x1A5BD0u)) {
        auto targetFn = runtime->lookupFunction(0x1A5BD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B22D8u; }
        if (ctx->pc != 0x1B22D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5BD0_0x1a5bd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B22D8u; }
        if (ctx->pc != 0x1B22D8u) { return; }
    }
    ctx->pc = 0x1B22D8u;
label_1b22d8:
    // 0x1b22d8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b22d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b22dc: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b22dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b22e0: 0x3c030031  lui         $v1, 0x31
    ctx->pc = 0x1b22e0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49 << 16));
    // 0x1b22e4: 0xa02468d0  sb          $a0, 0x68D0($at)
    ctx->pc = 0x1b22e4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 26832), (uint8_t)GPR_U32(ctx, 4));
    // 0x1b22e8: 0x246368c0  addiu       $v1, $v1, 0x68C0
    ctx->pc = 0x1b22e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 26816));
    // 0x1b22ec: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b22ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b22f0: 0x240700ff  addiu       $a3, $zero, 0xFF
    ctx->pc = 0x1b22f0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1b22f4: 0xac2366b0  sw          $v1, 0x66B0($at)
    ctx->pc = 0x1b22f4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26288), GPR_U32(ctx, 3));
    // 0x1b22f8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b22f8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b22fc:
    // 0x1b22fc: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b22fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b2300: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1b2300u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1b2304: 0x8c2566b0  lw          $a1, 0x66B0($at)
    ctx->pc = 0x1b2304u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26288)));
    // 0x1b2308: 0x28c30100  slti        $v1, $a2, 0x100
    ctx->pc = 0x1b2308u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x1b230c: 0x24a4fffe  addiu       $a0, $a1, -0x2
    ctx->pc = 0x1b230cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967294));
    // 0x1b2310: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b2310u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b2314: 0xac2466b0  sw          $a0, 0x66B0($at)
    ctx->pc = 0x1b2314u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26288), GPR_U32(ctx, 4));
    // 0x1b2318: 0xa4a7fffe  sh          $a3, -0x2($a1)
    ctx->pc = 0x1b2318u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 4294967294), (uint16_t)GPR_U32(ctx, 7));
    // 0x1b231c: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1B231Cu;
    {
        const bool branch_taken_0x1b231c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B2320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B231Cu;
            // 0x1b2320: 0x24e7ffff  addiu       $a3, $a3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b231c) {
            ctx->pc = 0x1B22FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b22fc;
        }
    }
    ctx->pc = 0x1B2324u;
    // 0x1b2324: 0x24030100  addiu       $v1, $zero, 0x100
    ctx->pc = 0x1b2324u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1b2328: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b2328u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b232c: 0xa42368c8  sh          $v1, 0x68C8($at)
    ctx->pc = 0x1b232cu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26824), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b2330: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b2330u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b2334: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2334u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B2338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2334u;
            // 0x1b2338: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B22D8u: goto label_1b22d8;
            case 0x1B22FCu: goto label_1b22fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B233Cu;
    // 0x1b233c: 0x0  nop
    ctx->pc = 0x1b233cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
