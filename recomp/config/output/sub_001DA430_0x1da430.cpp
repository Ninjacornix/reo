#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DA430
// Address: 0x1da430 - 0x1da51c
void sub_001DA430_0x1da430(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DA430_0x1da430");
#endif

    switch (ctx->pc) {
        case 0x1da460u: goto label_1da460;
        case 0x1da494u: goto label_1da494;
        case 0x1da4acu: goto label_1da4ac;
        case 0x1da4b4u: goto label_1da4b4;
        case 0x1da4bcu: goto label_1da4bc;
        case 0x1da504u: goto label_1da504;
        default: break;
    }

    ctx->pc = 0x1da430u;

    // 0x1da430: 0x8076920  j           func_1DA480
    ctx->pc = 0x1DA430u;
    ctx->pc = 0x1DA434u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA430u;
            // 0x1da434: 0x24040040  addiu       $a0, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1DA480u;
    goto label_1da480;
    ctx->pc = 0x1DA438u;
    // 0x1da438: 0x0  nop
    ctx->pc = 0x1da438u;
    // NOP
    // 0x1da43c: 0x0  nop
    ctx->pc = 0x1da43cu;
    // NOP
    // 0x1da440: 0x8076920  j           func_1DA480
    ctx->pc = 0x1DA440u;
    ctx->pc = 0x1DA444u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA440u;
            // 0x1da444: 0x24040040  addiu       $a0, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1DA480u;
    goto label_1da480;
    ctx->pc = 0x1DA448u;
    // 0x1da448: 0x0  nop
    ctx->pc = 0x1da448u;
    // NOP
    // 0x1da44c: 0x0  nop
    ctx->pc = 0x1da44cu;
    // NOP
    // 0x1da450: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1da450u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1da454: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1da454u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1da458: 0xc045534  jal         func_1154D0
    ctx->pc = 0x1DA458u;
    SET_GPR_U32(ctx, 31, 0x1DA460u);
    ctx->pc = 0x1DA45Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA458u;
            // 0x1da45c: 0x8cc40000  lw          $a0, 0x0($a2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1154D0u;
    if (runtime->hasFunction(0x1154D0u)) {
        auto targetFn = runtime->lookupFunction(0x1154D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA460u; }
        if (ctx->pc != 0x1DA460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001154D0_0x1154d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA460u; }
        if (ctx->pc != 0x1DA460u) { return; }
    }
    ctx->pc = 0x1DA460u;
label_1da460:
    // 0x1da460: 0xf  sync
    ctx->pc = 0x1da460u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x1da464: 0x42000038  ei
    ctx->pc = 0x1da464u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x1da468: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1da468u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1da46c: 0x3e00008  jr          $ra
    ctx->pc = 0x1DA46Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1DA470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA46Cu;
            // 0x1da470: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DA460u: goto label_1da460;
            case 0x1DA480u: goto label_1da480;
            case 0x1DA494u: goto label_1da494;
            case 0x1DA4ACu: goto label_1da4ac;
            case 0x1DA4B4u: goto label_1da4b4;
            case 0x1DA4BCu: goto label_1da4bc;
            case 0x1DA504u: goto label_1da504;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DA474u;
    // 0x1da474: 0x0  nop
    ctx->pc = 0x1da474u;
    // NOP
    // 0x1da478: 0x0  nop
    ctx->pc = 0x1da478u;
    // NOP
    // 0x1da47c: 0x0  nop
    ctx->pc = 0x1da47cu;
    // NOP
label_1da480:
    // 0x1da480: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1da480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1da484: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1da484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1da488: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1da488u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1da48c: 0xc045144  jal         func_114510
    ctx->pc = 0x1DA48Cu;
    SET_GPR_U32(ctx, 31, 0x1DA494u);
    ctx->pc = 0x1DA490u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA48Cu;
            // 0x1da490: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114510u;
    if (runtime->hasFunction(0x114510u)) {
        auto targetFn = runtime->lookupFunction(0x114510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA494u; }
        if (ctx->pc != 0x1DA494u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA494u; }
        if (ctx->pc != 0x1DA494u) { return; }
    }
    ctx->pc = 0x1DA494u;
label_1da494:
    // 0x1da494: 0x3c05001e  lui         $a1, 0x1E
    ctx->pc = 0x1da494u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)30 << 16));
    // 0x1da498: 0xafa2002c  sw          $v0, 0x2C($sp)
    ctx->pc = 0x1da498u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
    // 0x1da49c: 0x3204ffff  andi        $a0, $s0, 0xFFFF
    ctx->pc = 0x1da49cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
    // 0x1da4a0: 0x24a5a450  addiu       $a1, $a1, -0x5BB0
    ctx->pc = 0x1da4a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294943824));
    // 0x1da4a4: 0xc0450e8  jal         func_1143A0
    ctx->pc = 0x1DA4A4u;
    SET_GPR_U32(ctx, 31, 0x1DA4ACu);
    ctx->pc = 0x1DA4A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA4A4u;
            // 0x1da4a8: 0x27a6002c  addiu       $a2, $sp, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1143A0u;
    if (runtime->hasFunction(0x1143A0u)) {
        auto targetFn = runtime->lookupFunction(0x1143A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA4ACu; }
        if (ctx->pc != 0x1DA4ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001143A0_0x1143a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA4ACu; }
        if (ctx->pc != 0x1DA4ACu) { return; }
    }
    ctx->pc = 0x1DA4ACu;
label_1da4ac:
    // 0x1da4ac: 0xc045150  jal         func_114540
    ctx->pc = 0x1DA4ACu;
    SET_GPR_U32(ctx, 31, 0x1DA4B4u);
    ctx->pc = 0x114540u;
    if (runtime->hasFunction(0x114540u)) {
        auto targetFn = runtime->lookupFunction(0x114540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA4B4u; }
        if (ctx->pc != 0x1DA4B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114540_0x114540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA4B4u; }
        if (ctx->pc != 0x1DA4B4u) { return; }
    }
    ctx->pc = 0x1DA4B4u;
label_1da4b4:
    // 0x1da4b4: 0xc04515c  jal         func_114570
    ctx->pc = 0x1DA4B4u;
    SET_GPR_U32(ctx, 31, 0x1DA4BCu);
    ctx->pc = 0x1DA4B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA4B4u;
            // 0x1da4b8: 0x8fa4002c  lw          $a0, 0x2C($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114570u;
    if (runtime->hasFunction(0x114570u)) {
        auto targetFn = runtime->lookupFunction(0x114570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA4BCu; }
        if (ctx->pc != 0x1DA4BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114570_0x114570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA4BCu; }
        if (ctx->pc != 0x1DA4BCu) { return; }
    }
    ctx->pc = 0x1DA4BCu;
label_1da4bc:
    // 0x1da4bc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1da4bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1da4c0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1da4c0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1da4c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1DA4C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1DA4C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA4C4u;
            // 0x1da4c8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DA460u: goto label_1da460;
            case 0x1DA480u: goto label_1da480;
            case 0x1DA494u: goto label_1da494;
            case 0x1DA4ACu: goto label_1da4ac;
            case 0x1DA4B4u: goto label_1da4b4;
            case 0x1DA4BCu: goto label_1da4bc;
            case 0x1DA504u: goto label_1da504;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DA4CCu;
    // 0x1da4cc: 0x0  nop
    ctx->pc = 0x1da4ccu;
    // NOP
    // 0x1da4d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1da4d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1da4d4: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1da4d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1da4d8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1da4d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1da4dc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1da4dcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da4e0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1da4e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1da4e4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1da4e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da4e8: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1da4e8u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1da4ec: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1da4ecu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1da4f0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1da4f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1da4f4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1da4f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da4f8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1da4f8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da4fc: 0xc076947  jal         func_1DA51C
    ctx->pc = 0x1DA4FCu;
    SET_GPR_U32(ctx, 31, 0x1DA504u);
    ctx->pc = 0x1DA51Cu;
    if (runtime->hasFunction(0x1DA51Cu)) {
        auto targetFn = runtime->lookupFunction(0x1DA51Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA504u; }
        if (ctx->pc != 0x1DA504u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DA51C_0x1da51c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA504u; }
        if (ctx->pc != 0x1DA504u) { return; }
    }
    ctx->pc = 0x1DA504u;
label_1da504:
    // 0x1da504: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1da504u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da508: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1da508u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1da50c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1da50cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1da510: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1da510u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1da514: 0x3e00008  jr          $ra
    ctx->pc = 0x1DA514u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DA460u: goto label_1da460;
            case 0x1DA480u: goto label_1da480;
            case 0x1DA494u: goto label_1da494;
            case 0x1DA4ACu: goto label_1da4ac;
            case 0x1DA4B4u: goto label_1da4b4;
            case 0x1DA4BCu: goto label_1da4bc;
            case 0x1DA504u: goto label_1da504;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DA51Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
