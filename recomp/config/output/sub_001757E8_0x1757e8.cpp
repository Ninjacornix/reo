#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001757E8
// Address: 0x1757e8 - 0x1758f0
void sub_001757E8_0x1757e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001757E8_0x1757e8");
#endif

    switch (ctx->pc) {
        case 0x175804u: goto label_175804;
        case 0x175834u: goto label_175834;
        case 0x175878u: goto label_175878;
        default: break;
    }

    ctx->pc = 0x1757e8u;

    // 0x1757e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1757e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1757ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1757ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1757f0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1757f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1757f4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1757f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1757f8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1757f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1757fc: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1757FCu;
    SET_GPR_U32(ctx, 31, 0x175804u);
    ctx->pc = 0x175800u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1757FCu;
            // 0x175800: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175804u; }
        if (ctx->pc != 0x175804u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175804u; }
        if (ctx->pc != 0x175804u) { return; }
    }
    ctx->pc = 0x175804u;
label_175804:
    // 0x175804: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x175804u;
    {
        const bool branch_taken_0x175804 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x175808u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175804u;
            // 0x175808: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175804) {
            ctx->pc = 0x175828u;
            goto label_175828;
        }
    }
    ctx->pc = 0x17580Cu;
    // 0x17580c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x17580cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x175810: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175810u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x175814: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x175814u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x175818: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x175818u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17581c: 0x34a5011a  ori         $a1, $a1, 0x11A
    ctx->pc = 0x17581cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)282);
    // 0x175820: 0x805a704  j           func_169C10
    ctx->pc = 0x175820u;
    ctx->pc = 0x175824u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175820u;
            // 0x175824: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x175828u;
label_175828:
    // 0x175828: 0x26232b80  addiu       $v1, $s1, 0x2B80
    ctx->pc = 0x175828u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 11136));
    // 0x17582c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x17582cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175830: 0x26242ac0  addiu       $a0, $s1, 0x2AC0
    ctx->pc = 0x175830u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 10944));
label_175834:
    // 0x175834: 0xdc850000  ld          $a1, 0x0($a0)
    ctx->pc = 0x175834u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x175838: 0xdc860008  ld          $a2, 0x8($a0)
    ctx->pc = 0x175838u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x17583c: 0xdc870010  ld          $a3, 0x10($a0)
    ctx->pc = 0x17583cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x175840: 0xdc880018  ld          $t0, 0x18($a0)
    ctx->pc = 0x175840u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x175844: 0xfc450000  sd          $a1, 0x0($v0)
    ctx->pc = 0x175844u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 5));
    // 0x175848: 0xfc460008  sd          $a2, 0x8($v0)
    ctx->pc = 0x175848u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 6));
    // 0x17584c: 0xfc470010  sd          $a3, 0x10($v0)
    ctx->pc = 0x17584cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 16), GPR_U64(ctx, 7));
    // 0x175850: 0xfc480018  sd          $t0, 0x18($v0)
    ctx->pc = 0x175850u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 24), GPR_U64(ctx, 8));
    // 0x175854: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x175854u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x175858: 0x0  nop
    ctx->pc = 0x175858u;
    // NOP
    // 0x17585c: 0x0  nop
    ctx->pc = 0x17585cu;
    // NOP
    // 0x175860: 0x1483fff4  bne         $a0, $v1, . + 4 + (-0xC << 2)
    ctx->pc = 0x175860u;
    {
        const bool branch_taken_0x175860 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x175864u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175860u;
            // 0x175864: 0x24420020  addiu       $v0, $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175860) {
            ctx->pc = 0x175834u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_175834;
        }
    }
    ctx->pc = 0x175868u;
    // 0x175868: 0x260c0008  addiu       $t4, $s0, 0x8
    ctx->pc = 0x175868u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x17586c: 0x240a0001  addiu       $t2, $zero, 0x1
    ctx->pc = 0x17586cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x175870: 0x180582d  daddu       $t3, $t4, $zero
    ctx->pc = 0x175870u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175874: 0x26090030  addiu       $t1, $s0, 0x30
    ctx->pc = 0x175874u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 48));
label_175878:
    // 0x175878: 0xdd23fff0  ld          $v1, -0x10($t1)
    ctx->pc = 0x175878u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 9), 4294967280)));
    // 0x17587c: 0xa3140  sll         $a2, $t2, 5
    ctx->pc = 0x17587cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 10), 5));
    // 0x175880: 0xde020000  ld          $v0, 0x0($s0)
    ctx->pc = 0x175880u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x175884: 0x1663021  addu        $a2, $t3, $a2
    ctx->pc = 0x175884u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 6)));
    // 0x175888: 0x8d270008  lw          $a3, 0x8($t1)
    ctx->pc = 0x175888u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x17588c: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x17588cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x175890: 0x43102d  daddu       $v0, $v0, $v1
    ctx->pc = 0x175890u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 3));
    // 0x175894: 0x8e040018  lw          $a0, 0x18($s0)
    ctx->pc = 0x175894u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x175898: 0xfe020000  sd          $v0, 0x0($s0)
    ctx->pc = 0x175898u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 0), GPR_U64(ctx, 2));
    // 0x17589c: 0x29480004  slti        $t0, $t2, 0x4
    ctx->pc = 0x17589cu;
    SET_GPR_U64(ctx, 8, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1758a0: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x1758a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1758a4: 0xdcc50000  ld          $a1, 0x0($a2)
    ctx->pc = 0x1758a4u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1758a8: 0xdd630000  ld          $v1, 0x0($t3)
    ctx->pc = 0x1758a8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x1758ac: 0xae040018  sw          $a0, 0x18($s0)
    ctx->pc = 0x1758acu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 4));
    // 0x1758b0: 0xa3102a  slt         $v0, $a1, $v1
    ctx->pc = 0x1758b0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1758b4: 0xa2180b  movn        $v1, $a1, $v0
    ctx->pc = 0x1758b4u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 5));
    // 0x1758b8: 0xfd830000  sd          $v1, 0x0($t4)
    ctx->pc = 0x1758b8u;
    WRITE64(ADD32(GPR_U32(ctx, 12), 0), GPR_U64(ctx, 3));
    // 0x1758bc: 0xdd240000  ld          $a0, 0x0($t1)
    ctx->pc = 0x1758bcu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1758c0: 0x25290020  addiu       $t1, $t1, 0x20
    ctx->pc = 0x1758c0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 32));
    // 0x1758c4: 0xde020010  ld          $v0, 0x10($s0)
    ctx->pc = 0x1758c4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1758c8: 0x44182a  slt         $v1, $v0, $a0
    ctx->pc = 0x1758c8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1758cc: 0x83100b  movn        $v0, $a0, $v1
    ctx->pc = 0x1758ccu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x1758d0: 0x1500ffe9  bnez        $t0, . + 4 + (-0x17 << 2)
    ctx->pc = 0x1758D0u;
    {
        const bool branch_taken_0x1758d0 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x1758D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1758D0u;
            // 0x1758d4: 0xfe020010  sd          $v0, 0x10($s0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 16), 16), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1758d0) {
            ctx->pc = 0x175878u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_175878;
        }
    }
    ctx->pc = 0x1758D8u;
    // 0x1758d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1758d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1758dc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1758dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1758e0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1758e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1758e4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1758e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1758e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1758E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1758ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1758E8u;
            // 0x1758ec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x175804u: goto label_175804;
            case 0x175828u: goto label_175828;
            case 0x175834u: goto label_175834;
            case 0x175878u: goto label_175878;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1758F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
