#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001715F0
// Address: 0x1715f0 - 0x171808
void sub_001715F0_0x1715f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001715F0_0x1715f0");
#endif

    switch (ctx->pc) {
        case 0x1716e0u: goto label_1716e0;
        case 0x1716f8u: goto label_1716f8;
        case 0x171710u: goto label_171710;
        case 0x171728u: goto label_171728;
        case 0x171740u: goto label_171740;
        case 0x171758u: goto label_171758;
        case 0x171768u: goto label_171768;
        case 0x171788u: goto label_171788;
        case 0x171790u: goto label_171790;
        case 0x171798u: goto label_171798;
        default: break;
    }

    ctx->pc = 0x1715f0u;

    // 0x1715f0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1715f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1715f4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1715f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1715f8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1715f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1715fc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1715fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x171600: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x171600u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171604: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x171604u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x171608: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x171608u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x17160c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17160cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x171610: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x171610u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x171614: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x171614u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x171618: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x171618u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x17161c: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x17161cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x171620: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x171620u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x171624: 0x8c43f1c0  lw          $v1, -0xE40($v0)
    ctx->pc = 0x171624u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294963648)));
    // 0x171628: 0x8e451b30  lw          $a1, 0x1B30($s2)
    ctx->pc = 0x171628u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 6960)));
    // 0x17162c: 0x24a60004  addiu       $a2, $a1, 0x4
    ctx->pc = 0x17162cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x171630: 0x24b109d8  addiu       $s1, $a1, 0x9D8
    ctx->pc = 0x171630u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), 2520));
    // 0x171634: 0x24b30a00  addiu       $s3, $a1, 0xA00
    ctx->pc = 0x171634u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 5), 2560));
    // 0x171638: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x171638u;
    {
        const bool branch_taken_0x171638 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x17163Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171638u;
            // 0x17163c: 0x24be0aa8  addiu       $fp, $a1, 0xAA8 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 5), 2728));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171638) {
            ctx->pc = 0x171648u;
            goto label_171648;
        }
    }
    ctx->pc = 0x171640u;
    // 0x171640: 0x10000064  b           . + 4 + (0x64 << 2)
    ctx->pc = 0x171640u;
    {
        const bool branch_taken_0x171640 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x171644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171640u;
            // 0x171644: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171640) {
            ctx->pc = 0x1717D4u;
            goto label_1717d4;
        }
    }
    ctx->pc = 0x171648u;
label_171648:
    // 0x171648: 0x8cc4000c  lw          $a0, 0xC($a2)
    ctx->pc = 0x171648u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 12)));
    // 0x17164c: 0x8cc30008  lw          $v1, 0x8($a2)
    ctx->pc = 0x17164cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x171650: 0x8ca70028  lw          $a3, 0x28($a1)
    ctx->pc = 0x171650u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 40)));
    // 0x171654: 0x641818  mult        $v1, $v1, $a0
    ctx->pc = 0x171654u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x171658: 0x310c0  sll         $v0, $v1, 3
    ctx->pc = 0x171658u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x17165c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x17165cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x171660: 0x227c2  srl         $a0, $v0, 31
    ctx->pc = 0x171660u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x171664: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x171664u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x171668: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x171668u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x17166c: 0x14e0000a  bnez        $a3, . + 4 + (0xA << 2)
    ctx->pc = 0x17166Cu;
    {
        const bool branch_taken_0x17166c = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x171670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17166Cu;
            // 0x171670: 0x24542800  addiu       $s4, $v0, 0x2800 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 10240));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17166c) {
            ctx->pc = 0x171698u;
            goto label_171698;
        }
    }
    ctx->pc = 0x171674u;
    // 0x171674: 0x8cc20010  lw          $v0, 0x10($a2)
    ctx->pc = 0x171674u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x171678: 0x2404ffc0  addiu       $a0, $zero, -0x40
    ctx->pc = 0x171678u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x17167c: 0x2442003f  addiu       $v0, $v0, 0x3F
    ctx->pc = 0x17167cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 63));
    // 0x171680: 0x441024  and         $v0, $v0, $a0
    ctx->pc = 0x171680u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x171684: 0x541821  addu        $v1, $v0, $s4
    ctx->pc = 0x171684u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 20)));
    // 0x171688: 0xaca20028  sw          $v0, 0x28($a1)
    ctx->pc = 0x171688u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 40), GPR_U32(ctx, 2));
    // 0x17168c: 0x2463003f  addiu       $v1, $v1, 0x3F
    ctx->pc = 0x17168cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 63));
    // 0x171690: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x171690u;
    {
        const bool branch_taken_0x171690 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x171694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171690u;
            // 0x171694: 0x641024  and         $v0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171690) {
            ctx->pc = 0x1716B4u;
            goto label_1716b4;
        }
    }
    ctx->pc = 0x171698u;
label_171698:
    // 0x171698: 0x8ca2002c  lw          $v0, 0x2C($a1)
    ctx->pc = 0x171698u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 44)));
    // 0x17169c: 0x2404ffc0  addiu       $a0, $zero, -0x40
    ctx->pc = 0x17169cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1716a0: 0x24e3003f  addiu       $v1, $a3, 0x3F
    ctx->pc = 0x1716a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 63));
    // 0x1716a4: 0x2442003f  addiu       $v0, $v0, 0x3F
    ctx->pc = 0x1716a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 63));
    // 0x1716a8: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x1716a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x1716ac: 0x441024  and         $v0, $v0, $a0
    ctx->pc = 0x1716acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x1716b0: 0xaca30028  sw          $v1, 0x28($a1)
    ctx->pc = 0x1716b0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 40), GPR_U32(ctx, 3));
label_1716b4:
    // 0x1716b4: 0xaca2002c  sw          $v0, 0x2C($a1)
    ctx->pc = 0x1716b4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 44), GPR_U32(ctx, 2));
    // 0x1716b8: 0x8cb6002c  lw          $s6, 0x2C($a1)
    ctx->pc = 0x1716b8u;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 44)));
    // 0x1716bc: 0x2404ffc0  addiu       $a0, $zero, -0x40
    ctx->pc = 0x1716bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1716c0: 0x8cb00028  lw          $s0, 0x28($a1)
    ctx->pc = 0x1716c0u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 40)));
    // 0x1716c4: 0x3c020008  lui         $v0, 0x8
    ctx->pc = 0x1716c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8 << 16));
    // 0x1716c8: 0x3442003f  ori         $v0, $v0, 0x3F
    ctx->pc = 0x1716c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)63);
    // 0x1716cc: 0x561021  addu        $v0, $v0, $s6
    ctx->pc = 0x1716ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 22)));
    // 0x1716d0: 0x44a824  and         $s5, $v0, $a0
    ctx->pc = 0x1716d0u;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x1716d4: 0x26a3104f  addiu       $v1, $s5, 0x104F
    ctx->pc = 0x1716d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 4175));
    // 0x1716d8: 0xc05cf00  jal         func_173C00
    ctx->pc = 0x1716D8u;
    SET_GPR_U32(ctx, 31, 0x1716E0u);
    ctx->pc = 0x1716DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1716D8u;
            // 0x1716dc: 0x64b824  and         $s7, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 23, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173C00u;
    if (runtime->hasFunction(0x173C00u)) {
        auto targetFn = runtime->lookupFunction(0x173C00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1716E0u; }
        if (ctx->pc != 0x1716E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173C00_0x173c00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1716E0u; }
        if (ctx->pc != 0x1716E0u) { return; }
    }
    ctx->pc = 0x1716E0u;
label_1716e0:
    // 0x1716e0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1716e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1716e4: 0x1043001e  beq         $v0, $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x1716E4u;
    {
        const bool branch_taken_0x1716e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1716E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1716E4u;
            // 0x1716e8: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1716e4) {
            ctx->pc = 0x171760u;
            goto label_171760;
        }
    }
    ctx->pc = 0x1716ECu;
    // 0x1716ec: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x1716ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1716f0: 0xc051eb6  jal         func_147AD8
    ctx->pc = 0x1716F0u;
    SET_GPR_U32(ctx, 31, 0x1716F8u);
    ctx->pc = 0x1716F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1716F0u;
            // 0x1716f4: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147AD8u;
    if (runtime->hasFunction(0x147AD8u)) {
        auto targetFn = runtime->lookupFunction(0x147AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1716F8u; }
        if (ctx->pc != 0x1716F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147AD8_0x147ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1716F8u; }
        if (ctx->pc != 0x1716F8u) { return; }
    }
    ctx->pc = 0x1716F8u;
label_1716f8:
    // 0x1716f8: 0x3c060017  lui         $a2, 0x17
    ctx->pc = 0x1716f8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)23 << 16));
    // 0x1716fc: 0x24c61818  addiu       $a2, $a2, 0x1818
    ctx->pc = 0x1716fcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 6168));
    // 0x171700: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x171700u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171704: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x171704u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171708: 0xc051fcc  jal         func_147F30
    ctx->pc = 0x171708u;
    SET_GPR_U32(ctx, 31, 0x171710u);
    ctx->pc = 0x17170Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171708u;
            // 0x17170c: 0x240382d  daddu       $a3, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147F30u;
    if (runtime->hasFunction(0x147F30u)) {
        auto targetFn = runtime->lookupFunction(0x147F30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171710u; }
        if (ctx->pc != 0x171710u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F30_0x147f30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171710u; }
        if (ctx->pc != 0x171710u) { return; }
    }
    ctx->pc = 0x171710u;
label_171710:
    // 0x171710: 0x3c060017  lui         $a2, 0x17
    ctx->pc = 0x171710u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)23 << 16));
    // 0x171714: 0x24c61920  addiu       $a2, $a2, 0x1920
    ctx->pc = 0x171714u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 6432));
    // 0x171718: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x171718u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17171c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x17171cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x171720: 0xc051fcc  jal         func_147F30
    ctx->pc = 0x171720u;
    SET_GPR_U32(ctx, 31, 0x171728u);
    ctx->pc = 0x171724u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171720u;
            // 0x171724: 0x240382d  daddu       $a3, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147F30u;
    if (runtime->hasFunction(0x147F30u)) {
        auto targetFn = runtime->lookupFunction(0x147F30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171728u; }
        if (ctx->pc != 0x171728u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F30_0x147f30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171728u; }
        if (ctx->pc != 0x171728u) { return; }
    }
    ctx->pc = 0x171728u;
label_171728:
    // 0x171728: 0x3c060017  lui         $a2, 0x17
    ctx->pc = 0x171728u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)23 << 16));
    // 0x17172c: 0x24c619a0  addiu       $a2, $a2, 0x19A0
    ctx->pc = 0x17172cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 6560));
    // 0x171730: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x171730u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171734: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x171734u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x171738: 0xc051fcc  jal         func_147F30
    ctx->pc = 0x171738u;
    SET_GPR_U32(ctx, 31, 0x171740u);
    ctx->pc = 0x17173Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171738u;
            // 0x17173c: 0x240382d  daddu       $a3, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147F30u;
    if (runtime->hasFunction(0x147F30u)) {
        auto targetFn = runtime->lookupFunction(0x147F30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171740u; }
        if (ctx->pc != 0x171740u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F30_0x147f30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171740u; }
        if (ctx->pc != 0x171740u) { return; }
    }
    ctx->pc = 0x171740u;
label_171740:
    // 0x171740: 0x3c060017  lui         $a2, 0x17
    ctx->pc = 0x171740u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)23 << 16));
    // 0x171744: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x171744u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171748: 0x24c619c8  addiu       $a2, $a2, 0x19C8
    ctx->pc = 0x171748u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 6600));
    // 0x17174c: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x17174cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171750: 0xc051fcc  jal         func_147F30
    ctx->pc = 0x171750u;
    SET_GPR_U32(ctx, 31, 0x171758u);
    ctx->pc = 0x171754u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171750u;
            // 0x171754: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147F30u;
    if (runtime->hasFunction(0x147F30u)) {
        auto targetFn = runtime->lookupFunction(0x147F30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171758u; }
        if (ctx->pc != 0x171758u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F30_0x147f30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171758u; }
        if (ctx->pc != 0x171758u) { return; }
    }
    ctx->pc = 0x171758u;
label_171758:
    // 0x171758: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x171758u;
    {
        const bool branch_taken_0x171758 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17175Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171758u;
            // 0x17175c: 0x26300070  addiu       $s0, $s1, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 112));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171758) {
            ctx->pc = 0x17176Cu;
            goto label_17176c;
        }
    }
    ctx->pc = 0x171760u;
label_171760:
    // 0x171760: 0xc05c6a8  jal         func_171AA0
    ctx->pc = 0x171760u;
    SET_GPR_U32(ctx, 31, 0x171768u);
    ctx->pc = 0x171764u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171760u;
            // 0x171764: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171AA0u;
    if (runtime->hasFunction(0x171AA0u)) {
        auto targetFn = runtime->lookupFunction(0x171AA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171768u; }
        if (ctx->pc != 0x171768u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171AA0_0x171aa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171768u; }
        if (ctx->pc != 0x171768u) { return; }
    }
    ctx->pc = 0x171768u;
label_171768:
    // 0x171768: 0x26300070  addiu       $s0, $s1, 0x70
    ctx->pc = 0x171768u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 112));
label_17176c:
    // 0x17176c: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x17176cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171770: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x171770u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171774: 0x2e0402d  daddu       $t0, $s7, $zero
    ctx->pc = 0x171774u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171778: 0x24070100  addiu       $a3, $zero, 0x100
    ctx->pc = 0x171778u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x17177c: 0x24090200  addiu       $t1, $zero, 0x200
    ctx->pc = 0x17177cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x171780: 0xc05c2ba  jal         func_170AE8
    ctx->pc = 0x171780u;
    SET_GPR_U32(ctx, 31, 0x171788u);
    ctx->pc = 0x171784u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171780u;
            // 0x171784: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170AE8u;
    if (runtime->hasFunction(0x170AE8u)) {
        auto targetFn = runtime->lookupFunction(0x170AE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171788u; }
        if (ctx->pc != 0x171788u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170AE8_0x170ae8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171788u; }
        if (ctx->pc != 0x171788u) { return; }
    }
    ctx->pc = 0x171788u;
label_171788:
    // 0x171788: 0xc05c398  jal         func_170E60
    ctx->pc = 0x171788u;
    SET_GPR_U32(ctx, 31, 0x171790u);
    ctx->pc = 0x17178Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171788u;
            // 0x17178c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170E60u;
    if (runtime->hasFunction(0x170E60u)) {
        auto targetFn = runtime->lookupFunction(0x170E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171790u; }
        if (ctx->pc != 0x171790u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170E60_0x170e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171790u; }
        if (ctx->pc != 0x171790u) { return; }
    }
    ctx->pc = 0x171790u;
label_171790:
    // 0x171790: 0xc05c418  jal         func_171060
    ctx->pc = 0x171790u;
    SET_GPR_U32(ctx, 31, 0x171798u);
    ctx->pc = 0x171794u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171790u;
            // 0x171794: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171060u;
    if (runtime->hasFunction(0x171060u)) {
        auto targetFn = runtime->lookupFunction(0x171060u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171798u; }
        if (ctx->pc != 0x171798u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171060_0x171060(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171798u; }
        if (ctx->pc != 0x171798u) { return; }
    }
    ctx->pc = 0x171798u;
label_171798:
    // 0x171798: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x171798u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17179c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x17179cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1717a0: 0xa2200010  sb          $zero, 0x10($s1)
    ctx->pc = 0x1717a0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 16), (uint8_t)GPR_U32(ctx, 0));
    // 0x1717a4: 0xa2200011  sb          $zero, 0x11($s1)
    ctx->pc = 0x1717a4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 17), (uint8_t)GPR_U32(ctx, 0));
    // 0x1717a8: 0xa2200012  sb          $zero, 0x12($s1)
    ctx->pc = 0x1717a8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0x1717ac: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1717acu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x1717b0: 0xae200020  sw          $zero, 0x20($s1)
    ctx->pc = 0x1717b0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 32), GPR_U32(ctx, 0));
    // 0x1717b4: 0xafc20000  sw          $v0, 0x0($fp)
    ctx->pc = 0x1717b4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
    // 0x1717b8: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1717b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
    // 0x1717bc: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x1717bcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
    // 0x1717c0: 0xae200008  sw          $zero, 0x8($s1)
    ctx->pc = 0x1717c0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
    // 0x1717c4: 0xae20000c  sw          $zero, 0xC($s1)
    ctx->pc = 0x1717c4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 0));
    // 0x1717c8: 0xae200014  sw          $zero, 0x14($s1)
    ctx->pc = 0x1717c8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 0));
    // 0x1717cc: 0xae200018  sw          $zero, 0x18($s1)
    ctx->pc = 0x1717ccu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 0));
    // 0x1717d0: 0xae20001c  sw          $zero, 0x1C($s1)
    ctx->pc = 0x1717d0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 28), GPR_U32(ctx, 0));
label_1717d4:
    // 0x1717d4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1717d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1717d8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1717d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1717dc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1717dcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1717e0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1717e0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1717e4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1717e4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1717e8: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1717e8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1717ec: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x1717ecu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1717f0: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x1717f0u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1717f4: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x1717f4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1717f8: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x1717f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1717fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1717FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x171800u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1717FCu;
            // 0x171800: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x171648u: goto label_171648;
            case 0x171698u: goto label_171698;
            case 0x1716B4u: goto label_1716b4;
            case 0x1716E0u: goto label_1716e0;
            case 0x1716F8u: goto label_1716f8;
            case 0x171710u: goto label_171710;
            case 0x171728u: goto label_171728;
            case 0x171740u: goto label_171740;
            case 0x171758u: goto label_171758;
            case 0x171760u: goto label_171760;
            case 0x171768u: goto label_171768;
            case 0x17176Cu: goto label_17176c;
            case 0x171788u: goto label_171788;
            case 0x171790u: goto label_171790;
            case 0x171798u: goto label_171798;
            case 0x1717D4u: goto label_1717d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x171804u;
    // 0x171804: 0x0  nop
    ctx->pc = 0x171804u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
