#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016C040
// Address: 0x16c040 - 0x16c0e4
void sub_0016C040_0x16c040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016C040_0x16c040");
#endif

    switch (ctx->pc) {
        case 0x16c074u: goto label_16c074;
        case 0x16c0c0u: goto label_16c0c0;
        default: break;
    }

    ctx->pc = 0x16c040u;

    // 0x16c040: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16c040u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16c044: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16c044u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16c048: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x16c048u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c04c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16c04cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16c050: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x16c050u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c054: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16c054u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16c058: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x16c058u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c05c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16c05cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16c060: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x16c060u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c064: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x16c064u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x16c068: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x16c068u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x16c06c: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x16C06Cu;
    SET_GPR_U32(ctx, 31, 0x16C074u);
    ctx->pc = 0x16C070u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C06Cu;
            // 0x16c070: 0xa0a02d  daddu       $s4, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C074u; }
        if (ctx->pc != 0x16C074u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C074u; }
        if (ctx->pc != 0x16C074u) { return; }
    }
    ctx->pc = 0x16C074u;
label_16c074:
    // 0x16c074: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16c074u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16c078: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x16c078u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c07c: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x16c07cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c080: 0x240402d  daddu       $t0, $s2, $zero
    ctx->pc = 0x16c080u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c084: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x16c084u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c088: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x16C088u;
    {
        const bool branch_taken_0x16c088 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C08Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C088u;
            // 0x16c08c: 0x34a50184  ori         $a1, $a1, 0x184 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)388);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c088) {
            ctx->pc = 0x16C0B0u;
            goto label_16c0b0;
        }
    }
    ctx->pc = 0x16C090u;
    // 0x16c090: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16c090u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c094: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16c094u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c098: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16c098u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16c09c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16c09cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16c0a0: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16c0a0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16c0a4: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x16c0a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16c0a8: 0x805a704  j           func_169C10
    ctx->pc = 0x16C0A8u;
    ctx->pc = 0x16C0ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C0A8u;
            // 0x16c0ac: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16C0B0u;
label_16c0b0:
    // 0x16c0b0: 0x8e621b30  lw          $v0, 0x1B30($s3)
    ctx->pc = 0x16c0b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 6960)));
    // 0x16c0b4: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x16c0b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c0b8: 0xc05652e  jal         func_1594B8
    ctx->pc = 0x16C0B8u;
    SET_GPR_U32(ctx, 31, 0x16C0C0u);
    ctx->pc = 0x16C0BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C0B8u;
            // 0x16c0bc: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1594B8u;
    if (runtime->hasFunction(0x1594B8u)) {
        auto targetFn = runtime->lookupFunction(0x1594B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C0C0u; }
        if (ctx->pc != 0x16C0C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001594B8_0x1594b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C0C0u; }
        if (ctx->pc != 0x16C0C0u) { return; }
    }
    ctx->pc = 0x16C0C0u;
label_16c0c0:
    // 0x16c0c0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16c0c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c0c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16c0c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c0c8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16c0c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c0cc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16c0ccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16c0d0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16c0d0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16c0d4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16c0d4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16c0d8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x16c0d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16c0dc: 0x3e00008  jr          $ra
    ctx->pc = 0x16C0DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16C0E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C0DCu;
            // 0x16c0e0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16C074u: goto label_16c074;
            case 0x16C0B0u: goto label_16c0b0;
            case 0x16C0C0u: goto label_16c0c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C0E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
