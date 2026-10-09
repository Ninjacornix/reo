#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AAD20
// Address: 0x1aad20 - 0x1aae80
void sub_001AAD20_0x1aad20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AAD20_0x1aad20");
#endif

    switch (ctx->pc) {
        case 0x1aad7cu: goto label_1aad7c;
        case 0x1aad88u: goto label_1aad88;
        case 0x1aada0u: goto label_1aada0;
        case 0x1aada8u: goto label_1aada8;
        case 0x1aadd0u: goto label_1aadd0;
        case 0x1aade0u: goto label_1aade0;
        case 0x1aadecu: goto label_1aadec;
        case 0x1aae0cu: goto label_1aae0c;
        case 0x1aae1cu: goto label_1aae1c;
        case 0x1aae34u: goto label_1aae34;
        default: break;
    }

    ctx->pc = 0x1aad20u;

    // 0x1aad20: 0x27bdfe50  addiu       $sp, $sp, -0x1B0
    ctx->pc = 0x1aad20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966864));
    // 0x1aad24: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1aad24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1aad28: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1aad28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1aad2c: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1aad2cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aad30: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1aad30u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1aad34: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1aad34u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1aad38: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1aad38u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1aad3c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1aad3cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1aad40: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1aad40u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1aad44: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1aad44u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1aad48: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1aad48u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1aad4c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1aad4cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aad50: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1aad50u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aad54: 0x1223003e  beq         $s1, $v1, . + 4 + (0x3E << 2)
    ctx->pc = 0x1AAD54u;
    {
        const bool branch_taken_0x1aad54 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AAD58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAD54u;
            // 0x1aad58: 0xa4a30000  sh          $v1, 0x0($a1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aad54) {
            ctx->pc = 0x1AAE50u;
            goto label_1aae50;
        }
    }
    ctx->pc = 0x1AAD5Cu;
    // 0x1aad5c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aad5cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aad60: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1aad60u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1aad64: 0x8c32440c  lw          $s2, 0x440C($at)
    ctx->pc = 0x1aad64u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1aad68: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1aad68u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1aad6c: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1aad6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1aad70: 0x24a5d0b8  addiu       $a1, $a1, -0x2F48
    ctx->pc = 0x1aad70u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955192));
    // 0x1aad74: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AAD74u;
    SET_GPR_U32(ctx, 31, 0x1AAD7Cu);
    ctx->pc = 0x1AAD78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAD74u;
            // 0x1aad78: 0x24c6d040  addiu       $a2, $a2, -0x2FC0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294955072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAD7Cu; }
        if (ctx->pc != 0x1AAD7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAD7Cu; }
        if (ctx->pc != 0x1AAD7Cu) { return; }
    }
    ctx->pc = 0x1AAD7Cu;
label_1aad7c:
    // 0x1aad7c: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1aad7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1aad80: 0xc06a920  jal         func_1AA480
    ctx->pc = 0x1AAD80u;
    SET_GPR_U32(ctx, 31, 0x1AAD88u);
    ctx->pc = 0x1AAD84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAD80u;
            // 0x1aad84: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA480u;
    if (runtime->hasFunction(0x1AA480u)) {
        auto targetFn = runtime->lookupFunction(0x1AA480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAD88u; }
        if (ctx->pc != 0x1AAD88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA480_0x1aa480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAD88u; }
        if (ctx->pc != 0x1AAD88u) { return; }
    }
    ctx->pc = 0x1AAD88u;
label_1aad88:
    // 0x1aad88: 0x18400031  blez        $v0, . + 4 + (0x31 << 2)
    ctx->pc = 0x1AAD88u;
    {
        const bool branch_taken_0x1aad88 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1aad88) {
            ctx->pc = 0x1AAE50u;
            goto label_1aae50;
        }
    }
    ctx->pc = 0x1AAD90u;
    // 0x1aad90: 0x27a40180  addiu       $a0, $sp, 0x180
    ctx->pc = 0x1aad90u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 384));
    // 0x1aad94: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1aad94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aad98: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1AAD98u;
    SET_GPR_U32(ctx, 31, 0x1AADA0u);
    ctx->pc = 0x1AAD9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAD98u;
            // 0x1aad9c: 0x24060030  addiu       $a2, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AADA0u; }
        if (ctx->pc != 0x1AADA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AADA0u; }
        if (ctx->pc != 0x1AADA0u) { return; }
    }
    ctx->pc = 0x1AADA0u;
label_1aada0:
    // 0x1aada0: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1AADA0u;
    SET_GPR_U32(ctx, 31, 0x1AADA8u);
    ctx->pc = 0x1AADA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AADA0u;
            // 0x1aada4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AADA8u; }
        if (ctx->pc != 0x1AADA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AADA8u; }
        if (ctx->pc != 0x1AADA8u) { return; }
    }
    ctx->pc = 0x1AADA8u;
label_1aada8:
    // 0x1aada8: 0x8fa30184  lw          $v1, 0x184($sp)
    ctx->pc = 0x1aada8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 388)));
    // 0x1aadac: 0x10600028  beqz        $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x1AADACu;
    {
        const bool branch_taken_0x1aadac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AADB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AADACu;
            // 0x1aadb0: 0x8fb1018c  lw          $s1, 0x18C($sp) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 396)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aadac) {
            ctx->pc = 0x1AAE50u;
            goto label_1aae50;
        }
    }
    ctx->pc = 0x1AADB4u;
    // 0x1aadb4: 0x2439821  addu        $s3, $s2, $v1
    ctx->pc = 0x1aadb4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x1aadb8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aadb8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aadbc: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1aadbcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1aadc0: 0x3c020018  lui         $v0, 0x18
    ctx->pc = 0x1aadc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)24 << 16));
    // 0x1aadc4: 0xb02d  daddu       $s6, $zero, $zero
    ctx->pc = 0x1aadc4u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aadc8: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1AADC8u;
    {
        const bool branch_taken_0x1aadc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AADCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AADC8u;
            // 0x1aadcc: 0x62a021  addu        $s4, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aadc8) {
            ctx->pc = 0x1AAE3Cu;
            goto label_1aae3c;
        }
    }
    ctx->pc = 0x1AADD0u;
label_1aadd0:
    // 0x1aadd0: 0x8e750000  lw          $s5, 0x0($s3)
    ctx->pc = 0x1aadd0u;
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1aadd4: 0x26640004  addiu       $a0, $s3, 0x4
    ctx->pc = 0x1aadd4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x1aadd8: 0xc06bd74  jal         func_1AF5D0
    ctx->pc = 0x1AADD8u;
    SET_GPR_U32(ctx, 31, 0x1AADE0u);
    ctx->pc = 0x1AADDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AADD8u;
            // 0x1aaddc: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF5D0u;
    if (runtime->hasFunction(0x1AF5D0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF5D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AADE0u; }
        if (ctx->pc != 0x1AADE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF5D0_0x1af5d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AADE0u; }
        if (ctx->pc != 0x1AADE0u) { return; }
    }
    ctx->pc = 0x1AADE0u;
label_1aade0:
    // 0x1aade0: 0x8e450000  lw          $a1, 0x0($s2)
    ctx->pc = 0x1aade0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1aade4: 0xc0733f4  jal         func_1CCFD0
    ctx->pc = 0x1AADE4u;
    SET_GPR_U32(ctx, 31, 0x1AADECu);
    ctx->pc = 0x1AADE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AADE4u;
            // 0x1aade8: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCFD0u;
    if (runtime->hasFunction(0x1CCFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1CCFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AADECu; }
        if (ctx->pc != 0x1AADECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCFD0_0x1ccfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AADECu; }
        if (ctx->pc != 0x1AADECu) { return; }
    }
    ctx->pc = 0x1AADECu;
label_1aadec:
    // 0x1aadec: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AADECu;
    {
        const bool branch_taken_0x1aadec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aadec) {
            ctx->pc = 0x1AADFCu;
            goto label_1aadfc;
        }
    }
    ctx->pc = 0x1AADF4u;
    // 0x1aadf4: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x1aadf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1aadf8: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x1aadf8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
label_1aadfc:
    // 0x1aadfc: 0x26620004  addiu       $v0, $s3, 0x4
    ctx->pc = 0x1aadfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x1aae00: 0x26100002  addiu       $s0, $s0, 0x2
    ctx->pc = 0x1aae00u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
    // 0x1aae04: 0x559821  addu        $s3, $v0, $s5
    ctx->pc = 0x1aae04u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 21)));
    // 0x1aae08: 0x26d60001  addiu       $s6, $s6, 0x1
    ctx->pc = 0x1aae08u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
label_1aae0c:
    // 0x1aae0c: 0x2d1102a  slt         $v0, $s6, $s1
    ctx->pc = 0x1aae0cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 22) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x1aae10: 0x1440ffef  bnez        $v0, . + 4 + (-0x11 << 2)
    ctx->pc = 0x1AAE10u;
    {
        const bool branch_taken_0x1aae10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1aae10) {
            ctx->pc = 0x1AADD0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1aadd0;
        }
    }
    ctx->pc = 0x1AAE18u;
    // 0x1aae18: 0x2ac10007  slti        $at, $s6, 0x7
    ctx->pc = 0x1aae18u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 22) < (int64_t)(int32_t)7) ? 1 : 0);
label_1aae1c:
    // 0x1aae1c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AAE1Cu;
    {
        const bool branch_taken_0x1aae1c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aae1c) {
            ctx->pc = 0x1AAE2Cu;
            goto label_1aae2c;
        }
    }
    ctx->pc = 0x1AAE24u;
    // 0x1aae24: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1aae24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1aae28: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x1aae28u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
label_1aae2c:
    // 0x1aae2c: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x1AAE2Cu;
    SET_GPR_U32(ctx, 31, 0x1AAE34u);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAE34u; }
        if (ctx->pc != 0x1AAE34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAE34u; }
        if (ctx->pc != 0x1AAE34u) { return; }
    }
    ctx->pc = 0x1AAE34u;
label_1aae34:
    // 0x1aae34: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1AAE34u;
    {
        const bool branch_taken_0x1aae34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AAE38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAE34u;
            // 0x1aae38: 0xdfbf0070  ld          $ra, 0x70($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aae34) {
            ctx->pc = 0x1AAE54u;
            goto label_1aae54;
        }
    }
    ctx->pc = 0x1AAE3Cu;
label_1aae3c:
    // 0x1aae3c: 0x11082a  slt         $at, $zero, $s1
    ctx->pc = 0x1aae3cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x1aae40: 0x1020fff6  beqz        $at, . + 4 + (-0xA << 2)
    ctx->pc = 0x1AAE40u;
    {
        const bool branch_taken_0x1aae40 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AAE44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAE40u;
            // 0x1aae44: 0x2ac10007  slti        $at, $s6, 0x7 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 22) < (int64_t)(int32_t)7) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aae40) {
            ctx->pc = 0x1AAE1Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1aae1c;
        }
    }
    ctx->pc = 0x1AAE48u;
    // 0x1aae48: 0x1000fff0  b           . + 4 + (-0x10 << 2)
    ctx->pc = 0x1AAE48u;
    {
        const bool branch_taken_0x1aae48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AAE4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAE48u;
            // 0x1aae4c: 0x26920008  addiu       $s2, $s4, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 20), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aae48) {
            ctx->pc = 0x1AAE0Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1aae0c;
        }
    }
    ctx->pc = 0x1AAE50u;
label_1aae50:
    // 0x1aae50: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1aae50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
label_1aae54:
    // 0x1aae54: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1aae54u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1aae58: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1aae58u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1aae5c: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1aae5cu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1aae60: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1aae60u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1aae64: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1aae64u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1aae68: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1aae68u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1aae6c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1aae6cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aae70: 0x3e00008  jr          $ra
    ctx->pc = 0x1AAE70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AAE74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAE70u;
            // 0x1aae74: 0x27bd01b0  addiu       $sp, $sp, 0x1B0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 432));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AAD7Cu: goto label_1aad7c;
            case 0x1AAD88u: goto label_1aad88;
            case 0x1AADA0u: goto label_1aada0;
            case 0x1AADA8u: goto label_1aada8;
            case 0x1AADD0u: goto label_1aadd0;
            case 0x1AADE0u: goto label_1aade0;
            case 0x1AADECu: goto label_1aadec;
            case 0x1AADFCu: goto label_1aadfc;
            case 0x1AAE0Cu: goto label_1aae0c;
            case 0x1AAE1Cu: goto label_1aae1c;
            case 0x1AAE2Cu: goto label_1aae2c;
            case 0x1AAE34u: goto label_1aae34;
            case 0x1AAE3Cu: goto label_1aae3c;
            case 0x1AAE50u: goto label_1aae50;
            case 0x1AAE54u: goto label_1aae54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AAE78u;
    // 0x1aae78: 0x0  nop
    ctx->pc = 0x1aae78u;
    // NOP
    // 0x1aae7c: 0x0  nop
    ctx->pc = 0x1aae7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
