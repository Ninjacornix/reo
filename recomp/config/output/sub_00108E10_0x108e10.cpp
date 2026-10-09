#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00108E10
// Address: 0x108e10 - 0x108ed0
void sub_00108E10_0x108e10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00108E10_0x108e10");
#endif

    switch (ctx->pc) {
        case 0x108e40u: goto label_108e40;
        case 0x108ec0u: goto label_108ec0;
        default: break;
    }

    ctx->pc = 0x108e10u;

    // 0x108e10: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x108e10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x108e14: 0x3c020037  lui         $v0, 0x37
    ctx->pc = 0x108e14u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)55 << 16));
    // 0x108e18: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x108e18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x108e1c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x108e1cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108e20: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x108e20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x108e24: 0x2451f0dc  addiu       $s1, $v0, -0xF24
    ctx->pc = 0x108e24u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963420));
    // 0x108e28: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x108e28u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108e2c: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x108e2cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108e30: 0xe0302d  daddu       $a2, $a3, $zero
    ctx->pc = 0x108e30u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108e34: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x108e34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x108e38: 0xc045338  jal         func_114CE0
    ctx->pc = 0x108E38u;
    SET_GPR_U32(ctx, 31, 0x108E40u);
    ctx->pc = 0x108E3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x108E38u;
            // 0x108e3c: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114CE0u;
    if (runtime->hasFunction(0x114CE0u)) {
        auto targetFn = runtime->lookupFunction(0x114CE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108E40u; }
        if (ctx->pc != 0x108E40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114CE0_0x114ce0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108E40u; }
        if (ctx->pc != 0x108E40u) { return; }
    }
    ctx->pc = 0x108E40u;
label_108e40:
    // 0x108e40: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x108e40u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108e44: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x108e44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x108e48: 0x54830005  bnel        $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x108E48u;
    {
        const bool branch_taken_0x108e48 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x108e48) {
            ctx->pc = 0x108E4Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x108E48u;
            // 0x108e4c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x108E60u;
            goto label_108e60;
        }
    }
    ctx->pc = 0x108E50u;
    // 0x108e50: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x108e50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x108e54: 0x54600001  bnel        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x108E54u;
    {
        const bool branch_taken_0x108e54 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x108e54) {
            ctx->pc = 0x108E58u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x108E54u;
            // 0x108e58: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x108E5Cu;
            goto label_108e5c;
        }
    }
    ctx->pc = 0x108E5Cu;
label_108e5c:
    // 0x108e5c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x108e5cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_108e60:
    // 0x108e60: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x108e60u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x108e64: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x108e64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x108e68: 0x3e00008  jr          $ra
    ctx->pc = 0x108E68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x108E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108E68u;
            // 0x108e6c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108E40u: goto label_108e40;
            case 0x108E5Cu: goto label_108e5c;
            case 0x108E60u: goto label_108e60;
            case 0x108EC0u: goto label_108ec0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x108E70u;
    // 0x108e70: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x108e70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x108e74: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x108e74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x108e78: 0xffa60030  sd          $a2, 0x30($sp)
    ctx->pc = 0x108e78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 6));
    // 0x108e7c: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x108e7cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108e80: 0xffa70038  sd          $a3, 0x38($sp)
    ctx->pc = 0x108e80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 7));
    // 0x108e84: 0x27a70030  addiu       $a3, $sp, 0x30
    ctx->pc = 0x108e84u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x108e88: 0xffa80040  sd          $t0, 0x40($sp)
    ctx->pc = 0x108e88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 8));
    // 0x108e8c: 0xffa90048  sd          $t1, 0x48($sp)
    ctx->pc = 0x108e8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 9));
    // 0x108e90: 0xffaa0050  sd          $t2, 0x50($sp)
    ctx->pc = 0x108e90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 10));
    // 0x108e94: 0xffab0058  sd          $t3, 0x58($sp)
    ctx->pc = 0x108e94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 11));
    // 0x108e98: 0xe7ac0010  swc1        $f12, 0x10($sp)
    ctx->pc = 0x108e98u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 16), bits); }
    // 0x108e9c: 0xe7ad0014  swc1        $f13, 0x14($sp)
    ctx->pc = 0x108e9cu;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 20), bits); }
    // 0x108ea0: 0xe7ae0018  swc1        $f14, 0x18($sp)
    ctx->pc = 0x108ea0u;
    { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 24), bits); }
    // 0x108ea4: 0xe7af001c  swc1        $f15, 0x1C($sp)
    ctx->pc = 0x108ea4u;
    { float f = ctx->f[15]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 28), bits); }
    // 0x108ea8: 0xe7b00020  swc1        $f16, 0x20($sp)
    ctx->pc = 0x108ea8u;
    { float f = ctx->f[16]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 32), bits); }
    // 0x108eac: 0xe7b10024  swc1        $f17, 0x24($sp)
    ctx->pc = 0x108eacu;
    { float f = ctx->f[17]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 36), bits); }
    // 0x108eb0: 0xe7b20028  swc1        $f18, 0x28($sp)
    ctx->pc = 0x108eb0u;
    { float f = ctx->f[18]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
    // 0x108eb4: 0xe7b3002c  swc1        $f19, 0x2C($sp)
    ctx->pc = 0x108eb4u;
    { float f = ctx->f[19]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 44), bits); }
    // 0x108eb8: 0xc043478  jal         func_10D1E0
    ctx->pc = 0x108EB8u;
    SET_GPR_U32(ctx, 31, 0x108EC0u);
    ctx->pc = 0x108EBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x108EB8u;
            // 0x108ebc: 0x8c850008  lw          $a1, 0x8($a0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D1E0u;
    if (runtime->hasFunction(0x10D1E0u)) {
        auto targetFn = runtime->lookupFunction(0x10D1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108EC0u; }
        if (ctx->pc != 0x108EC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D1E0_0x10d1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108EC0u; }
        if (ctx->pc != 0x108EC0u) { return; }
    }
    ctx->pc = 0x108EC0u;
label_108ec0:
    // 0x108ec0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x108ec0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x108ec4: 0x3e00008  jr          $ra
    ctx->pc = 0x108EC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x108EC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108EC4u;
            // 0x108ec8: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108E40u: goto label_108e40;
            case 0x108E5Cu: goto label_108e5c;
            case 0x108E60u: goto label_108e60;
            case 0x108EC0u: goto label_108ec0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x108ECCu;
    // 0x108ecc: 0x0  nop
    ctx->pc = 0x108eccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
