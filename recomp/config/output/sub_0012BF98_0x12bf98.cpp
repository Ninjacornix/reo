#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012BF98
// Address: 0x12bf98 - 0x12c040
void sub_0012BF98_0x12bf98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012BF98_0x12bf98");
#endif

    switch (ctx->pc) {
        case 0x12bfd0u: goto label_12bfd0;
        case 0x12bff4u: goto label_12bff4;
        default: break;
    }

    ctx->pc = 0x12bf98u;

    // 0x12bf98: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x12bf98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x12bf9c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12bf9cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12bfa0: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x12bfa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x12bfa4: 0x2451049c  addiu       $s1, $v0, 0x49C
    ctx->pc = 0x12bfa4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 1180));
    // 0x12bfa8: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12bfa8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12bfac: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x12bfacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12bfb0: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x12bfb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x12bfb4: 0x14640012  bne         $v1, $a0, . + 4 + (0x12 << 2)
    ctx->pc = 0x12BFB4u;
    {
        const bool branch_taken_0x12bfb4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x12BFB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BFB4u;
            // 0x12bfb8: 0xffbf0040  sd          $ra, 0x40($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12bfb4) {
            ctx->pc = 0x12C000u;
            goto label_12c000;
        }
    }
    ctx->pc = 0x12BFBCu;
    // 0x12bfbc: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12bfbcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12bfc0: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x12bfc0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12bfc4: 0x245004e8  addiu       $s0, $v0, 0x4E8
    ctx->pc = 0x12bfc4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 1256));
    // 0x12bfc8: 0xc045148  jal         func_114520
    ctx->pc = 0x12BFC8u;
    SET_GPR_U32(ctx, 31, 0x12BFD0u);
    ctx->pc = 0x12BFCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BFC8u;
            // 0x12bfcc: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114520u;
    if (runtime->hasFunction(0x114520u)) {
        auto targetFn = runtime->lookupFunction(0x114520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BFD0u; }
        if (ctx->pc != 0x12BFD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114520_0x114520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BFD0u; }
        if (ctx->pc != 0x12BFD0u) { return; }
    }
    ctx->pc = 0x12BFD0u;
label_12bfd0:
    // 0x12bfd0: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x12bfd0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12bfd4: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x12bfd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12bfd8: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x12BFD8u;
    {
        const bool branch_taken_0x12bfd8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x12BFDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BFD8u;
            // 0x12bfdc: 0x2404000c  addiu       $a0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12bfd8) {
            ctx->pc = 0x12BFE8u;
            goto label_12bfe8;
        }
    }
    ctx->pc = 0x12BFE0u;
    // 0x12bfe0: 0x54640008  bnel        $v1, $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x12BFE0u;
    {
        const bool branch_taken_0x12bfe0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x12bfe0) {
            ctx->pc = 0x12BFE4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12BFE0u;
            // 0x12bfe4: 0xdfb00030  ld          $s0, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12C004u;
            goto label_12c004;
        }
    }
    ctx->pc = 0x12BFE8u;
label_12bfe8:
    // 0x12bfe8: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12bfe8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12bfec: 0xc045154  jal         func_114550
    ctx->pc = 0x12BFECu;
    SET_GPR_U32(ctx, 31, 0x12BFF4u);
    ctx->pc = 0x114550u;
    if (runtime->hasFunction(0x114550u)) {
        auto targetFn = runtime->lookupFunction(0x114550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BFF4u; }
        if (ctx->pc != 0x12BFF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114550_0x114550(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BFF4u; }
        if (ctx->pc != 0x12BFF4u) { return; }
    }
    ctx->pc = 0x12BFF4u;
label_12bff4:
    // 0x12bff4: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x12bff4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12bff8: 0x50430001  beql        $v0, $v1, . + 4 + (0x1 << 2)
    ctx->pc = 0x12BFF8u;
    {
        const bool branch_taken_0x12bff8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x12bff8) {
            ctx->pc = 0x12BFFCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12BFF8u;
            // 0x12bffc: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12C000u;
            goto label_12c000;
        }
    }
    ctx->pc = 0x12C000u;
label_12c000:
    // 0x12c000: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x12c000u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_12c004:
    // 0x12c004: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x12c004u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12c008: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x12c008u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12c00c: 0x3e00008  jr          $ra
    ctx->pc = 0x12C00Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C00Cu;
            // 0x12c010: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12BFD0u: goto label_12bfd0;
            case 0x12BFE8u: goto label_12bfe8;
            case 0x12BFF4u: goto label_12bff4;
            case 0x12C000u: goto label_12c000;
            case 0x12C004u: goto label_12c004;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C014u;
    // 0x12c014: 0x0  nop
    ctx->pc = 0x12c014u;
    // NOP
    // 0x12c018: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c018u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c01c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12c01cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12c020: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c020u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c024: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12c024u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12c028: 0x2442049c  addiu       $v0, $v0, 0x49C
    ctx->pc = 0x12c028u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1180));
    // 0x12c02c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c02cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c030: 0x0  nop
    ctx->pc = 0x12c030u;
    // NOP
    // 0x12c034: 0x804ac36  j           func_12B0D8
    ctx->pc = 0x12C034u;
    ctx->pc = 0x12C038u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C034u;
            // 0x12c038: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B0D8u;
    if (runtime->hasFunction(0x12B0D8u)) {
        auto targetFn = runtime->lookupFunction(0x12B0D8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012B0D8_0x12b0d8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C03Cu;
    // 0x12c03c: 0x0  nop
    ctx->pc = 0x12c03cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
