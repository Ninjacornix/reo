#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F270
// Address: 0x15f270 - 0x15f2f0
void sub_0015F270_0x15f270(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F270_0x15f270");
#endif

    switch (ctx->pc) {
        case 0x15f28cu: goto label_15f28c;
        case 0x15f2b8u: goto label_15f2b8;
        case 0x15f2d8u: goto label_15f2d8;
        default: break;
    }

    ctx->pc = 0x15f270u;

    // 0x15f270: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15f270u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15f274: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f274u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f278: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15f278u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f27c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15f27cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15f280: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15f280u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15f284: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15F284u;
    SET_GPR_U32(ctx, 31, 0x15F28Cu);
    ctx->pc = 0x15F288u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F284u;
            // 0x15f288: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F28Cu; }
        if (ctx->pc != 0x15F28Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F28Cu; }
        if (ctx->pc != 0x15F28Cu) { return; }
    }
    ctx->pc = 0x15F28Cu;
label_15f28c:
    // 0x15f28c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x15F28Cu;
    {
        const bool branch_taken_0x15f28c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15F290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F28Cu;
            // 0x15f290: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f28c) {
            ctx->pc = 0x15F2B0u;
            goto label_15f2b0;
        }
    }
    ctx->pc = 0x15F294u;
    // 0x15f294: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15f294u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15f298: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f298u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f29c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f29cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f2a0: 0x2484f150  addiu       $a0, $a0, -0xEB0
    ctx->pc = 0x15f2a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963536));
    // 0x15f2a4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15f2a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f2a8: 0x8058dd4  j           func_163750
    ctx->pc = 0x15F2A8u;
    ctx->pc = 0x15F2ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F2A8u;
            // 0x15f2ac: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F2B0u;
label_15f2b0:
    // 0x15f2b0: 0xc057cbc  jal         func_15F2F0
    ctx->pc = 0x15F2B0u;
    SET_GPR_U32(ctx, 31, 0x15F2B8u);
    ctx->pc = 0x15F2F0u;
    if (runtime->hasFunction(0x15F2F0u)) {
        auto targetFn = runtime->lookupFunction(0x15F2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F2B8u; }
        if (ctx->pc != 0x15F2B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F2F0_0x15f2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F2B8u; }
        if (ctx->pc != 0x15F2B8u) { return; }
    }
    ctx->pc = 0x15F2B8u;
label_15f2b8:
    // 0x15f2b8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x15f2b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x15f2bc: 0xae110128  sw          $s1, 0x128($s0)
    ctx->pc = 0x15f2bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 296), GPR_U32(ctx, 17));
    // 0x15f2c0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f2c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f2c4: 0xae02013c  sw          $v0, 0x13C($s0)
    ctx->pc = 0x15f2c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 316), GPR_U32(ctx, 2));
    // 0x15f2c8: 0xae000140  sw          $zero, 0x140($s0)
    ctx->pc = 0x15f2c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 320), GPR_U32(ctx, 0));
    // 0x15f2cc: 0xae000144  sw          $zero, 0x144($s0)
    ctx->pc = 0x15f2ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 324), GPR_U32(ctx, 0));
    // 0x15f2d0: 0xc057bee  jal         func_15EFB8
    ctx->pc = 0x15F2D0u;
    SET_GPR_U32(ctx, 31, 0x15F2D8u);
    ctx->pc = 0x15F2D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F2D0u;
            // 0x15f2d4: 0xae000148  sw          $zero, 0x148($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 328), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15EFB8u;
    if (runtime->hasFunction(0x15EFB8u)) {
        auto targetFn = runtime->lookupFunction(0x15EFB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F2D8u; }
        if (ctx->pc != 0x15F2D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EFB8_0x15efb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F2D8u; }
        if (ctx->pc != 0x15F2D8u) { return; }
    }
    ctx->pc = 0x15F2D8u;
label_15f2d8:
    // 0x15f2d8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f2d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f2dc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f2dcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f2e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f2e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f2e4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15f2e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f2e8: 0x8056fea  j           func_15BFA8
    ctx->pc = 0x15F2E8u;
    ctx->pc = 0x15F2ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F2E8u;
            // 0x15f2ec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BFA8u;
    if (runtime->hasFunction(0x15BFA8u)) {
        auto targetFn = runtime->lookupFunction(0x15BFA8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015BFA8_0x15bfa8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F2F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
