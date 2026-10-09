#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BDA10
// Address: 0x1bda10 - 0x1bdae0
void sub_001BDA10_0x1bda10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BDA10_0x1bda10");
#endif

    switch (ctx->pc) {
        case 0x1bda24u: goto label_1bda24;
        case 0x1bda34u: goto label_1bda34;
        case 0x1bda54u: goto label_1bda54;
        case 0x1bda70u: goto label_1bda70;
        default: break;
    }

    ctx->pc = 0x1bda10u;

    // 0x1bda10: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1bda10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1bda14: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bda14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bda18: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bda18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bda1c: 0xc06f504  jal         func_1BD410
    ctx->pc = 0x1BDA1Cu;
    SET_GPR_U32(ctx, 31, 0x1BDA24u);
    ctx->pc = 0x1BDA20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDA1Cu;
            // 0x1bda20: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BD410u;
    if (runtime->hasFunction(0x1BD410u)) {
        auto targetFn = runtime->lookupFunction(0x1BD410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDA24u; }
        if (ctx->pc != 0x1BDA24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD410_0x1bd410(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDA24u; }
        if (ctx->pc != 0x1BDA24u) { return; }
    }
    ctx->pc = 0x1BDA24u;
label_1bda24:
    // 0x1bda24: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BDA24u;
    {
        const bool branch_taken_0x1bda24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BDA28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDA24u;
            // 0x1bda28: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bda24) {
            ctx->pc = 0x1BDA3Cu;
            goto label_1bda3c;
        }
    }
    ctx->pc = 0x1BDA2Cu;
    // 0x1bda2c: 0xc06f660  jal         func_1BD980
    ctx->pc = 0x1BDA2Cu;
    SET_GPR_U32(ctx, 31, 0x1BDA34u);
    ctx->pc = 0x1BDA30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDA2Cu;
            // 0x1bda30: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BD980u;
    if (runtime->hasFunction(0x1BD980u)) {
        auto targetFn = runtime->lookupFunction(0x1BD980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDA34u; }
        if (ctx->pc != 0x1BDA34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD980_0x1bd980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDA34u; }
        if (ctx->pc != 0x1BDA34u) { return; }
    }
    ctx->pc = 0x1BDA34u;
label_1bda34:
    // 0x1bda34: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x1BDA34u;
    {
        const bool branch_taken_0x1bda34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BDA38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDA34u;
            // 0x1bda38: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bda34) {
            ctx->pc = 0x1BDAD4u;
            goto label_1bdad4;
        }
    }
    ctx->pc = 0x1BDA3Cu;
label_1bda3c:
    // 0x1bda3c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bda3cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bda40: 0x3c080023  lui         $t0, 0x23
    ctx->pc = 0x1bda40u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)35 << 16));
    // 0x1bda44: 0xac204868  sw          $zero, 0x4868($at)
    ctx->pc = 0x1bda44u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 18536), GPR_U32(ctx, 0));
    // 0x1bda48: 0x25084f90  addiu       $t0, $t0, 0x4F90
    ctx->pc = 0x1bda48u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 20368));
    // 0x1bda4c: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1bda4cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1bda50: 0x24844520  addiu       $a0, $a0, 0x4520
    ctx->pc = 0x1bda50u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17696));
label_1bda54:
    // 0x1bda54: 0x8d070000  lw          $a3, 0x0($t0)
    ctx->pc = 0x1bda54u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1bda58: 0x14e00004  bnez        $a3, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BDA58u;
    {
        const bool branch_taken_0x1bda58 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BDA5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDA58u;
            // 0x1bda5c: 0x25080004  addiu       $t0, $t0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bda58) {
            ctx->pc = 0x1BDA6Cu;
            goto label_1bda6c;
        }
    }
    ctx->pc = 0x1BDA60u;
    // 0x1bda60: 0x2403fffd  addiu       $v1, $zero, -0x3
    ctx->pc = 0x1bda60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
    // 0x1bda64: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1BDA64u;
    {
        const bool branch_taken_0x1bda64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BDA68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDA64u;
            // 0x1bda68: 0xae030008  sw          $v1, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bda64) {
            ctx->pc = 0x1BDAD0u;
            goto label_1bdad0;
        }
    }
    ctx->pc = 0x1BDA6Cu;
label_1bda6c:
    // 0x1bda6c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1bda6cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1bda70:
    // 0x1bda70: 0x80e50000  lb          $a1, 0x0($a3)
    ctx->pc = 0x1bda70u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1bda74: 0x4a00009  bltz        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1BDA74u;
    {
        const bool branch_taken_0x1bda74 = (GPR_S64(ctx, 5) < 0);
        ctx->pc = 0x1BDA78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDA74u;
            // 0x1bda78: 0x24e70001  addiu       $a3, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bda74) {
            ctx->pc = 0x1BDA9Cu;
            goto label_1bda9c;
        }
    }
    ctx->pc = 0x1BDA7Cu;
    // 0x1bda7c: 0x61940  sll         $v1, $a2, 5
    ctx->pc = 0x1bda7cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 5));
    // 0x1bda80: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1bda80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1bda84: 0x8c630008  lw          $v1, 0x8($v1)
    ctx->pc = 0x1bda84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1bda88: 0x65082b  sltu        $at, $v1, $a1
    ctx->pc = 0x1bda88u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x1bda8c: 0x14200004  bnez        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BDA8Cu;
    {
        const bool branch_taken_0x1bda8c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BDA90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDA8Cu;
            // 0x1bda90: 0x24c3ffff  addiu       $v1, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bda8c) {
            ctx->pc = 0x1BDAA0u;
            goto label_1bdaa0;
        }
    }
    ctx->pc = 0x1BDA94u;
    // 0x1bda94: 0x1000fff6  b           . + 4 + (-0xA << 2)
    ctx->pc = 0x1BDA94u;
    {
        const bool branch_taken_0x1bda94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BDA98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDA94u;
            // 0x1bda98: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bda94) {
            ctx->pc = 0x1BDA70u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bda70;
        }
    }
    ctx->pc = 0x1BDA9Cu;
label_1bda9c:
    // 0x1bda9c: 0x24c3ffff  addiu       $v1, $a2, -0x1
    ctx->pc = 0x1bda9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
label_1bdaa0:
    // 0x1bdaa0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bdaa0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bdaa4: 0x4a00007  bltz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1BDAA4u;
    {
        const bool branch_taken_0x1bdaa4 = (GPR_S64(ctx, 5) < 0);
        ctx->pc = 0x1BDAA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDAA4u;
            // 0x1bdaa8: 0xac234860  sw          $v1, 0x4860($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 18528), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdaa4) {
            ctx->pc = 0x1BDAC4u;
            goto label_1bdac4;
        }
    }
    ctx->pc = 0x1BDAACu;
    // 0x1bdaac: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bdaacu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bdab0: 0x8c234868  lw          $v1, 0x4868($at)
    ctx->pc = 0x1bdab0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18536)));
    // 0x1bdab4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bdab4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bdab8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bdab8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bdabc: 0x1000ffe5  b           . + 4 + (-0x1B << 2)
    ctx->pc = 0x1BDABCu;
    {
        const bool branch_taken_0x1bdabc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BDAC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDABCu;
            // 0x1bdac0: 0xac234868  sw          $v1, 0x4868($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 18536), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdabc) {
            ctx->pc = 0x1BDA54u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bda54;
        }
    }
    ctx->pc = 0x1BDAC4u;
label_1bdac4:
    // 0x1bdac4: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1bdac4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1bdac8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bdac8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bdacc: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x1bdaccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
label_1bdad0:
    // 0x1bdad0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bdad0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1bdad4:
    // 0x1bdad4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bdad4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bdad8: 0x3e00008  jr          $ra
    ctx->pc = 0x1BDAD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BDADCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDAD8u;
            // 0x1bdadc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BDA24u: goto label_1bda24;
            case 0x1BDA34u: goto label_1bda34;
            case 0x1BDA3Cu: goto label_1bda3c;
            case 0x1BDA54u: goto label_1bda54;
            case 0x1BDA6Cu: goto label_1bda6c;
            case 0x1BDA70u: goto label_1bda70;
            case 0x1BDA9Cu: goto label_1bda9c;
            case 0x1BDAA0u: goto label_1bdaa0;
            case 0x1BDAC4u: goto label_1bdac4;
            case 0x1BDAD0u: goto label_1bdad0;
            case 0x1BDAD4u: goto label_1bdad4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BDAE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
