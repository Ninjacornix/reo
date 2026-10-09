#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00171880
// Address: 0x171880 - 0x1719f0
void sub_00171880_0x171880(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00171880_0x171880");
#endif

    switch (ctx->pc) {
        case 0x1718b4u: goto label_1718b4;
        case 0x1718f4u: goto label_1718f4;
        case 0x171904u: goto label_171904;
        case 0x171944u: goto label_171944;
        case 0x171978u: goto label_171978;
        case 0x171988u: goto label_171988;
        case 0x1719b4u: goto label_1719b4;
        case 0x1719dcu: goto label_1719dc;
        default: break;
    }

    ctx->pc = 0x171880u;

label_171880:
    // 0x171880: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x171880u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x171884: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x171884u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x171888: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x171888u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17188c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x17188cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x171890: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x171890u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171894: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x171894u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x171898: 0x27a70008  addiu       $a3, $sp, 0x8
    ctx->pc = 0x171898u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
    // 0x17189c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x17189cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1718a0: 0x27a8000c  addiu       $t0, $sp, 0xC
    ctx->pc = 0x1718a0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
    // 0x1718a4: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1718a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1718a8: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1718a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1718ac: 0xc05c328  jal         func_170CA0
    ctx->pc = 0x1718ACu;
    SET_GPR_U32(ctx, 31, 0x1718B4u);
    ctx->pc = 0x1718B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1718ACu;
            // 0x1718b0: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170CA0u;
    if (runtime->hasFunction(0x170CA0u)) {
        auto targetFn = runtime->lookupFunction(0x170CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1718B4u; }
        if (ctx->pc != 0x1718B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170CA0_0x170ca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1718B4u; }
        if (ctx->pc != 0x1718B4u) { return; }
    }
    ctx->pc = 0x1718B4u;
label_1718b4:
    // 0x1718b4: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x1718b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1718b8: 0x3c020fff  lui         $v0, 0xFFF
    ctx->pc = 0x1718b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4095 << 16));
    // 0x1718bc: 0x8fa60008  lw          $a2, 0x8($sp)
    ctx->pc = 0x1718bcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1718c0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1718c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1718c4: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x1718c4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x1718c8: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x1718c8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1718cc: 0x8fa7000c  lw          $a3, 0xC($sp)
    ctx->pc = 0x1718ccu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x1718d0: 0x822024  and         $a0, $a0, $v0
    ctx->pc = 0x1718d0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1718d4: 0xc23024  and         $a2, $a2, $v0
    ctx->pc = 0x1718d4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
    // 0x1718d8: 0x220402d  daddu       $t0, $s1, $zero
    ctx->pc = 0x1718d8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1718dc: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x1718dcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1718e0: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1718e0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1718e4: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x1718e4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x1718e8: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1718e8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1718ec: 0xc05c6f8  jal         func_171BE0
    ctx->pc = 0x1718ECu;
    SET_GPR_U32(ctx, 31, 0x1718F4u);
    ctx->pc = 0x1718F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1718ECu;
            // 0x1718f0: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171BE0u;
    if (runtime->hasFunction(0x171BE0u)) {
        auto targetFn = runtime->lookupFunction(0x171BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1718F4u; }
        if (ctx->pc != 0x1718F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171BE0_0x171be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1718F4u; }
        if (ctx->pc != 0x1718F4u) { return; }
    }
    ctx->pc = 0x1718F4u;
label_1718f4:
    // 0x1718f4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1718f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1718f8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1718f8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1718fc: 0xc05c364  jal         func_170D90
    ctx->pc = 0x1718FCu;
    SET_GPR_U32(ctx, 31, 0x171904u);
    ctx->pc = 0x171900u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1718FCu;
            // 0x171900: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170D90u;
    if (runtime->hasFunction(0x170D90u)) {
        auto targetFn = runtime->lookupFunction(0x170D90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171904u; }
        if (ctx->pc != 0x171904u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170D90_0x170d90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171904u; }
        if (ctx->pc != 0x171904u) { return; }
    }
    ctx->pc = 0x171904u;
label_171904:
    // 0x171904: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x171904u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171908: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x171908u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17190c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x17190cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x171910: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x171910u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x171914: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x171914u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x171918: 0x3e00008  jr          $ra
    ctx->pc = 0x171918u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17191Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171918u;
            // 0x17191c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x171880u: goto label_171880;
            case 0x1718B4u: goto label_1718b4;
            case 0x1718F4u: goto label_1718f4;
            case 0x171904u: goto label_171904;
            case 0x171944u: goto label_171944;
            case 0x171978u: goto label_171978;
            case 0x171988u: goto label_171988;
            case 0x17198Cu: goto label_17198c;
            case 0x1719B4u: goto label_1719b4;
            case 0x1719DCu: goto label_1719dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x171920u;
    // 0x171920: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x171920u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x171924: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x171924u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x171928: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x171928u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17192c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x17192cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x171930: 0x8cc21b30  lw          $v0, 0x1B30($a2)
    ctx->pc = 0x171930u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 6960)));
    // 0x171934: 0x24500a48  addiu       $s0, $v0, 0xA48
    ctx->pc = 0x171934u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 2632));
    // 0x171938: 0x245109d8  addiu       $s1, $v0, 0x9D8
    ctx->pc = 0x171938u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 2520));
    // 0x17193c: 0xc05c398  jal         func_170E60
    ctx->pc = 0x17193Cu;
    SET_GPR_U32(ctx, 31, 0x171944u);
    ctx->pc = 0x171940u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17193Cu;
            // 0x171940: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170E60u;
    if (runtime->hasFunction(0x170E60u)) {
        auto targetFn = runtime->lookupFunction(0x170E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171944u; }
        if (ctx->pc != 0x171944u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170E60_0x170e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171944u; }
        if (ctx->pc != 0x171944u) { return; }
    }
    ctx->pc = 0x171944u;
label_171944:
    // 0x171944: 0x8e230014  lw          $v1, 0x14($s1)
    ctx->pc = 0x171944u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x171948: 0x50600010  beql        $v1, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x171948u;
    {
        const bool branch_taken_0x171948 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x171948) {
            ctx->pc = 0x17194Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171948u;
            // 0x17194c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17198Cu;
            goto label_17198c;
        }
    }
    ctx->pc = 0x171950u;
    // 0x171950: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x171950u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x171954: 0x5440000d  bnel        $v0, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x171954u;
    {
        const bool branch_taken_0x171954 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x171954) {
            ctx->pc = 0x171958u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171954u;
            // 0x171958: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17198Cu;
            goto label_17198c;
        }
    }
    ctx->pc = 0x17195Cu;
    // 0x17195c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17195cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x171960: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x171960u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x171964: 0xae220018  sw          $v0, 0x18($s1)
    ctx->pc = 0x171964u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 2));
    // 0x171968: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x171968u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17196c: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x17196cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x171970: 0xc05c620  jal         func_171880
    ctx->pc = 0x171970u;
    SET_GPR_U32(ctx, 31, 0x171978u);
    ctx->pc = 0x171974u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171970u;
            // 0x171974: 0x24a50918  addiu       $a1, $a1, 0x918 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2328));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171880u;
    goto label_171880;
    ctx->pc = 0x171978u;
label_171978:
    // 0x171978: 0x8e030018  lw          $v1, 0x18($s0)
    ctx->pc = 0x171978u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x17197c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17197cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171980: 0xc05c398  jal         func_170E60
    ctx->pc = 0x171980u;
    SET_GPR_U32(ctx, 31, 0x171988u);
    ctx->pc = 0x171984u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171980u;
            // 0x171984: 0xae030014  sw          $v1, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170E60u;
    if (runtime->hasFunction(0x170E60u)) {
        auto targetFn = runtime->lookupFunction(0x170E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171988u; }
        if (ctx->pc != 0x171988u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170E60_0x170e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171988u; }
        if (ctx->pc != 0x171988u) { return; }
    }
    ctx->pc = 0x171988u;
label_171988:
    // 0x171988: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x171988u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17198c:
    // 0x17198c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17198cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x171990: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x171990u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x171994: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x171994u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x171998: 0x3e00008  jr          $ra
    ctx->pc = 0x171998u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17199Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171998u;
            // 0x17199c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x171880u: goto label_171880;
            case 0x1718B4u: goto label_1718b4;
            case 0x1718F4u: goto label_1718f4;
            case 0x171904u: goto label_171904;
            case 0x171944u: goto label_171944;
            case 0x171978u: goto label_171978;
            case 0x171988u: goto label_171988;
            case 0x17198Cu: goto label_17198c;
            case 0x1719B4u: goto label_1719b4;
            case 0x1719DCu: goto label_1719dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1719A0u;
    // 0x1719a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1719a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1719a4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1719a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1719a8: 0x8cc41b30  lw          $a0, 0x1B30($a2)
    ctx->pc = 0x1719a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 6960)));
    // 0x1719ac: 0xc05c418  jal         func_171060
    ctx->pc = 0x1719ACu;
    SET_GPR_U32(ctx, 31, 0x1719B4u);
    ctx->pc = 0x1719B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1719ACu;
            // 0x1719b0: 0x24840a48  addiu       $a0, $a0, 0xA48 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2632));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171060u;
    if (runtime->hasFunction(0x171060u)) {
        auto targetFn = runtime->lookupFunction(0x171060u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1719B4u; }
        if (ctx->pc != 0x1719B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171060_0x171060(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1719B4u; }
        if (ctx->pc != 0x1719B4u) { return; }
    }
    ctx->pc = 0x1719B4u;
label_1719b4:
    // 0x1719b4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1719b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1719b8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1719b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1719bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1719BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1719C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1719BCu;
            // 0x1719c0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x171880u: goto label_171880;
            case 0x1718B4u: goto label_1718b4;
            case 0x1718F4u: goto label_1718f4;
            case 0x171904u: goto label_171904;
            case 0x171944u: goto label_171944;
            case 0x171978u: goto label_171978;
            case 0x171988u: goto label_171988;
            case 0x17198Cu: goto label_17198c;
            case 0x1719B4u: goto label_1719b4;
            case 0x1719DCu: goto label_1719dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1719C4u;
    // 0x1719c4: 0x0  nop
    ctx->pc = 0x1719c4u;
    // NOP
    // 0x1719c8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1719c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1719cc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1719ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1719d0: 0x8cc41b30  lw          $a0, 0x1B30($a2)
    ctx->pc = 0x1719d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 6960)));
    // 0x1719d4: 0xc05c458  jal         func_171160
    ctx->pc = 0x1719D4u;
    SET_GPR_U32(ctx, 31, 0x1719DCu);
    ctx->pc = 0x1719D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1719D4u;
            // 0x1719d8: 0x24840a48  addiu       $a0, $a0, 0xA48 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2632));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171160u;
    if (runtime->hasFunction(0x171160u)) {
        auto targetFn = runtime->lookupFunction(0x171160u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1719DCu; }
        if (ctx->pc != 0x1719DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171160_0x171160(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1719DCu; }
        if (ctx->pc != 0x1719DCu) { return; }
    }
    ctx->pc = 0x1719DCu;
label_1719dc:
    // 0x1719dc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1719dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1719e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1719e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1719e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1719E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1719E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1719E4u;
            // 0x1719e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x171880u: goto label_171880;
            case 0x1718B4u: goto label_1718b4;
            case 0x1718F4u: goto label_1718f4;
            case 0x171904u: goto label_171904;
            case 0x171944u: goto label_171944;
            case 0x171978u: goto label_171978;
            case 0x171988u: goto label_171988;
            case 0x17198Cu: goto label_17198c;
            case 0x1719B4u: goto label_1719b4;
            case 0x1719DCu: goto label_1719dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1719ECu;
    // 0x1719ec: 0x0  nop
    ctx->pc = 0x1719ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
