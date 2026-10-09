#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161688
// Address: 0x161688 - 0x161720
void sub_00161688_0x161688(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161688_0x161688");
#endif

    switch (ctx->pc) {
        case 0x1616b4u: goto label_1616b4;
        case 0x1616e8u: goto label_1616e8;
        case 0x1616fcu: goto label_1616fc;
        default: break;
    }

    ctx->pc = 0x161688u;

    // 0x161688: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x161688u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16168c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16168cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161690: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x161690u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161694: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x161694u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x161698: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x161698u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16169c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16169cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1616a0: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1616a0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1616a4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1616a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1616a8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1616a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1616ac: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1616ACu;
    SET_GPR_U32(ctx, 31, 0x1616B4u);
    ctx->pc = 0x1616B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1616ACu;
            // 0x1616b0: 0xe0982d  daddu       $s3, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1616B4u; }
        if (ctx->pc != 0x1616B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1616B4u; }
        if (ctx->pc != 0x1616B4u) { return; }
    }
    ctx->pc = 0x1616B4u;
label_1616b4:
    // 0x1616b4: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1616B4u;
    {
        const bool branch_taken_0x1616b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1616B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1616B4u;
            // 0x1616b8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1616b4) {
            ctx->pc = 0x1616E0u;
            goto label_1616e0;
        }
    }
    ctx->pc = 0x1616BCu;
    // 0x1616bc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1616bcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1616c0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1616c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1616c4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1616c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1616c8: 0x2484fd68  addiu       $a0, $a0, -0x298
    ctx->pc = 0x1616c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966632));
    // 0x1616cc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1616ccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1616d0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1616d0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1616d4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1616d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1616d8: 0x8058dd4  j           func_163750
    ctx->pc = 0x1616D8u;
    ctx->pc = 0x1616DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1616D8u;
            // 0x1616dc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1616E0u;
label_1616e0:
    // 0x1616e0: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x1616E0u;
    SET_GPR_U32(ctx, 31, 0x1616E8u);
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1616E8u; }
        if (ctx->pc != 0x1616E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1616E8u; }
        if (ctx->pc != 0x1616E8u) { return; }
    }
    ctx->pc = 0x1616E8u;
label_1616e8:
    // 0x1616e8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1616e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1616ec: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1616ecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1616f0: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x1616f0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1616f4: 0xc05f496  jal         func_17D258
    ctx->pc = 0x1616F4u;
    SET_GPR_U32(ctx, 31, 0x1616FCu);
    ctx->pc = 0x1616F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1616F4u;
            // 0x1616f8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D258u;
    if (runtime->hasFunction(0x17D258u)) {
        auto targetFn = runtime->lookupFunction(0x17D258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1616FCu; }
        if (ctx->pc != 0x1616FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D258_0x17d258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1616FCu; }
        if (ctx->pc != 0x1616FCu) { return; }
    }
    ctx->pc = 0x1616FCu;
label_1616fc:
    // 0x1616fc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1616fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161700: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x161700u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161704: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x161704u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x161708: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161708u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16170c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16170cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161710: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x161710u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161714: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x161714u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x161718: 0x805f4a0  j           func_17D280
    ctx->pc = 0x161718u;
    ctx->pc = 0x16171Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161718u;
            // 0x16171c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D280u;
    {
        auto targetFn = runtime->lookupFunction(0x17D280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x161720u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
