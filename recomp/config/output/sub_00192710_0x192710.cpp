#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192710
// Address: 0x192710 - 0x192a60
void sub_00192710_0x192710(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192710_0x192710");
#endif

    switch (ctx->pc) {
        case 0x192748u: goto label_192748;
        case 0x1927a8u: goto label_1927a8;
        case 0x1927e0u: goto label_1927e0;
        case 0x1927f0u: goto label_1927f0;
        case 0x192858u: goto label_192858;
        case 0x192878u: goto label_192878;
        case 0x1928a0u: goto label_1928a0;
        case 0x192900u: goto label_192900;
        case 0x192918u: goto label_192918;
        case 0x192940u: goto label_192940;
        case 0x1929acu: goto label_1929ac;
        case 0x1929d0u: goto label_1929d0;
        case 0x192a20u: goto label_192a20;
        case 0x192a48u: goto label_192a48;
        default: break;
    }

    ctx->pc = 0x192710u;

    // 0x192710: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x192710u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x192714: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x192714u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x192718: 0x7fb30040  sq          $s3, 0x40($sp)
    ctx->pc = 0x192718u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 19));
    // 0x19271c: 0x7fb20030  sq          $s2, 0x30($sp)
    ctx->pc = 0x19271cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 18));
    // 0x192720: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x192720u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192724: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x192724u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x192728: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x192728u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19272c: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x19272cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x192730: 0x260882d  daddu       $s1, $s3, $zero
    ctx->pc = 0x192730u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192734: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x192734u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x192738: 0x30d0ffff  andi        $s0, $a2, 0xFFFF
    ctx->pc = 0x192738u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
    // 0x19273c: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x19273cu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x192740: 0x46006546  mov.s       $f21, $f12
    ctx->pc = 0x192740u;
    ctx->f[21] = FPU_MOV_S(ctx->f[12]);
    // 0x192744: 0x46006d06  mov.s       $f20, $f13
    ctx->pc = 0x192744u;
    ctx->f[20] = FPU_MOV_S(ctx->f[13]);
label_192748:
    // 0x192748: 0x966200c6  lhu         $v0, 0xC6($s3)
    ctx->pc = 0x192748u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 198)));
    // 0x19274c: 0x1450001c  bne         $v0, $s0, . + 4 + (0x1C << 2)
    ctx->pc = 0x19274Cu;
    {
        const bool branch_taken_0x19274c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 16));
        if (branch_taken_0x19274c) {
            ctx->pc = 0x1927C0u;
            goto label_1927c0;
        }
    }
    ctx->pc = 0x192754u;
    // 0x192754: 0xc6610104  lwc1        $f1, 0x104($s3)
    ctx->pc = 0x192754u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 19), 260)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x192758: 0x26640040  addiu       $a0, $s3, 0x40
    ctx->pc = 0x192758u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 64));
    // 0x19275c: 0xc6400104  lwc1        $f0, 0x104($s2)
    ctx->pc = 0x19275cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 260)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x192760: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x192760u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192764: 0x26460040  addiu       $a2, $s2, 0x40
    ctx->pc = 0x192764u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 64));
    // 0x192768: 0x4600ab06  mov.s       $f12, $f21
    ctx->pc = 0x192768u;
    ctx->f[12] = FPU_MOV_S(ctx->f[21]);
    // 0x19276c: 0x4600a346  mov.s       $f13, $f20
    ctx->pc = 0x19276cu;
    ctx->f[13] = FPU_MOV_S(ctx->f[20]);
    // 0x192770: 0x4615081a  mula.s      $f1, $f21
    ctx->pc = 0x192770u;
    ctx->f[31] = FPU_MUL_S(ctx->f[1], ctx->f[21]);
    // 0x192774: 0x4614001c  madd.s      $f0, $f0, $f20
    ctx->pc = 0x192774u;
    ctx->f[0] = FPU_ADD_S(ctx->f[31], FPU_MUL_S(ctx->f[0], ctx->f[20]));
    // 0x192778: 0xe6600104  swc1        $f0, 0x104($s3)
    ctx->pc = 0x192778u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 260), bits); }
    // 0x19277c: 0xc6610108  lwc1        $f1, 0x108($s3)
    ctx->pc = 0x19277cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 19), 264)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x192780: 0xc6400108  lwc1        $f0, 0x108($s2)
    ctx->pc = 0x192780u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 264)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x192784: 0x4615081a  mula.s      $f1, $f21
    ctx->pc = 0x192784u;
    ctx->f[31] = FPU_MUL_S(ctx->f[1], ctx->f[21]);
    // 0x192788: 0x4614001c  madd.s      $f0, $f0, $f20
    ctx->pc = 0x192788u;
    ctx->f[0] = FPU_ADD_S(ctx->f[31], FPU_MUL_S(ctx->f[0], ctx->f[20]));
    // 0x19278c: 0xe6600108  swc1        $f0, 0x108($s3)
    ctx->pc = 0x19278cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 264), bits); }
    // 0x192790: 0xc661010c  lwc1        $f1, 0x10C($s3)
    ctx->pc = 0x192790u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 19), 268)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x192794: 0xc640010c  lwc1        $f0, 0x10C($s2)
    ctx->pc = 0x192794u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 268)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x192798: 0x4615081a  mula.s      $f1, $f21
    ctx->pc = 0x192798u;
    ctx->f[31] = FPU_MUL_S(ctx->f[1], ctx->f[21]);
    // 0x19279c: 0x4614001c  madd.s      $f0, $f0, $f20
    ctx->pc = 0x19279cu;
    ctx->f[0] = FPU_ADD_S(ctx->f[31], FPU_MUL_S(ctx->f[0], ctx->f[20]));
    // 0x1927a0: 0xc064640  jal         func_191900
    ctx->pc = 0x1927A0u;
    SET_GPR_U32(ctx, 31, 0x1927A8u);
    ctx->pc = 0x1927A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1927A0u;
            // 0x1927a4: 0xe660010c  swc1        $f0, 0x10C($s3) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 268), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x191900u;
    if (runtime->hasFunction(0x191900u)) {
        auto targetFn = runtime->lookupFunction(0x191900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1927A8u; }
        if (ctx->pc != 0x1927A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191900_0x191900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1927A8u; }
        if (ctx->pc != 0x1927A8u) { return; }
    }
    ctx->pc = 0x1927A8u;
label_1927a8:
    // 0x1927a8: 0x8e6200d0  lw          $v0, 0xD0($s3)
    ctx->pc = 0x1927a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 208)));
    // 0x1927ac: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1927ACu;
    {
        const bool branch_taken_0x1927ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1927ac) {
            ctx->pc = 0x1927C0u;
            goto label_1927c0;
        }
    }
    ctx->pc = 0x1927B4u;
    // 0x1927b4: 0x8e5200d0  lw          $s2, 0xD0($s2)
    ctx->pc = 0x1927b4u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 208)));
    // 0x1927b8: 0x1000ffe3  b           . + 4 + (-0x1D << 2)
    ctx->pc = 0x1927B8u;
    {
        const bool branch_taken_0x1927b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1927BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1927B8u;
            // 0x1927bc: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1927b8) {
            ctx->pc = 0x192748u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192748;
        }
    }
    ctx->pc = 0x1927C0u;
label_1927c0:
    // 0x1927c0: 0x8e6200cc  lw          $v0, 0xCC($s3)
    ctx->pc = 0x1927c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 204)));
    // 0x1927c4: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1927C4u;
    {
        const bool branch_taken_0x1927c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1927c4) {
            ctx->pc = 0x192804u;
            goto label_192804;
        }
    }
    ctx->pc = 0x1927CCu;
    // 0x1927cc: 0x1271000d  beq         $s3, $s1, . + 4 + (0xD << 2)
    ctx->pc = 0x1927CCu;
    {
        const bool branch_taken_0x1927cc = (GPR_U64(ctx, 19) == GPR_U64(ctx, 17));
        if (branch_taken_0x1927cc) {
            ctx->pc = 0x192804u;
            goto label_192804;
        }
    }
    ctx->pc = 0x1927D4u;
    // 0x1927d4: 0x8e5200cc  lw          $s2, 0xCC($s2)
    ctx->pc = 0x1927d4u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 204)));
    // 0x1927d8: 0x1000ffdb  b           . + 4 + (-0x25 << 2)
    ctx->pc = 0x1927D8u;
    {
        const bool branch_taken_0x1927d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1927DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1927D8u;
            // 0x1927dc: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1927d8) {
            ctx->pc = 0x192748u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192748;
        }
    }
    ctx->pc = 0x1927E0u;
label_1927e0:
    // 0x1927e0: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x1927e0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1927e4: 0x944200c6  lhu         $v0, 0xC6($v0)
    ctx->pc = 0x1927e4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 198)));
    // 0x1927e8: 0x1050ffd7  beq         $v0, $s0, . + 4 + (-0x29 << 2)
    ctx->pc = 0x1927E8u;
    {
        const bool branch_taken_0x1927e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 16));
        ctx->pc = 0x1927ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1927E8u;
            // 0x1927ec: 0x8e5200cc  lw          $s2, 0xCC($s2) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 204)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1927e8) {
            ctx->pc = 0x192748u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192748;
        }
    }
    ctx->pc = 0x1927F0u;
label_1927f0:
    // 0x1927f0: 0x8e6200cc  lw          $v0, 0xCC($s3)
    ctx->pc = 0x1927f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 204)));
    // 0x1927f4: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1927F4u;
    {
        const bool branch_taken_0x1927f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1927f4) {
            ctx->pc = 0x1927E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1927e0;
        }
    }
    ctx->pc = 0x1927FCu;
    // 0x1927fc: 0x8e7300c8  lw          $s3, 0xC8($s3)
    ctx->pc = 0x1927fcu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 200)));
    // 0x192800: 0x8e5200c8  lw          $s2, 0xC8($s2)
    ctx->pc = 0x192800u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 200)));
label_192804:
    // 0x192804: 0x1671fffa  bne         $s3, $s1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x192804u;
    {
        const bool branch_taken_0x192804 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 17));
        if (branch_taken_0x192804) {
            ctx->pc = 0x1927F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1927f0;
        }
    }
    ctx->pc = 0x19280Cu;
    // 0x19280c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19280cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x192810: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x192810u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x192814: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x192814u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x192818: 0x7bb30040  lq          $s3, 0x40($sp)
    ctx->pc = 0x192818u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19281c: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x19281cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x192820: 0x7bb20030  lq          $s2, 0x30($sp)
    ctx->pc = 0x192820u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x192824: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x192824u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x192828: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x192828u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19282c: 0x3e00008  jr          $ra
    ctx->pc = 0x19282Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x192830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19282Cu;
            // 0x192830: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192748u: goto label_192748;
            case 0x1927A8u: goto label_1927a8;
            case 0x1927C0u: goto label_1927c0;
            case 0x1927E0u: goto label_1927e0;
            case 0x1927F0u: goto label_1927f0;
            case 0x192804u: goto label_192804;
            case 0x192858u: goto label_192858;
            case 0x192878u: goto label_192878;
            case 0x19288Cu: goto label_19288c;
            case 0x1928A0u: goto label_1928a0;
            case 0x1928B4u: goto label_1928b4;
            case 0x1928B8u: goto label_1928b8;
            case 0x192900u: goto label_192900;
            case 0x192918u: goto label_192918;
            case 0x19292Cu: goto label_19292c;
            case 0x192940u: goto label_192940;
            case 0x192954u: goto label_192954;
            case 0x192958u: goto label_192958;
            case 0x1929ACu: goto label_1929ac;
            case 0x1929D0u: goto label_1929d0;
            case 0x1929D8u: goto label_1929d8;
            case 0x192A20u: goto label_192a20;
            case 0x192A48u: goto label_192a48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192834u;
    // 0x192834: 0x0  nop
    ctx->pc = 0x192834u;
    // NOP
    // 0x192838: 0x0  nop
    ctx->pc = 0x192838u;
    // NOP
    // 0x19283c: 0x0  nop
    ctx->pc = 0x19283cu;
    // NOP
    // 0x192840: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x192840u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x192844: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x192844u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x192848: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x192848u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19284c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19284cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x192850: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x192850u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192854: 0x220802d  daddu       $s0, $s1, $zero
    ctx->pc = 0x192854u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_192858:
    // 0x192858: 0x862200c4  lh          $v0, 0xC4($s1)
    ctx->pc = 0x192858u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 196)));
    // 0x19285c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x19285cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x192860: 0x34213700  ori         $at, $at, 0x3700
    ctx->pc = 0x192860u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)14080);
    // 0x192864: 0x26250080  addiu       $a1, $s1, 0x80
    ctx->pc = 0x192864u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 128));
    // 0x192868: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x192868u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19286c: 0x21180  sll         $v0, $v0, 6
    ctx->pc = 0x19286cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x192870: 0xc0644a0  jal         func_191280
    ctx->pc = 0x192870u;
    SET_GPR_U32(ctx, 31, 0x192878u);
    ctx->pc = 0x192874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192870u;
            // 0x192874: 0x412021  addu        $a0, $v0, $at (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 1)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192878u; }
        if (ctx->pc != 0x192878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192878u; }
        if (ctx->pc != 0x192878u) { return; }
    }
    ctx->pc = 0x192878u;
label_192878:
    // 0x192878: 0x8e2300d0  lw          $v1, 0xD0($s1)
    ctx->pc = 0x192878u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 208)));
    // 0x19287c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x19287Cu;
    {
        const bool branch_taken_0x19287c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x19287c) {
            ctx->pc = 0x19288Cu;
            goto label_19288c;
        }
    }
    ctx->pc = 0x192884u;
    // 0x192884: 0x1000fff4  b           . + 4 + (-0xC << 2)
    ctx->pc = 0x192884u;
    {
        const bool branch_taken_0x192884 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192884u;
            // 0x192888: 0x60882d  daddu       $s1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192884) {
            ctx->pc = 0x192858u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192858;
        }
    }
    ctx->pc = 0x19288Cu;
label_19288c:
    // 0x19288c: 0x8e2300cc  lw          $v1, 0xCC($s1)
    ctx->pc = 0x19288cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 204)));
    // 0x192890: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x192890u;
    {
        const bool branch_taken_0x192890 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x192890) {
            ctx->pc = 0x1928B8u;
            goto label_1928b8;
        }
    }
    ctx->pc = 0x192898u;
    // 0x192898: 0x1000ffef  b           . + 4 + (-0x11 << 2)
    ctx->pc = 0x192898u;
    {
        const bool branch_taken_0x192898 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19289Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192898u;
            // 0x19289c: 0x60882d  daddu       $s1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192898) {
            ctx->pc = 0x192858u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192858;
        }
    }
    ctx->pc = 0x1928A0u;
label_1928a0:
    // 0x1928a0: 0x8e2300cc  lw          $v1, 0xCC($s1)
    ctx->pc = 0x1928a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 204)));
    // 0x1928a4: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1928A4u;
    {
        const bool branch_taken_0x1928a4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1928a4) {
            ctx->pc = 0x1928B4u;
            goto label_1928b4;
        }
    }
    ctx->pc = 0x1928ACu;
    // 0x1928ac: 0x1000ffea  b           . + 4 + (-0x16 << 2)
    ctx->pc = 0x1928ACu;
    {
        const bool branch_taken_0x1928ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1928B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1928ACu;
            // 0x1928b0: 0x60882d  daddu       $s1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1928ac) {
            ctx->pc = 0x192858u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192858;
        }
    }
    ctx->pc = 0x1928B4u;
label_1928b4:
    // 0x1928b4: 0x8e3100c8  lw          $s1, 0xC8($s1)
    ctx->pc = 0x1928b4u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 200)));
label_1928b8:
    // 0x1928b8: 0x1630fff9  bne         $s1, $s0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1928B8u;
    {
        const bool branch_taken_0x1928b8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 16));
        if (branch_taken_0x1928b8) {
            ctx->pc = 0x1928A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1928a0;
        }
    }
    ctx->pc = 0x1928C0u;
    // 0x1928c0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1928c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1928c4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1928c4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1928c8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1928c8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1928cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1928CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1928D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1928CCu;
            // 0x1928d0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192748u: goto label_192748;
            case 0x1927A8u: goto label_1927a8;
            case 0x1927C0u: goto label_1927c0;
            case 0x1927E0u: goto label_1927e0;
            case 0x1927F0u: goto label_1927f0;
            case 0x192804u: goto label_192804;
            case 0x192858u: goto label_192858;
            case 0x192878u: goto label_192878;
            case 0x19288Cu: goto label_19288c;
            case 0x1928A0u: goto label_1928a0;
            case 0x1928B4u: goto label_1928b4;
            case 0x1928B8u: goto label_1928b8;
            case 0x192900u: goto label_192900;
            case 0x192918u: goto label_192918;
            case 0x19292Cu: goto label_19292c;
            case 0x192940u: goto label_192940;
            case 0x192954u: goto label_192954;
            case 0x192958u: goto label_192958;
            case 0x1929ACu: goto label_1929ac;
            case 0x1929D0u: goto label_1929d0;
            case 0x1929D8u: goto label_1929d8;
            case 0x192A20u: goto label_192a20;
            case 0x192A48u: goto label_192a48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1928D4u;
    // 0x1928d4: 0x0  nop
    ctx->pc = 0x1928d4u;
    // NOP
    // 0x1928d8: 0x0  nop
    ctx->pc = 0x1928d8u;
    // NOP
    // 0x1928dc: 0x0  nop
    ctx->pc = 0x1928dcu;
    // NOP
    // 0x1928e0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1928e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1928e4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1928e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1928e8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1928e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1928ec: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1928ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1928f0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1928f0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1928f4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1928f4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1928f8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1928f8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1928fc: 0x220802d  daddu       $s0, $s1, $zero
    ctx->pc = 0x1928fcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_192900:
    // 0x192900: 0x862200c4  lh          $v0, 0xC4($s1)
    ctx->pc = 0x192900u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 196)));
    // 0x192904: 0x26250080  addiu       $a1, $s1, 0x80
    ctx->pc = 0x192904u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 128));
    // 0x192908: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x192908u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19290c: 0x21180  sll         $v0, $v0, 6
    ctx->pc = 0x19290cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x192910: 0xc0644a0  jal         func_191280
    ctx->pc = 0x192910u;
    SET_GPR_U32(ctx, 31, 0x192918u);
    ctx->pc = 0x192914u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192910u;
            // 0x192914: 0x2422021  addu        $a0, $s2, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192918u; }
        if (ctx->pc != 0x192918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192918u; }
        if (ctx->pc != 0x192918u) { return; }
    }
    ctx->pc = 0x192918u;
label_192918:
    // 0x192918: 0x8e2300d0  lw          $v1, 0xD0($s1)
    ctx->pc = 0x192918u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 208)));
    // 0x19291c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x19291Cu;
    {
        const bool branch_taken_0x19291c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x19291c) {
            ctx->pc = 0x19292Cu;
            goto label_19292c;
        }
    }
    ctx->pc = 0x192924u;
    // 0x192924: 0x1000fff6  b           . + 4 + (-0xA << 2)
    ctx->pc = 0x192924u;
    {
        const bool branch_taken_0x192924 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192924u;
            // 0x192928: 0x60882d  daddu       $s1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192924) {
            ctx->pc = 0x192900u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192900;
        }
    }
    ctx->pc = 0x19292Cu;
label_19292c:
    // 0x19292c: 0x8e2300cc  lw          $v1, 0xCC($s1)
    ctx->pc = 0x19292cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 204)));
    // 0x192930: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x192930u;
    {
        const bool branch_taken_0x192930 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x192930) {
            ctx->pc = 0x192958u;
            goto label_192958;
        }
    }
    ctx->pc = 0x192938u;
    // 0x192938: 0x1000fff1  b           . + 4 + (-0xF << 2)
    ctx->pc = 0x192938u;
    {
        const bool branch_taken_0x192938 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19293Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192938u;
            // 0x19293c: 0x60882d  daddu       $s1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192938) {
            ctx->pc = 0x192900u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192900;
        }
    }
    ctx->pc = 0x192940u;
label_192940:
    // 0x192940: 0x8e2300cc  lw          $v1, 0xCC($s1)
    ctx->pc = 0x192940u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 204)));
    // 0x192944: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x192944u;
    {
        const bool branch_taken_0x192944 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x192944) {
            ctx->pc = 0x192954u;
            goto label_192954;
        }
    }
    ctx->pc = 0x19294Cu;
    // 0x19294c: 0x1000ffec  b           . + 4 + (-0x14 << 2)
    ctx->pc = 0x19294Cu;
    {
        const bool branch_taken_0x19294c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19294Cu;
            // 0x192950: 0x60882d  daddu       $s1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19294c) {
            ctx->pc = 0x192900u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192900;
        }
    }
    ctx->pc = 0x192954u;
label_192954:
    // 0x192954: 0x8e3100c8  lw          $s1, 0xC8($s1)
    ctx->pc = 0x192954u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 200)));
label_192958:
    // 0x192958: 0x1630fff9  bne         $s1, $s0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x192958u;
    {
        const bool branch_taken_0x192958 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 16));
        if (branch_taken_0x192958) {
            ctx->pc = 0x192940u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192940;
        }
    }
    ctx->pc = 0x192960u;
    // 0x192960: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x192960u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x192964: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x192964u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x192968: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x192968u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19296c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19296cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x192970: 0x3e00008  jr          $ra
    ctx->pc = 0x192970u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x192974u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192970u;
            // 0x192974: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192748u: goto label_192748;
            case 0x1927A8u: goto label_1927a8;
            case 0x1927C0u: goto label_1927c0;
            case 0x1927E0u: goto label_1927e0;
            case 0x1927F0u: goto label_1927f0;
            case 0x192804u: goto label_192804;
            case 0x192858u: goto label_192858;
            case 0x192878u: goto label_192878;
            case 0x19288Cu: goto label_19288c;
            case 0x1928A0u: goto label_1928a0;
            case 0x1928B4u: goto label_1928b4;
            case 0x1928B8u: goto label_1928b8;
            case 0x192900u: goto label_192900;
            case 0x192918u: goto label_192918;
            case 0x19292Cu: goto label_19292c;
            case 0x192940u: goto label_192940;
            case 0x192954u: goto label_192954;
            case 0x192958u: goto label_192958;
            case 0x1929ACu: goto label_1929ac;
            case 0x1929D0u: goto label_1929d0;
            case 0x1929D8u: goto label_1929d8;
            case 0x192A20u: goto label_192a20;
            case 0x192A48u: goto label_192a48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192978u;
    // 0x192978: 0x0  nop
    ctx->pc = 0x192978u;
    // NOP
    // 0x19297c: 0x0  nop
    ctx->pc = 0x19297cu;
    // NOP
    // 0x192980: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x192980u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x192984: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x192984u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x192988: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x192988u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19298c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19298cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x192990: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x192990u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192994: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x192994u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x192998: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x192998u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19299c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19299cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1929a0: 0x84910000  lh          $s1, 0x0($a0)
    ctx->pc = 0x1929a0u;
    SET_GPR_S32(ctx, 17, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1929a4: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1929A4u;
    {
        const bool branch_taken_0x1929a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1929A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1929A4u;
            // 0x1929a8: 0x24900002  addiu       $s0, $a0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1929a4) {
            ctx->pc = 0x1929D8u;
            goto label_1929d8;
        }
    }
    ctx->pc = 0x1929ACu;
label_1929ac:
    // 0x1929ac: 0x86030000  lh          $v1, 0x0($s0)
    ctx->pc = 0x1929acu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1929b0: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1929b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1929b4: 0x121180  sll         $v0, $s2, 6
    ctx->pc = 0x1929b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 6));
    // 0x1929b8: 0x34213700  ori         $at, $at, 0x3700
    ctx->pc = 0x1929b8u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)14080);
    // 0x1929bc: 0x412821  addu        $a1, $v0, $at
    ctx->pc = 0x1929bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 1)));
    // 0x1929c0: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1929c0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1929c4: 0x31180  sll         $v0, $v1, 6
    ctx->pc = 0x1929c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 6));
    // 0x1929c8: 0xc0626f8  jal         func_189BE0
    ctx->pc = 0x1929C8u;
    SET_GPR_U32(ctx, 31, 0x1929D0u);
    ctx->pc = 0x1929CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1929C8u;
            // 0x1929cc: 0x2622021  addu        $a0, $s3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189BE0u;
    if (runtime->hasFunction(0x189BE0u)) {
        auto targetFn = runtime->lookupFunction(0x189BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1929D0u; }
        if (ctx->pc != 0x1929D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189BE0_0x189be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1929D0u; }
        if (ctx->pc != 0x1929D0u) { return; }
    }
    ctx->pc = 0x1929D0u;
label_1929d0:
    // 0x1929d0: 0x26100002  addiu       $s0, $s0, 0x2
    ctx->pc = 0x1929d0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
    // 0x1929d4: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1929d4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_1929d8:
    // 0x1929d8: 0x251182a  slt         $v1, $s2, $s1
    ctx->pc = 0x1929d8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x1929dc: 0x1460fff3  bnez        $v1, . + 4 + (-0xD << 2)
    ctx->pc = 0x1929DCu;
    {
        const bool branch_taken_0x1929dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1929dc) {
            ctx->pc = 0x1929ACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1929ac;
        }
    }
    ctx->pc = 0x1929E4u;
    // 0x1929e4: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1929e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1929e8: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1929e8u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1929ec: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1929ecu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1929f0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1929f0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1929f4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1929f4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1929f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1929F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1929FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1929F8u;
            // 0x1929fc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192748u: goto label_192748;
            case 0x1927A8u: goto label_1927a8;
            case 0x1927C0u: goto label_1927c0;
            case 0x1927E0u: goto label_1927e0;
            case 0x1927F0u: goto label_1927f0;
            case 0x192804u: goto label_192804;
            case 0x192858u: goto label_192858;
            case 0x192878u: goto label_192878;
            case 0x19288Cu: goto label_19288c;
            case 0x1928A0u: goto label_1928a0;
            case 0x1928B4u: goto label_1928b4;
            case 0x1928B8u: goto label_1928b8;
            case 0x192900u: goto label_192900;
            case 0x192918u: goto label_192918;
            case 0x19292Cu: goto label_19292c;
            case 0x192940u: goto label_192940;
            case 0x192954u: goto label_192954;
            case 0x192958u: goto label_192958;
            case 0x1929ACu: goto label_1929ac;
            case 0x1929D0u: goto label_1929d0;
            case 0x1929D8u: goto label_1929d8;
            case 0x192A20u: goto label_192a20;
            case 0x192A48u: goto label_192a48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192A00u;
    // 0x192a00: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x192a00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x192a04: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x192a04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x192a08: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x192a08u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x192a0c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x192a0cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x192a10: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x192a10u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192a14: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x192a14u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192a18: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x192A18u;
    SET_GPR_U32(ctx, 31, 0x192A20u);
    ctx->pc = 0x192A1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192A18u;
            // 0x192a1c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192A20u; }
        if (ctx->pc != 0x192A20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192A20u; }
        if (ctx->pc != 0x192A20u) { return; }
    }
    ctx->pc = 0x192A20u;
label_192a20:
    // 0x192a20: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x192a20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x192a24: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x192a24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192a28: 0xac224168  sw          $v0, 0x4168($at)
    ctx->pc = 0x192a28u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16744), GPR_U32(ctx, 2));
    // 0x192a2c: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x192a2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x192a30: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x192a30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x192a34: 0x8c224168  lw          $v0, 0x4168($at)
    ctx->pc = 0x192a34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16744)));
    // 0x192a38: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x192a38u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x192a3c: 0x622821  addu        $a1, $v1, $v0
    ctx->pc = 0x192a3cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x192a40: 0xc064a98  jal         func_192A60
    ctx->pc = 0x192A40u;
    SET_GPR_U32(ctx, 31, 0x192A48u);
    ctx->pc = 0x192A44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192A40u;
            // 0x192a44: 0xac30fe40  sw          $s0, -0x1C0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966848), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192A60u;
    if (runtime->hasFunction(0x192A60u)) {
        auto targetFn = runtime->lookupFunction(0x192A60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192A48u; }
        if (ctx->pc != 0x192A48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192A60_0x192a60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192A48u; }
        if (ctx->pc != 0x192A48u) { return; }
    }
    ctx->pc = 0x192A48u;
label_192a48:
    // 0x192a48: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x192a48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x192a4c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x192a4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x192a50: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x192a50u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x192a54: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x192a54u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x192a58: 0x3e00008  jr          $ra
    ctx->pc = 0x192A58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x192A5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192A58u;
            // 0x192a5c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192748u: goto label_192748;
            case 0x1927A8u: goto label_1927a8;
            case 0x1927C0u: goto label_1927c0;
            case 0x1927E0u: goto label_1927e0;
            case 0x1927F0u: goto label_1927f0;
            case 0x192804u: goto label_192804;
            case 0x192858u: goto label_192858;
            case 0x192878u: goto label_192878;
            case 0x19288Cu: goto label_19288c;
            case 0x1928A0u: goto label_1928a0;
            case 0x1928B4u: goto label_1928b4;
            case 0x1928B8u: goto label_1928b8;
            case 0x192900u: goto label_192900;
            case 0x192918u: goto label_192918;
            case 0x19292Cu: goto label_19292c;
            case 0x192940u: goto label_192940;
            case 0x192954u: goto label_192954;
            case 0x192958u: goto label_192958;
            case 0x1929ACu: goto label_1929ac;
            case 0x1929D0u: goto label_1929d0;
            case 0x1929D8u: goto label_1929d8;
            case 0x192A20u: goto label_192a20;
            case 0x192A48u: goto label_192a48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192A60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
