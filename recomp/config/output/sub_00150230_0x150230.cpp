#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150230
// Address: 0x150230 - 0x150408
void sub_00150230_0x150230(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150230_0x150230");
#endif

    switch (ctx->pc) {
        case 0x150260u: goto label_150260;
        case 0x15028cu: goto label_15028c;
        case 0x1502b4u: goto label_1502b4;
        case 0x1502e0u: goto label_1502e0;
        case 0x15030cu: goto label_15030c;
        case 0x150334u: goto label_150334;
        case 0x15035cu: goto label_15035c;
        case 0x150384u: goto label_150384;
        case 0x1503acu: goto label_1503ac;
        case 0x1503d4u: goto label_1503d4;
        case 0x1503fcu: goto label_1503fc;
        default: break;
    }

    ctx->pc = 0x150230u;

    // 0x150230: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x150230u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x150234: 0x3e00008  jr          $ra
    ctx->pc = 0x150234u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150234u;
            // 0x150238: 0x8c62d808  lw          $v0, -0x27F8($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294957064)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15023Cu;
    // 0x15023c: 0x0  nop
    ctx->pc = 0x15023cu;
    // NOP
    // 0x150240: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x150240u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x150244: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x150244u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150248: 0x8c63d80c  lw          $v1, -0x27F4($v1)
    ctx->pc = 0x150248u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294957068)));
    // 0x15024c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15024cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150250: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x150250u;
    {
        const bool branch_taken_0x150250 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x150254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150250u;
            // 0x150254: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150250) {
            ctx->pc = 0x150260u;
            goto label_150260;
        }
    }
    ctx->pc = 0x150258u;
    // 0x150258: 0x60f809  jalr        $v1
    ctx->pc = 0x150258u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x150260u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x150260u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x150260u; }
            if (ctx->pc != 0x150260u) { return; }
        }
        }
    }
    ctx->pc = 0x150260u;
label_150260:
    // 0x150260: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x150260u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150264: 0x3e00008  jr          $ra
    ctx->pc = 0x150264u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150264u;
            // 0x150268: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15026Cu;
    // 0x15026c: 0x0  nop
    ctx->pc = 0x15026cu;
    // NOP
    // 0x150270: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x150270u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x150274: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x150274u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150278: 0x8c42d810  lw          $v0, -0x27F0($v0)
    ctx->pc = 0x150278u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957072)));
    // 0x15027c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15027Cu;
    {
        const bool branch_taken_0x15027c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15027Cu;
            // 0x150280: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15027c) {
            ctx->pc = 0x15028Cu;
            goto label_15028c;
        }
    }
    ctx->pc = 0x150284u;
    // 0x150284: 0x40f809  jalr        $v0
    ctx->pc = 0x150284u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15028Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x15028Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15028Cu; }
            if (ctx->pc != 0x15028Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15028Cu;
label_15028c:
    // 0x15028c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15028cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150290: 0x3e00008  jr          $ra
    ctx->pc = 0x150290u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150290u;
            // 0x150294: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150298u;
    // 0x150298: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x150298u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x15029c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15029cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1502a0: 0x8c42d814  lw          $v0, -0x27EC($v0)
    ctx->pc = 0x1502a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957076)));
    // 0x1502a4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1502A4u;
    {
        const bool branch_taken_0x1502a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1502A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1502A4u;
            // 0x1502a8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1502a4) {
            ctx->pc = 0x1502B4u;
            goto label_1502b4;
        }
    }
    ctx->pc = 0x1502ACu;
    // 0x1502ac: 0x40f809  jalr        $v0
    ctx->pc = 0x1502ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1502B4u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1502B4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1502B4u; }
            if (ctx->pc != 0x1502B4u) { return; }
        }
        }
    }
    ctx->pc = 0x1502B4u;
label_1502b4:
    // 0x1502b4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1502b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1502b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1502B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1502BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1502B8u;
            // 0x1502bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1502C0u;
    // 0x1502c0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1502c0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1502c4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1502c4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1502c8: 0x8c63d818  lw          $v1, -0x27E8($v1)
    ctx->pc = 0x1502c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294957080)));
    // 0x1502cc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1502ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1502d0: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1502D0u;
    {
        const bool branch_taken_0x1502d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1502D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1502D0u;
            // 0x1502d4: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1502d0) {
            ctx->pc = 0x1502E0u;
            goto label_1502e0;
        }
    }
    ctx->pc = 0x1502D8u;
    // 0x1502d8: 0x60f809  jalr        $v1
    ctx->pc = 0x1502D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1502E0u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1502E0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1502E0u; }
            if (ctx->pc != 0x1502E0u) { return; }
        }
        }
    }
    ctx->pc = 0x1502E0u;
label_1502e0:
    // 0x1502e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1502e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1502e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1502E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1502E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1502E4u;
            // 0x1502e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1502ECu;
    // 0x1502ec: 0x0  nop
    ctx->pc = 0x1502ecu;
    // NOP
    // 0x1502f0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1502f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1502f4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1502f4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1502f8: 0x8c42d81c  lw          $v0, -0x27E4($v0)
    ctx->pc = 0x1502f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957084)));
    // 0x1502fc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1502FCu;
    {
        const bool branch_taken_0x1502fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1502FCu;
            // 0x150300: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1502fc) {
            ctx->pc = 0x15030Cu;
            goto label_15030c;
        }
    }
    ctx->pc = 0x150304u;
    // 0x150304: 0x40f809  jalr        $v0
    ctx->pc = 0x150304u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15030Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x15030Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15030Cu; }
            if (ctx->pc != 0x15030Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15030Cu;
label_15030c:
    // 0x15030c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15030cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150310: 0x3e00008  jr          $ra
    ctx->pc = 0x150310u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150310u;
            // 0x150314: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150318u;
    // 0x150318: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x150318u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x15031c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15031cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150320: 0x8c42d824  lw          $v0, -0x27DC($v0)
    ctx->pc = 0x150320u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957092)));
    // 0x150324: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x150324u;
    {
        const bool branch_taken_0x150324 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150324u;
            // 0x150328: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150324) {
            ctx->pc = 0x150334u;
            goto label_150334;
        }
    }
    ctx->pc = 0x15032Cu;
    // 0x15032c: 0x40f809  jalr        $v0
    ctx->pc = 0x15032Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x150334u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x150334u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x150334u; }
            if (ctx->pc != 0x150334u) { return; }
        }
        }
    }
    ctx->pc = 0x150334u;
label_150334:
    // 0x150334: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x150334u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150338: 0x3e00008  jr          $ra
    ctx->pc = 0x150338u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15033Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150338u;
            // 0x15033c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150340u;
    // 0x150340: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x150340u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x150344: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x150344u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150348: 0x8c42d820  lw          $v0, -0x27E0($v0)
    ctx->pc = 0x150348u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957088)));
    // 0x15034c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15034Cu;
    {
        const bool branch_taken_0x15034c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15034Cu;
            // 0x150350: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15034c) {
            ctx->pc = 0x15035Cu;
            goto label_15035c;
        }
    }
    ctx->pc = 0x150354u;
    // 0x150354: 0x40f809  jalr        $v0
    ctx->pc = 0x150354u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15035Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x15035Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15035Cu; }
            if (ctx->pc != 0x15035Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15035Cu;
label_15035c:
    // 0x15035c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15035cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150360: 0x3e00008  jr          $ra
    ctx->pc = 0x150360u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150364u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150360u;
            // 0x150364: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150368u;
    // 0x150368: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x150368u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x15036c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15036cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150370: 0x8c42d828  lw          $v0, -0x27D8($v0)
    ctx->pc = 0x150370u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957096)));
    // 0x150374: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x150374u;
    {
        const bool branch_taken_0x150374 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150374u;
            // 0x150378: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150374) {
            ctx->pc = 0x150384u;
            goto label_150384;
        }
    }
    ctx->pc = 0x15037Cu;
    // 0x15037c: 0x40f809  jalr        $v0
    ctx->pc = 0x15037Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x150384u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x150384u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x150384u; }
            if (ctx->pc != 0x150384u) { return; }
        }
        }
    }
    ctx->pc = 0x150384u;
label_150384:
    // 0x150384: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x150384u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150388: 0x3e00008  jr          $ra
    ctx->pc = 0x150388u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15038Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150388u;
            // 0x15038c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150390u;
    // 0x150390: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x150390u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x150394: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x150394u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150398: 0x8c42d82c  lw          $v0, -0x27D4($v0)
    ctx->pc = 0x150398u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957100)));
    // 0x15039c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15039Cu;
    {
        const bool branch_taken_0x15039c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1503A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15039Cu;
            // 0x1503a0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15039c) {
            ctx->pc = 0x1503ACu;
            goto label_1503ac;
        }
    }
    ctx->pc = 0x1503A4u;
    // 0x1503a4: 0x40f809  jalr        $v0
    ctx->pc = 0x1503A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1503ACu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1503ACu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1503ACu; }
            if (ctx->pc != 0x1503ACu) { return; }
        }
        }
    }
    ctx->pc = 0x1503ACu;
label_1503ac:
    // 0x1503ac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1503acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1503b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1503B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1503B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1503B0u;
            // 0x1503b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1503B8u;
    // 0x1503b8: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1503b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1503bc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1503bcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1503c0: 0x8c42d830  lw          $v0, -0x27D0($v0)
    ctx->pc = 0x1503c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957104)));
    // 0x1503c4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1503C4u;
    {
        const bool branch_taken_0x1503c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1503C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1503C4u;
            // 0x1503c8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1503c4) {
            ctx->pc = 0x1503D4u;
            goto label_1503d4;
        }
    }
    ctx->pc = 0x1503CCu;
    // 0x1503cc: 0x40f809  jalr        $v0
    ctx->pc = 0x1503CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1503D4u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1503D4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1503D4u; }
            if (ctx->pc != 0x1503D4u) { return; }
        }
        }
    }
    ctx->pc = 0x1503D4u;
label_1503d4:
    // 0x1503d4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1503d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1503d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1503D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1503DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1503D8u;
            // 0x1503dc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1503E0u;
    // 0x1503e0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1503e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1503e4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1503e4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1503e8: 0x8c42d834  lw          $v0, -0x27CC($v0)
    ctx->pc = 0x1503e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957108)));
    // 0x1503ec: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1503ECu;
    {
        const bool branch_taken_0x1503ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1503F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1503ECu;
            // 0x1503f0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1503ec) {
            ctx->pc = 0x1503FCu;
            goto label_1503fc;
        }
    }
    ctx->pc = 0x1503F4u;
    // 0x1503f4: 0x40f809  jalr        $v0
    ctx->pc = 0x1503F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1503FCu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1503FCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1503FCu; }
            if (ctx->pc != 0x1503FCu) { return; }
        }
        }
    }
    ctx->pc = 0x1503FCu;
label_1503fc:
    // 0x1503fc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1503fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150400: 0x3e00008  jr          $ra
    ctx->pc = 0x150400u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150404u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150400u;
            // 0x150404: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150260u: goto label_150260;
            case 0x15028Cu: goto label_15028c;
            case 0x1502B4u: goto label_1502b4;
            case 0x1502E0u: goto label_1502e0;
            case 0x15030Cu: goto label_15030c;
            case 0x150334u: goto label_150334;
            case 0x15035Cu: goto label_15035c;
            case 0x150384u: goto label_150384;
            case 0x1503ACu: goto label_1503ac;
            case 0x1503D4u: goto label_1503d4;
            case 0x1503FCu: goto label_1503fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150408u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
