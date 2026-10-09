#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6760
// Address: 0x1d6760 - 0x1d68a0
void sub_001D6760_0x1d6760(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6760_0x1d6760");
#endif

    switch (ctx->pc) {
        case 0x1d67b0u: goto label_1d67b0;
        case 0x1d67f8u: goto label_1d67f8;
        case 0x1d6818u: goto label_1d6818;
        case 0x1d6850u: goto label_1d6850;
        default: break;
    }

    ctx->pc = 0x1d6760u;

    // 0x1d6760: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d6760u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d6764: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d6764u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d6768: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d6768u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d676c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d676cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d6770: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d6770u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d6774: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d6774u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d6778: 0x8c2245f8  lw          $v0, 0x45F8($at)
    ctx->pc = 0x1d6778u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17912)));
    // 0x1d677c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D677Cu;
    {
        const bool branch_taken_0x1d677c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D677Cu;
            // 0x1d6780: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d677c) {
            ctx->pc = 0x1D6790u;
            goto label_1d6790;
        }
    }
    ctx->pc = 0x1D6784u;
    // 0x1d6784: 0x10000040  b           . + 4 + (0x40 << 2)
    ctx->pc = 0x1D6784u;
    {
        const bool branch_taken_0x1d6784 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d6784) {
            ctx->pc = 0x1D6888u;
            goto label_1d6888;
        }
    }
    ctx->pc = 0x1D678Cu;
    // 0x1d678c: 0x0  nop
    ctx->pc = 0x1d678cu;
    // NOP
label_1d6790:
    // 0x1d6790: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d6790u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d6794: 0x8c2345f0  lw          $v1, 0x45F0($at)
    ctx->pc = 0x1d6794u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17904)));
    // 0x1d6798: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D6798u;
    {
        const bool branch_taken_0x1d6798 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d6798) {
            ctx->pc = 0x1D67A8u;
            goto label_1d67a8;
        }
    }
    ctx->pc = 0x1D67A0u;
    // 0x1d67a0: 0x10000039  b           . + 4 + (0x39 << 2)
    ctx->pc = 0x1D67A0u;
    {
        const bool branch_taken_0x1d67a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d67a0) {
            ctx->pc = 0x1D6888u;
            goto label_1d6888;
        }
    }
    ctx->pc = 0x1D67A8u;
label_1d67a8:
    // 0x1d67a8: 0xc0759b8  jal         func_1D66E0
    ctx->pc = 0x1D67A8u;
    SET_GPR_U32(ctx, 31, 0x1D67B0u);
    ctx->pc = 0x1D66E0u;
    if (runtime->hasFunction(0x1D66E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D66E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D67B0u; }
        if (ctx->pc != 0x1D67B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D66E0_0x1d66e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D67B0u; }
        if (ctx->pc != 0x1D67B0u) { return; }
    }
    ctx->pc = 0x1D67B0u;
label_1d67b0:
    // 0x1d67b0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D67B0u;
    {
        const bool branch_taken_0x1d67b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D67B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D67B0u;
            // 0x1d67b4: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d67b0) {
            ctx->pc = 0x1D67C0u;
            goto label_1d67c0;
        }
    }
    ctx->pc = 0x1D67B8u;
    // 0x1d67b8: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x1D67B8u;
    {
        const bool branch_taken_0x1d67b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D67BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D67B8u;
            // 0x1d67bc: 0x8c2245f8  lw          $v0, 0x45F8($at) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17912)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d67b8) {
            ctx->pc = 0x1D6888u;
            goto label_1d6888;
        }
    }
    ctx->pc = 0x1D67C0u;
label_1d67c0:
    // 0x1d67c0: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1d67c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d67c4: 0x12220020  beq         $s1, $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x1D67C4u;
    {
        const bool branch_taken_0x1d67c4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D67C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D67C4u;
            // 0x1d67c8: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d67c4) {
            ctx->pc = 0x1D6848u;
            goto label_1d6848;
        }
    }
    ctx->pc = 0x1D67CCu;
    // 0x1d67cc: 0x1222001e  beq         $s1, $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x1D67CCu;
    {
        const bool branch_taken_0x1d67cc = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        if (branch_taken_0x1d67cc) {
            ctx->pc = 0x1D6848u;
            goto label_1d6848;
        }
    }
    ctx->pc = 0x1D67D4u;
    // 0x1d67d4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d67d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d67d8: 0x12220003  beq         $s1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D67D8u;
    {
        const bool branch_taken_0x1d67d8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        if (branch_taken_0x1d67d8) {
            ctx->pc = 0x1D67E8u;
            goto label_1d67e8;
        }
    }
    ctx->pc = 0x1D67E0u;
    // 0x1d67e0: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x1D67E0u;
    {
        const bool branch_taken_0x1d67e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d67e0) {
            ctx->pc = 0x1D6880u;
            goto label_1d6880;
        }
    }
    ctx->pc = 0x1D67E8u;
label_1d67e8:
    // 0x1d67e8: 0x12000009  beqz        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D67E8u;
    {
        const bool branch_taken_0x1d67e8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d67e8) {
            ctx->pc = 0x1D6810u;
            goto label_1d6810;
        }
    }
    ctx->pc = 0x1D67F0u;
    // 0x1d67f0: 0xc075d74  jal         func_1D75D0
    ctx->pc = 0x1D67F0u;
    SET_GPR_U32(ctx, 31, 0x1D67F8u);
    ctx->pc = 0x1D75D0u;
    if (runtime->hasFunction(0x1D75D0u)) {
        auto targetFn = runtime->lookupFunction(0x1D75D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D67F8u; }
        if (ctx->pc != 0x1D67F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D75D0_0x1d75d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D67F8u; }
        if (ctx->pc != 0x1D67F8u) { return; }
    }
    ctx->pc = 0x1D67F8u;
label_1d67f8:
    // 0x1d67f8: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D67F8u;
    {
        const bool branch_taken_0x1d67f8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1d67f8) {
            ctx->pc = 0x1D6810u;
            goto label_1d6810;
        }
    }
    ctx->pc = 0x1D6800u;
    // 0x1d6800: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d6800u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d6804: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d6804u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d6808: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1D6808u;
    {
        const bool branch_taken_0x1d6808 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D680Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6808u;
            // 0x1d680c: 0xac2245f8  sw          $v0, 0x45F8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 17912), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6808) {
            ctx->pc = 0x1D6880u;
            goto label_1d6880;
        }
    }
    ctx->pc = 0x1D6810u;
label_1d6810:
    // 0x1d6810: 0xc075db0  jal         func_1D76C0
    ctx->pc = 0x1D6810u;
    SET_GPR_U32(ctx, 31, 0x1D6818u);
    ctx->pc = 0x1D6814u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6810u;
            // 0x1d6814: 0x27a4004c  addiu       $a0, $sp, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 76));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D76C0u;
    if (runtime->hasFunction(0x1D76C0u)) {
        auto targetFn = runtime->lookupFunction(0x1D76C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6818u; }
        if (ctx->pc != 0x1D6818u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D76C0_0x1d76c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6818u; }
        if (ctx->pc != 0x1D6818u) { return; }
    }
    ctx->pc = 0x1D6818u;
label_1d6818:
    // 0x1d6818: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d6818u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d681c: 0x10430006  beq         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D681Cu;
    {
        const bool branch_taken_0x1d681c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d681c) {
            ctx->pc = 0x1D6838u;
            goto label_1d6838;
        }
    }
    ctx->pc = 0x1D6824u;
    // 0x1d6824: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1D6824u;
    {
        const bool branch_taken_0x1d6824 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d6824) {
            ctx->pc = 0x1D6880u;
            goto label_1d6880;
        }
    }
    ctx->pc = 0x1D682Cu;
    // 0x1d682c: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1D682Cu;
    {
        const bool branch_taken_0x1d682c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d682c) {
            ctx->pc = 0x1D6880u;
            goto label_1d6880;
        }
    }
    ctx->pc = 0x1D6834u;
    // 0x1d6834: 0x0  nop
    ctx->pc = 0x1d6834u;
    // NOP
label_1d6838:
    // 0x1d6838: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1d6838u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d683c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d683cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d6840: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1D6840u;
    {
        const bool branch_taken_0x1d6840 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6840u;
            // 0x1d6844: 0xac2245f8  sw          $v0, 0x45F8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 17912), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6840) {
            ctx->pc = 0x1D6880u;
            goto label_1d6880;
        }
    }
    ctx->pc = 0x1D6848u;
label_1d6848:
    // 0x1d6848: 0xc075c14  jal         func_1D7050
    ctx->pc = 0x1D6848u;
    SET_GPR_U32(ctx, 31, 0x1D6850u);
    ctx->pc = 0x1D684Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6848u;
            // 0x1d684c: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7050u;
    if (runtime->hasFunction(0x1D7050u)) {
        auto targetFn = runtime->lookupFunction(0x1D7050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6850u; }
        if (ctx->pc != 0x1D6850u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7050_0x1d7050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6850u; }
        if (ctx->pc != 0x1D6850u) { return; }
    }
    ctx->pc = 0x1D6850u;
label_1d6850:
    // 0x1d6850: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D6850u;
    {
        const bool branch_taken_0x1d6850 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1d6850) {
            ctx->pc = 0x1D6868u;
            goto label_1d6868;
        }
    }
    ctx->pc = 0x1D6858u;
    // 0x1d6858: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d6858u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d685c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d685cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d6860: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1D6860u;
    {
        const bool branch_taken_0x1d6860 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6864u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6860u;
            // 0x1d6864: 0xac2245f8  sw          $v0, 0x45F8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 17912), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6860) {
            ctx->pc = 0x1D6880u;
            goto label_1d6880;
        }
    }
    ctx->pc = 0x1D6868u;
label_1d6868:
    // 0x1d6868: 0x87a3003c  lh          $v1, 0x3C($sp)
    ctx->pc = 0x1d6868u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1d686c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1d686cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d6870: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D6870u;
    {
        const bool branch_taken_0x1d6870 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D6874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6870u;
            // 0x1d6874: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6870) {
            ctx->pc = 0x1D6880u;
            goto label_1d6880;
        }
    }
    ctx->pc = 0x1D6878u;
    // 0x1d6878: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d6878u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d687c: 0xac2245f8  sw          $v0, 0x45F8($at)
    ctx->pc = 0x1d687cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17912), GPR_U32(ctx, 2));
label_1d6880:
    // 0x1d6880: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d6880u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d6884: 0x8c2245f8  lw          $v0, 0x45F8($at)
    ctx->pc = 0x1d6884u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17912)));
label_1d6888:
    // 0x1d6888: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d6888u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d688c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d688cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d6890: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d6890u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d6894: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6894u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6894u;
            // 0x1d6898: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6790u: goto label_1d6790;
            case 0x1D67A8u: goto label_1d67a8;
            case 0x1D67B0u: goto label_1d67b0;
            case 0x1D67C0u: goto label_1d67c0;
            case 0x1D67E8u: goto label_1d67e8;
            case 0x1D67F8u: goto label_1d67f8;
            case 0x1D6810u: goto label_1d6810;
            case 0x1D6818u: goto label_1d6818;
            case 0x1D6838u: goto label_1d6838;
            case 0x1D6848u: goto label_1d6848;
            case 0x1D6850u: goto label_1d6850;
            case 0x1D6868u: goto label_1d6868;
            case 0x1D6880u: goto label_1d6880;
            case 0x1D6888u: goto label_1d6888;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D689Cu;
    // 0x1d689c: 0x0  nop
    ctx->pc = 0x1d689cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
