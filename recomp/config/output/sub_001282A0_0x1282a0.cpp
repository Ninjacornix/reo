#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001282A0
// Address: 0x1282a0 - 0x128328
void sub_001282A0_0x1282a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001282A0_0x1282a0");
#endif

    switch (ctx->pc) {
        case 0x1282ccu: goto label_1282cc;
        case 0x1282d4u: goto label_1282d4;
        case 0x1282ecu: goto label_1282ec;
        case 0x1282f4u: goto label_1282f4;
        case 0x128300u: goto label_128300;
        default: break;
    }

    ctx->pc = 0x1282a0u;

    // 0x1282a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1282a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1282a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1282a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1282a8: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1282a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1282ac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1282acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1282b0: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x1282b0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1282b4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1282b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1282b8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1282b8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1282bc: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1282bcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1282c0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1282c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1282c4: 0xc04a066  jal         func_128198
    ctx->pc = 0x1282C4u;
    SET_GPR_U32(ctx, 31, 0x1282CCu);
    ctx->pc = 0x1282C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1282C4u;
            // 0x1282c8: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128198u;
    if (runtime->hasFunction(0x128198u)) {
        auto targetFn = runtime->lookupFunction(0x128198u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1282CCu; }
        if (ctx->pc != 0x1282CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128198_0x128198(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1282CCu; }
        if (ctx->pc != 0x1282CCu) { return; }
    }
    ctx->pc = 0x1282CCu;
label_1282cc:
    // 0x1282cc: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1282CCu;
    SET_GPR_U32(ctx, 31, 0x1282D4u);
    ctx->pc = 0x1282D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1282CCu;
            // 0x1282d0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1282D4u; }
        if (ctx->pc != 0x1282D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1282D4u; }
        if (ctx->pc != 0x1282D4u) { return; }
    }
    ctx->pc = 0x1282D4u;
label_1282d4:
    // 0x1282d4: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x1282d4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x1282d8: 0x2228823  subu        $s1, $s1, $v0
    ctx->pc = 0x1282d8u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1282dc: 0x24a59c28  addiu       $a1, $a1, -0x63D8
    ctx->pc = 0x1282dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941736));
    // 0x1282e0: 0x2626ffff  addiu       $a2, $s1, -0x1
    ctx->pc = 0x1282e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
    // 0x1282e4: 0xc042ca4  jal         func_10B290
    ctx->pc = 0x1282E4u;
    SET_GPR_U32(ctx, 31, 0x1282ECu);
    ctx->pc = 0x1282E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1282E4u;
            // 0x1282e8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B290u;
    if (runtime->hasFunction(0x10B290u)) {
        auto targetFn = runtime->lookupFunction(0x10B290u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1282ECu; }
        if (ctx->pc != 0x1282ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B290_0x10b290(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1282ECu; }
        if (ctx->pc != 0x1282ECu) { return; }
    }
    ctx->pc = 0x1282ECu;
label_1282ec:
    // 0x1282ec: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1282ECu;
    SET_GPR_U32(ctx, 31, 0x1282F4u);
    ctx->pc = 0x1282F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1282ECu;
            // 0x1282f0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1282F4u; }
        if (ctx->pc != 0x1282F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1282F4u; }
        if (ctx->pc != 0x1282F4u) { return; }
    }
    ctx->pc = 0x1282F4u;
label_1282f4:
    // 0x1282f4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1282f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1282f8: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1282F8u;
    SET_GPR_U32(ctx, 31, 0x128300u);
    ctx->pc = 0x1282FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1282F8u;
            // 0x1282fc: 0x2028021  addu        $s0, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128300u; }
        if (ctx->pc != 0x128300u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128300u; }
        if (ctx->pc != 0x128300u) { return; }
    }
    ctx->pc = 0x128300u;
label_128300:
    // 0x128300: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x128300u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x128304: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x128304u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128308: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x128308u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12830c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12830cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x128310: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x128310u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x128314: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x128314u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x128318: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x128318u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12831c: 0xc23023  subu        $a2, $a2, $v0
    ctx->pc = 0x12831cu;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x128320: 0x804a066  j           func_128198
    ctx->pc = 0x128320u;
    ctx->pc = 0x128324u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128320u;
            // 0x128324: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128198u;
    if (runtime->hasFunction(0x128198u)) {
        auto targetFn = runtime->lookupFunction(0x128198u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00128198_0x128198(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x128328u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
