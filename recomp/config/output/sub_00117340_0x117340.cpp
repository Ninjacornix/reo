#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00117340
// Address: 0x117340 - 0x1176b8
void sub_00117340_0x117340(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00117340_0x117340");
#endif

    switch (ctx->pc) {
        case 0x117364u: goto label_117364;
        case 0x1173f4u: goto label_1173f4;
        case 0x117428u: goto label_117428;
        case 0x117430u: goto label_117430;
        case 0x117478u: goto label_117478;
        case 0x1174c0u: goto label_1174c0;
        case 0x1174d0u: goto label_1174d0;
        case 0x117528u: goto label_117528;
        case 0x1175a0u: goto label_1175a0;
        case 0x1175e8u: goto label_1175e8;
        case 0x1175f8u: goto label_1175f8;
        case 0x117620u: goto label_117620;
        case 0x117630u: goto label_117630;
        case 0x117638u: goto label_117638;
        case 0x117648u: goto label_117648;
        case 0x117650u: goto label_117650;
        case 0x117680u: goto label_117680;
        case 0x117690u: goto label_117690;
        default: break;
    }

    ctx->pc = 0x117340u;

label_117340:
    // 0x117340: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x117340u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x117344: 0x4a00005  bltz        $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x117344u;
    {
        const bool branch_taken_0x117344 = (GPR_S64(ctx, 5) < 0);
        ctx->pc = 0x117348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117344u;
            // 0x117348: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117344) {
            ctx->pc = 0x11735Cu;
            goto label_11735c;
        }
    }
    ctx->pc = 0x11734Cu;
    // 0x11734c: 0x8c820020  lw          $v0, 0x20($a0)
    ctx->pc = 0x11734cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x117350: 0xa2102a  slt         $v0, $a1, $v0
    ctx->pc = 0x117350u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x117354: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x117354u;
    {
        const bool branch_taken_0x117354 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x117354) {
            ctx->pc = 0x117358u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x117354u;
            // 0x117358: 0x8c83001c  lw          $v1, 0x1C($a0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11736Cu;
            goto label_11736c;
        }
    }
    ctx->pc = 0x11735Cu;
label_11735c:
    // 0x11735c: 0xc045cc4  jal         func_117310
    ctx->pc = 0x11735Cu;
    SET_GPR_U32(ctx, 31, 0x117364u);
    ctx->pc = 0x117310u;
    if (runtime->hasFunction(0x117310u)) {
        auto targetFn = runtime->lookupFunction(0x117310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117364u; }
        if (ctx->pc != 0x117364u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117310_0x117310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117364u; }
        if (ctx->pc != 0x117364u) { return; }
    }
    ctx->pc = 0x117364u;
label_117364:
    // 0x117364: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x117364u;
    {
        const bool branch_taken_0x117364 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x117368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117364u;
            // 0x117368: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117364) {
            ctx->pc = 0x117378u;
            goto label_117378;
        }
    }
    ctx->pc = 0x11736Cu;
label_11736c:
    // 0x11736c: 0x51180  sll         $v0, $a1, 6
    ctx->pc = 0x11736cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 6));
    // 0x117370: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x117370u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x117374: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x117374u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_117378:
    // 0x117378: 0x3e00008  jr          $ra
    ctx->pc = 0x117378u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11737Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117378u;
            // 0x11737c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117340u: goto label_117340;
            case 0x11735Cu: goto label_11735c;
            case 0x117364u: goto label_117364;
            case 0x11736Cu: goto label_11736c;
            case 0x117378u: goto label_117378;
            case 0x1173CCu: goto label_1173cc;
            case 0x1173F4u: goto label_1173f4;
            case 0x117404u: goto label_117404;
            case 0x117414u: goto label_117414;
            case 0x117418u: goto label_117418;
            case 0x117428u: goto label_117428;
            case 0x117430u: goto label_117430;
            case 0x117478u: goto label_117478;
            case 0x1174C0u: goto label_1174c0;
            case 0x1174C8u: goto label_1174c8;
            case 0x1174D0u: goto label_1174d0;
            case 0x1174D4u: goto label_1174d4;
            case 0x117528u: goto label_117528;
            case 0x117550u: goto label_117550;
            case 0x1175A0u: goto label_1175a0;
            case 0x1175E8u: goto label_1175e8;
            case 0x1175F8u: goto label_1175f8;
            case 0x117600u: goto label_117600;
            case 0x117620u: goto label_117620;
            case 0x117630u: goto label_117630;
            case 0x117638u: goto label_117638;
            case 0x117640u: goto label_117640;
            case 0x117648u: goto label_117648;
            case 0x117650u: goto label_117650;
            case 0x117658u: goto label_117658;
            case 0x117680u: goto label_117680;
            case 0x117690u: goto label_117690;
            case 0x117694u: goto label_117694;
            default: break;
        }
        return;
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
            case 0x117340u: goto label_117340;
            case 0x11735Cu: goto label_11735c;
            case 0x117364u: goto label_117364;
            case 0x11736Cu: goto label_11736c;
            case 0x117378u: goto label_117378;
            case 0x1173CCu: goto label_1173cc;
            case 0x1173F4u: goto label_1173f4;
            case 0x117404u: goto label_117404;
            case 0x117414u: goto label_117414;
            case 0x117418u: goto label_117418;
            case 0x117428u: goto label_117428;
            case 0x117430u: goto label_117430;
            case 0x117478u: goto label_117478;
            case 0x1174C0u: goto label_1174c0;
            case 0x1174C8u: goto label_1174c8;
            case 0x1174D0u: goto label_1174d0;
            case 0x1174D4u: goto label_1174d4;
            case 0x117528u: goto label_117528;
            case 0x117550u: goto label_117550;
            case 0x1175A0u: goto label_1175a0;
            case 0x1175E8u: goto label_1175e8;
            case 0x1175F8u: goto label_1175f8;
            case 0x117600u: goto label_117600;
            case 0x117620u: goto label_117620;
            case 0x117630u: goto label_117630;
            case 0x117638u: goto label_117638;
            case 0x117640u: goto label_117640;
            case 0x117648u: goto label_117648;
            case 0x117650u: goto label_117650;
            case 0x117658u: goto label_117658;
            case 0x117680u: goto label_117680;
            case 0x117690u: goto label_117690;
            case 0x117694u: goto label_117694;
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
            case 0x117340u: goto label_117340;
            case 0x11735Cu: goto label_11735c;
            case 0x117364u: goto label_117364;
            case 0x11736Cu: goto label_11736c;
            case 0x117378u: goto label_117378;
            case 0x1173CCu: goto label_1173cc;
            case 0x1173F4u: goto label_1173f4;
            case 0x117404u: goto label_117404;
            case 0x117414u: goto label_117414;
            case 0x117418u: goto label_117418;
            case 0x117428u: goto label_117428;
            case 0x117430u: goto label_117430;
            case 0x117478u: goto label_117478;
            case 0x1174C0u: goto label_1174c0;
            case 0x1174C8u: goto label_1174c8;
            case 0x1174D0u: goto label_1174d0;
            case 0x1174D4u: goto label_1174d4;
            case 0x117528u: goto label_117528;
            case 0x117550u: goto label_117550;
            case 0x1175A0u: goto label_1175a0;
            case 0x1175E8u: goto label_1175e8;
            case 0x1175F8u: goto label_1175f8;
            case 0x117600u: goto label_117600;
            case 0x117620u: goto label_117620;
            case 0x117630u: goto label_117630;
            case 0x117638u: goto label_117638;
            case 0x117640u: goto label_117640;
            case 0x117648u: goto label_117648;
            case 0x117650u: goto label_117650;
            case 0x117658u: goto label_117658;
            case 0x117680u: goto label_117680;
            case 0x117690u: goto label_117690;
            case 0x117694u: goto label_117694;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11744Cu;
    // 0x11744c: 0x0  nop
    ctx->pc = 0x11744cu;
    // NOP
    // 0x117450: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x117450u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x117454: 0xe0282d  daddu       $a1, $a3, $zero
    ctx->pc = 0x117454u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117458: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x117458u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11745c: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x11745cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x117460: 0x34840008  ori         $a0, $a0, 0x8
    ctx->pc = 0x117460u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)8);
    // 0x117464: 0x24060040  addiu       $a2, $zero, 0x40
    ctx->pc = 0x117464u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x117468: 0x8ca70024  lw          $a3, 0x24($a1)
    ctx->pc = 0x117468u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 36)));
    // 0x11746c: 0x8ca80028  lw          $t0, 0x28($a1)
    ctx->pc = 0x11746cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 40)));
    // 0x117470: 0xc045b92  jal         func_116E48
    ctx->pc = 0x117470u;
    SET_GPR_U32(ctx, 31, 0x117478u);
    ctx->pc = 0x117474u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117470u;
            // 0x117474: 0x8ca9002c  lw          $t1, 0x2C($a1) (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 44)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116E48u;
    if (runtime->hasFunction(0x116E48u)) {
        auto targetFn = runtime->lookupFunction(0x116E48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117478u; }
        if (ctx->pc != 0x117478u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116E48_0x116e48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117478u; }
        if (ctx->pc != 0x117478u) { return; }
    }
    ctx->pc = 0x117478u;
label_117478:
    // 0x117478: 0x24030800  addiu       $v1, $zero, 0x800
    ctx->pc = 0x117478u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x11747c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11747cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117480: 0x2180b  movn        $v1, $zero, $v0
    ctx->pc = 0x117480u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
    // 0x117484: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x117484u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117488: 0x3e00008  jr          $ra
    ctx->pc = 0x117488u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11748Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117488u;
            // 0x11748c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117340u: goto label_117340;
            case 0x11735Cu: goto label_11735c;
            case 0x117364u: goto label_117364;
            case 0x11736Cu: goto label_11736c;
            case 0x117378u: goto label_117378;
            case 0x1173CCu: goto label_1173cc;
            case 0x1173F4u: goto label_1173f4;
            case 0x117404u: goto label_117404;
            case 0x117414u: goto label_117414;
            case 0x117418u: goto label_117418;
            case 0x117428u: goto label_117428;
            case 0x117430u: goto label_117430;
            case 0x117478u: goto label_117478;
            case 0x1174C0u: goto label_1174c0;
            case 0x1174C8u: goto label_1174c8;
            case 0x1174D0u: goto label_1174d0;
            case 0x1174D4u: goto label_1174d4;
            case 0x117528u: goto label_117528;
            case 0x117550u: goto label_117550;
            case 0x1175A0u: goto label_1175a0;
            case 0x1175E8u: goto label_1175e8;
            case 0x1175F8u: goto label_1175f8;
            case 0x117600u: goto label_117600;
            case 0x117620u: goto label_117620;
            case 0x117630u: goto label_117630;
            case 0x117638u: goto label_117638;
            case 0x117640u: goto label_117640;
            case 0x117648u: goto label_117648;
            case 0x117650u: goto label_117650;
            case 0x117658u: goto label_117658;
            case 0x117680u: goto label_117680;
            case 0x117690u: goto label_117690;
            case 0x117694u: goto label_117694;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117490u;
    // 0x117490: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x117490u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x117494: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x117494u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x117498: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x117498u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11749c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11749cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1174a0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1174a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1174a4: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1174a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1174a8: 0x8e250010  lw          $a1, 0x10($s1)
    ctx->pc = 0x1174a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1174ac: 0x30a20004  andi        $v0, $a1, 0x4
    ctx->pc = 0x1174acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)4);
    // 0x1174b0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1174B0u;
    {
        const bool branch_taken_0x1174b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1174b0) {
            ctx->pc = 0x1174C8u;
            goto label_1174c8;
        }
    }
    ctx->pc = 0x1174B8u;
    // 0x1174b8: 0xc045cd0  jal         func_117340
    ctx->pc = 0x1174B8u;
    SET_GPR_U32(ctx, 31, 0x1174C0u);
    ctx->pc = 0x1174BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1174B8u;
            // 0x1174bc: 0x52c02  srl         $a1, $a1, 16 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117340u;
    goto label_117340;
    ctx->pc = 0x1174C0u;
label_1174c0:
    // 0x1174c0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1174C0u;
    {
        const bool branch_taken_0x1174c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1174C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1174C0u;
            // 0x1174c4: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1174c0) {
            ctx->pc = 0x1174D4u;
            goto label_1174d4;
        }
    }
    ctx->pc = 0x1174C8u;
label_1174c8:
    // 0x1174c8: 0xc045cc4  jal         func_117310
    ctx->pc = 0x1174C8u;
    SET_GPR_U32(ctx, 31, 0x1174D0u);
    ctx->pc = 0x117310u;
    if (runtime->hasFunction(0x117310u)) {
        auto targetFn = runtime->lookupFunction(0x117310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1174D0u; }
        if (ctx->pc != 0x1174D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117310_0x117310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1174D0u; }
        if (ctx->pc != 0x1174D0u) { return; }
    }
    ctx->pc = 0x1174D0u;
label_1174d0:
    // 0x1174d0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1174d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1174d4:
    // 0x1174d4: 0x8e230014  lw          $v1, 0x14($s1)
    ctx->pc = 0x1174d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1174d8: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1174d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1174dc: 0x8e25001c  lw          $a1, 0x1C($s1)
    ctx->pc = 0x1174dcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1174e0: 0x3442000c  ori         $v0, $v0, 0xC
    ctx->pc = 0x1174e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)12);
    // 0x1174e4: 0xae030014  sw          $v1, 0x14($s0)
    ctx->pc = 0x1174e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
    // 0x1174e8: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x1174e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x1174ec: 0xae05001c  sw          $a1, 0x1C($s0)
    ctx->pc = 0x1174ecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 5));
    // 0x1174f0: 0x34840008  ori         $a0, $a0, 0x8
    ctx->pc = 0x1174f0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)8);
    // 0x1174f4: 0xae020020  sw          $v0, 0x20($s0)
    ctx->pc = 0x1174f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
    // 0x1174f8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1174f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1174fc: 0x24060040  addiu       $a2, $zero, 0x40
    ctx->pc = 0x1174fcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x117500: 0x8e220020  lw          $v0, 0x20($s1)
    ctx->pc = 0x117500u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x117504: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x117504u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
    // 0x117508: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x117508u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x11750c: 0xae030028  sw          $v1, 0x28($s0)
    ctx->pc = 0x11750cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 3));
    // 0x117510: 0x8e220028  lw          $v0, 0x28($s1)
    ctx->pc = 0x117510u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 40)));
    // 0x117514: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x117514u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x117518: 0x8e290028  lw          $t1, 0x28($s1)
    ctx->pc = 0x117518u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 40)));
    // 0x11751c: 0x8e270020  lw          $a3, 0x20($s1)
    ctx->pc = 0x11751cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x117520: 0xc045b92  jal         func_116E48
    ctx->pc = 0x117520u;
    SET_GPR_U32(ctx, 31, 0x117528u);
    ctx->pc = 0x117524u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117520u;
            // 0x117524: 0x8e280024  lw          $t0, 0x24($s1) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116E48u;
    if (runtime->hasFunction(0x116E48u)) {
        auto targetFn = runtime->lookupFunction(0x116E48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117528u; }
        if (ctx->pc != 0x117528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116E48_0x116e48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117528u; }
        if (ctx->pc != 0x117528u) { return; }
    }
    ctx->pc = 0x117528u;
label_117528:
    // 0x117528: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x117528u;
    {
        const bool branch_taken_0x117528 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11752Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117528u;
            // 0x11752c: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117528) {
            ctx->pc = 0x117550u;
            goto label_117550;
        }
    }
    ctx->pc = 0x117530u;
    // 0x117530: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x117530u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117534: 0x3c050011  lui         $a1, 0x11
    ctx->pc = 0x117534u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)17 << 16));
    // 0x117538: 0x24a57450  addiu       $a1, $a1, 0x7450
    ctx->pc = 0x117538u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29776));
    // 0x11753c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11753cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x117540: 0x24040800  addiu       $a0, $zero, 0x800
    ctx->pc = 0x117540u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x117544: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x117544u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117548: 0x8047d02  j           func_11F408
    ctx->pc = 0x117548u;
    ctx->pc = 0x11754Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117548u;
            // 0x11754c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11F408u;
    if (runtime->hasFunction(0x11F408u)) {
        auto targetFn = runtime->lookupFunction(0x11F408u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011F408_0x11f408(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x117550u;
label_117550:
    // 0x117550: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x117550u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x117554: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x117554u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117558: 0x3e00008  jr          $ra
    ctx->pc = 0x117558u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11755Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117558u;
            // 0x11755c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117340u: goto label_117340;
            case 0x11735Cu: goto label_11735c;
            case 0x117364u: goto label_117364;
            case 0x11736Cu: goto label_11736c;
            case 0x117378u: goto label_117378;
            case 0x1173CCu: goto label_1173cc;
            case 0x1173F4u: goto label_1173f4;
            case 0x117404u: goto label_117404;
            case 0x117414u: goto label_117414;
            case 0x117418u: goto label_117418;
            case 0x117428u: goto label_117428;
            case 0x117430u: goto label_117430;
            case 0x117478u: goto label_117478;
            case 0x1174C0u: goto label_1174c0;
            case 0x1174C8u: goto label_1174c8;
            case 0x1174D0u: goto label_1174d0;
            case 0x1174D4u: goto label_1174d4;
            case 0x117528u: goto label_117528;
            case 0x117550u: goto label_117550;
            case 0x1175A0u: goto label_1175a0;
            case 0x1175E8u: goto label_1175e8;
            case 0x1175F8u: goto label_1175f8;
            case 0x117600u: goto label_117600;
            case 0x117620u: goto label_117620;
            case 0x117630u: goto label_117630;
            case 0x117638u: goto label_117638;
            case 0x117640u: goto label_117640;
            case 0x117648u: goto label_117648;
            case 0x117650u: goto label_117650;
            case 0x117658u: goto label_117658;
            case 0x117680u: goto label_117680;
            case 0x117690u: goto label_117690;
            case 0x117694u: goto label_117694;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117560u;
    // 0x117560: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x117560u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x117564: 0xffb10030  sd          $s1, 0x30($sp)
    ctx->pc = 0x117564u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x117568: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x117568u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11756c: 0xffb50070  sd          $s5, 0x70($sp)
    ctx->pc = 0x11756cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 21));
    // 0x117570: 0xffb40060  sd          $s4, 0x60($sp)
    ctx->pc = 0x117570u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x117574: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x117574u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x117578: 0xffb30050  sd          $s3, 0x50($sp)
    ctx->pc = 0x117578u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x11757c: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x11757cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117580: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x117580u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x117584: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x117584u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117588: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x117588u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x11758c: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x11758cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117590: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x117590u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x117594: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x117594u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117598: 0xc045c92  jal         func_117248
    ctx->pc = 0x117598u;
    SET_GPR_U32(ctx, 31, 0x1175A0u);
    ctx->pc = 0x11759Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117598u;
            // 0x11759c: 0x2484c9c0  addiu       $a0, $a0, -0x3640 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953408));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117248u;
    if (runtime->hasFunction(0x117248u)) {
        auto targetFn = runtime->lookupFunction(0x117248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1175A0u; }
        if (ctx->pc != 0x1175A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117248_0x117248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1175A0u; }
        if (ctx->pc != 0x1175A0u) { return; }
    }
    ctx->pc = 0x1175A0u;
label_1175a0:
    // 0x1175a0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1175a0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1175a4: 0x1200003b  beqz        $s0, . + 4 + (0x3B << 2)
    ctx->pc = 0x1175A4u;
    {
        const bool branch_taken_0x1175a4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1175A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1175A4u;
            // 0x1175a8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1175a4) {
            ctx->pc = 0x117694u;
            goto label_117694;
        }
    }
    ctx->pc = 0x1175ACu;
    // 0x1175ac: 0x8e020018  lw          $v0, 0x18($s0)
    ctx->pc = 0x1175acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x1175b0: 0x32430001  andi        $v1, $s2, 0x1
    ctx->pc = 0x1175b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)1);
    // 0x1175b4: 0xae300000  sw          $s0, 0x0($s1)
    ctx->pc = 0x1175b4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0x1175b8: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x1175b8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x1175bc: 0xae130020  sw          $s3, 0x20($s0)
    ctx->pc = 0x1175bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 19));
    // 0x1175c0: 0xae140024  sw          $s4, 0x24($s0)
    ctx->pc = 0x1175c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 20));
    // 0x1175c4: 0xae150028  sw          $s5, 0x28($s0)
    ctx->pc = 0x1175c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 21));
    // 0x1175c8: 0xae100014  sw          $s0, 0x14($s0)
    ctx->pc = 0x1175c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 16));
    // 0x1175cc: 0x14600022  bnez        $v1, . + 4 + (0x22 << 2)
    ctx->pc = 0x1175CCu;
    {
        const bool branch_taken_0x1175cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1175D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1175CCu;
            // 0x1175d0: 0xae11001c  sw          $s1, 0x1C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1175cc) {
            ctx->pc = 0x117658u;
            goto label_117658;
        }
    }
    ctx->pc = 0x1175D4u;
    // 0x1175d4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1175d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1175d8: 0xafa00008  sw          $zero, 0x8($sp)
    ctx->pc = 0x1175d8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 0));
    // 0x1175dc: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x1175dcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x1175e0: 0xc045188  jal         func_114620
    ctx->pc = 0x1175E0u;
    SET_GPR_U32(ctx, 31, 0x1175E8u);
    ctx->pc = 0x1175E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1175E0u;
            // 0x1175e4: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1175E8u; }
        if (ctx->pc != 0x1175E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1175E8u; }
        if (ctx->pc != 0x1175E8u) { return; }
    }
    ctx->pc = 0x1175E8u;
label_1175e8:
    // 0x1175e8: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1175E8u;
    {
        const bool branch_taken_0x1175e8 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1175ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1175E8u;
            // 0x1175ec: 0xae220008  sw          $v0, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1175e8) {
            ctx->pc = 0x117600u;
            goto label_117600;
        }
    }
    ctx->pc = 0x1175F0u;
    // 0x1175f0: 0xc045cbc  jal         func_1172F0
    ctx->pc = 0x1175F0u;
    SET_GPR_U32(ctx, 31, 0x1175F8u);
    ctx->pc = 0x1175F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1175F0u;
            // 0x1175f4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1172F0u;
    if (runtime->hasFunction(0x1172F0u)) {
        auto targetFn = runtime->lookupFunction(0x1172F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1175F8u; }
        if (ctx->pc != 0x1175F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001172F0_0x1172f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1175F8u; }
        if (ctx->pc != 0x1175F8u) { return; }
    }
    ctx->pc = 0x1175F8u;
label_1175f8:
    // 0x1175f8: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1175F8u;
    {
        const bool branch_taken_0x1175f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1175FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1175F8u;
            // 0x1175fc: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1175f8) {
            ctx->pc = 0x117694u;
            goto label_117694;
        }
    }
    ctx->pc = 0x117600u;
label_117600:
    // 0x117600: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x117600u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x117604: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x117604u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117608: 0x3484000c  ori         $a0, $a0, 0xC
    ctx->pc = 0x117608u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)12);
    // 0x11760c: 0x24060040  addiu       $a2, $zero, 0x40
    ctx->pc = 0x11760cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x117610: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x117610u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117614: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x117614u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117618: 0xc045b82  jal         func_116E08
    ctx->pc = 0x117618u;
    SET_GPR_U32(ctx, 31, 0x117620u);
    ctx->pc = 0x11761Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117618u;
            // 0x11761c: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116E08u;
    if (runtime->hasFunction(0x116E08u)) {
        auto targetFn = runtime->lookupFunction(0x116E08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117620u; }
        if (ctx->pc != 0x117620u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116E08_0x116e08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117620u; }
        if (ctx->pc != 0x117620u) { return; }
    }
    ctx->pc = 0x117620u;
label_117620:
    // 0x117620: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x117620u;
    {
        const bool branch_taken_0x117620 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x117620) {
            ctx->pc = 0x117640u;
            goto label_117640;
        }
    }
    ctx->pc = 0x117628u;
    // 0x117628: 0xc045cbc  jal         func_1172F0
    ctx->pc = 0x117628u;
    SET_GPR_U32(ctx, 31, 0x117630u);
    ctx->pc = 0x11762Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117628u;
            // 0x11762c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1172F0u;
    if (runtime->hasFunction(0x1172F0u)) {
        auto targetFn = runtime->lookupFunction(0x1172F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117630u; }
        if (ctx->pc != 0x117630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001172F0_0x1172f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117630u; }
        if (ctx->pc != 0x117630u) { return; }
    }
    ctx->pc = 0x117630u;
label_117630:
    // 0x117630: 0xc04518c  jal         func_114630
    ctx->pc = 0x117630u;
    SET_GPR_U32(ctx, 31, 0x117638u);
    ctx->pc = 0x117634u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117630u;
            // 0x117634: 0x8e240008  lw          $a0, 0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117638u; }
        if (ctx->pc != 0x117638u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117638u; }
        if (ctx->pc != 0x117638u) { return; }
    }
    ctx->pc = 0x117638u;
label_117638:
    // 0x117638: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x117638u;
    {
        const bool branch_taken_0x117638 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11763Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117638u;
            // 0x11763c: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117638) {
            ctx->pc = 0x117694u;
            goto label_117694;
        }
    }
    ctx->pc = 0x117640u;
label_117640:
    // 0x117640: 0xc045198  jal         func_114660
    ctx->pc = 0x117640u;
    SET_GPR_U32(ctx, 31, 0x117648u);
    ctx->pc = 0x117644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117640u;
            // 0x117644: 0x8e240008  lw          $a0, 0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117648u; }
        if (ctx->pc != 0x117648u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117648u; }
        if (ctx->pc != 0x117648u) { return; }
    }
    ctx->pc = 0x117648u;
label_117648:
    // 0x117648: 0xc04518c  jal         func_114630
    ctx->pc = 0x117648u;
    SET_GPR_U32(ctx, 31, 0x117650u);
    ctx->pc = 0x11764Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117648u;
            // 0x11764c: 0x8e240008  lw          $a0, 0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117650u; }
        if (ctx->pc != 0x117650u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117650u; }
        if (ctx->pc != 0x117650u) { return; }
    }
    ctx->pc = 0x117650u;
label_117650:
    // 0x117650: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x117650u;
    {
        const bool branch_taken_0x117650 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x117654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117650u;
            // 0x117654: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117650) {
            ctx->pc = 0x117694u;
            goto label_117694;
        }
    }
    ctx->pc = 0x117658u;
label_117658:
    // 0x117658: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x117658u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11765c: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x11765cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x117660: 0xae220008  sw          $v0, 0x8($s1)
    ctx->pc = 0x117660u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
    // 0x117664: 0x3484000c  ori         $a0, $a0, 0xC
    ctx->pc = 0x117664u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)12);
    // 0x117668: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x117668u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11766c: 0x24060040  addiu       $a2, $zero, 0x40
    ctx->pc = 0x11766cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x117670: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x117670u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117674: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x117674u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117678: 0xc045b82  jal         func_116E08
    ctx->pc = 0x117678u;
    SET_GPR_U32(ctx, 31, 0x117680u);
    ctx->pc = 0x11767Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117678u;
            // 0x11767c: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116E08u;
    if (runtime->hasFunction(0x116E08u)) {
        auto targetFn = runtime->lookupFunction(0x116E08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117680u; }
        if (ctx->pc != 0x117680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116E08_0x116e08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117680u; }
        if (ctx->pc != 0x117680u) { return; }
    }
    ctx->pc = 0x117680u;
label_117680:
    // 0x117680: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x117680u;
    {
        const bool branch_taken_0x117680 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x117684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117680u;
            // 0x117684: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117680) {
            ctx->pc = 0x117694u;
            goto label_117694;
        }
    }
    ctx->pc = 0x117688u;
    // 0x117688: 0xc045cbc  jal         func_1172F0
    ctx->pc = 0x117688u;
    SET_GPR_U32(ctx, 31, 0x117690u);
    ctx->pc = 0x11768Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117688u;
            // 0x11768c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1172F0u;
    if (runtime->hasFunction(0x1172F0u)) {
        auto targetFn = runtime->lookupFunction(0x1172F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117690u; }
        if (ctx->pc != 0x117690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001172F0_0x1172f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117690u; }
        if (ctx->pc != 0x117690u) { return; }
    }
    ctx->pc = 0x117690u;
label_117690:
    // 0x117690: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x117690u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
label_117694:
    // 0x117694: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x117694u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x117698: 0xdfb50070  ld          $s5, 0x70($sp)
    ctx->pc = 0x117698u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11769c: 0xdfb40060  ld          $s4, 0x60($sp)
    ctx->pc = 0x11769cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1176a0: 0xdfb30050  ld          $s3, 0x50($sp)
    ctx->pc = 0x1176a0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1176a4: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x1176a4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1176a8: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x1176a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1176ac: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x1176acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1176b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1176B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1176B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1176B0u;
            // 0x1176b4: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117340u: goto label_117340;
            case 0x11735Cu: goto label_11735c;
            case 0x117364u: goto label_117364;
            case 0x11736Cu: goto label_11736c;
            case 0x117378u: goto label_117378;
            case 0x1173CCu: goto label_1173cc;
            case 0x1173F4u: goto label_1173f4;
            case 0x117404u: goto label_117404;
            case 0x117414u: goto label_117414;
            case 0x117418u: goto label_117418;
            case 0x117428u: goto label_117428;
            case 0x117430u: goto label_117430;
            case 0x117478u: goto label_117478;
            case 0x1174C0u: goto label_1174c0;
            case 0x1174C8u: goto label_1174c8;
            case 0x1174D0u: goto label_1174d0;
            case 0x1174D4u: goto label_1174d4;
            case 0x117528u: goto label_117528;
            case 0x117550u: goto label_117550;
            case 0x1175A0u: goto label_1175a0;
            case 0x1175E8u: goto label_1175e8;
            case 0x1175F8u: goto label_1175f8;
            case 0x117600u: goto label_117600;
            case 0x117620u: goto label_117620;
            case 0x117630u: goto label_117630;
            case 0x117638u: goto label_117638;
            case 0x117640u: goto label_117640;
            case 0x117648u: goto label_117648;
            case 0x117650u: goto label_117650;
            case 0x117658u: goto label_117658;
            case 0x117680u: goto label_117680;
            case 0x117690u: goto label_117690;
            case 0x117694u: goto label_117694;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1176B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
