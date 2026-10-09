#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148760
// Address: 0x148760 - 0x148828
void sub_00148760_0x148760(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148760_0x148760");
#endif

    switch (ctx->pc) {
        case 0x148778u: goto label_148778;
        case 0x1487e0u: goto label_1487e0;
        default: break;
    }

    ctx->pc = 0x148760u;

    // 0x148760: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x148760u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x148764: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x148764u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148768: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x148768u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x14876c: 0xac820830  sw          $v0, 0x830($a0)
    ctx->pc = 0x14876cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 2096), GPR_U32(ctx, 2));
    // 0x148770: 0xc047598  jal         func_11D660
    ctx->pc = 0x148770u;
    SET_GPR_U32(ctx, 31, 0x148778u);
    ctx->pc = 0x148774u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148770u;
            // 0x148774: 0xac8001c8  sw          $zero, 0x1C8($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 456), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148778u; }
        if (ctx->pc != 0x148778u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148778u; }
        if (ctx->pc != 0x148778u) { return; }
    }
    ctx->pc = 0x148778u;
label_148778:
    // 0x148778: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x148778u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x14877c: 0x3c071000  lui         $a3, 0x1000
    ctx->pc = 0x14877cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)4096 << 16));
    // 0x148780: 0x34c6f520  ori         $a2, $a2, 0xF520
    ctx->pc = 0x148780u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)62752);
    // 0x148784: 0x3c080001  lui         $t0, 0x1
    ctx->pc = 0x148784u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)1 << 16));
    // 0x148788: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x148788u;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 6), 0))); // MMIO: 0x10000000
    // 0x14878c: 0x34e7f590  ori         $a3, $a3, 0xF590
    ctx->pc = 0x14878cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)62864);
    // 0x148790: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x148790u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x148794: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x148794u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x148798: 0x681825  or          $v1, $v1, $t0
    ctx->pc = 0x148798u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 8));
    // 0x14879c: 0x3484b000  ori         $a0, $a0, 0xB000
    ctx->pc = 0x14879cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)45056);
    // 0x1487a0: 0xace30000  sw          $v1, 0x0($a3)
    ctx->pc = 0x1487a0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    // 0x1487a4: 0x34a5b400  ori         $a1, $a1, 0xB400
    ctx->pc = 0x1487a4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)46080);
    // 0x1487a8: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x1487a8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x1487ac: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1487acu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1487b0: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x1487b0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x1487b4: 0x3463d400  ori         $v1, $v1, 0xD400
    ctx->pc = 0x1487b4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)54272);
    // 0x1487b8: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x1487b8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x1487bc: 0x3c04fffe  lui         $a0, 0xFFFE
    ctx->pc = 0x1487bcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65534 << 16));
    // 0x1487c0: 0x3484ffff  ori         $a0, $a0, 0xFFFF
    ctx->pc = 0x1487c0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65535);
    // 0x1487c4: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x1487c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1487c8: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x1487c8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x1487cc: 0xace30000  sw          $v1, 0x0($a3)
    ctx->pc = 0x1487ccu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    // 0x1487d0: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1487D0u;
    {
        const bool branch_taken_0x1487d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1487D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1487D0u;
            // 0x1487d4: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1487d0) {
            ctx->pc = 0x1487E4u;
            goto label_1487e4;
        }
    }
    ctx->pc = 0x1487D8u;
    // 0x1487d8: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x1487D8u;
    SET_GPR_U32(ctx, 31, 0x1487E0u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1487E0u; }
        if (ctx->pc != 0x1487E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1487E0u; }
        if (ctx->pc != 0x1487E0u) { return; }
    }
    ctx->pc = 0x1487E0u;
label_1487e0:
    // 0x1487e0: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1487e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
label_1487e4:
    // 0x1487e4: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x1487e4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x1487e8: 0x3442b020  ori         $v0, $v0, 0xB020
    ctx->pc = 0x1487e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)45088);
    // 0x1487ec: 0x3484b420  ori         $a0, $a0, 0xB420
    ctx->pc = 0x1487ecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)46112);
    // 0x1487f0: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1487f0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x1487f4: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1487f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1487f8: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x1487f8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x1487fc: 0x3463d420  ori         $v1, $v1, 0xD420
    ctx->pc = 0x1487fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)54304);
    // 0x148800: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x148800u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x148804: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x148804u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x148808: 0x34422010  ori         $v0, $v0, 0x2010
    ctx->pc = 0x148808u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8208);
    // 0x14880c: 0x3c034000  lui         $v1, 0x4000
    ctx->pc = 0x14880cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16384 << 16));
    // 0x148810: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x148810u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x148814: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x148814u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148818: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x148818u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x14881c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x14881cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148820: 0x8044fb4  j           func_113ED0
    ctx->pc = 0x148820u;
    ctx->pc = 0x148824u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148820u;
            // 0x148824: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113ED0u;
    if (runtime->hasFunction(0x113ED0u)) {
        auto targetFn = runtime->lookupFunction(0x113ED0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00113ED0_0x113ed0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x148828u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
