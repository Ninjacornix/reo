#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00183670
// Address: 0x183670 - 0x183fc8
void sub_00183670_0x183670(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00183670_0x183670");
#endif

    switch (ctx->pc) {
        case 0x1836c8u: goto label_1836c8;
        case 0x183748u: goto label_183748;
        case 0x183758u: goto label_183758;
        case 0x183770u: goto label_183770;
        case 0x183780u: goto label_183780;
        case 0x1837acu: goto label_1837ac;
        case 0x1837c4u: goto label_1837c4;
        case 0x183810u: goto label_183810;
        case 0x1838d0u: goto label_1838d0;
        case 0x1838e4u: goto label_1838e4;
        case 0x1838f0u: goto label_1838f0;
        case 0x183904u: goto label_183904;
        case 0x183990u: goto label_183990;
        case 0x1839a0u: goto label_1839a0;
        case 0x1839acu: goto label_1839ac;
        case 0x1839f8u: goto label_1839f8;
        case 0x183a30u: goto label_183a30;
        case 0x183a88u: goto label_183a88;
        case 0x183a94u: goto label_183a94;
        case 0x183abcu: goto label_183abc;
        case 0x183b08u: goto label_183b08;
        case 0x183b20u: goto label_183b20;
        case 0x183bb8u: goto label_183bb8;
        case 0x183bd4u: goto label_183bd4;
        case 0x183bf4u: goto label_183bf4;
        case 0x183c20u: goto label_183c20;
        case 0x183c7cu: goto label_183c7c;
        case 0x183ca0u: goto label_183ca0;
        case 0x183cc4u: goto label_183cc4;
        case 0x183cd4u: goto label_183cd4;
        case 0x183df8u: goto label_183df8;
        case 0x183f10u: goto label_183f10;
        case 0x183f28u: goto label_183f28;
        case 0x183f3cu: goto label_183f3c;
        case 0x183f4cu: goto label_183f4c;
        case 0x183f5cu: goto label_183f5c;
        default: break;
    }

    ctx->pc = 0x183670u;

    // 0x183670: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x183670u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x183674: 0xffb70068  sd          $s7, 0x68($sp)
    ctx->pc = 0x183674u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 23));
    // 0x183678: 0x80b82d  daddu       $s7, $a0, $zero
    ctx->pc = 0x183678u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18367c: 0x171040  sll         $v0, $s7, 1
    ctx->pc = 0x18367cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 23), 1));
    // 0x183680: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x183680u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x183684: 0x571021  addu        $v0, $v0, $s7
    ctx->pc = 0x183684u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 23)));
    // 0x183688: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x183688u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x18368c: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x18368cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x183690: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x183690u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x183694: 0x571021  addu        $v0, $v0, $s7
    ctx->pc = 0x183694u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 23)));
    // 0x183698: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x183698u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x18369c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x18369cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1836a0: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x1836a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x1836a4: 0xffb50058  sd          $s5, 0x58($sp)
    ctx->pc = 0x1836a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 21));
    // 0x1836a8: 0x3c110023  lui         $s1, 0x23
    ctx->pc = 0x1836a8u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
    // 0x1836ac: 0x2631fa18  addiu       $s1, $s1, -0x5E8
    ctx->pc = 0x1836acu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294965784));
    // 0x1836b0: 0x2228821  addu        $s1, $s1, $v0
    ctx->pc = 0x1836b0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1836b4: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x1836b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x1836b8: 0xffbe0070  sd          $fp, 0x70($sp)
    ctx->pc = 0x1836b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 30));
    // 0x1836bc: 0xffbf0078  sd          $ra, 0x78($sp)
    ctx->pc = 0x1836bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 31));
    // 0x1836c0: 0xc062210  jal         func_188840
    ctx->pc = 0x1836C0u;
    SET_GPR_U32(ctx, 31, 0x1836C8u);
    ctx->pc = 0x188840u;
    if (runtime->hasFunction(0x188840u)) {
        auto targetFn = runtime->lookupFunction(0x188840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1836C8u; }
        if (ctx->pc != 0x1836C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188840_0x188840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1836C8u; }
        if (ctx->pc != 0x1836C8u) { return; }
    }
    ctx->pc = 0x1836C8u;
label_1836c8:
    // 0x1836c8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1836C8u;
    {
        const bool branch_taken_0x1836c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1836CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1836C8u;
            // 0x1836cc: 0x24060898  addiu       $a2, $zero, 0x898 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1836c8) {
            ctx->pc = 0x1836E0u;
            goto label_1836e0;
        }
    }
    ctx->pc = 0x1836D0u;
    // 0x1836d0: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1836d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1836d4: 0x10000230  b           . + 4 + (0x230 << 2)
    ctx->pc = 0x1836D4u;
    {
        const bool branch_taken_0x1836d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1836D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1836D4u;
            // 0x1836d8: 0x34420013  ori         $v0, $v0, 0x13 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)19);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1836d4) {
            ctx->pc = 0x183F98u;
            goto label_183f98;
        }
    }
    ctx->pc = 0x1836DCu;
    // 0x1836dc: 0x0  nop
    ctx->pc = 0x1836dcu;
    // NOP
label_1836e0:
    // 0x1836e0: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x1836e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
    // 0x1836e4: 0x2e63018  mult        $a2, $s7, $a2
    ctx->pc = 0x1836e4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 23) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 6, (int32_t)result); }
    // 0x1836e8: 0x24475b48  addiu       $a3, $v0, 0x5B48
    ctx->pc = 0x1836e8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 23368));
    // 0x1836ec: 0x24e90004  addiu       $t1, $a3, 0x4
    ctx->pc = 0x1836ecu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x1836f0: 0x24ec0808  addiu       $t4, $a3, 0x808
    ctx->pc = 0x1836f0u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), 2056));
    // 0x1836f4: 0x240bffff  addiu       $t3, $zero, -0x1
    ctx->pc = 0x1836f4u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1836f8: 0x3c0d0024  lui         $t5, 0x24
    ctx->pc = 0x1836f8u;
    SET_GPR_S32(ctx, 13, (int32_t)((uint32_t)36 << 16));
    // 0x1836fc: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x1836fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183700: 0x24c20890  addiu       $v0, $a2, 0x890
    ctx->pc = 0x183700u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 2192));
    // 0x183704: 0x24c30800  addiu       $v1, $a2, 0x800
    ctx->pc = 0x183704u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 2048));
    // 0x183708: 0x695021  addu        $t2, $v1, $t1
    ctx->pc = 0x183708u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x18370c: 0x671821  addu        $v1, $v1, $a3
    ctx->pc = 0x18370cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x183710: 0x474021  addu        $t0, $v0, $a3
    ctx->pc = 0x183710u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x183714: 0x491021  addu        $v0, $v0, $t1
    ctx->pc = 0x183714u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x183718: 0xcc3021  addu        $a2, $a2, $t4
    ctx->pc = 0x183718u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 12)));
    // 0x18371c: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x18371cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x183720: 0xac6b0000  sw          $t3, 0x0($v1)
    ctx->pc = 0x183720u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 11));
    // 0x183724: 0xad4b0000  sw          $t3, 0x0($t2)
    ctx->pc = 0x183724u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 11));
    // 0x183728: 0xad000000  sw          $zero, 0x0($t0)
    ctx->pc = 0x183728u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 0));
    // 0x18372c: 0x25a917c8  addiu       $t1, $t5, 0x17C8
    ctx->pc = 0x18372cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 13), 6088));
    // 0x183730: 0x81230000  lb          $v1, 0x0($t1)
    ctx->pc = 0x183730u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x183734: 0x81270001  lb          $a3, 0x1($t1)
    ctx->pc = 0x183734u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 1)));
    // 0x183738: 0xa0c30000  sb          $v1, 0x0($a2)
    ctx->pc = 0x183738u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x18373c: 0xa0c70001  sb          $a3, 0x1($a2)
    ctx->pc = 0x18373cu;
    WRITE8(ADD32(GPR_U32(ctx, 6), 1), (uint8_t)GPR_U32(ctx, 7));
    // 0x183740: 0xc061af8  jal         func_186BE0
    ctx->pc = 0x183740u;
    SET_GPR_U32(ctx, 31, 0x183748u);
    ctx->pc = 0x183744u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183740u;
            // 0x183744: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186BE0u;
    if (runtime->hasFunction(0x186BE0u)) {
        auto targetFn = runtime->lookupFunction(0x186BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183748u; }
        if (ctx->pc != 0x183748u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186BE0_0x186be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183748u; }
        if (ctx->pc != 0x183748u) { return; }
    }
    ctx->pc = 0x183748u;
label_183748:
    // 0x183748: 0x10400206  beqz        $v0, . + 4 + (0x206 << 2)
    ctx->pc = 0x183748u;
    {
        const bool branch_taken_0x183748 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x183748) {
            ctx->pc = 0x183F64u;
            goto label_183f64;
        }
    }
    ctx->pc = 0x183750u;
    // 0x183750: 0xc061b04  jal         func_186C10
    ctx->pc = 0x183750u;
    SET_GPR_U32(ctx, 31, 0x183758u);
    ctx->pc = 0x183754u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183750u;
            // 0x183754: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186C10u;
    if (runtime->hasFunction(0x186C10u)) {
        auto targetFn = runtime->lookupFunction(0x186C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183758u; }
        if (ctx->pc != 0x183758u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186C10_0x186c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183758u; }
        if (ctx->pc != 0x183758u) { return; }
    }
    ctx->pc = 0x183758u;
label_183758:
    // 0x183758: 0x10400202  beqz        $v0, . + 4 + (0x202 << 2)
    ctx->pc = 0x183758u;
    {
        const bool branch_taken_0x183758 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x18375Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183758u;
            // 0x18375c: 0x3c100024  lui         $s0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183758) {
            ctx->pc = 0x183F64u;
            goto label_183f64;
        }
    }
    ctx->pc = 0x183760u;
    // 0x183760: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x183760u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183764: 0x260517d0  addiu       $a1, $s0, 0x17D0
    ctx->pc = 0x183764u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 6096));
    // 0x183768: 0xc042d10  jal         func_10B440
    ctx->pc = 0x183768u;
    SET_GPR_U32(ctx, 31, 0x183770u);
    ctx->pc = 0x18376Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183768u;
            // 0x18376c: 0x2406001b  addiu       $a2, $zero, 0x1B (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 27));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183770u; }
        if (ctx->pc != 0x183770u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183770u; }
        if (ctx->pc != 0x183770u) { return; }
    }
    ctx->pc = 0x183770u;
label_183770:
    // 0x183770: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x183770u;
    {
        const bool branch_taken_0x183770 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x183774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183770u;
            // 0x183774: 0x2403ffff  addiu       $v1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183770) {
            ctx->pc = 0x1837B4u;
            goto label_1837b4;
        }
    }
    ctx->pc = 0x183778u;
    // 0x183778: 0x2414001f  addiu       $s4, $zero, 0x1F
    ctx->pc = 0x183778u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x18377c: 0x2622014c  addiu       $v0, $s1, 0x14C
    ctx->pc = 0x18377cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 332));
label_183780:
    // 0x183780: 0x2694ffff  addiu       $s4, $s4, -0x1
    ctx->pc = 0x183780u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
    // 0x183784: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x183784u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x183788: 0x0  nop
    ctx->pc = 0x183788u;
    // NOP
    // 0x18378c: 0x0  nop
    ctx->pc = 0x18378cu;
    // NOP
    // 0x183790: 0x0  nop
    ctx->pc = 0x183790u;
    // NOP
    // 0x183794: 0x681fffa  bgez        $s4, . + 4 + (-0x6 << 2)
    ctx->pc = 0x183794u;
    {
        const bool branch_taken_0x183794 = (GPR_S64(ctx, 20) >= 0);
        ctx->pc = 0x183798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183794u;
            // 0x183798: 0x2442fffc  addiu       $v0, $v0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183794) {
            ctx->pc = 0x183780u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_183780;
        }
    }
    ctx->pc = 0x18379Cu;
    // 0x18379c: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x18379cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1837a0: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1837a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1837a4: 0xc061d5e  jal         func_187578
    ctx->pc = 0x1837A4u;
    SET_GPR_U32(ctx, 31, 0x1837ACu);
    ctx->pc = 0x1837A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1837A4u;
            // 0x1837a8: 0x262600d0  addiu       $a2, $s1, 0xD0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 208));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187578u;
    if (runtime->hasFunction(0x187578u)) {
        auto targetFn = runtime->lookupFunction(0x187578u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1837ACu; }
        if (ctx->pc != 0x1837ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187578_0x187578(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1837ACu; }
        if (ctx->pc != 0x1837ACu) { return; }
    }
    ctx->pc = 0x1837ACu;
label_1837ac:
    // 0x1837ac: 0x104001ed  beqz        $v0, . + 4 + (0x1ED << 2)
    ctx->pc = 0x1837ACu;
    {
        const bool branch_taken_0x1837ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1837ac) {
            ctx->pc = 0x183F64u;
            goto label_183f64;
        }
    }
    ctx->pc = 0x1837B4u;
label_1837b4:
    // 0x1837b4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1837b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1837b8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1837b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1837bc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1837BCu;
    SET_GPR_U32(ctx, 31, 0x1837C4u);
    ctx->pc = 0x1837C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1837BCu;
            // 0x1837c0: 0x24060028  addiu       $a2, $zero, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1837C4u; }
        if (ctx->pc != 0x1837C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1837C4u; }
        if (ctx->pc != 0x1837C4u) { return; }
    }
    ctx->pc = 0x1837C4u;
label_1837c4:
    // 0x1837c4: 0x260517d0  addiu       $a1, $s0, 0x17D0
    ctx->pc = 0x1837c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 6096));
    // 0x1837c8: 0x68a20007  ldl         $v0, 0x7($a1)
    ctx->pc = 0x1837c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x1837cc: 0x6ca20000  ldr         $v0, 0x0($a1)
    ctx->pc = 0x1837ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x1837d0: 0x68a3000f  ldl         $v1, 0xF($a1)
    ctx->pc = 0x1837d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x1837d4: 0x6ca30008  ldr         $v1, 0x8($a1)
    ctx->pc = 0x1837d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x1837d8: 0x68a40017  ldl         $a0, 0x17($a1)
    ctx->pc = 0x1837d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x1837dc: 0x6ca40010  ldr         $a0, 0x10($a1)
    ctx->pc = 0x1837dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x1837e0: 0xb2220007  sdl         $v0, 0x7($s1)
    ctx->pc = 0x1837e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1837e4: 0xb6220000  sdr         $v0, 0x0($s1)
    ctx->pc = 0x1837e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1837e8: 0xb223000f  sdl         $v1, 0xF($s1)
    ctx->pc = 0x1837e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1837ec: 0xb6230008  sdr         $v1, 0x8($s1)
    ctx->pc = 0x1837ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1837f0: 0xb2240017  sdl         $a0, 0x17($s1)
    ctx->pc = 0x1837f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1837f4: 0xb6240010  sdr         $a0, 0x10($s1)
    ctx->pc = 0x1837f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1837f8: 0x8ca20018  lw          $v0, 0x18($a1)
    ctx->pc = 0x1837f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x1837fc: 0xae220018  sw          $v0, 0x18($s1)
    ctx->pc = 0x1837fcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 2));
    // 0x183800: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x183800u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x183804: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x183804u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183808: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x183808u;
    SET_GPR_U32(ctx, 31, 0x183810u);
    ctx->pc = 0x18380Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183808u;
            // 0x18380c: 0x24a517f0  addiu       $a1, $a1, 0x17F0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 6128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183810u; }
        if (ctx->pc != 0x183810u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183810u; }
        if (ctx->pc != 0x183810u) { return; }
    }
    ctx->pc = 0x183810u;
label_183810:
    // 0x183810: 0x24040400  addiu       $a0, $zero, 0x400
    ctx->pc = 0x183810u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x183814: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x183814u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x183818: 0x2407ff00  addiu       $a3, $zero, -0x100
    ctx->pc = 0x183818u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x18381c: 0x97a30000  lhu         $v1, 0x0($sp)
    ctx->pc = 0x18381cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x183820: 0x240a0002  addiu       $t2, $zero, 0x2
    ctx->pc = 0x183820u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x183824: 0x82001a  div         $zero, $a0, $v0
    ctx->pc = 0x183824u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x183828: 0x2409002b  addiu       $t1, $zero, 0x2B
    ctx->pc = 0x183828u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 43));
    // 0x18382c: 0xa6230028  sh          $v1, 0x28($s1)
    ctx->pc = 0x18382cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 40), (uint16_t)GPR_U32(ctx, 3));
    // 0x183830: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x183830u;
    {
        const bool branch_taken_0x183830 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x183830) {
            ctx->pc = 0x183834u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x183830u;
            // 0x183834: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x183838u;
            goto label_183838;
        }
    }
    ctx->pc = 0x183838u;
label_183838:
    // 0x183838: 0x97a20004  lhu         $v0, 0x4($sp)
    ctx->pc = 0x183838u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x18383c: 0x24080100  addiu       $t0, $zero, 0x100
    ctx->pc = 0x18383cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x183840: 0x8fa30008  lw          $v1, 0x8($sp)
    ctx->pc = 0x183840u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x183844: 0x2406ffff  addiu       $a2, $zero, -0x1
    ctx->pc = 0x183844u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x183848: 0xa622002c  sh          $v0, 0x2C($s1)
    ctx->pc = 0x183848u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 44), (uint16_t)GPR_U32(ctx, 2));
    // 0x18384c: 0xa627002e  sh          $a3, 0x2E($s1)
    ctx->pc = 0x18384cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 46), (uint16_t)GPR_U32(ctx, 7));
    // 0x183850: 0x2812  mflo        $a1
    ctx->pc = 0x183850u;
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x183854: 0x30a2ffff  andi        $v0, $a1, 0xFFFF
    ctx->pc = 0x183854u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x183858: 0xa625002a  sh          $a1, 0x2A($s1)
    ctx->pc = 0x183858u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 42), (uint16_t)GPR_U32(ctx, 5));
    // 0x18385c: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x18385cu;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x183860: 0x9625002c  lhu         $a1, 0x2C($s1)
    ctx->pc = 0x183860u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 44)));
    // 0x183864: 0xae240154  sw          $a0, 0x154($s1)
    ctx->pc = 0x183864u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 340), GPR_U32(ctx, 4));
    // 0x183868: 0xa22a0150  sb          $t2, 0x150($s1)
    ctx->pc = 0x183868u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 336), (uint8_t)GPR_U32(ctx, 10));
    // 0x18386c: 0xa2290151  sb          $t1, 0x151($s1)
    ctx->pc = 0x18386cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 337), (uint8_t)GPR_U32(ctx, 9));
    // 0x183870: 0xae280158  sw          $t0, 0x158($s1)
    ctx->pc = 0x183870u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 344), GPR_U32(ctx, 8));
    // 0x183874: 0xae20003c  sw          $zero, 0x3C($s1)
    ctx->pc = 0x183874u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 60), GPR_U32(ctx, 0));
    // 0x183878: 0xae200048  sw          $zero, 0x48($s1)
    ctx->pc = 0x183878u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 72), GPR_U32(ctx, 0));
    // 0x18387c: 0xae20004c  sw          $zero, 0x4C($s1)
    ctx->pc = 0x18387cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 76), GPR_U32(ctx, 0));
    // 0x183880: 0x3812  mflo        $a3
    ctx->pc = 0x183880u;
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x183884: 0xa2001b  divu        $zero, $a1, $v0
    ctx->pc = 0x183884u;
    { uint32_t divisor = GPR_U32(ctx, 2); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 5) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 5) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,5); } }
    // 0x183888: 0xae270030  sw          $a3, 0x30($s1)
    ctx->pc = 0x183888u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 48), GPR_U32(ctx, 7));
    // 0x18388c: 0x8fa40004  lw          $a0, 0x4($sp)
    ctx->pc = 0x18388cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x183890: 0xae260180  sw          $a2, 0x180($s1)
    ctx->pc = 0x183890u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 384), GPR_U32(ctx, 6));
    // 0x183894: 0xae200164  sw          $zero, 0x164($s1)
    ctx->pc = 0x183894u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 356), GPR_U32(ctx, 0));
    // 0x183898: 0xae200168  sw          $zero, 0x168($s1)
    ctx->pc = 0x183898u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 360), GPR_U32(ctx, 0));
    // 0x18389c: 0xae20016c  sw          $zero, 0x16C($s1)
    ctx->pc = 0x18389cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 364), GPR_U32(ctx, 0));
    // 0x1838a0: 0xae200170  sw          $zero, 0x170($s1)
    ctx->pc = 0x1838a0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 368), GPR_U32(ctx, 0));
    // 0x1838a4: 0xae260174  sw          $a2, 0x174($s1)
    ctx->pc = 0x1838a4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 372), GPR_U32(ctx, 6));
    // 0x1838a8: 0xae260178  sw          $a2, 0x178($s1)
    ctx->pc = 0x1838a8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 376), GPR_U32(ctx, 6));
    // 0x1838ac: 0xae26017c  sw          $a2, 0x17C($s1)
    ctx->pc = 0x1838acu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 380), GPR_U32(ctx, 6));
    // 0x1838b0: 0x2812  mflo        $a1
    ctx->pc = 0x1838b0u;
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x1838b4: 0x64001a  div         $zero, $v1, $a0
    ctx->pc = 0x1838b4u;
    { int32_t divisor = GPR_S32(ctx, 4);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1838b8: 0xae25015c  sw          $a1, 0x15C($s1)
    ctx->pc = 0x1838b8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 348), GPR_U32(ctx, 5));
    // 0x1838bc: 0x1812  mflo        $v1
    ctx->pc = 0x1838bcu;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x1838c0: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1838c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1838c4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1838C4u;
    {
        const bool branch_taken_0x1838c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1838C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1838C4u;
            // 0x1838c8: 0xae230040  sw          $v1, 0x40($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 64), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1838c4) {
            ctx->pc = 0x1838D8u;
            goto label_1838d8;
        }
    }
    ctx->pc = 0x1838CCu;
    // 0x1838cc: 0x0  nop
    ctx->pc = 0x1838ccu;
    // NOP
label_1838d0:
    // 0x1838d0: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1838d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1838d4: 0xae220040  sw          $v0, 0x40($s1)
    ctx->pc = 0x1838d4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 64), GPR_U32(ctx, 2));
label_1838d8:
    // 0x1838d8: 0x8e250040  lw          $a1, 0x40($s1)
    ctx->pc = 0x1838d8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
    // 0x1838dc: 0xc061d48  jal         func_187520
    ctx->pc = 0x1838DCu;
    SET_GPR_U32(ctx, 31, 0x1838E4u);
    ctx->pc = 0x1838E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1838DCu;
            // 0x1838e0: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187520u;
    if (runtime->hasFunction(0x187520u)) {
        auto targetFn = runtime->lookupFunction(0x187520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1838E4u; }
        if (ctx->pc != 0x1838E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187520_0x187520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1838E4u; }
        if (ctx->pc != 0x1838E4u) { return; }
    }
    ctx->pc = 0x1838E4u;
label_1838e4:
    // 0x1838e4: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1838E4u;
    {
        const bool branch_taken_0x1838e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1838E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1838E4u;
            // 0x1838e8: 0x8e220040  lw          $v0, 0x40($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1838e4) {
            ctx->pc = 0x1838D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1838d0;
        }
    }
    ctx->pc = 0x1838ECu;
    // 0x1838ec: 0x0  nop
    ctx->pc = 0x1838ecu;
    // NOP
label_1838f0:
    // 0x1838f0: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1838f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1838f4: 0xae220044  sw          $v0, 0x44($s1)
    ctx->pc = 0x1838f4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 68), GPR_U32(ctx, 2));
    // 0x1838f8: 0x8e250044  lw          $a1, 0x44($s1)
    ctx->pc = 0x1838f8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 68)));
    // 0x1838fc: 0xc061d48  jal         func_187520
    ctx->pc = 0x1838FCu;
    SET_GPR_U32(ctx, 31, 0x183904u);
    ctx->pc = 0x183900u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1838FCu;
            // 0x183900: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187520u;
    if (runtime->hasFunction(0x187520u)) {
        auto targetFn = runtime->lookupFunction(0x187520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183904u; }
        if (ctx->pc != 0x183904u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187520_0x187520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183904u; }
        if (ctx->pc != 0x183904u) { return; }
    }
    ctx->pc = 0x183904u;
label_183904:
    // 0x183904: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x183904u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183908: 0x5640fff9  bnel        $s2, $zero, . + 4 + (-0x7 << 2)
    ctx->pc = 0x183908u;
    {
        const bool branch_taken_0x183908 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x183908) {
            ctx->pc = 0x18390Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x183908u;
            // 0x18390c: 0x8e220044  lw          $v0, 0x44($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 68)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1838F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1838f0;
        }
    }
    ctx->pc = 0x183910u;
    // 0x183910: 0x8e230030  lw          $v1, 0x30($s1)
    ctx->pc = 0x183910u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 48)));
    // 0x183914: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x183914u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x183918: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x183918u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18391c: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x18391cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x183920: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x183920u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x183924: 0x246303fe  addiu       $v1, $v1, 0x3FE
    ctx->pc = 0x183924u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1022));
    // 0x183928: 0x28440000  slti        $a0, $v0, 0x0
    ctx->pc = 0x183928u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x18392c: 0xa62818  mult        $a1, $a1, $a2
    ctx->pc = 0x18392cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x183930: 0x64100b  movn        $v0, $v1, $a0
    ctx->pc = 0x183930u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
    // 0x183934: 0x21283  sra         $v0, $v0, 10
    ctx->pc = 0x183934u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 10));
    // 0x183938: 0x24560001  addiu       $s6, $v0, 0x1
    ctx->pc = 0x183938u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x18393c: 0x162080  sll         $a0, $s6, 2
    ctx->pc = 0x18393cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 22), 2));
    // 0x183940: 0x24a703ff  addiu       $a3, $a1, 0x3FF
    ctx->pc = 0x183940u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 5), 1023));
    // 0x183944: 0x2483ffff  addiu       $v1, $a0, -0x1
    ctx->pc = 0x183944u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x183948: 0x248403fe  addiu       $a0, $a0, 0x3FE
    ctx->pc = 0x183948u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1022));
    // 0x18394c: 0x28620000  slti        $v0, $v1, 0x0
    ctx->pc = 0x18394cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x183950: 0x28a60000  slti        $a2, $a1, 0x0
    ctx->pc = 0x183950u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x183954: 0x82180b  movn        $v1, $a0, $v0
    ctx->pc = 0x183954u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 4));
    // 0x183958: 0xe6280b  movn        $a1, $a3, $a2
    ctx->pc = 0x183958u;
    if (GPR_U64(ctx, 6) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 7));
    // 0x18395c: 0x31a83  sra         $v1, $v1, 10
    ctx->pc = 0x18395cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 10));
    // 0x183960: 0x24750001  addiu       $s5, $v1, 0x1
    ctx->pc = 0x183960u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x183964: 0x2aa20021  slti        $v0, $s5, 0x21
    ctx->pc = 0x183964u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)(int32_t)33) ? 1 : 0);
    // 0x183968: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x183968u;
    {
        const bool branch_taken_0x183968 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18396Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183968u;
            // 0x18396c: 0x53a83  sra         $a3, $a1, 10 (Delay Slot)
        SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 5), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183968) {
            ctx->pc = 0x183978u;
            goto label_183978;
        }
    }
    ctx->pc = 0x183970u;
    // 0x183970: 0x24150020  addiu       $s5, $zero, 0x20
    ctx->pc = 0x183970u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x183974: 0x24162000  addiu       $s6, $zero, 0x2000
    ctx->pc = 0x183974u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
label_183978:
    // 0x183978: 0x26330050  addiu       $s3, $s1, 0x50
    ctx->pc = 0x183978u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 17), 80));
    // 0x18397c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x18397cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183980: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x183980u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183984: 0x24060080  addiu       $a2, $zero, 0x80
    ctx->pc = 0x183984u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x183988: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x183988u;
    SET_GPR_U32(ctx, 31, 0x183990u);
    ctx->pc = 0x18398Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183988u;
            // 0x18398c: 0xe0802d  daddu       $s0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183990u; }
        if (ctx->pc != 0x183990u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183990u; }
        if (ctx->pc != 0x183990u) { return; }
    }
    ctx->pc = 0x183990u;
label_183990:
    // 0x183990: 0x255182a  slt         $v1, $s2, $s5
    ctx->pc = 0x183990u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 21)) ? 1 : 0);
    // 0x183994: 0x10600010  beqz        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x183994u;
    {
        const bool branch_taken_0x183994 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x183998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183994u;
            // 0x183998: 0xa02d  daddu       $s4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183994) {
            ctx->pc = 0x1839D8u;
            goto label_1839d8;
        }
    }
    ctx->pc = 0x18399Cu;
    // 0x18399c: 0x0  nop
    ctx->pc = 0x18399cu;
    // NOP
label_1839a0:
    // 0x1839a0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1839a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1839a4: 0xc061d2a  jal         func_1874A8
    ctx->pc = 0x1839A4u;
    SET_GPR_U32(ctx, 31, 0x1839ACu);
    ctx->pc = 0x1839A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1839A4u;
            // 0x1839a8: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1874A8u;
    if (runtime->hasFunction(0x1874A8u)) {
        auto targetFn = runtime->lookupFunction(0x1874A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1839ACu; }
        if (ctx->pc != 0x1839ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001874A8_0x1874a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1839ACu; }
        if (ctx->pc != 0x1839ACu) { return; }
    }
    ctx->pc = 0x1839ACu;
label_1839ac:
    // 0x1839ac: 0x26030001  addiu       $v1, $s0, 0x1
    ctx->pc = 0x1839acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1839b0: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1839b0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1839b4: 0x3a420001  xori        $v0, $s2, 0x1
    ctx->pc = 0x1839b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) ^ (uint64_t)(uint16_t)1);
    // 0x1839b8: 0x1640fff9  bnez        $s2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1839B8u;
    {
        const bool branch_taken_0x1839b8 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x1839BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1839B8u;
            // 0x1839bc: 0x62800a  movz        $s0, $v1, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1839b8) {
            ctx->pc = 0x1839A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1839a0;
        }
    }
    ctx->pc = 0x1839C0u;
    // 0x1839c0: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x1839c0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x1839c4: 0xae700000  sw          $s0, 0x0($s3)
    ctx->pc = 0x1839c4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 16));
    // 0x1839c8: 0x295102a  slt         $v0, $s4, $s5
    ctx->pc = 0x1839c8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 21)) ? 1 : 0);
    // 0x1839cc: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1839ccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1839d0: 0x1440fff3  bnez        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x1839D0u;
    {
        const bool branch_taken_0x1839d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1839D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1839D0u;
            // 0x1839d4: 0x26730004  addiu       $s3, $s3, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1839d0) {
            ctx->pc = 0x1839A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1839a0;
        }
    }
    ctx->pc = 0x1839D8u;
label_1839d8:
    // 0x1839d8: 0x24020898  addiu       $v0, $zero, 0x898
    ctx->pc = 0x1839d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
    // 0x1839dc: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x1839dcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1839e0: 0x2e21018  mult        $v0, $s7, $v0
    ctx->pc = 0x1839e0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 23) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1839e4: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1839e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1839e8: 0x241400ff  addiu       $s4, $zero, 0xFF
    ctx->pc = 0x1839e8u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1839ec: 0x3c010028  lui         $at, 0x28
    ctx->pc = 0x1839ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)40 << 16));
    // 0x1839f0: 0x24215f44  addiu       $at, $at, 0x5F44
    ctx->pc = 0x1839f0u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), 24388));
    // 0x1839f4: 0x221021  addu        $v0, $at, $v0
    ctx->pc = 0x1839f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_1839f8:
    // 0x1839f8: 0x2694ffff  addiu       $s4, $s4, -0x1
    ctx->pc = 0x1839f8u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
    // 0x1839fc: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1839fcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x183a00: 0x0  nop
    ctx->pc = 0x183a00u;
    // NOP
    // 0x183a04: 0x0  nop
    ctx->pc = 0x183a04u;
    // NOP
    // 0x183a08: 0x0  nop
    ctx->pc = 0x183a08u;
    // NOP
    // 0x183a0c: 0x681fffa  bgez        $s4, . + 4 + (-0x6 << 2)
    ctx->pc = 0x183A0Cu;
    {
        const bool branch_taken_0x183a0c = (GPR_S64(ctx, 20) >= 0);
        ctx->pc = 0x183A10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183A0Cu;
            // 0x183a10: 0x2442fffc  addiu       $v0, $v0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183a0c) {
            ctx->pc = 0x1839F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1839f8;
        }
    }
    ctx->pc = 0x183A14u;
    // 0x183a14: 0x24020898  addiu       $v0, $zero, 0x898
    ctx->pc = 0x183a14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
    // 0x183a18: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x183a18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x183a1c: 0x2e21018  mult        $v0, $s7, $v0
    ctx->pc = 0x183a1cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 23) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x183a20: 0x241400ff  addiu       $s4, $zero, 0xFF
    ctx->pc = 0x183a20u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x183a24: 0x3c010028  lui         $at, 0x28
    ctx->pc = 0x183a24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)40 << 16));
    // 0x183a28: 0x24216344  addiu       $at, $at, 0x6344
    ctx->pc = 0x183a28u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), 25412));
    // 0x183a2c: 0x221021  addu        $v0, $at, $v0
    ctx->pc = 0x183a2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_183a30:
    // 0x183a30: 0x2694ffff  addiu       $s4, $s4, -0x1
    ctx->pc = 0x183a30u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
    // 0x183a34: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x183a34u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x183a38: 0x0  nop
    ctx->pc = 0x183a38u;
    // NOP
    // 0x183a3c: 0x0  nop
    ctx->pc = 0x183a3cu;
    // NOP
    // 0x183a40: 0x0  nop
    ctx->pc = 0x183a40u;
    // NOP
    // 0x183a44: 0x681fffa  bgez        $s4, . + 4 + (-0x6 << 2)
    ctx->pc = 0x183A44u;
    {
        const bool branch_taken_0x183a44 = (GPR_S64(ctx, 20) >= 0);
        ctx->pc = 0x183A48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183A44u;
            // 0x183a48: 0x2442fffc  addiu       $v0, $v0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183a44) {
            ctx->pc = 0x183A30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_183a30;
        }
    }
    ctx->pc = 0x183A4Cu;
    // 0x183a4c: 0x26d4ffff  addiu       $s4, $s6, -0x1
    ctx->pc = 0x183a4cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 22), 4294967295));
    // 0x183a50: 0x680003e  bltz        $s4, . + 4 + (0x3E << 2)
    ctx->pc = 0x183A50u;
    {
        const bool branch_taken_0x183a50 = (GPR_S64(ctx, 20) < 0);
        ctx->pc = 0x183A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183A50u;
            // 0x183a54: 0x24030226  addiu       $v1, $zero, 0x226 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 550));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183a50) {
            ctx->pc = 0x183B4Cu;
            goto label_183b4c;
        }
    }
    ctx->pc = 0x183A58u;
    // 0x183a58: 0x241e0898  addiu       $fp, $zero, 0x898
    ctx->pc = 0x183a58u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
    // 0x183a5c: 0x72e31018  mult1       $v0, $s7, $v1
    ctx->pc = 0x183a5cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 23) * (int64_t)GPR_S32(ctx, 3); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x183a60: 0x2fe2018  mult        $a0, $s7, $fp
    ctx->pc = 0x183a60u;
    { int64_t result = (int64_t)GPR_S32(ctx, 23) * (int64_t)GPR_S32(ctx, 30); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x183a64: 0xafa20024  sw          $v0, 0x24($sp)
    ctx->pc = 0x183a64u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 2));
    // 0x183a68: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x183a68u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183a6c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x183a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x183a70: 0x3c010028  lui         $at, 0x28
    ctx->pc = 0x183a70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)40 << 16));
    // 0x183a74: 0x24215b48  addiu       $at, $at, 0x5B48
    ctx->pc = 0x183a74u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), 23368));
    // 0x183a78: 0x242021  addu        $a0, $at, $a0
    ctx->pc = 0x183a78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
    // 0x183a7c: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x183a7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x183a80: 0xafa40028  sw          $a0, 0x28($sp)
    ctx->pc = 0x183a80u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 4));
    // 0x183a84: 0x2456004c  addiu       $s6, $v0, 0x4C
    ctx->pc = 0x183a84u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), 76));
label_183a88:
    // 0x183a88: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x183a88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183a8c: 0xc061d2a  jal         func_1874A8
    ctx->pc = 0x183A8Cu;
    SET_GPR_U32(ctx, 31, 0x183A94u);
    ctx->pc = 0x183A90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183A8Cu;
            // 0x183a90: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1874A8u;
    if (runtime->hasFunction(0x1874A8u)) {
        auto targetFn = runtime->lookupFunction(0x1874A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183A94u; }
        if (ctx->pc != 0x183A94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001874A8_0x1874a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183A94u; }
        if (ctx->pc != 0x183A94u) { return; }
    }
    ctx->pc = 0x183A94u;
label_183a94:
    // 0x183a94: 0x5440fffc  bnel        $v0, $zero, . + 4 + (-0x4 << 2)
    ctx->pc = 0x183A94u;
    {
        const bool branch_taken_0x183a94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x183a94) {
            ctx->pc = 0x183A98u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x183A94u;
            // 0x183a98: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x183A88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_183a88;
        }
    }
    ctx->pc = 0x183A9Cu;
    // 0x183a9c: 0x2fe9818  mult        $s3, $s7, $fp
    ctx->pc = 0x183a9cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 23) * (int64_t)GPR_S32(ctx, 30); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 19, (int32_t)result); }
    // 0x183aa0: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x183aa0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x183aa4: 0x24755f48  addiu       $s5, $v1, 0x5F48
    ctx->pc = 0x183aa4u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 3), 24392));
    // 0x183aa8: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x183aa8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183aac: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x183aacu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183ab0: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x183ab0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x183ab4: 0xc061baa  jal         func_186EA8
    ctx->pc = 0x183AB4u;
    SET_GPR_U32(ctx, 31, 0x183ABCu);
    ctx->pc = 0x183AB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183AB4u;
            // 0x183ab8: 0x2752821  addu        $a1, $s3, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186EA8u;
    if (runtime->hasFunction(0x186EA8u)) {
        auto targetFn = runtime->lookupFunction(0x186EA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183ABCu; }
        if (ctx->pc != 0x183ABCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186EA8_0x186ea8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183ABCu; }
        if (ctx->pc != 0x183ABCu) { return; }
    }
    ctx->pc = 0x183ABCu;
label_183abc:
    // 0x183abc: 0x10400129  beqz        $v0, . + 4 + (0x129 << 2)
    ctx->pc = 0x183ABCu;
    {
        const bool branch_taken_0x183abc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x183abc) {
            ctx->pc = 0x183F64u;
            goto label_183f64;
        }
    }
    ctx->pc = 0x183AC4u;
    // 0x183ac4: 0x8fa40024  lw          $a0, 0x24($sp)
    ctx->pc = 0x183ac4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x183ac8: 0x921021  addu        $v0, $a0, $s2
    ctx->pc = 0x183ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 18)));
    // 0x183acc: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x183accu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x183ad0: 0x26a4fc00  addiu       $a0, $s5, -0x400
    ctx->pc = 0x183ad0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294966272));
    // 0x183ad4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x183ad4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x183ad8: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x183ad8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x183adc: 0x2a430100  slti        $v1, $s2, 0x100
    ctx->pc = 0x183adcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x183ae0: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x183AE0u;
    {
        const bool branch_taken_0x183ae0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x183AE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183AE0u;
            // 0x183ae4: 0xac500000  sw          $s0, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183ae0) {
            ctx->pc = 0x183AF0u;
            goto label_183af0;
        }
    }
    ctx->pc = 0x183AE8u;
    // 0x183ae8: 0x56800016  bnel        $s4, $zero, . + 4 + (0x16 << 2)
    ctx->pc = 0x183AE8u;
    {
        const bool branch_taken_0x183ae8 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 0));
        if (branch_taken_0x183ae8) {
            ctx->pc = 0x183AECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x183AE8u;
            // 0x183aec: 0x2694ffff  addiu       $s4, $s4, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x183B44u;
            goto label_183b44;
        }
    }
    ctx->pc = 0x183AF0u;
label_183af0:
    // 0x183af0: 0x26d60004  addiu       $s6, $s6, 0x4
    ctx->pc = 0x183af0u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 4));
    // 0x183af4: 0x2642821  addu        $a1, $s3, $a0
    ctx->pc = 0x183af4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 4)));
    // 0x183af8: 0x8ec60000  lw          $a2, 0x0($s6)
    ctx->pc = 0x183af8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x183afc: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x183afcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x183b00: 0xc061baa  jal         func_186EA8
    ctx->pc = 0x183B00u;
    SET_GPR_U32(ctx, 31, 0x183B08u);
    ctx->pc = 0x183B04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183B00u;
            // 0x183b04: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186EA8u;
    if (runtime->hasFunction(0x186EA8u)) {
        auto targetFn = runtime->lookupFunction(0x186EA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183B08u; }
        if (ctx->pc != 0x183B08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186EA8_0x186ea8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183B08u; }
        if (ctx->pc != 0x183B08u) { return; }
    }
    ctx->pc = 0x183B08u;
label_183b08:
    // 0x183b08: 0x10400116  beqz        $v0, . + 4 + (0x116 << 2)
    ctx->pc = 0x183B08u;
    {
        const bool branch_taken_0x183b08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x183B0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183B08u;
            // 0x183b0c: 0x8fa50028  lw          $a1, 0x28($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183b08) {
            ctx->pc = 0x183F64u;
            goto label_183f64;
        }
    }
    ctx->pc = 0x183B10u;
    // 0x183b10: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x183b10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x183b14: 0x241200ff  addiu       $s2, $zero, 0xFF
    ctx->pc = 0x183b14u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x183b18: 0x24a203fc  addiu       $v0, $a1, 0x3FC
    ctx->pc = 0x183b18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 1020));
    // 0x183b1c: 0x0  nop
    ctx->pc = 0x183b1cu;
    // NOP
label_183b20:
    // 0x183b20: 0x2652ffff  addiu       $s2, $s2, -0x1
    ctx->pc = 0x183b20u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x183b24: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x183b24u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x183b28: 0x0  nop
    ctx->pc = 0x183b28u;
    // NOP
    // 0x183b2c: 0x0  nop
    ctx->pc = 0x183b2cu;
    // NOP
    // 0x183b30: 0x0  nop
    ctx->pc = 0x183b30u;
    // NOP
    // 0x183b34: 0x641fffa  bgez        $s2, . + 4 + (-0x6 << 2)
    ctx->pc = 0x183B34u;
    {
        const bool branch_taken_0x183b34 = (GPR_S64(ctx, 18) >= 0);
        ctx->pc = 0x183B38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183B34u;
            // 0x183b38: 0x2442fffc  addiu       $v0, $v0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183b34) {
            ctx->pc = 0x183B20u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_183b20;
        }
    }
    ctx->pc = 0x183B3Cu;
    // 0x183b3c: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x183b3cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183b40: 0x2694ffff  addiu       $s4, $s4, -0x1
    ctx->pc = 0x183b40u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
label_183b44:
    // 0x183b44: 0x681ffd0  bgez        $s4, . + 4 + (-0x30 << 2)
    ctx->pc = 0x183B44u;
    {
        const bool branch_taken_0x183b44 = (GPR_S64(ctx, 20) >= 0);
        ctx->pc = 0x183B48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183B44u;
            // 0x183b48: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183b44) {
            ctx->pc = 0x183A88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_183a88;
        }
    }
    ctx->pc = 0x183B4Cu;
label_183b4c:
    // 0x183b4c: 0x9626002a  lhu         $a2, 0x2A($s1)
    ctx->pc = 0x183b4cu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 42)));
    // 0x183b50: 0x240503e8  addiu       $a1, $zero, 0x3E8
    ctx->pc = 0x183b50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x183b54: 0xae300034  sw          $s0, 0x34($s1)
    ctx->pc = 0x183b54u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 16));
    // 0x183b58: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x183b58u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183b5c: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x183B5Cu;
    {
        const bool branch_taken_0x183b5c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x183b5c) {
            ctx->pc = 0x183B60u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x183B5Cu;
            // 0x183b60: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x183B64u;
            goto label_183b64;
        }
    }
    ctx->pc = 0x183B64u;
label_183b64:
    // 0x183b64: 0x8e240030  lw          $a0, 0x30($s1)
    ctx->pc = 0x183b64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 48)));
    // 0x183b68: 0x9628002c  lhu         $t0, 0x2C($s1)
    ctx->pc = 0x183b68u;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 44)));
    // 0x183b6c: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x183b6cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183b70: 0x85001a  div         $zero, $a0, $a1
    ctx->pc = 0x183b70u;
    { int32_t divisor = GPR_S32(ctx, 5);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x183b74: 0x8e270044  lw          $a3, 0x44($s1)
    ctx->pc = 0x183b74u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 68)));
    // 0x183b78: 0x2012  mflo        $a0
    ctx->pc = 0x183b78u;
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x183b7c: 0xe81818  mult        $v1, $a3, $t0
    ctx->pc = 0x183b7cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x183b80: 0x41140  sll         $v0, $a0, 5
    ctx->pc = 0x183b80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
    // 0x183b84: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x183b84u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x183b88: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x183b88u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x183b8c: 0x66001a  div         $zero, $v1, $a2
    ctx->pc = 0x183b8cu;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x183b90: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x183b90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x183b94: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x183b94u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x183b98: 0x24530001  addiu       $s3, $v0, 0x1
    ctx->pc = 0x183b98u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x183b9c: 0x1812  mflo        $v1
    ctx->pc = 0x183b9cu;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x183ba0: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x183ba0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x183ba4: 0xae230038  sw          $v1, 0x38($s1)
    ctx->pc = 0x183ba4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 56), GPR_U32(ctx, 3));
    // 0x183ba8: 0x1860002a  blez        $v1, . + 4 + (0x2A << 2)
    ctx->pc = 0x183BA8u;
    {
        const bool branch_taken_0x183ba8 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x183BACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183BA8u;
            // 0x183bac: 0xe81018  mult        $v0, $a3, $t0 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x183ba8) {
            ctx->pc = 0x183C54u;
            goto label_183c54;
        }
    }
    ctx->pc = 0x183BB0u;
    // 0x183bb0: 0x24150001  addiu       $s5, $zero, 0x1
    ctx->pc = 0x183bb0u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x183bb4: 0x0  nop
    ctx->pc = 0x183bb4u;
    // NOP
label_183bb8:
    // 0x183bb8: 0x16530004  bne         $s2, $s3, . + 4 + (0x4 << 2)
    ctx->pc = 0x183BB8u;
    {
        const bool branch_taken_0x183bb8 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 19));
        ctx->pc = 0x183BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183BB8u;
            // 0x183bbc: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183bb8) {
            ctx->pc = 0x183BCCu;
            goto label_183bcc;
        }
    }
    ctx->pc = 0x183BC0u;
    // 0x183bc0: 0x8e220034  lw          $v0, 0x34($s1)
    ctx->pc = 0x183bc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 52)));
    // 0x183bc4: 0x2021023  subu        $v0, $s0, $v0
    ctx->pc = 0x183bc4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x183bc8: 0xae220170  sw          $v0, 0x170($s1)
    ctx->pc = 0x183bc8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 368), GPR_U32(ctx, 2));
label_183bcc:
    // 0x183bcc: 0xc061d2a  jal         func_1874A8
    ctx->pc = 0x183BCCu;
    SET_GPR_U32(ctx, 31, 0x183BD4u);
    ctx->pc = 0x183BD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183BCCu;
            // 0x183bd0: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1874A8u;
    if (runtime->hasFunction(0x1874A8u)) {
        auto targetFn = runtime->lookupFunction(0x1874A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183BD4u; }
        if (ctx->pc != 0x183BD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001874A8_0x1874a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183BD4u; }
        if (ctx->pc != 0x183BD4u) { return; }
    }
    ctx->pc = 0x183BD4u;
label_183bd4:
    // 0x183bd4: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x183bd4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183bd8: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x183bd8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x183bdc: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x183bdcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183be0: 0x27a70020  addiu       $a3, $sp, 0x20
    ctx->pc = 0x183be0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x183be4: 0x14550008  bne         $v0, $s5, . + 4 + (0x8 << 2)
    ctx->pc = 0x183BE4u;
    {
        const bool branch_taken_0x183be4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 21));
        ctx->pc = 0x183BE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183BE4u;
            // 0x183be8: 0x34c6ffff  ori         $a2, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x183be4) {
            ctx->pc = 0x183C08u;
            goto label_183c08;
        }
    }
    ctx->pc = 0x183BECu;
    // 0x183bec: 0xc060b28  jal         func_182CA0
    ctx->pc = 0x183BECu;
    SET_GPR_U32(ctx, 31, 0x183BF4u);
    ctx->pc = 0x183BF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183BECu;
            // 0x183bf0: 0x2406fffd  addiu       $a2, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182CA0u;
    if (runtime->hasFunction(0x182CA0u)) {
        auto targetFn = runtime->lookupFunction(0x182CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183BF4u; }
        if (ctx->pc != 0x183BF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182CA0_0x182ca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183BF4u; }
        if (ctx->pc != 0x183BF4u) { return; }
    }
    ctx->pc = 0x183BF4u;
label_183bf4:
    // 0x183bf4: 0x8fa20020  lw          $v0, 0x20($sp)
    ctx->pc = 0x183bf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x183bf8: 0x5040000e  beql        $v0, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x183BF8u;
    {
        const bool branch_taken_0x183bf8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x183bf8) {
            ctx->pc = 0x183BFCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x183BF8u;
            // 0x183bfc: 0x8e220038  lw          $v0, 0x38($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x183C34u;
            goto label_183c34;
        }
    }
    ctx->pc = 0x183C00u;
    // 0x183c00: 0x100000e6  b           . + 4 + (0xE6 << 2)
    ctx->pc = 0x183C00u;
    {
        const bool branch_taken_0x183c00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x183C04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183C00u;
            // 0x183c04: 0xdfb00030  ld          $s0, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183c00) {
            ctx->pc = 0x183F9Cu;
            goto label_183f9c;
        }
    }
    ctx->pc = 0x183C08u;
label_183c08:
    // 0x183c08: 0x52400001  beql        $s2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x183C08u;
    {
        const bool branch_taken_0x183c08 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x183c08) {
            ctx->pc = 0x183C0Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x183C08u;
            // 0x183c0c: 0xae300034  sw          $s0, 0x34($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x183C10u;
            goto label_183c10;
        }
    }
    ctx->pc = 0x183C10u;
label_183c10:
    // 0x183c10: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x183c10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183c14: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x183c14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183c18: 0xc060b28  jal         func_182CA0
    ctx->pc = 0x183C18u;
    SET_GPR_U32(ctx, 31, 0x183C20u);
    ctx->pc = 0x183C1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183C18u;
            // 0x183c1c: 0x27a70020  addiu       $a3, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182CA0u;
    if (runtime->hasFunction(0x182CA0u)) {
        auto targetFn = runtime->lookupFunction(0x182CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183C20u; }
        if (ctx->pc != 0x183C20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182CA0_0x182ca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183C20u; }
        if (ctx->pc != 0x183C20u) { return; }
    }
    ctx->pc = 0x183C20u;
label_183c20:
    // 0x183c20: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x183c20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x183c24: 0x146000dc  bnez        $v1, . + 4 + (0xDC << 2)
    ctx->pc = 0x183C24u;
    {
        const bool branch_taken_0x183c24 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x183C28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183C24u;
            // 0x183c28: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183c24) {
            ctx->pc = 0x183F98u;
            goto label_183f98;
        }
    }
    ctx->pc = 0x183C2Cu;
    // 0x183c2c: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x183c2cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x183c30: 0x8e220038  lw          $v0, 0x38($s1)
    ctx->pc = 0x183c30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
label_183c34:
    // 0x183c34: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x183c34u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x183c38: 0x282102a  slt         $v0, $s4, $v0
    ctx->pc = 0x183c38u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x183c3c: 0x1440ffde  bnez        $v0, . + 4 + (-0x22 << 2)
    ctx->pc = 0x183C3Cu;
    {
        const bool branch_taken_0x183c3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x183C40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183C3Cu;
            // 0x183c40: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183c3c) {
            ctx->pc = 0x183BB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_183bb8;
        }
    }
    ctx->pc = 0x183C44u;
    // 0x183c44: 0x9626002a  lhu         $a2, 0x2A($s1)
    ctx->pc = 0x183c44u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 42)));
    // 0x183c48: 0x9628002c  lhu         $t0, 0x2C($s1)
    ctx->pc = 0x183c48u;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 44)));
    // 0x183c4c: 0x8e270044  lw          $a3, 0x44($s1)
    ctx->pc = 0x183c4cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 68)));
    // 0x183c50: 0xe81018  mult        $v0, $a3, $t0
    ctx->pc = 0x183c50u;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
label_183c54:
    // 0x183c54: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x183C54u;
    {
        const bool branch_taken_0x183c54 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x183c54) {
            ctx->pc = 0x183C58u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x183C54u;
            // 0x183c58: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x183C5Cu;
            goto label_183c5c;
        }
    }
    ctx->pc = 0x183C5Cu;
label_183c5c:
    // 0x183c5c: 0x8e230034  lw          $v1, 0x34($s1)
    ctx->pc = 0x183c5cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 52)));
    // 0x183c60: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x183c60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183c64: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x183c64u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x183c68: 0x46001a  div         $zero, $v0, $a2
    ctx->pc = 0x183c68u;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x183c6c: 0x1012  mflo        $v0
    ctx->pc = 0x183c6cu;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x183c70: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x183c70u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x183c74: 0xc060b7a  jal         func_182DE8
    ctx->pc = 0x183C74u;
    SET_GPR_U32(ctx, 31, 0x183C7Cu);
    ctx->pc = 0x183C78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183C74u;
            // 0x183c78: 0xae220038  sw          $v0, 0x38($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182DE8u;
    if (runtime->hasFunction(0x182DE8u)) {
        auto targetFn = runtime->lookupFunction(0x182DE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183C7Cu; }
        if (ctx->pc != 0x183C7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182DE8_0x182de8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183C7Cu; }
        if (ctx->pc != 0x183C7Cu) { return; }
    }
    ctx->pc = 0x183C7Cu;
label_183c7c:
    // 0x183c7c: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x183c7cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x183c80: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x183c80u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183c84: 0x146000c4  bnez        $v1, . + 4 + (0xC4 << 2)
    ctx->pc = 0x183C84u;
    {
        const bool branch_taken_0x183c84 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x183C88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183C84u;
            // 0x183c88: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183c84) {
            ctx->pc = 0x183F98u;
            goto label_183f98;
        }
    }
    ctx->pc = 0x183C8Cu;
    // 0x183c8c: 0x12000008  beqz        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x183C8Cu;
    {
        const bool branch_taken_0x183c8c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x183C90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183C8Cu;
            // 0x183c90: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183c8c) {
            ctx->pc = 0x183CB0u;
            goto label_183cb0;
        }
    }
    ctx->pc = 0x183C94u;
    // 0x183c94: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x183c94u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x183c98: 0xc045a12  jal         func_116848
    ctx->pc = 0x183C98u;
    SET_GPR_U32(ctx, 31, 0x183CA0u);
    ctx->pc = 0x183C9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183C98u;
            // 0x183c9c: 0x24841800  addiu       $a0, $a0, 0x1800 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183CA0u; }
        if (ctx->pc != 0x183CA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183CA0u; }
        if (ctx->pc != 0x183CA0u) { return; }
    }
    ctx->pc = 0x183CA0u;
label_183ca0:
    // 0x183ca0: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x183ca0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x183ca4: 0x100000bc  b           . + 4 + (0xBC << 2)
    ctx->pc = 0x183CA4u;
    {
        const bool branch_taken_0x183ca4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x183CA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183CA4u;
            // 0x183ca8: 0x34429001  ori         $v0, $v0, 0x9001 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36865);
        ctx->in_delay_slot = false;
        if (branch_taken_0x183ca4) {
            ctx->pc = 0x183F98u;
            goto label_183f98;
        }
    }
    ctx->pc = 0x183CACu;
    // 0x183cac: 0x0  nop
    ctx->pc = 0x183cacu;
    // NOP
label_183cb0:
    // 0x183cb0: 0x3c100028  lui         $s0, 0x28
    ctx->pc = 0x183cb0u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)40 << 16));
    // 0x183cb4: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x183cb4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x183cb8: 0x26106c80  addiu       $s0, $s0, 0x6C80
    ctx->pc = 0x183cb8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 27776));
    // 0x183cbc: 0xc061ffe  jal         func_187FF8
    ctx->pc = 0x183CBCu;
    SET_GPR_U32(ctx, 31, 0x183CC4u);
    ctx->pc = 0x183CC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183CBCu;
            // 0x183cc0: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187FF8u;
    if (runtime->hasFunction(0x187FF8u)) {
        auto targetFn = runtime->lookupFunction(0x187FF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183CC4u; }
        if (ctx->pc != 0x183CC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187FF8_0x187ff8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183CC4u; }
        if (ctx->pc != 0x183CC4u) { return; }
    }
    ctx->pc = 0x183CC4u;
label_183cc4:
    // 0x183cc4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x183cc4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183cc8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x183cc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183ccc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x183CCCu;
    SET_GPR_U32(ctx, 31, 0x183CD4u);
    ctx->pc = 0x183CD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183CCCu;
            // 0x183cd0: 0x24060200  addiu       $a2, $zero, 0x200 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183CD4u; }
        if (ctx->pc != 0x183CD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183CD4u; }
        if (ctx->pc != 0x183CD4u) { return; }
    }
    ctx->pc = 0x183CD4u;
label_183cd4:
    // 0x183cd4: 0x24148427  addiu       $s4, $zero, -0x7BD9
    ctx->pc = 0x183cd4u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 4294935591));
    // 0x183cd8: 0x93a50017  lbu         $a1, 0x17($sp)
    ctx->pc = 0x183cd8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 23)));
    // 0x183cdc: 0x3c150024  lui         $s5, 0x24
    ctx->pc = 0x183cdcu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)36 << 16));
    // 0x183ce0: 0x93ae0016  lbu         $t6, 0x16($sp)
    ctx->pc = 0x183ce0u;
    SET_GPR_U32(ctx, 14, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 22)));
    // 0x183ce4: 0x24160002  addiu       $s6, $zero, 0x2
    ctx->pc = 0x183ce4u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x183ce8: 0x93ac0015  lbu         $t4, 0x15($sp)
    ctx->pc = 0x183ce8u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 21)));
    // 0x183cec: 0x52102  srl         $a0, $a1, 4
    ctx->pc = 0x183cecu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 5), 4));
    // 0x183cf0: 0x93ab0013  lbu         $t3, 0x13($sp)
    ctx->pc = 0x183cf0u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 19)));
    // 0x183cf4: 0xe9902  srl         $s3, $t6, 4
    ctx->pc = 0x183cf4u;
    SET_GPR_S32(ctx, 19, (int32_t)SRL32(GPR_U32(ctx, 14), 4));
    // 0x183cf8: 0x93aa0012  lbu         $t2, 0x12($sp)
    ctx->pc = 0x183cf8u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 18)));
    // 0x183cfc: 0xc9102  srl         $s2, $t4, 4
    ctx->pc = 0x183cfcu;
    SET_GPR_S32(ctx, 18, (int32_t)SRL32(GPR_U32(ctx, 12), 4));
    // 0x183d00: 0x93a60011  lbu         $a2, 0x11($sp)
    ctx->pc = 0x183d00u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 17)));
    // 0x183d04: 0xb7902  srl         $t7, $t3, 4
    ctx->pc = 0x183d04u;
    SET_GPR_S32(ctx, 15, (int32_t)SRL32(GPR_U32(ctx, 11), 4));
    // 0x183d08: 0xa8902  srl         $s1, $t2, 4
    ctx->pc = 0x183d08u;
    SET_GPR_S32(ctx, 17, (int32_t)SRL32(GPR_U32(ctx, 10), 4));
    // 0x183d0c: 0x314a000f  andi        $t2, $t2, 0xF
    ctx->pc = 0x183d0cu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) & (uint64_t)(uint16_t)15);
    // 0x183d10: 0x66902  srl         $t5, $a2, 4
    ctx->pc = 0x183d10u;
    SET_GPR_S32(ctx, 13, (int32_t)SRL32(GPR_U32(ctx, 6), 4));
    // 0x183d14: 0x30c6000f  andi        $a2, $a2, 0xF
    ctx->pc = 0x183d14u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)15);
    // 0x183d18: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x183d18u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x183d1c: 0xf3880  sll         $a3, $t7, 2
    ctx->pc = 0x183d1cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 15), 2));
    // 0x183d20: 0xd4880  sll         $t1, $t5, 2
    ctx->pc = 0x183d20u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 13), 2));
    // 0x183d24: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x183d24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x183d28: 0x131880  sll         $v1, $s3, 2
    ctx->pc = 0x183d28u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
    // 0x183d2c: 0x114080  sll         $t0, $s1, 2
    ctx->pc = 0x183d2cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x183d30: 0x122080  sll         $a0, $s2, 2
    ctx->pc = 0x183d30u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x183d34: 0xef3821  addu        $a3, $a3, $t7
    ctx->pc = 0x183d34u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 15)));
    // 0x183d38: 0x12d4821  addu        $t1, $t1, $t5
    ctx->pc = 0x183d38u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 13)));
    // 0x183d3c: 0x731821  addu        $v1, $v1, $s3
    ctx->pc = 0x183d3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 19)));
    // 0x183d40: 0x922021  addu        $a0, $a0, $s2
    ctx->pc = 0x183d40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 18)));
    // 0x183d44: 0x1114021  addu        $t0, $t0, $s1
    ctx->pc = 0x183d44u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 17)));
    // 0x183d48: 0x30a5000f  andi        $a1, $a1, 0xF
    ctx->pc = 0x183d48u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)15);
    // 0x183d4c: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x183d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x183d50: 0x31ce000f  andi        $t6, $t6, 0xF
    ctx->pc = 0x183d50u;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 14) & (uint64_t)(uint16_t)15);
    // 0x183d54: 0x318c000f  andi        $t4, $t4, 0xF
    ctx->pc = 0x183d54u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) & (uint64_t)(uint16_t)15);
    // 0x183d58: 0x316b000f  andi        $t3, $t3, 0xF
    ctx->pc = 0x183d58u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)15);
    // 0x183d5c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x183d5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x183d60: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x183d60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x183d64: 0x42040  sll         $a0, $a0, 1
    ctx->pc = 0x183d64u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x183d68: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x183d68u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x183d6c: 0x84040  sll         $t0, $t0, 1
    ctx->pc = 0x183d6cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x183d70: 0x94840  sll         $t1, $t1, 1
    ctx->pc = 0x183d70u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
    // 0x183d74: 0x6e1821  addu        $v1, $v1, $t6
    ctx->pc = 0x183d74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 14)));
    // 0x183d78: 0x8c2021  addu        $a0, $a0, $t4
    ctx->pc = 0x183d78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 12)));
    // 0x183d7c: 0xeb3821  addu        $a3, $a3, $t3
    ctx->pc = 0x183d7cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x183d80: 0x10a4021  addu        $t0, $t0, $t2
    ctx->pc = 0x183d80u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 10)));
    // 0x183d84: 0x1264821  addu        $t1, $t1, $a2
    ctx->pc = 0x183d84u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
    // 0x183d88: 0x244207d0  addiu       $v0, $v0, 0x7D0
    ctx->pc = 0x183d88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2000));
    // 0x183d8c: 0xa6140000  sh          $s4, 0x0($s0)
    ctx->pc = 0x183d8cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 20));
    // 0x183d90: 0xa602000e  sh          $v0, 0xE($s0)
    ctx->pc = 0x183d90u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 14), (uint16_t)GPR_U32(ctx, 2));
    // 0x183d94: 0x200882d  daddu       $s1, $s0, $zero
    ctx->pc = 0x183d94u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183d98: 0xa203000d  sb          $v1, 0xD($s0)
    ctx->pc = 0x183d98u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 13), (uint8_t)GPR_U32(ctx, 3));
    // 0x183d9c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x183d9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183da0: 0xa204000c  sb          $a0, 0xC($s0)
    ctx->pc = 0x183da0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 12), (uint8_t)GPR_U32(ctx, 4));
    // 0x183da4: 0x24060200  addiu       $a2, $zero, 0x200
    ctx->pc = 0x183da4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x183da8: 0xa207000b  sb          $a3, 0xB($s0)
    ctx->pc = 0x183da8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 11), (uint8_t)GPR_U32(ctx, 7));
    // 0x183dac: 0xa208000a  sb          $t0, 0xA($s0)
    ctx->pc = 0x183dacu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 8));
    // 0x183db0: 0xa2090009  sb          $t1, 0x9($s0)
    ctx->pc = 0x183db0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 9), (uint8_t)GPR_U32(ctx, 9));
    // 0x183db4: 0xa6000002  sh          $zero, 0x2($s0)
    ctx->pc = 0x183db4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 0));
    // 0x183db8: 0xa2000008  sb          $zero, 0x8($s0)
    ctx->pc = 0x183db8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 8), (uint8_t)GPR_U32(ctx, 0));
    // 0x183dbc: 0x96a217b0  lhu         $v0, 0x17B0($s5)
    ctx->pc = 0x183dbcu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 21), 6064)));
    // 0x183dc0: 0x2415a426  addiu       $s5, $zero, -0x5BDA
    ctx->pc = 0x183dc0u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 4294943782));
    // 0x183dc4: 0x6a03000f  ldl         $v1, 0xF($s0)
    ctx->pc = 0x183dc4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x183dc8: 0x6e030008  ldr         $v1, 0x8($s0)
    ctx->pc = 0x183dc8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x183dcc: 0xb203001f  sdl         $v1, 0x1F($s0)
    ctx->pc = 0x183dccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x183dd0: 0xb6030018  sdr         $v1, 0x18($s0)
    ctx->pc = 0x183dd0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x183dd4: 0xae160004  sw          $s6, 0x4($s0)
    ctx->pc = 0x183dd4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 22));
    // 0x183dd8: 0x3c160024  lui         $s6, 0x24
    ctx->pc = 0x183dd8u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)36 << 16));
    // 0x183ddc: 0xa6020040  sh          $v0, 0x40($s0)
    ctx->pc = 0x183ddcu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 64), (uint16_t)GPR_U32(ctx, 2));
    // 0x183de0: 0xae000010  sw          $zero, 0x10($s0)
    ctx->pc = 0x183de0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
    // 0x183de4: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x183de4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x183de8: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x183de8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x183dec: 0x26100200  addiu       $s0, $s0, 0x200
    ctx->pc = 0x183decu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 512));
    // 0x183df0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x183DF0u;
    SET_GPR_U32(ctx, 31, 0x183DF8u);
    ctx->pc = 0x183DF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183DF0u;
            // 0x183df4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183DF8u; }
        if (ctx->pc != 0x183DF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183DF8u; }
        if (ctx->pc != 0x183DF8u) { return; }
    }
    ctx->pc = 0x183DF8u;
label_183df8:
    // 0x183df8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x183df8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183dfc: 0x93a40017  lbu         $a0, 0x17($sp)
    ctx->pc = 0x183dfcu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 23)));
    // 0x183e00: 0x93af0016  lbu         $t7, 0x16($sp)
    ctx->pc = 0x183e00u;
    SET_GPR_U32(ctx, 15, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 22)));
    // 0x183e04: 0x93ad0015  lbu         $t5, 0x15($sp)
    ctx->pc = 0x183e04u;
    SET_GPR_U32(ctx, 13, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 21)));
    // 0x183e08: 0x43902  srl         $a3, $a0, 4
    ctx->pc = 0x183e08u;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 4), 4));
    // 0x183e0c: 0x93ac0013  lbu         $t4, 0x13($sp)
    ctx->pc = 0x183e0cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 19)));
    // 0x183e10: 0xfa102  srl         $s4, $t7, 4
    ctx->pc = 0x183e10u;
    SET_GPR_S32(ctx, 20, (int32_t)SRL32(GPR_U32(ctx, 15), 4));
    // 0x183e14: 0x93ab0012  lbu         $t3, 0x12($sp)
    ctx->pc = 0x183e14u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 18)));
    // 0x183e18: 0xd9902  srl         $s3, $t5, 4
    ctx->pc = 0x183e18u;
    SET_GPR_S32(ctx, 19, (int32_t)SRL32(GPR_U32(ctx, 13), 4));
    // 0x183e1c: 0x93a60011  lbu         $a2, 0x11($sp)
    ctx->pc = 0x183e1cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 17)));
    // 0x183e20: 0xc8902  srl         $s1, $t4, 4
    ctx->pc = 0x183e20u;
    SET_GPR_S32(ctx, 17, (int32_t)SRL32(GPR_U32(ctx, 12), 4));
    // 0x183e24: 0xb9102  srl         $s2, $t3, 4
    ctx->pc = 0x183e24u;
    SET_GPR_S32(ctx, 18, (int32_t)SRL32(GPR_U32(ctx, 11), 4));
    // 0x183e28: 0x316b000f  andi        $t3, $t3, 0xF
    ctx->pc = 0x183e28u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)15);
    // 0x183e2c: 0x67102  srl         $t6, $a2, 4
    ctx->pc = 0x183e2cu;
    SET_GPR_S32(ctx, 14, (int32_t)SRL32(GPR_U32(ctx, 6), 4));
    // 0x183e30: 0x30c6000f  andi        $a2, $a2, 0xF
    ctx->pc = 0x183e30u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)15);
    // 0x183e34: 0x71080  sll         $v0, $a3, 2
    ctx->pc = 0x183e34u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x183e38: 0x141880  sll         $v1, $s4, 2
    ctx->pc = 0x183e38u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 2));
    // 0x183e3c: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x183e3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x183e40: 0x133880  sll         $a3, $s3, 2
    ctx->pc = 0x183e40u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
    // 0x183e44: 0x114080  sll         $t0, $s1, 2
    ctx->pc = 0x183e44u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x183e48: 0x124880  sll         $t1, $s2, 2
    ctx->pc = 0x183e48u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x183e4c: 0xe5080  sll         $t2, $t6, 2
    ctx->pc = 0x183e4cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 14), 2));
    // 0x183e50: 0x3084000f  andi        $a0, $a0, 0xF
    ctx->pc = 0x183e50u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x183e54: 0x741821  addu        $v1, $v1, $s4
    ctx->pc = 0x183e54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 20)));
    // 0x183e58: 0xf33821  addu        $a3, $a3, $s3
    ctx->pc = 0x183e58u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 19)));
    // 0x183e5c: 0x1114021  addu        $t0, $t0, $s1
    ctx->pc = 0x183e5cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 17)));
    // 0x183e60: 0x1324821  addu        $t1, $t1, $s2
    ctx->pc = 0x183e60u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 18)));
    // 0x183e64: 0x14e5021  addu        $t2, $t2, $t6
    ctx->pc = 0x183e64u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 14)));
    // 0x183e68: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x183e68u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x183e6c: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x183e6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x183e70: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x183e70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183e74: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x183e74u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x183e78: 0x31ef000f  andi        $t7, $t7, 0xF
    ctx->pc = 0x183e78u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) & (uint64_t)(uint16_t)15);
    // 0x183e7c: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x183e7cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x183e80: 0x31ad000f  andi        $t5, $t5, 0xF
    ctx->pc = 0x183e80u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 13) & (uint64_t)(uint16_t)15);
    // 0x183e84: 0x84040  sll         $t0, $t0, 1
    ctx->pc = 0x183e84u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x183e88: 0x318c000f  andi        $t4, $t4, 0xF
    ctx->pc = 0x183e88u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) & (uint64_t)(uint16_t)15);
    // 0x183e8c: 0x94840  sll         $t1, $t1, 1
    ctx->pc = 0x183e8cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
    // 0x183e90: 0xa5040  sll         $t2, $t2, 1
    ctx->pc = 0x183e90u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
    // 0x183e94: 0x6f1821  addu        $v1, $v1, $t7
    ctx->pc = 0x183e94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 15)));
    // 0x183e98: 0x10c4021  addu        $t0, $t0, $t4
    ctx->pc = 0x183e98u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 12)));
    // 0x183e9c: 0x12b4821  addu        $t1, $t1, $t3
    ctx->pc = 0x183e9cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 11)));
    // 0x183ea0: 0x244207d0  addiu       $v0, $v0, 0x7D0
    ctx->pc = 0x183ea0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2000));
    // 0x183ea4: 0xed3821  addu        $a3, $a3, $t5
    ctx->pc = 0x183ea4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 13)));
    // 0x183ea8: 0x1465021  addu        $t2, $t2, $a2
    ctx->pc = 0x183ea8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 6)));
    // 0x183eac: 0xa207000c  sb          $a3, 0xC($s0)
    ctx->pc = 0x183eacu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 12), (uint8_t)GPR_U32(ctx, 7));
    // 0x183eb0: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x183eb0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x183eb4: 0xa6150000  sh          $s5, 0x0($s0)
    ctx->pc = 0x183eb4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 21));
    // 0x183eb8: 0xa602000e  sh          $v0, 0xE($s0)
    ctx->pc = 0x183eb8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 14), (uint16_t)GPR_U32(ctx, 2));
    // 0x183ebc: 0xa203000d  sb          $v1, 0xD($s0)
    ctx->pc = 0x183ebcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 13), (uint8_t)GPR_U32(ctx, 3));
    // 0x183ec0: 0xa208000b  sb          $t0, 0xB($s0)
    ctx->pc = 0x183ec0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 11), (uint8_t)GPR_U32(ctx, 8));
    // 0x183ec4: 0xa209000a  sb          $t1, 0xA($s0)
    ctx->pc = 0x183ec4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 9));
    // 0x183ec8: 0xa20a0009  sb          $t2, 0x9($s0)
    ctx->pc = 0x183ec8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 9), (uint8_t)GPR_U32(ctx, 10));
    // 0x183ecc: 0xa6000002  sh          $zero, 0x2($s0)
    ctx->pc = 0x183eccu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 0));
    // 0x183ed0: 0xa2000008  sb          $zero, 0x8($s0)
    ctx->pc = 0x183ed0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 8), (uint8_t)GPR_U32(ctx, 0));
    // 0x183ed4: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x183ed4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x183ed8: 0x6a09000f  ldl         $t1, 0xF($s0)
    ctx->pc = 0x183ed8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem << shift)); }
    // 0x183edc: 0x6e090008  ldr         $t1, 0x8($s0)
    ctx->pc = 0x183edcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem >> shift)); }
    // 0x183ee0: 0xb209001f  sdl         $t1, 0x1F($s0)
    ctx->pc = 0x183ee0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x183ee4: 0xb6090018  sdr         $t1, 0x18($s0)
    ctx->pc = 0x183ee4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x183ee8: 0xae000010  sw          $zero, 0x10($s0)
    ctx->pc = 0x183ee8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
    // 0x183eec: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x183eecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x183ef0: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x183ef0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x183ef4: 0x26c817b8  addiu       $t0, $s6, 0x17B8
    ctx->pc = 0x183ef4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 22), 6072));
    // 0x183ef8: 0x85090000  lh          $t1, 0x0($t0)
    ctx->pc = 0x183ef8u;
    SET_GPR_S32(ctx, 9, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x183efc: 0x81020002  lb          $v0, 0x2($t0)
    ctx->pc = 0x183efcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 2)));
    // 0x183f00: 0xa6090040  sh          $t1, 0x40($s0)
    ctx->pc = 0x183f00u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 64), (uint16_t)GPR_U32(ctx, 9));
    // 0x183f04: 0xa2020042  sb          $v0, 0x42($s0)
    ctx->pc = 0x183f04u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 66), (uint8_t)GPR_U32(ctx, 2));
    // 0x183f08: 0xc061d24  jal         func_187490
    ctx->pc = 0x183F08u;
    SET_GPR_U32(ctx, 31, 0x183F10u);
    ctx->pc = 0x183F0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183F08u;
            // 0x183f0c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187490u;
    if (runtime->hasFunction(0x187490u)) {
        auto targetFn = runtime->lookupFunction(0x187490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183F10u; }
        if (ctx->pc != 0x183F10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187490_0x187490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183F10u; }
        if (ctx->pc != 0x183F10u) { return; }
    }
    ctx->pc = 0x183F10u;
label_183f10:
    // 0x183f10: 0x10400014  beqz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x183F10u;
    {
        const bool branch_taken_0x183f10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x183F14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183F10u;
            // 0x183f14: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183f10) {
            ctx->pc = 0x183F64u;
            goto label_183f64;
        }
    }
    ctx->pc = 0x183F18u;
    // 0x183f18: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x183f18u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183f1c: 0x2406ffff  addiu       $a2, $zero, -0x1
    ctx->pc = 0x183f1cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x183f20: 0xc060b28  jal         func_182CA0
    ctx->pc = 0x183F20u;
    SET_GPR_U32(ctx, 31, 0x183F28u);
    ctx->pc = 0x183F24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183F20u;
            // 0x183f24: 0x27a70020  addiu       $a3, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182CA0u;
    if (runtime->hasFunction(0x182CA0u)) {
        auto targetFn = runtime->lookupFunction(0x182CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183F28u; }
        if (ctx->pc != 0x183F28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182CA0_0x182ca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183F28u; }
        if (ctx->pc != 0x183F28u) { return; }
    }
    ctx->pc = 0x183F28u;
label_183f28:
    // 0x183f28: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x183f28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x183f2c: 0x1460001a  bnez        $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x183F2Cu;
    {
        const bool branch_taken_0x183f2c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x183F30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183F2Cu;
            // 0x183f30: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183f2c) {
            ctx->pc = 0x183F98u;
            goto label_183f98;
        }
    }
    ctx->pc = 0x183F34u;
    // 0x183f34: 0xc061bbc  jal         func_186EF0
    ctx->pc = 0x183F34u;
    SET_GPR_U32(ctx, 31, 0x183F3Cu);
    ctx->pc = 0x183F38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183F34u;
            // 0x183f38: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186EF0u;
    if (runtime->hasFunction(0x186EF0u)) {
        auto targetFn = runtime->lookupFunction(0x186EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183F3Cu; }
        if (ctx->pc != 0x183F3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186EF0_0x186ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183F3Cu; }
        if (ctx->pc != 0x183F3Cu) { return; }
    }
    ctx->pc = 0x183F3Cu;
label_183f3c:
    // 0x183f3c: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x183F3Cu;
    {
        const bool branch_taken_0x183f3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x183f3c) {
            ctx->pc = 0x183F64u;
            goto label_183f64;
        }
    }
    ctx->pc = 0x183F44u;
    // 0x183f44: 0xc060a84  jal         func_182A10
    ctx->pc = 0x183F44u;
    SET_GPR_U32(ctx, 31, 0x183F4Cu);
    ctx->pc = 0x183F48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183F44u;
            // 0x183f48: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182A10u;
    if (runtime->hasFunction(0x182A10u)) {
        auto targetFn = runtime->lookupFunction(0x182A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183F4Cu; }
        if (ctx->pc != 0x183F4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182A10_0x182a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183F4Cu; }
        if (ctx->pc != 0x183F4Cu) { return; }
    }
    ctx->pc = 0x183F4Cu;
label_183f4c:
    // 0x183f4c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x183F4Cu;
    {
        const bool branch_taken_0x183f4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x183f4c) {
            ctx->pc = 0x183F64u;
            goto label_183f64;
        }
    }
    ctx->pc = 0x183F54u;
    // 0x183f54: 0xc061b4c  jal         func_186D30
    ctx->pc = 0x183F54u;
    SET_GPR_U32(ctx, 31, 0x183F5Cu);
    ctx->pc = 0x183F58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183F54u;
            // 0x183f58: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186D30u;
    if (runtime->hasFunction(0x186D30u)) {
        auto targetFn = runtime->lookupFunction(0x186D30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183F5Cu; }
        if (ctx->pc != 0x183F5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186D30_0x186d30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183F5Cu; }
        if (ctx->pc != 0x183F5Cu) { return; }
    }
    ctx->pc = 0x183F5Cu;
label_183f5c:
    // 0x183f5c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x183F5Cu;
    {
        const bool branch_taken_0x183f5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x183F60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183F5Cu;
            // 0x183f60: 0x24030898  addiu       $v1, $zero, 0x898 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183f5c) {
            ctx->pc = 0x183F70u;
            goto label_183f70;
        }
    }
    ctx->pc = 0x183F64u;
label_183f64:
    // 0x183f64: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x183f64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x183f68: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x183F68u;
    {
        const bool branch_taken_0x183f68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x183F6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183F68u;
            // 0x183f6c: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x183f68) {
            ctx->pc = 0x183F98u;
            goto label_183f98;
        }
    }
    ctx->pc = 0x183F70u;
label_183f70:
    // 0x183f70: 0x3c090028  lui         $t1, 0x28
    ctx->pc = 0x183f70u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)40 << 16));
    // 0x183f74: 0x2e31818  mult        $v1, $s7, $v1
    ctx->pc = 0x183f74u;
    { int64_t result = (int64_t)GPR_S32(ctx, 23) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x183f78: 0x25245b48  addiu       $a0, $t1, 0x5B48
    ctx->pc = 0x183f78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), 23368));
    // 0x183f7c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x183f7cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x183f80: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x183f80u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183f84: 0x24630880  addiu       $v1, $v1, 0x880
    ctx->pc = 0x183f84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2176));
    // 0x183f88: 0x832821  addu        $a1, $a0, $v1
    ctx->pc = 0x183f88u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x183f8c: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x183f8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183f90: 0xac86000c  sw          $a2, 0xC($a0)
    ctx->pc = 0x183f90u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 6));
    // 0x183f94: 0xaca00008  sw          $zero, 0x8($a1)
    ctx->pc = 0x183f94u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 0));
label_183f98:
    // 0x183f98: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x183f98u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_183f9c:
    // 0x183f9c: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x183f9cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x183fa0: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x183fa0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x183fa4: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x183fa4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x183fa8: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x183fa8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x183fac: 0xdfb50058  ld          $s5, 0x58($sp)
    ctx->pc = 0x183facu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x183fb0: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x183fb0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x183fb4: 0xdfb70068  ld          $s7, 0x68($sp)
    ctx->pc = 0x183fb4u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x183fb8: 0xdfbe0070  ld          $fp, 0x70($sp)
    ctx->pc = 0x183fb8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x183fbc: 0xdfbf0078  ld          $ra, 0x78($sp)
    ctx->pc = 0x183fbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x183fc0: 0x3e00008  jr          $ra
    ctx->pc = 0x183FC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x183FC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183FC0u;
            // 0x183fc4: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1836C8u: goto label_1836c8;
            case 0x1836E0u: goto label_1836e0;
            case 0x183748u: goto label_183748;
            case 0x183758u: goto label_183758;
            case 0x183770u: goto label_183770;
            case 0x183780u: goto label_183780;
            case 0x1837ACu: goto label_1837ac;
            case 0x1837B4u: goto label_1837b4;
            case 0x1837C4u: goto label_1837c4;
            case 0x183810u: goto label_183810;
            case 0x183838u: goto label_183838;
            case 0x1838D0u: goto label_1838d0;
            case 0x1838D8u: goto label_1838d8;
            case 0x1838E4u: goto label_1838e4;
            case 0x1838F0u: goto label_1838f0;
            case 0x183904u: goto label_183904;
            case 0x183978u: goto label_183978;
            case 0x183990u: goto label_183990;
            case 0x1839A0u: goto label_1839a0;
            case 0x1839ACu: goto label_1839ac;
            case 0x1839D8u: goto label_1839d8;
            case 0x1839F8u: goto label_1839f8;
            case 0x183A30u: goto label_183a30;
            case 0x183A88u: goto label_183a88;
            case 0x183A94u: goto label_183a94;
            case 0x183ABCu: goto label_183abc;
            case 0x183AF0u: goto label_183af0;
            case 0x183B08u: goto label_183b08;
            case 0x183B20u: goto label_183b20;
            case 0x183B44u: goto label_183b44;
            case 0x183B4Cu: goto label_183b4c;
            case 0x183B64u: goto label_183b64;
            case 0x183BB8u: goto label_183bb8;
            case 0x183BCCu: goto label_183bcc;
            case 0x183BD4u: goto label_183bd4;
            case 0x183BF4u: goto label_183bf4;
            case 0x183C08u: goto label_183c08;
            case 0x183C10u: goto label_183c10;
            case 0x183C20u: goto label_183c20;
            case 0x183C34u: goto label_183c34;
            case 0x183C54u: goto label_183c54;
            case 0x183C5Cu: goto label_183c5c;
            case 0x183C7Cu: goto label_183c7c;
            case 0x183CA0u: goto label_183ca0;
            case 0x183CB0u: goto label_183cb0;
            case 0x183CC4u: goto label_183cc4;
            case 0x183CD4u: goto label_183cd4;
            case 0x183DF8u: goto label_183df8;
            case 0x183F10u: goto label_183f10;
            case 0x183F28u: goto label_183f28;
            case 0x183F3Cu: goto label_183f3c;
            case 0x183F4Cu: goto label_183f4c;
            case 0x183F5Cu: goto label_183f5c;
            case 0x183F64u: goto label_183f64;
            case 0x183F70u: goto label_183f70;
            case 0x183F98u: goto label_183f98;
            case 0x183F9Cu: goto label_183f9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x183FC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
