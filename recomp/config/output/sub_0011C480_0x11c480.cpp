#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011C480
// Address: 0x11c480 - 0x11c510
void sub_0011C480_0x11c480(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011C480_0x11c480");
#endif

    switch (ctx->pc) {
        case 0x11c498u: goto label_11c498;
        case 0x11c4a8u: goto label_11c4a8;
        case 0x11c4ecu: goto label_11c4ec;
        default: break;
    }

    ctx->pc = 0x11c480u;

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
            case 0x11C498u: goto label_11c498;
            case 0x11C4A8u: goto label_11c4a8;
            case 0x11C4BCu: goto label_11c4bc;
            case 0x11C4ECu: goto label_11c4ec;
            case 0x11C4FCu: goto label_11c4fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11C510u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
