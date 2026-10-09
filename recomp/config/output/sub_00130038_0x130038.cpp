#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130038
// Address: 0x130038 - 0x1300c8
void sub_00130038_0x130038(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130038_0x130038");
#endif

    switch (ctx->pc) {
        case 0x130060u: goto label_130060;
        case 0x130074u: goto label_130074;
        default: break;
    }

    ctx->pc = 0x130038u;

    // 0x130038: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x130038u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13003c: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13003cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x130040: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x130040u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x130044: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130044u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130048: 0x24508760  addiu       $s0, $v0, -0x78A0
    ctx->pc = 0x130048u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294936416));
    // 0x13004c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13004cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x130050: 0x24110007  addiu       $s1, $zero, 0x7
    ctx->pc = 0x130050u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x130054: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x130054u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x130058: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x130058u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13005c: 0x0  nop
    ctx->pc = 0x13005cu;
    // NOP
label_130060:
    // 0x130060: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x130060u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x130064: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x130064u;
    {
        const bool branch_taken_0x130064 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x130064) {
            ctx->pc = 0x130068u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x130064u;
            // 0x130068: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x130078u;
            goto label_130078;
        }
    }
    ctx->pc = 0x13006Cu;
    // 0x13006c: 0xc04bffe  jal         func_12FFF8
    ctx->pc = 0x13006Cu;
    SET_GPR_U32(ctx, 31, 0x130074u);
    ctx->pc = 0x130070u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13006Cu;
            // 0x130070: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12FFF8u;
    if (runtime->hasFunction(0x12FFF8u)) {
        auto targetFn = runtime->lookupFunction(0x12FFF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130074u; }
        if (ctx->pc != 0x130074u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012FFF8_0x12fff8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130074u; }
        if (ctx->pc != 0x130074u) { return; }
    }
    ctx->pc = 0x130074u;
label_130074:
    // 0x130074: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x130074u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_130078:
    // 0x130078: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x130078u;
    {
        const bool branch_taken_0x130078 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x13007Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130078u;
            // 0x13007c: 0x261002f0  addiu       $s0, $s0, 0x2F0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 752));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130078) {
            ctx->pc = 0x130060u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_130060;
        }
    }
    ctx->pc = 0x130080u;
    // 0x130080: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x130080u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130084: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x130084u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130088: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x130088u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13008c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13008cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x130090: 0x3e00008  jr          $ra
    ctx->pc = 0x130090u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130090u;
            // 0x130094: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130060u: goto label_130060;
            case 0x130074u: goto label_130074;
            case 0x130078u: goto label_130078;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130098u;
    // 0x130098: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x130098u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13009c: 0x3e00008  jr          $ra
    ctx->pc = 0x13009Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1300A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13009Cu;
            // 0x1300a0: 0xac44a8a4  sw          $a0, -0x575C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294944932), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130060u: goto label_130060;
            case 0x130074u: goto label_130074;
            case 0x130078u: goto label_130078;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1300A4u;
    // 0x1300a4: 0x0  nop
    ctx->pc = 0x1300a4u;
    // NOP
    // 0x1300a8: 0x24020028  addiu       $v0, $zero, 0x28
    ctx->pc = 0x1300a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1300ac: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x1300acu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x1300b0: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x1300b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1300b4: 0x3c050022  lui         $a1, 0x22
    ctx->pc = 0x1300b4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)34 << 16));
    // 0x1300b8: 0xac62a8a8  sw          $v0, -0x5758($v1)
    ctx->pc = 0x1300b8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294944936), GPR_U32(ctx, 2));
    // 0x1300bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1300BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1300C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1300BCu;
            // 0x1300c0: 0xaca4a8ac  sw          $a0, -0x5754($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 4294944940), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130060u: goto label_130060;
            case 0x130074u: goto label_130074;
            case 0x130078u: goto label_130078;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1300C4u;
    // 0x1300c4: 0x0  nop
    ctx->pc = 0x1300c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
