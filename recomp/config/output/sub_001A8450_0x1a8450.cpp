#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A8450
// Address: 0x1a8450 - 0x1a8500
void sub_001A8450_0x1a8450(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A8450_0x1a8450");
#endif

    switch (ctx->pc) {
        case 0x1a846cu: goto label_1a846c;
        case 0x1a84a0u: goto label_1a84a0;
        default: break;
    }

    ctx->pc = 0x1a8450u;

    // 0x1a8450: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a8450u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a8454: 0x28a10005  slti        $at, $a1, 0x5
    ctx->pc = 0x1a8454u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)5) ? 1 : 0);
    // 0x1a8458: 0x14200006  bnez        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A8458u;
    {
        const bool branch_taken_0x1a8458 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A845Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8458u;
            // 0x1a845c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8458) {
            ctx->pc = 0x1A8474u;
            goto label_1a8474;
        }
    }
    ctx->pc = 0x1A8460u;
    // 0x1a8460: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a8460u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a8464: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A8464u;
    SET_GPR_U32(ctx, 31, 0x1A846Cu);
    ctx->pc = 0x1A8468u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8464u;
            // 0x1a8468: 0x248424e0  addiu       $a0, $a0, 0x24E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9440));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A846Cu; }
        if (ctx->pc != 0x1A846Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A846Cu; }
        if (ctx->pc != 0x1A846Cu) { return; }
    }
    ctx->pc = 0x1A846Cu;
label_1a846c:
    // 0x1a846c: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1A846Cu;
    {
        const bool branch_taken_0x1a846c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A8470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A846Cu;
            // 0x1a8470: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a846c) {
            ctx->pc = 0x1A84F4u;
            goto label_1a84f4;
        }
    }
    ctx->pc = 0x1A8474u;
label_1a8474:
    // 0x1a8474: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8474u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8478: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a8478u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a847c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1a847cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1a8480: 0x28420200  slti        $v0, $v0, 0x200
    ctx->pc = 0x1a8480u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)512) ? 1 : 0);
    // 0x1a8484: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A8484u;
    {
        const bool branch_taken_0x1a8484 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A8488u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8484u;
            // 0x1a8488: 0x3c03002b  lui         $v1, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8484) {
            ctx->pc = 0x1A8494u;
            goto label_1a8494;
        }
    }
    ctx->pc = 0x1A848Cu;
    // 0x1a848c: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1A848Cu;
    {
        const bool branch_taken_0x1a848c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A8490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A848Cu;
            // 0x1a8490: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a848c) {
            ctx->pc = 0x1A84F4u;
            goto label_1a84f4;
        }
    }
    ctx->pc = 0x1A8494u;
label_1a8494:
    // 0x1a8494: 0x24070018  addiu       $a3, $zero, 0x18
    ctx->pc = 0x1a8494u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1a8498: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A8498u;
    {
        const bool branch_taken_0x1a8498 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A849Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8498u;
            // 0x1a849c: 0x24630cc0  addiu       $v1, $v1, 0xCC0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3264));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8498) {
            ctx->pc = 0x1A84CCu;
            goto label_1a84cc;
        }
    }
    ctx->pc = 0x1A84A0u;
label_1a84a0:
    // 0x1a84a0: 0xe43006  srlv        $a2, $a0, $a3
    ctx->pc = 0x1a84a0u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 4), GPR_U32(ctx, 7) & 0x1F));
    // 0x1a84a4: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a84a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a84a8: 0x24e7fff8  addiu       $a3, $a3, -0x8
    ctx->pc = 0x1a84a8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967288));
    // 0x1a84ac: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1a84acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1a84b0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a84b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a84b4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a84b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a84b8: 0xa0460000  sb          $a2, 0x0($v0)
    ctx->pc = 0x1a84b8u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x1a84bc: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a84bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a84c0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1a84c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a84c4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a84c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a84c8: 0xac220a60  sw          $v0, 0xA60($at)
    ctx->pc = 0x1a84c8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2656), GPR_U32(ctx, 2));
label_1a84cc:
    // 0x1a84cc: 0x1ca0fff4  bgtz        $a1, . + 4 + (-0xC << 2)
    ctx->pc = 0x1A84CCu;
    {
        const bool branch_taken_0x1a84cc = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x1A84D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A84CCu;
            // 0x1a84d0: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a84cc) {
            ctx->pc = 0x1A84A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a84a0;
        }
    }
    ctx->pc = 0x1A84D4u;
    // 0x1a84d4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a84d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a84d8: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a84d8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a84dc: 0x8c240a60  lw          $a0, 0xA60($at)
    ctx->pc = 0x1a84dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a84e0: 0x24630cc0  addiu       $v1, $v1, 0xCC0
    ctx->pc = 0x1a84e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3264));
    // 0x1a84e4: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1a84e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1a84e8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a84e8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a84ec: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1a84ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a84f0: 0xa0650000  sb          $a1, 0x0($v1)
    ctx->pc = 0x1a84f0u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
label_1a84f4:
    // 0x1a84f4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a84f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a84f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1A84F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A84FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A84F8u;
            // 0x1a84fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A846Cu: goto label_1a846c;
            case 0x1A8474u: goto label_1a8474;
            case 0x1A8494u: goto label_1a8494;
            case 0x1A84A0u: goto label_1a84a0;
            case 0x1A84CCu: goto label_1a84cc;
            case 0x1A84F4u: goto label_1a84f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A8500u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
