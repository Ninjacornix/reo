#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161E90
// Address: 0x161e90 - 0x161ee0
void sub_00161E90_0x161e90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161E90_0x161e90");
#endif

    switch (ctx->pc) {
        case 0x161eb4u: goto label_161eb4;
        default: break;
    }

    ctx->pc = 0x161e90u;

    // 0x161e90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x161e90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x161e94: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x161e94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161e98: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x161e98u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e9c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x161e9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x161ea0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x161ea0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ea4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x161ea4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x161ea8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x161ea8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x161eac: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161EACu;
    SET_GPR_U32(ctx, 31, 0x161EB4u);
    ctx->pc = 0x161EB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161EACu;
            // 0x161eb0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161EB4u; }
        if (ctx->pc != 0x161EB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161EB4u; }
        if (ctx->pc != 0x161EB4u) { return; }
    }
    ctx->pc = 0x161EB4u;
label_161eb4:
    // 0x161eb4: 0x3a100001  xori        $s0, $s0, 0x1
    ctx->pc = 0x161eb4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) ^ (uint64_t)(uint16_t)1);
    // 0x161eb8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x161eb8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x161ebc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x161ebcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ec0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x161ec0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161ec4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x161ec4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ec8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x161ec8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161ecc: 0x2e070001  sltiu       $a3, $s0, 0x1
    ctx->pc = 0x161eccu;
    SET_GPR_U64(ctx, 7, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x161ed0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161ed0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161ed4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x161ed4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ed8: 0x805f50c  j           func_17D430
    ctx->pc = 0x161ED8u;
    ctx->pc = 0x161EDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161ED8u;
            // 0x161edc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D430u;
    if (runtime->hasFunction(0x17D430u)) {
        auto targetFn = runtime->lookupFunction(0x17D430u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D430_0x17d430(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161EE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
