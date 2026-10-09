#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163B30
// Address: 0x163b30 - 0x163bf0
void sub_00163B30_0x163b30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163B30_0x163b30");
#endif

    switch (ctx->pc) {
        case 0x163b48u: goto label_163b48;
        case 0x163b78u: goto label_163b78;
        case 0x163b90u: goto label_163b90;
        case 0x163b98u: goto label_163b98;
        case 0x163bb4u: goto label_163bb4;
        case 0x163bc4u: goto label_163bc4;
        case 0x163bd8u: goto label_163bd8;
        default: break;
    }

    ctx->pc = 0x163b30u;

    // 0x163b30: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163b30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x163b34: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x163b34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x163b38: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x163b38u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163b3c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x163b3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x163b40: 0xc0591ca  jal         func_164728
    ctx->pc = 0x163B40u;
    SET_GPR_U32(ctx, 31, 0x163B48u);
    ctx->pc = 0x163B44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163B40u;
            // 0x163b44: 0x8e040044  lw          $a0, 0x44($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164728u;
    if (runtime->hasFunction(0x164728u)) {
        auto targetFn = runtime->lookupFunction(0x164728u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163B48u; }
        if (ctx->pc != 0x163B48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164728_0x164728(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163B48u; }
        if (ctx->pc != 0x163B48u) { return; }
    }
    ctx->pc = 0x163B48u;
label_163b48:
    // 0x163b48: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x163b48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x163b4c: 0x54430004  bnel        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x163B4Cu;
    {
        const bool branch_taken_0x163b4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x163b4c) {
            ctx->pc = 0x163B50u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x163B4Cu;
            // 0x163b50: 0x8e040128  lw          $a0, 0x128($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 296)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x163B60u;
            goto label_163b60;
        }
    }
    ctx->pc = 0x163B54u;
    // 0x163b54: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x163B54u;
    {
        const bool branch_taken_0x163b54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x163B58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163B54u;
            // 0x163b58: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163b54) {
            ctx->pc = 0x163BDCu;
            goto label_163bdc;
        }
    }
    ctx->pc = 0x163B5Cu;
    // 0x163b5c: 0x0  nop
    ctx->pc = 0x163b5cu;
    // NOP
label_163b60:
    // 0x163b60: 0x50800006  beql        $a0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x163B60u;
    {
        const bool branch_taken_0x163b60 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x163b60) {
            ctx->pc = 0x163B64u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x163B60u;
            // 0x163b64: 0x8e050110  lw          $a1, 0x110($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 272)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x163B7Cu;
            goto label_163b7c;
        }
    }
    ctx->pc = 0x163B68u;
    // 0x163b68: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x163b68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x163b6c: 0x8c620014  lw          $v0, 0x14($v1)
    ctx->pc = 0x163b6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x163b70: 0x40f809  jalr        $v0
    ctx->pc = 0x163B70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x163B78u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x163B78u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163B48u: goto label_163b48;
            case 0x163B60u: goto label_163b60;
            case 0x163B78u: goto label_163b78;
            case 0x163B7Cu: goto label_163b7c;
            case 0x163B90u: goto label_163b90;
            case 0x163B98u: goto label_163b98;
            case 0x163BB4u: goto label_163bb4;
            case 0x163BC4u: goto label_163bc4;
            case 0x163BD0u: goto label_163bd0;
            case 0x163BD8u: goto label_163bd8;
            case 0x163BDCu: goto label_163bdc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x163B78u; }
            if (ctx->pc != 0x163B78u) { return; }
        }
        }
    }
    ctx->pc = 0x163B78u;
label_163b78:
    // 0x163b78: 0x8e050110  lw          $a1, 0x110($s0)
    ctx->pc = 0x163b78u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 272)));
label_163b7c:
    // 0x163b7c: 0x8e040044  lw          $a0, 0x44($s0)
    ctx->pc = 0x163b7cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x163b80: 0x8e06011c  lw          $a2, 0x11C($s0)
    ctx->pc = 0x163b80u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 284)));
    // 0x163b84: 0x8e070120  lw          $a3, 0x120($s0)
    ctx->pc = 0x163b84u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 288)));
    // 0x163b88: 0xc059192  jal         func_164648
    ctx->pc = 0x163B88u;
    SET_GPR_U32(ctx, 31, 0x163B90u);
    ctx->pc = 0x163B8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163B88u;
            // 0x163b8c: 0x8e080124  lw          $t0, 0x124($s0) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 292)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164648u;
    if (runtime->hasFunction(0x164648u)) {
        auto targetFn = runtime->lookupFunction(0x164648u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163B90u; }
        if (ctx->pc != 0x163B90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164648_0x164648(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163B90u; }
        if (ctx->pc != 0x163B90u) { return; }
    }
    ctx->pc = 0x163B90u;
label_163b90:
    // 0x163b90: 0xc0591b0  jal         func_1646C0
    ctx->pc = 0x163B90u;
    SET_GPR_U32(ctx, 31, 0x163B98u);
    ctx->pc = 0x163B94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163B90u;
            // 0x163b94: 0x8e040044  lw          $a0, 0x44($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1646C0u;
    if (runtime->hasFunction(0x1646C0u)) {
        auto targetFn = runtime->lookupFunction(0x1646C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163B98u; }
        if (ctx->pc != 0x163B98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001646C0_0x1646c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163B98u; }
        if (ctx->pc != 0x163B98u) { return; }
    }
    ctx->pc = 0x163B98u;
label_163b98:
    // 0x163b98: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x163b98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x163b9c: 0x1443000c  bne         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x163B9Cu;
    {
        const bool branch_taken_0x163b9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x163BA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163B9Cu;
            // 0x163ba0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163b9c) {
            ctx->pc = 0x163BD0u;
            goto label_163bd0;
        }
    }
    ctx->pc = 0x163BA4u;
    // 0x163ba4: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x163ba4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x163ba8: 0x2404ff9a  addiu       $a0, $zero, -0x66
    ctx->pc = 0x163ba8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967194));
    // 0x163bac: 0xc057abc  jal         func_15EAF0
    ctx->pc = 0x163BACu;
    SET_GPR_U32(ctx, 31, 0x163BB4u);
    ctx->pc = 0x163BB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163BACu;
            // 0x163bb0: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15EAF0u;
    if (runtime->hasFunction(0x15EAF0u)) {
        auto targetFn = runtime->lookupFunction(0x15EAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163BB4u; }
        if (ctx->pc != 0x163BB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EAF0_0x15eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163BB4u; }
        if (ctx->pc != 0x163BB4u) { return; }
    }
    ctx->pc = 0x163BB4u;
label_163bb4:
    // 0x163bb4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x163bb4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x163bb8: 0x8e050110  lw          $a1, 0x110($s0)
    ctx->pc = 0x163bb8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 272)));
    // 0x163bbc: 0xc058dd4  jal         func_163750
    ctx->pc = 0x163BBCu;
    SET_GPR_U32(ctx, 31, 0x163BC4u);
    ctx->pc = 0x163BC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163BBCu;
            // 0x163bc0: 0x248404d0  addiu       $a0, $a0, 0x4D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1232));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163BC4u; }
        if (ctx->pc != 0x163BC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163BC4u; }
        if (ctx->pc != 0x163BC4u) { return; }
    }
    ctx->pc = 0x163BC4u;
label_163bc4:
    // 0x163bc4: 0xae000118  sw          $zero, 0x118($s0)
    ctx->pc = 0x163bc4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 280), GPR_U32(ctx, 0));
    // 0x163bc8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x163BC8u;
    {
        const bool branch_taken_0x163bc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x163BCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163BC8u;
            // 0x163bcc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163bc8) {
            ctx->pc = 0x163BDCu;
            goto label_163bdc;
        }
    }
    ctx->pc = 0x163BD0u;
label_163bd0:
    // 0x163bd0: 0xc056fea  jal         func_15BFA8
    ctx->pc = 0x163BD0u;
    SET_GPR_U32(ctx, 31, 0x163BD8u);
    ctx->pc = 0x15BFA8u;
    if (runtime->hasFunction(0x15BFA8u)) {
        auto targetFn = runtime->lookupFunction(0x15BFA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163BD8u; }
        if (ctx->pc != 0x163BD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BFA8_0x15bfa8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163BD8u; }
        if (ctx->pc != 0x163BD8u) { return; }
    }
    ctx->pc = 0x163BD8u;
label_163bd8:
    // 0x163bd8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x163bd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_163bdc:
    // 0x163bdc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x163bdcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163be0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x163be0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163be4: 0x3e00008  jr          $ra
    ctx->pc = 0x163BE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163BE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163BE4u;
            // 0x163be8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163B48u: goto label_163b48;
            case 0x163B60u: goto label_163b60;
            case 0x163B78u: goto label_163b78;
            case 0x163B7Cu: goto label_163b7c;
            case 0x163B90u: goto label_163b90;
            case 0x163B98u: goto label_163b98;
            case 0x163BB4u: goto label_163bb4;
            case 0x163BC4u: goto label_163bc4;
            case 0x163BD0u: goto label_163bd0;
            case 0x163BD8u: goto label_163bd8;
            case 0x163BDCu: goto label_163bdc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163BECu;
    // 0x163bec: 0x0  nop
    ctx->pc = 0x163becu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
