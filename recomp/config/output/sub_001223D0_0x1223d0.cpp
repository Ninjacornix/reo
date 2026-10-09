#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001223D0
// Address: 0x1223d0 - 0x1224a8
void sub_001223D0_0x1223d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001223D0_0x1223d0");
#endif

    switch (ctx->pc) {
        case 0x122410u: goto label_122410;
        case 0x122420u: goto label_122420;
        case 0x122460u: goto label_122460;
        case 0x122478u: goto label_122478;
        case 0x122488u: goto label_122488;
        case 0x122498u: goto label_122498;
        default: break;
    }

    ctx->pc = 0x1223d0u;

    // 0x1223d0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1223d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1223d4: 0x46006006  mov.s       $f0, $f12
    ctx->pc = 0x1223d4u;
    ctx->f[0] = FPU_MOV_S(ctx->f[12]);
    // 0x1223d8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1223d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1223dc: 0xe7a00010  swc1        $f0, 0x10($sp)
    ctx->pc = 0x1223dcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 16), bits); }
    // 0x1223e0: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x1223e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x1223e4: 0x3c033f49  lui         $v1, 0x3F49
    ctx->pc = 0x1223e4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16201 << 16));
    // 0x1223e8: 0x8fa40010  lw          $a0, 0x10($sp)
    ctx->pc = 0x1223e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1223ec: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1223ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1223f0: 0x34630fd8  ori         $v1, $v1, 0xFD8
    ctx->pc = 0x1223f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4056);
    // 0x1223f4: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1223f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1223f8: 0x62182a  slt         $v1, $v1, $v0
    ctx->pc = 0x1223f8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1223fc: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1223FCu;
    {
        const bool branch_taken_0x1223fc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1223fc) {
            ctx->pc = 0x122418u;
            goto label_122418;
        }
    }
    ctx->pc = 0x122404u;
    // 0x122404: 0x44806800  mtc1        $zero, $f13
    ctx->pc = 0x122404u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[13], &bits, sizeof(bits)); }
    // 0x122408: 0xc0483da  jal         func_120F68
    ctx->pc = 0x122408u;
    SET_GPR_U32(ctx, 31, 0x122410u);
    ctx->pc = 0x120F68u;
    if (runtime->hasFunction(0x120F68u)) {
        auto targetFn = runtime->lookupFunction(0x120F68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122410u; }
        if (ctx->pc != 0x122410u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00120F68_0x120f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122410u; }
        if (ctx->pc != 0x122410u) { return; }
    }
    ctx->pc = 0x122410u;
label_122410:
    // 0x122410: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x122410u;
    {
        const bool branch_taken_0x122410 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x122414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122410u;
            // 0x122414: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122410) {
            ctx->pc = 0x12249Cu;
            goto label_12249c;
        }
    }
    ctx->pc = 0x122418u;
label_122418:
    // 0x122418: 0xc0482ba  jal         func_120AE8
    ctx->pc = 0x122418u;
    SET_GPR_U32(ctx, 31, 0x122420u);
    ctx->pc = 0x12241Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x122418u;
            // 0x12241c: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x120AE8u;
    if (runtime->hasFunction(0x120AE8u)) {
        auto targetFn = runtime->lookupFunction(0x120AE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122420u; }
        if (ctx->pc != 0x122420u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00120AE8_0x120ae8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122420u; }
        if (ctx->pc != 0x122420u) { return; }
    }
    ctx->pc = 0x122420u;
label_122420:
    // 0x122420: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x122420u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x122424: 0x30440003  andi        $a0, $v0, 0x3
    ctx->pc = 0x122424u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x122428: 0x1083000f  beq         $a0, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x122428u;
    {
        const bool branch_taken_0x122428 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x12242Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122428u;
            // 0x12242c: 0x28820002  slti        $v0, $a0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x122428) {
            ctx->pc = 0x122468u;
            goto label_122468;
        }
    }
    ctx->pc = 0x122430u;
    // 0x122430: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x122430u;
    {
        const bool branch_taken_0x122430 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x122430) {
            ctx->pc = 0x122434u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x122430u;
            // 0x122434: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x122448u;
            goto label_122448;
        }
    }
    ctx->pc = 0x122438u;
    // 0x122438: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x122438u;
    {
        const bool branch_taken_0x122438 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x12243Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122438u;
            // 0x12243c: 0xc7ac0000  lwc1        $f12, 0x0($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x122438) {
            ctx->pc = 0x122458u;
            goto label_122458;
        }
    }
    ctx->pc = 0x122440u;
    // 0x122440: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x122440u;
    {
        const bool branch_taken_0x122440 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x122444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122440u;
            // 0x122444: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122440) {
            ctx->pc = 0x122490u;
            goto label_122490;
        }
    }
    ctx->pc = 0x122448u;
label_122448:
    // 0x122448: 0x1082000d  beq         $a0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x122448u;
    {
        const bool branch_taken_0x122448 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x12244Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122448u;
            // 0x12244c: 0xc7ac0000  lwc1        $f12, 0x0($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x122448) {
            ctx->pc = 0x122480u;
            goto label_122480;
        }
    }
    ctx->pc = 0x122450u;
    // 0x122450: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x122450u;
    {
        const bool branch_taken_0x122450 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x122454u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122450u;
            // 0x122454: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122450) {
            ctx->pc = 0x122490u;
            goto label_122490;
        }
    }
    ctx->pc = 0x122458u;
label_122458:
    // 0x122458: 0xc0483da  jal         func_120F68
    ctx->pc = 0x122458u;
    SET_GPR_U32(ctx, 31, 0x122460u);
    ctx->pc = 0x12245Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x122458u;
            // 0x12245c: 0xc7ad0004  lwc1        $f13, 0x4($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[13] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x120F68u;
    if (runtime->hasFunction(0x120F68u)) {
        auto targetFn = runtime->lookupFunction(0x120F68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122460u; }
        if (ctx->pc != 0x122460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00120F68_0x120f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122460u; }
        if (ctx->pc != 0x122460u) { return; }
    }
    ctx->pc = 0x122460u;
label_122460:
    // 0x122460: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x122460u;
    {
        const bool branch_taken_0x122460 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x122464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122460u;
            // 0x122464: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122460) {
            ctx->pc = 0x12249Cu;
            goto label_12249c;
        }
    }
    ctx->pc = 0x122468u;
label_122468:
    // 0x122468: 0xc7ac0000  lwc1        $f12, 0x0($sp)
    ctx->pc = 0x122468u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x12246c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x12246cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x122470: 0xc048648  jal         func_121920
    ctx->pc = 0x122470u;
    SET_GPR_U32(ctx, 31, 0x122478u);
    ctx->pc = 0x122474u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x122470u;
            // 0x122474: 0xc7ad0004  lwc1        $f13, 0x4($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[13] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x121920u;
    if (runtime->hasFunction(0x121920u)) {
        auto targetFn = runtime->lookupFunction(0x121920u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122478u; }
        if (ctx->pc != 0x122478u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00121920_0x121920(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122478u; }
        if (ctx->pc != 0x122478u) { return; }
    }
    ctx->pc = 0x122478u;
label_122478:
    // 0x122478: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x122478u;
    {
        const bool branch_taken_0x122478 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12247Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122478u;
            // 0x12247c: 0x46000007  neg.s       $f0, $f0 (Delay Slot)
        ctx->f[0] = FPU_NEG_S(ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x122478) {
            ctx->pc = 0x122498u;
            goto label_122498;
        }
    }
    ctx->pc = 0x122480u;
label_122480:
    // 0x122480: 0xc0483da  jal         func_120F68
    ctx->pc = 0x122480u;
    SET_GPR_U32(ctx, 31, 0x122488u);
    ctx->pc = 0x122484u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x122480u;
            // 0x122484: 0xc7ad0004  lwc1        $f13, 0x4($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[13] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x120F68u;
    if (runtime->hasFunction(0x120F68u)) {
        auto targetFn = runtime->lookupFunction(0x120F68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122488u; }
        if (ctx->pc != 0x122488u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00120F68_0x120f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122488u; }
        if (ctx->pc != 0x122488u) { return; }
    }
    ctx->pc = 0x122488u;
label_122488:
    // 0x122488: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x122488u;
    {
        const bool branch_taken_0x122488 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12248Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122488u;
            // 0x12248c: 0x46000007  neg.s       $f0, $f0 (Delay Slot)
        ctx->f[0] = FPU_NEG_S(ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x122488) {
            ctx->pc = 0x122498u;
            goto label_122498;
        }
    }
    ctx->pc = 0x122490u;
label_122490:
    // 0x122490: 0xc048648  jal         func_121920
    ctx->pc = 0x122490u;
    SET_GPR_U32(ctx, 31, 0x122498u);
    ctx->pc = 0x122494u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x122490u;
            // 0x122494: 0xc7ad0004  lwc1        $f13, 0x4($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[13] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x121920u;
    if (runtime->hasFunction(0x121920u)) {
        auto targetFn = runtime->lookupFunction(0x121920u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122498u; }
        if (ctx->pc != 0x122498u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00121920_0x121920(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122498u; }
        if (ctx->pc != 0x122498u) { return; }
    }
    ctx->pc = 0x122498u;
label_122498:
    // 0x122498: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x122498u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_12249c:
    // 0x12249c: 0x3e00008  jr          $ra
    ctx->pc = 0x12249Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1224A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12249Cu;
            // 0x1224a0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122410u: goto label_122410;
            case 0x122418u: goto label_122418;
            case 0x122420u: goto label_122420;
            case 0x122448u: goto label_122448;
            case 0x122458u: goto label_122458;
            case 0x122460u: goto label_122460;
            case 0x122468u: goto label_122468;
            case 0x122478u: goto label_122478;
            case 0x122480u: goto label_122480;
            case 0x122488u: goto label_122488;
            case 0x122490u: goto label_122490;
            case 0x122498u: goto label_122498;
            case 0x12249Cu: goto label_12249c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1224A4u;
    // 0x1224a4: 0x0  nop
    ctx->pc = 0x1224a4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
