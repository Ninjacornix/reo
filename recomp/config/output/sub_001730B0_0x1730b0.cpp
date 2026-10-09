#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001730B0
// Address: 0x1730b0 - 0x173130
void sub_001730B0_0x1730b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001730B0_0x1730b0");
#endif

    switch (ctx->pc) {
        case 0x1730f4u: goto label_1730f4;
        default: break;
    }

    ctx->pc = 0x1730b0u;

    // 0x1730b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1730b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1730b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1730b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1730b8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1730b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1730bc: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1730bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1730c0: 0x8e031b7c  lw          $v1, 0x1B7C($s0)
    ctx->pc = 0x1730c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7036)));
    // 0x1730c4: 0x310c0  sll         $v0, $v1, 3
    ctx->pc = 0x1730c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1730c8: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1730c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1730cc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1730ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1730d0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1730d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1730d4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1730d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1730d8: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x1730d8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1730dc: 0x26101150  addiu       $s0, $s0, 0x1150
    ctx->pc = 0x1730dcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4432));
    // 0x1730e0: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x1730e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1730e4: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1730e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1730e8: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x1730e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x1730ec: 0x40f809  jalr        $v0
    ctx->pc = 0x1730ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1730F4u);
        ctx->pc = 0x1730F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1730ECu;
            // 0x1730f0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1730F4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1730F4u: goto label_1730f4;
            case 0x173108u: goto label_173108;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1730F4u; }
            if (ctx->pc != 0x1730F4u) { return; }
        }
        }
    }
    ctx->pc = 0x1730F4u;
label_1730f4:
    // 0x1730f4: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x1730f4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1730f8: 0x24040064  addiu       $a0, $zero, 0x64
    ctx->pc = 0x1730f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1730fc: 0x51880  sll         $v1, $a1, 2
    ctx->pc = 0x1730fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x173100: 0x50800001  beql        $a0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x173100u;
    {
        const bool branch_taken_0x173100 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x173100) {
            ctx->pc = 0x173104u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x173100u;
            // 0x173104: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x173108u;
            goto label_173108;
        }
    }
    ctx->pc = 0x173108u;
label_173108:
    // 0x173108: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x173108u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x17310c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17310cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173110: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x173110u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x173114: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x173114u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173118: 0x64001a  div         $zero, $v1, $a0
    ctx->pc = 0x173118u;
    { int32_t divisor = GPR_S32(ctx, 4);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x17311c: 0x1812  mflo        $v1
    ctx->pc = 0x17311cu;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x173120: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x173120u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x173124: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x173124u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x173128: 0x3e00008  jr          $ra
    ctx->pc = 0x173128u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17312Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173128u;
            // 0x17312c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1730F4u: goto label_1730f4;
            case 0x173108u: goto label_173108;
            default: break;
        }
        return;
    }
    ctx->pc = 0x173130u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
