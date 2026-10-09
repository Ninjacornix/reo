#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001373C8
// Address: 0x1373c8 - 0x137468
void sub_001373C8_0x1373c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001373C8_0x1373c8");
#endif

    switch (ctx->pc) {
        case 0x1373e4u: goto label_1373e4;
        case 0x137404u: goto label_137404;
        case 0x137434u: goto label_137434;
        case 0x13743cu: goto label_13743c;
        default: break;
    }

    ctx->pc = 0x1373c8u;

    // 0x1373c8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1373c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1373cc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1373ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1373d0: 0x3c110022  lui         $s1, 0x22
    ctx->pc = 0x1373d0u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)34 << 16));
    // 0x1373d4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1373d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1373d8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1373d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1373dc: 0xc0505c0  jal         func_141700
    ctx->pc = 0x1373DCu;
    SET_GPR_U32(ctx, 31, 0x1373E4u);
    ctx->pc = 0x1373E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1373DCu;
            // 0x1373e0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141700u;
    if (runtime->hasFunction(0x141700u)) {
        auto targetFn = runtime->lookupFunction(0x141700u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1373E4u; }
        if (ctx->pc != 0x1373E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141700_0x141700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1373E4u; }
        if (ctx->pc != 0x1373E4u) { return; }
    }
    ctx->pc = 0x1373E4u;
label_1373e4:
    // 0x1373e4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1373e4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1373e8: 0x2622bb88  addiu       $v0, $s1, -0x4478
    ctx->pc = 0x1373e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294949768));
    // 0x1373ec: 0x2484c468  addiu       $a0, $a0, -0x3B98
    ctx->pc = 0x1373ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952040));
    // 0x1373f0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1373f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1373f4: 0x12020006  beq         $s0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1373F4u;
    {
        const bool branch_taken_0x1373f4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x1373F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1373F4u;
            // 0x1373f8: 0x40302d  daddu       $a2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1373f4) {
            ctx->pc = 0x137410u;
            goto label_137410;
        }
    }
    ctx->pc = 0x1373FCu;
    // 0x1373fc: 0xc045a12  jal         func_116848
    ctx->pc = 0x1373FCu;
    SET_GPR_U32(ctx, 31, 0x137404u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137404u; }
        if (ctx->pc != 0x137404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137404u; }
        if (ctx->pc != 0x137404u) { return; }
    }
    ctx->pc = 0x137404u;
label_137404:
    // 0x137404: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x137404u;
    {
        const bool branch_taken_0x137404 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x137408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137404u;
            // 0x137408: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137404) {
            ctx->pc = 0x137458u;
            goto label_137458;
        }
    }
    ctx->pc = 0x13740Cu;
    // 0x13740c: 0x0  nop
    ctx->pc = 0x13740cu;
    // NOP
label_137410:
    // 0x137410: 0x82040002  lb          $a0, 0x2($s0)
    ctx->pc = 0x137410u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x137414: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x137414u;
    {
        const bool branch_taken_0x137414 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x137418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137414u;
            // 0x137418: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137414) {
            ctx->pc = 0x137434u;
            goto label_137434;
        }
    }
    ctx->pc = 0x13741Cu;
    // 0x13741c: 0x10820005  beq         $a0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x13741Cu;
    {
        const bool branch_taken_0x13741c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x137420u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13741Cu;
            // 0x137420: 0x24020009  addiu       $v0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13741c) {
            ctx->pc = 0x137434u;
            goto label_137434;
        }
    }
    ctx->pc = 0x137424u;
    // 0x137424: 0x10820003  beq         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x137424u;
    {
        const bool branch_taken_0x137424 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x137428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137424u;
            // 0x137428: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137424) {
            ctx->pc = 0x137434u;
            goto label_137434;
        }
    }
    ctx->pc = 0x13742Cu;
    // 0x13742c: 0xc045a12  jal         func_116848
    ctx->pc = 0x13742Cu;
    SET_GPR_U32(ctx, 31, 0x137434u);
    ctx->pc = 0x137430u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13742Cu;
            // 0x137430: 0x2484c4a8  addiu       $a0, $a0, -0x3B58 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137434u; }
        if (ctx->pc != 0x137434u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137434u; }
        if (ctx->pc != 0x137434u) { return; }
    }
    ctx->pc = 0x137434u;
label_137434:
    // 0x137434: 0xc04dcc4  jal         func_137310
    ctx->pc = 0x137434u;
    SET_GPR_U32(ctx, 31, 0x13743Cu);
    ctx->pc = 0x137310u;
    if (runtime->hasFunction(0x137310u)) {
        auto targetFn = runtime->lookupFunction(0x137310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13743Cu; }
        if (ctx->pc != 0x13743Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137310_0x137310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13743Cu; }
        if (ctx->pc != 0x13743Cu) { return; }
    }
    ctx->pc = 0x13743Cu;
label_13743c:
    // 0x13743c: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13743cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x137440: 0xa220bb88  sb          $zero, -0x4478($s1)
    ctx->pc = 0x137440u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 4294949768), (uint8_t)GPR_U32(ctx, 0));
    // 0x137444: 0x2463bbec  addiu       $v1, $v1, -0x4414
    ctx->pc = 0x137444u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949868));
    // 0x137448: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x137448u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13744c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x13744cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x137450: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x137450u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x137454: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x137454u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_137458:
    // 0x137458: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x137458u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13745c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13745cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x137460: 0x80505de  j           func_141778
    ctx->pc = 0x137460u;
    ctx->pc = 0x137464u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137460u;
            // 0x137464: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141778u;
    if (runtime->hasFunction(0x141778u)) {
        auto targetFn = runtime->lookupFunction(0x141778u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141778_0x141778(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x137468u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
