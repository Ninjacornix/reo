#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115568
// Address: 0x115568 - 0x1155e4
void sub_00115568_0x115568(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115568_0x115568");
#endif

    switch (ctx->pc) {
        case 0x1155d0u: goto label_1155d0;
        default: break;
    }

    ctx->pc = 0x115568u;

    // 0x115568: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x115568u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11556c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11556cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x115570: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x115570u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115574: 0x2e020080  sltiu       $v0, $s0, 0x80
    ctx->pc = 0x115574u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x115578: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x115578u;
    {
        const bool branch_taken_0x115578 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11557Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115578u;
            // 0x11557c: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115578) {
            ctx->pc = 0x115590u;
            goto label_115590;
        }
    }
    ctx->pc = 0x115580u;
    // 0x115580: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x115580u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x115584: 0x8c439d38  lw          $v1, -0x62C8($v0)
    ctx->pc = 0x115584u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942008)));
    // 0x115588: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x115588u;
    {
        const bool branch_taken_0x115588 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x11558Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115588u;
            // 0x11558c: 0x3c030026  lui         $v1, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115588) {
            ctx->pc = 0x115598u;
            goto label_115598;
        }
    }
    ctx->pc = 0x115590u;
label_115590:
    // 0x115590: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x115590u;
    {
        const bool branch_taken_0x115590 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x115594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115590u;
            // 0x115594: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115590) {
            ctx->pc = 0x1155D4u;
            goto label_1155d4;
        }
    }
    ctx->pc = 0x115598u;
label_115598:
    // 0x115598: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x115598u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x11559c: 0x2463a638  addiu       $v1, $v1, -0x59C8
    ctx->pc = 0x11559cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294944312));
    // 0x1155a0: 0x8ca4a630  lw          $a0, -0x59D0($a1)
    ctx->pc = 0x1155a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4294944304)));
    // 0x1155a4: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x1155a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1155a8: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1155a8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1155ac: 0x304201ff  andi        $v0, $v0, 0x1FF
    ctx->pc = 0x1155acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)511);
    // 0x1155b0: 0x23040  sll         $a2, $v0, 1
    ctx->pc = 0x1155b0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1155b4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1155b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1155b8: 0x662821  addu        $a1, $v1, $a2
    ctx->pc = 0x1155b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1155bc: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x1155bcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1155c0: 0xa0a70008  sb          $a3, 0x8($a1)
    ctx->pc = 0x1155c0u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 8), (uint8_t)GPR_U32(ctx, 7));
    // 0x1155c4: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x1155c4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1155c8: 0xc045194  jal         func_114650
    ctx->pc = 0x1155C8u;
    SET_GPR_U32(ctx, 31, 0x1155D0u);
    ctx->pc = 0x1155CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1155C8u;
            // 0x1155cc: 0xa0700009  sb          $s0, 0x9($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 9), (uint8_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1155D0u; }
        if (ctx->pc != 0x1155D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1155D0u; }
        if (ctx->pc != 0x1155D0u) { return; }
    }
    ctx->pc = 0x1155D0u;
label_1155d0:
    // 0x1155d0: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1155d0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1155d4:
    // 0x1155d4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1155d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1155d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1155d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1155dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1155DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1155E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1155DCu;
            // 0x1155e0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115590u: goto label_115590;
            case 0x115598u: goto label_115598;
            case 0x1155D0u: goto label_1155d0;
            case 0x1155D4u: goto label_1155d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1155E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
