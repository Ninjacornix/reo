#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00117380
// Address: 0x117380 - 0x11744c
void sub_00117380_0x117380(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00117380_0x117380");
#endif

    switch (ctx->pc) {
        case 0x1173f4u: goto label_1173f4;
        case 0x117428u: goto label_117428;
        case 0x117430u: goto label_117430;
        default: break;
    }

    ctx->pc = 0x117380u;

    // 0x117380: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x117380u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x117384: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x117384u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x117388: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x117388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11738c: 0x3442000a  ori         $v0, $v0, 0xA
    ctx->pc = 0x11738cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)10);
    // 0x117390: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x117390u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x117394: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x117394u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117398: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x117398u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11739c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11739cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1173a0: 0x8e430020  lw          $v1, 0x20($s2)
    ctx->pc = 0x1173a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 32)));
    // 0x1173a4: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1173A4u;
    {
        const bool branch_taken_0x1173a4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1173A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1173A4u;
            // 0x1173a8: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1173a4) {
            ctx->pc = 0x1173CCu;
            goto label_1173cc;
        }
    }
    ctx->pc = 0x1173ACu;
    // 0x1173ac: 0x14400019  bnez        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1173ACu;
    {
        const bool branch_taken_0x1173ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1173B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1173ACu;
            // 0x1173b0: 0x8e51001c  lw          $s1, 0x1C($s2) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1173ac) {
            ctx->pc = 0x117414u;
            goto label_117414;
        }
    }
    ctx->pc = 0x1173B4u;
    // 0x1173b4: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1173b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1173b8: 0x34420009  ori         $v0, $v0, 0x9
    ctx->pc = 0x1173b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)9);
    // 0x1173bc: 0x10620011  beq         $v1, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1173BCu;
    {
        const bool branch_taken_0x1173bc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1173bc) {
            ctx->pc = 0x117404u;
            goto label_117404;
        }
    }
    ctx->pc = 0x1173C4u;
    // 0x1173c4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1173C4u;
    {
        const bool branch_taken_0x1173c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1173C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1173C4u;
            // 0x1173c8: 0x8e240008  lw          $a0, 0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1173c4) {
            ctx->pc = 0x117418u;
            goto label_117418;
        }
    }
    ctx->pc = 0x1173CCu;
label_1173cc:
    // 0x1173cc: 0x8e51001c  lw          $s1, 0x1C($s2)
    ctx->pc = 0x1173ccu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
    // 0x1173d0: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x1173d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1173d4: 0x50400010  beql        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x1173D4u;
    {
        const bool branch_taken_0x1173d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1173d4) {
            ctx->pc = 0x1173D8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1173D4u;
            // 0x1173d8: 0x8e240008  lw          $a0, 0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x117418u;
            goto label_117418;
        }
    }
    ctx->pc = 0x1173DCu;
    // 0x1173dc: 0x8e220018  lw          $v0, 0x18($s1)
    ctx->pc = 0x1173dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1173e0: 0x380802d  daddu       $s0, $gp, $zero
    ctx->pc = 0x1173e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1173e4: 0x40e02d  daddu       $gp, $v0, $zero
    ctx->pc = 0x1173e4u;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1173e8: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x1173e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1173ec: 0x40f809  jalr        $v0
    ctx->pc = 0x1173ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1173F4u);
        ctx->pc = 0x1173F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1173ECu;
            // 0x1173f0: 0x8e240020  lw          $a0, 0x20($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1173F4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1173CCu: goto label_1173cc;
            case 0x1173F4u: goto label_1173f4;
            case 0x117404u: goto label_117404;
            case 0x117414u: goto label_117414;
            case 0x117418u: goto label_117418;
            case 0x117428u: goto label_117428;
            case 0x117430u: goto label_117430;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1173F4u; }
            if (ctx->pc != 0x1173F4u) { return; }
        }
        }
    }
    ctx->pc = 0x1173F4u;
label_1173f4:
    // 0x1173f4: 0x380182d  daddu       $v1, $gp, $zero
    ctx->pc = 0x1173f4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1173f8: 0x200e02d  daddu       $gp, $s0, $zero
    ctx->pc = 0x1173f8u;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1173fc: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1173FCu;
    {
        const bool branch_taken_0x1173fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x117400u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1173FCu;
            // 0x117400: 0x8e51001c  lw          $s1, 0x1C($s2) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1173fc) {
            ctx->pc = 0x117414u;
            goto label_117414;
        }
    }
    ctx->pc = 0x117404u;
label_117404:
    // 0x117404: 0x8e420024  lw          $v0, 0x24($s2)
    ctx->pc = 0x117404u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 36)));
    // 0x117408: 0xae220024  sw          $v0, 0x24($s1)
    ctx->pc = 0x117408u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
    // 0x11740c: 0x8e430028  lw          $v1, 0x28($s2)
    ctx->pc = 0x11740cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 40)));
    // 0x117410: 0xae230014  sw          $v1, 0x14($s1)
    ctx->pc = 0x117410u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 3));
label_117414:
    // 0x117414: 0x8e240008  lw          $a0, 0x8($s1)
    ctx->pc = 0x117414u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
label_117418:
    // 0x117418: 0x4800003  bltz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x117418u;
    {
        const bool branch_taken_0x117418 = (GPR_S64(ctx, 4) < 0);
        if (branch_taken_0x117418) {
            ctx->pc = 0x117428u;
            goto label_117428;
        }
    }
    ctx->pc = 0x117420u;
    // 0x117420: 0xc045194  jal         func_114650
    ctx->pc = 0x117420u;
    SET_GPR_U32(ctx, 31, 0x117428u);
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117428u; }
        if (ctx->pc != 0x117428u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117428u; }
        if (ctx->pc != 0x117428u) { return; }
    }
    ctx->pc = 0x117428u;
label_117428:
    // 0x117428: 0xc045cbc  jal         func_1172F0
    ctx->pc = 0x117428u;
    SET_GPR_U32(ctx, 31, 0x117430u);
    ctx->pc = 0x11742Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117428u;
            // 0x11742c: 0x8e240000  lw          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1172F0u;
    if (runtime->hasFunction(0x1172F0u)) {
        auto targetFn = runtime->lookupFunction(0x1172F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117430u; }
        if (ctx->pc != 0x117430u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001172F0_0x1172f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117430u; }
        if (ctx->pc != 0x117430u) { return; }
    }
    ctx->pc = 0x117430u;
label_117430:
    // 0x117430: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x117430u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x117434: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x117434u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x117438: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x117438u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11743c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11743cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x117440: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x117440u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117444: 0x3e00008  jr          $ra
    ctx->pc = 0x117444u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x117448u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117444u;
            // 0x117448: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1173CCu: goto label_1173cc;
            case 0x1173F4u: goto label_1173f4;
            case 0x117404u: goto label_117404;
            case 0x117414u: goto label_117414;
            case 0x117418u: goto label_117418;
            case 0x117428u: goto label_117428;
            case 0x117430u: goto label_117430;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11744Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
