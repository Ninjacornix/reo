#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AD4E0
// Address: 0x1ad4e0 - 0x1ad5c0
void sub_001AD4E0_0x1ad4e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AD4E0_0x1ad4e0");
#endif

    switch (ctx->pc) {
        case 0x1ad51cu: goto label_1ad51c;
        case 0x1ad55cu: goto label_1ad55c;
        default: break;
    }

    ctx->pc = 0x1ad4e0u;

    // 0x1ad4e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1ad4e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1ad4e4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad4e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad4e8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1ad4e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1ad4ec: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ad4ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ad4f0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ad4f0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ad4f4: 0x8c25382c  lw          $a1, 0x382C($at)
    ctx->pc = 0x1ad4f4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 14380)));
    // 0x1ad4f8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1ad4f8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad4fc: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1ad4fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1ad500: 0x8c86000c  lw          $a2, 0xC($a0)
    ctx->pc = 0x1ad500u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1ad504: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad504u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad508: 0x8c233824  lw          $v1, 0x3824($at)
    ctx->pc = 0x1ad508u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 14372)));
    // 0x1ad50c: 0xa38821  addu        $s1, $a1, $v1
    ctx->pc = 0x1ad50cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1ad510: 0x822821  addu        $a1, $a0, $v0
    ctx->pc = 0x1ad510u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ad514: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1AD514u;
    SET_GPR_U32(ctx, 31, 0x1AD51Cu);
    ctx->pc = 0x1AD518u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD514u;
            // 0x1ad518: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD51Cu; }
        if (ctx->pc != 0x1AD51Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD51Cu; }
        if (ctx->pc != 0x1AD51Cu) { return; }
    }
    ctx->pc = 0x1AD51Cu;
label_1ad51c:
    // 0x1ad51c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad51cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad520: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1ad520u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1ad524: 0x8c233810  lw          $v1, 0x3810($at)
    ctx->pc = 0x1ad524u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 14352)));
    // 0x1ad528: 0x24423814  addiu       $v0, $v0, 0x3814
    ctx->pc = 0x1ad528u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 14356));
    // 0x1ad52c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1ad52cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1ad530: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad530u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad534: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ad534u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ad538: 0xac510000  sw          $s1, 0x0($v0)
    ctx->pc = 0x1ad538u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 17));
    // 0x1ad53c: 0x8c243830  lw          $a0, 0x3830($at)
    ctx->pc = 0x1ad53cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 14384)));
    // 0x1ad540: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x1ad540u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1ad544: 0x8e060014  lw          $a2, 0x14($s0)
    ctx->pc = 0x1ad544u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1ad548: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad548u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad54c: 0x8c233828  lw          $v1, 0x3828($at)
    ctx->pc = 0x1ad54cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 14376)));
    // 0x1ad550: 0x2022821  addu        $a1, $s0, $v0
    ctx->pc = 0x1ad550u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1ad554: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1AD554u;
    SET_GPR_U32(ctx, 31, 0x1AD55Cu);
    ctx->pc = 0x1AD558u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD554u;
            // 0x1ad558: 0x832021  addu        $a0, $a0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD55Cu; }
        if (ctx->pc != 0x1AD55Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD55Cu; }
        if (ctx->pc != 0x1AD55Cu) { return; }
    }
    ctx->pc = 0x1AD55Cu;
label_1ad55c:
    // 0x1ad55c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad55cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad560: 0x8e04000c  lw          $a0, 0xC($s0)
    ctx->pc = 0x1ad560u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1ad564: 0x8c263824  lw          $a2, 0x3824($at)
    ctx->pc = 0x1ad564u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 14372)));
    // 0x1ad568: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad568u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad56c: 0xc42021  addu        $a0, $a2, $a0
    ctx->pc = 0x1ad56cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x1ad570: 0x8c253828  lw          $a1, 0x3828($at)
    ctx->pc = 0x1ad570u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 14376)));
    // 0x1ad574: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad574u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad578: 0x8c233810  lw          $v1, 0x3810($at)
    ctx->pc = 0x1ad578u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 14352)));
    // 0x1ad57c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad57cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad580: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1ad580u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ad584: 0xac243824  sw          $a0, 0x3824($at)
    ctx->pc = 0x1ad584u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 14372), GPR_U32(ctx, 4));
    // 0x1ad588: 0x8e040014  lw          $a0, 0x14($s0)
    ctx->pc = 0x1ad588u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1ad58c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad58cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad590: 0xac233810  sw          $v1, 0x3810($at)
    ctx->pc = 0x1ad590u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 14352), GPR_U32(ctx, 3));
    // 0x1ad594: 0xa42021  addu        $a0, $a1, $a0
    ctx->pc = 0x1ad594u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1ad598: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad598u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad59c: 0xac243828  sw          $a0, 0x3828($at)
    ctx->pc = 0x1ad59cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 14376), GPR_U32(ctx, 4));
    // 0x1ad5a0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1ad5a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ad5a4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ad5a4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ad5a8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ad5a8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ad5ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1AD5ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AD5B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD5ACu;
            // 0x1ad5b0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AD51Cu: goto label_1ad51c;
            case 0x1AD55Cu: goto label_1ad55c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AD5B4u;
    // 0x1ad5b4: 0x0  nop
    ctx->pc = 0x1ad5b4u;
    // NOP
    // 0x1ad5b8: 0x0  nop
    ctx->pc = 0x1ad5b8u;
    // NOP
    // 0x1ad5bc: 0x0  nop
    ctx->pc = 0x1ad5bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
