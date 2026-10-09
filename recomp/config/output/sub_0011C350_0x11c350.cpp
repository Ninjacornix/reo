#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011C350
// Address: 0x11c350 - 0x11c3e0
void sub_0011C350_0x11c350(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011C350_0x11c350");
#endif

    switch (ctx->pc) {
        case 0x11c368u: goto label_11c368;
        case 0x11c378u: goto label_11c378;
        case 0x11c3bcu: goto label_11c3bc;
        default: break;
    }

    ctx->pc = 0x11c350u;

    // 0x11c350: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x11c350u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11c354: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x11c354u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x11c358: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x11c358u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11c35c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11c35cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c360: 0xc046f5e  jal         func_11BD78
    ctx->pc = 0x11C360u;
    SET_GPR_U32(ctx, 31, 0x11C368u);
    ctx->pc = 0x11C364u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C360u;
            // 0x11c364: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BD78u;
    if (runtime->hasFunction(0x11BD78u)) {
        auto targetFn = runtime->lookupFunction(0x11BD78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C368u; }
        if (ctx->pc != 0x11C368u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BD78_0x11bd78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C368u; }
        if (ctx->pc != 0x11C368u) { return; }
    }
    ctx->pc = 0x11C368u;
label_11c368:
    // 0x11c368: 0x4400018  bltz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x11C368u;
    {
        const bool branch_taken_0x11c368 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x11C36Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C368u;
            // 0x11c36c: 0x3c02ffff  lui         $v0, 0xFFFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c368) {
            ctx->pc = 0x11C3CCu;
            goto label_11c3cc;
        }
    }
    ctx->pc = 0x11C370u;
    // 0x11c370: 0xc046f9e  jal         func_11BE78
    ctx->pc = 0x11C370u;
    SET_GPR_U32(ctx, 31, 0x11C378u);
    ctx->pc = 0x11BE78u;
    if (runtime->hasFunction(0x11BE78u)) {
        auto targetFn = runtime->lookupFunction(0x11BE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C378u; }
        if (ctx->pc != 0x11C378u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BE78_0x11be78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C378u; }
        if (ctx->pc != 0x11C378u) { return; }
    }
    ctx->pc = 0x11C378u;
label_11c378:
    // 0x11c378: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C378u;
    {
        const bool branch_taken_0x11c378 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C37Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C378u;
            // 0x11c37c: 0x3c100026  lui         $s0, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c378) {
            ctx->pc = 0x11C38Cu;
            goto label_11c38c;
        }
    }
    ctx->pc = 0x11C380u;
    // 0x11c380: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11c380u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11c384: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x11C384u;
    {
        const bool branch_taken_0x11c384 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C388u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C384u;
            // 0x11c388: 0x3442fffc  ori         $v0, $v0, 0xFFFC (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65532);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c384) {
            ctx->pc = 0x11C3CCu;
            goto label_11c3cc;
        }
    }
    ctx->pc = 0x11C38Cu;
label_11c38c:
    // 0x11c38c: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11c38cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11c390: 0x2607e400  addiu       $a3, $s0, -0x1C00
    ctx->pc = 0x11c390u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 4294960128));
    // 0x11c394: 0xae11e400  sw          $s1, -0x1C00($s0)
    ctx->pc = 0x11c394u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294960128), GPR_U32(ctx, 17));
    // 0x11c398: 0x2484e600  addiu       $a0, $a0, -0x1A00
    ctx->pc = 0x11c398u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294960640));
    // 0x11c39c: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11c39cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11c3a0: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x11c3a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x11c3a4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11c3a4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c3a8: 0x24080004  addiu       $t0, $zero, 0x4
    ctx->pc = 0x11c3a8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11c3ac: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x11c3acu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c3b0: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11c3b0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11c3b4: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11C3B4u;
    SET_GPR_U32(ctx, 31, 0x11C3BCu);
    ctx->pc = 0x11C3B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C3B4u;
            // 0x11c3b8: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C3BCu; }
        if (ctx->pc != 0x11C3BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C3BCu; }
        if (ctx->pc != 0x11C3BCu) { return; }
    }
    ctx->pc = 0x11C3BCu;
label_11c3bc:
    // 0x11c3bc: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11C3BCu;
    {
        const bool branch_taken_0x11c3bc = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11c3bc) {
            ctx->pc = 0x11C3C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11C3BCu;
            // 0x11c3c0: 0x8e02e400  lw          $v0, -0x1C00($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294960128)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11C3CCu;
            goto label_11c3cc;
        }
    }
    ctx->pc = 0x11C3C4u;
    // 0x11c3c4: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11c3c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11c3c8: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11c3c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
label_11c3cc:
    // 0x11c3cc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11c3ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11c3d0: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x11c3d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11c3d4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11c3d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11c3d8: 0x3e00008  jr          $ra
    ctx->pc = 0x11C3D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11C3DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C3D8u;
            // 0x11c3dc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11C368u: goto label_11c368;
            case 0x11C378u: goto label_11c378;
            case 0x11C38Cu: goto label_11c38c;
            case 0x11C3BCu: goto label_11c3bc;
            case 0x11C3CCu: goto label_11c3cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11C3E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
