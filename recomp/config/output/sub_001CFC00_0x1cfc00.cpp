#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CFC00
// Address: 0x1cfc00 - 0x1d0030
void sub_001CFC00_0x1cfc00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CFC00_0x1cfc00");
#endif

    switch (ctx->pc) {
        case 0x1cfc2cu: goto label_1cfc2c;
        case 0x1cfc3cu: goto label_1cfc3c;
        case 0x1cfc4cu: goto label_1cfc4c;
        case 0x1cfc5cu: goto label_1cfc5c;
        case 0x1cfc98u: goto label_1cfc98;
        case 0x1cfcbcu: goto label_1cfcbc;
        case 0x1cfce0u: goto label_1cfce0;
        case 0x1cfd18u: goto label_1cfd18;
        case 0x1cfd84u: goto label_1cfd84;
        case 0x1cfda4u: goto label_1cfda4;
        case 0x1cfdbcu: goto label_1cfdbc;
        case 0x1cfe20u: goto label_1cfe20;
        case 0x1cfe40u: goto label_1cfe40;
        case 0x1cfe60u: goto label_1cfe60;
        case 0x1cfe78u: goto label_1cfe78;
        case 0x1cfe98u: goto label_1cfe98;
        case 0x1cfec8u: goto label_1cfec8;
        case 0x1cfee4u: goto label_1cfee4;
        case 0x1cfeecu: goto label_1cfeec;
        case 0x1cfef0u: goto label_1cfef0;
        case 0x1cff34u: goto label_1cff34;
        case 0x1cff68u: goto label_1cff68;
        case 0x1cff8cu: goto label_1cff8c;
        case 0x1cffc8u: goto label_1cffc8;
        case 0x1cffe8u: goto label_1cffe8;
        case 0x1d0010u: goto label_1d0010;
        default: break;
    }

    ctx->pc = 0x1cfc00u;

    // 0x1cfc00: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x1cfc00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x1cfc04: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1cfc04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1cfc08: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1cfc08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1cfc0c: 0x27a40090  addiu       $a0, $sp, 0x90
    ctx->pc = 0x1cfc0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0x1cfc10: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1cfc10u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1cfc14: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x1cfc14u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1cfc18: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1cfc18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1cfc1c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1cfc1cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1cfc20: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cfc20u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cfc24: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CFC24u;
    SET_GPR_U32(ctx, 31, 0x1CFC2Cu);
    ctx->pc = 0x1CFC28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFC24u;
            // 0x1cfc28: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFC2Cu; }
        if (ctx->pc != 0x1CFC2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFC2Cu; }
        if (ctx->pc != 0x1CFC2Cu) { return; }
    }
    ctx->pc = 0x1CFC2Cu;
label_1cfc2c:
    // 0x1cfc2c: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1cfc2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1cfc30: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1cfc30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1cfc34: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CFC34u;
    SET_GPR_U32(ctx, 31, 0x1CFC3Cu);
    ctx->pc = 0x1CFC38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFC34u;
            // 0x1cfc38: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFC3Cu; }
        if (ctx->pc != 0x1CFC3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFC3Cu; }
        if (ctx->pc != 0x1CFC3Cu) { return; }
    }
    ctx->pc = 0x1CFC3Cu;
label_1cfc3c:
    // 0x1cfc3c: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1cfc3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1cfc40: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1cfc40u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1cfc44: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CFC44u;
    SET_GPR_U32(ctx, 31, 0x1CFC4Cu);
    ctx->pc = 0x1CFC48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFC44u;
            // 0x1cfc48: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFC4Cu; }
        if (ctx->pc != 0x1CFC4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFC4Cu; }
        if (ctx->pc != 0x1CFC4Cu) { return; }
    }
    ctx->pc = 0x1CFC4Cu;
label_1cfc4c:
    // 0x1cfc4c: 0x27a40090  addiu       $a0, $sp, 0x90
    ctx->pc = 0x1cfc4cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0x1cfc50: 0x27a50070  addiu       $a1, $sp, 0x70
    ctx->pc = 0x1cfc50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1cfc54: 0xc073ec8  jal         func_1CFB20
    ctx->pc = 0x1CFC54u;
    SET_GPR_U32(ctx, 31, 0x1CFC5Cu);
    ctx->pc = 0x1CFC58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFC54u;
            // 0x1cfc58: 0x27a60060  addiu       $a2, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CFB20u;
    if (runtime->hasFunction(0x1CFB20u)) {
        auto targetFn = runtime->lookupFunction(0x1CFB20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFC5Cu; }
        if (ctx->pc != 0x1CFC5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CFB20_0x1cfb20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFC5Cu; }
        if (ctx->pc != 0x1CFC5Cu) { return; }
    }
    ctx->pc = 0x1CFC5Cu;
label_1cfc5c:
    // 0x1cfc5c: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1cfc5cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1cfc60: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cfc60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cfc64: 0x8023adf8  lb          $v1, -0x5208($at)
    ctx->pc = 0x1cfc64u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946296)));
    // 0x1cfc68: 0x1062006c  beq         $v1, $v0, . + 4 + (0x6C << 2)
    ctx->pc = 0x1CFC68u;
    {
        const bool branch_taken_0x1cfc68 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CFC6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFC68u;
            // 0x1cfc6c: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfc68) {
            ctx->pc = 0x1CFE1Cu;
            goto label_1cfe1c;
        }
    }
    ctx->pc = 0x1CFC70u;
    // 0x1cfc70: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1cfc70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cfc74: 0x3c0a0038  lui         $t2, 0x38
    ctx->pc = 0x1cfc74u;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)56 << 16));
    // 0x1cfc78: 0x3c09004c  lui         $t1, 0x4C
    ctx->pc = 0x1cfc78u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)76 << 16));
    // 0x1cfc7c: 0x3c02004c  lui         $v0, 0x4C
    ctx->pc = 0x1cfc7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)76 << 16));
    // 0x1cfc80: 0x340bffff  ori         $t3, $zero, 0xFFFF
    ctx->pc = 0x1cfc80u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1cfc84: 0x2408ffff  addiu       $t0, $zero, -0x1
    ctx->pc = 0x1cfc84u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cfc88: 0x254a7e90  addiu       $t2, $t2, 0x7E90
    ctx->pc = 0x1cfc88u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 32400));
    // 0x1cfc8c: 0x25299680  addiu       $t1, $t1, -0x6980
    ctx->pc = 0x1cfc8cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294940288));
    // 0x1cfc90: 0x24429a80  addiu       $v0, $v0, -0x6580
    ctx->pc = 0x1cfc90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941312));
    // 0x1cfc94: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1cfc94u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
label_1cfc98:
    // 0x1cfc98: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x1cfc98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1cfc9c: 0x94630da0  lhu         $v1, 0xDA0($v1)
    ctx->pc = 0x1cfc9cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 3488)));
    // 0x1cfca0: 0x106b002c  beq         $v1, $t3, . + 4 + (0x2C << 2)
    ctx->pc = 0x1CFCA0u;
    {
        const bool branch_taken_0x1cfca0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 11));
        ctx->pc = 0x1CFCA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFCA0u;
            // 0x1cfca4: 0x328c0  sll         $a1, $v1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfca0) {
            ctx->pc = 0x1CFD54u;
            goto label_1cfd54;
        }
    }
    ctx->pc = 0x1CFCA8u;
    // 0x1cfca8: 0x1452821  addu        $a1, $t2, $a1
    ctx->pc = 0x1cfca8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 5)));
    // 0x1cfcac: 0x419c0  sll         $v1, $a0, 7
    ctx->pc = 0x1cfcacu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
    // 0x1cfcb0: 0x8ca60000  lw          $a2, 0x0($a1)
    ctx->pc = 0x1cfcb0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1cfcb4: 0x1231821  addu        $v1, $t1, $v1
    ctx->pc = 0x1cfcb4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 3)));
    // 0x1cfcb8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cfcb8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cfcbc:
    // 0x1cfcbc: 0x8c670000  lw          $a3, 0x0($v1)
    ctx->pc = 0x1cfcbcu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1cfcc0: 0x10e80020  beq         $a3, $t0, . + 4 + (0x20 << 2)
    ctx->pc = 0x1CFCC0u;
    {
        const bool branch_taken_0x1cfcc0 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 8));
        ctx->pc = 0x1CFCC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFCC0u;
            // 0x1cfcc4: 0x24630004  addiu       $v1, $v1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfcc0) {
            ctx->pc = 0x1CFD44u;
            goto label_1cfd44;
        }
    }
    ctx->pc = 0x1CFCC8u;
    // 0x1cfcc8: 0x73900  sll         $a3, $a3, 4
    ctx->pc = 0x1cfcc8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 4));
    // 0x1cfccc: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x1cfcccu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x1cfcd0: 0x90ee0001  lbu         $t6, 0x1($a3)
    ctx->pc = 0x1cfcd0u;
    SET_GPR_U32(ctx, 14, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 1)));
    // 0x1cfcd4: 0x90ed0000  lbu         $t5, 0x0($a3)
    ctx->pc = 0x1cfcd4u;
    SET_GPR_U32(ctx, 13, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1cfcd8: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1CFCD8u;
    {
        const bool branch_taken_0x1cfcd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CFCDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFCD8u;
            // 0x1cfcdc: 0x782d  daddu       $t7, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfcd8) {
            ctx->pc = 0x1CFD00u;
            goto label_1cfd00;
        }
    }
    ctx->pc = 0x1CFCE0u;
label_1cfce0:
    // 0x1cfce0: 0xfd3821  addu        $a3, $a3, $sp
    ctx->pc = 0x1cfce0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 29)));
    // 0x1cfce4: 0x24ec0090  addiu       $t4, $a3, 0x90
    ctx->pc = 0x1cfce4u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), 144));
    // 0x1cfce8: 0x95870000  lhu         $a3, 0x0($t4)
    ctx->pc = 0x1cfce8u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x1cfcec: 0x15a70003  bne         $t5, $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CFCECu;
    {
        const bool branch_taken_0x1cfcec = (GPR_U64(ctx, 13) != GPR_U64(ctx, 7));
        if (branch_taken_0x1cfcec) {
            ctx->pc = 0x1CFCFCu;
            goto label_1cfcfc;
        }
    }
    ctx->pc = 0x1CFCF4u;
    // 0x1cfcf4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1CFCF4u;
    {
        const bool branch_taken_0x1cfcf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CFCF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFCF4u;
            // 0x1cfcf8: 0xa58b0000  sh          $t3, 0x0($t4) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 12), 0), (uint16_t)GPR_U32(ctx, 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfcf4) {
            ctx->pc = 0x1CFD0Cu;
            goto label_1cfd0c;
        }
    }
    ctx->pc = 0x1CFCFCu;
label_1cfcfc:
    // 0x1cfcfc: 0x25ef0001  addiu       $t7, $t7, 0x1
    ctx->pc = 0x1cfcfcu;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 15), 1));
label_1cfd00:
    // 0x1cfd00: 0x29e70010  slti        $a3, $t7, 0x10
    ctx->pc = 0x1cfd00u;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 15) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1cfd04: 0x14e0fff6  bnez        $a3, . + 4 + (-0xA << 2)
    ctx->pc = 0x1CFD04u;
    {
        const bool branch_taken_0x1cfd04 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CFD08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFD04u;
            // 0x1cfd08: 0xf3840  sll         $a3, $t7, 1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 15), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfd04) {
            ctx->pc = 0x1CFCE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cfce0;
        }
    }
    ctx->pc = 0x1CFD0Cu;
label_1cfd0c:
    // 0x1cfd0c: 0x31ceffff  andi        $t6, $t6, 0xFFFF
    ctx->pc = 0x1cfd0cu;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 14) & (uint64_t)(uint16_t)65535);
    // 0x1cfd10: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1CFD10u;
    {
        const bool branch_taken_0x1cfd10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CFD14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFD10u;
            // 0x1cfd14: 0x602d  daddu       $t4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfd10) {
            ctx->pc = 0x1CFD38u;
            goto label_1cfd38;
        }
    }
    ctx->pc = 0x1CFD18u;
label_1cfd18:
    // 0x1cfd18: 0xfd3821  addu        $a3, $a3, $sp
    ctx->pc = 0x1cfd18u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 29)));
    // 0x1cfd1c: 0x24ed0070  addiu       $t5, $a3, 0x70
    ctx->pc = 0x1cfd1cu;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 7), 112));
    // 0x1cfd20: 0x95a70000  lhu         $a3, 0x0($t5)
    ctx->pc = 0x1cfd20u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 13), 0)));
    // 0x1cfd24: 0x15c70003  bne         $t6, $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CFD24u;
    {
        const bool branch_taken_0x1cfd24 = (GPR_U64(ctx, 14) != GPR_U64(ctx, 7));
        if (branch_taken_0x1cfd24) {
            ctx->pc = 0x1CFD34u;
            goto label_1cfd34;
        }
    }
    ctx->pc = 0x1CFD2Cu;
    // 0x1cfd2c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1CFD2Cu;
    {
        const bool branch_taken_0x1cfd2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CFD30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFD2Cu;
            // 0x1cfd30: 0xa5ab0000  sh          $t3, 0x0($t5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 13), 0), (uint16_t)GPR_U32(ctx, 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfd2c) {
            ctx->pc = 0x1CFD44u;
            goto label_1cfd44;
        }
    }
    ctx->pc = 0x1CFD34u;
label_1cfd34:
    // 0x1cfd34: 0x258c0001  addiu       $t4, $t4, 0x1
    ctx->pc = 0x1cfd34u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 1));
label_1cfd38:
    // 0x1cfd38: 0x29870010  slti        $a3, $t4, 0x10
    ctx->pc = 0x1cfd38u;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 12) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1cfd3c: 0x14e0fff6  bnez        $a3, . + 4 + (-0xA << 2)
    ctx->pc = 0x1CFD3Cu;
    {
        const bool branch_taken_0x1cfd3c = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CFD40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFD3Cu;
            // 0x1cfd40: 0xc3840  sll         $a3, $t4, 1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfd3c) {
            ctx->pc = 0x1CFD18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cfd18;
        }
    }
    ctx->pc = 0x1CFD44u;
label_1cfd44:
    // 0x1cfd44: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1cfd44u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1cfd48: 0x28a70020  slti        $a3, $a1, 0x20
    ctx->pc = 0x1cfd48u;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1cfd4c: 0x14e0ffdb  bnez        $a3, . + 4 + (-0x25 << 2)
    ctx->pc = 0x1CFD4Cu;
    {
        const bool branch_taken_0x1cfd4c = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cfd4c) {
            ctx->pc = 0x1CFCBCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cfcbc;
        }
    }
    ctx->pc = 0x1CFD54u;
label_1cfd54:
    // 0x1cfd54: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1cfd54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1cfd58: 0x28830002  slti        $v1, $a0, 0x2
    ctx->pc = 0x1cfd58u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1cfd5c: 0x1460ffce  bnez        $v1, . + 4 + (-0x32 << 2)
    ctx->pc = 0x1CFD5Cu;
    {
        const bool branch_taken_0x1cfd5c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CFD60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFD5Cu;
            // 0x1cfd60: 0x41840  sll         $v1, $a0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfd5c) {
            ctx->pc = 0x1CFC98u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cfc98;
        }
    }
    ctx->pc = 0x1CFD64u;
    // 0x1cfd64: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1cfd64u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cfd68: 0x3c04004c  lui         $a0, 0x4C
    ctx->pc = 0x1cfd68u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)76 << 16));
    // 0x1cfd6c: 0x3c06004c  lui         $a2, 0x4C
    ctx->pc = 0x1cfd6cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)76 << 16));
    // 0x1cfd70: 0x3405ffff  ori         $a1, $zero, 0xFFFF
    ctx->pc = 0x1cfd70u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1cfd74: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1cfd74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cfd78: 0x24849680  addiu       $a0, $a0, -0x6980
    ctx->pc = 0x1cfd78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294940288));
    // 0x1cfd7c: 0x24c69a80  addiu       $a2, $a2, -0x6580
    ctx->pc = 0x1cfd7cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294941312));
    // 0x1cfd80: 0xa1040  sll         $v0, $t2, 1
    ctx->pc = 0x1cfd80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
label_1cfd84:
    // 0x1cfd84: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x1cfd84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1cfd88: 0x94420da0  lhu         $v0, 0xDA0($v0)
    ctx->pc = 0x1cfd88u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 3488)));
    // 0x1cfd8c: 0x1045001e  beq         $v0, $a1, . + 4 + (0x1E << 2)
    ctx->pc = 0x1CFD8Cu;
    {
        const bool branch_taken_0x1cfd8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        ctx->pc = 0x1CFD90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFD8Cu;
            // 0x1cfd90: 0x304effff  andi        $t6, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 14, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfd8c) {
            ctx->pc = 0x1CFE08u;
            goto label_1cfe08;
        }
    }
    ctx->pc = 0x1CFD94u;
    // 0x1cfd94: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1cfd94u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cfd98: 0xa11c0  sll         $v0, $t2, 7
    ctx->pc = 0x1cfd98u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 10), 7));
    // 0x1cfd9c: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x1cfd9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1cfda0: 0x24490100  addiu       $t1, $v0, 0x100
    ctx->pc = 0x1cfda0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), 256));
label_1cfda4:
    // 0x1cfda4: 0x8d220000  lw          $v0, 0x0($t1)
    ctx->pc = 0x1cfda4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1cfda8: 0x10430013  beq         $v0, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1CFDA8u;
    {
        const bool branch_taken_0x1cfda8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1CFDACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFDA8u;
            // 0x1cfdac: 0x25290004  addiu       $t1, $t1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfda8) {
            ctx->pc = 0x1CFDF8u;
            goto label_1cfdf8;
        }
    }
    ctx->pc = 0x1CFDB0u;
    // 0x1cfdb0: 0x304dffff  andi        $t5, $v0, 0xFFFF
    ctx->pc = 0x1cfdb0u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1cfdb4: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1CFDB4u;
    {
        const bool branch_taken_0x1cfdb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CFDB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFDB4u;
            // 0x1cfdb8: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfdb4) {
            ctx->pc = 0x1CFDECu;
            goto label_1cfdec;
        }
    }
    ctx->pc = 0x1CFDBCu;
label_1cfdbc:
    // 0x1cfdbc: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x1cfdbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1cfdc0: 0x244b0060  addiu       $t3, $v0, 0x60
    ctx->pc = 0x1cfdc0u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 2), 96));
    // 0x1cfdc4: 0x95620000  lhu         $v0, 0x0($t3)
    ctx->pc = 0x1cfdc4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x1cfdc8: 0x15c20007  bne         $t6, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CFDC8u;
    {
        const bool branch_taken_0x1cfdc8 = (GPR_U64(ctx, 14) != GPR_U64(ctx, 2));
        if (branch_taken_0x1cfdc8) {
            ctx->pc = 0x1CFDE8u;
            goto label_1cfde8;
        }
    }
    ctx->pc = 0x1CFDD0u;
    // 0x1cfdd0: 0x95620002  lhu         $v0, 0x2($t3)
    ctx->pc = 0x1cfdd0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 11), 2)));
    // 0x1cfdd4: 0x15a20004  bne         $t5, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CFDD4u;
    {
        const bool branch_taken_0x1cfdd4 = (GPR_U64(ctx, 13) != GPR_U64(ctx, 2));
        ctx->pc = 0x1CFDD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFDD4u;
            // 0x1cfdd8: 0x256c0002  addiu       $t4, $t3, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 11), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfdd4) {
            ctx->pc = 0x1CFDE8u;
            goto label_1cfde8;
        }
    }
    ctx->pc = 0x1CFDDCu;
    // 0x1cfddc: 0xa5650000  sh          $a1, 0x0($t3)
    ctx->pc = 0x1cfddcu;
    WRITE16(ADD32(GPR_U32(ctx, 11), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x1cfde0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1CFDE0u;
    {
        const bool branch_taken_0x1cfde0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CFDE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFDE0u;
            // 0x1cfde4: 0xa5850000  sh          $a1, 0x0($t4) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 12), 0), (uint16_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfde0) {
            ctx->pc = 0x1CFDF8u;
            goto label_1cfdf8;
        }
    }
    ctx->pc = 0x1CFDE8u;
label_1cfde8:
    // 0x1cfde8: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1cfde8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
label_1cfdec:
    // 0x1cfdec: 0x28e20004  slti        $v0, $a3, 0x4
    ctx->pc = 0x1cfdecu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1cfdf0: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x1CFDF0u;
    {
        const bool branch_taken_0x1cfdf0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CFDF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFDF0u;
            // 0x1cfdf4: 0x71080  sll         $v0, $a3, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfdf0) {
            ctx->pc = 0x1CFDBCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cfdbc;
        }
    }
    ctx->pc = 0x1CFDF8u;
label_1cfdf8:
    // 0x1cfdf8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1cfdf8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1cfdfc: 0x29020020  slti        $v0, $t0, 0x20
    ctx->pc = 0x1cfdfcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1cfe00: 0x1440ffe8  bnez        $v0, . + 4 + (-0x18 << 2)
    ctx->pc = 0x1CFE00u;
    {
        const bool branch_taken_0x1cfe00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cfe00) {
            ctx->pc = 0x1CFDA4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cfda4;
        }
    }
    ctx->pc = 0x1CFE08u;
label_1cfe08:
    // 0x1cfe08: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x1cfe08u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x1cfe0c: 0x29420002  slti        $v0, $t2, 0x2
    ctx->pc = 0x1cfe0cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1cfe10: 0x1440ffdc  bnez        $v0, . + 4 + (-0x24 << 2)
    ctx->pc = 0x1CFE10u;
    {
        const bool branch_taken_0x1cfe10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CFE14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFE10u;
            // 0x1cfe14: 0xa1040  sll         $v0, $t2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfe10) {
            ctx->pc = 0x1CFD84u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cfd84;
        }
    }
    ctx->pc = 0x1CFE18u;
    // 0x1cfe18: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1cfe18u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cfe1c:
    // 0x1cfe1c: 0x108840  sll         $s1, $s0, 1
    ctx->pc = 0x1cfe1cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
label_1cfe20:
    // 0x1cfe20: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1cfe20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1cfe24: 0x23d1821  addu        $v1, $s1, $sp
    ctx->pc = 0x1cfe24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 29)));
    // 0x1cfe28: 0x94660090  lhu         $a2, 0x90($v1)
    ctx->pc = 0x1cfe28u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 144)));
    // 0x1cfe2c: 0x10c20005  beq         $a2, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CFE2Cu;
    {
        const bool branch_taken_0x1cfe2c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CFE30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFE2Cu;
            // 0x1cfe30: 0x23d1821  addu        $v1, $s1, $sp (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 29)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfe2c) {
            ctx->pc = 0x1CFE44u;
            goto label_1cfe44;
        }
    }
    ctx->pc = 0x1CFE34u;
    // 0x1cfe34: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1cfe34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1cfe38: 0xc073b48  jal         func_1CED20
    ctx->pc = 0x1CFE38u;
    SET_GPR_U32(ctx, 31, 0x1CFE40u);
    ctx->pc = 0x1CFE3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFE38u;
            // 0x1cfe3c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CED20u;
    if (runtime->hasFunction(0x1CED20u)) {
        auto targetFn = runtime->lookupFunction(0x1CED20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFE40u; }
        if (ctx->pc != 0x1CFE40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CED20_0x1ced20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFE40u; }
        if (ctx->pc != 0x1CFE40u) { return; }
    }
    ctx->pc = 0x1CFE40u;
label_1cfe40:
    // 0x1cfe40: 0x23d1821  addu        $v1, $s1, $sp
    ctx->pc = 0x1cfe40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 29)));
label_1cfe44:
    // 0x1cfe44: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1cfe44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1cfe48: 0x94630070  lhu         $v1, 0x70($v1)
    ctx->pc = 0x1cfe48u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 112)));
    // 0x1cfe4c: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CFE4Cu;
    {
        const bool branch_taken_0x1cfe4c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CFE50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFE4Cu;
            // 0x1cfe50: 0x3066ffff  andi        $a2, $v1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfe4c) {
            ctx->pc = 0x1CFE60u;
            goto label_1cfe60;
        }
    }
    ctx->pc = 0x1CFE54u;
    // 0x1cfe54: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1cfe54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1cfe58: 0xc073a2c  jal         func_1CE8B0
    ctx->pc = 0x1CFE58u;
    SET_GPR_U32(ctx, 31, 0x1CFE60u);
    ctx->pc = 0x1CFE5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFE58u;
            // 0x1cfe5c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE8B0u;
    if (runtime->hasFunction(0x1CE8B0u)) {
        auto targetFn = runtime->lookupFunction(0x1CE8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFE60u; }
        if (ctx->pc != 0x1CFE60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE8B0_0x1ce8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFE60u; }
        if (ctx->pc != 0x1CFE60u) { return; }
    }
    ctx->pc = 0x1CFE60u;
label_1cfe60:
    // 0x1cfe60: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1cfe60u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1cfe64: 0x2a020010  slti        $v0, $s0, 0x10
    ctx->pc = 0x1cfe64u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1cfe68: 0x1440ffed  bnez        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1CFE68u;
    {
        const bool branch_taken_0x1cfe68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CFE6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFE68u;
            // 0x1cfe6c: 0x108840  sll         $s1, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfe68) {
            ctx->pc = 0x1CFE20u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cfe20;
        }
    }
    ctx->pc = 0x1CFE70u;
    // 0x1cfe70: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1cfe70u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cfe74: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1cfe74u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
label_1cfe78:
    // 0x1cfe78: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1cfe78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1cfe7c: 0x7d1821  addu        $v1, $v1, $sp
    ctx->pc = 0x1cfe7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 29)));
    // 0x1cfe80: 0x24710060  addiu       $s1, $v1, 0x60
    ctx->pc = 0x1cfe80u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 96));
    // 0x1cfe84: 0x96240000  lhu         $a0, 0x0($s1)
    ctx->pc = 0x1cfe84u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cfe88: 0x10820009  beq         $a0, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1CFE88u;
    {
        const bool branch_taken_0x1cfe88 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cfe88) {
            ctx->pc = 0x1CFEB0u;
            goto label_1cfeb0;
        }
    }
    ctx->pc = 0x1CFE90u;
    // 0x1cfe90: 0xc073dd0  jal         func_1CF740
    ctx->pc = 0x1CFE90u;
    SET_GPR_U32(ctx, 31, 0x1CFE98u);
    ctx->pc = 0x1CFE94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFE90u;
            // 0x1cfe94: 0x96250002  lhu         $a1, 0x2($s1) (Delay Slot)
        SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF740u;
    if (runtime->hasFunction(0x1CF740u)) {
        auto targetFn = runtime->lookupFunction(0x1CF740u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFE98u; }
        if (ctx->pc != 0x1CFE98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF740_0x1cf740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFE98u; }
        if (ctx->pc != 0x1CFE98u) { return; }
    }
    ctx->pc = 0x1CFE98u;
label_1cfe98:
    // 0x1cfe98: 0x96230000  lhu         $v1, 0x0($s1)
    ctx->pc = 0x1cfe98u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cfe9c: 0x3c02004c  lui         $v0, 0x4C
    ctx->pc = 0x1cfe9cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)76 << 16));
    // 0x1cfea0: 0x2442aeb0  addiu       $v0, $v0, -0x5150
    ctx->pc = 0x1cfea0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294946480));
    // 0x1cfea4: 0x240400ff  addiu       $a0, $zero, 0xFF
    ctx->pc = 0x1cfea4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1cfea8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1cfea8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1cfeac: 0xa0440000  sb          $a0, 0x0($v0)
    ctx->pc = 0x1cfeacu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 4));
label_1cfeb0:
    // 0x1cfeb0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1cfeb0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1cfeb4: 0x2a020004  slti        $v0, $s0, 0x4
    ctx->pc = 0x1cfeb4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1cfeb8: 0x1440ffef  bnez        $v0, . + 4 + (-0x11 << 2)
    ctx->pc = 0x1CFEB8u;
    {
        const bool branch_taken_0x1cfeb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CFEBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFEB8u;
            // 0x1cfebc: 0x101880  sll         $v1, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfeb8) {
            ctx->pc = 0x1CFE78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cfe78;
        }
    }
    ctx->pc = 0x1CFEC0u;
    // 0x1cfec0: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x1CFEC0u;
    SET_GPR_U32(ctx, 31, 0x1CFEC8u);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFEC8u; }
        if (ctx->pc != 0x1CFEC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFEC8u; }
        if (ctx->pc != 0x1CFEC8u) { return; }
    }
    ctx->pc = 0x1CFEC8u;
label_1cfec8:
    // 0x1cfec8: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1cfec8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1cfecc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1cfeccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cfed0: 0x8024adf8  lb          $a0, -0x5208($at)
    ctx->pc = 0x1cfed0u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946296)));
    // 0x1cfed4: 0x1083004e  beq         $a0, $v1, . + 4 + (0x4E << 2)
    ctx->pc = 0x1CFED4u;
    {
        const bool branch_taken_0x1cfed4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1CFED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFED4u;
            // 0x1cfed8: 0x24041200  addiu       $a0, $zero, 0x1200 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4608));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfed4) {
            ctx->pc = 0x1D0010u;
            goto label_1d0010;
        }
    }
    ctx->pc = 0x1CFEDCu;
    // 0x1cfedc: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1CFEDCu;
    SET_GPR_U32(ctx, 31, 0x1CFEE4u);
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFEE4u; }
        if (ctx->pc != 0x1CFEE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFEE4u; }
        if (ctx->pc != 0x1CFEE4u) { return; }
    }
    ctx->pc = 0x1CFEE4u;
label_1cfee4:
    // 0x1cfee4: 0xc0740e8  jal         func_1D03A0
    ctx->pc = 0x1CFEE4u;
    SET_GPR_U32(ctx, 31, 0x1CFEECu);
    ctx->pc = 0x1D03A0u;
    if (runtime->hasFunction(0x1D03A0u)) {
        auto targetFn = runtime->lookupFunction(0x1D03A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFEECu; }
        if (ctx->pc != 0x1CFEECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D03A0_0x1d03a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFEECu; }
        if (ctx->pc != 0x1CFEECu) { return; }
    }
    ctx->pc = 0x1CFEECu;
label_1cfeec:
    // 0x1cfeec: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x1cfeecu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cfef0:
    // 0x1cfef0: 0x3c02004c  lui         $v0, 0x4C
    ctx->pc = 0x1cfef0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)76 << 16));
    // 0x1cfef4: 0x131840  sll         $v1, $s3, 1
    ctx->pc = 0x1cfef4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 1));
    // 0x1cfef8: 0x24429a80  addiu       $v0, $v0, -0x6580
    ctx->pc = 0x1cfef8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941312));
    // 0x1cfefc: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x1cfefcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1cff00: 0x94630da0  lhu         $v1, 0xDA0($v1)
    ctx->pc = 0x1cff00u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 3488)));
    // 0x1cff04: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1cff04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1cff08: 0x1062001b  beq         $v1, $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1CFF08u;
    {
        const bool branch_taken_0x1cff08 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CFF0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFF08u;
            // 0x1cff0c: 0x3c020038  lui         $v0, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)56 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cff08) {
            ctx->pc = 0x1CFF78u;
            goto label_1cff78;
        }
    }
    ctx->pc = 0x1CFF10u;
    // 0x1cff10: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1cff10u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1cff14: 0x24427e90  addiu       $v0, $v0, 0x7E90
    ctx->pc = 0x1cff14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 32400));
    // 0x1cff18: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1cff18u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cff1c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1cff1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1cff20: 0x8c520000  lw          $s2, 0x0($v0)
    ctx->pc = 0x1cff20u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cff24: 0x1319c0  sll         $v1, $s3, 7
    ctx->pc = 0x1cff24u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 7));
    // 0x1cff28: 0x3c02004c  lui         $v0, 0x4C
    ctx->pc = 0x1cff28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)76 << 16));
    // 0x1cff2c: 0x24429680  addiu       $v0, $v0, -0x6980
    ctx->pc = 0x1cff2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294940288));
    // 0x1cff30: 0x438821  addu        $s1, $v0, $v1
    ctx->pc = 0x1cff30u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_1cff34:
    // 0x1cff34: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1cff34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cff38: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1cff38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cff3c: 0x1062000a  beq         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1CFF3Cu;
    {
        const bool branch_taken_0x1cff3c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CFF40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFF3Cu;
            // 0x1cff40: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cff3c) {
            ctx->pc = 0x1CFF68u;
            goto label_1cff68;
        }
    }
    ctx->pc = 0x1CFF44u;
    // 0x1cff44: 0x31100  sll         $v0, $v1, 4
    ctx->pc = 0x1cff44u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1cff48: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1cff48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cff4c: 0x2421821  addu        $v1, $s2, $v0
    ctx->pc = 0x1cff4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x1cff50: 0x90650000  lbu         $a1, 0x0($v1)
    ctx->pc = 0x1cff50u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1cff54: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1cff54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1cff58: 0x90660001  lbu         $a2, 0x1($v1)
    ctx->pc = 0x1cff58u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1)));
    // 0x1cff5c: 0x90680004  lbu         $t0, 0x4($v1)
    ctx->pc = 0x1cff5cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1cff60: 0xc073c24  jal         func_1CF090
    ctx->pc = 0x1CFF60u;
    SET_GPR_U32(ctx, 31, 0x1CFF68u);
    ctx->pc = 0x1CFF64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFF60u;
            // 0x1cff64: 0x34470002  ori         $a3, $v0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF090u;
    if (runtime->hasFunction(0x1CF090u)) {
        auto targetFn = runtime->lookupFunction(0x1CF090u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFF68u; }
        if (ctx->pc != 0x1CFF68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF090_0x1cf090(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFF68u; }
        if (ctx->pc != 0x1CFF68u) { return; }
    }
    ctx->pc = 0x1CFF68u;
label_1cff68:
    // 0x1cff68: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1cff68u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1cff6c: 0x2a020020  slti        $v0, $s0, 0x20
    ctx->pc = 0x1cff6cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1cff70: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1CFF70u;
    {
        const bool branch_taken_0x1cff70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cff70) {
            ctx->pc = 0x1CFF34u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cff34;
        }
    }
    ctx->pc = 0x1CFF78u;
label_1cff78:
    // 0x1cff78: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1cff78u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1cff7c: 0x2a620002  slti        $v0, $s3, 0x2
    ctx->pc = 0x1cff7cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1cff80: 0x1440ffdb  bnez        $v0, . + 4 + (-0x25 << 2)
    ctx->pc = 0x1CFF80u;
    {
        const bool branch_taken_0x1cff80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cff80) {
            ctx->pc = 0x1CFEF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cfef0;
        }
    }
    ctx->pc = 0x1CFF88u;
    // 0x1cff88: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x1cff88u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cff8c:
    // 0x1cff8c: 0x3c02004c  lui         $v0, 0x4C
    ctx->pc = 0x1cff8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)76 << 16));
    // 0x1cff90: 0x131840  sll         $v1, $s3, 1
    ctx->pc = 0x1cff90u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 1));
    // 0x1cff94: 0x24429a80  addiu       $v0, $v0, -0x6580
    ctx->pc = 0x1cff94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941312));
    // 0x1cff98: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x1cff98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1cff9c: 0x94740da0  lhu         $s4, 0xDA0($v1)
    ctx->pc = 0x1cff9cu;
    SET_GPR_U32(ctx, 20, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 3488)));
    // 0x1cffa0: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1cffa0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1cffa4: 0x12820014  beq         $s4, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1CFFA4u;
    {
        const bool branch_taken_0x1cffa4 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cffa4) {
            ctx->pc = 0x1CFFF8u;
            goto label_1cfff8;
        }
    }
    ctx->pc = 0x1CFFACu;
    // 0x1cffac: 0x94700da4  lhu         $s0, 0xDA4($v1)
    ctx->pc = 0x1cffacu;
    SET_GPR_U32(ctx, 16, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 3492)));
    // 0x1cffb0: 0x3c02004c  lui         $v0, 0x4C
    ctx->pc = 0x1cffb0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)76 << 16));
    // 0x1cffb4: 0x24429680  addiu       $v0, $v0, -0x6980
    ctx->pc = 0x1cffb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294940288));
    // 0x1cffb8: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1cffb8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cffbc: 0x1319c0  sll         $v1, $s3, 7
    ctx->pc = 0x1cffbcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 7));
    // 0x1cffc0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1cffc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1cffc4: 0x24520100  addiu       $s2, $v0, 0x100
    ctx->pc = 0x1cffc4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), 256));
label_1cffc8:
    // 0x1cffc8: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x1cffc8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1cffcc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1cffccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cffd0: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CFFD0u;
    {
        const bool branch_taken_0x1cffd0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CFFD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFFD0u;
            // 0x1cffd4: 0x26520004  addiu       $s2, $s2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cffd0) {
            ctx->pc = 0x1CFFE8u;
            goto label_1cffe8;
        }
    }
    ctx->pc = 0x1CFFD8u;
    // 0x1cffd8: 0x306600ff  andi        $a2, $v1, 0xFF
    ctx->pc = 0x1cffd8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1cffdc: 0x3284ffff  andi        $a0, $s4, 0xFFFF
    ctx->pc = 0x1cffdcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)65535);
    // 0x1cffe0: 0xc073e74  jal         func_1CF9D0
    ctx->pc = 0x1CFFE0u;
    SET_GPR_U32(ctx, 31, 0x1CFFE8u);
    ctx->pc = 0x1CFFE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFFE0u;
            // 0x1cffe4: 0x3205ffff  andi        $a1, $s0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF9D0u;
    if (runtime->hasFunction(0x1CF9D0u)) {
        auto targetFn = runtime->lookupFunction(0x1CF9D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFFE8u; }
        if (ctx->pc != 0x1CFFE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF9D0_0x1cf9d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFFE8u; }
        if (ctx->pc != 0x1CFFE8u) { return; }
    }
    ctx->pc = 0x1CFFE8u;
label_1cffe8:
    // 0x1cffe8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1cffe8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1cffec: 0x2a220020  slti        $v0, $s1, 0x20
    ctx->pc = 0x1cffecu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1cfff0: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x1CFFF0u;
    {
        const bool branch_taken_0x1cfff0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cfff0) {
            ctx->pc = 0x1CFFC8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cffc8;
        }
    }
    ctx->pc = 0x1CFFF8u;
label_1cfff8:
    // 0x1cfff8: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1cfff8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1cfffc: 0x2a620002  slti        $v0, $s3, 0x2
    ctx->pc = 0x1cfffcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1d0000: 0x1440ffe2  bnez        $v0, . + 4 + (-0x1E << 2)
    ctx->pc = 0x1D0000u;
    {
        const bool branch_taken_0x1d0000 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d0000) {
            ctx->pc = 0x1CFF8Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cff8c;
        }
    }
    ctx->pc = 0x1D0008u;
    // 0x1d0008: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x1D0008u;
    SET_GPR_U32(ctx, 31, 0x1D0010u);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0010u; }
        if (ctx->pc != 0x1D0010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0010u; }
        if (ctx->pc != 0x1D0010u) { return; }
    }
    ctx->pc = 0x1D0010u;
label_1d0010:
    // 0x1d0010: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1d0010u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d0014: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d0014u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d0018: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d0018u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d001c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d001cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d0020: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d0020u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d0024: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d0024u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d0028: 0x3e00008  jr          $ra
    ctx->pc = 0x1D0028u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D002Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0028u;
            // 0x1d002c: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CFC2Cu: goto label_1cfc2c;
            case 0x1CFC3Cu: goto label_1cfc3c;
            case 0x1CFC4Cu: goto label_1cfc4c;
            case 0x1CFC5Cu: goto label_1cfc5c;
            case 0x1CFC98u: goto label_1cfc98;
            case 0x1CFCBCu: goto label_1cfcbc;
            case 0x1CFCE0u: goto label_1cfce0;
            case 0x1CFCFCu: goto label_1cfcfc;
            case 0x1CFD00u: goto label_1cfd00;
            case 0x1CFD0Cu: goto label_1cfd0c;
            case 0x1CFD18u: goto label_1cfd18;
            case 0x1CFD34u: goto label_1cfd34;
            case 0x1CFD38u: goto label_1cfd38;
            case 0x1CFD44u: goto label_1cfd44;
            case 0x1CFD54u: goto label_1cfd54;
            case 0x1CFD84u: goto label_1cfd84;
            case 0x1CFDA4u: goto label_1cfda4;
            case 0x1CFDBCu: goto label_1cfdbc;
            case 0x1CFDE8u: goto label_1cfde8;
            case 0x1CFDECu: goto label_1cfdec;
            case 0x1CFDF8u: goto label_1cfdf8;
            case 0x1CFE08u: goto label_1cfe08;
            case 0x1CFE1Cu: goto label_1cfe1c;
            case 0x1CFE20u: goto label_1cfe20;
            case 0x1CFE40u: goto label_1cfe40;
            case 0x1CFE44u: goto label_1cfe44;
            case 0x1CFE60u: goto label_1cfe60;
            case 0x1CFE78u: goto label_1cfe78;
            case 0x1CFE98u: goto label_1cfe98;
            case 0x1CFEB0u: goto label_1cfeb0;
            case 0x1CFEC8u: goto label_1cfec8;
            case 0x1CFEE4u: goto label_1cfee4;
            case 0x1CFEECu: goto label_1cfeec;
            case 0x1CFEF0u: goto label_1cfef0;
            case 0x1CFF34u: goto label_1cff34;
            case 0x1CFF68u: goto label_1cff68;
            case 0x1CFF78u: goto label_1cff78;
            case 0x1CFF8Cu: goto label_1cff8c;
            case 0x1CFFC8u: goto label_1cffc8;
            case 0x1CFFE8u: goto label_1cffe8;
            case 0x1CFFF8u: goto label_1cfff8;
            case 0x1D0010u: goto label_1d0010;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D0030u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
