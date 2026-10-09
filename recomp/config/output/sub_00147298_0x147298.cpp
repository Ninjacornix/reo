#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00147298
// Address: 0x147298 - 0x147508
void sub_00147298_0x147298(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00147298_0x147298");
#endif

    switch (ctx->pc) {
        case 0x1472c8u: goto label_1472c8;
        case 0x1472ecu: goto label_1472ec;
        case 0x147330u: goto label_147330;
        case 0x147340u: goto label_147340;
        case 0x147354u: goto label_147354;
        case 0x147360u: goto label_147360;
        case 0x147388u: goto label_147388;
        default: break;
    }

    ctx->pc = 0x147298u;

    // 0x147298: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x147298u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x14729c: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x14729cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1472a0: 0xffb30050  sd          $s3, 0x50($sp)
    ctx->pc = 0x1472a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x1472a4: 0x34632010  ori         $v1, $v1, 0x2010
    ctx->pc = 0x1472a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8208);
    // 0x1472a8: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x1472a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x1472ac: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x1472acu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1472b0: 0xffb10030  sd          $s1, 0x30($sp)
    ctx->pc = 0x1472b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x1472b4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1472b4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1472b8: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x1472b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x1472bc: 0x138980  sll         $s1, $s3, 6
    ctx->pc = 0x1472bcu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 19), 6));
    // 0x1472c0: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1472c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1472c4: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1472c4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_1472c8:
    // 0x1472c8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1472c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1472cc: 0x0  nop
    ctx->pc = 0x1472ccu;
    // NOP
    // 0x1472d0: 0x0  nop
    ctx->pc = 0x1472d0u;
    // NOP
    // 0x1472d4: 0x0  nop
    ctx->pc = 0x1472d4u;
    // NOP
    // 0x1472d8: 0x0  nop
    ctx->pc = 0x1472d8u;
    // NOP
    // 0x1472dc: 0x440fffa  bltz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1472DCu;
    {
        const bool branch_taken_0x1472dc = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1472dc) {
            ctx->pc = 0x1472C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1472c8;
        }
    }
    ctx->pc = 0x1472E4u;
    // 0x1472e4: 0xc047598  jal         func_11D660
    ctx->pc = 0x1472E4u;
    SET_GPR_U32(ctx, 31, 0x1472ECu);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1472ECu; }
        if (ctx->pc != 0x1472ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1472ECu; }
        if (ctx->pc != 0x1472ECu) { return; }
    }
    ctx->pc = 0x1472ECu;
label_1472ec:
    // 0x1472ec: 0x3c030fff  lui         $v1, 0xFFF
    ctx->pc = 0x1472ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4095 << 16));
    // 0x1472f0: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x1472f0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x1472f4: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x1472f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x1472f8: 0x34a5b010  ori         $a1, $a1, 0xB010
    ctx->pc = 0x1472f8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)45072);
    // 0x1472fc: 0x2031824  and         $v1, $s0, $v1
    ctx->pc = 0x1472fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & GPR_U64(ctx, 3));
    // 0x147300: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x147300u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x147304: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x147304u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x147308: 0x3484b020  ori         $a0, $a0, 0xB020
    ctx->pc = 0x147308u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)45088);
    // 0x14730c: 0xac910000  sw          $s1, 0x0($a0)
    ctx->pc = 0x14730cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 17)); // MMIO: 0x10000000
    // 0x147310: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x147310u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x147314: 0x3463b000  ori         $v1, $v1, 0xB000
    ctx->pc = 0x147314u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)45056);
    // 0x147318: 0x24040100  addiu       $a0, $zero, 0x100
    ctx->pc = 0x147318u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x14731c: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x14731cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x147320: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x147320u;
    {
        const bool branch_taken_0x147320 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x147320) {
            ctx->pc = 0x147324u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x147320u;
            // 0x147324: 0x3c057000  lui         $a1, 0x7000 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x147334u;
            goto label_147334;
        }
    }
    ctx->pc = 0x147328u;
    // 0x147328: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x147328u;
    SET_GPR_U32(ctx, 31, 0x147330u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147330u; }
        if (ctx->pc != 0x147330u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147330u; }
        if (ctx->pc != 0x147330u) { return; }
    }
    ctx->pc = 0x147330u;
label_147330:
    // 0x147330: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x147330u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
label_147334:
    // 0x147334: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x147334u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147338: 0xc05148a  jal         func_145228
    ctx->pc = 0x147338u;
    SET_GPR_U32(ctx, 31, 0x147340u);
    ctx->pc = 0x14733Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x147338u;
            // 0x14733c: 0x2652825  or          $a1, $s3, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 19) | GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145228u;
    if (runtime->hasFunction(0x145228u)) {
        auto targetFn = runtime->lookupFunction(0x145228u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147340u; }
        if (ctx->pc != 0x147340u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145228_0x145228(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147340u; }
        if (ctx->pc != 0x147340u) { return; }
    }
    ctx->pc = 0x147340u;
label_147340:
    // 0x147340: 0x8e440870  lw          $a0, 0x870($s2)
    ctx->pc = 0x147340u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 2160)));
    // 0x147344: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x147344u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x147348: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x147348u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x14734c: 0xc051fda  jal         func_147F68
    ctx->pc = 0x14734Cu;
    SET_GPR_U32(ctx, 31, 0x147354u);
    ctx->pc = 0x147350u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14734Cu;
            // 0x147350: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147F68u;
    if (runtime->hasFunction(0x147F68u)) {
        auto targetFn = runtime->lookupFunction(0x147F68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147354u; }
        if (ctx->pc != 0x147354u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F68_0x147f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147354u; }
        if (ctx->pc != 0x147354u) { return; }
    }
    ctx->pc = 0x147354u;
label_147354:
    // 0x147354: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x147354u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x147358: 0x3463b000  ori         $v1, $v1, 0xB000
    ctx->pc = 0x147358u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)45056);
    // 0x14735c: 0x0  nop
    ctx->pc = 0x14735cu;
    // NOP
label_147360:
    // 0x147360: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x147360u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x147364: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x147364u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x147368: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x147368u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x14736c: 0x0  nop
    ctx->pc = 0x14736cu;
    // NOP
    // 0x147370: 0x0  nop
    ctx->pc = 0x147370u;
    // NOP
    // 0x147374: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x147374u;
    {
        const bool branch_taken_0x147374 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x147374) {
            ctx->pc = 0x147360u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_147360;
        }
    }
    ctx->pc = 0x14737Cu;
    // 0x14737c: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x14737cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x147380: 0x34632010  ori         $v1, $v1, 0x2010
    ctx->pc = 0x147380u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8208);
    // 0x147384: 0x0  nop
    ctx->pc = 0x147384u;
    // NOP
label_147388:
    // 0x147388: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x147388u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x14738c: 0x0  nop
    ctx->pc = 0x14738cu;
    // NOP
    // 0x147390: 0x0  nop
    ctx->pc = 0x147390u;
    // NOP
    // 0x147394: 0x0  nop
    ctx->pc = 0x147394u;
    // NOP
    // 0x147398: 0x0  nop
    ctx->pc = 0x147398u;
    // NOP
    // 0x14739c: 0x440fffa  bltz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x14739Cu;
    {
        const bool branch_taken_0x14739c = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x14739c) {
            ctx->pc = 0x147388u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_147388;
        }
    }
    ctx->pc = 0x1473A4u;
    // 0x1473a4: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1473a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1473a8: 0xdfb30050  ld          $s3, 0x50($sp)
    ctx->pc = 0x1473a8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1473ac: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x1473acu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1473b0: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x1473b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1473b4: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x1473b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1473b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1473B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1473BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1473B8u;
            // 0x1473bc: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1472C8u: goto label_1472c8;
            case 0x1472ECu: goto label_1472ec;
            case 0x147330u: goto label_147330;
            case 0x147334u: goto label_147334;
            case 0x147340u: goto label_147340;
            case 0x147354u: goto label_147354;
            case 0x147360u: goto label_147360;
            case 0x147388u: goto label_147388;
            case 0x14740Cu: goto label_14740c;
            case 0x147420u: goto label_147420;
            case 0x147494u: goto label_147494;
            case 0x1474F8u: goto label_1474f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1473C0u;
    // 0x1473c0: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1473c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1473c4: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x1473c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1473c8: 0x3442e010  ori         $v0, $v0, 0xE010
    ctx->pc = 0x1473c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)57360);
    // 0x1473cc: 0xa0482d  daddu       $t1, $a1, $zero
    ctx->pc = 0x1473ccu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1473d0: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1473d0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x1473d4: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x1473d4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x1473d8: 0x3484b020  ori         $a0, $a0, 0xB020
    ctx->pc = 0x1473d8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)45088);
    // 0x1473dc: 0x8d220000  lw          $v0, 0x0($t1)
    ctx->pc = 0x1473dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1473e0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1473e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1473e4: 0xad220000  sw          $v0, 0x0($t1)
    ctx->pc = 0x1473e4u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 0), GPR_U32(ctx, 2));
    // 0x1473e8: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1473e8u;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0))); // MMIO: 0x10000000
    // 0x1473ec: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1473ECu;
    {
        const bool branch_taken_0x1473ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1473F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1473ECu;
            // 0x1473f0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1473ec) {
            ctx->pc = 0x14740Cu;
            goto label_14740c;
        }
    }
    ctx->pc = 0x1473F4u;
    // 0x1473f4: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1473f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1473f8: 0x3442b000  ori         $v0, $v0, 0xB000
    ctx->pc = 0x1473f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)45056);
    // 0x1473fc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1473fcu;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x147400: 0x30630100  andi        $v1, $v1, 0x100
    ctx->pc = 0x147400u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)256);
    // 0x147404: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x147404u;
    {
        const bool branch_taken_0x147404 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x147408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147404u;
            // 0x147408: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x147404) {
            ctx->pc = 0x147420u;
            goto label_147420;
        }
    }
    ctx->pc = 0x14740Cu;
label_14740c:
    // 0x14740c: 0xad220004  sw          $v0, 0x4($t1)
    ctx->pc = 0x14740cu;
    WRITE32(ADD32(GPR_U32(ctx, 9), 4), GPR_U32(ctx, 2));
    // 0x147410: 0xf  sync
    ctx->pc = 0x147410u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x147414: 0x42000038  ei
    ctx->pc = 0x147414u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x147418: 0x3e00008  jr          $ra
    ctx->pc = 0x147418u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14741Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147418u;
            // 0x14741c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1472C8u: goto label_1472c8;
            case 0x1472ECu: goto label_1472ec;
            case 0x147330u: goto label_147330;
            case 0x147334u: goto label_147334;
            case 0x147340u: goto label_147340;
            case 0x147354u: goto label_147354;
            case 0x147360u: goto label_147360;
            case 0x147388u: goto label_147388;
            case 0x14740Cu: goto label_14740c;
            case 0x147420u: goto label_147420;
            case 0x147494u: goto label_147494;
            case 0x1474F8u: goto label_1474f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x147420u;
label_147420:
    // 0x147420: 0x8d230010  lw          $v1, 0x10($t1)
    ctx->pc = 0x147420u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x147424: 0x8d220000  lw          $v0, 0x0($t1)
    ctx->pc = 0x147424u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x147428: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x147428u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x14742c: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x14742cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x147430: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x147430u;
    {
        const bool branch_taken_0x147430 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x147434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147430u;
            // 0x147434: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x147430) {
            ctx->pc = 0x147494u;
            goto label_147494;
        }
    }
    ctx->pc = 0x147438u;
    // 0x147438: 0x8d23000c  lw          $v1, 0xC($t1)
    ctx->pc = 0x147438u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 12)));
    // 0x14743c: 0x3442b010  ori         $v0, $v0, 0xB010
    ctx->pc = 0x14743cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)45072);
    // 0x147440: 0x3404ffc0  ori         $a0, $zero, 0xFFC0
    ctx->pc = 0x147440u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x147444: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x147444u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x147448: 0x24050100  addiu       $a1, $zero, 0x100
    ctx->pc = 0x147448u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x14744c: 0x3c011001  lui         $at, 0x1001
    ctx->pc = 0x14744cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4097 << 16));
    // 0x147450: 0xac24b020  sw          $a0, -0x4FE0($at)
    ctx->pc = 0x147450u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294946848), GPR_U32(ctx, 4)); // MMIO: 0x1000b020
    // 0x147454: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x147454u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x147458: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x147458u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x14745c: 0x3c011001  lui         $at, 0x1001
    ctx->pc = 0x14745cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4097 << 16));
    // 0x147460: 0xac25b000  sw          $a1, -0x5000($at)
    ctx->pc = 0x147460u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294946816), GPR_U32(ctx, 5)); // MMIO: 0x1000b000
    // 0x147464: 0x34632000  ori         $v1, $v1, 0x2000
    ctx->pc = 0x147464u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8192);
    // 0x147468: 0x344203ff  ori         $v0, $v0, 0x3FF
    ctx->pc = 0x147468u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1023);
    // 0x14746c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x14746cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x147470: 0x3c04000f  lui         $a0, 0xF
    ctx->pc = 0x147470u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)15 << 16));
    // 0x147474: 0x3484fc00  ori         $a0, $a0, 0xFC00
    ctx->pc = 0x147474u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)64512);
    // 0x147478: 0x3c030fff  lui         $v1, 0xFFF
    ctx->pc = 0x147478u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4095 << 16));
    // 0x14747c: 0x8d22000c  lw          $v0, 0xC($t1)
    ctx->pc = 0x14747cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 12)));
    // 0x147480: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x147480u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x147484: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x147484u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x147488: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x147488u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x14748c: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x14748Cu;
    {
        const bool branch_taken_0x14748c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x147490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14748Cu;
            // 0x147490: 0xad22000c  sw          $v0, 0xC($t1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 9), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14748c) {
            ctx->pc = 0x1474F8u;
            goto label_1474f8;
        }
    }
    ctx->pc = 0x147494u;
label_147494:
    // 0x147494: 0x8d220000  lw          $v0, 0x0($t1)
    ctx->pc = 0x147494u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x147498: 0x14430017  bne         $v0, $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x147498u;
    {
        const bool branch_taken_0x147498 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x14749Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147498u;
            // 0x14749c: 0x24080100  addiu       $t0, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
        if (branch_taken_0x147498) {
            ctx->pc = 0x1474F8u;
            goto label_1474f8;
        }
    }
    ctx->pc = 0x1474A0u;
    // 0x1474a0: 0x8d250000  lw          $a1, 0x0($t1)
    ctx->pc = 0x1474a0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1474a4: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x1474a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x1474a8: 0x8d230008  lw          $v1, 0x8($t1)
    ctx->pc = 0x1474a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x1474ac: 0x3484b010  ori         $a0, $a0, 0xB010
    ctx->pc = 0x1474acu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)45072);
    // 0x1474b0: 0x51280  sll         $v0, $a1, 10
    ctx->pc = 0x1474b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 10));
    // 0x1474b4: 0x8d26000c  lw          $a2, 0xC($t1)
    ctx->pc = 0x1474b4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 12)));
    // 0x1474b8: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x1474b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1474bc: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x1474bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1474c0: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x1474c0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x1474c4: 0xad230008  sw          $v1, 0x8($t1)
    ctx->pc = 0x1474c4u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 8), GPR_U32(ctx, 3));
    // 0x1474c8: 0x3c077000  lui         $a3, 0x7000
    ctx->pc = 0x1474c8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)28672 << 16));
    // 0x1474cc: 0xac860000  sw          $a2, 0x0($a0)
    ctx->pc = 0x1474ccu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 6));
    // 0x1474d0: 0x34a52000  ori         $a1, $a1, 0x2000
    ctx->pc = 0x1474d0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)8192);
    // 0x1474d4: 0x8d220008  lw          $v0, 0x8($t1)
    ctx->pc = 0x1474d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x1474d8: 0x21180  sll         $v0, $v0, 6
    ctx->pc = 0x1474d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x1474dc: 0x3c011001  lui         $at, 0x1001
    ctx->pc = 0x1474dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4097 << 16));
    // 0x1474e0: 0xac22b020  sw          $v0, -0x4FE0($at)
    ctx->pc = 0x1474e0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294946848), GPR_U32(ctx, 2)); // MMIO: 0x1000b020
    // 0x1474e4: 0x3c011001  lui         $at, 0x1001
    ctx->pc = 0x1474e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4097 << 16));
    // 0x1474e8: 0xac28b000  sw          $t0, -0x5000($at)
    ctx->pc = 0x1474e8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294946816), GPR_U32(ctx, 8)); // MMIO: 0x1000b000
    // 0x1474ec: 0x8d220008  lw          $v0, 0x8($t1)
    ctx->pc = 0x1474ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x1474f0: 0x471025  or          $v0, $v0, $a3
    ctx->pc = 0x1474f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 7));
    // 0x1474f4: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1474f4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
label_1474f8:
    // 0x1474f8: 0xf  sync
    ctx->pc = 0x1474f8u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x1474fc: 0x42000038  ei
    ctx->pc = 0x1474fcu;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x147500: 0x3e00008  jr          $ra
    ctx->pc = 0x147500u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147504u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147500u;
            // 0x147504: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1472C8u: goto label_1472c8;
            case 0x1472ECu: goto label_1472ec;
            case 0x147330u: goto label_147330;
            case 0x147334u: goto label_147334;
            case 0x147340u: goto label_147340;
            case 0x147354u: goto label_147354;
            case 0x147360u: goto label_147360;
            case 0x147388u: goto label_147388;
            case 0x14740Cu: goto label_14740c;
            case 0x147420u: goto label_147420;
            case 0x147494u: goto label_147494;
            case 0x1474F8u: goto label_1474f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x147508u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
