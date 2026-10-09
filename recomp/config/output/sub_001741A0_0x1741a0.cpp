#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001741A0
// Address: 0x1741a0 - 0x174218
void sub_001741A0_0x1741a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001741A0_0x1741a0");
#endif

    switch (ctx->pc) {
        case 0x1741d8u: goto label_1741d8;
        default: break;
    }

    ctx->pc = 0x1741a0u;

    // 0x1741a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1741a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1741a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1741a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1741a8: 0x24b00003  addiu       $s0, $a1, 0x3
    ctx->pc = 0x1741a8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), 3));
    // 0x1741ac: 0x108082  srl         $s0, $s0, 2
    ctx->pc = 0x1741acu;
    SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 16), 2));
    // 0x1741b0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1741b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1741b4: 0x108080  sll         $s0, $s0, 2
    ctx->pc = 0x1741b4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1741b8: 0x24d2fffc  addiu       $s2, $a2, -0x4
    ctx->pc = 0x1741b8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967292));
    // 0x1741bc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1741bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1741c0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1741c0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1741c4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x1741c4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1741c8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1741c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1741cc: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1741ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1741d0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1741D0u;
    SET_GPR_U32(ctx, 31, 0x1741D8u);
    ctx->pc = 0x1741D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1741D0u;
            // 0x1741d4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1741D8u; }
        if (ctx->pc != 0x1741D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1741D8u; }
        if (ctx->pc != 0x1741D8u) { return; }
    }
    ctx->pc = 0x1741D8u;
label_1741d8:
    // 0x1741d8: 0xae300000  sw          $s0, 0x0($s1)
    ctx->pc = 0x1741d8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0x1741dc: 0x2402000c  addiu       $v0, $zero, 0xC
    ctx->pc = 0x1741dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1741e0: 0x242001a  div         $zero, $s2, $v0
    ctx->pc = 0x1741e0u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 18);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1741e4: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1741E4u;
    {
        const bool branch_taken_0x1741e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1741e4) {
            ctx->pc = 0x1741E8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1741E4u;
            // 0x1741e8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1741ECu;
            goto label_1741ec;
        }
    }
    ctx->pc = 0x1741ECu;
label_1741ec:
    // 0x1741ec: 0xae200010  sw          $zero, 0x10($s1)
    ctx->pc = 0x1741ecu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 0));
    // 0x1741f0: 0xae200008  sw          $zero, 0x8($s1)
    ctx->pc = 0x1741f0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
    // 0x1741f4: 0xae20000c  sw          $zero, 0xC($s1)
    ctx->pc = 0x1741f4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 0));
    // 0x1741f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1741f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1741fc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1741fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x174200: 0x9012  mflo        $s2
    ctx->pc = 0x174200u;
    SET_GPR_U64(ctx, 18, ctx->lo);
    // 0x174204: 0xae320004  sw          $s2, 0x4($s1)
    ctx->pc = 0x174204u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 18));
    // 0x174208: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x174208u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17420c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17420cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174210: 0x3e00008  jr          $ra
    ctx->pc = 0x174210u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x174214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174210u;
            // 0x174214: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1741D8u: goto label_1741d8;
            case 0x1741ECu: goto label_1741ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x174218u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
