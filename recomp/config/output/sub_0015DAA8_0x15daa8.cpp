#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015DAA8
// Address: 0x15daa8 - 0x15dc28
void sub_0015DAA8_0x15daa8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015DAA8_0x15daa8");
#endif

    switch (ctx->pc) {
        case 0x15daf0u: goto label_15daf0;
        case 0x15db1cu: goto label_15db1c;
        case 0x15db4cu: goto label_15db4c;
        case 0x15db60u: goto label_15db60;
        case 0x15db70u: goto label_15db70;
        case 0x15db84u: goto label_15db84;
        case 0x15dbf8u: goto label_15dbf8;
        default: break;
    }

    ctx->pc = 0x15daa8u;

    // 0x15daa8: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x15daa8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x15daac: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x15daacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x15dab0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x15dab0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15dab4: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x15dab4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x15dab8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x15dab8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15dabc: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x15dabcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x15dac0: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x15dac0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x15dac4: 0xffb50058  sd          $s5, 0x58($sp)
    ctx->pc = 0x15dac4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 21));
    // 0x15dac8: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x15dac8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x15dacc: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x15daccu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15dad0: 0xffbe0070  sd          $fp, 0x70($sp)
    ctx->pc = 0x15dad0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 30));
    // 0x15dad4: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x15dad4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x15dad8: 0xffb70068  sd          $s7, 0x68($sp)
    ctx->pc = 0x15dad8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 23));
    // 0x15dadc: 0xffbf0078  sd          $ra, 0x78($sp)
    ctx->pc = 0x15dadcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 31));
    // 0x15dae0: 0x8e44001c  lw          $a0, 0x1C($s2)
    ctx->pc = 0x15dae0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
    // 0x15dae4: 0x8ed00040  lw          $s0, 0x40($s6)
    ctx->pc = 0x15dae4u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 64)));
    // 0x15dae8: 0xc057744  jal         func_15DD10
    ctx->pc = 0x15DAE8u;
    SET_GPR_U32(ctx, 31, 0x15DAF0u);
    ctx->pc = 0x15DAECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DAE8u;
            // 0x15daec: 0x8e570020  lw          $s7, 0x20($s2) (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 32)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15DD10u;
    if (runtime->hasFunction(0x15DD10u)) {
        auto targetFn = runtime->lookupFunction(0x15DD10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DAF0u; }
        if (ctx->pc != 0x15DAF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015DD10_0x15dd10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DAF0u; }
        if (ctx->pc != 0x15DAF0u) { return; }
    }
    ctx->pc = 0x15DAF0u;
label_15daf0:
    // 0x15daf0: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x15daf0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x15daf4: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x15daf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x15daf8: 0x8e440010  lw          $a0, 0x10($s2)
    ctx->pc = 0x15daf8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x15dafc: 0xafa20008  sw          $v0, 0x8($sp)
    ctx->pc = 0x15dafcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
    // 0x15db00: 0x8e450004  lw          $a1, 0x4($s2)
    ctx->pc = 0x15db00u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x15db04: 0xafa5000c  sw          $a1, 0xC($sp)
    ctx->pc = 0x15db04u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 5));
    // 0x15db08: 0x8e460008  lw          $a2, 0x8($s2)
    ctx->pc = 0x15db08u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x15db0c: 0xafa60010  sw          $a2, 0x10($sp)
    ctx->pc = 0x15db0cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 6));
    // 0x15db10: 0x8e47000c  lw          $a3, 0xC($s2)
    ctx->pc = 0x15db10u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x15db14: 0xc057754  jal         func_15DD50
    ctx->pc = 0x15DB14u;
    SET_GPR_U32(ctx, 31, 0x15DB1Cu);
    ctx->pc = 0x15DB18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DB14u;
            // 0x15db18: 0xafa70014  sw          $a3, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15DD50u;
    if (runtime->hasFunction(0x15DD50u)) {
        auto targetFn = runtime->lookupFunction(0x15DD50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DB1Cu; }
        if (ctx->pc != 0x15DB1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015DD50_0x15dd50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DB1Cu; }
        if (ctx->pc != 0x15DB1Cu) { return; }
    }
    ctx->pc = 0x15DB1Cu;
label_15db1c:
    // 0x15db1c: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x15db1cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x15db20: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x15db20u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15db24: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15db24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15db28: 0x8e420024  lw          $v0, 0x24($s2)
    ctx->pc = 0x15db28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 36)));
    // 0x15db2c: 0x8e530018  lw          $s3, 0x18($s2)
    ctx->pc = 0x15db2cu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
    // 0x15db30: 0x8e540034  lw          $s4, 0x34($s2)
    ctx->pc = 0x15db30u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 52)));
    // 0x15db34: 0x8e550030  lw          $s5, 0x30($s2)
    ctx->pc = 0x15db34u;
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 48)));
    // 0x15db38: 0x8e5e002c  lw          $fp, 0x2C($s2)
    ctx->pc = 0x15db38u;
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 44)));
    // 0x15db3c: 0xafa2001c  sw          $v0, 0x1C($sp)
    ctx->pc = 0x15db3cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x15db40: 0x8e460028  lw          $a2, 0x28($s2)
    ctx->pc = 0x15db40u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 40)));
    // 0x15db44: 0xc05db8a  jal         func_176E28
    ctx->pc = 0x15DB44u;
    SET_GPR_U32(ctx, 31, 0x15DB4Cu);
    ctx->pc = 0x15DB48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DB44u;
            // 0x15db48: 0xafa60020  sw          $a2, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176E28u;
    if (runtime->hasFunction(0x176E28u)) {
        auto targetFn = runtime->lookupFunction(0x176E28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DB4Cu; }
        if (ctx->pc != 0x15DB4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176E28_0x176e28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DB4Cu; }
        if (ctx->pc != 0x15DB4Cu) { return; }
    }
    ctx->pc = 0x15DB4Cu;
label_15db4c:
    // 0x15db4c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x15DB4Cu;
    {
        const bool branch_taken_0x15db4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15DB50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DB4Cu;
            // 0x15db50: 0x8fa50000  lw          $a1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15db4c) {
            ctx->pc = 0x15DB64u;
            goto label_15db64;
        }
    }
    ctx->pc = 0x15DB54u;
    // 0x15db54: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15db54u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15db58: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15DB58u;
    SET_GPR_U32(ctx, 31, 0x15DB60u);
    ctx->pc = 0x15DB5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DB58u;
            // 0x15db5c: 0x2484ec80  addiu       $a0, $a0, -0x1380 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962304));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DB60u; }
        if (ctx->pc != 0x15DB60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DB60u; }
        if (ctx->pc != 0x15DB60u) { return; }
    }
    ctx->pc = 0x15DB60u;
label_15db60:
    // 0x15db60: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x15db60u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_15db64:
    // 0x15db64: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x15db64u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15db68: 0xc057730  jal         func_15DCC0
    ctx->pc = 0x15DB68u;
    SET_GPR_U32(ctx, 31, 0x15DB70u);
    ctx->pc = 0x15DB6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DB68u;
            // 0x15db6c: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15DCC0u;
    if (runtime->hasFunction(0x15DCC0u)) {
        auto targetFn = runtime->lookupFunction(0x15DCC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DB70u; }
        if (ctx->pc != 0x15DB70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015DCC0_0x15dcc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DB70u; }
        if (ctx->pc != 0x15DB70u) { return; }
    }
    ctx->pc = 0x15DB70u;
label_15db70:
    // 0x15db70: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x15db70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15db74: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x15db74u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15db78: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x15db78u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15db7c: 0xc057730  jal         func_15DCC0
    ctx->pc = 0x15DB7Cu;
    SET_GPR_U32(ctx, 31, 0x15DB84u);
    ctx->pc = 0x15DB80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DB7Cu;
            // 0x15db80: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15DCC0u;
    if (runtime->hasFunction(0x15DCC0u)) {
        auto targetFn = runtime->lookupFunction(0x15DCC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DB84u; }
        if (ctx->pc != 0x15DB84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015DCC0_0x15dcc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DB84u; }
        if (ctx->pc != 0x15DB84u) { return; }
    }
    ctx->pc = 0x15DB84u;
label_15db84:
    // 0x15db84: 0xae370000  sw          $s7, 0x0($s1)
    ctx->pc = 0x15db84u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 23));
    // 0x15db88: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x15db88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15db8c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x15db8cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15db90: 0x8fa70004  lw          $a3, 0x4($sp)
    ctx->pc = 0x15db90u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x15db94: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x15db94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15db98: 0xae270004  sw          $a3, 0x4($s1)
    ctx->pc = 0x15db98u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 7));
    // 0x15db9c: 0x8fa60008  lw          $a2, 0x8($sp)
    ctx->pc = 0x15db9cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15dba0: 0xae260008  sw          $a2, 0x8($s1)
    ctx->pc = 0x15dba0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 6));
    // 0x15dba4: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x15dba4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15dba8: 0x8fa7000c  lw          $a3, 0xC($sp)
    ctx->pc = 0x15dba8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x15dbac: 0xae27000c  sw          $a3, 0xC($s1)
    ctx->pc = 0x15dbacu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 7));
    // 0x15dbb0: 0x8fa70010  lw          $a3, 0x10($sp)
    ctx->pc = 0x15dbb0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15dbb4: 0xae270010  sw          $a3, 0x10($s1)
    ctx->pc = 0x15dbb4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 7));
    // 0x15dbb8: 0x8fa70014  lw          $a3, 0x14($sp)
    ctx->pc = 0x15dbb8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x15dbbc: 0xae270014  sw          $a3, 0x14($s1)
    ctx->pc = 0x15dbbcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 7));
    // 0x15dbc0: 0x8fa70018  lw          $a3, 0x18($sp)
    ctx->pc = 0x15dbc0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15dbc4: 0xae23001c  sw          $v1, 0x1C($s1)
    ctx->pc = 0x15dbc4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 28), GPR_U32(ctx, 3));
    // 0x15dbc8: 0xae300020  sw          $s0, 0x20($s1)
    ctx->pc = 0x15dbc8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 32), GPR_U32(ctx, 16));
    // 0x15dbcc: 0xae340024  sw          $s4, 0x24($s1)
    ctx->pc = 0x15dbccu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 20));
    // 0x15dbd0: 0xae330028  sw          $s3, 0x28($s1)
    ctx->pc = 0x15dbd0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 40), GPR_U32(ctx, 19));
    // 0x15dbd4: 0xae3e002c  sw          $fp, 0x2C($s1)
    ctx->pc = 0x15dbd4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 44), GPR_U32(ctx, 30));
    // 0x15dbd8: 0xae350034  sw          $s5, 0x34($s1)
    ctx->pc = 0x15dbd8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 21));
    // 0x15dbdc: 0xae270018  sw          $a3, 0x18($s1)
    ctx->pc = 0x15dbdcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 7));
    // 0x15dbe0: 0xae220030  sw          $v0, 0x30($s1)
    ctx->pc = 0x15dbe0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 48), GPR_U32(ctx, 2));
    // 0x15dbe4: 0x8fa2001c  lw          $v0, 0x1C($sp)
    ctx->pc = 0x15dbe4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x15dbe8: 0xae220038  sw          $v0, 0x38($s1)
    ctx->pc = 0x15dbe8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 56), GPR_U32(ctx, 2));
    // 0x15dbec: 0x8fa70020  lw          $a3, 0x20($sp)
    ctx->pc = 0x15dbecu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15dbf0: 0xc05770a  jal         func_15DC28
    ctx->pc = 0x15DBF0u;
    SET_GPR_U32(ctx, 31, 0x15DBF8u);
    ctx->pc = 0x15DBF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DBF0u;
            // 0x15dbf4: 0xae27003c  sw          $a3, 0x3C($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 60), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15DC28u;
    if (runtime->hasFunction(0x15DC28u)) {
        auto targetFn = runtime->lookupFunction(0x15DC28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DBF8u; }
        if (ctx->pc != 0x15DBF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015DC28_0x15dc28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DBF8u; }
        if (ctx->pc != 0x15DBF8u) { return; }
    }
    ctx->pc = 0x15DBF8u;
label_15dbf8:
    // 0x15dbf8: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x15dbf8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x15dbfc: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x15dbfcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x15dc00: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x15dc00u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x15dc04: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x15dc04u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x15dc08: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x15dc08u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x15dc0c: 0xdfb50058  ld          $s5, 0x58($sp)
    ctx->pc = 0x15dc0cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x15dc10: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x15dc10u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x15dc14: 0xdfb70068  ld          $s7, 0x68($sp)
    ctx->pc = 0x15dc14u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x15dc18: 0xdfbe0070  ld          $fp, 0x70($sp)
    ctx->pc = 0x15dc18u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x15dc1c: 0xdfbf0078  ld          $ra, 0x78($sp)
    ctx->pc = 0x15dc1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x15dc20: 0x3e00008  jr          $ra
    ctx->pc = 0x15DC20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15DC24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DC20u;
            // 0x15dc24: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15DAF0u: goto label_15daf0;
            case 0x15DB1Cu: goto label_15db1c;
            case 0x15DB4Cu: goto label_15db4c;
            case 0x15DB60u: goto label_15db60;
            case 0x15DB64u: goto label_15db64;
            case 0x15DB70u: goto label_15db70;
            case 0x15DB84u: goto label_15db84;
            case 0x15DBF8u: goto label_15dbf8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15DC28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
