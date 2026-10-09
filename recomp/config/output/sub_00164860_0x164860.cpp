#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164860
// Address: 0x164860 - 0x164900
void sub_00164860_0x164860(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164860_0x164860");
#endif

    switch (ctx->pc) {
        case 0x164878u: goto label_164878;
        case 0x164884u: goto label_164884;
        case 0x16488cu: goto label_16488c;
        default: break;
    }

    ctx->pc = 0x164860u;

    // 0x164860: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164860u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x164864: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x164864u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x164868: 0x24901b6c  addiu       $s0, $a0, 0x1B6C
    ctx->pc = 0x164868u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 7020));
    // 0x16486c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x16486cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x164870: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x164870u;
    SET_GPR_U32(ctx, 31, 0x164878u);
    ctx->pc = 0x164874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164870u;
            // 0x164874: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164878u; }
        if (ctx->pc != 0x164878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164878u; }
        if (ctx->pc != 0x164878u) { return; }
    }
    ctx->pc = 0x164878u;
label_164878:
    // 0x164878: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x164878u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16487c: 0xc0489aa  jal         func_1226A8
    ctx->pc = 0x16487Cu;
    SET_GPR_U32(ctx, 31, 0x164884u);
    ctx->pc = 0x1226A8u;
    if (runtime->hasFunction(0x1226A8u)) {
        auto targetFn = runtime->lookupFunction(0x1226A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164884u; }
        if (ctx->pc != 0x164884u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001226A8_0x1226a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164884u; }
        if (ctx->pc != 0x164884u) { return; }
    }
    ctx->pc = 0x164884u;
label_164884:
    // 0x164884: 0xc04491c  jal         func_112470
    ctx->pc = 0x164884u;
    SET_GPR_U32(ctx, 31, 0x16488Cu);
    ctx->pc = 0x164888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164884u;
            // 0x164888: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112470u;
    if (runtime->hasFunction(0x112470u)) {
        auto targetFn = runtime->lookupFunction(0x112470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16488Cu; }
        if (ctx->pc != 0x16488Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112470_0x112470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16488Cu; }
        if (ctx->pc != 0x16488Cu) { return; }
    }
    ctx->pc = 0x16488Cu;
label_16488c:
    // 0x16488c: 0x3c0140dd  lui         $at, 0x40DD
    ctx->pc = 0x16488cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16605 << 16));
    // 0x164890: 0x34210c54  ori         $at, $at, 0xC54
    ctx->pc = 0x164890u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)3156);
    // 0x164894: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x164894u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x164898: 0x3c0144d8  lui         $at, 0x44D8
    ctx->pc = 0x164898u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)17624 << 16));
    // 0x16489c: 0x3421677d  ori         $at, $at, 0x677D
    ctx->pc = 0x16489cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)26493);
    // 0x1648a0: 0x44811800  mtc1        $at, $f3
    ctx->pc = 0x1648a0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x1648a4: 0x46020001  sub.s       $f0, $f0, $f2
    ctx->pc = 0x1648a4u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[2]);
    // 0x1648a8: 0x3c013c23  lui         $at, 0x3C23
    ctx->pc = 0x1648a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15395 << 16));
    // 0x1648ac: 0x3421d70a  ori         $at, $at, 0xD70A
    ctx->pc = 0x1648acu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)55050);
    // 0x1648b0: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x1648b0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1648b4: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x1648b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1648b8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1648b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1648bc: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1648bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1648c0: 0x46030002  mul.s       $f0, $f0, $f3
    ctx->pc = 0x1648c0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[3]);
    // 0x1648c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1648c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1648c8: 0x46010042  mul.s       $f1, $f0, $f1
    ctx->pc = 0x1648c8u;
    ctx->f[1] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x1648cc: 0x460000a4  .word       0x460000A4                   # cvt.w.s     $f2, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1648ccu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x1648d0: 0x44031000  mfc1        $v1, $f2
    ctx->pc = 0x1648d0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1648d4: 0x46000824  .word       0x46000824                   # cvt.w.s     $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1648d4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1648d8: 0x44020000  mfc1        $v0, $f0
    ctx->pc = 0x1648d8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x1648dc: 0x23040  sll         $a2, $v0, 1
    ctx->pc = 0x1648dcu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1648e0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1648e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1648e4: 0xc23021  addu        $a2, $a2, $v0
    ctx->pc = 0x1648e4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1648e8: 0x630c0  sll         $a2, $a2, 3
    ctx->pc = 0x1648e8u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
    // 0x1648ec: 0xc23021  addu        $a2, $a2, $v0
    ctx->pc = 0x1648ecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1648f0: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x1648f0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1648f4: 0x663023  subu        $a2, $v1, $a2
    ctx->pc = 0x1648f4u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1648f8: 0x804cbf8  j           func_132FE0
    ctx->pc = 0x1648F8u;
    ctx->pc = 0x1648FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1648F8u;
            // 0x1648fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132FE0u;
    if (runtime->hasFunction(0x132FE0u)) {
        auto targetFn = runtime->lookupFunction(0x132FE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00132FE0_0x132fe0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x164900u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
