#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6E70
// Address: 0x1c6e70 - 0x1c71f0
void sub_001C6E70_0x1c6e70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6E70_0x1c6e70");
#endif

    switch (ctx->pc) {
        case 0x1c6ea0u: goto label_1c6ea0;
        case 0x1c6ec4u: goto label_1c6ec4;
        case 0x1c6eccu: goto label_1c6ecc;
        case 0x1c6edcu: goto label_1c6edc;
        case 0x1c6ef4u: goto label_1c6ef4;
        case 0x1c6f40u: goto label_1c6f40;
        case 0x1c6f94u: goto label_1c6f94;
        case 0x1c6fb4u: goto label_1c6fb4;
        case 0x1c6fbcu: goto label_1c6fbc;
        case 0x1c6fecu: goto label_1c6fec;
        case 0x1c7018u: goto label_1c7018;
        case 0x1c703cu: goto label_1c703c;
        case 0x1c7044u: goto label_1c7044;
        case 0x1c705cu: goto label_1c705c;
        case 0x1c70a8u: goto label_1c70a8;
        case 0x1c70f8u: goto label_1c70f8;
        case 0x1c7100u: goto label_1c7100;
        case 0x1c7114u: goto label_1c7114;
        case 0x1c712cu: goto label_1c712c;
        case 0x1c7134u: goto label_1c7134;
        case 0x1c7148u: goto label_1c7148;
        case 0x1c715cu: goto label_1c715c;
        case 0x1c7164u: goto label_1c7164;
        case 0x1c7178u: goto label_1c7178;
        case 0x1c7184u: goto label_1c7184;
        case 0x1c71a4u: goto label_1c71a4;
        case 0x1c71b0u: goto label_1c71b0;
        default: break;
    }

    ctx->pc = 0x1c6e70u;

    // 0x1c6e70: 0x27bdfe60  addiu       $sp, $sp, -0x1A0
    ctx->pc = 0x1c6e70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966880));
    // 0x1c6e74: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1c6e74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1c6e78: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1c6e78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1c6e7c: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1c6e7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1c6e80: 0x27b600a2  addiu       $s6, $sp, 0xA2
    ctx->pc = 0x1c6e80u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 29), 162));
    // 0x1c6e84: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1c6e84u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1c6e88: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1c6e88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1c6e8c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c6e8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c6e90: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c6e90u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c6e94: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c6e94u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c6e98: 0x100000c2  b           . + 4 + (0xC2 << 2)
    ctx->pc = 0x1C6E98u;
    {
        const bool branch_taken_0x1c6e98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6E9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6E98u;
            // 0x1c6e9c: 0x27b000a3  addiu       $s0, $sp, 0xA3 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 163));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6e98) {
            ctx->pc = 0x1C71A4u;
            goto label_1c71a4;
        }
    }
    ctx->pc = 0x1C6EA0u;
label_1c6ea0:
    // 0x1c6ea0: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C6EA0u;
    {
        const bool branch_taken_0x1c6ea0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6EA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6EA0u;
            // 0x1c6ea4: 0x3c050033  lui         $a1, 0x33 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)51 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6ea0) {
            ctx->pc = 0x1C6EB0u;
            goto label_1c6eb0;
        }
    }
    ctx->pc = 0x1C6EA8u;
    // 0x1c6ea8: 0x100000c4  b           . + 4 + (0xC4 << 2)
    ctx->pc = 0x1C6EA8u;
    {
        const bool branch_taken_0x1c6ea8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6EACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6EA8u;
            // 0x1c6eac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6ea8) {
            ctx->pc = 0x1C71BCu;
            goto label_1c71bc;
        }
    }
    ctx->pc = 0x1C6EB0u;
label_1c6eb0:
    // 0x1c6eb0: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1c6eb0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1c6eb4: 0x24a537b0  addiu       $a1, $a1, 0x37B0
    ctx->pc = 0x1c6eb4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 14256));
    // 0x1c6eb8: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x1c6eb8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6ebc: 0xc071f1c  jal         func_1C7C70
    ctx->pc = 0x1C6EBCu;
    SET_GPR_U32(ctx, 31, 0x1C6EC4u);
    ctx->pc = 0x1C6EC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6EBCu;
            // 0x1c6ec0: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7C70u;
    if (runtime->hasFunction(0x1C7C70u)) {
        auto targetFn = runtime->lookupFunction(0x1C7C70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6EC4u; }
        if (ctx->pc != 0x1C6EC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7C70_0x1c7c70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6EC4u; }
        if (ctx->pc != 0x1C6EC4u) { return; }
    }
    ctx->pc = 0x1C6EC4u;
label_1c6ec4:
    // 0x1c6ec4: 0xc071f5c  jal         func_1C7D70
    ctx->pc = 0x1C6EC4u;
    SET_GPR_U32(ctx, 31, 0x1C6ECCu);
    ctx->pc = 0x1C6EC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6EC4u;
            // 0x1c6ec8: 0x27a40080  addiu       $a0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D70u;
    if (runtime->hasFunction(0x1C7D70u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6ECCu; }
        if (ctx->pc != 0x1C6ECCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D70_0x1c7d70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6ECCu; }
        if (ctx->pc != 0x1C6ECCu) { return; }
    }
    ctx->pc = 0x1C6ECCu;
label_1c6ecc:
    // 0x1c6ecc: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1c6eccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1c6ed0: 0x30540fff  andi        $s4, $v0, 0xFFF
    ctx->pc = 0x1c6ed0u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4095);
    // 0x1c6ed4: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1C6ED4u;
    {
        const bool branch_taken_0x1c6ed4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6ED4u;
            // 0x1c6ed8: 0x26950002  addiu       $s5, $s4, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 20), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6ed4) {
            ctx->pc = 0x1C6F9Cu;
            goto label_1c6f9c;
        }
    }
    ctx->pc = 0x1C6EDCu;
label_1c6edc:
    // 0x1c6edc: 0x10200015  beqz        $at, . + 4 + (0x15 << 2)
    ctx->pc = 0x1C6EDCu;
    {
        const bool branch_taken_0x1c6edc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6EE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6EDCu;
            // 0x1c6ee0: 0x27a40080  addiu       $a0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6edc) {
            ctx->pc = 0x1C6F34u;
            goto label_1c6f34;
        }
    }
    ctx->pc = 0x1C6EE4u;
    // 0x1c6ee4: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x1c6ee4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c6ee8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c6ee8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6eec: 0xc071eb0  jal         func_1C7AC0
    ctx->pc = 0x1C6EECu;
    SET_GPR_U32(ctx, 31, 0x1C6EF4u);
    ctx->pc = 0x1C6EF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6EECu;
            // 0x1c6ef0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7AC0u;
    if (runtime->hasFunction(0x1C7AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6EF4u; }
        if (ctx->pc != 0x1C6EF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7AC0_0x1c7ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6EF4u; }
        if (ctx->pc != 0x1C6EF4u) { return; }
    }
    ctx->pc = 0x1C6EF4u;
label_1c6ef4:
    // 0x1c6ef4: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6ef4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6ef8: 0x24020015  addiu       $v0, $zero, 0x15
    ctx->pc = 0x1c6ef8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1c6efc: 0x942351b8  lhu         $v1, 0x51B8($at)
    ctx->pc = 0x1c6efcu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 20920)));
    // 0x1c6f00: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6f00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6f04: 0xac2251b0  sw          $v0, 0x51B0($at)
    ctx->pc = 0x1c6f04u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 2));
    // 0x1c6f08: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c6f08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c6f0c: 0x8c225f58  lw          $v0, 0x5F58($at)
    ctx->pc = 0x1c6f0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24408)));
    // 0x1c6f10: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1c6f10u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1c6f14: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C6F14u;
    {
        const bool branch_taken_0x1c6f14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C6F18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6F14u;
            // 0x1c6f18: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6f14) {
            ctx->pc = 0x1C6F2Cu;
            goto label_1c6f2c;
        }
    }
    ctx->pc = 0x1C6F1Cu;
    // 0x1c6f1c: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x1c6f1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1c6f20: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6f20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6f24: 0xac2251b0  sw          $v0, 0x51B0($at)
    ctx->pc = 0x1c6f24u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 2));
    // 0x1c6f28: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c6f28u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c6f2c:
    // 0x1c6f2c: 0x100000a4  b           . + 4 + (0xA4 << 2)
    ctx->pc = 0x1C6F2Cu;
    {
        const bool branch_taken_0x1c6f2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6F30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6F2Cu;
            // 0x1c6f30: 0xdfbf0070  ld          $ra, 0x70($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6f2c) {
            ctx->pc = 0x1C71C0u;
            goto label_1c71c0;
        }
    }
    ctx->pc = 0x1C6F34u;
label_1c6f34:
    // 0x1c6f34: 0x27a500a0  addiu       $a1, $sp, 0xA0
    ctx->pc = 0x1c6f34u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1c6f38: 0xc071f50  jal         func_1C7D40
    ctx->pc = 0x1C6F38u;
    SET_GPR_U32(ctx, 31, 0x1C6F40u);
    ctx->pc = 0x1C6F3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6F38u;
            // 0x1c6f3c: 0x2406000c  addiu       $a2, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D40u;
    if (runtime->hasFunction(0x1C7D40u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6F40u; }
        if (ctx->pc != 0x1C6F40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D40_0x1c7d40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6F40u; }
        if (ctx->pc != 0x1C6F40u) { return; }
    }
    ctx->pc = 0x1C6F40u;
label_1c6f40:
    // 0x1c6f40: 0x92110000  lbu         $s1, 0x0($s0)
    ctx->pc = 0x1c6f40u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1c6f44: 0x2694fff4  addiu       $s4, $s4, -0xC
    ctx->pc = 0x1c6f44u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967284));
    // 0x1c6f48: 0x6210004  bgez        $s1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C6F48u;
    {
        const bool branch_taken_0x1c6f48 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x1C6F4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6F48u;
            // 0x1c6f4c: 0x32230003  andi        $v1, $s1, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)3);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6f48) {
            ctx->pc = 0x1C6F5Cu;
            goto label_1c6f5c;
        }
    }
    ctx->pc = 0x1C6F50u;
    // 0x1c6f50: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C6F50u;
    {
        const bool branch_taken_0x1c6f50 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c6f50) {
            ctx->pc = 0x1C6F5Cu;
            goto label_1c6f5c;
        }
    }
    ctx->pc = 0x1C6F58u;
    // 0x1c6f58: 0x2463fffc  addiu       $v1, $v1, -0x4
    ctx->pc = 0x1c6f58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967292));
label_1c6f5c:
    // 0x1c6f5c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C6F5Cu;
    {
        const bool branch_taken_0x1c6f5c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6F60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6F5Cu;
            // 0x1c6f60: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6f5c) {
            ctx->pc = 0x1C6F6Cu;
            goto label_1c6f6c;
        }
    }
    ctx->pc = 0x1C6F64u;
    // 0x1c6f64: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1c6f64u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c6f68: 0x2228821  addu        $s1, $s1, $v0
    ctx->pc = 0x1c6f68u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
label_1c6f6c:
    // 0x1c6f6c: 0x92c30000  lbu         $v1, 0x0($s6)
    ctx->pc = 0x1c6f6cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x1c6f70: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1c6f70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c6f74: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C6F74u;
    {
        const bool branch_taken_0x1c6f74 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c6f74) {
            ctx->pc = 0x1C6F84u;
            goto label_1c6f84;
        }
    }
    ctx->pc = 0x1C6F7Cu;
    // 0x1c6f7c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C6F7Cu;
    {
        const bool branch_taken_0x1c6f7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6F80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6F7Cu;
            // 0x1c6f80: 0x2519021  addu        $s2, $s2, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6f7c) {
            ctx->pc = 0x1C6F88u;
            goto label_1c6f88;
        }
    }
    ctx->pc = 0x1C6F84u;
label_1c6f84:
    // 0x1c6f84: 0x2719821  addu        $s3, $s3, $s1
    ctx->pc = 0x1c6f84u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 17)));
label_1c6f88:
    // 0x1c6f88: 0x2625fff4  addiu       $a1, $s1, -0xC
    ctx->pc = 0x1c6f88u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967284));
    // 0x1c6f8c: 0xc071f7c  jal         func_1C7DF0
    ctx->pc = 0x1C6F8Cu;
    SET_GPR_U32(ctx, 31, 0x1C6F94u);
    ctx->pc = 0x1C6F90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6F8Cu;
            // 0x1c6f90: 0x27a40080  addiu       $a0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7DF0u;
    if (runtime->hasFunction(0x1C7DF0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6F94u; }
        if (ctx->pc != 0x1C6F94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7DF0_0x1c7df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6F94u; }
        if (ctx->pc != 0x1C6F94u) { return; }
    }
    ctx->pc = 0x1C6F94u;
label_1c6f94:
    // 0x1c6f94: 0x2622fff4  addiu       $v0, $s1, -0xC
    ctx->pc = 0x1c6f94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967284));
    // 0x1c6f98: 0x282a023  subu        $s4, $s4, $v0
    ctx->pc = 0x1c6f98u;
    SET_GPR_S32(ctx, 20, (int32_t)SUB32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
label_1c6f9c:
    // 0x1c6f9c: 0x1680ffcf  bnez        $s4, . + 4 + (-0x31 << 2)
    ctx->pc = 0x1C6F9Cu;
    {
        const bool branch_taken_0x1c6f9c = (GPR_U64(ctx, 20) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C6FA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6F9Cu;
            // 0x1c6fa0: 0x2a81000d  slti        $at, $s4, 0xD (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 20) < (int64_t)(int32_t)13) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6f9c) {
            ctx->pc = 0x1C6EDCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c6edc;
        }
    }
    ctx->pc = 0x1C6FA4u;
    // 0x1c6fa4: 0x3c050033  lui         $a1, 0x33
    ctx->pc = 0x1c6fa4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)51 << 16));
    // 0x1c6fa8: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1c6fa8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1c6fac: 0xc071f1c  jal         func_1C7C70
    ctx->pc = 0x1C6FACu;
    SET_GPR_U32(ctx, 31, 0x1C6FB4u);
    ctx->pc = 0x1C6FB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6FACu;
            // 0x1c6fb0: 0x24a537b0  addiu       $a1, $a1, 0x37B0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 14256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7C70u;
    if (runtime->hasFunction(0x1C7C70u)) {
        auto targetFn = runtime->lookupFunction(0x1C7C70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6FB4u; }
        if (ctx->pc != 0x1C6FB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7C70_0x1c7c70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6FB4u; }
        if (ctx->pc != 0x1C6FB4u) { return; }
    }
    ctx->pc = 0x1C6FB4u;
label_1c6fb4:
    // 0x1c6fb4: 0xc071f5c  jal         func_1C7D70
    ctx->pc = 0x1C6FB4u;
    SET_GPR_U32(ctx, 31, 0x1C6FBCu);
    ctx->pc = 0x1C6FB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6FB4u;
            // 0x1c6fb8: 0x27a40080  addiu       $a0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D70u;
    if (runtime->hasFunction(0x1C7D70u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6FBCu; }
        if (ctx->pc != 0x1C6FBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D70_0x1c7d70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6FBCu; }
        if (ctx->pc != 0x1C6FBCu) { return; }
    }
    ctx->pc = 0x1C6FBCu;
label_1c6fbc:
    // 0x1c6fbc: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1c6fbcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1c6fc0: 0x1240000a  beqz        $s2, . + 4 + (0xA << 2)
    ctx->pc = 0x1C6FC0u;
    {
        const bool branch_taken_0x1c6fc0 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6FC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6FC0u;
            // 0x1c6fc4: 0x30510fff  andi        $s1, $v0, 0xFFF (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4095);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6fc0) {
            ctx->pc = 0x1C6FECu;
            goto label_1c6fec;
        }
    }
    ctx->pc = 0x1C6FC8u;
    // 0x1c6fc8: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6fc8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6fcc: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c6fccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c6fd0: 0x90235054  lbu         $v1, 0x5054($at)
    ctx->pc = 0x1c6fd0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20564)));
    // 0x1c6fd4: 0x32420fff  andi        $v0, $s2, 0xFFF
    ctx->pc = 0x1c6fd4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)4095);
    // 0x1c6fd8: 0x24843ff0  addiu       $a0, $a0, 0x3FF0
    ctx->pc = 0x1c6fd8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16368));
    // 0x1c6fdc: 0x31b00  sll         $v1, $v1, 12
    ctx->pc = 0x1c6fdcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 12));
    // 0x1c6fe0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1c6fe0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1c6fe4: 0xc071f54  jal         func_1C7D50
    ctx->pc = 0x1C6FE4u;
    SET_GPR_U32(ctx, 31, 0x1C6FECu);
    ctx->pc = 0x1C6FE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6FE4u;
            // 0x1c6fe8: 0x3045ffff  andi        $a1, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D50u;
    if (runtime->hasFunction(0x1C7D50u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6FECu; }
        if (ctx->pc != 0x1C6FECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D50_0x1c7d50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6FECu; }
        if (ctx->pc != 0x1C6FECu) { return; }
    }
    ctx->pc = 0x1C6FECu;
label_1c6fec:
    // 0x1c6fec: 0x1260000a  beqz        $s3, . + 4 + (0xA << 2)
    ctx->pc = 0x1C6FECu;
    {
        const bool branch_taken_0x1c6fec = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c6fec) {
            ctx->pc = 0x1C7018u;
            goto label_1c7018;
        }
    }
    ctx->pc = 0x1C6FF4u;
    // 0x1c6ff4: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6ff4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6ff8: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c6ff8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c6ffc: 0x90235054  lbu         $v1, 0x5054($at)
    ctx->pc = 0x1c6ffcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20564)));
    // 0x1c7000: 0x32620fff  andi        $v0, $s3, 0xFFF
    ctx->pc = 0x1c7000u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)4095);
    // 0x1c7004: 0x24843bd0  addiu       $a0, $a0, 0x3BD0
    ctx->pc = 0x1c7004u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15312));
    // 0x1c7008: 0x31b00  sll         $v1, $v1, 12
    ctx->pc = 0x1c7008u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 12));
    // 0x1c700c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1c700cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1c7010: 0xc071f54  jal         func_1C7D50
    ctx->pc = 0x1C7010u;
    SET_GPR_U32(ctx, 31, 0x1C7018u);
    ctx->pc = 0x1C7014u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7010u;
            // 0x1c7014: 0x3045ffff  andi        $a1, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D50u;
    if (runtime->hasFunction(0x1C7D50u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7018u; }
        if (ctx->pc != 0x1C7018u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D50_0x1c7d50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7018u; }
        if (ctx->pc != 0x1C7018u) { return; }
    }
    ctx->pc = 0x1C7018u;
label_1c7018:
    // 0x1c7018: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7018u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c701c: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c701cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c7020: 0x90235054  lbu         $v1, 0x5054($at)
    ctx->pc = 0x1c7020u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20564)));
    // 0x1c7024: 0x32220fff  andi        $v0, $s1, 0xFFF
    ctx->pc = 0x1c7024u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)4095);
    // 0x1c7028: 0x24842f90  addiu       $a0, $a0, 0x2F90
    ctx->pc = 0x1c7028u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12176));
    // 0x1c702c: 0x31b00  sll         $v1, $v1, 12
    ctx->pc = 0x1c702cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 12));
    // 0x1c7030: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1c7030u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1c7034: 0xc071f54  jal         func_1C7D50
    ctx->pc = 0x1C7034u;
    SET_GPR_U32(ctx, 31, 0x1C703Cu);
    ctx->pc = 0x1C7038u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7034u;
            // 0x1c7038: 0x3045ffff  andi        $a1, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D50u;
    if (runtime->hasFunction(0x1C7D50u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C703Cu; }
        if (ctx->pc != 0x1C703Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D50_0x1c7d50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C703Cu; }
        if (ctx->pc != 0x1C703Cu) { return; }
    }
    ctx->pc = 0x1C703Cu;
label_1c703c:
    // 0x1c703c: 0x10000053  b           . + 4 + (0x53 << 2)
    ctx->pc = 0x1C703Cu;
    {
        const bool branch_taken_0x1c703c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c703c) {
            ctx->pc = 0x1C718Cu;
            goto label_1c718c;
        }
    }
    ctx->pc = 0x1C7044u;
label_1c7044:
    // 0x1c7044: 0x10200015  beqz        $at, . + 4 + (0x15 << 2)
    ctx->pc = 0x1C7044u;
    {
        const bool branch_taken_0x1c7044 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7048u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7044u;
            // 0x1c7048: 0x27a40080  addiu       $a0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7044) {
            ctx->pc = 0x1C709Cu;
            goto label_1c709c;
        }
    }
    ctx->pc = 0x1C704Cu;
    // 0x1c704c: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x1c704cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c7050: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c7050u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7054: 0xc071eb0  jal         func_1C7AC0
    ctx->pc = 0x1C7054u;
    SET_GPR_U32(ctx, 31, 0x1C705Cu);
    ctx->pc = 0x1C7058u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7054u;
            // 0x1c7058: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7AC0u;
    if (runtime->hasFunction(0x1C7AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C705Cu; }
        if (ctx->pc != 0x1C705Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7AC0_0x1c7ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C705Cu; }
        if (ctx->pc != 0x1C705Cu) { return; }
    }
    ctx->pc = 0x1C705Cu;
label_1c705c:
    // 0x1c705c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c705cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7060: 0x24020015  addiu       $v0, $zero, 0x15
    ctx->pc = 0x1c7060u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1c7064: 0x942351b8  lhu         $v1, 0x51B8($at)
    ctx->pc = 0x1c7064u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 20920)));
    // 0x1c7068: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7068u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c706c: 0xac2251b0  sw          $v0, 0x51B0($at)
    ctx->pc = 0x1c706cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 2));
    // 0x1c7070: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c7070u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c7074: 0x8c225f58  lw          $v0, 0x5F58($at)
    ctx->pc = 0x1c7074u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24408)));
    // 0x1c7078: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1c7078u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1c707c: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C707Cu;
    {
        const bool branch_taken_0x1c707c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C7080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C707Cu;
            // 0x1c7080: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c707c) {
            ctx->pc = 0x1C7094u;
            goto label_1c7094;
        }
    }
    ctx->pc = 0x1C7084u;
    // 0x1c7084: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x1c7084u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1c7088: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7088u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c708c: 0xac2251b0  sw          $v0, 0x51B0($at)
    ctx->pc = 0x1c708cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 2));
    // 0x1c7090: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c7090u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c7094:
    // 0x1c7094: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x1C7094u;
    {
        const bool branch_taken_0x1c7094 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c7094) {
            ctx->pc = 0x1C71BCu;
            goto label_1c71bc;
        }
    }
    ctx->pc = 0x1C709Cu;
label_1c709c:
    // 0x1c709c: 0x27a500a0  addiu       $a1, $sp, 0xA0
    ctx->pc = 0x1c709cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1c70a0: 0xc071f50  jal         func_1C7D40
    ctx->pc = 0x1C70A0u;
    SET_GPR_U32(ctx, 31, 0x1C70A8u);
    ctx->pc = 0x1C70A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C70A0u;
            // 0x1c70a4: 0x2406000c  addiu       $a2, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D40u;
    if (runtime->hasFunction(0x1C7D40u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C70A8u; }
        if (ctx->pc != 0x1C70A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D40_0x1c7d40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C70A8u; }
        if (ctx->pc != 0x1C70A8u) { return; }
    }
    ctx->pc = 0x1C70A8u;
label_1c70a8:
    // 0x1c70a8: 0x92120000  lbu         $s2, 0x0($s0)
    ctx->pc = 0x1c70a8u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1c70ac: 0x2631fff4  addiu       $s1, $s1, -0xC
    ctx->pc = 0x1c70acu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967284));
    // 0x1c70b0: 0x6410004  bgez        $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C70B0u;
    {
        const bool branch_taken_0x1c70b0 = (GPR_S64(ctx, 18) >= 0);
        ctx->pc = 0x1C70B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C70B0u;
            // 0x1c70b4: 0x32430003  andi        $v1, $s2, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)3);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c70b0) {
            ctx->pc = 0x1C70C4u;
            goto label_1c70c4;
        }
    }
    ctx->pc = 0x1C70B8u;
    // 0x1c70b8: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C70B8u;
    {
        const bool branch_taken_0x1c70b8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c70b8) {
            ctx->pc = 0x1C70C4u;
            goto label_1c70c4;
        }
    }
    ctx->pc = 0x1C70C0u;
    // 0x1c70c0: 0x2463fffc  addiu       $v1, $v1, -0x4
    ctx->pc = 0x1c70c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967292));
label_1c70c4:
    // 0x1c70c4: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C70C4u;
    {
        const bool branch_taken_0x1c70c4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C70C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C70C4u;
            // 0x1c70c8: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c70c4) {
            ctx->pc = 0x1C70D4u;
            goto label_1c70d4;
        }
    }
    ctx->pc = 0x1C70CCu;
    // 0x1c70cc: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1c70ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c70d0: 0x2429021  addu        $s2, $s2, $v0
    ctx->pc = 0x1c70d0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
label_1c70d4:
    // 0x1c70d4: 0x92c30000  lbu         $v1, 0x0($s6)
    ctx->pc = 0x1c70d4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x1c70d8: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1c70d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c70dc: 0x1062000f  beq         $v1, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1C70DCu;
    {
        const bool branch_taken_0x1c70dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C70E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C70DCu;
            // 0x1c70e0: 0x3c040033  lui         $a0, 0x33 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c70dc) {
            ctx->pc = 0x1C711Cu;
            goto label_1c711c;
        }
    }
    ctx->pc = 0x1C70E4u;
    // 0x1c70e4: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c70e4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c70e8: 0x27a500a0  addiu       $a1, $sp, 0xA0
    ctx->pc = 0x1c70e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1c70ec: 0x24843ff0  addiu       $a0, $a0, 0x3FF0
    ctx->pc = 0x1c70ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16368));
    // 0x1c70f0: 0xc071f4c  jal         func_1C7D30
    ctx->pc = 0x1C70F0u;
    SET_GPR_U32(ctx, 31, 0x1C70F8u);
    ctx->pc = 0x1C70F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C70F0u;
            // 0x1c70f4: 0x2406000c  addiu       $a2, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D30u;
    if (runtime->hasFunction(0x1C7D30u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C70F8u; }
        if (ctx->pc != 0x1C70F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D30_0x1c7d30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C70F8u; }
        if (ctx->pc != 0x1C70F8u) { return; }
    }
    ctx->pc = 0x1C70F8u;
label_1c70f8:
    // 0x1c70f8: 0xc071f30  jal         func_1C7CC0
    ctx->pc = 0x1C70F8u;
    SET_GPR_U32(ctx, 31, 0x1C7100u);
    ctx->pc = 0x1C70FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C70F8u;
            // 0x1c70fc: 0x27a40080  addiu       $a0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7CC0u;
    if (runtime->hasFunction(0x1C7CC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7100u; }
        if (ctx->pc != 0x1C7100u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7CC0_0x1c7cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7100u; }
        if (ctx->pc != 0x1C7100u) { return; }
    }
    ctx->pc = 0x1C7100u;
label_1c7100:
    // 0x1c7100: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c7100u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c7104: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1c7104u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7108: 0x2646fff4  addiu       $a2, $s2, -0xC
    ctx->pc = 0x1c7108u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967284));
    // 0x1c710c: 0xc071f4c  jal         func_1C7D30
    ctx->pc = 0x1C710Cu;
    SET_GPR_U32(ctx, 31, 0x1C7114u);
    ctx->pc = 0x1C7110u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C710Cu;
            // 0x1c7110: 0x24843ff0  addiu       $a0, $a0, 0x3FF0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16368));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D30u;
    if (runtime->hasFunction(0x1C7D30u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7114u; }
        if (ctx->pc != 0x1C7114u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D30_0x1c7d30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7114u; }
        if (ctx->pc != 0x1C7114u) { return; }
    }
    ctx->pc = 0x1C7114u;
label_1c7114:
    // 0x1c7114: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1C7114u;
    {
        const bool branch_taken_0x1c7114 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c7114) {
            ctx->pc = 0x1C7148u;
            goto label_1c7148;
        }
    }
    ctx->pc = 0x1C711Cu;
label_1c711c:
    // 0x1c711c: 0x27a500a0  addiu       $a1, $sp, 0xA0
    ctx->pc = 0x1c711cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1c7120: 0x24843bd0  addiu       $a0, $a0, 0x3BD0
    ctx->pc = 0x1c7120u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15312));
    // 0x1c7124: 0xc071f4c  jal         func_1C7D30
    ctx->pc = 0x1C7124u;
    SET_GPR_U32(ctx, 31, 0x1C712Cu);
    ctx->pc = 0x1C7128u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7124u;
            // 0x1c7128: 0x2406000c  addiu       $a2, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D30u;
    if (runtime->hasFunction(0x1C7D30u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C712Cu; }
        if (ctx->pc != 0x1C712Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D30_0x1c7d30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C712Cu; }
        if (ctx->pc != 0x1C712Cu) { return; }
    }
    ctx->pc = 0x1C712Cu;
label_1c712c:
    // 0x1c712c: 0xc071f30  jal         func_1C7CC0
    ctx->pc = 0x1C712Cu;
    SET_GPR_U32(ctx, 31, 0x1C7134u);
    ctx->pc = 0x1C7130u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C712Cu;
            // 0x1c7130: 0x27a40080  addiu       $a0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7CC0u;
    if (runtime->hasFunction(0x1C7CC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7134u; }
        if (ctx->pc != 0x1C7134u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7CC0_0x1c7cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7134u; }
        if (ctx->pc != 0x1C7134u) { return; }
    }
    ctx->pc = 0x1C7134u;
label_1c7134:
    // 0x1c7134: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c7134u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c7138: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1c7138u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c713c: 0x2646fff4  addiu       $a2, $s2, -0xC
    ctx->pc = 0x1c713cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967284));
    // 0x1c7140: 0xc071f4c  jal         func_1C7D30
    ctx->pc = 0x1C7140u;
    SET_GPR_U32(ctx, 31, 0x1C7148u);
    ctx->pc = 0x1C7144u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7140u;
            // 0x1c7144: 0x24843bd0  addiu       $a0, $a0, 0x3BD0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15312));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D30u;
    if (runtime->hasFunction(0x1C7D30u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7148u; }
        if (ctx->pc != 0x1C7148u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D30_0x1c7d30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7148u; }
        if (ctx->pc != 0x1C7148u) { return; }
    }
    ctx->pc = 0x1C7148u;
label_1c7148:
    // 0x1c7148: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c7148u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c714c: 0x27a500a0  addiu       $a1, $sp, 0xA0
    ctx->pc = 0x1c714cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1c7150: 0x24842f90  addiu       $a0, $a0, 0x2F90
    ctx->pc = 0x1c7150u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12176));
    // 0x1c7154: 0xc071f4c  jal         func_1C7D30
    ctx->pc = 0x1C7154u;
    SET_GPR_U32(ctx, 31, 0x1C715Cu);
    ctx->pc = 0x1C7158u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7154u;
            // 0x1c7158: 0x2406000c  addiu       $a2, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D30u;
    if (runtime->hasFunction(0x1C7D30u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C715Cu; }
        if (ctx->pc != 0x1C715Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D30_0x1c7d30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C715Cu; }
        if (ctx->pc != 0x1C715Cu) { return; }
    }
    ctx->pc = 0x1C715Cu;
label_1c715c:
    // 0x1c715c: 0xc071f30  jal         func_1C7CC0
    ctx->pc = 0x1C715Cu;
    SET_GPR_U32(ctx, 31, 0x1C7164u);
    ctx->pc = 0x1C7160u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C715Cu;
            // 0x1c7160: 0x27a40080  addiu       $a0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7CC0u;
    if (runtime->hasFunction(0x1C7CC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7164u; }
        if (ctx->pc != 0x1C7164u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7CC0_0x1c7cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7164u; }
        if (ctx->pc != 0x1C7164u) { return; }
    }
    ctx->pc = 0x1C7164u;
label_1c7164:
    // 0x1c7164: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c7164u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c7168: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1c7168u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c716c: 0x2646fff4  addiu       $a2, $s2, -0xC
    ctx->pc = 0x1c716cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967284));
    // 0x1c7170: 0xc071f4c  jal         func_1C7D30
    ctx->pc = 0x1C7170u;
    SET_GPR_U32(ctx, 31, 0x1C7178u);
    ctx->pc = 0x1C7174u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7170u;
            // 0x1c7174: 0x24842f90  addiu       $a0, $a0, 0x2F90 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D30u;
    if (runtime->hasFunction(0x1C7D30u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7178u; }
        if (ctx->pc != 0x1C7178u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D30_0x1c7d30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7178u; }
        if (ctx->pc != 0x1C7178u) { return; }
    }
    ctx->pc = 0x1C7178u;
label_1c7178:
    // 0x1c7178: 0x2645fff4  addiu       $a1, $s2, -0xC
    ctx->pc = 0x1c7178u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967284));
    // 0x1c717c: 0xc071f7c  jal         func_1C7DF0
    ctx->pc = 0x1C717Cu;
    SET_GPR_U32(ctx, 31, 0x1C7184u);
    ctx->pc = 0x1C7180u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C717Cu;
            // 0x1c7180: 0x27a40080  addiu       $a0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7DF0u;
    if (runtime->hasFunction(0x1C7DF0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7184u; }
        if (ctx->pc != 0x1C7184u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7DF0_0x1c7df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7184u; }
        if (ctx->pc != 0x1C7184u) { return; }
    }
    ctx->pc = 0x1C7184u;
label_1c7184:
    // 0x1c7184: 0x2642fff4  addiu       $v0, $s2, -0xC
    ctx->pc = 0x1c7184u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967284));
    // 0x1c7188: 0x2228823  subu        $s1, $s1, $v0
    ctx->pc = 0x1c7188u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
label_1c718c:
    // 0x1c718c: 0x1620ffad  bnez        $s1, . + 4 + (-0x53 << 2)
    ctx->pc = 0x1C718Cu;
    {
        const bool branch_taken_0x1c718c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C7190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C718Cu;
            // 0x1c7190: 0x2a21000d  slti        $at, $s1, 0xD (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)13) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c718c) {
            ctx->pc = 0x1C7044u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c7044;
        }
    }
    ctx->pc = 0x1C7194u;
    // 0x1c7194: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c7194u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c7198: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x1c7198u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c719c: 0xc071f60  jal         func_1C7D80
    ctx->pc = 0x1C719Cu;
    SET_GPR_U32(ctx, 31, 0x1C71A4u);
    ctx->pc = 0x1C71A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C719Cu;
            // 0x1c71a0: 0x248437b0  addiu       $a0, $a0, 0x37B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D80u;
    if (runtime->hasFunction(0x1C7D80u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C71A4u; }
        if (ctx->pc != 0x1C71A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D80_0x1c7d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C71A4u; }
        if (ctx->pc != 0x1C71A4u) { return; }
    }
    ctx->pc = 0x1C71A4u;
label_1c71a4:
    // 0x1c71a4: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c71a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c71a8: 0xc071f24  jal         func_1C7C90
    ctx->pc = 0x1C71A8u;
    SET_GPR_U32(ctx, 31, 0x1C71B0u);
    ctx->pc = 0x1C71ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C71A8u;
            // 0x1c71ac: 0x248437b0  addiu       $a0, $a0, 0x37B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7C90u;
    if (runtime->hasFunction(0x1C7C90u)) {
        auto targetFn = runtime->lookupFunction(0x1C7C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C71B0u; }
        if (ctx->pc != 0x1C71B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7C90_0x1c7c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C71B0u; }
        if (ctx->pc != 0x1C71B0u) { return; }
    }
    ctx->pc = 0x1C71B0u;
label_1c71b0:
    // 0x1c71b0: 0x1440ff3b  bnez        $v0, . + 4 + (-0xC5 << 2)
    ctx->pc = 0x1C71B0u;
    {
        const bool branch_taken_0x1c71b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C71B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C71B0u;
            // 0x1c71b4: 0x28410002  slti        $at, $v0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c71b0) {
            ctx->pc = 0x1C6EA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c6ea0;
        }
    }
    ctx->pc = 0x1C71B8u;
    // 0x1c71b8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c71b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1c71bc:
    // 0x1c71bc: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1c71bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
label_1c71c0:
    // 0x1c71c0: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1c71c0u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1c71c4: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1c71c4u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1c71c8: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1c71c8u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1c71cc: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1c71ccu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c71d0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c71d0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c71d4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c71d4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c71d8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c71d8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c71dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1C71DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C71E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C71DCu;
            // 0x1c71e0: 0x27bd01a0  addiu       $sp, $sp, 0x1A0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 416));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6EA0u: goto label_1c6ea0;
            case 0x1C6EB0u: goto label_1c6eb0;
            case 0x1C6EC4u: goto label_1c6ec4;
            case 0x1C6ECCu: goto label_1c6ecc;
            case 0x1C6EDCu: goto label_1c6edc;
            case 0x1C6EF4u: goto label_1c6ef4;
            case 0x1C6F2Cu: goto label_1c6f2c;
            case 0x1C6F34u: goto label_1c6f34;
            case 0x1C6F40u: goto label_1c6f40;
            case 0x1C6F5Cu: goto label_1c6f5c;
            case 0x1C6F6Cu: goto label_1c6f6c;
            case 0x1C6F84u: goto label_1c6f84;
            case 0x1C6F88u: goto label_1c6f88;
            case 0x1C6F94u: goto label_1c6f94;
            case 0x1C6F9Cu: goto label_1c6f9c;
            case 0x1C6FB4u: goto label_1c6fb4;
            case 0x1C6FBCu: goto label_1c6fbc;
            case 0x1C6FECu: goto label_1c6fec;
            case 0x1C7018u: goto label_1c7018;
            case 0x1C703Cu: goto label_1c703c;
            case 0x1C7044u: goto label_1c7044;
            case 0x1C705Cu: goto label_1c705c;
            case 0x1C7094u: goto label_1c7094;
            case 0x1C709Cu: goto label_1c709c;
            case 0x1C70A8u: goto label_1c70a8;
            case 0x1C70C4u: goto label_1c70c4;
            case 0x1C70D4u: goto label_1c70d4;
            case 0x1C70F8u: goto label_1c70f8;
            case 0x1C7100u: goto label_1c7100;
            case 0x1C7114u: goto label_1c7114;
            case 0x1C711Cu: goto label_1c711c;
            case 0x1C712Cu: goto label_1c712c;
            case 0x1C7134u: goto label_1c7134;
            case 0x1C7148u: goto label_1c7148;
            case 0x1C715Cu: goto label_1c715c;
            case 0x1C7164u: goto label_1c7164;
            case 0x1C7178u: goto label_1c7178;
            case 0x1C7184u: goto label_1c7184;
            case 0x1C718Cu: goto label_1c718c;
            case 0x1C71A4u: goto label_1c71a4;
            case 0x1C71B0u: goto label_1c71b0;
            case 0x1C71BCu: goto label_1c71bc;
            case 0x1C71C0u: goto label_1c71c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C71E4u;
    // 0x1c71e4: 0x0  nop
    ctx->pc = 0x1c71e4u;
    // NOP
    // 0x1c71e8: 0x0  nop
    ctx->pc = 0x1c71e8u;
    // NOP
    // 0x1c71ec: 0x0  nop
    ctx->pc = 0x1c71ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
