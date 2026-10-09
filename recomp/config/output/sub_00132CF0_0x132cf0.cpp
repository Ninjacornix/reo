#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132CF0
// Address: 0x132cf0 - 0x132df0
void sub_00132CF0_0x132cf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132CF0_0x132cf0");
#endif

    switch (ctx->pc) {
        case 0x132d08u: goto label_132d08;
        case 0x132d78u: goto label_132d78;
        case 0x132dd8u: goto label_132dd8;
        default: break;
    }

    ctx->pc = 0x132cf0u;

    // 0x132cf0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132cf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132cf4: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x132CF4u;
    {
        const bool branch_taken_0x132cf4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132CF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132CF4u;
            // 0x132cf8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132cf4) {
            ctx->pc = 0x132D10u;
            goto label_132d10;
        }
    }
    ctx->pc = 0x132CFCu;
    // 0x132cfc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132cfcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132d00: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132D00u;
    SET_GPR_U32(ctx, 31, 0x132D08u);
    ctx->pc = 0x132D04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132D00u;
            // 0x132d04: 0x2484b360  addiu       $a0, $a0, -0x4CA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947680));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132D08u; }
        if (ctx->pc != 0x132D08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132D08u; }
        if (ctx->pc != 0x132D08u) { return; }
    }
    ctx->pc = 0x132D08u;
label_132d08:
    // 0x132d08: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x132D08u;
    {
        const bool branch_taken_0x132d08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132D0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132D08u;
            // 0x132d0c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132d08) {
            ctx->pc = 0x132D14u;
            goto label_132d14;
        }
    }
    ctx->pc = 0x132D10u;
label_132d10:
    // 0x132d10: 0x84820060  lh          $v0, 0x60($a0)
    ctx->pc = 0x132d10u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 96)));
label_132d14:
    // 0x132d14: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132d14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132d18: 0x3e00008  jr          $ra
    ctx->pc = 0x132D18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132D1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132D18u;
            // 0x132d1c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132D08u: goto label_132d08;
            case 0x132D10u: goto label_132d10;
            case 0x132D14u: goto label_132d14;
            case 0x132D40u: goto label_132d40;
            case 0x132D78u: goto label_132d78;
            case 0x132D80u: goto label_132d80;
            case 0x132D84u: goto label_132d84;
            case 0x132DB0u: goto label_132db0;
            case 0x132DD8u: goto label_132dd8;
            case 0x132DE0u: goto label_132de0;
            case 0x132DE4u: goto label_132de4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132D20u;
    // 0x132d20: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132d20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132d24: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x132D24u;
    {
        const bool branch_taken_0x132d24 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132D28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132D24u;
            // 0x132d28: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132d24) {
            ctx->pc = 0x132D40u;
            goto label_132d40;
        }
    }
    ctx->pc = 0x132D2Cu;
    // 0x132d2c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132d2cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132d30: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132d30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132d34: 0x2484b390  addiu       $a0, $a0, -0x4C70
    ctx->pc = 0x132d34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947728));
    // 0x132d38: 0x804a034  j           func_1280D0
    ctx->pc = 0x132D38u;
    ctx->pc = 0x132D3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132D38u;
            // 0x132d3c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x132D40u;
label_132d40:
    // 0x132d40: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132d40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132d44: 0xa480006a  sh          $zero, 0x6A($a0)
    ctx->pc = 0x132d44u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 106), (uint16_t)GPR_U32(ctx, 0));
    // 0x132d48: 0xa4800060  sh          $zero, 0x60($a0)
    ctx->pc = 0x132d48u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 96), (uint16_t)GPR_U32(ctx, 0));
    // 0x132d4c: 0xac800064  sw          $zero, 0x64($a0)
    ctx->pc = 0x132d4cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 100), GPR_U32(ctx, 0));
    // 0x132d50: 0xa4800068  sh          $zero, 0x68($a0)
    ctx->pc = 0x132d50u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 104), (uint16_t)GPR_U32(ctx, 0));
    // 0x132d54: 0x3e00008  jr          $ra
    ctx->pc = 0x132D54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132D58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132D54u;
            // 0x132d58: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132D08u: goto label_132d08;
            case 0x132D10u: goto label_132d10;
            case 0x132D14u: goto label_132d14;
            case 0x132D40u: goto label_132d40;
            case 0x132D78u: goto label_132d78;
            case 0x132D80u: goto label_132d80;
            case 0x132D84u: goto label_132d84;
            case 0x132DB0u: goto label_132db0;
            case 0x132DD8u: goto label_132dd8;
            case 0x132DE0u: goto label_132de0;
            case 0x132DE4u: goto label_132de4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132D5Cu;
    // 0x132d5c: 0x0  nop
    ctx->pc = 0x132d5cu;
    // NOP
    // 0x132d60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132d60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132d64: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x132D64u;
    {
        const bool branch_taken_0x132d64 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132D68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132D64u;
            // 0x132d68: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132d64) {
            ctx->pc = 0x132D80u;
            goto label_132d80;
        }
    }
    ctx->pc = 0x132D6Cu;
    // 0x132d6c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132d6cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132d70: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132D70u;
    SET_GPR_U32(ctx, 31, 0x132D78u);
    ctx->pc = 0x132D74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132D70u;
            // 0x132d74: 0x2484b3c0  addiu       $a0, $a0, -0x4C40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947776));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132D78u; }
        if (ctx->pc != 0x132D78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132D78u; }
        if (ctx->pc != 0x132D78u) { return; }
    }
    ctx->pc = 0x132D78u;
label_132d78:
    // 0x132d78: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x132D78u;
    {
        const bool branch_taken_0x132d78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132D78u;
            // 0x132d7c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132d78) {
            ctx->pc = 0x132D84u;
            goto label_132d84;
        }
    }
    ctx->pc = 0x132D80u;
label_132d80:
    // 0x132d80: 0x8c82004c  lw          $v0, 0x4C($a0)
    ctx->pc = 0x132d80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
label_132d84:
    // 0x132d84: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132d84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132d88: 0x3e00008  jr          $ra
    ctx->pc = 0x132D88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132D8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132D88u;
            // 0x132d8c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132D08u: goto label_132d08;
            case 0x132D10u: goto label_132d10;
            case 0x132D14u: goto label_132d14;
            case 0x132D40u: goto label_132d40;
            case 0x132D78u: goto label_132d78;
            case 0x132D80u: goto label_132d80;
            case 0x132D84u: goto label_132d84;
            case 0x132DB0u: goto label_132db0;
            case 0x132DD8u: goto label_132dd8;
            case 0x132DE0u: goto label_132de0;
            case 0x132DE4u: goto label_132de4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132D90u;
    // 0x132d90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132d90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132d94: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x132D94u;
    {
        const bool branch_taken_0x132d94 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132D98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132D94u;
            // 0x132d98: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132d94) {
            ctx->pc = 0x132DB0u;
            goto label_132db0;
        }
    }
    ctx->pc = 0x132D9Cu;
    // 0x132d9c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132d9cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132da0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132da0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132da4: 0x2484b3f0  addiu       $a0, $a0, -0x4C10
    ctx->pc = 0x132da4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947824));
    // 0x132da8: 0x804a034  j           func_1280D0
    ctx->pc = 0x132DA8u;
    ctx->pc = 0x132DACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132DA8u;
            // 0x132dac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x132DB0u;
label_132db0:
    // 0x132db0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132db0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132db4: 0xa085006c  sb          $a1, 0x6C($a0)
    ctx->pc = 0x132db4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 108), (uint8_t)GPR_U32(ctx, 5));
    // 0x132db8: 0x3e00008  jr          $ra
    ctx->pc = 0x132DB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132DBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132DB8u;
            // 0x132dbc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132D08u: goto label_132d08;
            case 0x132D10u: goto label_132d10;
            case 0x132D14u: goto label_132d14;
            case 0x132D40u: goto label_132d40;
            case 0x132D78u: goto label_132d78;
            case 0x132D80u: goto label_132d80;
            case 0x132D84u: goto label_132d84;
            case 0x132DB0u: goto label_132db0;
            case 0x132DD8u: goto label_132dd8;
            case 0x132DE0u: goto label_132de0;
            case 0x132DE4u: goto label_132de4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132DC0u;
    // 0x132dc0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132dc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132dc4: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x132DC4u;
    {
        const bool branch_taken_0x132dc4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132DC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132DC4u;
            // 0x132dc8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132dc4) {
            ctx->pc = 0x132DE0u;
            goto label_132de0;
        }
    }
    ctx->pc = 0x132DCCu;
    // 0x132dcc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132dccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132dd0: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132DD0u;
    SET_GPR_U32(ctx, 31, 0x132DD8u);
    ctx->pc = 0x132DD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132DD0u;
            // 0x132dd4: 0x2484b420  addiu       $a0, $a0, -0x4BE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947872));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132DD8u; }
        if (ctx->pc != 0x132DD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132DD8u; }
        if (ctx->pc != 0x132DD8u) { return; }
    }
    ctx->pc = 0x132DD8u;
label_132dd8:
    // 0x132dd8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x132DD8u;
    {
        const bool branch_taken_0x132dd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132DDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132DD8u;
            // 0x132ddc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132dd8) {
            ctx->pc = 0x132DE4u;
            goto label_132de4;
        }
    }
    ctx->pc = 0x132DE0u;
label_132de0:
    // 0x132de0: 0x8c820014  lw          $v0, 0x14($a0)
    ctx->pc = 0x132de0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
label_132de4:
    // 0x132de4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132de4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132de8: 0x3e00008  jr          $ra
    ctx->pc = 0x132DE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132DECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132DE8u;
            // 0x132dec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132D08u: goto label_132d08;
            case 0x132D10u: goto label_132d10;
            case 0x132D14u: goto label_132d14;
            case 0x132D40u: goto label_132d40;
            case 0x132D78u: goto label_132d78;
            case 0x132D80u: goto label_132d80;
            case 0x132D84u: goto label_132d84;
            case 0x132DB0u: goto label_132db0;
            case 0x132DD8u: goto label_132dd8;
            case 0x132DE0u: goto label_132de0;
            case 0x132DE4u: goto label_132de4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132DF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
