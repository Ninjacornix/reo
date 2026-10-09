#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CDFE0
// Address: 0x1cdfe0 - 0x1ce110
void sub_001CDFE0_0x1cdfe0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CDFE0_0x1cdfe0");
#endif

    switch (ctx->pc) {
        case 0x1ce014u: goto label_1ce014;
        case 0x1ce040u: goto label_1ce040;
        case 0x1ce064u: goto label_1ce064;
        case 0x1ce09cu: goto label_1ce09c;
        case 0x1ce0c4u: goto label_1ce0c4;
        case 0x1ce0d4u: goto label_1ce0d4;
        case 0x1ce0f8u: goto label_1ce0f8;
        default: break;
    }

    ctx->pc = 0x1cdfe0u;

    // 0x1cdfe0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cdfe0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cdfe4: 0x28822000  slti        $v0, $a0, 0x2000
    ctx->pc = 0x1cdfe4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)8192) ? 1 : 0);
    // 0x1cdfe8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cdfe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cdfec: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cdfecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cdff0: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1CDFF0u;
    {
        const bool branch_taken_0x1cdff0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CDFF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDFF0u;
            // 0x1cdff4: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cdff0) {
            ctx->pc = 0x1CE01Cu;
            goto label_1ce01c;
        }
    }
    ctx->pc = 0x1CDFF8u;
    // 0x1cdff8: 0x28812100  slti        $at, $a0, 0x2100
    ctx->pc = 0x1cdff8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)8448) ? 1 : 0);
    // 0x1cdffc: 0x10200008  beqz        $at, . + 4 + (0x8 << 2)
    ctx->pc = 0x1CDFFCu;
    {
        const bool branch_taken_0x1cdffc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CE000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDFFCu;
            // 0x1ce000: 0x28822400  slti        $v0, $a0, 0x2400 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)9216) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cdffc) {
            ctx->pc = 0x1CE020u;
            goto label_1ce020;
        }
    }
    ctx->pc = 0x1CE004u;
    // 0x1ce004: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x1ce004u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce008: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1ce008u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce00c: 0xc074cd4  jal         func_1D3350
    ctx->pc = 0x1CE00Cu;
    SET_GPR_U32(ctx, 31, 0x1CE014u);
    ctx->pc = 0x1CE010u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE00Cu;
            // 0x1ce010: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3350u;
    if (runtime->hasFunction(0x1D3350u)) {
        auto targetFn = runtime->lookupFunction(0x1D3350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE014u; }
        if (ctx->pc != 0x1CE014u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3350_0x1d3350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE014u; }
        if (ctx->pc != 0x1CE014u) { return; }
    }
    ctx->pc = 0x1CE014u;
label_1ce014:
    // 0x1ce014: 0x10000039  b           . + 4 + (0x39 << 2)
    ctx->pc = 0x1CE014u;
    {
        const bool branch_taken_0x1ce014 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CE018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE014u;
            // 0x1ce018: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ce014) {
            ctx->pc = 0x1CE0FCu;
            goto label_1ce0fc;
        }
    }
    ctx->pc = 0x1CE01Cu;
label_1ce01c:
    // 0x1ce01c: 0x28822400  slti        $v0, $a0, 0x2400
    ctx->pc = 0x1ce01cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)9216) ? 1 : 0);
label_1ce020:
    // 0x1ce020: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1CE020u;
    {
        const bool branch_taken_0x1ce020 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CE024u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE020u;
            // 0x1ce024: 0x28822a00  slti        $v0, $a0, 0x2A00 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)10752) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ce020) {
            ctx->pc = 0x1CE048u;
            goto label_1ce048;
        }
    }
    ctx->pc = 0x1CE028u;
    // 0x1ce028: 0x28812500  slti        $at, $a0, 0x2500
    ctx->pc = 0x1ce028u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)9472) ? 1 : 0);
    // 0x1ce02c: 0x10200006  beqz        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1CE02Cu;
    {
        const bool branch_taken_0x1ce02c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CE030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE02Cu;
            // 0x1ce030: 0xc0282d  daddu       $a1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ce02c) {
            ctx->pc = 0x1CE048u;
            goto label_1ce048;
        }
    }
    ctx->pc = 0x1CE034u;
    // 0x1ce034: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1ce034u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce038: 0xc074cd4  jal         func_1D3350
    ctx->pc = 0x1CE038u;
    SET_GPR_U32(ctx, 31, 0x1CE040u);
    ctx->pc = 0x1CE03Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE038u;
            // 0x1ce03c: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3350u;
    if (runtime->hasFunction(0x1D3350u)) {
        auto targetFn = runtime->lookupFunction(0x1D3350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE040u; }
        if (ctx->pc != 0x1CE040u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3350_0x1d3350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE040u; }
        if (ctx->pc != 0x1CE040u) { return; }
    }
    ctx->pc = 0x1CE040u;
label_1ce040:
    // 0x1ce040: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x1CE040u;
    {
        const bool branch_taken_0x1ce040 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ce040) {
            ctx->pc = 0x1CE0F8u;
            goto label_1ce0f8;
        }
    }
    ctx->pc = 0x1CE048u;
label_1ce048:
    // 0x1ce048: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1CE048u;
    {
        const bool branch_taken_0x1ce048 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CE04Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE048u;
            // 0x1ce04c: 0x28813000  slti        $at, $a0, 0x3000 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)12288) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ce048) {
            ctx->pc = 0x1CE06Cu;
            goto label_1ce06c;
        }
    }
    ctx->pc = 0x1CE050u;
    // 0x1ce050: 0x10200007  beqz        $at, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CE050u;
    {
        const bool branch_taken_0x1ce050 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CE054u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE050u;
            // 0x1ce054: 0x28821800  slti        $v0, $a0, 0x1800 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)6144) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ce050) {
            ctx->pc = 0x1CE070u;
            goto label_1ce070;
        }
    }
    ctx->pc = 0x1CE058u;
    // 0x1ce058: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1ce058u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce05c: 0xc074c40  jal         func_1D3100
    ctx->pc = 0x1CE05Cu;
    SET_GPR_U32(ctx, 31, 0x1CE064u);
    ctx->pc = 0x1CE060u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE05Cu;
            // 0x1ce060: 0xc0282d  daddu       $a1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3100u;
    if (runtime->hasFunction(0x1D3100u)) {
        auto targetFn = runtime->lookupFunction(0x1D3100u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE064u; }
        if (ctx->pc != 0x1CE064u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3100_0x1d3100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE064u; }
        if (ctx->pc != 0x1CE064u) { return; }
    }
    ctx->pc = 0x1CE064u;
label_1ce064:
    // 0x1ce064: 0x10000024  b           . + 4 + (0x24 << 2)
    ctx->pc = 0x1CE064u;
    {
        const bool branch_taken_0x1ce064 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ce064) {
            ctx->pc = 0x1CE0F8u;
            goto label_1ce0f8;
        }
    }
    ctx->pc = 0x1CE06Cu;
label_1ce06c:
    // 0x1ce06c: 0x28821800  slti        $v0, $a0, 0x1800
    ctx->pc = 0x1ce06cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)6144) ? 1 : 0);
label_1ce070:
    // 0x1ce070: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1CE070u;
    {
        const bool branch_taken_0x1ce070 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CE074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE070u;
            // 0x1ce074: 0x28822100  slti        $v0, $a0, 0x2100 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)8448) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ce070) {
            ctx->pc = 0x1CE0A4u;
            goto label_1ce0a4;
        }
    }
    ctx->pc = 0x1CE078u;
    // 0x1ce078: 0x28812000  slti        $at, $a0, 0x2000
    ctx->pc = 0x1ce078u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)8192) ? 1 : 0);
    // 0x1ce07c: 0x10200009  beqz        $at, . + 4 + (0x9 << 2)
    ctx->pc = 0x1CE07Cu;
    {
        const bool branch_taken_0x1ce07c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CE080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE07Cu;
            // 0x1ce080: 0xc0282d  daddu       $a1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ce07c) {
            ctx->pc = 0x1CE0A4u;
            goto label_1ce0a4;
        }
    }
    ctx->pc = 0x1CE084u;
    // 0x1ce084: 0x3c07004a  lui         $a3, 0x4A
    ctx->pc = 0x1ce084u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)74 << 16));
    // 0x1ce088: 0x3c06004a  lui         $a2, 0x4A
    ctx->pc = 0x1ce088u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)74 << 16));
    // 0x1ce08c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1ce08cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce090: 0x24c6fa10  addiu       $a2, $a2, -0x5F0
    ctx->pc = 0x1ce090u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294965776));
    // 0x1ce094: 0xc074b2c  jal         func_1D2CB0
    ctx->pc = 0x1CE094u;
    SET_GPR_U32(ctx, 31, 0x1CE09Cu);
    ctx->pc = 0x1CE098u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE094u;
            // 0x1ce098: 0x24e73c20  addiu       $a3, $a3, 0x3C20 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 15392));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D2CB0u;
    if (runtime->hasFunction(0x1D2CB0u)) {
        auto targetFn = runtime->lookupFunction(0x1D2CB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE09Cu; }
        if (ctx->pc != 0x1CE09Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D2CB0_0x1d2cb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE09Cu; }
        if (ctx->pc != 0x1CE09Cu) { return; }
    }
    ctx->pc = 0x1CE09Cu;
label_1ce09c:
    // 0x1ce09c: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1CE09Cu;
    {
        const bool branch_taken_0x1ce09c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ce09c) {
            ctx->pc = 0x1CE0F8u;
            goto label_1ce0f8;
        }
    }
    ctx->pc = 0x1CE0A4u;
label_1ce0a4:
    // 0x1ce0a4: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1CE0A4u;
    {
        const bool branch_taken_0x1ce0a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CE0A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE0A4u;
            // 0x1ce0a8: 0xc0282d  daddu       $a1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ce0a4) {
            ctx->pc = 0x1CE0CCu;
            goto label_1ce0cc;
        }
    }
    ctx->pc = 0x1CE0ACu;
    // 0x1ce0ac: 0x28812400  slti        $at, $a0, 0x2400
    ctx->pc = 0x1ce0acu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)9216) ? 1 : 0);
    // 0x1ce0b0: 0x10200006  beqz        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1CE0B0u;
    {
        const bool branch_taken_0x1ce0b0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ce0b0) {
            ctx->pc = 0x1CE0CCu;
            goto label_1ce0cc;
        }
    }
    ctx->pc = 0x1CE0B8u;
    // 0x1ce0b8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1ce0b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce0bc: 0xc074bf8  jal         func_1D2FE0
    ctx->pc = 0x1CE0BCu;
    SET_GPR_U32(ctx, 31, 0x1CE0C4u);
    ctx->pc = 0x1CE0C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE0BCu;
            // 0x1ce0c0: 0xc0282d  daddu       $a1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D2FE0u;
    if (runtime->hasFunction(0x1D2FE0u)) {
        auto targetFn = runtime->lookupFunction(0x1D2FE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE0C4u; }
        if (ctx->pc != 0x1CE0C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D2FE0_0x1d2fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE0C4u; }
        if (ctx->pc != 0x1CE0C4u) { return; }
    }
    ctx->pc = 0x1CE0C4u;
label_1ce0c4:
    // 0x1ce0c4: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1CE0C4u;
    {
        const bool branch_taken_0x1ce0c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ce0c4) {
            ctx->pc = 0x1CE0F8u;
            goto label_1ce0f8;
        }
    }
    ctx->pc = 0x1CE0CCu;
label_1ce0cc:
    // 0x1ce0cc: 0xc074b00  jal         func_1D2C00
    ctx->pc = 0x1CE0CCu;
    SET_GPR_U32(ctx, 31, 0x1CE0D4u);
    ctx->pc = 0x1CE0D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE0CCu;
            // 0x1ce0d0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D2C00u;
    if (runtime->hasFunction(0x1D2C00u)) {
        auto targetFn = runtime->lookupFunction(0x1D2C00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE0D4u; }
        if (ctx->pc != 0x1CE0D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D2C00_0x1d2c00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE0D4u; }
        if (ctx->pc != 0x1CE0D4u) { return; }
    }
    ctx->pc = 0x1CE0D4u;
label_1ce0d4:
    // 0x1ce0d4: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1ce0d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1ce0d8: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CE0D8u;
    {
        const bool branch_taken_0x1ce0d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ce0d8) {
            ctx->pc = 0x1CE0F8u;
            goto label_1ce0f8;
        }
    }
    ctx->pc = 0x1CE0E0u;
    // 0x1ce0e0: 0x9204081c  lbu         $a0, 0x81C($s0)
    ctx->pc = 0x1ce0e0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2076)));
    // 0x1ce0e4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ce0e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ce0e8: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CE0E8u;
    {
        const bool branch_taken_0x1ce0e8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1CE0ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE0E8u;
            // 0x1ce0ec: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ce0e8) {
            ctx->pc = 0x1CE0F8u;
            goto label_1ce0f8;
        }
    }
    ctx->pc = 0x1CE0F0u;
    // 0x1ce0f0: 0xc074d58  jal         func_1D3560
    ctx->pc = 0x1CE0F0u;
    SET_GPR_U32(ctx, 31, 0x1CE0F8u);
    ctx->pc = 0x1D3560u;
    if (runtime->hasFunction(0x1D3560u)) {
        auto targetFn = runtime->lookupFunction(0x1D3560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE0F8u; }
        if (ctx->pc != 0x1CE0F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3560_0x1d3560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE0F8u; }
        if (ctx->pc != 0x1CE0F8u) { return; }
    }
    ctx->pc = 0x1CE0F8u;
label_1ce0f8:
    // 0x1ce0f8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1ce0f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1ce0fc:
    // 0x1ce0fc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ce0fcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ce100: 0x3e00008  jr          $ra
    ctx->pc = 0x1CE100u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CE104u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE100u;
            // 0x1ce104: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CE014u: goto label_1ce014;
            case 0x1CE01Cu: goto label_1ce01c;
            case 0x1CE020u: goto label_1ce020;
            case 0x1CE040u: goto label_1ce040;
            case 0x1CE048u: goto label_1ce048;
            case 0x1CE064u: goto label_1ce064;
            case 0x1CE06Cu: goto label_1ce06c;
            case 0x1CE070u: goto label_1ce070;
            case 0x1CE09Cu: goto label_1ce09c;
            case 0x1CE0A4u: goto label_1ce0a4;
            case 0x1CE0C4u: goto label_1ce0c4;
            case 0x1CE0CCu: goto label_1ce0cc;
            case 0x1CE0D4u: goto label_1ce0d4;
            case 0x1CE0F8u: goto label_1ce0f8;
            case 0x1CE0FCu: goto label_1ce0fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CE108u;
    // 0x1ce108: 0x0  nop
    ctx->pc = 0x1ce108u;
    // NOP
    // 0x1ce10c: 0x0  nop
    ctx->pc = 0x1ce10cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
