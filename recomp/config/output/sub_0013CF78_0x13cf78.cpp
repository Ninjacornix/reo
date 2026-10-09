#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013CF78
// Address: 0x13cf78 - 0x13d040
void sub_0013CF78_0x13cf78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013CF78_0x13cf78");
#endif

    switch (ctx->pc) {
        case 0x13cfd8u: goto label_13cfd8;
        case 0x13cfe8u: goto label_13cfe8;
        default: break;
    }

    ctx->pc = 0x13cf78u;

    // 0x13cf78: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13cf78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13cf7c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13cf7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13cf80: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13cf80u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cf84: 0x16000008  bnez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13CF84u;
    {
        const bool branch_taken_0x13cf84 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x13CF88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CF84u;
            // 0x13cf88: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13cf84) {
            ctx->pc = 0x13CFA8u;
            goto label_13cfa8;
        }
    }
    ctx->pc = 0x13CF8Cu;
    // 0x13cf8c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13cf8cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13cf90: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13cf90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13cf94: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13cf94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13cf98: 0x2484d368  addiu       $a0, $a0, -0x2C98
    ctx->pc = 0x13cf98u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955880));
    // 0x13cf9c: 0x804f53e  j           func_13D4F8
    ctx->pc = 0x13CF9Cu;
    ctx->pc = 0x13CFA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13CF9Cu;
            // 0x13cfa0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13CFA4u;
    // 0x13cfa4: 0x0  nop
    ctx->pc = 0x13cfa4u;
    // NOP
label_13cfa8:
    // 0x13cfa8: 0x82020001  lb          $v0, 0x1($s0)
    ctx->pc = 0x13cfa8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x13cfac: 0x50400010  beql        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x13CFACu;
    {
        const bool branch_taken_0x13cfac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13cfac) {
            ctx->pc = 0x13CFB0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13CFACu;
            // 0x13cfb0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13CFF0u;
            goto label_13cff0;
        }
    }
    ctx->pc = 0x13CFB4u;
    // 0x13cfb4: 0x8e040028  lw          $a0, 0x28($s0)
    ctx->pc = 0x13cfb4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x13cfb8: 0x10800008  beqz        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13CFB8u;
    {
        const bool branch_taken_0x13cfb8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x13CFBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CFB8u;
            // 0x13cfbc: 0xa2000001  sb          $zero, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13cfb8) {
            ctx->pc = 0x13CFDCu;
            goto label_13cfdc;
        }
    }
    ctx->pc = 0x13CFC0u;
    // 0x13cfc0: 0x82030002  lb          $v1, 0x2($s0)
    ctx->pc = 0x13cfc0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x13cfc4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13cfc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13cfc8: 0x54620005  bnel        $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x13CFC8u;
    {
        const bool branch_taken_0x13cfc8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x13cfc8) {
            ctx->pc = 0x13CFCCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13CFC8u;
            // 0x13cfcc: 0xae00002c  sw          $zero, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13CFE0u;
            goto label_13cfe0;
        }
    }
    ctx->pc = 0x13CFD0u;
    // 0x13cfd0: 0xc04c1d2  jal         func_130748
    ctx->pc = 0x13CFD0u;
    SET_GPR_U32(ctx, 31, 0x13CFD8u);
    ctx->pc = 0x130748u;
    if (runtime->hasFunction(0x130748u)) {
        auto targetFn = runtime->lookupFunction(0x130748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CFD8u; }
        if (ctx->pc != 0x13CFD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130748_0x130748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CFD8u; }
        if (ctx->pc != 0x13CFD8u) { return; }
    }
    ctx->pc = 0x13CFD8u;
label_13cfd8:
    // 0x13cfd8: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x13cfd8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
label_13cfdc:
    // 0x13cfdc: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x13cfdcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
label_13cfe0:
    // 0x13cfe0: 0xc04f3b4  jal         func_13CED0
    ctx->pc = 0x13CFE0u;
    SET_GPR_U32(ctx, 31, 0x13CFE8u);
    ctx->pc = 0x13CFE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13CFE0u;
            // 0x13cfe4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CED0u;
    if (runtime->hasFunction(0x13CED0u)) {
        auto targetFn = runtime->lookupFunction(0x13CED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CFE8u; }
        if (ctx->pc != 0x13CFE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CED0_0x13ced0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CFE8u; }
        if (ctx->pc != 0x13CFE8u) { return; }
    }
    ctx->pc = 0x13CFE8u;
label_13cfe8:
    // 0x13cfe8: 0xae000034  sw          $zero, 0x34($s0)
    ctx->pc = 0x13cfe8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x13cfec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13cfecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13cff0:
    // 0x13cff0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13cff0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13cff4: 0x3e00008  jr          $ra
    ctx->pc = 0x13CFF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CFF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CFF4u;
            // 0x13cff8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CFA8u: goto label_13cfa8;
            case 0x13CFD8u: goto label_13cfd8;
            case 0x13CFDCu: goto label_13cfdc;
            case 0x13CFE0u: goto label_13cfe0;
            case 0x13CFE8u: goto label_13cfe8;
            case 0x13CFF0u: goto label_13cff0;
            case 0x13D020u: goto label_13d020;
            case 0x13D030u: goto label_13d030;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CFFCu;
    // 0x13cffc: 0x0  nop
    ctx->pc = 0x13cffcu;
    // NOP
    // 0x13d000: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13d000u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13d004: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13D004u;
    {
        const bool branch_taken_0x13d004 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D004u;
            // 0x13d008: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d004) {
            ctx->pc = 0x13D020u;
            goto label_13d020;
        }
    }
    ctx->pc = 0x13D00Cu;
    // 0x13d00c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d00cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d010: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d010u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d014: 0x2484d368  addiu       $a0, $a0, -0x2C98
    ctx->pc = 0x13d014u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955880));
    // 0x13d018: 0x804f53e  j           func_13D4F8
    ctx->pc = 0x13D018u;
    ctx->pc = 0x13D01Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D018u;
            // 0x13d01c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13D020u;
label_13d020:
    // 0x13d020: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13d020u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13d024: 0x54a20002  bnel        $a1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x13D024u;
    {
        const bool branch_taken_0x13d024 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        if (branch_taken_0x13d024) {
            ctx->pc = 0x13D028u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D024u;
            // 0x13d028: 0xa0800004  sb          $zero, 0x4($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 4), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D030u;
            goto label_13d030;
        }
    }
    ctx->pc = 0x13D02Cu;
    // 0x13d02c: 0xa0850004  sb          $a1, 0x4($a0)
    ctx->pc = 0x13d02cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 4), (uint8_t)GPR_U32(ctx, 5));
label_13d030:
    // 0x13d030: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d030u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d034: 0x3e00008  jr          $ra
    ctx->pc = 0x13D034u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D034u;
            // 0x13d038: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CFA8u: goto label_13cfa8;
            case 0x13CFD8u: goto label_13cfd8;
            case 0x13CFDCu: goto label_13cfdc;
            case 0x13CFE0u: goto label_13cfe0;
            case 0x13CFE8u: goto label_13cfe8;
            case 0x13CFF0u: goto label_13cff0;
            case 0x13D020u: goto label_13d020;
            case 0x13D030u: goto label_13d030;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D03Cu;
    // 0x13d03c: 0x0  nop
    ctx->pc = 0x13d03cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
