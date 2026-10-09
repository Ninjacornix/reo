#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138328
// Address: 0x138328 - 0x1383e8
void sub_00138328_0x138328(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138328_0x138328");
#endif

    switch (ctx->pc) {
        case 0x138388u: goto label_138388;
        case 0x13839cu: goto label_13839c;
        case 0x1383a4u: goto label_1383a4;
        case 0x1383b0u: goto label_1383b0;
        case 0x1383c0u: goto label_1383c0;
        default: break;
    }

    ctx->pc = 0x138328u;

    // 0x138328: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x138328u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13832c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13832cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x138330: 0x8c43bbfc  lw          $v1, -0x4404($v0)
    ctx->pc = 0x138330u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949884)));
    // 0x138334: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x138334u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x138338: 0x14640005  bne         $v1, $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x138338u;
    {
        const bool branch_taken_0x138338 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x13833Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138338u;
            // 0x13833c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138338) {
            ctx->pc = 0x138350u;
            goto label_138350;
        }
    }
    ctx->pc = 0x138340u;
    // 0x138340: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x138340u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138344: 0x80505ea  j           func_1417A8
    ctx->pc = 0x138344u;
    ctx->pc = 0x138348u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138344u;
            // 0x138348: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1417A8u;
    if (runtime->hasFunction(0x1417A8u)) {
        auto targetFn = runtime->lookupFunction(0x1417A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001417A8_0x1417a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13834Cu;
    // 0x13834c: 0x0  nop
    ctx->pc = 0x13834cu;
    // NOP
label_138350:
    // 0x138350: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x138350u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138354: 0x3e00008  jr          $ra
    ctx->pc = 0x138354u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138354u;
            // 0x138358: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138350u: goto label_138350;
            case 0x138388u: goto label_138388;
            case 0x13839Cu: goto label_13839c;
            case 0x1383A4u: goto label_1383a4;
            case 0x1383B0u: goto label_1383b0;
            case 0x1383C0u: goto label_1383c0;
            case 0x1383C8u: goto label_1383c8;
            case 0x1383CCu: goto label_1383cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13835Cu;
    // 0x13835c: 0x0  nop
    ctx->pc = 0x13835cu;
    // NOP
    // 0x138360: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x138360u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x138364: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x138364u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x138368: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x138368u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13836c: 0x2452bbc4  addiu       $s2, $v0, -0x443C
    ctx->pc = 0x13836cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949828));
    // 0x138370: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x138370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x138374: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x138374u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138378: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x138378u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13837c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x13837cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x138380: 0xc050864  jal         func_142190
    ctx->pc = 0x138380u;
    SET_GPR_U32(ctx, 31, 0x138388u);
    ctx->pc = 0x138384u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138380u;
            // 0x138384: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142190u;
    if (runtime->hasFunction(0x142190u)) {
        auto targetFn = runtime->lookupFunction(0x142190u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138388u; }
        if (ctx->pc != 0x138388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142190_0x142190(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138388u; }
        if (ctx->pc != 0x138388u) { return; }
    }
    ctx->pc = 0x138388u;
label_138388:
    // 0x138388: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x138388u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13838c: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x13838Cu;
    {
        const bool branch_taken_0x13838c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x138390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13838Cu;
            // 0x138390: 0x34049600  ori         $a0, $zero, 0x9600 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)38400);
        ctx->in_delay_slot = false;
        if (branch_taken_0x13838c) {
            ctx->pc = 0x1383CCu;
            goto label_1383cc;
        }
    }
    ctx->pc = 0x138394u;
    // 0x138394: 0xc04e082  jal         func_138208
    ctx->pc = 0x138394u;
    SET_GPR_U32(ctx, 31, 0x13839Cu);
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13839Cu; }
        if (ctx->pc != 0x13839Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13839Cu; }
        if (ctx->pc != 0x13839Cu) { return; }
    }
    ctx->pc = 0x13839Cu;
label_13839c:
    // 0x13839c: 0xc04065a  jal         func_101968
    ctx->pc = 0x13839Cu;
    SET_GPR_U32(ctx, 31, 0x1383A4u);
    ctx->pc = 0x1383A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13839Cu;
            // 0x1383a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101968u;
    if (runtime->hasFunction(0x101968u)) {
        auto targetFn = runtime->lookupFunction(0x101968u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1383A4u; }
        if (ctx->pc != 0x1383A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101968_0x101968(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1383A4u; }
        if (ctx->pc != 0x1383A4u) { return; }
    }
    ctx->pc = 0x1383A4u;
label_1383a4:
    // 0x1383a4: 0x34049601  ori         $a0, $zero, 0x9601
    ctx->pc = 0x1383a4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)38401);
    // 0x1383a8: 0xc04e082  jal         func_138208
    ctx->pc = 0x1383A8u;
    SET_GPR_U32(ctx, 31, 0x1383B0u);
    ctx->pc = 0x1383ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1383A8u;
            // 0x1383ac: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1383B0u; }
        if (ctx->pc != 0x1383B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1383B0u; }
        if (ctx->pc != 0x1383B0u) { return; }
    }
    ctx->pc = 0x1383B0u;
label_1383b0:
    // 0x1383b0: 0x56000005  bnel        $s0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1383B0u;
    {
        const bool branch_taken_0x1383b0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1383b0) {
            ctx->pc = 0x1383B4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1383B0u;
            // 0x1383b4: 0xae400000  sw          $zero, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1383C8u;
            goto label_1383c8;
        }
    }
    ctx->pc = 0x1383B8u;
    // 0x1383b8: 0xc0406ba  jal         func_101AE8
    ctx->pc = 0x1383B8u;
    SET_GPR_U32(ctx, 31, 0x1383C0u);
    ctx->pc = 0x101AE8u;
    if (runtime->hasFunction(0x101AE8u)) {
        auto targetFn = runtime->lookupFunction(0x101AE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1383C0u; }
        if (ctx->pc != 0x1383C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101AE8_0x101ae8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1383C0u; }
        if (ctx->pc != 0x1383C0u) { return; }
    }
    ctx->pc = 0x1383C0u;
label_1383c0:
    // 0x1383c0: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1383c0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1383c4: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x1383c4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
label_1383c8:
    // 0x1383c8: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x1383c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1383cc:
    // 0x1383cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1383ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1383d0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1383d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1383d4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1383d4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1383d8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1383d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1383dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1383DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1383E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1383DCu;
            // 0x1383e0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138350u: goto label_138350;
            case 0x138388u: goto label_138388;
            case 0x13839Cu: goto label_13839c;
            case 0x1383A4u: goto label_1383a4;
            case 0x1383B0u: goto label_1383b0;
            case 0x1383C0u: goto label_1383c0;
            case 0x1383C8u: goto label_1383c8;
            case 0x1383CCu: goto label_1383cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1383E4u;
    // 0x1383e4: 0x0  nop
    ctx->pc = 0x1383e4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
