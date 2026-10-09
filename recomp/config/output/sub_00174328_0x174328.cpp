#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00174328
// Address: 0x174328 - 0x1743a0
void sub_00174328_0x174328(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00174328_0x174328");
#endif

    switch (ctx->pc) {
        case 0x17438cu: goto label_17438c;
        default: break;
    }

    ctx->pc = 0x174328u;

    // 0x174328: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x174328u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x17432c: 0x24831140  addiu       $v1, $a0, 0x1140
    ctx->pc = 0x17432cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4416));
    // 0x174330: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x174330u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x174334: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x174334u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x174338: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x174338u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x17433c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17433cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x174340: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x174340u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x174344: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x174344u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x174348: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x174348u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x17434c: 0xace40000  sw          $a0, 0x0($a3)
    ctx->pc = 0x17434cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
    // 0x174350: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x174350u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x174354: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x174354u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174358: 0x24640038  addiu       $a0, $v1, 0x38
    ctx->pc = 0x174358u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 56));
    // 0x17435c: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x17435cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x174360: 0x8c850000  lw          $a1, 0x0($a0)
    ctx->pc = 0x174360u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x174364: 0xc0482d  daddu       $t1, $a2, $zero
    ctx->pc = 0x174364u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174368: 0x8c68000c  lw          $t0, 0xC($v1)
    ctx->pc = 0x174368u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x17436c: 0xe0302d  daddu       $a2, $a3, $zero
    ctx->pc = 0x17436cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174370: 0x10a00007  beqz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x174370u;
    {
        const bool branch_taken_0x174370 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x174374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174370u;
            // 0x174374: 0x8c670008  lw          $a3, 0x8($v1) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174370) {
            ctx->pc = 0x174390u;
            goto label_174390;
        }
    }
    ctx->pc = 0x174378u;
    // 0x174378: 0xe81021  addu        $v0, $a3, $t0
    ctx->pc = 0x174378u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x17437c: 0x1282823  subu        $a1, $t1, $t0
    ctx->pc = 0x17437cu;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 8)));
    // 0x174380: 0x122102b  sltu        $v0, $t1, $v0
    ctx->pc = 0x174380u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 9) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x174384: 0xc05d0e8  jal         func_1743A0
    ctx->pc = 0x174384u;
    SET_GPR_U32(ctx, 31, 0x17438Cu);
    ctx->pc = 0x174388u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174384u;
            // 0x174388: 0x122280b  movn        $a1, $t1, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 9));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1743A0u;
    if (runtime->hasFunction(0x1743A0u)) {
        auto targetFn = runtime->lookupFunction(0x1743A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17438Cu; }
        if (ctx->pc != 0x17438Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001743A0_0x1743a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17438Cu; }
        if (ctx->pc != 0x17438Cu) { return; }
    }
    ctx->pc = 0x17438Cu;
label_17438c:
    // 0x17438c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x17438cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_174390:
    // 0x174390: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x174390u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x174394: 0x3e00008  jr          $ra
    ctx->pc = 0x174394u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x174398u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174394u;
            // 0x174398: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17438Cu: goto label_17438c;
            case 0x174390u: goto label_174390;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17439Cu;
    // 0x17439c: 0x0  nop
    ctx->pc = 0x17439cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
