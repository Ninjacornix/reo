#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1300
// Address: 0x1b1300 - 0x1b1360
void sub_001B1300_0x1b1300(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1300_0x1b1300");
#endif

    switch (ctx->pc) {
        case 0x1b1310u: goto label_1b1310;
        case 0x1b1350u: goto label_1b1350;
        default: break;
    }

    ctx->pc = 0x1b1300u;

    // 0x1b1300: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b1300u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b1304: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b1304u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b1308: 0xc06c4b0  jal         func_1B12C0
    ctx->pc = 0x1B1308u;
    SET_GPR_U32(ctx, 31, 0x1B1310u);
    ctx->pc = 0x1B12C0u;
    if (runtime->hasFunction(0x1B12C0u)) {
        auto targetFn = runtime->lookupFunction(0x1B12C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1310u; }
        if (ctx->pc != 0x1B1310u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B12C0_0x1b12c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1310u; }
        if (ctx->pc != 0x1B1310u) { return; }
    }
    ctx->pc = 0x1B1310u;
label_1b1310:
    // 0x1b1310: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b1310u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b1314: 0x1043000e  beq         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1B1314u;
    {
        const bool branch_taken_0x1b1314 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B1318u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1314u;
            // 0x1b1318: 0x3c01004f  lui         $at, 0x4F (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)79 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1314) {
            ctx->pc = 0x1B1350u;
            goto label_1b1350;
        }
    }
    ctx->pc = 0x1B131Cu;
    // 0x1b131c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b131cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1320: 0x8422dd80  lh          $v0, -0x2280($at)
    ctx->pc = 0x1b1320u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294958464)));
    // 0x1b1324: 0x24060190  addiu       $a2, $zero, 0x190
    ctx->pc = 0x1b1324u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 400));
    // 0x1b1328: 0x3c01004f  lui         $at, 0x4F
    ctx->pc = 0x1b1328u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)79 << 16));
    // 0x1b132c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1b132cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1b1330: 0x8c23cb70  lw          $v1, -0x3490($at)
    ctx->pc = 0x1b1330u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294953840)));
    // 0x1b1334: 0x3c01004f  lui         $at, 0x4F
    ctx->pc = 0x1b1334u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)79 << 16));
    // 0x1b1338: 0xa422dd80  sh          $v0, -0x2280($at)
    ctx->pc = 0x1b1338u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294958464), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b133c: 0x2462fffc  addiu       $v0, $v1, -0x4
    ctx->pc = 0x1b133cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967292));
    // 0x1b1340: 0x3c01004f  lui         $at, 0x4F
    ctx->pc = 0x1b1340u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)79 << 16));
    // 0x1b1344: 0xac22cb70  sw          $v0, -0x3490($at)
    ctx->pc = 0x1b1344u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294953840), GPR_U32(ctx, 2));
    // 0x1b1348: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B1348u;
    SET_GPR_U32(ctx, 31, 0x1B1350u);
    ctx->pc = 0x1B134Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1348u;
            // 0x1b134c: 0xac64fffc  sw          $a0, -0x4($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294967292), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1350u; }
        if (ctx->pc != 0x1B1350u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1350u; }
        if (ctx->pc != 0x1B1350u) { return; }
    }
    ctx->pc = 0x1B1350u;
label_1b1350:
    // 0x1b1350: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b1350u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b1354: 0x3e00008  jr          $ra
    ctx->pc = 0x1B1354u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B1358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1354u;
            // 0x1b1358: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B1310u: goto label_1b1310;
            case 0x1B1350u: goto label_1b1350;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B135Cu;
    // 0x1b135c: 0x0  nop
    ctx->pc = 0x1b135cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
