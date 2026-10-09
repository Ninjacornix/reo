#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131D98
// Address: 0x131d98 - 0x131e38
void sub_00131D98_0x131d98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131D98_0x131d98");
#endif

    switch (ctx->pc) {
        case 0x131dacu: goto label_131dac;
        case 0x131db8u: goto label_131db8;
        case 0x131dc4u: goto label_131dc4;
        case 0x131dd0u: goto label_131dd0;
        case 0x131dd8u: goto label_131dd8;
        case 0x131e08u: goto label_131e08;
        case 0x131e1cu: goto label_131e1c;
        default: break;
    }

    ctx->pc = 0x131d98u;

    // 0x131d98: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x131d98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x131d9c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x131d9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x131da0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x131da0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x131da4: 0xc049938  jal         func_1264E0
    ctx->pc = 0x131DA4u;
    SET_GPR_U32(ctx, 31, 0x131DACu);
    ctx->pc = 0x131DA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131DA4u;
            // 0x131da8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131DACu; }
        if (ctx->pc != 0x131DACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131DACu; }
        if (ctx->pc != 0x131DACu) { return; }
    }
    ctx->pc = 0x131DACu;
label_131dac:
    // 0x131dac: 0x8e04000c  lw          $a0, 0xC($s0)
    ctx->pc = 0x131dacu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x131db0: 0xc04b1ba  jal         func_12C6E8
    ctx->pc = 0x131DB0u;
    SET_GPR_U32(ctx, 31, 0x131DB8u);
    ctx->pc = 0x131DB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131DB0u;
            // 0x131db4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C6E8u;
    if (runtime->hasFunction(0x12C6E8u)) {
        auto targetFn = runtime->lookupFunction(0x12C6E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131DB8u; }
        if (ctx->pc != 0x131DB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C6E8_0x12c6e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131DB8u; }
        if (ctx->pc != 0x131DB8u) { return; }
    }
    ctx->pc = 0x131DB8u;
label_131db8:
    // 0x131db8: 0x8e04000c  lw          $a0, 0xC($s0)
    ctx->pc = 0x131db8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x131dbc: 0xc04b1c0  jal         func_12C700
    ctx->pc = 0x131DBCu;
    SET_GPR_U32(ctx, 31, 0x131DC4u);
    ctx->pc = 0x131DC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131DBCu;
            // 0x131dc0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C700u;
    if (runtime->hasFunction(0x12C700u)) {
        auto targetFn = runtime->lookupFunction(0x12C700u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131DC4u; }
        if (ctx->pc != 0x131DC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C700_0x12c700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131DC4u; }
        if (ctx->pc != 0x131DC4u) { return; }
    }
    ctx->pc = 0x131DC4u;
label_131dc4:
    // 0x131dc4: 0x8e04000c  lw          $a0, 0xC($s0)
    ctx->pc = 0x131dc4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x131dc8: 0xc04fb16  jal         func_13EC58
    ctx->pc = 0x131DC8u;
    SET_GPR_U32(ctx, 31, 0x131DD0u);
    ctx->pc = 0x131DCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131DC8u;
            // 0x131dcc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13EC58u;
    if (runtime->hasFunction(0x13EC58u)) {
        auto targetFn = runtime->lookupFunction(0x13EC58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131DD0u; }
        if (ctx->pc != 0x131DD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013EC58_0x13ec58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131DD0u; }
        if (ctx->pc != 0x131DD0u) { return; }
    }
    ctx->pc = 0x131DD0u;
label_131dd0:
    // 0x131dd0: 0xc04b32c  jal         func_12CCB0
    ctx->pc = 0x131DD0u;
    SET_GPR_U32(ctx, 31, 0x131DD8u);
    ctx->pc = 0x131DD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131DD0u;
            // 0x131dd4: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CCB0u;
    if (runtime->hasFunction(0x12CCB0u)) {
        auto targetFn = runtime->lookupFunction(0x12CCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131DD8u; }
        if (ctx->pc != 0x131DD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CCB0_0x12ccb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131DD8u; }
        if (ctx->pc != 0x131DD8u) { return; }
    }
    ctx->pc = 0x131DD8u;
label_131dd8:
    // 0x131dd8: 0x82030002  lb          $v1, 0x2($s0)
    ctx->pc = 0x131dd8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x131ddc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x131ddcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x131de0: 0x5462000a  bnel        $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x131DE0u;
    {
        const bool branch_taken_0x131de0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x131de0) {
            ctx->pc = 0x131DE4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131DE0u;
            // 0x131de4: 0x8e040074  lw          $a0, 0x74($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 116)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131E0Cu;
            goto label_131e0c;
        }
    }
    ctx->pc = 0x131DE8u;
    // 0x131de8: 0x8e040014  lw          $a0, 0x14($s0)
    ctx->pc = 0x131de8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x131dec: 0x50800007  beql        $a0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x131DECu;
    {
        const bool branch_taken_0x131dec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x131dec) {
            ctx->pc = 0x131DF0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131DECu;
            // 0x131df0: 0x8e040074  lw          $a0, 0x74($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 116)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131E0Cu;
            goto label_131e0c;
        }
    }
    ctx->pc = 0x131DF4u;
    // 0x131df4: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x131df4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x131df8: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x131df8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x131dfc: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x131dfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x131e00: 0x40f809  jalr        $v0
    ctx->pc = 0x131E00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x131E08u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x131E08u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131DACu: goto label_131dac;
            case 0x131DB8u: goto label_131db8;
            case 0x131DC4u: goto label_131dc4;
            case 0x131DD0u: goto label_131dd0;
            case 0x131DD8u: goto label_131dd8;
            case 0x131E08u: goto label_131e08;
            case 0x131E0Cu: goto label_131e0c;
            case 0x131E1Cu: goto label_131e1c;
            case 0x131E20u: goto label_131e20;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x131E08u; }
            if (ctx->pc != 0x131E08u) { return; }
        }
        }
    }
    ctx->pc = 0x131E08u;
label_131e08:
    // 0x131e08: 0x8e040074  lw          $a0, 0x74($s0)
    ctx->pc = 0x131e08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 116)));
label_131e0c:
    // 0x131e0c: 0x50800004  beql        $a0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x131E0Cu;
    {
        const bool branch_taken_0x131e0c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x131e0c) {
            ctx->pc = 0x131E10u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131E0Cu;
            // 0x131e10: 0xa20000ac  sb          $zero, 0xAC($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 172), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131E20u;
            goto label_131e20;
        }
    }
    ctx->pc = 0x131E14u;
    // 0x131e14: 0xc048aba  jal         func_122AE8
    ctx->pc = 0x131E14u;
    SET_GPR_U32(ctx, 31, 0x131E1Cu);
    ctx->pc = 0x122AE8u;
    if (runtime->hasFunction(0x122AE8u)) {
        auto targetFn = runtime->lookupFunction(0x122AE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131E1Cu; }
        if (ctx->pc != 0x131E1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00122AE8_0x122ae8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131E1Cu; }
        if (ctx->pc != 0x131E1Cu) { return; }
    }
    ctx->pc = 0x131E1Cu;
label_131e1c:
    // 0x131e1c: 0xa20000ac  sb          $zero, 0xAC($s0)
    ctx->pc = 0x131e1cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 172), (uint8_t)GPR_U32(ctx, 0));
label_131e20:
    // 0x131e20: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x131e20u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x131e24: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x131e24u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x131e28: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x131e28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x131e2c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x131e2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131e30: 0x804993e  j           func_1264F8
    ctx->pc = 0x131E30u;
    ctx->pc = 0x131E34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131E30u;
            // 0x131e34: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001264F8_0x1264f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x131E38u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
