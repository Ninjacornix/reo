#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164CE0
// Address: 0x164ce0 - 0x164f3c
void sub_00164CE0_0x164ce0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164CE0_0x164ce0");
#endif

    switch (ctx->pc) {
        case 0x164d34u: goto label_164d34;
        case 0x164d48u: goto label_164d48;
        case 0x164d5cu: goto label_164d5c;
        case 0x164d74u: goto label_164d74;
        case 0x164d94u: goto label_164d94;
        case 0x164db0u: goto label_164db0;
        case 0x164e2cu: goto label_164e2c;
        case 0x164e88u: goto label_164e88;
        case 0x164ea4u: goto label_164ea4;
        case 0x164ee8u: goto label_164ee8;
        default: break;
    }

    ctx->pc = 0x164ce0u;

    // 0x164ce0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x164ce0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x164ce4: 0xffbe0060  sd          $fp, 0x60($sp)
    ctx->pc = 0x164ce4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 30));
    // 0x164ce8: 0xe0f02d  daddu       $fp, $a3, $zero
    ctx->pc = 0x164ce8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164cec: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x164cecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x164cf0: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x164cf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x164cf4: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x164cf4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164cf8: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x164cf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x164cfc: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x164cfcu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164d00: 0xffb70058  sd          $s7, 0x58($sp)
    ctx->pc = 0x164d00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 23));
    // 0x164d04: 0xa0b82d  daddu       $s7, $a1, $zero
    ctx->pc = 0x164d04u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164d08: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x164d08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x164d0c: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x164d0cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x164d10: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x164d10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x164d14: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x164d14u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164d18: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x164d18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x164d1c: 0x26910cc0  addiu       $s1, $s4, 0xCC0
    ctx->pc = 0x164d1cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 20), 3264));
    // 0x164d20: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x164d20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x164d24: 0xffbf0068  sd          $ra, 0x68($sp)
    ctx->pc = 0x164d24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 31));
    // 0x164d28: 0xafc00000  sw          $zero, 0x0($fp)
    ctx->pc = 0x164d28u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 0));
    // 0x164d2c: 0xc0594b2  jal         func_1652C8
    ctx->pc = 0x164D2Cu;
    SET_GPR_U32(ctx, 31, 0x164D34u);
    ctx->pc = 0x164D30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164D2Cu;
            // 0x164d30: 0x8e931b74  lw          $s3, 0x1B74($s4) (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 7028)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1652C8u;
    if (runtime->hasFunction(0x1652C8u)) {
        auto targetFn = runtime->lookupFunction(0x1652C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164D34u; }
        if (ctx->pc != 0x164D34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001652C8_0x1652c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164D34u; }
        if (ctx->pc != 0x164D34u) { return; }
    }
    ctx->pc = 0x164D34u;
label_164d34:
    // 0x164d34: 0x54400010  bnel        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x164D34u;
    {
        const bool branch_taken_0x164d34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x164d34) {
            ctx->pc = 0x164D38u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x164D34u;
            // 0x164d38: 0x3c020016  lui         $v0, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)22 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x164D78u;
            goto label_164d78;
        }
    }
    ctx->pc = 0x164D3Cu;
    // 0x164d3c: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x164d3cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x164d40: 0xc05d830  jal         func_1760C0
    ctx->pc = 0x164D40u;
    SET_GPR_U32(ctx, 31, 0x164D48u);
    ctx->pc = 0x164D44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164D40u;
            // 0x164d44: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1760C0u;
    if (runtime->hasFunction(0x1760C0u)) {
        auto targetFn = runtime->lookupFunction(0x1760C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164D48u; }
        if (ctx->pc != 0x164D48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001760C0_0x1760c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164D48u; }
        if (ctx->pc != 0x164D48u) { return; }
    }
    ctx->pc = 0x164D48u;
label_164d48:
    // 0x164d48: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x164d48u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164d4c: 0x640006f  bltz        $s2, . + 4 + (0x6F << 2)
    ctx->pc = 0x164D4Cu;
    {
        const bool branch_taken_0x164d4c = (GPR_S64(ctx, 18) < 0);
        ctx->pc = 0x164D50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164D4Cu;
            // 0x164d50: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164d4c) {
            ctx->pc = 0x164F0Cu;
            goto label_164f0c;
        }
    }
    ctx->pc = 0x164D54u;
    // 0x164d54: 0xc05d58a  jal         func_175628
    ctx->pc = 0x164D54u;
    SET_GPR_U32(ctx, 31, 0x164D5Cu);
    ctx->pc = 0x164D58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164D54u;
            // 0x164d58: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164D5Cu; }
        if (ctx->pc != 0x164D5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164D5Cu; }
        if (ctx->pc != 0x164D5Cu) { return; }
    }
    ctx->pc = 0x164D5Cu;
label_164d5c:
    // 0x164d5c: 0x5440000a  bnel        $v0, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x164D5Cu;
    {
        const bool branch_taken_0x164d5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x164d5c) {
            ctx->pc = 0x164D60u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x164D5Cu;
            // 0x164d60: 0x8fa50004  lw          $a1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x164D88u;
            goto label_164d88;
        }
    }
    ctx->pc = 0x164D64u;
    // 0x164d64: 0x8fa60004  lw          $a2, 0x4($sp)
    ctx->pc = 0x164d64u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x164d68: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x164d68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164d6c: 0xc05d862  jal         func_176188
    ctx->pc = 0x164D6Cu;
    SET_GPR_U32(ctx, 31, 0x164D74u);
    ctx->pc = 0x164D70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164D6Cu;
            // 0x164d70: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176188u;
    if (runtime->hasFunction(0x176188u)) {
        auto targetFn = runtime->lookupFunction(0x176188u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164D74u; }
        if (ctx->pc != 0x164D74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176188_0x176188(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164D74u; }
        if (ctx->pc != 0x164D74u) { return; }
    }
    ctx->pc = 0x164D74u;
label_164d74:
    // 0x164d74: 0x3c020016  lui         $v0, 0x16
    ctx->pc = 0x164d74u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)22 << 16));
label_164d78:
    // 0x164d78: 0x24424c28  addiu       $v0, $v0, 0x4C28
    ctx->pc = 0x164d78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19496));
    // 0x164d7c: 0x10000063  b           . + 4 + (0x63 << 2)
    ctx->pc = 0x164D7Cu;
    {
        const bool branch_taken_0x164d7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x164D80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164D7Cu;
            // 0x164d80: 0xae62003c  sw          $v0, 0x3C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 60), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164d7c) {
            ctx->pc = 0x164F0Cu;
            goto label_164f0c;
        }
    }
    ctx->pc = 0x164D84u;
    // 0x164d84: 0x0  nop
    ctx->pc = 0x164d84u;
    // NOP
label_164d88:
    // 0x164d88: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x164d88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164d8c: 0xc05d844  jal         func_176110
    ctx->pc = 0x164D8Cu;
    SET_GPR_U32(ctx, 31, 0x164D94u);
    ctx->pc = 0x164D90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164D8Cu;
            // 0x164d90: 0x27a60008  addiu       $a2, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176110u;
    if (runtime->hasFunction(0x176110u)) {
        auto targetFn = runtime->lookupFunction(0x176110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164D94u; }
        if (ctx->pc != 0x164D94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176110_0x176110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164D94u; }
        if (ctx->pc != 0x164D94u) { return; }
    }
    ctx->pc = 0x164D94u;
label_164d94:
    // 0x164d94: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x164d94u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164d98: 0x600005c  bltz        $s0, . + 4 + (0x5C << 2)
    ctx->pc = 0x164D98u;
    {
        const bool branch_taken_0x164d98 = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x164D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164D98u;
            // 0x164d9c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164d98) {
            ctx->pc = 0x164F0Cu;
            goto label_164f0c;
        }
    }
    ctx->pc = 0x164DA0u;
    // 0x164da0: 0x8fa60004  lw          $a2, 0x4($sp)
    ctx->pc = 0x164da0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x164da4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x164da4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164da8: 0xc05d862  jal         func_176188
    ctx->pc = 0x164DA8u;
    SET_GPR_U32(ctx, 31, 0x164DB0u);
    ctx->pc = 0x164DACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164DA8u;
            // 0x164dac: 0xb02d  daddu       $s6, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176188u;
    if (runtime->hasFunction(0x176188u)) {
        auto targetFn = runtime->lookupFunction(0x176188u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164DB0u; }
        if (ctx->pc != 0x164DB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176188_0x176188(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164DB0u; }
        if (ctx->pc != 0x164DB0u) { return; }
    }
    ctx->pc = 0x164DB0u;
label_164db0:
    // 0x164db0: 0x2121823  subu        $v1, $s0, $s2
    ctx->pc = 0x164db0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
    // 0x164db4: 0x8e620038  lw          $v0, 0x38($s3)
    ctx->pc = 0x164db4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 56)));
    // 0x164db8: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x164db8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x164dbc: 0x460003c  bltz        $v1, . + 4 + (0x3C << 2)
    ctx->pc = 0x164DBCu;
    {
        const bool branch_taken_0x164dbc = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x164DC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164DBCu;
            // 0x164dc0: 0x8fa50000  lw          $a1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164dbc) {
            ctx->pc = 0x164EB0u;
            goto label_164eb0;
        }
    }
    ctx->pc = 0x164DC4u;
    // 0x164dc4: 0x31943  sra         $v1, $v1, 5
    ctx->pc = 0x164dc4u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 5));
    // 0x164dc8: 0x651818  mult        $v1, $v1, $a1
    ctx->pc = 0x164dc8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x164dcc: 0x310c0  sll         $v0, $v1, 3
    ctx->pc = 0x164dccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x164dd0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x164dd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x164dd4: 0x28840  sll         $s1, $v0, 1
    ctx->pc = 0x164dd4u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x164dd8: 0x1a200022  blez        $s1, . + 4 + (0x22 << 2)
    ctx->pc = 0x164DD8u;
    {
        const bool branch_taken_0x164dd8 = (GPR_S64(ctx, 17) <= 0);
        ctx->pc = 0x164DDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164DD8u;
            // 0x164ddc: 0xafa0000c  sw          $zero, 0xC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164dd8) {
            ctx->pc = 0x164E64u;
            goto label_164e64;
        }
    }
    ctx->pc = 0x164DE0u;
    // 0x164de0: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x164de0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x164de4: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x164de4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164de8: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x164de8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x164dec: 0x27a6000c  addiu       $a2, $sp, 0xC
    ctx->pc = 0x164decu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
    // 0x164df0: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x164df0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x164df4: 0x2a2001a  div         $zero, $s5, $v0
    ctx->pc = 0x164df4u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 21);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x164df8: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x164DF8u;
    {
        const bool branch_taken_0x164df8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x164df8) {
            ctx->pc = 0x164DFCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x164DF8u;
            // 0x164dfc: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x164E00u;
            goto label_164e00;
        }
    }
    ctx->pc = 0x164E00u;
label_164e00:
    // 0x164e00: 0x1812  mflo        $v1
    ctx->pc = 0x164e00u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x164e04: 0x651818  mult        $v1, $v1, $a1
    ctx->pc = 0x164e04u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x164e08: 0x310c0  sll         $v0, $v1, 3
    ctx->pc = 0x164e08u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x164e0c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x164e0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x164e10: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x164e10u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x164e14: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x164e14u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164e18: 0x51102a  slt         $v0, $v0, $s1
    ctx->pc = 0x164e18u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x164e1c: 0x222800a  movz        $s0, $s1, $v0
    ctx->pc = 0x164e1cu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 17));
    // 0x164e20: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x164e20u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164e24: 0xc0593d0  jal         func_164F40
    ctx->pc = 0x164E24u;
    SET_GPR_U32(ctx, 31, 0x164E2Cu);
    ctx->pc = 0x164E28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164E24u;
            // 0x164e28: 0x2308023  subu        $s0, $s1, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164F40u;
    if (runtime->hasFunction(0x164F40u)) {
        auto targetFn = runtime->lookupFunction(0x164F40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164E2Cu; }
        if (ctx->pc != 0x164E2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164F40_0x164f40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164E2Cu; }
        if (ctx->pc != 0x164E2Cu) { return; }
    }
    ctx->pc = 0x164E2Cu;
label_164e2c:
    // 0x164e2c: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x164e2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164e30: 0x40b02d  daddu       $s6, $v0, $zero
    ctx->pc = 0x164e30u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164e34: 0x310c0  sll         $v0, $v1, 3
    ctx->pc = 0x164e34u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x164e38: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x164e38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x164e3c: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x164e3cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x164e40: 0x2c2001a  div         $zero, $s6, $v0
    ctx->pc = 0x164e40u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 22);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x164e44: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x164E44u;
    {
        const bool branch_taken_0x164e44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x164e44) {
            ctx->pc = 0x164E48u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x164E44u;
            // 0x164e48: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x164E4Cu;
            goto label_164e4c;
        }
    }
    ctx->pc = 0x164E4Cu;
label_164e4c:
    // 0x164e4c: 0x8e630038  lw          $v1, 0x38($s3)
    ctx->pc = 0x164e4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 56)));
    // 0x164e50: 0x2012  mflo        $a0
    ctx->pc = 0x164e50u;
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x164e54: 0x42140  sll         $a0, $a0, 5
    ctx->pc = 0x164e54u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
    // 0x164e58: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x164e58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x164e5c: 0x1e00000b  bgtz        $s0, . + 4 + (0xB << 2)
    ctx->pc = 0x164E5Cu;
    {
        const bool branch_taken_0x164e5c = (GPR_S64(ctx, 16) > 0);
        ctx->pc = 0x164E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164E5Cu;
            // 0x164e60: 0xae630038  sw          $v1, 0x38($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 56), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164e5c) {
            ctx->pc = 0x164E8Cu;
            goto label_164e8c;
        }
    }
    ctx->pc = 0x164E64u;
label_164e64:
    // 0x164e64: 0x8fa20008  lw          $v0, 0x8($sp)
    ctx->pc = 0x164e64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x164e68: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x164E68u;
    {
        const bool branch_taken_0x164e68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x164E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164E68u;
            // 0x164e6c: 0x3c020016  lui         $v0, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)22 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164e68) {
            ctx->pc = 0x164E8Cu;
            goto label_164e8c;
        }
    }
    ctx->pc = 0x164E70u;
    // 0x164e70: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x164e70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164e74: 0x24424c28  addiu       $v0, $v0, 0x4C28
    ctx->pc = 0x164e74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19496));
    // 0x164e78: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x164e78u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164e7c: 0xae62003c  sw          $v0, 0x3C($s3)
    ctx->pc = 0x164e7cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 60), GPR_U32(ctx, 2));
    // 0x164e80: 0xc04cc90  jal         func_133240
    ctx->pc = 0x164E80u;
    SET_GPR_U32(ctx, 31, 0x164E88u);
    ctx->pc = 0x164E84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164E80u;
            // 0x164e84: 0x27a60010  addiu       $a2, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133240u;
    if (runtime->hasFunction(0x133240u)) {
        auto targetFn = runtime->lookupFunction(0x133240u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164E88u; }
        if (ctx->pc != 0x164E88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133240_0x133240(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164E88u; }
        if (ctx->pc != 0x164E88u) { return; }
    }
    ctx->pc = 0x164E88u;
label_164e88:
    // 0x164e88: 0xafa2000c  sw          $v0, 0xC($sp)
    ctx->pc = 0x164e88u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 2));
label_164e8c:
    // 0x164e8c: 0x8fa2000c  lw          $v0, 0xC($sp)
    ctx->pc = 0x164e8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x164e90: 0x1040001d  beqz        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x164E90u;
    {
        const bool branch_taken_0x164e90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x164E94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164E90u;
            // 0x164e94: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164e90) {
            ctx->pc = 0x164F08u;
            goto label_164f08;
        }
    }
    ctx->pc = 0x164E98u;
    // 0x164e98: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x164e98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x164e9c: 0xc05d518  jal         func_175460
    ctx->pc = 0x164E9Cu;
    SET_GPR_U32(ctx, 31, 0x164EA4u);
    ctx->pc = 0x164EA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164E9Cu;
            // 0x164ea0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164EA4u; }
        if (ctx->pc != 0x164EA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164EA4u; }
        if (ctx->pc != 0x164EA4u) { return; }
    }
    ctx->pc = 0x164EA4u;
label_164ea4:
    // 0x164ea4: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x164EA4u;
    {
        const bool branch_taken_0x164ea4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x164EA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164EA4u;
            // 0x164ea8: 0xafd60000  sw          $s6, 0x0($fp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164ea4) {
            ctx->pc = 0x164F0Cu;
            goto label_164f0c;
        }
    }
    ctx->pc = 0x164EACu;
    // 0x164eac: 0x0  nop
    ctx->pc = 0x164eacu;
    // NOP
label_164eb0:
    // 0x164eb0: 0x8fa20008  lw          $v0, 0x8($sp)
    ctx->pc = 0x164eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x164eb4: 0x10400014  beqz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x164EB4u;
    {
        const bool branch_taken_0x164eb4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x164EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164EB4u;
            // 0x164eb8: 0x32023  negu        $a0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164eb4) {
            ctx->pc = 0x164F08u;
            goto label_164f08;
        }
    }
    ctx->pc = 0x164EBCu;
    // 0x164ebc: 0x2482001f  addiu       $v0, $a0, 0x1F
    ctx->pc = 0x164ebcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 31));
    // 0x164ec0: 0x28830000  slti        $v1, $a0, 0x0
    ctx->pc = 0x164ec0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x164ec4: 0x43200b  movn        $a0, $v0, $v1
    ctx->pc = 0x164ec4u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 2));
    // 0x164ec8: 0x42143  sra         $a0, $a0, 5
    ctx->pc = 0x164ec8u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 5));
    // 0x164ecc: 0x48140  sll         $s0, $a0, 5
    ctx->pc = 0x164eccu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
    // 0x164ed0: 0x5a00000b  blezl       $s0, . + 4 + (0xB << 2)
    ctx->pc = 0x164ED0u;
    {
        const bool branch_taken_0x164ed0 = (GPR_S64(ctx, 16) <= 0);
        if (branch_taken_0x164ed0) {
            ctx->pc = 0x164ED4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x164ED0u;
            // 0x164ed4: 0x3c020016  lui         $v0, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)22 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x164F00u;
            goto label_164f00;
        }
    }
    ctx->pc = 0x164ED8u;
    // 0x164ed8: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x164ed8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164edc: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x164edcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164ee0: 0xc0593f2  jal         func_164FC8
    ctx->pc = 0x164EE0u;
    SET_GPR_U32(ctx, 31, 0x164EE8u);
    ctx->pc = 0x164EE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164EE0u;
            // 0x164ee4: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164FC8u;
    if (runtime->hasFunction(0x164FC8u)) {
        auto targetFn = runtime->lookupFunction(0x164FC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164EE8u; }
        if (ctx->pc != 0x164EE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164FC8_0x164fc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164EE8u; }
        if (ctx->pc != 0x164EE8u) { return; }
    }
    ctx->pc = 0x164EE8u;
label_164ee8:
    // 0x164ee8: 0x8e630038  lw          $v1, 0x38($s3)
    ctx->pc = 0x164ee8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 56)));
    // 0x164eec: 0x2022023  subu        $a0, $s0, $v0
    ctx->pc = 0x164eecu;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x164ef0: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x164ef0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x164ef4: 0x1c800004  bgtz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x164EF4u;
    {
        const bool branch_taken_0x164ef4 = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x164EF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164EF4u;
            // 0x164ef8: 0xae630038  sw          $v1, 0x38($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 56), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164ef4) {
            ctx->pc = 0x164F08u;
            goto label_164f08;
        }
    }
    ctx->pc = 0x164EFCu;
    // 0x164efc: 0x3c020016  lui         $v0, 0x16
    ctx->pc = 0x164efcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)22 << 16));
label_164f00:
    // 0x164f00: 0x24424c28  addiu       $v0, $v0, 0x4C28
    ctx->pc = 0x164f00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19496));
    // 0x164f04: 0xae62003c  sw          $v0, 0x3C($s3)
    ctx->pc = 0x164f04u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 60), GPR_U32(ctx, 2));
label_164f08:
    // 0x164f08: 0xafd60000  sw          $s6, 0x0($fp)
    ctx->pc = 0x164f08u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 22));
label_164f0c:
    // 0x164f0c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x164f0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x164f10: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x164f10u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x164f14: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x164f14u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x164f18: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x164f18u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x164f1c: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x164f1cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x164f20: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x164f20u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x164f24: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x164f24u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x164f28: 0xdfb70058  ld          $s7, 0x58($sp)
    ctx->pc = 0x164f28u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x164f2c: 0xdfbe0060  ld          $fp, 0x60($sp)
    ctx->pc = 0x164f2cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x164f30: 0xdfbf0068  ld          $ra, 0x68($sp)
    ctx->pc = 0x164f30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x164f34: 0x3e00008  jr          $ra
    ctx->pc = 0x164F34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164F38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164F34u;
            // 0x164f38: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164D34u: goto label_164d34;
            case 0x164D48u: goto label_164d48;
            case 0x164D5Cu: goto label_164d5c;
            case 0x164D74u: goto label_164d74;
            case 0x164D78u: goto label_164d78;
            case 0x164D88u: goto label_164d88;
            case 0x164D94u: goto label_164d94;
            case 0x164DB0u: goto label_164db0;
            case 0x164E00u: goto label_164e00;
            case 0x164E2Cu: goto label_164e2c;
            case 0x164E4Cu: goto label_164e4c;
            case 0x164E64u: goto label_164e64;
            case 0x164E88u: goto label_164e88;
            case 0x164E8Cu: goto label_164e8c;
            case 0x164EA4u: goto label_164ea4;
            case 0x164EB0u: goto label_164eb0;
            case 0x164EE8u: goto label_164ee8;
            case 0x164F00u: goto label_164f00;
            case 0x164F08u: goto label_164f08;
            case 0x164F0Cu: goto label_164f0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164F3Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
