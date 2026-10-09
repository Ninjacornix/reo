#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00159070
// Address: 0x159070 - 0x15911c
void sub_00159070_0x159070(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00159070_0x159070");
#endif

    switch (ctx->pc) {
        case 0x159098u: goto label_159098;
        case 0x1590dcu: goto label_1590dc;
        default: break;
    }

    ctx->pc = 0x159070u;

    // 0x159070: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x159070u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x159074: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x159074u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x159078: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x159078u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15907c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15907cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x159080: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x159080u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159084: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x159084u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x159088: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x159088u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15908c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x15908cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x159090: 0xc056dec  jal         func_15B7B0
    ctx->pc = 0x159090u;
    SET_GPR_U32(ctx, 31, 0x159098u);
    ctx->pc = 0x159094u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x159090u;
            // 0x159094: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B7B0u;
    if (runtime->hasFunction(0x15B7B0u)) {
        auto targetFn = runtime->lookupFunction(0x15B7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159098u; }
        if (ctx->pc != 0x159098u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B7B0_0x15b7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159098u; }
        if (ctx->pc != 0x159098u) { return; }
    }
    ctx->pc = 0x159098u;
label_159098:
    // 0x159098: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x159098u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x15909c: 0x240600cc  addiu       $a2, $zero, 0xCC
    ctx->pc = 0x15909cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 204));
    // 0x1590a0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1590a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1590a4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1590A4u;
    {
        const bool branch_taken_0x1590a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1590A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1590A4u;
            // 0x1590a8: 0x34a5020a  ori         $a1, $a1, 0x20A (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)522);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1590a4) {
            ctx->pc = 0x1590C8u;
            goto label_1590c8;
        }
    }
    ctx->pc = 0x1590ACu;
    // 0x1590ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1590acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1590b0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1590b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1590b4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1590b4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1590b8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1590b8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1590bc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1590bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1590c0: 0x80563ce  j           func_158F38
    ctx->pc = 0x1590C0u;
    ctx->pc = 0x1590C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1590C0u;
            // 0x1590c4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158F38u;
    if (runtime->hasFunction(0x158F38u)) {
        auto targetFn = runtime->lookupFunction(0x158F38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00158F38_0x158f38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1590C8u;
label_1590c8:
    // 0x1590c8: 0x8e110004  lw          $s1, 0x4($s0)
    ctx->pc = 0x1590c8u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1590cc: 0x8e100000  lw          $s0, 0x0($s0)
    ctx->pc = 0x1590ccu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1590d0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1590d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1590d4: 0xc0561d4  jal         func_158750
    ctx->pc = 0x1590D4u;
    SET_GPR_U32(ctx, 31, 0x1590DCu);
    ctx->pc = 0x1590D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1590D4u;
            // 0x1590d8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158750u;
    if (runtime->hasFunction(0x158750u)) {
        auto targetFn = runtime->lookupFunction(0x158750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1590DCu; }
        if (ctx->pc != 0x1590DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158750_0x158750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1590DCu; }
        if (ctx->pc != 0x1590DCu) { return; }
    }
    ctx->pc = 0x1590DCu;
label_1590dc:
    // 0x1590dc: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1590dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1590e0: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x1590e0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x1590e4: 0x508023  subu        $s0, $v0, $s0
    ctx->pc = 0x1590e4u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1590e8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1590E8u;
    {
        const bool branch_taken_0x1590e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1590ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1590E8u;
            // 0x1590ec: 0x34a50305  ori         $a1, $a1, 0x305 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)773);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1590e8) {
            ctx->pc = 0x1590F8u;
            goto label_1590f8;
        }
    }
    ctx->pc = 0x1590F0u;
    // 0x1590f0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1590F0u;
    {
        const bool branch_taken_0x1590f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1590F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1590F0u;
            // 0x1590f4: 0xae710000  sw          $s1, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1590f0) {
            ctx->pc = 0x159100u;
            goto label_159100;
        }
    }
    ctx->pc = 0x1590F8u;
label_1590f8:
    // 0x1590f8: 0xae700000  sw          $s0, 0x0($s3)
    ctx->pc = 0x1590f8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 16));
    // 0x1590fc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1590fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_159100:
    // 0x159100: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x159100u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x159104: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x159104u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x159108: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x159108u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15910c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15910cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x159110: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x159110u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x159114: 0x80563ce  j           func_158F38
    ctx->pc = 0x159114u;
    ctx->pc = 0x159118u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x159114u;
            // 0x159118: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158F38u;
    if (runtime->hasFunction(0x158F38u)) {
        auto targetFn = runtime->lookupFunction(0x158F38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00158F38_0x158f38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15911Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
