#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001224D0
// Address: 0x1224d0 - 0x122690
void sub_001224D0_0x1224d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001224D0_0x1224d0");
#endif

    switch (ctx->pc) {
        case 0x1225e8u: goto label_1225e8;
        case 0x1225f8u: goto label_1225f8;
        case 0x12263cu: goto label_12263c;
        case 0x122654u: goto label_122654;
        case 0x12266cu: goto label_12266c;
        case 0x122680u: goto label_122680;
        default: break;
    }

    ctx->pc = 0x1224d0u;

    // 0x1224d0: 0x44036000  mfc1        $v1, $f12
    ctx->pc = 0x1224d0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[12], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1224d4: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x1224d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1224d8: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x1224d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x1224dc: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1224dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1224e0: 0x823024  and         $a2, $a0, $v0
    ctx->pc = 0x1224e0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1224e4: 0x61dc2  srl         $v1, $a2, 23
    ctx->pc = 0x1224e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 6), 23));
    // 0x1224e8: 0x2465ff81  addiu       $a1, $v1, -0x7F
    ctx->pc = 0x1224e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967169));
    // 0x1224ec: 0x28a20017  slti        $v0, $a1, 0x17
    ctx->pc = 0x1224ecu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)23) ? 1 : 0);
    // 0x1224f0: 0x1040002b  beqz        $v0, . + 4 + (0x2B << 2)
    ctx->pc = 0x1224F0u;
    {
        const bool branch_taken_0x1224f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1224F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1224F0u;
            // 0x1224f4: 0x46006006  mov.s       $f0, $f12 (Delay Slot)
        ctx->f[0] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1224f0) {
            ctx->pc = 0x1225A0u;
            goto label_1225a0;
        }
    }
    ctx->pc = 0x1224F8u;
    // 0x1224f8: 0x4a30013  bgezl       $a1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1224F8u;
    {
        const bool branch_taken_0x1224f8 = (GPR_S64(ctx, 5) >= 0);
        if (branch_taken_0x1224f8) {
            ctx->pc = 0x1224FCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1224F8u;
            // 0x1224fc: 0x3c02007f  lui         $v0, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)127 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x122548u;
            goto label_122548;
        }
    }
    ctx->pc = 0x122500u;
    // 0x122500: 0x3c017149  lui         $at, 0x7149
    ctx->pc = 0x122500u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)29001 << 16));
    // 0x122504: 0x3421f2c9  ori         $at, $at, 0xF2C9
    ctx->pc = 0x122504u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)62153);
    // 0x122508: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x122508u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x12250c: 0x44800800  mtc1        $zero, $f1
    ctx->pc = 0x12250cu;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x122510: 0x46006000  add.s       $f0, $f12, $f0
    ctx->pc = 0x122510u;
    ctx->f[0] = FPU_ADD_S(ctx->f[12], ctx->f[0]);
    // 0x122514: 0x46000834  c.lt.s      $f1, $f0
    ctx->pc = 0x122514u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x122518: 0x4500001f  bc1f        . + 4 + (0x1F << 2)
    ctx->pc = 0x122518u;
    {
        const bool branch_taken_0x122518 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x122518) {
            ctx->pc = 0x122598u;
            goto label_122598;
        }
    }
    ctx->pc = 0x122520u;
    // 0x122520: 0x4800003  bltz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x122520u;
    {
        const bool branch_taken_0x122520 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x122524u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122520u;
            // 0x122524: 0x3c02007f  lui         $v0, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)127 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122520) {
            ctx->pc = 0x122530u;
            goto label_122530;
        }
    }
    ctx->pc = 0x122528u;
    // 0x122528: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x122528u;
    {
        const bool branch_taken_0x122528 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12252Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122528u;
            // 0x12252c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122528) {
            ctx->pc = 0x122598u;
            goto label_122598;
        }
    }
    ctx->pc = 0x122530u;
label_122530:
    // 0x122530: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x122530u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x122534: 0x46102b  sltu        $v0, $v0, $a2
    ctx->pc = 0x122534u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x122538: 0x54400017  bnel        $v0, $zero, . + 4 + (0x17 << 2)
    ctx->pc = 0x122538u;
    {
        const bool branch_taken_0x122538 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x122538) {
            ctx->pc = 0x12253Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x122538u;
            // 0x12253c: 0x3c04bf80  lui         $a0, 0xBF80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49024 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x122598u;
            goto label_122598;
        }
    }
    ctx->pc = 0x122540u;
    // 0x122540: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x122540u;
    {
        const bool branch_taken_0x122540 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x122540) {
            ctx->pc = 0x122598u;
            goto label_122598;
        }
    }
    ctx->pc = 0x122548u;
label_122548:
    // 0x122548: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x122548u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x12254c: 0xa23007  srav        $a2, $v0, $a1
    ctx->pc = 0x12254cu;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 2), GPR_U32(ctx, 5) & 0x1F));
    // 0x122550: 0x861824  and         $v1, $a0, $a2
    ctx->pc = 0x122550u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 6));
    // 0x122554: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x122554u;
    {
        const bool branch_taken_0x122554 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x122558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122554u;
            // 0x122558: 0x46006006  mov.s       $f0, $f12 (Delay Slot)
        ctx->f[0] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x122554) {
            ctx->pc = 0x1225A0u;
            goto label_1225a0;
        }
    }
    ctx->pc = 0x12255Cu;
    // 0x12255c: 0x3c017149  lui         $at, 0x7149
    ctx->pc = 0x12255cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)29001 << 16));
    // 0x122560: 0x3421f2c9  ori         $at, $at, 0xF2C9
    ctx->pc = 0x122560u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)62153);
    // 0x122564: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x122564u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x122568: 0x44800800  mtc1        $zero, $f1
    ctx->pc = 0x122568u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x12256c: 0x46006000  add.s       $f0, $f12, $f0
    ctx->pc = 0x12256cu;
    ctx->f[0] = FPU_ADD_S(ctx->f[12], ctx->f[0]);
    // 0x122570: 0x46000834  c.lt.s      $f1, $f0
    ctx->pc = 0x122570u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x122574: 0x45000008  bc1f        . + 4 + (0x8 << 2)
    ctx->pc = 0x122574u;
    {
        const bool branch_taken_0x122574 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x122574) {
            ctx->pc = 0x122598u;
            goto label_122598;
        }
    }
    ctx->pc = 0x12257Cu;
    // 0x12257c: 0x4810005  bgez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x12257Cu;
    {
        const bool branch_taken_0x12257c = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x122580u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12257Cu;
            // 0x122580: 0x61027  nor         $v0, $zero, $a2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12257c) {
            ctx->pc = 0x122594u;
            goto label_122594;
        }
    }
    ctx->pc = 0x122584u;
    // 0x122584: 0x3c020080  lui         $v0, 0x80
    ctx->pc = 0x122584u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)128 << 16));
    // 0x122588: 0xa21007  srav        $v0, $v0, $a1
    ctx->pc = 0x122588u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), GPR_U32(ctx, 5) & 0x1F));
    // 0x12258c: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x12258cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x122590: 0x61027  nor         $v0, $zero, $a2
    ctx->pc = 0x122590u;
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 6)));
label_122594:
    // 0x122594: 0x822024  and         $a0, $a0, $v0
    ctx->pc = 0x122594u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
label_122598:
    // 0x122598: 0x44846000  mtc1        $a0, $f12
    ctx->pc = 0x122598u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
    // 0x12259c: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x12259cu;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
label_1225a0:
    // 0x1225a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1225A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122530u: goto label_122530;
            case 0x122548u: goto label_122548;
            case 0x122594u: goto label_122594;
            case 0x122598u: goto label_122598;
            case 0x1225A0u: goto label_1225a0;
            case 0x1225E8u: goto label_1225e8;
            case 0x1225F0u: goto label_1225f0;
            case 0x1225F8u: goto label_1225f8;
            case 0x122620u: goto label_122620;
            case 0x122630u: goto label_122630;
            case 0x12263Cu: goto label_12263c;
            case 0x122648u: goto label_122648;
            case 0x122654u: goto label_122654;
            case 0x122660u: goto label_122660;
            case 0x12266Cu: goto label_12266c;
            case 0x122678u: goto label_122678;
            case 0x122680u: goto label_122680;
            case 0x122684u: goto label_122684;
            case 0x122688u: goto label_122688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1225A8u;
    // 0x1225a8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1225a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1225ac: 0x46006006  mov.s       $f0, $f12
    ctx->pc = 0x1225acu;
    ctx->f[0] = FPU_MOV_S(ctx->f[12]);
    // 0x1225b0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1225b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1225b4: 0xe7a00010  swc1        $f0, 0x10($sp)
    ctx->pc = 0x1225b4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 16), bits); }
    // 0x1225b8: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x1225b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x1225bc: 0x3c033f49  lui         $v1, 0x3F49
    ctx->pc = 0x1225bcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16201 << 16));
    // 0x1225c0: 0x8fa40010  lw          $a0, 0x10($sp)
    ctx->pc = 0x1225c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1225c4: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1225c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1225c8: 0x34630fd8  ori         $v1, $v1, 0xFD8
    ctx->pc = 0x1225c8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4056);
    // 0x1225cc: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1225ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1225d0: 0x62182a  slt         $v1, $v1, $v0
    ctx->pc = 0x1225d0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1225d4: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1225D4u;
    {
        const bool branch_taken_0x1225d4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1225d4) {
            ctx->pc = 0x1225F0u;
            goto label_1225f0;
        }
    }
    ctx->pc = 0x1225DCu;
    // 0x1225dc: 0x44806800  mtc1        $zero, $f13
    ctx->pc = 0x1225dcu;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[13], &bits, sizeof(bits)); }
    // 0x1225e0: 0xc048648  jal         func_121920
    ctx->pc = 0x1225E0u;
    SET_GPR_U32(ctx, 31, 0x1225E8u);
    ctx->pc = 0x1225E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1225E0u;
            // 0x1225e4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x121920u;
    if (runtime->hasFunction(0x121920u)) {
        auto targetFn = runtime->lookupFunction(0x121920u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1225E8u; }
        if (ctx->pc != 0x1225E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00121920_0x121920(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1225E8u; }
        if (ctx->pc != 0x1225E8u) { return; }
    }
    ctx->pc = 0x1225E8u;
label_1225e8:
    // 0x1225e8: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x1225E8u;
    {
        const bool branch_taken_0x1225e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1225ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1225E8u;
            // 0x1225ec: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1225e8) {
            ctx->pc = 0x122688u;
            goto label_122688;
        }
    }
    ctx->pc = 0x1225F0u;
label_1225f0:
    // 0x1225f0: 0xc0482ba  jal         func_120AE8
    ctx->pc = 0x1225F0u;
    SET_GPR_U32(ctx, 31, 0x1225F8u);
    ctx->pc = 0x1225F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1225F0u;
            // 0x1225f4: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x120AE8u;
    if (runtime->hasFunction(0x120AE8u)) {
        auto targetFn = runtime->lookupFunction(0x120AE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1225F8u; }
        if (ctx->pc != 0x1225F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00120AE8_0x120ae8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1225F8u; }
        if (ctx->pc != 0x1225F8u) { return; }
    }
    ctx->pc = 0x1225F8u;
label_1225f8:
    // 0x1225f8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1225f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1225fc: 0x30440003  andi        $a0, $v0, 0x3
    ctx->pc = 0x1225fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x122600: 0x10830011  beq         $a0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x122600u;
    {
        const bool branch_taken_0x122600 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x122604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122600u;
            // 0x122604: 0x28820002  slti        $v0, $a0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x122600) {
            ctx->pc = 0x122648u;
            goto label_122648;
        }
    }
    ctx->pc = 0x122608u;
    // 0x122608: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x122608u;
    {
        const bool branch_taken_0x122608 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x122608) {
            ctx->pc = 0x12260Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x122608u;
            // 0x12260c: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x122620u;
            goto label_122620;
        }
    }
    ctx->pc = 0x122610u;
    // 0x122610: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x122610u;
    {
        const bool branch_taken_0x122610 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x122614u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122610u;
            // 0x122614: 0xc7ac0000  lwc1        $f12, 0x0($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x122610) {
            ctx->pc = 0x122630u;
            goto label_122630;
        }
    }
    ctx->pc = 0x122618u;
    // 0x122618: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x122618u;
    {
        const bool branch_taken_0x122618 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x122618) {
            ctx->pc = 0x122678u;
            goto label_122678;
        }
    }
    ctx->pc = 0x122620u;
label_122620:
    // 0x122620: 0x1082000f  beq         $a0, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x122620u;
    {
        const bool branch_taken_0x122620 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x122624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122620u;
            // 0x122624: 0xc7ac0000  lwc1        $f12, 0x0($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x122620) {
            ctx->pc = 0x122660u;
            goto label_122660;
        }
    }
    ctx->pc = 0x122628u;
    // 0x122628: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x122628u;
    {
        const bool branch_taken_0x122628 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x122628) {
            ctx->pc = 0x122678u;
            goto label_122678;
        }
    }
    ctx->pc = 0x122630u;
label_122630:
    // 0x122630: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x122630u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x122634: 0xc048648  jal         func_121920
    ctx->pc = 0x122634u;
    SET_GPR_U32(ctx, 31, 0x12263Cu);
    ctx->pc = 0x122638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x122634u;
            // 0x122638: 0xc7ad0004  lwc1        $f13, 0x4($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[13] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x121920u;
    if (runtime->hasFunction(0x121920u)) {
        auto targetFn = runtime->lookupFunction(0x121920u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12263Cu; }
        if (ctx->pc != 0x12263Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00121920_0x121920(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12263Cu; }
        if (ctx->pc != 0x12263Cu) { return; }
    }
    ctx->pc = 0x12263Cu;
label_12263c:
    // 0x12263c: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x12263Cu;
    {
        const bool branch_taken_0x12263c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x122640u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12263Cu;
            // 0x122640: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12263c) {
            ctx->pc = 0x122688u;
            goto label_122688;
        }
    }
    ctx->pc = 0x122644u;
    // 0x122644: 0x0  nop
    ctx->pc = 0x122644u;
    // NOP
label_122648:
    // 0x122648: 0xc7ac0000  lwc1        $f12, 0x0($sp)
    ctx->pc = 0x122648u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x12264c: 0xc0483da  jal         func_120F68
    ctx->pc = 0x12264Cu;
    SET_GPR_U32(ctx, 31, 0x122654u);
    ctx->pc = 0x122650u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12264Cu;
            // 0x122650: 0xc7ad0004  lwc1        $f13, 0x4($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[13] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x120F68u;
    if (runtime->hasFunction(0x120F68u)) {
        auto targetFn = runtime->lookupFunction(0x120F68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122654u; }
        if (ctx->pc != 0x122654u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00120F68_0x120f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122654u; }
        if (ctx->pc != 0x122654u) { return; }
    }
    ctx->pc = 0x122654u;
label_122654:
    // 0x122654: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x122654u;
    {
        const bool branch_taken_0x122654 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x122658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122654u;
            // 0x122658: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122654) {
            ctx->pc = 0x122688u;
            goto label_122688;
        }
    }
    ctx->pc = 0x12265Cu;
    // 0x12265c: 0x0  nop
    ctx->pc = 0x12265cu;
    // NOP
label_122660:
    // 0x122660: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x122660u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x122664: 0xc048648  jal         func_121920
    ctx->pc = 0x122664u;
    SET_GPR_U32(ctx, 31, 0x12266Cu);
    ctx->pc = 0x122668u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x122664u;
            // 0x122668: 0xc7ad0004  lwc1        $f13, 0x4($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[13] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x121920u;
    if (runtime->hasFunction(0x121920u)) {
        auto targetFn = runtime->lookupFunction(0x121920u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12266Cu; }
        if (ctx->pc != 0x12266Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00121920_0x121920(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12266Cu; }
        if (ctx->pc != 0x12266Cu) { return; }
    }
    ctx->pc = 0x12266Cu;
label_12266c:
    // 0x12266c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x12266Cu;
    {
        const bool branch_taken_0x12266c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x122670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12266Cu;
            // 0x122670: 0x46000007  neg.s       $f0, $f0 (Delay Slot)
        ctx->f[0] = FPU_NEG_S(ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x12266c) {
            ctx->pc = 0x122684u;
            goto label_122684;
        }
    }
    ctx->pc = 0x122674u;
    // 0x122674: 0x0  nop
    ctx->pc = 0x122674u;
    // NOP
label_122678:
    // 0x122678: 0xc0483da  jal         func_120F68
    ctx->pc = 0x122678u;
    SET_GPR_U32(ctx, 31, 0x122680u);
    ctx->pc = 0x12267Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x122678u;
            // 0x12267c: 0xc7ad0004  lwc1        $f13, 0x4($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[13] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x120F68u;
    if (runtime->hasFunction(0x120F68u)) {
        auto targetFn = runtime->lookupFunction(0x120F68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122680u; }
        if (ctx->pc != 0x122680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00120F68_0x120f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122680u; }
        if (ctx->pc != 0x122680u) { return; }
    }
    ctx->pc = 0x122680u;
label_122680:
    // 0x122680: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x122680u;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
label_122684:
    // 0x122684: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x122684u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_122688:
    // 0x122688: 0x3e00008  jr          $ra
    ctx->pc = 0x122688u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12268Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122688u;
            // 0x12268c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122530u: goto label_122530;
            case 0x122548u: goto label_122548;
            case 0x122594u: goto label_122594;
            case 0x122598u: goto label_122598;
            case 0x1225A0u: goto label_1225a0;
            case 0x1225E8u: goto label_1225e8;
            case 0x1225F0u: goto label_1225f0;
            case 0x1225F8u: goto label_1225f8;
            case 0x122620u: goto label_122620;
            case 0x122630u: goto label_122630;
            case 0x12263Cu: goto label_12263c;
            case 0x122648u: goto label_122648;
            case 0x122654u: goto label_122654;
            case 0x122660u: goto label_122660;
            case 0x12266Cu: goto label_12266c;
            case 0x122678u: goto label_122678;
            case 0x122680u: goto label_122680;
            case 0x122684u: goto label_122684;
            case 0x122688u: goto label_122688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122690u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
