#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A370
// Address: 0x17a370 - 0x17a3e8
void sub_0017A370_0x17a370(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A370_0x17a370");
#endif

    switch (ctx->pc) {
        case 0x17a394u: goto label_17a394;
        case 0x17a3acu: goto label_17a3ac;
        default: break;
    }

    ctx->pc = 0x17a370u;

    // 0x17a370: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17a370u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17a374: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a374u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a378: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x17a378u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x17a37c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a37cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a380: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17a380u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17a384: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17a384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17a388: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17a388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17a38c: 0xc05e756  jal         func_179D58
    ctx->pc = 0x17A38Cu;
    SET_GPR_U32(ctx, 31, 0x17A394u);
    ctx->pc = 0x17A390u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A38Cu;
            // 0x17a390: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A394u; }
        if (ctx->pc != 0x17A394u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A394u; }
        if (ctx->pc != 0x17A394u) { return; }
    }
    ctx->pc = 0x17A394u;
label_17a394:
    // 0x17a394: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17a394u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a398: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17a398u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a39c: 0x1220000c  beqz        $s1, . + 4 + (0xC << 2)
    ctx->pc = 0x17A39Cu;
    {
        const bool branch_taken_0x17a39c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A3A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A39Cu;
            // 0x17a3a0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a39c) {
            ctx->pc = 0x17A3D0u;
            goto label_17a3d0;
        }
    }
    ctx->pc = 0x17A3A4u;
    // 0x17a3a4: 0xc05e966  jal         func_17A598
    ctx->pc = 0x17A3A4u;
    SET_GPR_U32(ctx, 31, 0x17A3ACu);
    ctx->pc = 0x17A598u;
    if (runtime->hasFunction(0x17A598u)) {
        auto targetFn = runtime->lookupFunction(0x17A598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A3ACu; }
        if (ctx->pc != 0x17A3ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A598_0x17a598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A3ACu; }
        if (ctx->pc != 0x17A3ACu) { return; }
    }
    ctx->pc = 0x17A3ACu;
label_17a3ac:
    // 0x17a3ac: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x17A3ACu;
    {
        const bool branch_taken_0x17a3ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A3B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A3ACu;
            // 0x17a3b0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a3ac) {
            ctx->pc = 0x17A3D4u;
            goto label_17a3d4;
        }
    }
    ctx->pc = 0x17A3B4u;
    // 0x17a3b4: 0x92220025  lbu         $v0, 0x25($s1)
    ctx->pc = 0x17a3b4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 37)));
    // 0x17a3b8: 0x28430040  slti        $v1, $v0, 0x40
    ctx->pc = 0x17a3b8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x17a3bc: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x17A3BCu;
    {
        const bool branch_taken_0x17a3bc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x17A3C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A3BCu;
            // 0x17a3c0: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a3bc) {
            ctx->pc = 0x17A3CCu;
            goto label_17a3cc;
        }
    }
    ctx->pc = 0x17A3C4u;
    // 0x17a3c4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x17a3c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x17a3c8: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x17a3c8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
label_17a3cc:
    // 0x17a3cc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a3ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_17a3d0:
    // 0x17a3d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a3d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17a3d4:
    // 0x17a3d4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a3d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a3d8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a3d8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a3dc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17a3dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a3e0: 0x3e00008  jr          $ra
    ctx->pc = 0x17A3E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A3E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A3E0u;
            // 0x17a3e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A394u: goto label_17a394;
            case 0x17A3ACu: goto label_17a3ac;
            case 0x17A3CCu: goto label_17a3cc;
            case 0x17A3D0u: goto label_17a3d0;
            case 0x17A3D4u: goto label_17a3d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A3E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
