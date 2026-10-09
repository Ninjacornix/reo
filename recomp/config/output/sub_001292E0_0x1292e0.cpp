#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001292E0
// Address: 0x1292e0 - 0x129350
void sub_001292E0_0x1292e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001292E0_0x1292e0");
#endif

    switch (ctx->pc) {
        case 0x129328u: goto label_129328;
        case 0x129340u: goto label_129340;
        default: break;
    }

    ctx->pc = 0x1292e0u;

    // 0x1292e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1292e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1292e4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1292e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1292e8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1292e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1292ec: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1292ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1292f0: 0x8e050008  lw          $a1, 0x8($s0)
    ctx->pc = 0x1292f0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1292f4: 0x50a00013  beql        $a1, $zero, . + 4 + (0x13 << 2)
    ctx->pc = 0x1292F4u;
    {
        const bool branch_taken_0x1292f4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x1292f4) {
            ctx->pc = 0x1292F8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1292F4u;
            // 0x1292f8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129344u;
            goto label_129344;
        }
    }
    ctx->pc = 0x1292FCu;
    // 0x1292fc: 0x82020002  lb          $v0, 0x2($s0)
    ctx->pc = 0x1292fcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x129300: 0x54400010  bnel        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x129300u;
    {
        const bool branch_taken_0x129300 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x129300) {
            ctx->pc = 0x129304u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129300u;
            // 0x129304: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129344u;
            goto label_129344;
        }
    }
    ctx->pc = 0x129308u;
    // 0x129308: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x129308u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12930c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x12930cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x129310: 0x8c43d100  lw          $v1, -0x2F00($v0)
    ctx->pc = 0x129310u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294955264)));
    // 0x129314: 0x54640006  bnel        $v1, $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x129314u;
    {
        const bool branch_taken_0x129314 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x129314) {
            ctx->pc = 0x129318u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129314u;
            // 0x129318: 0x8ca30000  lw          $v1, 0x0($a1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129330u;
            goto label_129330;
        }
    }
    ctx->pc = 0x12931Cu;
    // 0x12931c: 0x8e050028  lw          $a1, 0x28($s0)
    ctx->pc = 0x12931cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x129320: 0xc04a0ca  jal         func_128328
    ctx->pc = 0x129320u;
    SET_GPR_U32(ctx, 31, 0x129328u);
    ctx->pc = 0x129324u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129320u;
            // 0x129324: 0x8e040024  lw          $a0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128328u;
    if (runtime->hasFunction(0x128328u)) {
        auto targetFn = runtime->lookupFunction(0x128328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129328u; }
        if (ctx->pc != 0x129328u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128328_0x128328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129328u; }
        if (ctx->pc != 0x129328u) { return; }
    }
    ctx->pc = 0x129328u;
label_129328:
    // 0x129328: 0x8e050008  lw          $a1, 0x8($s0)
    ctx->pc = 0x129328u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x12932c: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x12932cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
label_129330:
    // 0x129330: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x129330u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x129334: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x129334u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x129338: 0x40f809  jalr        $v0
    ctx->pc = 0x129338u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x129340u);
        ctx->pc = 0x12933Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129338u;
            // 0x12933c: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x129340u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129328u: goto label_129328;
            case 0x129330u: goto label_129330;
            case 0x129340u: goto label_129340;
            case 0x129344u: goto label_129344;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x129340u; }
            if (ctx->pc != 0x129340u) { return; }
        }
        }
    }
    ctx->pc = 0x129340u;
label_129340:
    // 0x129340: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x129340u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_129344:
    // 0x129344: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x129344u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x129348: 0x3e00008  jr          $ra
    ctx->pc = 0x129348u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12934Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129348u;
            // 0x12934c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129328u: goto label_129328;
            case 0x129330u: goto label_129330;
            case 0x129340u: goto label_129340;
            case 0x129344u: goto label_129344;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129350u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
