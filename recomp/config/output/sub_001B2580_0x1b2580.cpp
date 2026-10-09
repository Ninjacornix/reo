#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2580
// Address: 0x1b2580 - 0x1b2620
void sub_001B2580_0x1b2580(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2580_0x1b2580");
#endif

    switch (ctx->pc) {
        case 0x1b25a4u: goto label_1b25a4;
        case 0x1b25c4u: goto label_1b25c4;
        case 0x1b2604u: goto label_1b2604;
        default: break;
    }

    ctx->pc = 0x1b2580u;

    // 0x1b2580: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b2580u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b2584: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b2584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b2588: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b2588u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b258c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b258cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b2590: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1b2590u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2594: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b2594u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b2598: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1b2598u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b259c: 0xc06c9e4  jal         func_1B2790
    ctx->pc = 0x1B259Cu;
    SET_GPR_U32(ctx, 31, 0x1B25A4u);
    ctx->pc = 0x1B25A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B259Cu;
            // 0x1b25a0: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2790u;
    if (runtime->hasFunction(0x1B2790u)) {
        auto targetFn = runtime->lookupFunction(0x1B2790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B25A4u; }
        if (ctx->pc != 0x1B25A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2790_0x1b2790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B25A4u; }
        if (ctx->pc != 0x1B25A4u) { return; }
    }
    ctx->pc = 0x1B25A4u;
label_1b25a4:
    // 0x1b25a4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B25A4u;
    {
        const bool branch_taken_0x1b25a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B25A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B25A4u;
            // 0x1b25a8: 0x2a030100  slti        $v1, $s0, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)256) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b25a4) {
            ctx->pc = 0x1B25B4u;
            goto label_1b25b4;
        }
    }
    ctx->pc = 0x1B25ACu;
    // 0x1b25ac: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1B25ACu;
    {
        const bool branch_taken_0x1b25ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B25B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B25ACu;
            // 0x1b25b0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b25ac) {
            ctx->pc = 0x1B2608u;
            goto label_1b2608;
        }
    }
    ctx->pc = 0x1B25B4u;
label_1b25b4:
    // 0x1b25b4: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B25B4u;
    {
        const bool branch_taken_0x1b25b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b25b4) {
            ctx->pc = 0x1B25CCu;
            goto label_1b25cc;
        }
    }
    ctx->pc = 0x1B25BCu;
    // 0x1b25bc: 0xc06ca04  jal         func_1B2810
    ctx->pc = 0x1B25BCu;
    SET_GPR_U32(ctx, 31, 0x1B25C4u);
    ctx->pc = 0x1B2810u;
    if (runtime->hasFunction(0x1B2810u)) {
        auto targetFn = runtime->lookupFunction(0x1B2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B25C4u; }
        if (ctx->pc != 0x1B25C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2810_0x1b2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B25C4u; }
        if (ctx->pc != 0x1B25C4u) { return; }
    }
    ctx->pc = 0x1B25C4u;
label_1b25c4:
    // 0x1b25c4: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1B25C4u;
    {
        const bool branch_taken_0x1b25c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B25C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B25C4u;
            // 0x1b25c8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b25c4) {
            ctx->pc = 0x1B2608u;
            goto label_1b2608;
        }
    }
    ctx->pc = 0x1B25CCu;
label_1b25cc:
    // 0x1b25cc: 0xac52001c  sw          $s2, 0x1C($v0)
    ctx->pc = 0x1b25ccu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 18));
    // 0x1b25d0: 0x2403009f  addiu       $v1, $zero, 0x9F
    ctx->pc = 0x1b25d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 159));
    // 0x1b25d4: 0xac510018  sw          $s1, 0x18($v0)
    ctx->pc = 0x1b25d4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 17));
    // 0x1b25d8: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x1b25d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1b25dc: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x1b25dcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x1b25e0: 0x3c010025  lui         $at, 0x25
    ctx->pc = 0x1b25e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)37 << 16));
    // 0x1b25e4: 0xc420ff08  lwc1        $f0, -0xF8($at)
    ctx->pc = 0x1b25e4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294967048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b25e8: 0x32080  sll         $a0, $v1, 2
    ctx->pc = 0x1b25e8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b25ec: 0x3c030032  lui         $v1, 0x32
    ctx->pc = 0x1b25ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)50 << 16));
    // 0x1b25f0: 0x246388e0  addiu       $v1, $v1, -0x7720
    ctx->pc = 0x1b25f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294936800));
    // 0x1b25f4: 0x642821  addu        $a1, $v1, $a0
    ctx->pc = 0x1b25f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b25f8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1b25f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b25fc: 0xc069704  jal         func_1A5C10
    ctx->pc = 0x1B25FCu;
    SET_GPR_U32(ctx, 31, 0x1B2604u);
    ctx->pc = 0x1B2600u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B25FCu;
            // 0x1b2600: 0xe4400010  swc1        $f0, 0x10($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 16), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5C10u;
    if (runtime->hasFunction(0x1A5C10u)) {
        auto targetFn = runtime->lookupFunction(0x1A5C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2604u; }
        if (ctx->pc != 0x1B2604u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5C10_0x1a5c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2604u; }
        if (ctx->pc != 0x1B2604u) { return; }
    }
    ctx->pc = 0x1B2604u;
label_1b2604:
    // 0x1b2604: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1b2604u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1b2608:
    // 0x1b2608: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b2608u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b260c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b260cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b2610: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b2610u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b2614: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b2614u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b2618: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2618u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B261Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2618u;
            // 0x1b261c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B25A4u: goto label_1b25a4;
            case 0x1B25B4u: goto label_1b25b4;
            case 0x1B25C4u: goto label_1b25c4;
            case 0x1B25CCu: goto label_1b25cc;
            case 0x1B2604u: goto label_1b2604;
            case 0x1B2608u: goto label_1b2608;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B2620u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
