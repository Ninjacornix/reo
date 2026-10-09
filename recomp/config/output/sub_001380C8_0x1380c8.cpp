#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001380C8
// Address: 0x1380c8 - 0x138208
void sub_001380C8_0x1380c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001380C8_0x1380c8");
#endif

    switch (ctx->pc) {
        case 0x1380e8u: goto label_1380e8;
        case 0x138130u: goto label_138130;
        case 0x138144u: goto label_138144;
        case 0x13815cu: goto label_13815c;
        case 0x138174u: goto label_138174;
        case 0x138194u: goto label_138194;
        case 0x1381b8u: goto label_1381b8;
        case 0x1381c0u: goto label_1381c0;
        case 0x1381d0u: goto label_1381d0;
        default: break;
    }

    ctx->pc = 0x1380c8u;

label_1380c8:
    // 0x1380c8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1380c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x1380cc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1380ccu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1380d0: 0x8044bb89  lb          $a0, -0x4477($v0)
    ctx->pc = 0x1380d0u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294949769)));
    // 0x1380d4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1380d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1380d8: 0x14830005  bne         $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1380D8u;
    {
        const bool branch_taken_0x1380d8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x1380DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1380D8u;
            // 0x1380dc: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1380d8) {
            ctx->pc = 0x1380F0u;
            goto label_1380f0;
        }
    }
    ctx->pc = 0x1380E0u;
    // 0x1380e0: 0xc04dffa  jal         func_137FE8
    ctx->pc = 0x1380E0u;
    SET_GPR_U32(ctx, 31, 0x1380E8u);
    ctx->pc = 0x137FE8u;
    if (runtime->hasFunction(0x137FE8u)) {
        auto targetFn = runtime->lookupFunction(0x137FE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1380E8u; }
        if (ctx->pc != 0x1380E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137FE8_0x137fe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1380E8u; }
        if (ctx->pc != 0x1380E8u) { return; }
    }
    ctx->pc = 0x1380E8u;
label_1380e8:
    // 0x1380e8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1380E8u;
    {
        const bool branch_taken_0x1380e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1380ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1380E8u;
            // 0x1380ec: 0x21040  sll         $v0, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1380e8) {
            ctx->pc = 0x138108u;
            goto label_138108;
        }
    }
    ctx->pc = 0x1380F0u;
label_1380f0:
    // 0x1380f0: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1380f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1380f4: 0x14830004  bne         $a0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1380F4u;
    {
        const bool branch_taken_0x1380f4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x1380F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1380F4u;
            // 0x1380f8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1380f4) {
            ctx->pc = 0x138108u;
            goto label_138108;
        }
    }
    ctx->pc = 0x1380FCu;
    // 0x1380fc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1380fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138100: 0x804e00a  j           func_138028
    ctx->pc = 0x138100u;
    ctx->pc = 0x138104u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138100u;
            // 0x138104: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138028u;
    if (runtime->hasFunction(0x138028u)) {
        auto targetFn = runtime->lookupFunction(0x138028u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00138028_0x138028(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x138108u;
label_138108:
    // 0x138108: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x138108u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13810c: 0x3e00008  jr          $ra
    ctx->pc = 0x13810Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13810Cu;
            // 0x138110: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1380C8u: goto label_1380c8;
            case 0x1380E8u: goto label_1380e8;
            case 0x1380F0u: goto label_1380f0;
            case 0x138108u: goto label_138108;
            case 0x138130u: goto label_138130;
            case 0x138144u: goto label_138144;
            case 0x13815Cu: goto label_13815c;
            case 0x138174u: goto label_138174;
            case 0x138194u: goto label_138194;
            case 0x138198u: goto label_138198;
            case 0x1381B8u: goto label_1381b8;
            case 0x1381C0u: goto label_1381c0;
            case 0x1381D0u: goto label_1381d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138114u;
    // 0x138114: 0x0  nop
    ctx->pc = 0x138114u;
    // NOP
    // 0x138118: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138118u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13811c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13811cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x138120: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x138120u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x138124: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x138124u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x138128: 0xc045a12  jal         func_116848
    ctx->pc = 0x138128u;
    SET_GPR_U32(ctx, 31, 0x138130u);
    ctx->pc = 0x13812Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138128u;
            // 0x13812c: 0x2484c5f8  addiu       $a0, $a0, -0x3A08 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952440));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138130u; }
        if (ctx->pc != 0x138130u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138130u; }
        if (ctx->pc != 0x138130u) { return; }
    }
    ctx->pc = 0x138130u;
label_138130:
    // 0x138130: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x138130u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x138134: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138134u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138138: 0x8c45bbc4  lw          $a1, -0x443C($v0)
    ctx->pc = 0x138138u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949828)));
    // 0x13813c: 0xc045a12  jal         func_116848
    ctx->pc = 0x13813Cu;
    SET_GPR_U32(ctx, 31, 0x138144u);
    ctx->pc = 0x138140u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13813Cu;
            // 0x138140: 0x2484c608  addiu       $a0, $a0, -0x39F8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952456));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138144u; }
        if (ctx->pc != 0x138144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138144u; }
        if (ctx->pc != 0x138144u) { return; }
    }
    ctx->pc = 0x138144u;
label_138144:
    // 0x138144: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138144u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138148: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x138148u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13814c: 0x2484c628  addiu       $a0, $a0, -0x39D8
    ctx->pc = 0x13814cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952488));
    // 0x138150: 0x2442bbdc  addiu       $v0, $v0, -0x4424
    ctx->pc = 0x138150u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949852));
    // 0x138154: 0xc045a12  jal         func_116848
    ctx->pc = 0x138154u;
    SET_GPR_U32(ctx, 31, 0x13815Cu);
    ctx->pc = 0x138158u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138154u;
            // 0x138158: 0x8c450000  lw          $a1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13815Cu; }
        if (ctx->pc != 0x13815Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13815Cu; }
        if (ctx->pc != 0x13815Cu) { return; }
    }
    ctx->pc = 0x13815Cu;
label_13815c:
    // 0x13815c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13815cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138160: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x138160u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x138164: 0x2484c648  addiu       $a0, $a0, -0x39B8
    ctx->pc = 0x138164u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952520));
    // 0x138168: 0x2450bb88  addiu       $s0, $v0, -0x4478
    ctx->pc = 0x138168u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949768));
    // 0x13816c: 0xc045a12  jal         func_116848
    ctx->pc = 0x13816Cu;
    SET_GPR_U32(ctx, 31, 0x138174u);
    ctx->pc = 0x138170u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13816Cu;
            // 0x138170: 0x82050002  lb          $a1, 0x2($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138174u; }
        if (ctx->pc != 0x138174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138174u; }
        if (ctx->pc != 0x138174u) { return; }
    }
    ctx->pc = 0x138174u;
label_138174:
    // 0x138174: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138174u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138178: 0x82030001  lb          $v1, 0x1($s0)
    ctx->pc = 0x138178u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x13817c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13817cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x138180: 0x2484c668  addiu       $a0, $a0, -0x3998
    ctx->pc = 0x138180u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952552));
    // 0x138184: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x138184u;
    {
        const bool branch_taken_0x138184 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x138188u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138184u;
            // 0x138188: 0x92050001  lbu         $a1, 0x1($s0) (Delay Slot)
        SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138184) {
            ctx->pc = 0x138198u;
            goto label_138198;
        }
    }
    ctx->pc = 0x13818Cu;
    // 0x13818c: 0xc045a12  jal         func_116848
    ctx->pc = 0x13818Cu;
    SET_GPR_U32(ctx, 31, 0x138194u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138194u; }
        if (ctx->pc != 0x138194u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138194u; }
        if (ctx->pc != 0x138194u) { return; }
    }
    ctx->pc = 0x138194u;
label_138194:
    // 0x138194: 0x92050001  lbu         $a1, 0x1($s0)
    ctx->pc = 0x138194u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
label_138198:
    // 0x138198: 0x51600  sll         $v0, $a1, 24
    ctx->pc = 0x138198u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x13819c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x13819cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1381a0: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x1381a0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x1381a4: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1381A4u;
    {
        const bool branch_taken_0x1381a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1381a4) {
            ctx->pc = 0x1381B8u;
            goto label_1381b8;
        }
    }
    ctx->pc = 0x1381ACu;
    // 0x1381ac: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1381acu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1381b0: 0xc045a12  jal         func_116848
    ctx->pc = 0x1381B0u;
    SET_GPR_U32(ctx, 31, 0x1381B8u);
    ctx->pc = 0x1381B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1381B0u;
            // 0x1381b4: 0x2484c688  addiu       $a0, $a0, -0x3978 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952584));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1381B8u; }
        if (ctx->pc != 0x1381B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1381B8u; }
        if (ctx->pc != 0x1381B8u) { return; }
    }
    ctx->pc = 0x1381B8u;
label_1381b8:
    // 0x1381b8: 0xc04e032  jal         func_1380C8
    ctx->pc = 0x1381B8u;
    SET_GPR_U32(ctx, 31, 0x1381C0u);
    ctx->pc = 0x1380C8u;
    goto label_1380c8;
    ctx->pc = 0x1381C0u;
label_1381c0:
    // 0x1381c0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1381c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1381c4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1381c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1381c8: 0xc045a12  jal         func_116848
    ctx->pc = 0x1381C8u;
    SET_GPR_U32(ctx, 31, 0x1381D0u);
    ctx->pc = 0x1381CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1381C8u;
            // 0x1381cc: 0x2484c6a8  addiu       $a0, $a0, -0x3958 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952616));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1381D0u; }
        if (ctx->pc != 0x1381D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1381D0u; }
        if (ctx->pc != 0x1381D0u) { return; }
    }
    ctx->pc = 0x1381D0u;
label_1381d0:
    // 0x1381d0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1381d0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1381d4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1381d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1381d8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1381d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1381dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1381DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1381E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1381DCu;
            // 0x1381e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1380C8u: goto label_1380c8;
            case 0x1380E8u: goto label_1380e8;
            case 0x1380F0u: goto label_1380f0;
            case 0x138108u: goto label_138108;
            case 0x138130u: goto label_138130;
            case 0x138144u: goto label_138144;
            case 0x13815Cu: goto label_13815c;
            case 0x138174u: goto label_138174;
            case 0x138194u: goto label_138194;
            case 0x138198u: goto label_138198;
            case 0x1381B8u: goto label_1381b8;
            case 0x1381C0u: goto label_1381c0;
            case 0x1381D0u: goto label_1381d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1381E4u;
    // 0x1381e4: 0x0  nop
    ctx->pc = 0x1381e4u;
    // NOP
    // 0x1381e8: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x1381e8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x1381ec: 0x2463bbe4  addiu       $v1, $v1, -0x441C
    ctx->pc = 0x1381ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949860));
    // 0x1381f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1381F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1381F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1381F0u;
            // 0x1381f4: 0x8c620000  lw          $v0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1380C8u: goto label_1380c8;
            case 0x1380E8u: goto label_1380e8;
            case 0x1380F0u: goto label_1380f0;
            case 0x138108u: goto label_138108;
            case 0x138130u: goto label_138130;
            case 0x138144u: goto label_138144;
            case 0x13815Cu: goto label_13815c;
            case 0x138174u: goto label_138174;
            case 0x138194u: goto label_138194;
            case 0x138198u: goto label_138198;
            case 0x1381B8u: goto label_1381b8;
            case 0x1381C0u: goto label_1381c0;
            case 0x1381D0u: goto label_1381d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1381F8u;
    // 0x1381f8: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x1381f8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x1381fc: 0x2463bbe0  addiu       $v1, $v1, -0x4420
    ctx->pc = 0x1381fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949856));
    // 0x138200: 0x3e00008  jr          $ra
    ctx->pc = 0x138200u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138200u;
            // 0x138204: 0x8c620000  lw          $v0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1380C8u: goto label_1380c8;
            case 0x1380E8u: goto label_1380e8;
            case 0x1380F0u: goto label_1380f0;
            case 0x138108u: goto label_138108;
            case 0x138130u: goto label_138130;
            case 0x138144u: goto label_138144;
            case 0x13815Cu: goto label_13815c;
            case 0x138174u: goto label_138174;
            case 0x138194u: goto label_138194;
            case 0x138198u: goto label_138198;
            case 0x1381B8u: goto label_1381b8;
            case 0x1381C0u: goto label_1381c0;
            case 0x1381D0u: goto label_1381d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138208u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
