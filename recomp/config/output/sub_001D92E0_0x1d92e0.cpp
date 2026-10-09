#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D92E0
// Address: 0x1d92e0 - 0x1d93a0
void sub_001D92E0_0x1d92e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D92E0_0x1d92e0");
#endif

    switch (ctx->pc) {
        case 0x1d92fcu: goto label_1d92fc;
        case 0x1d9338u: goto label_1d9338;
        case 0x1d9378u: goto label_1d9378;
        case 0x1d9380u: goto label_1d9380;
        default: break;
    }

    ctx->pc = 0x1d92e0u;

    // 0x1d92e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d92e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d92e4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d92e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d92e8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d92e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d92ec: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d92ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d92f0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d92f0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d92f4: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D92F4u;
    SET_GPR_U32(ctx, 31, 0x1D92FCu);
    ctx->pc = 0x1D92F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D92F4u;
            // 0x1d92f8: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D92FCu; }
        if (ctx->pc != 0x1D92FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D92FCu; }
        if (ctx->pc != 0x1D92FCu) { return; }
    }
    ctx->pc = 0x1D92FCu;
label_1d92fc:
    // 0x1d92fc: 0x2a010005  slti        $at, $s0, 0x5
    ctx->pc = 0x1d92fcu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)5) ? 1 : 0);
    // 0x1d9300: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D9300u;
    {
        const bool branch_taken_0x1d9300 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D9304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9300u;
            // 0x1d9304: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9300) {
            ctx->pc = 0x1D9310u;
            goto label_1d9310;
        }
    }
    ctx->pc = 0x1D9308u;
    // 0x1d9308: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1D9308u;
    {
        const bool branch_taken_0x1d9308 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9308) {
            ctx->pc = 0x1D9388u;
            goto label_1d9388;
        }
    }
    ctx->pc = 0x1D9310u;
label_1d9310:
    // 0x1d9310: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d9310u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d9314: 0x24060c54  addiu       $a2, $zero, 0xC54
    ctx->pc = 0x1d9314u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3156));
    // 0x1d9318: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d9318u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d931c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d931cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d9320: 0x2404004e  addiu       $a0, $zero, 0x4E
    ctx->pc = 0x1d9320u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 78));
    // 0x1d9324: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d9324u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d9328: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d9328u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d932c: 0xc0402d  daddu       $t0, $a2, $zero
    ctx->pc = 0x1d932cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9330: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D9330u;
    SET_GPR_U32(ctx, 31, 0x1D9338u);
    ctx->pc = 0x1D9334u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9330u;
            // 0x1d9334: 0xac30729c  sw          $s0, 0x729C($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 29340), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9338u; }
        if (ctx->pc != 0x1D9338u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9338u; }
        if (ctx->pc != 0x1D9338u) { return; }
    }
    ctx->pc = 0x1D9338u;
label_1d9338:
    // 0x1d9338: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d9338u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d933c: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d933cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d9340: 0x8c306298  lw          $s0, 0x6298($at)
    ctx->pc = 0x1d9340u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 25240)));
    // 0x1d9344: 0x6010004  bgez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D9344u;
    {
        const bool branch_taken_0x1d9344 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x1D9348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9344u;
            // 0x1d9348: 0x2442629c  addiu       $v0, $v0, 0x629C (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 25244));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9344) {
            ctx->pc = 0x1D9358u;
            goto label_1d9358;
        }
    }
    ctx->pc = 0x1D934Cu;
    // 0x1d934c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1D934Cu;
    {
        const bool branch_taken_0x1d934c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D934Cu;
            // 0x1d9350: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d934c) {
            ctx->pc = 0x1D9388u;
            goto label_1d9388;
        }
    }
    ctx->pc = 0x1D9354u;
    // 0x1d9354: 0x0  nop
    ctx->pc = 0x1d9354u;
    // NOP
label_1d9358:
    // 0x1d9358: 0x24450004  addiu       $a1, $v0, 0x4
    ctx->pc = 0x1d9358u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1d935c: 0x101180  sll         $v0, $s0, 6
    ctx->pc = 0x1d935cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 6));
    // 0x1d9360: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1d9360u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9364: 0x501821  addu        $v1, $v0, $s0
    ctx->pc = 0x1d9364u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d9368: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x1d9368u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d936c: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1d936cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d9370: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1D9370u;
    SET_GPR_U32(ctx, 31, 0x1D9378u);
    ctx->pc = 0x1D9374u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9370u;
            // 0x1d9374: 0x23080  sll         $a2, $v0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9378u; }
        if (ctx->pc != 0x1D9378u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9378u; }
        if (ctx->pc != 0x1D9378u) { return; }
    }
    ctx->pc = 0x1D9378u;
label_1d9378:
    // 0x1d9378: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D9378u;
    SET_GPR_U32(ctx, 31, 0x1D9380u);
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9380u; }
        if (ctx->pc != 0x1D9380u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9380u; }
        if (ctx->pc != 0x1D9380u) { return; }
    }
    ctx->pc = 0x1D9380u;
label_1d9380:
    // 0x1d9380: 0x10143c  dsll32      $v0, $s0, 16
    ctx->pc = 0x1d9380u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) << (32 + 16));
    // 0x1d9384: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d9384u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
label_1d9388:
    // 0x1d9388: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d9388u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d938c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d938cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d9390: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d9390u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d9394: 0x3e00008  jr          $ra
    ctx->pc = 0x1D9394u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D9398u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9394u;
            // 0x1d9398: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D92FCu: goto label_1d92fc;
            case 0x1D9310u: goto label_1d9310;
            case 0x1D9338u: goto label_1d9338;
            case 0x1D9358u: goto label_1d9358;
            case 0x1D9378u: goto label_1d9378;
            case 0x1D9380u: goto label_1d9380;
            case 0x1D9388u: goto label_1d9388;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D939Cu;
    // 0x1d939c: 0x0  nop
    ctx->pc = 0x1d939cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
