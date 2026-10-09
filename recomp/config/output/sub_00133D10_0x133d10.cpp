#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133D10
// Address: 0x133d10 - 0x133fdc
void sub_00133D10_0x133d10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133D10_0x133d10");
#endif

    switch (ctx->pc) {
        case 0x133d6cu: goto label_133d6c;
        case 0x133d90u: goto label_133d90;
        case 0x133da4u: goto label_133da4;
        case 0x133dc4u: goto label_133dc4;
        case 0x133ddcu: goto label_133ddc;
        case 0x133e04u: goto label_133e04;
        case 0x133e20u: goto label_133e20;
        case 0x133e50u: goto label_133e50;
        case 0x133e68u: goto label_133e68;
        case 0x133e88u: goto label_133e88;
        case 0x133ea0u: goto label_133ea0;
        case 0x133eb8u: goto label_133eb8;
        case 0x133ed0u: goto label_133ed0;
        case 0x133ef0u: goto label_133ef0;
        case 0x133f08u: goto label_133f08;
        case 0x133f20u: goto label_133f20;
        case 0x133f38u: goto label_133f38;
        case 0x133f40u: goto label_133f40;
        case 0x133f54u: goto label_133f54;
        case 0x133f5cu: goto label_133f5c;
        case 0x133f64u: goto label_133f64;
        case 0x133f6cu: goto label_133f6c;
        case 0x133f88u: goto label_133f88;
        case 0x133f90u: goto label_133f90;
        case 0x133f9cu: goto label_133f9c;
        case 0x133fa8u: goto label_133fa8;
        case 0x133fb4u: goto label_133fb4;
        default: break;
    }

    ctx->pc = 0x133d10u;

    // 0x133d10: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x133d10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x133d14: 0xffb40070  sd          $s4, 0x70($sp)
    ctx->pc = 0x133d14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 20));
    // 0x133d18: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x133d18u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133d1c: 0xffb00050  sd          $s0, 0x50($sp)
    ctx->pc = 0x133d1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 16));
    // 0x133d20: 0xffb10058  sd          $s1, 0x58($sp)
    ctx->pc = 0x133d20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 17));
    // 0x133d24: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x133d24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x133d28: 0xffb30068  sd          $s3, 0x68($sp)
    ctx->pc = 0x133d28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 19));
    // 0x133d2c: 0xffb50078  sd          $s5, 0x78($sp)
    ctx->pc = 0x133d2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 21));
    // 0x133d30: 0xffb60080  sd          $s6, 0x80($sp)
    ctx->pc = 0x133d30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 22));
    // 0x133d34: 0xffbf0088  sd          $ra, 0x88($sp)
    ctx->pc = 0x133d34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 136), GPR_U64(ctx, 31));
    // 0x133d38: 0x82820098  lb          $v0, 0x98($s4)
    ctx->pc = 0x133d38u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 152)));
    // 0x133d3c: 0x8e920004  lw          $s2, 0x4($s4)
    ctx->pc = 0x133d3cu;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4)));
    // 0x133d40: 0x1040009c  beqz        $v0, . + 4 + (0x9C << 2)
    ctx->pc = 0x133D40u;
    {
        const bool branch_taken_0x133d40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x133D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133D40u;
            // 0x133d44: 0x8e910014  lw          $s1, 0x14($s4) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133d40) {
            ctx->pc = 0x133FB4u;
            goto label_133fb4;
        }
    }
    ctx->pc = 0x133D48u;
    // 0x133d48: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x133d48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x133d4c: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x133d4cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x133d50: 0xa7a00042  sh          $zero, 0x42($sp)
    ctx->pc = 0x133d50u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 66), (uint16_t)GPR_U32(ctx, 0));
    // 0x133d54: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x133d54u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133d58: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x133d58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x133d5c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x133d5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133d60: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x133d60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x133d64: 0x60f809  jalr        $v1
    ctx->pc = 0x133D64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x133D6Cu);
        ctx->pc = 0x133D68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133D64u;
            // 0x133d68: 0x34c6ffff  ori         $a2, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133D6Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133D6Cu: goto label_133d6c;
            case 0x133D90u: goto label_133d90;
            case 0x133DA4u: goto label_133da4;
            case 0x133DC4u: goto label_133dc4;
            case 0x133DDCu: goto label_133ddc;
            case 0x133DE8u: goto label_133de8;
            case 0x133E04u: goto label_133e04;
            case 0x133E20u: goto label_133e20;
            case 0x133E24u: goto label_133e24;
            case 0x133E50u: goto label_133e50;
            case 0x133E68u: goto label_133e68;
            case 0x133E70u: goto label_133e70;
            case 0x133E88u: goto label_133e88;
            case 0x133EA0u: goto label_133ea0;
            case 0x133EB8u: goto label_133eb8;
            case 0x133ED0u: goto label_133ed0;
            case 0x133ED8u: goto label_133ed8;
            case 0x133EF0u: goto label_133ef0;
            case 0x133F08u: goto label_133f08;
            case 0x133F20u: goto label_133f20;
            case 0x133F38u: goto label_133f38;
            case 0x133F40u: goto label_133f40;
            case 0x133F54u: goto label_133f54;
            case 0x133F5Cu: goto label_133f5c;
            case 0x133F64u: goto label_133f64;
            case 0x133F6Cu: goto label_133f6c;
            case 0x133F80u: goto label_133f80;
            case 0x133F88u: goto label_133f88;
            case 0x133F90u: goto label_133f90;
            case 0x133F9Cu: goto label_133f9c;
            case 0x133FA8u: goto label_133fa8;
            case 0x133FB4u: goto label_133fb4;
            case 0x133FB8u: goto label_133fb8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133D6Cu; }
            if (ctx->pc != 0x133D6Cu) { return; }
        }
        }
    }
    ctx->pc = 0x133D6Cu;
label_133d6c:
    // 0x133d6c: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x133d6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x133d70: 0x27b50020  addiu       $s5, $sp, 0x20
    ctx->pc = 0x133d70u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x133d74: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x133d74u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x133d78: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x133d78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x133d7c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x133d7cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133d80: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x133d80u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x133d84: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x133d84u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x133d88: 0x60f809  jalr        $v1
    ctx->pc = 0x133D88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x133D90u);
        ctx->pc = 0x133D8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133D88u;
            // 0x133d8c: 0x2a0382d  daddu       $a3, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133D90u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133D6Cu: goto label_133d6c;
            case 0x133D90u: goto label_133d90;
            case 0x133DA4u: goto label_133da4;
            case 0x133DC4u: goto label_133dc4;
            case 0x133DDCu: goto label_133ddc;
            case 0x133DE8u: goto label_133de8;
            case 0x133E04u: goto label_133e04;
            case 0x133E20u: goto label_133e20;
            case 0x133E24u: goto label_133e24;
            case 0x133E50u: goto label_133e50;
            case 0x133E68u: goto label_133e68;
            case 0x133E70u: goto label_133e70;
            case 0x133E88u: goto label_133e88;
            case 0x133EA0u: goto label_133ea0;
            case 0x133EB8u: goto label_133eb8;
            case 0x133ED0u: goto label_133ed0;
            case 0x133ED8u: goto label_133ed8;
            case 0x133EF0u: goto label_133ef0;
            case 0x133F08u: goto label_133f08;
            case 0x133F20u: goto label_133f20;
            case 0x133F38u: goto label_133f38;
            case 0x133F40u: goto label_133f40;
            case 0x133F54u: goto label_133f54;
            case 0x133F5Cu: goto label_133f5c;
            case 0x133F64u: goto label_133f64;
            case 0x133F6Cu: goto label_133f6c;
            case 0x133F80u: goto label_133f80;
            case 0x133F88u: goto label_133f88;
            case 0x133F90u: goto label_133f90;
            case 0x133F9Cu: goto label_133f9c;
            case 0x133FA8u: goto label_133fa8;
            case 0x133FB4u: goto label_133fb4;
            case 0x133FB8u: goto label_133fb8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133D90u; }
            if (ctx->pc != 0x133D90u) { return; }
        }
        }
    }
    ctx->pc = 0x133D90u;
label_133d90:
    // 0x133d90: 0x27b30040  addiu       $s3, $sp, 0x40
    ctx->pc = 0x133d90u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x133d94: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x133d94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133d98: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x133d98u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x133d9c: 0xc049bc8  jal         func_126F20
    ctx->pc = 0x133D9Cu;
    SET_GPR_U32(ctx, 31, 0x133DA4u);
    ctx->pc = 0x133DA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133D9Cu;
            // 0x133da0: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126F20u;
    if (runtime->hasFunction(0x126F20u)) {
        auto targetFn = runtime->lookupFunction(0x126F20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133DA4u; }
        if (ctx->pc != 0x133DA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126F20_0x126f20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133DA4u; }
        if (ctx->pc != 0x133DA4u) { return; }
    }
    ctx->pc = 0x133DA4u;
label_133da4:
    // 0x133da4: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x133DA4u;
    {
        const bool branch_taken_0x133da4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x133DA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133DA4u;
            // 0x133da8: 0x2a0302d  daddu       $a2, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133da4) {
            ctx->pc = 0x133DE8u;
            goto label_133de8;
        }
    }
    ctx->pc = 0x133DACu;
    // 0x133dac: 0xa2800098  sb          $zero, 0x98($s4)
    ctx->pc = 0x133dacu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 152), (uint8_t)GPR_U32(ctx, 0));
    // 0x133db0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x133db0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133db4: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x133db4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x133db8: 0x8c43001c  lw          $v1, 0x1C($v0)
    ctx->pc = 0x133db8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x133dbc: 0x60f809  jalr        $v1
    ctx->pc = 0x133DBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x133DC4u);
        ctx->pc = 0x133DC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133DBCu;
            // 0x133dc0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133DC4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133D6Cu: goto label_133d6c;
            case 0x133D90u: goto label_133d90;
            case 0x133DA4u: goto label_133da4;
            case 0x133DC4u: goto label_133dc4;
            case 0x133DDCu: goto label_133ddc;
            case 0x133DE8u: goto label_133de8;
            case 0x133E04u: goto label_133e04;
            case 0x133E20u: goto label_133e20;
            case 0x133E24u: goto label_133e24;
            case 0x133E50u: goto label_133e50;
            case 0x133E68u: goto label_133e68;
            case 0x133E70u: goto label_133e70;
            case 0x133E88u: goto label_133e88;
            case 0x133EA0u: goto label_133ea0;
            case 0x133EB8u: goto label_133eb8;
            case 0x133ED0u: goto label_133ed0;
            case 0x133ED8u: goto label_133ed8;
            case 0x133EF0u: goto label_133ef0;
            case 0x133F08u: goto label_133f08;
            case 0x133F20u: goto label_133f20;
            case 0x133F38u: goto label_133f38;
            case 0x133F40u: goto label_133f40;
            case 0x133F54u: goto label_133f54;
            case 0x133F5Cu: goto label_133f5c;
            case 0x133F64u: goto label_133f64;
            case 0x133F6Cu: goto label_133f6c;
            case 0x133F80u: goto label_133f80;
            case 0x133F88u: goto label_133f88;
            case 0x133F90u: goto label_133f90;
            case 0x133F9Cu: goto label_133f9c;
            case 0x133FA8u: goto label_133fa8;
            case 0x133FB4u: goto label_133fb4;
            case 0x133FB8u: goto label_133fb8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133DC4u; }
            if (ctx->pc != 0x133DC4u) { return; }
        }
        }
    }
    ctx->pc = 0x133DC4u;
label_133dc4:
    // 0x133dc4: 0x8e260000  lw          $a2, 0x0($s1)
    ctx->pc = 0x133dc4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x133dc8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x133dc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133dcc: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x133dccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x133dd0: 0x8cc2001c  lw          $v0, 0x1C($a2)
    ctx->pc = 0x133dd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 28)));
    // 0x133dd4: 0x40f809  jalr        $v0
    ctx->pc = 0x133DD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x133DDCu);
        ctx->pc = 0x133DD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133DD4u;
            // 0x133dd8: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133DDCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133D6Cu: goto label_133d6c;
            case 0x133D90u: goto label_133d90;
            case 0x133DA4u: goto label_133da4;
            case 0x133DC4u: goto label_133dc4;
            case 0x133DDCu: goto label_133ddc;
            case 0x133DE8u: goto label_133de8;
            case 0x133E04u: goto label_133e04;
            case 0x133E20u: goto label_133e20;
            case 0x133E24u: goto label_133e24;
            case 0x133E50u: goto label_133e50;
            case 0x133E68u: goto label_133e68;
            case 0x133E70u: goto label_133e70;
            case 0x133E88u: goto label_133e88;
            case 0x133EA0u: goto label_133ea0;
            case 0x133EB8u: goto label_133eb8;
            case 0x133ED0u: goto label_133ed0;
            case 0x133ED8u: goto label_133ed8;
            case 0x133EF0u: goto label_133ef0;
            case 0x133F08u: goto label_133f08;
            case 0x133F20u: goto label_133f20;
            case 0x133F38u: goto label_133f38;
            case 0x133F40u: goto label_133f40;
            case 0x133F54u: goto label_133f54;
            case 0x133F5Cu: goto label_133f5c;
            case 0x133F64u: goto label_133f64;
            case 0x133F6Cu: goto label_133f6c;
            case 0x133F80u: goto label_133f80;
            case 0x133F88u: goto label_133f88;
            case 0x133F90u: goto label_133f90;
            case 0x133F9Cu: goto label_133f9c;
            case 0x133FA8u: goto label_133fa8;
            case 0x133FB4u: goto label_133fb4;
            case 0x133FB8u: goto label_133fb8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133DDCu; }
            if (ctx->pc != 0x133DDCu) { return; }
        }
        }
    }
    ctx->pc = 0x133DDCu;
label_133ddc:
    // 0x133ddc: 0x10000076  b           . + 4 + (0x76 << 2)
    ctx->pc = 0x133DDCu;
    {
        const bool branch_taken_0x133ddc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x133DE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133DDCu;
            // 0x133de0: 0xdfb00050  ld          $s0, 0x50($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133ddc) {
            ctx->pc = 0x133FB8u;
            goto label_133fb8;
        }
    }
    ctx->pc = 0x133DE4u;
    // 0x133de4: 0x0  nop
    ctx->pc = 0x133de4u;
    // NOP
label_133de8:
    // 0x133de8: 0x87b00040  lh          $s0, 0x40($sp)
    ctx->pc = 0x133de8u;
    SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x133dec: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x133decu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133df0: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x133df0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133df4: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x133df4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x133df8: 0x902021  addu        $a0, $a0, $s0
    ctx->pc = 0x133df8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x133dfc: 0xc04999c  jal         func_126670
    ctx->pc = 0x133DFCu;
    SET_GPR_U32(ctx, 31, 0x133E04u);
    ctx->pc = 0x133E00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133DFCu;
            // 0x133e00: 0xb02823  subu        $a1, $a1, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126670u;
    if (runtime->hasFunction(0x126670u)) {
        auto targetFn = runtime->lookupFunction(0x126670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133E04u; }
        if (ctx->pc != 0x133E04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126670_0x126670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133E04u; }
        if (ctx->pc != 0x133E04u) { return; }
    }
    ctx->pc = 0x133E04u;
label_133e04:
    // 0x133e04: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x133e04u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133e08: 0x12600006  beqz        $s3, . + 4 + (0x6 << 2)
    ctx->pc = 0x133E08u;
    {
        const bool branch_taken_0x133e08 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x133E0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133E08u;
            // 0x133e0c: 0x2403ffff  addiu       $v1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133e08) {
            ctx->pc = 0x133E24u;
            goto label_133e24;
        }
    }
    ctx->pc = 0x133E10u;
    // 0x133e10: 0x8fa40020  lw          $a0, 0x20($sp)
    ctx->pc = 0x133e10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x133e14: 0x27a60042  addiu       $a2, $sp, 0x42
    ctx->pc = 0x133e14u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 66));
    // 0x133e18: 0xc04999c  jal         func_126670
    ctx->pc = 0x133E18u;
    SET_GPR_U32(ctx, 31, 0x133E20u);
    ctx->pc = 0x133E1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133E18u;
            // 0x133e1c: 0x8fa50024  lw          $a1, 0x24($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126670u;
    if (runtime->hasFunction(0x126670u)) {
        auto targetFn = runtime->lookupFunction(0x126670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133E20u; }
        if (ctx->pc != 0x133E20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126670_0x126670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133E20u; }
        if (ctx->pc != 0x133E20u) { return; }
    }
    ctx->pc = 0x133E20u;
label_133e20:
    // 0x133e20: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x133e20u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_133e24:
    // 0x133e24: 0x87a20040  lh          $v0, 0x40($sp)
    ctx->pc = 0x133e24u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x133e28: 0x87b60042  lh          $s6, 0x42($sp)
    ctx->pc = 0x133e28u;
    SET_GPR_S32(ctx, 22, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 66)));
    // 0x133e2c: 0x12600010  beqz        $s3, . + 4 + (0x10 << 2)
    ctx->pc = 0x133E2Cu;
    {
        const bool branch_taken_0x133e2c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x133E30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133E2Cu;
            // 0x133e30: 0x2028021  addu        $s0, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133e2c) {
            ctx->pc = 0x133E70u;
            goto label_133e70;
        }
    }
    ctx->pc = 0x133E34u;
    // 0x133e34: 0x10600028  beqz        $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x133E34u;
    {
        const bool branch_taken_0x133e34 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x133E38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133E34u;
            // 0x133e38: 0x2a0302d  daddu       $a2, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133e34) {
            ctx->pc = 0x133ED8u;
            goto label_133ed8;
        }
    }
    ctx->pc = 0x133E3Cu;
    // 0x133e3c: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x133e3cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x133e40: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x133e40u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133e44: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x133e44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x133e48: 0x40f809  jalr        $v0
    ctx->pc = 0x133E48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x133E50u);
        ctx->pc = 0x133E4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133E48u;
            // 0x133e4c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133E50u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133D6Cu: goto label_133d6c;
            case 0x133D90u: goto label_133d90;
            case 0x133DA4u: goto label_133da4;
            case 0x133DC4u: goto label_133dc4;
            case 0x133DDCu: goto label_133ddc;
            case 0x133DE8u: goto label_133de8;
            case 0x133E04u: goto label_133e04;
            case 0x133E20u: goto label_133e20;
            case 0x133E24u: goto label_133e24;
            case 0x133E50u: goto label_133e50;
            case 0x133E68u: goto label_133e68;
            case 0x133E70u: goto label_133e70;
            case 0x133E88u: goto label_133e88;
            case 0x133EA0u: goto label_133ea0;
            case 0x133EB8u: goto label_133eb8;
            case 0x133ED0u: goto label_133ed0;
            case 0x133ED8u: goto label_133ed8;
            case 0x133EF0u: goto label_133ef0;
            case 0x133F08u: goto label_133f08;
            case 0x133F20u: goto label_133f20;
            case 0x133F38u: goto label_133f38;
            case 0x133F40u: goto label_133f40;
            case 0x133F54u: goto label_133f54;
            case 0x133F5Cu: goto label_133f5c;
            case 0x133F64u: goto label_133f64;
            case 0x133F6Cu: goto label_133f6c;
            case 0x133F80u: goto label_133f80;
            case 0x133F88u: goto label_133f88;
            case 0x133F90u: goto label_133f90;
            case 0x133F9Cu: goto label_133f9c;
            case 0x133FA8u: goto label_133fa8;
            case 0x133FB4u: goto label_133fb4;
            case 0x133FB8u: goto label_133fb8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133E50u; }
            if (ctx->pc != 0x133E50u) { return; }
        }
        }
    }
    ctx->pc = 0x133E50u;
label_133e50:
    // 0x133e50: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x133e50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x133e54: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x133e54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133e58: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x133e58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x133e5c: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x133e5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x133e60: 0x40f809  jalr        $v0
    ctx->pc = 0x133E60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x133E68u);
        ctx->pc = 0x133E64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133E60u;
            // 0x133e64: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133E68u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133D6Cu: goto label_133d6c;
            case 0x133D90u: goto label_133d90;
            case 0x133DA4u: goto label_133da4;
            case 0x133DC4u: goto label_133dc4;
            case 0x133DDCu: goto label_133ddc;
            case 0x133DE8u: goto label_133de8;
            case 0x133E04u: goto label_133e04;
            case 0x133E20u: goto label_133e20;
            case 0x133E24u: goto label_133e24;
            case 0x133E50u: goto label_133e50;
            case 0x133E68u: goto label_133e68;
            case 0x133E70u: goto label_133e70;
            case 0x133E88u: goto label_133e88;
            case 0x133EA0u: goto label_133ea0;
            case 0x133EB8u: goto label_133eb8;
            case 0x133ED0u: goto label_133ed0;
            case 0x133ED8u: goto label_133ed8;
            case 0x133EF0u: goto label_133ef0;
            case 0x133F08u: goto label_133f08;
            case 0x133F20u: goto label_133f20;
            case 0x133F38u: goto label_133f38;
            case 0x133F40u: goto label_133f40;
            case 0x133F54u: goto label_133f54;
            case 0x133F5Cu: goto label_133f5c;
            case 0x133F64u: goto label_133f64;
            case 0x133F6Cu: goto label_133f6c;
            case 0x133F80u: goto label_133f80;
            case 0x133F88u: goto label_133f88;
            case 0x133F90u: goto label_133f90;
            case 0x133F9Cu: goto label_133f9c;
            case 0x133FA8u: goto label_133fa8;
            case 0x133FB4u: goto label_133fb4;
            case 0x133FB8u: goto label_133fb8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133E68u; }
            if (ctx->pc != 0x133E68u) { return; }
        }
        }
    }
    ctx->pc = 0x133E68u;
label_133e68:
    // 0x133e68: 0x10000052  b           . + 4 + (0x52 << 2)
    ctx->pc = 0x133E68u;
    {
        const bool branch_taken_0x133e68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x133E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133E68u;
            // 0x133e6c: 0xa2800098  sb          $zero, 0x98($s4) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 20), 152), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133e68) {
            ctx->pc = 0x133FB4u;
            goto label_133fb4;
        }
    }
    ctx->pc = 0x133E70u;
label_133e70:
    // 0x133e70: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x133e70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x133e74: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x133e74u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133e78: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x133e78u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133e7c: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x133e7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x133e80: 0x40f809  jalr        $v0
    ctx->pc = 0x133E80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x133E88u);
        ctx->pc = 0x133E84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133E80u;
            // 0x133e84: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133E88u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133D6Cu: goto label_133d6c;
            case 0x133D90u: goto label_133d90;
            case 0x133DA4u: goto label_133da4;
            case 0x133DC4u: goto label_133dc4;
            case 0x133DDCu: goto label_133ddc;
            case 0x133DE8u: goto label_133de8;
            case 0x133E04u: goto label_133e04;
            case 0x133E20u: goto label_133e20;
            case 0x133E24u: goto label_133e24;
            case 0x133E50u: goto label_133e50;
            case 0x133E68u: goto label_133e68;
            case 0x133E70u: goto label_133e70;
            case 0x133E88u: goto label_133e88;
            case 0x133EA0u: goto label_133ea0;
            case 0x133EB8u: goto label_133eb8;
            case 0x133ED0u: goto label_133ed0;
            case 0x133ED8u: goto label_133ed8;
            case 0x133EF0u: goto label_133ef0;
            case 0x133F08u: goto label_133f08;
            case 0x133F20u: goto label_133f20;
            case 0x133F38u: goto label_133f38;
            case 0x133F40u: goto label_133f40;
            case 0x133F54u: goto label_133f54;
            case 0x133F5Cu: goto label_133f5c;
            case 0x133F64u: goto label_133f64;
            case 0x133F6Cu: goto label_133f6c;
            case 0x133F80u: goto label_133f80;
            case 0x133F88u: goto label_133f88;
            case 0x133F90u: goto label_133f90;
            case 0x133F9Cu: goto label_133f9c;
            case 0x133FA8u: goto label_133fa8;
            case 0x133FB4u: goto label_133fb4;
            case 0x133FB8u: goto label_133fb8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133E88u; }
            if (ctx->pc != 0x133E88u) { return; }
        }
        }
    }
    ctx->pc = 0x133E88u;
label_133e88:
    // 0x133e88: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x133e88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133e8c: 0x27b00010  addiu       $s0, $sp, 0x10
    ctx->pc = 0x133e8cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x133e90: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x133e90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133e94: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x133e94u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133e98: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x133E98u;
    SET_GPR_U32(ctx, 31, 0x133EA0u);
    ctx->pc = 0x133E9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133E98u;
            // 0x133e9c: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133EA0u; }
        if (ctx->pc != 0x133EA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133EA0u; }
        if (ctx->pc != 0x133EA0u) { return; }
    }
    ctx->pc = 0x133EA0u;
label_133ea0:
    // 0x133ea0: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x133ea0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x133ea4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x133ea4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133ea8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x133ea8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133eac: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x133eacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x133eb0: 0x40f809  jalr        $v0
    ctx->pc = 0x133EB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x133EB8u);
        ctx->pc = 0x133EB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133EB0u;
            // 0x133eb4: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133EB8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133D6Cu: goto label_133d6c;
            case 0x133D90u: goto label_133d90;
            case 0x133DA4u: goto label_133da4;
            case 0x133DC4u: goto label_133dc4;
            case 0x133DDCu: goto label_133ddc;
            case 0x133DE8u: goto label_133de8;
            case 0x133E04u: goto label_133e04;
            case 0x133E20u: goto label_133e20;
            case 0x133E24u: goto label_133e24;
            case 0x133E50u: goto label_133e50;
            case 0x133E68u: goto label_133e68;
            case 0x133E70u: goto label_133e70;
            case 0x133E88u: goto label_133e88;
            case 0x133EA0u: goto label_133ea0;
            case 0x133EB8u: goto label_133eb8;
            case 0x133ED0u: goto label_133ed0;
            case 0x133ED8u: goto label_133ed8;
            case 0x133EF0u: goto label_133ef0;
            case 0x133F08u: goto label_133f08;
            case 0x133F20u: goto label_133f20;
            case 0x133F38u: goto label_133f38;
            case 0x133F40u: goto label_133f40;
            case 0x133F54u: goto label_133f54;
            case 0x133F5Cu: goto label_133f5c;
            case 0x133F64u: goto label_133f64;
            case 0x133F6Cu: goto label_133f6c;
            case 0x133F80u: goto label_133f80;
            case 0x133F88u: goto label_133f88;
            case 0x133F90u: goto label_133f90;
            case 0x133F9Cu: goto label_133f9c;
            case 0x133FA8u: goto label_133fa8;
            case 0x133FB4u: goto label_133fb4;
            case 0x133FB8u: goto label_133fb8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133EB8u; }
            if (ctx->pc != 0x133EB8u) { return; }
        }
        }
    }
    ctx->pc = 0x133EB8u;
label_133eb8:
    // 0x133eb8: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x133eb8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x133ebc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x133ebcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133ec0: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x133ec0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133ec4: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x133ec4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x133ec8: 0x40f809  jalr        $v0
    ctx->pc = 0x133EC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x133ED0u);
        ctx->pc = 0x133ECCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133EC8u;
            // 0x133ecc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133ED0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133D6Cu: goto label_133d6c;
            case 0x133D90u: goto label_133d90;
            case 0x133DA4u: goto label_133da4;
            case 0x133DC4u: goto label_133dc4;
            case 0x133DDCu: goto label_133ddc;
            case 0x133DE8u: goto label_133de8;
            case 0x133E04u: goto label_133e04;
            case 0x133E20u: goto label_133e20;
            case 0x133E24u: goto label_133e24;
            case 0x133E50u: goto label_133e50;
            case 0x133E68u: goto label_133e68;
            case 0x133E70u: goto label_133e70;
            case 0x133E88u: goto label_133e88;
            case 0x133EA0u: goto label_133ea0;
            case 0x133EB8u: goto label_133eb8;
            case 0x133ED0u: goto label_133ed0;
            case 0x133ED8u: goto label_133ed8;
            case 0x133EF0u: goto label_133ef0;
            case 0x133F08u: goto label_133f08;
            case 0x133F20u: goto label_133f20;
            case 0x133F38u: goto label_133f38;
            case 0x133F40u: goto label_133f40;
            case 0x133F54u: goto label_133f54;
            case 0x133F5Cu: goto label_133f5c;
            case 0x133F64u: goto label_133f64;
            case 0x133F6Cu: goto label_133f6c;
            case 0x133F80u: goto label_133f80;
            case 0x133F88u: goto label_133f88;
            case 0x133F90u: goto label_133f90;
            case 0x133F9Cu: goto label_133f9c;
            case 0x133FA8u: goto label_133fa8;
            case 0x133FB4u: goto label_133fb4;
            case 0x133FB8u: goto label_133fb8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133ED0u; }
            if (ctx->pc != 0x133ED0u) { return; }
        }
        }
    }
    ctx->pc = 0x133ED0u;
label_133ed0:
    // 0x133ed0: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x133ED0u;
    {
        const bool branch_taken_0x133ed0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x133ed0) {
            ctx->pc = 0x133F38u;
            goto label_133f38;
        }
    }
    ctx->pc = 0x133ED8u;
label_133ed8:
    // 0x133ed8: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x133ed8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x133edc: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x133edcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133ee0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x133ee0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133ee4: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x133ee4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x133ee8: 0x40f809  jalr        $v0
    ctx->pc = 0x133EE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x133EF0u);
        ctx->pc = 0x133EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133EE8u;
            // 0x133eec: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133EF0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133D6Cu: goto label_133d6c;
            case 0x133D90u: goto label_133d90;
            case 0x133DA4u: goto label_133da4;
            case 0x133DC4u: goto label_133dc4;
            case 0x133DDCu: goto label_133ddc;
            case 0x133DE8u: goto label_133de8;
            case 0x133E04u: goto label_133e04;
            case 0x133E20u: goto label_133e20;
            case 0x133E24u: goto label_133e24;
            case 0x133E50u: goto label_133e50;
            case 0x133E68u: goto label_133e68;
            case 0x133E70u: goto label_133e70;
            case 0x133E88u: goto label_133e88;
            case 0x133EA0u: goto label_133ea0;
            case 0x133EB8u: goto label_133eb8;
            case 0x133ED0u: goto label_133ed0;
            case 0x133ED8u: goto label_133ed8;
            case 0x133EF0u: goto label_133ef0;
            case 0x133F08u: goto label_133f08;
            case 0x133F20u: goto label_133f20;
            case 0x133F38u: goto label_133f38;
            case 0x133F40u: goto label_133f40;
            case 0x133F54u: goto label_133f54;
            case 0x133F5Cu: goto label_133f5c;
            case 0x133F64u: goto label_133f64;
            case 0x133F6Cu: goto label_133f6c;
            case 0x133F80u: goto label_133f80;
            case 0x133F88u: goto label_133f88;
            case 0x133F90u: goto label_133f90;
            case 0x133F9Cu: goto label_133f9c;
            case 0x133FA8u: goto label_133fa8;
            case 0x133FB4u: goto label_133fb4;
            case 0x133FB8u: goto label_133fb8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133EF0u; }
            if (ctx->pc != 0x133EF0u) { return; }
        }
        }
    }
    ctx->pc = 0x133EF0u;
label_133ef0:
    // 0x133ef0: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x133ef0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133ef4: 0x27b00030  addiu       $s0, $sp, 0x30
    ctx->pc = 0x133ef4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x133ef8: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x133ef8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133efc: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x133efcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133f00: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x133F00u;
    SET_GPR_U32(ctx, 31, 0x133F08u);
    ctx->pc = 0x133F04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133F00u;
            // 0x133f04: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F08u; }
        if (ctx->pc != 0x133F08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F08u; }
        if (ctx->pc != 0x133F08u) { return; }
    }
    ctx->pc = 0x133F08u;
label_133f08:
    // 0x133f08: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x133f08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x133f0c: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x133f0cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133f10: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x133f10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133f14: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x133f14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x133f18: 0x40f809  jalr        $v0
    ctx->pc = 0x133F18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x133F20u);
        ctx->pc = 0x133F1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133F18u;
            // 0x133f1c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133F20u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133D6Cu: goto label_133d6c;
            case 0x133D90u: goto label_133d90;
            case 0x133DA4u: goto label_133da4;
            case 0x133DC4u: goto label_133dc4;
            case 0x133DDCu: goto label_133ddc;
            case 0x133DE8u: goto label_133de8;
            case 0x133E04u: goto label_133e04;
            case 0x133E20u: goto label_133e20;
            case 0x133E24u: goto label_133e24;
            case 0x133E50u: goto label_133e50;
            case 0x133E68u: goto label_133e68;
            case 0x133E70u: goto label_133e70;
            case 0x133E88u: goto label_133e88;
            case 0x133EA0u: goto label_133ea0;
            case 0x133EB8u: goto label_133eb8;
            case 0x133ED0u: goto label_133ed0;
            case 0x133ED8u: goto label_133ed8;
            case 0x133EF0u: goto label_133ef0;
            case 0x133F08u: goto label_133f08;
            case 0x133F20u: goto label_133f20;
            case 0x133F38u: goto label_133f38;
            case 0x133F40u: goto label_133f40;
            case 0x133F54u: goto label_133f54;
            case 0x133F5Cu: goto label_133f5c;
            case 0x133F64u: goto label_133f64;
            case 0x133F6Cu: goto label_133f6c;
            case 0x133F80u: goto label_133f80;
            case 0x133F88u: goto label_133f88;
            case 0x133F90u: goto label_133f90;
            case 0x133F9Cu: goto label_133f9c;
            case 0x133FA8u: goto label_133fa8;
            case 0x133FB4u: goto label_133fb4;
            case 0x133FB8u: goto label_133fb8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133F20u; }
            if (ctx->pc != 0x133F20u) { return; }
        }
        }
    }
    ctx->pc = 0x133F20u;
label_133f20:
    // 0x133f20: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x133f20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x133f24: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x133f24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133f28: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x133f28u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133f2c: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x133f2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x133f30: 0x40f809  jalr        $v0
    ctx->pc = 0x133F30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x133F38u);
        ctx->pc = 0x133F34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133F30u;
            // 0x133f34: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133F38u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133D6Cu: goto label_133d6c;
            case 0x133D90u: goto label_133d90;
            case 0x133DA4u: goto label_133da4;
            case 0x133DC4u: goto label_133dc4;
            case 0x133DDCu: goto label_133ddc;
            case 0x133DE8u: goto label_133de8;
            case 0x133E04u: goto label_133e04;
            case 0x133E20u: goto label_133e20;
            case 0x133E24u: goto label_133e24;
            case 0x133E50u: goto label_133e50;
            case 0x133E68u: goto label_133e68;
            case 0x133E70u: goto label_133e70;
            case 0x133E88u: goto label_133e88;
            case 0x133EA0u: goto label_133ea0;
            case 0x133EB8u: goto label_133eb8;
            case 0x133ED0u: goto label_133ed0;
            case 0x133ED8u: goto label_133ed8;
            case 0x133EF0u: goto label_133ef0;
            case 0x133F08u: goto label_133f08;
            case 0x133F20u: goto label_133f20;
            case 0x133F38u: goto label_133f38;
            case 0x133F40u: goto label_133f40;
            case 0x133F54u: goto label_133f54;
            case 0x133F5Cu: goto label_133f5c;
            case 0x133F64u: goto label_133f64;
            case 0x133F6Cu: goto label_133f6c;
            case 0x133F80u: goto label_133f80;
            case 0x133F88u: goto label_133f88;
            case 0x133F90u: goto label_133f90;
            case 0x133F9Cu: goto label_133f9c;
            case 0x133FA8u: goto label_133fa8;
            case 0x133FB4u: goto label_133fb4;
            case 0x133FB8u: goto label_133fb8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133F38u; }
            if (ctx->pc != 0x133F38u) { return; }
        }
        }
    }
    ctx->pc = 0x133F38u;
label_133f38:
    // 0x133f38: 0xc04b5b8  jal         func_12D6E0
    ctx->pc = 0x133F38u;
    SET_GPR_U32(ctx, 31, 0x133F40u);
    ctx->pc = 0x133F3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133F38u;
            // 0x133f3c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D6E0u;
    if (runtime->hasFunction(0x12D6E0u)) {
        auto targetFn = runtime->lookupFunction(0x12D6E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F40u; }
        if (ctx->pc != 0x133F40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D6E0_0x12d6e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F40u; }
        if (ctx->pc != 0x133F40u) { return; }
    }
    ctx->pc = 0x133F40u;
label_133f40:
    // 0x133f40: 0x8e8300a4  lw          $v1, 0xA4($s4)
    ctx->pc = 0x133f40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 164)));
    // 0x133f44: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x133f44u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133f48: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x133f48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x133f4c: 0xc04b32c  jal         func_12CCB0
    ctx->pc = 0x133F4Cu;
    SET_GPR_U32(ctx, 31, 0x133F54u);
    ctx->pc = 0x133F50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133F4Cu;
            // 0x133f50: 0xae8300a4  sw          $v1, 0xA4($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 164), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CCB0u;
    if (runtime->hasFunction(0x12CCB0u)) {
        auto targetFn = runtime->lookupFunction(0x12CCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F54u; }
        if (ctx->pc != 0x133F54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CCB0_0x12ccb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F54u; }
        if (ctx->pc != 0x133F54u) { return; }
    }
    ctx->pc = 0x133F54u;
label_133f54:
    // 0x133f54: 0xc04b320  jal         func_12CC80
    ctx->pc = 0x133F54u;
    SET_GPR_U32(ctx, 31, 0x133F5Cu);
    ctx->pc = 0x133F58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133F54u;
            // 0x133f58: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CC80u;
    if (runtime->hasFunction(0x12CC80u)) {
        auto targetFn = runtime->lookupFunction(0x12CC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F5Cu; }
        if (ctx->pc != 0x133F5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CC80_0x12cc80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F5Cu; }
        if (ctx->pc != 0x133F5Cu) { return; }
    }
    ctx->pc = 0x133F5Cu;
label_133f5c:
    // 0x133f5c: 0xc04b58e  jal         func_12D638
    ctx->pc = 0x133F5Cu;
    SET_GPR_U32(ctx, 31, 0x133F64u);
    ctx->pc = 0x133F60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133F5Cu;
            // 0x133f60: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D638u;
    if (runtime->hasFunction(0x12D638u)) {
        auto targetFn = runtime->lookupFunction(0x12D638u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F64u; }
        if (ctx->pc != 0x133F64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D638_0x12d638(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F64u; }
        if (ctx->pc != 0x133F64u) { return; }
    }
    ctx->pc = 0x133F64u;
label_133f64:
    // 0x133f64: 0xc04b2ee  jal         func_12CBB8
    ctx->pc = 0x133F64u;
    SET_GPR_U32(ctx, 31, 0x133F6Cu);
    ctx->pc = 0x133F68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133F64u;
            // 0x133f68: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CBB8u;
    if (runtime->hasFunction(0x12CBB8u)) {
        auto targetFn = runtime->lookupFunction(0x12CBB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F6Cu; }
        if (ctx->pc != 0x133F6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CBB8_0x12cbb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F6Cu; }
        if (ctx->pc != 0x133F6Cu) { return; }
    }
    ctx->pc = 0x133F6Cu;
label_133f6c:
    // 0x133f6c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x133f6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x133f70: 0x50430003  beql        $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x133F70u;
    {
        const bool branch_taken_0x133f70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x133f70) {
            ctx->pc = 0x133F74u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x133F70u;
            // 0x133f74: 0x8e850048  lw          $a1, 0x48($s4) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 72)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x133F80u;
            goto label_133f80;
        }
    }
    ctx->pc = 0x133F78u;
    // 0x133f78: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x133F78u;
    {
        const bool branch_taken_0x133f78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x133F7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133F78u;
            // 0x133f7c: 0xa2800098  sb          $zero, 0x98($s4) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 20), 152), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133f78) {
            ctx->pc = 0x133FB4u;
            goto label_133fb4;
        }
    }
    ctx->pc = 0x133F80u;
label_133f80:
    // 0x133f80: 0xc04b304  jal         func_12CC10
    ctx->pc = 0x133F80u;
    SET_GPR_U32(ctx, 31, 0x133F88u);
    ctx->pc = 0x133F84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133F80u;
            // 0x133f84: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CC10u;
    if (runtime->hasFunction(0x12CC10u)) {
        auto targetFn = runtime->lookupFunction(0x12CC10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F88u; }
        if (ctx->pc != 0x133F88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CC10_0x12cc10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F88u; }
        if (ctx->pc != 0x133F88u) { return; }
    }
    ctx->pc = 0x133F88u;
label_133f88:
    // 0x133f88: 0xc04b602  jal         func_12D808
    ctx->pc = 0x133F88u;
    SET_GPR_U32(ctx, 31, 0x133F90u);
    ctx->pc = 0x133F8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133F88u;
            // 0x133f8c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D808u;
    if (runtime->hasFunction(0x12D808u)) {
        auto targetFn = runtime->lookupFunction(0x12D808u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F90u; }
        if (ctx->pc != 0x133F90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D808_0x12d808(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F90u; }
        if (ctx->pc != 0x133F90u) { return; }
    }
    ctx->pc = 0x133F90u;
label_133f90:
    // 0x133f90: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x133f90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133f94: 0xc04b5d2  jal         func_12D748
    ctx->pc = 0x133F94u;
    SET_GPR_U32(ctx, 31, 0x133F9Cu);
    ctx->pc = 0x133F98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133F94u;
            // 0x133f98: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D748u;
    if (runtime->hasFunction(0x12D748u)) {
        auto targetFn = runtime->lookupFunction(0x12D748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F9Cu; }
        if (ctx->pc != 0x133F9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D748_0x12d748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133F9Cu; }
        if (ctx->pc != 0x133F9Cu) { return; }
    }
    ctx->pc = 0x133F9Cu;
label_133f9c:
    // 0x133f9c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x133f9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133fa0: 0xc04b5da  jal         func_12D768
    ctx->pc = 0x133FA0u;
    SET_GPR_U32(ctx, 31, 0x133FA8u);
    ctx->pc = 0x133FA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133FA0u;
            // 0x133fa4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D768u;
    if (runtime->hasFunction(0x12D768u)) {
        auto targetFn = runtime->lookupFunction(0x12D768u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133FA8u; }
        if (ctx->pc != 0x133FA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D768_0x12d768(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133FA8u; }
        if (ctx->pc != 0x133FA8u) { return; }
    }
    ctx->pc = 0x133FA8u;
label_133fa8:
    // 0x133fa8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x133fa8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133fac: 0xc04b5d6  jal         func_12D758
    ctx->pc = 0x133FACu;
    SET_GPR_U32(ctx, 31, 0x133FB4u);
    ctx->pc = 0x133FB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133FACu;
            // 0x133fb0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D758u;
    if (runtime->hasFunction(0x12D758u)) {
        auto targetFn = runtime->lookupFunction(0x12D758u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133FB4u; }
        if (ctx->pc != 0x133FB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D758_0x12d758(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133FB4u; }
        if (ctx->pc != 0x133FB4u) { return; }
    }
    ctx->pc = 0x133FB4u;
label_133fb4:
    // 0x133fb4: 0xdfb00050  ld          $s0, 0x50($sp)
    ctx->pc = 0x133fb4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_133fb8:
    // 0x133fb8: 0xdfb10058  ld          $s1, 0x58($sp)
    ctx->pc = 0x133fb8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x133fbc: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x133fbcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x133fc0: 0xdfb30068  ld          $s3, 0x68($sp)
    ctx->pc = 0x133fc0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x133fc4: 0xdfb40070  ld          $s4, 0x70($sp)
    ctx->pc = 0x133fc4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x133fc8: 0xdfb50078  ld          $s5, 0x78($sp)
    ctx->pc = 0x133fc8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x133fcc: 0xdfb60080  ld          $s6, 0x80($sp)
    ctx->pc = 0x133fccu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x133fd0: 0xdfbf0088  ld          $ra, 0x88($sp)
    ctx->pc = 0x133fd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x133fd4: 0x3e00008  jr          $ra
    ctx->pc = 0x133FD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x133FD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133FD4u;
            // 0x133fd8: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133D6Cu: goto label_133d6c;
            case 0x133D90u: goto label_133d90;
            case 0x133DA4u: goto label_133da4;
            case 0x133DC4u: goto label_133dc4;
            case 0x133DDCu: goto label_133ddc;
            case 0x133DE8u: goto label_133de8;
            case 0x133E04u: goto label_133e04;
            case 0x133E20u: goto label_133e20;
            case 0x133E24u: goto label_133e24;
            case 0x133E50u: goto label_133e50;
            case 0x133E68u: goto label_133e68;
            case 0x133E70u: goto label_133e70;
            case 0x133E88u: goto label_133e88;
            case 0x133EA0u: goto label_133ea0;
            case 0x133EB8u: goto label_133eb8;
            case 0x133ED0u: goto label_133ed0;
            case 0x133ED8u: goto label_133ed8;
            case 0x133EF0u: goto label_133ef0;
            case 0x133F08u: goto label_133f08;
            case 0x133F20u: goto label_133f20;
            case 0x133F38u: goto label_133f38;
            case 0x133F40u: goto label_133f40;
            case 0x133F54u: goto label_133f54;
            case 0x133F5Cu: goto label_133f5c;
            case 0x133F64u: goto label_133f64;
            case 0x133F6Cu: goto label_133f6c;
            case 0x133F80u: goto label_133f80;
            case 0x133F88u: goto label_133f88;
            case 0x133F90u: goto label_133f90;
            case 0x133F9Cu: goto label_133f9c;
            case 0x133FA8u: goto label_133fa8;
            case 0x133FB4u: goto label_133fb4;
            case 0x133FB8u: goto label_133fb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x133FDCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
