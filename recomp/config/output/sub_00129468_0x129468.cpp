#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129468
// Address: 0x129468 - 0x1297a0
void sub_00129468_0x129468(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129468_0x129468");
#endif

    switch (ctx->pc) {
        case 0x129490u: goto label_129490;
        case 0x1294a4u: goto label_1294a4;
        case 0x1294acu: goto label_1294ac;
        case 0x1294f8u: goto label_1294f8;
        case 0x129504u: goto label_129504;
        case 0x129510u: goto label_129510;
        case 0x129528u: goto label_129528;
        case 0x129534u: goto label_129534;
        case 0x129540u: goto label_129540;
        case 0x12954cu: goto label_12954c;
        case 0x129568u: goto label_129568;
        case 0x1295c0u: goto label_1295c0;
        case 0x1295dcu: goto label_1295dc;
        case 0x129650u: goto label_129650;
        case 0x129688u: goto label_129688;
        case 0x1296b0u: goto label_1296b0;
        case 0x1296ccu: goto label_1296cc;
        case 0x1296e0u: goto label_1296e0;
        case 0x129708u: goto label_129708;
        case 0x129710u: goto label_129710;
        case 0x129720u: goto label_129720;
        case 0x129734u: goto label_129734;
        case 0x129750u: goto label_129750;
        case 0x12975cu: goto label_12975c;
        case 0x129778u: goto label_129778;
        default: break;
    }

    ctx->pc = 0x129468u;

label_129468:
    // 0x129468: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x129468u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12946c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12946cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x129470: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x129470u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129474: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x129474u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x129478: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x129478u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12947c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12947cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x129480: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x129480u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129484: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x129484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x129488: 0xc04c16e  jal         func_1305B8
    ctx->pc = 0x129488u;
    SET_GPR_U32(ctx, 31, 0x129490u);
    ctx->pc = 0x12948Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129488u;
            // 0x12948c: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305B8u;
    if (runtime->hasFunction(0x1305B8u)) {
        auto targetFn = runtime->lookupFunction(0x1305B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129490u; }
        if (ctx->pc != 0x129490u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305B8_0x1305b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129490u; }
        if (ctx->pc != 0x129490u) { return; }
    }
    ctx->pc = 0x129490u;
label_129490:
    // 0x129490: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x129490u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x129494: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x129494u;
    {
        const bool branch_taken_0x129494 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x129494) {
            ctx->pc = 0x1294A4u;
            goto label_1294a4;
        }
    }
    ctx->pc = 0x12949Cu;
    // 0x12949c: 0xc04c1d2  jal         func_130748
    ctx->pc = 0x12949Cu;
    SET_GPR_U32(ctx, 31, 0x1294A4u);
    ctx->pc = 0x1294A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12949Cu;
            // 0x1294a0: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130748u;
    if (runtime->hasFunction(0x130748u)) {
        auto targetFn = runtime->lookupFunction(0x130748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1294A4u; }
        if (ctx->pc != 0x1294A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130748_0x130748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1294A4u; }
        if (ctx->pc != 0x1294A4u) { return; }
    }
    ctx->pc = 0x1294A4u;
label_1294a4:
    // 0x1294a4: 0xc049938  jal         func_1264E0
    ctx->pc = 0x1294A4u;
    SET_GPR_U32(ctx, 31, 0x1294ACu);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1294ACu; }
        if (ctx->pc != 0x1294ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1294ACu; }
        if (ctx->pc != 0x1294ACu) { return; }
    }
    ctx->pc = 0x1294ACu;
label_1294ac:
    // 0x1294ac: 0x8e060014  lw          $a2, 0x14($s0)
    ctx->pc = 0x1294acu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1294b0: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x1294b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1294b4: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1294b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1294b8: 0x8e030030  lw          $v1, 0x30($s0)
    ctx->pc = 0x1294b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x1294bc: 0x461023  subu        $v0, $v0, $a2
    ctx->pc = 0x1294bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1294c0: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x1294c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x1294c4: 0x222202a  slt         $a0, $s1, $v0
    ctx->pc = 0x1294c4u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1294c8: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x1294c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1294cc: 0x224100b  movn        $v0, $s1, $a0
    ctx->pc = 0x1294ccu;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 17));
    // 0x1294d0: 0xae030018  sw          $v1, 0x18($s0)
    ctx->pc = 0x1294d0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 3));
    // 0x1294d4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1294D4u;
    {
        const bool branch_taken_0x1294d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1294D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1294D4u;
            // 0x1294d8: 0xae02001c  sw          $v0, 0x1C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1294d4) {
            ctx->pc = 0x1294F0u;
            goto label_1294f0;
        }
    }
    ctx->pc = 0x1294DCu;
    // 0x1294dc: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1294dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1294e0: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1294e0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x1294e4: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1294E4u;
    {
        const bool branch_taken_0x1294e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1294E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1294E4u;
            // 0x1294e8: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1294e4) {
            ctx->pc = 0x129544u;
            goto label_129544;
        }
    }
    ctx->pc = 0x1294ECu;
    // 0x1294ec: 0x0  nop
    ctx->pc = 0x1294ecu;
    // NOP
label_1294f0:
    // 0x1294f0: 0xc04c1ea  jal         func_1307A8
    ctx->pc = 0x1294F0u;
    SET_GPR_U32(ctx, 31, 0x1294F8u);
    ctx->pc = 0x1294F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1294F0u;
            // 0x1294f4: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1307A8u;
    if (runtime->hasFunction(0x1307A8u)) {
        auto targetFn = runtime->lookupFunction(0x1307A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1294F8u; }
        if (ctx->pc != 0x1294F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001307A8_0x1307a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1294F8u; }
        if (ctx->pc != 0x1294F8u) { return; }
    }
    ctx->pc = 0x1294F8u;
label_1294f8:
    // 0x1294f8: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x1294f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1294fc: 0xc04c3c8  jal         func_130F20
    ctx->pc = 0x1294FCu;
    SET_GPR_U32(ctx, 31, 0x129504u);
    ctx->pc = 0x129500u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1294FCu;
            // 0x129500: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130F20u;
    if (runtime->hasFunction(0x130F20u)) {
        auto targetFn = runtime->lookupFunction(0x130F20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129504u; }
        if (ctx->pc != 0x129504u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130F20_0x130f20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129504u; }
        if (ctx->pc != 0x129504u) { return; }
    }
    ctx->pc = 0x129504u;
label_129504:
    // 0x129504: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x129504u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x129508: 0xc04c38a  jal         func_130E28
    ctx->pc = 0x129508u;
    SET_GPR_U32(ctx, 31, 0x129510u);
    ctx->pc = 0x12950Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129508u;
            // 0x12950c: 0x8e05002c  lw          $a1, 0x2C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130E28u;
    if (runtime->hasFunction(0x130E28u)) {
        auto targetFn = runtime->lookupFunction(0x130E28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129510u; }
        if (ctx->pc != 0x129510u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130E28_0x130e28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129510u; }
        if (ctx->pc != 0x129510u) { return; }
    }
    ctx->pc = 0x129510u;
label_129510:
    // 0x129510: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x129510u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x129514: 0xa2030001  sb          $v1, 0x1($s0)
    ctx->pc = 0x129514u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x129518: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x129518u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12951c: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x12951cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x129520: 0xc04c392  jal         func_130E48
    ctx->pc = 0x129520u;
    SET_GPR_U32(ctx, 31, 0x129528u);
    ctx->pc = 0x129524u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129520u;
            // 0x129524: 0xa2000003  sb          $zero, 0x3($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130E48u;
    if (runtime->hasFunction(0x130E48u)) {
        auto targetFn = runtime->lookupFunction(0x130E48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129528u; }
        if (ctx->pc != 0x129528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130E48_0x130e48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129528u; }
        if (ctx->pc != 0x129528u) { return; }
    }
    ctx->pc = 0x129528u;
label_129528:
    // 0x129528: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x129528u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x12952c: 0xc04c170  jal         func_1305C0
    ctx->pc = 0x12952Cu;
    SET_GPR_U32(ctx, 31, 0x129534u);
    ctx->pc = 0x129530u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12952Cu;
            // 0x129530: 0x8e050014  lw          $a1, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305C0u;
    if (runtime->hasFunction(0x1305C0u)) {
        auto targetFn = runtime->lookupFunction(0x1305C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129534u; }
        if (ctx->pc != 0x129534u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305C0_0x1305c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129534u; }
        if (ctx->pc != 0x129534u) { return; }
    }
    ctx->pc = 0x129534u;
label_129534:
    // 0x129534: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x129534u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x129538: 0xc04c1a6  jal         func_130698
    ctx->pc = 0x129538u;
    SET_GPR_U32(ctx, 31, 0x129540u);
    ctx->pc = 0x12953Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129538u;
            // 0x12953c: 0x8e05001c  lw          $a1, 0x1C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130698u;
    if (runtime->hasFunction(0x130698u)) {
        auto targetFn = runtime->lookupFunction(0x130698u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129540u; }
        if (ctx->pc != 0x129540u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130698_0x130698(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129540u; }
        if (ctx->pc != 0x129540u) { return; }
    }
    ctx->pc = 0x129540u;
label_129540:
    // 0x129540: 0x8e10001c  lw          $s0, 0x1C($s0)
    ctx->pc = 0x129540u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
label_129544:
    // 0x129544: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x129544u;
    SET_GPR_U32(ctx, 31, 0x12954Cu);
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12954Cu; }
        if (ctx->pc != 0x12954Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12954Cu; }
        if (ctx->pc != 0x12954Cu) { return; }
    }
    ctx->pc = 0x12954Cu;
label_12954c:
    // 0x12954c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x12954cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129550: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x129550u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x129554: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x129554u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129558: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x129558u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12955c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12955cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x129560: 0x3e00008  jr          $ra
    ctx->pc = 0x129560u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129560u;
            // 0x129564: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129468u: goto label_129468;
            case 0x129490u: goto label_129490;
            case 0x1294A4u: goto label_1294a4;
            case 0x1294ACu: goto label_1294ac;
            case 0x1294F0u: goto label_1294f0;
            case 0x1294F8u: goto label_1294f8;
            case 0x129504u: goto label_129504;
            case 0x129510u: goto label_129510;
            case 0x129528u: goto label_129528;
            case 0x129534u: goto label_129534;
            case 0x129540u: goto label_129540;
            case 0x129544u: goto label_129544;
            case 0x12954Cu: goto label_12954c;
            case 0x129568u: goto label_129568;
            case 0x129590u: goto label_129590;
            case 0x1295A8u: goto label_1295a8;
            case 0x1295B8u: goto label_1295b8;
            case 0x1295C0u: goto label_1295c0;
            case 0x1295C8u: goto label_1295c8;
            case 0x1295DCu: goto label_1295dc;
            case 0x1295E4u: goto label_1295e4;
            case 0x129650u: goto label_129650;
            case 0x129660u: goto label_129660;
            case 0x129670u: goto label_129670;
            case 0x129680u: goto label_129680;
            case 0x129688u: goto label_129688;
            case 0x129690u: goto label_129690;
            case 0x1296B0u: goto label_1296b0;
            case 0x1296B8u: goto label_1296b8;
            case 0x1296CCu: goto label_1296cc;
            case 0x1296E0u: goto label_1296e0;
            case 0x129708u: goto label_129708;
            case 0x129710u: goto label_129710;
            case 0x129720u: goto label_129720;
            case 0x129734u: goto label_129734;
            case 0x129750u: goto label_129750;
            case 0x129754u: goto label_129754;
            case 0x12975Cu: goto label_12975c;
            case 0x129760u: goto label_129760;
            case 0x129778u: goto label_129778;
            case 0x12977Cu: goto label_12977c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129568u;
label_129568:
    // 0x129568: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x129568u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12956c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x12956cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129570: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x129570u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x129574: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x129574u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129578: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x129578u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12957c: 0x16000004  bnez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x12957Cu;
    {
        const bool branch_taken_0x12957c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x129580u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12957Cu;
            // 0x129580: 0xc0182d  daddu       $v1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12957c) {
            ctx->pc = 0x129590u;
            goto label_129590;
        }
    }
    ctx->pc = 0x129584u;
    // 0x129584: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129584u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x129588: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x129588u;
    {
        const bool branch_taken_0x129588 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12958Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129588u;
            // 0x12958c: 0x24849ef0  addiu       $a0, $a0, -0x6110 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942448));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129588) {
            ctx->pc = 0x1295B8u;
            goto label_1295b8;
        }
    }
    ctx->pc = 0x129590u;
label_129590:
    // 0x129590: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x129590u;
    {
        const bool branch_taken_0x129590 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x129590) {
            ctx->pc = 0x1295A8u;
            goto label_1295a8;
        }
    }
    ctx->pc = 0x129598u;
    // 0x129598: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129598u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x12959c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x12959Cu;
    {
        const bool branch_taken_0x12959c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1295A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12959Cu;
            // 0x1295a0: 0x24849f18  addiu       $a0, $a0, -0x60E8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942488));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12959c) {
            ctx->pc = 0x1295B8u;
            goto label_1295b8;
        }
    }
    ctx->pc = 0x1295A4u;
    // 0x1295a4: 0x0  nop
    ctx->pc = 0x1295a4u;
    // NOP
label_1295a8:
    // 0x1295a8: 0x54600007  bnel        $v1, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x1295A8u;
    {
        const bool branch_taken_0x1295a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1295a8) {
            ctx->pc = 0x1295ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1295A8u;
            // 0x1295ac: 0x82070001  lb          $a3, 0x1($s0) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1295C8u;
            goto label_1295c8;
        }
    }
    ctx->pc = 0x1295B0u;
    // 0x1295b0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1295b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1295b4: 0x24849f48  addiu       $a0, $a0, -0x60B8
    ctx->pc = 0x1295b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942536));
label_1295b8:
    // 0x1295b8: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x1295B8u;
    SET_GPR_U32(ctx, 31, 0x1295C0u);
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1295C0u; }
        if (ctx->pc != 0x1295C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1295C0u; }
        if (ctx->pc != 0x1295C0u) { return; }
    }
    ctx->pc = 0x1295C0u;
label_1295c0:
    // 0x1295c0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1295C0u;
    {
        const bool branch_taken_0x1295c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1295C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1295C0u;
            // 0x1295c4: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1295c0) {
            ctx->pc = 0x1295E4u;
            goto label_1295e4;
        }
    }
    ctx->pc = 0x1295C8u;
label_1295c8:
    // 0x1295c8: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1295c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1295cc: 0x10e30005  beq         $a3, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1295CCu;
    {
        const bool branch_taken_0x1295cc = (GPR_U64(ctx, 7) == GPR_U64(ctx, 3));
        ctx->pc = 0x1295D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1295CCu;
            // 0x1295d0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1295cc) {
            ctx->pc = 0x1295E4u;
            goto label_1295e4;
        }
    }
    ctx->pc = 0x1295D4u;
    // 0x1295d4: 0xc04a51a  jal         func_129468
    ctx->pc = 0x1295D4u;
    SET_GPR_U32(ctx, 31, 0x1295DCu);
    ctx->pc = 0x129468u;
    goto label_129468;
    ctx->pc = 0x1295DCu;
label_1295dc:
    // 0x1295dc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1295dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1295e0: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1295e0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
label_1295e4:
    // 0x1295e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1295e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1295e8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1295e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1295ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1295ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1295F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1295ECu;
            // 0x1295f0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129468u: goto label_129468;
            case 0x129490u: goto label_129490;
            case 0x1294A4u: goto label_1294a4;
            case 0x1294ACu: goto label_1294ac;
            case 0x1294F0u: goto label_1294f0;
            case 0x1294F8u: goto label_1294f8;
            case 0x129504u: goto label_129504;
            case 0x129510u: goto label_129510;
            case 0x129528u: goto label_129528;
            case 0x129534u: goto label_129534;
            case 0x129540u: goto label_129540;
            case 0x129544u: goto label_129544;
            case 0x12954Cu: goto label_12954c;
            case 0x129568u: goto label_129568;
            case 0x129590u: goto label_129590;
            case 0x1295A8u: goto label_1295a8;
            case 0x1295B8u: goto label_1295b8;
            case 0x1295C0u: goto label_1295c0;
            case 0x1295C8u: goto label_1295c8;
            case 0x1295DCu: goto label_1295dc;
            case 0x1295E4u: goto label_1295e4;
            case 0x129650u: goto label_129650;
            case 0x129660u: goto label_129660;
            case 0x129670u: goto label_129670;
            case 0x129680u: goto label_129680;
            case 0x129688u: goto label_129688;
            case 0x129690u: goto label_129690;
            case 0x1296B0u: goto label_1296b0;
            case 0x1296B8u: goto label_1296b8;
            case 0x1296CCu: goto label_1296cc;
            case 0x1296E0u: goto label_1296e0;
            case 0x129708u: goto label_129708;
            case 0x129710u: goto label_129710;
            case 0x129720u: goto label_129720;
            case 0x129734u: goto label_129734;
            case 0x129750u: goto label_129750;
            case 0x129754u: goto label_129754;
            case 0x12975Cu: goto label_12975c;
            case 0x129760u: goto label_129760;
            case 0x129778u: goto label_129778;
            case 0x12977Cu: goto label_12977c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1295F4u;
    // 0x1295f4: 0x0  nop
    ctx->pc = 0x1295f4u;
    // NOP
    // 0x1295f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1295f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1295fc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1295fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x129600: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x129600u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129604: 0x804a55a  j           func_129568
    ctx->pc = 0x129604u;
    ctx->pc = 0x129608u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129604u;
            // 0x129608: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129568u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_129568;
    ctx->pc = 0x12960Cu;
    // 0x12960c: 0x0  nop
    ctx->pc = 0x12960cu;
    // NOP
    // 0x129610: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x129610u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x129614: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x129614u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x129618: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x129618u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12961c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12961cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x129620: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x129620u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129624: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x129624u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x129628: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x129628u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12962c: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x12962cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x129630: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x129630u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129634: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x129634u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129638: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x129638u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12963c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12963cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x129640: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x129640u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x129644: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x129644u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x129648: 0xc04a13e  jal         func_1284F8
    ctx->pc = 0x129648u;
    SET_GPR_U32(ctx, 31, 0x129650u);
    ctx->pc = 0x12964Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129648u;
            // 0x12964c: 0x260402d  daddu       $t0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284F8u;
    if (runtime->hasFunction(0x1284F8u)) {
        auto targetFn = runtime->lookupFunction(0x1284F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129650u; }
        if (ctx->pc != 0x129650u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001284F8_0x1284f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129650u; }
        if (ctx->pc != 0x129650u) { return; }
    }
    ctx->pc = 0x129650u;
label_129650:
    // 0x129650: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x129650u;
    {
        const bool branch_taken_0x129650 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x129654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129650u;
            // 0x129654: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129650) {
            ctx->pc = 0x129660u;
            goto label_129660;
        }
    }
    ctx->pc = 0x129658u;
    // 0x129658: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x129658u;
    {
        const bool branch_taken_0x129658 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12965Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129658u;
            // 0x12965c: 0x24849f70  addiu       $a0, $a0, -0x6090 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942576));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129658) {
            ctx->pc = 0x129680u;
            goto label_129680;
        }
    }
    ctx->pc = 0x129660u;
label_129660:
    // 0x129660: 0x6810003  bgez        $s4, . + 4 + (0x3 << 2)
    ctx->pc = 0x129660u;
    {
        const bool branch_taken_0x129660 = (GPR_S64(ctx, 20) >= 0);
        ctx->pc = 0x129664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129660u;
            // 0x129664: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129660) {
            ctx->pc = 0x129670u;
            goto label_129670;
        }
    }
    ctx->pc = 0x129668u;
    // 0x129668: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x129668u;
    {
        const bool branch_taken_0x129668 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12966Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129668u;
            // 0x12966c: 0x24849f98  addiu       $a0, $a0, -0x6068 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942616));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129668) {
            ctx->pc = 0x129680u;
            goto label_129680;
        }
    }
    ctx->pc = 0x129670u;
label_129670:
    // 0x129670: 0x56600007  bnel        $s3, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x129670u;
    {
        const bool branch_taken_0x129670 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        if (branch_taken_0x129670) {
            ctx->pc = 0x129674u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129670u;
            // 0x129674: 0x82040001  lb          $a0, 0x1($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129690u;
            goto label_129690;
        }
    }
    ctx->pc = 0x129678u;
    // 0x129678: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129678u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x12967c: 0x24849fc8  addiu       $a0, $a0, -0x6038
    ctx->pc = 0x12967cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942664));
label_129680:
    // 0x129680: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x129680u;
    SET_GPR_U32(ctx, 31, 0x129688u);
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129688u; }
        if (ctx->pc != 0x129688u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129688u; }
        if (ctx->pc != 0x129688u) { return; }
    }
    ctx->pc = 0x129688u;
label_129688:
    // 0x129688: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x129688u;
    {
        const bool branch_taken_0x129688 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12968Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129688u;
            // 0x12968c: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129688) {
            ctx->pc = 0x12977Cu;
            goto label_12977c;
        }
    }
    ctx->pc = 0x129690u;
label_129690:
    // 0x129690: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x129690u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x129694: 0x10830039  beq         $a0, $v1, . + 4 + (0x39 << 2)
    ctx->pc = 0x129694u;
    {
        const bool branch_taken_0x129694 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x129698u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129694u;
            // 0x129698: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129694) {
            ctx->pc = 0x12977Cu;
            goto label_12977c;
        }
    }
    ctx->pc = 0x12969Cu;
    // 0x12969c: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x12969cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1296a0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1296A0u;
    {
        const bool branch_taken_0x1296a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1296A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1296A0u;
            // 0x1296a4: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1296a0) {
            ctx->pc = 0x1296B8u;
            goto label_1296b8;
        }
    }
    ctx->pc = 0x1296A8u;
    // 0x1296a8: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x1296A8u;
    SET_GPR_U32(ctx, 31, 0x1296B0u);
    ctx->pc = 0x1296ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1296A8u;
            // 0x1296ac: 0x24849ff0  addiu       $a0, $a0, -0x6010 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942704));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1296B0u; }
        if (ctx->pc != 0x1296B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1296B0u; }
        if (ctx->pc != 0x1296B0u) { return; }
    }
    ctx->pc = 0x1296B0u;
label_1296b0:
    // 0x1296b0: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x1296B0u;
    {
        const bool branch_taken_0x1296b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1296B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1296B0u;
            // 0x1296b4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1296b0) {
            ctx->pc = 0x12977Cu;
            goto label_12977c;
        }
    }
    ctx->pc = 0x1296B8u;
label_1296b8:
    // 0x1296b8: 0x1492c0  sll         $s2, $s4, 11
    ctx->pc = 0x1296b8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 20), 11));
    // 0x1296bc: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1296bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1296c0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1296c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1296c4: 0xc04fe2a  jal         func_13F8A8
    ctx->pc = 0x1296C4u;
    SET_GPR_U32(ctx, 31, 0x1296CCu);
    ctx->pc = 0x1296C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1296C4u;
            // 0x1296c8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F8A8u;
    if (runtime->hasFunction(0x13F8A8u)) {
        auto targetFn = runtime->lookupFunction(0x13F8A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1296CCu; }
        if (ctx->pc != 0x1296CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F8A8_0x13f8a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1296CCu; }
        if (ctx->pc != 0x1296CCu) { return; }
    }
    ctx->pc = 0x1296CCu;
label_1296cc:
    // 0x1296cc: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1296ccu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1296d0: 0x1220002a  beqz        $s1, . + 4 + (0x2A << 2)
    ctx->pc = 0x1296D0u;
    {
        const bool branch_taken_0x1296d0 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1296D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1296D0u;
            // 0x1296d4: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1296d0) {
            ctx->pc = 0x12977Cu;
            goto label_12977c;
        }
    }
    ctx->pc = 0x1296D8u;
    // 0x1296d8: 0xc049938  jal         func_1264E0
    ctx->pc = 0x1296D8u;
    SET_GPR_U32(ctx, 31, 0x1296E0u);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1296E0u; }
        if (ctx->pc != 0x1296E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1296E0u; }
        if (ctx->pc != 0x1296E0u) { return; }
    }
    ctx->pc = 0x1296E0u;
label_1296e0:
    // 0x1296e0: 0xae130024  sw          $s3, 0x24($s0)
    ctx->pc = 0x1296e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 19));
    // 0x1296e4: 0xae110008  sw          $s1, 0x8($s0)
    ctx->pc = 0x1296e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 17));
    // 0x1296e8: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x1296e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x1296ec: 0xae120028  sw          $s2, 0x28($s0)
    ctx->pc = 0x1296ecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 18));
    // 0x1296f0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1296f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1296f4: 0x8c82d100  lw          $v0, -0x2F00($a0)
    ctx->pc = 0x1296f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294955264)));
    // 0x1296f8: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1296F8u;
    {
        const bool branch_taken_0x1296f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1296FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1296F8u;
            // 0x1296fc: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1296f8) {
            ctx->pc = 0x129708u;
            goto label_129708;
        }
    }
    ctx->pc = 0x129700u;
    // 0x129700: 0xc04a0ca  jal         func_128328
    ctx->pc = 0x129700u;
    SET_GPR_U32(ctx, 31, 0x129708u);
    ctx->pc = 0x129704u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129700u;
            // 0x129704: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128328u;
    if (runtime->hasFunction(0x128328u)) {
        auto targetFn = runtime->lookupFunction(0x128328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129708u; }
        if (ctx->pc != 0x129708u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128328_0x128328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129708u; }
        if (ctx->pc != 0x129708u) { return; }
    }
    ctx->pc = 0x129708u;
label_129708:
    // 0x129708: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x129708u;
    SET_GPR_U32(ctx, 31, 0x129710u);
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129710u; }
        if (ctx->pc != 0x129710u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129710u; }
        if (ctx->pc != 0x129710u) { return; }
    }
    ctx->pc = 0x129710u;
label_129710:
    // 0x129710: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x129710u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129714: 0x8e060008  lw          $a2, 0x8($s0)
    ctx->pc = 0x129714u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x129718: 0xc04a51a  jal         func_129468
    ctx->pc = 0x129718u;
    SET_GPR_U32(ctx, 31, 0x129720u);
    ctx->pc = 0x12971Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129718u;
            // 0x12971c: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129468u;
    goto label_129468;
    ctx->pc = 0x129720u;
label_129720:
    // 0x129720: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x129720u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129724: 0x5e20000e  bgtzl       $s1, . + 4 + (0xE << 2)
    ctx->pc = 0x129724u;
    {
        const bool branch_taken_0x129724 = (GPR_S64(ctx, 17) > 0);
        if (branch_taken_0x129724) {
            ctx->pc = 0x129728u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129724u;
            // 0x129728: 0xa2000002  sb          $zero, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129760u;
            goto label_129760;
        }
    }
    ctx->pc = 0x12972Cu;
    // 0x12972c: 0xc049938  jal         func_1264E0
    ctx->pc = 0x12972Cu;
    SET_GPR_U32(ctx, 31, 0x129734u);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129734u; }
        if (ctx->pc != 0x129734u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129734u; }
        if (ctx->pc != 0x129734u) { return; }
    }
    ctx->pc = 0x129734u;
label_129734:
    // 0x129734: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x129734u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x129738: 0x10800006  beqz        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x129738u;
    {
        const bool branch_taken_0x129738 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x129738) {
            ctx->pc = 0x129754u;
            goto label_129754;
        }
    }
    ctx->pc = 0x129740u;
    // 0x129740: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x129740u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x129744: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x129744u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x129748: 0x40f809  jalr        $v0
    ctx->pc = 0x129748u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x129750u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x129750u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129468u: goto label_129468;
            case 0x129490u: goto label_129490;
            case 0x1294A4u: goto label_1294a4;
            case 0x1294ACu: goto label_1294ac;
            case 0x1294F0u: goto label_1294f0;
            case 0x1294F8u: goto label_1294f8;
            case 0x129504u: goto label_129504;
            case 0x129510u: goto label_129510;
            case 0x129528u: goto label_129528;
            case 0x129534u: goto label_129534;
            case 0x129540u: goto label_129540;
            case 0x129544u: goto label_129544;
            case 0x12954Cu: goto label_12954c;
            case 0x129568u: goto label_129568;
            case 0x129590u: goto label_129590;
            case 0x1295A8u: goto label_1295a8;
            case 0x1295B8u: goto label_1295b8;
            case 0x1295C0u: goto label_1295c0;
            case 0x1295C8u: goto label_1295c8;
            case 0x1295DCu: goto label_1295dc;
            case 0x1295E4u: goto label_1295e4;
            case 0x129650u: goto label_129650;
            case 0x129660u: goto label_129660;
            case 0x129670u: goto label_129670;
            case 0x129680u: goto label_129680;
            case 0x129688u: goto label_129688;
            case 0x129690u: goto label_129690;
            case 0x1296B0u: goto label_1296b0;
            case 0x1296B8u: goto label_1296b8;
            case 0x1296CCu: goto label_1296cc;
            case 0x1296E0u: goto label_1296e0;
            case 0x129708u: goto label_129708;
            case 0x129710u: goto label_129710;
            case 0x129720u: goto label_129720;
            case 0x129734u: goto label_129734;
            case 0x129750u: goto label_129750;
            case 0x129754u: goto label_129754;
            case 0x12975Cu: goto label_12975c;
            case 0x129760u: goto label_129760;
            case 0x129778u: goto label_129778;
            case 0x12977Cu: goto label_12977c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x129750u; }
            if (ctx->pc != 0x129750u) { return; }
        }
        }
    }
    ctx->pc = 0x129750u;
label_129750:
    // 0x129750: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x129750u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
label_129754:
    // 0x129754: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x129754u;
    SET_GPR_U32(ctx, 31, 0x12975Cu);
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12975Cu; }
        if (ctx->pc != 0x12975Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12975Cu; }
        if (ctx->pc != 0x12975Cu) { return; }
    }
    ctx->pc = 0x12975Cu;
label_12975c:
    // 0x12975c: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x12975cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
label_129760:
    // 0x129760: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x129760u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129764: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x129764u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129768: 0x260402d  daddu       $t0, $s3, $zero
    ctx->pc = 0x129768u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12976c: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x12976cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x129770: 0xc04a13e  jal         func_1284F8
    ctx->pc = 0x129770u;
    SET_GPR_U32(ctx, 31, 0x129778u);
    ctx->pc = 0x129774u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129770u;
            // 0x129774: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284F8u;
    if (runtime->hasFunction(0x1284F8u)) {
        auto targetFn = runtime->lookupFunction(0x1284F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129778u; }
        if (ctx->pc != 0x129778u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001284F8_0x1284f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129778u; }
        if (ctx->pc != 0x129778u) { return; }
    }
    ctx->pc = 0x129778u;
label_129778:
    // 0x129778: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x129778u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_12977c:
    // 0x12977c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12977cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129780: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x129780u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x129784: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x129784u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x129788: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x129788u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12978c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12978cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x129790: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x129790u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x129794: 0x3e00008  jr          $ra
    ctx->pc = 0x129794u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129794u;
            // 0x129798: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129468u: goto label_129468;
            case 0x129490u: goto label_129490;
            case 0x1294A4u: goto label_1294a4;
            case 0x1294ACu: goto label_1294ac;
            case 0x1294F0u: goto label_1294f0;
            case 0x1294F8u: goto label_1294f8;
            case 0x129504u: goto label_129504;
            case 0x129510u: goto label_129510;
            case 0x129528u: goto label_129528;
            case 0x129534u: goto label_129534;
            case 0x129540u: goto label_129540;
            case 0x129544u: goto label_129544;
            case 0x12954Cu: goto label_12954c;
            case 0x129568u: goto label_129568;
            case 0x129590u: goto label_129590;
            case 0x1295A8u: goto label_1295a8;
            case 0x1295B8u: goto label_1295b8;
            case 0x1295C0u: goto label_1295c0;
            case 0x1295C8u: goto label_1295c8;
            case 0x1295DCu: goto label_1295dc;
            case 0x1295E4u: goto label_1295e4;
            case 0x129650u: goto label_129650;
            case 0x129660u: goto label_129660;
            case 0x129670u: goto label_129670;
            case 0x129680u: goto label_129680;
            case 0x129688u: goto label_129688;
            case 0x129690u: goto label_129690;
            case 0x1296B0u: goto label_1296b0;
            case 0x1296B8u: goto label_1296b8;
            case 0x1296CCu: goto label_1296cc;
            case 0x1296E0u: goto label_1296e0;
            case 0x129708u: goto label_129708;
            case 0x129710u: goto label_129710;
            case 0x129720u: goto label_129720;
            case 0x129734u: goto label_129734;
            case 0x129750u: goto label_129750;
            case 0x129754u: goto label_129754;
            case 0x12975Cu: goto label_12975c;
            case 0x129760u: goto label_129760;
            case 0x129778u: goto label_129778;
            case 0x12977Cu: goto label_12977c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12979Cu;
    // 0x12979c: 0x0  nop
    ctx->pc = 0x12979cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
