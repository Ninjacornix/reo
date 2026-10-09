#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5EC0
// Address: 0x1c5ec0 - 0x1c60c0
void sub_001C5EC0_0x1c5ec0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5EC0_0x1c5ec0");
#endif

    switch (ctx->pc) {
        case 0x1c5f04u: goto label_1c5f04;
        case 0x1c5f18u: goto label_1c5f18;
        case 0x1c5f20u: goto label_1c5f20;
        case 0x1c5fd4u: goto label_1c5fd4;
        case 0x1c6028u: goto label_1c6028;
        default: break;
    }

    ctx->pc = 0x1c5ec0u;

    // 0x1c5ec0: 0x8c860000  lw          $a2, 0x0($a0)
    ctx->pc = 0x1c5ec0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c5ec4: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x1c5ec4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1c5ec8: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x1c5ec8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
    // 0x1c5ecc: 0x3e00008  jr          $ra
    ctx->pc = 0x1C5ECCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C5ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5ECCu;
            // 0x1c5ed0: 0xaca60000  sw          $a2, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C5F04u: goto label_1c5f04;
            case 0x1C5F18u: goto label_1c5f18;
            case 0x1C5F20u: goto label_1c5f20;
            case 0x1C5F64u: goto label_1c5f64;
            case 0x1C5F88u: goto label_1c5f88;
            case 0x1C5F8Cu: goto label_1c5f8c;
            case 0x1C5F94u: goto label_1c5f94;
            case 0x1C5FBCu: goto label_1c5fbc;
            case 0x1C5FD4u: goto label_1c5fd4;
            case 0x1C5FDCu: goto label_1c5fdc;
            case 0x1C5FE4u: goto label_1c5fe4;
            case 0x1C6028u: goto label_1c6028;
            case 0x1C6040u: goto label_1c6040;
            case 0x1C6044u: goto label_1c6044;
            case 0x1C607Cu: goto label_1c607c;
            case 0x1C608Cu: goto label_1c608c;
            case 0x1C60A8u: goto label_1c60a8;
            case 0x1C60ACu: goto label_1c60ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C5ED4u;
    // 0x1c5ed4: 0x0  nop
    ctx->pc = 0x1c5ed4u;
    // NOP
    // 0x1c5ed8: 0x0  nop
    ctx->pc = 0x1c5ed8u;
    // NOP
    // 0x1c5edc: 0x0  nop
    ctx->pc = 0x1c5edcu;
    // NOP
    // 0x1c5ee0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c5ee0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c5ee4: 0x3c050033  lui         $a1, 0x33
    ctx->pc = 0x1c5ee4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)51 << 16));
    // 0x1c5ee8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c5ee8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c5eec: 0x24a58f20  addiu       $a1, $a1, -0x70E0
    ctx->pc = 0x1c5eecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294938400));
    // 0x1c5ef0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c5ef0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c5ef4: 0x24062000  addiu       $a2, $zero, 0x2000
    ctx->pc = 0x1c5ef4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1c5ef8: 0xa48001cc  sh          $zero, 0x1CC($a0)
    ctx->pc = 0x1c5ef8u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 460), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c5efc: 0xc07224c  jal         func_1C8930
    ctx->pc = 0x1C5EFCu;
    SET_GPR_U32(ctx, 31, 0x1C5F04u);
    ctx->pc = 0x1C5F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5EFCu;
            // 0x1c5f00: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8930u;
    if (runtime->hasFunction(0x1C8930u)) {
        auto targetFn = runtime->lookupFunction(0x1C8930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5F04u; }
        if (ctx->pc != 0x1C5F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8930_0x1c8930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5F04u; }
        if (ctx->pc != 0x1C5F04u) { return; }
    }
    ctx->pc = 0x1C5F04u;
label_1c5f04:
    // 0x1c5f04: 0x3c050032  lui         $a1, 0x32
    ctx->pc = 0x1c5f04u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)50 << 16));
    // 0x1c5f08: 0x26040014  addiu       $a0, $s0, 0x14
    ctx->pc = 0x1c5f08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x1c5f0c: 0x24a56f20  addiu       $a1, $a1, 0x6F20
    ctx->pc = 0x1c5f0cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 28448));
    // 0x1c5f10: 0xc07224c  jal         func_1C8930
    ctx->pc = 0x1C5F10u;
    SET_GPR_U32(ctx, 31, 0x1C5F18u);
    ctx->pc = 0x1C5F14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5F10u;
            // 0x1c5f14: 0x24062000  addiu       $a2, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8930u;
    if (runtime->hasFunction(0x1C8930u)) {
        auto targetFn = runtime->lookupFunction(0x1C8930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5F18u; }
        if (ctx->pc != 0x1C5F18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8930_0x1c8930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5F18u; }
        if (ctx->pc != 0x1C5F18u) { return; }
    }
    ctx->pc = 0x1C5F18u;
label_1c5f18:
    // 0x1c5f18: 0xc0720b4  jal         func_1C82D0
    ctx->pc = 0x1C5F18u;
    SET_GPR_U32(ctx, 31, 0x1C5F20u);
    ctx->pc = 0x1C5F1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5F18u;
            // 0x1c5f1c: 0x26040028  addiu       $a0, $s0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C82D0u;
    if (runtime->hasFunction(0x1C82D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C82D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5F20u; }
        if (ctx->pc != 0x1C5F20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C82D0_0x1c82d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5F20u; }
        if (ctx->pc != 0x1C5F20u) { return; }
    }
    ctx->pc = 0x1C5F20u;
label_1c5f20:
    // 0x1c5f20: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c5f20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c5f24: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c5f24u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c5f28: 0x3e00008  jr          $ra
    ctx->pc = 0x1C5F28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C5F2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5F28u;
            // 0x1c5f2c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C5F04u: goto label_1c5f04;
            case 0x1C5F18u: goto label_1c5f18;
            case 0x1C5F20u: goto label_1c5f20;
            case 0x1C5F64u: goto label_1c5f64;
            case 0x1C5F88u: goto label_1c5f88;
            case 0x1C5F8Cu: goto label_1c5f8c;
            case 0x1C5F94u: goto label_1c5f94;
            case 0x1C5FBCu: goto label_1c5fbc;
            case 0x1C5FD4u: goto label_1c5fd4;
            case 0x1C5FDCu: goto label_1c5fdc;
            case 0x1C5FE4u: goto label_1c5fe4;
            case 0x1C6028u: goto label_1c6028;
            case 0x1C6040u: goto label_1c6040;
            case 0x1C6044u: goto label_1c6044;
            case 0x1C607Cu: goto label_1c607c;
            case 0x1C608Cu: goto label_1c608c;
            case 0x1C60A8u: goto label_1c60a8;
            case 0x1C60ACu: goto label_1c60ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C5F30u;
    // 0x1c5f30: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1c5f30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1c5f34: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1c5f34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1c5f38: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c5f38u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c5f3c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c5f3cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c5f40: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1c5f40u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5f44: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c5f44u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c5f48: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1c5f48u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5f4c: 0x8c9001ac  lw          $s0, 0x1AC($a0)
    ctx->pc = 0x1c5f4cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 428)));
    // 0x1c5f50: 0x2625000c  addiu       $a1, $s1, 0xC
    ctx->pc = 0x1c5f50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
    // 0x1c5f54: 0x16200003  bnez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C5F54u;
    {
        const bool branch_taken_0x1c5f54 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C5F58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5F54u;
            // 0x1c5f58: 0x2604000c  addiu       $a0, $s0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5f54) {
            ctx->pc = 0x1C5F64u;
            goto label_1c5f64;
        }
    }
    ctx->pc = 0x1C5F5Cu;
    // 0x1c5f5c: 0x10000052  b           . + 4 + (0x52 << 2)
    ctx->pc = 0x1C5F5Cu;
    {
        const bool branch_taken_0x1c5f5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5F60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5F5Cu;
            // 0x1c5f60: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5f5c) {
            ctx->pc = 0x1C60A8u;
            goto label_1c60a8;
        }
    }
    ctx->pc = 0x1C5F64u;
label_1c5f64:
    // 0x1c5f64: 0x96220000  lhu         $v0, 0x0($s1)
    ctx->pc = 0x1c5f64u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1c5f68: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C5F68u;
    {
        const bool branch_taken_0x1c5f68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5F6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5F68u;
            // 0x1c5f6c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5f68) {
            ctx->pc = 0x1C5F8Cu;
            goto label_1c5f8c;
        }
    }
    ctx->pc = 0x1C5F70u;
    // 0x1c5f70: 0x92280003  lbu         $t0, 0x3($s1)
    ctx->pc = 0x1c5f70u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x1c5f74: 0x11000004  beqz        $t0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C5F74u;
    {
        const bool branch_taken_0x1c5f74 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c5f74) {
            ctx->pc = 0x1C5F88u;
            goto label_1c5f88;
        }
    }
    ctx->pc = 0x1C5F7Cu;
    // 0x1c5f7c: 0x96220008  lhu         $v0, 0x8($s1)
    ctx->pc = 0x1c5f7cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1c5f80: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C5F80u;
    {
        const bool branch_taken_0x1c5f80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c5f80) {
            ctx->pc = 0x1C5F94u;
            goto label_1c5f94;
        }
    }
    ctx->pc = 0x1C5F88u;
label_1c5f88:
    // 0x1c5f88: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c5f88u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c5f8c:
    // 0x1c5f8c: 0x10000047  b           . + 4 + (0x47 << 2)
    ctx->pc = 0x1C5F8Cu;
    {
        const bool branch_taken_0x1c5f8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5F90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5F8Cu;
            // 0x1c5f90: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5f8c) {
            ctx->pc = 0x1C60ACu;
            goto label_1c60ac;
        }
    }
    ctx->pc = 0x1C5F94u;
label_1c5f94:
    // 0x1c5f94: 0x964701b4  lhu         $a3, 0x1B4($s2)
    ctx->pc = 0x1c5f94u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 436)));
    // 0x1c5f98: 0x964301b0  lhu         $v1, 0x1B0($s2)
    ctx->pc = 0x1c5f98u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 432)));
    // 0x1c5f9c: 0x8e4201a8  lw          $v0, 0x1A8($s2)
    ctx->pc = 0x1c5f9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 424)));
    // 0x1c5fa0: 0x2073021  addu        $a2, $s0, $a3
    ctx->pc = 0x1c5fa0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 7)));
    // 0x1c5fa4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c5fa4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c5fa8: 0x46082b  sltu        $at, $v0, $a2
    ctx->pc = 0x1c5fa8u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x1c5fac: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C5FACu;
    {
        const bool branch_taken_0x1c5fac = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5FB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5FACu;
            // 0x1c5fb0: 0x310600ff  andi        $a2, $t0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5fac) {
            ctx->pc = 0x1C5FBCu;
            goto label_1c5fbc;
        }
    }
    ctx->pc = 0x1C5FB4u;
    // 0x1c5fb4: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x1C5FB4u;
    {
        const bool branch_taken_0x1c5fb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5FB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5FB4u;
            // 0x1c5fb8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5fb4) {
            ctx->pc = 0x1C60A8u;
            goto label_1c60a8;
        }
    }
    ctx->pc = 0x1C5FBCu;
label_1c5fbc:
    // 0x1c5fbc: 0x24e2fff4  addiu       $v0, $a3, -0xC
    ctx->pc = 0x1c5fbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967284));
    // 0x1c5fc0: 0x46082a  slt         $at, $v0, $a2
    ctx->pc = 0x1c5fc0u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x1c5fc4: 0x14200005  bnez        $at, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C5FC4u;
    {
        const bool branch_taken_0x1c5fc4 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C5FC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5FC4u;
            // 0x1c5fc8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5fc4) {
            ctx->pc = 0x1C5FDCu;
            goto label_1c5fdc;
        }
    }
    ctx->pc = 0x1C5FCCu;
    // 0x1c5fcc: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C5FCCu;
    SET_GPR_U32(ctx, 31, 0x1C5FD4u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5FD4u; }
        if (ctx->pc != 0x1C5FD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5FD4u; }
        if (ctx->pc != 0x1C5FD4u) { return; }
    }
    ctx->pc = 0x1C5FD4u;
label_1c5fd4:
    // 0x1c5fd4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C5FD4u;
    {
        const bool branch_taken_0x1c5fd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5FD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5FD4u;
            // 0x1c5fd8: 0x96220000  lhu         $v0, 0x0($s1) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5fd4) {
            ctx->pc = 0x1C5FE4u;
            goto label_1c5fe4;
        }
    }
    ctx->pc = 0x1C5FDCu;
label_1c5fdc:
    // 0x1c5fdc: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x1C5FDCu;
    {
        const bool branch_taken_0x1c5fdc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c5fdc) {
            ctx->pc = 0x1C60A8u;
            goto label_1c60a8;
        }
    }
    ctx->pc = 0x1C5FE4u;
label_1c5fe4:
    // 0x1c5fe4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1c5fe4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5fe8: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x1c5fe8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1c5fec: 0x92220002  lbu         $v0, 0x2($s1)
    ctx->pc = 0x1c5fecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1c5ff0: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1c5ff0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c5ff4: 0x92220003  lbu         $v0, 0x3($s1)
    ctx->pc = 0x1c5ff4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x1c5ff8: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1c5ff8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1c5ffc: 0xa2020003  sb          $v0, 0x3($s0)
    ctx->pc = 0x1c5ffcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c6000: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x1c6000u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1c6004: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1c6004u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1c6008: 0x96220008  lhu         $v0, 0x8($s1)
    ctx->pc = 0x1c6008u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1c600c: 0xa6020008  sh          $v0, 0x8($s0)
    ctx->pc = 0x1c600cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1c6010: 0x9222000a  lbu         $v0, 0xA($s1)
    ctx->pc = 0x1c6010u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 10)));
    // 0x1c6014: 0xa202000a  sb          $v0, 0xA($s0)
    ctx->pc = 0x1c6014u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c6018: 0x9222000b  lbu         $v0, 0xB($s1)
    ctx->pc = 0x1c6018u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 11)));
    // 0x1c601c: 0x304200e0  andi        $v0, $v0, 0xE0
    ctx->pc = 0x1c601cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)224);
    // 0x1c6020: 0xc07199c  jal         func_1C6670
    ctx->pc = 0x1C6020u;
    SET_GPR_U32(ctx, 31, 0x1C6028u);
    ctx->pc = 0x1C6024u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6020u;
            // 0x1c6024: 0x305100ff  andi        $s1, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C6670u;
    if (runtime->hasFunction(0x1C6670u)) {
        auto targetFn = runtime->lookupFunction(0x1C6670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6028u; }
        if (ctx->pc != 0x1C6028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C6670_0x1c6670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6028u; }
        if (ctx->pc != 0x1C6028u) { return; }
    }
    ctx->pc = 0x1C6028u;
label_1c6028:
    // 0x1c6028: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1c6028u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1c602c: 0x240200ff  addiu       $v0, $zero, 0xFF
    ctx->pc = 0x1c602cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1c6030: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C6030u;
    {
        const bool branch_taken_0x1c6030 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c6030) {
            ctx->pc = 0x1C6040u;
            goto label_1c6040;
        }
    }
    ctx->pc = 0x1C6038u;
    // 0x1c6038: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C6038u;
    {
        const bool branch_taken_0x1c6038 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C603Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6038u;
            // 0x1c603c: 0x3062001f  andi        $v0, $v1, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)31);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6038) {
            ctx->pc = 0x1C6044u;
            goto label_1c6044;
        }
    }
    ctx->pc = 0x1C6040u;
label_1c6040:
    // 0x1c6040: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c6040u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c6044:
    // 0x1c6044: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1c6044u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1c6048: 0x322200ff  andi        $v0, $s1, 0xFF
    ctx->pc = 0x1c6048u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1c604c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1c604cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1c6050: 0xa202000b  sb          $v0, 0xB($s0)
    ctx->pc = 0x1c6050u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 11), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c6054: 0x964301b4  lhu         $v1, 0x1B4($s2)
    ctx->pc = 0x1c6054u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 436)));
    // 0x1c6058: 0x8e4201ac  lw          $v0, 0x1AC($s2)
    ctx->pc = 0x1c6058u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 428)));
    // 0x1c605c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c605cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c6060: 0xae4201ac  sw          $v0, 0x1AC($s2)
    ctx->pc = 0x1c6060u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 428), GPR_U32(ctx, 2));
    // 0x1c6064: 0x92040003  lbu         $a0, 0x3($s0)
    ctx->pc = 0x1c6064u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1c6068: 0x4810004  bgez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C6068u;
    {
        const bool branch_taken_0x1c6068 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x1C606Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6068u;
            // 0x1c606c: 0x30830003  andi        $v1, $a0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)3);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6068) {
            ctx->pc = 0x1C607Cu;
            goto label_1c607c;
        }
    }
    ctx->pc = 0x1C6070u;
    // 0x1c6070: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C6070u;
    {
        const bool branch_taken_0x1c6070 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c6070) {
            ctx->pc = 0x1C607Cu;
            goto label_1c607c;
        }
    }
    ctx->pc = 0x1C6078u;
    // 0x1c6078: 0x2463fffc  addiu       $v1, $v1, -0x4
    ctx->pc = 0x1c6078u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967292));
label_1c607c:
    // 0x1c607c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C607Cu;
    {
        const bool branch_taken_0x1c607c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C607Cu;
            // 0x1c6080: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c607c) {
            ctx->pc = 0x1C608Cu;
            goto label_1c608c;
        }
    }
    ctx->pc = 0x1C6084u;
    // 0x1c6084: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1c6084u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c6088: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1c6088u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_1c608c:
    // 0x1c608c: 0x8e4301c8  lw          $v1, 0x1C8($s2)
    ctx->pc = 0x1c608cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 456)));
    // 0x1c6090: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c6090u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c6094: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1c6094u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1c6098: 0xae4301c8  sw          $v1, 0x1C8($s2)
    ctx->pc = 0x1c6098u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 456), GPR_U32(ctx, 3));
    // 0x1c609c: 0x924301c4  lbu         $v1, 0x1C4($s2)
    ctx->pc = 0x1c609cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 452)));
    // 0x1c60a0: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1c60a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c60a4: 0xa24301c4  sb          $v1, 0x1C4($s2)
    ctx->pc = 0x1c60a4u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 452), (uint8_t)GPR_U32(ctx, 3));
label_1c60a8:
    // 0x1c60a8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1c60a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1c60ac:
    // 0x1c60ac: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c60acu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c60b0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c60b0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c60b4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c60b4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c60b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C60B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C60BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C60B8u;
            // 0x1c60bc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C5F04u: goto label_1c5f04;
            case 0x1C5F18u: goto label_1c5f18;
            case 0x1C5F20u: goto label_1c5f20;
            case 0x1C5F64u: goto label_1c5f64;
            case 0x1C5F88u: goto label_1c5f88;
            case 0x1C5F8Cu: goto label_1c5f8c;
            case 0x1C5F94u: goto label_1c5f94;
            case 0x1C5FBCu: goto label_1c5fbc;
            case 0x1C5FD4u: goto label_1c5fd4;
            case 0x1C5FDCu: goto label_1c5fdc;
            case 0x1C5FE4u: goto label_1c5fe4;
            case 0x1C6028u: goto label_1c6028;
            case 0x1C6040u: goto label_1c6040;
            case 0x1C6044u: goto label_1c6044;
            case 0x1C607Cu: goto label_1c607c;
            case 0x1C608Cu: goto label_1c608c;
            case 0x1C60A8u: goto label_1c60a8;
            case 0x1C60ACu: goto label_1c60ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C60C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
