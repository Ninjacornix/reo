#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A8500
// Address: 0x1a8500 - 0x1a85a0
void sub_001A8500_0x1a8500(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A8500_0x1a8500");
#endif

    switch (ctx->pc) {
        case 0x1a8528u: goto label_1a8528;
        case 0x1a8558u: goto label_1a8558;
        default: break;
    }

    ctx->pc = 0x1a8500u;

    // 0x1a8500: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a8500u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a8504: 0xa6082a  slt         $at, $a1, $a2
    ctx->pc = 0x1a8504u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x1a8508: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A8508u;
    {
        const bool branch_taken_0x1a8508 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A850Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8508u;
            // 0x1a850c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8508) {
            ctx->pc = 0x1A851Cu;
            goto label_1a851c;
        }
    }
    ctx->pc = 0x1A8510u;
    // 0x1a8510: 0x28a10005  slti        $at, $a1, 0x5
    ctx->pc = 0x1a8510u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)5) ? 1 : 0);
    // 0x1a8514: 0x14200006  bnez        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A8514u;
    {
        const bool branch_taken_0x1a8514 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A8518u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8514u;
            // 0x1a8518: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8514) {
            ctx->pc = 0x1A8530u;
            goto label_1a8530;
        }
    }
    ctx->pc = 0x1A851Cu;
label_1a851c:
    // 0x1a851c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a851cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a8520: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A8520u;
    SET_GPR_U32(ctx, 31, 0x1A8528u);
    ctx->pc = 0x1A8524u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8520u;
            // 0x1a8524: 0x24842510  addiu       $a0, $a0, 0x2510 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9488));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8528u; }
        if (ctx->pc != 0x1A8528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8528u; }
        if (ctx->pc != 0x1A8528u) { return; }
    }
    ctx->pc = 0x1A8528u;
label_1a8528:
    // 0x1a8528: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1A8528u;
    {
        const bool branch_taken_0x1a8528 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A852Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8528u;
            // 0x1a852c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8528) {
            ctx->pc = 0x1A8590u;
            goto label_1a8590;
        }
    }
    ctx->pc = 0x1A8530u;
label_1a8530:
    // 0x1a8530: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a8530u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a8534: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x1a8534u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1a8538: 0x28420200  slti        $v0, $v0, 0x200
    ctx->pc = 0x1a8538u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)512) ? 1 : 0);
    // 0x1a853c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A853Cu;
    {
        const bool branch_taken_0x1a853c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A8540u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A853Cu;
            // 0x1a8540: 0x3c03002b  lui         $v1, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a853c) {
            ctx->pc = 0x1A854Cu;
            goto label_1a854c;
        }
    }
    ctx->pc = 0x1A8544u;
    // 0x1a8544: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1A8544u;
    {
        const bool branch_taken_0x1a8544 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A8548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8544u;
            // 0x1a8548: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8544) {
            ctx->pc = 0x1A8590u;
            goto label_1a8590;
        }
    }
    ctx->pc = 0x1A854Cu;
label_1a854c:
    // 0x1a854c: 0x24070018  addiu       $a3, $zero, 0x18
    ctx->pc = 0x1a854cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1a8550: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A8550u;
    {
        const bool branch_taken_0x1a8550 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A8554u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8550u;
            // 0x1a8554: 0x24630cc0  addiu       $v1, $v1, 0xCC0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3264));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8550) {
            ctx->pc = 0x1A8584u;
            goto label_1a8584;
        }
    }
    ctx->pc = 0x1A8558u;
label_1a8558:
    // 0x1a8558: 0xe43006  srlv        $a2, $a0, $a3
    ctx->pc = 0x1a8558u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 4), GPR_U32(ctx, 7) & 0x1F));
    // 0x1a855c: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a855cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a8560: 0x24e7fff8  addiu       $a3, $a3, -0x8
    ctx->pc = 0x1a8560u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967288));
    // 0x1a8564: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1a8564u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1a8568: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a8568u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a856c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a856cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8570: 0xa0460000  sb          $a2, 0x0($v0)
    ctx->pc = 0x1a8570u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x1a8574: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a8574u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a8578: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1a8578u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a857c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a857cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8580: 0xac220a60  sw          $v0, 0xA60($at)
    ctx->pc = 0x1a8580u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2656), GPR_U32(ctx, 2));
label_1a8584:
    // 0x1a8584: 0x1ca0fff4  bgtz        $a1, . + 4 + (-0xC << 2)
    ctx->pc = 0x1A8584u;
    {
        const bool branch_taken_0x1a8584 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x1A8588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8584u;
            // 0x1a8588: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8584) {
            ctx->pc = 0x1A8558u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a8558;
        }
    }
    ctx->pc = 0x1A858Cu;
    // 0x1a858c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a858cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a8590:
    // 0x1a8590: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a8590u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a8594: 0x3e00008  jr          $ra
    ctx->pc = 0x1A8594u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A8598u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8594u;
            // 0x1a8598: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A851Cu: goto label_1a851c;
            case 0x1A8528u: goto label_1a8528;
            case 0x1A8530u: goto label_1a8530;
            case 0x1A854Cu: goto label_1a854c;
            case 0x1A8558u: goto label_1a8558;
            case 0x1A8584u: goto label_1a8584;
            case 0x1A8590u: goto label_1a8590;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A859Cu;
    // 0x1a859c: 0x0  nop
    ctx->pc = 0x1a859cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
