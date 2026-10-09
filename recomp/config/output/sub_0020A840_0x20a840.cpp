#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020A840
// Address: 0x20a840 - 0x20a910
void sub_0020A840_0x20a840(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020A840_0x20a840");
#endif

    switch (ctx->pc) {
        case 0x20a860u: goto label_20a860;
        case 0x20a89cu: goto label_20a89c;
        case 0x20a8b4u: goto label_20a8b4;
        case 0x20a8c4u: goto label_20a8c4;
        case 0x20a8d4u: goto label_20a8d4;
        case 0x20a8e4u: goto label_20a8e4;
        case 0x20a8f4u: goto label_20a8f4;
        case 0x20a904u: goto label_20a904;
        default: break;
    }

    ctx->pc = 0x20a840u;

    // 0x20a840: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x20a840u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x20a844: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x20a844u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x20a848: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x20a848u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x20a84c: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x20a84cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x20a850: 0x3442f000  ori         $v0, $v0, 0xF000
    ctx->pc = 0x20a850u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)61440);
    // 0x20a854: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x20a854u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x20a858: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x20a858u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x20a85c: 0x3484f000  ori         $a0, $a0, 0xF000
    ctx->pc = 0x20a85cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)61440);
label_20a860:
    // 0x20a860: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x20a860u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0))); // MMIO: 0x10000000
    // 0x20a864: 0x30420004  andi        $v0, $v0, 0x4
    ctx->pc = 0x20a864u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x20a868: 0x0  nop
    ctx->pc = 0x20a868u;
    // NOP
    // 0x20a86c: 0x0  nop
    ctx->pc = 0x20a86cu;
    // NOP
    // 0x20a870: 0x0  nop
    ctx->pc = 0x20a870u;
    // NOP
    // 0x20a874: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x20A874u;
    {
        const bool branch_taken_0x20a874 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x20a874) {
            ctx->pc = 0x20A860u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_20a860;
        }
    }
    ctx->pc = 0x20A87Cu;
    // 0x20a87c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x20a87cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x20a880: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x20a880u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x20a884: 0x3442f000  ori         $v0, $v0, 0xF000
    ctx->pc = 0x20a884u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)61440);
    // 0x20a888: 0x3c038007  lui         $v1, 0x8007
    ctx->pc = 0x20a888u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32775 << 16));
    // 0x20a88c: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x20a88cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x20a890: 0x8c624760  lw          $v0, 0x4760($v1)
    ctx->pc = 0x20a890u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18272)));
    // 0x20a894: 0x40f809  jalr        $v0
    ctx->pc = 0x20A894u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x20A89Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x20A89Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A860u: goto label_20a860;
            case 0x20A89Cu: goto label_20a89c;
            case 0x20A8B4u: goto label_20a8b4;
            case 0x20A8C4u: goto label_20a8c4;
            case 0x20A8D4u: goto label_20a8d4;
            case 0x20A8E4u: goto label_20a8e4;
            case 0x20A8F4u: goto label_20a8f4;
            case 0x20A904u: goto label_20a904;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x20A89Cu; }
            if (ctx->pc != 0x20A89Cu) { return; }
        }
        }
    }
    ctx->pc = 0x20A89Cu;
label_20a89c:
    // 0x20a89c: 0x3c028007  lui         $v0, 0x8007
    ctx->pc = 0x20a89cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32775 << 16));
    // 0x20a8a0: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x20a8a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x20a8a4: 0x8c434764  lw          $v1, 0x4764($v0)
    ctx->pc = 0x20a8a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18276)));
    // 0x20a8a8: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x20a8a8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x20a8ac: 0x60f809  jalr        $v1
    ctx->pc = 0x20A8ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x20A8B4u);
        ctx->pc = 0x20A8B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A8ACu;
            // 0x20a8b0: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x20A8B4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A860u: goto label_20a860;
            case 0x20A89Cu: goto label_20a89c;
            case 0x20A8B4u: goto label_20a8b4;
            case 0x20A8C4u: goto label_20a8c4;
            case 0x20A8D4u: goto label_20a8d4;
            case 0x20A8E4u: goto label_20a8e4;
            case 0x20A8F4u: goto label_20a8f4;
            case 0x20A904u: goto label_20a904;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x20A8B4u; }
            if (ctx->pc != 0x20A8B4u) { return; }
        }
        }
    }
    ctx->pc = 0x20A8B4u;
label_20a8b4:
    // 0x20a8b4: 0x3c028007  lui         $v0, 0x8007
    ctx->pc = 0x20a8b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32775 << 16));
    // 0x20a8b8: 0x8c43474c  lw          $v1, 0x474C($v0)
    ctx->pc = 0x20a8b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18252)));
    // 0x20a8bc: 0x60f809  jalr        $v1
    ctx->pc = 0x20A8BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x20A8C4u);
        ctx->pc = 0x20A8C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A8BCu;
            // 0x20a8c0: 0x3404dffd  ori         $a0, $zero, 0xDFFD (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)57341);
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x20A8C4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A860u: goto label_20a860;
            case 0x20A89Cu: goto label_20a89c;
            case 0x20A8B4u: goto label_20a8b4;
            case 0x20A8C4u: goto label_20a8c4;
            case 0x20A8D4u: goto label_20a8d4;
            case 0x20A8E4u: goto label_20a8e4;
            case 0x20A8F4u: goto label_20a8f4;
            case 0x20A904u: goto label_20a904;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x20A8C4u; }
            if (ctx->pc != 0x20A8C4u) { return; }
        }
        }
    }
    ctx->pc = 0x20A8C4u;
label_20a8c4:
    // 0x20a8c4: 0x3c028007  lui         $v0, 0x8007
    ctx->pc = 0x20a8c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32775 << 16));
    // 0x20a8c8: 0x8c434750  lw          $v1, 0x4750($v0)
    ctx->pc = 0x20a8c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18256)));
    // 0x20a8cc: 0x60f809  jalr        $v1
    ctx->pc = 0x20A8CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x20A8D4u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x20A8D4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A860u: goto label_20a860;
            case 0x20A89Cu: goto label_20a89c;
            case 0x20A8B4u: goto label_20a8b4;
            case 0x20A8C4u: goto label_20a8c4;
            case 0x20A8D4u: goto label_20a8d4;
            case 0x20A8E4u: goto label_20a8e4;
            case 0x20A8F4u: goto label_20a8f4;
            case 0x20A904u: goto label_20a904;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x20A8D4u; }
            if (ctx->pc != 0x20A8D4u) { return; }
        }
        }
    }
    ctx->pc = 0x20A8D4u;
label_20a8d4:
    // 0x20a8d4: 0x3c028007  lui         $v0, 0x8007
    ctx->pc = 0x20a8d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32775 << 16));
    // 0x20a8d8: 0x8c43475c  lw          $v1, 0x475C($v0)
    ctx->pc = 0x20a8d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18268)));
    // 0x20a8dc: 0x60f809  jalr        $v1
    ctx->pc = 0x20A8DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x20A8E4u);
        ctx->pc = 0x20A8E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A8DCu;
            // 0x20a8e0: 0x2404007f  addiu       $a0, $zero, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x20A8E4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A860u: goto label_20a860;
            case 0x20A89Cu: goto label_20a89c;
            case 0x20A8B4u: goto label_20a8b4;
            case 0x20A8C4u: goto label_20a8c4;
            case 0x20A8D4u: goto label_20a8d4;
            case 0x20A8E4u: goto label_20a8e4;
            case 0x20A8F4u: goto label_20a8f4;
            case 0x20A904u: goto label_20a904;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x20A8E4u; }
            if (ctx->pc != 0x20A8E4u) { return; }
        }
        }
    }
    ctx->pc = 0x20A8E4u;
label_20a8e4:
    // 0x20a8e4: 0x3c028007  lui         $v0, 0x8007
    ctx->pc = 0x20a8e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32775 << 16));
    // 0x20a8e8: 0x8c434754  lw          $v1, 0x4754($v0)
    ctx->pc = 0x20a8e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18260)));
    // 0x20a8ec: 0x60f809  jalr        $v1
    ctx->pc = 0x20A8ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x20A8F4u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x20A8F4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A860u: goto label_20a860;
            case 0x20A89Cu: goto label_20a89c;
            case 0x20A8B4u: goto label_20a8b4;
            case 0x20A8C4u: goto label_20a8c4;
            case 0x20A8D4u: goto label_20a8d4;
            case 0x20A8E4u: goto label_20a8e4;
            case 0x20A8F4u: goto label_20a8f4;
            case 0x20A904u: goto label_20a904;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x20A8F4u; }
            if (ctx->pc != 0x20A8F4u) { return; }
        }
        }
    }
    ctx->pc = 0x20A8F4u;
label_20a8f4:
    // 0x20a8f4: 0x3c028007  lui         $v0, 0x8007
    ctx->pc = 0x20a8f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32775 << 16));
    // 0x20a8f8: 0x8c434758  lw          $v1, 0x4758($v0)
    ctx->pc = 0x20a8f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18264)));
    // 0x20a8fc: 0x60f809  jalr        $v1
    ctx->pc = 0x20A8FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x20A904u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x20A904u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A860u: goto label_20a860;
            case 0x20A89Cu: goto label_20a89c;
            case 0x20A8B4u: goto label_20a8b4;
            case 0x20A8C4u: goto label_20a8c4;
            case 0x20A8D4u: goto label_20a8d4;
            case 0x20A8E4u: goto label_20a8e4;
            case 0x20A8F4u: goto label_20a8f4;
            case 0x20A904u: goto label_20a904;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x20A904u; }
            if (ctx->pc != 0x20A904u) { return; }
        }
        }
    }
    ctx->pc = 0x20A904u;
label_20a904:
    // 0x20a904: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x20a904u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x20a908: 0x3e00008  jr          $ra
    ctx->pc = 0x20A908u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x20A90Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A908u;
            // 0x20a90c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A860u: goto label_20a860;
            case 0x20A89Cu: goto label_20a89c;
            case 0x20A8B4u: goto label_20a8b4;
            case 0x20A8C4u: goto label_20a8c4;
            case 0x20A8D4u: goto label_20a8d4;
            case 0x20A8E4u: goto label_20a8e4;
            case 0x20A8F4u: goto label_20a8f4;
            case 0x20A904u: goto label_20a904;
            default: break;
        }
        return;
    }
    ctx->pc = 0x20A910u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
