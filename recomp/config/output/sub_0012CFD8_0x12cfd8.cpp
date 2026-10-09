#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012CFD8
// Address: 0x12cfd8 - 0x12d338
void sub_0012CFD8_0x12cfd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012CFD8_0x12cfd8");
#endif

    switch (ctx->pc) {
        case 0x12d02cu: goto label_12d02c;
        case 0x12d050u: goto label_12d050;
        case 0x12d088u: goto label_12d088;
        case 0x12d090u: goto label_12d090;
        case 0x12d0d8u: goto label_12d0d8;
        case 0x12d104u: goto label_12d104;
        case 0x12d11cu: goto label_12d11c;
        case 0x12d134u: goto label_12d134;
        case 0x12d140u: goto label_12d140;
        case 0x12d168u: goto label_12d168;
        case 0x12d1a0u: goto label_12d1a0;
        case 0x12d1b8u: goto label_12d1b8;
        case 0x12d1d0u: goto label_12d1d0;
        case 0x12d1f8u: goto label_12d1f8;
        case 0x12d218u: goto label_12d218;
        case 0x12d244u: goto label_12d244;
        case 0x12d258u: goto label_12d258;
        case 0x12d270u: goto label_12d270;
        case 0x12d2a0u: goto label_12d2a0;
        case 0x12d2b0u: goto label_12d2b0;
        case 0x12d2d0u: goto label_12d2d0;
        case 0x12d2d8u: goto label_12d2d8;
        case 0x12d2fcu: goto label_12d2fc;
        case 0x12d30cu: goto label_12d30c;
        case 0x12d314u: goto label_12d314;
        default: break;
    }

    ctx->pc = 0x12cfd8u;

    // 0x12cfd8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x12cfd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x12cfdc: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x12cfdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x12cfe0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x12cfe0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cfe4: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x12cfe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x12cfe8: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x12cfe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x12cfec: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x12cfecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x12cff0: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x12cff0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x12cff4: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x12cff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x12cff8: 0x8e43003c  lw          $v1, 0x3C($s2)
    ctx->pc = 0x12cff8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 60)));
    // 0x12cffc: 0x8e540004  lw          $s4, 0x4($s2)
    ctx->pc = 0x12cffcu;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x12d000: 0x460000a  bltz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x12D000u;
    {
        const bool branch_taken_0x12d000 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x12D004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D000u;
            // 0x12d004: 0x8e510008  lw          $s1, 0x8($s2) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d000) {
            ctx->pc = 0x12D02Cu;
            goto label_12d02c;
        }
    }
    ctx->pc = 0x12D008u;
    // 0x12d008: 0x8e420040  lw          $v0, 0x40($s2)
    ctx->pc = 0x12d008u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 64)));
    // 0x12d00c: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x12d00cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x12d010: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x12D010u;
    {
        const bool branch_taken_0x12d010 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12d010) {
            ctx->pc = 0x12D014u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12D010u;
            // 0x12d014: 0x82430003  lb          $v1, 0x3($s2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 3)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12D030u;
            goto label_12d030;
        }
    }
    ctx->pc = 0x12D018u;
    // 0x12d018: 0x8e420048  lw          $v0, 0x48($s2)
    ctx->pc = 0x12d018u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 72)));
    // 0x12d01c: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x12D01Cu;
    {
        const bool branch_taken_0x12d01c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x12d01c) {
            ctx->pc = 0x12D020u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12D01Cu;
            // 0x12d020: 0x82430003  lb          $v1, 0x3($s2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 3)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12D030u;
            goto label_12d030;
        }
    }
    ctx->pc = 0x12D024u;
    // 0x12d024: 0x40f809  jalr        $v0
    ctx->pc = 0x12D024u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12D02Cu);
        ctx->pc = 0x12D028u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D024u;
            // 0x12d028: 0x8e44004c  lw          $a0, 0x4C($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D02Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D02Cu: goto label_12d02c;
            case 0x12D030u: goto label_12d030;
            case 0x12D050u: goto label_12d050;
            case 0x12D068u: goto label_12d068;
            case 0x12D088u: goto label_12d088;
            case 0x12D090u: goto label_12d090;
            case 0x12D0D8u: goto label_12d0d8;
            case 0x12D104u: goto label_12d104;
            case 0x12D11Cu: goto label_12d11c;
            case 0x12D134u: goto label_12d134;
            case 0x12D140u: goto label_12d140;
            case 0x12D168u: goto label_12d168;
            case 0x12D190u: goto label_12d190;
            case 0x12D194u: goto label_12d194;
            case 0x12D1A0u: goto label_12d1a0;
            case 0x12D1B8u: goto label_12d1b8;
            case 0x12D1D0u: goto label_12d1d0;
            case 0x12D1D8u: goto label_12d1d8;
            case 0x12D1F8u: goto label_12d1f8;
            case 0x12D210u: goto label_12d210;
            case 0x12D218u: goto label_12d218;
            case 0x12D244u: goto label_12d244;
            case 0x12D250u: goto label_12d250;
            case 0x12D258u: goto label_12d258;
            case 0x12D270u: goto label_12d270;
            case 0x12D28Cu: goto label_12d28c;
            case 0x12D2A0u: goto label_12d2a0;
            case 0x12D2A8u: goto label_12d2a8;
            case 0x12D2B0u: goto label_12d2b0;
            case 0x12D2D0u: goto label_12d2d0;
            case 0x12D2D8u: goto label_12d2d8;
            case 0x12D2FCu: goto label_12d2fc;
            case 0x12D300u: goto label_12d300;
            case 0x12D30Cu: goto label_12d30c;
            case 0x12D314u: goto label_12d314;
            case 0x12D318u: goto label_12d318;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D02Cu; }
            if (ctx->pc != 0x12D02Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12D02Cu;
label_12d02c:
    // 0x12d02c: 0x82430003  lb          $v1, 0x3($s2)
    ctx->pc = 0x12d02cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 3)));
label_12d030:
    // 0x12d030: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12d030u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12d034: 0x5462000c  bnel        $v1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x12D034u;
    {
        const bool branch_taken_0x12d034 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x12d034) {
            ctx->pc = 0x12D038u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12D034u;
            // 0x12d038: 0x8e220000  lw          $v0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12D068u;
            goto label_12d068;
        }
    }
    ctx->pc = 0x12D03Cu;
    // 0x12d03c: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12d03cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12d040: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d040u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d044: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x12d044u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x12d048: 0x40f809  jalr        $v0
    ctx->pc = 0x12D048u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12D050u);
        ctx->pc = 0x12D04Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D048u;
            // 0x12d04c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D050u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D02Cu: goto label_12d02c;
            case 0x12D030u: goto label_12d030;
            case 0x12D050u: goto label_12d050;
            case 0x12D068u: goto label_12d068;
            case 0x12D088u: goto label_12d088;
            case 0x12D090u: goto label_12d090;
            case 0x12D0D8u: goto label_12d0d8;
            case 0x12D104u: goto label_12d104;
            case 0x12D11Cu: goto label_12d11c;
            case 0x12D134u: goto label_12d134;
            case 0x12D140u: goto label_12d140;
            case 0x12D168u: goto label_12d168;
            case 0x12D190u: goto label_12d190;
            case 0x12D194u: goto label_12d194;
            case 0x12D1A0u: goto label_12d1a0;
            case 0x12D1B8u: goto label_12d1b8;
            case 0x12D1D0u: goto label_12d1d0;
            case 0x12D1D8u: goto label_12d1d8;
            case 0x12D1F8u: goto label_12d1f8;
            case 0x12D210u: goto label_12d210;
            case 0x12D218u: goto label_12d218;
            case 0x12D244u: goto label_12d244;
            case 0x12D250u: goto label_12d250;
            case 0x12D258u: goto label_12d258;
            case 0x12D270u: goto label_12d270;
            case 0x12D28Cu: goto label_12d28c;
            case 0x12D2A0u: goto label_12d2a0;
            case 0x12D2A8u: goto label_12d2a8;
            case 0x12D2B0u: goto label_12d2b0;
            case 0x12D2D0u: goto label_12d2d0;
            case 0x12D2D8u: goto label_12d2d8;
            case 0x12D2FCu: goto label_12d2fc;
            case 0x12D300u: goto label_12d300;
            case 0x12D30Cu: goto label_12d30c;
            case 0x12D314u: goto label_12d314;
            case 0x12D318u: goto label_12d318;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D050u; }
            if (ctx->pc != 0x12D050u) { return; }
        }
        }
    }
    ctx->pc = 0x12D050u;
label_12d050:
    // 0x12d050: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x12D050u;
    {
        const bool branch_taken_0x12d050 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12d050) {
            ctx->pc = 0x12D054u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12D050u;
            // 0x12d054: 0x8e220000  lw          $v0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12D068u;
            goto label_12d068;
        }
    }
    ctx->pc = 0x12D058u;
    // 0x12d058: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x12d058u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x12d05c: 0x100000ad  b           . + 4 + (0xAD << 2)
    ctx->pc = 0x12D05Cu;
    {
        const bool branch_taken_0x12d05c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12D060u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D05Cu;
            // 0x12d060: 0xa2420001  sb          $v0, 0x1($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d05c) {
            ctx->pc = 0x12D314u;
            goto label_12d314;
        }
    }
    ctx->pc = 0x12D064u;
    // 0x12d064: 0x0  nop
    ctx->pc = 0x12d064u;
    // NOP
label_12d068:
    // 0x12d068: 0x26530014  addiu       $s3, $s2, 0x14
    ctx->pc = 0x12d068u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 18), 20));
    // 0x12d06c: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x12d06cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x12d070: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d070u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d074: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x12d074u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x12d078: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12d078u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12d07c: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x12d07cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x12d080: 0x60f809  jalr        $v1
    ctx->pc = 0x12D080u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x12D088u);
        ctx->pc = 0x12D084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D080u;
            // 0x12d084: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D088u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D02Cu: goto label_12d02c;
            case 0x12D030u: goto label_12d030;
            case 0x12D050u: goto label_12d050;
            case 0x12D068u: goto label_12d068;
            case 0x12D088u: goto label_12d088;
            case 0x12D090u: goto label_12d090;
            case 0x12D0D8u: goto label_12d0d8;
            case 0x12D104u: goto label_12d104;
            case 0x12D11Cu: goto label_12d11c;
            case 0x12D134u: goto label_12d134;
            case 0x12D140u: goto label_12d140;
            case 0x12D168u: goto label_12d168;
            case 0x12D190u: goto label_12d190;
            case 0x12D194u: goto label_12d194;
            case 0x12D1A0u: goto label_12d1a0;
            case 0x12D1B8u: goto label_12d1b8;
            case 0x12D1D0u: goto label_12d1d0;
            case 0x12D1D8u: goto label_12d1d8;
            case 0x12D1F8u: goto label_12d1f8;
            case 0x12D210u: goto label_12d210;
            case 0x12D218u: goto label_12d218;
            case 0x12D244u: goto label_12d244;
            case 0x12D250u: goto label_12d250;
            case 0x12D258u: goto label_12d258;
            case 0x12D270u: goto label_12d270;
            case 0x12D28Cu: goto label_12d28c;
            case 0x12D2A0u: goto label_12d2a0;
            case 0x12D2A8u: goto label_12d2a8;
            case 0x12D2B0u: goto label_12d2b0;
            case 0x12D2D0u: goto label_12d2d0;
            case 0x12D2D8u: goto label_12d2d8;
            case 0x12D2FCu: goto label_12d2fc;
            case 0x12D300u: goto label_12d300;
            case 0x12D30Cu: goto label_12d30c;
            case 0x12D314u: goto label_12d314;
            case 0x12D318u: goto label_12d318;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D088u; }
            if (ctx->pc != 0x12D088u) { return; }
        }
        }
    }
    ctx->pc = 0x12D088u;
label_12d088:
    // 0x12d088: 0xc04939a  jal         func_124E68
    ctx->pc = 0x12D088u;
    SET_GPR_U32(ctx, 31, 0x12D090u);
    ctx->pc = 0x12D08Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D088u;
            // 0x12d08c: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124E68u;
    if (runtime->hasFunction(0x124E68u)) {
        auto targetFn = runtime->lookupFunction(0x124E68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D090u; }
        if (ctx->pc != 0x12D090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124E68_0x124e68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D090u; }
        if (ctx->pc != 0x12D090u) { return; }
    }
    ctx->pc = 0x12D090u;
label_12d090:
    // 0x12d090: 0x1440005f  bnez        $v0, . + 4 + (0x5F << 2)
    ctx->pc = 0x12D090u;
    {
        const bool branch_taken_0x12d090 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12d090) {
            ctx->pc = 0x12D210u;
            goto label_12d210;
        }
    }
    ctx->pc = 0x12D098u;
    // 0x12d098: 0x8e460018  lw          $a2, 0x18($s2)
    ctx->pc = 0x12d098u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
    // 0x12d09c: 0x28c20004  slti        $v0, $a2, 0x4
    ctx->pc = 0x12d09cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x12d0a0: 0x1440005b  bnez        $v0, . + 4 + (0x5B << 2)
    ctx->pc = 0x12D0A0u;
    {
        const bool branch_taken_0x12d0a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12D0A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D0A0u;
            // 0x12d0a4: 0x34058001  ori         $a1, $zero, 0x8001 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32769);
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d0a0) {
            ctx->pc = 0x12D210u;
            goto label_12d210;
        }
    }
    ctx->pc = 0x12D0A8u;
    // 0x12d0a8: 0x8e640000  lw          $a0, 0x0($s3)
    ctx->pc = 0x12d0a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12d0ac: 0x94830000  lhu         $v1, 0x0($a0)
    ctx->pc = 0x12d0acu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12d0b0: 0x90820001  lbu         $v0, 0x1($a0)
    ctx->pc = 0x12d0b0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x12d0b4: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x12d0b4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x12d0b8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x12d0b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x12d0bc: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x12d0bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x12d0c0: 0x14450053  bne         $v0, $a1, . + 4 + (0x53 << 2)
    ctx->pc = 0x12D0C0u;
    {
        const bool branch_taken_0x12d0c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        ctx->pc = 0x12D0C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D0C0u;
            // 0x12d0c4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d0c0) {
            ctx->pc = 0x12D210u;
            goto label_12d210;
        }
    }
    ctx->pc = 0x12D0C8u;
    // 0x12d0c8: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x12d0c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d0cc: 0xa2420001  sb          $v0, 0x1($s2)
    ctx->pc = 0x12d0ccu;
    WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x12d0d0: 0xc049bc8  jal         func_126F20
    ctx->pc = 0x12D0D0u;
    SET_GPR_U32(ctx, 31, 0x12D0D8u);
    ctx->pc = 0x12D0D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D0D0u;
            // 0x12d0d4: 0x27a60010  addiu       $a2, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126F20u;
    if (runtime->hasFunction(0x126F20u)) {
        auto targetFn = runtime->lookupFunction(0x126F20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D0D8u; }
        if (ctx->pc != 0x12D0D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126F20_0x126f20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D0D8u; }
        if (ctx->pc != 0x12D0D8u) { return; }
    }
    ctx->pc = 0x12D0D8u;
label_12d0d8:
    // 0x12d0d8: 0x5440003f  bnel        $v0, $zero, . + 4 + (0x3F << 2)
    ctx->pc = 0x12D0D8u;
    {
        const bool branch_taken_0x12d0d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12d0d8) {
            ctx->pc = 0x12D0DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12D0D8u;
            // 0x12d0dc: 0x260a02d  daddu       $s4, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12D1D8u;
            goto label_12d1d8;
        }
    }
    ctx->pc = 0x12D0E0u;
    // 0x12d0e0: 0x87a50010  lh          $a1, 0x10($sp)
    ctx->pc = 0x12d0e0u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12d0e4: 0x8e420018  lw          $v0, 0x18($s2)
    ctx->pc = 0x12d0e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
    // 0x12d0e8: 0x45102a  slt         $v0, $v0, $a1
    ctx->pc = 0x12d0e8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x12d0ec: 0x54400067  bnel        $v0, $zero, . + 4 + (0x67 << 2)
    ctx->pc = 0x12D0ECu;
    {
        const bool branch_taken_0x12d0ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12d0ec) {
            ctx->pc = 0x12D0F0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12D0ECu;
            // 0x12d0f0: 0x8e230000  lw          $v1, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12D28Cu;
            goto label_12d28c;
        }
    }
    ctx->pc = 0x12D0F4u;
    // 0x12d0f4: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x12d0f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d0f8: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x12d0f8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d0fc: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x12D0FCu;
    SET_GPR_U32(ctx, 31, 0x12D104u);
    ctx->pc = 0x12D100u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D0FCu;
            // 0x12d100: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D104u; }
        if (ctx->pc != 0x12D104u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D104u; }
        if (ctx->pc != 0x12D104u) { return; }
    }
    ctx->pc = 0x12D104u;
label_12d104:
    // 0x12d104: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12d104u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12d108: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d108u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d10c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12d10cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d110: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x12d110u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x12d114: 0x40f809  jalr        $v0
    ctx->pc = 0x12D114u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12D11Cu);
        ctx->pc = 0x12D118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D114u;
            // 0x12d118: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D11Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D02Cu: goto label_12d02c;
            case 0x12D030u: goto label_12d030;
            case 0x12D050u: goto label_12d050;
            case 0x12D068u: goto label_12d068;
            case 0x12D088u: goto label_12d088;
            case 0x12D090u: goto label_12d090;
            case 0x12D0D8u: goto label_12d0d8;
            case 0x12D104u: goto label_12d104;
            case 0x12D11Cu: goto label_12d11c;
            case 0x12D134u: goto label_12d134;
            case 0x12D140u: goto label_12d140;
            case 0x12D168u: goto label_12d168;
            case 0x12D190u: goto label_12d190;
            case 0x12D194u: goto label_12d194;
            case 0x12D1A0u: goto label_12d1a0;
            case 0x12D1B8u: goto label_12d1b8;
            case 0x12D1D0u: goto label_12d1d0;
            case 0x12D1D8u: goto label_12d1d8;
            case 0x12D1F8u: goto label_12d1f8;
            case 0x12D210u: goto label_12d210;
            case 0x12D218u: goto label_12d218;
            case 0x12D244u: goto label_12d244;
            case 0x12D250u: goto label_12d250;
            case 0x12D258u: goto label_12d258;
            case 0x12D270u: goto label_12d270;
            case 0x12D28Cu: goto label_12d28c;
            case 0x12D2A0u: goto label_12d2a0;
            case 0x12D2A8u: goto label_12d2a8;
            case 0x12D2B0u: goto label_12d2b0;
            case 0x12D2D0u: goto label_12d2d0;
            case 0x12D2D8u: goto label_12d2d8;
            case 0x12D2FCu: goto label_12d2fc;
            case 0x12D300u: goto label_12d300;
            case 0x12D30Cu: goto label_12d30c;
            case 0x12D314u: goto label_12d314;
            case 0x12D318u: goto label_12d318;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D11Cu; }
            if (ctx->pc != 0x12D11Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12D11Cu;
label_12d11c:
    // 0x12d11c: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12d11cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12d120: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d120u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d124: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12d124u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12d128: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x12d128u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x12d12c: 0x40f809  jalr        $v0
    ctx->pc = 0x12D12Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12D134u);
        ctx->pc = 0x12D130u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D12Cu;
            // 0x12d130: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D134u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D02Cu: goto label_12d02c;
            case 0x12D030u: goto label_12d030;
            case 0x12D050u: goto label_12d050;
            case 0x12D068u: goto label_12d068;
            case 0x12D088u: goto label_12d088;
            case 0x12D090u: goto label_12d090;
            case 0x12D0D8u: goto label_12d0d8;
            case 0x12D104u: goto label_12d104;
            case 0x12D11Cu: goto label_12d11c;
            case 0x12D134u: goto label_12d134;
            case 0x12D140u: goto label_12d140;
            case 0x12D168u: goto label_12d168;
            case 0x12D190u: goto label_12d190;
            case 0x12D194u: goto label_12d194;
            case 0x12D1A0u: goto label_12d1a0;
            case 0x12D1B8u: goto label_12d1b8;
            case 0x12D1D0u: goto label_12d1d0;
            case 0x12D1D8u: goto label_12d1d8;
            case 0x12D1F8u: goto label_12d1f8;
            case 0x12D210u: goto label_12d210;
            case 0x12D218u: goto label_12d218;
            case 0x12D244u: goto label_12d244;
            case 0x12D250u: goto label_12d250;
            case 0x12D258u: goto label_12d258;
            case 0x12D270u: goto label_12d270;
            case 0x12D28Cu: goto label_12d28c;
            case 0x12D2A0u: goto label_12d2a0;
            case 0x12D2A8u: goto label_12d2a8;
            case 0x12D2B0u: goto label_12d2b0;
            case 0x12D2D0u: goto label_12d2d0;
            case 0x12D2D8u: goto label_12d2d8;
            case 0x12D2FCu: goto label_12d2fc;
            case 0x12D300u: goto label_12d300;
            case 0x12D30Cu: goto label_12d30c;
            case 0x12D314u: goto label_12d314;
            case 0x12D318u: goto label_12d318;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D134u; }
            if (ctx->pc != 0x12D134u) { return; }
        }
        }
    }
    ctx->pc = 0x12D134u;
label_12d134:
    // 0x12d134: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x12D134u;
    {
        const bool branch_taken_0x12d134 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12D138u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D134u;
            // 0x12d138: 0x260a02d  daddu       $s4, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d134) {
            ctx->pc = 0x12D1D8u;
            goto label_12d1d8;
        }
    }
    ctx->pc = 0x12D13Cu;
    // 0x12d13c: 0x0  nop
    ctx->pc = 0x12d13cu;
    // NOP
label_12d140:
    // 0x12d140: 0xa4802a  slt         $s0, $a1, $a0
    ctx->pc = 0x12d140u;
    SET_GPR_U64(ctx, 16, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x12d144: 0x52000013  beql        $s0, $zero, . + 4 + (0x13 << 2)
    ctx->pc = 0x12D144u;
    {
        const bool branch_taken_0x12d144 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x12d144) {
            ctx->pc = 0x12D148u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12D144u;
            // 0x12d148: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12D194u;
            goto label_12d194;
        }
    }
    ctx->pc = 0x12D14Cu;
    // 0x12d14c: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x12d14cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12d150: 0x80430000  lb          $v1, 0x0($v0)
    ctx->pc = 0x12d150u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12d154: 0x5460000f  bnel        $v1, $zero, . + 4 + (0xF << 2)
    ctx->pc = 0x12D154u;
    {
        const bool branch_taken_0x12d154 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x12d154) {
            ctx->pc = 0x12D158u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12D154u;
            // 0x12d158: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12D194u;
            goto label_12d194;
        }
    }
    ctx->pc = 0x12D15Cu;
    // 0x12d15c: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x12d15cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d160: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x12d160u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x12d164: 0x0  nop
    ctx->pc = 0x12d164u;
    // NOP
label_12d168:
    // 0x12d168: 0xa6102a  slt         $v0, $a1, $a2
    ctx->pc = 0x12d168u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x12d16c: 0x50400008  beql        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x12D16Cu;
    {
        const bool branch_taken_0x12d16c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x12d16c) {
            ctx->pc = 0x12D170u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12D16Cu;
            // 0x12d170: 0xa4802a  slt         $s0, $a1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
        ctx->in_delay_slot = false;
            ctx->pc = 0x12D190u;
            goto label_12d190;
        }
    }
    ctx->pc = 0x12D174u;
    // 0x12d174: 0x8e420014  lw          $v0, 0x14($s2)
    ctx->pc = 0x12d174u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x12d178: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x12d178u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x12d17c: 0x80430000  lb          $v1, 0x0($v0)
    ctx->pc = 0x12d17cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12d180: 0x0  nop
    ctx->pc = 0x12d180u;
    // NOP
    // 0x12d184: 0x5060fff8  beql        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x12D184u;
    {
        const bool branch_taken_0x12d184 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x12d184) {
            ctx->pc = 0x12D188u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12D184u;
            // 0x12d188: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12D168u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12d168;
        }
    }
    ctx->pc = 0x12D18Cu;
    // 0x12d18c: 0xa4802a  slt         $s0, $a1, $a0
    ctx->pc = 0x12d18cu;
    SET_GPR_U64(ctx, 16, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
label_12d190:
    // 0x12d190: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x12d190u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_12d194:
    // 0x12d194: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x12d194u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d198: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x12D198u;
    SET_GPR_U32(ctx, 31, 0x12D1A0u);
    ctx->pc = 0x12D19Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D198u;
            // 0x12d19c: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D1A0u; }
        if (ctx->pc != 0x12D1A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D1A0u; }
        if (ctx->pc != 0x12D1A0u) { return; }
    }
    ctx->pc = 0x12D1A0u;
label_12d1a0:
    // 0x12d1a0: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12d1a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12d1a4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d1a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d1a8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12d1a8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d1ac: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x12d1acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x12d1b0: 0x40f809  jalr        $v0
    ctx->pc = 0x12D1B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12D1B8u);
        ctx->pc = 0x12D1B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D1B0u;
            // 0x12d1b4: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D1B8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D02Cu: goto label_12d02c;
            case 0x12D030u: goto label_12d030;
            case 0x12D050u: goto label_12d050;
            case 0x12D068u: goto label_12d068;
            case 0x12D088u: goto label_12d088;
            case 0x12D090u: goto label_12d090;
            case 0x12D0D8u: goto label_12d0d8;
            case 0x12D104u: goto label_12d104;
            case 0x12D11Cu: goto label_12d11c;
            case 0x12D134u: goto label_12d134;
            case 0x12D140u: goto label_12d140;
            case 0x12D168u: goto label_12d168;
            case 0x12D190u: goto label_12d190;
            case 0x12D194u: goto label_12d194;
            case 0x12D1A0u: goto label_12d1a0;
            case 0x12D1B8u: goto label_12d1b8;
            case 0x12D1D0u: goto label_12d1d0;
            case 0x12D1D8u: goto label_12d1d8;
            case 0x12D1F8u: goto label_12d1f8;
            case 0x12D210u: goto label_12d210;
            case 0x12D218u: goto label_12d218;
            case 0x12D244u: goto label_12d244;
            case 0x12D250u: goto label_12d250;
            case 0x12D258u: goto label_12d258;
            case 0x12D270u: goto label_12d270;
            case 0x12D28Cu: goto label_12d28c;
            case 0x12D2A0u: goto label_12d2a0;
            case 0x12D2A8u: goto label_12d2a8;
            case 0x12D2B0u: goto label_12d2b0;
            case 0x12D2D0u: goto label_12d2d0;
            case 0x12D2D8u: goto label_12d2d8;
            case 0x12D2FCu: goto label_12d2fc;
            case 0x12D300u: goto label_12d300;
            case 0x12D30Cu: goto label_12d30c;
            case 0x12D314u: goto label_12d314;
            case 0x12D318u: goto label_12d318;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D1B8u; }
            if (ctx->pc != 0x12D1B8u) { return; }
        }
        }
    }
    ctx->pc = 0x12D1B8u;
label_12d1b8:
    // 0x12d1b8: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12d1b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12d1bc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d1bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d1c0: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12d1c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12d1c4: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x12d1c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x12d1c8: 0x40f809  jalr        $v0
    ctx->pc = 0x12D1C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12D1D0u);
        ctx->pc = 0x12D1CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D1C8u;
            // 0x12d1cc: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D1D0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D02Cu: goto label_12d02c;
            case 0x12D030u: goto label_12d030;
            case 0x12D050u: goto label_12d050;
            case 0x12D068u: goto label_12d068;
            case 0x12D088u: goto label_12d088;
            case 0x12D090u: goto label_12d090;
            case 0x12D0D8u: goto label_12d0d8;
            case 0x12D104u: goto label_12d104;
            case 0x12D11Cu: goto label_12d11c;
            case 0x12D134u: goto label_12d134;
            case 0x12D140u: goto label_12d140;
            case 0x12D168u: goto label_12d168;
            case 0x12D190u: goto label_12d190;
            case 0x12D194u: goto label_12d194;
            case 0x12D1A0u: goto label_12d1a0;
            case 0x12D1B8u: goto label_12d1b8;
            case 0x12D1D0u: goto label_12d1d0;
            case 0x12D1D8u: goto label_12d1d8;
            case 0x12D1F8u: goto label_12d1f8;
            case 0x12D210u: goto label_12d210;
            case 0x12D218u: goto label_12d218;
            case 0x12D244u: goto label_12d244;
            case 0x12D250u: goto label_12d250;
            case 0x12D258u: goto label_12d258;
            case 0x12D270u: goto label_12d270;
            case 0x12D28Cu: goto label_12d28c;
            case 0x12D2A0u: goto label_12d2a0;
            case 0x12D2A8u: goto label_12d2a8;
            case 0x12D2B0u: goto label_12d2b0;
            case 0x12D2D0u: goto label_12d2d0;
            case 0x12D2D8u: goto label_12d2d8;
            case 0x12D2FCu: goto label_12d2fc;
            case 0x12D300u: goto label_12d300;
            case 0x12D30Cu: goto label_12d30c;
            case 0x12D314u: goto label_12d314;
            case 0x12D318u: goto label_12d318;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D1D0u; }
            if (ctx->pc != 0x12D1D0u) { return; }
        }
        }
    }
    ctx->pc = 0x12D1D0u;
label_12d1d0:
    // 0x12d1d0: 0x16000051  bnez        $s0, . + 4 + (0x51 << 2)
    ctx->pc = 0x12D1D0u;
    {
        const bool branch_taken_0x12d1d0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x12D1D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D1D0u;
            // 0x12d1d4: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d1d0) {
            ctx->pc = 0x12D318u;
            goto label_12d318;
        }
    }
    ctx->pc = 0x12D1D8u;
label_12d1d8:
    // 0x12d1d8: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12d1d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12d1dc: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x12d1dcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x12d1e0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d1e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d1e4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12d1e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12d1e8: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x12d1e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x12d1ec: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x12d1ecu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x12d1f0: 0x40f809  jalr        $v0
    ctx->pc = 0x12D1F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12D1F8u);
        ctx->pc = 0x12D1F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D1F0u;
            // 0x12d1f4: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D1F8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D02Cu: goto label_12d02c;
            case 0x12D030u: goto label_12d030;
            case 0x12D050u: goto label_12d050;
            case 0x12D068u: goto label_12d068;
            case 0x12D088u: goto label_12d088;
            case 0x12D090u: goto label_12d090;
            case 0x12D0D8u: goto label_12d0d8;
            case 0x12D104u: goto label_12d104;
            case 0x12D11Cu: goto label_12d11c;
            case 0x12D134u: goto label_12d134;
            case 0x12D140u: goto label_12d140;
            case 0x12D168u: goto label_12d168;
            case 0x12D190u: goto label_12d190;
            case 0x12D194u: goto label_12d194;
            case 0x12D1A0u: goto label_12d1a0;
            case 0x12D1B8u: goto label_12d1b8;
            case 0x12D1D0u: goto label_12d1d0;
            case 0x12D1D8u: goto label_12d1d8;
            case 0x12D1F8u: goto label_12d1f8;
            case 0x12D210u: goto label_12d210;
            case 0x12D218u: goto label_12d218;
            case 0x12D244u: goto label_12d244;
            case 0x12D250u: goto label_12d250;
            case 0x12D258u: goto label_12d258;
            case 0x12D270u: goto label_12d270;
            case 0x12D28Cu: goto label_12d28c;
            case 0x12D2A0u: goto label_12d2a0;
            case 0x12D2A8u: goto label_12d2a8;
            case 0x12D2B0u: goto label_12d2b0;
            case 0x12D2D0u: goto label_12d2d0;
            case 0x12D2D8u: goto label_12d2d8;
            case 0x12D2FCu: goto label_12d2fc;
            case 0x12D300u: goto label_12d300;
            case 0x12D30Cu: goto label_12d30c;
            case 0x12D314u: goto label_12d314;
            case 0x12D318u: goto label_12d318;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D1F8u; }
            if (ctx->pc != 0x12D1F8u) { return; }
        }
        }
    }
    ctx->pc = 0x12D1F8u;
label_12d1f8:
    // 0x12d1f8: 0x8e440018  lw          $a0, 0x18($s2)
    ctx->pc = 0x12d1f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
    // 0x12d1fc: 0x1480ffd0  bnez        $a0, . + 4 + (-0x30 << 2)
    ctx->pc = 0x12D1FCu;
    {
        const bool branch_taken_0x12d1fc = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x12D200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D1FCu;
            // 0x12d200: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d1fc) {
            ctx->pc = 0x12D140u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12d140;
        }
    }
    ctx->pc = 0x12D204u;
    // 0x12d204: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x12D204u;
    {
        const bool branch_taken_0x12d204 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12D208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D204u;
            // 0x12d208: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d204) {
            ctx->pc = 0x12D318u;
            goto label_12d318;
        }
    }
    ctx->pc = 0x12D20Cu;
    // 0x12d20c: 0x0  nop
    ctx->pc = 0x12d20cu;
    // NOP
label_12d210:
    // 0x12d210: 0xc04b602  jal         func_12D808
    ctx->pc = 0x12D210u;
    SET_GPR_U32(ctx, 31, 0x12D218u);
    ctx->pc = 0x12D214u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D210u;
            // 0x12d214: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D808u;
    if (runtime->hasFunction(0x12D808u)) {
        auto targetFn = runtime->lookupFunction(0x12D808u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D218u; }
        if (ctx->pc != 0x12D218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D808_0x12d808(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D218u; }
        if (ctx->pc != 0x12D218u) { return; }
    }
    ctx->pc = 0x12D218u;
label_12d218:
    // 0x12d218: 0x8e430034  lw          $v1, 0x34($s2)
    ctx->pc = 0x12d218u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 52)));
    // 0x12d21c: 0x62182a  slt         $v1, $v1, $v0
    ctx->pc = 0x12d21cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x12d220: 0x1460000b  bnez        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x12D220u;
    {
        const bool branch_taken_0x12d220 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12D224u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D220u;
            // 0x12d224: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d220) {
            ctx->pc = 0x12D250u;
            goto label_12d250;
        }
    }
    ctx->pc = 0x12D228u;
    // 0x12d228: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d228u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d22c: 0xa2420001  sb          $v0, 0x1($s2)
    ctx->pc = 0x12d22cu;
    WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x12d230: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x12d230u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d234: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x12d234u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12d238: 0x8c43001c  lw          $v1, 0x1C($v0)
    ctx->pc = 0x12d238u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x12d23c: 0x60f809  jalr        $v1
    ctx->pc = 0x12D23Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x12D244u);
        ctx->pc = 0x12D240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D23Cu;
            // 0x12d240: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D244u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D02Cu: goto label_12d02c;
            case 0x12D030u: goto label_12d030;
            case 0x12D050u: goto label_12d050;
            case 0x12D068u: goto label_12d068;
            case 0x12D088u: goto label_12d088;
            case 0x12D090u: goto label_12d090;
            case 0x12D0D8u: goto label_12d0d8;
            case 0x12D104u: goto label_12d104;
            case 0x12D11Cu: goto label_12d11c;
            case 0x12D134u: goto label_12d134;
            case 0x12D140u: goto label_12d140;
            case 0x12D168u: goto label_12d168;
            case 0x12D190u: goto label_12d190;
            case 0x12D194u: goto label_12d194;
            case 0x12D1A0u: goto label_12d1a0;
            case 0x12D1B8u: goto label_12d1b8;
            case 0x12D1D0u: goto label_12d1d0;
            case 0x12D1D8u: goto label_12d1d8;
            case 0x12D1F8u: goto label_12d1f8;
            case 0x12D210u: goto label_12d210;
            case 0x12D218u: goto label_12d218;
            case 0x12D244u: goto label_12d244;
            case 0x12D250u: goto label_12d250;
            case 0x12D258u: goto label_12d258;
            case 0x12D270u: goto label_12d270;
            case 0x12D28Cu: goto label_12d28c;
            case 0x12D2A0u: goto label_12d2a0;
            case 0x12D2A8u: goto label_12d2a8;
            case 0x12D2B0u: goto label_12d2b0;
            case 0x12D2D0u: goto label_12d2d0;
            case 0x12D2D8u: goto label_12d2d8;
            case 0x12D2FCu: goto label_12d2fc;
            case 0x12D300u: goto label_12d300;
            case 0x12D30Cu: goto label_12d30c;
            case 0x12D314u: goto label_12d314;
            case 0x12D318u: goto label_12d318;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D244u; }
            if (ctx->pc != 0x12D244u) { return; }
        }
        }
    }
    ctx->pc = 0x12D244u;
label_12d244:
    // 0x12d244: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x12D244u;
    {
        const bool branch_taken_0x12d244 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12D248u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D244u;
            // 0x12d248: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d244) {
            ctx->pc = 0x12D318u;
            goto label_12d318;
        }
    }
    ctx->pc = 0x12D24Cu;
    // 0x12d24c: 0x0  nop
    ctx->pc = 0x12d24cu;
    // NOP
label_12d250:
    // 0x12d250: 0xc04b5f6  jal         func_12D7D8
    ctx->pc = 0x12D250u;
    SET_GPR_U32(ctx, 31, 0x12D258u);
    ctx->pc = 0x12D254u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D250u;
            // 0x12d254: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D7D8u;
    if (runtime->hasFunction(0x12D7D8u)) {
        auto targetFn = runtime->lookupFunction(0x12D7D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D258u; }
        if (ctx->pc != 0x12D258u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D7D8_0x12d7d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D258u; }
        if (ctx->pc != 0x12D258u) { return; }
    }
    ctx->pc = 0x12D258u;
label_12d258:
    // 0x12d258: 0x8e44000c  lw          $a0, 0xC($s2)
    ctx->pc = 0x12d258u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x12d25c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12d25cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d260: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x12d260u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12d264: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x12d264u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x12d268: 0x40f809  jalr        $v0
    ctx->pc = 0x12D268u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12D270u);
        ctx->pc = 0x12D26Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D268u;
            // 0x12d26c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D270u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D02Cu: goto label_12d02c;
            case 0x12D030u: goto label_12d030;
            case 0x12D050u: goto label_12d050;
            case 0x12D068u: goto label_12d068;
            case 0x12D088u: goto label_12d088;
            case 0x12D090u: goto label_12d090;
            case 0x12D0D8u: goto label_12d0d8;
            case 0x12D104u: goto label_12d104;
            case 0x12D11Cu: goto label_12d11c;
            case 0x12D134u: goto label_12d134;
            case 0x12D140u: goto label_12d140;
            case 0x12D168u: goto label_12d168;
            case 0x12D190u: goto label_12d190;
            case 0x12D194u: goto label_12d194;
            case 0x12D1A0u: goto label_12d1a0;
            case 0x12D1B8u: goto label_12d1b8;
            case 0x12D1D0u: goto label_12d1d0;
            case 0x12D1D8u: goto label_12d1d8;
            case 0x12D1F8u: goto label_12d1f8;
            case 0x12D210u: goto label_12d210;
            case 0x12D218u: goto label_12d218;
            case 0x12D244u: goto label_12d244;
            case 0x12D250u: goto label_12d250;
            case 0x12D258u: goto label_12d258;
            case 0x12D270u: goto label_12d270;
            case 0x12D28Cu: goto label_12d28c;
            case 0x12D2A0u: goto label_12d2a0;
            case 0x12D2A8u: goto label_12d2a8;
            case 0x12D2B0u: goto label_12d2b0;
            case 0x12D2D0u: goto label_12d2d0;
            case 0x12D2D8u: goto label_12d2d8;
            case 0x12D2FCu: goto label_12d2fc;
            case 0x12D300u: goto label_12d300;
            case 0x12D30Cu: goto label_12d30c;
            case 0x12D314u: goto label_12d314;
            case 0x12D318u: goto label_12d318;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D270u; }
            if (ctx->pc != 0x12D270u) { return; }
        }
        }
    }
    ctx->pc = 0x12D270u;
label_12d270:
    // 0x12d270: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x12d270u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x12d274: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x12d274u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x12d278: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x12d278u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
    // 0x12d27c: 0x70182a  slt         $v1, $v1, $s0
    ctx->pc = 0x12d27cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x12d280: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x12D280u;
    {
        const bool branch_taken_0x12d280 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x12d280) {
            ctx->pc = 0x12D2A8u;
            goto label_12d2a8;
        }
    }
    ctx->pc = 0x12D288u;
    // 0x12d288: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12d288u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_12d28c:
    // 0x12d28c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d28cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d290: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x12d290u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d294: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x12d294u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x12d298: 0x40f809  jalr        $v0
    ctx->pc = 0x12D298u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12D2A0u);
        ctx->pc = 0x12D29Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D298u;
            // 0x12d29c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D2A0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D02Cu: goto label_12d02c;
            case 0x12D030u: goto label_12d030;
            case 0x12D050u: goto label_12d050;
            case 0x12D068u: goto label_12d068;
            case 0x12D088u: goto label_12d088;
            case 0x12D090u: goto label_12d090;
            case 0x12D0D8u: goto label_12d0d8;
            case 0x12D104u: goto label_12d104;
            case 0x12D11Cu: goto label_12d11c;
            case 0x12D134u: goto label_12d134;
            case 0x12D140u: goto label_12d140;
            case 0x12D168u: goto label_12d168;
            case 0x12D190u: goto label_12d190;
            case 0x12D194u: goto label_12d194;
            case 0x12D1A0u: goto label_12d1a0;
            case 0x12D1B8u: goto label_12d1b8;
            case 0x12D1D0u: goto label_12d1d0;
            case 0x12D1D8u: goto label_12d1d8;
            case 0x12D1F8u: goto label_12d1f8;
            case 0x12D210u: goto label_12d210;
            case 0x12D218u: goto label_12d218;
            case 0x12D244u: goto label_12d244;
            case 0x12D250u: goto label_12d250;
            case 0x12D258u: goto label_12d258;
            case 0x12D270u: goto label_12d270;
            case 0x12D28Cu: goto label_12d28c;
            case 0x12D2A0u: goto label_12d2a0;
            case 0x12D2A8u: goto label_12d2a8;
            case 0x12D2B0u: goto label_12d2b0;
            case 0x12D2D0u: goto label_12d2d0;
            case 0x12D2D8u: goto label_12d2d8;
            case 0x12D2FCu: goto label_12d2fc;
            case 0x12D300u: goto label_12d300;
            case 0x12D30Cu: goto label_12d30c;
            case 0x12D314u: goto label_12d314;
            case 0x12D318u: goto label_12d318;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D2A0u; }
            if (ctx->pc != 0x12D2A0u) { return; }
        }
        }
    }
    ctx->pc = 0x12D2A0u;
label_12d2a0:
    // 0x12d2a0: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x12D2A0u;
    {
        const bool branch_taken_0x12d2a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12D2A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D2A0u;
            // 0x12d2a4: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d2a0) {
            ctx->pc = 0x12D318u;
            goto label_12d318;
        }
    }
    ctx->pc = 0x12D2A8u;
label_12d2a8:
    // 0x12d2a8: 0xc04939a  jal         func_124E68
    ctx->pc = 0x12D2A8u;
    SET_GPR_U32(ctx, 31, 0x12D2B0u);
    ctx->pc = 0x12D2ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D2A8u;
            // 0x12d2ac: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124E68u;
    if (runtime->hasFunction(0x124E68u)) {
        auto targetFn = runtime->lookupFunction(0x124E68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D2B0u; }
        if (ctx->pc != 0x12D2B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124E68_0x124e68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D2B0u; }
        if (ctx->pc != 0x12D2B0u) { return; }
    }
    ctx->pc = 0x12D2B0u;
label_12d2b0:
    // 0x12d2b0: 0x2403000a  addiu       $v1, $zero, 0xA
    ctx->pc = 0x12d2b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x12d2b4: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x12D2B4u;
    {
        const bool branch_taken_0x12d2b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x12D2B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D2B4u;
            // 0x12d2b8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d2b4) {
            ctx->pc = 0x12D2D0u;
            goto label_12d2d0;
        }
    }
    ctx->pc = 0x12D2BCu;
    // 0x12d2bc: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12d2bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12d2c0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d2c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d2c4: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x12d2c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x12d2c8: 0x40f809  jalr        $v0
    ctx->pc = 0x12D2C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12D2D0u);
        ctx->pc = 0x12D2CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D2C8u;
            // 0x12d2cc: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D2D0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D02Cu: goto label_12d02c;
            case 0x12D030u: goto label_12d030;
            case 0x12D050u: goto label_12d050;
            case 0x12D068u: goto label_12d068;
            case 0x12D088u: goto label_12d088;
            case 0x12D090u: goto label_12d090;
            case 0x12D0D8u: goto label_12d0d8;
            case 0x12D104u: goto label_12d104;
            case 0x12D11Cu: goto label_12d11c;
            case 0x12D134u: goto label_12d134;
            case 0x12D140u: goto label_12d140;
            case 0x12D168u: goto label_12d168;
            case 0x12D190u: goto label_12d190;
            case 0x12D194u: goto label_12d194;
            case 0x12D1A0u: goto label_12d1a0;
            case 0x12D1B8u: goto label_12d1b8;
            case 0x12D1D0u: goto label_12d1d0;
            case 0x12D1D8u: goto label_12d1d8;
            case 0x12D1F8u: goto label_12d1f8;
            case 0x12D210u: goto label_12d210;
            case 0x12D218u: goto label_12d218;
            case 0x12D244u: goto label_12d244;
            case 0x12D250u: goto label_12d250;
            case 0x12D258u: goto label_12d258;
            case 0x12D270u: goto label_12d270;
            case 0x12D28Cu: goto label_12d28c;
            case 0x12D2A0u: goto label_12d2a0;
            case 0x12D2A8u: goto label_12d2a8;
            case 0x12D2B0u: goto label_12d2b0;
            case 0x12D2D0u: goto label_12d2d0;
            case 0x12D2D8u: goto label_12d2d8;
            case 0x12D2FCu: goto label_12d2fc;
            case 0x12D300u: goto label_12d300;
            case 0x12D30Cu: goto label_12d30c;
            case 0x12D314u: goto label_12d314;
            case 0x12D318u: goto label_12d318;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D2D0u; }
            if (ctx->pc != 0x12D2D0u) { return; }
        }
        }
    }
    ctx->pc = 0x12D2D0u;
label_12d2d0:
    // 0x12d2d0: 0xc04939a  jal         func_124E68
    ctx->pc = 0x12D2D0u;
    SET_GPR_U32(ctx, 31, 0x12D2D8u);
    ctx->pc = 0x12D2D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D2D0u;
            // 0x12d2d4: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124E68u;
    if (runtime->hasFunction(0x124E68u)) {
        auto targetFn = runtime->lookupFunction(0x124E68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D2D8u; }
        if (ctx->pc != 0x12D2D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124E68_0x124e68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D2D8u; }
        if (ctx->pc != 0x12D2D8u) { return; }
    }
    ctx->pc = 0x12D2D8u;
label_12d2d8:
    // 0x12d2d8: 0x2403000f  addiu       $v1, $zero, 0xF
    ctx->pc = 0x12d2d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x12d2dc: 0x54430008  bnel        $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x12D2DCu;
    {
        const bool branch_taken_0x12d2dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x12d2dc) {
            ctx->pc = 0x12D2E0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12D2DCu;
            // 0x12d2e0: 0x8e460018  lw          $a2, 0x18($s2) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12D300u;
            goto label_12d300;
        }
    }
    ctx->pc = 0x12D2E4u;
    // 0x12d2e4: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12d2e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12d2e8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d2e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d2ec: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x12d2ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d2f0: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x12d2f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x12d2f4: 0x40f809  jalr        $v0
    ctx->pc = 0x12D2F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12D2FCu);
        ctx->pc = 0x12D2F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D2F4u;
            // 0x12d2f8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D2FCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D02Cu: goto label_12d02c;
            case 0x12D030u: goto label_12d030;
            case 0x12D050u: goto label_12d050;
            case 0x12D068u: goto label_12d068;
            case 0x12D088u: goto label_12d088;
            case 0x12D090u: goto label_12d090;
            case 0x12D0D8u: goto label_12d0d8;
            case 0x12D104u: goto label_12d104;
            case 0x12D11Cu: goto label_12d11c;
            case 0x12D134u: goto label_12d134;
            case 0x12D140u: goto label_12d140;
            case 0x12D168u: goto label_12d168;
            case 0x12D190u: goto label_12d190;
            case 0x12D194u: goto label_12d194;
            case 0x12D1A0u: goto label_12d1a0;
            case 0x12D1B8u: goto label_12d1b8;
            case 0x12D1D0u: goto label_12d1d0;
            case 0x12D1D8u: goto label_12d1d8;
            case 0x12D1F8u: goto label_12d1f8;
            case 0x12D210u: goto label_12d210;
            case 0x12D218u: goto label_12d218;
            case 0x12D244u: goto label_12d244;
            case 0x12D250u: goto label_12d250;
            case 0x12D258u: goto label_12d258;
            case 0x12D270u: goto label_12d270;
            case 0x12D28Cu: goto label_12d28c;
            case 0x12D2A0u: goto label_12d2a0;
            case 0x12D2A8u: goto label_12d2a8;
            case 0x12D2B0u: goto label_12d2b0;
            case 0x12D2D0u: goto label_12d2d0;
            case 0x12D2D8u: goto label_12d2d8;
            case 0x12D2FCu: goto label_12d2fc;
            case 0x12D300u: goto label_12d300;
            case 0x12D30Cu: goto label_12d30c;
            case 0x12D314u: goto label_12d314;
            case 0x12D318u: goto label_12d318;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D2FCu; }
            if (ctx->pc != 0x12D2FCu) { return; }
        }
        }
    }
    ctx->pc = 0x12D2FCu;
label_12d2fc:
    // 0x12d2fc: 0x8e460018  lw          $a2, 0x18($s2)
    ctx->pc = 0x12d2fcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
label_12d300:
    // 0x12d300: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x12d300u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d304: 0xc04946a  jal         func_1251A8
    ctx->pc = 0x12D304u;
    SET_GPR_U32(ctx, 31, 0x12D30Cu);
    ctx->pc = 0x12D308u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D304u;
            // 0x12d308: 0x8e450014  lw          $a1, 0x14($s2) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1251A8u;
    if (runtime->hasFunction(0x1251A8u)) {
        auto targetFn = runtime->lookupFunction(0x1251A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D30Cu; }
        if (ctx->pc != 0x12D30Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001251A8_0x1251a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D30Cu; }
        if (ctx->pc != 0x12D30Cu) { return; }
    }
    ctx->pc = 0x12D30Cu;
label_12d30c:
    // 0x12d30c: 0xc04948c  jal         func_125230
    ctx->pc = 0x12D30Cu;
    SET_GPR_U32(ctx, 31, 0x12D314u);
    ctx->pc = 0x12D310u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D30Cu;
            // 0x12d310: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125230u;
    if (runtime->hasFunction(0x125230u)) {
        auto targetFn = runtime->lookupFunction(0x125230u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D314u; }
        if (ctx->pc != 0x12D314u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00125230_0x125230(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D314u; }
        if (ctx->pc != 0x12D314u) { return; }
    }
    ctx->pc = 0x12D314u;
label_12d314:
    // 0x12d314: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x12d314u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_12d318:
    // 0x12d318: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x12d318u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12d31c: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x12d31cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12d320: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x12d320u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12d324: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x12d324u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12d328: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x12d328u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x12d32c: 0x3e00008  jr          $ra
    ctx->pc = 0x12D32Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D330u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D32Cu;
            // 0x12d330: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D02Cu: goto label_12d02c;
            case 0x12D030u: goto label_12d030;
            case 0x12D050u: goto label_12d050;
            case 0x12D068u: goto label_12d068;
            case 0x12D088u: goto label_12d088;
            case 0x12D090u: goto label_12d090;
            case 0x12D0D8u: goto label_12d0d8;
            case 0x12D104u: goto label_12d104;
            case 0x12D11Cu: goto label_12d11c;
            case 0x12D134u: goto label_12d134;
            case 0x12D140u: goto label_12d140;
            case 0x12D168u: goto label_12d168;
            case 0x12D190u: goto label_12d190;
            case 0x12D194u: goto label_12d194;
            case 0x12D1A0u: goto label_12d1a0;
            case 0x12D1B8u: goto label_12d1b8;
            case 0x12D1D0u: goto label_12d1d0;
            case 0x12D1D8u: goto label_12d1d8;
            case 0x12D1F8u: goto label_12d1f8;
            case 0x12D210u: goto label_12d210;
            case 0x12D218u: goto label_12d218;
            case 0x12D244u: goto label_12d244;
            case 0x12D250u: goto label_12d250;
            case 0x12D258u: goto label_12d258;
            case 0x12D270u: goto label_12d270;
            case 0x12D28Cu: goto label_12d28c;
            case 0x12D2A0u: goto label_12d2a0;
            case 0x12D2A8u: goto label_12d2a8;
            case 0x12D2B0u: goto label_12d2b0;
            case 0x12D2D0u: goto label_12d2d0;
            case 0x12D2D8u: goto label_12d2d8;
            case 0x12D2FCu: goto label_12d2fc;
            case 0x12D300u: goto label_12d300;
            case 0x12D30Cu: goto label_12d30c;
            case 0x12D314u: goto label_12d314;
            case 0x12D318u: goto label_12d318;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12D334u;
    // 0x12d334: 0x0  nop
    ctx->pc = 0x12d334u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
