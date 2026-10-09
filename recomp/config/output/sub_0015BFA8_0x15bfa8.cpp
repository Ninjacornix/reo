#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015BFA8
// Address: 0x15bfa8 - 0x15c078
void sub_0015BFA8_0x15bfa8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015BFA8_0x15bfa8");
#endif

    switch (ctx->pc) {
        case 0x15c050u: goto label_15c050;
        case 0x15c060u: goto label_15c060;
        case 0x15c06cu: goto label_15c06c;
        default: break;
    }

    ctx->pc = 0x15bfa8u;

    // 0x15bfa8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15bfa8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15bfac: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x15bfacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x15bfb0: 0x8c860128  lw          $a2, 0x128($a0)
    ctx->pc = 0x15bfb0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 296)));
    // 0x15bfb4: 0x10c0002d  beqz        $a2, . + 4 + (0x2D << 2)
    ctx->pc = 0x15BFB4u;
    {
        const bool branch_taken_0x15bfb4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x15BFB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BFB4u;
            // 0x15bfb8: 0x8c870040  lw          $a3, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15bfb4) {
            ctx->pc = 0x15C06Cu;
            goto label_15c06c;
        }
    }
    ctx->pc = 0x15BFBCu;
    // 0x15bfbc: 0x8c82014c  lw          $v0, 0x14C($a0)
    ctx->pc = 0x15bfbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 332)));
    // 0x15bfc0: 0x54c2000b  bnel        $a2, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x15BFC0u;
    {
        const bool branch_taken_0x15bfc0 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        if (branch_taken_0x15bfc0) {
            ctx->pc = 0x15BFC4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15BFC0u;
            // 0x15bfc4: 0x8c82012c  lw          $v0, 0x12C($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 300)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15BFF0u;
            goto label_15bff0;
        }
    }
    ctx->pc = 0x15BFC8u;
    // 0x15bfc8: 0x8c820154  lw          $v0, 0x154($a0)
    ctx->pc = 0x15bfc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 340)));
    // 0x15bfcc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x15bfccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15bfd0: 0x8c840150  lw          $a0, 0x150($a0)
    ctx->pc = 0x15bfd0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 336)));
    // 0x15bfd4: 0xafa60004  sw          $a2, 0x4($sp)
    ctx->pc = 0x15bfd4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 6));
    // 0x15bfd8: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x15bfd8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x15bfdc: 0xafa40008  sw          $a0, 0x8($sp)
    ctx->pc = 0x15bfdcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 4));
    // 0x15bfe0: 0xafa2000c  sw          $v0, 0xC($sp)
    ctx->pc = 0x15bfe0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 2));
    // 0x15bfe4: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x15BFE4u;
    {
        const bool branch_taken_0x15bfe4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15BFE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BFE4u;
            // 0x15bfe8: 0xafa00010  sw          $zero, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15bfe4) {
            ctx->pc = 0x15C040u;
            goto label_15c040;
        }
    }
    ctx->pc = 0x15BFECu;
    // 0x15bfec: 0x0  nop
    ctx->pc = 0x15bfecu;
    // NOP
label_15bff0:
    // 0x15bff0: 0x54c2000b  bnel        $a2, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x15BFF0u;
    {
        const bool branch_taken_0x15bff0 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        if (branch_taken_0x15bff0) {
            ctx->pc = 0x15BFF4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15BFF0u;
            // 0x15bff4: 0x8c82013c  lw          $v0, 0x13C($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 316)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15C020u;
            goto label_15c020;
        }
    }
    ctx->pc = 0x15BFF8u;
    // 0x15bff8: 0x8c820138  lw          $v0, 0x138($a0)
    ctx->pc = 0x15bff8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 312)));
    // 0x15bffc: 0x8c830130  lw          $v1, 0x130($a0)
    ctx->pc = 0x15bffcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 304)));
    // 0x15c000: 0x8c840134  lw          $a0, 0x134($a0)
    ctx->pc = 0x15c000u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 308)));
    // 0x15c004: 0xafa60004  sw          $a2, 0x4($sp)
    ctx->pc = 0x15c004u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 6));
    // 0x15c008: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x15c008u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x15c00c: 0xafa4000c  sw          $a0, 0xC($sp)
    ctx->pc = 0x15c00cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 4));
    // 0x15c010: 0xafa20010  sw          $v0, 0x10($sp)
    ctx->pc = 0x15c010u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x15c014: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x15C014u;
    {
        const bool branch_taken_0x15c014 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C014u;
            // 0x15c018: 0xafa00000  sw          $zero, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c014) {
            ctx->pc = 0x15C040u;
            goto label_15c040;
        }
    }
    ctx->pc = 0x15C01Cu;
    // 0x15c01c: 0x0  nop
    ctx->pc = 0x15c01cu;
    // NOP
label_15c020:
    // 0x15c020: 0x8c850148  lw          $a1, 0x148($a0)
    ctx->pc = 0x15c020u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 328)));
    // 0x15c024: 0x8c830140  lw          $v1, 0x140($a0)
    ctx->pc = 0x15c024u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 320)));
    // 0x15c028: 0x8c840144  lw          $a0, 0x144($a0)
    ctx->pc = 0x15c028u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 324)));
    // 0x15c02c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x15c02cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x15c030: 0xafa60004  sw          $a2, 0x4($sp)
    ctx->pc = 0x15c030u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 6));
    // 0x15c034: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x15c034u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x15c038: 0xafa4000c  sw          $a0, 0xC($sp)
    ctx->pc = 0x15c038u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 4));
    // 0x15c03c: 0xafa50010  sw          $a1, 0x10($sp)
    ctx->pc = 0x15c03cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 5));
label_15c040:
    // 0x15c040: 0xafa00014  sw          $zero, 0x14($sp)
    ctx->pc = 0x15c040u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x15c044: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x15c044u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c048: 0xc05d028  jal         func_1740A0
    ctx->pc = 0x15C048u;
    SET_GPR_U32(ctx, 31, 0x15C050u);
    ctx->pc = 0x15C04Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C048u;
            // 0x15c04c: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1740A0u;
    if (runtime->hasFunction(0x1740A0u)) {
        auto targetFn = runtime->lookupFunction(0x1740A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C050u; }
        if (ctx->pc != 0x15C050u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001740A0_0x1740a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C050u; }
        if (ctx->pc != 0x15C050u) { return; }
    }
    ctx->pc = 0x15C050u;
label_15c050:
    // 0x15c050: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15C050u;
    {
        const bool branch_taken_0x15c050 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C054u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C050u;
            // 0x15c054: 0x2404fec8  addiu       $a0, $zero, -0x138 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966984));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c050) {
            ctx->pc = 0x15C06Cu;
            goto label_15c06c;
        }
    }
    ctx->pc = 0x15C058u;
    // 0x15c058: 0xc057abc  jal         func_15EAF0
    ctx->pc = 0x15C058u;
    SET_GPR_U32(ctx, 31, 0x15C060u);
    ctx->pc = 0x15EAF0u;
    if (runtime->hasFunction(0x15EAF0u)) {
        auto targetFn = runtime->lookupFunction(0x15EAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C060u; }
        if (ctx->pc != 0x15C060u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EAF0_0x15eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C060u; }
        if (ctx->pc != 0x15C060u) { return; }
    }
    ctx->pc = 0x15C060u;
label_15c060:
    // 0x15c060: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15c060u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15c064: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15C064u;
    SET_GPR_U32(ctx, 31, 0x15C06Cu);
    ctx->pc = 0x15C068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C064u;
            // 0x15c068: 0x2484e770  addiu       $a0, $a0, -0x1890 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961008));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C06Cu; }
        if (ctx->pc != 0x15C06Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C06Cu; }
        if (ctx->pc != 0x15C06Cu) { return; }
    }
    ctx->pc = 0x15C06Cu;
label_15c06c:
    // 0x15c06c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15c06cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15c070: 0x3e00008  jr          $ra
    ctx->pc = 0x15C070u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15C074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C070u;
            // 0x15c074: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15BFF0u: goto label_15bff0;
            case 0x15C020u: goto label_15c020;
            case 0x15C040u: goto label_15c040;
            case 0x15C050u: goto label_15c050;
            case 0x15C060u: goto label_15c060;
            case 0x15C06Cu: goto label_15c06c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15C078u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
