#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001130F8
// Address: 0x1130f8 - 0x113390
void sub_001130F8_0x1130f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001130F8_0x1130f8");
#endif

    switch (ctx->pc) {
        case 0x113154u: goto label_113154;
        case 0x11317cu: goto label_11317c;
        case 0x113198u: goto label_113198;
        case 0x1131b4u: goto label_1131b4;
        case 0x1131d0u: goto label_1131d0;
        case 0x113218u: goto label_113218;
        case 0x113248u: goto label_113248;
        case 0x1132ecu: goto label_1132ec;
        default: break;
    }

    ctx->pc = 0x1130f8u;

    // 0x1130f8: 0x27bdff30  addiu       $sp, $sp, -0xD0
    ctx->pc = 0x1130f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967088));
    // 0x1130fc: 0x52c00  sll         $a1, $a1, 16
    ctx->pc = 0x1130fcu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x113100: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x113100u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x113104: 0x84400  sll         $t0, $t0, 16
    ctx->pc = 0x113104u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 16));
    // 0x113108: 0xffbe00b0  sd          $fp, 0xB0($sp)
    ctx->pc = 0x113108u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 30));
    // 0x11310c: 0x98400  sll         $s0, $t1, 16
    ctx->pc = 0x11310cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 9), 16));
    // 0x113110: 0xffb700a0  sd          $s7, 0xA0($sp)
    ctx->pc = 0x113110u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 23));
    // 0x113114: 0xa5400  sll         $t2, $t2, 16
    ctx->pc = 0x113114u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 16));
    // 0x113118: 0xffb60090  sd          $s6, 0x90($sp)
    ctx->pc = 0x113118u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 22));
    // 0x11311c: 0x108403  sra         $s0, $s0, 16
    ctx->pc = 0x11311cu;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 16));
    // 0x113120: 0xffb50080  sd          $s5, 0x80($sp)
    ctx->pc = 0x113120u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 21));
    // 0x113124: 0x5b403  sra         $s6, $a1, 16
    ctx->pc = 0x113124u;
    SET_GPR_S32(ctx, 22, SRA32(GPR_S32(ctx, 5), 16));
    // 0x113128: 0xffb20050  sd          $s2, 0x50($sp)
    ctx->pc = 0x113128u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
    // 0x11312c: 0x8ac03  sra         $s5, $t0, 16
    ctx->pc = 0x11312cu;
    SET_GPR_S32(ctx, 21, SRA32(GPR_S32(ctx, 8), 16));
    // 0x113130: 0xffb10040  sd          $s1, 0x40($sp)
    ctx->pc = 0x113130u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 17));
    // 0x113134: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x113134u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113138: 0xffb40070  sd          $s4, 0x70($sp)
    ctx->pc = 0x113138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 20));
    // 0x11313c: 0xabc03  sra         $s7, $t2, 16
    ctx->pc = 0x11313cu;
    SET_GPR_S32(ctx, 23, SRA32(GPR_S32(ctx, 10), 16));
    // 0x113140: 0xffb30060  sd          $s3, 0x60($sp)
    ctx->pc = 0x113140u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 19));
    // 0x113144: 0x68c00  sll         $s1, $a2, 16
    ctx->pc = 0x113144u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 6), 16));
    // 0x113148: 0xffbf00c0  sd          $ra, 0xC0($sp)
    ctx->pc = 0x113148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 31));
    // 0x11314c: 0xc0449be  jal         func_1126F8
    ctx->pc = 0x11314Cu;
    SET_GPR_U32(ctx, 31, 0x113154u);
    ctx->pc = 0x113150u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11314Cu;
            // 0x113150: 0x7f400  sll         $fp, $a3, 16 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1126F8u;
    if (runtime->hasFunction(0x1126F8u)) {
        auto targetFn = runtime->lookupFunction(0x1126F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113154u; }
        if (ctx->pc != 0x113154u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001126F8_0x1126f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113154u; }
        if (ctx->pc != 0x113154u) { return; }
    }
    ctx->pc = 0x113154u;
label_113154:
    // 0x113154: 0x119c03  sra         $s3, $s1, 16
    ctx->pc = 0x113154u;
    SET_GPR_S32(ctx, 19, SRA32(GPR_S32(ctx, 17), 16));
    // 0x113158: 0x1ea403  sra         $s4, $fp, 16
    ctx->pc = 0x113158u;
    SET_GPR_S32(ctx, 20, SRA32(GPR_S32(ctx, 30), 16));
    // 0x11315c: 0xafa20020  sw          $v0, 0x20($sp)
    ctx->pc = 0x11315cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    // 0x113160: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x113160u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113164: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x113164u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113168: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x113168u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11316c: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x11316cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113170: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x113170u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113174: 0xc044a08  jal         func_112820
    ctx->pc = 0x113174u;
    SET_GPR_U32(ctx, 31, 0x11317Cu);
    ctx->pc = 0x113178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113174u;
            // 0x113178: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112820u;
    if (runtime->hasFunction(0x112820u)) {
        auto targetFn = runtime->lookupFunction(0x112820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11317Cu; }
        if (ctx->pc != 0x11317Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112820_0x112820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11317Cu; }
        if (ctx->pc != 0x11317Cu) { return; }
    }
    ctx->pc = 0x11317Cu;
label_11317c:
    // 0x11317c: 0x26440028  addiu       $a0, $s2, 0x28
    ctx->pc = 0x11317cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 40));
    // 0x113180: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x113180u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113184: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x113184u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113188: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x113188u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11318c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x11318cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113190: 0xc044a08  jal         func_112820
    ctx->pc = 0x113190u;
    SET_GPR_U32(ctx, 31, 0x113198u);
    ctx->pc = 0x113194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113190u;
            // 0x113194: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112820u;
    if (runtime->hasFunction(0x112820u)) {
        auto targetFn = runtime->lookupFunction(0x112820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113198u; }
        if (ctx->pc != 0x113198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112820_0x112820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113198u; }
        if (ctx->pc != 0x113198u) { return; }
    }
    ctx->pc = 0x113198u;
label_113198:
    // 0x113198: 0x26440060  addiu       $a0, $s2, 0x60
    ctx->pc = 0x113198u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 96));
    // 0x11319c: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x11319cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1131a0: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1131a0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1131a4: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x1131a4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1131a8: 0x2a0402d  daddu       $t0, $s5, $zero
    ctx->pc = 0x1131a8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1131ac: 0xc044b48  jal         func_112D20
    ctx->pc = 0x1131ACu;
    SET_GPR_U32(ctx, 31, 0x1131B4u);
    ctx->pc = 0x1131B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1131ACu;
            // 0x1131b0: 0x200482d  daddu       $t1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112D20u;
    if (runtime->hasFunction(0x112D20u)) {
        auto targetFn = runtime->lookupFunction(0x112D20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1131B4u; }
        if (ctx->pc != 0x1131B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112D20_0x112d20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1131B4u; }
        if (ctx->pc != 0x1131B4u) { return; }
    }
    ctx->pc = 0x1131B4u;
label_1131b4:
    // 0x1131b4: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x1131b4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1131b8: 0x26440150  addiu       $a0, $s2, 0x150
    ctx->pc = 0x1131b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 336));
    // 0x1131bc: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x1131bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1131c0: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1131c0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1131c4: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x1131c4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1131c8: 0xc044b48  jal         func_112D20
    ctx->pc = 0x1131C8u;
    SET_GPR_U32(ctx, 31, 0x1131D0u);
    ctx->pc = 0x1131CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1131C8u;
            // 0x1131cc: 0x2a0402d  daddu       $t0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112D20u;
    if (runtime->hasFunction(0x112D20u)) {
        auto targetFn = runtime->lookupFunction(0x112D20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1131D0u; }
        if (ctx->pc != 0x1131D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112D20_0x112d20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1131D0u; }
        if (ctx->pc != 0x1131D0u) { return; }
    }
    ctx->pc = 0x1131D0u;
label_1131d0:
    // 0x1131d0: 0x12e0001d  beqz        $s7, . + 4 + (0x1D << 2)
    ctx->pc = 0x1131D0u;
    {
        const bool branch_taken_0x1131d0 = (GPR_U64(ctx, 23) == GPR_U64(ctx, 0));
        ctx->pc = 0x1131D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1131D0u;
            // 0x1131d4: 0x111443  sra         $v0, $s1, 17 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 17), 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1131d0) {
            ctx->pc = 0x113248u;
            goto label_113248;
        }
    }
    ctx->pc = 0x1131D8u;
    // 0x1131d8: 0x24100800  addiu       $s0, $zero, 0x800
    ctx->pc = 0x1131d8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x1131dc: 0x1e8c43  sra         $s1, $fp, 17
    ctx->pc = 0x1131dcu;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 30), 17));
    // 0x1131e0: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x1131e0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x1131e4: 0x2118823  subu        $s1, $s0, $s1
    ctx->pc = 0x1131e4u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x1131e8: 0xafa00008  sw          $zero, 0x8($sp)
    ctx->pc = 0x1131e8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 0));
    // 0x1131ec: 0x2028023  subu        $s0, $s0, $v0
    ctx->pc = 0x1131ecu;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1131f0: 0x264400e0  addiu       $a0, $s2, 0xE0
    ctx->pc = 0x1131f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 224));
    // 0x1131f4: 0xafa00010  sw          $zero, 0x10($sp)
    ctx->pc = 0x1131f4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x1131f8: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x1131f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1131fc: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1131fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113200: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x113200u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113204: 0x260402d  daddu       $t0, $s3, $zero
    ctx->pc = 0x113204u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113208: 0x280482d  daddu       $t1, $s4, $zero
    ctx->pc = 0x113208u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11320c: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x11320cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113210: 0xc044bc2  jal         func_112F08
    ctx->pc = 0x113210u;
    SET_GPR_U32(ctx, 31, 0x113218u);
    ctx->pc = 0x113214u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113210u;
            // 0x113214: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112F08u;
    if (runtime->hasFunction(0x112F08u)) {
        auto targetFn = runtime->lookupFunction(0x112F08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113218u; }
        if (ctx->pc != 0x113218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112F08_0x112f08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113218u; }
        if (ctx->pc != 0x113218u) { return; }
    }
    ctx->pc = 0x113218u;
label_113218:
    // 0x113218: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x113218u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11321c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x11321cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113220: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x113220u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113224: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x113224u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x113228: 0xafa00008  sw          $zero, 0x8($sp)
    ctx->pc = 0x113228u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 0));
    // 0x11322c: 0x264401d0  addiu       $a0, $s2, 0x1D0
    ctx->pc = 0x11322cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 464));
    // 0x113230: 0xafa00010  sw          $zero, 0x10($sp)
    ctx->pc = 0x113230u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x113234: 0x260402d  daddu       $t0, $s3, $zero
    ctx->pc = 0x113234u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113238: 0x280482d  daddu       $t1, $s4, $zero
    ctx->pc = 0x113238u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11323c: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x11323cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113240: 0xc044bc2  jal         func_112F08
    ctx->pc = 0x113240u;
    SET_GPR_U32(ctx, 31, 0x113248u);
    ctx->pc = 0x113244u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113240u;
            // 0x113244: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112F08u;
    if (runtime->hasFunction(0x112F08u)) {
        auto targetFn = runtime->lookupFunction(0x112F08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113248u; }
        if (ctx->pc != 0x113248u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112F08_0x112f08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113248u; }
        if (ctx->pc != 0x113248u) { return; }
    }
    ctx->pc = 0x113248u;
label_113248:
    // 0x113248: 0x700014a9  por         $v0, $zero, $zero
    ctx->pc = 0x113248u;
    SET_GPR_VEC(ctx, 2, PS2_POR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x11324c: 0x2409000e  addiu       $t1, $zero, 0xE
    ctx->pc = 0x11324cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x113250: 0x7e420050  sq          $v0, 0x50($s2)
    ctx->pc = 0x113250u;
    WRITE128(ADD32(GPR_U32(ctx, 18), 80), GPR_VEC(ctx, 2));
    // 0x113254: 0x24058000  addiu       $a1, $zero, -0x8000
    ctx->pc = 0x113254u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294934528));
    // 0x113258: 0x7e420140  sq          $v0, 0x140($s2)
    ctx->pc = 0x113258u;
    WRITE128(ADD32(GPR_U32(ctx, 18), 320), GPR_VEC(ctx, 2));
    // 0x11325c: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x11325cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x113260: 0xde440050  ld          $a0, 0x50($s2)
    ctx->pc = 0x113260u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 18), 80)));
    // 0x113264: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x113264u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x113268: 0xde460140  ld          $a2, 0x140($s2)
    ctx->pc = 0x113268u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 18), 320)));
    // 0x11326c: 0x137100b  movn        $v0, $t1, $s7
    ctx->pc = 0x11326cu;
    if (GPR_U64(ctx, 23) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 9));
    // 0x113270: 0x852024  and         $a0, $a0, $a1
    ctx->pc = 0x113270u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x113274: 0x137180b  movn        $v1, $t1, $s7
    ctx->pc = 0x113274u;
    if (GPR_U64(ctx, 23) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 9));
    // 0x113278: 0xc53024  and         $a2, $a2, $a1
    ctx->pc = 0x113278u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 5));
    // 0x11327c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x11327cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x113280: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x113280u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x113284: 0x34028000  ori         $v0, $zero, 0x8000
    ctx->pc = 0x113284u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x113288: 0xde470058  ld          $a3, 0x58($s2)
    ctx->pc = 0x113288u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 18), 88)));
    // 0x11328c: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x11328cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x113290: 0xde480148  ld          $t0, 0x148($s2)
    ctx->pc = 0x113290u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 18), 328)));
    // 0x113294: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x113294u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x113298: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x113298u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11329c: 0x3193a  dsrl        $v1, $v1, 4
    ctx->pc = 0x11329cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> 4);
    // 0x1132a0: 0x2405fff0  addiu       $a1, $zero, -0x10
    ctx->pc = 0x1132a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
    // 0x1132a4: 0x34028000  ori         $v0, $zero, 0x8000
    ctx->pc = 0x1132a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x1132a8: 0x2137c  dsll32      $v0, $v0, 13
    ctx->pc = 0x1132a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 13));
    // 0x1132ac: 0xc33024  and         $a2, $a2, $v1
    ctx->pc = 0x1132acu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 3));
    // 0x1132b0: 0x832024  and         $a0, $a0, $v1
    ctx->pc = 0x1132b0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x1132b4: 0x1054024  and         $t0, $t0, $a1
    ctx->pc = 0x1132b4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) & GPR_U64(ctx, 5));
    // 0x1132b8: 0xe53824  and         $a3, $a3, $a1
    ctx->pc = 0x1132b8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & GPR_U64(ctx, 5));
    // 0x1132bc: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x1132bcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x1132c0: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1132c0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1132c4: 0x1094025  or          $t0, $t0, $t1
    ctx->pc = 0x1132c4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 9));
    // 0x1132c8: 0xe93825  or          $a3, $a3, $t1
    ctx->pc = 0x1132c8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 9));
    // 0x1132cc: 0xfe440050  sd          $a0, 0x50($s2)
    ctx->pc = 0x1132ccu;
    WRITE64(ADD32(GPR_U32(ctx, 18), 80), GPR_U64(ctx, 4));
    // 0x1132d0: 0xfe460140  sd          $a2, 0x140($s2)
    ctx->pc = 0x1132d0u;
    WRITE64(ADD32(GPR_U32(ctx, 18), 320), GPR_U64(ctx, 6));
    // 0x1132d4: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x1132d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1132d8: 0xfe470058  sd          $a3, 0x58($s2)
    ctx->pc = 0x1132d8u;
    WRITE64(ADD32(GPR_U32(ctx, 18), 88), GPR_U64(ctx, 7));
    // 0x1132dc: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1132dcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1132e0: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x1132e0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1132e4: 0xc044b16  jal         func_112C58
    ctx->pc = 0x1132E4u;
    SET_GPR_U32(ctx, 31, 0x1132ECu);
    ctx->pc = 0x1132E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1132E4u;
            // 0x1132e8: 0xfe480148  sd          $t0, 0x148($s2) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 18), 328), GPR_U64(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112C58u;
    if (runtime->hasFunction(0x112C58u)) {
        auto targetFn = runtime->lookupFunction(0x112C58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1132ECu; }
        if (ctx->pc != 0x1132ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112C58_0x112c58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1132ECu; }
        if (ctx->pc != 0x1132ECu) { return; }
    }
    ctx->pc = 0x1132ECu;
label_1132ec:
    // 0x1132ec: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x1132ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1132f0: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1132f0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1132f4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1132f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1132f8: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x1132f8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x1132fc: 0x34840001  ori         $a0, $a0, 0x1
    ctx->pc = 0x1132fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)1);
    // 0x113300: 0xdc620000  ld          $v0, 0x0($v1)
    ctx->pc = 0x113300u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x113304: 0x3403ffff  ori         $v1, $zero, 0xFFFF
    ctx->pc = 0x113304u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x113308: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x113308u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x11330c: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x11330cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x113310: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x113310u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x113314: 0x10440004  beq         $v0, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x113314u;
    {
        const bool branch_taken_0x113314 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x113318u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113314u;
            // 0x113318: 0x8fa30020  lw          $v1, 0x20($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113314) {
            ctx->pc = 0x113328u;
            goto label_113328;
        }
    }
    ctx->pc = 0x11331Cu;
    // 0x11331c: 0x84620000  lh          $v0, 0x0($v1)
    ctx->pc = 0x11331cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x113320: 0x14400010  bnez        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x113320u;
    {
        const bool branch_taken_0x113320 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x113324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113320u;
            // 0x113324: 0xdfbf00c0  ld          $ra, 0xC0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 192)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113320) {
            ctx->pc = 0x113364u;
            goto label_113364;
        }
    }
    ctx->pc = 0x113328u;
label_113328:
    // 0x113328: 0x63043  sra         $a2, $a2, 1
    ctx->pc = 0x113328u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 1));
    // 0x11332c: 0xde440038  ld          $a0, 0x38($s2)
    ctx->pc = 0x11332cu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 18), 56)));
    // 0x113330: 0xde430060  ld          $v1, 0x60($s2)
    ctx->pc = 0x113330u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 18), 96)));
    // 0x113334: 0x61400  sll         $v0, $a2, 16
    ctx->pc = 0x113334u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 16));
    // 0x113338: 0x2405fe00  addiu       $a1, $zero, -0x200
    ctx->pc = 0x113338u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966784));
    // 0x11333c: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x11333cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x113340: 0x651824  and         $v1, $v1, $a1
    ctx->pc = 0x113340u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 5));
    // 0x113344: 0x304201ff  andi        $v0, $v0, 0x1FF
    ctx->pc = 0x113344u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)511);
    // 0x113348: 0x852024  and         $a0, $a0, $a1
    ctx->pc = 0x113348u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x11334c: 0x30c601ff  andi        $a2, $a2, 0x1FF
    ctx->pc = 0x11334cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)511);
    // 0x113350: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x113350u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x113354: 0x661825  or          $v1, $v1, $a2
    ctx->pc = 0x113354u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 6));
    // 0x113358: 0xfe430060  sd          $v1, 0x60($s2)
    ctx->pc = 0x113358u;
    WRITE64(ADD32(GPR_U32(ctx, 18), 96), GPR_U64(ctx, 3));
    // 0x11335c: 0xfe440038  sd          $a0, 0x38($s2)
    ctx->pc = 0x11335cu;
    WRITE64(ADD32(GPR_U32(ctx, 18), 56), GPR_U64(ctx, 4));
    // 0x113360: 0xdfbf00c0  ld          $ra, 0xC0($sp)
    ctx->pc = 0x113360u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 192)));
label_113364:
    // 0x113364: 0xdfbe00b0  ld          $fp, 0xB0($sp)
    ctx->pc = 0x113364u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x113368: 0xdfb700a0  ld          $s7, 0xA0($sp)
    ctx->pc = 0x113368u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x11336c: 0xdfb60090  ld          $s6, 0x90($sp)
    ctx->pc = 0x11336cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x113370: 0xdfb50080  ld          $s5, 0x80($sp)
    ctx->pc = 0x113370u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x113374: 0xdfb40070  ld          $s4, 0x70($sp)
    ctx->pc = 0x113374u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x113378: 0xdfb30060  ld          $s3, 0x60($sp)
    ctx->pc = 0x113378u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11337c: 0xdfb20050  ld          $s2, 0x50($sp)
    ctx->pc = 0x11337cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x113380: 0xdfb10040  ld          $s1, 0x40($sp)
    ctx->pc = 0x113380u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x113384: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x113384u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x113388: 0x3e00008  jr          $ra
    ctx->pc = 0x113388u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11338Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113388u;
            // 0x11338c: 0x27bd00d0  addiu       $sp, $sp, 0xD0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113154u: goto label_113154;
            case 0x11317Cu: goto label_11317c;
            case 0x113198u: goto label_113198;
            case 0x1131B4u: goto label_1131b4;
            case 0x1131D0u: goto label_1131d0;
            case 0x113218u: goto label_113218;
            case 0x113248u: goto label_113248;
            case 0x1132ECu: goto label_1132ec;
            case 0x113328u: goto label_113328;
            case 0x113364u: goto label_113364;
            default: break;
        }
        return;
    }
    ctx->pc = 0x113390u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
