#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DA480
// Address: 0x1da480 - 0x1da4cc
void sub_001DA480_0x1da480(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DA480_0x1da480");
#endif

    switch (ctx->pc) {
        case 0x1da494u: goto label_1da494;
        case 0x1da4acu: goto label_1da4ac;
        case 0x1da4b4u: goto label_1da4b4;
        case 0x1da4bcu: goto label_1da4bc;
        default: break;
    }

    ctx->pc = 0x1da480u;

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
            case 0x1DA494u: goto label_1da494;
            case 0x1DA4ACu: goto label_1da4ac;
            case 0x1DA4B4u: goto label_1da4b4;
            case 0x1DA4BCu: goto label_1da4bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DA4CCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
