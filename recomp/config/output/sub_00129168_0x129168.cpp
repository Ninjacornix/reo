#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129168
// Address: 0x129168 - 0x129240
void sub_00129168_0x129168(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129168_0x129168");
#endif

    switch (ctx->pc) {
        case 0x12919cu: goto label_12919c;
        case 0x1291c4u: goto label_1291c4;
        case 0x1291f4u: goto label_1291f4;
        case 0x1291fcu: goto label_1291fc;
        case 0x129210u: goto label_129210;
        default: break;
    }

    ctx->pc = 0x129168u;

    // 0x129168: 0x27bdfed0  addiu       $sp, $sp, -0x130
    ctx->pc = 0x129168u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966992));
    // 0x12916c: 0xffb00110  sd          $s0, 0x110($sp)
    ctx->pc = 0x12916cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 272), GPR_U64(ctx, 16));
    // 0x129170: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x129170u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129174: 0xffb10118  sd          $s1, 0x118($sp)
    ctx->pc = 0x129174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 280), GPR_U64(ctx, 17));
    // 0x129178: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x129178u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12917c: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x12917cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129180: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x129180u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129184: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x129184u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129188: 0x27a70100  addiu       $a3, $sp, 0x100
    ctx->pc = 0x129188u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
    // 0x12918c: 0x27a80104  addiu       $t0, $sp, 0x104
    ctx->pc = 0x12918cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 260));
    // 0x129190: 0xffbf0120  sd          $ra, 0x120($sp)
    ctx->pc = 0x129190u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 288), GPR_U64(ctx, 31));
    // 0x129194: 0xc04a786  jal         func_129E18
    ctx->pc = 0x129194u;
    SET_GPR_U32(ctx, 31, 0x12919Cu);
    ctx->pc = 0x129198u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129194u;
            // 0x129198: 0x27a90108  addiu       $t1, $sp, 0x108 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 29), 264));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129E18u;
    if (runtime->hasFunction(0x129E18u)) {
        auto targetFn = runtime->lookupFunction(0x129E18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12919Cu; }
        if (ctx->pc != 0x12919Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129E18_0x129e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12919Cu; }
        if (ctx->pc != 0x12919Cu) { return; }
    }
    ctx->pc = 0x12919Cu;
label_12919c:
    // 0x12919c: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x12919Cu;
    {
        const bool branch_taken_0x12919c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1291A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12919Cu;
            // 0x1291a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12919c) {
            ctx->pc = 0x1291B0u;
            goto label_1291b0;
        }
    }
    ctx->pc = 0x1291A4u;
    // 0x1291a4: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1291A4u;
    {
        const bool branch_taken_0x1291a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1291A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1291A4u;
            // 0x1291a8: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1291a4) {
            ctx->pc = 0x129228u;
            goto label_129228;
        }
    }
    ctx->pc = 0x1291ACu;
    // 0x1291ac: 0x0  nop
    ctx->pc = 0x1291acu;
    // NOP
label_1291b0:
    // 0x1291b0: 0x8fa30100  lw          $v1, 0x100($sp)
    ctx->pc = 0x1291b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 256)));
    // 0x1291b4: 0x8fa20104  lw          $v0, 0x104($sp)
    ctx->pc = 0x1291b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 260)));
    // 0x1291b8: 0xae230034  sw          $v1, 0x34($s1)
    ctx->pc = 0x1291b8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 3));
    // 0x1291bc: 0xc04a7dc  jal         func_129F70
    ctx->pc = 0x1291BCu;
    SET_GPR_U32(ctx, 31, 0x1291C4u);
    ctx->pc = 0x1291C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1291BCu;
            // 0x1291c0: 0xae220030  sw          $v0, 0x30($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 48), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129F70u;
    if (runtime->hasFunction(0x129F70u)) {
        auto targetFn = runtime->lookupFunction(0x129F70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1291C4u; }
        if (ctx->pc != 0x1291C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129F70_0x129f70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1291C4u; }
        if (ctx->pc != 0x1291C4u) { return; }
    }
    ctx->pc = 0x1291C4u;
label_1291c4:
    // 0x1291c4: 0xae200014  sw          $zero, 0x14($s1)
    ctx->pc = 0x1291c4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 0));
    // 0x1291c8: 0x8e260034  lw          $a2, 0x34($s1)
    ctx->pc = 0x1291c8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 52)));
    // 0x1291cc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1291ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1291d0: 0x8fa30108  lw          $v1, 0x108($sp)
    ctx->pc = 0x1291d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 264)));
    // 0x1291d4: 0x8fa40104  lw          $a0, 0x104($sp)
    ctx->pc = 0x1291d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 260)));
    // 0x1291d8: 0xae230040  sw          $v1, 0x40($s1)
    ctx->pc = 0x1291d8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 64), GPR_U32(ctx, 3));
    // 0x1291dc: 0x60402d  daddu       $t0, $v1, $zero
    ctx->pc = 0x1291dcu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1291e0: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1291e0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1291e4: 0xae220038  sw          $v0, 0x38($s1)
    ctx->pc = 0x1291e4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 56), GPR_U32(ctx, 2));
    // 0x1291e8: 0xae24003c  sw          $a0, 0x3C($s1)
    ctx->pc = 0x1291e8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 60), GPR_U32(ctx, 4));
    // 0x1291ec: 0xc04c13a  jal         func_1304E8
    ctx->pc = 0x1291ECu;
    SET_GPR_U32(ctx, 31, 0x1291F4u);
    ctx->pc = 0x1291F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1291ECu;
            // 0x1291f0: 0x8e240004  lw          $a0, 0x4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1304E8u;
    if (runtime->hasFunction(0x1304E8u)) {
        auto targetFn = runtime->lookupFunction(0x1304E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1291F4u; }
        if (ctx->pc != 0x1291F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001304E8_0x1304e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1291F4u; }
        if (ctx->pc != 0x1291F4u) { return; }
    }
    ctx->pc = 0x1291F4u;
label_1291f4:
    // 0x1291f4: 0xc04c16e  jal         func_1305B8
    ctx->pc = 0x1291F4u;
    SET_GPR_U32(ctx, 31, 0x1291FCu);
    ctx->pc = 0x1291F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1291F4u;
            // 0x1291f8: 0x8e240004  lw          $a0, 0x4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305B8u;
    if (runtime->hasFunction(0x1305B8u)) {
        auto targetFn = runtime->lookupFunction(0x1305B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1291FCu; }
        if (ctx->pc != 0x1291FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305B8_0x1305b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1291FCu; }
        if (ctx->pc != 0x1291FCu) { return; }
    }
    ctx->pc = 0x1291FCu;
label_1291fc:
    // 0x1291fc: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1291fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x129200: 0x54430005  bnel        $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x129200u;
    {
        const bool branch_taken_0x129200 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x129200) {
            ctx->pc = 0x129204u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129200u;
            // 0x129204: 0x8fa40108  lw          $a0, 0x108($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 264)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129218u;
            goto label_129218;
        }
    }
    ctx->pc = 0x129208u;
    // 0x129208: 0xc04c158  jal         func_130560
    ctx->pc = 0x129208u;
    SET_GPR_U32(ctx, 31, 0x129210u);
    ctx->pc = 0x12920Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129208u;
            // 0x12920c: 0x8e240004  lw          $a0, 0x4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130560u;
    if (runtime->hasFunction(0x130560u)) {
        auto targetFn = runtime->lookupFunction(0x130560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129210u; }
        if (ctx->pc != 0x129210u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130560_0x130560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129210u; }
        if (ctx->pc != 0x129210u) { return; }
    }
    ctx->pc = 0x129210u;
label_129210:
    // 0x129210: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x129210u;
    {
        const bool branch_taken_0x129210 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129210u;
            // 0x129214: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129210) {
            ctx->pc = 0x129228u;
            goto label_129228;
        }
    }
    ctx->pc = 0x129218u;
label_129218:
    // 0x129218: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x129218u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12921c: 0x41ac0  sll         $v1, $a0, 11
    ctx->pc = 0x12921cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 11));
    // 0x129220: 0xae24000c  sw          $a0, 0xC($s1)
    ctx->pc = 0x129220u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 4));
    // 0x129224: 0xae230010  sw          $v1, 0x10($s1)
    ctx->pc = 0x129224u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 3));
label_129228:
    // 0x129228: 0xdfb00110  ld          $s0, 0x110($sp)
    ctx->pc = 0x129228u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 272)));
    // 0x12922c: 0xdfb10118  ld          $s1, 0x118($sp)
    ctx->pc = 0x12922cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 280)));
    // 0x129230: 0xdfbf0120  ld          $ra, 0x120($sp)
    ctx->pc = 0x129230u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 288)));
    // 0x129234: 0x3e00008  jr          $ra
    ctx->pc = 0x129234u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129234u;
            // 0x129238: 0x27bd0130  addiu       $sp, $sp, 0x130 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12919Cu: goto label_12919c;
            case 0x1291B0u: goto label_1291b0;
            case 0x1291C4u: goto label_1291c4;
            case 0x1291F4u: goto label_1291f4;
            case 0x1291FCu: goto label_1291fc;
            case 0x129210u: goto label_129210;
            case 0x129218u: goto label_129218;
            case 0x129228u: goto label_129228;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12923Cu;
    // 0x12923c: 0x0  nop
    ctx->pc = 0x12923cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
