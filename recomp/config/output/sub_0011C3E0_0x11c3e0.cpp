#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011C3E0
// Address: 0x11c3e0 - 0x11c530
void sub_0011C3E0_0x11c3e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011C3E0_0x11c3e0");
#endif

    switch (ctx->pc) {
        case 0x11c3f4u: goto label_11c3f4;
        case 0x11c404u: goto label_11c404;
        case 0x11c42cu: goto label_11c42c;
        case 0x11c460u: goto label_11c460;
        case 0x11c498u: goto label_11c498;
        case 0x11c4a8u: goto label_11c4a8;
        case 0x11c4ecu: goto label_11c4ec;
        case 0x11c520u: goto label_11c520;
        default: break;
    }

    ctx->pc = 0x11c3e0u;

    // 0x11c3e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11c3e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11c3e4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x11c3e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x11c3e8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11c3e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11c3ec: 0xc046f5e  jal         func_11BD78
    ctx->pc = 0x11C3ECu;
    SET_GPR_U32(ctx, 31, 0x11C3F4u);
    ctx->pc = 0x11C3F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C3ECu;
            // 0x11c3f0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BD78u;
    if (runtime->hasFunction(0x11BD78u)) {
        auto targetFn = runtime->lookupFunction(0x11BD78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C3F4u; }
        if (ctx->pc != 0x11C3F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BD78_0x11bd78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C3F4u; }
        if (ctx->pc != 0x11C3F4u) { return; }
    }
    ctx->pc = 0x11C3F4u;
label_11c3f4:
    // 0x11c3f4: 0x440001e  bltz        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x11C3F4u;
    {
        const bool branch_taken_0x11c3f4 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x11C3F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C3F4u;
            // 0x11c3f8: 0x3c02ffff  lui         $v0, 0xFFFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c3f4) {
            ctx->pc = 0x11C470u;
            goto label_11c470;
        }
    }
    ctx->pc = 0x11C3FCu;
    // 0x11c3fc: 0xc046f9e  jal         func_11BE78
    ctx->pc = 0x11C3FCu;
    SET_GPR_U32(ctx, 31, 0x11C404u);
    ctx->pc = 0x11BE78u;
    if (runtime->hasFunction(0x11BE78u)) {
        auto targetFn = runtime->lookupFunction(0x11BE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C404u; }
        if (ctx->pc != 0x11C404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BE78_0x11be78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C404u; }
        if (ctx->pc != 0x11C404u) { return; }
    }
    ctx->pc = 0x11C404u;
label_11c404:
    // 0x11c404: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C404u;
    {
        const bool branch_taken_0x11c404 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11c404) {
            ctx->pc = 0x11C408u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11C404u;
            // 0x11c408: 0x3c020026  lui         $v0, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11C418u;
            goto label_11c418;
        }
    }
    ctx->pc = 0x11C40Cu;
    // 0x11c40c: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11c40cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11c410: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x11C410u;
    {
        const bool branch_taken_0x11c410 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C410u;
            // 0x11c414: 0x3442fffc  ori         $v0, $v0, 0xFFFC (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65532);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c410) {
            ctx->pc = 0x11C470u;
            goto label_11c470;
        }
    }
    ctx->pc = 0x11C418u;
label_11c418:
    // 0x11c418: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11c418u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c41c: 0x2450e408  addiu       $s0, $v0, -0x1BF8
    ctx->pc = 0x11c41cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294960136));
    // 0x11c420: 0x240600fc  addiu       $a2, $zero, 0xFC
    ctx->pc = 0x11c420u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 252));
    // 0x11c424: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x11C424u;
    SET_GPR_U32(ctx, 31, 0x11C42Cu);
    ctx->pc = 0x11C428u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C424u;
            // 0x11c428: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C42Cu; }
        if (ctx->pc != 0x11C42Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C42Cu; }
        if (ctx->pc != 0x11C42Cu) { return; }
    }
    ctx->pc = 0x11C42Cu;
label_11c42c:
    // 0x11c42c: 0x2603fff8  addiu       $v1, $s0, -0x8
    ctx->pc = 0x11c42cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967288));
    // 0x11c430: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11c430u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11c434: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x11c434u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c438: 0xa0600103  sb          $zero, 0x103($v1)
    ctx->pc = 0x11c438u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 259), (uint8_t)GPR_U32(ctx, 0));
    // 0x11c43c: 0x2484e600  addiu       $a0, $a0, -0x1A00
    ctx->pc = 0x11c43cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294960640));
    // 0x11c440: 0x24050009  addiu       $a1, $zero, 0x9
    ctx->pc = 0x11c440u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x11c444: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11c444u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11c448: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11c448u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c44c: 0x24080200  addiu       $t0, $zero, 0x200
    ctx->pc = 0x11c44cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x11c450: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x11c450u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c454: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11c454u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11c458: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11C458u;
    SET_GPR_U32(ctx, 31, 0x11C460u);
    ctx->pc = 0x11C45Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C458u;
            // 0x11c45c: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C460u; }
        if (ctx->pc != 0x11C460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C460u; }
        if (ctx->pc != 0x11C460u) { return; }
    }
    ctx->pc = 0x11C460u;
label_11c460:
    // 0x11c460: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11C460u;
    {
        const bool branch_taken_0x11c460 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11c460) {
            ctx->pc = 0x11C464u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11C460u;
            // 0x11c464: 0x8e02fff8  lw          $v0, -0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294967288)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11C470u;
            goto label_11c470;
        }
    }
    ctx->pc = 0x11C468u;
    // 0x11c468: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11c468u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11c46c: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11c46cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
label_11c470:
    // 0x11c470: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11c470u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11c474: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11c474u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11c478: 0x3e00008  jr          $ra
    ctx->pc = 0x11C478u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11C47Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C478u;
            // 0x11c47c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11C3F4u: goto label_11c3f4;
            case 0x11C404u: goto label_11c404;
            case 0x11C418u: goto label_11c418;
            case 0x11C42Cu: goto label_11c42c;
            case 0x11C460u: goto label_11c460;
            case 0x11C470u: goto label_11c470;
            case 0x11C498u: goto label_11c498;
            case 0x11C4A8u: goto label_11c4a8;
            case 0x11C4BCu: goto label_11c4bc;
            case 0x11C4ECu: goto label_11c4ec;
            case 0x11C4FCu: goto label_11c4fc;
            case 0x11C520u: goto label_11c520;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11C480u;
    // 0x11c480: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x11c480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11c484: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x11c484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x11c488: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x11c488u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11c48c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11c48cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c490: 0xc046f5e  jal         func_11BD78
    ctx->pc = 0x11C490u;
    SET_GPR_U32(ctx, 31, 0x11C498u);
    ctx->pc = 0x11C494u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C490u;
            // 0x11c494: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BD78u;
    if (runtime->hasFunction(0x11BD78u)) {
        auto targetFn = runtime->lookupFunction(0x11BD78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C498u; }
        if (ctx->pc != 0x11C498u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BD78_0x11bd78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C498u; }
        if (ctx->pc != 0x11C498u) { return; }
    }
    ctx->pc = 0x11C498u;
label_11c498:
    // 0x11c498: 0x4400018  bltz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x11C498u;
    {
        const bool branch_taken_0x11c498 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x11C49Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C498u;
            // 0x11c49c: 0x3c02ffff  lui         $v0, 0xFFFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c498) {
            ctx->pc = 0x11C4FCu;
            goto label_11c4fc;
        }
    }
    ctx->pc = 0x11C4A0u;
    // 0x11c4a0: 0xc046f9e  jal         func_11BE78
    ctx->pc = 0x11C4A0u;
    SET_GPR_U32(ctx, 31, 0x11C4A8u);
    ctx->pc = 0x11BE78u;
    if (runtime->hasFunction(0x11BE78u)) {
        auto targetFn = runtime->lookupFunction(0x11BE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C4A8u; }
        if (ctx->pc != 0x11C4A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BE78_0x11be78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C4A8u; }
        if (ctx->pc != 0x11C4A8u) { return; }
    }
    ctx->pc = 0x11C4A8u;
label_11c4a8:
    // 0x11c4a8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C4A8u;
    {
        const bool branch_taken_0x11c4a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C4ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C4A8u;
            // 0x11c4ac: 0x3c100026  lui         $s0, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c4a8) {
            ctx->pc = 0x11C4BCu;
            goto label_11c4bc;
        }
    }
    ctx->pc = 0x11C4B0u;
    // 0x11c4b0: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11c4b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11c4b4: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x11C4B4u;
    {
        const bool branch_taken_0x11c4b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C4B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C4B4u;
            // 0x11c4b8: 0x3442fffc  ori         $v0, $v0, 0xFFFC (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65532);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c4b4) {
            ctx->pc = 0x11C4FCu;
            goto label_11c4fc;
        }
    }
    ctx->pc = 0x11C4BCu;
label_11c4bc:
    // 0x11c4bc: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11c4bcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11c4c0: 0x2607e400  addiu       $a3, $s0, -0x1C00
    ctx->pc = 0x11c4c0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 4294960128));
    // 0x11c4c4: 0xae11e400  sw          $s1, -0x1C00($s0)
    ctx->pc = 0x11c4c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294960128), GPR_U32(ctx, 17));
    // 0x11c4c8: 0x2484e600  addiu       $a0, $a0, -0x1A00
    ctx->pc = 0x11c4c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294960640));
    // 0x11c4cc: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11c4ccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11c4d0: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x11c4d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x11c4d4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11c4d4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c4d8: 0x24080004  addiu       $t0, $zero, 0x4
    ctx->pc = 0x11c4d8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11c4dc: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x11c4dcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c4e0: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11c4e0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11c4e4: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11C4E4u;
    SET_GPR_U32(ctx, 31, 0x11C4ECu);
    ctx->pc = 0x11C4E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C4E4u;
            // 0x11c4e8: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C4ECu; }
        if (ctx->pc != 0x11C4ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C4ECu; }
        if (ctx->pc != 0x11C4ECu) { return; }
    }
    ctx->pc = 0x11C4ECu;
label_11c4ec:
    // 0x11c4ec: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11C4ECu;
    {
        const bool branch_taken_0x11c4ec = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11c4ec) {
            ctx->pc = 0x11C4F0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11C4ECu;
            // 0x11c4f0: 0x8e02e400  lw          $v0, -0x1C00($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294960128)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11C4FCu;
            goto label_11c4fc;
        }
    }
    ctx->pc = 0x11C4F4u;
    // 0x11c4f4: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11c4f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11c4f8: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11c4f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
label_11c4fc:
    // 0x11c4fc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11c4fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11c500: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x11c500u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11c504: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11c504u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11c508: 0x3e00008  jr          $ra
    ctx->pc = 0x11C508u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11C50Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C508u;
            // 0x11c50c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11C3F4u: goto label_11c3f4;
            case 0x11C404u: goto label_11c404;
            case 0x11C418u: goto label_11c418;
            case 0x11C42Cu: goto label_11c42c;
            case 0x11C460u: goto label_11c460;
            case 0x11C470u: goto label_11c470;
            case 0x11C498u: goto label_11c498;
            case 0x11C4A8u: goto label_11c4a8;
            case 0x11C4BCu: goto label_11c4bc;
            case 0x11C4ECu: goto label_11c4ec;
            case 0x11C4FCu: goto label_11c4fc;
            case 0x11C520u: goto label_11c520;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11C510u;
    // 0x11c510: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x11c510u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11c514: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x11c514u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x11c518: 0xc046fd0  jal         func_11BF40
    ctx->pc = 0x11C518u;
    SET_GPR_U32(ctx, 31, 0x11C520u);
    ctx->pc = 0x11C51Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C518u;
            // 0x11c51c: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BF40u;
    if (runtime->hasFunction(0x11BF40u)) {
        auto targetFn = runtime->lookupFunction(0x11BF40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C520u; }
        if (ctx->pc != 0x11C520u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BF40_0x11bf40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C520u; }
        if (ctx->pc != 0x11C520u) { return; }
    }
    ctx->pc = 0x11C520u;
label_11c520:
    // 0x11c520: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x11c520u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11c524: 0x3e00008  jr          $ra
    ctx->pc = 0x11C524u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11C528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C524u;
            // 0x11c528: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11C3F4u: goto label_11c3f4;
            case 0x11C404u: goto label_11c404;
            case 0x11C418u: goto label_11c418;
            case 0x11C42Cu: goto label_11c42c;
            case 0x11C460u: goto label_11c460;
            case 0x11C470u: goto label_11c470;
            case 0x11C498u: goto label_11c498;
            case 0x11C4A8u: goto label_11c4a8;
            case 0x11C4BCu: goto label_11c4bc;
            case 0x11C4ECu: goto label_11c4ec;
            case 0x11C4FCu: goto label_11c4fc;
            case 0x11C520u: goto label_11c520;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11C52Cu;
    // 0x11c52c: 0x0  nop
    ctx->pc = 0x11c52cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
