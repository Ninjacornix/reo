#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001006E8
// Address: 0x1006e8 - 0x1007c0
void sub_001006E8_0x1006e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001006E8_0x1006e8");
#endif

    switch (ctx->pc) {
        case 0x100718u: goto label_100718;
        case 0x100720u: goto label_100720;
        case 0x10074cu: goto label_10074c;
        case 0x1007a8u: goto label_1007a8;
        default: break;
    }

    ctx->pc = 0x1006e8u;

    // 0x1006e8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1006e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1006ec: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x1006ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x1006f0: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1006f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1006f4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1006f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1006f8: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1006f8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1006fc: 0x8c437940  lw          $v1, 0x7940($v0)
    ctx->pc = 0x1006fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31040)));
    // 0x100700: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x100700u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100704: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x100704u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x100708: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x100708u;
    {
        const bool branch_taken_0x100708 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x10070Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100708u;
            // 0x10070c: 0xffb10010  sd          $s1, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100708) {
            ctx->pc = 0x100718u;
            goto label_100718;
        }
    }
    ctx->pc = 0x100710u;
    // 0x100710: 0xc0401f0  jal         func_1007C0
    ctx->pc = 0x100710u;
    SET_GPR_U32(ctx, 31, 0x100718u);
    ctx->pc = 0x1007C0u;
    if (runtime->hasFunction(0x1007C0u)) {
        auto targetFn = runtime->lookupFunction(0x1007C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100718u; }
        if (ctx->pc != 0x100718u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001007C0_0x1007c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100718u; }
        if (ctx->pc != 0x100718u) { return; }
    }
    ctx->pc = 0x100718u;
label_100718:
    // 0x100718: 0xc047598  jal         func_11D660
    ctx->pc = 0x100718u;
    SET_GPR_U32(ctx, 31, 0x100720u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100720u; }
        if (ctx->pc != 0x100720u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100720u; }
        if (ctx->pc != 0x100720u) { return; }
    }
    ctx->pc = 0x100720u;
label_100720:
    // 0x100720: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x100720u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x100724: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x100724u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x100728: 0x8cb19f88  lw          $s1, -0x6078($a1)
    ctx->pc = 0x100728u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4294942600)));
    // 0x10072c: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x10072cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x100730: 0xac909f90  sw          $s0, -0x6070($a0)
    ctx->pc = 0x100730u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4294942608), GPR_U32(ctx, 16));
    // 0x100734: 0xacb29f88  sw          $s2, -0x6078($a1)
    ctx->pc = 0x100734u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294942600), GPR_U32(ctx, 18));
    // 0x100738: 0xac7c9f8c  sw          $gp, -0x6074($v1)
    ctx->pc = 0x100738u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294942604), GPR_U32(ctx, 28));
    // 0x10073c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10073Cu;
    {
        const bool branch_taken_0x10073c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x100740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10073Cu;
            // 0x100740: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10073c) {
            ctx->pc = 0x100750u;
            goto label_100750;
        }
    }
    ctx->pc = 0x100744u;
    // 0x100744: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x100744u;
    SET_GPR_U32(ctx, 31, 0x10074Cu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10074Cu; }
        if (ctx->pc != 0x10074Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10074Cu; }
        if (ctx->pc != 0x10074Cu) { return; }
    }
    ctx->pc = 0x10074Cu;
label_10074c:
    // 0x10074c: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x10074cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_100750:
    // 0x100750: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x100750u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x100754: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x100754u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x100758: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x100758u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10075c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10075cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x100760: 0x3e00008  jr          $ra
    ctx->pc = 0x100760u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100760u;
            // 0x100764: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100718u: goto label_100718;
            case 0x100720u: goto label_100720;
            case 0x10074Cu: goto label_10074c;
            case 0x100750u: goto label_100750;
            case 0x1007A8u: goto label_1007a8;
            case 0x1007ACu: goto label_1007ac;
            case 0x1007B0u: goto label_1007b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100768u;
    // 0x100768: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x100768u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x10076c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x10076cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x100770: 0x8c459f88  lw          $a1, -0x6078($v0)
    ctx->pc = 0x100770u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942600)));
    // 0x100774: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x100774u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x100778: 0x10a0000c  beqz        $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x100778u;
    {
        const bool branch_taken_0x100778 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x10077Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100778u;
            // 0x10077c: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100778) {
            ctx->pc = 0x1007ACu;
            goto label_1007ac;
        }
    }
    ctx->pc = 0x100780u;
    // 0x100780: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x100780u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x100784: 0x8c437924  lw          $v1, 0x7924($v0)
    ctx->pc = 0x100784u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31012)));
    // 0x100788: 0x14600009  bnez        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x100788u;
    {
        const bool branch_taken_0x100788 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10078Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100788u;
            // 0x10078c: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100788) {
            ctx->pc = 0x1007B0u;
            goto label_1007b0;
        }
    }
    ctx->pc = 0x100790u;
    // 0x100790: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x100790u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x100794: 0x380802d  daddu       $s0, $gp, $zero
    ctx->pc = 0x100794u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100798: 0x8c5c9f8c  lw          $gp, -0x6074($v0)
    ctx->pc = 0x100798u;
    SET_GPR_S32(ctx, 28, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942604)));
    // 0x10079c: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x10079cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x1007a0: 0xa0f809  jalr        $a1
    ctx->pc = 0x1007A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 5);
        SET_GPR_U32(ctx, 31, 0x1007A8u);
        ctx->pc = 0x1007A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1007A0u;
            // 0x1007a4: 0x8c649f90  lw          $a0, -0x6070($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942608)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1007A8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100718u: goto label_100718;
            case 0x100720u: goto label_100720;
            case 0x10074Cu: goto label_10074c;
            case 0x100750u: goto label_100750;
            case 0x1007A8u: goto label_1007a8;
            case 0x1007ACu: goto label_1007ac;
            case 0x1007B0u: goto label_1007b0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1007A8u; }
            if (ctx->pc != 0x1007A8u) { return; }
        }
        }
    }
    ctx->pc = 0x1007A8u;
label_1007a8:
    // 0x1007a8: 0x200e02d  daddu       $gp, $s0, $zero
    ctx->pc = 0x1007a8u;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1007ac:
    // 0x1007ac: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1007acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1007b0:
    // 0x1007b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1007b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1007b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1007B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1007B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1007B4u;
            // 0x1007b8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100718u: goto label_100718;
            case 0x100720u: goto label_100720;
            case 0x10074Cu: goto label_10074c;
            case 0x100750u: goto label_100750;
            case 0x1007A8u: goto label_1007a8;
            case 0x1007ACu: goto label_1007ac;
            case 0x1007B0u: goto label_1007b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1007BCu;
    // 0x1007bc: 0x0  nop
    ctx->pc = 0x1007bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
