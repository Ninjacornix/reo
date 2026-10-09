#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A2490
// Address: 0x1a2490 - 0x1a2550
void sub_001A2490_0x1a2490(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A2490_0x1a2490");
#endif

    switch (ctx->pc) {
        case 0x1a24f4u: goto label_1a24f4;
        case 0x1a2504u: goto label_1a2504;
        case 0x1a2514u: goto label_1a2514;
        case 0x1a2524u: goto label_1a2524;
        case 0x1a2534u: goto label_1a2534;
        case 0x1a2544u: goto label_1a2544;
        default: break;
    }

    ctx->pc = 0x1a2490u;

    // 0x1a2490: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a2490u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a2494: 0x3c0600ff  lui         $a2, 0xFF
    ctx->pc = 0x1a2494u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)255 << 16));
    // 0x1a2498: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a2498u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a249c: 0x24030013  addiu       $v1, $zero, 0x13
    ctx->pc = 0x1a249cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x1a24a0: 0x8c870000  lw          $a3, 0x0($a0)
    ctx->pc = 0x1a24a0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a24a4: 0xe63024  and         $a2, $a3, $a2
    ctx->pc = 0x1a24a4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 7) & GPR_U64(ctx, 6));
    // 0x1a24a8: 0x63402  srl         $a2, $a2, 16
    ctx->pc = 0x1a24a8u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 16));
    // 0x1a24ac: 0x10c30023  beq         $a2, $v1, . + 4 + (0x23 << 2)
    ctx->pc = 0x1A24ACu;
    {
        const bool branch_taken_0x1a24ac = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A24B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A24ACu;
            // 0x1a24b0: 0x24030012  addiu       $v1, $zero, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a24ac) {
            ctx->pc = 0x1A253Cu;
            goto label_1a253c;
        }
    }
    ctx->pc = 0x1A24B4u;
    // 0x1a24b4: 0x10c3001d  beq         $a2, $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x1A24B4u;
    {
        const bool branch_taken_0x1a24b4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        if (branch_taken_0x1a24b4) {
            ctx->pc = 0x1A252Cu;
            goto label_1a252c;
        }
    }
    ctx->pc = 0x1A24BCu;
    // 0x1a24bc: 0x24030011  addiu       $v1, $zero, 0x11
    ctx->pc = 0x1a24bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x1a24c0: 0x10c30016  beq         $a2, $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x1A24C0u;
    {
        const bool branch_taken_0x1a24c0 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A24C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A24C0u;
            // 0x1a24c4: 0x24030023  addiu       $v1, $zero, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 35));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a24c0) {
            ctx->pc = 0x1A251Cu;
            goto label_1a251c;
        }
    }
    ctx->pc = 0x1A24C8u;
    // 0x1a24c8: 0x10c30010  beq         $a2, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1A24C8u;
    {
        const bool branch_taken_0x1a24c8 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        if (branch_taken_0x1a24c8) {
            ctx->pc = 0x1A250Cu;
            goto label_1a250c;
        }
    }
    ctx->pc = 0x1A24D0u;
    // 0x1a24d0: 0x24030022  addiu       $v1, $zero, 0x22
    ctx->pc = 0x1a24d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1a24d4: 0x10c30009  beq         $a2, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1A24D4u;
    {
        const bool branch_taken_0x1a24d4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A24D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A24D4u;
            // 0x1a24d8: 0x24030021  addiu       $v1, $zero, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a24d4) {
            ctx->pc = 0x1A24FCu;
            goto label_1a24fc;
        }
    }
    ctx->pc = 0x1A24DCu;
    // 0x1a24dc: 0x10c30003  beq         $a2, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A24DCu;
    {
        const bool branch_taken_0x1a24dc = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        if (branch_taken_0x1a24dc) {
            ctx->pc = 0x1A24ECu;
            goto label_1a24ec;
        }
    }
    ctx->pc = 0x1A24E4u;
    // 0x1a24e4: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1A24E4u;
    {
        const bool branch_taken_0x1a24e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A24E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A24E4u;
            // 0x1a24e8: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a24e4) {
            ctx->pc = 0x1A2548u;
            goto label_1a2548;
        }
    }
    ctx->pc = 0x1A24ECu;
label_1a24ec:
    // 0x1a24ec: 0xc068954  jal         func_1A2550
    ctx->pc = 0x1A24ECu;
    SET_GPR_U32(ctx, 31, 0x1A24F4u);
    ctx->pc = 0x1A2550u;
    if (runtime->hasFunction(0x1A2550u)) {
        auto targetFn = runtime->lookupFunction(0x1A2550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A24F4u; }
        if (ctx->pc != 0x1A24F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2550_0x1a2550(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A24F4u; }
        if (ctx->pc != 0x1A24F4u) { return; }
    }
    ctx->pc = 0x1A24F4u;
label_1a24f4:
    // 0x1a24f4: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1A24F4u;
    {
        const bool branch_taken_0x1a24f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a24f4) {
            ctx->pc = 0x1A2544u;
            goto label_1a2544;
        }
    }
    ctx->pc = 0x1A24FCu;
label_1a24fc:
    // 0x1a24fc: 0xc068980  jal         func_1A2600
    ctx->pc = 0x1A24FCu;
    SET_GPR_U32(ctx, 31, 0x1A2504u);
    ctx->pc = 0x1A2600u;
    if (runtime->hasFunction(0x1A2600u)) {
        auto targetFn = runtime->lookupFunction(0x1A2600u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2504u; }
        if (ctx->pc != 0x1A2504u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2600_0x1a2600(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2504u; }
        if (ctx->pc != 0x1A2504u) { return; }
    }
    ctx->pc = 0x1A2504u;
label_1a2504:
    // 0x1a2504: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1A2504u;
    {
        const bool branch_taken_0x1a2504 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a2504) {
            ctx->pc = 0x1A2544u;
            goto label_1a2544;
        }
    }
    ctx->pc = 0x1A250Cu;
label_1a250c:
    // 0x1a250c: 0xc0689b0  jal         func_1A26C0
    ctx->pc = 0x1A250Cu;
    SET_GPR_U32(ctx, 31, 0x1A2514u);
    ctx->pc = 0x1A26C0u;
    if (runtime->hasFunction(0x1A26C0u)) {
        auto targetFn = runtime->lookupFunction(0x1A26C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2514u; }
        if (ctx->pc != 0x1A2514u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A26C0_0x1a26c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2514u; }
        if (ctx->pc != 0x1A2514u) { return; }
    }
    ctx->pc = 0x1A2514u;
label_1a2514:
    // 0x1a2514: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1A2514u;
    {
        const bool branch_taken_0x1a2514 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a2514) {
            ctx->pc = 0x1A2544u;
            goto label_1a2544;
        }
    }
    ctx->pc = 0x1A251Cu;
label_1a251c:
    // 0x1a251c: 0xc0689e4  jal         func_1A2790
    ctx->pc = 0x1A251Cu;
    SET_GPR_U32(ctx, 31, 0x1A2524u);
    ctx->pc = 0x1A2790u;
    if (runtime->hasFunction(0x1A2790u)) {
        auto targetFn = runtime->lookupFunction(0x1A2790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2524u; }
        if (ctx->pc != 0x1A2524u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2790_0x1a2790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2524u; }
        if (ctx->pc != 0x1A2524u) { return; }
    }
    ctx->pc = 0x1A2524u;
label_1a2524:
    // 0x1a2524: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1A2524u;
    {
        const bool branch_taken_0x1a2524 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a2524) {
            ctx->pc = 0x1A2544u;
            goto label_1a2544;
        }
    }
    ctx->pc = 0x1A252Cu;
label_1a252c:
    // 0x1a252c: 0xc068a10  jal         func_1A2840
    ctx->pc = 0x1A252Cu;
    SET_GPR_U32(ctx, 31, 0x1A2534u);
    ctx->pc = 0x1A2840u;
    if (runtime->hasFunction(0x1A2840u)) {
        auto targetFn = runtime->lookupFunction(0x1A2840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2534u; }
        if (ctx->pc != 0x1A2534u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2840_0x1a2840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2534u; }
        if (ctx->pc != 0x1A2534u) { return; }
    }
    ctx->pc = 0x1A2534u;
label_1a2534:
    // 0x1a2534: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A2534u;
    {
        const bool branch_taken_0x1a2534 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a2534) {
            ctx->pc = 0x1A2544u;
            goto label_1a2544;
        }
    }
    ctx->pc = 0x1A253Cu;
label_1a253c:
    // 0x1a253c: 0xc068a40  jal         func_1A2900
    ctx->pc = 0x1A253Cu;
    SET_GPR_U32(ctx, 31, 0x1A2544u);
    ctx->pc = 0x1A2900u;
    if (runtime->hasFunction(0x1A2900u)) {
        auto targetFn = runtime->lookupFunction(0x1A2900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2544u; }
        if (ctx->pc != 0x1A2544u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2900_0x1a2900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2544u; }
        if (ctx->pc != 0x1A2544u) { return; }
    }
    ctx->pc = 0x1A2544u;
label_1a2544:
    // 0x1a2544: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a2544u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1a2548:
    // 0x1a2548: 0x3e00008  jr          $ra
    ctx->pc = 0x1A2548u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A254Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2548u;
            // 0x1a254c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A24ECu: goto label_1a24ec;
            case 0x1A24F4u: goto label_1a24f4;
            case 0x1A24FCu: goto label_1a24fc;
            case 0x1A2504u: goto label_1a2504;
            case 0x1A250Cu: goto label_1a250c;
            case 0x1A2514u: goto label_1a2514;
            case 0x1A251Cu: goto label_1a251c;
            case 0x1A2524u: goto label_1a2524;
            case 0x1A252Cu: goto label_1a252c;
            case 0x1A2534u: goto label_1a2534;
            case 0x1A253Cu: goto label_1a253c;
            case 0x1A2544u: goto label_1a2544;
            case 0x1A2548u: goto label_1a2548;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A2550u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
