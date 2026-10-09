#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013FD58
// Address: 0x13fd58 - 0x13fef0
void sub_0013FD58_0x13fd58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013FD58_0x13fd58");
#endif

    switch (ctx->pc) {
        case 0x13fd94u: goto label_13fd94;
        case 0x13fe0cu: goto label_13fe0c;
        case 0x13fe94u: goto label_13fe94;
        case 0x13fec0u: goto label_13fec0;
        default: break;
    }

    ctx->pc = 0x13fd58u;

    // 0x13fd58: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13fd58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13fd5c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13fd5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13fd60: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13fd60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13fd64: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13fd64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13fd68: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x13fd68u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13fd6c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13fd6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13fd70: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x13fd70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13fd74: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13fd74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fd78: 0x18400057  blez        $v0, . + 4 + (0x57 << 2)
    ctx->pc = 0x13FD78u;
    {
        const bool branch_taken_0x13fd78 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x13FD7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FD78u;
            // 0x13fd7c: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fd78) {
            ctx->pc = 0x13FED8u;
            goto label_13fed8;
        }
    }
    ctx->pc = 0x13FD80u;
    // 0x13fd80: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x13fd80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13fd84: 0x50400055  beql        $v0, $zero, . + 4 + (0x55 << 2)
    ctx->pc = 0x13FD84u;
    {
        const bool branch_taken_0x13fd84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fd84) {
            ctx->pc = 0x13FD88u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FD84u;
            // 0x13fd88: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FEDCu;
            goto label_13fedc;
        }
    }
    ctx->pc = 0x13FD8Cu;
    // 0x13fd8c: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13FD8Cu;
    SET_GPR_U32(ctx, 31, 0x13FD94u);
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FD94u; }
        if (ctx->pc != 0x13FD94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FD94u; }
        if (ctx->pc != 0x13FD94u) { return; }
    }
    ctx->pc = 0x13FD94u;
label_13fd94:
    // 0x13fd94: 0x16400022  bnez        $s2, . + 4 + (0x22 << 2)
    ctx->pc = 0x13FD94u;
    {
        const bool branch_taken_0x13fd94 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x13FD98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FD94u;
            // 0x13fd98: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fd94) {
            ctx->pc = 0x13FE20u;
            goto label_13fe20;
        }
    }
    ctx->pc = 0x13FD9Cu;
    // 0x13fd9c: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x13fd9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13fda0: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x13fda0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x13fda4: 0x8e270004  lw          $a3, 0x4($s1)
    ctx->pc = 0x13fda4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fda8: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13FDA8u;
    {
        const bool branch_taken_0x13fda8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fda8) {
            ctx->pc = 0x13FDACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FDA8u;
            // 0x13fdac: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FDB0u;
            goto label_13fdb0;
        }
    }
    ctx->pc = 0x13FDB0u;
label_13fdb0:
    // 0x13fdb0: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x13fdb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13fdb4: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x13fdb4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13fdb8: 0x671823  subu        $v1, $v1, $a3
    ctx->pc = 0x13fdb8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x13fdbc: 0x8e05001c  lw          $a1, 0x1C($s0)
    ctx->pc = 0x13fdbcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x13fdc0: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x13fdc0u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x13fdc4: 0x852023  subu        $a0, $a0, $a1
    ctx->pc = 0x13fdc4u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x13fdc8: 0x3010  mfhi        $a2
    ctx->pc = 0x13fdc8u;
    SET_GPR_U64(ctx, 6, ctx->hi);
    // 0x13fdcc: 0x82001a  div         $zero, $a0, $v0
    ctx->pc = 0x13fdccu;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x13fdd0: 0x1810  mfhi        $v1
    ctx->pc = 0x13fdd0u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x13fdd4: 0x54c30008  bnel        $a2, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x13FDD4u;
    {
        const bool branch_taken_0x13fdd4 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 3));
        if (branch_taken_0x13fdd4) {
            ctx->pc = 0x13FDD8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FDD4u;
            // 0x13fdd8: 0x8e020038  lw          $v0, 0x38($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FDF8u;
            goto label_13fdf8;
        }
    }
    ctx->pc = 0x13FDDCu;
    // 0x13fddc: 0xae060014  sw          $a2, 0x14($s0)
    ctx->pc = 0x13fddcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 6));
    // 0x13fde0: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x13fde0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x13fde4: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13fde4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fde8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x13fde8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x13fdec: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x13FDECu;
    {
        const bool branch_taken_0x13fdec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FDF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FDECu;
            // 0x13fdf0: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fdec) {
            ctx->pc = 0x13FE0Cu;
            goto label_13fe0c;
        }
    }
    ctx->pc = 0x13FDF4u;
    // 0x13fdf4: 0x0  nop
    ctx->pc = 0x13fdf4u;
    // NOP
label_13fdf8:
    // 0x13fdf8: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x13FDF8u;
    {
        const bool branch_taken_0x13fdf8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fdf8) {
            ctx->pc = 0x13FDFCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FDF8u;
            // 0x13fdfc: 0x8e020028  lw          $v0, 0x28($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FE14u;
            goto label_13fe14;
        }
    }
    ctx->pc = 0x13FE00u;
    // 0x13fe00: 0x8e04003c  lw          $a0, 0x3C($s0)
    ctx->pc = 0x13fe00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x13fe04: 0x40f809  jalr        $v0
    ctx->pc = 0x13FE04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13FE0Cu);
        ctx->pc = 0x13FE08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FE04u;
            // 0x13fe08: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13FE0Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FD94u: goto label_13fd94;
            case 0x13FDB0u: goto label_13fdb0;
            case 0x13FDF8u: goto label_13fdf8;
            case 0x13FE0Cu: goto label_13fe0c;
            case 0x13FE14u: goto label_13fe14;
            case 0x13FE20u: goto label_13fe20;
            case 0x13FE38u: goto label_13fe38;
            case 0x13FE80u: goto label_13fe80;
            case 0x13FE94u: goto label_13fe94;
            case 0x13FE9Cu: goto label_13fe9c;
            case 0x13FEA8u: goto label_13fea8;
            case 0x13FEC0u: goto label_13fec0;
            case 0x13FED8u: goto label_13fed8;
            case 0x13FEDCu: goto label_13fedc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13FE0Cu; }
            if (ctx->pc != 0x13FE0Cu) { return; }
        }
        }
    }
    ctx->pc = 0x13FE0Cu;
label_13fe0c:
    // 0x13fe0c: 0x8e270004  lw          $a3, 0x4($s1)
    ctx->pc = 0x13fe0cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fe10: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x13fe10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
label_13fe14:
    // 0x13fe14: 0x471023  subu        $v0, $v0, $a3
    ctx->pc = 0x13fe14u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x13fe18: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x13FE18u;
    {
        const bool branch_taken_0x13fe18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FE1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FE18u;
            // 0x13fe1c: 0xae020028  sw          $v0, 0x28($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fe18) {
            ctx->pc = 0x13FEC0u;
            goto label_13fec0;
        }
    }
    ctx->pc = 0x13FE20u;
label_13fe20:
    // 0x13fe20: 0x56420021  bnel        $s2, $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x13FE20u;
    {
        const bool branch_taken_0x13fe20 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x13fe20) {
            ctx->pc = 0x13FE24u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FE20u;
            // 0x13fe24: 0x8e020038  lw          $v0, 0x38($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FEA8u;
            goto label_13fea8;
        }
    }
    ctx->pc = 0x13FE28u;
    // 0x13fe28: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x13fe28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13fe2c: 0x8e040018  lw          $a0, 0x18($s0)
    ctx->pc = 0x13fe2cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x13fe30: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13FE30u;
    {
        const bool branch_taken_0x13fe30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fe30) {
            ctx->pc = 0x13FE34u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FE30u;
            // 0x13fe34: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FE38u;
            goto label_13fe38;
        }
    }
    ctx->pc = 0x13FE38u;
label_13fe38:
    // 0x13fe38: 0x8e250000  lw          $a1, 0x0($s1)
    ctx->pc = 0x13fe38u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13fe3c: 0x8e03001c  lw          $v1, 0x1C($s0)
    ctx->pc = 0x13fe3cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x13fe40: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x13fe40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13fe44: 0x8e270004  lw          $a3, 0x4($s1)
    ctx->pc = 0x13fe44u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fe48: 0xa32823  subu        $a1, $a1, $v1
    ctx->pc = 0x13fe48u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x13fe4c: 0x872023  subu        $a0, $a0, $a3
    ctx->pc = 0x13fe4cu;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x13fe50: 0x70a2001a  div1        $zero, $a1, $v0
    ctx->pc = 0x13fe50u;
    { int32_t divisor = GPR_S32(ctx, 2); int32_t dividend = GPR_S32(ctx, 5); if (divisor != 0) {     if (divisor == -1 && dividend == INT32_MIN) {         ctx->lo1 = (uint64_t)(int64_t)INT32_MIN; ctx->hi1 = 0;     } else {         ctx->lo1 = (uint64_t)(int64_t)(dividend / divisor);         ctx->hi1 = (uint64_t)(int64_t)(dividend % divisor);     } } else {     ctx->lo1 = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi1 = (uint64_t)(int64_t)dividend; } }
    // 0x13fe54: 0x82001a  div         $zero, $a0, $v0
    ctx->pc = 0x13fe54u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x13fe58: 0x70001810  mfhi1       $v1
    ctx->pc = 0x13fe58u;
    SET_GPR_U64(ctx, 3, ctx->hi1);
    // 0x13fe5c: 0x2010  mfhi        $a0
    ctx->pc = 0x13fe5cu;
    SET_GPR_U64(ctx, 4, ctx->hi);
    // 0x13fe60: 0x54830007  bnel        $a0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x13FE60u;
    {
        const bool branch_taken_0x13fe60 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x13fe60) {
            ctx->pc = 0x13FE64u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FE60u;
            // 0x13fe64: 0x8e020038  lw          $v0, 0x38($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FE80u;
            goto label_13fe80;
        }
    }
    ctx->pc = 0x13FE68u;
    // 0x13fe68: 0xae040018  sw          $a0, 0x18($s0)
    ctx->pc = 0x13fe68u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 4));
    // 0x13fe6c: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x13fe6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x13fe70: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13fe70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fe74: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x13fe74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x13fe78: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x13FE78u;
    {
        const bool branch_taken_0x13fe78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FE7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FE78u;
            // 0x13fe7c: 0xae02000c  sw          $v0, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fe78) {
            ctx->pc = 0x13FE94u;
            goto label_13fe94;
        }
    }
    ctx->pc = 0x13FE80u;
label_13fe80:
    // 0x13fe80: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x13FE80u;
    {
        const bool branch_taken_0x13fe80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fe80) {
            ctx->pc = 0x13FE84u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FE80u;
            // 0x13fe84: 0x8e020030  lw          $v0, 0x30($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FE9Cu;
            goto label_13fe9c;
        }
    }
    ctx->pc = 0x13FE88u;
    // 0x13fe88: 0x8e04003c  lw          $a0, 0x3C($s0)
    ctx->pc = 0x13fe88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x13fe8c: 0x40f809  jalr        $v0
    ctx->pc = 0x13FE8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13FE94u);
        ctx->pc = 0x13FE90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FE8Cu;
            // 0x13fe90: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13FE94u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FD94u: goto label_13fd94;
            case 0x13FDB0u: goto label_13fdb0;
            case 0x13FDF8u: goto label_13fdf8;
            case 0x13FE0Cu: goto label_13fe0c;
            case 0x13FE14u: goto label_13fe14;
            case 0x13FE20u: goto label_13fe20;
            case 0x13FE38u: goto label_13fe38;
            case 0x13FE80u: goto label_13fe80;
            case 0x13FE94u: goto label_13fe94;
            case 0x13FE9Cu: goto label_13fe9c;
            case 0x13FEA8u: goto label_13fea8;
            case 0x13FEC0u: goto label_13fec0;
            case 0x13FED8u: goto label_13fed8;
            case 0x13FEDCu: goto label_13fedc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13FE94u; }
            if (ctx->pc != 0x13FE94u) { return; }
        }
        }
    }
    ctx->pc = 0x13FE94u;
label_13fe94:
    // 0x13fe94: 0x8e270004  lw          $a3, 0x4($s1)
    ctx->pc = 0x13fe94u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fe98: 0x8e020030  lw          $v0, 0x30($s0)
    ctx->pc = 0x13fe98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
label_13fe9c:
    // 0x13fe9c: 0x471023  subu        $v0, $v0, $a3
    ctx->pc = 0x13fe9cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x13fea0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x13FEA0u;
    {
        const bool branch_taken_0x13fea0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FEA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FEA0u;
            // 0x13fea4: 0xae020030  sw          $v0, 0x30($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fea0) {
            ctx->pc = 0x13FEC0u;
            goto label_13fec0;
        }
    }
    ctx->pc = 0x13FEA8u;
label_13fea8:
    // 0x13fea8: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x13fea8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x13feac: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13FEACu;
    {
        const bool branch_taken_0x13feac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FEB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FEACu;
            // 0x13feb0: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13feac) {
            ctx->pc = 0x13FEC0u;
            goto label_13fec0;
        }
    }
    ctx->pc = 0x13FEB4u;
    // 0x13feb4: 0x8e04003c  lw          $a0, 0x3C($s0)
    ctx->pc = 0x13feb4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x13feb8: 0x40f809  jalr        $v0
    ctx->pc = 0x13FEB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13FEC0u);
        ctx->pc = 0x13FEBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FEB8u;
            // 0x13febc: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13FEC0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FD94u: goto label_13fd94;
            case 0x13FDB0u: goto label_13fdb0;
            case 0x13FDF8u: goto label_13fdf8;
            case 0x13FE0Cu: goto label_13fe0c;
            case 0x13FE14u: goto label_13fe14;
            case 0x13FE20u: goto label_13fe20;
            case 0x13FE38u: goto label_13fe38;
            case 0x13FE80u: goto label_13fe80;
            case 0x13FE94u: goto label_13fe94;
            case 0x13FE9Cu: goto label_13fe9c;
            case 0x13FEA8u: goto label_13fea8;
            case 0x13FEC0u: goto label_13fec0;
            case 0x13FED8u: goto label_13fed8;
            case 0x13FEDCu: goto label_13fedc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13FEC0u; }
            if (ctx->pc != 0x13FEC0u) { return; }
        }
        }
    }
    ctx->pc = 0x13FEC0u;
label_13fec0:
    // 0x13fec0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13fec0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13fec4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13fec4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13fec8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13fec8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13fecc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13feccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13fed0: 0x804fc9c  j           func_13F270
    ctx->pc = 0x13FED0u;
    ctx->pc = 0x13FED4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13FED0u;
            // 0x13fed4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13FED8u;
label_13fed8:
    // 0x13fed8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13fed8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13fedc:
    // 0x13fedc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13fedcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13fee0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13fee0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13fee4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13fee4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13fee8: 0x3e00008  jr          $ra
    ctx->pc = 0x13FEE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13FEECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FEE8u;
            // 0x13feec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FD94u: goto label_13fd94;
            case 0x13FDB0u: goto label_13fdb0;
            case 0x13FDF8u: goto label_13fdf8;
            case 0x13FE0Cu: goto label_13fe0c;
            case 0x13FE14u: goto label_13fe14;
            case 0x13FE20u: goto label_13fe20;
            case 0x13FE38u: goto label_13fe38;
            case 0x13FE80u: goto label_13fe80;
            case 0x13FE94u: goto label_13fe94;
            case 0x13FE9Cu: goto label_13fe9c;
            case 0x13FEA8u: goto label_13fea8;
            case 0x13FEC0u: goto label_13fec0;
            case 0x13FED8u: goto label_13fed8;
            case 0x13FEDCu: goto label_13fedc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13FEF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
