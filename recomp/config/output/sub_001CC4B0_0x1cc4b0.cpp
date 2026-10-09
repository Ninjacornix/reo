#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CC4B0
// Address: 0x1cc4b0 - 0x1cc548
void sub_001CC4B0_0x1cc4b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CC4B0_0x1cc4b0");
#endif

    switch (ctx->pc) {
        case 0x1cc4e0u: goto label_1cc4e0;
        case 0x1cc510u: goto label_1cc510;
        case 0x1cc53cu: goto label_1cc53c;
        default: break;
    }

    ctx->pc = 0x1cc4b0u;

    // 0x1cc4b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cc4b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cc4b4: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1cc4b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1cc4b8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cc4b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cc4bc: 0x24630a40  addiu       $v1, $v1, 0xA40
    ctx->pc = 0x1cc4bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2624));
    // 0x1cc4c0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc4c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc4c4: 0xac230a20  sw          $v1, 0xA20($at)
    ctx->pc = 0x1cc4c4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2592), GPR_U32(ctx, 3));
    // 0x1cc4c8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1cc4c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1cc4cc: 0x902343d5  lbu         $v1, 0x43D5($at)
    ctx->pc = 0x1cc4ccu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17365)));
    // 0x1cc4d0: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CC4D0u;
    {
        const bool branch_taken_0x1cc4d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CC4D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC4D0u;
            // 0x1cc4d4: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cc4d0) {
            ctx->pc = 0x1CC4E8u;
            goto label_1cc4e8;
        }
    }
    ctx->pc = 0x1CC4D8u;
    // 0x1cc4d8: 0xc0de938  jal         func_37A4E0
    ctx->pc = 0x1CC4D8u;
    SET_GPR_U32(ctx, 31, 0x1CC4E0u);
    ctx->pc = 0x37A4E0u;
    {
        auto targetFn = runtime->lookupFunction(0x37A4E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC4E0u; }
        if (ctx->pc != 0x1CC4E0u) { return; }
    }
    ctx->pc = 0x1CC4E0u;
label_1cc4e0:
    // 0x1cc4e0: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1CC4E0u;
    {
        const bool branch_taken_0x1cc4e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CC4E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC4E0u;
            // 0x1cc4e4: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cc4e0) {
            ctx->pc = 0x1CC540u;
            goto label_1cc540;
        }
    }
    ctx->pc = 0x1CC4E8u;
label_1cc4e8:
    // 0x1cc4e8: 0x8c240a20  lw          $a0, 0xA20($at)
    ctx->pc = 0x1cc4e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2592)));
    // 0x1cc4ec: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1cc4ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1cc4f0: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1CC4F0u;
    {
        const bool branch_taken_0x1cc4f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cc4f0) {
            ctx->pc = 0x1CC53Cu;
            goto label_1cc53c;
        }
    }
    ctx->pc = 0x1CC4F8u;
    // 0x1cc4f8: 0x8c820084  lw          $v0, 0x84($a0)
    ctx->pc = 0x1cc4f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 132)));
    // 0x1cc4fc: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CC4FCu;
    {
        const bool branch_taken_0x1cc4fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cc4fc) {
            ctx->pc = 0x1CC51Cu;
            goto label_1cc51c;
        }
    }
    ctx->pc = 0x1CC504u;
    // 0x1cc504: 0x24040ff0  addiu       $a0, $zero, 0xFF0
    ctx->pc = 0x1cc504u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4080));
    // 0x1cc508: 0xc073420  jal         func_1CD080
    ctx->pc = 0x1CC508u;
    SET_GPR_U32(ctx, 31, 0x1CC510u);
    ctx->pc = 0x1CC50Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC508u;
            // 0x1cc50c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD080u;
    if (runtime->hasFunction(0x1CD080u)) {
        auto targetFn = runtime->lookupFunction(0x1CD080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC510u; }
        if (ctx->pc != 0x1CC510u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD080_0x1cd080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC510u; }
        if (ctx->pc != 0x1CC510u) { return; }
    }
    ctx->pc = 0x1CC510u;
label_1cc510:
    // 0x1cc510: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc510u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc514: 0x8c220a20  lw          $v0, 0xA20($at)
    ctx->pc = 0x1cc514u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2592)));
    // 0x1cc518: 0xac400084  sw          $zero, 0x84($v0)
    ctx->pc = 0x1cc518u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 132), GPR_U32(ctx, 0));
label_1cc51c:
    // 0x1cc51c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc51cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc520: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cc520u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cc524: 0x8c220a20  lw          $v0, 0xA20($at)
    ctx->pc = 0x1cc524u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2592)));
    // 0x1cc528: 0x24840a40  addiu       $a0, $a0, 0xA40
    ctx->pc = 0x1cc528u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2624));
    // 0x1cc52c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cc52cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc530: 0x24060098  addiu       $a2, $zero, 0x98
    ctx->pc = 0x1cc530u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 152));
    // 0x1cc534: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CC534u;
    SET_GPR_U32(ctx, 31, 0x1CC53Cu);
    ctx->pc = 0x1CC538u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC534u;
            // 0x1cc538: 0xac400000  sw          $zero, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC53Cu; }
        if (ctx->pc != 0x1CC53Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC53Cu; }
        if (ctx->pc != 0x1CC53Cu) { return; }
    }
    ctx->pc = 0x1CC53Cu;
label_1cc53c:
    // 0x1cc53c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cc53cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1cc540:
    // 0x1cc540: 0x3e00008  jr          $ra
    ctx->pc = 0x1CC540u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CC544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC540u;
            // 0x1cc544: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CC4E0u: goto label_1cc4e0;
            case 0x1CC4E8u: goto label_1cc4e8;
            case 0x1CC510u: goto label_1cc510;
            case 0x1CC51Cu: goto label_1cc51c;
            case 0x1CC53Cu: goto label_1cc53c;
            case 0x1CC540u: goto label_1cc540;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CC548u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
