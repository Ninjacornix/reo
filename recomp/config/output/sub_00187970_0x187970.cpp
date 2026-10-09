#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00187970
// Address: 0x187970 - 0x187a40
void sub_00187970_0x187970(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00187970_0x187970");
#endif

    switch (ctx->pc) {
        case 0x18798cu: goto label_18798c;
        case 0x1879e0u: goto label_1879e0;
        case 0x1879f0u: goto label_1879f0;
        default: break;
    }

    ctx->pc = 0x187970u;

    // 0x187970: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x187970u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x187974: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x187974u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x187978: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x187978u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x18797c: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x18797cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x187980: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x187980u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x187984: 0xc061e4c  jal         func_187930
    ctx->pc = 0x187984u;
    SET_GPR_U32(ctx, 31, 0x18798Cu);
    ctx->pc = 0x187988u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187984u;
            // 0x187988: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187930u;
    if (runtime->hasFunction(0x187930u)) {
        auto targetFn = runtime->lookupFunction(0x187930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18798Cu; }
        if (ctx->pc != 0x18798Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187930_0x187930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18798Cu; }
        if (ctx->pc != 0x18798Cu) { return; }
    }
    ctx->pc = 0x18798Cu;
label_18798c:
    // 0x18798c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x18798cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187990: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x187990u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x187994: 0x2452d980  addiu       $s2, $v0, -0x2680
    ctx->pc = 0x187994u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), 4294957440));
    // 0x187998: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x187998u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x18799c: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x18799cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1879a0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1879a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1879a4: 0x6200020  bltz        $s1, . + 4 + (0x20 << 2)
    ctx->pc = 0x1879A4u;
    {
        const bool branch_taken_0x1879a4 = (GPR_S64(ctx, 17) < 0);
        ctx->pc = 0x1879A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1879A4u;
            // 0x1879a8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1879a4) {
            ctx->pc = 0x187A28u;
            goto label_187a28;
        }
    }
    ctx->pc = 0x1879ACu;
    // 0x1879ac: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1879acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1879b0: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x1879b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1879b4: 0x8e080010  lw          $t0, 0x10($s0)
    ctx->pc = 0x1879b4u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1879b8: 0x34630001  ori         $v1, $v1, 0x1
    ctx->pc = 0x1879b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1);
    // 0x1879bc: 0x8e070008  lw          $a3, 0x8($s0)
    ctx->pc = 0x1879bcu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1879c0: 0xafa2000c  sw          $v0, 0xC($sp)
    ctx->pc = 0x1879c0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 2));
    // 0x1879c4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1879c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1879c8: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x1879c8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x1879cc: 0xafa70008  sw          $a3, 0x8($sp)
    ctx->pc = 0x1879ccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 7));
    // 0x1879d0: 0xafa80010  sw          $t0, 0x10($sp)
    ctx->pc = 0x1879d0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 8));
    // 0x1879d4: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x1879d4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x1879d8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1879D8u;
    SET_GPR_U32(ctx, 31, 0x1879E0u);
    ctx->pc = 0x1879DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1879D8u;
            // 0x1879dc: 0xa3a00014  sb          $zero, 0x14($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 20), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1879E0u; }
        if (ctx->pc != 0x1879E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1879E0u; }
        if (ctx->pc != 0x1879E0u) { return; }
    }
    ctx->pc = 0x1879E0u;
label_1879e0:
    // 0x1879e0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1879e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1879e4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1879e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1879e8: 0xc06230c  jal         func_188C30
    ctx->pc = 0x1879E8u;
    SET_GPR_U32(ctx, 31, 0x1879F0u);
    ctx->pc = 0x1879ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1879E8u;
            // 0x1879ec: 0x24a60080  addiu       $a2, $a1, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188C30u;
    if (runtime->hasFunction(0x188C30u)) {
        auto targetFn = runtime->lookupFunction(0x188C30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1879F0u; }
        if (ctx->pc != 0x1879F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188C30_0x188c30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1879F0u; }
        if (ctx->pc != 0x1879F0u) { return; }
    }
    ctx->pc = 0x1879F0u;
label_1879f0:
    // 0x1879f0: 0x1118c0  sll         $v1, $s1, 3
    ctx->pc = 0x1879f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x1879f4: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x1879f4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x1879f8: 0x711823  subu        $v1, $v1, $s1
    ctx->pc = 0x1879f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1879fc: 0x2484b8c8  addiu       $a0, $a0, -0x4738
    ctx->pc = 0x1879fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949064));
    // 0x187a00: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x187a00u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x187a04: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x187a04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187a08: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x187a08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x187a0c: 0x643021  addu        $a2, $v1, $a0
    ctx->pc = 0x187a0cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x187a10: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x187a10u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x187a14: 0x4a00004  bltz        $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x187A14u;
    {
        const bool branch_taken_0x187a14 = (GPR_S64(ctx, 5) < 0);
        ctx->pc = 0x187A18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187A14u;
            // 0x187a18: 0xac850004  sw          $a1, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187a14) {
            ctx->pc = 0x187A28u;
            goto label_187a28;
        }
    }
    ctx->pc = 0x187A1Cu;
    // 0x187a1c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x187a1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x187a20: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x187a20u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x187a24: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x187a24u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_187a28:
    // 0x187a28: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x187a28u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x187a2c: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x187a2cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x187a30: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x187a30u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x187a34: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x187a34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x187a38: 0x3e00008  jr          $ra
    ctx->pc = 0x187A38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x187A3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187A38u;
            // 0x187a3c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18798Cu: goto label_18798c;
            case 0x1879E0u: goto label_1879e0;
            case 0x1879F0u: goto label_1879f0;
            case 0x187A28u: goto label_187a28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187A40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
