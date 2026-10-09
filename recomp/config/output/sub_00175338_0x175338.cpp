#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00175338
// Address: 0x175338 - 0x1753f0
void sub_00175338_0x175338(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00175338_0x175338");
#endif

    switch (ctx->pc) {
        case 0x175368u: goto label_175368;
        case 0x175388u: goto label_175388;
        case 0x1753c0u: goto label_1753c0;
        case 0x1753d0u: goto label_1753d0;
        default: break;
    }

    ctx->pc = 0x175338u;

    // 0x175338: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x175338u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17533c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17533cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x175340: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x175340u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175344: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x175344u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x175348: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x175348u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17534c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17534cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x175350: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x175350u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175354: 0x1600000a  bnez        $s0, . + 4 + (0xA << 2)
    ctx->pc = 0x175354u;
    {
        const bool branch_taken_0x175354 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x175358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175354u;
            // 0x175358: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175354) {
            ctx->pc = 0x175380u;
            goto label_175380;
        }
    }
    ctx->pc = 0x17535Cu;
    // 0x17535c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17535cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175360: 0xc05d4fc  jal         func_1753F0
    ctx->pc = 0x175360u;
    SET_GPR_U32(ctx, 31, 0x175368u);
    ctx->pc = 0x175364u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175360u;
            // 0x175364: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1753F0u;
    if (runtime->hasFunction(0x1753F0u)) {
        auto targetFn = runtime->lookupFunction(0x1753F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175368u; }
        if (ctx->pc != 0x175368u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001753F0_0x1753f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175368u; }
        if (ctx->pc != 0x175368u) { return; }
    }
    ctx->pc = 0x175368u;
label_175368:
    // 0x175368: 0x111080  sll         $v0, $s1, 2
    ctx->pc = 0x175368u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x17536c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x17536cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x175370: 0x220821  addu        $at, $at, $v0
    ctx->pc = 0x175370u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x175374: 0xac32ef88  sw          $s2, -0x1078($at)
    ctx->pc = 0x175374u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294963080), GPR_U32(ctx, 18));
    // 0x175378: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x175378u;
    {
        const bool branch_taken_0x175378 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17537Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175378u;
            // 0x17537c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175378) {
            ctx->pc = 0x1753D4u;
            goto label_1753d4;
        }
    }
    ctx->pc = 0x175380u;
label_175380:
    // 0x175380: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x175380u;
    SET_GPR_U32(ctx, 31, 0x175388u);
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175388u; }
        if (ctx->pc != 0x175388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175388u; }
        if (ctx->pc != 0x175388u) { return; }
    }
    ctx->pc = 0x175388u;
label_175388:
    // 0x175388: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x175388u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x17538c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x17538Cu;
    {
        const bool branch_taken_0x17538c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x175390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17538Cu;
            // 0x175390: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17538c) {
            ctx->pc = 0x1753B0u;
            goto label_1753b0;
        }
    }
    ctx->pc = 0x175394u;
    // 0x175394: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175394u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x175398: 0x34a50112  ori         $a1, $a1, 0x112
    ctx->pc = 0x175398u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)274);
    // 0x17539c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17539cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1753a0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1753a0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1753a4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1753a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1753a8: 0x805a704  j           func_169C10
    ctx->pc = 0x1753A8u;
    ctx->pc = 0x1753ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1753A8u;
            // 0x1753ac: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1753B0u;
label_1753b0:
    // 0x1753b0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1753b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1753b4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1753b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1753b8: 0xc05d518  jal         func_175460
    ctx->pc = 0x1753B8u;
    SET_GPR_U32(ctx, 31, 0x1753C0u);
    ctx->pc = 0x1753BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1753B8u;
            // 0x1753bc: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1753C0u; }
        if (ctx->pc != 0x1753C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1753C0u; }
        if (ctx->pc != 0x1753C0u) { return; }
    }
    ctx->pc = 0x1753C0u;
label_1753c0:
    // 0x1753c0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1753c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1753c4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1753c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1753c8: 0xc05d52c  jal         func_1754B0
    ctx->pc = 0x1753C8u;
    SET_GPR_U32(ctx, 31, 0x1753D0u);
    ctx->pc = 0x1753CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1753C8u;
            // 0x1753cc: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1754B0u;
    if (runtime->hasFunction(0x1754B0u)) {
        auto targetFn = runtime->lookupFunction(0x1754B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1753D0u; }
        if (ctx->pc != 0x1753D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001754B0_0x1754b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1753D0u; }
        if (ctx->pc != 0x1753D0u) { return; }
    }
    ctx->pc = 0x1753D0u;
label_1753d0:
    // 0x1753d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1753d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1753d4:
    // 0x1753d4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1753d4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1753d8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1753d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1753dc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1753dcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1753e0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1753e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1753e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1753E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1753E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1753E4u;
            // 0x1753e8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x175368u: goto label_175368;
            case 0x175380u: goto label_175380;
            case 0x175388u: goto label_175388;
            case 0x1753B0u: goto label_1753b0;
            case 0x1753C0u: goto label_1753c0;
            case 0x1753D0u: goto label_1753d0;
            case 0x1753D4u: goto label_1753d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1753ECu;
    // 0x1753ec: 0x0  nop
    ctx->pc = 0x1753ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
