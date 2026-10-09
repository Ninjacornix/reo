#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A860
// Address: 0x12a860 - 0x12a8e4
void sub_0012A860_0x12a860(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A860_0x12a860");
#endif

    switch (ctx->pc) {
        case 0x12a8b0u: goto label_12a8b0;
        case 0x12a8bcu: goto label_12a8bc;
        case 0x12a8c8u: goto label_12a8c8;
        default: break;
    }

    ctx->pc = 0x12a860u;

    // 0x12a860: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12a860u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12a864: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12a864u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12a868: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x12a868u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a86c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12a86cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12a870: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x12a870u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a874: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12a874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12a878: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12A878u;
    {
        const bool branch_taken_0x12a878 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x12A87Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A878u;
            // 0x12a87c: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12a878) {
            ctx->pc = 0x12A888u;
            goto label_12a888;
        }
    }
    ctx->pc = 0x12A880u;
    // 0x12a880: 0x56400009  bnel        $s2, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x12A880u;
    {
        const bool branch_taken_0x12a880 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x12a880) {
            ctx->pc = 0x12A884u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12A880u;
            // 0x12a884: 0x8e300094  lw          $s0, 0x94($s1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 148)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12A8A8u;
            goto label_12a8a8;
        }
    }
    ctx->pc = 0x12A888u;
label_12a888:
    // 0x12a888: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x12a888u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x12a88c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12a88cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a890: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12a890u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12a894: 0x2484a3f8  addiu       $a0, $a0, -0x5C08
    ctx->pc = 0x12a894u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943736));
    // 0x12a898: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12a898u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12a89c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12a89cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12a8a0: 0x804a034  j           func_1280D0
    ctx->pc = 0x12A8A0u;
    ctx->pc = 0x12A8A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A8A0u;
            // 0x12a8a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12A8A8u;
label_12a8a8:
    // 0x12a8a8: 0xc04f3de  jal         func_13CF78
    ctx->pc = 0x12A8A8u;
    SET_GPR_U32(ctx, 31, 0x12A8B0u);
    ctx->pc = 0x12A8ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A8A8u;
            // 0x12a8ac: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CF78u;
    if (runtime->hasFunction(0x13CF78u)) {
        auto targetFn = runtime->lookupFunction(0x13CF78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A8B0u; }
        if (ctx->pc != 0x12A8B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CF78_0x13cf78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A8B0u; }
        if (ctx->pc != 0x12A8B0u) { return; }
    }
    ctx->pc = 0x12A8B0u;
label_12a8b0:
    // 0x12a8b0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12a8b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a8b4: 0xc04a996  jal         func_12A658
    ctx->pc = 0x12A8B4u;
    SET_GPR_U32(ctx, 31, 0x12A8BCu);
    ctx->pc = 0x12A8B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A8B4u;
            // 0x12a8b8: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12A658u;
    if (runtime->hasFunction(0x12A658u)) {
        auto targetFn = runtime->lookupFunction(0x12A658u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A8BCu; }
        if (ctx->pc != 0x12A8BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A658_0x12a658(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A8BCu; }
        if (ctx->pc != 0x12A8BCu) { return; }
    }
    ctx->pc = 0x12A8BCu;
label_12a8bc:
    // 0x12a8bc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12a8bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a8c0: 0xc04f51a  jal         func_13D468
    ctx->pc = 0x12A8C0u;
    SET_GPR_U32(ctx, 31, 0x12A8C8u);
    ctx->pc = 0x12A8C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A8C0u;
            // 0x12a8c4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D468u;
    if (runtime->hasFunction(0x13D468u)) {
        auto targetFn = runtime->lookupFunction(0x13D468u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A8C8u; }
        if (ctx->pc != 0x12A8C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D468_0x13d468(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A8C8u; }
        if (ctx->pc != 0x12A8C8u) { return; }
    }
    ctx->pc = 0x12A8C8u;
label_12a8c8:
    // 0x12a8c8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12a8c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a8cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12a8ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a8d0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12a8d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12a8d4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12a8d4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12a8d8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12a8d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12a8dc: 0x804a9e0  j           func_12A780
    ctx->pc = 0x12A8DCu;
    ctx->pc = 0x12A8E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A8DCu;
            // 0x12a8e0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12A780u;
    if (runtime->hasFunction(0x12A780u)) {
        auto targetFn = runtime->lookupFunction(0x12A780u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012A780_0x12a780(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12A8E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
