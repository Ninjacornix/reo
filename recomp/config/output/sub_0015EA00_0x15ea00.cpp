#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015EA00
// Address: 0x15ea00 - 0x15eaf0
void sub_0015EA00_0x15ea00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015EA00_0x15ea00");
#endif

    switch (ctx->pc) {
        case 0x15ea1cu: goto label_15ea1c;
        case 0x15ea48u: goto label_15ea48;
        case 0x15ea5cu: goto label_15ea5c;
        case 0x15ea70u: goto label_15ea70;
        case 0x15ea78u: goto label_15ea78;
        case 0x15ea80u: goto label_15ea80;
        case 0x15ea88u: goto label_15ea88;
        case 0x15ea90u: goto label_15ea90;
        case 0x15ea98u: goto label_15ea98;
        case 0x15eaa0u: goto label_15eaa0;
        case 0x15eaa8u: goto label_15eaa8;
        case 0x15eab0u: goto label_15eab0;
        case 0x15eab8u: goto label_15eab8;
        case 0x15eac0u: goto label_15eac0;
        default: break;
    }

    ctx->pc = 0x15ea00u;

    // 0x15ea00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15ea00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15ea04: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15ea04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15ea08: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15ea08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15ea0c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15ea0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15ea10: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x15ea10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15ea14: 0xc05799e  jal         func_15E678
    ctx->pc = 0x15EA14u;
    SET_GPR_U32(ctx, 31, 0x15EA1Cu);
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EA1Cu; }
        if (ctx->pc != 0x15EA1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EA1Cu; }
        if (ctx->pc != 0x15EA1Cu) { return; }
    }
    ctx->pc = 0x15EA1Cu;
label_15ea1c:
    // 0x15ea1c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x15ea1cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x15ea20: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x15ea20u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ea24: 0x2463de50  addiu       $v1, $v1, -0x21B0
    ctx->pc = 0x15ea24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294958672));
    // 0x15ea28: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x15ea28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x15ea2c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x15ea2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x15ea30: 0x14400029  bnez        $v0, . + 4 + (0x29 << 2)
    ctx->pc = 0x15EA30u;
    {
        const bool branch_taken_0x15ea30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15EA34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EA30u;
            // 0x15ea34: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ea30) {
            ctx->pc = 0x15EAD8u;
            goto label_15ead8;
        }
    }
    ctx->pc = 0x15EA38u;
    // 0x15ea38: 0x24900068  addiu       $s0, $a0, 0x68
    ctx->pc = 0x15ea38u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 104));
    // 0x15ea3c: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x15ea3cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15ea40: 0x24110007  addiu       $s1, $zero, 0x7
    ctx->pc = 0x15ea40u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x15ea44: 0x0  nop
    ctx->pc = 0x15ea44u;
    // NOP
label_15ea48:
    // 0x15ea48: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x15ea48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x15ea4c: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x15EA4Cu;
    {
        const bool branch_taken_0x15ea4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x15ea4c) {
            ctx->pc = 0x15EA50u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15EA4Cu;
            // 0x15ea50: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15EA60u;
            goto label_15ea60;
        }
    }
    ctx->pc = 0x15EA54u;
    // 0x15ea54: 0xc057474  jal         func_15D1D0
    ctx->pc = 0x15EA54u;
    SET_GPR_U32(ctx, 31, 0x15EA5Cu);
    ctx->pc = 0x15EA58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EA54u;
            // 0x15ea58: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D1D0u;
    if (runtime->hasFunction(0x15D1D0u)) {
        auto targetFn = runtime->lookupFunction(0x15D1D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EA5Cu; }
        if (ctx->pc != 0x15EA5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D1D0_0x15d1d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EA5Cu; }
        if (ctx->pc != 0x15EA5Cu) { return; }
    }
    ctx->pc = 0x15EA5Cu;
label_15ea5c:
    // 0x15ea5c: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x15ea5cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_15ea60:
    // 0x15ea60: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x15EA60u;
    {
        const bool branch_taken_0x15ea60 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x15EA64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EA60u;
            // 0x15ea64: 0x26100210  addiu       $s0, $s0, 0x210 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 528));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ea60) {
            ctx->pc = 0x15EA48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15ea48;
        }
    }
    ctx->pc = 0x15EA68u;
    // 0x15ea68: 0xc058d66  jal         func_163598
    ctx->pc = 0x15EA68u;
    SET_GPR_U32(ctx, 31, 0x15EA70u);
    ctx->pc = 0x163598u;
    if (runtime->hasFunction(0x163598u)) {
        auto targetFn = runtime->lookupFunction(0x163598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EA70u; }
        if (ctx->pc != 0x15EA70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163598_0x163598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EA70u; }
        if (ctx->pc != 0x15EA70u) { return; }
    }
    ctx->pc = 0x15EA70u;
label_15ea70:
    // 0x15ea70: 0xc058d8e  jal         func_163638
    ctx->pc = 0x15EA70u;
    SET_GPR_U32(ctx, 31, 0x15EA78u);
    ctx->pc = 0x163638u;
    if (runtime->hasFunction(0x163638u)) {
        auto targetFn = runtime->lookupFunction(0x163638u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EA78u; }
        if (ctx->pc != 0x15EA78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163638_0x163638(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EA78u; }
        if (ctx->pc != 0x15EA78u) { return; }
    }
    ctx->pc = 0x15EA78u;
label_15ea78:
    // 0x15ea78: 0xc058d7a  jal         func_1635E8
    ctx->pc = 0x15EA78u;
    SET_GPR_U32(ctx, 31, 0x15EA80u);
    ctx->pc = 0x1635E8u;
    if (runtime->hasFunction(0x1635E8u)) {
        auto targetFn = runtime->lookupFunction(0x1635E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EA80u; }
        if (ctx->pc != 0x15EA80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001635E8_0x1635e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EA80u; }
        if (ctx->pc != 0x15EA80u) { return; }
    }
    ctx->pc = 0x15EA80u;
label_15ea80:
    // 0x15ea80: 0xc0582d0  jal         func_160B40
    ctx->pc = 0x15EA80u;
    SET_GPR_U32(ctx, 31, 0x15EA88u);
    ctx->pc = 0x160B40u;
    if (runtime->hasFunction(0x160B40u)) {
        auto targetFn = runtime->lookupFunction(0x160B40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EA88u; }
        if (ctx->pc != 0x15EA88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B40_0x160b40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EA88u; }
        if (ctx->pc != 0x15EA88u) { return; }
    }
    ctx->pc = 0x15EA88u;
label_15ea88:
    // 0x15ea88: 0xc04f586  jal         func_13D618
    ctx->pc = 0x15EA88u;
    SET_GPR_U32(ctx, 31, 0x15EA90u);
    ctx->pc = 0x13D618u;
    if (runtime->hasFunction(0x13D618u)) {
        auto targetFn = runtime->lookupFunction(0x13D618u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EA90u; }
        if (ctx->pc != 0x15EA90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D618_0x13d618(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EA90u; }
        if (ctx->pc != 0x15EA90u) { return; }
    }
    ctx->pc = 0x15EA90u;
label_15ea90:
    // 0x15ea90: 0xc057afa  jal         func_15EBE8
    ctx->pc = 0x15EA90u;
    SET_GPR_U32(ctx, 31, 0x15EA98u);
    ctx->pc = 0x15EBE8u;
    if (runtime->hasFunction(0x15EBE8u)) {
        auto targetFn = runtime->lookupFunction(0x15EBE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EA98u; }
        if (ctx->pc != 0x15EA98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EBE8_0x15ebe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EA98u; }
        if (ctx->pc != 0x15EA98u) { return; }
    }
    ctx->pc = 0x15EA98u;
label_15ea98:
    // 0x15ea98: 0xc04a8e2  jal         func_12A388
    ctx->pc = 0x15EA98u;
    SET_GPR_U32(ctx, 31, 0x15EAA0u);
    ctx->pc = 0x12A388u;
    if (runtime->hasFunction(0x12A388u)) {
        auto targetFn = runtime->lookupFunction(0x12A388u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EAA0u; }
        if (ctx->pc != 0x15EAA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A388_0x12a388(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EAA0u; }
        if (ctx->pc != 0x15EAA0u) { return; }
    }
    ctx->pc = 0x15EAA0u;
label_15eaa0:
    // 0x15eaa0: 0xc059106  jal         func_164418
    ctx->pc = 0x15EAA0u;
    SET_GPR_U32(ctx, 31, 0x15EAA8u);
    ctx->pc = 0x164418u;
    if (runtime->hasFunction(0x164418u)) {
        auto targetFn = runtime->lookupFunction(0x164418u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EAA8u; }
        if (ctx->pc != 0x15EAA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164418_0x164418(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EAA8u; }
        if (ctx->pc != 0x15EAA8u) { return; }
    }
    ctx->pc = 0x15EAA8u;
label_15eaa8:
    // 0x15eaa8: 0xc05001c  jal         func_140070
    ctx->pc = 0x15EAA8u;
    SET_GPR_U32(ctx, 31, 0x15EAB0u);
    ctx->pc = 0x140070u;
    if (runtime->hasFunction(0x140070u)) {
        auto targetFn = runtime->lookupFunction(0x140070u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EAB0u; }
        if (ctx->pc != 0x15EAB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140070_0x140070(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EAB0u; }
        if (ctx->pc != 0x15EAB0u) { return; }
    }
    ctx->pc = 0x15EAB0u;
label_15eab0:
    // 0x15eab0: 0xc04fcc4  jal         func_13F310
    ctx->pc = 0x15EAB0u;
    SET_GPR_U32(ctx, 31, 0x15EAB8u);
    ctx->pc = 0x13F310u;
    if (runtime->hasFunction(0x13F310u)) {
        auto targetFn = runtime->lookupFunction(0x13F310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EAB8u; }
        if (ctx->pc != 0x15EAB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F310_0x13f310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EAB8u; }
        if (ctx->pc != 0x15EAB8u) { return; }
    }
    ctx->pc = 0x15EAB8u;
label_15eab8:
    // 0x15eab8: 0xc04fe16  jal         func_13F858
    ctx->pc = 0x15EAB8u;
    SET_GPR_U32(ctx, 31, 0x15EAC0u);
    ctx->pc = 0x13F858u;
    if (runtime->hasFunction(0x13F858u)) {
        auto targetFn = runtime->lookupFunction(0x13F858u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EAC0u; }
        if (ctx->pc != 0x15EAC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F858_0x13f858(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EAC0u; }
        if (ctx->pc != 0x15EAC0u) { return; }
    }
    ctx->pc = 0x15EAC0u;
label_15eac0:
    // 0x15eac0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15eac0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15eac4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15eac4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15eac8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15eac8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15eacc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15eaccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15ead0: 0x8058d30  j           func_1634C0
    ctx->pc = 0x15EAD0u;
    ctx->pc = 0x15EAD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EAD0u;
            // 0x15ead4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1634C0u;
    if (runtime->hasFunction(0x1634C0u)) {
        auto targetFn = runtime->lookupFunction(0x1634C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001634C0_0x1634c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15EAD8u;
label_15ead8:
    // 0x15ead8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15ead8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15eadc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15eadcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15eae0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15eae0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15eae4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15eae4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15eae8: 0x3e00008  jr          $ra
    ctx->pc = 0x15EAE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EAECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EAE8u;
            // 0x15eaec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EA1Cu: goto label_15ea1c;
            case 0x15EA48u: goto label_15ea48;
            case 0x15EA5Cu: goto label_15ea5c;
            case 0x15EA60u: goto label_15ea60;
            case 0x15EA70u: goto label_15ea70;
            case 0x15EA78u: goto label_15ea78;
            case 0x15EA80u: goto label_15ea80;
            case 0x15EA88u: goto label_15ea88;
            case 0x15EA90u: goto label_15ea90;
            case 0x15EA98u: goto label_15ea98;
            case 0x15EAA0u: goto label_15eaa0;
            case 0x15EAA8u: goto label_15eaa8;
            case 0x15EAB0u: goto label_15eab0;
            case 0x15EAB8u: goto label_15eab8;
            case 0x15EAC0u: goto label_15eac0;
            case 0x15EAD8u: goto label_15ead8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EAF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
