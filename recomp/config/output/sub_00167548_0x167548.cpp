#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167548
// Address: 0x167548 - 0x1675e8
void sub_00167548_0x167548(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167548_0x167548");
#endif

    switch (ctx->pc) {
        case 0x167580u: goto label_167580;
        case 0x1675acu: goto label_1675ac;
        case 0x1675c8u: goto label_1675c8;
        default: break;
    }

    ctx->pc = 0x167548u;

    // 0x167548: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x167548u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x16754c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16754cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x167550: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x167550u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167554: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x167554u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x167558: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167558u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x16755c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16755cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x167560: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x167560u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167564: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x167564u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x167568: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167568u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x16756c: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x16756cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x167570: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x167570u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x167574: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x167574u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167578: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x167578u;
    SET_GPR_U32(ctx, 31, 0x167580u);
    ctx->pc = 0x16757Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167578u;
            // 0x16757c: 0x24701150  addiu       $s0, $v1, 0x1150 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4432));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167580u; }
        if (ctx->pc != 0x167580u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167580u; }
        if (ctx->pc != 0x167580u) { return; }
    }
    ctx->pc = 0x167580u;
label_167580:
    // 0x167580: 0x8e110020  lw          $s1, 0x20($s0)
    ctx->pc = 0x167580u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x167584: 0x1620000a  bnez        $s1, . + 4 + (0xA << 2)
    ctx->pc = 0x167584u;
    {
        const bool branch_taken_0x167584 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x167588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167584u;
            // 0x167588: 0x8e120024  lw          $s2, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167584) {
            ctx->pc = 0x1675B0u;
            goto label_1675b0;
        }
    }
    ctx->pc = 0x16758Cu;
    // 0x16758c: 0x12400009  beqz        $s2, . + 4 + (0x9 << 2)
    ctx->pc = 0x16758Cu;
    {
        const bool branch_taken_0x16758c = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x167590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16758Cu;
            // 0x167590: 0x3c027fff  lui         $v0, 0x7FFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16758c) {
            ctx->pc = 0x1675B4u;
            goto label_1675b4;
        }
    }
    ctx->pc = 0x167594u;
    // 0x167594: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x167594u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x167598: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x167598u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x16759c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x16759cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1675a0: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x1675a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x1675a4: 0x40f809  jalr        $v0
    ctx->pc = 0x1675A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1675ACu);
        ctx->pc = 0x1675A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1675A4u;
            // 0x1675a8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1675ACu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167580u: goto label_167580;
            case 0x1675ACu: goto label_1675ac;
            case 0x1675B0u: goto label_1675b0;
            case 0x1675B4u: goto label_1675b4;
            case 0x1675C8u: goto label_1675c8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1675ACu; }
            if (ctx->pc != 0x1675ACu) { return; }
        }
        }
    }
    ctx->pc = 0x1675ACu;
label_1675ac:
    // 0x1675ac: 0x2428821  addu        $s1, $s2, $v0
    ctx->pc = 0x1675acu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
label_1675b0:
    // 0x1675b0: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x1675b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
label_1675b4:
    // 0x1675b4: 0x2a230000  slti        $v1, $s1, 0x0
    ctx->pc = 0x1675b4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1675b8: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1675b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1675bc: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1675bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1675c0: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x1675C0u;
    SET_GPR_U32(ctx, 31, 0x1675C8u);
    ctx->pc = 0x1675C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1675C0u;
            // 0x1675c4: 0x43880b  movn        $s1, $v0, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1675C8u; }
        if (ctx->pc != 0x1675C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1675C8u; }
        if (ctx->pc != 0x1675C8u) { return; }
    }
    ctx->pc = 0x1675C8u;
label_1675c8:
    // 0x1675c8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1675c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1675cc: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x1675ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1675d0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1675d0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1675d4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1675d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1675d8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1675d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1675dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1675DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1675E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1675DCu;
            // 0x1675e0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167580u: goto label_167580;
            case 0x1675ACu: goto label_1675ac;
            case 0x1675B0u: goto label_1675b0;
            case 0x1675B4u: goto label_1675b4;
            case 0x1675C8u: goto label_1675c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1675E4u;
    // 0x1675e4: 0x0  nop
    ctx->pc = 0x1675e4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
