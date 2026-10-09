#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130478
// Address: 0x130478 - 0x1304e8
void sub_00130478_0x130478(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130478_0x130478");
#endif

    switch (ctx->pc) {
        case 0x1304acu: goto label_1304ac;
        default: break;
    }

    ctx->pc = 0x130478u;

    // 0x130478: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x130478u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13047c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13047cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x130480: 0x100882d  daddu       $s1, $t0, $zero
    ctx->pc = 0x130480u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130484: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130488: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x130488u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13048c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13048cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x130490: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x130490u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130494: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x130494u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x130498: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x130498u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13049c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x13049cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x1304a0: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1304a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1304a4: 0xc0505b4  jal         func_1416D0
    ctx->pc = 0x1304A4u;
    SET_GPR_U32(ctx, 31, 0x1304ACu);
    ctx->pc = 0x1304A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1304A4u;
            // 0x1304a8: 0xc0a02d  daddu       $s4, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416D0u;
    if (runtime->hasFunction(0x1416D0u)) {
        auto targetFn = runtime->lookupFunction(0x1416D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1304ACu; }
        if (ctx->pc != 0x1304ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416D0_0x1416d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1304ACu; }
        if (ctx->pc != 0x1304ACu) { return; }
    }
    ctx->pc = 0x1304ACu;
label_1304ac:
    // 0x1304ac: 0x118ac0  sll         $s1, $s1, 11
    ctx->pc = 0x1304acu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 11));
    // 0x1304b0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1304b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1304b4: 0xae12000c  sw          $s2, 0xC($s0)
    ctx->pc = 0x1304b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 18));
    // 0x1304b8: 0xae110010  sw          $s1, 0x10($s0)
    ctx->pc = 0x1304b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 17));
    // 0x1304bc: 0xae13004c  sw          $s3, 0x4C($s0)
    ctx->pc = 0x1304bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 76), GPR_U32(ctx, 19));
    // 0x1304c0: 0xae140050  sw          $s4, 0x50($s0)
    ctx->pc = 0x1304c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 20));
    // 0x1304c4: 0xa2020041  sb          $v0, 0x41($s0)
    ctx->pc = 0x1304c4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 65), (uint8_t)GPR_U32(ctx, 2));
    // 0x1304c8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1304c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1304cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1304ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1304d0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1304d0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1304d4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1304d4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1304d8: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1304d8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1304dc: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1304dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1304e0: 0x80505ba  j           func_1416E8
    ctx->pc = 0x1304E0u;
    ctx->pc = 0x1304E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1304E0u;
            // 0x1304e4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001416E8_0x1416e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1304E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
