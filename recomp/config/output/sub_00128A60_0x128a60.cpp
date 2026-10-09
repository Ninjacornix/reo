#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128A60
// Address: 0x128a60 - 0x128b18
void sub_00128A60_0x128a60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128A60_0x128a60");
#endif

    switch (ctx->pc) {
        case 0x128a7cu: goto label_128a7c;
        case 0x128ae4u: goto label_128ae4;
        case 0x128af8u: goto label_128af8;
        default: break;
    }

    ctx->pc = 0x128a60u;

label_128a60:
    // 0x128a60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x128a60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x128a64: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x128a64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x128a68: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x128a68u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x128a6c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x128a6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x128a70: 0x2610d230  addiu       $s0, $s0, -0x2DD0
    ctx->pc = 0x128a70u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294955568));
    // 0x128a74: 0xc04a4d4  jal         func_129350
    ctx->pc = 0x128A74u;
    SET_GPR_U32(ctx, 31, 0x128A7Cu);
    ctx->pc = 0x128A78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128A74u;
            // 0x128a78: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129350u;
    if (runtime->hasFunction(0x129350u)) {
        auto targetFn = runtime->lookupFunction(0x129350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128A7Cu; }
        if (ctx->pc != 0x128A7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129350_0x129350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128A7Cu; }
        if (ctx->pc != 0x128A7Cu) { return; }
    }
    ctx->pc = 0x128A7Cu;
label_128a7c:
    // 0x128a7c: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x128a7cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x128a80: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x128a80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x128a84: 0x3c050021  lui         $a1, 0x21
    ctx->pc = 0x128a84u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)33 << 16));
    // 0x128a88: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x128a88u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x128a8c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x128a8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x128a90: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x128a90u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x128a94: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x128a94u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x128a98: 0xaca2d234  sw          $v0, -0x2DCC($a1)
    ctx->pc = 0x128a98u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294955572), GPR_U32(ctx, 2));
    // 0x128a9c: 0xac60d22c  sw          $zero, -0x2DD4($v1)
    ctx->pc = 0x128a9cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294955564), GPR_U32(ctx, 0));
    // 0x128aa0: 0xac80d23c  sw          $zero, -0x2DC4($a0)
    ctx->pc = 0x128aa0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4294955580), GPR_U32(ctx, 0));
    // 0x128aa4: 0x3e00008  jr          $ra
    ctx->pc = 0x128AA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x128AA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128AA4u;
            // 0x128aa8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128A60u: goto label_128a60;
            case 0x128A7Cu: goto label_128a7c;
            case 0x128AE4u: goto label_128ae4;
            case 0x128AF8u: goto label_128af8;
            case 0x128AFCu: goto label_128afc;
            case 0x128B08u: goto label_128b08;
            case 0x128B0Cu: goto label_128b0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x128AACu;
    // 0x128aac: 0x0  nop
    ctx->pc = 0x128aacu;
    // NOP
    // 0x128ab0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x128ab0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x128ab4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x128ab4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x128ab8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x128ab8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x128abc: 0x2450d230  addiu       $s0, $v0, -0x2DD0
    ctx->pc = 0x128abcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294955568));
    // 0x128ac0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x128ac0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x128ac4: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x128ac4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x128ac8: 0x1080000f  beqz        $a0, . + 4 + (0xF << 2)
    ctx->pc = 0x128AC8u;
    {
        const bool branch_taken_0x128ac8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x128ACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128AC8u;
            // 0x128acc: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128ac8) {
            ctx->pc = 0x128B08u;
            goto label_128b08;
        }
    }
    ctx->pc = 0x128AD0u;
    // 0x128ad0: 0x8c43d234  lw          $v1, -0x2DCC($v0)
    ctx->pc = 0x128ad0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294955572)));
    // 0x128ad4: 0x462000d  bltzl       $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x128AD4u;
    {
        const bool branch_taken_0x128ad4 = (GPR_S64(ctx, 3) < 0);
        if (branch_taken_0x128ad4) {
            ctx->pc = 0x128AD8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x128AD4u;
            // 0x128ad8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x128B0Cu;
            goto label_128b0c;
        }
    }
    ctx->pc = 0x128ADCu;
    // 0x128adc: 0xc04a752  jal         func_129D48
    ctx->pc = 0x128ADCu;
    SET_GPR_U32(ctx, 31, 0x128AE4u);
    ctx->pc = 0x129D48u;
    if (runtime->hasFunction(0x129D48u)) {
        auto targetFn = runtime->lookupFunction(0x129D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128AE4u; }
        if (ctx->pc != 0x128AE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129D48_0x129d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128AE4u; }
        if (ctx->pc != 0x128AE4u) { return; }
    }
    ctx->pc = 0x128AE4u;
label_128ae4:
    // 0x128ae4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x128ae4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x128ae8: 0x50430004  beql        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x128AE8u;
    {
        const bool branch_taken_0x128ae8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x128ae8) {
            ctx->pc = 0x128AECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x128AE8u;
            // 0x128aec: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x128AFCu;
            goto label_128afc;
        }
    }
    ctx->pc = 0x128AF0u;
    // 0x128af0: 0xc04a5f8  jal         func_1297E0
    ctx->pc = 0x128AF0u;
    SET_GPR_U32(ctx, 31, 0x128AF8u);
    ctx->pc = 0x128AF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128AF0u;
            // 0x128af4: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1297E0u;
    if (runtime->hasFunction(0x1297E0u)) {
        auto targetFn = runtime->lookupFunction(0x1297E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128AF8u; }
        if (ctx->pc != 0x128AF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001297E0_0x1297e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128AF8u; }
        if (ctx->pc != 0x128AF8u) { return; }
    }
    ctx->pc = 0x128AF8u;
label_128af8:
    // 0x128af8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x128af8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_128afc:
    // 0x128afc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x128afcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x128b00: 0x804a298  j           func_128A60
    ctx->pc = 0x128B00u;
    ctx->pc = 0x128B04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128B00u;
            // 0x128b04: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128A60u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_128a60;
    ctx->pc = 0x128B08u;
label_128b08:
    // 0x128b08: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x128b08u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_128b0c:
    // 0x128b0c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x128b0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x128b10: 0x3e00008  jr          $ra
    ctx->pc = 0x128B10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x128B14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128B10u;
            // 0x128b14: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128A60u: goto label_128a60;
            case 0x128A7Cu: goto label_128a7c;
            case 0x128AE4u: goto label_128ae4;
            case 0x128AF8u: goto label_128af8;
            case 0x128AFCu: goto label_128afc;
            case 0x128B08u: goto label_128b08;
            case 0x128B0Cu: goto label_128b0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x128B18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
