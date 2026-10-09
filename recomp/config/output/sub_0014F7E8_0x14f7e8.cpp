#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0014F7E8
// Address: 0x14f7e8 - 0x14f908
void sub_0014F7E8_0x14f7e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0014F7E8_0x14f7e8");
#endif

    switch (ctx->pc) {
        case 0x14f868u: goto label_14f868;
        case 0x14f898u: goto label_14f898;
        case 0x14f8b8u: goto label_14f8b8;
        default: break;
    }

    ctx->pc = 0x14f7e8u;

    // 0x14f7e8: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x14f7e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x14f7ec: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x14f7ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x14f7f0: 0xa82d  daddu       $s5, $zero, $zero
    ctx->pc = 0x14f7f0u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f7f4: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x14f7f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x14f7f8: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x14f7f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x14f7fc: 0xa0b82d  daddu       $s7, $a1, $zero
    ctx->pc = 0x14f7fcu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f800: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x14f800u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x14f804: 0x80f02d  daddu       $fp, $a0, $zero
    ctx->pc = 0x14f804u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f808: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x14f808u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x14f80c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x14f80cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x14f810: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x14f810u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x14f814: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x14f814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x14f818: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x14f818u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x14f81c: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x14f81cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x14f820: 0x8ee30004  lw          $v1, 0x4($s7)
    ctx->pc = 0x14f820u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 4)));
    // 0x14f824: 0xafa60000  sw          $a2, 0x0($sp)
    ctx->pc = 0x14f824u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 6));
    // 0x14f828: 0x2465000f  addiu       $a1, $v1, 0xF
    ctx->pc = 0x14f828u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 15));
    // 0x14f82c: 0x28620000  slti        $v0, $v1, 0x0
    ctx->pc = 0x14f82cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x14f830: 0x8ee40008  lw          $a0, 0x8($s7)
    ctx->pc = 0x14f830u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 8)));
    // 0x14f834: 0xa2180b  movn        $v1, $a1, $v0
    ctx->pc = 0x14f834u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 5));
    // 0x14f838: 0x31903  sra         $v1, $v1, 4
    ctx->pc = 0x14f838u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 4));
    // 0x14f83c: 0xafa30004  sw          $v1, 0x4($sp)
    ctx->pc = 0x14f83cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
    // 0x14f840: 0x2486000f  addiu       $a2, $a0, 0xF
    ctx->pc = 0x14f840u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 15));
    // 0x14f844: 0x28820000  slti        $v0, $a0, 0x0
    ctx->pc = 0x14f844u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x14f848: 0xc2200b  movn        $a0, $a2, $v0
    ctx->pc = 0x14f848u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 6));
    // 0x14f84c: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x14f84cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x14f850: 0x4b103  sra         $s6, $a0, 4
    ctx->pc = 0x14f850u;
    SET_GPR_S32(ctx, 22, SRA32(GPR_S32(ctx, 4), 4));
    // 0x14f854: 0x1860001f  blez        $v1, . + 4 + (0x1F << 2)
    ctx->pc = 0x14F854u;
    {
        const bool branch_taken_0x14f854 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x14F858u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14F854u;
            // 0x14f858: 0x8ef4000c  lw          $s4, 0xC($s7) (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14f854) {
            ctx->pc = 0x14F8D4u;
            goto label_14f8d4;
        }
    }
    ctx->pc = 0x14F85Cu;
    // 0x14f85c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x14F85Cu;
    {
        const bool branch_taken_0x14f85c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x14F860u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14F85Cu;
            // 0x14f860: 0x8fc30008  lw          $v1, 0x8($fp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14f85c) {
            ctx->pc = 0x14F870u;
            goto label_14f870;
        }
    }
    ctx->pc = 0x14F864u;
    // 0x14f864: 0x0  nop
    ctx->pc = 0x14f864u;
    // NOP
label_14f868:
    // 0x14f868: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x14f868u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x14f86c: 0x0  nop
    ctx->pc = 0x14f86cu;
    // NOP
label_14f870:
    // 0x14f870: 0x751818  mult        $v1, $v1, $s5
    ctx->pc = 0x14f870u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 21); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x14f874: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x14f874u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x14f878: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x14f878u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x14f87c: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x14f87cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x14f880: 0x1ac0000f  blez        $s6, . + 4 + (0xF << 2)
    ctx->pc = 0x14F880u;
    {
        const bool branch_taken_0x14f880 = (GPR_S64(ctx, 22) <= 0);
        ctx->pc = 0x14F884u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14F880u;
            // 0x14f884: 0xa29021  addu        $s2, $a1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14f880) {
            ctx->pc = 0x14F8C0u;
            goto label_14f8c0;
        }
    }
    ctx->pc = 0x14F888u;
    // 0x14f888: 0x158980  sll         $s1, $s5, 6
    ctx->pc = 0x14f888u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 21), 6));
    // 0x14f88c: 0x149900  sll         $s3, $s4, 4
    ctx->pc = 0x14f88cu;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 20), 4));
    // 0x14f890: 0x2c0802d  daddu       $s0, $s6, $zero
    ctx->pc = 0x14f890u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f894: 0x0  nop
    ctx->pc = 0x14f894u;
    // NOP
label_14f898:
    // 0x14f898: 0x8ee60000  lw          $a2, 0x0($s7)
    ctx->pc = 0x14f898u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 0)));
    // 0x14f89c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x14f89cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f8a0: 0x8fa70000  lw          $a3, 0x0($sp)
    ctx->pc = 0x14f8a0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14f8a4: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x14f8a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f8a8: 0x2263021  addu        $a2, $s1, $a2
    ctx->pc = 0x14f8a8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 6)));
    // 0x14f8ac: 0x2338821  addu        $s1, $s1, $s3
    ctx->pc = 0x14f8acu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 19)));
    // 0x14f8b0: 0xc0533ee  jal         func_14CFB8
    ctx->pc = 0x14F8B0u;
    SET_GPR_U32(ctx, 31, 0x14F8B8u);
    ctx->pc = 0x14F8B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14F8B0u;
            // 0x14f8b4: 0x2610ffff  addiu       $s0, $s0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14CFB8u;
    if (runtime->hasFunction(0x14CFB8u)) {
        auto targetFn = runtime->lookupFunction(0x14CFB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F8B8u; }
        if (ctx->pc != 0x14F8B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0014CFB8_0x14cfb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F8B8u; }
        if (ctx->pc != 0x14F8B8u) { return; }
    }
    ctx->pc = 0x14F8B8u;
label_14f8b8:
    // 0x14f8b8: 0x1600fff7  bnez        $s0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x14F8B8u;
    {
        const bool branch_taken_0x14f8b8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x14F8BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14F8B8u;
            // 0x14f8bc: 0x26520180  addiu       $s2, $s2, 0x180 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 384));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14f8b8) {
            ctx->pc = 0x14F898u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14f898;
        }
    }
    ctx->pc = 0x14F8C0u;
label_14f8c0:
    // 0x14f8c0: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x14f8c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x14f8c4: 0x26b50001  addiu       $s5, $s5, 0x1
    ctx->pc = 0x14f8c4u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
    // 0x14f8c8: 0x2a3102a  slt         $v0, $s5, $v1
    ctx->pc = 0x14f8c8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x14f8cc: 0x5440ffe6  bnel        $v0, $zero, . + 4 + (-0x1A << 2)
    ctx->pc = 0x14F8CCu;
    {
        const bool branch_taken_0x14f8cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x14f8cc) {
            ctx->pc = 0x14F8D0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x14F8CCu;
            // 0x14f8d0: 0x8fc50000  lw          $a1, 0x0($fp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x14F868u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14f868;
        }
    }
    ctx->pc = 0x14F8D4u;
label_14f8d4:
    // 0x14f8d4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x14f8d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14f8d8: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x14f8d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x14f8dc: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x14f8dcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x14f8e0: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x14f8e0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x14f8e4: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x14f8e4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x14f8e8: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x14f8e8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x14f8ec: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x14f8ecu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x14f8f0: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x14f8f0u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x14f8f4: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x14f8f4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x14f8f8: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x14f8f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x14f8fc: 0x3e00008  jr          $ra
    ctx->pc = 0x14F8FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14F900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14F8FCu;
            // 0x14f900: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14F868u: goto label_14f868;
            case 0x14F870u: goto label_14f870;
            case 0x14F898u: goto label_14f898;
            case 0x14F8B8u: goto label_14f8b8;
            case 0x14F8C0u: goto label_14f8c0;
            case 0x14F8D4u: goto label_14f8d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14F904u;
    // 0x14f904: 0x0  nop
    ctx->pc = 0x14f904u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
