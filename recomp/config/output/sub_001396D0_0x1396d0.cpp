#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001396D0
// Address: 0x1396d0 - 0x139798
void sub_001396D0_0x1396d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001396D0_0x1396d0");
#endif

    switch (ctx->pc) {
        case 0x1396f4u: goto label_1396f4;
        case 0x1396fcu: goto label_1396fc;
        case 0x139770u: goto label_139770;
        default: break;
    }

    ctx->pc = 0x1396d0u;

    // 0x1396d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1396d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1396d4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1396d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1396d8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1396d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1396dc: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1396dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1396e0: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1396e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1396e4: 0x50400028  beql        $v0, $zero, . + 4 + (0x28 << 2)
    ctx->pc = 0x1396E4u;
    {
        const bool branch_taken_0x1396e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1396e4) {
            ctx->pc = 0x1396E8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1396E4u;
            // 0x1396e8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x139788u;
            goto label_139788;
        }
    }
    ctx->pc = 0x1396ECu;
    // 0x1396ec: 0xc0505c0  jal         func_141700
    ctx->pc = 0x1396ECu;
    SET_GPR_U32(ctx, 31, 0x1396F4u);
    ctx->pc = 0x141700u;
    if (runtime->hasFunction(0x141700u)) {
        auto targetFn = runtime->lookupFunction(0x141700u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1396F4u; }
        if (ctx->pc != 0x1396F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141700_0x141700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1396F4u; }
        if (ctx->pc != 0x1396F4u) { return; }
    }
    ctx->pc = 0x1396F4u;
label_1396f4:
    // 0x1396f4: 0xc04dd82  jal         func_137608
    ctx->pc = 0x1396F4u;
    SET_GPR_U32(ctx, 31, 0x1396FCu);
    ctx->pc = 0x1396F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1396F4u;
            // 0x1396f8: 0x8e04001c  lw          $a0, 0x1C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137608u;
    if (runtime->hasFunction(0x137608u)) {
        auto targetFn = runtime->lookupFunction(0x137608u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1396FCu; }
        if (ctx->pc != 0x1396FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137608_0x137608(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1396FCu; }
        if (ctx->pc != 0x1396FCu) { return; }
    }
    ctx->pc = 0x1396FCu;
label_1396fc:
    // 0x1396fc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1396fcu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139700: 0x2c62000a  sltiu       $v0, $v1, 0xA
    ctx->pc = 0x139700u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x139704: 0x5040001c  beql        $v0, $zero, . + 4 + (0x1C << 2)
    ctx->pc = 0x139704u;
    {
        const bool branch_taken_0x139704 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x139704) {
            ctx->pc = 0x139708u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x139704u;
            // 0x139708: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x139778u;
            goto label_139778;
        }
    }
    ctx->pc = 0x13970Cu;
    // 0x13970c: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x13970cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x139710: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x139710u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x139714: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x139714u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x139718: 0x8c63ca60  lw          $v1, -0x35A0($v1)
    ctx->pc = 0x139718u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294953568)));
    // 0x13971c: 0x600008  jr          $v1
    ctx->pc = 0x13971Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x139728u: goto label_139728;
            case 0x139738u: goto label_139738;
            case 0x139760u: goto label_139760;
            case 0x139774u: goto label_139774;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139724u;
    // 0x139724: 0x0  nop
    ctx->pc = 0x139724u;
    // NOP
label_139728:
    // 0x139728: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x139728u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x13972c: 0x8e04001c  lw          $a0, 0x1C($s0)
    ctx->pc = 0x13972cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x139730: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x139730u;
    {
        const bool branch_taken_0x139730 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139734u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139730u;
            // 0x139734: 0xa2020002  sb          $v0, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139730) {
            ctx->pc = 0x139768u;
            goto label_139768;
        }
    }
    ctx->pc = 0x139738u;
label_139738:
    // 0x139738: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x139738u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x13973c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x13973cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x139740: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x139740u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x139744: 0xae040014  sw          $a0, 0x14($s0)
    ctx->pc = 0x139744u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 4));
    // 0x139748: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x139748u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x13974c: 0x8e04001c  lw          $a0, 0x1C($s0)
    ctx->pc = 0x13974cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x139750: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x139750u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x139754: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x139754u;
    {
        const bool branch_taken_0x139754 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139754u;
            // 0x139758: 0xae02000c  sw          $v0, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139754) {
            ctx->pc = 0x139768u;
            goto label_139768;
        }
    }
    ctx->pc = 0x13975Cu;
    // 0x13975c: 0x0  nop
    ctx->pc = 0x13975cu;
    // NOP
label_139760:
    // 0x139760: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x139760u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x139764: 0x8e04001c  lw          $a0, 0x1C($s0)
    ctx->pc = 0x139764u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
label_139768:
    // 0x139768: 0xc04dcf2  jal         func_1373C8
    ctx->pc = 0x139768u;
    SET_GPR_U32(ctx, 31, 0x139770u);
    ctx->pc = 0x1373C8u;
    if (runtime->hasFunction(0x1373C8u)) {
        auto targetFn = runtime->lookupFunction(0x1373C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139770u; }
        if (ctx->pc != 0x139770u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001373C8_0x1373c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139770u; }
        if (ctx->pc != 0x139770u) { return; }
    }
    ctx->pc = 0x139770u;
label_139770:
    // 0x139770: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x139770u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
label_139774:
    // 0x139774: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x139774u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_139778:
    // 0x139778: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x139778u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13977c: 0x80505de  j           func_141778
    ctx->pc = 0x13977Cu;
    ctx->pc = 0x139780u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13977Cu;
            // 0x139780: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141778u;
    if (runtime->hasFunction(0x141778u)) {
        auto targetFn = runtime->lookupFunction(0x141778u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141778_0x141778(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x139784u;
    // 0x139784: 0x0  nop
    ctx->pc = 0x139784u;
    // NOP
label_139788:
    // 0x139788: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x139788u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13978c: 0x3e00008  jr          $ra
    ctx->pc = 0x13978Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x139790u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13978Cu;
            // 0x139790: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1396F4u: goto label_1396f4;
            case 0x1396FCu: goto label_1396fc;
            case 0x139728u: goto label_139728;
            case 0x139738u: goto label_139738;
            case 0x139760u: goto label_139760;
            case 0x139768u: goto label_139768;
            case 0x139770u: goto label_139770;
            case 0x139774u: goto label_139774;
            case 0x139778u: goto label_139778;
            case 0x139788u: goto label_139788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139794u;
    // 0x139794: 0x0  nop
    ctx->pc = 0x139794u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
