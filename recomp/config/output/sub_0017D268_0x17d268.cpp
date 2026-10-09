#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D268
// Address: 0x17d268 - 0x17d2e8
void sub_0017D268_0x17d268(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D268_0x17d268");
#endif

    switch (ctx->pc) {
        case 0x17d280u: goto label_17d280;
        case 0x17d2b4u: goto label_17d2b4;
        default: break;
    }

    ctx->pc = 0x17d268u;

    // 0x17d268: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x17d268u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x17d26c: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x17d26cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x17d270: 0x8c83000c  lw          $v1, 0xC($a0)
    ctx->pc = 0x17d270u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x17d274: 0x3e00008  jr          $ra
    ctx->pc = 0x17D274u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D274u;
            // 0x17d278: 0xacc30000  sw          $v1, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D280u: goto label_17d280;
            case 0x17D2B4u: goto label_17d2b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D27Cu;
    // 0x17d27c: 0x0  nop
    ctx->pc = 0x17d27cu;
    // NOP
label_17d280:
    // 0x17d280: 0x3e00008  jr          $ra
    ctx->pc = 0x17D280u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D280u;
            // 0x17d284: 0xac850010  sw          $a1, 0x10($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D280u: goto label_17d280;
            case 0x17D2B4u: goto label_17d2b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D288u;
    // 0x17d288: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17d288u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17d28c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17d28cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17d290: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17d290u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d294: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17d294u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17d298: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17d298u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d29c: 0x24050064  addiu       $a1, $zero, 0x64
    ctx->pc = 0x17d29cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x17d2a0: 0x108080  sll         $s0, $s0, 2
    ctx->pc = 0x17d2a0u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x17d2a4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17d2a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17d2a8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17d2a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17d2ac: 0xc05f4ba  jal         func_17D2E8
    ctx->pc = 0x17D2ACu;
    SET_GPR_U32(ctx, 31, 0x17D2B4u);
    ctx->pc = 0x17D2B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D2ACu;
            // 0x17d2b0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D2E8u;
    if (runtime->hasFunction(0x17D2E8u)) {
        auto targetFn = runtime->lookupFunction(0x17D2E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D2B4u; }
        if (ctx->pc != 0x17D2B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D2E8_0x17d2e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D2B4u; }
        if (ctx->pc != 0x17D2B4u) { return; }
    }
    ctx->pc = 0x17D2B4u;
label_17d2b4:
    // 0x17d2b4: 0x2118021  addu        $s0, $s0, $s1
    ctx->pc = 0x17d2b4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x17d2b8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17d2b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17d2bc: 0xae12003c  sw          $s2, 0x3C($s0)
    ctx->pc = 0x17d2bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 18));
    // 0x17d2c0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17d2c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17d2c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17d2c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d2c8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17d2c8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17d2cc: 0x3e00008  jr          $ra
    ctx->pc = 0x17D2CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D2D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D2CCu;
            // 0x17d2d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D280u: goto label_17d280;
            case 0x17D2B4u: goto label_17d2b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D2D4u;
    // 0x17d2d4: 0x0  nop
    ctx->pc = 0x17d2d4u;
    // NOP
    // 0x17d2d8: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x17d2d8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x17d2dc: 0xa42821  addu        $a1, $a1, $a0
    ctx->pc = 0x17d2dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x17d2e0: 0x3e00008  jr          $ra
    ctx->pc = 0x17D2E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D2E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D2E0u;
            // 0x17d2e4: 0x8ca2003c  lw          $v0, 0x3C($a1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 60)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D280u: goto label_17d280;
            case 0x17D2B4u: goto label_17d2b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D2E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
