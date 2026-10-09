#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F4220
// Address: 0x1f4220 - 0x1f428c
void sub_001F4220_0x1f4220(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F4220_0x1f4220");
#endif

    switch (ctx->pc) {
        case 0x1f425cu: goto label_1f425c;
        case 0x1f4274u: goto label_1f4274;
        default: break;
    }

    ctx->pc = 0x1f4220u;

    // 0x1f4220: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f4220u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f4224: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1f4224u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1f4228: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1f4228u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1f422c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f422cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4230: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1f4230u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1f4234: 0x24427440  addiu       $v0, $v0, 0x7440
    ctx->pc = 0x1f4234u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 29760));
    // 0x1f4238: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f4238u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f423c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1f423cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4240: 0x8023eb00  lb          $v1, -0x1500($at)
    ctx->pc = 0x1f4240u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294961920)));
    // 0x1f4244: 0x3c040036  lui         $a0, 0x36
    ctx->pc = 0x1f4244u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)54 << 16));
    // 0x1f4248: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1f4248u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1f424c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1f424cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1f4250: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1f4250u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f4254: 0x40f809  jalr        $v0
    ctx->pc = 0x1F4254u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1F425Cu);
        ctx->pc = 0x1F4258u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4254u;
            // 0x1f4258: 0x2484eb00  addiu       $a0, $a0, -0x1500 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961920));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1F425Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F425Cu: goto label_1f425c;
            case 0x1F4274u: goto label_1f4274;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1F425Cu; }
            if (ctx->pc != 0x1F425Cu) { return; }
        }
        }
    }
    ctx->pc = 0x1F425Cu;
label_1f425c:
    // 0x1f425c: 0x3c050036  lui         $a1, 0x36
    ctx->pc = 0x1f425cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)54 << 16));
    // 0x1f4260: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1f4260u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4264: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1f4264u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4268: 0x24a5eb88  addiu       $a1, $a1, -0x1478
    ctx->pc = 0x1f4268u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294962056));
    // 0x1f426c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F426Cu;
    SET_GPR_U32(ctx, 31, 0x1F4274u);
    ctx->pc = 0x1F4270u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F426Cu;
            // 0x1f4270: 0x2406000c  addiu       $a2, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4274u; }
        if (ctx->pc != 0x1F4274u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4274u; }
        if (ctx->pc != 0x1F4274u) { return; }
    }
    ctx->pc = 0x1F4274u;
label_1f4274:
    // 0x1f4274: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1f4274u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4278: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1f4278u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f427c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1f427cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f4280: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f4280u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f4284: 0x3e00008  jr          $ra
    ctx->pc = 0x1F4284u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F4288u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4284u;
            // 0x1f4288: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F425Cu: goto label_1f425c;
            case 0x1F4274u: goto label_1f4274;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F428Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
