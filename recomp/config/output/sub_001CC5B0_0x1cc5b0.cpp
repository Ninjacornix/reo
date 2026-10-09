#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CC5B0
// Address: 0x1cc5b0 - 0x1cc740
void sub_001CC5B0_0x1cc5b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CC5B0_0x1cc5b0");
#endif

    switch (ctx->pc) {
        case 0x1cc5e8u: goto label_1cc5e8;
        case 0x1cc600u: goto label_1cc600;
        case 0x1cc614u: goto label_1cc614;
        case 0x1cc624u: goto label_1cc624;
        case 0x1cc63cu: goto label_1cc63c;
        case 0x1cc64cu: goto label_1cc64c;
        case 0x1cc668u: goto label_1cc668;
        case 0x1cc670u: goto label_1cc670;
        case 0x1cc6acu: goto label_1cc6ac;
        case 0x1cc6e4u: goto label_1cc6e4;
        case 0x1cc6f4u: goto label_1cc6f4;
        case 0x1cc700u: goto label_1cc700;
        default: break;
    }

    ctx->pc = 0x1cc5b0u;

    // 0x1cc5b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cc5b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cc5b4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc5b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc5b8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cc5b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cc5bc: 0x8c230a30  lw          $v1, 0xA30($at)
    ctx->pc = 0x1cc5bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc5c0: 0x1060005a  beqz        $v1, . + 4 + (0x5A << 2)
    ctx->pc = 0x1CC5C0u;
    {
        const bool branch_taken_0x1cc5c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cc5c0) {
            ctx->pc = 0x1CC72Cu;
            goto label_1cc72c;
        }
    }
    ctx->pc = 0x1CC5C8u;
    // 0x1cc5c8: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x1cc5c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x1cc5cc: 0x1440001b  bnez        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1CC5CCu;
    {
        const bool branch_taken_0x1cc5cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cc5cc) {
            ctx->pc = 0x1CC63Cu;
            goto label_1cc63c;
        }
    }
    ctx->pc = 0x1CC5D4u;
    // 0x1cc5d4: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x1cc5d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1cc5d8: 0x8c640028  lw          $a0, 0x28($v1)
    ctx->pc = 0x1cc5d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 40)));
    // 0x1cc5dc: 0x8c660008  lw          $a2, 0x8($v1)
    ctx->pc = 0x1cc5dcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1cc5e0: 0xc0731d0  jal         func_1CC740
    ctx->pc = 0x1CC5E0u;
    SET_GPR_U32(ctx, 31, 0x1CC5E8u);
    ctx->pc = 0x1CC5E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC5E0u;
            // 0x1cc5e4: 0x24450010  addiu       $a1, $v0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC740u;
    if (runtime->hasFunction(0x1CC740u)) {
        auto targetFn = runtime->lookupFunction(0x1CC740u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC5E8u; }
        if (ctx->pc != 0x1CC5E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC740_0x1cc740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC5E8u; }
        if (ctx->pc != 0x1CC5E8u) { return; }
    }
    ctx->pc = 0x1CC5E8u;
label_1cc5e8:
    // 0x1cc5e8: 0x3c024000  lui         $v0, 0x4000
    ctx->pc = 0x1cc5e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16384 << 16));
    // 0x1cc5ec: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x1cc5ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x1cc5f0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1cc5f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc5f4: 0xac222010  sw          $v0, 0x2010($at)
    ctx->pc = 0x1cc5f4u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8208), GPR_U32(ctx, 2)); // MMIO: 0x10002010
    // 0x1cc5f8: 0xc044fb4  jal         func_113ED0
    ctx->pc = 0x1CC5F8u;
    SET_GPR_U32(ctx, 31, 0x1CC600u);
    ctx->pc = 0x1CC5FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC5F8u;
            // 0x1cc5fc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113ED0u;
    if (runtime->hasFunction(0x113ED0u)) {
        auto targetFn = runtime->lookupFunction(0x113ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC600u; }
        if (ctx->pc != 0x1CC600u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113ED0_0x113ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC600u; }
        if (ctx->pc != 0x1CC600u) { return; }
    }
    ctx->pc = 0x1CC600u;
label_1cc600:
    // 0x1cc600: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x1cc600u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x1cc604: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1cc604u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc608: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cc608u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc60c: 0xc044fb4  jal         func_113ED0
    ctx->pc = 0x1CC60Cu;
    SET_GPR_U32(ctx, 31, 0x1CC614u);
    ctx->pc = 0x1CC610u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC60Cu;
            // 0x1cc610: 0xac202000  sw          $zero, 0x2000($at) (Delay Slot)
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8192), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113ED0u;
    if (runtime->hasFunction(0x113ED0u)) {
        auto targetFn = runtime->lookupFunction(0x113ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC614u; }
        if (ctx->pc != 0x1CC614u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113ED0_0x113ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC614u; }
        if (ctx->pc != 0x1CC614u) { return; }
    }
    ctx->pc = 0x1CC614u;
label_1cc614:
    // 0x1cc614: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc614u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc618: 0x8c220a30  lw          $v0, 0xA30($at)
    ctx->pc = 0x1cc618u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc61c: 0xc0731f8  jal         func_1CC7E0
    ctx->pc = 0x1CC61Cu;
    SET_GPR_U32(ctx, 31, 0x1CC624u);
    ctx->pc = 0x1CC620u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC61Cu;
            // 0x1cc620: 0x8c440028  lw          $a0, 0x28($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC7E0u;
    if (runtime->hasFunction(0x1CC7E0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC7E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC624u; }
        if (ctx->pc != 0x1CC624u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC7E0_0x1cc7e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC624u; }
        if (ctx->pc != 0x1CC624u) { return; }
    }
    ctx->pc = 0x1CC624u;
label_1cc624:
    // 0x1cc624: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x1cc624u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x1cc628: 0xac202010  sw          $zero, 0x2010($at)
    ctx->pc = 0x1cc628u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8208), GPR_U32(ctx, 0)); // MMIO: 0x10002010
    // 0x1cc62c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc62cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc630: 0x8c220a30  lw          $v0, 0xA30($at)
    ctx->pc = 0x1cc630u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc634: 0xc044f26  jal         func_113C98
    ctx->pc = 0x1CC634u;
    SET_GPR_U32(ctx, 31, 0x1CC63Cu);
    ctx->pc = 0x1CC638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC634u;
            // 0x1cc638: 0x24440040  addiu       $a0, $v0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113C98u;
    if (runtime->hasFunction(0x113C98u)) {
        auto targetFn = runtime->lookupFunction(0x113C98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC63Cu; }
        if (ctx->pc != 0x1CC63Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113C98_0x113c98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC63Cu; }
        if (ctx->pc != 0x1CC63Cu) { return; }
    }
    ctx->pc = 0x1CC63Cu;
label_1cc63c:
    // 0x1cc63c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc63cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc640: 0x8c220a30  lw          $v0, 0xA30($at)
    ctx->pc = 0x1cc640u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc644: 0xc044f60  jal         func_113D80
    ctx->pc = 0x1CC644u;
    SET_GPR_U32(ctx, 31, 0x1CC64Cu);
    ctx->pc = 0x1CC648u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC644u;
            // 0x1cc648: 0x24440040  addiu       $a0, $v0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113D80u;
    if (runtime->hasFunction(0x113D80u)) {
        auto targetFn = runtime->lookupFunction(0x113D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC64Cu; }
        if (ctx->pc != 0x1CC64Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113D80_0x113d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC64Cu; }
        if (ctx->pc != 0x1CC64Cu) { return; }
    }
    ctx->pc = 0x1CC64Cu;
label_1cc64c:
    // 0x1cc64c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc64cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc650: 0x8c240a30  lw          $a0, 0xA30($at)
    ctx->pc = 0x1cc650u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc654: 0x8c83001c  lw          $v1, 0x1C($a0)
    ctx->pc = 0x1cc654u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x1cc658: 0x8c820020  lw          $v0, 0x20($a0)
    ctx->pc = 0x1cc658u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x1cc65c: 0x8c84002c  lw          $a0, 0x2C($a0)
    ctx->pc = 0x1cc65cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
    // 0x1cc660: 0xc073200  jal         func_1CC800
    ctx->pc = 0x1CC660u;
    SET_GPR_U32(ctx, 31, 0x1CC668u);
    ctx->pc = 0x1CC664u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC660u;
            // 0x1cc664: 0x622818  mult        $a1, $v1, $v0 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC800u;
    if (runtime->hasFunction(0x1CC800u)) {
        auto targetFn = runtime->lookupFunction(0x1CC800u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC668u; }
        if (ctx->pc != 0x1CC668u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC800_0x1cc800(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC668u; }
        if (ctx->pc != 0x1CC668u) { return; }
    }
    ctx->pc = 0x1CC668u;
label_1cc668:
    // 0x1cc668: 0xc07320c  jal         func_1CC830
    ctx->pc = 0x1CC668u;
    SET_GPR_U32(ctx, 31, 0x1CC670u);
    ctx->pc = 0x1CC830u;
    if (runtime->hasFunction(0x1CC830u)) {
        auto targetFn = runtime->lookupFunction(0x1CC830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC670u; }
        if (ctx->pc != 0x1CC670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC830_0x1cc830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC670u; }
        if (ctx->pc != 0x1CC670u) { return; }
    }
    ctx->pc = 0x1CC670u;
label_1cc670:
    // 0x1cc670: 0x2404fffb  addiu       $a0, $zero, -0x5
    ctx->pc = 0x1cc670u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967291));
    // 0x1cc674: 0x21882  srl         $v1, $v0, 2
    ctx->pc = 0x1cc674u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1cc678: 0x442024  and         $a0, $v0, $a0
    ctx->pc = 0x1cc678u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x1cc67c: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x1cc67cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x1cc680: 0x30620001  andi        $v0, $v1, 0x1
    ctx->pc = 0x1cc680u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x1cc684: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x1cc684u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x1cc688: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1cc688u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1cc68c: 0xac242010  sw          $a0, 0x2010($at)
    ctx->pc = 0x1cc68cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8208), GPR_U32(ctx, 4)); // MMIO: 0x10002010
    // 0x1cc690: 0x3c021001  lui         $v0, 0x1001
    ctx->pc = 0x1cc690u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4097 << 16));
    // 0x1cc694: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x1cc694u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x1cc698: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1cc698u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1cc69c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1cc69cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc6a0: 0xac222000  sw          $v0, 0x2000($at)
    ctx->pc = 0x1cc6a0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8192), GPR_U32(ctx, 2)); // MMIO: 0x10002000
    // 0x1cc6a4: 0xc044fb4  jal         func_113ED0
    ctx->pc = 0x1CC6A4u;
    SET_GPR_U32(ctx, 31, 0x1CC6ACu);
    ctx->pc = 0x1CC6A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC6A4u;
            // 0x1cc6a8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113ED0u;
    if (runtime->hasFunction(0x113ED0u)) {
        auto targetFn = runtime->lookupFunction(0x113ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC6ACu; }
        if (ctx->pc != 0x1CC6ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113ED0_0x113ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC6ACu; }
        if (ctx->pc != 0x1CC6ACu) { return; }
    }
    ctx->pc = 0x1CC6ACu;
label_1cc6ac:
    // 0x1cc6ac: 0x3c011001  lui         $at, 0x1001
    ctx->pc = 0x1cc6acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4097 << 16));
    // 0x1cc6b0: 0x8c22b000  lw          $v0, -0x5000($at)
    ctx->pc = 0x1cc6b0u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294946816))); // MMIO: 0x1000b000
    // 0x1cc6b4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1cc6b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1cc6b8: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x1cc6b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1cc6bc: 0x0  nop
    ctx->pc = 0x1cc6bcu;
    // NOP
    // 0x1cc6c0: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1CC6C0u;
    {
        const bool branch_taken_0x1cc6c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cc6c0) {
            ctx->pc = 0x1CC6ACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cc6ac;
        }
    }
    ctx->pc = 0x1CC6C8u;
    // 0x1cc6c8: 0x3c024000  lui         $v0, 0x4000
    ctx->pc = 0x1cc6c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16384 << 16));
    // 0x1cc6cc: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x1cc6ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x1cc6d0: 0x34420020  ori         $v0, $v0, 0x20
    ctx->pc = 0x1cc6d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32);
    // 0x1cc6d4: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1cc6d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc6d8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cc6d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc6dc: 0xc044fb4  jal         func_113ED0
    ctx->pc = 0x1CC6DCu;
    SET_GPR_U32(ctx, 31, 0x1CC6E4u);
    ctx->pc = 0x1CC6E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC6DCu;
            // 0x1cc6e0: 0xac222000  sw          $v0, 0x2000($at) (Delay Slot)
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8192), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113ED0u;
    if (runtime->hasFunction(0x113ED0u)) {
        auto targetFn = runtime->lookupFunction(0x113ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC6E4u; }
        if (ctx->pc != 0x1CC6E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113ED0_0x113ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC6E4u; }
        if (ctx->pc != 0x1CC6E4u) { return; }
    }
    ctx->pc = 0x1CC6E4u;
label_1cc6e4:
    // 0x1cc6e4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc6e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc6e8: 0x8c220a30  lw          $v0, 0xA30($at)
    ctx->pc = 0x1cc6e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc6ec: 0xc044f26  jal         func_113C98
    ctx->pc = 0x1CC6ECu;
    SET_GPR_U32(ctx, 31, 0x1CC6F4u);
    ctx->pc = 0x1CC6F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC6ECu;
            // 0x1cc6f0: 0x24440040  addiu       $a0, $v0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113C98u;
    if (runtime->hasFunction(0x113C98u)) {
        auto targetFn = runtime->lookupFunction(0x113C98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC6F4u; }
        if (ctx->pc != 0x1CC6F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113C98_0x113c98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC6F4u; }
        if (ctx->pc != 0x1CC6F4u) { return; }
    }
    ctx->pc = 0x1CC6F4u;
label_1cc6f4:
    // 0x1cc6f4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc6f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc6f8: 0xc073228  jal         func_1CC8A0
    ctx->pc = 0x1CC6F8u;
    SET_GPR_U32(ctx, 31, 0x1CC700u);
    ctx->pc = 0x1CC6FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC6F8u;
            // 0x1cc6fc: 0x8c240a30  lw          $a0, 0xA30($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8A0u;
    if (runtime->hasFunction(0x1CC8A0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC700u; }
        if (ctx->pc != 0x1CC700u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8A0_0x1cc8a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC700u; }
        if (ctx->pc != 0x1CC700u) { return; }
    }
    ctx->pc = 0x1CC700u;
label_1cc700:
    // 0x1cc700: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc700u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc704: 0x8c250a30  lw          $a1, 0xA30($at)
    ctx->pc = 0x1cc704u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc708: 0x8ca30018  lw          $v1, 0x18($a1)
    ctx->pc = 0x1cc708u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x1cc70c: 0x24640001  addiu       $a0, $v1, 0x1
    ctx->pc = 0x1cc70cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1cc710: 0xaca40018  sw          $a0, 0x18($a1)
    ctx->pc = 0x1cc710u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 24), GPR_U32(ctx, 4));
    // 0x1cc714: 0x8ca30014  lw          $v1, 0x14($a1)
    ctx->pc = 0x1cc714u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x1cc718: 0x83182b  sltu        $v1, $a0, $v1
    ctx->pc = 0x1cc718u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1cc71c: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CC71Cu;
    {
        const bool branch_taken_0x1cc71c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CC720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC71Cu;
            // 0x1cc720: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cc71c) {
            ctx->pc = 0x1CC72Cu;
            goto label_1cc72c;
        }
    }
    ctx->pc = 0x1CC724u;
    // 0x1cc724: 0x8c230a30  lw          $v1, 0xA30($at)
    ctx->pc = 0x1cc724u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc728: 0xac600018  sw          $zero, 0x18($v1)
    ctx->pc = 0x1cc728u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 24), GPR_U32(ctx, 0));
label_1cc72c:
    // 0x1cc72c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cc72cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cc730: 0x3e00008  jr          $ra
    ctx->pc = 0x1CC730u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CC734u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC730u;
            // 0x1cc734: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CC5E8u: goto label_1cc5e8;
            case 0x1CC600u: goto label_1cc600;
            case 0x1CC614u: goto label_1cc614;
            case 0x1CC624u: goto label_1cc624;
            case 0x1CC63Cu: goto label_1cc63c;
            case 0x1CC64Cu: goto label_1cc64c;
            case 0x1CC668u: goto label_1cc668;
            case 0x1CC670u: goto label_1cc670;
            case 0x1CC6ACu: goto label_1cc6ac;
            case 0x1CC6E4u: goto label_1cc6e4;
            case 0x1CC6F4u: goto label_1cc6f4;
            case 0x1CC700u: goto label_1cc700;
            case 0x1CC72Cu: goto label_1cc72c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CC738u;
    // 0x1cc738: 0x0  nop
    ctx->pc = 0x1cc738u;
    // NOP
    // 0x1cc73c: 0x0  nop
    ctx->pc = 0x1cc73cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
