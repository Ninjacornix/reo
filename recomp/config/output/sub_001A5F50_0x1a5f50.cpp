#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5F50
// Address: 0x1a5f50 - 0x1a6030
void sub_001A5F50_0x1a5f50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5F50_0x1a5f50");
#endif

    switch (ctx->pc) {
        case 0x1a5f68u: goto label_1a5f68;
        case 0x1a5fbcu: goto label_1a5fbc;
        case 0x1a5fc8u: goto label_1a5fc8;
        case 0x1a5fd0u: goto label_1a5fd0;
        case 0x1a5fdcu: goto label_1a5fdc;
        default: break;
    }

    ctx->pc = 0x1a5f50u;

    // 0x1a5f50: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1a5f50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1a5f54: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1a5f54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5f58: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1a5f58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1a5f5c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a5f5cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a5f60: 0xc069850  jal         func_1A6140
    ctx->pc = 0x1A5F60u;
    SET_GPR_U32(ctx, 31, 0x1A5F68u);
    ctx->pc = 0x1A5F64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5F60u;
            // 0x1a5f64: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A6140u;
    if (runtime->hasFunction(0x1A6140u)) {
        auto targetFn = runtime->lookupFunction(0x1A6140u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5F68u; }
        if (ctx->pc != 0x1A5F68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A6140_0x1a6140(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5F68u; }
        if (ctx->pc != 0x1A5F68u) { return; }
    }
    ctx->pc = 0x1A5F68u;
label_1a5f68:
    // 0x1a5f68: 0x10400025  beqz        $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x1A5F68u;
    {
        const bool branch_taken_0x1a5f68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a5f68) {
            ctx->pc = 0x1A6000u;
            goto label_1a6000;
        }
    }
    ctx->pc = 0x1A5F70u;
    // 0x1a5f70: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a5f70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a5f74: 0x3c11002b  lui         $s1, 0x2B
    ctx->pc = 0x1a5f74u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)43 << 16));
    // 0x1a5f78: 0x90220a15  lbu         $v0, 0xA15($at)
    ctx->pc = 0x1a5f78u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 2581)));
    // 0x1a5f7c: 0x26310a30  addiu       $s1, $s1, 0xA30
    ctx->pc = 0x1a5f7cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 2608));
    // 0x1a5f80: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1a5f80u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1a5f84: 0x3c10002b  lui         $s0, 0x2B
    ctx->pc = 0x1a5f84u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)43 << 16));
    // 0x1a5f88: 0x24631160  addiu       $v1, $v1, 0x1160
    ctx->pc = 0x1a5f88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4448));
    // 0x1a5f8c: 0x26100a00  addiu       $s0, $s0, 0xA00
    ctx->pc = 0x1a5f8cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2560));
    // 0x1a5f90: 0xa2220006  sb          $v0, 0x6($s1)
    ctx->pc = 0x1a5f90u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 6), (uint8_t)GPR_U32(ctx, 2));
    // 0x1a5f94: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x1a5f94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1a5f98: 0x3045000f  andi        $a1, $v0, 0xF
    ctx->pc = 0x1a5f98u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x1a5f9c: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1a5f9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1a5fa0: 0x3042fff0  andi        $v0, $v0, 0xFFF0
    ctx->pc = 0x1a5fa0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65520);
    // 0x1a5fa4: 0x90630000  lbu         $v1, 0x0($v1)
    ctx->pc = 0x1a5fa4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a5fa8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1a5fa8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1a5fac: 0xae220008  sw          $v0, 0x8($s1)
    ctx->pc = 0x1a5facu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
    // 0x1a5fb0: 0x86050002  lh          $a1, 0x2($s0)
    ctx->pc = 0x1a5fb0u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1a5fb4: 0xc069920  jal         func_1A6480
    ctx->pc = 0x1A5FB4u;
    SET_GPR_U32(ctx, 31, 0x1A5FBCu);
    ctx->pc = 0x1A5FB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5FB4u;
            // 0x1a5fb8: 0x2624000c  addiu       $a0, $s1, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A6480u;
    if (runtime->hasFunction(0x1A6480u)) {
        auto targetFn = runtime->lookupFunction(0x1A6480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5FBCu; }
        if (ctx->pc != 0x1A5FBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A6480_0x1a6480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5FBCu; }
        if (ctx->pc != 0x1A5FBCu) { return; }
    }
    ctx->pc = 0x1A5FBCu;
label_1a5fbc:
    // 0x1a5fbc: 0x86050004  lh          $a1, 0x4($s0)
    ctx->pc = 0x1a5fbcu;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1a5fc0: 0xc069920  jal         func_1A6480
    ctx->pc = 0x1A5FC0u;
    SET_GPR_U32(ctx, 31, 0x1A5FC8u);
    ctx->pc = 0x1A5FC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5FC0u;
            // 0x1a5fc4: 0x26240018  addiu       $a0, $s1, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A6480u;
    if (runtime->hasFunction(0x1A6480u)) {
        auto targetFn = runtime->lookupFunction(0x1A6480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5FC8u; }
        if (ctx->pc != 0x1A5FC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A6480_0x1a6480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5FC8u; }
        if (ctx->pc != 0x1A5FC8u) { return; }
    }
    ctx->pc = 0x1A5FC8u;
label_1a5fc8:
    // 0x1a5fc8: 0xc069974  jal         func_1A65D0
    ctx->pc = 0x1A5FC8u;
    SET_GPR_U32(ctx, 31, 0x1A5FD0u);
    ctx->pc = 0x1A5FCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5FC8u;
            // 0x1a5fcc: 0x2624000c  addiu       $a0, $s1, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A65D0u;
    if (runtime->hasFunction(0x1A65D0u)) {
        auto targetFn = runtime->lookupFunction(0x1A65D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5FD0u; }
        if (ctx->pc != 0x1A5FD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A65D0_0x1a65d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5FD0u; }
        if (ctx->pc != 0x1A5FD0u) { return; }
    }
    ctx->pc = 0x1A5FD0u;
label_1a5fd0:
    // 0x1a5fd0: 0x305000ff  andi        $s0, $v0, 0xFF
    ctx->pc = 0x1a5fd0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1a5fd4: 0xc069974  jal         func_1A65D0
    ctx->pc = 0x1A5FD4u;
    SET_GPR_U32(ctx, 31, 0x1A5FDCu);
    ctx->pc = 0x1A5FD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5FD4u;
            // 0x1a5fd8: 0x26240018  addiu       $a0, $s1, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A65D0u;
    if (runtime->hasFunction(0x1A65D0u)) {
        auto targetFn = runtime->lookupFunction(0x1A65D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5FDCu; }
        if (ctx->pc != 0x1A5FDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A65D0_0x1a65d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5FDCu; }
        if (ctx->pc != 0x1A5FDCu) { return; }
    }
    ctx->pc = 0x1A5FDCu;
label_1a5fdc:
    // 0x1a5fdc: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1a5fdcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1a5fe0: 0x102c00  sll         $a1, $s0, 16
    ctx->pc = 0x1a5fe0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 16), 16));
    // 0x1a5fe4: 0x32500  sll         $a0, $v1, 20
    ctx->pc = 0x1a5fe4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 20));
    // 0x1a5fe8: 0x8e230008  lw          $v1, 0x8($s1)
    ctx->pc = 0x1a5fe8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1a5fec: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x1a5fecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x1a5ff0: 0xae230008  sw          $v1, 0x8($s1)
    ctx->pc = 0x1a5ff0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 3));
    // 0x1a5ff4: 0x8e230008  lw          $v1, 0x8($s1)
    ctx->pc = 0x1a5ff4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1a5ff8: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1a5ff8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1a5ffc: 0xae230008  sw          $v1, 0x8($s1)
    ctx->pc = 0x1a5ffcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 3));
label_1a6000:
    // 0x1a6000: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a6000u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a6004: 0x90230990  lbu         $v1, 0x990($at)
    ctx->pc = 0x1a6004u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 2448)));
    // 0x1a6008: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a6008u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a600c: 0xa0230988  sb          $v1, 0x988($at)
    ctx->pc = 0x1a600cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 2440), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a6010: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1a6010u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a6014: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a6014u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a6018: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a6018u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a601c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A601Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A6020u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A601Cu;
            // 0x1a6020: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A5F68u: goto label_1a5f68;
            case 0x1A5FBCu: goto label_1a5fbc;
            case 0x1A5FC8u: goto label_1a5fc8;
            case 0x1A5FD0u: goto label_1a5fd0;
            case 0x1A5FDCu: goto label_1a5fdc;
            case 0x1A6000u: goto label_1a6000;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A6024u;
    // 0x1a6024: 0x0  nop
    ctx->pc = 0x1a6024u;
    // NOP
    // 0x1a6028: 0x0  nop
    ctx->pc = 0x1a6028u;
    // NOP
    // 0x1a602c: 0x0  nop
    ctx->pc = 0x1a602cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
