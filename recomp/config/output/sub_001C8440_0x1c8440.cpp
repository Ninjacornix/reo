#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8440
// Address: 0x1c8440 - 0x1c85c0
void sub_001C8440_0x1c8440(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8440_0x1c8440");
#endif

    switch (ctx->pc) {
        case 0x1c8454u: goto label_1c8454;
        case 0x1c8470u: goto label_1c8470;
        case 0x1c84c8u: goto label_1c84c8;
        case 0x1c84f4u: goto label_1c84f4;
        case 0x1c852cu: goto label_1c852c;
        case 0x1c8550u: goto label_1c8550;
        case 0x1c8558u: goto label_1c8558;
        case 0x1c8580u: goto label_1c8580;
        case 0x1c85a8u: goto label_1c85a8;
        default: break;
    }

    ctx->pc = 0x1c8440u;

    // 0x1c8440: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c8440u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c8444: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c8444u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c8448: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c8448u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c844c: 0xc072214  jal         func_1C8850
    ctx->pc = 0x1C844Cu;
    SET_GPR_U32(ctx, 31, 0x1C8454u);
    ctx->pc = 0x1C8450u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C844Cu;
            // 0x1c8450: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8850u;
    if (runtime->hasFunction(0x1C8850u)) {
        auto targetFn = runtime->lookupFunction(0x1C8850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8454u; }
        if (ctx->pc != 0x1C8454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8850_0x1c8850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8454u; }
        if (ctx->pc != 0x1C8454u) { return; }
    }
    ctx->pc = 0x1C8454u;
label_1c8454:
    // 0x1c8454: 0xc602006c  lwc1        $f2, 0x6C($s0)
    ctx->pc = 0x1c8454u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 108)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1c8458: 0xc6010070  lwc1        $f1, 0x70($s0)
    ctx->pc = 0x1c8458u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 112)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1c845c: 0x46020001  sub.s       $f0, $f0, $f2
    ctx->pc = 0x1c845cu;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[2]);
    // 0x1c8460: 0x46010041  sub.s       $f1, $f0, $f1
    ctx->pc = 0x1c8460u;
    ctx->f[1] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x1c8464: 0xe6010074  swc1        $f1, 0x74($s0)
    ctx->pc = 0x1c8464u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 116), bits); }
    // 0x1c8468: 0xc0722f0  jal         func_1C8BC0
    ctx->pc = 0x1C8468u;
    SET_GPR_U32(ctx, 31, 0x1C8470u);
    ctx->pc = 0x1C846Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8468u;
            // 0x1c846c: 0xe6000070  swc1        $f0, 0x70($s0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 112), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8BC0u;
    if (runtime->hasFunction(0x1C8BC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C8BC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8470u; }
        if (ctx->pc != 0x1C8470u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8BC0_0x1c8bc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8470u; }
        if (ctx->pc != 0x1C8470u) { return; }
    }
    ctx->pc = 0x1C8470u;
label_1c8470:
    // 0x1c8470: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1c8470u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c8474: 0x14450046  bne         $v0, $a1, . + 4 + (0x46 << 2)
    ctx->pc = 0x1C8474u;
    {
        const bool branch_taken_0x1c8474 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        ctx->pc = 0x1C8478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8474u;
            // 0x1c8478: 0x24030004  addiu       $v1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8474) {
            ctx->pc = 0x1C8590u;
            goto label_1c8590;
        }
    }
    ctx->pc = 0x1C847Cu;
    // 0x1c847c: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1c847cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1c8480: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1c8480u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c8484: 0x10830048  beq         $a0, $v1, . + 4 + (0x48 << 2)
    ctx->pc = 0x1C8484u;
    {
        const bool branch_taken_0x1c8484 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C8488u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8484u;
            // 0x1c8488: 0x24030004  addiu       $v1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8484) {
            ctx->pc = 0x1C85A8u;
            goto label_1c85a8;
        }
    }
    ctx->pc = 0x1C848Cu;
    // 0x1c848c: 0x10830046  beq         $a0, $v1, . + 4 + (0x46 << 2)
    ctx->pc = 0x1C848Cu;
    {
        const bool branch_taken_0x1c848c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c848c) {
            ctx->pc = 0x1C85A8u;
            goto label_1c85a8;
        }
    }
    ctx->pc = 0x1C8494u;
    // 0x1c8494: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c8494u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c8498: 0x10830037  beq         $a0, $v1, . + 4 + (0x37 << 2)
    ctx->pc = 0x1C8498u;
    {
        const bool branch_taken_0x1c8498 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c8498) {
            ctx->pc = 0x1C8578u;
            goto label_1c8578;
        }
    }
    ctx->pc = 0x1C84A0u;
    // 0x1c84a0: 0x10850007  beq         $a0, $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C84A0u;
    {
        const bool branch_taken_0x1c84a0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 5));
        ctx->pc = 0x1C84A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C84A0u;
            // 0x1c84a4: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c84a0) {
            ctx->pc = 0x1C84C0u;
            goto label_1c84c0;
        }
    }
    ctx->pc = 0x1C84A8u;
    // 0x1c84a8: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C84A8u;
    {
        const bool branch_taken_0x1c84a8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c84a8) {
            ctx->pc = 0x1C84B8u;
            goto label_1c84b8;
        }
    }
    ctx->pc = 0x1C84B0u;
    // 0x1c84b0: 0x1000003e  b           . + 4 + (0x3E << 2)
    ctx->pc = 0x1C84B0u;
    {
        const bool branch_taken_0x1c84b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C84B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C84B0u;
            // 0x1c84b4: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c84b0) {
            ctx->pc = 0x1C85ACu;
            goto label_1c85ac;
        }
    }
    ctx->pc = 0x1C84B8u;
label_1c84b8:
    // 0x1c84b8: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1C84B8u;
    {
        const bool branch_taken_0x1c84b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C84BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C84B8u;
            // 0x1c84bc: 0xae050000  sw          $a1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c84b8) {
            ctx->pc = 0x1C85A8u;
            goto label_1c85a8;
        }
    }
    ctx->pc = 0x1C84C0u;
label_1c84c0:
    // 0x1c84c0: 0xc072410  jal         func_1C9040
    ctx->pc = 0x1C84C0u;
    SET_GPR_U32(ctx, 31, 0x1C84C8u);
    ctx->pc = 0x1C9040u;
    if (runtime->hasFunction(0x1C9040u)) {
        auto targetFn = runtime->lookupFunction(0x1C9040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C84C8u; }
        if (ctx->pc != 0x1C84C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C9040_0x1c9040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C84C8u; }
        if (ctx->pc != 0x1C84C8u) { return; }
    }
    ctx->pc = 0x1C84C8u;
label_1c84c8:
    // 0x1c84c8: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c84c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c84cc: 0x14430025  bne         $v0, $v1, . + 4 + (0x25 << 2)
    ctx->pc = 0x1C84CCu;
    {
        const bool branch_taken_0x1c84cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1C84D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C84CCu;
            // 0x1c84d0: 0x24030004  addiu       $v1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c84cc) {
            ctx->pc = 0x1C8564u;
            goto label_1c8564;
        }
    }
    ctx->pc = 0x1C84D4u;
    // 0x1c84d4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c84d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c84d8: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x1c84d8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c84dc: 0x8022c6c0  lb          $v0, -0x3940($at)
    ctx->pc = 0x1c84dcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952640)));
    // 0x1c84e0: 0xae020048  sw          $v0, 0x48($s0)
    ctx->pc = 0x1c84e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 72), GPR_U32(ctx, 2));
    // 0x1c84e4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c84e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c84e8: 0x8022c6c1  lb          $v0, -0x393F($at)
    ctx->pc = 0x1c84e8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952641)));
    // 0x1c84ec: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1C84ECu;
    {
        const bool branch_taken_0x1c84ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C84F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C84ECu;
            // 0x1c84f0: 0xae020040  sw          $v0, 0x40($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c84ec) {
            ctx->pc = 0x1C8500u;
            goto label_1c8500;
        }
    }
    ctx->pc = 0x1C84F4u;
label_1c84f4:
    // 0x1c84f4: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x1c84f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1c84f8: 0xac43004c  sw          $v1, 0x4C($v0)
    ctx->pc = 0x1c84f8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 76), GPR_U32(ctx, 3));
    // 0x1c84fc: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1c84fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
label_1c8500:
    // 0x1c8500: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8500u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8504: 0x8022c6c0  lb          $v0, -0x3940($at)
    ctx->pc = 0x1c8504u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952640)));
    // 0x1c8508: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1c8508u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1c850c: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1C850Cu;
    {
        const bool branch_taken_0x1c850c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C8510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C850Cu;
            // 0x1c8510: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c850c) {
            ctx->pc = 0x1C84F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c84f4;
        }
    }
    ctx->pc = 0x1C8514u;
    // 0x1c8514: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8514u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8518: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c8518u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c851c: 0x8023c6c1  lb          $v1, -0x393F($at)
    ctx->pc = 0x1c851cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952641)));
    // 0x1c8520: 0x3100b  movn        $v0, $zero, $v1
    ctx->pc = 0x1c8520u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
    // 0x1c8524: 0xc072214  jal         func_1C8850
    ctx->pc = 0x1C8524u;
    SET_GPR_U32(ctx, 31, 0x1C852Cu);
    ctx->pc = 0x1C8528u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8524u;
            // 0x1c8528: 0xa2020044  sb          $v0, 0x44($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 68), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8850u;
    if (runtime->hasFunction(0x1C8850u)) {
        auto targetFn = runtime->lookupFunction(0x1C8850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C852Cu; }
        if (ctx->pc != 0x1C852Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8850_0x1c8850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C852Cu; }
        if (ctx->pc != 0x1C852Cu) { return; }
    }
    ctx->pc = 0x1C852Cu;
label_1c852c:
    // 0x1c852c: 0xe600006c  swc1        $f0, 0x6C($s0)
    ctx->pc = 0x1c852cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 108), bits); }
    // 0x1c8530: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8530u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8534: 0xae000070  sw          $zero, 0x70($s0)
    ctx->pc = 0x1c8534u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 112), GPR_U32(ctx, 0));
    // 0x1c8538: 0x8025c6c1  lb          $a1, -0x393F($at)
    ctx->pc = 0x1c8538u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952641)));
    // 0x1c853c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c853cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8540: 0x8026c6c0  lb          $a2, -0x3940($at)
    ctx->pc = 0x1c8540u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952640)));
    // 0x1c8544: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8544u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8548: 0xc0719f8  jal         func_1C67E0
    ctx->pc = 0x1C8548u;
    SET_GPR_U32(ctx, 31, 0x1C8550u);
    ctx->pc = 0x1C854Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8548u;
            // 0x1c854c: 0x8c24b694  lw          $a0, -0x496C($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294948500)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C67E0u;
    if (runtime->hasFunction(0x1C67E0u)) {
        auto targetFn = runtime->lookupFunction(0x1C67E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8550u; }
        if (ctx->pc != 0x1C8550u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C67E0_0x1c67e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8550u; }
        if (ctx->pc != 0x1C8550u) { return; }
    }
    ctx->pc = 0x1C8550u;
label_1c8550:
    // 0x1c8550: 0xc0719f0  jal         func_1C67C0
    ctx->pc = 0x1C8550u;
    SET_GPR_U32(ctx, 31, 0x1C8558u);
    ctx->pc = 0x1C67C0u;
    if (runtime->hasFunction(0x1C67C0u)) {
        auto targetFn = runtime->lookupFunction(0x1C67C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8558u; }
        if (ctx->pc != 0x1C8558u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C67C0_0x1c67c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8558u; }
        if (ctx->pc != 0x1C8558u) { return; }
    }
    ctx->pc = 0x1C8558u;
label_1c8558:
    // 0x1c8558: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c8558u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c855c: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1C855Cu;
    {
        const bool branch_taken_0x1c855c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8560u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C855Cu;
            // 0x1c8560: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c855c) {
            ctx->pc = 0x1C85A8u;
            goto label_1c85a8;
        }
    }
    ctx->pc = 0x1C8564u;
label_1c8564:
    // 0x1c8564: 0x14430010  bne         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1C8564u;
    {
        const bool branch_taken_0x1c8564 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1c8564) {
            ctx->pc = 0x1C85A8u;
            goto label_1c85a8;
        }
    }
    ctx->pc = 0x1C856Cu;
    // 0x1c856c: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1c856cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c8570: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1C8570u;
    {
        const bool branch_taken_0x1c8570 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8574u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8570u;
            // 0x1c8574: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8570) {
            ctx->pc = 0x1C85A8u;
            goto label_1c85a8;
        }
    }
    ctx->pc = 0x1C8578u;
label_1c8578:
    // 0x1c8578: 0xc071a90  jal         func_1C6A40
    ctx->pc = 0x1C8578u;
    SET_GPR_U32(ctx, 31, 0x1C8580u);
    ctx->pc = 0x1C6A40u;
    if (runtime->hasFunction(0x1C6A40u)) {
        auto targetFn = runtime->lookupFunction(0x1C6A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8580u; }
        if (ctx->pc != 0x1C8580u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C6A40_0x1c6a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8580u; }
        if (ctx->pc != 0x1C8580u) { return; }
    }
    ctx->pc = 0x1C8580u;
label_1c8580:
    // 0x1c8580: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1C8580u;
    {
        const bool branch_taken_0x1c8580 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8584u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8580u;
            // 0x1c8584: 0x24030005  addiu       $v1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8580) {
            ctx->pc = 0x1C85A8u;
            goto label_1c85a8;
        }
    }
    ctx->pc = 0x1C8588u;
    // 0x1c8588: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C8588u;
    {
        const bool branch_taken_0x1c8588 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C858Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8588u;
            // 0x1c858c: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8588) {
            ctx->pc = 0x1C85A8u;
            goto label_1c85a8;
        }
    }
    ctx->pc = 0x1C8590u;
label_1c8590:
    // 0x1c8590: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C8590u;
    {
        const bool branch_taken_0x1c8590 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C8594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8590u;
            // 0x1c8594: 0x24040005  addiu       $a0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8590) {
            ctx->pc = 0x1C85A0u;
            goto label_1c85a0;
        }
    }
    ctx->pc = 0x1C8598u;
    // 0x1c8598: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C8598u;
    {
        const bool branch_taken_0x1c8598 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c8598) {
            ctx->pc = 0x1C85A8u;
            goto label_1c85a8;
        }
    }
    ctx->pc = 0x1C85A0u;
label_1c85a0:
    // 0x1c85a0: 0xc071ef0  jal         func_1C7BC0
    ctx->pc = 0x1C85A0u;
    SET_GPR_U32(ctx, 31, 0x1C85A8u);
    ctx->pc = 0x1C85A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C85A0u;
            // 0x1c85a4: 0xae040000  sw          $a0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7BC0u;
    if (runtime->hasFunction(0x1C7BC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7BC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C85A8u; }
        if (ctx->pc != 0x1C85A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7BC0_0x1c7bc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C85A8u; }
        if (ctx->pc != 0x1C85A8u) { return; }
    }
    ctx->pc = 0x1C85A8u;
label_1c85a8:
    // 0x1c85a8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c85a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1c85ac:
    // 0x1c85ac: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c85acu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c85b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C85B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C85B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C85B0u;
            // 0x1c85b4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8454u: goto label_1c8454;
            case 0x1C8470u: goto label_1c8470;
            case 0x1C84B8u: goto label_1c84b8;
            case 0x1C84C0u: goto label_1c84c0;
            case 0x1C84C8u: goto label_1c84c8;
            case 0x1C84F4u: goto label_1c84f4;
            case 0x1C8500u: goto label_1c8500;
            case 0x1C852Cu: goto label_1c852c;
            case 0x1C8550u: goto label_1c8550;
            case 0x1C8558u: goto label_1c8558;
            case 0x1C8564u: goto label_1c8564;
            case 0x1C8578u: goto label_1c8578;
            case 0x1C8580u: goto label_1c8580;
            case 0x1C8590u: goto label_1c8590;
            case 0x1C85A0u: goto label_1c85a0;
            case 0x1C85A8u: goto label_1c85a8;
            case 0x1C85ACu: goto label_1c85ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C85B8u;
    // 0x1c85b8: 0x0  nop
    ctx->pc = 0x1c85b8u;
    // NOP
    // 0x1c85bc: 0x0  nop
    ctx->pc = 0x1c85bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
