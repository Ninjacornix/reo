#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00187B70
// Address: 0x187b70 - 0x187d38
void sub_00187B70_0x187b70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00187B70_0x187b70");
#endif

    switch (ctx->pc) {
        case 0x187bccu: goto label_187bcc;
        case 0x187bf8u: goto label_187bf8;
        case 0x187c14u: goto label_187c14;
        case 0x187c24u: goto label_187c24;
        case 0x187c30u: goto label_187c30;
        case 0x187c44u: goto label_187c44;
        case 0x187c64u: goto label_187c64;
        default: break;
    }

    ctx->pc = 0x187b70u;

    // 0x187b70: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x187b70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x187b74: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x187b74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x187b78: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x187b78u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187b7c: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x187b7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x187b80: 0x12b0c0  sll         $s6, $s2, 3
    ctx->pc = 0x187b80u;
    SET_GPR_S32(ctx, 22, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x187b84: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x187b84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x187b88: 0x3c170029  lui         $s7, 0x29
    ctx->pc = 0x187b88u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)41 << 16));
    // 0x187b8c: 0x26e3b8c8  addiu       $v1, $s7, -0x4738
    ctx->pc = 0x187b8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 23), 4294949064));
    // 0x187b90: 0x2d21023  subu        $v0, $s6, $s2
    ctx->pc = 0x187b90u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 22), GPR_U32(ctx, 18)));
    // 0x187b94: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x187b94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x187b98: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x187b98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x187b9c: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x187b9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x187ba0: 0x24130003  addiu       $s3, $zero, 0x3
    ctx->pc = 0x187ba0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x187ba4: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x187ba4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x187ba8: 0xa0f02d  daddu       $fp, $a1, $zero
    ctx->pc = 0x187ba8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187bac: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x187bacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x187bb0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x187bb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x187bb4: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x187bb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x187bb8: 0x438821  addu        $s1, $v0, $v1
    ctx->pc = 0x187bb8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x187bbc: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x187bbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x187bc0: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x187bc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x187bc4: 0xc0623b6  jal         func_188ED8
    ctx->pc = 0x187BC4u;
    SET_GPR_U32(ctx, 31, 0x187BCCu);
    ctx->pc = 0x187BC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187BC4u;
            // 0x187bc8: 0x8e240000  lw          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188ED8u;
    if (runtime->hasFunction(0x188ED8u)) {
        auto targetFn = runtime->lookupFunction(0x188ED8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187BCCu; }
        if (ctx->pc != 0x187BCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188ED8_0x188ed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187BCCu; }
        if (ctx->pc != 0x187BCCu) { return; }
    }
    ctx->pc = 0x187BCCu;
label_187bcc:
    // 0x187bcc: 0x14530004  bne         $v0, $s3, . + 4 + (0x4 << 2)
    ctx->pc = 0x187BCCu;
    {
        const bool branch_taken_0x187bcc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 19));
        ctx->pc = 0x187BD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187BCCu;
            // 0x187bd0: 0x3c150029  lui         $s5, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187bcc) {
            ctx->pc = 0x187BE0u;
            goto label_187be0;
        }
    }
    ctx->pc = 0x187BD4u;
    // 0x187bd4: 0x1000004c  b           . + 4 + (0x4C << 2)
    ctx->pc = 0x187BD4u;
    {
        const bool branch_taken_0x187bd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x187BD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187BD4u;
            // 0x187bd8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187bd4) {
            ctx->pc = 0x187D08u;
            goto label_187d08;
        }
    }
    ctx->pc = 0x187BDCu;
    // 0x187bdc: 0x0  nop
    ctx->pc = 0x187bdcu;
    // NOP
label_187be0:
    // 0x187be0: 0x3c100029  lui         $s0, 0x29
    ctx->pc = 0x187be0u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)41 << 16));
    // 0x187be4: 0x2610d980  addiu       $s0, $s0, -0x2680
    ctx->pc = 0x187be4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294957440));
    // 0x187be8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x187be8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187bec: 0x26a4b900  addiu       $a0, $s5, -0x4700
    ctx->pc = 0x187becu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294949120));
    // 0x187bf0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x187BF0u;
    SET_GPR_U32(ctx, 31, 0x187BF8u);
    ctx->pc = 0x187BF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187BF0u;
            // 0x187bf4: 0x24062080  addiu       $a2, $zero, 0x2080 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8320));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187BF8u; }
        if (ctx->pc != 0x187BF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187BF8u; }
        if (ctx->pc != 0x187BF8u) { return; }
    }
    ctx->pc = 0x187BF8u;
label_187bf8:
    // 0x187bf8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x187bf8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187bfc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x187bfcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187c00: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x187c00u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x187c04: 0x24022080  addiu       $v0, $zero, 0x2080
    ctx->pc = 0x187c04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8320));
    // 0x187c08: 0x3c140018  lui         $s4, 0x18
    ctx->pc = 0x187c08u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)24 << 16));
    // 0x187c0c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x187C0Cu;
    SET_GPR_U32(ctx, 31, 0x187C14u);
    ctx->pc = 0x187C10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187C0Cu;
            // 0x187c10: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187C14u; }
        if (ctx->pc != 0x187C14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187C14u; }
        if (ctx->pc != 0x187C14u) { return; }
    }
    ctx->pc = 0x187C14u;
label_187c14:
    // 0x187c14: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x187c14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187c18: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x187c18u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x187c1c: 0xc0453c6  jal         func_114F18
    ctx->pc = 0x187C1Cu;
    SET_GPR_U32(ctx, 31, 0x187C24u);
    ctx->pc = 0x187C20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187C1Cu;
            // 0x187c20: 0x248500ff  addiu       $a1, $a0, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 255));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114F18u;
    if (runtime->hasFunction(0x114F18u)) {
        auto targetFn = runtime->lookupFunction(0x114F18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187C24u; }
        if (ctx->pc != 0x187C24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114F18_0x114f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187C24u; }
        if (ctx->pc != 0x187C24u) { return; }
    }
    ctx->pc = 0x187C24u;
label_187c24:
    // 0x187c24: 0xae13fd24  sw          $s3, -0x2DC($s0)
    ctx->pc = 0x187c24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294966564), GPR_U32(ctx, 19));
    // 0x187c28: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x187c28u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x187c2c: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x187c2cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_187c30:
    // 0x187c30: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x187c30u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187c34: 0x8e05fd24  lw          $a1, -0x2DC($s0)
    ctx->pc = 0x187c34u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294966564)));
    // 0x187c38: 0x26a7b900  addiu       $a3, $s5, -0x4700
    ctx->pc = 0x187c38u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 21), 4294949120));
    // 0x187c3c: 0xc062560  jal         func_189580
    ctx->pc = 0x187C3Cu;
    SET_GPR_U32(ctx, 31, 0x187C44u);
    ctx->pc = 0x187C40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187C3Cu;
            // 0x187c40: 0x26887808  addiu       $t0, $s4, 0x7808 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 20), 30728));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189580u;
    if (runtime->hasFunction(0x189580u)) {
        auto targetFn = runtime->lookupFunction(0x189580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187C44u; }
        if (ctx->pc != 0x187C44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189580_0x189580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187C44u; }
        if (ctx->pc != 0x187C44u) { return; }
    }
    ctx->pc = 0x187C44u;
label_187c44:
    // 0x187c44: 0x5453fffa  bnel        $v0, $s3, . + 4 + (-0x6 << 2)
    ctx->pc = 0x187C44u;
    {
        const bool branch_taken_0x187c44 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 19));
        if (branch_taken_0x187c44) {
            ctx->pc = 0x187C48u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x187C44u;
            // 0x187c48: 0x8e240000  lw          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x187C30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_187c30;
        }
    }
    ctx->pc = 0x187C4Cu;
    // 0x187c4c: 0x2d21023  subu        $v0, $s6, $s2
    ctx->pc = 0x187c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 22), GPR_U32(ctx, 18)));
    // 0x187c50: 0x26f1b8c8  addiu       $s1, $s7, -0x4738
    ctx->pc = 0x187c50u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 23), 4294949064));
    // 0x187c54: 0x28080  sll         $s0, $v0, 2
    ctx->pc = 0x187c54u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x187c58: 0x2301821  addu        $v1, $s1, $s0
    ctx->pc = 0x187c58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x187c5c: 0xc061db2  jal         func_1876C8
    ctx->pc = 0x187C5Cu;
    SET_GPR_U32(ctx, 31, 0x187C64u);
    ctx->pc = 0x187C60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187C5Cu;
            // 0x187c60: 0x8c640004  lw          $a0, 0x4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1876C8u;
    if (runtime->hasFunction(0x1876C8u)) {
        auto targetFn = runtime->lookupFunction(0x1876C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187C64u; }
        if (ctx->pc != 0x187C64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001876C8_0x1876c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187C64u; }
        if (ctx->pc != 0x187C64u) { return; }
    }
    ctx->pc = 0x187C64u;
label_187c64:
    // 0x187c64: 0x40582d  daddu       $t3, $v0, $zero
    ctx->pc = 0x187c64u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187c68: 0x8d630008  lw          $v1, 0x8($t3)
    ctx->pc = 0x187c68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 8)));
    // 0x187c6c: 0x10600026  beqz        $v1, . + 4 + (0x26 << 2)
    ctx->pc = 0x187C6Cu;
    {
        const bool branch_taken_0x187c6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x187C70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187C6Cu;
            // 0x187c70: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187c6c) {
            ctx->pc = 0x187D08u;
            goto label_187d08;
        }
    }
    ctx->pc = 0x187C74u;
    // 0x187c74: 0x9162000d  lbu         $v0, 0xD($t3)
    ctx->pc = 0x187c74u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 13)));
    // 0x187c78: 0x2302021  addu        $a0, $s1, $s0
    ctx->pc = 0x187c78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x187c7c: 0x9163000c  lbu         $v1, 0xC($t3)
    ctx->pc = 0x187c7cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 12)));
    // 0x187c80: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x187c80u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187c84: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x187c84u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x187c88: 0xa0502d  daddu       $t2, $a1, $zero
    ctx->pc = 0x187c88u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187c8c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x187c8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x187c90: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x187c90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x187c94: 0xac830008  sw          $v1, 0x8($a0)
    ctx->pc = 0x187c94u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 3));
    // 0x187c98: 0x140482d  daddu       $t1, $t2, $zero
    ctx->pc = 0x187c98u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187c9c: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x187c9cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x187ca0: 0x2114021  addu        $t0, $s0, $s1
    ctx->pc = 0x187ca0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x187ca4: 0x9163000f  lbu         $v1, 0xF($t3)
    ctx->pc = 0x187ca4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 15)));
    // 0x187ca8: 0x9164000e  lbu         $a0, 0xE($t3)
    ctx->pc = 0x187ca8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 14)));
    // 0x187cac: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x187cacu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x187cb0: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x187cb0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x187cb4: 0xaca4000c  sw          $a0, 0xC($a1)
    ctx->pc = 0x187cb4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 4));
    // 0x187cb8: 0x91660011  lbu         $a2, 0x11($t3)
    ctx->pc = 0x187cb8u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 17)));
    // 0x187cbc: 0x91650013  lbu         $a1, 0x13($t3)
    ctx->pc = 0x187cbcu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 19)));
    // 0x187cc0: 0x91640012  lbu         $a0, 0x12($t3)
    ctx->pc = 0x187cc0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 18)));
    // 0x187cc4: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x187cc4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x187cc8: 0x91630010  lbu         $v1, 0x10($t3)
    ctx->pc = 0x187cc8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 16)));
    // 0x187ccc: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x187cccu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x187cd0: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x187cd0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x187cd4: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x187cd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x187cd8: 0x862021  addu        $a0, $a0, $a2
    ctx->pc = 0x187cd8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x187cdc: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x187cdcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x187ce0: 0xad430010  sw          $v1, 0x10($t2)
    ctx->pc = 0x187ce0u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 16), GPR_U32(ctx, 3));
    // 0x187ce4: 0xad270014  sw          $a3, 0x14($t1)
    ctx->pc = 0x187ce4u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 20), GPR_U32(ctx, 7));
    // 0x187ce8: 0x6903000f  ldl         $v1, 0xF($t0)
    ctx->pc = 0x187ce8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x187cec: 0x6d030008  ldr         $v1, 0x8($t0)
    ctx->pc = 0x187cecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x187cf0: 0x69040017  ldl         $a0, 0x17($t0)
    ctx->pc = 0x187cf0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x187cf4: 0x6d040010  ldr         $a0, 0x10($t0)
    ctx->pc = 0x187cf4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x187cf8: 0xb3c30007  sdl         $v1, 0x7($fp)
    ctx->pc = 0x187cf8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 30), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187cfc: 0xb7c30000  sdr         $v1, 0x0($fp)
    ctx->pc = 0x187cfcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 30), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187d00: 0xb3c4000f  sdl         $a0, 0xF($fp)
    ctx->pc = 0x187d00u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 30), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187d04: 0xb7c40008  sdr         $a0, 0x8($fp)
    ctx->pc = 0x187d04u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 30), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
label_187d08:
    // 0x187d08: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x187d08u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x187d0c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x187d0cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x187d10: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x187d10u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x187d14: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x187d14u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x187d18: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x187d18u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x187d1c: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x187d1cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x187d20: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x187d20u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x187d24: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x187d24u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x187d28: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x187d28u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x187d2c: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x187d2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x187d30: 0x3e00008  jr          $ra
    ctx->pc = 0x187D30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x187D34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187D30u;
            // 0x187d34: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x187BCCu: goto label_187bcc;
            case 0x187BE0u: goto label_187be0;
            case 0x187BF8u: goto label_187bf8;
            case 0x187C14u: goto label_187c14;
            case 0x187C24u: goto label_187c24;
            case 0x187C30u: goto label_187c30;
            case 0x187C44u: goto label_187c44;
            case 0x187C64u: goto label_187c64;
            case 0x187D08u: goto label_187d08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187D38u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
