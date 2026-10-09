#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167430
// Address: 0x167430 - 0x1674a0
void sub_00167430_0x167430(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167430_0x167430");
#endif

    switch (ctx->pc) {
        case 0x167470u: goto label_167470;
        case 0x167488u: goto label_167488;
        default: break;
    }

    ctx->pc = 0x167430u;

    // 0x167430: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x167430u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x167434: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x167434u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x167438: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x167438u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16743c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16743cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x167440: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167440u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167444: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x167444u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x167448: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x167448u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16744c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x16744cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x167450: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167450u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167454: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x167454u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167458: 0x828021  addu        $s0, $a0, $v0
    ctx->pc = 0x167458u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x16745c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x16745cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167460: 0x26101168  addiu       $s0, $s0, 0x1168
    ctx->pc = 0x167460u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4456));
    // 0x167464: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x167464u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x167468: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x167468u;
    SET_GPR_U32(ctx, 31, 0x167470u);
    ctx->pc = 0x16746Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167468u;
            // 0x16746c: 0xe0902d  daddu       $s2, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167470u; }
        if (ctx->pc != 0x167470u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167470u; }
        if (ctx->pc != 0x167470u) { return; }
    }
    ctx->pc = 0x167470u;
label_167470:
    // 0x167470: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x167470u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x167474: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x167474u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167478: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x167478u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x16747c: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x16747cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x167480: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x167480u;
    SET_GPR_U32(ctx, 31, 0x167488u);
    ctx->pc = 0x167484u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167480u;
            // 0x167484: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167488u; }
        if (ctx->pc != 0x167488u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167488u; }
        if (ctx->pc != 0x167488u) { return; }
    }
    ctx->pc = 0x167488u;
label_167488:
    // 0x167488: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x167488u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16748c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16748cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x167490: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x167490u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x167494: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x167494u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x167498: 0x3e00008  jr          $ra
    ctx->pc = 0x167498u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16749Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167498u;
            // 0x16749c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167470u: goto label_167470;
            case 0x167488u: goto label_167488;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1674A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
