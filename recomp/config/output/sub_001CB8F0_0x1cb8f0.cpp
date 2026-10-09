#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CB8F0
// Address: 0x1cb8f0 - 0x1cbb60
void sub_001CB8F0_0x1cb8f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CB8F0_0x1cb8f0");
#endif

    switch (ctx->pc) {
        case 0x1cb914u: goto label_1cb914;
        case 0x1cb938u: goto label_1cb938;
        case 0x1cb944u: goto label_1cb944;
        case 0x1cb950u: goto label_1cb950;
        case 0x1cb994u: goto label_1cb994;
        case 0x1cb9acu: goto label_1cb9ac;
        case 0x1cb9c4u: goto label_1cb9c4;
        case 0x1cb9d8u: goto label_1cb9d8;
        case 0x1cb9e4u: goto label_1cb9e4;
        case 0x1cba08u: goto label_1cba08;
        case 0x1cba20u: goto label_1cba20;
        case 0x1cba38u: goto label_1cba38;
        case 0x1cba40u: goto label_1cba40;
        case 0x1cbaa0u: goto label_1cbaa0;
        case 0x1cbac0u: goto label_1cbac0;
        case 0x1cbae0u: goto label_1cbae0;
        case 0x1cbb24u: goto label_1cbb24;
        case 0x1cbb3cu: goto label_1cbb3c;
        default: break;
    }

    ctx->pc = 0x1cb8f0u;

    // 0x1cb8f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cb8f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cb8f4: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cb8f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cb8f8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cb8f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cb8fc: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1cb8fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cb900: 0x8c245ff8  lw          $a0, 0x5FF8($at)
    ctx->pc = 0x1cb900u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24568)));
    // 0x1cb904: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB904u;
    {
        const bool branch_taken_0x1cb904 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1cb904) {
            ctx->pc = 0x1CB914u;
            goto label_1cb914;
        }
    }
    ctx->pc = 0x1CB90Cu;
    // 0x1cb90c: 0xc072f7c  jal         func_1CBDF0
    ctx->pc = 0x1CB90Cu;
    SET_GPR_U32(ctx, 31, 0x1CB914u);
    ctx->pc = 0x1CBDF0u;
    if (runtime->hasFunction(0x1CBDF0u)) {
        auto targetFn = runtime->lookupFunction(0x1CBDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB914u; }
        if (ctx->pc != 0x1CB914u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBDF0_0x1cbdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB914u; }
        if (ctx->pc != 0x1CB914u) { return; }
    }
    ctx->pc = 0x1CB914u;
label_1cb914:
    // 0x1cb914: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cb914u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cb918: 0x3e00008  jr          $ra
    ctx->pc = 0x1CB918u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CB91Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB918u;
            // 0x1cb91c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CB914u: goto label_1cb914;
            case 0x1CB938u: goto label_1cb938;
            case 0x1CB944u: goto label_1cb944;
            case 0x1CB950u: goto label_1cb950;
            case 0x1CB994u: goto label_1cb994;
            case 0x1CB9ACu: goto label_1cb9ac;
            case 0x1CB9C4u: goto label_1cb9c4;
            case 0x1CB9D8u: goto label_1cb9d8;
            case 0x1CB9E4u: goto label_1cb9e4;
            case 0x1CB9FCu: goto label_1cb9fc;
            case 0x1CBA08u: goto label_1cba08;
            case 0x1CBA20u: goto label_1cba20;
            case 0x1CBA38u: goto label_1cba38;
            case 0x1CBA40u: goto label_1cba40;
            case 0x1CBAA0u: goto label_1cbaa0;
            case 0x1CBAC0u: goto label_1cbac0;
            case 0x1CBAE0u: goto label_1cbae0;
            case 0x1CBB24u: goto label_1cbb24;
            case 0x1CBB3Cu: goto label_1cbb3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CB920u;
    // 0x1cb920: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cb920u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cb924: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cb924u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cb928: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cb928u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cb92c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb92cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb930: 0xc072f7c  jal         func_1CBDF0
    ctx->pc = 0x1CB930u;
    SET_GPR_U32(ctx, 31, 0x1CB938u);
    ctx->pc = 0x1CB934u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB930u;
            // 0x1cb934: 0xac22da08  sw          $v0, -0x25F8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294957576), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CBDF0u;
    if (runtime->hasFunction(0x1CBDF0u)) {
        auto targetFn = runtime->lookupFunction(0x1CBDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB938u; }
        if (ctx->pc != 0x1CB938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBDF0_0x1cbdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB938u; }
        if (ctx->pc != 0x1CB938u) { return; }
    }
    ctx->pc = 0x1CB938u;
label_1cb938:
    // 0x1cb938: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cb938u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cb93c: 0xc045198  jal         func_114660
    ctx->pc = 0x1CB93Cu;
    SET_GPR_U32(ctx, 31, 0x1CB944u);
    ctx->pc = 0x1CB940u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB93Cu;
            // 0x1cb940: 0x8c246000  lw          $a0, 0x6000($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24576)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB944u; }
        if (ctx->pc != 0x1CB944u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB944u; }
        if (ctx->pc != 0x1CB944u) { return; }
    }
    ctx->pc = 0x1CB944u;
label_1cb944:
    // 0x1cb944: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cb944u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cb948: 0xc04518c  jal         func_114630
    ctx->pc = 0x1CB948u;
    SET_GPR_U32(ctx, 31, 0x1CB950u);
    ctx->pc = 0x1CB94Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB948u;
            // 0x1cb94c: 0x8c246000  lw          $a0, 0x6000($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24576)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB950u; }
        if (ctx->pc != 0x1CB950u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB950u; }
        if (ctx->pc != 0x1CB950u) { return; }
    }
    ctx->pc = 0x1CB950u;
label_1cb950:
    // 0x1cb950: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1cb950u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cb954: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cb954u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cb958: 0xac236000  sw          $v1, 0x6000($at)
    ctx->pc = 0x1cb958u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24576), GPR_U32(ctx, 3));
    // 0x1cb95c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cb95cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cb960: 0xac235ff8  sw          $v1, 0x5FF8($at)
    ctx->pc = 0x1cb960u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24568), GPR_U32(ctx, 3));
    // 0x1cb964: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cb964u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cb968: 0x3e00008  jr          $ra
    ctx->pc = 0x1CB968u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CB96Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB968u;
            // 0x1cb96c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CB914u: goto label_1cb914;
            case 0x1CB938u: goto label_1cb938;
            case 0x1CB944u: goto label_1cb944;
            case 0x1CB950u: goto label_1cb950;
            case 0x1CB994u: goto label_1cb994;
            case 0x1CB9ACu: goto label_1cb9ac;
            case 0x1CB9C4u: goto label_1cb9c4;
            case 0x1CB9D8u: goto label_1cb9d8;
            case 0x1CB9E4u: goto label_1cb9e4;
            case 0x1CB9FCu: goto label_1cb9fc;
            case 0x1CBA08u: goto label_1cba08;
            case 0x1CBA20u: goto label_1cba20;
            case 0x1CBA38u: goto label_1cba38;
            case 0x1CBA40u: goto label_1cba40;
            case 0x1CBAA0u: goto label_1cbaa0;
            case 0x1CBAC0u: goto label_1cbac0;
            case 0x1CBAE0u: goto label_1cbae0;
            case 0x1CBB24u: goto label_1cbb24;
            case 0x1CBB3Cu: goto label_1cbb3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CB970u;
    // 0x1cb970: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cb970u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cb974: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cb974u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cb978: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cb978u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cb97c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1cb97cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cb980: 0x8c246008  lw          $a0, 0x6008($at)
    ctx->pc = 0x1cb980u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24584)));
    // 0x1cb984: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB984u;
    {
        const bool branch_taken_0x1cb984 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1cb984) {
            ctx->pc = 0x1CB994u;
            goto label_1cb994;
        }
    }
    ctx->pc = 0x1CB98Cu;
    // 0x1cb98c: 0xc045194  jal         func_114650
    ctx->pc = 0x1CB98Cu;
    SET_GPR_U32(ctx, 31, 0x1CB994u);
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB994u; }
        if (ctx->pc != 0x1CB994u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB994u; }
        if (ctx->pc != 0x1CB994u) { return; }
    }
    ctx->pc = 0x1CB994u;
label_1cb994:
    // 0x1cb994: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cb994u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cb998: 0x3e00008  jr          $ra
    ctx->pc = 0x1CB998u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CB99Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB998u;
            // 0x1cb99c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CB914u: goto label_1cb914;
            case 0x1CB938u: goto label_1cb938;
            case 0x1CB944u: goto label_1cb944;
            case 0x1CB950u: goto label_1cb950;
            case 0x1CB994u: goto label_1cb994;
            case 0x1CB9ACu: goto label_1cb9ac;
            case 0x1CB9C4u: goto label_1cb9c4;
            case 0x1CB9D8u: goto label_1cb9d8;
            case 0x1CB9E4u: goto label_1cb9e4;
            case 0x1CB9FCu: goto label_1cb9fc;
            case 0x1CBA08u: goto label_1cba08;
            case 0x1CBA20u: goto label_1cba20;
            case 0x1CBA38u: goto label_1cba38;
            case 0x1CBA40u: goto label_1cba40;
            case 0x1CBAA0u: goto label_1cbaa0;
            case 0x1CBAC0u: goto label_1cbac0;
            case 0x1CBAE0u: goto label_1cbae0;
            case 0x1CBB24u: goto label_1cbb24;
            case 0x1CBB3Cu: goto label_1cbb3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CB9A0u;
    // 0x1cb9a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cb9a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cb9a4: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1CB9A4u;
    {
        const bool branch_taken_0x1cb9a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB9A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB9A4u;
            // 0x1cb9a8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb9a4) {
            ctx->pc = 0x1CB9E4u;
            goto label_1cb9e4;
        }
    }
    ctx->pc = 0x1CB9ACu;
label_1cb9ac:
    // 0x1cb9ac: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1cb9acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cb9b0: 0x8c236008  lw          $v1, 0x6008($at)
    ctx->pc = 0x1cb9b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24584)));
    // 0x1cb9b4: 0x10620011  beq         $v1, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1CB9B4u;
    {
        const bool branch_taken_0x1cb9b4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb9b4) {
            ctx->pc = 0x1CB9FCu;
            goto label_1cb9fc;
        }
    }
    ctx->pc = 0x1CB9BCu;
    // 0x1cb9bc: 0xc073000  jal         func_1CC000
    ctx->pc = 0x1CB9BCu;
    SET_GPR_U32(ctx, 31, 0x1CB9C4u);
    ctx->pc = 0x1CC000u;
    if (runtime->hasFunction(0x1CC000u)) {
        auto targetFn = runtime->lookupFunction(0x1CC000u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB9C4u; }
        if (ctx->pc != 0x1CB9C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC000_0x1cc000(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB9C4u; }
        if (ctx->pc != 0x1CB9C4u) { return; }
    }
    ctx->pc = 0x1CB9C4u;
label_1cb9c4:
    // 0x1cb9c4: 0x3c05001d  lui         $a1, 0x1D
    ctx->pc = 0x1cb9c4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)29 << 16));
    // 0x1cb9c8: 0x24040100  addiu       $a0, $zero, 0x100
    ctx->pc = 0x1cb9c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1cb9cc: 0x24a5b970  addiu       $a1, $a1, -0x4690
    ctx->pc = 0x1cb9ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294949232));
    // 0x1cb9d0: 0xc0450e8  jal         func_1143A0
    ctx->pc = 0x1CB9D0u;
    SET_GPR_U32(ctx, 31, 0x1CB9D8u);
    ctx->pc = 0x1CB9D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB9D0u;
            // 0x1cb9d4: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1143A0u;
    if (runtime->hasFunction(0x1143A0u)) {
        auto targetFn = runtime->lookupFunction(0x1143A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB9D8u; }
        if (ctx->pc != 0x1CB9D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001143A0_0x1143a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB9D8u; }
        if (ctx->pc != 0x1CB9D8u) { return; }
    }
    ctx->pc = 0x1CB9D8u;
label_1cb9d8:
    // 0x1cb9d8: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cb9d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cb9dc: 0xc045198  jal         func_114660
    ctx->pc = 0x1CB9DCu;
    SET_GPR_U32(ctx, 31, 0x1CB9E4u);
    ctx->pc = 0x1CB9E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB9DCu;
            // 0x1cb9e0: 0x8c246008  lw          $a0, 0x6008($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24584)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB9E4u; }
        if (ctx->pc != 0x1CB9E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB9E4u; }
        if (ctx->pc != 0x1CB9E4u) { return; }
    }
    ctx->pc = 0x1CB9E4u;
label_1cb9e4:
    // 0x1cb9e4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb9e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb9e8: 0x8c22da08  lw          $v0, -0x25F8($at)
    ctx->pc = 0x1cb9e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957576)));
    // 0x1cb9ec: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x1cb9ecu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1cb9f0: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1cb9f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1cb9f4: 0x1440ffed  bnez        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1CB9F4u;
    {
        const bool branch_taken_0x1cb9f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CB9F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB9F4u;
            // 0x1cb9f8: 0x3c010023  lui         $at, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb9f4) {
            ctx->pc = 0x1CB9ACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cb9ac;
        }
    }
    ctx->pc = 0x1CB9FCu;
label_1cb9fc:
    // 0x1cb9fc: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cb9fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cba00: 0xc04518c  jal         func_114630
    ctx->pc = 0x1CBA00u;
    SET_GPR_U32(ctx, 31, 0x1CBA08u);
    ctx->pc = 0x1CBA04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBA00u;
            // 0x1cba04: 0x8c246008  lw          $a0, 0x6008($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24584)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBA08u; }
        if (ctx->pc != 0x1CBA08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBA08u; }
        if (ctx->pc != 0x1CBA08u) { return; }
    }
    ctx->pc = 0x1CBA08u;
label_1cba08:
    // 0x1cba08: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cba08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cba0c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1cba0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cba10: 0x8c245fe8  lw          $a0, 0x5FE8($at)
    ctx->pc = 0x1cba10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24552)));
    // 0x1cba14: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cba14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cba18: 0xc04518c  jal         func_114630
    ctx->pc = 0x1CBA18u;
    SET_GPR_U32(ctx, 31, 0x1CBA20u);
    ctx->pc = 0x1CBA1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBA18u;
            // 0x1cba1c: 0xac226008  sw          $v0, 0x6008($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 24584), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBA20u; }
        if (ctx->pc != 0x1CBA20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBA20u; }
        if (ctx->pc != 0x1CBA20u) { return; }
    }
    ctx->pc = 0x1CBA20u;
label_1cba20:
    // 0x1cba20: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cba20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cba24: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1cba24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cba28: 0x8c246000  lw          $a0, 0x6000($at)
    ctx->pc = 0x1cba28u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24576)));
    // 0x1cba2c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cba2cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cba30: 0xc045190  jal         func_114640
    ctx->pc = 0x1CBA30u;
    SET_GPR_U32(ctx, 31, 0x1CBA38u);
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBA38u; }
        if (ctx->pc != 0x1CBA38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBA38u; }
        if (ctx->pc != 0x1CBA38u) { return; }
    }
    ctx->pc = 0x1CBA38u;
label_1cba38:
    // 0x1cba38: 0xc045118  jal         func_114460
    ctx->pc = 0x1CBA38u;
    SET_GPR_U32(ctx, 31, 0x1CBA40u);
    ctx->pc = 0x114460u;
    if (runtime->hasFunction(0x114460u)) {
        auto targetFn = runtime->lookupFunction(0x114460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBA40u; }
        if (ctx->pc != 0x1CBA40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114460_0x114460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBA40u; }
        if (ctx->pc != 0x1CBA40u) { return; }
    }
    ctx->pc = 0x1CBA40u;
label_1cba40:
    // 0x1cba40: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cba40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cba44: 0x3e00008  jr          $ra
    ctx->pc = 0x1CBA44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CBA48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBA44u;
            // 0x1cba48: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CB914u: goto label_1cb914;
            case 0x1CB938u: goto label_1cb938;
            case 0x1CB944u: goto label_1cb944;
            case 0x1CB950u: goto label_1cb950;
            case 0x1CB994u: goto label_1cb994;
            case 0x1CB9ACu: goto label_1cb9ac;
            case 0x1CB9C4u: goto label_1cb9c4;
            case 0x1CB9D8u: goto label_1cb9d8;
            case 0x1CB9E4u: goto label_1cb9e4;
            case 0x1CB9FCu: goto label_1cb9fc;
            case 0x1CBA08u: goto label_1cba08;
            case 0x1CBA20u: goto label_1cba20;
            case 0x1CBA38u: goto label_1cba38;
            case 0x1CBA40u: goto label_1cba40;
            case 0x1CBAA0u: goto label_1cbaa0;
            case 0x1CBAC0u: goto label_1cbac0;
            case 0x1CBAE0u: goto label_1cbae0;
            case 0x1CBB24u: goto label_1cbb24;
            case 0x1CBB3Cu: goto label_1cbb3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CBA4Cu;
    // 0x1cba4c: 0x0  nop
    ctx->pc = 0x1cba4cu;
    // NOP
    // 0x1cba50: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x1cba50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1cba54: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cba54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cba58: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1cba58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1cba5c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cba5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cba60: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1cba60u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1cba64: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1cba64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1cba68: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cba68u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cba6c: 0x27b20048  addiu       $s2, $sp, 0x48
    ctx->pc = 0x1cba6cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
    // 0x1cba70: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cba70u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cba74: 0x27b10044  addiu       $s1, $sp, 0x44
    ctx->pc = 0x1cba74u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 68));
    // 0x1cba78: 0xac20d9f8  sw          $zero, -0x2608($at)
    ctx->pc = 0x1cba78u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957560), GPR_U32(ctx, 0));
    // 0x1cba7c: 0x27b00054  addiu       $s0, $sp, 0x54
    ctx->pc = 0x1cba7cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 84));
    // 0x1cba80: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cba80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cba84: 0xac20da00  sw          $zero, -0x2600($at)
    ctx->pc = 0x1cba84u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957568), GPR_U32(ctx, 0));
    // 0x1cba88: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cba88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cba8c: 0xac20da08  sw          $zero, -0x25F8($at)
    ctx->pc = 0x1cba8cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957576), GPR_U32(ctx, 0));
    // 0x1cba90: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x1cba90u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x1cba94: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1cba94u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1cba98: 0xc045188  jal         func_114620
    ctx->pc = 0x1CBA98u;
    SET_GPR_U32(ctx, 31, 0x1CBAA0u);
    ctx->pc = 0x1CBA9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBA98u;
            // 0x1cba9c: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBAA0u; }
        if (ctx->pc != 0x1CBAA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBAA0u; }
        if (ctx->pc != 0x1CBAA0u) { return; }
    }
    ctx->pc = 0x1CBAA0u;
label_1cbaa0:
    // 0x1cbaa0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbaa0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbaa4: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1cbaa4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1cbaa8: 0xac226008  sw          $v0, 0x6008($at)
    ctx->pc = 0x1cbaa8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24584), GPR_U32(ctx, 2));
    // 0x1cbaac: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cbaacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cbab0: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x1cbab0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x1cbab4: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1cbab4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1cbab8: 0xc045188  jal         func_114620
    ctx->pc = 0x1CBAB8u;
    SET_GPR_U32(ctx, 31, 0x1CBAC0u);
    ctx->pc = 0x1CBABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBAB8u;
            // 0x1cbabc: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBAC0u; }
        if (ctx->pc != 0x1CBAC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBAC0u; }
        if (ctx->pc != 0x1CBAC0u) { return; }
    }
    ctx->pc = 0x1CBAC0u;
label_1cbac0:
    // 0x1cbac0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbac0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbac4: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1cbac4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1cbac8: 0xac226000  sw          $v0, 0x6000($at)
    ctx->pc = 0x1cbac8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24576), GPR_U32(ctx, 2));
    // 0x1cbacc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cbaccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cbad0: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x1cbad0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x1cbad4: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1cbad4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1cbad8: 0xc045188  jal         func_114620
    ctx->pc = 0x1CBAD8u;
    SET_GPR_U32(ctx, 31, 0x1CBAE0u);
    ctx->pc = 0x1CBADCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBAD8u;
            // 0x1cbadc: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBAE0u; }
        if (ctx->pc != 0x1CBAE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBAE0u; }
        if (ctx->pc != 0x1CBAE0u) { return; }
    }
    ctx->pc = 0x1CBAE0u;
label_1cbae0:
    // 0x1cbae0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbae0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbae4: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1cbae4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1cbae8: 0xac225fe8  sw          $v0, 0x5FE8($at)
    ctx->pc = 0x1cbae8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24552), GPR_U32(ctx, 2));
    // 0x1cbaec: 0x24022000  addiu       $v0, $zero, 0x2000
    ctx->pc = 0x1cbaecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1cbaf0: 0xafa2006c  sw          $v0, 0x6C($sp)
    ctx->pc = 0x1cbaf0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 2));
    // 0x1cbaf4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1cbaf4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1cbaf8: 0x24421cf0  addiu       $v0, $v0, 0x1CF0
    ctx->pc = 0x1cbaf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7408));
    // 0x1cbafc: 0xafa20070  sw          $v0, 0x70($sp)
    ctx->pc = 0x1cbafcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 112), GPR_U32(ctx, 2));
    // 0x1cbb00: 0x3c02001d  lui         $v0, 0x1D
    ctx->pc = 0x1cbb00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)29 << 16));
    // 0x1cbb04: 0x2442b9a0  addiu       $v0, $v0, -0x4660
    ctx->pc = 0x1cbb04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949280));
    // 0x1cbb08: 0xafa20064  sw          $v0, 0x64($sp)
    ctx->pc = 0x1cbb08u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 100), GPR_U32(ctx, 2));
    // 0x1cbb0c: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cbb0cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cbb10: 0x2442da10  addiu       $v0, $v0, -0x25F0
    ctx->pc = 0x1cbb10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294957584));
    // 0x1cbb14: 0xafa20068  sw          $v0, 0x68($sp)
    ctx->pc = 0x1cbb14u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 2));
    // 0x1cbb18: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1cbb18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1cbb1c: 0xc045108  jal         func_114420
    ctx->pc = 0x1CBB1Cu;
    SET_GPR_U32(ctx, 31, 0x1CBB24u);
    ctx->pc = 0x1CBB20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBB1Cu;
            // 0x1cbb20: 0xafa20074  sw          $v0, 0x74($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 116), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114420u;
    if (runtime->hasFunction(0x114420u)) {
        auto targetFn = runtime->lookupFunction(0x114420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBB24u; }
        if (ctx->pc != 0x1CBB24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114420_0x114420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBB24u; }
        if (ctx->pc != 0x1CBB24u) { return; }
    }
    ctx->pc = 0x1CBB24u;
label_1cbb24:
    // 0x1cbb24: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbb24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbb28: 0xac225ff8  sw          $v0, 0x5FF8($at)
    ctx->pc = 0x1cbb28u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24568), GPR_U32(ctx, 2));
    // 0x1cbb2c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbb2cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbb30: 0x8c245ff8  lw          $a0, 0x5FF8($at)
    ctx->pc = 0x1cbb30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24568)));
    // 0x1cbb34: 0xc045110  jal         func_114440
    ctx->pc = 0x1CBB34u;
    SET_GPR_U32(ctx, 31, 0x1CBB3Cu);
    ctx->pc = 0x1CBB38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBB34u;
            // 0x1cbb38: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114440u;
    if (runtime->hasFunction(0x114440u)) {
        auto targetFn = runtime->lookupFunction(0x114440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBB3Cu; }
        if (ctx->pc != 0x1CBB3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114440_0x114440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBB3Cu; }
        if (ctx->pc != 0x1CBB3Cu) { return; }
    }
    ctx->pc = 0x1CBB3Cu;
label_1cbb3c:
    // 0x1cbb3c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1cbb3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1cbb40: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1cbb40u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cbb44: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cbb44u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cbb48: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cbb48u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cbb4c: 0x3e00008  jr          $ra
    ctx->pc = 0x1CBB4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CBB50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBB4Cu;
            // 0x1cbb50: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CB914u: goto label_1cb914;
            case 0x1CB938u: goto label_1cb938;
            case 0x1CB944u: goto label_1cb944;
            case 0x1CB950u: goto label_1cb950;
            case 0x1CB994u: goto label_1cb994;
            case 0x1CB9ACu: goto label_1cb9ac;
            case 0x1CB9C4u: goto label_1cb9c4;
            case 0x1CB9D8u: goto label_1cb9d8;
            case 0x1CB9E4u: goto label_1cb9e4;
            case 0x1CB9FCu: goto label_1cb9fc;
            case 0x1CBA08u: goto label_1cba08;
            case 0x1CBA20u: goto label_1cba20;
            case 0x1CBA38u: goto label_1cba38;
            case 0x1CBA40u: goto label_1cba40;
            case 0x1CBAA0u: goto label_1cbaa0;
            case 0x1CBAC0u: goto label_1cbac0;
            case 0x1CBAE0u: goto label_1cbae0;
            case 0x1CBB24u: goto label_1cbb24;
            case 0x1CBB3Cu: goto label_1cbb3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CBB54u;
    // 0x1cbb54: 0x0  nop
    ctx->pc = 0x1cbb54u;
    // NOP
    // 0x1cbb58: 0x0  nop
    ctx->pc = 0x1cbb58u;
    // NOP
    // 0x1cbb5c: 0x0  nop
    ctx->pc = 0x1cbb5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
