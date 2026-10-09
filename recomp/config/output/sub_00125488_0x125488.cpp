#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00125488
// Address: 0x125488 - 0x1254f4
void sub_00125488_0x125488(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00125488_0x125488");
#endif

    switch (ctx->pc) {
        case 0x1254c0u: goto label_1254c0;
        default: break;
    }

    ctx->pc = 0x125488u;

    // 0x125488: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x125488u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x12548c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12548cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x125490: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x125490u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125494: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x125494u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x125498: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x125498u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12549c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12549cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1254a0: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x1254a0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1254a4: 0x122840  sll         $a1, $s2, 1
    ctx->pc = 0x1254a4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x1254a8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1254a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1254ac: 0x2252821  addu        $a1, $s1, $a1
    ctx->pc = 0x1254acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
    // 0x1254b0: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1254b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1254b4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1254b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1254b8: 0xc049516  jal         func_125458
    ctx->pc = 0x1254B8u;
    SET_GPR_U32(ctx, 31, 0x1254C0u);
    ctx->pc = 0x1254BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1254B8u;
            // 0x1254bc: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125458u;
    if (runtime->hasFunction(0x125458u)) {
        auto targetFn = runtime->lookupFunction(0x125458u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1254C0u; }
        if (ctx->pc != 0x1254C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00125458_0x125458(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1254C0u; }
        if (ctx->pc != 0x1254C0u) { return; }
    }
    ctx->pc = 0x1254C0u;
label_1254c0:
    // 0x1254c0: 0x102040  sll         $a0, $s0, 1
    ctx->pc = 0x1254c0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x1254c4: 0x2128021  addu        $s0, $s0, $s2
    ctx->pc = 0x1254c4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
    // 0x1254c8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1254c8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1254cc: 0x108040  sll         $s0, $s0, 1
    ctx->pc = 0x1254ccu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x1254d0: 0x2242021  addu        $a0, $s1, $a0
    ctx->pc = 0x1254d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
    // 0x1254d4: 0x2302821  addu        $a1, $s1, $s0
    ctx->pc = 0x1254d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x1254d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1254d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1254dc: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1254dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1254e0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1254e0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1254e4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1254e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1254e8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1254e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1254ec: 0x8049516  j           func_125458
    ctx->pc = 0x1254ECu;
    ctx->pc = 0x1254F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1254ECu;
            // 0x1254f0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125458u;
    if (runtime->hasFunction(0x125458u)) {
        auto targetFn = runtime->lookupFunction(0x125458u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00125458_0x125458(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1254F4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
