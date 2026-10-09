#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D0C8
// Address: 0x17d0c8 - 0x17d168
void sub_0017D0C8_0x17d0c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D0C8_0x17d0c8");
#endif

    switch (ctx->pc) {
        case 0x17d0f4u: goto label_17d0f4;
        default: break;
    }

    ctx->pc = 0x17d0c8u;

    // 0x17d0c8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17d0c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17d0cc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17d0ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17d0d0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17d0d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d0d4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17d0d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17d0d8: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x17d0d8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d0dc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x17d0dcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d0e0: 0x24060090  addiu       $a2, $zero, 0x90
    ctx->pc = 0x17d0e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 144));
    // 0x17d0e4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17d0e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17d0e8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17d0e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17d0ec: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x17D0ECu;
    SET_GPR_U32(ctx, 31, 0x17D0F4u);
    ctx->pc = 0x17D0F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D0ECu;
            // 0x17d0f0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D0F4u; }
        if (ctx->pc != 0x17D0F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D0F4u; }
        if (ctx->pc != 0x17D0F4u) { return; }
    }
    ctx->pc = 0x17D0F4u;
label_17d0f4:
    // 0x17d0f4: 0x2623001f  addiu       $v1, $s1, 0x1F
    ctx->pc = 0x17d0f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 31));
    // 0x17d0f8: 0x2402ffe0  addiu       $v0, $zero, -0x20
    ctx->pc = 0x17d0f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967264));
    // 0x17d0fc: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x17d0fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x17d100: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17d100u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17d104: 0x24650c00  addiu       $a1, $v1, 0xC00
    ctx->pc = 0x17d104u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 3072));
    // 0x17d108: 0x24620400  addiu       $v0, $v1, 0x400
    ctx->pc = 0x17d108u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1024));
    // 0x17d10c: 0x24640800  addiu       $a0, $v1, 0x800
    ctx->pc = 0x17d10cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 2048));
    // 0x17d110: 0x2406ffff  addiu       $a2, $zero, -0x1
    ctx->pc = 0x17d110u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x17d114: 0xae110054  sw          $s1, 0x54($s0)
    ctx->pc = 0x17d114u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 17));
    // 0x17d118: 0xae120058  sw          $s2, 0x58($s0)
    ctx->pc = 0x17d118u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 18));
    // 0x17d11c: 0xae070000  sw          $a3, 0x0($s0)
    ctx->pc = 0x17d11cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 7));
    // 0x17d120: 0xae020040  sw          $v0, 0x40($s0)
    ctx->pc = 0x17d120u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 2));
    // 0x17d124: 0xae040044  sw          $a0, 0x44($s0)
    ctx->pc = 0x17d124u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 4));
    // 0x17d128: 0xae050048  sw          $a1, 0x48($s0)
    ctx->pc = 0x17d128u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 72), GPR_U32(ctx, 5));
    // 0x17d12c: 0xae060064  sw          $a2, 0x64($s0)
    ctx->pc = 0x17d12cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 6));
    // 0x17d130: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x17d130u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x17d134: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x17d134u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x17d138: 0xae00000c  sw          $zero, 0xC($s0)
    ctx->pc = 0x17d138u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x17d13c: 0xae070028  sw          $a3, 0x28($s0)
    ctx->pc = 0x17d13cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 7));
    // 0x17d140: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x17d140u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x17d144: 0xae000038  sw          $zero, 0x38($s0)
    ctx->pc = 0x17d144u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 0));
    // 0x17d148: 0xae03003c  sw          $v1, 0x3C($s0)
    ctx->pc = 0x17d148u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 3));
    // 0x17d14c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17d14cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17d150: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17d150u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d154: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17d154u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17d158: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17d158u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17d15c: 0x3e00008  jr          $ra
    ctx->pc = 0x17D15Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D15Cu;
            // 0x17d160: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D0F4u: goto label_17d0f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D164u;
    // 0x17d164: 0x0  nop
    ctx->pc = 0x17d164u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
