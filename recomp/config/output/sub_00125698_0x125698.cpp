#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00125698
// Address: 0x125698 - 0x125764
void sub_00125698_0x125698(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00125698_0x125698");
#endif

    switch (ctx->pc) {
        case 0x1256c4u: goto label_1256c4;
        case 0x1256e0u: goto label_1256e0;
        case 0x1256e8u: goto label_1256e8;
        case 0x125710u: goto label_125710;
        case 0x125718u: goto label_125718;
        case 0x125730u: goto label_125730;
        case 0x125738u: goto label_125738;
        case 0x12574cu: goto label_12574c;
        default: break;
    }

    ctx->pc = 0x125698u;

    // 0x125698: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x125698u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12569c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12569cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1256a0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1256a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1256a4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1256a4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1256a8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1256a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1256ac: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1256acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1256b0: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1256b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1256b4: 0x54620012  bnel        $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1256B4u;
    {
        const bool branch_taken_0x1256b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1256b4) {
            ctx->pc = 0x1256B8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1256B4u;
            // 0x1256b8: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125700u;
            goto label_125700;
        }
    }
    ctx->pc = 0x1256BCu;
    // 0x1256bc: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x1256BCu;
    SET_GPR_U32(ctx, 31, 0x1256C4u);
    ctx->pc = 0x1256C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1256BCu;
            // 0x1256c0: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1256C4u; }
        if (ctx->pc != 0x1256C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1256C4u; }
        if (ctx->pc != 0x1256C4u) { return; }
    }
    ctx->pc = 0x1256C4u;
label_1256c4:
    // 0x1256c4: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x1256c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x1256c8: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x1256c8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x1256cc: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1256CCu;
    {
        const bool branch_taken_0x1256cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1256D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1256CCu;
            // 0x1256d0: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1256cc) {
            ctx->pc = 0x1256F8u;
            goto label_1256f8;
        }
    }
    ctx->pc = 0x1256D4u;
    // 0x1256d4: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x1256d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x1256d8: 0x40f809  jalr        $v0
    ctx->pc = 0x1256D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1256E0u);
        ctx->pc = 0x1256DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1256D8u;
            // 0x1256dc: 0x8e04007c  lw          $a0, 0x7C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1256E0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1256C4u: goto label_1256c4;
            case 0x1256E0u: goto label_1256e0;
            case 0x1256E8u: goto label_1256e8;
            case 0x1256F8u: goto label_1256f8;
            case 0x125700u: goto label_125700;
            case 0x125710u: goto label_125710;
            case 0x125718u: goto label_125718;
            case 0x125730u: goto label_125730;
            case 0x125738u: goto label_125738;
            case 0x12574Cu: goto label_12574c;
            case 0x125750u: goto label_125750;
            case 0x125754u: goto label_125754;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1256E0u; }
            if (ctx->pc != 0x1256E0u) { return; }
        }
        }
    }
    ctx->pc = 0x1256E0u;
label_1256e0:
    // 0x1256e0: 0xc0494dc  jal         func_125370
    ctx->pc = 0x1256E0u;
    SET_GPR_U32(ctx, 31, 0x1256E8u);
    ctx->pc = 0x1256E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1256E0u;
            // 0x1256e4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125370u;
    if (runtime->hasFunction(0x125370u)) {
        auto targetFn = runtime->lookupFunction(0x125370u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1256E8u; }
        if (ctx->pc != 0x1256E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00125370_0x125370(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1256E8u; }
        if (ctx->pc != 0x1256E8u) { return; }
    }
    ctx->pc = 0x1256E8u;
label_1256e8:
    // 0x1256e8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1256e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1256ec: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1256ecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1256f0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1256F0u;
    {
        const bool branch_taken_0x1256f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1256F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1256F0u;
            // 0x1256f4: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1256f0) {
            ctx->pc = 0x125700u;
            goto label_125700;
        }
    }
    ctx->pc = 0x1256F8u;
label_1256f8:
    // 0x1256f8: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1256f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1256fc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1256fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_125700:
    // 0x125700: 0x54620014  bnel        $v1, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x125700u;
    {
        const bool branch_taken_0x125700 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x125700) {
            ctx->pc = 0x125704u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125700u;
            // 0x125704: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125754u;
            goto label_125754;
        }
    }
    ctx->pc = 0x125708u;
    // 0x125708: 0xc04d41e  jal         func_135078
    ctx->pc = 0x125708u;
    SET_GPR_U32(ctx, 31, 0x125710u);
    ctx->pc = 0x12570Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125708u;
            // 0x12570c: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135078u;
    if (runtime->hasFunction(0x135078u)) {
        auto targetFn = runtime->lookupFunction(0x135078u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125710u; }
        if (ctx->pc != 0x125710u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135078_0x135078(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125710u; }
        if (ctx->pc != 0x125710u) { return; }
    }
    ctx->pc = 0x125710u;
label_125710:
    // 0x125710: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x125710u;
    SET_GPR_U32(ctx, 31, 0x125718u);
    ctx->pc = 0x125714u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125710u;
            // 0x125714: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125718u; }
        if (ctx->pc != 0x125718u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125718u; }
        if (ctx->pc != 0x125718u) { return; }
    }
    ctx->pc = 0x125718u;
label_125718:
    // 0x125718: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x125718u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12571c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x12571cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x125720: 0x1622000b  bne         $s1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x125720u;
    {
        const bool branch_taken_0x125720 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x125724u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125720u;
            // 0x125724: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125720) {
            ctx->pc = 0x125750u;
            goto label_125750;
        }
    }
    ctx->pc = 0x125728u;
    // 0x125728: 0xc049546  jal         func_125518
    ctx->pc = 0x125728u;
    SET_GPR_U32(ctx, 31, 0x125730u);
    ctx->pc = 0x125518u;
    if (runtime->hasFunction(0x125518u)) {
        auto targetFn = runtime->lookupFunction(0x125518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125730u; }
        if (ctx->pc != 0x125730u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00125518_0x125518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125730u; }
        if (ctx->pc != 0x125730u) { return; }
    }
    ctx->pc = 0x125730u;
label_125730:
    // 0x125730: 0xc04d412  jal         func_135048
    ctx->pc = 0x125730u;
    SET_GPR_U32(ctx, 31, 0x125738u);
    ctx->pc = 0x125734u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125730u;
            // 0x125734: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135048u;
    if (runtime->hasFunction(0x135048u)) {
        auto targetFn = runtime->lookupFunction(0x135048u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125738u; }
        if (ctx->pc != 0x125738u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135048_0x135048(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125738u; }
        if (ctx->pc != 0x125738u) { return; }
    }
    ctx->pc = 0x125738u;
label_125738:
    // 0x125738: 0x8e020080  lw          $v0, 0x80($s0)
    ctx->pc = 0x125738u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x12573c: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x12573cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x125740: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x125740u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x125744: 0x40f809  jalr        $v0
    ctx->pc = 0x125744u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12574Cu);
        ctx->pc = 0x125748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125744u;
            // 0x125748: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12574Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1256C4u: goto label_1256c4;
            case 0x1256E0u: goto label_1256e0;
            case 0x1256E8u: goto label_1256e8;
            case 0x1256F8u: goto label_1256f8;
            case 0x125700u: goto label_125700;
            case 0x125710u: goto label_125710;
            case 0x125718u: goto label_125718;
            case 0x125730u: goto label_125730;
            case 0x125738u: goto label_125738;
            case 0x12574Cu: goto label_12574c;
            case 0x125750u: goto label_125750;
            case 0x125754u: goto label_125754;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12574Cu; }
            if (ctx->pc != 0x12574Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12574Cu;
label_12574c:
    // 0x12574c: 0xae110004  sw          $s1, 0x4($s0)
    ctx->pc = 0x12574cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 17));
label_125750:
    // 0x125750: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x125750u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_125754:
    // 0x125754: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x125754u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x125758: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x125758u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12575c: 0x3e00008  jr          $ra
    ctx->pc = 0x12575Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12575Cu;
            // 0x125760: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1256C4u: goto label_1256c4;
            case 0x1256E0u: goto label_1256e0;
            case 0x1256E8u: goto label_1256e8;
            case 0x1256F8u: goto label_1256f8;
            case 0x125700u: goto label_125700;
            case 0x125710u: goto label_125710;
            case 0x125718u: goto label_125718;
            case 0x125730u: goto label_125730;
            case 0x125738u: goto label_125738;
            case 0x12574Cu: goto label_12574c;
            case 0x125750u: goto label_125750;
            case 0x125754u: goto label_125754;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125764u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
