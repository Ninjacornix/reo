#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001938A0
// Address: 0x1938a0 - 0x1939a0
void sub_001938A0_0x1938a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001938A0_0x1938a0");
#endif

    switch (ctx->pc) {
        case 0x1938d4u: goto label_1938d4;
        case 0x1938fcu: goto label_1938fc;
        case 0x193914u: goto label_193914;
        case 0x193924u: goto label_193924;
        case 0x193930u: goto label_193930;
        case 0x19395cu: goto label_19395c;
        case 0x193978u: goto label_193978;
        default: break;
    }

    ctx->pc = 0x1938a0u;

label_1938a0:
    // 0x1938a0: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x1938a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x1938a4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1938a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1938a8: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x1938a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x1938ac: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1938acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1938b0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1938b0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1938b4: 0xe7b60008  swc1        $f22, 0x8($sp)
    ctx->pc = 0x1938b4u;
    { float f = ctx->f[22]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 8), bits); }
    // 0x1938b8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1938b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1938bc: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x1938bcu;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x1938c0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1938c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1938c4: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x1938c4u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x1938c8: 0x46006586  mov.s       $f22, $f12
    ctx->pc = 0x1938c8u;
    ctx->f[22] = FPU_MOV_S(ctx->f[12]);
    // 0x1938cc: 0x46006d46  mov.s       $f21, $f13
    ctx->pc = 0x1938ccu;
    ctx->f[21] = FPU_MOV_S(ctx->f[13]);
    // 0x1938d0: 0x46007506  mov.s       $f20, $f14
    ctx->pc = 0x1938d0u;
    ctx->f[20] = FPU_MOV_S(ctx->f[14]);
label_1938d4:
    // 0x1938d4: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x1938d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1938d8: 0x2221821  addu        $v1, $s1, $v0
    ctx->pc = 0x1938d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1938dc: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1938dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1938e0: 0xc46000dc  lwc1        $f0, 0xDC($v1)
    ctx->pc = 0x1938e0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 220)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1938e4: 0x2882000a  slti        $v0, $a0, 0xA
    ctx->pc = 0x1938e4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x1938e8: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1938E8u;
    {
        const bool branch_taken_0x1938e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1938ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1938E8u;
            // 0x1938ec: 0xe4600104  swc1        $f0, 0x104($v1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 260), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1938e8) {
            ctx->pc = 0x1938D4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1938d4;
        }
    }
    ctx->pc = 0x1938F0u;
    // 0x1938f0: 0x26240040  addiu       $a0, $s1, 0x40
    ctx->pc = 0x1938f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 64));
    // 0x1938f4: 0xc064e68  jal         func_1939A0
    ctx->pc = 0x1938F4u;
    SET_GPR_U32(ctx, 31, 0x1938FCu);
    ctx->pc = 0x1938F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1938F4u;
            // 0x1938f8: 0x26250104  addiu       $a1, $s1, 0x104 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 260));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1939A0u;
    if (runtime->hasFunction(0x1939A0u)) {
        auto targetFn = runtime->lookupFunction(0x1939A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1938FCu; }
        if (ctx->pc != 0x1938FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001939A0_0x1939a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1938FCu; }
        if (ctx->pc != 0x1938FCu) { return; }
    }
    ctx->pc = 0x1938FCu;
label_1938fc:
    // 0x1938fc: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1938fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x193900: 0x26250104  addiu       $a1, $s1, 0x104
    ctx->pc = 0x193900u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 260));
    // 0x193904: 0x4600b306  mov.s       $f12, $f22
    ctx->pc = 0x193904u;
    ctx->f[12] = FPU_MOV_S(ctx->f[22]);
    // 0x193908: 0x4600ab46  mov.s       $f13, $f21
    ctx->pc = 0x193908u;
    ctx->f[13] = FPU_MOV_S(ctx->f[21]);
    // 0x19390c: 0xc064ebc  jal         func_193AF0
    ctx->pc = 0x19390Cu;
    SET_GPR_U32(ctx, 31, 0x193914u);
    ctx->pc = 0x193910u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19390Cu;
            // 0x193910: 0x4600a386  mov.s       $f14, $f20 (Delay Slot)
        ctx->f[14] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x193AF0u;
    if (runtime->hasFunction(0x193AF0u)) {
        auto targetFn = runtime->lookupFunction(0x193AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193914u; }
        if (ctx->pc != 0x193914u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193AF0_0x193af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193914u; }
        if (ctx->pc != 0x193914u) { return; }
    }
    ctx->pc = 0x193914u;
label_193914:
    // 0x193914: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x193914u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x193918: 0x27a50040  addiu       $a1, $sp, 0x40
    ctx->pc = 0x193918u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x19391c: 0xc0644a0  jal         func_191280
    ctx->pc = 0x19391Cu;
    SET_GPR_U32(ctx, 31, 0x193924u);
    ctx->pc = 0x193920u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19391Cu;
            // 0x193920: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193924u; }
        if (ctx->pc != 0x193924u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193924u; }
        if (ctx->pc != 0x193924u) { return; }
    }
    ctx->pc = 0x193924u;
label_193924:
    // 0x193924: 0x26240080  addiu       $a0, $s1, 0x80
    ctx->pc = 0x193924u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 128));
    // 0x193928: 0xc06450c  jal         func_191430
    ctx->pc = 0x193928u;
    SET_GPR_U32(ctx, 31, 0x193930u);
    ctx->pc = 0x19392Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193928u;
            // 0x19392c: 0x27a50080  addiu       $a1, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191430u;
    if (runtime->hasFunction(0x191430u)) {
        auto targetFn = runtime->lookupFunction(0x191430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193930u; }
        if (ctx->pc != 0x193930u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191430_0x191430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193930u; }
        if (ctx->pc != 0x193930u) { return; }
    }
    ctx->pc = 0x193930u;
label_193930:
    // 0x193930: 0x8e2400d0  lw          $a0, 0xD0($s1)
    ctx->pc = 0x193930u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 208)));
    // 0x193934: 0x10800009  beqz        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x193934u;
    {
        const bool branch_taken_0x193934 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x193934) {
            ctx->pc = 0x19395Cu;
            goto label_19395c;
        }
    }
    ctx->pc = 0x19393Cu;
    // 0x19393c: 0xc6220104  lwc1        $f2, 0x104($s1)
    ctx->pc = 0x19393cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 260)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x193940: 0x27a50080  addiu       $a1, $sp, 0x80
    ctx->pc = 0x193940u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x193944: 0xc6210108  lwc1        $f1, 0x108($s1)
    ctx->pc = 0x193944u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 264)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x193948: 0xc620010c  lwc1        $f0, 0x10C($s1)
    ctx->pc = 0x193948u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 268)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19394c: 0x4602b302  mul.s       $f12, $f22, $f2
    ctx->pc = 0x19394cu;
    ctx->f[12] = FPU_MUL_S(ctx->f[22], ctx->f[2]);
    // 0x193950: 0x4601ab42  mul.s       $f13, $f21, $f1
    ctx->pc = 0x193950u;
    ctx->f[13] = FPU_MUL_S(ctx->f[21], ctx->f[1]);
    // 0x193954: 0xc064e28  jal         func_1938A0
    ctx->pc = 0x193954u;
    SET_GPR_U32(ctx, 31, 0x19395Cu);
    ctx->pc = 0x193958u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193954u;
            // 0x193958: 0x4600a382  mul.s       $f14, $f20, $f0 (Delay Slot)
        ctx->f[14] = FPU_MUL_S(ctx->f[20], ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1938A0u;
    goto label_1938a0;
    ctx->pc = 0x19395Cu;
label_19395c:
    // 0x19395c: 0x8e2400cc  lw          $a0, 0xCC($s1)
    ctx->pc = 0x19395cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 204)));
    // 0x193960: 0x10800005  beqz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x193960u;
    {
        const bool branch_taken_0x193960 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x193964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193960u;
            // 0x193964: 0x4600b306  mov.s       $f12, $f22 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[22]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x193960) {
            ctx->pc = 0x193978u;
            goto label_193978;
        }
    }
    ctx->pc = 0x193968u;
    // 0x193968: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x193968u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19396c: 0x4600ab46  mov.s       $f13, $f21
    ctx->pc = 0x19396cu;
    ctx->f[13] = FPU_MOV_S(ctx->f[21]);
    // 0x193970: 0xc064e28  jal         func_1938A0
    ctx->pc = 0x193970u;
    SET_GPR_U32(ctx, 31, 0x193978u);
    ctx->pc = 0x193974u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193970u;
            // 0x193974: 0x4600a386  mov.s       $f14, $f20 (Delay Slot)
        ctx->f[14] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1938A0u;
    goto label_1938a0;
    ctx->pc = 0x193978u;
label_193978:
    // 0x193978: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x193978u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19397c: 0xc7b60008  lwc1        $f22, 0x8($sp)
    ctx->pc = 0x19397cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[22] = f; }
    // 0x193980: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x193980u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x193984: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x193984u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x193988: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x193988u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19398c: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x19398cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x193990: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x193990u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x193994: 0x3e00008  jr          $ra
    ctx->pc = 0x193994u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x193998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193994u;
            // 0x193998: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1938A0u: goto label_1938a0;
            case 0x1938D4u: goto label_1938d4;
            case 0x1938FCu: goto label_1938fc;
            case 0x193914u: goto label_193914;
            case 0x193924u: goto label_193924;
            case 0x193930u: goto label_193930;
            case 0x19395Cu: goto label_19395c;
            case 0x193978u: goto label_193978;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19399Cu;
    // 0x19399c: 0x0  nop
    ctx->pc = 0x19399cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
