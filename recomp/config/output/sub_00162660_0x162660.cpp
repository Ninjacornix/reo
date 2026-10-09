#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162660
// Address: 0x162660 - 0x1627f0
void sub_00162660_0x162660(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162660_0x162660");
#endif

    switch (ctx->pc) {
        case 0x16267cu: goto label_16267c;
        case 0x1626d4u: goto label_1626d4;
        case 0x162720u: goto label_162720;
        case 0x16272cu: goto label_16272c;
        case 0x162738u: goto label_162738;
        case 0x162764u: goto label_162764;
        case 0x162790u: goto label_162790;
        case 0x1627bcu: goto label_1627bc;
        default: break;
    }

    ctx->pc = 0x162660u;

label_162660:
    // 0x162660: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x162660u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x162664: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x162664u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x162668: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x162668u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16266c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16266cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x162670: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x162670u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x162674: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x162674u;
    SET_GPR_U32(ctx, 31, 0x16267Cu);
    ctx->pc = 0x162678u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162674u;
            // 0x162678: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16267Cu; }
        if (ctx->pc != 0x16267Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16267Cu; }
        if (ctx->pc != 0x16267Cu) { return; }
    }
    ctx->pc = 0x16267Cu;
label_16267c:
    // 0x16267c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x16267cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x162680: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x162680u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162684: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x162684u;
    {
        const bool branch_taken_0x162684 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x162688u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162684u;
            // 0x162688: 0x248401d0  addiu       $a0, $a0, 0x1D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 464));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162684) {
            ctx->pc = 0x1626A0u;
            goto label_1626a0;
        }
    }
    ctx->pc = 0x16268Cu;
    // 0x16268c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16268cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162690: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x162690u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162694: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x162694u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x162698: 0x8058dd4  j           func_163750
    ctx->pc = 0x162698u;
    ctx->pc = 0x16269Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162698u;
            // 0x16269c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1626A0u;
label_1626a0:
    // 0x1626a0: 0x8e24004c  lw          $a0, 0x4C($s1)
    ctx->pc = 0x1626a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 76)));
    // 0x1626a4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1626a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1626a8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1626a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1626ac: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1626acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1626b0: 0x804f51a  j           func_13D468
    ctx->pc = 0x1626B0u;
    ctx->pc = 0x1626B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1626B0u;
            // 0x1626b4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D468u;
    if (runtime->hasFunction(0x13D468u)) {
        auto targetFn = runtime->lookupFunction(0x13D468u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D468_0x13d468(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1626B8u;
    // 0x1626b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1626b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1626bc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1626bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1626c0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1626c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1626c4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1626c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1626c8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1626c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1626cc: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1626CCu;
    SET_GPR_U32(ctx, 31, 0x1626D4u);
    ctx->pc = 0x1626D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1626CCu;
            // 0x1626d0: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1626D4u; }
        if (ctx->pc != 0x1626D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1626D4u; }
        if (ctx->pc != 0x1626D4u) { return; }
    }
    ctx->pc = 0x1626D4u;
label_1626d4:
    // 0x1626d4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1626d4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1626d8: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1626D8u;
    {
        const bool branch_taken_0x1626d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1626DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1626D8u;
            // 0x1626dc: 0x24840200  addiu       $a0, $a0, 0x200 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 512));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1626d8) {
            ctx->pc = 0x1626F8u;
            goto label_1626f8;
        }
    }
    ctx->pc = 0x1626E0u;
    // 0x1626e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1626e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1626e4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1626e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1626e8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1626e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1626ec: 0x8058dd4  j           func_163750
    ctx->pc = 0x1626ECu;
    ctx->pc = 0x1626F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1626ECu;
            // 0x1626f0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1626F4u;
    // 0x1626f4: 0x0  nop
    ctx->pc = 0x1626f4u;
    // NOP
label_1626f8:
    // 0x1626f8: 0x16200007  bnez        $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1626F8u;
    {
        const bool branch_taken_0x1626f8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1626FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1626F8u;
            // 0x1626fc: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1626f8) {
            ctx->pc = 0x162718u;
            goto label_162718;
        }
    }
    ctx->pc = 0x162700u;
    // 0x162700: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x162700u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x162704: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162704u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162708: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x162708u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16270c: 0x24840230  addiu       $a0, $a0, 0x230
    ctx->pc = 0x16270cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 560));
    // 0x162710: 0x8058dd4  j           func_163750
    ctx->pc = 0x162710u;
    ctx->pc = 0x162714u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162710u;
            // 0x162714: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162718u;
label_162718:
    // 0x162718: 0xc04f3de  jal         func_13CF78
    ctx->pc = 0x162718u;
    SET_GPR_U32(ctx, 31, 0x162720u);
    ctx->pc = 0x16271Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162718u;
            // 0x16271c: 0x8e04004c  lw          $a0, 0x4C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CF78u;
    if (runtime->hasFunction(0x13CF78u)) {
        auto targetFn = runtime->lookupFunction(0x13CF78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162720u; }
        if (ctx->pc != 0x162720u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CF78_0x13cf78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162720u; }
        if (ctx->pc != 0x162720u) { return; }
    }
    ctx->pc = 0x162720u;
label_162720:
    // 0x162720: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x162720u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162724: 0xc058944  jal         func_162510
    ctx->pc = 0x162724u;
    SET_GPR_U32(ctx, 31, 0x16272Cu);
    ctx->pc = 0x162728u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162724u;
            // 0x162728: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162510u;
    if (runtime->hasFunction(0x162510u)) {
        auto targetFn = runtime->lookupFunction(0x162510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16272Cu; }
        if (ctx->pc != 0x16272Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162510_0x162510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16272Cu; }
        if (ctx->pc != 0x16272Cu) { return; }
    }
    ctx->pc = 0x16272Cu;
label_16272c:
    // 0x16272c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16272cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162730: 0xc058998  jal         func_162660
    ctx->pc = 0x162730u;
    SET_GPR_U32(ctx, 31, 0x162738u);
    ctx->pc = 0x162734u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162730u;
            // 0x162734: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162660u;
    goto label_162660;
    ctx->pc = 0x162738u;
label_162738:
    // 0x162738: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x162738u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16273c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16273cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162740: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162740u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162744: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x162744u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x162748: 0x8058974  j           func_1625D0
    ctx->pc = 0x162748u;
    ctx->pc = 0x16274Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162748u;
            // 0x16274c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1625D0u;
    if (runtime->hasFunction(0x1625D0u)) {
        auto targetFn = runtime->lookupFunction(0x1625D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001625D0_0x1625d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162750u;
    // 0x162750: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162750u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162754: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x162754u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x162758: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x162758u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16275c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x16275Cu;
    SET_GPR_U32(ctx, 31, 0x162764u);
    ctx->pc = 0x162760u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16275Cu;
            // 0x162760: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162764u; }
        if (ctx->pc != 0x162764u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162764u; }
        if (ctx->pc != 0x162764u) { return; }
    }
    ctx->pc = 0x162764u;
label_162764:
    // 0x162764: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x162764u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162768: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x162768u;
    {
        const bool branch_taken_0x162768 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16276Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162768u;
            // 0x16276c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162768) {
            ctx->pc = 0x162788u;
            goto label_162788;
        }
    }
    ctx->pc = 0x162770u;
    // 0x162770: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x162770u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x162774: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162774u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162778: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x162778u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16277c: 0x24840260  addiu       $a0, $a0, 0x260
    ctx->pc = 0x16277cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 608));
    // 0x162780: 0x8058dd4  j           func_163750
    ctx->pc = 0x162780u;
    ctx->pc = 0x162784u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162780u;
            // 0x162784: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162788u;
label_162788:
    // 0x162788: 0xc058998  jal         func_162660
    ctx->pc = 0x162788u;
    SET_GPR_U32(ctx, 31, 0x162790u);
    ctx->pc = 0x162660u;
    goto label_162660;
    ctx->pc = 0x162790u;
label_162790:
    // 0x162790: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x162790u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162794: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x162794u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162798: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162798u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16279c: 0x80589ea  j           func_1627A8
    ctx->pc = 0x16279Cu;
    ctx->pc = 0x1627A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16279Cu;
            // 0x1627a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1627A8u;
    goto label_1627a8;
    ctx->pc = 0x1627A4u;
    // 0x1627a4: 0x0  nop
    ctx->pc = 0x1627a4u;
    // NOP
label_1627a8:
    // 0x1627a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1627a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1627ac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1627acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1627b0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1627b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1627b4: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1627B4u;
    SET_GPR_U32(ctx, 31, 0x1627BCu);
    ctx->pc = 0x1627B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1627B4u;
            // 0x1627b8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1627BCu; }
        if (ctx->pc != 0x1627BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1627BCu; }
        if (ctx->pc != 0x1627BCu) { return; }
    }
    ctx->pc = 0x1627BCu;
label_1627bc:
    // 0x1627bc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1627bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1627c0: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1627C0u;
    {
        const bool branch_taken_0x1627c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1627C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1627C0u;
            // 0x1627c4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1627c0) {
            ctx->pc = 0x1627E0u;
            goto label_1627e0;
        }
    }
    ctx->pc = 0x1627C8u;
    // 0x1627c8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1627c8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1627cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1627ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1627d0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1627d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1627d4: 0x24840290  addiu       $a0, $a0, 0x290
    ctx->pc = 0x1627d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 656));
    // 0x1627d8: 0x8058dd4  j           func_163750
    ctx->pc = 0x1627D8u;
    ctx->pc = 0x1627DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1627D8u;
            // 0x1627dc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1627E0u;
label_1627e0:
    // 0x1627e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1627e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1627e4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1627e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1627e8: 0x8058abe  j           func_162AF8
    ctx->pc = 0x1627E8u;
    ctx->pc = 0x1627ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1627E8u;
            // 0x1627ec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162AF8u;
    if (runtime->hasFunction(0x162AF8u)) {
        auto targetFn = runtime->lookupFunction(0x162AF8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00162AF8_0x162af8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1627F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
