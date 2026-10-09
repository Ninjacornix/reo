#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193790
// Address: 0x193790 - 0x193880
void sub_00193790_0x193790(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193790_0x193790");
#endif

    switch (ctx->pc) {
        case 0x1937c4u: goto label_1937c4;
        case 0x1937f8u: goto label_1937f8;
        case 0x193808u: goto label_193808;
        case 0x193814u: goto label_193814;
        case 0x193840u: goto label_193840;
        case 0x19385cu: goto label_19385c;
        default: break;
    }

    ctx->pc = 0x193790u;

label_193790:
    // 0x193790: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x193790u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x193794: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x193794u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x193798: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x193798u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x19379c: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x19379cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1937a0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1937a0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1937a4: 0xe7b60008  swc1        $f22, 0x8($sp)
    ctx->pc = 0x1937a4u;
    { float f = ctx->f[22]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 8), bits); }
    // 0x1937a8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1937a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1937ac: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x1937acu;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x1937b0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1937b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1937b4: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x1937b4u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x1937b8: 0x46006586  mov.s       $f22, $f12
    ctx->pc = 0x1937b8u;
    ctx->f[22] = FPU_MOV_S(ctx->f[12]);
    // 0x1937bc: 0x46006d46  mov.s       $f21, $f13
    ctx->pc = 0x1937bcu;
    ctx->f[21] = FPU_MOV_S(ctx->f[13]);
    // 0x1937c0: 0x46007506  mov.s       $f20, $f14
    ctx->pc = 0x1937c0u;
    ctx->f[20] = FPU_MOV_S(ctx->f[14]);
label_1937c4:
    // 0x1937c4: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x1937c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1937c8: 0x2221821  addu        $v1, $s1, $v0
    ctx->pc = 0x1937c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1937cc: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1937ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1937d0: 0xc46000dc  lwc1        $f0, 0xDC($v1)
    ctx->pc = 0x1937d0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 220)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1937d4: 0x2882000a  slti        $v0, $a0, 0xA
    ctx->pc = 0x1937d4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x1937d8: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1937D8u;
    {
        const bool branch_taken_0x1937d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1937DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1937D8u;
            // 0x1937dc: 0xe4600104  swc1        $f0, 0x104($v1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 260), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1937d8) {
            ctx->pc = 0x1937C4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1937c4;
        }
    }
    ctx->pc = 0x1937E0u;
    // 0x1937e0: 0x26240040  addiu       $a0, $s1, 0x40
    ctx->pc = 0x1937e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 64));
    // 0x1937e4: 0x26250104  addiu       $a1, $s1, 0x104
    ctx->pc = 0x1937e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 260));
    // 0x1937e8: 0x4600b306  mov.s       $f12, $f22
    ctx->pc = 0x1937e8u;
    ctx->f[12] = FPU_MOV_S(ctx->f[22]);
    // 0x1937ec: 0x4600ab46  mov.s       $f13, $f21
    ctx->pc = 0x1937ecu;
    ctx->f[13] = FPU_MOV_S(ctx->f[21]);
    // 0x1937f0: 0xc064e80  jal         func_193A00
    ctx->pc = 0x1937F0u;
    SET_GPR_U32(ctx, 31, 0x1937F8u);
    ctx->pc = 0x1937F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1937F0u;
            // 0x1937f4: 0x4600a386  mov.s       $f14, $f20 (Delay Slot)
        ctx->f[14] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x193A00u;
    if (runtime->hasFunction(0x193A00u)) {
        auto targetFn = runtime->lookupFunction(0x193A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1937F8u; }
        if (ctx->pc != 0x1937F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193A00_0x193a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1937F8u; }
        if (ctx->pc != 0x1937F8u) { return; }
    }
    ctx->pc = 0x1937F8u;
label_1937f8:
    // 0x1937f8: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1937f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1937fc: 0x26250040  addiu       $a1, $s1, 0x40
    ctx->pc = 0x1937fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 64));
    // 0x193800: 0xc0644a0  jal         func_191280
    ctx->pc = 0x193800u;
    SET_GPR_U32(ctx, 31, 0x193808u);
    ctx->pc = 0x193804u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193800u;
            // 0x193804: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193808u; }
        if (ctx->pc != 0x193808u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193808u; }
        if (ctx->pc != 0x193808u) { return; }
    }
    ctx->pc = 0x193808u;
label_193808:
    // 0x193808: 0x26240080  addiu       $a0, $s1, 0x80
    ctx->pc = 0x193808u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 128));
    // 0x19380c: 0xc06450c  jal         func_191430
    ctx->pc = 0x19380Cu;
    SET_GPR_U32(ctx, 31, 0x193814u);
    ctx->pc = 0x193810u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19380Cu;
            // 0x193810: 0x27a50040  addiu       $a1, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191430u;
    if (runtime->hasFunction(0x191430u)) {
        auto targetFn = runtime->lookupFunction(0x191430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193814u; }
        if (ctx->pc != 0x193814u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191430_0x191430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193814u; }
        if (ctx->pc != 0x193814u) { return; }
    }
    ctx->pc = 0x193814u;
label_193814:
    // 0x193814: 0x8e2400d0  lw          $a0, 0xD0($s1)
    ctx->pc = 0x193814u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 208)));
    // 0x193818: 0x10800009  beqz        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x193818u;
    {
        const bool branch_taken_0x193818 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x193818) {
            ctx->pc = 0x193840u;
            goto label_193840;
        }
    }
    ctx->pc = 0x193820u;
    // 0x193820: 0xc6220104  lwc1        $f2, 0x104($s1)
    ctx->pc = 0x193820u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 260)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x193824: 0x27a50040  addiu       $a1, $sp, 0x40
    ctx->pc = 0x193824u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x193828: 0xc6210108  lwc1        $f1, 0x108($s1)
    ctx->pc = 0x193828u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 264)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19382c: 0xc620010c  lwc1        $f0, 0x10C($s1)
    ctx->pc = 0x19382cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 268)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193830: 0x4602b302  mul.s       $f12, $f22, $f2
    ctx->pc = 0x193830u;
    ctx->f[12] = FPU_MUL_S(ctx->f[22], ctx->f[2]);
    // 0x193834: 0x4601ab42  mul.s       $f13, $f21, $f1
    ctx->pc = 0x193834u;
    ctx->f[13] = FPU_MUL_S(ctx->f[21], ctx->f[1]);
    // 0x193838: 0xc064de4  jal         func_193790
    ctx->pc = 0x193838u;
    SET_GPR_U32(ctx, 31, 0x193840u);
    ctx->pc = 0x19383Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193838u;
            // 0x19383c: 0x4600a382  mul.s       $f14, $f20, $f0 (Delay Slot)
        ctx->f[14] = FPU_MUL_S(ctx->f[20], ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x193790u;
    goto label_193790;
    ctx->pc = 0x193840u;
label_193840:
    // 0x193840: 0x8e2400cc  lw          $a0, 0xCC($s1)
    ctx->pc = 0x193840u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 204)));
    // 0x193844: 0x10800005  beqz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x193844u;
    {
        const bool branch_taken_0x193844 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x193848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193844u;
            // 0x193848: 0x4600b306  mov.s       $f12, $f22 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[22]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x193844) {
            ctx->pc = 0x19385Cu;
            goto label_19385c;
        }
    }
    ctx->pc = 0x19384Cu;
    // 0x19384c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x19384cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193850: 0x4600ab46  mov.s       $f13, $f21
    ctx->pc = 0x193850u;
    ctx->f[13] = FPU_MOV_S(ctx->f[21]);
    // 0x193854: 0xc064de4  jal         func_193790
    ctx->pc = 0x193854u;
    SET_GPR_U32(ctx, 31, 0x19385Cu);
    ctx->pc = 0x193858u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193854u;
            // 0x193858: 0x4600a386  mov.s       $f14, $f20 (Delay Slot)
        ctx->f[14] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x193790u;
    goto label_193790;
    ctx->pc = 0x19385Cu;
label_19385c:
    // 0x19385c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19385cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x193860: 0xc7b60008  lwc1        $f22, 0x8($sp)
    ctx->pc = 0x193860u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[22] = f; }
    // 0x193864: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x193864u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x193868: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x193868u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x19386c: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x19386cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x193870: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x193870u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x193874: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x193874u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x193878: 0x3e00008  jr          $ra
    ctx->pc = 0x193878u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19387Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193878u;
            // 0x19387c: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193790u: goto label_193790;
            case 0x1937C4u: goto label_1937c4;
            case 0x1937F8u: goto label_1937f8;
            case 0x193808u: goto label_193808;
            case 0x193814u: goto label_193814;
            case 0x193840u: goto label_193840;
            case 0x19385Cu: goto label_19385c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x193880u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
