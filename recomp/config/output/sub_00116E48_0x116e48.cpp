#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00116E48
// Address: 0x116e48 - 0x116fd0
void sub_00116E48_0x116e48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00116E48_0x116e48");
#endif

    switch (ctx->pc) {
        case 0x116e78u: goto label_116e78;
        case 0x116ee0u: goto label_116ee0;
        case 0x116f04u: goto label_116f04;
        case 0x116fa8u: goto label_116fa8;
        default: break;
    }

    ctx->pc = 0x116e48u;

    // 0x116e48: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x116e48u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116e4c: 0xe0182d  daddu       $v1, $a3, $zero
    ctx->pc = 0x116e4cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116e50: 0x100582d  daddu       $t3, $t0, $zero
    ctx->pc = 0x116e50u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116e54: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x116e54u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x116e58: 0x120502d  daddu       $t2, $t1, $zero
    ctx->pc = 0x116e58u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116e5c: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x116e5cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116e60: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x116e60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x116e64: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x116e64u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116e68: 0x60402d  daddu       $t0, $v1, $zero
    ctx->pc = 0x116e68u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116e6c: 0x160482d  daddu       $t1, $t3, $zero
    ctx->pc = 0x116e6cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116e70: 0xc045b34  jal         func_116CD0
    ctx->pc = 0x116E70u;
    SET_GPR_U32(ctx, 31, 0x116E78u);
    ctx->pc = 0x116E74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116E70u;
            // 0x116e74: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116CD0u;
    if (runtime->hasFunction(0x116CD0u)) {
        auto targetFn = runtime->lookupFunction(0x116CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116E78u; }
        if (ctx->pc != 0x116E78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116CD0_0x116cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116E78u; }
        if (ctx->pc != 0x116E78u) { return; }
    }
    ctx->pc = 0x116E78u;
label_116e78:
    // 0x116e78: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x116e78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x116e7c: 0x3e00008  jr          $ra
    ctx->pc = 0x116E7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116E80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116E7Cu;
            // 0x116e80: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116E78u: goto label_116e78;
            case 0x116EE0u: goto label_116ee0;
            case 0x116EFCu: goto label_116efc;
            case 0x116F04u: goto label_116f04;
            case 0x116F5Cu: goto label_116f5c;
            case 0x116F98u: goto label_116f98;
            case 0x116FA8u: goto label_116fa8;
            case 0x116FB0u: goto label_116fb0;
            case 0x116FBCu: goto label_116fbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x116E84u;
    // 0x116e84: 0x0  nop
    ctx->pc = 0x116e84u;
    // NOP
    // 0x116e88: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x116e88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x116e8c: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x116e8cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x116e90: 0xffb10080  sd          $s1, 0x80($sp)
    ctx->pc = 0x116e90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 17));
    // 0x116e94: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x116e94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x116e98: 0x2471af98  addiu       $s1, $v1, -0x5068
    ctx->pc = 0x116e98u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 4294946712));
    // 0x116e9c: 0xffb00070  sd          $s0, 0x70($sp)
    ctx->pc = 0x116e9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 16));
    // 0x116ea0: 0x8c67af98  lw          $a3, -0x5068($v1)
    ctx->pc = 0x116ea0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294946712)));
    // 0x116ea4: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x116ea4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x116ea8: 0x304500ff  andi        $a1, $v0, 0xFF
    ctx->pc = 0x116ea8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x116eac: 0x10a00043  beqz        $a1, . + 4 + (0x43 << 2)
    ctx->pc = 0x116EACu;
    {
        const bool branch_taken_0x116eac = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x116EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116EACu;
            // 0x116eb0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116eac) {
            ctx->pc = 0x116FBCu;
            goto label_116fbc;
        }
    }
    ctx->pc = 0x116EB4u;
    // 0x116eb4: 0x24a2000f  addiu       $v0, $a1, 0xF
    ctx->pc = 0x116eb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 15));
    // 0x116eb8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x116eb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x116ebc: 0x24a4001e  addiu       $a0, $a1, 0x1E
    ctx->pc = 0x116ebcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 30));
    // 0x116ec0: 0x62182a  slt         $v1, $v1, $v0
    ctx->pc = 0x116ec0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x116ec4: 0x43200b  movn        $a0, $v0, $v1
    ctx->pc = 0x116ec4u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 2));
    // 0x116ec8: 0xe0302d  daddu       $a2, $a3, $zero
    ctx->pc = 0x116ec8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116ecc: 0x42903  sra         $a1, $a0, 4
    ctx->pc = 0x116eccu;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 4), 4));
    // 0x116ed0: 0xa0e00000  sb          $zero, 0x0($a3)
    ctx->pc = 0x116ed0u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x116ed4: 0x18a00009  blez        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x116ED4u;
    {
        const bool branch_taken_0x116ed4 = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x116ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116ED4u;
            // 0x116ed8: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116ed4) {
            ctx->pc = 0x116EFCu;
            goto label_116efc;
        }
    }
    ctx->pc = 0x116EDCu;
    // 0x116edc: 0x3a0182d  daddu       $v1, $sp, $zero
    ctx->pc = 0x116edcu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_116ee0:
    // 0x116ee0: 0x78c20000  lq          $v0, 0x0($a2)
    ctx->pc = 0x116ee0u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x116ee4: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x116ee4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x116ee8: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x116ee8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
    // 0x116eec: 0x7c620000  sq          $v0, 0x0($v1)
    ctx->pc = 0x116eecu;
    WRITE128(ADD32(GPR_U32(ctx, 3), 0), GPR_VEC(ctx, 2));
    // 0x116ef0: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x116ef0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x116ef4: 0x1480fffa  bnez        $a0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x116EF4u;
    {
        const bool branch_taken_0x116ef4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x116ef4) {
            ctx->pc = 0x116EE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116ee0;
        }
    }
    ctx->pc = 0x116EFCu;
label_116efc:
    // 0x116efc: 0xc045284  jal         func_114A10
    ctx->pc = 0x116EFCu;
    SET_GPR_U32(ctx, 31, 0x116F04u);
    ctx->pc = 0x114A10u;
    if (runtime->hasFunction(0x114A10u)) {
        auto targetFn = runtime->lookupFunction(0x114A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116F04u; }
        if (ctx->pc != 0x116F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A10_0x114a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116F04u; }
        if (ctx->pc != 0x116F04u) { return; }
    }
    ctx->pc = 0x116F04u;
label_116f04:
    // 0x116f04: 0x8fa30008  lw          $v1, 0x8($sp)
    ctx->pc = 0x116f04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x116f08: 0x4610014  bgez        $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x116F08u;
    {
        const bool branch_taken_0x116f08 = (GPR_S64(ctx, 3) >= 0);
        if (branch_taken_0x116f08) {
            ctx->pc = 0x116F5Cu;
            goto label_116f5c;
        }
    }
    ctx->pc = 0x116F10u;
    // 0x116f10: 0x8fa20008  lw          $v0, 0x8($sp)
    ctx->pc = 0x116f10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x116f14: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x116f14u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x116f18: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x116f18u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x116f1c: 0x8e240010  lw          $a0, 0x10($s1)
    ctx->pc = 0x116f1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x116f20: 0x432824  and         $a1, $v0, $v1
    ctx->pc = 0x116f20u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x116f24: 0xa4202a  slt         $a0, $a1, $a0
    ctx->pc = 0x116f24u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x116f28: 0x10800021  beqz        $a0, . + 4 + (0x21 << 2)
    ctx->pc = 0x116F28u;
    {
        const bool branch_taken_0x116f28 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x116F2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116F28u;
            // 0x116f2c: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116f28) {
            ctx->pc = 0x116FB0u;
            goto label_116fb0;
        }
    }
    ctx->pc = 0x116F30u;
    // 0x116f30: 0x8e23000c  lw          $v1, 0xC($s1)
    ctx->pc = 0x116f30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x116f34: 0xa22818  mult        $a1, $a1, $v0
    ctx->pc = 0x116f34u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x116f38: 0xa31021  addu        $v0, $a1, $v1
    ctx->pc = 0x116f38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x116f3c: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x116f3cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x116f40: 0x10c0001b  beqz        $a2, . + 4 + (0x1B << 2)
    ctx->pc = 0x116F40u;
    {
        const bool branch_taken_0x116f40 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x116f40) {
            ctx->pc = 0x116FB0u;
            goto label_116fb0;
        }
    }
    ctx->pc = 0x116F48u;
    // 0x116f48: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x116f48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x116f4c: 0x380802d  daddu       $s0, $gp, $zero
    ctx->pc = 0x116f4cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116f50: 0x60e02d  daddu       $gp, $v1, $zero
    ctx->pc = 0x116f50u;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116f54: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x116F54u;
    {
        const bool branch_taken_0x116f54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x116F58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116F54u;
            // 0x116f58: 0x8e22000c  lw          $v0, 0xC($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116f54) {
            ctx->pc = 0x116F98u;
            goto label_116f98;
        }
    }
    ctx->pc = 0x116F5Cu;
label_116f5c:
    // 0x116f5c: 0x8fa50008  lw          $a1, 0x8($sp)
    ctx->pc = 0x116f5cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x116f60: 0x8e220018  lw          $v0, 0x18($s1)
    ctx->pc = 0x116f60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x116f64: 0xa2102a  slt         $v0, $a1, $v0
    ctx->pc = 0x116f64u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x116f68: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x116F68u;
    {
        const bool branch_taken_0x116f68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x116F6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116F68u;
            // 0x116f6c: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116f68) {
            ctx->pc = 0x116FB0u;
            goto label_116fb0;
        }
    }
    ctx->pc = 0x116F70u;
    // 0x116f70: 0x8e230014  lw          $v1, 0x14($s1)
    ctx->pc = 0x116f70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x116f74: 0xa22818  mult        $a1, $a1, $v0
    ctx->pc = 0x116f74u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x116f78: 0xa31021  addu        $v0, $a1, $v1
    ctx->pc = 0x116f78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x116f7c: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x116f7cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x116f80: 0x10c0000b  beqz        $a2, . + 4 + (0xB << 2)
    ctx->pc = 0x116F80u;
    {
        const bool branch_taken_0x116f80 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x116f80) {
            ctx->pc = 0x116FB0u;
            goto label_116fb0;
        }
    }
    ctx->pc = 0x116F88u;
    // 0x116f88: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x116f88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x116f8c: 0x380802d  daddu       $s0, $gp, $zero
    ctx->pc = 0x116f8cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116f90: 0x60e02d  daddu       $gp, $v1, $zero
    ctx->pc = 0x116f90u;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116f94: 0x8e220014  lw          $v0, 0x14($s1)
    ctx->pc = 0x116f94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
label_116f98:
    // 0x116f98: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x116f98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116f9c: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x116f9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x116fa0: 0xc0f809  jalr        $a2
    ctx->pc = 0x116FA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 6);
        SET_GPR_U32(ctx, 31, 0x116FA8u);
        ctx->pc = 0x116FA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116FA0u;
            // 0x116fa4: 0x8c450004  lw          $a1, 0x4($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x116FA8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116E78u: goto label_116e78;
            case 0x116EE0u: goto label_116ee0;
            case 0x116EFCu: goto label_116efc;
            case 0x116F04u: goto label_116f04;
            case 0x116F5Cu: goto label_116f5c;
            case 0x116F98u: goto label_116f98;
            case 0x116FA8u: goto label_116fa8;
            case 0x116FB0u: goto label_116fb0;
            case 0x116FBCu: goto label_116fbc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x116FA8u; }
            if (ctx->pc != 0x116FA8u) { return; }
        }
        }
    }
    ctx->pc = 0x116FA8u;
label_116fa8:
    // 0x116fa8: 0x380102d  daddu       $v0, $gp, $zero
    ctx->pc = 0x116fa8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116fac: 0x200e02d  daddu       $gp, $s0, $zero
    ctx->pc = 0x116facu;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_116fb0:
    // 0x116fb0: 0xf  sync
    ctx->pc = 0x116fb0u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x116fb4: 0x42000038  ei
    ctx->pc = 0x116fb4u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x116fb8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x116fb8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_116fbc:
    // 0x116fbc: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x116fbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x116fc0: 0xdfb10080  ld          $s1, 0x80($sp)
    ctx->pc = 0x116fc0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x116fc4: 0xdfb00070  ld          $s0, 0x70($sp)
    ctx->pc = 0x116fc4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x116fc8: 0x3e00008  jr          $ra
    ctx->pc = 0x116FC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116FCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116FC8u;
            // 0x116fcc: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116E78u: goto label_116e78;
            case 0x116EE0u: goto label_116ee0;
            case 0x116EFCu: goto label_116efc;
            case 0x116F04u: goto label_116f04;
            case 0x116F5Cu: goto label_116f5c;
            case 0x116F98u: goto label_116f98;
            case 0x116FA8u: goto label_116fa8;
            case 0x116FB0u: goto label_116fb0;
            case 0x116FBCu: goto label_116fbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x116FD0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
