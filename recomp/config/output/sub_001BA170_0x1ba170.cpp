#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BA170
// Address: 0x1ba170 - 0x1ba440
void sub_001BA170_0x1ba170(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BA170_0x1ba170");
#endif

    switch (ctx->pc) {
        case 0x1ba1b0u: goto label_1ba1b0;
        case 0x1ba1c0u: goto label_1ba1c0;
        case 0x1ba1d4u: goto label_1ba1d4;
        case 0x1ba1f4u: goto label_1ba1f4;
        case 0x1ba204u: goto label_1ba204;
        case 0x1ba214u: goto label_1ba214;
        case 0x1ba228u: goto label_1ba228;
        case 0x1ba2b0u: goto label_1ba2b0;
        case 0x1ba2d4u: goto label_1ba2d4;
        case 0x1ba2f0u: goto label_1ba2f0;
        case 0x1ba300u: goto label_1ba300;
        case 0x1ba314u: goto label_1ba314;
        case 0x1ba380u: goto label_1ba380;
        case 0x1ba388u: goto label_1ba388;
        case 0x1ba3b8u: goto label_1ba3b8;
        case 0x1ba3d0u: goto label_1ba3d0;
        case 0x1ba3fcu: goto label_1ba3fc;
        case 0x1ba40cu: goto label_1ba40c;
        default: break;
    }

    ctx->pc = 0x1ba170u;

label_1ba170:
    // 0x1ba170: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1ba170u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1ba174: 0x3c02004c  lui         $v0, 0x4C
    ctx->pc = 0x1ba174u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)76 << 16));
    // 0x1ba178: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1ba178u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1ba17c: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1ba17cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1ba180: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ba180u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ba184: 0x2442ae24  addiu       $v0, $v0, -0x51DC
    ctx->pc = 0x1ba184u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294946340));
    // 0x1ba188: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ba188u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ba18c: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x1ba18cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ba190: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ba190u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ba194: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1ba194u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba198: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1ba198u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1ba19c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1ba19cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba1a0: 0x10510005  beq         $v0, $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BA1A0u;
    {
        const bool branch_taken_0x1ba1a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 17));
        ctx->pc = 0x1BA1A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA1A0u;
            // 0x1ba1a4: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba1a0) {
            ctx->pc = 0x1BA1B8u;
            goto label_1ba1b8;
        }
    }
    ctx->pc = 0x1BA1A8u;
    // 0x1ba1a8: 0xc06b688  jal         func_1ADA20
    ctx->pc = 0x1BA1A8u;
    SET_GPR_U32(ctx, 31, 0x1BA1B0u);
    ctx->pc = 0x1BA1ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA1A8u;
            // 0x1ba1ac: 0xac710000  sw          $s1, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADA20u;
    if (runtime->hasFunction(0x1ADA20u)) {
        auto targetFn = runtime->lookupFunction(0x1ADA20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA1B0u; }
        if (ctx->pc != 0x1BA1B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADA20_0x1ada20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA1B0u; }
        if (ctx->pc != 0x1BA1B0u) { return; }
    }
    ctx->pc = 0x1BA1B0u;
label_1ba1b0:
    // 0x1ba1b0: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1BA1B0u;
    {
        const bool branch_taken_0x1ba1b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA1B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA1B0u;
            // 0x1ba1b4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba1b0) {
            ctx->pc = 0x1BA22Cu;
            goto label_1ba22c;
        }
    }
    ctx->pc = 0x1BA1B8u;
label_1ba1b8:
    // 0x1ba1b8: 0xc06b8b8  jal         func_1AE2E0
    ctx->pc = 0x1BA1B8u;
    SET_GPR_U32(ctx, 31, 0x1BA1C0u);
    ctx->pc = 0x1BA1BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA1B8u;
            // 0x1ba1bc: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AE2E0u;
    if (runtime->hasFunction(0x1AE2E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AE2E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA1C0u; }
        if (ctx->pc != 0x1BA1C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE2E0_0x1ae2e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA1C0u; }
        if (ctx->pc != 0x1BA1C0u) { return; }
    }
    ctx->pc = 0x1BA1C0u;
label_1ba1c0:
    // 0x1ba1c0: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1BA1C0u;
    {
        const bool branch_taken_0x1ba1c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA1C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA1C0u;
            // 0x1ba1c4: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba1c0) {
            ctx->pc = 0x1BA21Cu;
            goto label_1ba21c;
        }
    }
    ctx->pc = 0x1BA1C8u;
    // 0x1ba1c8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1ba1c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba1cc: 0xc06b8b8  jal         func_1AE2E0
    ctx->pc = 0x1BA1CCu;
    SET_GPR_U32(ctx, 31, 0x1BA1D4u);
    ctx->pc = 0x1BA1D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA1CCu;
            // 0x1ba1d0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AE2E0u;
    if (runtime->hasFunction(0x1AE2E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AE2E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA1D4u; }
        if (ctx->pc != 0x1BA1D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE2E0_0x1ae2e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA1D4u; }
        if (ctx->pc != 0x1BA1D4u) { return; }
    }
    ctx->pc = 0x1BA1D4u;
label_1ba1d4:
    // 0x1ba1d4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BA1D4u;
    {
        const bool branch_taken_0x1ba1d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA1D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA1D4u;
            // 0x1ba1d8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba1d4) {
            ctx->pc = 0x1BA1E8u;
            goto label_1ba1e8;
        }
    }
    ctx->pc = 0x1BA1DCu;
    // 0x1ba1dc: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1ba1dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1ba1e0: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1BA1E0u;
    {
        const bool branch_taken_0x1ba1e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1ba1e0) {
            ctx->pc = 0x1BA1FCu;
            goto label_1ba1fc;
        }
    }
    ctx->pc = 0x1BA1E8u;
label_1ba1e8:
    // 0x1ba1e8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1ba1e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba1ec: 0xc06b688  jal         func_1ADA20
    ctx->pc = 0x1BA1ECu;
    SET_GPR_U32(ctx, 31, 0x1BA1F4u);
    ctx->pc = 0x1BA1F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA1ECu;
            // 0x1ba1f0: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADA20u;
    if (runtime->hasFunction(0x1ADA20u)) {
        auto targetFn = runtime->lookupFunction(0x1ADA20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA1F4u; }
        if (ctx->pc != 0x1BA1F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADA20_0x1ada20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA1F4u; }
        if (ctx->pc != 0x1BA1F4u) { return; }
    }
    ctx->pc = 0x1BA1F4u;
label_1ba1f4:
    // 0x1ba1f4: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1BA1F4u;
    {
        const bool branch_taken_0x1ba1f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba1f4) {
            ctx->pc = 0x1BA228u;
            goto label_1ba228;
        }
    }
    ctx->pc = 0x1BA1FCu;
label_1ba1fc:
    // 0x1ba1fc: 0xc06b7d4  jal         func_1ADF50
    ctx->pc = 0x1BA1FCu;
    SET_GPR_U32(ctx, 31, 0x1BA204u);
    ctx->pc = 0x1BA200u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA1FCu;
            // 0x1ba200: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADF50u;
    if (runtime->hasFunction(0x1ADF50u)) {
        auto targetFn = runtime->lookupFunction(0x1ADF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA204u; }
        if (ctx->pc != 0x1BA204u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADF50_0x1adf50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA204u; }
        if (ctx->pc != 0x1BA204u) { return; }
    }
    ctx->pc = 0x1BA204u;
label_1ba204:
    // 0x1ba204: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1ba204u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba208: 0x2405007f  addiu       $a1, $zero, 0x7F
    ctx->pc = 0x1ba208u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1ba20c: 0xc06b8fc  jal         func_1AE3F0
    ctx->pc = 0x1BA20Cu;
    SET_GPR_U32(ctx, 31, 0x1BA214u);
    ctx->pc = 0x1BA210u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA20Cu;
            // 0x1ba210: 0x2406003c  addiu       $a2, $zero, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AE3F0u;
    if (runtime->hasFunction(0x1AE3F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AE3F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA214u; }
        if (ctx->pc != 0x1BA214u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE3F0_0x1ae3f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA214u; }
        if (ctx->pc != 0x1BA214u) { return; }
    }
    ctx->pc = 0x1BA214u;
label_1ba214:
    // 0x1ba214: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1BA214u;
    {
        const bool branch_taken_0x1ba214 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA218u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA214u;
            // 0x1ba218: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba214) {
            ctx->pc = 0x1BA22Cu;
            goto label_1ba22c;
        }
    }
    ctx->pc = 0x1BA21Cu;
label_1ba21c:
    // 0x1ba21c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1ba21cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba220: 0xc06b688  jal         func_1ADA20
    ctx->pc = 0x1BA220u;
    SET_GPR_U32(ctx, 31, 0x1BA228u);
    ctx->pc = 0x1BA224u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA220u;
            // 0x1ba224: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADA20u;
    if (runtime->hasFunction(0x1ADA20u)) {
        auto targetFn = runtime->lookupFunction(0x1ADA20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA228u; }
        if (ctx->pc != 0x1BA228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADA20_0x1ada20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA228u; }
        if (ctx->pc != 0x1BA228u) { return; }
    }
    ctx->pc = 0x1BA228u;
label_1ba228:
    // 0x1ba228: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ba228u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ba22c:
    // 0x1ba22c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1ba22cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ba230: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ba230u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ba234: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ba234u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ba238: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ba238u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ba23c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA23Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA23Cu;
            // 0x1ba240: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA170u: goto label_1ba170;
            case 0x1BA1B0u: goto label_1ba1b0;
            case 0x1BA1B8u: goto label_1ba1b8;
            case 0x1BA1C0u: goto label_1ba1c0;
            case 0x1BA1D4u: goto label_1ba1d4;
            case 0x1BA1E8u: goto label_1ba1e8;
            case 0x1BA1F4u: goto label_1ba1f4;
            case 0x1BA1FCu: goto label_1ba1fc;
            case 0x1BA204u: goto label_1ba204;
            case 0x1BA214u: goto label_1ba214;
            case 0x1BA21Cu: goto label_1ba21c;
            case 0x1BA228u: goto label_1ba228;
            case 0x1BA22Cu: goto label_1ba22c;
            case 0x1BA278u: goto label_1ba278;
            case 0x1BA288u: goto label_1ba288;
            case 0x1BA2A8u: goto label_1ba2a8;
            case 0x1BA2B0u: goto label_1ba2b0;
            case 0x1BA2C4u: goto label_1ba2c4;
            case 0x1BA2CCu: goto label_1ba2cc;
            case 0x1BA2D4u: goto label_1ba2d4;
            case 0x1BA2F0u: goto label_1ba2f0;
            case 0x1BA300u: goto label_1ba300;
            case 0x1BA308u: goto label_1ba308;
            case 0x1BA314u: goto label_1ba314;
            case 0x1BA318u: goto label_1ba318;
            case 0x1BA380u: goto label_1ba380;
            case 0x1BA388u: goto label_1ba388;
            case 0x1BA3B0u: goto label_1ba3b0;
            case 0x1BA3B8u: goto label_1ba3b8;
            case 0x1BA3C0u: goto label_1ba3c0;
            case 0x1BA3D0u: goto label_1ba3d0;
            case 0x1BA3D8u: goto label_1ba3d8;
            case 0x1BA3F4u: goto label_1ba3f4;
            case 0x1BA3FCu: goto label_1ba3fc;
            case 0x1BA40Cu: goto label_1ba40c;
            case 0x1BA410u: goto label_1ba410;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA244u;
    // 0x1ba244: 0x0  nop
    ctx->pc = 0x1ba244u;
    // NOP
    // 0x1ba248: 0x0  nop
    ctx->pc = 0x1ba248u;
    // NOP
    // 0x1ba24c: 0x0  nop
    ctx->pc = 0x1ba24cu;
    // NOP
    // 0x1ba250: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1ba250u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1ba254: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1ba254u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1ba258: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ba258u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ba25c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ba25cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ba260: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1ba260u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba264: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1ba264u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba268: 0x6210003  bgez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA268u;
    {
        const bool branch_taken_0x1ba268 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x1BA26Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA268u;
            // 0x1ba26c: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba268) {
            ctx->pc = 0x1BA278u;
            goto label_1ba278;
        }
    }
    ctx->pc = 0x1BA270u;
    // 0x1ba270: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1BA270u;
    {
        const bool branch_taken_0x1ba270 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA270u;
            // 0x1ba274: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba270) {
            ctx->pc = 0x1BA318u;
            goto label_1ba318;
        }
    }
    ctx->pc = 0x1BA278u;
label_1ba278:
    // 0x1ba278: 0x92420002  lbu         $v0, 0x2($s2)
    ctx->pc = 0x1ba278u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 2)));
    // 0x1ba27c: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1BA27Cu;
    {
        const bool branch_taken_0x1ba27c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BA280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA27Cu;
            // 0x1ba280: 0x24100005  addiu       $s0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba27c) {
            ctx->pc = 0x1BA288u;
            goto label_1ba288;
        }
    }
    ctx->pc = 0x1BA284u;
    // 0x1ba284: 0x92500003  lbu         $s0, 0x3($s2)
    ctx->pc = 0x1ba284u;
    SET_GPR_U32(ctx, 16, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 3)));
label_1ba288:
    // 0x1ba288: 0x3c02004c  lui         $v0, 0x4C
    ctx->pc = 0x1ba288u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)76 << 16));
    // 0x1ba28c: 0x2442ae71  addiu       $v0, $v0, -0x518F
    ctx->pc = 0x1ba28cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294946417));
    // 0x1ba290: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1ba290u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1ba294: 0x90420000  lbu         $v0, 0x0($v0)
    ctx->pc = 0x1ba294u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ba298: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA298u;
    {
        const bool branch_taken_0x1ba298 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BA29Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA298u;
            // 0x1ba29c: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba298) {
            ctx->pc = 0x1BA2A8u;
            goto label_1ba2a8;
        }
    }
    ctx->pc = 0x1BA2A0u;
    // 0x1ba2a0: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1BA2A0u;
    {
        const bool branch_taken_0x1ba2a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA2A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2A0u;
            // 0x1ba2a4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba2a0) {
            ctx->pc = 0x1BA318u;
            goto label_1ba318;
        }
    }
    ctx->pc = 0x1BA2A8u;
label_1ba2a8:
    // 0x1ba2a8: 0xc06b8b8  jal         func_1AE2E0
    ctx->pc = 0x1BA2A8u;
    SET_GPR_U32(ctx, 31, 0x1BA2B0u);
    ctx->pc = 0x1BA2ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2A8u;
            // 0x1ba2ac: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AE2E0u;
    if (runtime->hasFunction(0x1AE2E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AE2E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA2B0u; }
        if (ctx->pc != 0x1BA2B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE2E0_0x1ae2e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA2B0u; }
        if (ctx->pc != 0x1BA2B0u) { return; }
    }
    ctx->pc = 0x1BA2B0u;
label_1ba2b0:
    // 0x1ba2b0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ba2b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ba2b4: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA2B4u;
    {
        const bool branch_taken_0x1ba2b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BA2B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2B4u;
            // 0x1ba2b8: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba2b4) {
            ctx->pc = 0x1BA2C4u;
            goto label_1ba2c4;
        }
    }
    ctx->pc = 0x1BA2BCu;
    // 0x1ba2bc: 0x14440003  bne         $v0, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA2BCu;
    {
        const bool branch_taken_0x1ba2bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x1BA2C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2BCu;
            // 0x1ba2c0: 0x26060005  addiu       $a2, $s0, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba2bc) {
            ctx->pc = 0x1BA2CCu;
            goto label_1ba2cc;
        }
    }
    ctx->pc = 0x1BA2C4u;
label_1ba2c4:
    // 0x1ba2c4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1BA2C4u;
    {
        const bool branch_taken_0x1ba2c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA2C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2C4u;
            // 0x1ba2c8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba2c4) {
            ctx->pc = 0x1BA318u;
            goto label_1ba318;
        }
    }
    ctx->pc = 0x1BA2CCu;
label_1ba2cc:
    // 0x1ba2cc: 0xc06e85c  jal         func_1BA170
    ctx->pc = 0x1BA2CCu;
    SET_GPR_U32(ctx, 31, 0x1BA2D4u);
    ctx->pc = 0x1BA2D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2CCu;
            // 0x1ba2d0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BA170u;
    goto label_1ba170;
    ctx->pc = 0x1BA2D4u;
label_1ba2d4:
    // 0x1ba2d4: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1BA2D4u;
    {
        const bool branch_taken_0x1ba2d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BA2D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2D4u;
            // 0x1ba2d8: 0x3c010023  lui         $at, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba2d4) {
            ctx->pc = 0x1BA314u;
            goto label_1ba314;
        }
    }
    ctx->pc = 0x1BA2DCu;
    // 0x1ba2dc: 0x26440038  addiu       $a0, $s2, 0x38
    ctx->pc = 0x1ba2dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 56));
    // 0x1ba2e0: 0x8c254bf4  lw          $a1, 0x4BF4($at)
    ctx->pc = 0x1ba2e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 19444)));
    // 0x1ba2e4: 0x27a6004c  addiu       $a2, $sp, 0x4C
    ctx->pc = 0x1ba2e4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 76));
    // 0x1ba2e8: 0xc06e52c  jal         func_1B94B0
    ctx->pc = 0x1BA2E8u;
    SET_GPR_U32(ctx, 31, 0x1BA2F0u);
    ctx->pc = 0x1BA2ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2E8u;
            // 0x1ba2ec: 0x27a70048  addiu       $a3, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B94B0u;
    if (runtime->hasFunction(0x1B94B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B94B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA2F0u; }
        if (ctx->pc != 0x1BA2F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B94B0_0x1b94b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA2F0u; }
        if (ctx->pc != 0x1BA2F0u) { return; }
    }
    ctx->pc = 0x1BA2F0u;
label_1ba2f0:
    // 0x1ba2f0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BA2F0u;
    {
        const bool branch_taken_0x1ba2f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BA2F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2F0u;
            // 0x1ba2f4: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba2f0) {
            ctx->pc = 0x1BA308u;
            goto label_1ba308;
        }
    }
    ctx->pc = 0x1BA2F8u;
    // 0x1ba2f8: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1BA2F8u;
    SET_GPR_U32(ctx, 31, 0x1BA300u);
    ctx->pc = 0x1BA2FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2F8u;
            // 0x1ba2fc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA300u; }
        if (ctx->pc != 0x1BA300u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA300u; }
        if (ctx->pc != 0x1BA300u) { return; }
    }
    ctx->pc = 0x1BA300u;
label_1ba300:
    // 0x1ba300: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1BA300u;
    {
        const bool branch_taken_0x1ba300 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA300u;
            // 0x1ba304: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba300) {
            ctx->pc = 0x1BA318u;
            goto label_1ba318;
        }
    }
    ctx->pc = 0x1BA308u;
label_1ba308:
    // 0x1ba308: 0x8fa5004c  lw          $a1, 0x4C($sp)
    ctx->pc = 0x1ba308u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x1ba30c: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1BA30Cu;
    SET_GPR_U32(ctx, 31, 0x1BA314u);
    ctx->pc = 0x1BA310u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA30Cu;
            // 0x1ba310: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA314u; }
        if (ctx->pc != 0x1BA314u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA314u; }
        if (ctx->pc != 0x1BA314u) { return; }
    }
    ctx->pc = 0x1BA314u;
label_1ba314:
    // 0x1ba314: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ba314u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ba318:
    // 0x1ba318: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1ba318u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ba31c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ba31cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ba320: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ba320u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ba324: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ba324u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ba328: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA328u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA32Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA328u;
            // 0x1ba32c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA170u: goto label_1ba170;
            case 0x1BA1B0u: goto label_1ba1b0;
            case 0x1BA1B8u: goto label_1ba1b8;
            case 0x1BA1C0u: goto label_1ba1c0;
            case 0x1BA1D4u: goto label_1ba1d4;
            case 0x1BA1E8u: goto label_1ba1e8;
            case 0x1BA1F4u: goto label_1ba1f4;
            case 0x1BA1FCu: goto label_1ba1fc;
            case 0x1BA204u: goto label_1ba204;
            case 0x1BA214u: goto label_1ba214;
            case 0x1BA21Cu: goto label_1ba21c;
            case 0x1BA228u: goto label_1ba228;
            case 0x1BA22Cu: goto label_1ba22c;
            case 0x1BA278u: goto label_1ba278;
            case 0x1BA288u: goto label_1ba288;
            case 0x1BA2A8u: goto label_1ba2a8;
            case 0x1BA2B0u: goto label_1ba2b0;
            case 0x1BA2C4u: goto label_1ba2c4;
            case 0x1BA2CCu: goto label_1ba2cc;
            case 0x1BA2D4u: goto label_1ba2d4;
            case 0x1BA2F0u: goto label_1ba2f0;
            case 0x1BA300u: goto label_1ba300;
            case 0x1BA308u: goto label_1ba308;
            case 0x1BA314u: goto label_1ba314;
            case 0x1BA318u: goto label_1ba318;
            case 0x1BA380u: goto label_1ba380;
            case 0x1BA388u: goto label_1ba388;
            case 0x1BA3B0u: goto label_1ba3b0;
            case 0x1BA3B8u: goto label_1ba3b8;
            case 0x1BA3C0u: goto label_1ba3c0;
            case 0x1BA3D0u: goto label_1ba3d0;
            case 0x1BA3D8u: goto label_1ba3d8;
            case 0x1BA3F4u: goto label_1ba3f4;
            case 0x1BA3FCu: goto label_1ba3fc;
            case 0x1BA40Cu: goto label_1ba40c;
            case 0x1BA410u: goto label_1ba410;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA330u;
    // 0x1ba330: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1ba330u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1ba334: 0xa020ae71  sb          $zero, -0x518F($at)
    ctx->pc = 0x1ba334u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294946417), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ba338: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1ba338u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1ba33c: 0xa020ae72  sb          $zero, -0x518E($at)
    ctx->pc = 0x1ba33cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294946418), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ba340: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1ba340u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1ba344: 0xa020ae73  sb          $zero, -0x518D($at)
    ctx->pc = 0x1ba344u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294946419), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ba348: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1ba348u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1ba34c: 0xa020ae74  sb          $zero, -0x518C($at)
    ctx->pc = 0x1ba34cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294946420), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ba350: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1ba350u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1ba354: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA354u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA354u;
            // 0x1ba358: 0xa020ae75  sb          $zero, -0x518B($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294946421), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA170u: goto label_1ba170;
            case 0x1BA1B0u: goto label_1ba1b0;
            case 0x1BA1B8u: goto label_1ba1b8;
            case 0x1BA1C0u: goto label_1ba1c0;
            case 0x1BA1D4u: goto label_1ba1d4;
            case 0x1BA1E8u: goto label_1ba1e8;
            case 0x1BA1F4u: goto label_1ba1f4;
            case 0x1BA1FCu: goto label_1ba1fc;
            case 0x1BA204u: goto label_1ba204;
            case 0x1BA214u: goto label_1ba214;
            case 0x1BA21Cu: goto label_1ba21c;
            case 0x1BA228u: goto label_1ba228;
            case 0x1BA22Cu: goto label_1ba22c;
            case 0x1BA278u: goto label_1ba278;
            case 0x1BA288u: goto label_1ba288;
            case 0x1BA2A8u: goto label_1ba2a8;
            case 0x1BA2B0u: goto label_1ba2b0;
            case 0x1BA2C4u: goto label_1ba2c4;
            case 0x1BA2CCu: goto label_1ba2cc;
            case 0x1BA2D4u: goto label_1ba2d4;
            case 0x1BA2F0u: goto label_1ba2f0;
            case 0x1BA300u: goto label_1ba300;
            case 0x1BA308u: goto label_1ba308;
            case 0x1BA314u: goto label_1ba314;
            case 0x1BA318u: goto label_1ba318;
            case 0x1BA380u: goto label_1ba380;
            case 0x1BA388u: goto label_1ba388;
            case 0x1BA3B0u: goto label_1ba3b0;
            case 0x1BA3B8u: goto label_1ba3b8;
            case 0x1BA3C0u: goto label_1ba3c0;
            case 0x1BA3D0u: goto label_1ba3d0;
            case 0x1BA3D8u: goto label_1ba3d8;
            case 0x1BA3F4u: goto label_1ba3f4;
            case 0x1BA3FCu: goto label_1ba3fc;
            case 0x1BA40Cu: goto label_1ba40c;
            case 0x1BA410u: goto label_1ba410;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA35Cu;
    // 0x1ba35c: 0x0  nop
    ctx->pc = 0x1ba35cu;
    // NOP
    // 0x1ba360: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ba360u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ba364: 0x3c020059  lui         $v0, 0x59
    ctx->pc = 0x1ba364u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)89 << 16));
    // 0x1ba368: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1ba368u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1ba36c: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1ba36cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1ba370: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ba370u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ba374: 0x2442ed70  addiu       $v0, $v0, -0x1290
    ctx->pc = 0x1ba374u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294962544));
    // 0x1ba378: 0xc06b3dc  jal         func_1ACF70
    ctx->pc = 0x1BA378u;
    SET_GPR_U32(ctx, 31, 0x1BA380u);
    ctx->pc = 0x1BA37Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA378u;
            // 0x1ba37c: 0x438021  addu        $s0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACF70u;
    if (runtime->hasFunction(0x1ACF70u)) {
        auto targetFn = runtime->lookupFunction(0x1ACF70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA380u; }
        if (ctx->pc != 0x1BA380u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACF70_0x1acf70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA380u; }
        if (ctx->pc != 0x1BA380u) { return; }
    }
    ctx->pc = 0x1BA380u;
label_1ba380:
    // 0x1ba380: 0xc06b878  jal         func_1AE1E0
    ctx->pc = 0x1BA380u;
    SET_GPR_U32(ctx, 31, 0x1BA388u);
    ctx->pc = 0x1AE1E0u;
    if (runtime->hasFunction(0x1AE1E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AE1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA388u; }
        if (ctx->pc != 0x1BA388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE1E0_0x1ae1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA388u; }
        if (ctx->pc != 0x1BA388u) { return; }
    }
    ctx->pc = 0x1BA388u;
label_1ba388:
    // 0x1ba388: 0x86040000  lh          $a0, 0x0($s0)
    ctx->pc = 0x1ba388u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1ba38c: 0x2c81000c  sltiu       $at, $a0, 0xC
    ctx->pc = 0x1ba38cu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)12) ? 1 : 0);
    // 0x1ba390: 0x1020001e  beqz        $at, . + 4 + (0x1E << 2)
    ctx->pc = 0x1BA390u;
    {
        const bool branch_taken_0x1ba390 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA394u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA390u;
            // 0x1ba394: 0x3c030025  lui         $v1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba390) {
            ctx->pc = 0x1BA40Cu;
            goto label_1ba40c;
        }
    }
    ctx->pc = 0x1BA398u;
    // 0x1ba398: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x1ba398u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1ba39c: 0x246301f0  addiu       $v1, $v1, 0x1F0
    ctx->pc = 0x1ba39cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 496));
    // 0x1ba3a0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ba3a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ba3a4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1ba3a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ba3a8: 0x400008  jr          $v0
    ctx->pc = 0x1BA3A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA3B0u: goto label_1ba3b0;
            case 0x1BA3C0u: goto label_1ba3c0;
            case 0x1BA3D8u: goto label_1ba3d8;
            case 0x1BA40Cu: goto label_1ba40c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA3B0u;
label_1ba3b0:
    // 0x1ba3b0: 0xc06e214  jal         func_1B8850
    ctx->pc = 0x1BA3B0u;
    SET_GPR_U32(ctx, 31, 0x1BA3B8u);
    ctx->pc = 0x1BA3B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA3B0u;
            // 0x1ba3b4: 0x86040002  lh          $a0, 0x2($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B8850u;
    if (runtime->hasFunction(0x1B8850u)) {
        auto targetFn = runtime->lookupFunction(0x1B8850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA3B8u; }
        if (ctx->pc != 0x1BA3B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8850_0x1b8850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA3B8u; }
        if (ctx->pc != 0x1BA3B8u) { return; }
    }
    ctx->pc = 0x1BA3B8u;
label_1ba3b8:
    // 0x1ba3b8: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1BA3B8u;
    {
        const bool branch_taken_0x1ba3b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA3BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA3B8u;
            // 0x1ba3bc: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba3b8) {
            ctx->pc = 0x1BA410u;
            goto label_1ba410;
        }
    }
    ctx->pc = 0x1BA3C0u;
label_1ba3c0:
    // 0x1ba3c0: 0x86050002  lh          $a1, 0x2($s0)
    ctx->pc = 0x1ba3c0u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1ba3c4: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1ba3c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba3c8: 0xc06b688  jal         func_1ADA20
    ctx->pc = 0x1BA3C8u;
    SET_GPR_U32(ctx, 31, 0x1BA3D0u);
    ctx->pc = 0x1BA3CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA3C8u;
            // 0x1ba3cc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADA20u;
    if (runtime->hasFunction(0x1ADA20u)) {
        auto targetFn = runtime->lookupFunction(0x1ADA20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA3D0u; }
        if (ctx->pc != 0x1BA3D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADA20_0x1ada20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA3D0u; }
        if (ctx->pc != 0x1BA3D0u) { return; }
    }
    ctx->pc = 0x1BA3D0u;
label_1ba3d0:
    // 0x1ba3d0: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1BA3D0u;
    {
        const bool branch_taken_0x1ba3d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba3d0) {
            ctx->pc = 0x1BA40Cu;
            goto label_1ba40c;
        }
    }
    ctx->pc = 0x1BA3D8u;
label_1ba3d8:
    // 0x1ba3d8: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1ba3d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1ba3dc: 0x9023ae71  lbu         $v1, -0x518F($at)
    ctx->pc = 0x1ba3dcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946417)));
    // 0x1ba3e0: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BA3E0u;
    {
        const bool branch_taken_0x1ba3e0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA3E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA3E0u;
            // 0x1ba3e4: 0x2485fffc  addiu       $a1, $a0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba3e0) {
            ctx->pc = 0x1BA3F4u;
            goto label_1ba3f4;
        }
    }
    ctx->pc = 0x1BA3E8u;
    // 0x1ba3e8: 0x2482fffd  addiu       $v0, $a0, -0x3
    ctx->pc = 0x1ba3e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967293));
    // 0x1ba3ec: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA3ECu;
    {
        const bool branch_taken_0x1ba3ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1ba3ec) {
            ctx->pc = 0x1BA3FCu;
            goto label_1ba3fc;
        }
    }
    ctx->pc = 0x1BA3F4u;
label_1ba3f4:
    // 0x1ba3f4: 0xc06e910  jal         func_1BA440
    ctx->pc = 0x1BA3F4u;
    SET_GPR_U32(ctx, 31, 0x1BA3FCu);
    ctx->pc = 0x1BA3F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA3F4u;
            // 0x1ba3f8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BA440u;
    if (runtime->hasFunction(0x1BA440u)) {
        auto targetFn = runtime->lookupFunction(0x1BA440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA3FCu; }
        if (ctx->pc != 0x1BA3FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BA440_0x1ba440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA3FCu; }
        if (ctx->pc != 0x1BA3FCu) { return; }
    }
    ctx->pc = 0x1BA3FCu;
label_1ba3fc:
    // 0x1ba3fc: 0x86050002  lh          $a1, 0x2($s0)
    ctx->pc = 0x1ba3fcu;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1ba400: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1ba400u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ba404: 0xc06b688  jal         func_1ADA20
    ctx->pc = 0x1BA404u;
    SET_GPR_U32(ctx, 31, 0x1BA40Cu);
    ctx->pc = 0x1BA408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA404u;
            // 0x1ba408: 0x24060005  addiu       $a2, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADA20u;
    if (runtime->hasFunction(0x1ADA20u)) {
        auto targetFn = runtime->lookupFunction(0x1ADA20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA40Cu; }
        if (ctx->pc != 0x1BA40Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADA20_0x1ada20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA40Cu; }
        if (ctx->pc != 0x1BA40Cu) { return; }
    }
    ctx->pc = 0x1BA40Cu;
label_1ba40c:
    // 0x1ba40c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1ba40cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1ba410:
    // 0x1ba410: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ba410u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba414: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ba414u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ba418: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA418u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA41Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA418u;
            // 0x1ba41c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA170u: goto label_1ba170;
            case 0x1BA1B0u: goto label_1ba1b0;
            case 0x1BA1B8u: goto label_1ba1b8;
            case 0x1BA1C0u: goto label_1ba1c0;
            case 0x1BA1D4u: goto label_1ba1d4;
            case 0x1BA1E8u: goto label_1ba1e8;
            case 0x1BA1F4u: goto label_1ba1f4;
            case 0x1BA1FCu: goto label_1ba1fc;
            case 0x1BA204u: goto label_1ba204;
            case 0x1BA214u: goto label_1ba214;
            case 0x1BA21Cu: goto label_1ba21c;
            case 0x1BA228u: goto label_1ba228;
            case 0x1BA22Cu: goto label_1ba22c;
            case 0x1BA278u: goto label_1ba278;
            case 0x1BA288u: goto label_1ba288;
            case 0x1BA2A8u: goto label_1ba2a8;
            case 0x1BA2B0u: goto label_1ba2b0;
            case 0x1BA2C4u: goto label_1ba2c4;
            case 0x1BA2CCu: goto label_1ba2cc;
            case 0x1BA2D4u: goto label_1ba2d4;
            case 0x1BA2F0u: goto label_1ba2f0;
            case 0x1BA300u: goto label_1ba300;
            case 0x1BA308u: goto label_1ba308;
            case 0x1BA314u: goto label_1ba314;
            case 0x1BA318u: goto label_1ba318;
            case 0x1BA380u: goto label_1ba380;
            case 0x1BA388u: goto label_1ba388;
            case 0x1BA3B0u: goto label_1ba3b0;
            case 0x1BA3B8u: goto label_1ba3b8;
            case 0x1BA3C0u: goto label_1ba3c0;
            case 0x1BA3D0u: goto label_1ba3d0;
            case 0x1BA3D8u: goto label_1ba3d8;
            case 0x1BA3F4u: goto label_1ba3f4;
            case 0x1BA3FCu: goto label_1ba3fc;
            case 0x1BA40Cu: goto label_1ba40c;
            case 0x1BA410u: goto label_1ba410;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA420u;
    // 0x1ba420: 0x806b1cc  j           func_1AC730
    ctx->pc = 0x1BA420u;
    ctx->pc = 0x1BA424u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA420u;
            // 0x1ba424: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AC730u;
    if (runtime->hasFunction(0x1AC730u)) {
        auto targetFn = runtime->lookupFunction(0x1AC730u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001AC730_0x1ac730(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1BA428u;
    // 0x1ba428: 0x0  nop
    ctx->pc = 0x1ba428u;
    // NOP
    // 0x1ba42c: 0x0  nop
    ctx->pc = 0x1ba42cu;
    // NOP
    // 0x1ba430: 0x806b1cc  j           func_1AC730
    ctx->pc = 0x1BA430u;
    ctx->pc = 0x1BA434u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA430u;
            // 0x1ba434: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AC730u;
    if (runtime->hasFunction(0x1AC730u)) {
        auto targetFn = runtime->lookupFunction(0x1AC730u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001AC730_0x1ac730(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1BA438u;
    // 0x1ba438: 0x0  nop
    ctx->pc = 0x1ba438u;
    // NOP
    // 0x1ba43c: 0x0  nop
    ctx->pc = 0x1ba43cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
