#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018CD00
// Address: 0x18cd00 - 0x18ce30
void sub_0018CD00_0x18cd00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018CD00_0x18cd00");
#endif

    switch (ctx->pc) {
        case 0x18cd20u: goto label_18cd20;
        case 0x18cd2cu: goto label_18cd2c;
        case 0x18cdb0u: goto label_18cdb0;
        case 0x18cdfcu: goto label_18cdfc;
        default: break;
    }

    ctx->pc = 0x18cd00u;

    // 0x18cd00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x18cd00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18cd04: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x18cd04u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cd08: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18cd08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x18cd0c: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x18cd0cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x18cd10: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18cd10u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18cd14: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x18cd14u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cd18: 0xc0631f0  jal         func_18C7C0
    ctx->pc = 0x18CD18u;
    SET_GPR_U32(ctx, 31, 0x18CD20u);
    ctx->pc = 0x18CD1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18CD18u;
            // 0x18cd1c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C7C0u;
    if (runtime->hasFunction(0x18C7C0u)) {
        auto targetFn = runtime->lookupFunction(0x18C7C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CD20u; }
        if (ctx->pc != 0x18CD20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7C0_0x18c7c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CD20u; }
        if (ctx->pc != 0x18CD20u) { return; }
    }
    ctx->pc = 0x18CD20u;
label_18cd20:
    // 0x18cd20: 0x26040010  addiu       $a0, $s0, 0x10
    ctx->pc = 0x18cd20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x18cd24: 0xc063214  jal         func_18C850
    ctx->pc = 0x18CD24u;
    SET_GPR_U32(ctx, 31, 0x18CD2Cu);
    ctx->pc = 0x18CD28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18CD24u;
            // 0x18cd28: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C850u;
    if (runtime->hasFunction(0x18C850u)) {
        auto targetFn = runtime->lookupFunction(0x18C850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CD2Cu; }
        if (ctx->pc != 0x18CD2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C850_0x18c850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CD2Cu; }
        if (ctx->pc != 0x18CD2Cu) { return; }
    }
    ctx->pc = 0x18CD2Cu;
label_18cd2c:
    // 0x18cd2c: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x18cd2cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x18cd30: 0x34038001  ori         $v1, $zero, 0x8001
    ctx->pc = 0x18cd30u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32769);
    // 0x18cd34: 0x4283c  dsll32      $a1, $a0, 0
    ctx->pc = 0x18cd34u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) << (32 + 0));
    // 0x18cd38: 0x652825  or          $a1, $v1, $a1
    ctx->pc = 0x18cd38u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x18cd3c: 0x2404000e  addiu       $a0, $zero, 0xE
    ctx->pc = 0x18cd3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x18cd40: 0xfe050020  sd          $a1, 0x20($s0)
    ctx->pc = 0x18cd40u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 32), GPR_U64(ctx, 5));
    // 0x18cd44: 0x2403003f  addiu       $v1, $zero, 0x3F
    ctx->pc = 0x18cd44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
    // 0x18cd48: 0xfe040028  sd          $a0, 0x28($s0)
    ctx->pc = 0x18cd48u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 40), GPR_U64(ctx, 4));
    // 0x18cd4c: 0xfe000030  sd          $zero, 0x30($s0)
    ctx->pc = 0x18cd4cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 48), GPR_U64(ctx, 0));
    // 0x18cd50: 0xfe030038  sd          $v1, 0x38($s0)
    ctx->pc = 0x18cd50u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 56), GPR_U64(ctx, 3));
    // 0x18cd54: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x18cd54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18cd58: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18cd58u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18cd5c: 0x3e00008  jr          $ra
    ctx->pc = 0x18CD5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18CD60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18CD5Cu;
            // 0x18cd60: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18CD20u: goto label_18cd20;
            case 0x18CD2Cu: goto label_18cd2c;
            case 0x18CDB0u: goto label_18cdb0;
            case 0x18CDFCu: goto label_18cdfc;
            case 0x18CE0Cu: goto label_18ce0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18CD64u;
    // 0x18cd64: 0x0  nop
    ctx->pc = 0x18cd64u;
    // NOP
    // 0x18cd68: 0x0  nop
    ctx->pc = 0x18cd68u;
    // NOP
    // 0x18cd6c: 0x0  nop
    ctx->pc = 0x18cd6cu;
    // NOP
    // 0x18cd70: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x18cd70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18cd74: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18cd74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18cd78: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18cd78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x18cd7c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18cd7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18cd80: 0x8c224150  lw          $v0, 0x4150($at)
    ctx->pc = 0x18cd80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16720)));
    // 0x18cd84: 0x10400021  beqz        $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x18CD84u;
    {
        const bool branch_taken_0x18cd84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x18CD88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18CD84u;
            // 0x18cd88: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18cd84) {
            ctx->pc = 0x18CE0Cu;
            goto label_18ce0c;
        }
    }
    ctx->pc = 0x18CD8Cu;
    // 0x18cd8c: 0x3c030080  lui         $v1, 0x80
    ctx->pc = 0x18cd8cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)128 << 16));
    // 0x18cd90: 0x8c30fd78  lw          $s0, -0x288($at)
    ctx->pc = 0x18cd90u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966648)));
    // 0x18cd94: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18cd94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18cd98: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x18cd98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cd9c: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x18cd9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x18cda0: 0xac233c00  sw          $v1, 0x3C00($at)
    ctx->pc = 0x18cda0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 15360), GPR_U32(ctx, 3)); // MMIO: 0x10003c00
    // 0x18cda4: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x18cda4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x18cda8: 0xc0454b0  jal         func_1152C0
    ctx->pc = 0x18CDA8u;
    SET_GPR_U32(ctx, 31, 0x18CDB0u);
    ctx->pc = 0x18CDACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18CDA8u;
            // 0x18cdac: 0xfc221040  sd          $v0, 0x1040($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 4160), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1152C0u;
    if (runtime->hasFunction(0x1152C0u)) {
        auto targetFn = runtime->lookupFunction(0x1152C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CDB0u; }
        if (ctx->pc != 0x18CDB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001152C0_0x1152c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CDB0u; }
        if (ctx->pc != 0x18CDB0u) { return; }
    }
    ctx->pc = 0x18CDB0u;
label_18cdb0:
    // 0x18cdb0: 0x92070000  lbu         $a3, 0x0($s0)
    ctx->pc = 0x18cdb0u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x18cdb4: 0x2405ffbf  addiu       $a1, $zero, -0x41
    ctx->pc = 0x18cdb4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967231));
    // 0x18cdb8: 0x30020001  andi        $v0, $zero, 0x1
    ctx->pc = 0x18cdb8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) & (uint64_t)(uint16_t)1);
    // 0x18cdbc: 0x64060040  daddiu      $a2, $zero, 0x40
    ctx->pc = 0x18cdbcu;
    SET_GPR_S64(ctx, 6, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)64);
    // 0x18cdc0: 0x219c0  sll         $v1, $v0, 7
    ctx->pc = 0x18cdc0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
    // 0x18cdc4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18cdc4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18cdc8: 0x2402ff7f  addiu       $v0, $zero, -0x81
    ctx->pc = 0x18cdc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967167));
    // 0x18cdcc: 0xe52824  and         $a1, $a3, $a1
    ctx->pc = 0x18cdccu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & GPR_U64(ctx, 5));
    // 0x18cdd0: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x18cdd0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x18cdd4: 0xa2050000  sb          $a1, 0x0($s0)
    ctx->pc = 0x18cdd4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x18cdd8: 0x92050000  lbu         $a1, 0x0($s0)
    ctx->pc = 0x18cdd8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x18cddc: 0xa21024  and         $v0, $a1, $v0
    ctx->pc = 0x18cddcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x18cde0: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x18cde0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x18cde4: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x18cde4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x18cde8: 0x8c264150  lw          $a2, 0x4150($at)
    ctx->pc = 0x18cde8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16720)));
    // 0x18cdec: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18cdecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18cdf0: 0x8c254148  lw          $a1, 0x4148($at)
    ctx->pc = 0x18cdf0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16712)));
    // 0x18cdf4: 0xc040d4c  jal         func_103530
    ctx->pc = 0x18CDF4u;
    SET_GPR_U32(ctx, 31, 0x18CDFCu);
    ctx->pc = 0x18CDF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18CDF4u;
            // 0x18cdf8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103530u;
    if (runtime->hasFunction(0x103530u)) {
        auto targetFn = runtime->lookupFunction(0x103530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CDFCu; }
        if (ctx->pc != 0x18CDFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103530_0x103530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CDFCu; }
        if (ctx->pc != 0x18CDFCu) { return; }
    }
    ctx->pc = 0x18CDFCu;
label_18cdfc:
    // 0x18cdfc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18cdfcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18ce00: 0xac204148  sw          $zero, 0x4148($at)
    ctx->pc = 0x18ce00u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16712), GPR_U32(ctx, 0));
    // 0x18ce04: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18ce04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18ce08: 0xac204150  sw          $zero, 0x4150($at)
    ctx->pc = 0x18ce08u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16720), GPR_U32(ctx, 0));
label_18ce0c:
    // 0x18ce0c: 0xf  sync
    ctx->pc = 0x18ce0cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x18ce10: 0x42000038  ei
    ctx->pc = 0x18ce10u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x18ce14: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x18ce14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18ce18: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18ce18u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ce1c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18ce1cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18ce20: 0x3e00008  jr          $ra
    ctx->pc = 0x18CE20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18CE24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18CE20u;
            // 0x18ce24: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18CD20u: goto label_18cd20;
            case 0x18CD2Cu: goto label_18cd2c;
            case 0x18CDB0u: goto label_18cdb0;
            case 0x18CDFCu: goto label_18cdfc;
            case 0x18CE0Cu: goto label_18ce0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18CE28u;
    // 0x18ce28: 0x0  nop
    ctx->pc = 0x18ce28u;
    // NOP
    // 0x18ce2c: 0x0  nop
    ctx->pc = 0x18ce2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
